{*******************************************************}
{                                                       }
{       Borland Delphi Test Server                      }
{                                                       }
{  Copyright (c) 2001 Borland Software Corporation      }
{                                                       }
{*******************************************************}
unit SvrLogFrame;

interface

uses 
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ActnList, Menus, ComCtrls, SvrLogDetailFrame, SvrLog, Registry;

type

  TColumnInfo = record
    Visible: Boolean;
    Width: Integer;
    ColumnPosition: Integer;
    SubItemPosition: Integer;
    Caption: string;
  end;

  TLogColumnOrder = array[0..Ord(High(TLogColumn))] of TLogColumn;

  TLogFrame = class(TFrame)
    lvLog: TListView;
    PopupMenu2: TPopupMenu;
    ActionList1: TActionList;
    ClearAction: TAction;
    Clear1: TMenuItem;
    DetailAction: TAction;
    DetailAction1: TMenuItem;
    procedure ClearActionExecute(Sender: TObject);
    procedure ClearActionUpdate(Sender: TObject);
    procedure DetailActionExecute(Sender: TObject);
    procedure lvLogDblClick(Sender: TObject);
    procedure lvLogColumnClick(Sender: TObject; Column: TListColumn);
    procedure lvLogCompare(Sender: TObject; Item1, Item2: TListItem;
      Data: Integer; var Compare: Integer);
    procedure lvLogColumnDragged(Sender: TObject);
  private
    FShowingDetail: Boolean;
    FColumnToSort: Integer;
    FSortDescending: Boolean;
    FSorted: Boolean;
    FColumnInfo: array[TLogColumn] of TColumnInfo;
    FLogMax: Integer;
    FLogDelete: Integer;
    function GetCount: Integer;
    function GetIndex: Integer;
    function GetCurrent: TTransactionLogEntry;
    procedure ConstrainLog;
    function GetColumnVisible(I: TLogColumn): Boolean;
    function GetColumnWidth(I: TLogColumn): Integer;
    procedure SetColumnVisible(I: TLogColumn; const Value: Boolean);
    procedure SetColumnWidth(I: TLogColumn; const Value: Integer);
    function GetColumnCaption(I: TLogColumn): string;
    function GetColumnPosition(I: TLogColumn): Integer;
    procedure SetColumnPosition(I: TLogColumn; const Value: Integer);
     function GetSubItemPosition(I: TLogColumn): Integer;
    procedure SetSubItemPosition(I: TLogColumn; const Value: Integer);
    function GetColumn(ALogColumn: TLogColumn): TListColumn;
    procedure SetCurrent(AItem: TListItem);
    function GetItemCount: Integer;
    procedure SetLogDelete(const Value: Integer);
    procedure SetLogMax(const Value: Integer);
    { Private declarations }
  public
    { Public declarations }
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure SynchColumnInfo;
    procedure Add(Transaction: TTransactionLogEntry);
    procedure Next;
    procedure Previous;
    procedure Clear;
    property Count: Integer read GetCount;
    procedure ShowDetail(Details: TLogDetailFrame);
    procedure RefreshColumns;
    procedure RefreshSubItems;
    procedure Save(Reg: TRegIniFile; const Section: string);
    procedure Load(Reg: TRegIniFile; const Section: string);
    procedure GetSubItemOrder(var Positions: TLogColumnOrder);
    procedure GetColumnOrder(var Positions: TLogColumnOrder);
    property Index: Integer read GetIndex;
    property Current: TTransactionLogEntry read GetCurrent;
    property LogMax: Integer read FLogMax write SetLogMax;
    property LogDelete: Integer read FLogDelete write SetLogDelete;
    property ColumnCaption[I: TLogColumn]: string read GetColumnCaption;
    property ColumnWidth[I: TLogColumn]: Integer read GetColumnWidth write SetColumnWidth;
    property ColumnVisible[I: TLogColumn]: Boolean read GetColumnVisible write SetColumnVisible;
    property ColumnPosition[I: TLogColumn]: Integer read GetColumnPosition write SetColumnPosition;
    property SubItemPosition[I: TLogColumn]: Integer read GetSubItemPosition write SetSubItemPosition;
    property Columns[I: TLogColumn]: TListColumn read GetColumn;
    property ItemCount: Integer read GetItemCount;
  end;

