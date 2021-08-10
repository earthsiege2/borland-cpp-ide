
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 1995,2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit ListActns;

interface

uses Classes, Controls, ActnList, ImgList;

type

  TListControlItems = class;

  TListControlItem = class(TCollectionItem)
  private
    FListControlItems: TListControlItems;
  protected
    FCaption: String;
    FData: Pointer;
    FImageIndex: TImageIndex;
    procedure Changed;
    function GetDisplayName: String; override;
    procedure SetCaption(const Value: String); virtual;
    procedure SetData(const Value: Pointer); virtual;
    procedure SetImageIndex(const Value: TImageIndex); virtual;
  public
    constructor Create(Collection: TCollection); override;
    procedure Assign(Source: TPersistent); override;
    property Data: Pointer read FData write SetData;
  published
    property Caption: String read FCaption write SetCaption;
    property ImageIndex: TImageIndex read FImageIndex write SetImageIndex default -1;
  end;

  TListItemsSortType = (stNone, stData, stText, stBoth);
  TListCompareEvent = function(List: TListControlItems;
    Item1, Item2: TListControlItem): Integer of object;
  TListItemsCompare = function(List: TListControlItems;
    Index1, Index2: Integer): Integer;

  TListControlItems = class(TOwnedCollection)
  private
    FCaseSensitive: Boolean;
    FSortType: TListItemsSortType;
    FOnCompare: TListCompareEvent;
    procedure ExchangeItems(Index1, Index2: Integer);
    function GetListItem(const Index: Integer): TListControlItem;
    procedure QuickSort(L, R: Integer; SCompare: TListItemsCompare);
    procedure SetSortType(const Value: TListItemsSortType);
  protected
    function CompareItems(I1, I2: TListControlItem): Integer; virtual;
  public
    function Add: TListControlItem;
    procedure Sort;
    procedure CustomSort(Compare: TListItemsCompare);
    property Items[const Index: Integer]: TListControlItem read GetListItem; default;
  published
    property CaseSensitive: Boolean read FCaseSensitive write FCaseSensitive;
    property SortType: TListItemsSortType read FSortType write SetSortType;
    property OnCompare: TListCompareEvent read FOnCompare write FOnCompare;
  end;

{ TCustomListAction }

  TCustomListAction = class;
  TGetItemCountEvent = procedure(Sender: TCustomListAction;
    var Count: Integer) of object;
  TItemSelectedEvent = procedure(Sender: TCustomListAction;
    Control: TControl) of object;

  TCustomListAction = class(TCustomAction)
  private
    FActive: Boolean;
    FActivated: Boolean;
    FImages: TCustomImageList;
    FInUpdate: Boolean;
    FLoadedImages: TCustomImageList;
    FLoading: Boolean;
    FOnGetItemCount: TGetItemCountEvent;
    FOnItemSelected: TItemSelectedEvent;
    FItemIndex: Integer;
    procedure SetActive(const Value: Boolean);
    procedure SetImages(const Value: TCustomImageList);
    procedure SetItemIndex(const Value: Integer);
  protected
    function GetCount: Integer; virtual;
    function GetString(Index: Integer): String; virtual;
    procedure Loaded; override;
    procedure SetString(Index: Integer; const Value: String); virtual;
    property Images: TCustomImageList read FImages write SetImages;
    property ItemIndex: Integer read FItemIndex write SetItemIndex;
    property Loading: Boolean read FLoading;    
    property OnGetItemCount: TGetItemCountEvent read FOnGetItemCount
      write FOnGetItemCount;
    property OnItemSelected: TItemSelectedEvent read FOnItemSelected write FOnItemSelected;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ExecuteTarget(Target: TObject); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    property Active: Boolean read FActive write SetActive default True;
    property Count: Integer read GetCount;
    property Strings[Index: Integer]: String read GetString write SetString; default;
  end;

