
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 1995-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit ActnMan;

interface

(*$HPPEMIT '#pragma link "dclact.lib"'*)

uses Windows, Messages, SysUtils, Forms, Classes, Menus, ActnList, Graphics,
  ToolWin, ImgList, Controls, Buttons;

const
  CM_ITEMSELECTED  = CM_BASE + $0402;
  CM_ITEMCLICKED   = CM_BASE + $0403;
  CM_ITEMKEYED     = CM_BASE + $0404;
  CM_SCROLLCLICKED = CM_BASE + $0406;
  CM_RESETBAR      = CM_BASE + $0409;
  CM_ENTERMENULOOP = CM_BASE + $0410;

type

{ TCustomActionManager }

  TActionBars = class;
  TActionListCollection = class;
  TActionClientsCollection = class;
  TActionClientItem = class;
  TActionClientItemClass = class of TActionClientItem;
  TCustomActionBar = class;
  TActionClient = class;
  TActionClients = class;
  TActionClientsClass = class of TActionClients;
  TActionBarsClass = class of TActionBars;
  TActionBarItemClass = class of TActionBarItem;

  TCustomActionManager = class(TCustomActionList)
  private
    FActionBars: TActionBars;
    FLinkedActionLists: TActionListCollection;
    FDefaultActionBars: TActionBars;
    FFileName: TFileName;
    FLoading: Boolean;
    FPrioritySchedule: TStringList;
    FSaved: Boolean;
    procedure SetActionBars(const Value: TActionBars);
    procedure SetPrioritySchedule(const Value: TStringList);
    function IsPriorityScheduleStored: Boolean;
    procedure SetLinkedActionLists(const Value: TActionListCollection);
    function IsLinkedActionListsStored: Boolean;
    function IsActionBarsStored: Boolean;
  protected
    procedure Change; override;
    function CreateActionBars: TActionBars;
    function FindActionClient(AnAction: TContainedAction;
      Clients: TActionClientsCollection = nil): TActionClientItem;
    function FindActionBar(ActionBar: TCustomActionBar;
      Clients: TActionClientsCollection = nil): TActionClient;
    function GetActionBarsClass: TActionBarsClass;
    function GetActionBarItemClass: TActionBarItemClass;
    function GetActionClientsClass: TActionClientsClass;
    function GetActionClientItemClass: TActionClientItemClass;
    function GetUsage(AnItem: TActionClientItem): Boolean; virtual;
    procedure Loaded; override;
    procedure LoadMenu(Clients: TActionClients; AMenu: TMenuItem);
    procedure Notification(AComponent: TComponent; Operation: TOperation);
      override;
    procedure SetupActionBars(ActionBars: TActionClientsCollection);
    procedure SetImages(Value: TCustomImageList); override;
    property Loading: Boolean read FLoading;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure LoadFromFile(const Filename: string);
    procedure LoadFromStream(S: TStream);
    procedure ResetActionBar(Index: Integer);
    procedure ResetUsageData;
    procedure SaveToFile(const Filename: string);
    procedure SaveToStream(S: TStream);
    property ActionBars: TActionBars read FActionBars write SetActionBars
      stored IsActionBarsStored;
    property DefaultActionBars: TActionBars read FDefaultActionBars;
    property LinkedActionLists: TActionListCollection read FLinkedActionLists
      write SetLinkedActionLists stored IsLinkedActionListsStored;
    property FileName: TFileName read FFileName write FFileName;
    property Images;
    property PrioritySchedule: TStringList read FPrioritySchedule
      write SetPrioritySchedule stored IsPriorityScheduleStored;
  end;

{ TActionManager }

  TActionManager = class(TCustomActionManager)
  published
    // FileName must be streamed before ActionBars
    property FileName;
    property ActionBars;
    property LinkedActionLists;
    property Images;
    property PrioritySchedule;
    property State;
    property OnChange;
    property OnExecute;
    property OnUpdate;
  end;

{ TActionListItem }

  TActionListItem = class(TCollectionItem)
  private
    FActionList: TCustomActionList;
    FCaption: string;
    procedure SetActionList(const Value: TCustomActionList);
    function GetCaption: string;
  protected
    function GetDisplayName: string; override;
    function Owner: TActionListCollection;
  public
    procedure Assign(Source: TPersistent); override;
  published
    property ActionList: TCustomActionList read FActionList write SetActionList;
    property Caption: string read GetCaption write FCaption;
  end;

{ TActionListCollection }

  TActionListCollection = class(TOwnedCollection)
  private
    function GetActionManager: TCustomActionManager;
    function GetListItem(Index: Integer): TActionListItem;
    procedure SetListItem(Index: Integer;
      const Value: TActionListItem);
  public
    property ActionManager: TCustomActionManager read GetActionManager;
    property ListItems[Index: Integer]: TActionListItem read GetListItem
      write SetListItem; default;
  end;

{ TActionClientsCollection }

  TActionProc = procedure(AClient: TActionClient) of Object;

  TActionClientsCollection = class(TOwnedCollection)
  private
    FParentItem: TActionClient;
    FCustomizable: Boolean;
    function GetActionClient(const Index: Integer): TActionClient;
    procedure SetActionClient(const Index: Integer;
      const Value: TActionClient);
  protected
    function GetActionManager: TCustomActionManager;  
    function InternalRethinkHotkeys(ForceRethink: Boolean): Boolean;
    property ActionClients[const Index: Integer]: TActionClient
      read GetActionClient write SetActionClient; default;
    property ParentItem: TActionClient read FParentItem write FParentItem;
  public
    procedure AfterConstruction; override;
    procedure IterateClients(Clients: TActionClientsCollection; ActionProc: TActionProc);    
    property ActionManager: TCustomActionManager read GetActionManager;
    property Customizable: Boolean read FCustomizable write FCustomizable default True;
  end;

{ TActionClient }

  TBackgroundLayout = (blNormal, blStretch, blTile, blLeftBanner, blRightBanner);
  TChangesAllowed = (caModify, caMove, caDelete);
  TChangesAllowedSet = set of TChangesAllowed;

  TActionClient = class(TCollectionItem)
  private
    FActionBar: TCustomActionBar;
    FBackground: TPicture;
    FBackgroundLayout: TBackgroundLayout;
    FChildActionBar: TCustomActionBar;
    FContextItems: TActionClients;
    FCaption: string;
    FColor: TColor;
    FSmallIcons: Boolean;
    FItems: TActionClients;
    FVisible: Boolean;
    FChangesAllowed: TChangesAllowedSet;
    function GetContextItems: TActionClients;
    procedure SetActionBar(const Value: TCustomActionBar);
    procedure SetItems(const Value: TActionClients);
    procedure SetBackground(const Value: TPicture);
    procedure SetBackgroundLayout(const Value: TBackgroundLayout);
    procedure SetContextItems(const Value: TActionClients);
    function IsBackgroundStored: Boolean;
    function AreContextItemsStored: Boolean;
    function GetBackground: TPicture;
    function GetItems: TActionClients;
    function IsItemsStored: Boolean;
    function GetHasItems: Boolean;
    function GetOwningCollection: TActionClientsCollection;
  protected
    procedure ClearActionBar;
    procedure ColorChanged; virtual;
    procedure FreeChildren;
    function HasVisibleItems: Boolean;
    function IsChildItem(AClient: TActionClient): Boolean;
    procedure SetChangesAllowed(const Value: TChangesAllowedSet); virtual;
    procedure SetColor(const Value: TColor); virtual;
    procedure SetVisible(const Value: Boolean); virtual;
    property OwningCollection: TActionClientsCollection read GetOwningCollection;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    function HasBackground: Boolean;
    procedure Refresh; virtual;
    property ActionBar: TCustomActionBar read FActionBar write SetActionBar;
    property ChildActionBar: TCustomActionBar read FChildActionBar
      write FChildActionBar;
    property HasItems: Boolean read GetHasItems;
  published
    property ChangesAllowed: TChangesAllowedSet read FChangesAllowed
      write SetChangesAllowed default [caModify, caMove, caDelete];
    property Color: TColor read FColor write SetColor default clDefault;
    property ContextItems: TActionClients read GetContextItems write SetContextItems
      stored AreContextItemsStored;
    property Background: TPicture read GetBackground write SetBackground
      stored IsBackgroundStored;
    property BackgroundLayout: TBackgroundLayout read FBackgroundLayout
      write SetBackgroundLayout default blNormal;
    property Items: TActionClients read GetItems write SetItems
      stored IsItemsStored;
    property Visible: Boolean read FVisible write SetVisible default True;
  end;

{ TActionBarItem }

  TActionBarItem = class(TActionClient)
  private
    FAutoSize: Boolean;
    FGlyphLayout: TButtonLayout;
    function GetActionBars: TActionBars;
    procedure SetAutoSize(const Value: Boolean);
    procedure SetGlyphLayout(const Value: TButtonLayout);
  protected
    procedure ColorChanged; override;
    function GetDisplayName: string; override;
    procedure SetVisible(const Value: Boolean); override;
    property ActionBars: TActionBars read GetActionBars;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Refresh; override;    
  published
    property ActionBar;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default True;
    property GlyphLayout: TButtonLayout read FGlyphLayout write SetGlyphLayout default blGlyphLeft;
  end;

{ TActionBars }

  TActionBars = class(TActionClientsCollection)
  private
    FSessionCount: Integer;
    FShowHint: Boolean;
    function GetActionBar(const Index: Integer): TActionBarItem;
    procedure SetShowHints(const Value: Boolean);
    procedure SetHintShortCuts(const Value: Boolean);
    function GetHintShortCuts: Boolean;
  protected
    procedure DoShowHint(AClient: TActionClient);
    procedure Notify(Item: TCollectionItem;
      Action: TCollectionNotification); override;
  public
    constructor Create(AOwner: TPersistent; ItemClass: TCollectionItemClass);
    function Add: TActionBarItem;
    property ActionBars[const Index: Integer]: TActionBarItem
      read GetActionBar; default;
  published
    property Customizable;
    property HintShortCuts: Boolean read GetHintShortCuts
      write SetHintShortCuts default True;
    property SessionCount: Integer read FSessionCount write FSessionCount default 0;
    property ShowHints: Boolean read FShowHint write SetShowHints default True;
  end;

{ TActionClients }

  TActionClientClass = class of TActionClient;
  TCaptionOptions = (coNone, coSelective, coAll);

  TActionClients = class(TActionClientsCollection)
  private
    FCaptionOptions: TCaptionOptions;
    FSmallIcons: Boolean;
    FHideUnused: Boolean;
    FAutoHotKeys: Boolean;
    function GetActionClient(const Index: Integer): TActionClientItem;
    procedure SetActionClient(const Index: Integer;
      const Value: TActionClientItem);
    procedure SetCaptionOptions(const Value: TCaptionOptions);
    procedure SetSmallIcons(const Value: Boolean);
    procedure SetHideUnused(const Value: Boolean);
    procedure SetAutoHotKeys(const Value: Boolean);
  protected
    procedure DoHideUnused(AClient: TActionClient);
    procedure DoShowCaptions(AClient: TActionClient);
    procedure ToggleSmallIcons(Clients: TActionClients; Small: Boolean);
    procedure Notify(Item: TCollectionItem;
      Action: TCollectionNotification); override;
  public
    constructor Create(AOwner: TPersistent; ItemClass: TCollectionItemClass);
    function Add: TActionClientItem;
    procedure Assign(Source: TPersistent); override;
    function VisibleCount: Integer;
    property ActionClients[const Index: Integer]: TActionClientItem
      read GetActionClient write SetActionClient; default;
    property ActionManager: TCustomActionManager read GetActionManager;
  published
    property AutoHotKeys: Boolean read FAutoHotKeys write SetAutoHotKeys default True;
    property Customizable;
    property HideUnused: Boolean read FHideUnused write SetHideUnused default True;
    property CaptionOptions: TCaptionOptions read FCaptionOptions
      write SetCaptionOptions default coSelective;
    property SmallIcons: Boolean read FSmallIcons write SetSmallIcons default True;
  end;

{ TActionClientLink }

  TActionClientLinkClass = class of TActionClientLink;

  TActionClientLink = class(TActionLink)
  protected
    FClient: TActionClientItem;
    procedure AssignClient(AClient: TObject); override;
    function IsCaptionLinked: Boolean; override;
    function IsEnabledLinked: Boolean; override;
    function IsHintLinked: Boolean; override;
    function IsImageIndexLinked: Boolean; override;
    function IsOnExecuteLinked: Boolean; override;
    function IsShortCutLinked: Boolean; override;
    function IsVisibleLinked: Boolean; override;
    procedure SetCaption(const Value: string); override;
    procedure SetChecked(Value: Boolean); override;
    procedure SetEnabled(Value: Boolean); override;
    procedure SetHint(const Value: string); override;
    procedure SetImageIndex(Value: Integer); override;
    procedure SetOnExecute(Value: TNotifyEvent); override;
    procedure SetShortCut(Value: TShortCut); override;
    procedure SetVisible(Value: Boolean); override;
  end;

{ TActionClientItem }

  TMergeRange = 0..High(Integer);
  TCustomActionControl = class;

  TActionClientItem = class(TActionClient)
  private
    FActionLink: TActionClientLink;
    FCheckUnused: Boolean;
    FControl: TCustomActionControl;
    FUsageCount: Integer;
    FShortCut: TShortCut;
    FMergeIndex: TMergeRange;
    FSeparator: Boolean;
    FShowCaption: Boolean;
    FShowShortCut: Boolean;
    FShortCutText: string;
    FImageIndex: Integer;
    FLastSession: Integer;
    FUnused: Boolean;
    FShowGlyph: Boolean;
    procedure DoActionChange(Sender: TObject);
    procedure SetAction(const Value: TContainedAction);
    procedure SetUsageCount(const Value: Integer);
    function GetActionClients: TActionClients;
    procedure SetShortCut(const Value: TShortCut);
    procedure SetControl(const Value: TCustomActionControl);
    procedure SetMergeIndex(const Value: TMergeRange);
    procedure SetShowShortCut(const Value: Boolean);
    procedure SetImageIndex(const Value: Integer);
    procedure SetCaption(const Value: string);
    procedure SetShowCaption(const Value: Boolean);
    function GetCaption: string;
    function GetAction: TContainedAction;
    procedure SetShowGlyph(const Value: Boolean);
    function IsCaptionStored: Boolean;
    function GetParentItem: TActionClient;
    procedure SetLastSession(const Value: Integer);
  protected
    procedure ActionChange(Sender: TObject; CheckDefaults: Boolean); dynamic;
    procedure ColorChanged; override;
    function GetActionLinkClass: TActionClientLinkClass; dynamic;
    function GetDisplayName: string; override;
    procedure ResetUsageData;
    procedure SetChangesAllowed(const Value: TChangesAllowedSet); override;    
    procedure SetCollection(Value: TCollection); override;
    procedure SetIndex(Value: Integer); override;
    procedure SetVisible(const Value: Boolean); override;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    function HasGlyph: Boolean;
    procedure InitiateAction; virtual;
    procedure Refresh; override;
    function Unused: Boolean;
    property ActionClients: TActionClients read GetActionClients;
    property ActionLink: TActionClientLink read FActionLink write FActionLink;
    property CheckUnused: Boolean read FCheckUnused write FCheckUnused;
    property Control: TCustomActionControl read FControl write SetControl;
    property ParentItem: TActionClient read GetParentItem;
    property Separator: Boolean read FSeparator;
    property ShortCutText: string read FShortCutText;
  published
    property Action: TContainedAction read GetAction write SetAction;
    property Caption: string read GetCaption write SetCaption stored IsCaptionStored;
    property ImageIndex: Integer read FImageIndex write SetImageIndex default -1;
    property MergeIndex: TMergeRange read FMergeIndex write SetMergeIndex default 0;
    property LastSession: Integer read FLastSession write SetLastSession default 0;
    property ShowCaption: Boolean read FShowCaption write SetShowCaption default True;
    property ShowGlyph: Boolean read FShowGlyph write SetShowGlyph default True;
    property ShowShortCut: Boolean read FShowShortCut write SetShowShortCut default True;
    property ShortCut: TShortCut read FShortCut write SetShortCut default 0;
    property UsageCount: Integer read FUsageCount write SetUsageCount default 0;
  end;

{ TActionDragObject }

  TCustomActionClass = class(TCustomAction);

  TActionDragObject = class(TDragObjectEx)
  private
    FActions: TList;
    FActionManager: TCustomActionManager;
    function GetAction(Index: Integer): TContainedAction;
    function GetActionCount: Integer;
  protected
    FActionClasses: Boolean;
  public
    constructor Create;
    destructor Destroy; override;
    procedure AddAction(AnAction: TContainedAction);
    procedure AddActionClass(AnActionClass: TCustomActionClass);
    property ActionCount: Integer read GetActionCount;
    property ActionManager: TCustomActionManager read FActionManager
      write FActionManager;
    property Actions[Index: Integer]: TContainedAction read GetAction;
  end;

{ TCategoryDragObject }

  TCategoryDragObject = class(TActionDragObject)
  private
    FCategory: string;
  public
    constructor Create(ACategory: string);
    property Category: string read FCategory;
  end;

{ TActionItemDragObject }

  TActionItemDragObject = class(TDragObjectEx)
  private
    FClientItem: TActionClientItem;
  protected
    procedure Finished(Target: TObject; X: Integer; Y: Integer;
      Accepted: Boolean); override;
  public
    property ClientItem: TActionClientItem read FClientItem;
  end;