implementation

uses SvrLogDetailDlg, SvrConst;

{$R *.dfm}

const
  LogColumnCaptions: array[TLogColumn] of string =
    (sEvent, sTime, sDate, sElapsed, sPath, sCode, sContentLength, sContentType, sThread);
  DefaultColumnPositions: array[TLogColumn] of Integer =
    (1, 2, 3, 4, 5, 6, 7, 8, 0);
  DefaultColumnVisible: array[TLogColumn] of Boolean =
    (True, True, False, True, True, True, True, True, True);
  DefaultColumnWidth: array[TLogColumn] of Integer =
    (50, 50, 50, 50, 50, 50, 50, 50, 50);

procedure TLogFrame.Add(Transaction: TTransactionLogEntry);
var
  Item: TListItem;
  I: Integer;
  LogColumn: TLogColumn;
  Positions: TLogColumnOrder;
  HaveCaption: Boolean;
begin
  GetSubItemOrder(Positions);
  Item := lvLog.Items.Add;
  Item.Data := Transaction;
  HaveCaption := False;
  for I := Low(Positions) to High(Positions) do
  begin
    LogColumn := Positions[I];
    if ColumnVisible[LogColumn] then
    begin
      if HaveCaption then
        Item.SubItems.Add(Transaction.Columns[LogColumn])
      else
      begin
        Item.Caption := Transaction.Columns[LogColumn];
        HaveCaption := True;
      end;
    end;
  end;
  ConstrainLog;
  if not FShowingDetail then
    SetCurrent(Item);
  FSorted := False;
end;

procedure TLogFrame.RefreshSubItems;
var
  Item: TListItem;
  I, J: Integer;
  LogColumn: TLogColumn;
  Positions: TLogColumnOrder;
  HaveCaption: Boolean;
  Transaction: TTransactionLogEntry;
  Count: Integer;
begin
  GetSubItemOrder(Positions);
  lvLog.Items.BeginUpdate;
  try
    for I := 0 to lvLog.Items.Count - 1 do
    begin
      Item := lvLog.Items[I];
      Transaction := TTransactionLogEntry(Item.Data);
      HaveCaption := False;
      Count := 0;
      for J := Low(Positions) to High(Positions) do
      begin
        LogColumn := Positions[J];
        if ColumnVisible[LogColumn] then
        begin
          if HaveCaption then
          begin
            if Count >= Item.SubItems.Count then
              Item.SubItems.Add(Transaction.Columns[LogColumn])
            else
              Item.SubItems[Count] := Transaction.Columns[LogColumn];
            Inc(Count);
          end
          else
          begin
            Item.Caption := Transaction.Columns[LogColumn];
            HaveCaption := True;
          end;
        end;
      end;
    end;
  finally
    lvLog.Items.EndUpdate;
  end;
end;

procedure TLogFrame.Clear;
var
  I: Integer;
begin
  for I := 0 to lvLog.Items.Count - 1 do
    if Assigned(lvLog.Items[I].Data) then
      TObject(lvLog.Items[I].Data).Free;
  lvLog.Items.Clear;
  FSorted := False;
end;

procedure TLogFrame.ClearActionExecute(Sender: TObject);
begin
  Clear;
end;

procedure TLogFrame.ClearActionUpdate(Sender: TObject);
begin
  (Sender as TAction).Enabled := lvLog.Items.Count > 0;
end;

function TLogFrame.GetCount: Integer;
begin
  Result := lvLog.Items.Count;
end;

function TLogFrame.GetIndex: Integer;
var
  Item: TListItem;