{ TVirtualListAction }

  TGetVirtualItemEvent = procedure(Sender: TCustomListAction; const Index: Integer;
    var Value: String; var ImageIndex: Integer; var Data: Pointer) of object;

  TVirtualListAction = class(TCustomListAction)
  private
    FOnGetItem: TGetVirtualItemEvent;
  protected
    function GetItem(const Index: Integer; var Value: String;
      var ImageIndex: Integer; var Data: Pointer): Boolean;
  public
    property Count;
  published
    property Active;
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property Images;
    property ItemIndex default -1;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnGetItem: TGetVirtualItemEvent read FOnGetItem write FOnGetItem;
    property OnGetItemCount;
    property OnItemSelected;
    property OnHint;
  end;

{ TStaticListAction }

  TStaticListAction = class;
  TGetItemEvent = procedure(Sender: TCustomListAction; const Index: Integer;
    var Item: TListControlItem) of object;

  TStaticListItems = class(TListControlItems)
  private
    FStaticListAction: TStaticListAction;
  protected
    procedure Notify(Item: TCollectionItem;
      Action: TCollectionNotification); override;
    procedure Update(Item: TCollectionItem); override;
  end;

  TListControlItemClass = class of TListControlItem;

  TStaticListAction = class(TCustomListAction)
  private
    FListItems: TStaticListItems;
    FOnGetItem: TGetItemEvent;
    procedure SetListitems(const Value: TStaticListItems);
  protected
    function GetItemClass: TListControlItemClass; virtual;
    function GetCount: Integer; override;
    function GetItem(const Index: Integer; AnItem: TListControlItem): Boolean;
    function GetString(Index: Integer): String; override;
    procedure SetString(Index: Integer; const Value: String); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Count;
  published
    property Active;
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property Images;
    property ItemIndex default -1;
    property Items: TStaticListItems read FListItems write SetListitems;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnGetItem: TGetItemEvent read FOnGetItem write FOnGetItem;
    property OnItemSelected;
    property OnHint;
    property OnUpdate;
  end;

{ TListActionLink }

  TListActionLink = class(TWinControlActionLink)
  protected
    function IsActiveLinked: Boolean; virtual;
    procedure SetActive(const Value: Boolean); virtual;
    function IsImagesLinked: Boolean; virtual;
    procedure SetAction(Value: TBasicAction); override;
    procedure SetImages(Value: TCustomImageList); virtual;
    procedure SetItemIndex(const Value: Integer); virtual;
    procedure AddItem(AnItem: TListControlItem); overload; virtual;
    procedure AddItem(ACaption: String; AImageIndex: Integer;
      DataPtr: Pointer); overload; virtual;
    procedure RefreshControl;
  end;

implementation

uses SysUtils, ComCtrls;

{ TListControlItem }

procedure TListControlItem.Assign(Source: TPersistent);
begin
  if Source is TListControlItem then
  begin
    if Assigned(Collection) then Collection.BeginUpdate;
    try
      Caption := TListControlItem(Source).Caption;
      ImageIndex := TListControlItem(Source).ImageIndex;
      Data := TListControlItem(Source).Data;
    finally
      if Assigned(Collection) then Collection.EndUpdate;
    end;
  end;
end;

procedure TListControlItem.Changed;
begin
  if Assigned(FListControlItems) then
    FListControlItems.Update(Self);
end;

constructor TListControlItem.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FImageIndex := -1;
end;

function TListControlItem.GetDisplayName: String;
begin
  if Length(Caption) > 0 then
    Result := Caption
  else
    Result := inherited GetDisplayName;
end;

procedure TListControlItem.SetCaption(const Value: String);
begin
  FCaption := Value;
  Changed;
end;

procedure TListControlItem.SetData(const Value: Pointer);
begin
  FData := Value;
  Changed;
end;

procedure TListControlItem.SetImageIndex(const Value: TImageIndex);
begin
  FImageIndex := Value;
  Changed;
end;

{ TListControlItems }

