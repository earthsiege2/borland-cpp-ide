{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QMenus;

{$S-,W-,R-,T-,H+,X+}

interface

uses
  QTypes, SysUtils, Types, Classes, Qt, QGraphics, Contnrs, QActnList,
  QImgList;

const
  ShortCutKeyMask       = $0000FFFF;
  KeyMask               = $1FFF;
  midSeparator          = -1;
  midInvisible          = 0;

  QEventType_MenuClick = QEventType(Integer(QEventType_ClxBase) + $40);

type
  EMenuError = class(Exception);
  TMenu = class;
  TMenuItem = class;

{ TMenuActionLink }

  TMenuActionLink = class(TActionLink)
  protected
    FClient: TMenuItem;
    procedure AssignClient(AClient: TObject); override;
    function IsCaptionLinked: Boolean; override;
    function IsCheckedLinked: Boolean; override;
    function IsEnabledLinked: Boolean; override;
    function IsHelpLinked: Boolean; override;
    function IsHintLinked: Boolean; override;
    function IsImageIndexLinked: Boolean; override;
    function IsShortCutLinked: Boolean; override;
    function IsVisibleLinked: Boolean; override;
    function IsOnExecuteLinked: Boolean; override;
    procedure SetCaption(const Value: TCaption); override;
    procedure SetChecked(Value: Boolean); override;
    procedure SetEnabled(Value: Boolean); override;
    procedure SetHelpContext(Value: THelpContext); override;
    procedure SetHelpKeyword(const Value: string); override;
    procedure SetHelpType(Value: THelpType); override;
    procedure SetHint(const Value: WideString); override;
    procedure SetImageIndex(Value: Integer); override;
    procedure SetShortCut(Value: TShortCut); override;
    procedure SetVisible(Value: Boolean); override;
    procedure SetOnExecute(Value: TNotifyEvent); override;
  end;

  TMenuActionLinkClass = class of TMenuActionLink;

{ TMenuItem }

  TMenuChangeEvent = procedure (Sender: TObject; Source: TMenuItem; Rebuild: Boolean) of object;
  TMenuItemAutoFlag = (maAutomatic, maManual, maParent);
  TMenuAutoFlag = maAutomatic..maManual;

  TMenuItem = class(THandleComponent)
  private
    FActionLink: TMenuActionLink;
    FAutoHotkeys: TMenuItemAutoFlag;
    FVisible: Boolean;
    FRadioItem: Boolean;
    FChecked: Boolean;
    FEnabled: Boolean;
    FGroupIndex: Byte;
    FID: Integer;
    FItems: TList;
    FBitmap: TBitmap;
    FCaption: WideString;
    FHint: WideString;
    FMenu: TMenu;
    FMenuData: QMenuDataH;
    FMerged: TMenuItem;
    FMergedWith: TMenuItem;
    FOnChange: TMenuChangeEvent;
    FParent: TMenuItem;
    FOnClick: TNotifyEvent;
    FOnHighlighted: TNotifyEvent;
    FOnShow: TNotifyEvent;
    FShortCut: TShortCut;
    FImageIndex: TImageIndex;
    FCurrentItem: TMenuItem;
    FMenuItemHandle: QMenuItemH;
    procedure ActivatedHook(ItemID: Integer); cdecl;
    procedure DoActionChange(Sender: TObject);
    procedure DoSetImageIndex(const Value: Integer);
    function GetAction: TBasicAction;
    procedure SetAction(Value: TBasicAction);
    function GetCount: Integer;
    function GetItem(Index: Integer): TMenuItem;
    function GetMenuIndex: Integer;
    procedure HighlightedHook(ItemID: Integer); cdecl;
    procedure ItemHandleNeeded;
    procedure MergeWith(Menu: TMenuItem);
    procedure RebuildMenu;
    procedure RemoveItemHandle;
    procedure SetBitmap(const Value: TBitmap);
    procedure SetCaption(const Value: WideString);
    procedure SetChecked(const Value: Boolean);
    procedure SetEnabled(const Value: Boolean);
    procedure SetGroupIndex(const Value: Byte);
    procedure SetMenuIndex(Value: Integer);
    procedure SetRadioItem(const Value: Boolean);
    procedure SetShortCut(const Value: TShortCut);
    procedure SetVisible(const Value: Boolean);
    procedure ShowHook; cdecl;
    procedure SubItemChanged(Sender: TObject; Source: TMenuItem; Rebuild: Boolean);
    function VisibleCount: Integer;
    procedure TurnSiblingsOff;
    procedure VerifyGroupIndex(Position: Integer; Value: Byte);
    function GetHandle: QPopupMenuH;
    procedure InitiateActions;
    procedure SetImageIndex(const Value: TImageIndex);
    procedure ChangePixmap(Value: QPixmapH);
    function IsBitmapStored: Boolean;
    function IsCaptionStored: Boolean;
    function IsCheckedStored: Boolean;
    function IsEnabledStored: Boolean;
    function IsHelpContextStored: Boolean;
    function IsHintStored: Boolean;
    function IsImageIndexStored: Boolean;
    function IsOnClickStored: Boolean;
    function IsShortCutStored: Boolean;
    function IsVisibleStored: Boolean;
    procedure UpdateItems;
    function InternalRethinkHotkeys(ForceRethink: Boolean): Boolean;
    procedure RemoveQtItemFromParent;
    procedure SetAutoHotkeys(const Value: TMenuItemAutoFlag);
    function GetAutoHotkeys: Boolean;
  protected
    procedure ActionChange(Sender: TObject; CheckDefaults: Boolean); dynamic;
    procedure AssignTo(Dest: TPersistent); override;
    procedure BitmapChanged(Sender: TObject);
    function FindItem(ItemID: Integer): TMenuItem;
    function GetActionLinkClass: TMenuActionLinkClass; dynamic;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure Loaded; override;
    procedure CreateWidget; override;
    procedure DestroyWidget; override;
    function GetBitmap: TBitmap;
    function GetImageList: TCustomImageList;
    function MenuItemHandle: QMenuItemH;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure Highlighted; virtual;
    procedure HookEvents; override;
    procedure InvokeHelp; override;
    function InsertNewLine(ABefore: Boolean; AItem: TMenuItem): Integer;
    procedure MenuChanged(Rebuild: Boolean); virtual;
    procedure SetChildOrder(Child: TComponent; Order: Integer); override;
    procedure SetParentComponent(Value: TComponent); override;
    procedure Show; dynamic;
    function Showing: Boolean;
    function DisplayBitmap: Boolean;
    procedure WidgetDestroyed; override;
    property ActionLink: TMenuActionLink read FActionLink write FActionLink;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure InitiateAction; virtual;
    procedure Add(Item: TMenuItem); overload;
    procedure Add(const AItems: array of TMenuItem); overload;
    procedure Clear;
    procedure Click; virtual;
    procedure Delete(Index: Integer);
    function Find(const ACaption: WideString): TMenuItem; overload;
    function Find(AHandle: QMenuItemH): TMenuItem; overload;
    function GetParentComponent: TComponent; override;
    function GetParentMenu: TMenu;
    function HasBitmap: Boolean;
    function HasParent: Boolean; override;
    function IndexOf(Item: TMenuItem): Integer;
    function MenuData: QMenuDataH;
    procedure Insert(Index: Integer; Item: TMenuItem);
    function InsertNewLineBefore(AItem: TMenuItem): Integer;
    function InsertNewLineAfter(AItem: TMenuItem): Integer;
    function IsLine: Boolean;
    procedure Remove(Item: TMenuItem);
    function RethinkHotkeys: Boolean;
    property ID: Integer read FID;
    property Count: Integer read GetCount;
    property Handle: QPopupMenuH read GetHandle;
    property Items[Index: Integer]: TMenuItem read GetItem; default;
    property MenuIndex: Integer read GetMenuIndex write SetMenuIndex;
    property Parent: TMenuItem read FParent;
  published
    property Action: TBasicAction read GetAction write SetAction;
    property AutoHotkeys: TMenuItemAutoFlag read FAutoHotkeys write SetAutoHotkeys default maParent;
    property Bitmap: TBitmap read GetBitmap write SetBitmap stored IsBitmapStored;
    property Caption: WideString read FCaption write SetCaption stored IsCaptionStored;
    property Checked: Boolean read FChecked write SetChecked stored IsCheckedStored default False;
    property Enabled: Boolean read FEnabled write SetEnabled stored IsEnabledStored default True;
    property GroupIndex: Byte read FGroupIndex write SetGroupIndex default 0;
    property Hint: WideString read FHint write FHint stored IsHintStored;
    property ImageIndex: TImageIndex read FImageIndex write SetImageIndex stored IsImageIndexStored default -1;
    property RadioItem: Boolean read FRadioItem write SetRadioItem default False;
    property ShortCut: TShortCut read FShortCut write SetShortCut stored IsShortCutStored default 0;
    property Visible: Boolean read FVisible write SetVisible stored IsVisibleStored default True;
    property OnClick: TNotifyEvent read FOnClick write FOnClick stored IsOnClickStored;
    property OnHighlighted: TNotifyEvent read FOnHighlighted write FOnHighlighted;
    property OnShow: TNotifyEvent read FOnShow write FOnShow;
    property HelpKeyword stored IsHelpContextStored;
    property HelpType stored IsHelpContextStored;
    property HelpContext stored IsHelpContextStored;
  end;

  TFindItemKind = (fkID, fkHandle, fkShortCut);

  TMenu = class(THandleComponent)
  private
    FOnChange: TMenuChangeEvent;
    FItems: TMenuItem;
    FPalette: TWidgetPalette;
    FColor: TColor;
    FImages: TCustomImageList;
    FImageChangeLink: TChangeLink;
    procedure ActivatedHook(ItemID: Integer); cdecl;
    procedure ImageListChange(Sender: TObject);
    procedure HighlightedHook(ItemID: Integer); {$IFDEF MSWINDOWS} virtual; {$ENDIF} cdecl;
    procedure SetColor(const Value: TColor);
    procedure SetImages(const Value: TCustomImageList);
    procedure UpdateItemImages;
    function GetAutoHotkeys: TMenuAutoFlag;
    procedure SetAutoHotkeys(const Value: TMenuAutoFlag);
    function IsBitmapStored: Boolean;
    function GetBitmap: TBitmap;
  protected
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure Loaded; override;
    procedure MenuChanged(Sender: TObject; Source: TMenuItem; Rebuild: Boolean); virtual;
    function MenuDataHandle: QMenuDataH; virtual; abstract;
    procedure DoChange(Source: TMenuItem; Rebuild: Boolean); virtual;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure PaletteChanged(Sender: TObject); virtual;
    procedure SetBitmap(Value: TBitmap); virtual;
    procedure SetChildOrder(Child: TComponent; Order: Integer); override;
    property AutoHotkeys: TMenuAutoFlag read GetAutoHotkeys write SetAutoHotkeys default maAutomatic;
    property Bitmap: TBitmap read GetBitmap write SetBitmap stored IsBitmapStored;
    property Color: TColor read FColor write SetColor default clButton;
    property OnChange: TMenuChangeEvent read FOnChange write FOnChange;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function FindItem(Value: Integer; Kind: TFindItemKind): TMenuItem;
    function IsShortCut(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; virtual;
    procedure SetForm(Value: TObject);
    property Images: TCustomImageList read FImages write SetImages;
  published
    property Items: TMenuItem read FItems;
  end;

  TMainMenu = class(TMenu)
  private
    FAutoMerge: Boolean;
    function GetHandle: QMenuBarH;
    procedure ItemChanged;
    procedure SetAutoMerge(const Value: Boolean);
  protected
    procedure CreateWidget; override;
    procedure HookEvents; override;
    procedure MenuChanged(Sender: TObject; Source: TMenuItem; Rebuild: Boolean); override;
    function MenuDataHandle: QMenuDataH; override;
  public
    property Handle: QMenuBarH read GetHandle;
    function IsShortCut(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; override;
    procedure Merge(Menu: TMainMenu);
    procedure Unmerge(Menu: TMainMenu);
  published
    property AutoHotkeys;
    property AutoMerge: Boolean read FAutoMerge write SetAutoMerge default False;
    property Color;
    property Bitmap;
    property Images;
    property OnChange;
    property HelpType;
    property HelpKeyword;
    property HelpContext;
  end;

  TPopupAlignment = (paLeft, paRight, paCenter);

  TPopupMenu = class(TMenu)
  private
    FPopupPoint: TPoint;
    FAlignment: TPopupAlignment;
    FAutoPopup: Boolean;
    FPopupComponent: TComponent;
{$IFDEF MSWINDOWS}
    FCurrentItem: TMenuItem; // include in CLX 2.0
{$ENDIF}
    FOnPopup: TNotifyEvent;
    function GetHandle: QPopupMenuH;
{$IFDEF MSWINDOWS}
    procedure HighlightedHook(ItemID: Integer); override; cdecl; // include in CLX 2.0
{$ENDIF}
    procedure ShowHook; cdecl;
  protected
    function MenuDataHandle: QMenuDataH; override;
    procedure CreateWidget; override;
    procedure DoPopup(Sender: TObject); virtual;
    procedure HookEvents; override;
{$IFDEF MSWINDOWS}
    procedure InvokeHelp; override;
{$ENDIF}
  public
    constructor Create(AOwner: TComponent); override;
    procedure Popup(X, Y: Integer); virtual;
    property PopupComponent: TComponent read FPopupComponent write FPopupComponent;
    property Handle: QPopupMenuH read GetHandle;
  published
    property Alignment: TPopupAlignment read FAlignment write FAlignment default paLeft;
    property AutoHotkeys;
    property AutoPopup: Boolean read FAutoPopup write FAutoPopup default True;
    property Color;
    property Bitmap;
    property HelpContext;
    property HelpKeyword;
    property HelpType;
    property Images;
    property OnChange;
    property OnPopup: TNotifyEvent read FOnPopup write FOnPopup;
  end;

  PMenuItem = ^TMenuItem;

  TMenuItemStack = class(TStack)
  public
    procedure ClearItem(AItem: TMenuItem);
  end;

const
  cHotkeyPrefix = '&';
  cLineCaption = '-';
  cDialogSuffix = '...';

var
  { These are the hotkeys that the auto-hotkey system will pick from.
    Change this global variable at runtime if you want to add or remove
    characters from the available characters.  Notice that by default we
    do not do international characters. }
  ValidMenuHotkeys: string = '1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ'; { do not localize }
  ShortCutItems: TMenuItemStack;

  { StripHotkey removes the & escape char that marks the hotkey character(s) in
  the string.  When the current locale is a Far East locale, this function also
  looks for and removes parens around the hotkey, common in Far East locales. }
function StripHotkey(const Text: WideString): WideString;

{ GetHotkey will return the last hotkey that StripHotkey would strip. }
function GetHotkey(const Text: WideString): WideString;

{ Similar to AnsiSameText but strips hotkeys before comparing }
function AnsiSameCaption(const Text1, Text2: string): Boolean;
function WideSameCaption(const Text1, Text2: WideString): Boolean;

function ShortCut(Key: Word; Shift: TShiftState): TShortCut;
procedure ShortCutToKey(ShortCut: TShortCut; var Key: Word; var Shift: TShiftState);
function ShortCutToText(ShortCut: TShortCut): WideString;
function TextToShortCut(const AText: string): TShortCut;

function NewMenu(Owner: TComponent; const AName: string;
  const Items: array of TMenuItem): TMainMenu;
function NewPopupMenu(Owner: TComponent; const AName: string;
  Alignment: TPopupAlignment; AutoPopup: Boolean;
  const Items: array of TMenuitem): TPopupMenu;
function NewSubMenu(const ACaption: WideString; hCtx: THelpContext;
  const AName: string; const Items: array of TMenuItem;
  AEnabled: Boolean = True): TMenuItem;
function NewItem(const ACaption: WideString; AShortCut: TShortCut;
  AChecked, AEnabled: Boolean; AOnClick: TNotifyEvent; hCtx: THelpContext;
  const AName: string): TMenuItem;
function NewLine: TMenuItem;

implementation

{$IFDEF LINUX}
uses
  QForms, QConsts, QControls, Libc;
{$ENDIF}
{$IFDEF MSWINDOWS}
uses
  QForms, QConsts, QControls;
{$ENDIF}

const
  cMenuAutoFlagToItem: array [TMenuAutoFlag] of TMenuItemAutoFlag = (maAutomatic, maManual);
  cItemAutoFlagToMenu: array [TMenuItemAutoFlag] of TMenuAutoFlag = (maAutomatic, maManual, maAutomatic);
  cBooleanToItemAutoFlag: array [Boolean] of TMenuItemAutoFlag = (maManual, maAutomatic);
  cItemAutoFlagToBoolean: array [TMenuItemAutoFlag] of Boolean = (True, False, True);

function ShortCutFlags(ShortCut: TShortCut): Integer;
begin
  Result := ShortCut and KeyMask;
  if scShift and ShortCut = scShift then Result := Result or Integer(Modifier_SHIFT);
  if scCtrl and ShortCut = scCtrl then Result := Result or Integer(Modifier_CTRL);
  if scAlt and ShortCut = scAlt then Result := Result or Integer(Modifier_ALT);
end;

function StripHotkey(const Text: WideString): WideString;
var
  I: Integer;
begin
  Result := Text;
  for I := Length(Result) downto 1 do
    if Result[I] = cHotkeyPrefix then
      if SysLocale.FarEast and ((I > 2) and (Length(Result) - I >= 2) and
        (Result[I - 1] = '(') and (Result[I + 2] = ')')) then
        Delete(Result, I - 1, 4)
      else
        Delete(Result, I, 1);
end;

function GetHotkey(const Text: WideString): WideString;
var
  I, L: Integer;
begin
  Result := '';
  I := 1;
  L := Length(Text) - 1;
  while I <= L do
  begin
    if Text[I] = cHotkeyPrefix then
    begin
      Inc(I);
      if Text[I] <> cHotkeyPrefix then
        Result := Text[I];  { keep going there may be another one }
    end;
    Inc(I);
  end;
end;

function AnsiSameCaption(const Text1, Text2: string): Boolean;
begin
  Result := AnsiSameText(StripHotkey(Text1), StripHotkey(Text2));
end;

function WideSameCaption(const Text1, Text2: WideString): Boolean;
begin
  Result := WideSameText(StripHotkey(Text1), StripHotkey(Text2));
end;

{ Menu building functions }

procedure InitMenuItems(AMenu: TMenu; const Items: array of TMenuItem);
var
  I: Integer;

  procedure SetOwner(Item: TMenuItem);
  var
    I: Integer;
  begin
    if Item.Owner <> nil then AMenu.Owner.InsertComponent(Item);
    for I := 0 to Item.Count - 1 do
      SetOwner(Item[I]);
  end;

begin
  for I := Low(Items) to High(Items) do
  begin
    SetOwner(Items[I]);
    AMenu.FItems.Add(Items[I]);
  end;
end;

function NewMenu(Owner: TComponent; const AName: string;
  const Items: array of TMenuItem): TMainMenu;
begin
  Result := TMainMenu.Create(Owner);
  Result.Name := AName;
  InitMenuItems(Result, Items);
end;

function NewPopupMenu(Owner: TComponent; const AName: string;
  Alignment: TPopupAlignment; AutoPopup: Boolean;
  const Items: array of TMenuItem): TPopupMenu;
begin
  Result := TPopupMenu.Create(Owner);
  Result.Name := AName;
  Result.AutoPopup := AutoPopup;
  Result.Alignment := Alignment;
  InitMenuItems(Result, Items);
end;

{ should this also take a help string, maybe? APH }
function NewSubMenu(const ACaption: WideString; hCtx: THelpContext;
  const AName: string; const Items: array of TMenuItem;
  AEnabled: Boolean): TMenuItem;
var
  I: Integer;
begin
  Result := TMenuItem.Create(nil);
  for I := Low(Items) to High(Items) do
    Result.Add(Items[I]);
  Result.Caption := ACaption;
  Result.HelpContext := hCtx;
  Result.Name := AName;
  Result.Enabled := AEnabled;
end;

{ should this also take a help string, maybe? APH }
function NewItem(const ACaption: WideString; AShortCut: TShortCut;
  AChecked, AEnabled: Boolean; AOnClick: TNotifyEvent; hCtx: THelpContext;
  const AName: string): TMenuItem;
begin
  Result := TMenuItem.Create(nil);
  with Result do
  begin
    Caption := ACaption;
    ShortCut := AShortCut;
    OnClick := AOnClick;
    HelpContext := hCtx;
    Checked := AChecked;
    Enabled := AEnabled;
    Name := AName;
  end;
end;

function NewLine: TMenuItem;
begin
  Result := TMenuItem.Create(nil);
  Result.Caption := cLineCaption;
end;

{ TShortCut processing routines }

function ShortCut(Key: Word; Shift: TShiftState): TShortCut;
begin
  Result := 0;
  if (WordRec(Key).Hi <> 0) and not ((Key >= Key_Word_Lower) and (Key <= Key_Word_Upper)) then
    Exit;
  Result := Key;
  if ssShift in Shift then Inc(Result, scShift);
  if ssCtrl in Shift then Inc(Result, scCtrl);
  if ssAlt in Shift then Inc(Result, scAlt);
end;

procedure ShortCutToKey(ShortCut: TShortCut; var Key: Word; var Shift: TShiftState);
begin
  Key := ShortCut and not (scShift + scCtrl + scAlt);
  Shift := [];
  if ShortCut and scShift <> 0 then Include(Shift, ssShift);
  if ShortCut and scCtrl <> 0 then Include(Shift, ssCtrl);
  if ShortCut and scAlt <> 0 then Include(Shift, ssAlt);
end;

type
  TMenuKeyCap = (mkcEsc, mkcTab, mkcBackTab, mkcBksp, mkcReturn, mkcEnter, mkcIns,
    mkcDel, mkcHome, mkcEnd, mkcLeft, mkcUp, mkcRight, mkcDown, mkcPgUp,
    mkcPgDn, mkcShift, mkcCtrl, mkcAlt, mkcSpace);

var
  MenuKeyCaps: array[TMenuKeyCap] of string = (
    SmkcEsc, SmkcTab, SmkcBackTab, SmkcBksp, SmkcReturn, SmkcEnter, SmkcIns,
    SmkcDel, SmkcHome, SmkcEnd, SmkcLeft, SmkcUp, SmkcRight, SmkcDown, SmkcPgUp,
    SmkcPgDn, SmkcShift, SmkcCtrl, SmkcAlt, SmkcSpace);

function ShortCutToText(ShortCut: TShortCut): WideString;
var
  Name: string;
  Key: Integer;
begin
  Key := ShortCut and KeyMask;
  case Key of
    Key_Escape..Key_Delete:
      Name := MenuKeyCaps[TMenuKeyCap(Integer(Key) - Integer(Key_Escape))];
    Key_Home..Key_Next:
      Name := MenuKeyCaps[TMenuKeyCap(Integer(Key) - Integer(Key_Home) + Ord(mkcHome))];
    Key_F1..Key_F35:
      Name := 'F' + IntToStr(Integer(Key) - Integer(Key_F1) + 1);
    Key_Space:
      Name := MenuKeyCaps[mkcSpace];
    Key_Exclam..Key_QuoteLeft, Key_BraceLeft..Key_AsciiTilde:
      Name := Chr(Key);
    $61..$7A:
      Name := Chr(Key - $20);
  end;
  if Name <> '' then
  begin
    Result := '';
    if ShortCut and scCtrl <> 0 then Result := Result + MenuKeyCaps[mkcCtrl];
    if ShortCut and scAlt <> 0 then Result := Result + MenuKeyCaps[mkcAlt];
    if ShortCut and scShift <> 0 then Result := Result + MenuKeyCaps[mkcShift];
    Result := Result + Name;
  end
  else Result := '';
end;

{ This function is *very* slow.  Use sparingly.  Return 0 if no VK code was
  found for the text }

function TextToShortCut(const AText: string): TShortCut;

  { If the front of Text is equal to Front then remove the matching piece
    from Text and return True, otherwise return False }

  function CompareFront(var Text: string; const Front: string): Boolean;
  begin
    Result := False;
    if (Length(Text) >= Length(Front)) and
      (AnsiStrLIComp(PChar(Text), PChar(Front), Length(Front)) = 0) then
    begin
      Result := True;
      Delete(Text, 1, Length(Front));
    end;
  end;

var
  Key: TShortCut;
  Shift: TShortCut;
  Text: string;
begin
  Result := 0;
  Shift := 0;
  Text := AText;
  while True do
  begin
    if CompareFront(Text, MenuKeyCaps[mkcShift]) then Shift := Shift or scShift
    else if CompareFront(Text, '^') then Shift := Shift or scCtrl
    else if CompareFront(Text, MenuKeyCaps[mkcCtrl]) then Shift := Shift or scCtrl
    else if CompareFront(Text, MenuKeyCaps[mkcAlt]) then Shift := Shift or scAlt
    else Break;
  end;
  if Text = '' then Exit;
  { bounds of these loops may change if Qt::Key enum changes. }
  for Key := TShortCut(Key_Space) to TShortCut(Key_AsciiTilde) do { Copy range from table in ShortCutToText }
    if AnsiCompareText(Text, ShortCutToText(Key)) = 0 then
    begin
      Result := Key or Shift;
      Exit;
    end;

  for Key := TShortCut(Key_Escape) to TShortCut(Key_Hyper_R) do { Copy range from table in ShortCutToText }
    if AnsiCompareText(Text, ShortCutToText(Key)) = 0 then
    begin
      Result := Key or Shift;
      Exit;
    end;
end;

{ Used to populate or merge menus }

procedure IterateMenus(Func: Pointer; Menu1, Menu2: TMenuItem);
var
  I, J: Integer;
  IIndex, JIndex: Byte;
  Menu1Size, Menu2Size: Integer;
  Done: Boolean;

  function Iterate(var I: Integer; MenuItem: TMenuItem; AFunc: Pointer): Boolean;
  var
    Item: TMenuItem;
  begin
    if MenuItem = nil then Exit;
    Result := False;
    while not Result and (I < MenuItem.Count) do
    begin
      Item := MenuItem[I];
      if Item.GroupIndex > IIndex then Break;
      asm
                MOV     EAX,Item
                MOV     EDX,[EBP+8]
                PUSH    DWORD PTR [EDX]
                CALL    DWORD PTR AFunc
                ADD     ESP,4
                MOV     Result,AL
      end;
      Inc(I);
    end;
  end;

begin
  I := 0;
  J := 0;
  Menu1Size := 0;
  Menu2Size := 0;
  if Menu1 <> nil then Menu1Size := Menu1.Count;
  if Menu2 <> nil then Menu2Size := Menu2.Count;
  Done := False;
  while not Done and ((I < Menu1Size) or (J < Menu2Size)) do
  begin
    IIndex := High(Byte);
    JIndex := High(Byte);
    if (I < Menu1Size) then IIndex := Menu1[I].GroupIndex;
    if (J < Menu2Size) then JIndex := Menu2[J].GroupIndex;
    if IIndex <= JIndex then Done := Iterate(I, Menu1, Func)
    else
    begin
      IIndex := JIndex;
      Done := Iterate(J, Menu2, Func);
    end;
    while (I < Menu1Size) and (Menu1[I].GroupIndex <= IIndex) do Inc(I);
    while (J < Menu2Size) and (Menu2[J].GroupIndex <= IIndex) do Inc(J);
  end;
end;

procedure Error(ResStr: PResStringRec);

  function ReturnAddr: Pointer;
  asm
          MOV     EAX,[ESP+8]
  end;

begin
  raise EMenuError.CreateRes(ResStr) at ReturnAddr;
end;

{ TMenuItemStack }

procedure TMenuItemStack.ClearItem(AItem: TMenuItem);
var
  I: Integer;
begin
  for I := 0 to List.Count - 1 do
    if PMenuItem(List[I])^ = AItem then
      PMenuItem(List[I])^ := nil;
end;

{ TMenuActionLink }

procedure TMenuActionLink.AssignClient(AClient: TObject);
begin
  FClient := AClient as TMenuItem;
end;

function TMenuActionLink.IsCaptionLinked: Boolean;
begin
  Result := inherited IsCaptionLinked and
    WideSameCaption(FClient.Caption, (Action as TCustomAction).Caption);
end;

function TMenuActionLink.IsCheckedLinked: Boolean;
begin
  Result := inherited IsCheckedLinked and
    (FClient.Checked = (Action as TCustomAction).Checked);
end;

function TMenuActionLink.IsEnabledLinked: Boolean;
begin
  Result := inherited IsEnabledLinked and
    (FClient.Enabled = (Action as TCustomAction).Enabled);
end;

function TMenuActionLink.IsHelpLinked: Boolean;
begin
  Result := inherited IsHelpLinked and
    (FClient.HelpContext = (Action as TCustomAction).HelpContext) and
    (FClient.HelpKeyWord = (Action as TCustomAction).HelpKeyword) and
    (FClient.HelpType = (Action as TCustomAction).HelpType);
end;

function TMenuActionLink.IsHintLinked: Boolean;
begin
  Result := inherited IsHintLinked and
    (FClient.Hint = (Action as TCustomAction).Hint);
end;

function TMenuActionLink.IsImageIndexLinked: Boolean;
begin
  Result := inherited IsImageIndexLinked and
    (FClient.ImageIndex = (Action as TCustomAction).ImageIndex);
end;

function TMenuActionLink.IsShortCutLinked: Boolean;
begin
  Result := inherited IsShortCutLinked and
    (FClient.ShortCut = (Action as TCustomAction).ShortCut);
end;

function TMenuActionLink.IsVisibleLinked: Boolean;
begin
  Result := inherited IsVisibleLinked and
    (FClient.Visible = (Action as TCustomAction).Visible);
end;

function TMenuActionLink.IsOnExecuteLinked: Boolean;
begin
  Result := inherited IsOnExecuteLinked and
    (@FClient.OnClick = @Action.OnExecute);
end;

procedure TMenuActionLink.SetCaption(const Value: TCaption);
begin
  if IsCaptionLinked then FClient.Caption := Value;
end;

procedure TMenuActionLink.SetChecked(Value: Boolean);
begin
  if IsCheckedLinked then FClient.Checked := Value;
end;

procedure TMenuActionLink.SetEnabled(Value: Boolean);
begin
  if IsEnabledLinked then FClient.Enabled := Value;
end;

procedure TMenuActionLink.SetHelpContext(Value: THelpContext);
begin
  if IsHelpLinked then FClient.HelpContext := Value;
end;

procedure TMenuActionLink.SetHelpKeyword(const Value: string);
begin
  if IsHelpLinked then FCLient.HelpKeyword := Value;
end;

procedure TMenuActionLink.SetHelpType(Value: THelpType);
begin
  if IsHelpLinked then FClient.HelpType := Value;
end;

procedure TMenuActionLink.SetHint(const Value: WideString);
begin
  if IsHintLinked then FClient.Hint := Value;
end;

procedure TMenuActionLink.SetImageIndex(Value: Integer);
begin
   if IsImageIndexLinked then FClient.ImageIndex := Value;
end;

procedure TMenuActionLink.SetShortCut(Value: TShortCut);
begin
  if IsShortCutLinked then FClient.ShortCut := Value;
end;

procedure TMenuActionLink.SetVisible(Value: Boolean);
begin
  if IsVisibleLinked then FClient.Visible := Value;
end;

procedure TMenuActionLink.SetOnExecute(Value: TNotifyEvent);
begin
  if IsOnExecuteLinked then FClient.OnClick := Value;
end;

{ TMenuItem }

procedure TMenuItem.ActivatedHook(ItemID: Integer);
var
  Item: TMenuItem;
begin
  try
    Item := FindItem(ItemID);
    if Item <> nil then
      QApplication_postEvent(Handle, QCustomEvent_create(QEventType_MenuClick, Item));
  except
    Application.HandleException(Self);
  end;
end;

procedure TMenuItem.Add(const AItems: array of TMenuItem);
var
  I: Integer;
begin
  for I := Low(AItems) to High(AItems) do
    Add(AItems[I]);
end;

procedure TMenuItem.BitmapChanged(Sender: TObject);
begin
  if (csLoading in ComponentState) and (Sender <> nil) and not
    (Sender as TBitmap).Transparent then
    (Sender as TBitmap).Transparent := True;
  if DisplayBitmap then
    ChangePixmap((Sender as TBitmap).Handle);
end;

function TMenuItem.GetAutoHotkeys: Boolean;
var
  LAuto: TMenuItemAutoFlag;
begin
  LAuto := FAutoHotkeys;
  if (LAuto = maParent) and
     (Parent <> nil) then
    LAuto := cBooleanToItemAutoFlag[Parent.GetAutoHotkeys];
  Result := cItemAutoFlagToBoolean[LAuto];
end;

procedure TMenuItem.ItemHandleNeeded;
begin
  if (FMenuItemHandle = nil) and (Parent <> nil) then
  begin
    FMenuItemHandle := QMenuData_findItem(Parent.MenuData, FID);
    if FMenuItemHandle <> nil then
      QClxObjectMap_add(Pointer(FMenuItemHandle), Integer(Self));
  end;
end;

function TMenuItem.MenuItemHandle: QMenuItemH;
begin
  Result := FMenuItemHandle;
end;

procedure TMenuItem.InitiateAction;
begin
  if FActionLink <> nil then FActionLink.Update;
end;

function TMenuItem.InternalRethinkHotkeys(ForceRethink: Boolean): Boolean;
var
  LDid, LDoing, LToDo, LBest: TStringList;
  I, LIteration, LColumn, LAt, LBestCount: Integer;
  LChar, LCaption, LOrigAvailable, LAvailable, LBestAvailable: WideString;

  function IfHotkeyAvailable(const AHotkey: WideString): Boolean;
  var
    At: Integer;
  begin
    At := Pos(AHotkey, LAvailable);
    Result := At <> 0;
    if Result then
      System.Delete(LAvailable, At, 1);
  end;

  procedure CopyToBest;
  var
    I: Integer;
  begin
    LBest.Assign(LDid);
    LBestCount := LDid.Count;
    for I := 0 to LDoing.Count - 1 do
      LBest.AddObject(TMenuItem(LDoing.Objects[I]).FCaption, LDoing.Objects[I]);
    LBestAvailable := LAvailable;
  end;

  procedure InsertHotkeyFarEastFormat(var ACaption: WideString;
    const AHotKey: WideString; AColumn: Integer);
  var
    NonLatinCaption: Boolean;
    I: Integer;
  begin
    NonLatinCaption := False;
    for I := 1 to Length(ACaption) do
      if Integer(ACaption[I]) > $255 then
      begin
        NonLatinCaption := True;
        Break;
      end;
    if NonLatinCaption then
    begin
      if Copy(ACaption, (Length(ACaption) - Length(cDialogSuffix)) + 1, Length(cDialogSuffix)) = cDialogSuffix then
        ACaption := Copy(ACaption, 1, Length(ACaption) - Length(cDialogSuffix)) +
          '(' + cHotkeyPrefix + AHotKey + ')' + cDialogSuffix
      else
        ACaption := ACaption + '(' + cHotkeyPrefix + AHotKey + ')';
    end
    else if AColumn <> 0 then
      System.Insert(cHotkeyPrefix, ACaption, AColumn);
  end;

begin
  Result := False;
  if ForceRethink or (not (csDesigning in ComponentState) and GetAutoHotkeys) then
  begin
    LAvailable := ValidMenuHotkeys;
    LDid := nil;
    LDoing := nil;
    LToDo := nil;
    LBest := nil;
    LBestCount := 0;
    try
      LDid := TStringList.Create;
      LDoing := TStringList.Create;
      LToDo := TStringList.Create;
      LBest := TStringList.Create;
      for I := 0 to Count - 1 do
        if Items[I].Visible and
           (Items[I].FCaption <> cLineCaption) and
           (Items[I].FCaption <> '') then
        begin
          LChar := Uppercase(GetHotkey(Items[I].FCaption));
          if LChar = '' then
            LToDo.InsertObject(0, Items[I].FCaption, Items[I])
          else if (AnsiPos(LChar, ValidMenuHotkeys) <> 0) and
                  not IfHotkeyAvailable(LChar) then
          begin
            Items[I].FCaption := StripHotkey(Items[I].FCaption);
            LToDo.InsertObject(0, Items[I].FCaption, Items[I]);
          end;
        end;
      LOrigAvailable := LAvailable;
      for LIteration := 0 to LToDo.Count - 1 do
      begin
        LAvailable := LOrigAvailable;
        LDoing.Assign(LToDo);
        LDid.Clear;
        for I := LDoing.Count - 1 downto 0 do
        begin
          LCaption := LDoing[I];
          LColumn := 1;
          while LColumn <= Length(LCaption) do
          begin
            LChar := Uppercase(Copy(LCaption, LColumn, 1));
            if IfHotkeyAvailable(LChar) then
            begin
              if SysLocale.FarEast then
                InsertHotkeyFarEastFormat(LCaption, LChar, LColumn)
              else
                System.Insert(cHotkeyPrefix, LCaption, LColumn);
              LDid.AddObject(LCaption, LDoing.Objects[I]);
              LDoing.Delete(I);
              System.Break;
            end;
            Inc(LColumn);
          end;
        end;
        if LDid.Count > LBestCount then
          CopyToBest;
        if LDoing.Count > 0 then
          for I := 0 to LDoing.Count - 1 do
          begin
            LAt := LToDo.IndexOfObject(LDoing.Objects[I]);
            LToDo.Move(LAt, LToDo.Count - 1);
          end
        else
          System.Break;
      end;
      if LBestCount = 0 then
        CopyToBest;
      Result := LBest.Count > 0;
      for I := 0 to LBest.Count - 1 do
      begin
        LCaption := LBest[I];
        if SysLocale.FarEast and (Pos(cHotkeyPrefix, LCaption) = 0)
          and (LBestAvailable <> '') then
        begin
          if Pos(cHotkeyPrefix, LCaption) = 0 then
          begin
            InsertHotkeyFarEastFormat(LCaption, Copy(LBestAvailable, Length(LBestAvailable), 1), 0);
            System.Delete(LBestAvailable, length(LBestAvailable), 1);
          end;
        end;
        TMenuItem(LBest.Objects[I]).Caption := LCaption;
      end;
    finally
      LBest.Free;
      LToDo.Free;
      LDoing.Free;
      LDid.Free;
    end;
  end;
end;

function TMenuItem.RethinkHotkeys: Boolean;
begin
  Result := InternalRethinkHotkeys(True);
  if Result then
    MenuChanged(False);
end;

procedure TMenuItem.RemoveItemHandle;
begin
  if FMenuItemHandle <> nil then
  begin
    QClxObjectMap_remove(FMenuItemHandle);
    FMenuItemHandle := nil;
  end;
end;

procedure TMenuItem.SetAutoHotkeys(const Value: TMenuItemAutoFlag);
begin
  if Value <> FAutoHotkeys then
  begin
    FAutoHotkeys := Value;
    MenuChanged(True);
  end;
end;

procedure TMenuItem.Add(Item: TMenuItem);
begin
  Insert(GetCount, Item);
end;

procedure TMenuItem.Clear;
var
  I: Integer;
begin
  for I := Count - 1 downto 0 do
    Items[I].Free;
end;

procedure TMenuItem.Click;
begin
  if Enabled then
  begin
    { Call OnClick if assigned and not equal to associated action's OnExecute.
      If associated action's OnExecute assigned then call it, otherwise, call
      OnClick. }
    try
      if Assigned(FOnClick) and (Action <> nil) and (@FOnClick <> @Action.OnExecute) then
        FOnClick(Self)
      else if not (csDesigning in ComponentState) and (ActionLink <> nil) then
        FActionLink.Execute
      else if Assigned(FOnClick) then
        FOnClick(Self);
    except
      Application.HandleException(Self);
    end;
  end;
end;

constructor TMenuItem.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FChecked := False;
  FAutoHotkeys := maParent;
  FVisible := True;
  FEnabled := True;
  FGroupIndex := 0;
  FShortCut := 0;
  FImageIndex := -1;
  FRadioItem := False;
end;

function TMenuItem.GetBitmap: TBitmap;
begin
  if FBitmap = nil then
  begin
    FBitmap := TBitmap.Create;
    FBitmap.OnChange := BitmapChanged;
  end;
  Result := FBitmap;
end;

procedure TMenuItem.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do Proc(Items[I]);
end;

procedure TMenuItem.SetChildOrder(Child: TComponent; Order: Integer);
begin
  (Child as TMenuItem).MenuIndex := Order;
end;

procedure TMenuItem.Loaded;
begin
  inherited Loaded;
  if Action <> nil then ActionChange(Action, True);
  if DisplayBitmap then ChangePixmap(FBitmap.Handle);
  if Count > 0 then InternalRethinkHotkeys(False);
end;

procedure TMenuItem.CreateWidget;
begin
  FHandle := QPopupMenu_create(ParentWidget, nil);
  if FMenu = nil then
    FMenuData := QPopupMenu_to_QMenuData(Handle);
  Hooks := QPopupMenu_hook_create(Handle);
  QWidget_setFocusPolicy(QWidgetH(Handle), QWidgetFocusPolicy_NoFocus);
end;

procedure TMenuItem.Delete(Index: Integer);
var
  Cur: TMenuItem;
begin
  if (Index < 0) or (FItems = nil) or (Index >= GetCount) then Error(@SMenuIndexError);
  Cur := FItems[Index];
  if not (csDestroying in ComponentState) and (Index >= 0) then
  begin
    Cur.RemoveItemHandle;
    if Showing and (Cur.ID < 0) then
    begin
      QMenuData_removeItem(MenuData, Cur.ID);
      Cur.FID := 0;
    end;
  end;
  if Cur.FMergedWith = nil then
  begin
    Cur.FParent := nil;
    Cur.FOnChange := nil;
  end;
  FItems.Delete(Index);
  if not (csDestroying in ComponentState) and (Index >= 0) then
    MenuChanged((VisibleCount = 0) and Visible);
end;

destructor TMenuItem.Destroy;
begin
  if Assigned(ShortCutItems) then
    ShortCutItems.ClearItem(Self);
  if FParent <> nil then
    FParent.Remove(Self);
  RemoveItemHandle;
  while Count > 0 do Items[0].Free;
  FItems.Free;
  FItems := nil;
  FreeAndNil(FActionLink);
  if Assigned(FBitmap) then FBitmap.Free;
  inherited Destroy;
end;

procedure TMenuItem.DestroyWidget;
var
  I: Integer;
begin
  if not Assigned(FHandle) then Exit;
  if Assigned(FItems) then
    for I := FItems.Count - 1 downto 0 do
      TMenuItem(FItems[I]).DestroyWidget;
  FMenuData := nil;
  inherited DestroyWidget;
end;

function TMenuItem.Find(const ACaption: WideString): TMenuItem;
var
  I: Integer;
  LCaption: WideString;
begin
  Result := nil;
  LCaption := StripHotkey(ACaption);
  for I := 0 to Count - 1 do
    if WideSameText(LCaption, StripHotkey(Items[I].Caption)) then
    begin
      Result := Items[I];
      Break;
    end;
end;

function TMenuItem.Find(AHandle: QMenuItemH): TMenuItem;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
    if AHandle = Items[I].FMenuItemHandle then
    begin
      Result := Items[I];
      Break;
    end;
end;

function TMenuItem.GetAction: TBasicAction;
begin
  if FActionLink <> nil then
    Result := FActionLink.Action else
    Result := nil;
end;

function TMenuItem.GetActionLinkClass: TMenuActionLinkClass;
begin
  Result := TMenuActionLink;
end;

function TMenuItem.GetCount: Integer;
begin
  if FItems = nil then Result := 0
  else Result := FItems.Count;
end;

function TMenuItem.GetHandle: QPopupMenuH;
begin
  HandleNeeded;
  Result := QPopupMenuH(FHandle);
end;

function TMenuItem.GetItem(Index: Integer): TMenuItem;
begin
  if FItems = nil then Error(@SMenuIndexError);
  Result := FItems[Index];
end;

function TMenuItem.GetMenuIndex: Integer;
begin
  Result := -1;
  if FParent <> nil then Result := FParent.IndexOf(Self);
end;

function TMenuItem.GetParentComponent: TComponent;
begin
  if (FParent <> nil) and (FParent.FMenu <> nil) then
    Result := FParent.FMenu else
    Result := FParent;
end;

function TMenuItem.GetParentMenu: TMenu;
var
  MenuItem: TMenuItem;
begin
  MenuItem := Self;
  while Assigned(MenuItem.FParent) do MenuItem := MenuItem.FParent;
  Result := MenuItem.FMenu;
end;

function TMenuItem.HasParent: Boolean;
begin
  Result := True;
end;

procedure TMenuItem.Highlighted;
begin
  if Enabled and Assigned(FOnHighlighted) then
    FOnHighlighted(Self);

  Application.Hint := GetLongHint(Hint);

  // The OnClick event should get fired whenever a submenu item is present
  if Count > 0 then Click;
end;

procedure TMenuItem.HighlightedHook(ItemID: Integer);
begin
  try
    FCurrentItem := FindItem(ItemID);
    if FCurrentItem <> nil then
    begin
      FCurrentItem.Highlighted;
      // Hotkeys need not be rethought if there are no submenu items
      if Count > 0 then FCurrentItem.InternalRethinkHotkeys(False);
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TMenuItem.HookEvents;
var
  Method: TMethod;
begin
  QPopupMenu_activated_Event(Method) := ActivatedHook;
  QPopupMenu_hook_hook_activated(QPopupMenu_hookH(Hooks), Method);
  QPopupMenu_highlighted_Event(Method) := HighlightedHook;
  QPopupMenu_hook_hook_highlighted(QPopupMenu_hookH(Hooks), Method);
  QPopupMenu_aboutToShow_Event(Method) := ShowHook;
  QPopupMenu_hook_hook_aboutToShow(QPopupMenu_hookH(Hooks), Method);
  inherited HookEvents;
end;

function TMenuItem.IndexOf(Item: TMenuItem): Integer;
begin
  Result := -1;
  if FItems <> nil then Result := FItems.IndexOf(Item);
end;

procedure TMenuItem.Insert(Index: Integer; Item: TMenuItem);
begin
  if (csDestroying in ComponentState) then Exit;
  if (FMerged = nil) and (Item.FParent <> nil) then Error(@SMenuReinserted);
  if Item = Self then Error(@SNoMenuRecursion);
  if FItems = nil then FItems := TList.Create;
  if (Index - 1 >= 0) and (Index - 1 < FItems.Count) then
    if Item.GroupIndex < TMenuItem(FItems[Index - 1]).GroupIndex then
      Item.GroupIndex := TMenuItem(FItems[Index - 1]).GroupIndex;
  VerifyGroupIndex(Index, Item.GroupIndex);

  FItems.Insert(Index, Item);
  Item.FParent := Self;
  Item.FOnChange := SubItemChanged;

  if not Item.Showing then Exit;

  { Recreate this item as a QPopupMenu so it can accept subitems. }
  { if Count = 1 then RebuildMenu; }
  MenuChanged(VisibleCount = 1);

  if (Item.FHandle <> nil) then
    { this item has sub items (or will) and needs to be inserted as a QPopupMenu) }
    Item.FID := QMenuData_insertItem(MenuData, @(Item.Caption), QPopupMenuH(Item.FHandle), -1, Index)
  else if not Item.IsLine then
  begin
    Item.FID := QMenuData_insertItem(MenuData, @(Item.FCaption), -1, Index);
    QMenuData_setAccel(MenuData, ShortCutFlags(Item.FShortCut), Item.FID);
  end
  else
    Item.FID := QMenuData_insertSeparator(MenuData, Index);

  if not Item.IsLine then
  begin
    if (Item.ImageIndex > -1) then
      Item.DoSetImageIndex(Item.ImageIndex)
    else if Item.DisplayBitmap then 
      Item.ChangePixmap(Item.FBitmap.Handle);
  end;

  Item.ItemHandleNeeded;
  if not Item.FEnabled then
    QMenuData_setItemEnabled(MenuData, Item.FID, False);
  if Item.FChecked then
    QMenuData_setItemChecked(MenuData, Item.FID, True);
  if ComponentState * [csLoading, csDesigning] = [] then
    InternalRethinkHotkeys(False);
end;

function TMenuItem.InsertNewLine(ABefore: Boolean; AItem: TMenuItem): Integer;
begin
  if AItem.Parent <> Self then
    Error(@SMenuNotFound);
  if ABefore then
  begin
    if (AItem.MenuIndex > 0) and
       Items[AItem.MenuIndex - 1].IsLine then
    begin
      Result := AItem.MenuIndex - 1;
      Items[AItem.MenuIndex - 1].Visible := True;
    end
    else
    begin
      Result := AItem.MenuIndex;
      Insert(AItem.MenuIndex, NewLine);
    end;
  end
  else
  begin
    if (AItem.MenuIndex < Count - 1) and
       Items[AItem.MenuIndex + 1].IsLine then
    begin
      Result := AItem.MenuIndex + 2;
      Items[AItem.MenuIndex + 1].Visible := True;
    end
    else
    begin
      Result := AItem.MenuIndex + 2;
      Insert(AItem.MenuIndex + 1, NewLine);
    end;
  end;
end;

function TMenuItem.InsertNewLineAfter(AItem: TMenuItem): Integer;
begin
  Result := InsertNewLine(False, AItem);
end;

function TMenuItem.InsertNewLineBefore(AItem: TMenuItem): Integer;
begin
  Result := InsertNewLine(True, AItem);
end;

procedure TMenuItem.InvokeHelp;
var
  Item: TMenuItem;
begin
  if FCurrentItem <> nil then
    Item := FCurrentItem
  else
    Item := Self;
  while Item <> nil do
  begin
    case Item.HelpType of
      htKeyword:
        if Item.HelpKeyword <> '' then
        begin
          Application.KeywordHelp(Item.HelpKeyword);
          Exit;
        end;
      htContext:
        if Item.HelpContext <> 0 then
        begin
          Application.ContextHelp(Item.HelpContext);
          Exit;
        end;
    end;
    Item := Item.Parent;
  end;
  GetParentMenu.InvokeHelp;
end;

function TMenuItem.IsLine: Boolean;
begin
  Result := FCaption = cLineCaption;
end;

procedure TMenuItem.MenuChanged(Rebuild: Boolean);
var
  Source: TMenuItem;
begin
  if Rebuild then
    RebuildMenu;
  if (Parent = nil) and (Owner is TMenu) then
    Source := nil else
    Source := Self;
  if Assigned(FOnChange) then FOnChange(Self, Source, Rebuild);
end;

function TMenuItem.MenuData: QMenuDataH;
begin
  HandleNeeded;
  Result := FMenuData;
end;

procedure TMenuItem.MergeWith(Menu: TMenuItem);

  procedure InsertMerged(Index: Integer; Item: TMenuItem);
  begin
    if Index < 0 then Index := 0;
    Item.FMergedWith := FMerged;
    FMenu.FItems.Insert(Index, Item);
  end;

var
  I, InsertAt, CurGroup: Integer;
  MergeItem,
  Item: TMenuItem;
begin
  if FMerged <> Menu then
  begin
    if FMerged <> nil then
      FMerged.FMergedWith := nil;
    FMerged := Menu;
    if FMerged <> nil then
    begin
      FMerged.FMergedWith := Self;
      FMerged.FreeNotification(Self);
    end;

    if FMerged <> nil then
    begin
      InsertAt := FMenu.Items.Count;
      I := FMerged.Count - 1;

      while I >= 0 do
      begin
        Item := nil;
        if InsertAt > 0 then
        begin
          Item := FMenu.Items[InsertAt-1];
          CurGroup := Item.GroupIndex;
        end
        else
          CurGroup := -1;
        MergeItem := FMerged.FMenu.Items[I];

        while MergeItem.GroupIndex > CurGroup do
        begin
          InsertMerged(InsertAt, MergeItem);
          Dec(I);
          if I >= 0 then
            MergeItem := FMerged.FMenu.Items[I]
          else
            Break;
        end;
        if MergeItem.GroupIndex = CurGroup then
        begin
          InsertMerged(InsertAt, MergeItem);
          while MergeItem.GroupIndex = CurGroup do
          begin
            Item.Visible := False;
            Dec(InsertAt);
            if InsertAt > 0 then
            begin
              Item := FMenu.Items[InsertAt-1];
              CurGroup := Item.GroupIndex;
            end else
              Break;
          end;
          Dec(I);
        end
        else
          Dec(InsertAt);
      end;
    end
    else begin
      for I := FMenu.FItems.Count - 1 downto 0 do
      begin
        Item := FMenu.Items[I];
        if Item.FMergedWith <> nil then
        begin
          FMenu.FItems.Remove(Item);
          Item.FParent := Item.FMergedWith;
          Item.FOnChange := Item.FMergedWith.SubItemChanged;
          Item.FMergedWith := nil;
        end;
      end;
      if not (csDestroying in FMenu.Owner.ComponentState) then
        for I := 0 to FMenu.FItems.Count - 1 do
          FMenu.FItems[I].Visible := True;
    end;
  end;
end;

procedure TMenuItem.RebuildMenu;
var
  ThisIndex: Integer;
  SaveParent: TMenuItem;
begin
  ThisIndex := GetMenuIndex;
  if ThisIndex < 0 then Exit;
  SaveParent := Parent;
  if VisibleCount > 0 then
  begin
    HandleNeeded;
    if (Parent <> nil) then
    begin
      Parent.Delete(ThisIndex);
      SaveParent.Insert(ThisIndex, Self);
    end;
  end
  else begin
    if Parent <> nil then Parent.Delete(ThisIndex);
    DestroyWidget;
    FParent := nil;
    SaveParent.Insert(ThisIndex, Self);
  end;
end;

procedure TMenuItem.Remove(Item: TMenuItem);
var
  I: Integer;
begin
  I := IndexOf(Item);
  if I = -1 then Error(@SMenuNotFound);
  Delete(I);
end;

procedure TMenuItem.SetAction(Value: TBasicAction);
begin
  if Value = nil then
  begin
    FActionLink.Free;
    FActionLink := nil;
  end
  else
  begin
    if FActionLink = nil then
      FActionLink := GetActionLinkClass.Create(Self);
    FActionLink.Action := Value;
    FActionLink.OnChange := DoActionChange;
    ActionChange(Value, csLoading in Value.ComponentState);
    Value.FreeNotification(Self);
  end;
end;

procedure TMenuItem.SetBitmap(const Value: TBitmap);
begin
  if FBitmap <> Value then
  begin
    if Value <> nil then
    begin
      Bitmap.Assign(Value);
      Bitmap.Transparent := True;
      if DisplayBitmap then ChangePixmap(FBitmap.Handle);
    end
    else begin
      FBitmap.Free;
      FBitmap := nil;
      if DisplayBitmap then ChangePixmap(nil);
    end;
  end;
end;

procedure TMenuItem.InitiateActions;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].InitiateAction;
end;

procedure TMenuItem.SetCaption(const Value: WideString);
var
  ThisIndex: Integer;
  SaveParent: TMenuItem;
begin
  if FCaption <> Value then
  begin
    FCaption := Value;
    if Assigned(Parent) and (Showing or (csDesigning in ComponentState)) then
    begin
      if FCaption = cLineCaption then
      begin
        ThisIndex := GetMenuIndex;
        SaveParent := Parent;
        Parent.Delete(GetMenuIndex);
        SaveParent.Insert(ThisIndex, Self);
      end else
        QMenuData_changeItem(Parent.MenuData, FID, @FCaption);
    end;
  end;
end;

procedure TMenuItem.SetChecked(const Value: Boolean);
begin
  if FChecked <> Value then
  begin
    FChecked := Value;
    if Assigned(Parent) and (Showing or (csDesigning in ComponentState)) then
    begin
      QMenuData_setItemChecked(Parent.MenuData, FID, FChecked);
      if FChecked and FRadioItem then
        TurnSiblingsOff;
    end;
  end;
end;

procedure TMenuItem.SetEnabled(const Value: Boolean);
begin
  if FEnabled <> Value then
  begin
    FEnabled := Value;
    if Assigned(Parent) and (Showing or (csDesigning in ComponentState)) then
      QMenuData_setItemEnabled(Parent.MenuData, FID, FEnabled);
  end;
end;

procedure TMenuItem.SetGroupIndex(const Value: Byte);
begin
  if FGroupIndex <> Value then
  begin
    if Parent <> nil then Parent.VerifyGroupIndex(Parent.IndexOf(Self), Value);
    FGroupIndex := Value;
    if FChecked and FRadioItem then
      TurnSiblingsOff;
  end;
end;

procedure TMenuItem.SetMenuIndex(Value: Integer);
var
  Parent: TMenuItem;
  Count: Integer;
begin
  if FParent <> nil then
  begin
    Count := FParent.Count;
    if Value < 0 then Value := 0;
    if Value >= Count then Value := Count - 1;
    if Value <> MenuIndex then
    begin
      Parent := FParent;
      Parent.Remove(Self);
      Parent.Insert(Value, Self);
    end;
  end;

end;

procedure TMenuItem.SetParentComponent(Value: TComponent);
begin
  if FParent <> nil then FParent.Remove(Self);
  if Value <> nil then
    if Value is TMenu then
      TMenu(Value).Items.Add(Self)
    else if Value is TMenuItem then
      TMenuItem(Value).Add(Self);
end;

procedure TMenuItem.SetRadioItem(const Value: Boolean);
begin
  if FRadioItem <> Value then
  begin
    FRadioItem := Value;
    if FChecked and FRadioItem then
      TurnSiblingsOff;
      { MenuChanged(True); }
  end;
end;

procedure TMenuItem.ActionChange(Sender: TObject; CheckDefaults: Boolean);
begin
  if Action is TCustomAction then
    with TCustomAction(Sender) do
    begin
      if not CheckDefaults or (Self.Caption = '') then
        Self.Caption := Caption;
      if not CheckDefaults or (Self.Checked = False) then
        Self.Checked := Checked;
      if not CheckDefaults or (Self.Enabled = True) then
        Self.Enabled := Enabled;
      if not CheckDefaults or (Self.HelpContext = 0) then
        Self.HelpContext := HelpContext;
      if not CheckDefaults or (Self.HelpKeyWord = '') then
        Self.HelpKeyWord := HelpKeyWord;
      if not CheckDefaults then
        Self.HelpType := HelpType;
      if not CheckDefaults or (Self.Hint = '') then
        Self.Hint := Hint;
      if not CheckDefaults or (Self.ImageIndex = -1) then
       Self.ImageIndex := ImageIndex;
      if not CheckDefaults or (Self.ShortCut = scNone) then
        Self.ShortCut := ShortCut;
      if not CheckDefaults or (Self.Visible = True) then
        Self.Visible := Visible;
      if not CheckDefaults or not Assigned(Self.OnClick) then
        Self.OnClick := OnExecute;
    end;
end;

procedure TMenuItem.DoActionChange(Sender: TObject);
begin
  if Sender = Action then ActionChange(Sender, False);
end;

function TMenuItem.IsCaptionStored: Boolean;
begin
  Result := (ActionLink = nil) or not FActionLink.IsCaptionLinked;
end;

function TMenuItem.IsCheckedStored: Boolean;
begin
  Result := (ActionLink = nil) or not FActionLink.IsCheckedLinked;
end;

function TMenuItem.IsEnabledStored: Boolean;
begin
  Result := (ActionLink = nil) or not FActionLink.IsEnabledLinked;
end;

function TMenuItem.IsHintStored: Boolean;
begin
  Result := (ActionLink = nil) or not FActionLink.IsHintLinked;
end;

function TMenuItem.IsHelpContextStored: Boolean;
begin
  Result := (ActionLink = nil) or not FActionLink.IsHelpLinked;
end;

function TMenuItem.IsImageIndexStored: Boolean;
begin
  Result := (ActionLink = nil) or not FActionLink.IsImageIndexLinked;
end;

function TMenuItem.IsShortCutStored: Boolean;
begin
  Result := (ActionLink = nil) or not FActionLink.IsShortCutLinked;
end;

function TMenuItem.IsVisibleStored: Boolean;
begin
  Result := (ActionLink = nil) or not FActionLink.IsVisibleLinked;
end;

function TMenuItem.IsOnClickStored: Boolean;
begin
  Result := (ActionLink = nil) or not FActionLink.IsOnExecuteLinked;
end;

procedure TMenuItem.AssignTo(Dest: TPersistent);
begin
  if Dest is TCustomAction then
    with TCustomAction(Dest) do
    begin
      Enabled := Self.Enabled;
      HelpContext := Self.HelpContext;
      HelpKeyWord := Self.HelpKeyWord;
      HelpType := Self.HelpType;
      Hint := Self.Hint;
      ImageIndex := Self.ImageIndex;
      Caption := Self.Caption;
      Visible := Self.Visible;
      OnExecute := Self.OnClick;
    end
  else inherited AssignTo(Dest);
end;

procedure TMenuItem.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Operation = opRemove then
    if AComponent = Action then
      Action := nil
    else if AComponent = FMerged then
      MergeWith(nil);
end;

procedure TMenuItem.SetShortCut(const Value: TShortCut);
begin
  if FShortCut <> Value then
  begin
    FShortCut := Value;
    if Assigned(Parent) and Showing then
      QMenuData_setAccel(Parent.MenuData, ShortCutFlags(FShortCut), FID);
  end;
end;

procedure TMenuItem.SetVisible(const Value: Boolean);
begin
  if FVisible <> Value then
  begin
    FVisible := Value;
    if (Parent = nil) or (csDesigning in ComponentState) then Exit;
    if not FVisible then
      RemoveQtItemFromParent;
    Parent.UpdateItems;
  end;
end;

procedure TMenuItem.SubItemChanged(Sender: TObject; Source: TMenuItem;
  Rebuild: Boolean);
begin
  if Rebuild then
   RebuildMenu;
  if Parent <> nil then Parent.SubItemChanged(Self, Source, False)
  else if Owner is TMainMenu then TMainMenu(Owner).ItemChanged;
end;

procedure TMenuItem.TurnSiblingsOff;
var
  I: Integer;
  Item: TMenuItem;
begin
  if FParent <> nil then
    for I := 0 to FParent.Count - 1 do
    begin
      Item := FParent[I];
      if (Item <> Self) and Item.FRadioItem and (Item.GroupIndex = GroupIndex) then
        Item.SetChecked(False);
    end;
end;

procedure TMenuItem.UpdateItems;

  function UpdateItem(MenuItem: TMenuItem): Boolean;
  begin
    Result := False;
    MenuItem.ItemHandleNeeded;
    IterateMenus(@UpdateItem, MenuItem.FMerged, MenuItem);
    MenuItem.SubItemChanged(MenuItem, MenuItem, True);
  end;

begin
  IterateMenus(@UpdateItem, nil, Self);
end;


procedure TMenuItem.VerifyGroupIndex(Position: Integer; Value: Byte);
var
  I: Integer;
begin
  for I := 0 to GetCount - 1 do
    if I < Position then
    begin
      if Items[I].GroupIndex > Value then
        Error(@SGroupIndexTooLow)
    end
    else
      { Ripple change to menu items at Position and after }
      if Items[I].GroupIndex < Value then Items[I].FGroupIndex := Value;
end;

procedure TMenuItem.WidgetDestroyed;
begin
  inherited WidgetDestroyed;
end;

procedure TMenuItem.Show;
begin
  if Assigned(FOnShow) then FOnShow(Self);
end;

function TMenuItem.HasBitmap: Boolean;
begin
  Result := Assigned(FBitmap) and not FBitmap.Empty;
end;

function TMenuItem.IsBitmapStored: Boolean;
begin
  Result := HasBitmap;
end;

function TMenuItem.DisplayBitmap: Boolean;
begin
  Result := HasBitmap and ((ImageIndex < 0) or ((GetParentMenu <> nil) and
    not Assigned(GetParentMenu.Images)));
end;

function TMenuItem.FindItem(ItemID: Integer): TMenuItem;
var
  MI: QMenuItemH;
  Index: Integer;
begin
  Result := nil;
  if not Showing then Exit;
  MI := QMenuData_findItem(MenuData, ItemID);
  for Index := 0 to FItems.Count - 1 do
    if TMenuItem(FItems[Index]).FMenuItemHandle = MI then
    begin
      Result := FItems[Index];
      Exit;
    end;
end;

procedure TMenuItem.RemoveQtItemFromParent;
var
  ParentMenu: TMenu;
  ParentItem: TMenuItem;
begin
  ParentItem := Parent;
  if ParentItem = nil then
  begin
    ParentMenu := GetParentMenu;
    if ParentMenu <> nil then
      ParentItem := ParentMenu.Items
  end;                  
  if (ParentItem <> nil) and ParentItem.Showing and (ID < 0) then
  begin
    QMenuData_removeItem(ParentItem.MenuData, ID);
    FID := 0;
  end;
  RemoveItemHandle;
end;

function TMenuItem.Showing: Boolean;
var
  ParentItem: TMenuItem;
begin
  Result := FVisible or (csDesigning in ComponentState);
  ParentItem := Parent;
  if Result then
    while (ParentItem <> nil) and Result do
    begin
      Result := Result and (ParentItem.Visible or (csDesigning in ComponentState));
      ParentItem := ParentItem.Parent;
    end;
end;

procedure TMenuItem.ShowHook;
var
  I: Integer;
  Menu: TMenu;
begin
  try
    FCurrentItem := nil;
    Menu := GetParentMenu;
    QWidget_setPalette(Handle, Menu.FPalette.Handle, True);
    if not (csDesigning in ComponentState) then
    begin
      InitiateActions;
      InternalRethinkHotkeys(False);
    end;
    for I := 0 to FItems.Count - 1 do
      TMenuItem(FItems[I]).Show;
  except
    Application.HandleException(Self);
  end;
end;

procedure TMenuItem.SetImageIndex(const Value: TImageIndex);
begin
  if FImageIndex <> Value then
  begin
    FImageIndex := Value;
    DoSetImageIndex(Value);
  end;
end;

procedure TMenuItem.ChangePixmap(Value: QPixmapH);
var
  SaveParent: TMenuItem;
  ThisIndex: Integer;
begin
  if (Parent <> nil) and (Showing or (csDesigning in ComponentState)) then
  begin
    if (Value <> nil) and not QPixmap_isNull(Value) {Value.Empty} then
    begin
      QMenuData_changeItem(Parent.MenuData, ID, QIconSet_create(Value,
        QIconSetSize_Small), @FCaption);
    end
    else if not (csDestroying in ComponentState) and (Parent <> nil)
    and (QMenuData_iconSet(Parent.MenuData, FID) <> nil) then
    begin
      ThisIndex := GetMenuIndex;
      SaveParent := Parent;
      Parent.Delete(GetMenuIndex);
      SaveParent.Insert(ThisIndex, Self);
    end;
  end;
end;

function TMenuItem.GetImageList: TCustomImageList;
var
  LMenu: TMenu;
begin
  Result := nil;
  LMenu := GetParentMenu;
  if LMenu <> nil then
    Result := LMenu.Images;
end;

procedure TMenuItem.DoSetImageIndex(const Value: Integer);
var
  ImageList: TCustomImageList;
  Pixmap: QPixmapH;
begin
  ImageList := GetImageList;
  if ImageList = nil then Exit;
  if (Value > -1) then
  begin
    Pixmap := ImageList.GetPixmap(Value);
    if (Pixmap <> nil) and not QPixmap_isNull(Pixmap) then
      ChangePixmap(Pixmap)
    else
      ChangePixmap(nil);
  end
  else if DisplayBitmap then
    ChangePixmap(FBitmap.Handle)
  else
    ChangePixmap(nil);
end;

function TMenuItem.VisibleCount: Integer;
var
  I: Integer;
begin
  if csDesigning in ComponentState then
  begin
    Result := Count;
    Exit;
  end;
  Result := 0;
  if FItems <> nil then
    for I := 0 to FItems.Count - 1 do
      if TMenuItem(FItems[I]).Visible then Inc(Result);
end;

{ TMenu }

procedure TMenu.ActivatedHook(ItemID: Integer);
var
  Item: TMenuItem;
begin
  try
    Item := Items.FindItem(ItemID);
    if Item <> nil then
      QApplication_postEvent(Handle, QCustomEvent_create(QEventType_MenuClick, Item));
  except
    Application.HandleException(Self);
  end;
end;

constructor TMenu.Create(AOwner: TComponent);
begin
  FItems := TMenuItem.Create(Self);
  FItems.FOnChange := MenuChanged;
  FItems.FMenu := Self;
  FImageChangeLink := TChangeLink.Create;
  FImageChangeLink.OnChange := ImageListChange;
  FItems.FAutoHotkeys := maParent;
  inherited Create(AOwner);
  ParentWidget := nil;
  HandleNeeded;
  QWidget_setFocusPolicy(QWidgetH(Handle), QWidgetFocusPolicy_NoFocus);
  FPalette := TWidgetPalette.Create;
  FPalette.OnChange := PaletteChanged;
  FPalette.ColorRole := crButton;
  FPalette.TextColorRole := crButtonText;
  FColor := clButton;
end;

destructor TMenu.Destroy;
begin
  FItems.Free;
  FPalette.Free;
  inherited Destroy;
end;

procedure TMenu.DoChange(Source: TMenuItem; Rebuild: Boolean);
begin
  if Assigned(FOnChange) then FOnChange(Self, Source, Rebuild);
end;

function TMenu.FindItem(Value: Integer; Kind: TFindItemKind): TMenuItem;
var
  FoundItem: TMenuItem;

  function Find(Item: TMenuItem): Boolean;
  var
    I: Integer;
  begin
    Result := False;
    if ((Kind = fkID) and (Value = Item.ID)) or
      ((Kind = fkHandle) and (Value = Integer(Item.FMenuItemHandle))) or
      ((Kind = fkShortCut) and (Value = Item.ShortCut)) then
    begin
      FoundItem := Item;
      Result := True;
      Exit;
    end
    else
      for I := 0 to Item.GetCount - 1 do
        if Find(Item[I]) then
        begin
          Result := True;
          Exit;
        end;
  end;

begin
  FoundItem := nil;
  IterateMenus(@Find, Items.FMerged, Items);
  Result := FoundItem;
end;

function TMenu.GetAutoHotkeys: TMenuAutoFlag;
begin
  Result := cItemAutoFlagToMenu[Items.FAutoHotkeys];
end;

function TMenu.GetBitmap: TBitmap;
begin
  Result := FPalette.Bitmap;
end;

procedure TMenu.GetChildren(Proc: TGetChildProc; Root: TComponent);
begin
  FItems.GetChildren(Proc, Root);
end;

procedure TMenu.SetChildOrder(Child: TComponent; Order: Integer);
begin
  FItems.SetChildOrder(Child, Order);
end;

procedure TMenu.HighlightedHook(ItemID: Integer);
var
  Item: TMenuItem;
begin
  try
    Item := Items.FindItem(ItemID);
    if Item <> nil then
    begin
      Item.Highlighted;
      // Hotkeys need not be rethought if there are submenu items
      if Item.Count > 0 then Items.InternalRethinkHotkeys(False);
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TMenu.ImageListChange(Sender: TObject);
begin
  UpdateItemImages;
end;

function TMenu.IsBitmapStored: Boolean;
begin
  Result := not FPalette.IsBitmapEmpty;
end;

function TMenu.IsShortCut(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
type
  TClickResult = (crDisabled, crClicked, crShortCutMoved, crShortCutFreed);
var
  ShortCut: TShortCut;
  ClickResult: TClickResult;
  ShortCutItem: TMenuItem;

  function NthParentOf(Item: TMenuItem; N: Integer): TMenuItem;
  begin
    Result := Item;
    while (N > 0) and (Result <> nil) do
    begin
      Result := Result.Parent;
      Dec(N);
    end;
  end;

  function DoClick(var Item: TMenuItem; Level: Integer): TClickResult;
  var
    ItemParent: TMenuItem;
  begin
    Result := crClicked;
    ItemParent := Item.Parent;
    Assert(Item = NthParentOf(ShortCutItem, Level));
    if ItemParent <> nil then Result := DoClick(ItemParent, Level + 1);
    if Result in [crDisabled, crShortCutFreed] then Exit;
    if Result = crShortCutMoved then
    begin
      {
        Shortcut moved, we need to refind the shortcut and restore Item
        to point to the parent at the right level, if possible
      }
      if (ShortCutItem = nil) or (ShortCutItem.ShortCut <> ShortCut) then
      begin
        ShortCutItem := FindItem(ShortCut, fkShortCut);
        if ShortCutItem = nil then
        begin
          Result := crShortCutFreed;
          Exit;  { Shortcut item could not be found }
        end;
      end;
      Item := NthParentOf(ShortCutItem, Level);
      if (Item = nil) or (Item.Parent <> ItemParent) then
        Exit;  { Shortcut moved in structure, level not correct }
      if Level = 0 then Result := crClicked;
    end;
    if Item.Enabled then
      try
        if not (csDesigning in ComponentState) then Item.InitiateActions;
        Item.Click;
        if (ShortCutItem = nil) or
          ((Item <> ShortCutItem) and (ShortCutItem.ShortCut <> ShortCut)) then
          Result := crShortCutMoved;
      except
        Application.HandleException(Self);
      end
    else Result := crDisabled;
  end;

begin
  ShortCut := QMenus.ShortCut(Key, Shift);
  if ShortCut = 0 then
  begin
    Result := False;
    Exit;
  end;
  repeat
    ClickResult := crDisabled;
    ShortCutItem := FindItem(ShortCut, fkShortCut);
    if ShortCutItem <> nil then
    begin
      ShortCutItems.Push(@ShortCutItem);
      try
        ClickResult := DoClick(ShortCutItem, 0);
      finally
        ShortCutItems.Pop;
      end;
    end;
  until ClickResult <> crShortCutMoved;
  Result := ShortCutItem <> nil;
end;

procedure TMenu.Loaded;
begin
  inherited Loaded;
  DoChange(nil, False);
  Items.InternalRethinkHotkeys(False);
end;

procedure TMenu.MenuChanged(Sender: TObject; Source: TMenuItem;
  Rebuild: Boolean);
begin
  if ComponentState * [csLoading, csDestroying] = [] then
    DoChange(Source, Rebuild);
end;

procedure TMenu.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (AComponent = FImages) and (Operation = opRemove) then Images := nil; 
end;

procedure TMenu.PaletteChanged(Sender: TObject);
begin
  QWidget_setPalette(QWidgetH(Handle), (Sender as TPalette).Handle, True);
end;

procedure TMenu.SetAutoHotkeys(const Value: TMenuAutoFlag);
begin
  Items.FAutoHotkeys := cMenuAutoFlagToItem[Value];
end;

procedure TMenu.SetBitmap(Value: TBitmap);
begin
  FPalette.Bitmap := Value;
end;

procedure TMenu.SetColor(const Value: TColor);
begin
  if Color <> Value then
  begin
    FPalette.BaseColor := Value;
    FColor := Value;
  end;
end;

procedure TMenu.SetForm(Value: TObject);
var
  P: TPoint;
begin
  if Value <> nil then
  begin
    if not (Value is TCustomForm) then
      Error(@SMenuSetFormError);
    ParentWidget := TCustomForm(Value).Handle;
  end else
    ParentWidget := nil;
  if not (csDestroying in ComponentState) then
  begin
    P := Point(0, 0);
    QWidget_reparent(QWidgetH(Handle), ParentWidget, @P, Value <> nil);
  end;
end;

procedure TMenu.SetImages(const Value: TCustomImageList);
begin
  if FImages <> nil then FImages.UnRegisterChanges(FImageChangeLink);
  FImages := Value;
  if FImages <> nil then
  begin
    FImages.RegisterChanges(FImageChangeLink);
    FImages.FreeNotification(Self);
  end;
  UpdateItemImages;
end;

procedure TMenu.UpdateItemImages;

  function UpdateImage(MenuItem: TMenuItem): Boolean;
  var
    ImageList: TCustomImageList;
  begin
    Result := False;
    ImageList := MenuItem.GetImageList;
    if (ImageList <> nil) then
      MenuItem.DoSetImageIndex(MenuItem.ImageIndex)
    else if (MenuItem.FBitmap <> nil) and not MenuItem.FBitmap.Empty then
      MenuItem.ChangePixmap(MenuItem.FBitmap.Handle)
    else
      MenuItem.ChangePixmap(nil);
    IterateMenus(@UpdateImage, MenuItem.FMerged, MenuItem);
  end;

begin
  IterateMenus(@UpdateImage, Items.FMerged, Items);
end;

{ TMainMenu }

function TMainMenu.GetHandle: QMenuBarH;
begin
  HandleNeeded;
  Result := QMenuBarH(FHandle);
end;

{$IFDEF LINUX}
type
  TKMenuBar_create = function (AParent: QWidgetH): QMenuBarH; cdecl;
var
  KMenuBar_create: TKMenuBar_create = nil;            
{$ENDIF}

procedure TMainMenu.CreateWidget;
begin
{$IFDEF LINUX}
  if Assigned(KMenuBar_create) then
    FHandle := KMenuBar_create(ParentWidget);
  if not Assigned(FHandle) then
{$ENDIF}
    FHandle := QMenuBar_create(ParentWidget, nil);
  FItems.ParentWidget := Handle;
  FItems.FMenuData := MenuDataHandle;
  Hooks := QMenuBar_hook_create(Handle);
end;

procedure TMainMenu.HookEvents;
var
  Method: TMethod;
begin
  QMenuBar_activated_Event(Method) := ActivatedHook;
  QMenuBar_hook_hook_activated(QMenuBar_hookH(Hooks), Method);
  QMenuBar_highlighted_Event(Method) := HighlightedHook;
  QMenuBar_hook_hook_highlighted(QMenuBar_hookH(Hooks), Method);
  inherited HookEvents;
end;

function TMainMenu.MenuDataHandle: QMenuDataH;
begin
  Result := QMenuBar_to_QMenuData(Handle);
end;

procedure TMainMenu.MenuChanged(Sender: TObject; Source: TMenuItem;
  Rebuild: Boolean);
begin
  inherited MenuChanged(Sender, Source, Rebuild);
end;

procedure TMainMenu.ItemChanged;
begin
  MenuChanged(nil, nil, False);
end;

function TMainMenu.IsShortCut(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
var
  I, J: Integer;
begin
  Result := False;
  if Items.FMergedWith <> nil then Exit;
  //we have to manually "locate" the top level menu item with this shortcut.
  J := -1;
  for I := 0 to FItems.Count - 1 do
  begin
    Result := IsAccel(Key, Items[I].Caption) and (ssAlt in Shift)
      and Items[I].Visible;
    if Items[I].Visible then Inc(J);
    if Result then
    begin
      QMenuBar_activateItemAt(QMenuBarH(Handle), J);
      Exit;
    end;
  end;
  Result := inherited IsShortCut(Key, Shift, KeyText);
end;

procedure TMainMenu.SetAutoMerge(const Value: Boolean);
begin
  FAutoMerge := Value;
end;

procedure TMainMenu.Merge(Menu: TMainMenu);
begin
  if Menu <> nil then
    FItems.MergeWith(Menu.FItems) else
    FItems.MergeWith(nil);
end;

procedure TMainMenu.Unmerge(Menu: TMainMenu);
begin
  FItems.MergeWith(nil);
end;

{ TPopupMenu }

constructor TPopupMenu.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FAutoPopup := True;
  FItems.OnClick := DoPopup;
  HandleNeeded;
end;

procedure TPopupMenu.CreateWidget;
begin
  FHandle := QPopupMenu_create(ParentWidget, nil);
  FItems.ParentWidget := Handle;
  FItems.FMenuData := MenuDataHandle;
  Hooks := QPopupMenu_hook_create(Handle);
end;

procedure TPopupMenu.DoPopup(Sender: TObject);
begin
  Items.InitiateActions;
  if Assigned(FOnPopup) then FOnPopup(Sender);
end;

function TPopupMenu.GetHandle: QPopupMenuH;
begin
  HandleNeeded;
  Result := QPopupMenuH(FHandle);
end;

{$IFDEF MSWINDOWS}
procedure TPopupMenu.HighlightedHook(ItemID: Integer);
begin
  try
    FCurrentItem := Items.FindItem(ItemID);
    if FCurrentItem <> nil then
    begin
      FCurrentItem.Highlighted;
      // Hotkeys need not be rethought if there are submenu items
      if FCurrentItem.Count > 0 then Items.InternalRethinkHotkeys(False);
    end;
  except
    Application.HandleException(Self);
  end;
end;
{$ENDIF}

procedure TPopupMenu.HookEvents;
var
  Method: TMethod;
begin
  QPopupMenu_activated_Event(Method) := ActivatedHook;
  QPopupMenu_hook_hook_activated(QPopupMenu_hookH(Hooks), Method);
  QPopupMenu_highlighted_Event(Method) := HighlightedHook;
  QPopupMenu_hook_hook_highlighted(QPopupMenu_hookH(Hooks), Method);
  QPopupMenu_aboutToShow_Event(Method) := ShowHook;
  QPopupMenu_hook_hook_aboutToShow(QPopupMenu_hookH(Hooks), Method);
  inherited HookEvents;
end;

{$IFDEF MSWINDOWS}
procedure TPopupMenu.InvokeHelp;
var
  Item: TMenuItem;
begin
  if FCurrentItem = nil then
    inherited
  else begin
    Item := FCurrentItem;
    while Item <> nil do
    begin
      case Item.HelpType of
        htKeyword:
          if Item.HelpKeyword <> '' then
          begin
            Application.KeywordHelp(Item.HelpKeyword);
            Exit;
          end;
        htContext:
          if Item.HelpContext <> 0 then
          begin
            Application.ContextHelp(Item.HelpContext);
            Exit;
          end;
      end;
      Item := Item.Parent;
    end;
  end;
end;
{$ENDIF}

function TPopupMenu.MenuDataHandle: QMenuDataH;
begin
  Result := QPopupMenu_to_QMenuData(Handle);
end;

procedure TPopupMenu.Popup(X, Y: Integer);
var
  Size: TSize;
begin
  if FItems.Count = 0 then Exit;  { Qt will popup a menu with no items! }
  FPopupPoint := Types.Point(X, Y);
  DoPopup(Self);
  if Alignment in [paCenter, paRight] then
  begin
    QWidget_sizeHint(Handle, @Size);
    if Alignment = paRight then
      Dec(FPopupPoint.X, Size.cx)
    else
      Dec(FPopupPoint.X, Size.cx div 2);
  end;
  QPopupMenu_exec(Handle, @FPopupPoint, -1);
{$IFDEF MSWINDOWS}  
  FCurrentItem := nil;
{$ENDIF}  
end;

procedure TPopupMenu.ShowHook;
var
  I: Integer;
begin
  try
    for I := 0 to FItems.Count - 1 do
      TMenuItem(FItems[I]).Show;
  except
    Application.HandleException(Self);
  end;
end;

initialization
  ShortCutItems := TMenuItemStack.Create;
{$IFDEF MSWINDOWS}  
  StartClassGroup(TControl);
  GroupDescendentsWith(TMenu, QControls.TControl);
  GroupDescendentsWith(TMenuItem, QControls.TControl);
{$ENDIF}  
  RegisterClass(TMenuItem);
{$IFDEF LINUX}
  if Assigned(LoadThemeHook) then
    KMenuBar_create := dlsym(LoadThemeHook(), 'KMenuBar_create');
{$ENDIF}

finalization
  FreeAndNil(ShortCutItems);

end.