begin
  Item := lvLog.GetNextItem(nil, sdAll, [isSelected]);
  if Assigned(Item) then
    Result := Item.Index
  else
    Result := -1;
end;

procedure TLogFrame.Next;
var
  Item: TListItem;
begin
  Item := lvLog.GetNextItem(nil, sdAll, [isSelected]);
  if Assigned(Item) then
  begin
    Item := lvLog.GetNextItem(Item, sdBelow, []);
    if Assigned(Item) then
      SetCurrent(Item);
  end;
end;

procedure TLogFrame.SetCurrent(AItem: TListItem);
begin
  if Assigned(AItem) then
  begin
    lvLog.Selected := AItem;
    AItem.MakeVisible(False);
  end
  else
    lvLog.Selected := nil;
end;

procedure TLogFrame.Previous;
var
  Item: TListItem;
begin
  Item := lvLog.GetNextItem(nil, sdAll, [isSelected]);
  if Assigned(Item) then
    SetCurrent(lvLog.GetNextItem(Item, sdAbove, []));
end;

procedure TLogFrame.DetailActionExecute(Sender: TObject);
begin
  with FLogDetail do
  try
    FShowingDetail := True;
    ShowModal;
  finally
    FShowingDetail := False;
  end;
end;

procedure TLogFrame.ShowDetail(Details: TLogDetailFrame);
var
  Entry: TTransactionLogEntry;
begin
  Entry := Current;
  if Assigned(Current) then
  begin
    Details.Text := Entry.LogString;
  end
  else
  begin
    Details.Clear;
  end;
end;

destructor TLogFrame.Destroy;
begin
  Clear;
  FreeAndNil(FLogDetail);
  inherited;
end;

function TLogFrame.GetCurrent: TTransactionLogEntry;
var
  Item: TListItem;
begin
  Item := lvLog.GetNextItem(nil, sdAll, [isSelected]);
  if Assigned(Item) then
    Result := TObject(Item.Data) as TTransactionLogEntry
  else
    Result := nil;
end;

constructor TLogFrame.Create(AOwner: TComponent);
var
  I: TLogColumn;
begin
  inherited;
  FLogDetail := TLogDetail.Create(Self);
  FLogDetail.LogFrame := Self;
  for I := Low(TLogColumn) to High(TLogColumn) do
  begin
    FColumnInfo[I].Width := DefaultColumnWidth[I];
    FColumnInfo[I].Visible := DefaultColumnVisible[I];
    FColumnInfo[I].Caption := LogColumnCaptions[I];
    FColumnInfo[I].ColumnPosition := DefaultColumnPositions[I];
    FColumnInfo[I].SubItemPosition := DefaultColumnPositions[I];
  end;
  RefreshColumns;
end;


procedure TLogFrame.RefreshColumns;
var
  I: Integer;
  LogColumn: TLogColumn;
  Column: TListColumn;
  Positions: TLogColumnOrder;
  Count: Integer;
begin
  lvLog.Columns.BeginUpdate;
  try
    lvLog.Columns.Clear;
    GetColumnOrder(Positions);
    Count := 0;
    for I := Low(Positions) to High(Positions) do
    begin
      LogColumn := Positions[I];
      if FColumnInfo[LogColumn].Visible then
      begin
        FColumnInfo[LogColumn].SubItemPosition := Count;
        Column := lvLog.Columns.Add;
        Column.Caption := FColumnInfo[LogColumn].Caption;
        Column.Width := FColumnInfo[LogColumn].Width;
        Column.Tag := Integer(LogColumn);
        Inc(Count);
      end
      else
        FColumnInfo[LogColumn].SubItemPosition := High(Positions);
    end;
  finally
    lvLog.Columns.EndUpdate;
  end;
end;

procedure TLogFrame.ConstrainLog;
var
  DeleteCount: Integer;