function ListItemsCompare(List: TListControlItems; Index1, Index2: Integer): Integer;
begin
  Result := List.CompareItems(List.Items[Index1], List.Items[Index2]);
end;

function TListControlItems.Add: TListControlItem;
begin
  Result := TListControlItem(inherited Add);
  Result.FListControlItems := Self;
end;

procedure TListControlItems.CustomSort(Compare: TListItemsCompare);
begin
  if (SortType <> stNone) and (Count > 1) then
    QuickSort(0, Count - 1, Compare);
end;

function TListControlItems.CompareItems(I1, I2: TListControlItem): Integer;
begin
  if Assigned(OnCompare) then
    Result := OnCompare(Self, I1, I2)
  else
    if CaseSensitive then
      Result := AnsiCompareStr(I1.Caption, I2.Caption)
    else
      Result := AnsiCompareText(I1.Caption, I2.Caption);
end;

procedure TListControlItems.ExchangeItems(Index1, Index2: Integer);
var
  Item1, Item2: TListControlItem;
  I1, I2: Integer;
begin
  Item1 := Items[Index1];
  Item2 := Items[Index2];
  I1 := Items[Index1].Index;
  I2 := Items[Index2].Index;
  Item1.Index := I2;
  Item2.Index := I1;
end;

procedure TListControlItems.QuickSort(L, R: Integer; SCompare: TListItemsCompare);
var
  I, J, P: Integer;
begin
  repeat
    I := L;
    J := R;
    P := (L + R) shr 1;
    repeat
      while SCompare(Self, I, P) < 0 do Inc(I);
      while SCompare(Self, J, P) > 0 do Dec(J);
      if I <= J then
      begin
        ExchangeItems(I, J);
        if P = I then
          P := J
        else if P = J then
          P := I;
        Inc(I);
        Dec(J);
      end;
    until I > J;
    if L < J then QuickSort(L, J, SCompare);
    L := I;
  until I >= R;
end;

function TListControlItems.GetListItem(
  const Index: Integer): TListControlItem;
begin
  Result := TListControlItem(GetItem(Index));
end;

procedure TListControlItems.SetSortType(const Value: TListItemsSortType);
begin
  if FSortType <> Value then
  begin
    FSortType := Value;
    if Value <> stNone then
      CustomSort(ListItemsCompare);
  end;
end;

procedure TListControlItems.Sort;
begin
  CustomSort(ListItemsCompare);
end;

{ TCustomListAction }

constructor TCustomListAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FItemIndex := -1;
  DisableIfNoHandler := False;
  Enabled := True;
  Active := True;
end;

procedure TCustomListAction.ExecuteTarget(Target: TObject);
var
  I: Integer;
begin
  if FInUpdate then exit;
  FInUpdate := True;
  try
    if Target is TCustomListControl then
    begin
      FItemIndex := TCustomListControl(Target).ItemIndex;
      for I := 0 to FClients.Count - 1 do
        if (TBasicActionLink(FClients[I]) is TListActionLink) and 
           (TListActionLink(FClients[I]).FClient <> Target) then
          with Target as TCustomListControl do
            TListActionLink(FClients[I]).SetItemIndex(ItemIndex);
    end;
    if Assigned(FOnItemSelected) then
      FOnItemSelected(Self, Target as TControl);
  finally
    FInUpdate := False;
  end;
end;

function TCustomListAction.GetCount: Integer;
begin
  Result := -1;
  if Assigned(FOnGetItemCount) then
    FOnGetItemCount(Self, Result);
end;

function TCustomListAction.GetString(Index: Integer): String;
begin
  Result := '';
end;

function TCustomListAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := True;
end;

procedure TCustomListAction.Loaded;
begin
  inherited Loaded;
  if FActivated then
    SetActive(FActivated);
  if Assigned(FLoadedImages) then
    SetImages(FLoadedImages);
end;

procedure TCustomListAction.SetActive(const Value: Boolean);
var
  I: Integer;
