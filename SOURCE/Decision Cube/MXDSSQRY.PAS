{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxdssqry;

interface

uses
 Windows, Messages, SysUtils, Classes, Dialogs, Controls, StdCtrls, Graphics,
 DB, dbtables, Grids, forms, ExtCtrls, Buttons, ComCtrls, Menus,
 mxConsts, mxgrid, mxdb, mxcommon, mxstore, mxtables, mxqparse;

type
  ECubeDesignError = class(Exception);
  EAddWarning = class(Exception);
  EAddError = class(Exception);

  TDSSQueryEditor = class(TForm)
    FieldList: TListBox;
    ActiveDimList: TListBox;
    SummaryList: TListBox;
    Label2: TLabel;
    Label3: TLabel;
    ShowBox: TMemo;
    AggPopup: TPopupMenu;
    Cancel: TBitBtn;
    CancelQryMod: TButton;
    count1: TMenuItem;
    count2: TMenuItem;
    EditQry: TButton;
    VQB: TButton;
    SelectAllFields: TButton;
    Label4: TLabel;
    OKButton: TButton;
    average1: TMenuItem;
    HelpButton: TButton;
    Pager: TPageControl;
    Dimensions: TTabSheet;
    Query: TTabSheet;
    Label1: TLabel;
    TableCombo: TComboBox;
    DatabaseCombo: TComboBox;
    Label5: TLabel;
    Label6: TLabel;
    AddButton: TBitBtn;
    AddAgg: TBitBtn;
    RemoveButton: TBitBtn;
    RemoveAgg: TBitBtn;
    Label7: TLabel;
    CountStarAvg: TCheckBox;
    procedure AddButtonClick(Sender: TObject);
    procedure RemoveButtonClick(Sender: TObject);
    procedure FieldListClick(Sender: TObject);
    procedure ActiveDimListClick(Sender: TObject);
    procedure SummaryListClick(Sender: TObject);
    procedure AddAggClick(Sender: TObject);
    procedure RemoveAggClick(Sender: TObject);
    procedure Sum1Click(Sender: TObject);
    procedure Count1Click(Sender: TObject);
    procedure OKButtonClick(Sender: TObject);
    procedure CancelQryModClick(Sender: TObject);
    procedure ShowBoxChange(Sender: TObject);
    procedure EditQryClick(Sender: TObject);
    procedure VQBClick(Sender: TObject);
    procedure SelectAllFieldsClick(Sender: TObject);
    procedure FieldListDblClick(Sender: TObject);
    procedure average1Click(Sender: TObject);
    procedure ActiveDimListDragDrop(Sender, Source: TObject; X,
      Y: Integer);
    procedure ActiveDimListDragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure FieldListDragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure SummaryListDragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure FieldListDragDrop(Sender, Source: TObject; X, Y: Integer);
    procedure SummaryListDragDrop(Sender, Source: TObject; X, Y: Integer);
    procedure FieldListKeyPress(Sender: TObject; var Key: Char);
    procedure ShowBoxKeyPress(Sender: TObject; var Key: Char);
    procedure ActiveDimListKeyPress(Sender: TObject; var Key: Char);
    procedure SummaryListKeyPress(Sender: TObject; var Key: Char);
    procedure PagerChanging(Sender: TObject;
      var AllowChange: Boolean);
    procedure TableComboChange(Sender: TObject);
    procedure DatabaseComboChange(Sender: TObject);
    procedure DatabaseComboExit(Sender: TObject);
    procedure DatabaseComboKeyPress(Sender: TObject; var Key: Char);
    procedure TableComboKeyPress(Sender: TObject; var Key: Char);
    procedure TableComboExit(Sender: TObject);
    procedure HelpButtonClick(Sender: TObject);
    procedure DatabaseComboKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure TableComboKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure CountStarAvgClick(Sender: TObject);
    { Private declarations }
  private
    bEditEnabled: Boolean;
    bisOK: Boolean;
    bQueryLegal: Boolean;
    bAllFields: Boolean;
    bDataBaseEditing: Boolean;
    bDataBaseChanged: Boolean;
    bTableNameEditing: Boolean;
    bTableNameChanged: Boolean;
    bQueryEditing: Boolean;
    bSQLChangeOff: Boolean;
    bStarAvgChanging: Boolean;
    myMap: TQueryDims;
    fieldMap: TQueryDims;
    myQuery: TQuery;
    vqbQuery: TQuery;
    myDB: TDataBase;
    mySQL: String;
    myAlias: String;
    fQParse: TXtabQuery;
    procedure SetQueryEditState(State: Boolean);
    procedure ListBoxUnSelect(aListBox: TListBox);
    function AddNewItem(sType: TDimFlags; DM: TQueryDim; Name: string): Boolean;
    function AddSummary(sType: TDimFlags): Boolean;
    procedure AddCountStar;
    procedure RemoveCountStar;
    function FieldListDisplay(Map: TQueryDim): string;
    procedure ProcessNewQuery(newSQL: string);
    procedure ProcessNewQueryError(newSQL: string);
    procedure SetDatabaseName(tAlias: string);
    procedure SetTableName(TableName: string);
    procedure UpdateLists;
    procedure UpdateTableList;
    procedure UpdateDataBaseList;
    procedure UpdateFieldList;
    procedure UpdateDimLists;
    procedure UpdateSQLBox;
    procedure UpdateTableName;
    { Protected declarations }
  protected
    { Public declarations }
  public
    function SInitialize(const Designer: IDesigner; aQuery: TQuery): Boolean;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

procedure ShowDSSQueryEditor(const Designer: IDesigner; aQuery: TQuery);

implementation

uses
  GQEDelph;

{$R *.DFM}


  { Query Editor }

procedure ShowDSSQueryEditor(const Designer: IDesigner; aQuery: TQuery);
var
  aWindow: TDSSQueryEditor;
  x, y: Integer;
begin
  if not assigned(aQuery) then Exit;
  aWindow := TDSSQueryEditor.Create(application);
  try
    if aWindow.SInitialize(Designer, aQuery) then
    begin
      x := (Screen.Width - aWindow.Width) div 2;
      y := (Screen.Height - aWindow.Height) div 2;
      if (x < 0) then x := 0;
      if (y < 0) then y := 0;
      aWindow.Left := x;
      aWindow.Top := y;
      aWindow.ShowModal;
    end;
  finally
    aWindow.free;
  end;
end;

function CheckIfStringNull(aString: string): Boolean;
var
  i: Integer;  
begin
  Result := False;
  for i := 1 to length(aString) do
    if (ord(aString[i]) > 32) then Exit;
  Result := True;
end;

constructor TDSSQueryEditor.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
end;

destructor TDSSQueryEditor.Destroy;
begin
  if (myDB <> nil) then
  begin
    myQuery.DBSession.CloseDataBase(myDB);
    myDB := nil;
  end;
  myMap.Free;
  fieldMap.Free;
  vqbQuery.Free;
  fQParse.Free;
  inherited Destroy;
end;

function TDSSQueryEditor.SInitialize(const Designer: IDesigner; aQuery: TQuery): Boolean;
begin
  myQuery := aQuery;
  if (not assigned(myQuery)) then
  begin
    raise ECubeDesignError.createRes(@sNoDataSet);
    Result := False;
    Exit;
  end;
  myMap := TQueryDims.Create(myQuery, TQueryDim);
  fieldMap := TQueryDims.Create(myQuery, TQueryDim);
  SetDataBaseName(myQuery.DataBaseName);  { be sure to set database before SQL }
  bEditEnabled := True;
  UpdateTableList;
  UpdateDatabaseList;
  bDataBaseEditing := False;
  bTableNameEditing := False;
  Pager.activePage := Dimensions;
  try
    bAllFields := True;
    ProcessNewQuery(myQuery.SQL.text);
  except
    on E: exception do
    begin
      mySQL := myQuery.SQL.Text;
      ShowMessage(E.message);
      Pager.ActivePage := Query;
    end;
  end;
  SetQueryEditState(False);
  bSQLChangeOff := False;
  UpdateLists;
  VQB.Visible := LoadGQE;
  bTableNameEditing := False;
  bStarAvgChanging := False;
  Result := True;
end;

procedure TDSSQueryEditor.UpdateLists;
begin
  UpdateFieldList;
  UpdateDimLists;
  UpdateSQLBox;
end;

procedure TDSSQueryEditor.UpdateFieldList;
var
  i: Integer;
  DM: TQueryDim;  
begin
  FieldList.Clear;
  for i := 0 to fieldMap.Count-1 do
  begin
    DM := fieldMap[i];
    FieldList.Items.Add(FieldListDisplay(DM));
  end;
  if bAllFields then
    SelectAllFields.caption := sQueryFields
  else
    SelectAllFields.caption := sAllFields;
end;

procedure TDSSQueryEditor.UpdateDimLists;
var
  i: Integer;
  DM: TQueryDim;
  bChecked: Boolean;
begin
  ActiveDimList.Clear;
  SummaryList.Clear;
  AddButton.enabled := (Fieldlist.SelCount > 0);
  AddAgg.enabled := (Fieldlist.SelCount > 0);
  RemoveButton.enabled := False;
  RemoveAgg.enabled := False;
  bChecked := False;
  for I := 0 to myMap.count-1 do
  begin
    DM := myMap[i];
    if DM.active then
    begin
      if (DM.DimensionType <> dimDimension) then
      begin
        SummaryList.Items.Add(DM.FieldName);
        if (AnsiUpperCase(DM.Name) = sCountStar) then
          bChecked := True;
      end
      else
        ActiveDimList.Items.Add(DM.FieldName);
    end;
  end;
  bStarAvgChanging := True;
  CountStarAvg.Checked := bChecked;
  bStarAvgChanging := False;
end;

procedure TDSSQueryEditor.UpdateSQLBox;
begin
  bSQLChangeOff := True;
  ShowBox.Lines.Text := mySQL;
  bSQLChangeOff := False;
end;

procedure TDSSQueryEditor.AddButtonClick(Sender: TObject);
var
  i, j: Integer;
  DM: TQueryDim;
  bChanged: Boolean;
  eWarning: string;
begin
  bChanged := False;
  eWarning := '';
  with FieldList do
    for I := 0 to Items.Count - 1 do
    begin
      if Selected[I] then
      begin
        for J := 0 to fieldMap.count-1 do
        begin
          DM := fieldMap[J];

          if (FieldListDisplay(DM) = Items.STRINGS[I]) then
          begin
            try
              if AddNewItem(dimDimension,DM,'') then
                bChanged := True;
            except
              on e: EAddWarning do
              begin
                eWarning := E.message;
              end;
              on E: exception do
              begin
                if bChanged then
                begin
                  mySQL := FQParse.SQLString;
                  UpdateDimLists;
                  UpdateSQLBox;
                end;
                raise;
              end;
            end;
          end;
        end;
      end;
    end;
  if bChanged then
  begin
    mySQL := FQParse.SQLString;
    UpdateDimLists;
    UpdateSQLBox;
  end;
  if (EWarning <> '') then
    raise EAddWarning.create(EWarning);
end;

procedure TDSSQueryEditor.AddAggClick(Sender: TObject);
var
  aPoint: TPoint;
begin
  aPoint.x := 0;
  aPoint.y := AddAgg.Height;
  aPoint := AddAgg.ClientToScreen(aPoint);
  AggPopUp.PopUp(aPoint.x, aPoint.y);
end;

function TDSSQueryEditor.AddSummary(sType: TDimFlags): Boolean;
var
  i, j: Integer;
  DM: TQueryDim;
  EWarning: string;  
begin
  EWarning := '';
  Result := False;
  with FieldList do
    for I := 0 to Items.Count - 1 do
    begin
      if Selected[I] then
      begin
        for J := 0 to fieldMap.count-1 do
        begin
          DM := fieldMap[J];
          if (FieldListDisplay(DM) = Items.STRINGS[I]) then
          begin
            try
              if AddNewItem(stype,DM,'') then
                Result := True;
            except
              on E: EAddWarning do
              begin
                EWarning := E.message;
              end;
              on E: exception do
              begin
                if Result then
                begin
                  mySQL := FQParse.SQLString;
                  UpdateDimLists;
                  UpdateSQLBox;
                end;
                raise;
              end;
            end;
          end;
        end;
      end;
    end;
  if Result then
  begin
    mySQL := fQParse.SQLString;
    UpdateDimLists;
    UpdateSQLBox;
  end;
  if (EWarning <> '') then
    raise EAddWarning.create(EWarning);
end;

procedure TDSSQueryEditor.RemoveButtonClick(Sender: TObject);
var
  i, j: Integer;
  DM: TQueryDim;
  bChanged: Boolean;
  reSelect: Integer;
label
  FastExit;
begin
  bChanged := False;
  reSelect := -1;
  with ActiveDimList do
  begin
    for I := 0 to Items.Count - 1 do
    begin
      if Selected[I] then
      begin
        if (Reselect = -1) then Reselect := I;
        for J := 0 to myMap.count-1 do
        begin
          DM := myMap[j];
          if (DM.FieldName = Items.STRINGS[I]) then
          begin
            try
              RemoveDimensionItem(fQParse, myMap, J);
              DM.free;
              bChanged := True;
              Break;
            except
              showmessage(SRemoveFieldError);
            end;
            goto FastExit;
          end;
        end;
      end;
    end;
  end;
  FastExit:
    if bChanged then
    begin
      mySQL := fQParse.SQLString;
      UpdateDimLists;
      UpdateSQLBox;

      if (reselect >= ActiveDimList.Items.count) then
        reselect := ActiveDimList.Items.count-1;
      if (reselect >= 0) then
      begin
        ActiveDimList.selected[reselect] := True;
        RemoveButton.enabled := True;
      end;
    end;
end;

procedure TDSSQueryEditor.RemoveAggClick(Sender: TObject);
var
  i, j, k: Integer;
  DM: TQueryDim;
  reSelect: Integer;
  bChanged: Boolean;
label
  FastExit;
begin
  reselect := -1;
  with SummaryList do
  begin
    bChanged := False;
    for I := 0 to Items.Count - 1 do
    begin
      if (Reselect = -1) then Reselect := I;
      if Selected[I] then
      begin
        for J := 0 to myMap.count-1 do
        begin
          DM := myMap[j];
          if (DM.FieldName = Items.STRINGS[I]) then
          begin
            try
              RemoveDimensionItem(fQParse, myMap, J);
              if (DM.DimensionType <> dimDimension) then
              begin
                for k := 0 to fieldMap.count-1 do
                begin
                  if (fieldMap[k].FieldName = DM.FieldName) then
                    Break;
                end;
                if (k = fieldMap.count) and (AnsiUpperCase(DM.Name) <> sCountStar) then
                begin
                  fieldMap.Add.Assign(DM);
                  UpdateFieldList;
                end;
              end;
              DM.free;
              bChanged := True;
              Break;
            except
              showmessage(SRemoveFieldError);
            end;
            goto FastExit;
          end;
        end;
      end;
    end;
  end;
  FastExit:
    if bChanged then
    begin
      mySQL := fQParse.SQLString;
      UpdateDimLists;
      if (reselect >= SummaryList.Items.count) then
        reselect := SummaryList.Items.count-1;
      if (reselect >= 0) then
      begin
        SummaryList.selected[reselect] := True;
        RemoveAgg.enabled := True;
      end;
      UpdateSQLBox;
    end;
end;

procedure TDSSQueryEditor.FieldListClick(Sender: TObject);
begin
  if (FieldList.SelCount >= 0) then
  begin
    AddButton.enabled := True;
    AddAgg.enabled := True;
    ListBoxUnSelect(SummaryList);
    ListBoxUnSelect(ActiveDimList);
    RemoveButton.enabled := False;
    RemoveAgg.enabled := False;
  end;
end;

procedure TDSSQueryEditor.ActiveDimListClick(Sender: TObject);
begin
  ListBoxUnSelect(SummaryList);
  ListBoxUnSelect(FieldList);
  AddButton.enabled := False;
  AddAgg.enabled := False;
  RemoveButton.enabled := (ActiveDimList.SelCount >= 0);
end;

procedure TDSSQueryEditor.SummaryListClick(Sender: TObject);
begin
  ListBoxUnSelect(ActiveDimList);
  ListBoxUnSelect(FieldList);
  AddButton.enabled := False;
  AddAgg.enabled := False;
  RemoveButton.enabled := False;
  RemoveAgg.enabled := (SummaryList.SelCount >= 0);
end;

procedure TDSSQueryEditor.ListBoxUnSelect(aListBox: TListBox);
var
  i: Integer;  
begin
  with aListBox do
  begin
    for i := 0 to items.count-1 do
    begin
      if selected[i] then selected[i] := False;
    end;
  end;
end;

function TDSSQueryEditor.FieldListDisplay(Map: TQueryDim): string;
begin
  Result := Map.FieldName;
  if Map.active then Result := '*' + Result;
end;

procedure TDSSQueryEditor.AddCountStar;
var
  DM: TQueryDim;
begin
  DM := fieldMap.Add;
  try
    DM.BaseName := '*';
    DM.FieldName := '*';
    DM.FieldType := ftString;
    AddNewItem(dimCount, DM, sCountStar);
  finally
    DM.Free;
  end;
  mySQL := fQParse.SQLString;
  UpdateDimLists;
  UpdateSQLBox;
end;

procedure TDSSQueryEditor.RemoveCountStar;
var
  j: Integer;
  DM: TQueryDim;
begin
  for J := 0 to myMap.count-1 do
  begin
    DM := myMap[j];
    if (AnsiUpperCase(DM.Name) = sCountStar) then
    begin
      try
        RemoveDimensionItem(fQParse, myMap, J);
        DM.free;
        Break;
      except
        showmessage(SRemoveFieldError);
        Exit;
      end;
    end;
  end;
  mySQL := fQParse.SQLString;
  UpdateDimLists;
  UpdateSQLBox;
end;

function TDSSQueryEditor.AddNewItem(sType: TDimFlags; DM: TQueryDim; Name: string): Boolean;
var
  NewDM: TQueryDim;
  iPos, i: Integer;
begin
  Result := False;
  { Check to see if it exists already }
  if myMap.alreadyExists(DM.BaseName, stype) then
    raise EAddWarning.create(GetAggName(sType, DM.BaseName) + SAddFieldExists);
  if not isAggValid(stype, DM.FieldType) then
  begin
    if (stype = dimDimension) then
      raise EAddError.create(DM.BaseName + sDimTypeNotALlowed)
    else
      raise EAddError.create(GetAggName(stype, DM.BaseName) + sAggTypeNotALlowed);
  end;
  NewDM := myMap.Add;
  if not assigned(NewDM) then Exit;
  iPos := myMap.count-1;
  if (sType = dimDimension) then  { add new dimension before summaries }
  begin
    for i := 0 to myMap.count-2 do
    begin
      if (myMap[i].dimensionType <> dimDimension) then
      begin
        iPos := i;
        Break;
      end;
    end;
  end;
  if (NewDM.Index <> iPos) then NewDM.Index := iPos;
  NewDM.fieldname := DM.FieldName;
  NewDM.basename := DM.baseName;
  NewDM.DimensionType := sType;
  NewDM.Name := GetAggName(SType, DM.Name);
  NewDM.active := True;
  try
   AddDimensionItem(fQParse, myMap, iPos, Name);
  except
    on E: Exception do
    begin
      NewDM.free;
      raise;
    end;
  end;
  Result := True;
end;

procedure TDSSQueryEditor.Sum1Click(Sender: TObject);
begin
  AddSummary(dimSum);
end;

procedure TDSSQueryEditor.Count1Click(Sender: TObject);
begin
  AddSummary(dimCount);
end;

procedure TDSSQueryEditor.OKButtonClick(Sender: TObject);
var
  anError: TQueryError;
  aMessage: string;
  dSQL: string;
begin
  try
    dSQL := fQParse.GetDialectSQLString;
    anError := fQParse.isLegal;
  except
    on exception do
    begin
      anError := tqeNotInitialized;
    end;
  end;
  if (anError <> tqeOK) then
  begin
    case anError of
      tqeNoDimensions : aMessage := SNoDims;
      tqeNoAggs       : aMessage := SNoAggs;
      tqeNotGrouped   : aMessage := SGroupsMissing;
      else
        aMessage := SQueryIllegal;
    end;
    if (MessageDlg(aMessage + ' ' + sWantToExit, mtConfirmation, [mbYes, mbNo], 0) <> 6) then
    begin
      updatelists;
      Exit;
    end;
  end;
  myQuery.active := False;
  myQuery.SQL.text := dSQL;
  myQuery.DatabaseName := myAlias;
  UpdateDesigner(myQuery);
  Close;
end;

procedure TDSSQueryEditor.VQBClick(Sender: TObject);
var
  bNoDataBase: Boolean;
  SaveSQL: string;
begin
  if not GQELoaded then Exit;
  bNoDataBase := myAlias = '';
  if (vqbQuery = nil) then vqbQuery := TQuery.Create(myQuery);
  if (vqbQuery.DataBaseName <> myALias) then
  begin
    vqbQuery.DataBaseName := myAlias;
    vqbQuery.SQL.text := '';
  end;
  SaveSQL := vqbQuery.Text;
  BuildQuery(vqbQuery);
  if bNoDataBase then
  begin
    if (VQBQuery.DataBaseName = '') then Exit;
    SetDataBaseName(vqbquery.DataBaseName);
  end;
  if (SaveSQL <> vqbQuery.SQL.Text) then
  begin
    try
      bAllFields := False;
      ProcessNewQuery(VQBQuery.SQL.Text);
      if not bisOK then
      begin
        fQParse.DeleteProjectors;
        mySQL := fQParse.SQLString;
        myMap.Clear;
        updatelists;
      end;
    except
      on E: exception do
      begin
        ShowMessage(E.message);
      end;
    end;
  end;
  SetQueryEditState(False);
end;

procedure TDSSQueryEditor.ProcessNewQuery(newSQL: String);
var
  i: Integer;
  anError: TQueryError; 
begin
  if CheckifStringNull(newSQL) or (myDB = nil) then
  begin
    mySQL := '';
    bQueryLegal := False;
    myMap.clear;
    bisOK := False;
    fieldMap.clear;
    bAllFields := False;
    bSQLChangeOff := False;
    SetQueryEditState(False);
    UpdateLists;
    Exit;
  end;
  try
    if bAllFields then
    begin
      fQParse.canDelete := True;
      BuildDimensionMap(fQParse, myMap, newSQL);
      fQParse.canDelete := False;
      BuildMasterDimensionMap(fQParse, FieldMap);
    end
    else
    begin
      fQParse.canDelete := True;
      anError := BuildDimensionMap(fQParse, FieldMap, newSQL);
      bisOK := (anError = tqeOK);
      for i := 0 to fieldMap.count-1 do
        fieldMap[i].active := False;
      myMap.Assign(FieldMap);
      for i := 0 to MYMap.count-1 do
        MYMap[i].active := True;
    end;
    mySQL := fQParse.SQLString;
  except
    on E: exception do
    begin
      bQueryLegal := False;
      raise;
    end;
  end;
  bQueryLegal := True;
  SetQueryEditState(False);
  updatelists;
  UpdateTableName;
end;

procedure TDSSQueryEditor.UpdateTableName;
var
  TableName: string;
  i: Integer;
  bFound: Boolean;
begin
  { Update the table dropdown } 
  bFound := False;
  if assigned(fQParse) and (fQParse.nTables = 1) then
  begin
    TableName := fQParse.TableName[0];
    for i := 0 to TableCombo.Items.count-1 do
    begin
      if (TableCombo.Items[i] = TableName) then
      begin
        bTableNameEditing := True;
        TableCombo.ItemIndex := i;
        bFound := True;
        Break;
      end;
    end;
    if not bFound then
    begin
      bTableNameEditing := True;
      TableCombo.ItemIndex := TableCombo.items.Add(TableName);
    end;
    bTableNameEditing := False;
  end;
end;

procedure TDSSQueryEditor.CancelQryModClick(Sender: TObject);
begin
  if not bQueryEditing then Exit;
  ProcessNewQueryError(mySQL);
  if OKButton.Enabled then OKButton.SetFocus;
end;

procedure TDSSQueryEditor.ProcessNewQueryError(newSQL: string);
begin
  try
    mySQL := newSQL;
    ProcessNewQuery(mySQL);
  except
    on e: exception do
    begin
      ShowMessage(e.message);
      myMap.clear;
      fieldMap.clear;
    end;
  end;
  SetQueryEditState(False);
  updatelists;
end;

procedure TDSSQueryEditor.ShowBoxChange(Sender: TObject);
begin
  if bQueryEditing then Exit;
  if bSQLChangeOff then Exit;
  SetQueryEditState(True);
end;

procedure TDSSQueryEditor.SetQueryEditState(State: Boolean);
var
  dState: Boolean;
begin
  dState := assigned(myDb);
  AddButton.enabled := False;
  RemoveButton.enabled := False;
  RemoveAgg.enabled := False;
  AddAgg.enabled := False;
  ShowBox.enabled := dState;
  EditQry.enabled := dState;
  TableCombo.enabled := dState;
  OKButton.enabled := not state;
  { save the old state to restore later if needed }
  bQueryEditing := dState and state;
  CancelQryMod.enabled := dState and state;
  FieldList.enabled := dState and bQueryLegal and not state;
  ActiveDimList.enabled := dState and bQueryLegal and not state;
  SummaryList.enabled := dState and bQueryLegal and not state;
  SelectAllFields.enabled := dState and bQueryLegal and not state;
  CountStarAvg.enabled := dState and bQueryLegal and not state;
  if bQueryEditing then
    EditQry.caption := sEditDone
  else
    EditQry.caption := sEditQuery;
  VQB.enabled := not state;
end;

procedure TDSSQueryEditor.EditQryClick(Sender: TObject);
var
  aString: string;  
begin
  if bQueryEditing then
  begin
    aString := ShowBox.Lines.Text;
    try
      bAllFields := True;
      ProcessNewQuery(aString);
    except
      on E: exception do
      begin
        ShowMessage(E.message);
        bQueryEditing := True;
        Exit;
      end;
    end;
    SetQueryEditState(False);
    updatelists;
    if OKButton.Enabled then OKButton.SetFocus;
  end
  else
  begin
    if bSQLChangeOff then Exit;
    SetQueryEditState(True);
    if ShowBox.enabled then ShowBox.SetFocus;
  end;
end;

procedure TDSSQueryEditor.SelectAllFieldsClick(Sender: TObject);
begin
  if not assigned(myDB) then Exit;
  bAllFields := not bAllFields;
  ProcessNewQuery(mySQL);
end;

procedure TDSSQueryEditor.FieldListDblClick(Sender: TObject);
var
  i, j: Integer;
  DM: TQueryDim;
  bChanged: Boolean;
  EWarning: string;  
begin
  bChanged := False;
  EWarning := '';
  with FieldList do
    for I := 0 to Items.Count - 1 do
    begin
      if Selected[I] then
      begin
        for J := 0 to fieldMap.count-1 do
        begin
          DM := fieldMap[J];
          if FieldListDisplay(DM) = Items.STRINGS[I] then
          begin
            try
              if AddNewItem(DM.DimensionType,DM,'') then
                bChanged := True;
            except
              on E: EAddWarning do
              begin
                EWarning := E.message;
              end;
              on exception do
              begin
                if bChanged then
                begin
                  mySQL := FQParse.SQLString;
                  UpdateDimLists;
                  UpdateSQLBox;
                end;
              raise;
            end;
          end;
        end;
      end;
    end;
  end;
  if bChanged then
  begin
    mySQL := FQParse.SQLString;
    UpdateDimLists;
    UpdateSQLBox;
  end;
  if (EWarning <> '') then
    raise EAddWarning.create(EWarning);
end;

procedure TDSSQueryEditor.average1Click(Sender: TObject);
var
  EWarning: string;  
begin
  EWarning := '';
  try
    AddSummary(dimSum);
  except
    on E: EAddWarning do
    begin
      EWarning := E.message;
    end;
  end;
  if not CountStarAvg.checked then
  begin
    try
      AddSummary(dimCount);
    except
      on E: EAddWarning do
      begin
        EWarning := E.message;
      end;
    end;
  end;
  if (EWarning <> '') then
  begin
    if CountStarAvg.Checked then
      ShowMessage(SAddAvgStarWarning)
    else
      ShowMessage(SAddAvgWarning);
  end;
end;

procedure TDSSQueryEditor.ActiveDimListDragDrop(Sender, Source: TObject; X,
  Y: Integer);
begin
  if (source = FieldList) then
  begin
    AddButtonClick(Self);
  end;
end;

procedure TDSSQueryEditor.ActiveDimListDragOver(Sender, Source: TObject; X,
  Y: Integer; State: TDragState; var Accept: Boolean);
begin
  if (Source = FieldList) then
    Accept := True;
end;

procedure TDSSQueryEditor.FieldListDragOver(Sender, Source: TObject; X,
  Y: Integer; State: TDragState; var Accept: Boolean);
begin
  if (Source = ActiveDimList) or (Source = SummaryList) then
    Accept := True;
end;

procedure TDSSQueryEditor.SummaryListDragOver(Sender, Source: TObject; X,
  Y: Integer; State: TDragState; var Accept: Boolean);
begin
  if (source = FieldList) then
    Accept := True;
end;

procedure TDSSQueryEditor.FieldListDragDrop(Sender, Source: TObject; X,
  Y: Integer);
begin
  if (Source = ActiveDimList) then RemoveButtonClick(Self);
  if (Source = SummaryList) then RemoveAggClick(Self);
end;

procedure TDSSQueryEditor.SummaryListDragDrop(Sender, Source: TObject; X,
  Y: Integer);
begin
  if (Source = FieldList) then AddAggClick(Self);
end;

procedure TDSSQueryEditor.FieldListKeyPress(Sender: TObject;
  var Key: Char);
begin
  if (Key = Chr(13)) then
  begin
    AddButtonClick(Self);
    key := chr(0);
  end;
end;

procedure TDSSQueryEditor.ShowBoxKeyPress(Sender: TObject; var Key: Char);
begin
  if bQueryEditing then
  begin
    if (key = chr(27)) then
    begin
      CancelQryModClick(Self);
      key := chr(0);
    end
    else
    begin
    end;
  end;
end;

procedure TDSSQueryEditor.ActiveDimListKeyPress(Sender: TObject;
  var Key: Char);
begin
  if (Key = Chr(13)) then
  begin
    RemoveButtonClick(Self);
    key := chr(0);
  end;
end;

procedure TDSSQueryEditor.SummaryListKeyPress(Sender: TObject;
  var Key: Char);
begin
  if (Key = Chr(13)) then
  begin
    RemoveAggClick(Self);
    key := chr(0);
  end;
end;

procedure TDSSQueryEditor.PagerChanging(Sender: TObject;
  var AllowChange: Boolean);
begin
  if (Pager.ActivePage.Name = 'Query') and bQueryEditing then
  begin
    EditQryClick(Self);
    if bQueryEditing then AllowChange := False;
  end;
end;

procedure TDSSQueryEditor.SetTableName(TableName: string);
var
  anSQL: string;  
begin
  if not CheckifStringNull(TableName) then
  begin
    if BQueryLegal and assigned(fQParse) and (fQParse.nTables = 1) then
      if (TableName = fQParse.TableName[0]) then Exit;
    anSQL := 'Select From ' + TableName;
    bAllFields := True;
    try
      ProcessNewQuery(anSQL);
    except
      fQParse.SQLString := '';
      fQParse.AddTable(TableName);
      anSQL := FQParse.SQLString;
      bAllFields := True;
      ProcessNewQuery(anSQL);
    end;
  end;
end;

procedure TDSSQueryEditor.SetDatabaseName(tAlias: string);
var
  tDB: TDataBase;
  bFound: Boolean;
  i: Integer;  
begin
  if not CheckIfStringNull(tAlias) then
  begin
    tDB := myQuery.DBSession.OpenDataBase(tAlias);
    if assigned (tDB) then
    begin
      myAlias := tAlias;
      if (myDB <> nil) then
      begin
        myQuery.DBSession.CloseDataBase(myDB);
        myDB := nil;
      end;
      myDb := tDB;
      myDB.connected := True;
      if not assigned(fQParse) then fQParse := TXTabQuery.create;
      fQParse.canDelete := True;
      fQParse.DBHandle := myDB.Handle;
      UpdateTableList;
      bAllFields := True;
      ProcessNewQuery('');
      SetQueryEditState(False);
      bFound := False;
      DataBaseCombo.text := tAlias;
      for i := 0 to DataBaseCombo.items.count-1 do
      begin
        if (tAlias = DataBaseCombo.items[i]) then
          bFound := True;
      end;
      if not bFound then DataBaseCombo.items.Add(tAlias);
    end;
  end;
end;

procedure TDssQueryEditor.UpdateTableList;
begin
  TableCombo.Clear;
  if not CheckifStringNull(myAlias) then
    myQuery.DBSession.GetTableNames(Myalias, '', True, False, TableCombo.items);
end;

procedure TDssQueryEditor.UpdateDataBaseList;
begin
  myQuery.DBSession.GetDatabaseNames(DatabaseCombo.items);
end;

procedure TDSSQueryEditor.DatabaseComboChange(Sender: TObject);
begin
  if bDataBaseEditing then
    bDataBaseChanged := True
  else
    SetDataBaseName(DatabaseCombo.text);
end;

procedure TDSSQueryEditor.DatabaseComboExit(Sender: TObject);
begin
  if bDataBaseChanged then
  begin
    try
      SetDataBaseName(DataBaseCombo.Text);
    except
      on e: exception do
      begin
        ShowMessage(e.message);
        if DataBaseCombo.enabled then
          DataBaseCombo.SetFocus;
      end;
    end;
  end;
  bDataBaseEditing := False;
  bDataBaseChanged := False;
end;

procedure TDSSQueryEditor.DatabaseComboKeyDown(Sender: TObject;
  var Key: Word; Shift: TShiftState);
begin
  bDataBaseEditing := True;
  TableCombo.enabled := True;
end;

procedure TDSSQueryEditor.DatabaseComboKeyPress(Sender: TObject;
  var Key: Char);
begin
  if (Key = Char(13)) then
  begin
    DataBaseComboExit(Self);
    Key := Char(0);
  end;
end;

procedure TDSSQueryEditor.TableComboKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  bTableNameEditing := True;
end;

procedure TDSSQueryEditor.TableComboKeyPress(Sender: TObject;
  var Key: Char);
begin
  if (Key = Char(13)) then
  begin
    TableComboExit(Self);
    Key := Char(0);
  end;
end;

procedure TDSSQueryEditor.TableComboExit(Sender: TObject);
begin
  if bTableNameChanged then
  begin
    try
      SetTableName(TableCombo.Text);
      SetQueryEditState(False);
    except
      on e: exception do
      begin
        ShowMessage(e.message);
        TableCombo.SetFocus;
      end;
    end;
  end;
  bTableNameEditing := False;
  bTableNameChanged := False;
end;

procedure TDSSQueryEditor.TableComboChange(Sender: TObject);
begin
  if bTableNameEditing then
    bTableNameChanged := True
  else if not CheckifStringNull(TableCombo.text) then
  begin
    SetTableName(TableCombo.text);
  end;
end;

procedure TDSSQueryEditor.HelpButtonClick(Sender: TObject);
begin
  Application.HelpContext(hcDDecisionQueryEditor);
end;

procedure TDSSQueryEditor.CountStarAvgClick(Sender: TObject);
begin
  if bStarAvgChanging then Exit;
  if CountStarAvg.Checked then
    AddCountStar
  else
    RemoveCountStar;
end;

end.
