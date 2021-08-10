{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Contnrs;

interface

uses
  SysUtils, Classes;

type

{ TObjectList class }

  TObjectList = class(TList)
  private
    FOwnsObjects: Boolean;
  protected
    procedure Notify(Ptr: Pointer; Action: TListNotification); override;
    function GetItem(Index: Integer): TObject;
    procedure SetItem(Index: Integer; AObject: TObject);
  public
    constructor Create; overload;
    constructor Create(AOwnsObjects: Boolean); overload;

    function Add(AObject: TObject): Integer;
    function Remove(AObject: TObject): Integer;
    function IndexOf(AObject: TObject): Integer;
    function FindInstanceOf(AClass: TClass; AExact: Boolean = True; AStartAt: Integer = 0): Integer;
    procedure Insert(Index: Integer; AObject: TObject);
    property OwnsObjects: Boolean read FOwnsObjects write FOwnsObjects;
    property Items[Index: Integer]: TObject read GetItem write SetItem; default;
  end;

{ TComponentList class }

  TComponentList = class(TObjectList)
  private
    FNexus: TComponent;
  protected
    procedure Notify(Ptr: Pointer; Action: TListNotification); override;
    function GetItems(Index: Integer): TComponent;
    procedure SetItems(Index: Integer; AComponent: TComponent);
    procedure HandleFreeNotify(Sender: TObject; AComponent: TComponent);
  public
    destructor Destroy; override;

    function Add(AComponent: TComponent): Integer;
    function Remove(AComponent: TComponent): Integer;
    function IndexOf(AComponent: TComponent): Integer;
    procedure Insert(Index: Integer; AComponent: TComponent);
    property Items[Index: Integer]: TComponent read GetItems write SetItems; default;
  end;

{ TClassList class }

  TClassList = class(TList)
  protected
    function GetItems(Index: Integer): TClass;
    procedure SetItems(Index: Integer; AClass: TClass);
  public
    function Add(aClass: TClass): Integer;
    function Remove(aClass: TClass): Integer;
    function IndexOf(aClass: TClass): Integer;
    procedure Insert(Index: Integer; aClass: TClass);
    property Items[Index: Integer]: TClass read GetItems write SetItems; default;
  end;

{ TOrdered class }

  TOrderedList = class(TObject)
  private
    FList: TList;
  protected
    procedure PushItem(AItem: Pointer); virtual; abstract;
    function PopItem: Pointer; virtual;
    function PeekItem: Pointer; virtual;
    property List: TList read FList;
  public
    constructor Create;
    destructor Destroy; override;

    function Count: Integer;
    function AtLeast(ACount: Integer): Boolean;
    procedure Push(AItem: Pointer);
    function Pop: Pointer;
    function Peek: Pointer;
  end;

{ TStack class }

  TStack = class(TOrderedList)
  protected
    procedure PushItem(AItem: Pointer); override;
  end;

{ TObjectStack class }

  TObjectStack = class(TStack)
  public
    procedure Push(AObject: TObject);
    function Pop: TObject;
    function Peek: TObject;
  end;

{ TQueue class }

  TQueue = class(TOrderedList)
  protected
    procedure PushItem(AItem: Pointer); override;
  end;

{ TObjectQueue class }

  TObjectQueue = class(TQueue)
  public
    procedure Push(AObject: TObject);
    function Pop: TObject;
    function Peek: TObject;
  end;

implementation

{ TObjectList }

function TObjectList.Add(AObject: TObject): Integer;
begin
  Result := inherited Add(AObject);
end;

constructor TObjectList.Create;
begin
  inherited Create;
  FOwnsObjects := True;
end;

constructor TObjectList.Create(AOwnsObjects: Boolean);
begin
  inherited Create;
  FOwnsObjects := AOwnsObjects;
end;

function TObjectList.FindInstanceOf(AClass: TClass; AExact: Boolean;
  AStartAt: Integer): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := AStartAt to Count - 1 do
    if (AExact and
        (Items[I].ClassType = AClass)) or
       (not AExact and
        Items[I].InheritsFrom(AClass)) then
    begin
      Result := I;
      break;
    end;
end;

function TObjectList.GetItem(Index: Integer): TObject;
begin
  Result := inherited Items[Index];
end;

function TObjectList.IndexOf(AObject: TObject): Integer;
begin
  Result := inherited IndexOf(AObject);
end;

procedure TObjectList.Insert(Index: Integer; AObject: TObject);
begin
  inherited Insert(Index, AObject);
end;

procedure TObjectList.Notify(Ptr: Pointer; Action: TListNotification);
begin
  if OwnsObjects then
    if Action = lnDeleted then
      TObject(Ptr).Free;
  inherited Notify(Ptr, Action);
end;

function TObjectList.Remove(AObject: TObject): Integer;
begin
  Result := inherited Remove(AObject);
end;

procedure TObjectList.SetItem(Index: Integer; AObject: TObject);
begin
  inherited Items[Index] := AObject;
end;


{ TComponentListNexus }
{ used by TComponentList to get free notification }

type
  TComponentListNexusEvent = procedure(Sender: TObject; AComponent: TComponent) of object;
  TComponentListNexus = class(TComponent)
  private
    FOnFreeNotify: TComponentListNexusEvent;
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    property OnFreeNotify: TComponentListNexusEvent read FOnFreeNotify write FOnFreeNotify;
  end;

{ TComponentListNexus }

procedure TComponentListNexus.Notification(AComponent: TComponent; Operation: TOperation);
begin
  if (Operation = opRemove) and Assigned(FOnFreeNotify) then
    FOnFreeNotify(Self, AComponent);
  inherited Notification(AComponent, Operation);
end;

{ TComponentList }

function TComponentList.Add(AComponent: TComponent): Integer;
begin
  Result := inherited Add(AComponent);
end;

destructor TComponentList.Destroy;
begin
  FNexus.Free;
  inherited Destroy;
end;

function TComponentList.GetItems(Index: Integer): TComponent;
begin
  Result := TComponent(inherited Items[Index]);
end;

procedure TComponentList.HandleFreeNotify(Sender: TObject; AComponent: TComponent);
begin
  Extract(AComponent);
end;

function TComponentList.IndexOf(AComponent: TComponent): Integer;
begin
  Result := inherited IndexOf(AComponent);
end;

procedure TComponentList.Insert(Index: Integer; AComponent: TComponent);
begin
  inherited Insert(Index, AComponent);
end;

procedure TComponentList.Notify(Ptr: Pointer; Action: TListNotification);
begin
  if not Assigned(FNexus) then
  begin
    FNexus := TComponentListNexus.Create(nil);
    TComponentListNexus(FNexus).OnFreeNotify := HandleFreeNotify;
  end;
  case Action of
    lnAdded:
      if Ptr <> nil then
        TComponent(Ptr).FreeNotification(FNexus);
    lnExtracted,
    lnDeleted:
      if Ptr <> nil then
        TComponent(Ptr).RemoveFreeNotification(FNexus);
  end;
  inherited Notify(Ptr, Action);
end;

function TComponentList.Remove(AComponent: TComponent): Integer;
begin
  Result := inherited Remove(AComponent);
end;

procedure TComponentList.SetItems(Index: Integer; AComponent: TComponent);
begin
  inherited Items[Index] := AComponent;
end;

{ TClassList }

function TClassList.Add(AClass: TClass): Integer;
begin
  Result := inherited Add(AClass);
end;

function TClassList.GetItems(Index: Integer): TClass;
begin
  Result := TClass(inherited Items[Index]);
end;

function TClassList.IndexOf(AClass: TClass): Integer;
begin
  Result := inherited IndexOf(AClass);
end;

procedure TClassList.Insert(Index: Integer; AClass: TClass);
begin
  inherited Insert(Index, AClass);
end;

function TClassList.Remove(AClass: TClass): Integer;
begin
  Result := inherited Remove(AClass);
end;

procedure TClassList.SetItems(Index: Integer; AClass: TClass);
begin
  inherited Items[Index] := AClass;
end;

{ TOrderedList }

function TOrderedList.AtLeast(ACount: integer): boolean;
begin
  Result := List.Count >= ACount;
end;

function TOrderedList.Peek: Pointer;
begin
  Result := PeekItem;
end;

function TOrderedList.Pop: Pointer;
begin
  Result := PopItem;
end;

procedure TOrderedList.Push(AItem: Pointer);
begin
  PushItem(AItem);
end;

function TOrderedList.Count: Integer;
begin
  Result := List.Count;
end;

constructor TOrderedList.Create;
begin
  inherited Create;
  FList := TList.Create;
end;

destructor TOrderedList.Destroy;
begin
  List.Free;
  inherited Destroy;
end;

function TOrderedList.PeekItem: Pointer;
begin
  Result := List[List.Count-1];
end;

function TOrderedList.PopItem: Pointer;
begin
  Result := PeekItem;
  List.Delete(List.Count-1);
end;

{ TStack }

procedure TStack.PushItem(AItem: Pointer);
begin
  List.Add(AItem);
end;

{ TObjectStack }

function TObjectStack.Peek: TObject;
begin
  Result := TObject(inherited Peek);
end;

function TObjectStack.Pop: TObject;
begin
  Result := TObject(inherited Pop);
end;

procedure TObjectStack.Push(AObject: TObject);
begin
  inherited Push(AObject);
end;

{ TQueue }

procedure TQueue.PushItem(AItem: Pointer);
begin
  List.Insert(0, AItem);
end;

{ TObjectQueue }

function TObjectQueue.Peek: TObject;
begin
  Result := TObject(inherited Peek);
end;

function TObjectQueue.Pop: TObject;
begin
  Result := TObject(inherited Pop);
end;

procedure TObjectQueue.Push(AObject: TObject);
begin
  inherited Push(AObject);
end;

end.