begin
  if Value and (csLoading in ComponentState) then
  begin
    FActivated := Value;
    exit;
  end;
  if FActive <> Value then
  begin
    FActive := Value;
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TListActionLink then
      begin
        FLoading := True;
        try
          TListActionLink(FClients[I]).SetActive(Value);
        finally
          FLoading := False;
        end;
      end;
    Change;
    if FItemIndex <> -1 then
      SetItemIndex(FItemIndex);
  end;
end;

procedure TCustomListAction.SetImages(const Value: TCustomImageList);
var
  I: Integer;
begin
  if Assigned(Value) and (csLoading in ComponentState) then
  begin
    FLoadedImages := Value;
    exit;
  end;
  if FImages <> Value then
  begin
    FImages := Value;
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TListActionLink then
        TListActionLink(FClients[I]).SetImages(Value);
  end;
end;

procedure TCustomListAction.SetItemIndex(const Value: Integer);
var
  I: Integer;
begin
  if not Active then exit;
  for I := 0 to FClients.Count - 1 do
    if TBasicActionLink(FClients[I]) is TListActionLink then
      TListActionLink(FClients[I]).SetItemIndex(Value);
  FItemIndex := Value;
end;

procedure TCustomListAction.SetString(Index: Integer; const Value: String);
begin
end;

{ TVirtualListAction }

function TVirtualListAction.GetItem(const Index: Integer; var Value: String;
  var ImageIndex: Integer; var Data: Pointer): Boolean;
begin
  Result := False;
  if Count <= 0 then exit;
  Result := Assigned(FOnGetItem);
  if Result then
    FOnGetItem(Self, Index, Value, ImageIndex, Data);
end;

{ TStaticListItems }

type
  TWinControlActionLinkType = class(TWinControlActionLink);
  TCustomListViewClass = class(TCustomListView);

procedure TStaticListItems.Notify(Item: TCollectionItem;
  Action: TCollectionNotification);
var
  I: Integer;
begin
  case Action of
    cnAdded:
      begin
        if not Assigned(FStaticListAction) or not FStaticListAction.Active then exit;
        for I := 0 to FStaticListAction.FClients.Count - 1 do
          with TWinControlActionLinkType(FStaticListAction.FClients[I]) do
          begin
            if FClient is TCustomComboBoxEx then
              with FClient as TCustomComboBoxEx do
                with ItemsEx.Add do
                begin
                  Caption := TListControlItem(Item). Caption;
                  ImageIndex := TListControlItem(Item).ImageIndex;
                  Data := TListControlItem(Item).Data;
                end
            else if FClient is TCustomListView then
              with TCustomListViewClass(FClient).Items.Add do
              begin
                Caption := TListControlItem(Item).Caption;
                ImageIndex := TListControlItem(Item).ImageIndex;
                Data := TListControlItem(Item).Data;
              end;
          end;
      end;
    cnDeleting:
      begin
        if not Assigned(FStaticListAction) or not FStaticListAction.Active then exit;
        for I := 0 to FStaticListAction.FClients.Count - 1 do
          with TWinControlActionLinkType(FStaticListAction.FClients[I]) do
          begin
            if FClient is TCustomComboBoxEx then
              TCustomComboBoxEx(FClient).Items.Delete(Item.Index)
            else if FClient is TCustomListView then
              TCustomListViewClass(FClient).Items.Delete(Item.Index);
          end;
      end;
  end;
end;

procedure TStaticListItems.Update(Item: TCollectionItem);
var
  I: Integer;
begin
  inherited Update(Item);
  if not Assigned(FStaticListAction) or not Assigned(Item) or
     not FStaticListAction.Active or FStaticListAction.Loading then exit;
  for I := 0 to FStaticListAction.FClients.Count - 1 do
    with TWinControlActionLinkType(FStaticListAction.FClients[I]) do
    begin
      if FClient is TCustomComboBoxEx then
        with FClient as TCustomComboBoxEx do
          with ItemsEx[Item.Index] do
          begin
            Caption := TListControlItem(Item). Caption;
            ImageIndex := TListControlItem(Item).ImageIndex;
            Data := TListControlItem(Item).Data;
          end
      else if FClient is TCustomListView then
        with TCustomListViewClass(FClient).Items[Item.Index] do
        begin
          Caption := TListControlItem(Item).Caption;
          ImageIndex := TListControlItem(Item).ImageIndex;
          Data := TListControlItem(Item).Data;
        end;
    end;