{ TCustomActionBar }

  TCustomActionControlClass = class of TCustomActionControl;
  TBarOrientation = (boLeftToRight, boRightToLeft, boTopToBottom, boBottomToTop);
  TControlCreatedEvent = procedure(Sender: TObject;
    var Control: TCustomActionControl) of object;
  TGetControlClassEvent = procedure(Sender: TCustomActionBar; AnItem: TActionClient;
    var ControlClass: TCustomActionControlClass) of object;
  TBarEdge = (beLeft, beRight, beEither);

  TCustomActionBar = class(TToolWindow)
  private
    FActionClient: TActionClient;
    FActionManager: TCustomActionManager;
    FAllowHiding: Boolean;
    FCanvas: TCanvas;
    FDesignMode: Boolean;
    FEnabledState: Boolean;
    FOrientation: TBarOrientation;
    FSpacing: Integer;
    FOnControlCreated: TControlCreatedEvent;
    FOnGetControlClass: TGetControlClassEvent;
    FOnPaint: TNotifyEvent;
    FPersistentHotKeys: Boolean;
    FHRowCount: Integer;
    FVRowCount: Integer;
    FVertMargin: Integer;
    FHorzMargin: Integer;
    FHorzSeparator: Boolean;
    FSavedSize: TPoint;    
    FVertSeparator: Boolean;
    FTallest: Integer;
    FWidest: Integer;
    FContextBar: Boolean;
    procedure SetActionManager(const Value: TCustomActionManager);
    procedure SetHorzMargin(const Value: Integer);
    procedure SetHorzSeparator(const Value: Boolean);
    procedure SetSpacing(const Value: Integer);
    procedure SetVertMargin(const Value: Integer);
    procedure SetVertSeparator(const Value: Boolean);
    procedure CMEnabledchanged(var Message: TMessage);
      message CM_ENABLEDCHANGED;
    procedure CMResetBar(var Message: TMessage); message CM_RESETBAR;
    function GetItems: TActionClients;
    procedure WMContextMenu(var Message: TWMContextMenu);
      message WM_CONTEXTMENU;
    function GetAutoSizing: Boolean;
  protected
    FSavedWrapState: Boolean;
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    procedure AutoSizingChanged; virtual;
    function BackgroundSize: TPoint;
    procedure Clear; virtual;
    function CalcInsertPosition(Control: TCustomActionControl; X, Y: Integer): Integer;
    function CreateControl(AnItem: TActionClientItem): TCustomActionControl; virtual;
    procedure CreateControls; virtual;
    function CustomAlignInsertBefore(C1: TControl; C2: TControl): Boolean;
      override;
    procedure CustomAlignPosition(Control: TControl; var NewLeft: Integer;
      var NewTop: Integer; var NewWidth: Integer; var NewHeight: Integer;
      var AlignRect: TRect; AlignInfo: TAlignInfo); override;
    function DoGetControlClass(AnItem: TActionClientItem): TCustomActionControlClass; dynamic;
    procedure DoControlCreated(Control: TCustomActionControl); virtual;
    procedure DoDropCategory(Source: TCategoryDragObject; const X, Y: Integer); virtual;
    procedure DoDropActions(Source: TActionDragObject; const X, Y: Integer); virtual;
    procedure DragOver(Source: TObject; X: Integer; Y: Integer;
      State: TDragState; var Accept: Boolean); override;
    function FindLast: TActionClientItem; virtual;
    function FindAccelItem(const Accel: Word): TActionClientItem;
    function FindItemAt(const P: TPoint): TCustomActionControl;
    function FindItemCaption(const ACaption: string): TCustomActionControl;
    function FindNearestControl(const Point: TPoint): TCustomActionControl;
    function FindNextVisibleItem(AClient: TActionClientItem): TActionClientItem;
    function FindPreviousVisibleItem(AClient: TActionClientItem): TActionClientItem;
    function FindLeastUsedItem(const Visible: Boolean = True): TActionClientItem;
    function FindNext(AClient: TActionClientItem;
      const Wrap: Boolean = True): TActionClientItem; virtual;
     function FindPrevious(AClient: TActionClientItem;
      const Wrap: Boolean = True): TActionClientItem; virtual;
    function GetBannerWidth(BarEdge:  TBarEdge): Integer;
    function GetBarHeight: Integer; virtual;
    function GetBarWidth: Integer; virtual;
    function GetDesignMode: Boolean; virtual;
    function GetActionControl(const Index: Integer): TCustomActionControl; virtual;
    function GetControlClass(AnItem: TActionClientItem): TCustomActionControlClass; virtual;
    function HasItems: Boolean;
    function ItemCount: Integer; virtual;
    procedure Loaded; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure DrawBackground; virtual;
    procedure Paint; virtual;
    procedure PaintWindow(DC: HDC); override;
    procedure Reset; virtual;
    procedure Resize; override;
    procedure SetActionClient(const Value: TActionClient); virtual;
    procedure SetAutoSizing(const Value: Boolean); virtual;
    procedure SetDesignMode(const Value: Boolean); virtual;
    procedure SetOrientation(const Value: TBarOrientation); virtual;
    procedure SetPersistentHotKeys(const Value: Boolean); virtual;
    procedure SetBiDiMode(Value: TBiDiMode); override;
    procedure VisibleChanging; override;
    property Canvas: TCanvas read FCanvas;
    property HRowCount: Integer read FHRowCount;
    property Items: TActionClients read GetItems;
    property PersistentHotKeys: Boolean read FPersistentHotKeys write SetPersistentHotKeys;
    property VRowCount: Integer read FVRowCount;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure DragDrop(Source: TObject; X: Integer; Y: Integer); override;
    function FindFirst: TActionClientItem; virtual;
    function FindFirstVisibleItem: TActionClientItem;
    function FindLastVisibleItem: TActionClientItem;
    property ActionManager: TCustomActionManager read FActionManager
      write SetActionManager;
    property ActionClient: TActionClient read FActionClient write SetActionClient;
    property AllowHiding: Boolean read FAllowHiding write FAllowHiding;
    property AutoSizing: Boolean read GetAutoSizing write SetAutoSizing;    
    property Caption;
    property Color;
    property ContextBar: Boolean read FContextBar write FContextBar;
    property DesignMode: Boolean read GetDesignMode write SetDesignMode;
    property HorzMargin: Integer read FHorzMargin write SetHorzMargin default 1;
    property HorzSeparator: Boolean read FHorzSeparator write SetHorzSeparator;
    property Orientation: TBarOrientation read FOrientation write SetOrientation;
    property ActionControls[const Index: Integer]: TCustomActionControl read GetActionControl;
    property Spacing: Integer read FSpacing write SetSpacing;
    property VertMargin: Integer read FVertMargin write SetVertMargin default 1;
    property VertSeparator: Boolean read FVertSeparator write SetVertSeparator;
    property OnControlCreated: TControlCreatedEvent read FOnControlCreated
      write FOnControlCreated;
    property OnGetControlClass: TGetControlClassEvent read FOnGetControlClass
      write FOnGetControlClass;
    property OnPaint: TNotifyEvent read FOnPaint write FOnPaint;
  end;

{ TCustomActionControl }

  TCMItemMsg = record
    Msg: Cardinal;
    Unused: Integer;
    Sender: TCustomActionControl;
    Result: Longint;
  end;

  TCustomActionControl = class(TGraphicControl)
  private
    FActionBar: TCustomActionBar;
    FActionClient: TActionClientItem;
    FGlyphLayout: TButtonLayout;
    FGlyphPos: TPoint;
    FMargins: TRect;
    FSelected: Boolean;
    FSmallIcon: Boolean;
    FSpacing: Integer;
    FTextBounds: TRect;
    FTransparent: Boolean;
    function CaptionLength: Integer;
    function CaptionHeight: Integer;
    function ActualSpacing(ImageSize: TPoint): Integer;
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
    function GetActionBar: TCustomActionBar;
    procedure SetMargins(Value: TRect);
    procedure SetTransparent(const Value: Boolean);
    procedure SetSmallIcon(const Value: Boolean);
    procedure SetSpacing(const Value: Integer);
    procedure SetGlyphLayout(const Value: TButtonLayout);
    procedure WMContextMenu(var Message: TWMContextMenu);
      message WM_CONTEXTMENU;
  protected
    procedure BeginAutoDrag; override;
    procedure CalcLayout; virtual;
    function DesignWndProc(var Message: TMessage): Boolean; override;
    procedure DoDragDrop(DragObject: TObject; X, Y: Integer); virtual;
    procedure DragOver(Source: TObject; X: Integer; Y: Integer;
      State: TDragState; var Accept: Boolean); override;
    function GetAction: TBasicAction; override;
    function GetShowCaption: Boolean; virtual;
    function GetShowShortCut: Boolean; virtual;
    procedure CMDesignHitTest(var Message: TCMDesignHitTest);
      message CM_DESIGNHITTEST;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure CMItemSelected(var Message: TCMItemMsg); message CM_ITEMSELECTED;
    procedure DoStartDrag(var DragObject: TDragObject); override;
    procedure DrawDesignFocus(var PaintRect: TRect); virtual;
    procedure DrawDragDropPoint;
    procedure DrawGlyph(const Location: TPoint); virtual;
    procedure DrawBackground(var PaintRect: TRect); virtual;
    procedure DrawText(var ARect: TRect; var Flags: Cardinal; Text: string); virtual;
    procedure DrawSeparator(const Offset: Integer); virtual;
    function GetImageSize: TPoint; virtual;
    function HasGlyph: Boolean;
    function IsChecked: Boolean; virtual;
    function IsGrouped: Boolean; virtual;
    function GetSeparator: Boolean; virtual;
    procedure Paint; override;
    procedure PositionChanged; virtual;
    procedure ResetUsageData;
    procedure SetActionClient(Value: TActionClientItem); virtual;
    procedure SetSelected(Value: Boolean); virtual;
    procedure UpdateSelection;
    procedure UpdateTextBounds;
    procedure WMSetText(var Message: TWMSetText); message WM_SETTEXT;
    property GlyphPos: TPoint read FGlyphPos write FGlyphPos;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CalcBounds; virtual;
    procedure Click; override;
    procedure DragDrop(Source: TObject; X: Integer; Y: Integer); override;
    procedure InitiateAction; override;
    procedure Keyed; virtual;
    property ActionBar: TCustomActionBar read GetActionBar;
    property ActionClient: TActionClientItem read FActionClient write SetActionClient;
    property GlyphLayout: TButtonLayout read FGlyphLayout write SetGlyphLayout;
    property Margins: TRect read FMargins write SetMargins;
    property Selected: Boolean read FSelected write SetSelected;
    property Separator: Boolean read GetSeparator;
    property ShowCaption: Boolean read GetShowCaption;
    property ShowShortCut: Boolean read GetShowShortCut;
    property SmallIcon: Boolean read FSmallIcon write SetSmallIcon;
    property Spacing: Integer read FSpacing write SetSpacing default 4;
    property TextBounds: TRect read FTextBounds write FTextBounds;
    property Transparent: Boolean read FTransparent write SetTransparent;
    property OnClick;
  end;

{ IActionBarDesigner }

  IActionBarDesigner = interface
  ['{7CFC301B-1C59-11D4-8184-00C04F6BB89F}']
    function CreateAction(AnActionClass: TContainedActionClass): TContainedAction;
    procedure EditAction(Action: TContainedAction);
    procedure Modified(ActionBar: TCustomActionBar);
    procedure SetActiveMenu(Menu: TCustomActionBar);
    procedure SetItemSelection(const Items: array of TActionClient);
    procedure SetSelection(APersistent: TPersistent);
  end;

{ TXToolDockForm }

  TXToolDockForm = class(TToolDockForm)
  private
    procedure CMDialogChar(var Message: TMessage); message CM_DIALOGCHAR;
  end;

procedure NotifyDesigner(ActionBar: TCustomActionBar);

const
  caAllChanges = [caModify, caMove, caDelete];
  ControlDragMode: array[Boolean] of TDragMode = (dmManual, dmAutomatic);
  cDefaultSchedule: string = '0=3'#13#10'1=3'#13#10'2=6'#13#10'3=9'#13#10 +
                             '4=12'#13#10'5=12'#13#10'6=17'#13#10'7=17'#13#10 +
                             '8=17'#13#10'9=23'#13#10'10=23'#13#10'11=23'#13#10 +
                             '12=23'#13#10'13=23'#13#10'14=31'#13#10'15=31'#13#10 +
                             '16=31'#13#10'17=31'#13#10'18=31'#13#10'19=31'#13#10 +
                             '20=31'#13#10'21=31'#13#10'22=31'#13#10'23=31'#13#10 +
                             '24=31'#13#10'25=31'#13#10;

var
  ActionBarDesigner: IActionBarDesigner = nil;

implementation

uses Consts, Dialogs, CommCtrl, GraphUtil, Math, ActnMenus;

{ TXToolDockForm }

procedure TXToolDockForm.CMDialogChar(var Message: TMessage);
begin
  { Make sure pickletters are found in the main form first }
  if Application.MainForm <> nil then
    Application.MainForm.Dispatch(Message);
  if Message.Result = 0 then inherited;
end;

procedure NotifyDesigner(ActionBar: TCustomActionBar);
begin
  if Assigned(ActionBarDesigner) then
    ActionBarDesigner.Modified(ActionBar);
end;

{ TCustomActionManager }

constructor TCustomActionManager.Create(AOwner: TComponent);
begin
  RPR;
  inherited Create(AOwner);
  Exclude(FComponentStyle, csInheritable);
  FActionBars := CreateActionBars;
  FLinkedActionLists := TActionListCollection.Create(Self, TActionListItem);
  FPrioritySchedule := TStringList.Create;
  FPrioritySchedule.Text := cDefaultSchedule;
end;

destructor TCustomActionManager.Destroy;
begin
  FPrioritySchedule.Free;
  FActionBars.Free;
  FLinkedActionLists.Free;
  inherited Destroy;
end;

procedure TCustomActionManager.Assign(Source: TPersistent);
begin
  if Source is TActionManager then
  begin
    ActionBars.Assign(TActionManager(Source).ActionBars);
    FileName := TActionManager(Source).FileName;
    Images.Assign(TActionManager(Source).Images);
    PrioritySchedule.Assign(TActionManager(Source).PrioritySchedule);
    LinkedActionLists.Assign(TActionManager(Source).LinkedActionLists);
  end
  else
    inherited Assign(Source);
end;

function TCustomActionManager.CreateActionBars: TActionBars;
begin
  Result := GetActionBarsClass.Create(Self, GetActionBarItemClass);
end;

function TCustomActionManager.FindActionClient(AnAction: TContainedAction;
  Clients: TActionClientsCollection): TActionClientItem;
var
  I: Integer;
begin
  Result := nil;
  if Clients = nil then
   Clients := ActionBars;
   for I := 0 to Clients.Count - 1 do
    if Clients[I] is TActionClientItem and
       (TActionClientItem(Clients[I]).Action = AnAction) then
    begin
      Result := TActionClientItem(Clients[I]);
      break;
    end
    else
      if Clients[I].HasItems then
      begin
        Result := FindActionClient(AnAction, Clients[I].Items);
        if Assigned(Result) then
          break;
      end;
end;

function TCustomActionManager.FindActionBar(ActionBar: TCustomActionBar;
  Clients: TActionClientsCollection): TActionClient;
var
  I: Integer;
begin
  Result := nil;
  if Clients = nil then
    Clients := ActionBars;
  for I := 0 to Clients.Count - 1 do
    if Clients[I].ActionBar = ActionBar then
    begin
      Result := Clients[I];
      break;
    end
    else
      if Clients[I].HasItems then
      begin
        Result := FindActionBar(ActionBar, Clients[I].Items);
        if Assigned(Result) then
          break;
      end;
end;

procedure TCustomActionManager.LoadFromFile(const Filename: string);
var
  S: TFileStream;
begin
  S := TFileStream.Create(Filename, fmOpenRead or fmShareDenyWrite);
  try
    try
      LoadFromStream(S);
    except
      //  swallow exceptions here because we still want the app to start
      FreeAndNil(S);
      if MessageDlg(Format(SErrorLoadingFile, [FileName]), mtError,
         [mbYes, mbNo], 0) = mrYes then
        DeleteFile(FileName);
    end;
  finally
    FreeAndNil(S);
  end;
end;

procedure TCustomActionManager.LoadFromStream(S: TStream);
var
  Stream: TMemoryStream;
begin
  Stream := TMemoryStream.Create;
  FLoading := True;
  try
    FDefaultActionBars := CreateActionBars;
    FDefaultActionBars.Assign(ActionBars);
    try
      Stream.LoadFromStream(S);
      Stream.Position := 0;
      Stream.ReadComponent(Self);
      inherited Loaded;  // Reset the csLoading flag
      SetupActionBars(ActionBars);      
    except
      FActionBars.Assign(FDefaultActionBars);
      raise;
    end;
  finally
    FLoading := False;
    Stream.Free;
  end;
end;

procedure TCustomActionManager.Loaded;
begin
  inherited Loaded;
  if FLoading then exit;
  if not (csDesigning in ComponentState) and FileExists(FileName) then
    LoadFromFile(FFileName)
  else
    SetupActionBars(FActionBars);
  if not (csDesigning in ComponentState) then
    Inc(ActionBars.FSessionCount);
end;

procedure TCustomActionManager.LoadMenu(Clients: TActionClients; AMenu: TMenuItem);
var
  I: Integer;