begin
  if LogMax > 0 then
    if lvLog.Items.Count > LogMax then
    begin
      if LogDelete > 0 then
        DeleteCount := LogDelete
      else
        DeleteCount := 1;
      while (lvLog.Items.Count > 0) and (DeleteCount > 0) do
      begin
        lvLog.Items.Delete(0);
        Dec(DeleteCount);
      end;
    end;
end;

procedure TLogFrame.SetLogMax(const Value: Integer);
begin
  FLogMax := Value;
  ConstrainLog;
end;

procedure TLogFrame.lvLogDblClick(Sender: TObject);
begin
  DetailActionExecute(Self);
end;

procedure TLogFrame.lvLogColumnClick(Sender: TObject; Column: TListColumn);
begin
  if FSorted and (FColumnToSort = Column.Index) then
    FSortDescending := not FSortDescending
  else
    FSortDescending := False;
  FColumnToSort := Column.Index;
    (Sender as TCustomListView).AlphaSort;
  FSorted := True;
end;


procedure TLogFrame.lvLogCompare(Sender: TObject; Item1, Item2: TListItem; Data: Integer; var Compare: Integer);

  function SortOnKey(AKey: TLogColumn): Integer;
  var
    Transaction1, Transaction2: TTransactionLogEntry;
  begin
    Result := 0;
    if FColumnToSort <> FColumnInfo[AKey].SubItemPosition then
    begin
      Transaction1 := TTransactionLogEntry(Item1.Data);
      Transaction2 := TTransactionLogEntry(Item2.Data);
      Result := AnsiCompareText(Transaction1.Columns[AKey],
        Transaction2.Columns[AKey]);
    end;
  end;
var
  I: Integer;
begin
  if FColumnToSort = 0 then
    Compare := CompareText(Item1.Caption,Item2.Caption)
  else
  begin
    I := FColumnToSort - 1;
    Compare := AnsiCompareText(Item1.SubItems[I],Item2.SubItems[I]);
  end;
  if Compare = 0 then
  begin
    Compare := SortOnKey(lcThreadID);
    if Compare = 0 then
      Compare := SortOnKey(lcTime);
  end;
  if FSortDescending then
    Compare := -Compare;

end;

procedure TLogFrame.lvLogColumnDragged(Sender: TObject);
begin
 // SynchColumnInfo;
end;

function TLogFrame.GetColumnVisible(I: TLogColumn): Boolean;
begin
  Result := FColumnInfo[I].Visible;
end;

function TLogFrame.GetColumnWidth(I: TLogColumn): Integer;
begin
  Result := FColumnInfo[I].Width;

end;

procedure TLogFrame.SetColumnVisible(I: TLogColumn; const Value: Boolean);
begin
  FColumnInfo[I].Visible := Value;

end;

procedure TLogFrame.SetColumnWidth(I: TLogColumn; const Value: Integer);
begin
  FColumnInfo[I].Width := Value;

end;

function TLogFrame.GetColumnCaption(I: TLogColumn): string;
begin
  Result := FColumnInfo[I].Caption;
end;

const
  LogColumnID: array[TLogColumn] of string =
   ('Event', 'Time', 'Date', 'Elapsed', 'Path', 'Code', 'Content_Length',   // Do not localize
    'Content_Type', 'Thread');   // Do not localize
  sWidth = 'Width';           // Do not localize
  sVisible = 'Visible';       // Do not localize
  sPosition = 'Position';     // Do not localize
  sDetails = 'Details';       // Do not localize

procedure TLogFrame.Load(Reg: TRegIniFile; const Section: string);
var
  I: TLogColumn;
  SubSection: string;
  LastPath: string;
