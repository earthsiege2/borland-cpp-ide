unit TreeIntf;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ExtCtrls, ComCtrls, DesignIntf, DesignEditors, DesignMenus, TypInfo, Contnrs,
  IniFiles, Menus, ImgList;

type

{ TSprig }

{ sprig \Sprig\, n.
  [AS. sprec; akin to Icel. sprek a stick. Cf. Spray a branch.]
  1. A small shoot or twig of a tree or other plant; a spray; as, a sprig of
     laurel or of parsley.
  2. A youth; a lad; -- used humorously or in slight disparagement.
     A sprig whom I remember, with a whey-face and a satchel, not so many
     years ago. --Sir W. Scott.
  3. A brad, or nail without a head.
  4. (Naut.) A small eyebolt ragged or barbed at the point.
  5. A leaf in Delphi's object treeview
  Source: Webster's Revised Unabridged Dictionary, well sort of anyway }

  TSprig = class;
  TSprigClass = class of TSprig;
  TSprigAction = procedure(AItem: TSprig) of object;
  TSprigIndex = class;
  TRootSprig = class;
  TRootSprigClass = class of TRootSprig;
  TSprigTreeNode = class;
  ISprigDesigner = interface;

  ISprigCollection = interface
    ['{0B6ABAEE-E1A4-4DAC-8E20-C6B741A5082D}']
    function RootSprigAssigned: Boolean;
    function RootSprig: TRootSprig;
    function GetSprigDesigner: ISprigDesigner;
    procedure SetSprigDesigner(const ASprigDesigner: ISprigDesigner);
    property SprigDesigner: ISprigDesigner read GetSprigDesigner write SetSprigDesigner;
  end;

  ISprigDesigner = interface
    ['{6AC141E3-2FBE-425E-B299-AB29E7DF3FBB}']
    function GetTreeView: TCustomTreeView;
    procedure BeforeItemsModified;
    procedure AfterItemsModified;
    function GetRootSprig: TRootSprig;
    procedure SetRootSprig(ARootSprig: TRootSprig);
    property RootSprig: TRootSprig read GetRootSprig write SetRootSprig;
  end;

  TInformant = class(TObject)
  private
    FNotifyList: TList;
    FDisableNotify: Integer;
    FNotifyNeeded: Boolean;
    FDestroying: Boolean;
  protected
    procedure Changed(AObj: TInformant); virtual;
  public
    procedure BeforeDestruction; override;
    destructor Destroy; override;
    property Destroying: Boolean read FDestroying;

    procedure DisableNotify;
    procedure EnableNotify;
    procedure Notification;
    procedure Notify(AObj: TInformant);
    procedure Unnotify(AObj: TInformant);
  end;

  TSprigDeleteStyle = (dsNormal, dsIgnore, dsAbort, dsCustom);

  TSprig = class(TInformant)
  private
    FRoot: TRootSprig;
    FParent: TSprig;
    FList: TObjectList;
    FItem: TPersistent;
    FTreeNode: TTreeNode;
    FImageIndex: TImageIndex;
    FCaption: string;
    FExpanded, FInvalid, FCollectionsDone, FHidden, FHiddenTested: Boolean;
    procedure SetExpanded(const Value: Boolean);
  protected
    function GetItem(Index: Integer): TSprig;
    function UniqueName: string; virtual;
    function CaptionFor(const AName: string; const ALabel: string = '';
      const AClass: string = ''): string;
    procedure ReparentChildren;
    procedure SelectItems(const AItems: array of TPersistent; ARuntimeChange: Boolean = True); virtual;
    procedure RuntimeChange; virtual;
    procedure DesigntimeChange; virtual;
    function FindItem(AItem: TPersistent; Recurse: Boolean): TSprig; virtual;
    function FindItemByName(const AName: string; AClass: TClass; Recurse: Boolean): TSprig; virtual;
    function FindItemByPath(const APath: string; Recurse: Boolean = True): TSprig; virtual;
    function GetDesigner(out ADesigner: IDesigner): Boolean; virtual;
    function GetImageIndex: TImageIndex; virtual;
    procedure SetImageIndex(const Value: TImageIndex); virtual;
    function GetStateIndex: TImageIndex; virtual;
    procedure BeginUpdate; virtual;
    procedure EnsureUpdate; virtual;
    procedure EndUpdate; virtual;
    function GetAddType(Index: Integer): string; virtual;
  public
    constructor Create(AItem: TPersistent); overload; virtual;
    destructor Destroy; override;
    procedure Invalidate;

    function Transient: Boolean; virtual;
    function AnyProblems: Boolean; virtual;
    property Invalid: Boolean read FInvalid;

    property Item: TPersistent read FItem;
    function Hidden: Boolean; virtual;
    function Ghosted: Boolean; virtual;
    function FocusItem: TPersistent; virtual;
    function ItemClass: TClass; virtual;
    function Owner: TSprig; virtual;

    procedure VisualRefresh; virtual;
    function TreeNodeFor(ATreeView: TCustomTreeView): TTreeNode; virtual;
    property TreeNode: TTreeNode read FTreeNode;
    property Expanded: Boolean read FExpanded write SetExpanded;
    property ImageIndex: TImageIndex read GetImageIndex write SetImageIndex;
    property StateIndex: TImageIndex read GetStateIndex;
    procedure ClearTreeNode; overload;
    procedure ClearTreeNode(ARecurse: Boolean; AFreeNode: Boolean = True); overload;

    function Name: string; virtual;
    function Caption: string; virtual;
    function Hint: string; virtual;

    procedure PrepareMenu(const AItems: IMenuItems); virtual;
    function ShowRegisteredMenus: Boolean; virtual;

    function DragClass: TClass;
    function DragOver(AItem: TSprig): Boolean; virtual;
    function DragOverTo(AParent: TSprig): Boolean; virtual;
    function DragDrop(AItem: TSprig): Boolean; virtual;
    function DragDropTo(AParent: TSprig): Boolean; virtual;
    function PaletteOver(ASprigClass: TSprigClass; AClass: TClass): Boolean; virtual;
    class function PaletteOverTo(AParent: TSprig; AClass: TClass): Boolean; virtual;

    function Add(AItem: TSprig): TSprig;
    function Find(AItem: TPersistent; Recurse: Boolean = True): TSprig; overload;
    function Find(const AName: string; Recurse: Boolean = True): TSprig; overload;
    function Find(const AName: string; AClass: TClass; Recurse: Boolean = True): TSprig; overload;
    function FindPath(const APath: string; Recurse: Boolean = True): TSprig;
    function IndexOf(AItem: TSprig): Integer;
    procedure ForEach(ABefore: TSprigAction; AAfter: TSprigAction = nil);
    procedure ClearUnneededSprigs;

    function DeleteStyle: TSprigDeleteStyle; virtual;
    function CustomDelete: Boolean; virtual;

    function CanMove(AUp: Boolean): Boolean; virtual;
    function Move(AUp: Boolean): Boolean; virtual;
    function CanAdd: Boolean; virtual;
    function AddTypeCount: Integer; virtual;
    property AddTypes[Index: Integer]: string read GetAddType;
    procedure AddType(Index: Integer); virtual;

    procedure SortItems; virtual;
    function SortByIndex: Boolean; virtual;
    function IncludeIndexInCaption: Boolean; virtual;
    function ItemIndex: Integer; virtual;
    function CopyGlyph(ABitmap: TBitmap): Boolean; virtual;

    property Root: TRootSprig read FRoot;
    property Parent: TSprig read FParent;
    function Parents(ASprig: TSprig): Boolean;
    function Path: string;
    property Items[Index: Integer]: TSprig read GetItem; default;
    function Count: Integer;
    function Index: Integer;
    procedure Reparent; virtual;
    function Construct(AClass: TComponentClass): TComponent; virtual;

    function SeekParent(AItem: TPersistent; Recurse: Boolean = True): TSprig; overload;
    function SeekParent(const AName: string; Recurse: Boolean = True): TSprig; overload;
    function SeekParent(const AName: string; AClass: TClass; Recurse: Boolean = True): TSprig; overload;
    class function ParentProperty: string; virtual;
    procedure FigureParent; virtual;
    procedure FigureChildren; virtual;
  end;

  // a sprig that represents something that doesn't actually exist
  TAbstractSprig = class(TSprig)
  public
    function Ghosted: Boolean; override;
  end;

  // an abstract sprig that only exists if it has children
  TTransientSprig = class(TAbstractSprig)
  public
    function Transient: Boolean; override;
  end;

  // collection variants of the above
  TAbstractCollectionSprig = class(TAbstractSprig)
  public
    constructor Create(AItem: TPersistent); override;
  end;
  TTransientCollectionSprig = class(TTransientSprig)
  public
    constructor Create(AItem: TPersistent); override;
  end;

  // a sprig that points to a persistent
  TPersistentSprig = class(TSprig)
  end;

  // a sprig that points to a component
  TComponentSprig = class(TPersistentSprig)
  private
    FOwner: TSprig;
  public
    constructor Create(AItem: TPersistent); override;
    constructor Create(AItem: TPersistent; AOwner: TSprig); overload;
    function UniqueName: string; override;
    function Owner: TSprig; override;
    //function ShowRegisteredMenus: Boolean; override;
    // TSprig's implimentation of FigureParent is TComponent aware
  end;
  TComponentSprigClass = class of TComponentSprig;

  TRootSprig = class(TPersistentSprig)
  private
    FIndex: TSprigIndex;
    FNamedItems,
    FPathedItems: TList;
    FRepopulating,
    FParentChanges: Boolean;
    FSprigDesigner: ISprigDesigner;
    FDesigner: IDesigner;
    FRepopulateNeeded: Boolean;
    FNeedUpdate: Boolean;
    FUpdateLocks: Integer;
    procedure ValidateParent(AItem: TSprig);
    procedure PreRefreshTreeView(AItem: TSprig);
    procedure PostRefreshTreeView(AItem: TSprig);
    procedure DepopulateTreeView(AItem: TSprig);
    procedure RestoreExpandState(AItem: TSprig);
    procedure StoreExpandState(AItem: TSprig);
    procedure SetSprigDesigner(const ASprigDesigner: ISprigDesigner);
    procedure SelectionSurvey(out ADeleteStyle: TSprigDeleteStyle; out AAllVisible: Boolean);
  protected
    function FindItem(AItem: TPersistent; Recurse: Boolean = True): TSprig; override;
    function FindItemByName(const AName: string; AClass: TClass; Recurse: Boolean): TSprig; override;
    function FindItemByPath(const APath: string; Recurse: Boolean = True): TSprig; override;
    procedure AddItem(ASprig: TSprig);
    procedure RemoveItem(ASprig: TSprig);
    function GetDesigner(out ADesigner: IDesigner): Boolean; override;
    function GetAddType(Index: Integer): String; override;
    function SelectedSprig(var ASprig: TSprig): Boolean;
  public
    constructor Create(AItem: TPersistent); override;
    destructor Destroy; override;
    procedure FigureParent; override;

    property SprigDesigner: ISprigDesigner read FSprigDesigner write SetSprigDesigner;
    property Designer: IDesigner read FDesigner write FDesigner;

    property Repopulating: Boolean read FRepopulating;
    function Repopulate: Boolean;
    function TreeView: TCustomTreeView;
    procedure RefreshTreeView;
    procedure StoreTreeState;
    procedure BeginUpdate; override;
    procedure EnsureUpdate; override;
    procedure EndUpdate; override;

    procedure ItemDeleted(AItem: TPersistent);
    procedure ItemInserted;
    procedure ItemsModified(AForceRepopulate: Boolean = True);

    procedure RuntimeChange; override;
    procedure DesigntimeChange; override;
    procedure SelectItems(const AItems: array of TPersistent; ARuntimeChange: Boolean = True); override;

    // these are not used to operate on the root but its children
    function CanMove(AUp: Boolean): Boolean; override;
    function Move(AUp: Boolean): Boolean; override;
    function CanAdd: Boolean; override;
    procedure AddType(Index: Integer); override;
    function AddTypeCount: Integer; override;

    function EditAction(Action: TEditAction): Boolean;
    function GetEditState: TEditState;

    function DeleteStyle: TSprigDeleteStyle; override;

    function PaletteOver(ASprigClass: TSprigClass; AClass: TClass): Boolean; override;
    function AcceptsClass(AClass: TClass): Boolean; virtual;

    property RepopulateNeeded: Boolean read FRepopulateNeeded write FRepopulateNeeded;
  end;

  TSprigTreeNode = class(TTreeNode)
  public
    destructor Destroy; override;
  end;

  TSprigIndex = class(TObject)
  private
    FList: TObjectList;
  public
    constructor Create;
    destructor Destroy; override;

    procedure Add(ASprig: TSprig);
    procedure Remove(ASprig: TSprig);
    function Find(AItem: TPersistent): TSprig;
  end;

  TPropertySprig = class(TPersistentSprig)
  public
    function Ghosted: Boolean; override;
    function DeleteStyle: TSprigDeleteStyle; override;
  end;

  TCollectionSprig = class(TPropertySprig)
  private
    FPropName: string;
    FOwner: TSprig;
  protected
    function GetAddType(Index: Integer): string; override;
  public
    constructor Create(AItem: TPersistent); override;
    function Name: string; override;
    function Caption: string; override;
    procedure FigureParent; override;
    procedure FigureChildren; override;
    function Owner: TSprig; override;

    function SortByIndex: Boolean; override;
    procedure AddType(Index: Integer); override;
    function AddTypeCount: Integer; override;

    function DeleteStyle: TSprigDeleteStyle; override;
    function CustomDelete: Boolean; override;
  end;

  TCollectionItemSprig = class(TPersistentSprig)
  private
    FOwner: TSprig;
  protected
    function GetAddType(Index: Integer): string; override;
  public
    function Name: string; override;
    procedure FigureParent; override;
    function Owner: TSprig; override;
    function Ghosted: Boolean; override;
    function ItemIndex: Integer; override;
    function IncludeIndexInCaption: Boolean; override;
    function DragOverTo(AParent: TSprig): Boolean; override;
    function DragDropTo(AParent: TSprig): Boolean; override;
    procedure AddType(Index: Integer); override;
    function AddTypeCount: Integer; override;
  end;

  TSprigType = class(TObject)
  private
    FGroup: Integer;
    FClass: TClass;
    FSprigClass: TSprigClass;
  public
    constructor Create(const AClass: TClass; const ASprigClass: TSprigClass);
    function Score(const AClass: TClass): Integer;
    property SprigClass: TSprigClass read FSprigClass;
  end;

  TGUIDArray = array of TGUID;

  TSprigIntfType = class(TObject)
  private
    FGroup: Integer;
    FInterfaces: TGUIDArray;
    FSprigClass: TSprigClass;
  public
    constructor Create(const AInterfaces: TGUIDArray; const ASprigClass: TSprigClass);
    function Match(const AClass: TClass): Boolean;
    property SprigClass: TSprigClass read FSprigClass;
  end;

  TSprigTypeList = class(TObject)
  private
    FList: TObjectList;
    FLastClass: TClass;
    FLastSprigClass: TSprigClass;

    FInterfaceList: TObjectList;
  protected
    procedure ClearCache;
    function MatchCache(const AClass: TClass): TSprigClass;
    function MatchClass(const AClass: TClass): TSprigClass;
  public
    constructor Create;
    destructor Destroy; override;
    function Match(const AClass: TClass): TSprigClass;
    procedure Add(const AClass: TClass; const ASprigClass: TSprigClass); overload;
    procedure Add(const AInterfaces: TGUIDArray; const ASprigClass: TSprigClass); overload;
    procedure FreeEditorGroup(AGroup: Integer);
  end;

  TDragSprigs = class(TDragControlObjectEx)
  private
    FSprigs: TList;
    function GetSprig(Index: Integer): TSprig;
  public
    constructor Create(AControl: TControl); override;
    destructor Destroy; override;
    procedure Add(ASprig: TSprig);
    function Count: Integer;
    property Sprigs[Index: Integer]: TSprig read GetSprig;
  end;

procedure RegisterSprigType(const AClass: TClass; ASprigClass: TSprigClass); overload;
procedure RegisterSprigType(const AInterfaces: TGUIDArray; ASprigClass: TSprigClass); overload;

function FindBestSprigClass(AClass: TClass): TSprigClass; overload;
function FindBestSprigClass(AClass: TClass; AMinimumSprigClass: TSprigClass): TSprigClass; overload;

procedure RegisterRootSprigType(const AClass: TClass; ASprigClass: TRootSprigClass); overload;
procedure RegisterRootSprigType(const AInterfaces: TGUIDArray; ASprigClass: TRootSprigClass); overload;

function FindBestRootSprigClass(AClass: TClass): TRootSprigClass; overload;
function FindBestRootSprigClass(AClass: TClass; AMinimumSprigClass: TRootSprigClass): TRootSprigClass; overload;

var
  GShowClassNameInTreeView: Boolean = False;

const
  CFakeSprigImage = 0;
  CFakeCollectionSprigImage = 1;
  CPersistentSprigImage = 2;
  CCollectionSprigImage = 3;
  CComponentSprigImage = 4;
  CDataModuleSprigImage = 5;
  CControlSprigImage = 6;
  CUIControlSprigImage = 7;
  CUIContainerSprigImage = 8;
  CFormSprigImage = 9;
  CGhostedOffset = 10;

  CNoStateImage = 0;
  CCheckOutStateImage = 1;

  CCollectionName = '<Collection.%s>'; // DO NOT LOCALIZE

const
  CUIControlImageIndex: array [Boolean] of Integer = (CUIControlSprigImage,
                                                      CUIContainerSprigImage);

type
  TRootSprigList = class(TObject)
  private
    FList: TBucketList;
  public
    constructor Create;
    destructor Destroy; override;
    function FindRoot(const ADesigner: IDesigner; out ARootSprig: TRootSprig): Boolean;

    procedure DesignerClosed(const ADesigner: IDesigner; AGoingDormant: Boolean);
    procedure DesignerOpened(const ADesigner: IDesigner; AResurrecting: Boolean);
    procedure ItemDeleted(const ADesigner: IDesigner; AItem: TPersistent);
    procedure ItemInserted(const ADesigner: IDesigner; AItem: TPersistent);
    procedure ItemsModified(const ADesigner: IDesigner);
  end;

function RootSprigList: TRootSprigList;

type
  TCopySprigGlyphFunc = function(ASprig: TSprig; ABitmap: TBitmap): Boolean of object;

var
  CopySprigGlyphFunc: TCopySprigGlyphFunc;

implementation

uses
  DesignConst;

var
  InternalSprigTypeList: TSprigTypeList = nil;
  InternalRootSprigTypeList: TSprigTypeList = nil;

procedure RegisterSprigType(const AClass: TClass; ASprigClass: TSprigClass);
begin
  if InternalSprigTypeList = nil then
    InternalSprigTypeList := TSprigTypeList.Create;
  InternalSprigTypeList.Add(AClass, ASprigClass);
end;

procedure RegisterSprigType(const AInterfaces: TGUIDArray; ASprigClass: TSprigClass);
begin
  if InternalSprigTypeList = nil then
    InternalSprigTypeList := TSprigTypeList.Create;
  InternalSprigTypeList.Add(AInterfaces, ASprigClass);
end;


function FindBestSprigClass(AClass: TClass): TSprigClass;
begin
  Result := FindBestSprigClass(AClass, TSprig);
end;

function FindBestSprigClass(AClass: TClass;
  AMinimumSprigClass: TSprigClass): TSprigClass;
begin
  Result := nil;
  if InternalSprigTypeList <> nil then
  begin
    Result := InternalSprigTypeList.Match(AClass);
    if (Result <> nil) and not Result.InheritsFrom(AMinimumSprigClass) then
      Result := nil;
  end;
end;

procedure RegisterRootSprigType(const AClass: TClass; ASprigClass: TRootSprigClass);
begin
  if InternalRootSprigTypeList = nil then
    InternalRootSprigTypeList := TSprigTypeList.Create;
  InternalRootSprigTypeList.Add(AClass, ASprigClass);
end;

procedure RegisterRootSprigType(const AInterfaces: TGUIDArray; ASprigClass: TRootSprigClass);
begin
  if InternalRootSprigTypeList = nil then
    InternalRootSprigTypeList := TSprigTypeList.Create;
  InternalRootSprigTypeList.Add(AInterfaces, ASprigClass);
end;


function FindBestRootSprigClass(AClass: TClass): TRootSprigClass;
begin
  Result := FindBestRootSprigClass(AClass, TRootSprig);
end;

function FindBestRootSprigClass(AClass: TClass;
  AMinimumSprigClass: TRootSprigClass): TRootSprigClass;
begin
  Result := nil;
  if InternalRootSprigTypeList <> nil then
  begin
    Result := TRootSprigClass(InternalRootSprigTypeList.Match(AClass));
    if (Result <> nil) and not Result.InheritsFrom(AMinimumSprigClass) then
      Result := nil;
  end;
end;

procedure FlushSprigTypes(AGroup: Integer);
begin
  if InternalRootSprigTypeList <> nil then
    InternalRootSprigTypeList.FreeEditorGroup(AGroup);
  if InternalSprigTypeList <> nil then
    InternalSprigTypeList.FreeEditorGroup(AGroup);
end;

{ TInformant }

procedure TInformant.BeforeDestruction;
begin
  FDestroying := True;
  Notification;
  inherited;
end;

procedure TInformant.Changed(AObj: TInformant);
begin
  if AObj.Destroying then
    AObj.Unnotify(Self);
end;

destructor TInformant.Destroy;
begin
  FreeAndNil(FNotifyList);
  inherited;
end;

procedure TInformant.DisableNotify;
begin
  Inc(FDisableNotify);
end;

procedure TInformant.EnableNotify;
begin
  Dec(FDisableNotify);
  if (FDisableNotify = 0) and FNotifyNeeded then
    Notification;
end;

procedure TInformant.Notification;
var
  I: Integer;
begin
  if (FDisableNotify = 0) and (FNotifyList <> nil) then
  begin
    for I := FNotifyList.Count - 1 downto 0 do
      TInformant(FNotifyList[I]).Changed(Self);
    FNotifyNeeded := False;
  end
  else
    FNotifyNeeded := True;
end;

procedure TInformant.Notify(AObj: TInformant);
begin
  if FNotifyList = nil then
    FNotifyList := TList.Create;

  if FNotifyList.IndexOf(AObj) = -1 then
  begin
    FNotifyList.Add(AObj);
    AObj.Notify(Self);
  end;
end;

procedure TInformant.Unnotify(AObj: TInformant);
var
  I: Integer;
begin
  if FNotifyList <> nil then
  begin
    I := FNotifyList.IndexOf(AObj);
    if I <> -1 then
    begin
      FNotifyList.Delete(I);
      AObj.Unnotify(Self);
    end;
    if (FNotifyList <> nil) and
       (FNotifyList.Count = 0) then
      FreeAndNil(FNotifyList);
  end;
end;

{ TSprig }

function TSprig.Add(AItem: TSprig): TSprig;
begin
  // hey is it already in us?
  if (AItem.Parent <> Self) and
     (not AItem.Parents(Self)) then
  begin

    // remove the item from its old parent and clear any tree nodes it may have
    if (AItem.Parent <> nil) and
       (AItem.Parent.FList <> nil) then
    begin
      AItem.ClearTreeNode;
      AItem.Parent.FList.Extract(AItem);
    end;

    // make sure we have a list
    if not Assigned(FList) then
      FList := TObjectList.Create;

    // add it to our list
    FList.Add(AItem);

    // populate its parent
    AItem.FParent := Self;

    // populate the root?
    if AItem.Root = nil then
    begin
      AItem.FRoot := Root;

      // add it to the root's index?
      if Root <> nil then
        Root.AddItem(AItem);
    end;

    // we changed something!
    Root.FRepopulateNeeded := True;

    {AItem.FRoot := Root;
    if (AItem.Root = nil) and
       (Self is TRootSprig) then
      AItem.FRoot := TRootSprig(Self);

    // remove ourselve from the root index
    if AItem.FRoot <> nil then
      AItem.FRoot.FIndex.Add(Self);}
  end;

  // return it
  Result := AItem;
end;

function TSprig.AnyProblems: Boolean;
var
  LProp: PPropInfo;
begin
  Result := False;
  if ParentProperty <> '' then
  begin
    LProp := GetPropInfo(Item, ParentProperty, [tkClass]);
    Result := (LProp = nil) or
              (GetObjectProp(Item, LProp, TPersistent) = nil);
  end;
end;

function TSprig.Caption: string;
begin
  Result := CaptionFor(Name);
  if IncludeIndexInCaption then
    Result := Format('%d - %s', [ItemIndex, Result]); // DO NOT LOCALIZE
end;

procedure TSprig.ClearTreeNode(ARecurse, AFreeNode: Boolean);
var
  I: Integer;
  LNode: TTreeNode;
begin
  EnsureUpdate;

  // first do our children
  if ARecurse then
    for I := Count - 1 downto 0 do
      Items[I].ClearTreeNode(True);

  // now do ourself
  if TreeNode <> nil then
  begin
    LNode := TreeNode;
    FTreeNode := nil;
    LNode.Data := nil;
    if AFreeNode and not (csDestroying in LNode.TreeView.ComponentState) then
      LNode.Delete;
  end;
end;

procedure TSprig.ClearTreeNode;
begin
  ClearTreeNode(True, True);
end;

procedure TSprig.ClearUnneededSprigs;
var
  I: Integer;
begin
  for I := Count - 1 downto 0 do
    with Items[I] do
    begin
      ClearUnneededSprigs;
      if (Transient and (Count = 0)) or
         Invalid then
        Free;
    end;
end;

function TSprig.Count: Integer;
begin
  Result := 0;
  if Assigned(FList) then
    Result := FList.Count;
end;

constructor TSprig.Create(AItem: TPersistent);
const
  CImageIndex: array [Boolean] of TImageIndex = (CFakeSprigImage, CPersistentSprigImage);
begin
  inherited Create;
  FItem := AItem;
  FHiddenTested := Item = nil;
  FHidden := Item = nil;
  ImageIndex := CImageIndex[Item <> nil];
end;

destructor TSprig.Destroy;
begin
  // just in case it hasn't happen already
  Invalidate;

  // we know nothing!
  FItem := nil;

  // remove ourselves from the tree
  ClearTreeNode(False);

  // remove ourselves from the parent
  if (Parent <> nil) and (Parent.FList <> nil) then
    Parent.FList.Extract(Self);
  FParent := nil;

  // wipe out the lists
  if FList <> nil then
  begin
    while FList.Count > 0 do
      FList.Last.Free;
    FreeAndNil(FList);
  end;

  // remove ourselves
  inherited;
end;

function TSprig.DragClass: TClass;
begin
  if Item <> nil then
    Result := Item.ClassType
  else
    Result := ClassType;
end;

function TSprig.DragDrop(AItem: TSprig): Boolean;
begin
  Result := False;
  if Assigned(AItem) then
    Result := AItem.DragDropTo(Self);
end;

function TSprig.DragDropTo(AParent: TSprig): Boolean;
var
  LProp: PPropInfo;
begin
  Result := False;
  if (ParentProperty <> '') and
     (AParent <> Parent) then
  begin
    LProp := GetPropInfo(Item, ParentProperty, [tkClass]);
    if LProp <> nil then
    begin
      if AParent is TRootSprig then
        SetObjectProp(Item, LProp, nil)
      else
        SetObjectProp(Item, LProp, AParent.Item);
      Result := True;
    end;
  end;
end;

function TSprig.DragOver(AItem: TSprig): Boolean;
begin
  Result := False;
  if AItem <> nil then
    Result := AItem.DragOverTo(Self);
end;

function TSprig.DragOverTo(AParent: TSprig): Boolean;
var
  LProp: PPropInfo;
begin
  Result := False;
  if ParentProperty <> '' then
  begin
    LProp := GetPropInfo(Item, ParentProperty, [tkClass]);
    if LProp <> nil then
      Result := (AParent is TRootSprig) or
                (AParent.Item is GetTypeData(LProp^.PropType^)^.ClassType);
  end;
end;

function TSprig.Find(AItem: TPersistent; Recurse: Boolean): TSprig;
begin
  Result := FindItem(AItem, Recurse);
end;

function TSprig.FindItem(AItem: TPersistent; Recurse: Boolean): TSprig;
var
  I: Integer;
  LItem: TSprig;
begin
  Result := nil;
  if AItem <> nil then
    if AItem = Item then
      Result := Self
    else
      for I := 0 to Count - 1 do
      begin
        LItem := Items[I];
        if LItem.Item = AItem then
        begin
          Result := LItem;
          Break;
        end
        else if Recurse then
        begin
          Result := LItem.FindItem(AItem, True);
          if Result <> nil then
            Break;
        end;
      end;
end;

function TSprig.Find(const AName: string; Recurse: Boolean): TSprig;
begin
  Result := FindItemByName(AName, nil, Recurse);
end;

function TSprig.Find(const AName: string; AClass: TClass; Recurse: Boolean): TSprig;
begin
  Result := FindItemByName(AName, AClass, Recurse);
end;

function TSprig.FindItemByName(const AName: string; AClass: TClass; Recurse: Boolean): TSprig;
var
  I: Integer;
  LItem: TSprig;
begin
  Result := nil;
  if AName <> '' then

    // if class is nil then just check name
    if AClass = nil then
    begin
      if AnsiSameText(Name, AName) then
        Result := Self
      else
        for I := 0 to Count - 1 do
        begin
          LItem := Items[I];
          if AnsiSameText(LItem.Name, AName) then
          begin
            Result := LItem;
            Break;
          end
          else if Recurse then
          begin
            Result := LItem.FindItemByName(AName, nil, True);
            if Result <> nil then
              Break;
          end;
        end;
    end

    // use both name and class then
    else
    begin
      if (Item is AClass) and
         AnsiSameText(Name, AName) then
        Result := Self
      else
        for I := 0 to Count - 1 do
        begin
          LItem := Items[I];
          if (LItem.Item is AClass) and
             AnsiSameText(LItem.Name, AName) then
          begin
            Result := LItem;
            Break;
          end
          else if Recurse then
          begin
            Result := LItem.FindItemByName(AName, AClass, True);
            if Result <> nil then
              Break;
          end;
        end;
    end;

end;

function TSprig.FindPath(const APath: string; Recurse: Boolean): TSprig;
begin
  Result := FindItemByPath(APath, Recurse);
end;

function TSprig.FindItemByPath(const APath: string; Recurse: Boolean = True): TSprig;
var
  I: Integer;
  LItem: TSprig;
begin
  Result := nil;
  if APath <> '' then
    if AnsiSameText(Path, APath) then
      Result := Self
    else
      for I := 0 to Count - 1 do
      begin
        LItem := Items[I];
        if AnsiSameText(LItem.Path, APath) then
        begin
          Result := LItem;
          Break;
        end
        else if Recurse then
        begin
          Result := LItem.FindPath(APath, True);
          if Result <> nil then
            Break;
        end;
      end;
end;

procedure TSprig.ForEach(ABefore, AAfter: TSprigAction);
var
  I: Integer;
begin
  if not Invalid then
  begin
    if Assigned(ABefore) then
      ABefore(Self);
    for I := Count - 1 downto 0 do
     Items[I].ForEach(ABefore, AAfter);
    if Assigned(AAfter) then
      AAfter(Self);
  end;
end;

function TSprig.GetItem(Index: Integer): TSprig;
begin
  Result := nil;
  if Assigned(FList) then
    Result := TSprig(FList[Index]);
end;

function TSprig.Hint: string;
begin
  Result := '';
end;

function TSprig.Index: Integer;
begin
  Result := -1;
  if Parent <> nil then
    Result := Parent.IndexOf(Self);
end;

function TSprig.IndexOf(AItem: TSprig): Integer;
begin
  Result := -1;
  if Assigned(FList) then
    Result := FList.IndexOf(AItem);
end;

function TSprig.UniqueName: string;
begin
  Result := '';
  if Item <> nil then
    Result := Item.GetNamePath;
end;

function TSprig.Name: string;
begin
  Result := UniqueName;
end;

procedure TSprig.PrepareMenu(const AItems: IMenuItems);
begin
  //
end;

function TSprig.SeekParent(AItem: TPersistent; Recurse: Boolean): TSprig;
begin
  Result := nil;
  if AItem <> nil then
  begin
    if (Parent <> nil) and
       (Parent.Item = AItem) then
      Result := Parent
      
    else if Owner <> nil then
      Result := Owner.Find(AItem, Recurse);

    if Result = nil then
    begin
      if Root <> nil then
        Result := Root.Find(AItem, Recurse);
      if Result = nil then
        Result := Root;
    end;
  end
  else
    Result := Root;
end;

function TSprig.SeekParent(const AName: string; Recurse: Boolean): TSprig;
begin
  Result := nil;
  if AName <> '' then
  begin
    if (Parent <> nil) and
       AnsiSameText(Parent.Name, AName) then
      Result := Parent

    else if Owner <> nil then
      Result := Owner.Find(AName, Recurse);

    if Result = nil then
    begin
      if Root <> nil then
        Result := Root.Find(AName, Recurse);
      if Result = nil then
        Result := Root;
    end;
  end
  else
    Result := Root;
end;

function TSprig.SeekParent(const AName: string; AClass: TClass;
  Recurse: Boolean): TSprig;
begin
  Result := Root;
  if (AName <> '') and
     (AClass <> nil) then
  begin
    if (Parent <> nil) and
       (Parent.Item <> nil) and
       (Parent.Item is AClass) and
       AnsiSameText(Parent.Name, AName) then
      Result := Parent

    else if Owner <> nil then
      Result := Owner.Find(AName, AClass, Recurse);

    if Result = nil then
    begin
      if Root <> nil then
        Result := Root.Find(AName, AClass, Recurse);
      if Result = nil then
        Result := Root;
    end;
  end
  else
    Result := Root;
end;

function TSprig.Transient: Boolean;
begin
  Result := False;
end;

type
  THackTreeView = class(TCustomTreeView)
  end;

function TSprig.TreeNodeFor(ATreeView: TCustomTreeView): TTreeNode;
var
  LParent: TTreeNode;
begin
  if TreeNode = nil then
  begin
    EnsureUpdate;
    LParent := nil;
    if Parent <> nil then
      LParent := Parent.TreeNode;
    FTreeNode := THackTreeView(ATreeView).Items.AddNode(
      TSprigTreeNode.Create(THackTreeView(ATreeView).Items),
      LParent, Caption, Self, naAddChild);
    //FTreeNode := THackTreeView(ATreeView).Items.AddChildObject(LParent, Caption, Self);
  end;
  Result := TreeNode;
end;

procedure TSprig.VisualRefresh;
  function Trimmed(const AText: string): string;
  begin
    if Length(AText) >= 80 then
      Result := Copy(AText, 1, 76) + '... ' { Do not localize }
    else
      Result := AText;
  end;
begin
  if TreeNode <> nil then
    with TreeNode do
    begin
      if Self.FCaption <> Self.Caption then
        Self.FCaption := Trimmed(Self.Caption);
      Text := Self.FCaption;
      ImageIndex := Self.ImageIndex;
      SelectedIndex := Self.ImageIndex;
      StateIndex := Self.StateIndex;
      //HasChildren := Self.Count > 0;
    end;
end;

function TSprig.CaptionFor(const AName, ALabel, AClass: string): string;
begin
  Result := AName;
  if ALabel <> '' then
  begin
    if Result = '' then
      Result := '<?>'; // DO NOT LOCALIZE
    Result := Format('%s {%s}', [Result, ALabel]); // DO NOT LOCALIZE
  end;
  if GShowClassNameInTreeView then
  begin
    if AClass = '' then
      Result := Format('%s (%s)', [Result, AClass]) // DO NOT LOCALIZE
    else if Item <> nil then
      Result := Format('%s (%s)', [Result, Item.ClassName]); // DO NOT LOCALIZE
  end;
end;

function TSprig.PaletteOver(ASprigClass: TSprigClass; AClass: TClass): Boolean;
begin
  Result := False;
  if ASprigClass <> nil then
    Result := ASprigClass.PaletteOverTo(Self, AClass);
end;

class function TSprig.PaletteOverTo(AParent: TSprig; AClass: TClass): Boolean;
var
  LProp: PPropInfo;
begin
  Result := False;
  if ParentProperty <> '' then
  begin
    LProp := GetPropInfo(AClass.ClassInfo, ParentProperty, [tkClass]);
    if LProp <> nil then
      Result := (AParent is TRootSprig) or
                (AParent.Item is GetTypeData(LProp^.PropType^)^.ClassType);
  end;
end;

function TSprig.Path: string;
begin
  Result := UniqueName;
  if Parent <> nil then
    Result := Format('%s\%s', [Parent.Path, Result]); // DO NOT LOCALIZE
end;

function TSprig.DeleteStyle: TSprigDeleteStyle;
const
  cDeleteStyle: array [Boolean] of TSprigDeleteStyle = (dsAbort, dsNormal);
begin
  Result := cDeleteStyle[Item <> nil];
end;

function TSprig.CustomDelete: Boolean;
begin
  Result := False;
end;

function TSprig.ItemClass: TClass;
begin
  Result := nil;
  if Item <> nil then
    Result := Item.ClassType;
end;

class function TSprig.ParentProperty: string;
begin
  Result := '';
end;

procedure TSprig.FigureParent;
var
  LProp: PPropInfo;
  LParentItem: TPersistent;
begin
  // assume nowhere!
  LParentItem := nil;

  // if we actually point to something
  if Item <> nil then
  begin

    // parent property based?
    if ParentProperty <> '' then
    begin
      LProp := GetPropInfo(Item, ParentProperty, [tkClass]);
      if LProp <> nil then
        LParentItem := TPersistent(GetObjectProp(Item, LProp, TPersistent));
    end;

    // still nothing but we have a component
    if (LParentItem = nil) and
       (Item is TComponent) then
      LParentItem := TComponent(Item).GetParentComponent;
  end;

  // plug in!
  if LParentItem <> nil then
    SeekParent(LParentItem).Add(Self)
  else if Owner <> nil then
    Owner.Add(Self)
  else
    Root.Add(Self);
end;

procedure TSprig.FigureChildren;
var
  LProps: TPropList;
  LProp: TObject;
  LPropCount, I: Integer;
  LParent: TSprig;
  LParentClass: TSprigClass;
begin
  // something to do?
  if (Item <> nil) and not FCollectionsDone then
  begin
    FCollectionsDone := True;

    // grab the list of properties
    LPropCount := GetPropList(Item.ClassInfo, [tkClass], @LProps);

    // we need to make this a optimized as possible
    for I := 0 to LPropCount - 1 do
    begin

      // got a collection?
      LProp := TObject(GetOrdProp(Item, LProps[I]));
      if (LProp is TCollection) and
         (GetUltimateOwner(TCollection(LProp)) <> nil) then
      begin

        // does it exists already?
        LParent := Find(TCollection(LProp), False);
        if LParent = nil then
        begin
          LParentClass := FindBestSprigClass(TCollection(LProp).ClassType, TCollectionSprig);
          if LParentClass <> nil then
          begin
            LParent := LParentClass.Create(TCollection(LProp));
            TCollectionSprig(LParent).FPropName := LProps[I].Name;
            TCollectionSprig(LParent).FOwner := Self;

            // made some additions
            Add(LParent);
          end;
        end;
      end;
    end;
  end;
end;

function TSprig.FocusItem: TPersistent;
begin
  Result := Item;
  if (Result = nil) and
     (Parent <> nil) then
    Result := Parent.FocusItem;
end;

function SortBySprigItemIndex(Node1, Node2: TTreeNode; lParam: Integer): Integer; stdcall;
begin
  Result := TSprig(Node1.Data).ItemIndex -
            TSprig(Node2.Data).ItemIndex;
end;

procedure TSprig.SortItems;
begin
  if (TreeNode <> nil) and
     (TreeNode.HasChildren) then
    if SortByIndex then
      TreeNode.CustomSort(@SortBySprigItemIndex, 0)
    else
      TreeNode.CustomSort(nil, 0);
end;

function TSprig.SortByIndex: Boolean;
begin
  Result := False;
end;

function TSprig.ItemIndex: Integer;
begin
  Result := 0;
end;

procedure TSprig.Reparent;
begin
  // we don't care
end;

function TSprig.ShowRegisteredMenus: Boolean;
begin
  Result := Item <> nil;
end;

procedure TSprig.ReparentChildren;
var
  I: Integer;
begin
  for I := Count - 1 downto 0 do
    Items[I].Reparent;
end;

function TSprig.IncludeIndexInCaption: Boolean;
begin
  Result := False;
end;

procedure TSprig.SetExpanded(const Value: Boolean);
begin
  if FExpanded <> Value then
  begin
    FExpanded := Value;
    if Expanded and
       (Parent <> nil) then
      Parent.Expanded := True;
  end;
end;

procedure TSprig.Invalidate;
var
  I: Integer;
begin
  if not Invalid then
  begin
    FInvalid := True;

    // remove ourselve from the root index
    if Root <> nil then
      Root.RemoveItem(Self);

    // don't point there anymore
    FItem := nil;
    for I := Count - 1 downto 0 do
      Items[I].Invalidate;
  end;
end;

procedure TSprig.SelectItems(const AItems: array of TPersistent; ARuntimeChange: Boolean);
begin
  if Root <> nil then
    Root.SelectItems(AItems, ARuntimeChange);
end;

function TSprig.Parents(ASprig: TSprig): Boolean;
begin
  repeat
    Result := ASprig = Self;
    ASprig := ASprig.Parent;
  until (Result = True) or
        (ASprig = nil);
end;

procedure TSprig.DesigntimeChange;
begin
  if Root <> nil then
    Root.DesigntimeChange;
end;

procedure TSprig.RuntimeChange;
begin
  if Root <> nil then
    Root.RuntimeChange;
end;

function TSprig.GetDesigner(out ADesigner: IDesigner): Boolean;
begin
  if Root <> nil then
    Result := Root.GetDesigner(ADesigner)
  else
    Result := False;
end;

function TSprig.GetImageIndex: TImageIndex;
begin
  Result := FImageIndex;
  if Ghosted then
    Inc(Result, CGhostedOffset);
end;

procedure TSprig.SetImageIndex(const Value: TImageIndex);
begin
  FImageIndex := Value;
end;

function TSprig.GetStateIndex: TImageIndex;
const
  CStateIndex: array [Boolean] of TImageIndex = (CNoStateImage, CCheckOutStateImage);
begin
  Result := CStateIndex[AnyProblems];
end;

function TSprig.Construct(AClass: TComponentClass): TComponent;
var
  LDesigner: IDesigner;
  LParent: TPersistent;
begin
  Result := nil;
  if (Item <> nil) and
     (Item is TComponent) then
    LParent := Item
  else if Owner <> nil then
    LParent := Owner.Item
  else
    LParent := Root.Item;
  if (LParent is TComponent) and
     GetDesigner(LDesigner) then
    Result := LDesigner.CreateComponent(AClass, TComponent(LParent), 0, 0, 0, 0);
end;

procedure TSprig.BeginUpdate;
begin
  if Root <> nil then
    Root.BeginUpdate;
end;

procedure TSprig.EndUpdate;
begin
  if Root <> nil then
    Root.EndUpdate;
end;

procedure TSprig.EnsureUpdate;
begin
  if Root <> nil then
    Root.EnsureUpdate;
end;

function TSprig.Hidden: Boolean;
var
  LDesigner: IDesigner;
begin
  if not FHiddenTested and
     GetDesigner(LDesigner) then
  begin
    FHiddenTested := True;
    FHidden := not (Item is TComponent) or
               LDesigner.IsComponentHidden(TComponent(Item));
  end;
  Result := FHidden;
end;

function TSprig.Ghosted: Boolean;
begin
  Result := Hidden;
end;

function TSprig.CanMove(AUp: Boolean): Boolean;
var
  LSibling: TSprig;
begin
  Result := Assigned(Parent) and Parent.SortByIndex and
            Assigned(TreeNode) and Assigned(TreeNode.Parent);
  if Result then
  begin
    LSibling := nil;
    if AUp and (TreeNode.Index > 0) then
      LSibling := TSprig(TreeNode.Parent.Item[TreeNode.Index - 1].Data)
    else if not AUp and (TreeNode.Index < TreeNode.Parent.Count - 1) then
      LSibling := TSprig(TreeNode.Parent.Item[TreeNode.Index + 1].Data);
    Result := Assigned(LSibling) and LSibling.DragOver(Self)
  end;
end;

function TSprig.Move(AUp: Boolean): Boolean;
var
  LSibling: TSprig;
begin
  BeginUpdate;
  try
    if AUp then
      LSibling := TSprig(TreeNode.Parent.Item[TreeNode.Index - 1].Data)
    else
      LSibling := TSprig(TreeNode.Parent.Item[TreeNode.Index + 1].Data);
    Result := LSibling.DragDrop(Self);
    if Result then
      SelectItems([Item]);
  finally
    EndUpdate;
  end;
end;

procedure TSprig.AddType(Index: Integer);
begin
  //
end;

function TSprig.AddTypeCount: Integer;
begin
  Result := 0;
end;

function TSprig.CanAdd: Boolean;
begin
  Result := AddTypeCount > 0;
end;

function TSprig.GetAddType(Index: Integer): string;
begin
  Result := '';
end;

function TSprig.Owner: TSprig;
begin
  Result := nil;
end;

function TSprig.CopyGlyph(ABitmap: TBitmap): Boolean;
begin
  Result := Assigned(CopySprigGlyphFunc) and
            CopySprigGlyphFunc(Self, ABitmap);
end;

{ TRootSprig }

procedure TRootSprig.AddItem(ASprig: TSprig);
begin
  if ASprig.Item <> nil then
    FIndex.Add(ASprig);
end;

function TRootSprig.DeleteStyle: TSprigDeleteStyle;
begin
  Result := dsAbort;
end;

procedure TRootSprig.SelectionSurvey(out ADeleteStyle: TSprigDeleteStyle; out AAllVisible: Boolean);
var
  I: Integer;
  LSprig: TSprig;
  LAbort, LAllCustom, LAllNormal: Boolean;
begin
  AAllVisible := True;
  LAbort := False;
  LAllCustom := True;
  LAllNormal := True;
  for I := 0 to TreeView.SelectionCount - 1 do
  begin
    LSprig := TSprig(TreeView.Selections[I].Data);
    if LSprig <> nil then
    begin

      // calculate if all are visible?
      AAllVisible := AAllVisible and not LSprig.Hidden;

      // calculate delete style
      case LSprig.DeleteStyle of
        dsNormal:
          LAllCustom := False;
        dsIgnore:;
        dsAbort:
          LAbort := True;
        dsCustom:
          LAllNormal := False;
      end;
    end;
  end;

  ADeleteStyle := dsAbort;
  if not LAbort then
    if LAllNormal then
      ADeleteStyle := dsNormal
    else if LAllCustom then
      ADeleteStyle := dsCustom;
end;

function TRootSprig.EditAction(Action: TEditAction): Boolean;

  function DoCustomDelete(out ASprig: TSprig): Boolean;
  var
    I: Integer;
    LSprig: TSprig;
  begin
    Result := False;
    ASprig := nil;
    for I := 0 to TreeView.SelectionCount - 1 do
    begin
      LSprig := TSprig(TreeView.Selections[I].Data);
      if LSprig <> nil then
      begin
        Result := LSprig.CustomDelete or Result;
        if not LSprig.Invalid then
          ASprig := LSprig;
      end;
    end;
  end;

var
  LEditQuery: IDesignEditQuery;
  LDeleteStyle: TSprigDeleteStyle;
  LAllVisible: Boolean;
  LSprig: TSprig;
begin
  Result := False;
  if Supports(Designer, IDesignEditQuery, LEditQuery) then
  begin

    // one we care about?
    if Action in [eaDelete, eaCut, eaCopy] then
    begin
      SelectionSurvey(LDeleteStyle, LAllVisible);

      // delete
      if Action = eaDelete then
        case LDeleteStyle of
          dsNormal:
            begin
              Designer.DeleteSelection(True);
              Result := True;
            end;
          dsCustom:
            begin
              Result := DoCustomDelete(LSprig);
              if Result then
                if (LSprig <> nil) and
                   (LSprig.Item <> nil) then
                  SelectItems([LSprig.Item], True)
                else
                  RuntimeChange;
            end;
        else
          Result := False;
        end

      // cut/copy
      else if (LDeleteStyle = dsNormal) and LAllVisible then
        Result := LEditQuery.EditAction(Action);
    end
    else
      Result := LEditQuery.EditAction(Action);
  end;
end;

function TRootSprig.GetEditState: TEditState;
var
  LEditQuery: IDesignEditQuery;
  LDeleteStyle: TSprigDeleteStyle;
  LAllVisible: Boolean;
begin
  Result := [];
  if Supports(Designer, IDesignEditQuery, LEditQuery) then
  begin
    Result := LEditQuery.GetEditState;

    Result := Result - [esCanZOrder, esCanAlignGrid, esCanEditOle,
                        esCanTabOrder, esCanCreationOrder, esCanCreateTemplate];

    SelectionSurvey(LDeleteStyle, LAllVisible);
    if LDeleteStyle = dsAbort then
      Result := Result - [esCanDelete];
    if not LAllVisible then
      Result := Result - [esCanCopy, esCanCut, esCanPaste];
  end;
end;

function TRootSprig.SelectedSprig(var ASprig: TSprig): Boolean;
begin
  Result := (TreeView <> nil) and
            (TreeView.SelectionCount = 1) and
            (TreeView.Selections[0].Data <> Self);
  if Result then
    ASprig := TSprig(TreeView.Selections[0].Data);
end;

function TRootSprig.CanMove(AUp: Boolean): Boolean;
var
  LSprig: TSprig;
begin
  Result := SelectedSprig(LSprig) and
            LSprig.CanMove(AUp);
end;

function TRootSprig.Move(AUp: Boolean): Boolean;
var
  LSprig: TSprig;
begin
  Result := SelectedSprig(LSprig) and
            LSprig.Move(AUp);
end;

procedure TRootSprig.AddType(Index: Integer);
var
  LSprig: TSprig;
begin
  if SelectedSprig(LSprig) then
    LSprig.AddType(Index);
end;

function TRootSprig.AddTypeCount: Integer;
var
  LSprig: TSprig;
begin
  Result := 0;
  if SelectedSprig(LSprig) then
    Result := LSprig.AddTypeCount;
end;

function TRootSprig.GetAddType(Index: Integer): String;
var
  LSprig: TSprig;
begin
  Result := '';
  if SelectedSprig(LSprig) then
    Result := LSprig.GetAddType(Index);
end;

function TRootSprig.CanAdd: Boolean;
var
  LSprig: TSprig;
begin
  Result := SelectedSprig(LSprig) and
            LSprig.CanAdd;
end;

constructor TRootSprig.Create(AItem: TPersistent);
begin
  inherited;
  FRoot := Self;
  FIndex := TSprigIndex.Create;
  FNamedItems := TList.Create;
  FPathedItems := TList.Create;
  FRepopulateNeeded := True;
end;

procedure TRootSprig.DesigntimeChange;
{var
  LDesigner: IDesigner;}
begin
{  if GetDesigner(LDesigner) then
    LDesigner.Modified;}
    //!!
end;

destructor TRootSprig.Destroy;
begin
  SprigDesigner := nil;
  inherited;
  FreeAndNil(FIndex);
  FreeAndNil(FNamedItems);
  FreeAndNil(FPathedItems);
end;

procedure TRootSprig.FigureParent;
begin
  // we do nothing
end;

function TRootSprig.FindItem(AItem: TPersistent; Recurse: Boolean): TSprig;
begin
  if AItem = Item then
    Result := Self
  else if not Recurse then
    Result := inherited FindItem(AItem, False)
  else
    Result := FIndex.Find(AItem);
end;

function TRootSprig.FindItemByName(const AName: string; AClass: TClass;
  Recurse: Boolean): TSprig;
  function MatchingItem(ASprig: TSprig): Boolean;
  begin
    Result := AnsiSameText(ASprig.Name, AName) and
              ((AClass = nil) or
               (ASprig.Item is AClass));
  end;
var
  I: Integer;
begin
  if MatchingItem(Self) then
    Result := Self
  else
  begin
    Result := nil;
    for I := 0 to FNamedItems.Count - 1 do
      if MatchingItem(TSprig(FNamedItems[I])) then
      begin
        Result := TSprig(FNamedItems[I]);
        Break;
      end;
    if Result = nil then
    begin
      Result := inherited FindItemByName(AName, AClass, Recurse);
      if Result <> nil then
        FNamedItems.Add(Result);
    end;
  end;
end;

function TRootSprig.FindItemByPath(const APath: string;
  Recurse: Boolean): TSprig;
var
  I: Integer;
begin
  if AnsiSameText(Path, APath) then
    Result := Self
  else
  begin
    Result := nil;
    for I := 0 to FPathedItems.Count - 1 do
      if AnsiSameText(TSprig(FPathedItems[I]).Path, APath) then
      begin
        Result := TSprig(FPathedItems[I]);
        Break;
      end;
    if Result = nil then
    begin
      Result := inherited FindItemByPath(APath, Recurse);
      if Result <> nil then
        FPathedItems.Add(Result);
    end;
  end;
end;

procedure TRootSprig.SelectItems(const AItems: array of TPersistent; ARuntimeChange: Boolean);
var
  LDesigner: IDesigner;
  LSelections: IDesignerSelections;
  I: Integer;
begin
  if GetDesigner(LDesigner) then
  begin
    if ARuntimeChange then
      LDesigner.Modified;
    LSelections := CreateSelectionlist;
    for I := Low(AItems) to High(AItems) do
      LSelections.Add(AItems[I]);
    LDesigner.SetSelections(LSelections);
  end;
end;

function TRootSprig.PaletteOver(ASprigClass: TSprigClass; AClass: TClass): Boolean;
begin
  Result := True;
end;

procedure TRootSprig.RemoveItem(ASprig: TSprig);
begin
  if ASprig.Item <> nil then
    FIndex.Remove(ASprig);
  FNamedItems.Remove(ASprig);
  FPathedItems.Remove(ASprig);
end;

procedure TRootSprig.ValidateParent(AItem: TSprig);
var
  LParent: TSprig;
begin
  if not AItem.Invalid then
  begin

    // figure out the parent
    LParent := AItem.Parent;
    AItem.FigureParent;
    FParentChanges := FParentChanges or (LParent <> AItem.Parent);

    // figure out the children
    AItem.FigureChildren;
  end;
end;

function TRootSprig.Repopulate: Boolean;
var
  LToDo: TList;

  procedure ValidateSprigs(ASprig: TSprig);
  var
    I: Integer;
  begin
    // only if the sprig is valid
    if not ASprig.Invalid then
    begin
      // expando?
      StoreExpandState(ASprig);

      // remove it from the todo list?
      if ASprig.Item <> nil then
        LToDo.Remove(ASprig.Item);
    end;

    // now validate the children
    for I := ASprig.Count - 1 downto 0 do
      ValidateSprigs(ASprig[I]);

    // now the sprig itself
    if ASprig.Invalid then
      ASprig.Free;
  end;

  procedure RemoveInvalidSprigs(ASprig: TSprig);
  var
    I: Integer;
  begin
    for I := ASprig.Count - 1 downto 0 do
      RemoveInvalidSprigs(ASprig);
    if ASprig.Invalid then
      ASprig.Free;
  end;
var
  I: Integer;
  LSprigClass: TSprigClass;
  LSprig: TSprig;
  LItem: TComponent;
begin
  // assume no additions
  Result := False;
  if FRepopulateNeeded then
  begin
    BeginUpdate;
    FRepopulating := True;
    LToDo := TList.Create;
    try

      // For each component, add to the ToDo list
      with TComponent(Item) do
        for I := 0 to ComponentCount - 1 do
        begin
          LItem := Components[I];
          if not (csTransient in LItem.ComponentStyle) and
             (csDesigning in LItem.ComponentState) and
             not (csDestroying in LItem.ComponentState) then
            LToDo.Add(Components[I]);
        end;

      // clear the invalid items
      ValidateSprigs(Self);

      // For each item in the ToDo list
      for I := 0 to LToDo.Count - 1 do
      begin

        // Find best sprig class
        LSprigClass := FindBestSprigClass(TComponent(LToDo[I]).ClassType, TComponentSprig);

        // Create the sprig at the root
        if LSprigClass <> nil then
        begin
          LSprig := LSprigClass.Create(TComponent(LToDo[I]));
          TComponentSprig(LSprig).FOwner := Self;

          // made some additions
          Add(LSprig);
          Result := True;
        end;
      end;

      // For each sprig until there are no more parent changes
      repeat
        FParentChanges := False;
        ForEach(ValidateParent);
      until not FParentChanges;

      // prune the tree of sprigs (transient or any remaining invalid ones
      ClearUnneededSprigs;

      // make sure we are expanded
      FExpanded := True;

    finally
      // clean up
      LToDo.Free;
      FRepopulateNeeded := False;
      FRepopulating := False;
      EndUpdate;
    end;
  end;
end;

procedure TRootSprig.RuntimeChange;
var
  LDesigner: IDesigner;
begin
  if GetDesigner(LDesigner) then
    LDesigner.Modified;
end;

procedure TRootSprig.PreRefreshTreeView(AItem: TSprig);
begin
  with AItem do
  begin
    TreeNodeFor(TreeView);
    VisualRefresh;
  end;
end;

procedure TRootSprig.PostRefreshTreeView(AItem: TSprig);
begin
  with AItem do
  begin
    SortItems;
    RestoreExpandState(AItem);
  end;
end;

procedure TRootSprig.RestoreExpandState(AItem: TSprig);
{var
  I: Integer;}
  procedure MakeExpanded(ANode: TTreeNode);
  begin
    if ANode <> nil then
    begin
      if not ANode.Expanded then
        ANode.Expanded := True;
      MakeExpanded(ANode.Parent);
    end;
  end;
begin
  if AItem.TreeNode <> nil then
  begin
    {if FExpandedItems.Count > 0 then
    begin
      I := FExpandedItems.IndexOf(AItem.Path);
      if I >= 0 then
      begin
        FExpandedItems.Delete(I);
        AItem.Expanded := True;
      end;
    end;}
    if AItem.Expanded or
       (AItem = Self) then
      MakeExpanded(AItem.TreeNode);
  end;
end;

procedure TRootSprig.StoreExpandState(AItem: TSprig);
begin
  with AItem do
    Expanded := (TreeNode <> nil) and
                (TreeNode.Expanded) and
                (TreeNode.IsVisible);
end;

procedure TRootSprig.StoreTreeState;
begin
  if TreeView <> nil then
    ForEach(StoreExpandState);
end;

procedure TRootSprig.DepopulateTreeView(AItem: TSprig);
begin
  with AItem do
  begin
    Expanded := (TreeNode <> nil) and
                (TreeNode.Expanded) and
                (TreeNode.IsVisible);
    ClearTreeNode;
  end;
end;

procedure TRootSprig.RefreshTreeView;
begin
  BeginUpdate;
  if RepopulateNeeded then
    Repopulate;
  if TreeView <> nil then
    ForEach(PreRefreshTreeView, PostRefreshTreeView);
  EndUpdate;
end;

function TRootSprig.GetDesigner(out ADesigner: IDesigner): Boolean;
begin
  ADesigner := Designer;
  Result := ADesigner <> nil;
end;

procedure TRootSprig.ItemDeleted(AItem: TPersistent);
var
  LSprig: TSprig;
begin
  LSprig := Find(AItem);
  if (LSprig <> nil) and
     (LSprig <> Self) and
     (not LSprig.Invalid) then
  begin
    LSprig.Invalidate;
    FRepopulateNeeded := True;
  end;
end;

procedure TRootSprig.ItemInserted;
begin
  FRepopulateNeeded := True;
end;

procedure TRootSprig.ItemsModified(AForceRepopulate: Boolean);
begin
  if AForceRepopulate then
    FRepopulateNeeded := True;
  if SprigDesigner <> nil then
  begin
    SprigDesigner.BeforeItemsModified;
    try
      RefreshTreeView;
    finally
      SprigDesigner.AfterItemsModified;
    end;
  end;
end;

function TRootSprig.AcceptsClass(AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TComponent);
end;

procedure TRootSprig.BeginUpdate;
begin
  Inc(FUpdateLocks);
end;

procedure TRootSprig.EndUpdate;
begin
  if FUpdateLocks > 0 then
  begin
    Dec(FUpdateLocks);
    if (FUpdateLocks = 0) and (FNeedUpdate) then
    begin
      if TreeView <> nil then
        THackTreeView(TreeView).Items.EndUpdate;
      FNeedUpdate := False;
    end;
  end;
end;

procedure TRootSprig.EnsureUpdate;
begin
  if (FUpdateLocks > 0) and (not FNeedUpdate) then
  begin
    if TreeView <> nil then
      THackTreeView(TreeView).Items.BeginUpdate;
    FNeedUpdate := True;
  end;
end;

procedure TRootSprig.SetSprigDesigner(const ASprigDesigner: ISprigDesigner);
var
  LSprigDesigner: ISprigDesigner;
begin
  if SprigDesigner <> nil then
  begin
    Assert(FUpdateLocks = 0);
    ForEach(nil, DepopulateTreeView);
    LSprigDesigner := SprigDesigner;
    FSprigDesigner := nil;
    LSprigDesigner.RootSprig := nil;
    //LSprigDesigner.Collection := nil;
  end;
  FSprigDesigner := ASprigDesigner;
  FUpdateLocks := 0;
  FNeedUpdate := False;
  if SprigDesigner <> nil then
    RefreshTreeView;
end;

function TRootSprig.TreeView: TCustomTreeView;
begin
  Result := nil;
  if SprigDesigner <> nil then
    Result := SprigDesigner.GetTreeView;
end;

{ TSprigType }

constructor TSprigType.Create(const AClass: TClass; const ASprigClass: TSprigClass);
begin
  inherited Create;
  FClass := AClass;
  FSprigClass := ASprigClass;
  FGroup := CurrentGroup;
end;

function TSprigType.Score(const AClass: TClass): Integer;
begin
  Result := High(Integer);
  if AClass.InheritsFrom(FClass) then
    Result := CountGenerations(FClass, AClass);
end;

{ TSprigIntfType }

constructor TSprigIntfType.Create(const AInterfaces: TGUIDArray;
  const ASprigClass: TSprigClass);
begin
  inherited Create;
  FInterfaces := AInterfaces;
  FSprigClass := ASprigClass;
  FGroup := CurrentGroup;
end;

function TSprigIntfType.Match(const AClass: TClass): Boolean;
var
  I: Integer;
begin
  for I := 0 to Length(FInterfaces) - 1 do
    if not Supports(AClass, FInterfaces[I]) then
    begin
      Result := False;
      Exit;
    end;
  Result := True;
end;

{ TSprigTypeList }

procedure TSprigTypeList.Add(const AClass: TClass; const ASprigClass: TSprigClass);
begin
  FList.Insert(0, TSprigType.Create(AClass, ASprigClass));
end;

procedure TSprigTypeList.Add(const AInterfaces: TGUIDArray;
  const ASprigClass: TSprigClass);
begin
  FInterfaceList.Insert(0, TSprigIntfType.Create(AInterfaces, ASprigClass));
end;

procedure TSprigTypeList.ClearCache;
begin
  FLastClass := nil;
  FLastSprigClass := nil;
end;

constructor TSprigTypeList.Create;
begin
  inherited;
  FList := TObjectList.Create;
  FInterfaceList := TObjectList.Create;
end;

destructor TSprigTypeList.Destroy;
begin
  FList.Free;
  FInterfaceList.Free;
  inherited;
end;

procedure TSprigTypeList.FreeEditorGroup(AGroup: Integer);
var
  I: Integer;
begin
  ClearCache;
  for I := FList.Count - 1 downto 0 do
    if TSprigType(FList[I]).FGroup = AGroup then
      FList.Delete(I);
  for I := FInterfaceList.Count - 1 downto 0 do
    if TSprigIntfType(FInterfaceList[I]).FGroup = AGroup then
      FInterfaceList.Delete(I);
end;

function TSprigTypeList.Match(const AClass: TClass): TSprigClass;
begin
  Result := MatchCache(AClass);
  if Result = nil then
    Result := MatchClass(AClass);
end;

function TSprigTypeList.MatchCache(const AClass: TClass): TSprigClass;
begin
  Result := nil;
  if FLastClass = AClass then
    Result := FLastSprigClass;
end;

function TSprigTypeList.MatchClass(const AClass: TClass): TSprigClass;
var
  I, LBestScore, LScore: Integer;
begin
  Result := nil;
  for I := 0 to FInterfaceList.Count - 1 do
    if TSprigIntfType(FInterfaceList[I]).Match(AClass) then
    begin
      Result := TSprigIntfType(FInterfaceList[I]).SprigClass;
      Break;
    end;
  if Result = nil then
  begin
    LBestScore := High(Integer);
    for I := 0 to FList.Count - 1 do
    begin
      LScore := TSprigType(FList[I]).Score(AClass);
      if LScore < LBestScore then
      begin
        LBestScore := LScore;
        Result := TSprigType(FList[I]).SprigClass;
      end;
    end;
  end;
  if Result <> nil then
  begin
    FLastClass := AClass;
    FLastSprigClass := Result;
  end;
end;

{ TDragSprig }

procedure TDragSprigs.Add(ASprig: TSprig);
begin
  FSprigs.Add(ASprig);
end;

constructor TDragSprigs.Create(AControl: TControl);
begin
  inherited Create(AControl);
  FSprigs := TList.Create;
end;

destructor TDragSprigs.Destroy;
begin
  FSprigs.Free;
  inherited;
end;

function TDragSprigs.GetSprig(Index: Integer): TSprig;
begin
  Result := TSprig(FSprigs[Index]);
end;

function TDragSprigs.Count: Integer;
begin
  Result := FSprigs.Count;
end;

{ TPropertySprig }

function TPropertySprig.DeleteStyle: TSprigDeleteStyle;
begin
  Result := dsAbort;
end;

function TPropertySprig.Ghosted: Boolean;
begin
  Result := False;
end;

{ TCollectionSprig }

function TCollectionSprig.DeleteStyle: TSprigDeleteStyle;
begin
  Result := dsCustom;
end;

function TCollectionSprig.CustomDelete: Boolean;
begin
  Result := TCollection(Item).Count > 0;
  if Result then
    TCollection(Item).Clear;
end;

function TCollectionSprig.Caption: string;
begin
  Result := CaptionFor(FPropName);
end;

procedure TCollectionSprig.FigureParent;
begin
  SeekParent(FOwner.Item);
end;

function TCollectionSprig.SortByIndex: Boolean;
begin
  Result := True;
end;

function TCollectionSprig.Name: string;
begin
  Result := Format(CCollectionName, [FPropName]);
end;

constructor TCollectionSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CCollectionSprigImage;
end;

procedure TCollectionSprig.AddType(Index: Integer);
begin
  SelectItems([TCollection(Item).Add]);
end;

function TCollectionSprig.AddTypeCount: Integer;
begin
  Result := 1;
end;

resourcestring
  sAddCaption = 'Add item';

function TCollectionSprig.GetAddType(Index: Integer): string;
begin
  case Index of
    0: Result := sAddCaption;
  end;
end;

function TCollectionSprig.Owner: TSprig;
begin
  Result := FOwner;
end;

procedure TCollectionSprig.FigureChildren;
var
  I: Integer;
  LChildItem: TCollectionItem;
  LChild: TSprig;
  LChildClass: TSprigClass;
begin
  // let it go first
  inherited;

  // now lets loop through the component items
  for I := 0 to TCollection(Item).Count - 1 do
  begin

    // find the best class
    LChildItem := TCollection(Item).Items[I];
    LChild := Find(LChildItem, False);

    // if not then create it
    if LChild = nil then
    begin
      LChildClass := FindBestSprigClass(LChildItem.ClassType, TCollectionItemSprig);
      if LChildClass <> nil then
      begin
        LChild := LChildClass.Create(LChildItem);
        TCollectionItemSprig(LChild).FOwner := Self;

        // made some additions
        Add(LChild);
      end;
    end;
  end;
end;

{ TCollectionItemSprig }

procedure TCollectionItemSprig.FigureParent;
begin
  SeekParent(FOwner.Item);
end;

function TCollectionItemSprig.Name: string;
begin
  Result := TCollectionItem(Item).DisplayName;
end;

function TCollectionItemSprig.ItemIndex: Integer;
begin
  Result := TCollectionItem(Item).Index;
end;

function TCollectionItemSprig.DragDropTo(AParent: TSprig): Boolean;
var
  LOrigIndex: Integer;
begin
  LOrigIndex := ItemIndex;
  if AParent.Parent = Parent then
    TCollectionItem(Item).Index := TCollectionItem(AParent.Item).Index;
  Result := LOrigIndex <> ItemIndex;
end;

function TCollectionItemSprig.DragOverTo(AParent: TSprig): Boolean;
begin
  Result := AParent.Parent = Parent;
end;

function TCollectionItemSprig.IncludeIndexInCaption: Boolean;
begin
  Result := True;
end;

procedure TCollectionItemSprig.AddType(Index: Integer);
begin
  Parent.AddType(Index);
end;

function TCollectionItemSprig.AddTypeCount: Integer;
begin
  Result := Parent.AddTypeCount;
end;

function TCollectionItemSprig.GetAddType(Index: Integer): string;
begin
  Result := Parent.AddTypes[Index];
end;

function TCollectionItemSprig.Owner: TSprig;
begin
  Result := FOwner;
end;

function TCollectionItemSprig.Ghosted: Boolean;
begin
  Result := False;
end;

{ TSprigIndex }

procedure TSprigIndex.Add(ASprig: TSprig);
var
  I, L: Integer;
begin
  L := WordRec(LongRec(ASprig.Item).Lo).Hi; // grab xxxxLLxx byte
  if FList[L] = nil then
    FList[L] := TList.Create;
  for I := 0 to TList(FList[L]).Count - 1 do
    if TList(FList[L]).Items[I] = ASprig then
      Assert(False);
  TList(FList[L]).Add(ASprig);
end;

constructor TSprigIndex.Create;
begin
  inherited;
  FList := TObjectList.Create;
  FList.Count := 256;
end;

destructor TSprigIndex.Destroy;
begin
  FList.Free;
  inherited;
end;

function TSprigIndex.Find(AItem: TPersistent): TSprig;
var
  I, L: Integer;
begin
  Result := nil;
  L := WordRec(LongRec(AItem).Lo).Hi; // grab xxxxLLxx byte
  if FList[L] <> nil then
    for I := 0 to TList(FList[L]).Count - 1 do
      if TSprig(TList(FList[L]).Items[I]).Item = AItem then
      begin
        Result := TSprig(TList(FList[L]).Items[I]);
        Break;
      end;
end;

procedure TSprigIndex.Remove(ASprig: TSprig);
var
  I, L: Integer;
begin
  L := WordRec(LongRec(ASprig.Item).Lo).Hi; // grab xxxxLLxx byte
  if FList[L] <> nil then
  begin
    for I := 0 to TList(FList[L]).Count - 1 do
      if TList(FList[L]).Items[I] = ASprig then
      begin
        TList(FList[L]).Delete(I);
        Break;
      end;
    if TList(FList[L]).Count = 0 then
      FList[L] := nil; // this will free and nil the sub-list reference
  end;
end;

{ TSprigTreeNode }

destructor TSprigTreeNode.Destroy;
begin
  if Data <> nil then
    TSprig(Data).ClearTreeNode(True, False);
  inherited;
end;

{ TComponentSprig }

constructor TComponentSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CComponentSprigImage;
end;

constructor TComponentSprig.Create(AItem: TPersistent; AOwner: TSprig);
begin
  Create(AItem);
  FOwner := AOwner;
end;

resourcestring
  SUnnamedItemCaption = '<Components[%d]>';

//function TComponentSprig.ShowRegisteredMenus: Boolean;
//begin
//  Result := not Hidden;
//end;

function TComponentSprig.Owner: TSprig;
begin
  Result := FOwner;
end;

function TComponentSprig.UniqueName: string;
begin
  if Item <> nil then
  begin
    Result := TComponent(Item).Name;
    if Result = '' then
      Result := Format(SUnnamedItemCaption, [TComponent(Item).ComponentIndex]);
  end
  else
    Result := inherited UniqueName;
end;

{ TAbstractSprig }

function TAbstractSprig.Ghosted: Boolean;
begin
  Result := False;
end;

{ TTransientSprig }

function TTransientSprig.Transient: Boolean;
begin
  Result := True;
end;

{ TAbstractCollectionSprig }

constructor TAbstractCollectionSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CFakeCollectionSprigImage;
end;

{ TTransientCollectionSprig }

constructor TTransientCollectionSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CFakeCollectionSprigImage;
end;


{ RootSprigList support }

var
  InternalRootSprigList: TRootSprigList = nil;

function RootSprigList: TRootSprigList;
begin
  if InternalRootSprigList = nil then
    InternalRootSprigList := TRootSprigList.Create;
  Result := InternalRootSprigList;
end;


{ TRootSprigList }

constructor TRootSprigList.Create;
begin
  inherited;
  FList := TBucketList.Create;
end;

procedure TRootSprigList.DesignerClosed(const ADesigner: IDesigner; AGoingDormant: Boolean);
var
  LRootSprig: Pointer;
  LRoot: TComponent;
begin
  if ADesigner <> nil then
  begin
    LRoot := ADesigner.Root;
    if FList.Find(LRoot, LRootSprig) then
    begin
      FList.Remove(LRoot);
      TRootSprig(LRootSprig).Designer := nil;
      TRootSprig(LRootSprig).SprigDesigner := nil;
      FreeAndNil(LRootSprig);
    end;
  end;
end;

procedure TRootSprigList.DesignerOpened(const ADesigner: IDesigner; AResurrecting: Boolean);
var
  LRoot: TComponent;
  LRootSprigClass: TRootSprigClass;
  LRootSprig: TRootSprig;
begin
  if ADesigner <> nil then
  begin
    LRoot := ADesigner.Root;
    if not FList.Exists(LRoot) then
    begin
      LRootSprigClass := FindBestRootSprigClass(LRoot.ClassType);
      LRootSprig := LRootSprigClass.Create(LRoot);
      LRootSprig.Designer := ADesigner;
      FList.Add(LRoot, LRootSprig);
    end;
  end;
end;

destructor TRootSprigList.Destroy;
begin
  FreeAndNil(FList);
  inherited;
end;

function TRootSprigList.FindRoot(const ADesigner: IDesigner;
  out ARootSprig: TRootSprig): Boolean;
var
  LRootSprig: Pointer;
begin
  Result := (ADesigner <> nil) and FList.Find(ADesigner.Root, LRootSprig);
  if Result then
    ARootSprig := TRootSprig(LRootSprig);
end;

procedure TRootSprigList.ItemDeleted(const ADesigner: IDesigner;
  AItem: TPersistent);
var
  LRootSprig: TRootSprig;
begin
  if FindRoot(ADesigner, LRootSprig) then
    LRootSprig.ItemDeleted(AItem);
end;

procedure TRootSprigList.ItemInserted(const ADesigner: IDesigner;
  AItem: TPersistent);
var
  LRootSprig: TRootSprig;
begin
  if FindRoot(ADesigner, LRootSprig) then
    LRootSprig.ItemInserted;
end;

procedure TRootSprigList.ItemsModified(const ADesigner: IDesigner);
var
  LRootSprig: TRootSprig;
begin
  if FindRoot(ADesigner, LRootSprig) then
    LRootSprig.ItemsModified;
end;

initialization
  NotifyGroupChange(FlushSprigTypes);

finalization
  FreeAndNil(InternalRootSprigList);
  FreeAndNil(InternalSprigTypeList);
  FreeAndNil(InternalRootSprigTypeList);
  UnNotifyGroupChange(FlushSprigTypes);
end.