begin
  for I := 0 to AMenu.Count - 1 do
    with Clients.Add do
    begin
      Caption := AMenu.Items[I].Caption;
      Action := TContainedAction(AMenu.Items[I].Action);
      if Assigned(Action) then
        Action.ActionList := Self;
      if AMenu.Items[I].Count > 0 then
        LoadMenu(Items, AMenu.Items[I]);
    end;
end;

procedure TCustomActionManager.Notification(AComponent: TComponent;
  Operation: TOperation);
var
  Item: TActionClientItem;
  ABar: TActionClient;
  I: Integer;
  Bars: TList;
begin
  inherited Notification(AComponent, Operation);
  if Application.Terminated and (Length(FFileName) > 0) and not FSaved then
  begin
    SaveToFile(FFileName);
    FSaved := True;
  end;
  if (Operation = opRemove) and not (csDestroying in ComponentState) then
    if (AComponent is TContainedAction) then
    begin
      Item := FindActionClient(TContainedAction(AComponent));
      Bars := TList.Create;
      try
        while Item <> nil do
        begin
          if Assigned(Item.ActionClients.ParentItem.ActionBar) then
          begin
            Item.ActionClients.ParentItem.ActionBar.DisableAlign;
            Bars.Add(Item.ActionClients.ParentItem.ActionBar);
          end;
          Item.ActionClients.Delete(Item.Index);
          Item := FindActionClient(TContainedAction(AComponent));
        end;
      finally
        for I := 0 to Bars.Count - 1 do
          if Assigned(Bars[I]) then
            TCustomActionBar(Bars[I]).EnableAlign;
      end;
    end
    else if (AComponent is TCustomActionBar) then
    begin
      ABar := FindActionBar(TCustomActionBar(AComponent));
      if Assigned(ABar) then
        ABar.FActionBar := nil;
    end
    else if (AComponent is TCustomActionList) then
      for I := FLinkedActionLists.Count - 1 downto 0 do
        if FLinkedActionLists[I].ActionList = AComponent then
        begin
          FLinkedActionLists.Delete(I);
          break;
        end;
end;

procedure TCustomActionManager.SaveToFile(const Filename: string);
var
  S: TStream;
begin
  State := asNormal;
  try
    S := TFileStream.Create(ExpandFileName(Filename), fmCreate);
    try
      try
        SaveToStream(S);
      except
        //  catch all exceptions because we still want the app to shutdown
      end;
    finally
      S.Free;
    end;
  except
    ShowMessage(SUnableToSaveSettings);
  end;
end;

procedure TCustomActionManager.SaveToStream(S: TStream);
var
  BinaryStream: TMemoryStream;
begin
  BinaryStream := TMemoryStream.Create;
  try
    BinaryStream.WriteComponent(Self);
    BinaryStream.Position := 0;
    S.CopyFrom(BinaryStream, BinaryStream.Size);
  finally
    BinaryStream.Free;
  end;
end;

procedure TCustomActionManager.SetupActionBars(ActionBars: TActionClientsCollection);
var
  I: Integer;
begin
  if ActionBars.Count = 0 then exit;
  for I := 0 to ActionBars.Count - 1 do
    if Assigned(ActionBars[I].ActionBar) then
    begin
      ActionBars.InternalRethinkHotkeys(True);
      ActionBars[I].ActionBar.ActionClient := ActionBars[I];
      ActionBars[I].ActionBar.Resize;
      with ActionBars[I].ActionBar do
        RequestAlign;
    end;
end;

procedure TCustomActionManager.SetActionBars(const Value: TActionBars);
begin
  FActionBars.Assign(Value);
end;

procedure TCustomActionManager.SetImages(Value: TCustomImageList);
var
  I, X: Integer;
  Update: Boolean;
begin
  Update := (Value <> Images) and not (csDestroying in ComponentState);
  inherited SetImages(Value);
  if not Update then exit;
  for I := 0 to ActionBars.Count - 1 do
    for X := 0 to ActionBars[I].Items.Count - 1 do
      if Assigned(ActionBars[I].Items[X].Control) then
        ActionBars[I].Items[X].Control.CalcBounds;
end;

function PrioritySort(List: TStringList; Index1, Index2: Integer): Integer;
begin
  Result := CompareText(List.Names[Index1], List.Names[Index2]);
end;

procedure TCustomActionManager.SetPrioritySchedule(const Value: TStringList);
begin
  if Length(Trim(FPrioritySchedule.Text)) = 0 then
  begin
    if MessageDlg(SRestoreDefaultSchedule, mtConfirmation, mbOKCancel, 0) = mrOk then
      FPrioritySchedule.Text := cDefaultSchedule
    else
      FPrioritySchedule.Clear;
  end
  else
  begin
    StrToInt(Value.Names[0]);
    StrToInt(Value.Values[Value.Names[0]]);
    FPrioritySchedule.Assign(Value);    
  end;
  FPrioritySchedule.CustomSort(PrioritySort);
end;

function TCustomActionManager.GetUsage(AnItem: TActionClientItem): Boolean;
var
  NumSessions: Integer;
  I: Integer;
begin
  // Returns True if AnItem is recently used
  Result := (AnItem.UsageCount = -1) or (PrioritySchedule.Count = 0);
  if Result then exit;
  NumSessions := ActionBars.SessionCount - AnItem.LastSession;
  I := 0;
  while (I < PrioritySchedule.Count) and
     (AnItem.UsageCount > StrToInt(PrioritySchedule.Names[I])) do
    Inc(I);
  if I = PrioritySchedule.Count then
    Dec(I);
  with PrioritySchedule do
    Result := NumSessions < StrToInt(Values[Names[I]]);
end;

function TCustomActionManager.IsPriorityScheduleStored: Boolean;
begin
  Result := CompareText(cDefaultSchedule, FPrioritySchedule.Text) <> 0;
end;

procedure TCustomActionManager.ResetActionBar(Index: Integer);
begin
  if Assigned(FDefaultActionBars) then
    FActionBars.Items[Index].Assign(FDefaultActionBars.Items[Index]);
end;

type
  // For D6 update 2
  // Fix TCustomActionManager.ResetUsageData without changing unit signature
  // Below method should move to be a member of TCustomActionManager in D7
  TResetComponent = class
    FActionManager: TCustomActionManager;
    procedure ResetClientUsageData(AClient: TActionClient);
  end;

procedure TResetComponent.ResetClientUsageData(
  AClient: TActionClient);
begin
  if AClient is TActionClientItem then
    with AClient as TActionClientItem do
    begin
      UsageCount := 0;
      LastSession := FActionManager.ActionBars.SessionCount;
    end;
end;

procedure TCustomActionManager.ResetUsageData;
var
  ResetComponent: TResetComponent;
begin
  ResetComponent := TResetComponent.Create;
  try
    ResetComponent.FActionManager := Self;
    ActionBars.IterateClients(ActionBars, ResetComponent.ResetClientUsageData);
  finally
    ResetComponent.Free;
  end;
end;

procedure TCustomActionManager.SetLinkedActionLists(
  const Value: TActionListCollection);
begin
  FLinkedActionLists.Assign(Value);
end;

procedure TCustomActionManager.Change;
begin
  inherited Change;
  if Assigned(ActionBars) then
    ActionBars.IterateClients(ActionBars, nil);
end;

function TCustomActionManager.GetActionClientsClass: TActionClientsClass;
begin
  Result := TActionClients;
end;

function TCustomActionManager.GetActionClientItemClass: TActionClientItemClass;
begin
  Result := TActionClientItem;
end;

function TCustomActionManager.GetActionBarsClass: TActionBarsClass;
begin
  Result := TActionBars;
end;

function TCustomActionManager.GetActionBarItemClass: TActionBarItemClass;
begin
  Result := TActionBarItem;
end;

function TCustomActionManager.IsLinkedActionListsStored: Boolean;
begin
  Result := LinkedActionLists.Count > 0; 
end;

function TCustomActionManager.IsActionBarsStored: Boolean;
begin
  Result := ActionBars.Count > 0;
end;

{ TActionListItem }

procedure TActionListItem.Assign(Source: TPersistent);
begin
  if Source is TActionListItem then
  begin
    if Assigned(Collection) then Collection.BeginUpdate;
    try
      ActionList := TActionListItem(Source).ActionList;
      Caption := TActionListItem(Source).Caption;
    finally
      if Assigned(Collection) then Collection.EndUpdate;
    end;
  end
  else
    inherited Assign(Source);
end;

function TActionListItem.GetCaption: string;
begin
  Result := FCaption;
  if (Length(Result) = 0) then
    if Assigned(FActionList) then
      Result := FActionList.Name
    else
      Result := SNoName;
end;

function TActionListItem.GetDisplayName: string;
begin
  if Assigned(FActionList) then
    Result := Caption
  else
    Result := inherited GetDisplayName;
end;

function TActionListItem.Owner: TActionListCollection;
begin
  Result := TActionListCollection(Collection);
end;

procedure TActionListItem.SetActionList(
  const Value: TCustomActionList);
begin
  if Value = Owner.ActionManager then
    raise Exception.Create(SCirularReferencesNotAllowed);
  if (FActionList <> Value) then
  begin
    FActionList := Value;
    FActionList.FreeNotification(Owner.ActionManager);
  end;
end;

{ TActionListCollection }

function TActionListCollection.GetActionManager: TCustomActionManager;
begin
  Result := TCustomActionManager(Owner);
end;

function TActionListCollection.GetListItem(
  Index: Integer): TActionListItem;
begin
  Result := TActionListItem(Items[Index]);
end;

procedure TActionListCollection.SetListItem(Index: Integer;
  const Value: TActionListItem);
begin
  TActionListItem(ListItems[Index]).Assign(Value);
end;

{ TActionClientsCollection }

procedure TActionClientsCollection.SetActionClient(const Index: Integer;
  const Value: TActionClient);
begin
  inherited SetItem(Index, Value);
end;

function TActionClientsCollection.GetActionClient(
  const Index: Integer): TActionClient;
begin
  Result := TActionClient(Items[Index]);
end;

function TActionClientsCollection.GetActionManager: TCustomActionManager;
begin
  Result := Owner as TActionManager;
end;

function TActionClientsCollection.InternalRethinkHotkeys(
  ForceRethink: Boolean): Boolean;
var
  Did, Doing, ToDo, Best: TStringList;
  I, Iteration, Column, At, BestCount: Integer;
  Char, Caption, OrigAvailable, Available, BestAvailable: string;

  function IfHotkeyAvailable(const AHotkey: string): Boolean;
  var
    At: Integer;
  begin
    At := AnsiPos(AHotkey, Available);
    Result := At <> 0;
    if Result then
      System.Delete(Available, At, 1);
  end;

  procedure CopyToBest;
  var
    I: Integer;
  begin
    Best.Assign(Did);
    BestCount := Did.Count;
    for I := 0 to Doing.Count - 1 do
      Best.AddObject(TActionClient(Doing.Objects[I]).FCaption, Doing.Objects[I]);
    BestAvailable := Available;
  end;

  procedure InsertHotkeyFarEastFormat(var ACaption: string; const AHotKey: string; AColumn: Integer);
  var
    I: Integer;
    vMBCSFlag: Boolean;
  begin
    vMBCSFlag := False;
    for I := 1 to Length(ACaption) do
      if ACaption[I] in LeadBytes then
      begin
        vMBCSFlag := True;
        System.Break;
      end;
    if vMBCSFlag then
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
  if ForceRethink then
  begin
    Available := ValidMenuHotkeys;
    Did := TStringList.Create;
    Doing := TStringList.Create;
    ToDo := TStringList.Create;
    Best := TStringList.Create;
    BestCount := 0;
    try
      for I := 0 to Count - 1 do
        if ActionClients[I].Visible and
           (ActionClients[I].FCaption <> cLineCaption) and
           (ActionClients[I].FCaption <> '') then
        begin
          Char := Uppercase(GetHotkey(ActionClients[I].FCaption));
          if Char = '' then
            ToDo.InsertObject(0, ActionClients[I].FCaption, Items[I])
          else if (AnsiPos(Char, ValidMenuHotkeys) <> 0) and
                  not IfHotkeyAvailable(Char) then
          begin
            ActionClients[I].FCaption := StripHotkey(ActionClients[I].FCaption);
            ToDo.InsertObject(0, ActionClients[I].FCaption, Items[I]);
          end;
        end;
      OrigAvailable := Available;
      for Iteration := 0 to ToDo.Count - 1 do
      begin
        Available := OrigAvailable;
        Doing.Assign(ToDo);
        Did.Clear;
        for I := Doing.Count - 1 downto 0 do
        begin
          Caption := Doing[I];
          Column := 1;
          while Column <= Length(Caption) do
          begin
            if Caption[Column] in LeadBytes then
              Inc(Column)
            else
            begin
              Char := Uppercase(Copy(Caption, Column, 1));
              if IfHotkeyAvailable(Char) then
              begin
                if SysLocale.FarEast then
                  InsertHotkeyFarEastFormat(Caption, Char, Column)
                else
                  System.Insert(cHotkeyPrefix, Caption, Column);
                Did.AddObject(Caption, Doing.Objects[I]);
                Doing.Delete(I);
                System.Break;
              end;
            end;
            Inc(Column);
          end;
        end;
        if Did.Count > BestCount then
          CopyToBest;
        if Doing.Count > 0 then
          for I := 0 to Doing.Count - 1 do
          begin
            At := ToDo.IndexOfObject(Doing.Objects[I]);
            ToDo.Move(At, ToDo.Count - 1);
          end
        else
          System.Break;
      end;
      if BestCount = 0 then
        CopyToBest;
      Result := Best.Count > 0;
      for I := 0 to Best.Count - 1 do
      begin
        Caption := Best[I];
        if SysLocale.FarEast and (AnsiPos(cHotkeyPrefix, Caption) = 0)
          and (BestAvailable <> '') then
        begin
          if AnsiPos(cHotkeyPrefix, Caption) = 0 then
          begin
            InsertHotkeyFarEastFormat(Caption, Copy(BestAvailable, Length(BestAvailable), 1), 0);
            System.Delete(BestAvailable, length(BestAvailable), 1);
          end;
        end;
        TActionClient(Best.Objects[I]).FCaption := Caption;
      end;
    finally
      Best.Free;
      ToDo.Free;
      Doing.Free;
      Did.Free;
    end;
  end;
  for I := 0 to Count - 1 do
    if Assigned(ActionClients[I].FItems) and ActionClients[I].FItems.AutoHotKeys then
      ActionClients[I].FItems.InternalRethinkHotkeys(True);
end;

procedure TActionClientsCollection.AfterConstruction;
begin
  inherited AfterConstruction;
  FCustomizable := True;
end;

procedure TActionClientsCollection.IterateClients(Clients: TActionClientsCollection;
  ActionProc: TActionProc);

  procedure UpdateActionBar(Client: TActionClient);
  begin
    if Client.Items.Count = 0 then exit;
    with Client.Items do
      if Assigned(ParentItem) and Assigned(ParentItem.ActionBar) then
        with ParentItem.ActionBar do
          Resize;
  end;

var
  I: Integer;
begin
  if Clients = nil then exit;
  for I := 0 to Clients.Count - 1 do
    if Clients[I].HasItems then
    begin
      if Assigned(ActionProc) then
        ActionProc(Clients[I])
      else
        Clients[I].Refresh;
      IterateClients(Clients[I].Items, ActionProc);
      UpdateActionBar(Clients[I]);
    end
    else
    begin
      if Assigned(Clients[I].ActionBar) then
      begin
        if Assigned(ActionProc) then
          ActionProc(Clients[I])
        else
          Clients[I].Refresh;
        UpdateActionBar(Clients[I]);
      end
      else
      begin
        if Assigned(ActionProc) then
          ActionProc(Clients[I])
        else
          Clients[I].Refresh;
        UpdateActionBar(Clients[I]);
      end;
    end;
end;

{ TActionClient }

constructor TActionClient.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FBackgroundLayout := blNormal;
  FVisible := True;
  FSmallIcons := True;
  FColor := clDefault;
  FBackgroundLayout := blNormal;
  FChangesAllowed := caAllChanges;
end;

destructor TActionClient.Destroy;
begin
  ClearActionBar;
  if Assigned(FBackground) then
    FreeAndNil(FBackground);
  if Assigned(FActionBar) then
    FActionBar.ActionClient := nil;
  FreeChildren;
  inherited Destroy;
end;

function TActionClient.AreContextItemsStored: Boolean;
begin
  Result := Assigned(FContextItems) and (FContextItems.Count > 0);
end;

procedure TActionClient.Assign(Source: TPersistent);
begin
  if Source is TActionClient then
  begin
    if Assigned(Collection) then Collection.BeginUpdate;
    try
      Color := TActionClientItem(Source).Color;
      ContextItems := TActionClientItem(Source).ContextItems;
      if TActionClientItem(Source).HasBackground then
        Background.Assign(TActionClientItem(Source).Background);
      BackgroundLayout := TActionClientItem(Source).BackgroundLayout;
      Visible := TActionClientItem(Source).Visible;
      if Assigned(TActionClientItem(Source).FItems) then
        Items.Assign(TActionClientItem(Source).FItems);
      ActionBar := TActionClientItem(Source).ActionBar;
    finally
      if Assigned(Collection) then Collection.EndUpdate;
    end;
  end
  else
    inherited Assign(Source);
end;

procedure TActionClient.ClearActionBar;
begin
  FActionBar := nil;
end;

procedure TActionClient.ColorChanged;
begin
end;

procedure TActionClient.FreeChildren;
var
  I: Integer;
