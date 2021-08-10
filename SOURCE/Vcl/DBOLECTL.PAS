
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit DbOleCtl;

interface

uses Windows, Messages, SysUtils, Classes, Controls, Forms, OleCtrls, Db,
  DbCtrls, ActiveX;

type
  TDBOleControl = class;
  TDataBindings = class;

  TDataBindItem = class(TCollectionItem)
  private
    FOwner: TDataBindings;
    FDataLink: TFieldDataLink;
    FDispId: TDispID;
    procedure DataChange(Sender: TObject);
    function GetDataField: string;
    procedure SetDataField(const Value: string);
    procedure SetDispID(Value: TDispID);
    procedure UpdateData(Sender: TObject);
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
  published
    property DataField: string read GetDataField write SetDataField;
    property DispID: TDispID read FDispId write SetDispID;
  end;

  TDataBindings = class(TCollection)
  private
    FDBOleControl: TDBOleControl;
    function GetItem(Index: Integer): TDataBindItem;
    procedure SetItem(Index: Integer; Value: TDataBindItem);
  public
    constructor Create(DBOleControl: TDBOleControl);
    function Add: TDataBindItem;
    procedure Update(Item: TCollectionItem); override;
    function GetItemByDispID(ADispID: TDispID): TDataBindItem;
    function GetOwner: TPersistent; override;
    property Items[Index: Integer]: TDataBindItem read GetItem write SetItem; default;
  end;

  TDBOleControl = class(TOleControl)
  private
    FDataBindings: TDataBindings;
    FDataChanging: Boolean;
    FDataSource: TDataSource;
    procedure SetDataSource(Value: TDataSource);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    function OnChanged(dispid: TDispID): HResult; override;
    function OnRequestEdit(dispid: TDispID): HResult; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property DataSource: TDataSource read FDataSource write SetDataSource;
    property DataBindings: TDataBindings read FDataBindings write FDataBindings;
 end;

implementation

{ TDataBindItem }

constructor TDataBindItem.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FOwner := Collection as TDataBindings;
  FDataLink := TFieldDataLink.Create;
  FDataLink.Control := FOwner.FDbOleControl;
  FDataLink.OnDataChange := DataChange;
  FDataLink.OnUpdateData := UpdateData;
end;

procedure TDataBindItem.DataChange(Sender: TObject);
var
  LocalVar: OleVariant;
begin
  with FOwner.FDbOleControl do
  begin
    FDataChanging := True;
    try
      LocalVar := FDataLink.Field.Value;
      if LocalVar <> Null then
        SetProperty(FDispID, TVarData(LocalVar));
    finally
      FDataChanging := False;
    end;
  end;
end;

destructor TDataBindItem.Destroy;
begin
  FDataLink.Free;
  FDataLink := nil;
  inherited Destroy;
end;

function TDataBindItem.GetDataField: string;
begin
  Result := FDataLink.FieldName;
end;

procedure TDataBindItem.SetDataField(const Value: string);
begin
  FDataLink.FieldName := Value;
  Changed(False);
end;

procedure TDataBindItem.SetDispID(Value: TDispID);
begin
  if Value <> FDispID then
  begin
    FDispID := Value;
    Changed(False);
  end;
end;

procedure TDataBindItem.UpdateData(Sender: TObject);
var
  PropValue: OleVariant;
begin
  FOwner.FDbOleControl.GetProperty(FDispID, TVarData(PropValue));
  FDataLink.Field.Value := PropValue;
end;

{ TDataBindings }

constructor TDataBindings.Create(DBOleControl: TDBOleControl);
begin
  inherited Create(TDataBindItem);
  FDBOleControl:= DBOleControl;
end;

function TDataBindings.Add: TDataBindItem;
begin
  Result:= TDataBindItem(inherited Add);
end;

function TDataBindings.GetItem(index: integer): TDataBindItem;
begin
  Result:= TDataBindItem(inherited GetItem(Index));
end;

function TDataBindings.GetItemByDispID(ADispID: TDispID): TDataBindItem;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
    if Items[I].DispID = ADispID then Result := Items[I];
end;

function TDataBindings.GetOwner: TPersistent;
begin
  Result:=  FDBOleControl;
end;

procedure TDataBindings.SetItem(index: integer; Value: TDataBindItem);
begin
  inherited SetItem(Index, Value);
end;

procedure TDataBindings.Update(Item: TCollectionItem);
begin

end;

{ TDBOleControl }

constructor TDBOleControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDataBindings:= TDataBindings.Create(self);
end;

destructor TDBOleControl.Destroy;
begin
  FDataBindings.Free;
  inherited Destroy;
end;

procedure TDBOleControl.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (FDataSource <> nil) and
    (AComponent = DataSource) then DataSource := nil;
end;

function TDBOleControl.OnChanged(DispID: TDispID): HResult;
var
  Item: TDataBindItem;
  I: Integer;

  procedure SetItemValue;
  var
    PropValue: OleVariant;
  begin
    if Item <> nil then
    begin
      GetProperty(Item.DispID, TVarData(PropValue));
      if (Item.FDatalink <> nil) and (Item.FDatalink.Field <> nil) then
      begin
        Item.FDataLink.Edit;
        Item.FDataLink.Field.Value := PropValue;
      end;
    end;
  end;

begin
  Result := S_OK;
  try
    if (not FDataChanging) and ([csLoading, csReading] * ComponentState = []) then
    begin
      if DispID = DISPID_UNKNOWN then
      begin
        for I := 0 to DataBindings.Count - 1 do
        begin
          Item := DataBindings[I];
          SetItemValue;
        end;
      end
      else begin
        Item := DataBindings.GetItemByDispID(DispID);
        SetItemValue;
      end;
    end;
  except
    // Return S_OK even in case of error
  end;
end;

function TDBOleControl.OnRequestEdit(DispID: TDispID): HResult;
var
  Item: TDataBindItem;
begin
  Result := S_OK;
  try
    if not FDataChanging then
    begin
      Item := DataBindings.GetItemByDispID(DispID);
      if (Item <> nil) and not Item.FDataLink.CanModify then
        Result := S_FALSE;
    end;
  except
    Result := S_FALSE;  // Disallow edit if exception was raised
  end;
end;

procedure TDBOleControl.SetDataSource(Value: TDataSource);
var
  I: Integer;
begin
  if csLoading in ComponentState then
    for I := 0 to DataBindings.Count - 1 do
      if DataBindings[I].FDataLink.DataSourceFixed then Exit;
  if Value = nil then DataBindings.Clear;
  FDataSource := Value;
  if Value <> nil then
  begin
    for I := 0 to DataBindings.Count - 1 do
      DataBindings[I].FDataLink.DataSource := Value;
    Value.FreeNotification(Self);
  end;
end;

end.