end;

{ TStaticListAction }

constructor TStaticListAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FListItems := TStaticListItems.Create(Self, GetItemClass);
  FListItems.FStaticListAction := Self;
end;

destructor TStaticListAction.Destroy;
begin
  FreeAndNil(FListItems);
  inherited Destroy;
end;

function TStaticListAction.GetCount: Integer;
begin
  Result := FListItems.Count;
end;

function TStaticListAction.GetItem(const Index: Integer; AnItem: TListControlItem): Boolean;
begin
  Result := (Index >= 0) and (Index < FListItems.Count);
  if not Result then exit;
  AnItem.Assign(FListItems[Index]);
  if Assigned(FOnGetItem) then
    FOnGetItem(Self, Index, AnItem);
end;

function TStaticListAction.GetItemClass: TListControlItemClass;
begin
  Result := TListControlItem;
end;

function TStaticListAction.GetString(Index: Integer): String;
begin
  Result := Items[Index].Caption;
end;

procedure TStaticListAction.SetListitems(const Value: TStaticListItems);
begin
  FListItems.Assign(Value);
end;

procedure TStaticListAction.SetString(Index: Integer; const Value: String);
begin
  Items[Index].Caption := Value;
end;

{ TListActionLink }

function TListActionLink.IsActiveLinked: Boolean;
begin
  Result := Action is TCustomListAction;
end;

function TListActionLink.IsImagesLinked: Boolean;
begin
  Result := Action is TCustomListAction and
    Assigned(TCustomListAction(Action).FImages);
end;

procedure TListActionLink.SetAction(Value: TBasicAction);
begin
  inherited SetAction(Value);
  if FClient is TCustomListControl then
    if FAction is TCustomListAction then
      if TCustomListAction(FAction).Active then
        RefreshControl;
end;

procedure TListActionLink.SetActive(const Value: Boolean);
begin
  if not Value then
  begin
    if (FClient is TCustomListControl) then
      TCustomListControl(FClient).Clear;
    exit;
  end;
  if Value and (FAction is TCustomListAction) and
     not TCustomListAction(FAction).Active then exit;
  if Action is TCustomListAction then
    RefreshControl;
end;

procedure TListActionLink.SetImages(Value: TCustomImageList);
begin
end;

procedure TListActionLink.RefreshControl;
var
  I: Integer;
  ACaption: String;
  AImageIndex: Integer;
  DataPtr: Pointer;
begin
  if not (Action is TCustomListAction) then exit;
  if FClient is TCustomListControl then
    TCustomListControl(FClient).Clear;
  if Action is TStaticListAction then
  begin
    with Action as TStaticListAction do
      for I := 0 to Count - 1 do
        if GetItem(I, Items[I]) then
          AddItem(Items[I]);
  end
  else
  if Action is TVirtualListAction then
    for I := 0 to TCustomListAction(Action).Count - 1 do
      with Action as TVirtualListAction do
        if GetItem(I, ACaption, AImageIndex, DataPtr) then
          AddItem(ACaption, AImageIndex, DataPtr);
end;

procedure TListActionLink.AddItem(AnItem: TListControlItem);
begin
end;

procedure TListActionLink.AddItem(ACaption: String; AImageIndex: Integer;
  DataPtr: Pointer);
begin
end;

procedure TListActionLink.SetItemIndex(const Value: Integer);
begin
  if FClient is TCustomListControl then
    with FClient as TCustomListControl do
      ItemIndex := Value;
end;

end.