begin
  if FItems = nil then exit;
  if FItems.Count > 0 then
    for I := 0 to FItems.Count - 1 do
      if FItems.ActionClients[I].FItems <> nil then
        FItems.ActionClients[I].FreeChildren;
  FItems.Free;
  FItems := nil;
end;

function TActionClient.GetBackground: TPicture;
begin
  if FBackground = nil then
    FBackground := TPicture.Create;
  Result := FBackground;
end;

function TActionClient.GetContextItems: TActionClients;
begin
  if FContextItems = nil then
    FContextItems := TActionClients.Create(Self.OwningCollection.ActionManager,
      TActionClientItem);
  Result := FContextItems;
end;

function TActionClient.GetHasItems: Boolean;
begin
  Result := Assigned(FItems) and (FItems.Count > 0);
end;

function TActionClientItem.GetParentItem: TActionClient;
begin
  if Assigned(ActionClients) then
    Result := ActionClients.ParentItem
  else
    Result := nil;
end;

function TActionClient.GetItems: TActionClients;
begin
  if FItems = nil then
  begin
    if Assigned(OwningCollection) and Assigned(OwningCollection.ActionManager) then
      with OwningCollection.ActionManager do
        FItems := GetActionClientsClass.Create(OwningCollection.ActionManager,
          GetActionClientItemClass)
    else
      FItems := TActionClients.Create(OwningCollection.ActionManager,
        TActionClientItem);
    FItems.FParentItem := Self;
  end;
  Result := FItems;
end;

function TActionClient.GetOwningCollection: TActionClientsCollection;
begin
  Result := TActionClientsCollection(Collection);
end;

function TActionClient.HasBackground: Boolean;
begin
  Result := Assigned(FBackground) and Assigned(FBackground.Graphic) and
    not FBackground.Graphic.Empty;
end;

function TActionClient.HasVisibleItems: Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Items.Count - 1 do
    if not Items[I].Unused and Items[I].Visible then
      Result := True
    else
      if Items[I].HasVisibleItems then
        Result := True;
end;

function TActionClient.IsBackgroundStored: Boolean;
begin
  Result := Assigned(FBackground) and Assigned(FBackground.Graphic) and
    not FBackground.Graphic.Empty;
end;

function TActionClient.IsChildItem(AClient: TActionClient): Boolean;
var
  AC: TActionClient;
begin
  Result := False;
  if Assigned(AClient) and (AClient.Items = Collection) then
  begin
    Result := True;
    exit;
  end;
  AC := OwningCollection.ParentItem;
  while AC <> nil do
    if AC.Collection = AClient.Items then
    begin
      Result := True;
      exit;
    end
    else
      AC := AC.OwningCollection.ParentItem;
end;

function TActionClient.IsItemsStored: Boolean;
begin
  Result := Assigned(FItems) and (FItems.Count > 0);
end;

procedure TActionClient.Refresh;
begin
end;

procedure TActionClient.SetActionBar(const Value: TCustomActionBar);
var
  ParentCollection: TActionClientsCollection;
begin
  if FActionBar <> Value then
  begin
    // Check to ensure no parent of this actionbar is already connected to a client
    ParentCollection := OwningCollection;
    while Assigned(ParentCollection) do
      if Assigned(ParentCollection.FParentItem) then
      begin
        if Assigned(ParentCollection.FParentItem.ActionBar) then
          raise Exception.Create(SAssignSubItemError)
        else
          ParentCollection := ParentCollection.FParentItem.OwningCollection
      end
      else
        ParentCollection := nil;
    if Assigned(FActionBar) and Assigned(FActionBar.ActionClient) then
      FActionBar.Clear;
    if Assigned(Value) and
       not (csLoading in OwningCollection.ActionManager.ComponentState) and
       not OwningCollection.ActionManager.Loading then
      Value.ActionClient := Self;
    FActionBar := Value;
  end;
end;

procedure TActionClient.SetItems(const Value: TActionClients);
begin
  if Value = nil then
    FreeAndNil(FItems)
  else
    FItems.Assign(Value);
end;

procedure TActionClient.SetBackground(const Value: TPicture);
var
  I: Integer;
begin
  FBackground.Assign(Value);
  if Assigned(Value) and HasItems then
    if Assigned(ActionBar) then
    begin
      for I := 0 to ActionBar.Items.Count - 1 do
        ActionBar.Items[I].Control.Transparent := not (FBackgroundLayout in
          [blLeftBanner, blRightBanner]);
      ActionBar.Realign;
      ActionBar.Invalidate;
    end;
end;

procedure TActionClient.SetBackgroundLayout(const Value: TBackgroundLayout);
var
  I: Integer;
begin
  if FBackgroundLayout <> Value then
  begin
    FBackgroundLayout := Value;
    if HasBackground and HasItems then
      for I := 0 to Items.Count - 1 do
        if Assigned(Items.ActionClients[I].Control) then
          Items.ActionClients[I].Control.Transparent :=
            not (Value in [blLeftBanner, blRightBanner]);
    if Assigned(ActionBar) then
    begin
      ActionBar.RequestAlign;
      ActionBar.Invalidate;
    end;
  end;
end;

procedure TActionClient.SetChangesAllowed(const Value: TChangesAllowedSet);
begin
  if FChangesAllowed <> Value then
    FChangesAllowed := Value;
end;

procedure TActionClient.SetColor(const Value: TColor);
begin
  if FColor <> Value then
  begin
    FColor := Value;
    ColorChanged;
  end;
end;

procedure TActionClient.SetContextItems(const Value: TActionClients);
begin
  FContextItems := Value;
end;

procedure TActionClient.SetVisible(const Value: Boolean);
begin
  if FVisible <> Value then
  begin
    FVisible := Value;
    NotifyDesigner(nil);
  end;
end;

{ TActionBarItem }

procedure TActionBarItem.ColorChanged;
begin
  if Assigned(FActionBar) then
    if Color = clDefault then
      FActionBar.ParentColor := True
    else
      FActionBar.Color := Color;
end;

constructor TActionBarItem.Create(Collection: TCollection);
begin
  inherited;
  FAutoSize := True;
end;

destructor TActionBarItem.Destroy;
begin
  if Assigned(ActionBar) then
    ActionBar.FActionClient := nil;
  inherited Destroy;
end;

function TActionBarItem.GetActionBars: TActionBars;
begin
  Result := TActionBars(Collection);
end;

function TActionBarItem.GetDisplayName: string;
begin
  if Assigned(ActionBar) then
    Result := 'ActionBar ->' + ActionBar.Name
  else
    Result := inherited GetDisplayName;
end;

procedure TActionBarItem.Refresh;
begin
  if Assigned(ActionBar) and not (csLoading in ActionBar.ComponentState) then
    ActionBar.RequestAlign;
end;