begin
  FLogDetail.Load(Reg, sDetails);
  LastPath := Reg.CurrentPath;
  Reg.OpenKey(Section, True);
  try
    for I := Low(TLogColumn) to High(TLogColumn) do
      begin
        SubSection := LogColumnID[I];
        ColumnVisible[I] := Reg.ReadBool(SubSection, sVisible, ColumnVisible[I]);
        ColumnWidth[I] := Reg.ReadInteger(SubSection, sWidth, ColumnWidth[I]);
        ColumnPosition[I] := Reg.ReadInteger(SubSection, sPosition, ColumnPosition[I]);
      end;
  finally
    Reg.OpenKey('\' + LastPath, True);
  end;
  RefreshColumns;
end;

procedure TLogFrame.Save(Reg: TRegIniFile; const Section: string);
var
  I: TLogColumn;
  SubSection: string;
  LastPath: string;
begin
  FLogDetail.Save(Reg, sDetails);
  SynchColumnInfo;
  LastPath := Reg.CurrentPath;
  Reg.OpenKey(Section, True);
  try
    for I := Low(TLogColumn) to High(TLogColumn) do
      begin
        SubSection := LogColumnID[I];
        Reg.WriteBool(SubSection, sVisible, ColumnVisible[I]);
        Reg.WriteInteger(SubSection, sWidth, ColumnWidth[I]);
        Reg.WriteInteger(SubSection, sPosition, ColumnPosition[I]);
      end;
  finally
    Reg.OpenKey('\' + LastPath, True);
  end;
end;

procedure TLogFrame.SynchColumnInfo;
var
  I, J: Integer;
  LogColumn: TLogColumn;
  Positions: TLogColumnOrder;
begin
  for I := 0 to High(Positions) do
    Positions[I] := TLogColumn(-1);
  for LogColumn := Low(TLogColumn) to High(TLogColumn) do
    if not FColumnInfo[LogColumn].Visible then
      Positions[FColumnInfo[LogColumn].ColumnPosition] := LogColumn;

  for I := 0 to lvLog.Columns.Count - 1 do
  begin
    LogColumn := TLogColumn(lvLog.Columns[I].Tag);
    FColumnInfo[LogColumn].Width := lvLog.Columns[I].Width;
    for J := I to High(Positions) do
      if Positions[J] = TLogColumn(-1) then
      begin
        FColumnInfo[LogColumn].ColumnPosition := J;
        Positions[J] := LogColumn;
        break;
      end;
  end;
end;

function TLogFrame.GetColumnPosition(I: TLogColumn): Integer;
begin
  Result := FColumnInfo[I].ColumnPosition;
end;

procedure TLogFrame.SetColumnPosition(I: TLogColumn; const Value: Integer);
begin
  FColumnInfo[I].ColumnPosition := Value;
end;

procedure TLogFrame.GetColumnOrder(var Positions: TLogColumnOrder);
var
  LogColumn: TLogColumn;
begin
  for LogColumn := Low(TLogColumn) to High(TLogColumn) do
    Positions[FColumnInfo[LogColumn].ColumnPosition] := LogColumn;
end;

procedure TLogFrame.GetSubItemOrder(var Positions: TLogColumnOrder);
var
  LogColumn: TLogColumn;
begin
  for LogColumn := Low(TLogColumn) to High(TLogColumn) do
    Positions[FColumnInfo[LogColumn].SubItemPosition] := LogColumn;
end;

function TLogFrame.GetSubItemPosition(I: TLogColumn): Integer;
begin
  Result := FColumnInfo[I].SubItemPosition;

end;

procedure TLogFrame.SetSubItemPosition(I: TLogColumn;
  const Value: Integer);
begin
  FColumnInfo[I].SubItemPosition := Value;
end;

function TLogFrame.GetColumn(ALogColumn: TLogColumn): TListColumn;
var
  I: Integer;
begin
  for I := 0 to lvLog.Columns.Count - 1 do
  begin
    Result := lvLog.Columns[I];
    if TLogColumn(Result.Tag) = ALogColumn then Exit;
  end;
  Result := nil;
end;

function TLogFrame.GetItemCount: Integer;
begin
  Result := lvLog.Items.Count;
end;

procedure TLogFrame.SetLogDelete(const Value: Integer);
begin
  FLogDelete := Value;
end;

end.