procedure TActionBarItem.SetAutoSize(const Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    if Assigned(FActionBar) then
      FActionBar.AutoSizingChanged;
  end;
end;

procedure TActionBarItem.SetGlyphLayout(const Value: TButtonLayout);
var
  I: Integer;
begin
  if FGlyphLayout <> Value then
  begin
    FGlyphLayout := Value;
    if Assigned(ActionBar) then
    begin
      ActionBar.DisableAlign;
      try
        for I := 0 to Items.Count - 1 do
          if Assigned(Items[I].Control) then
            Items[I].Control.GlyphLayout := Value;
      finally
        ActionBar.EnableAlign;
        ActionBar.Resize;
      end;
    end
    else
      for I := 0 to Items.Count - 1 do
        if Assigned(Items[I].Control) then
          Items[I].Control.GlyphLayout := Value;
  end;
end;

procedure TActionBarItem.SetVisible(const Value: Boolean);
begin
  inherited SetVisible(Value);
  if Assigned(FActionBar) then
    FActionBar.Visible := Visible;
end;

{ TActionBars }

constructor TActionBars.Create(AOwner: TPersistent; ItemClass: TCollectionItemClass);
begin
  inherited Create(AOwner, ItemClass);
  FSessionCount := 0;
  ShowHints := True;
  HintShortCuts := True;
end;

function TActionBars.Add: TActionBarItem;
begin
  Result := TActionBarItem(inherited Add);
end;

procedure TActionBars.DoShowHint(AClient: TActionClient);
begin
  if (AClient is TActionBarItem) and Assigned(TActionBarItem(AClient).ActionBar) then
    with AClient as TActionBarItem do
      ActionBar.ShowHint := FShowHint;
end;

function TActionBars.GetActionBar(const Index: Integer): TActionBarItem;
begin
  Result := TActionBarItem(Items[Index]);
end;

function TActionBars.GetHintShortCuts: Boolean;
begin
  Result := False;
  if Assigned(Application) then
    Result := Application.HintShortCuts;
end;

procedure TActionBars.Notify(Item: TCollectionItem;
  Action: TCollectionNotification);
begin
  inherited Notify(Item, Action);
  if Action = cnDeleting then
    if Item is TActionBarItem then
      with Item as TActionBarItem do
        if Assigned(FActionBar) then
          FActionBar.FActionClient := nil;
end;

procedure TActionBars.SetShowHints(const Value: Boolean);
begin
  if Value <> FShowHint then
  begin
    FShowHint := Value;
    IterateClients(Self, DoShowHint);
  end;
end;

procedure TActionBars.SetHintShortCuts(const Value: Boolean);
begin
  if Assigned(Application) then
    Application.HintShortCuts := Value;
end;

{ TActionClients }

constructor TActionClients.Create(AOwner: TPersistent;
  ItemClass: TCollectionItemClass);
begin
  inherited Create(AOwner, ItemClass);
  FCaptionOptions := coSelective;
  FSmallIcons := True;
  FHideUnused := True;
  FAutoHotKeys := True;
end;

function TActionClients.Add: TActionClientItem;
begin
  Result := TActionClientItem(inherited Add);
end;

procedure TActionClients.Assign(Source: TPersistent);
begin
  inherited Assign(Source);
  if Source is TActionClients then
  begin
    AutoHotKeys := TActionClients(Source).AutoHotKeys;
    Customizable := TActionClients(Source).Customizable;
    HideUnused := TActionClients(Source).HideUnused;
    CaptionOptions := TActionClients(Source).CaptionOptions;
    SmallIcons := TActionClients(Source).SmallIcons;
  end;
end;

procedure TActionClients.DoHideUnused(AClient: TActionClient);
begin
  if not (AClient is TActionClientItem) then exit;
  with AClient as TActionClientItem do
  begin
    FCheckUnused := True;
    if Assigned(FItems) then
      Items.HideUnused := FHideUnused;
  end;
end;

procedure TActionClients.DoShowCaptions(AClient: TActionClient);
begin
  if not (AClient is TActionClientItem) then exit;
    with AClient as TActionClientItem do
      if Assigned(Control) then
        Control.CalcBounds;
end;

function TActionClients.GetActionClient(const Index: Integer): TActionClientItem;
begin
  Result := TActionClientItem(Items[Index]);
end;

procedure TActionClients.Notify(Item: TCollectionItem;
  Action: TCollectionNotification);
var
  ActnBar: TCustomActionBar;
begin
  inherited Notify(Item, Action);
  case Action of
    cnAdded:
      with Item as TActionClient do
        if Assigned(Self.ParentItem) then
        begin
          if Assigned(Self.ParentItem) then
            Self.ParentItem.OwningCollection.InternalRethinkHotkeys(True);
          ActnBar := nil;
          if Assigned(Self.ParentItem.ActionBar) then
            ActnBar := Self.ParentItem.ActionBar
          else
            if Assigned(Self.ParentItem.ChildActionBar) then
              ActnBar := Self.ParentItem.ChildActionBar;
          if (Self.UpdateCount = 0) and Assigned(ActnBar) and ActnBar.HandleAllocated then
            ActnBar.CreateControl(TActionClientItem(Item));
        end;
    cnExtracting:
      if Item is TActionClientItem then
        with Item as TActionClientItem do
          if Assigned(ParentItem) and Assigned(ParentItem.ChildActionBar) and
             ParentItem.ChildActionBar.HandleAllocated then
            PostMessage(ParentItem.ChildActionBar.Handle, WM_SIZE, 0 ,0);
    cnDeleting:
      begin
        TActionClient(Item).FreeChildren;
        if Item is TActionClientItem then
          with Item as TActionClientItem do
            if Assigned(ParentItem) and Assigned(ParentItem.ChildActionBar) and
               ParentItem.ChildActionBar.HandleAllocated then
              PostMessage(ParentItem.ChildActionBar.Handle, WM_SIZE, 0 ,0);
      end;
  end;
end;

procedure TActionClients.SetActionClient(const Index: Integer;
  const Value: TActionClientItem);
begin
  inherited SetItem(Index, Value);
end;

procedure TActionClients.SetAutoHotKeys(const Value: Boolean);
begin
  if FAutoHotKeys <> Value then
  begin
    FAutoHotKeys := Value;
    InternalRethinkHotkeys(True);
  end;
end;

procedure TActionClients.SetCaptionOptions(const Value: TCaptionOptions);
begin
  if FCaptionOptions <> Value then
  begin
    FCaptionOptions := Value;
    if Assigned(ParentItem) and Assigned(ParentItem.ActionBar) then
    begin
      ParentItem.ActionBar.DisableAlign;
      try
        IterateClients(Self, DoShowCaptions);
      finally
        ParentItem.ActionBar.EnableAlign;
      end;
    end
    else
      IterateClients(Self, DoShowCaptions);
  end;
end;

procedure TActionClients.SetHideUnused(const Value: Boolean);
begin
  if FHideUnused <> Value then
  begin
    FHideUnused := Value;
    if not (csLoading in ActionManager.ComponentState) then
      IterateClients(Self, DoHideUnused);
  end;
end;

procedure TActionClients.SetSmallIcons(const Value: Boolean);
begin
  if FSmallIcons <> Value then
  begin
    FSmallIcons := Value;
    if Assigned(FParentItem) and Assigned(FParentItem.ActionBar) then
    begin
      FParentItem.ActionBar.DisableAlign;
      try
        ToggleSmallIcons(Self, Value);
        FParentItem.ActionBar.RequestAlign;
      finally
        FParentItem.ActionBar.EnableAlign;
        FParentItem.ActionBar.Resize;
      end;
    end
    else
      ToggleSmallIcons(Self, Value);
  end;
end;

procedure TActionClients.ToggleSmallIcons(Clients: TActionClients;
  Small: Boolean);
var
  I: Integer;
begin
  if Clients = nil then exit;
  for I := 0 to Clients.Count - 1 do
  begin
    if Assigned(Clients[I].Control) then
      Clients[I].Control.SmallIcon := Small;
    if Clients[I].HasItems then
    begin
      Clients[I].Items.SmallIcons := Small;
      ToggleSmallIcons(Clients[I].Items, Small);
    end
    else
      if Assigned(Clients[I].Control) then
        Clients[I].Control.SmallIcon := Small;
  end;
end;

function TActionClients.VisibleCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to Count - 1 do
    if ActionClients[I].Visible then
      Inc(Result);
end;

{ TActionClientLink }

procedure TActionClientLink.AssignClient(AClient: TObject);
begin
  FClient := AClient as TActionClientItem;
end;

function TActionClientLink.IsCaptionLinked: Boolean;
var
  S: String;
begin
  Result := inherited IsCaptionLinked and
    (FClient.Caption = (Action as TCustomAction).Caption);
  if not Result and TActionClients(FClient.Collection).AutoHotKeys then
  begin
    S := FClient.Caption;
    if Pos('&', S) > 0 then
      Delete(S, Pos('&', S), 1);
    Result := S = (Action as TCustomAction).Caption;
  end;
end;

function TActionClientLink.IsEnabledLinked: Boolean;
begin
  Result := inherited IsEnabledLinked and Assigned(FClient.FControl) and
    (FClient.FControl.Enabled = (Action as TCustomAction).Enabled);
end;

function TActionClientLink.IsHintLinked: Boolean;
begin
  Result := inherited IsHintLinked and Assigned(FClient.FControl) and
    (FClient.FControl.Hint = (Action as TCustomAction).Hint);
end;

function TActionClientLink.IsImageIndexLinked: Boolean;
begin
  Result := inherited IsImageIndexLinked and Assigned(FClient.FControl) and
    (FClient.FControl.Hint = (Action as TCustomAction).Hint);
end;

function TActionClientLink.IsOnExecuteLinked: Boolean;
begin
  Result := inherited IsOnExecuteLinked and Assigned(FClient.FControl) and
    (@FClient.FControl.OnClick = @Action.OnExecute);
end;

function TActionClientLink.IsShortCutLinked: Boolean;
begin
  Result := inherited IsShortCutLinked and
    (FClient.ShortCut = (Action as TCustomAction).ShortCut);
end;

function TActionClientLink.IsVisibleLinked: Boolean;
begin
  Result := inherited IsVisibleLinked and (FClient.Visible =
    (Action as TCustomAction).Visible);
end;

procedure TActionClientLink.SetCaption(const Value: string);
begin
  if IsCaptionLinked then FClient.Caption := Value;
end;

procedure TActionClientLink.SetChecked(Value: Boolean);
begin
  inherited SetChecked(Value);
  if IsCheckedLinked and Assigned(FClient.Control) then FClient.Control.Invalidate;
end;

procedure TActionClientLink.SetEnabled(Value: Boolean);
begin
  if IsEnabledLinked then
    FClient.FControl.Enabled := Value;
end;

procedure TActionClientLink.SetHint(const Value: string);
begin
  if IsHintLinked then FClient.FControl.Hint := Value;
end;

procedure TActionClientLink.SetImageIndex(Value: Integer);
begin
  if IsImageIndexLinked then FClient.ImageIndex := Value;
end;

procedure TActionClientLink.SetOnExecute(Value: TNotifyEvent);
begin
  if IsOnExecuteLinked then
    FClient.FControl.OnClick := Value;
end;

procedure TActionClientLink.SetShortCut(Value: TShortCut);
begin
  if IsShortCutLinked then
    FClient.Shortcut := Value;
end;

procedure TActionClientLink.SetVisible(Value: Boolean);
begin
  if IsVisibleLinked then
    FClient.Visible := Value;
end;

{ TActionClientItem }

constructor TActionClientItem.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FImageIndex := -1;
  FMergeIndex := 0;
  FShowCaption := True;
  FShowGlyph := True;
  FShowShortCut := True;
  FCheckUnused := True;
  FUsageCount := 0;
  FLastSession := 0;
end;

destructor TActionClientItem.Destroy;
begin
  FreeAndNil(FActionLink);
  FreeAndNil(FControl);
  inherited Destroy;
end;

procedure TActionClientItem.ActionChange(Sender: TObject;
  CheckDefaults: Boolean);
begin
  if Sender is TCustomAction then
    with TCustomAction(Sender) do
    begin
      if Assigned(Self.FControl) then
      begin
        if (not CheckDefaults or (Self.FControl.Enabled = True)) then
          Self.FControl.Enabled := Enabled;
        if not CheckDefaults or (Self.FControl.Hint = '') then
          Self.FControl.Hint := Hint;
        if not CheckDefaults or not Assigned(Self.FControl.OnClick) then
          Self.FControl.OnClick := OnExecute;
      end;
      if not CheckDefaults or (Self.Caption = '') then
        Self.Caption := Caption;
      if not CheckDefaults or (Self.ImageIndex = 0) then
        Self.ImageIndex := ImageIndex;
      if not CheckDefaults or (Self.ShortCut = 0) then
        Self.ShortCut := ShortCut;
      if not CheckDefaults or (Self.Visible = True) then
        Self.Visible := Visible;
    end;
end;

procedure TActionClientItem.Assign(Source: TPersistent);
begin
  if Source is TActionClientItem then
  begin
    if Assigned(Collection) then Collection.BeginUpdate;
    try
      Action := TActionClientItem(Source).Action;
      Caption := TActionClientItem(Source).Caption;
      ImageIndex := TActionClientItem(Source).ImageIndex;
      MergeIndex := TActionClientItem(Source).MergeIndex;
      LastSession := TActionClientItem(Source).LastSession;
      ShowCaption := TActionClientItem(Source).ShowCaption;
      ShowGlyph := TActionClientItem(Source).ShowGlyph;
      ShowShortCut := TActionClientItem(Source).ShowShortCut;
      ShortCut := TActionClientItem(Source).ShortCut;
      UsageCount := TActionClientItem(Source).UsageCount;
      if Assigned(TActionClientItem(Source).FItems) then
        Items.Assign(TActionClientItem(Source).Items);
    finally
      if Assigned(Collection) then Collection.EndUpdate;
    end;
  end
  else
    inherited Assign(Source);
end;

procedure TActionClientItem.ColorChanged;
begin
  if Assigned(FControl) then
    case FColor of
      clDefault: FControl.ParentColor := True;
      clNone   : FControl.Transparent := True;
    else
      FControl.Color := Color;
    end;
end;

procedure TActionClientItem.DoActionChange(Sender: TObject);
begin
  if Sender = Action then ActionChange(Sender, True);
end;

function TActionClientItem.GetActionClients: TActionClients;
begin
  Result := TActionClients(Collection);
end;

function TActionClientItem.GetActionLinkClass: TActionClientLinkClass;
begin
  Result := TActionClientLink;
end;

function TActionClientItem.GetAction: TContainedAction;
begin
  if ActionLink <> nil then
    Result := TContainedAction(ActionLink.Action) else
    Result := nil;
end;

function TActionClientItem.GetCaption: string;
begin
  if Assigned(ActionBarDesigner) and (Length(FCaption) = 0) and
     not Assigned(Action) then
    Result := Format('ActionClientItem%d', [Index])  { do not localize }
  else
    Result := FCaption;
end;

function TActionClientItem.GetDisplayName: string;
begin
  Result := inherited GetDisplayName;
  if Length(Caption) > 0 then
    Result := Caption
  else
    if Action is TCustomAction then
      with Action as TCustomAction do
        if Length(Caption) > 0 then
          Result := Caption;
end;

function TActionClientItem.HasGlyph: Boolean;
begin
  Result := (Action is TCustomAction) and ShowGlyph;
  if Result then
    with TCustomAction(Action) do
      Result := (Self.ImageIndex <> -1) and Assigned(ActionList.Images) and
        (ImageIndex > -1) and (ImageIndex < ActionList.Images.Count);
end;

procedure TActionClientItem.InitiateAction;
begin
  if ActionLink <> nil then
    ActionLink.Update;
end;

function TActionClientItem.IsCaptionStored: Boolean;
begin
  if Assigned(Action) and (Action is TCustomAction) then
    Result := CompareText(Caption, TCustomAction(Action).Caption) <> 0
  else
    Result := True;
end;

procedure TActionClientItem.Refresh;
begin
  if Assigned(FControl) then
    FControl.CalcBounds;
end;

procedure TActionClientItem.ResetUsageData;
var
  ParentCollection: TActionClientsCollection;
  ParentItem: TActionClient;
begin
  if FUsageCount <> -1 then
  begin
    Inc(FUsageCount);
    FCheckUnused := True;
  end;
  FLastSession := ActionClients.ActionManager.ActionBars.SessionCount;
  ParentItem := ActionClients.ParentItem;
  if Assigned(ParentItem) then
  begin
    ParentCollection := ActionClients.ParentItem.OwningCollection;
    while Assigned(ParentCollection) and not (ParentCollection is TActionBars) do
      ParentCollection := ParentCollection.FParentItem.OwningCollection;
    if Assigned(ParentCollection) then
      FLastSession := TActionBars(ParentCollection).SessionCount;
    while Assigned(ParentItem) do
    begin
      if ParentItem is TActionClientItem then
      begin
        TActionClientItem(ParentItem).FCheckUnused := True;
        if TActionClientItem(ParentItem).FUsageCount <> -1 then
          Inc(TActionClientItem(ParentItem).FUsageCount);
        TActionClientItem(ParentItem).LastSession := FLastSession;
      end;
      ParentItem := ParentItem.OwningCollection.FParentItem;
    end
  end;
end;

procedure TActionClientItem.SetAction(const Value: TContainedAction);
begin
  if Value = nil then
  begin
    ActionLink.Free;
    ActionLink := nil;
  end
  else
  begin
    if Value = Action then exit;
    if Assigned(Control) then
      FreeAndNil(FControl);
    if ActionLink = nil then
      ActionLink := GetActionLinkClass.Create(Self);
    ActionLink.Action := Value;
    ActionLink.OnChange := DoActionChange;
    ActionChange(Value, (csLoading in Value.ComponentState) or
      ActionClients.ActionManager.Loading);
    Value.FreeNotification(TActionClients(Collection).ActionManager);
    if Assigned(ActionClients.ParentItem) then
      if Assigned(ActionClients.ParentItem.ActionBar) then
        ActionClients.ParentItem.ActionBar.CreateControl(Self)
      else if Assigned(ActionClients.ParentItem.ChildActionBar) then
        ActionClients.ParentItem.ChildActionBar.CreateControl(Self)
  end;
end;

procedure TActionClientItem.SetCaption(const Value: string);
begin
  if FCaption <> Value then
  begin
    FCaption := Value;
    FSeparator := (Action = nil) and ((Value = '-') or (Value = '|'));
    if Separator then
    begin
      Action := nil;
      ShortCut := 0;
    end;
    if Assigned(FControl) then
      Control.Caption := Value;
  end;
end;

procedure TActionClientItem.SetControl(const Value: TCustomActionControl);
begin
  if FControl <> Value then
  begin
    FreeAndNil(FControl);
    FControl := Value;
    if Assigned(FControl) then
    begin
      ActionChange(Action, True);
      FControl.ActionClient := Self;
    end;
  end;
end;

procedure TActionClientItem.SetImageIndex(const Value: Integer);
begin
  if FImageIndex <> Value then
  begin
    FImageIndex := Value;
    if Assigned(Control) then
    begin
      Control.CalcBounds;
      Control.Invalidate;
    end;
  end;
end;

procedure TActionClientItem.SetIndex(Value: Integer);
begin
  inherited SetIndex(Value);
  if Assigned(FControl) then
    FControl.PositionChanged;
  NotifyDesigner(ActionBar);
end;

procedure TActionClientItem.SetLastSession(const Value: Integer);
begin
  if FLastSession <> Value then
  begin
    FLastSession := Value;
    FCheckUnused := True;
  end;
end;

procedure TActionClientItem.SetMergeIndex(const Value: TMergeRange);
var
  I: Integer;
begin
  if (Value > FMergeIndex) or (Index = 0) or
     (ActionClients.ActionClients[Index - 1].FMergeIndex = 0) then
  begin
    for I := Index + 1 to ActionClients.Count - 1 do
    begin
      with ActionClients.ActionClients[I] do
      if Self.FMergeIndex = FMergeIndex then
        FMergeIndex := Value
      else
        FMergeIndex := Value + Abs(Self.FMergeIndex - FMergeIndex);
    end;
    FMergeIndex := Value;
  end;
end;

procedure TActionClientItem.SetShortCut(const Value: TShortCut);
begin
  if FShortCut <> Value then
  begin
    FShortCut := Value;
    FShortCutText := ShortCutToText(Value);
    Refresh;
  end;
end;

procedure TActionClientItem.SetShowCaption(const Value: Boolean);
begin
  if FShowCaption <> Value then
  begin
    if not (csLoading in ActionClients.ActionManager.ComponentState) and not HasGlyph then
      FShowCaption := Value or Assigned(FControl) and (FControl.ComponentCount = 0)
    else
      FShowCaption := Value;
    Refresh;
  end;
end;

procedure TActionClientItem.SetShowShortCut(const Value: Boolean);
begin
  if FShowShortCut <> Value then
  begin
    FShowShortCut := Value;
    if Assigned(FControl) then
    begin
      FControl.CalcBounds;
      FControl.Parent.Realign;
    end;
  end;
end;

procedure TActionClientItem.SetUsageCount(const Value: Integer);
begin
  if Value = MaxInt then
    FUsageCount := 0
  else
    FUsageCount := Value;
  FCheckUnused := True;
  if Assigned(FControl) then
    FControl.Invalidate;
end;

procedure TActionClientItem.SetVisible(const Value: Boolean);
begin
  if (FVisible <> Value) or (Assigned(Control) and (Control.Visible <> Value)) then
  begin
    FVisible := Value;
    if Assigned(FControl) and (FControl.Visible <> Value) then
      FControl.Visible := FVisible;
    if Assigned(FActionBar) then
    begin
      if (FActionBar.Visible <> Value) then
        if FActionBar.Parent is TXToolDockForm then
          FActionBar.Parent.Visible := False
        else
          FActionBar.Visible := FVisible;
      if not (csDesigning in FActionBar.ComponentState) then
        Refresh;
    end;
  end;
end;

procedure TActionClientItem.SetChangesAllowed(
  const Value: TChangesAllowedSet);
begin
  inherited SetChangesAllowed(Value);
  if Byte(ChangesAllowed) < Byte(ActionClients.ParentItem.ChangesAllowed) then
    ActionClients.ParentItem.ChangesAllowed := ChangesAllowed;
end;

procedure TActionClientItem.SetShowGlyph(const Value: Boolean);
begin
  if FShowGlyph <> Value then
  begin
    FShowGlyph := Value;
    if Assigned(Control) then
      Control.CalcBounds;
  end;
end;

procedure TActionClientItem.SetCollection(Value: TCollection);
begin
  if Assigned(FControl) then
  begin
    FreeAndNil(FControl);
    if Assigned(ActionBar) then
      ActionBar.Resize;
  end;
  inherited SetCollection(Value);
end;

function TActionClientItem.Unused: Boolean;

  function CheckControl(Item: TActionClientItem): Boolean;
  begin
    Result := Item.Visible and Assigned(Item.Control) and Item.Control.Visible;
  end;

var
  I: Integer;
begin
  Result := FUnused;
  if not FCheckUnused then exit;
  if not ActionClients.HideUnused then
  begin
    Result := False;
    exit;
  end;
  with ActionClients.ActionManager do
    // if item is a separator and items surrounding it are unused, it is unused too
    if Separator then
    begin
      for I := Index - 1 downto 0 do
        if (Index > 0) then
        begin
          if ActionClients.ActionClients[Index - 1].Separator then
            break;
          Result := not GetUsage(ActionClients.ActionClients[Index - 1]);
          if Result then
            break;
        end;

      if Result then
        for I := 0 to Collection.Count - 1 do
          if (Index < Collection.Count - 1) then
          begin
            if ActionClients.ActionClients[Index + 1].Separator then
              break;
            Result := not GetUsage(ActionClients.ActionClients[Index + 1]);
            if Result then
              break;
          end;
    end
    else
    begin
      Result := not GetUsage(Self);
      if Result and (Items.Count > 0) then
        Result := not HasVisibleItems;
      FCheckUnused := False;
    end;
  FUnused := Result;
end;

{ TActionDragObject }

constructor TActionDragObject.Create;
begin
  FActions := TList.Create;
  FActionClasses := False;
end;

destructor TActionDragObject.Destroy;
begin
  FActions.Free;
  inherited Destroy;
end;

procedure TActionDragObject.AddAction(AnAction: TContainedAction);
begin
  FActions.Add(AnAction);
end;

procedure TActionDragObject.AddActionClass(AnActionClass: TCustomActionClass);
begin
  FActions.Add(AnActionClass);
end;

function TActionDragObject.GetAction(
  Index: Integer): TContainedAction;
begin
  if FActionClasses then
    Result := ActionBarDesigner.CreateAction(FActions[Index])
  else
    Result := TCustomAction(FActions[Index]);
end;

function TActionDragObject.GetActionCount: Integer;
begin
  Result := FActions.Count;
end;

{ TCategoryDragObject }

constructor TCategoryDragObject.Create(ACategory: string);
begin
  inherited Create;
  FCategory := ACategory;
end;

{ TActionItemDragObject }

procedure TActionItemDragObject.Finished(Target: TObject; X, Y: Integer;
  Accepted: Boolean);
var
  P: TPoint;
begin
  inherited Finished(Target, X, Y, Accepted);
  if not Assigned(ClientItem.Control) then exit;
  P := ClientItem.Control.ScreenToClient(Point(X, Y));
  if Dropped and not Accepted and not PtInRect(ClientItem.Control.ClientRect, P) then
  begin
    ClientItem.Free;
    if Assigned(ActionBarDesigner) then
      ActionBarDesigner.Modified(nil);
  end;
end;

{ TCustomActionBar }

constructor TCustomActionBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FActionManager := nil;
  FActionClient := nil;
  FCanvas := TControlCanvas.Create;
  TControlCanvas(FCanvas).Control := Self;
  ControlStyle := ControlStyle + [csClickEvents, csDoubleClicks, csSetCaption,
    csOpaque];
  Height := 50;
  Width := 150;
  DoubleBuffered := True;
  FVertMargin := 1;
  FHorzMargin := 0;
  FAllowHiding := True;
end;

destructor TCustomActionBar.Destroy;
begin
  ActionManager := nil;
  FCanvas.Free;
  inherited Destroy;
end;

procedure TCustomActionBar.AlignControls(AControl: TControl;
  var Rect: TRect);
begin
  FHRowCount := 1;
  FVRowCount := 1;
  FWidest := 0;
  FTallest := 0;
  inherited AlignControls(AControl, Rect);
end;

procedure TCustomActionBar.AutoSizingChanged;
begin
end;

function TCustomActionBar.BackgroundSize: TPoint;
begin
  Result := Point(0, 0);
end;

function TCustomActionBar.CalcInsertPosition(Control: TCustomActionControl;
  X, Y: Integer): Integer;
begin
  if Control <> nil then
  begin
    Result := Control.ActionClient.Index;
    if (X < Control.Left) and (Orientation in [boLeftToRight]) then
      Dec(Result);
    if (Y < Control.Top) and (Orientation in [boTopToBottom]) then
      Dec(Result);
    if (X > Control.BoundsRect.Right) and (Orientation in [boLeftToRight]) then
      Inc(Result);
    if (Y > Control.BoundsRect.Bottom) and (Orientation in [boTopToBottom]) then
      Inc(Result);
    if Result > Items.Count then
      Result := Items.Count;
    if Result < 0 then Result := 0;
  end
  else
    if HasItems then
      Result := Items.Count
    else
      Result := 0;
end;

procedure TCustomActionBar.Clear;
var
  I: Integer;
begin
  if Assigned(FActionClient) then
  begin
    for I := ItemCount - 1 downto 0 do
      ActionControls[I].Free;
    FActionClient.ClearActionBar;
    FActionClient := nil;
  end;
end;

procedure TCustomActionBar.CMEnabledchanged(var Message: TMessage);
begin
  inherited;
  Broadcast(Message);
end;

function TCustomActionBar.CreateControl(
  AnItem: TActionClientItem): TCustomActionControl;
var
  ItemClass: TCustomActionControlClass;
begin
  if AnItem.Control <> nil then
  begin
    AnItem.Control.Free;
    AnItem.Control := nil;
  end;
  Result := nil;
  ItemClass := DoGetControlClass(AnItem);
  if ItemClass = nil then exit;
  DisableAlign;
  try
    Result := ItemClass.Create(Self);
    with Result do
    begin
      DragMode := ControlDragMode[DesignMode];
      Align := alCustom;
      FActionBar := Self;
      Parent := Self;
      BiDiMode := Self.BiDiMode;
      ActionClient := AnItem;
      ActionClient.Control := Result;
      RequestAlign;
    end;
  finally
    EnableAlign;
  end;
end;

procedure TCustomActionBar.CreateControls;
var
  I: Integer;
  NewControl: TCustomActionControl;
  Items: TActionClients;
begin
  if (FActionClient = nil) then exit;
  DisableAlign;
  try
    if ContextBar then
      Items := FActionClient.ContextItems
    else
      Items := FActionClient.Items;
    if not Items.Count = 0 then exit;
    for I := 0 to Items.Count - 1 do
    begin
      NewControl := CreateControl(Items.ActionClients[I]);
      if Assigned(NewControl) then
      begin
        NewControl.Transparent := FActionClient.HasBackground and
          not (FActionClient.BackgroundLayout in [blLeftBanner, blRightBanner]);
        DoControlCreated(NewControl);
      end;
    end;
  finally
    EnableAlign;
  end;
end;

function TCustomActionBar.CustomAlignInsertBefore(C1,
  C2: TControl): Boolean;
begin
  Result := (C1 is TCustomActionControl) and (C2 is TCustomActionControl);
  if not Result then exit;
  if Assigned(TCustomActionControl(C1).ActionClient) and
    Assigned(TCustomActionControl(C2).ActionClient) then
    Result := TCustomActionControl(C1).ActionClient.Index <
      TCustomActionControl(C2).ActionClient.Index
  else
    Result := False;
  if C1.Visible and (C1.Height > FTallest) then
    FTallest := C1.Height;
  if C1.Visible and (C1.Width > FWidest) then
    FWidest := C1.Width;
  if C2.Visible and (C2.Height > FTallest) then
    FTallest := C2.Height;
  if C2.Visible and (C2.Width > FWidest) then
    FWidest := C2.Width;
  if Floating then
    case Orientation of
      boTopToBottom, boBottomToTop: Constraints.MinHeight := FTallest + VertMargin * 2;
      boLeftToRight, boRightToLeft: Constraints.MinWidth := FWidest + HorzMargin * 2 +
        GetBannerWidth(beEither);
    end;
end;

procedure TCustomActionBar.CustomAlignPosition(Control: TControl;
  var NewLeft, NewTop, NewWidth, NewHeight: Integer; var AlignRect: TRect;
  AlignInfo: TAlignInfo);
const
  SepSize: array[Boolean] of Integer = (0, 2);
var
  ABControl: TCustomActionControl;
begin
  if not (Control is TCustomActionControl) then exit;
  ABControl := TCustomActionControl(Control);
  if AlignInfo.AlignList.Count = 1 then
  begin
    FWidest := Control.Width;
    FTallest := Control.Height;
  end;
  if AlignInfo.ControlIndex = 0 then
    AlignRect := Rect(HorzMargin + GetBannerWidth(beLeft),
      VertMargin, ClientWidth - VertMargin - GetBannerWidth(beRight),
      ClientHeight - VertMargin);
  case FOrientation of
    boLeftToRight:
      begin
        if (Floating or AutoSizing) and (AlignInfo.ControlIndex <> 0) and
           (ABControl.Width + FHorzMargin > AlignRect.Right - AlignRect.Left) then
        begin
          AlignRect := Rect(FHorzMargin + GetBannerWidth(beLeft),
            AlignRect.Top + FTallest + (FVertMargin * 2 +
            SepSize[FHorzSeparator]),
            ClientWidth - FHorzMargin - GetBannerWidth(beRight),
            ClientHeight - AlignRect.Top - FVertMargin);
          Inc(FVRowCount);
        end;
        NewTop := AlignRect.Top;
        NewLeft := AlignRect.Left;
        NewHeight := FTallest;
        Inc(AlignRect.Left, ABControl.Width + FSpacing);
      end;
    boRightToLeft:
      begin
        if (Floating or AutoSizing) and (AlignInfo.ControlIndex <> 0) and
           (ABControl.Width > AlignRect.Right - AlignRect.Left) then
        begin
          AlignRect := Rect(FHorzMargin + GetBannerWidth(beLeft),
            AlignRect.Top + FTallest + (FVertMargin * 2 +
            SepSize[FHorzSeparator]),
            ClientWidth - FHorzMargin - GetBannerWidth(beRight),
            ClientHeight - AlignRect.Top - FVertMargin);
          Inc(FVRowCount);
        end;
        NewTop := AlignRect.Top;
        if AlignInfo.ControlIndex = 0 then
        begin
          NewLeft := AlignRect.Right - ABControl.Width - FHorzMargin;
          Dec(AlignRect.Right, FVertMargin + ABControl.Width + FSpacing);
        end
        else
        begin
          NewLeft := AlignRect.Right - ABControl.Width;
          if AlignInfo.ControlIndex = AlignInfo.AlignList.Count - 1 then
            Dec(AlignRect.Right, ABControl.Width)
          else
            Dec(AlignRect.Right, ABControl.Width + FSpacing);
        end;
        NewHeight := FTallest;
      end;
    boTopToBottom:
      begin
        if (Floating or AutoSizing) and (AlignInfo.ControlIndex <> 0) and
           (ABControl.Height > AlignRect.Bottom - AlignRect.Top) then
        begin
          AlignRect := Rect(ALignRect.Left + FWidest + HorzMargin * 2 + SepSize[FHorzSeparator],
            VertMargin, ClientWidth - HorzMargin - GetBannerWidth(beRight),
            ClientHeight - VertMargin);
          Inc(FHRowCount);
        end;
        if AlignInfo.ControlIndex = 0 then
          NewTop := VertMargin
        else
          NewTop := AlignRect.Top;
        AlignRect.Right := FWidest + GetBannerWidth(beEither);
        NewLeft := AlignRect.Left;
        NewWidth := FWidest;
        Inc(AlignRect.Top, ABControl.Height + FSpacing);
      end;
    boBottomToTop:
      begin
        if (Floating or AutoSizing) and (AlignInfo.ControlIndex <> 0) and
           (ABControl.Height > AlignRect.Bottom - AlignRect.Top) then
        begin
          AlignRect := Rect(HorzMargin + GetBannerWidth(beLeft), VertMargin,
            AlignRect.Right - FWidest - (HorzMargin * 2) - SepSize[FHorzSeparator],
            ClientHeight - VertMargin);
          Inc(FHRowCount);
        end;
        if AlignInfo.ControlIndex = 0 then
          NewTop := ClientHeight - Control.Height - HorzMargin
        else
          NewTop := AlignRect.Bottom - Control.Height - Spacing;
        NewLeft := AlignRect.Right - FWidest;
        NewWidth := FWidest;
        Dec(AlignRect.Bottom, ABControl.Height + FSpacing);
      end;
  end;
end;

procedure TCustomActionBar.DrawBackground;
var
   x,y,w,h : Integer;
begin
  if Assigned(FActionClient) and FActionClient.HasBackground then
  begin
    case FActionClient.BackgroundLayout of
      blRightBanner: Canvas.Draw(Width - FActionClient.Background.Graphic.Width,
        0, FActionClient.Background.Graphic);
      blLeftBanner,
      blNormal : Canvas.Draw(0, 0, FActionClient.Background.Graphic);
      blStretch: Canvas.StretchDraw(ClientRect, FActionClient.Background.Graphic);
      blTile:
        begin
          w := FActionClient.Background.Graphic.Width;
          h := FActionClient.Background.Graphic.Height;
          for x := 0 to ClientWidth div w do
           for y := 0 to ClientHeight div h do
             Canvas.Draw(w * x, h * y, FActionClient.Background.Graphic);
        end;
    end;
  end;
end;

procedure TCustomActionBar.DragOver(Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  inherited DragOver(Source, X, Y, State, Accept);
  Accept := ((Source is TActionDragObject) or (Source is TActionItemDragObject));
end;

procedure TCustomActionBar.DragDrop(Source: TObject; X, Y: Integer);
var
  Ctrl: TCustomActionControl;
  Offset: Integer;
begin
  inherited DragDrop(Source, X, Y);
  if (FActionClient = nil) then
  begin
    with Source as TActionDragObject do
      if (GetActionCount > 0) then
      begin
        Self.ActionManager := TCustomActionManager(ActionManager);
        FActionClient := ActionManager.ActionBars.Add;
        FActionClient.FActionBar := Self;
      end;
  end;
  DisableAlign;
  try
    if Source is TCategoryDragObject then
      DoDropCategory(Source as TCategoryDragObject, X, Y)
    else if Source is TActionDragObject then
      DoDropActions(Source as TActionDragObject, X, Y)
    else if (Source is TActionItemDragObject) then
      with Source as TActionItemDragObject do
      begin
        Ctrl := FindNearestControl(Point(X, Y));
        if Ctrl = ClientItem.Control then exit;
        if Ctrl = nil then
          ClientItem.Collection := Items
        else
        begin
          Offset := 0;
          if ((X > Ctrl.BoundsRect.Right) or (Y > Ctrl.BoundsRect.Bottom)) and
             (Ctrl.ActionClient.Index < Ctrl.ActionClient.ActionClients.Count - 1) then
            Offset := 1;
          if (X < Ctrl.BoundsRect.Left) or (Y < Ctrl.BoundsRect.Top) then
            Offset := 0;
          ClientItem.Collection := Items;
          ClientItem.Index := Ctrl.ActionClient.Index + Offset;
        end;
        CreateControl(ClientItem);
      end;
  finally
    ActionClient.Items.InternalRethinkHotkeys(True);
    ActionClient.Refresh;
    EnableAlign;
    Realign;
  end;
end;

function TCustomActionBar.DoGetControlClass(
  AnItem: TActionClientItem): TCustomActionControlClass;
begin
  if Assigned(FOnGetControlClass) then
    FOnGetControlClass(Self, AnItem, Result)
  else
    Result := GetControlClass(AnItem);
end;

procedure TCustomActionBar.DoControlCreated(Control: TCustomActionControl);
begin
  if Assigned(FOnControlCreated) then
    FOnControlCreated(Self, Control);
end;

function TCustomActionBar.FindAccelItem(const Accel: Word): TActionClientItem;
var
  I: Integer;
begin
  for I := 0 to ItemCount - 1 do
  begin
    Result := Items[I];
    if (Items.CaptionOptions <> coNone) and Result.Control.Parent.Showing and
       Result.Visible and Result.ShowCaption and Result.Control.Enabled and
       IsAccel(Accel, Result.Caption) then
      Exit;
  end;
  Result := nil;
end;

function TCustomActionBar.FindFirst: TActionClientItem;
begin
  if Assigned(FActionClient) and HasItems and (ControlCount > 0) then
    Result := Items[0]
  else
    Result := nil;
end;

function TCustomActionBar.FindItemAt(const P: TPoint): TCustomActionControl;
var
  Item: TControl;
begin
  Item := ControlAtPos(P, True);
  if Item is TCustomActionControl then
    Result := TCustomActionControl(Item)
  else
    Result := nil;
end;

function TCustomActionBar.FindItemCaption(const ACaption: string): TCustomActionControl;
var
  I: Integer;
begin
  Result := nil;
  for i := 0 to ItemCount - 1 do
    if CompareText(ActionControls[I].Caption, ACaption) = 0 then
    begin
      Result := ActionControls[I];
      break;
    end;
end;

function TCustomActionBar.FindLast: TActionClientItem;
begin
  if Assigned(FActionClient) and HasItems then
    Result := Items[Items.Count - 1]
  else
    Result := nil;
end;

function TCustomActionBar.FindLeastUsedItem(
  const Visible: Boolean = True): TActionClientItem;
var
  I: Integer;
  Age: Integer;
begin
  Result := FindFirst;
  if Result = nil then exit;
  while Assigned(Result) and not Result.Control.Visible do
    Result := FindPrevious(Result, False);
  Age := 0;
  for I := 1 to ItemCount - 1 do
  begin
    if Assigned(Items[I].Control) and
      (Items[I].Control.Visible <> Visible) then Continue;
    if Assigned(Items[I]) and Assigned(ActionControls[I]) and 
       (Age <= ActionManager.ActionBars.SessionCount - Items[I].LastSession) then
    begin
      Result := Items[I];
      Age := ActionManager.ActionBars.SessionCount - ActionControls[I].ActionClient.LastSession;
    end;
  end;
  if Result = nil then
    Result := FindLastVisibleItem;
end;

function TCustomActionBar.FindLastVisibleItem: TActionClientItem;
begin
  Result := FindLast;
  while Assigned(Result) and ((Result.Control = nil) or
     (Assigned(Result.Control) and not Result.Control.Visible)) do
    Result := FindPrevious(Result, False);
end;

function TCustomActionBar.FindFirstVisibleItem: TActionClientItem;
begin
  Result := FindFirst;
  while Assigned(Result) and Assigned(Result.Control) and not Result.Control.Visible do
    Result := FindNext(Result, False);
end;

function TCustomActionBar.FindNearestControl(
  const Point: TPoint): TCustomActionControl;

  function PointToRow(Pt: TPoint): Integer;
  var
    RowSize: Integer;
  begin
    Result := 1;
    if FVRowCount > 1 then
    begin
      RowSize := GetBarHeight div FVRowCount;
      Result := 1;
      while Pt.Y > RowSize * Result do
        Inc(Result);
    end;
    if FHRowCount > 1 then
    begin
      RowSize := GetBarWidth div FHRowCount;
      Result := 1;
      while Pt.X > RowSize * Result do
        Inc(Result);
    end;
  end;

var
  I: Integer;
  MinDistance: Integer;
  D: Integer;
  X1, Y1: Integer;
  Row: Integer;
  Ctrl: TControl;
begin
  Ctrl := ControlAtPos(Point, True);
  if Ctrl is TCustomActionControl then
  begin
    Result := TCustomActionControl(Ctrl);
    exit;
  end
  else
    Result := nil;
  MinDistance := MaxInt;
  Row := PointToRow(Point);
  for I := 0 to ItemCount - 1 do
  begin
    if (Items[I].Control = nil) or not Items[I].Control.Visible then Continue;
    if PointToRow(Items[I].Control.BoundsRect.TopLeft) <> Row then Continue;
    X1 := Point.X;
    Y1 := Point.Y;
    if Point.X < Items[I].Control.Left then X1 := Items[I].Control.Left;
    if Point.Y < Items[I].Control.Top then Y1 := Items[I].Control.Top;
    if Point.X > Items[I].Control.BoundsRect.Right then X1 := Items[I].Control.BoundsRect.Right;
    if Point.Y > Items[I].Control.BoundsRect.Bottom then Y1 := Items[I].Control.BoundsRect.Bottom;
    D := ((Point.X - X1) * (Point.X - X1)) + ((Point.Y - Y1) * (Point.Y - Y1));
    if D < MinDistance then
    begin
      MinDistance := D;
      Result := Items[I].Control;
    end;
  end;
end;

function TCustomActionBar.FindNextVisibleitem(AClient: TActionClientItem): TActionClientItem;
begin
  Result := FindNext(AClient, False);
  while Assigned(Result) and Assigned(Result.Control) and not Result.Control.Visible do
    Result := FindNext(Result, False);
end;

function TCustomActionBar.FindNext(AClient: TActionClientItem;
  const Wrap: Boolean = True): TActionClientItem;
begin
  Result := nil;
  if Assigned(AClient) then
  begin
    if HasItems and
       (AClient.Index < Items.Count - 1) then
      Result := Items[AClient.Index + 1]
    else
      if Wrap and (ItemCount > 1) then
        Result := Items[0];
  end
  else
    if Wrap then
      Result := FindFirst;
end;

function TCustomActionBar.FindPrevious(AClient: TActionClientItem;
  const Wrap: Boolean = True): TActionClientItem;
begin
  Result := nil;
  if Assigned(AClient) then
  begin
    if AClient.Index > 0 then
      Result := Items[AClient.Index - 1]
    else
      if Wrap and (ItemCount > 1) then
        Result := Items[Items.Count - 1];
  end
  else
    if Wrap then
      Result := FindLast;
end;

function TCustomActionBar.GetActionControl(const Index: Integer): TCustomActionControl;
begin
  if (Index >= 0) and (Index < ItemCount) then
    { Use Items to ensure we only get items from the ActionClients
     Collection.  ActionBars can add additional controls to enhance the utility
     of the Actionbar and in those cases we want to avoid returning controls
     that are not actually an Actionclient. }
    Result := Items[Index].Control
  else
    Result := nil;
end;

function TCustomActionBar.GetBannerWidth(
  BarEdge: TBarEdge): Integer;
begin
  Result := 0;
  if ActionClient = nil then exit;
  case BarEdge of
    beLeft : if ActionClient.BackgroundLayout = blLeftBanner then
               Result := ActionClient.Background.Bitmap.Width;
    beRight: if ActionClient.BackgroundLayout = blRightBanner then
               Result := ActionClient.Background.Bitmap.Width;
    beEither: if ActionClient.BackgroundLayout in [blLeftBanner, blRightBanner] then
                Result := ActionClient.Background.Bitmap.Width;
  end;
end;

function TCustomActionBar.GetControlClass(
  AnItem: TActionClientItem): TCustomActionControlClass;
begin
  Result := TCustomActionControl;
end;

function TCustomActionBar.GetItems: TActionClients;
begin
  Result := nil;
  if not Assigned(ActionClient) then exit;
  if ContextBar then
    Result := ActionClient.ContextItems
  else
    Result := ActionClient.Items;
end;

function TCustomActionBar.HasItems: Boolean;
begin
  Result := False;
  if not Assigned(ActionClient) then exit;
  if ContextBar then
    Result := Assigned(ActionClient.FContextItems) and
      (ActionClient.FContextItems.Count > 0)
  else
    Result := ActionClient.HasItems;
end;

function TCustomActionBar.ItemCount: Integer;
begin
  if Assigned(FActionClient) and HasItems then
    Result := Items.Count
  else
    Result := 0;
end;

procedure TCustomActionBar.Loaded;
var
  AM: TCustomActionManager;
begin
  inherited Loaded;
  if Assigned(FActionManager) then
  begin
    AM := FActionManager;
    SetActionManager(AM);
  end;
end;

procedure TCustomActionBar.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  case Operation of
    opRemove:
      if (AComponent = FActionManager) then
      begin
        Clear;
        FActionManager := nil;
      end;
  end;
end;

procedure TCustomActionBar.Paint;
begin
  DrawBackground;
  if Assigned(FOnPaint) then FOnPaint(Self);
end;

procedure TCustomActionBar.PaintWindow(DC: HDC);
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

procedure TCustomActionBar.SetActionClient(const Value: TActionClient);
begin
  if FActionClient <> Value then
  begin
    Clear;
    FActionClient := Value;
    if FActionClient = nil then exit;
    if FActionClient.Color <> clDefault then
      Color := FActionClient.Color;
    ActionManager := Value.OwningCollection.ActionManager;
    FActionClient := Value;
    AutoSizingChanged;
    CreateControls;
  end;
end;

procedure TCustomActionBar.SetDesignMode(const Value: Boolean);
var
  I: Integer;
begin
  if FDesignMode <> Value then
  begin
    FDesignMode := Value;
    if csDesigning in ComponentState then exit;
    if Assigned(ActionClient) and not Items.Customizable or
       (ActionClient.ChangesAllowed = []) then
      if FDesignMode then
      begin
        FEnabledState := Enabled;
        Enabled := False;
      end
      else
        Enabled := FEnabledState;

    if DesignMode then
    begin
      FSavedWrapState := DesignMode and AutoSizing;
      FSavedSize := Point(Width, Height);
    end;
    AutoSizing := (DesignMode or FSavedWrapState) and (ItemCount > 0);
    if not DesignMode then
      case Orientation of
        boLeftToRight, boRightToLeft: Height := FSavedSize.Y;
        boTopToBottom, boBottomToTop: Width := FSavedSize.X;
      end;
    for I := 0 to Items.Count - 1 do
      with Items[I] do
        if Assigned(Control) then
        begin
          if FDesignMode then
          begin
            if not Control.Visible then
              Control.Visible := True;
            Control.Enabled := (ChangesAllowed <> []) and
              (Self.ActionClient.ChangesAllowed <> []);
            Control.DragMode := ControlDragMode[DesignMode and
              (caMove in ActionClient.ChangesAllowed) or
              (caDelete in ActionClient.ChangesAllowed)];
          end
          else
          begin
            Control.DragMode := dmManual;
            if not Visible then
              Control.Visible := Visible;
            if Assigned(Action) then
              Action.Update;
          end;
       end;
  end;
end;

procedure TCustomActionBar.SetOrientation(const Value: TBarOrientation);
var
  I: Integer;
begin
  if FOrientation <> Value then
  begin
    FOrientation := Value;
    if ItemCount > 0 then
    begin
      DisableAlign;
      try
        for I := 0 to ItemCount - 1 do
          ActionControls[I].CalcBounds;
      finally
        EnableAlign;
      end;
    end;
  end;
end;

procedure TCustomActionBar.SetSpacing(const Value: Integer);
begin
  if FSpacing <> Value then
  begin
    FSpacing := Value;
    Realign;
  end;
end;

procedure TCustomActionBar.SetActionManager(const Value: TCustomActionManager);
begin
  if FActionManager <> Value then
  begin
    if Assigned(FActionManager) then
    begin
      FActionManager.RemoveFreeNotification(Self);
      Clear;
    end;
    FActionManager := Value;
    if Assigned(FActionManager) then
      FActionManager.FreeNotification(Self);
  end;
end;

procedure TCustomActionBar.SetPersistentHotKeys(const Value: Boolean);
begin
  if FPersistentHotKeys<> Value then
  begin
    FPersistentHotKeys:= Value;
    Refresh;
  end;
end;

procedure TCustomActionBar.DoDropActions(Source: TActionDragObject;
  const X, Y: Integer);
var
  Idx: Integer;
  I: Integer;
  AC: TActionClientItem;
begin
  Idx := CalcInsertPosition(FindNearestControl(Point(X, Y)), X, Y);
  with Source as TActionDragObject do
  begin
    if ActionCount = 0 then exit;
    for I := 0 to ActionCount - 1 do
    begin
      AC := TActionClientItem(ActionClient.Items.Insert(Idx));
      ActionClient.Items[Idx].Action := Actions[I];
      Idx := AC.Index + 1;
    end;
  end;
end;

procedure TCustomActionBar.DoDropCategory(Source: TCategoryDragObject;
  const X, Y: Integer);
var
  I: Integer;
  AC: TActionClientItem;
begin
  I := CalcInsertPosition(FindNearestControl(Point(X, Y)), X, Y);
  AC := TActionClientItem(Items.Insert(I));
  with Source as TCategoryDragObject do
  begin
    AC.Caption := Category;
    if ActionCount = 0 then exit;
    Items[AC.Index].Caption := Category;
    for I := 0 to ActionCount - 1 do
    begin
      with Items[AC.Index].Items.Insert(I) as TActionClientItem do
      begin
        Action := Actions[I];
        LastSession := ActionManager.ActionBars.SessionCount;
      end;
    end;
    AC.Control.CalcBounds;
    AC.Visible := True;
    AC.Control.Enabled := (Assigned(AC.Action) or
      (AC.HasItems and (AC.Items.VisibleCount > 0)));
  end;
end;

function TCustomActionBar.FindPreviousVisibleItem(
  AClient: TActionClientItem): TActionClientItem;
begin
  Result := FindPrevious(AClient, False);
  while Assigned(Result) and not Result.Visible do
    Result := FindPrevious(Result, False);
end;

procedure TCustomActionBar.SetBiDiMode(Value: TBiDiMode);
begin
  inherited SetBiDiMode(Value);
  if not (FOrientation in [boTopToBottom, boBottomToTop]) then
    case Value of
      bdLeftToRight: Orientation := boLeftToRight;
      bdRightToLeftNoAlign,
      bdRightToLeftReadingOnly,
      bdRightToLeft: Orientation := boRightToLeft;
   end;
end;

function TCustomActionBar.GetBarHeight: Integer;
begin
  Result := Height;
  if (ItemCount = 0) or (Align in [alLeft, alRight, alClient]) then exit;
  Result := VertMargin + FTallest * FVRowCount +
    (VertMargin * 2) * (FVRowCount - 1) + VertMargin;
  if HorzSeparator and (FVRowCount > 1) then
    Inc(Result, 2 * (FVRowCount - 1));
  if ebTop in EdgeBorders then
  begin
    if EdgeInner in [esRaised, esLowered] then
      Inc(Result);
    if EdgeOuter in [esRaised, esLowered] then
      Inc(Result);
  end;
  if ebBottom in EdgeBorders then
    if EdgeInner in [esRaised, esLowered] then
      Inc(Result);
    if EdgeOuter in [esRaised, esLowered] then
      Inc(Result);
end;

function TCustomActionBar.GetBarWidth: Integer;
begin
  Result := Width;
  if (ItemCount = 0) or not AutoSizing or (Align in [alTop, alBottom, alClient]) then exit;
  Result := HorzMargin + FWidest * FHRowCount +
    (HorzMargin * 2) * (FHRowCount - 1) + HorzMargin;
  if VertSeparator and (FHRowCount > 1) then
    Inc(Result, FHRowCount * 2);
  if ebLeft in EdgeBorders then
  begin
    if EdgeInner in [esRaised, esLowered] then
      Inc(Result);
    if EdgeOuter in [esRaised, esLowered] then
      Inc(Result);
  end;
  if ebRight in EdgeBorders then
    if EdgeInner in [esRaised, esLowered] then
      Inc(Result);
    if EdgeOuter in [esRaised, esLowered] then
      Inc(Result);
end;

function TCustomActionBar.GetDesignMode: Boolean;
begin
  Result := (csDesigning in ComponentState) or FDesignMode;
end;

procedure TCustomActionBar.SetHorzMargin(const Value: Integer);
begin
  if FHorzMargin <> Value then
  begin
    FHorzMargin := Value;
    Realign;
    AdjustSize;
  end;
end;

procedure TCustomActionBar.SetVertMargin(const Value: Integer);
begin
  if FVertMargin <> Value then
  begin
    FVertMargin := Value;
    Realign;
    AdjustSize;
  end;
end;

procedure TCustomActionBar.SetHorzSeparator(const Value: Boolean);
begin
  if FHorzSeparator <> Value then
  begin
    FHorzSeparator := Value;
    Realign;
    AdjustSize;
  end;
end;

procedure TCustomActionBar.SetVertSeparator(const Value: Boolean);
begin
  if FHorzSeparator <> Value then
  begin
    FHorzSeparator := Value;
    Realign;
    AdjustSize;
  end;
end;

procedure TCustomActionBar.CMResetBar(var Message: TMessage);
begin
  Reset;
end;

procedure TCustomActionBar.Reset;
var
  AC: TActionClient;
begin
  if Assigned(ActionManager) then
  begin
    DisableAlign;
    AC := ActionClient;
    try
      ActionClient := nil;
      ActionManager.ResetActionBar(AC.Index);
    finally
      ActionClient := AC;
      EnableAlign
    end;
  end;
end;

procedure TCustomActionBar.Resize;
begin
  inherited Resize;
end;

procedure TCustomActionBar.VisibleChanging;
begin
  inherited VisibleChanging;
  if not AllowHiding then
    raise Exception.CreateFmt(SCannotHideActionBand, [Name]);
end;

procedure TCustomActionBar.WMContextMenu(var Message: TWMContextMenu);
var
  PopupMenu: TCustomActionPopupMenu;
begin
  inherited;
  if Assigned(ActionClient) and (ActionClient.ContextItems.Count > 0) then
  begin
    PopupMenu := MenuPopupClass.Create(Owner);
    PopupMenu.ContextBar := True;
    PopupMenu.ParentWindow := Application.Handle;
    PopupMenu.Parent := Self;
    PopupMenu.ActionClient := ActionClient;
    PopupMenu.Popup(Message.XPos, Message.YPos);
    PopupMenu.Free;
  end;
end;

function TCustomActionBar.GetAutoSizing: Boolean;
begin
  Result := ActionClient is TActionBarItem and TActionBarItem(ActionClient).AutoSize
end;

procedure TCustomActionBar.SetAutoSizing(const Value: Boolean);
begin
  if ActionClient is TActionBarItem then
    TActionBarItem(ActionClient).AutoSize := Value;
end;

{ TCustomActionControl }

constructor TCustomActionControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csDesignInteractive];
  Height := 22;
  Width := 22;
  FGlyphLayout := blGlyphLeft;
  ParentShowHint := True;
  FMargins := Rect(4,4,4,4);
  FTransparent := True;
end;

destructor TCustomActionControl.Destroy;
begin
  if Assigned(FActionClient) and (FActionClient.Control = Self) then
    FActionClient.FControl := nil;
  inherited Destroy;
end;

procedure TCustomActionControl.BeginAutoDrag;
begin
  SetSelected(True);
  BeginDrag(False, Mouse.DragThreshold);
end;

function TCustomActionControl.CaptionLength: Integer;
begin
  if Assigned(ActionClient) and ShowCaption or not HasGlyph or
     (ActionClient.ActionClients.CaptionOptions = coAll) then
    Result := FTextBounds.Right - FTextBounds.Left
  else
    Result := 0;
end;

function TCustomActionControl.CaptionHeight: Integer;
begin
  if Assigned(ActionClient) and ShowCaption or not HasGlyph or
     (ActionClient.ActionClients.CaptionOptions = coAll) then
    Result := FTextBounds.Bottom - FTextBounds.Top
  else
    Result := 0;
end;

function TCustomActionControl.ActualSpacing(ImageSize: TPoint): Integer;
begin
  // Assumes that if the CaptionLength = 0 then CaptionHeight would also = 0
  if (ImageSize.X = 0) or (CaptionLength = 0) then
    Result := 0
  else
    Result := FSpacing;
end;

procedure TCustomActionControl.CalcLayout;
var
  AWidth: Integer;
  AHeight: Integer;
  ImageSize: TPoint;
begin
  if ActionClient = nil then exit;
  ImageSize := GetImageSize;
  Canvas.Font.Assign(Font);
  UpdateTextBounds;
  AWidth := Width;
  AHeight := Height;
  case GlyphLayout of
    blGlyphRight,
    blGlyphLeft:
      begin
        if GlyphLayout = blGlyphLeft then
        begin
          FGlyphPos := Point(FMargins.Left, AHeight div 2 - ImageSize.Y div 2);
          OffsetRect(FTextBounds, FMargins.Left + ImageSize.X + ActualSpacing(ImageSize),
            AHeight div 2 - CaptionHeight div 2);
        end
        else
        begin
          FGlyphPos := Point(AWidth - FMargins.Right - ImageSize.X,
            AHeight div 2 - ImageSize.Y div 2);
          OffsetRect(FTextBounds, FMargins.Left, AHeight div 2 - CaptionHeight div 2);
        end;
      end;
    blGlyphTop,
    blGlyphBottom:
      begin
        if GlyphLayout = blGlyphTop then
        begin
          if ShowCaption then
            FGlyphPos := Point(AWidth div 2 - ImageSize.X div 2, FMargins.Top)
          else
            FGlyphPos := Point(AWidth div 2 - ImageSize.X div 2,
              AHeight div 2 - ImageSize.Y div 2);
            OffsetRect(FTextBounds, AWidth div 2 - CaptionLength div 2,
              AHeight - FMargins.Bottom - CaptionHeight);
        end
        else
        begin
          OffsetRect(FTextBounds, AWidth div 2 - CaptionLength div 2, FMargins.Top);
          FGlyphPos := Point(AWidth div 2 - ImageSize.X div 2, FTextBounds.Top +
            CaptionHeight + ActualSpacing(ImageSize));
        end;
      end;
  end;
end;

procedure TCustomActionControl.CMFontChanged(var Message: TMessage);
begin
  inherited;
  if ActionClient <> nil then
    CalcBounds;
end;

procedure TCustomActionControl.Click;
begin
  if Assigned(ActionClient) and Assigned(ActionClient.ActionLink) then
  begin
    if not ActionBar.DesignMode then
      ResetUsageData;
    if not ActionBar.DesignMode then
      ActionClient.ActionLink.Execute(Self);
  end;
end;

function TCustomActionControl.DesignWndProc(var Message: TMessage): Boolean;
begin
  Result := False;
  case Message.Msg of
    WM_CONTEXTMENU,
    WM_RBUTTONDOWN,
    WM_RBUTTONUP:
      if Assigned(ActionClient) and Assigned(ActionClient.FContextItems) then
        Result := True;
    CM_DRAG,
    WM_LBUTTONUP,
    WM_LBUTTONDOWN,
    WM_MOUSEMOVE:
      begin
        Dispatch(Message);
        Result := True;
      end;
    WM_LBUTTONDBLCLK:
      begin
        if Assigned(ActionClient) and Assigned(ActionClient.Action) then
          ActionBarDesigner.EditAction(ActionClient.Action);
        Result := True;
      end;
  end;
end;

procedure TCustomActionControl.DrawBackground(var PaintRect: TRect);
const
  BrushStyle: array[Boolean] of TBrushStyle = (bsSolid, bsClear);
begin
  if csDesigning in ComponentState then
    Canvas.Brush.Style := BrushStyle[FTransparent]
  else
    Canvas.Brush.Style := BrushStyle[FTransparent and not FSelected];
  if Assigned(ActionClient) and Assigned(ActionClient.ParentItem) and
     not ActionClient.ParentItem.HasBackground then
    Canvas.FillRect(PaintRect);
end;

procedure TCustomActionControl.DrawGlyph(const Location: TPoint);
const
  DrawDisabledState: array[Boolean] of Cardinal = (DSS_DISABLED, 0);
var
  ActionList: TCustomActionList;
  FgBmp, BgBmp: TBitmap;
begin
  if not HasGlyph then exit;
  ActionList := TAction(Action).ActionList;
  with ActionList.Images, Location do
    if Enabled or (csDesigning in ComponentState) then
    begin
      if ActionBar.Items.SmallIcons then
        ImageList_DrawEx(Handle, ActionClient.ImageIndex, Canvas.Handle,
          X, Y, 0, 0, clNone, clNone, ILD_TRANSPARENT)
      else
      begin
        BgBmp := TBitmap.Create;
        try
          FgBmp := TBitmap.Create;
          try
            BgBmp.Width := 16;
            BgBmp.Height := 16;
            BgBmp.Canvas.Brush.Color := clWhite;
            BgBmp.Canvas.FillRect(FgBmp.Canvas.ClipRect);
            ImageList_DrawEx(Handle, ActionClient.ImageIndex, BgBmp.Canvas.Handle,
              0, 0, 0, 0, CLR_NONE, CLR_NONE, ILD_TRANSPARENT);
            FgBmp.Width := 32;
            FgBmp.Height := 32;
            FgBmp.Canvas.StretchDraw(Rect(0, 0, 32, 32), BgBmp);
            FgBmp.TransparentColor := clWhite;
            FgBmp.Transparent := True;
            BgBmp.Width := 32;
            BgBmp.Height := 32;
            if IsChecked and (Parent.ControlAtPos(Parent.ScreenToClient(
               Mouse.CursorPos), False) <> Self) then
              BgBmp.Canvas.Brush.Bitmap := AllocPatternBitmap(Color,
                GetHighLightColor(Color))
            else
              BgBmp.Canvas.Brush.Color := Color;
            BgBmp.Canvas.FillRect(BgBmp.Canvas.ClipRect);
            BgBmp.Canvas.Draw(0, 0, FgBmp);
            Canvas.StretchDraw(Rect(X, Y, X + 32, Y + 32), BgBmp);
          finally
            FgBmp.Free;
          end;
        finally
          BgBmp.Free;
        end;
      end;
    end
    else
    begin
      FgBmp := TBitmap.Create;
      try
        if GetBitmap(ActionClient.ImageIndex, FgBmp) then
        begin
          if not ActionBar.Items.SmallIcons then
          begin
            FgBmp.Width := 32;
            FgBmp.Height := 32;
            FgBmp.Canvas.StretchDraw(Rect(0, 0, X + 64, Y + 64), FgBmp);
          end;
          DrawState(Canvas.Handle, Canvas.Brush.Handle, nil, FgBmp.Handle, 0,
            Location.X, Location.Y, 0, 0, DST_BITMAP or DrawDisabledState[Enabled])
        end;
      finally
        FgBmp.Free;
      end;
    end;
end;

procedure TCustomActionControl.DrawSeparator(const Offset: Integer);
var
  StartPos: TPoint;
  EndPos: TPoint;
begin
  if ActionBar = nil then exit;
  if ActionBar.Orientation in [boLeftToRight, boRightToLeft] then
  begin     // Vertical bar
    StartPos := Point(ClientWidth div 2, Offset - 1);
    EndPos := Point(ClientWidth div 2, ClientHeight - Offset + 1);
  end
  else
  begin     // Horizontal bar
    StartPos := Point(Offset, ClientHeight div 2);
    EndPos := Point(Width - Offset, ClientHeight div 2);
  end;
  with Canvas do
  begin
    Pen.Width := 1;
    if FSelected and (csDesigning in ComponentState) then
      FillRect(ClientRect);
    if Assigned(ActionClient) and ActionClient.Unused then
      Pen.Color := GetShadowColor(GetHighLightColor(Color))
    else
      if Color = clBtnFace then
        Pen.Color := clBtnShadow
      else
        Pen.Color := GetShadowColor(Color);
    MoveTo(StartPos.X, StartPos.Y);
    LineTo(EndPos.X, EndPos.Y);
    if Assigned(ActionClient) and ActionClient.Unused then
    begin
      if Color = clBtnFace then
        Pen.Color := clBtnHighLight
      else
        Pen.Color := GetHighLightColor(GetHighLightColor(Color))
    end
    else
      if Color = clBtnFace then
        Pen.Color := clBtnHighLight
      else
        Pen.Color := GetHighLightColor(Color);
    if StartPos.X = EndPos.X then
    begin
      MoveTo(StartPos.X + 1, StartPos.Y);
      LineTo(StartPos.X + 1, EndPos.Y);
    end
    else
    begin
      MoveTo(StartPos.X, StartPos.Y + 1);
      LineTo(EndPos.X, EndPos.Y + 1);
    end;
  end;
end;

procedure TCustomActionControl.DrawText(var ARect: TRect; var Flags: Cardinal;
  Text: string);
begin
  Canvas.Brush.Style := bsClear;
  Windows.DrawText(Canvas.Handle, PChar(Text), Length(Text), ARect, Flags)
end;

function TCustomActionControl.IsGrouped: Boolean;
begin
  Result := (Action is TCustomAction) and (TCustomAction(Action).GroupIndex > 0);
end;

procedure TCustomActionControl.Paint;
var
  PaintRect: TRect;
  TextRect: TRect;
  Offset: TPoint;
  Flags: Cardinal;
begin
  PaintRect := ClientRect;
  Offset := Point(0,0);

  Canvas.Brush.Color := Color;

  DrawBackground(PaintRect);
  if Separator then
    DrawSeparator(2)
  else
  begin
    DrawGlyph(FGlyphPos);
    if ShowCaption or not HasGlyph then
    begin
      Flags := DrawTextBiDiModeFlags(DT_LEFT) or DT_NOCLIP;
      TextRect := FTextBounds;
      if Assigned(ActionClient) then
        DrawText(TextRect, Flags, ActionClient.Caption)
      else
        DrawText(TextRect, Flags, Caption);
    end;
  end;

  if FSelected and Assigned(ActionBar) and ActionBar.DesignMode then
    DrawDesignFocus(PaintRect);
end;

procedure TCustomActionControl.PositionChanged;
begin
  RequestAlign;
end;

procedure TCustomActionControl.SetTransparent(const Value: Boolean);
begin
  if Value <> FTransparent then
  begin
    FTransparent := Value;
    if Value then
      ControlStyle := ControlStyle - [csOpaque]
    else
      ControlStyle := ControlStyle + [csOpaque];
    Invalidate;
  end;
end;

function TCustomActionControl.GetImageSize: TPoint;
var
  ActionList: TCustomActionList;
begin
  Result := Point(0,0);
  if not HasGlyph or not ActionClient.ShowGlyph then Exit;
  if not ActionClient.ActionClients.SmallIcons then
    Result := Point(32, 32)
  else
  begin
    ActionList := nil;
    if Action is TContainedAction then
      ActionList := TContainedAction(Action).ActionList;
    if Assigned(ActionList) and Assigned(ActionList.Images) then
      with ActionList.Images do
        Result := Point(Width, Height);
  end;
end;

procedure TCustomActionControl.SetActionClient(Value: TActionClientItem);
begin
  if FActionClient <> Value then
  begin
    if Assigned(FActionClient) then
      FActionClient.ActionBar := nil;
    FActionClient := Value;
    if Assigned(Action) then
      ControlStyle := ControlStyle + [csActionClient];
    if Value = nil then exit;
    case FActionClient.Color of
      clNone:
        begin
          FTransparent := True;
          ParentColor := True;
        end;
      clDefault:
        ParentColor := True;
      else
        Color := FActionClient.Color;
    end;
    Visible := Value.Visible;
    Caption := FActionClient.Caption
  end;
end;

procedure TCustomActionControl.SetSelected(Value: Boolean);
begin
  if (Value <> FSelected) then
  begin
    FSelected := Value;
    if Value then
      UpdateSelection;
    Invalidate;
  end;
end;

procedure TCustomActionControl.UpdateSelection;
var
  Msg: TMessage;
begin
  // MenuItems can be selected but they don't have to be enabled
  if Parent <> nil then
  begin
    Msg.Msg := CM_ITEMSELECTED;
    Msg.WParam := 0;
    Msg.LParam := Longint(Self);
    Msg.Result := 0;
    Parent.Broadcast(Msg);
  end;
end;

procedure TCustomActionControl.CMItemSelected(var Message: TCMItemMsg);
begin
  if Message.Sender <> Self then
    if Message.Sender.Selected and FSelected then
      Selected := False;
  if (csDesigning in ComponentState) and Selected and
     Assigned(ActionBarDesigner) then
    ActionBarDesigner.SetSelection(FActionClient);
end;

procedure TCustomActionControl.SetMargins(Value: TRect);
begin
  if (Value.Left <> FMargins.Left) or (Value.Top <> FMargins.Bottom) or
     (Value.Right <> FMargins.Right) or (Value.Bottom <> FMargins.Bottom) then
  begin
    FMargins := Value;
    CalcBounds;
  end;
end;

procedure TCustomActionControl.SetSpacing(const Value: Integer);
begin
  if Value <> FSpacing then
  begin
    FSpacing := Value;
    if Assigned(ActionBar) and ActionBar.AlignDisabled then
      CalcBounds;
  end;
end;

procedure TCustomActionControl.SetGlyphLayout(const Value: TButtonLayout);
var
  PaintRect: TRect;
  Offset: TPoint;
begin
  if FGlyphLayout <> Value then
  begin
    PaintRect := Rect(0, 0, Width, Height);
    Offset.X := 0;
    Offset.Y := 0;
    FGlyphLayout := Value;
    { Recalculate the Width/Height of the control }
    CalcBounds;
    RequestAlign;
    Invalidate;
  end;
end;

procedure TCustomActionControl.Keyed;
begin
  ResetUsageData;
  if Assigned(Parent) then
    PostMessage(Parent.Handle, CM_ITEMKEYED, 0, LongInt(Self));
end;

procedure TCustomActionControl.CMDesignHitTest(var Message: TCMDesignHitTest);
begin
  Message.Result := 1;
end;

procedure TCustomActionControl.DrawDesignFocus(var PaintRect: TRect);
var
  OldBrushStyle: TBrushStyle;
  OldPenWidth: Integer;
begin
  OldBrushStyle := Canvas.Brush.Style;
  Canvas.Brush.Style := bsClear;
  OldPenWidth := Canvas.Pen.Width;  
  Canvas.Pen.Width := 2;
  Canvas.Rectangle(PaintRect);
  Canvas.Brush.Style := OldBrushStyle;
  Canvas.Pen.Width := OldPenWidth;
end;

procedure TCustomActionControl.ResetUsageData;
begin
  if (csDesigning in ComponentState) or Assigned(ActionBar) and
     ActionBar.DesignMode then
    exit;
  if Assigned(ActionClient) and not ActionClient.HasItems then
    if Enabled and Assigned(FActionClient) then
      FActionClient.ResetUsageData;
end;

procedure TCustomActionControl.DragDrop(Source: TObject; X, Y: Integer);
begin
  inherited DragDrop(Source, X, Y);
  DoDragDrop(Source, X, Y);
end;

procedure TCustomActionControl.DragOver(Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  inherited DragOver(Source, X, Y, State, Accept);
  Accept := Assigned(FActionClient) and ((Source is TActionDragObject) or
    (Source is TActionItemDragObject) or (Source is TCategoryDragObject));
  if Accept and (Source is TActionItemDragObject) then
    with Source as TActionItemDragObject do
      if ClientItem <> Self.ActionClient then
        Accept := not ActionClient.IsChildItem(ClientItem);
  if Accept and (State in [dsDragEnter, dsDragLeave]) then
    DrawDragDropPoint;
end;

procedure TCustomActionControl.DrawDragDropPoint;
begin
  if Selected or (ActionBar = nil) then exit;
  Canvas.Brush.Style := bsSolid;
  case ActionBar.Orientation of
    boLeftToRight, boRightToLeft:
      begin
        PatBlt(Canvas.Handle, 0, 0, 6, 2, PATINVERT);
        PatBlt(Canvas.Handle, 2, 2, 2, ClientHeight - 4, PATINVERT);
        PatBlt(Canvas.Handle, 0, ClientHeight - 2, 6, ClientHeight, PATINVERT);
      end;
    boTopToBottom, boBottomToTop:
      begin
        PatBlt(Canvas.Handle, 0, 0, 2, 6, PATINVERT);
        PatBlt(Canvas.Handle, 2, 2, ClientWidth - 6, 2, PATINVERT);
        PatBlt(Canvas.Handle, ClientWidth - 4, 0, 2, 6, PATINVERT);
      end;
  end;
end;

procedure TCustomActionControl.DoStartDrag(var DragObject: TDragObject);
begin
  DragObject := TActionItemDragObject.Create;
  TActionItemDragObject(DragObject).FClientItem := ActionClient;
  inherited DoStartDrag(DragObject);
end;

function TCustomActionControl.HasGlyph: Boolean;
begin
  Result := False;
  if Assigned(FActionClient) then
    Result := FActionClient.HasGlyph;
end;

procedure TCustomActionControl.WMSetText(var Message: TWMSetText);
begin
  inherited;
  if Assigned(FActionBar) then
    FActionBar.Resize;
end;

function TCustomActionControl.GetSeparator: Boolean;
begin
  Result := False;
  if Assigned(ActionClient) then
    Result := ActionClient.Separator;
end;

function TCustomActionControl.GetShowCaption: Boolean;
begin
  Result := True;
  if Assigned(FActionClient) then
    case FActionClient.ActionClients.CaptionOptions of
      coNone: Result := False;
      coSelective: Result := FActionClient.ShowCaption;
      coAll: Result := True;
    end;
end;

function TCustomActionControl.GetShowShortCut: Boolean;
begin
  Result := False;
  if Assigned(FActionClient) then
    Result := FActionClient.ShowShortCut and (FActionClient.ShortCut <> 0);
end;

function TCustomActionControl.IsChecked: Boolean;
begin
  Result := False;
  if Assigned(ActionClient) and (ActionClient.Action is TCustomAction) then
    Result := TCustomAction(ActionClient.Action).Checked;
end;

function TCustomActionControl.GetAction: TBasicAction;
begin
  if Assigned(FActionClient) then
    Result := FActionClient.Action
  else
    Result := nil;
end;

procedure TCustomActionControl.InitiateAction;
begin
  if Assigned(FActionClient) then
    FActionClient.InitiateAction;
end;

function TCustomActionControl.GetActionBar: TCustomActionBar;
begin
  Result := Parent as TCustomActionBar;
end;

procedure TCustomActionControl.CMTextChanged(var Message: TMessage);
begin
  inherited;
  if Assigned(ActionBar) then
    CalcBounds;
end;

procedure TCustomActionControl.UpdateTextBounds;
begin
  FTextBounds := Rect(0,0,0,0);
  if Assigned(ActionClient) then
    Windows.DrawText(Canvas.Handle, PChar(ActionClient.Caption), -1, FTextBounds,
      DT_CALCRECT)
  else
    Windows.DrawText(Canvas.Handle, PChar(Caption), -1, FTextBounds, DT_CALCRECT)
end;

procedure TCustomActionControl.CalcBounds;
var
  AWidth: Integer;
  AHeight: Integer;
  ImageSize: TPoint;
begin
  if ActionClient = nil then exit;
  ImageSize := GetImageSize;
  Canvas.Font.Assign(Font);
  UpdateTextBounds;
  AWidth := Width;
  AHeight := Height;
  case GlyphLayout of
    blGlyphRight,
    blGlyphLeft:
      begin
        AWidth := Margins.Left + ImageSize.X + ActualSpacing(ImageSize) + CaptionLength +
          Margins.Right;
        AHeight := Margins.Top + Max(ImageSize.Y, CaptionHeight) +
          Margins.Bottom;
      end;
    blGlyphTop,
    blGlyphBottom:
      begin
        AWidth := Margins.Left + ImageSize.X + CaptionLength + Margins.Right;
        AHeight := Margins.Top + ImageSize.Y + ActualSpacing(ImageSize) + CaptionHeight +
          Margins.Bottom;
      end;
  end;
  if (AWidth <> Width) or (AHeight <> Height) then
  begin
    SetBounds(Left, Top, AWidth, AHeight);
    CalcLayout;
    RequestAlign;
  end;
end;

procedure TCustomActionControl.DoDragDrop(DragObject: TObject;
  X, Y: Integer);
var
  Idx: Integer;
  I: Integer;
  NewItem: TActionClientItem;
begin
  if Assigned(ActionClient) then
    Idx := ActionClient.Index
  else
    Idx := 0;

  if DragObject is TActionDragObject then
  begin
    ActionBar.DisableAlign;
    ActionBar.Items.BeginUpdate;
    try
      with DragObject as TActionDragObject do
        for I := 0 to ActionCount - 1 do
        begin
          NewItem := TActionClientItem(ActionBar.Items.Insert(Idx));
          NewItem.LastSession := ActionBar.ActionManager.ActionBars.SessionCount;
          NewItem.Action := Actions[I];
          NewItem.Index := Idx;
        end;
    finally
      ActionBar.Items.EndUpdate;
      ActionBar.EnableAlign;
    end;
  end
  else if DragObject is TActionItemDragObject then
    with DragObject as TActionItemDragObject do
    begin
      if ClientItem.Collection <> Self.ActionClient.ActionClients then
      begin
        ClientItem.Collection := Self.ActionClient.ActionClients;
        ClientItem.Index := idx;
        ClientItem.LastSession := ActionBar.ActionManager.ActionBars.SessionCount;
      end
      else
      begin
        ClientItem.Index := idx;
        if Assigned(ActionBarDesigner) then
          ActionBarDesigner.SetSelection(ClientItem);
      end;
    end;
  NotifyDesigner(ActionBar);
end;

procedure TCustomActionControl.SetSmallIcon(const Value: Boolean);
begin
  if FSmallIcon <> Value then
  begin
    FSmallIcon := Value;
    CalcBounds;
    RequestAlign;
  end;
end;

procedure TCustomActionControl.WMContextMenu(var Message: TWMContextMenu);
var
  PopupMenu: TCustomActionPopupMenu;
begin
  inherited;
  if Assigned(ActionClient) and (ActionClient.ContextItems.Count > 0) then
  begin
    PopupMenu := MenuPopupClass.Create(Owner);
    PopupMenu.ContextBar := True;
    PopupMenu.Parent := Parent;
    PopupMenu.ActionClient := ActionClient;
    PopupMenu.Popup(Message.XPos, Message.YPos);
    PopupMenu.Free;
  end;
end;

end.
