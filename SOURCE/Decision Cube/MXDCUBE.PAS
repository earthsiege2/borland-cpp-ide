{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxdcube;

interface

uses
 Windows, Messages, Classes, SysUtils, Controls, StdCtrls, Graphics, dialogs,
 DB, DBTables, Grids, Forms, mxConsts, mxgrid, mxdb, mxcommon, mxstore,
 ExtCtrls, Buttons, ComCtrls, Menus, Mask;

type
  ECubeDesignError = class(Exception);

  TEditorDimensionItem = class(TDimensionItem);

  TDssCubeEditor = class(TForm)
    FieldList: TListBox;
    RadioMetaData: TRadioButton;
    RadioDimensionData: TRadioButton;
    RadioAllData: TRadioButton;
    RadioNoData: TRadioButton;
    Panel1: TGroupBox;
    CaptionEdit: TEdit;
    CaptionLabel: TLabel;
    ActiveLabel: TLabel;
    BinLabel: TLabel;
    StartLabel: TLabel;
    TypeLabel: TLabel;
    ActiveEdit: TComboBox;
    BinEdit: TComboBox;
    TypeEdit: TComboBox;
    Pager: TPageControl;
    DimensionInfo: TTabSheet;
    MemoryControl: TTabSheet;
    Label1: TLabel;
    Label2: TLabel;
    FormatEdit: TEdit;
    StartEdit: TMaskEdit;
    OKButton: TButton;
    CancelButton: TButton;
    HelpButton: TButton;
    NActiveDims: TLabel;
    nDemandDims: TLabel;
    Label4: TLabel;
    Label7: TLabel;
    Label9: TLabel;
    NActiveSums: TLabel;
    NDemandSums: TLabel;
    Label6: TLabel;
    MaxDims: TEdit;
    MaxSums: TEdit;
    MaxCells: TEdit;
    Label5: TLabel;
    Label12: TLabel;
    nDemandCells: TLabel;
    GetCellCounts: TButton;
    CubeLimits: TGroupBox;
    ValueCount: TLabel;
    Label3: TLabel;
    nCurrDims: TLabel;
    nCurrSums: TLabel;
    nCurrCells: TLabel;
    BaseNameLabel: TLabel;
    BaseNameEdit: TMaskEdit;
    procedure RadioDimensionDataClick(Sender: TObject);
    procedure RadioMetaDataClick(Sender: TObject);
    procedure RadioAllDataClick(Sender: TObject);
    procedure RadioNoDataClick(Sender: TObject);
    procedure FieldListClick(Sender: TObject);
    procedure OKButtonClick(Sender: TObject);
    procedure HandleFieldEdit(Sender: TObject);
    procedure HandleBeginEdit(Sender: TObject; var Key: Char);
    procedure ActiveEditChange(Sender: TObject);
    procedure CancelButtonClick(Sender: TObject);
    procedure PagerChange(Sender: TObject);
    procedure GetCellCountsClick(Sender: TObject);
    procedure FormKeyPress(Sender: TObject; var Key: Char);
    procedure HelpButtonClick(Sender: TObject);
    { Private declarations }
  private
    myObject: TDecisionCube;
    myMap: TCubeDims;
    myDataSet: TDataSet;
    myDB: TDataBase;
    bBinEdited: boolean;
    bEditing: boolean;
    bParsed: boolean;
    bDataSetMatch: boolean;
    fLastSelected: integer;
    bForceRefresh: boolean;
    bSetNameEditing: boolean;
    bSetValuesEditing: boolean;
    { editable field copies }
    FNameCopy: String;
    FFormatCopy: String;
    FActiveCopy: TActiveFlags;
    FTypeCopy:  TDimFlags;
    FBinTypeCopy: TBinType;
    FStartValueCopy: string;
    procedure InitEdit;
    procedure CommitEdit;
    procedure GetValueCounts;
    { Protected declarations }
  protected
    { Public declarations }
  public
    procedure UpdateLists;
    procedure InitializePanel;
    procedure InitCapacityPage;
    function SInitialize(const Designer: IDesigner; AnObject: TComponent): boolean;
    procedure SFinalize;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  procedure ShowDSSCubeEditor(const Designer: IDesigner; aCube: TDecisionCube);

var
  DSSCubeEditor: TDssCubeEditor;

implementation

{$R *.DFM}


  { Query Editor }

procedure ShowDSSCubeEditor(const Designer: IDesigner; aCube: TDecisionCube);
var
  aWindow: TDssCubeEditor;
  x,y: integer;
begin
  if not assigned(aCube) then Exit;
  aWindow := TDssCubeEditor.Create(application);
  try
    if aWindow.SInitialize(Designer, aCube) then
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

constructor TDssCubeEditor.Create(AOwner: TComponent);
begin
  bSetNameEditing := false;
  bSetValuesEditing := false;
  bForceRefresh := false;
  myMap := nil;
  inherited Create(AOwner);
end;

destructor TDssCubeEditor.Destroy;
begin
  myMap.free;
  inherited Destroy;
end;

function TDssCubeEditor.SInitialize(const Designer: IDesigner; anObject: TComponent): boolean;
var
  anError: TQueryError;
  aliasname: string;
  bDBexists: boolean;
begin
  Result := False;
  if not (anObject is TDecisionCube) then Exit;
  myObject := TDecisionCube(anObject);
  myDataSet := myObject.DataSet;
  if (not assigned(myDataSet)) then
    raise ECubeDesignError.CreateRes(@sNoDataSet);
  Pager.ActivePage := DimensionInfo;
  if (myDataSet is TQuery) then
  begin
    bDBExists := (tquery(myDataSet).Database <> nil);
    if not bDBExists then
    begin
      aliasName := TQuery(myDataSet).DataBaseName;
      if (aliasName <> '') then
        myDB := TQuery(myDataSet).DBSession.OpenDataBase(aliasName);
    end;
  end;
  { Build the dimension map for this set }
  myMap := TCubeDims.Create(myObject, TCubeDim);
  myMap.Assign(TCubeDims(myObject.DimensionMap));
  anError := BuildDataSetMap(myDataSet, myMap, bParsed, bDataSetMatch);
  if (anError = tqeNotInitialized) then
  begin
    raise ECubeDesignError.CreateRes(@sQryNotInitialized);
    Result := False;
    Exit;
  end;
  MaxDims.text := inttostr(myObject.MaxDimensions);
  MaxSums.text := inttostr(myObject.MaxSummaries);
  maxCells.text := inttostr(myObject.MaxCells);
  UpdateLists;
  InitCapacityPage;
  InitializePanel;
  Result := True;
end;

procedure TDssCubeEditor.SFinalize;
var
  i,dims, sums: integer;
  ValueCount, CP: integer;
  bEstimating: boolean;
begin
  CommitEdit;
  dims := strtoint(MaxDims.text);
  sums := strtoint(MaxSums.text);
  if (myMap.ActiveDimensionCount > dims) then
    raise ECubeDesignError.createResFmt(@sMaxAllowedDims,[dims]);
  if (myMap.ActiveSummaryCount > sums) then
    raise ECubeDesignError.createResFmt(@sMaxAllowedsums,[sums]);
  myObject.MaxDimensions := dims;
  myObject.MaxSummaries := sums;
  myObject.MaxCells := strtoInt(MaxCells.text);
  if (myObject.CurrentSummary <= sums) then
    myObject.currentSummary := 0;
  {
    See if the valuecount information is still available.  If not, an attempt is
    made to be friendly to the user by making a fairly pessimistic assumption about
    the size of a dimension whose valuecount is not available.  If all AsNeeded or
    Active Cells can still be loaded, no attempt is made to fetch the cell info
    at this point.
  }
  if (myObject.maxCells > 0) then
  begin
    bEstimating := false;
    CP := 1;
    for i := 0 to myMap.count-1 do
    begin
      if (myMap[i].DimensionType = dimDimension) and (myMap[i].ActiveFlag <> diInactive) then
      begin
        ValueCount := myMap[i].ValueCount;
        if (ValueCount <= 0) then
        begin
          bEstimating := true;
          ValueCount := LargeValueCount;
        end;
        CP := CP * ValueCount;
      end;
    end;
    if (CP > myObject.MaxCells) and bEstimating then
    begin
      if (MessageDlg(sGetValueCounts, mtConfirmation, [mbYes, mbNo], 0) = 6) then
      begin
        GetValueCounts;
      end;
    end;
  end;
  for i := 0 to myMap.count-1 do
  begin
    myMap[i].ActiveFlag := myMap[i].ActiveFlag; { resets the Active boolean }
  end;
  myObject.Refresh(myMap, bForceRefresh);
  UpdateDesigner(myObject);
end;

procedure TDssCubeEditor.UpdateLists;
var
  i: Integer;
  DM: TCubeDim;
begin
  FieldList.Clear;
  for I := 0 to myMap.count-1 do
  begin
    DM := myMap[i];
    if DM.loaded then
      FieldList.Items.Add(DM.FieldName + '*')
    else
      FieldList.Items.Add(DM.FieldName);
  end;
end;

procedure TDssCubeEditor.InitializePanel;
begin
  if (FieldList.items.count > 0) then FieldList.itemindex := 0;
  fLastSelected := FieldList.itemindex;
  InitEdit;
  if (csDesigning in myObject.ComponentState) then
  begin
    case myObject.DesignState of
      dsMetaData      : RadioMetaData.Checked := True;
      dsDimensionData : RadioDimensionData.Checked := true;
      dsAllData       : RadioAllData.Checked := true;
      dsNoData        : RadioNoData.Checked := true;
    end;
  end
  else
  begin
    RadioMetaData.Enabled := false;
    RadioDimensionData.Enabled := false;
    RadioAllData.Enabled := false;
    RadioNoData.Enabled := false;
    GetCellCounts.visible := false;
    MaxCells.enabled := false;
    MaxDims.enabled := false;
    MaxSums.enabled := false;
  end;
end;

procedure TDssCubeEditor.FieldListClick(Sender: TObject);
begin
  try
    CommitEdit;
  except
    on E: exception do
    begin
      raise Exception.create(E.Message);
      Exit;
    end;
  end;
  fLastSelected := fieldList.itemIndex;
  InitEdit;
end;

procedure TDssCubeEditor.InitEdit;
var
  DM: TCubeDim;
begin
  if (fLastSelected >= 0) and (fLastSelected < MyMap.count) then
  begin
    DM := myMap[fLastSelected];
    ValueCount.Caption := inttostr(DM.ValueCount);
    FActiveCopy := DM.ActiveFlag;
    FNameCopy := DM.Name;
    FTypeCopy := DM.DimensionType;
    FFormatCopy := DM.Format;
    ActiveEdit.itemindex := ord(DM.ActiveFlag);
    TypeEdit.itemindex := ord(DM.DimensionType);
    TypeEdit.Enabled := (not bParsed) or not (myDataSet is TQuery);
    CaptionEdit.text := DM.Name;
    CaptionEdit.enabled := not (AnsiUpperCase(DM.Name) = sCountStar);
    BaseNameEdit.text := DM.BaseName;
    BaseNameEdit.visible := (not bParsed) or not (myDataSet is TQuery);
    BaseNameLabel.visible := (not bParsed) or not (myDataSet is TQuery);
    FormatEdit.Text := DM.Format;
    BinEdit.Itemindex := ord(TCubeDim(DM).BinType);
    FBinTypeCopy := TCubeDim(DM).BinType;
    if (DM.DimensionType = dimDimension) then
    begin
      BinEdit.enabled := true;
      BinLabel.Enabled := true;
      if (DM.FieldType in [ftDate,ftDateTime]) and (DM.BinType in [binQuarter,binMonth,binYear])then
      begin
        FStartValueCopy := TCubeDim(DM).StartValue;
        StartEdit.text := TCubeDim(DM).StartValue;
        StartEdit.enabled := true;
        StartLabel.enabled := true;
      end
      else if (DM.BinType = binSet) then
      begin
        StartEdit.enabled := true;
        StartLabel.enabled := true;
        StartEdit.Text := DM.StartValue;
      end
      else
      begin
        StartEdit.Text := '';
        StartEdit.enabled := false;
        StartLabel.enabled := false;
      end;
    end
    else
    begin
      BinEdit.enabled := false;
      BinLabel.enabled := false;
      StartEdit.Text := '';
      StartEdit.enabled := false;
      StartLabel.enabled := false;
    end;
  end
  else
  begin
    ActiveEdit.itemindex := -1;
    FormatEdit.text := '';
    CaptionEdit.text := '';
    BaseNameEdit.Text := '';
    TypeEdit.itemindex := -1;
    BinEdit.itemindex := -1;
    StartEdit.text := '';
  end;

  bEditing := false;
  bBinEdited := false;
end;

procedure TDssCubeEditor.CommitEdit;
var
  OldDM, DM: TCubeDim;
  newBinType: tBinType;
  ValueCount: Integer;
begin
  if bEditing and (fLastSelected >= 0) and (fLastSelected < myMap.count) then
  begin
    DM := myMap[fLastSelected];
    DM.DimensionType := TDimFlags(TypeEdit.itemindex);
    DM.ActiveFlag := TActiveFlags(ActiveEdit.itemindex);
    DM.Name := CaptionEdit.text;
    if (not bParsed) or not (myDataSet is TQuery) then
      DM.BaseName := BaseNameEdit.Text;
    DM.Format := FormatEdit.text;
    if bBinEdited then
    begin
      { estimate the valuecount of this new bin, based on the old one, if possible }
      ValueCount := 0;
      newBinType := TBinType(BinEdit.ItemIndex);
      if (myObject.DimensionMap.count > fLastSelected) then
      begin
        oldDM := myObject.DimensionMap[fLastSelected];
        if (OldDM.BinType = NewBinType) then
          ValueCount := OldDM.ValueCount
        else
          case newBinType of
          binMonth:
          begin
            if (OldDM.BinType = binQuarter) then
              ValueCount := OldDM.ValueCount * 3
            else if (OldDM.BinType = binYear) then
              ValueCount := OldDM.ValueCount * 12;
          end;
          binQuarter:
          begin
            if (OldDM.BinType = binMonth) then
              ValueCount := OldDM.ValueCount div 3
            else if (OldDM.BinType = binYear) then
              ValueCount := OldDM.ValueCount * 4;
          end;
          binYear:
          begin
            if (OldDM.BinType = binMonth) then
              ValueCount := OldDM.ValueCount div 12
            else if (OldDM.BinType = binQuarter) then
              ValueCount := OldDM.ValueCount div 4;
          end;
          binSet:
          begin
            ValueCount := 2;
          end;
          binNone:
          begin
            if (OldDM.BinType = binSet) and assigned (OldDM.BinData) then
              ValueCount := OldDM.BinData.GetAllBinValueCount;
          end;
        end;
      end;
      try
        DM.BinType := TBinType(BinEdit.ItemIndex);
        if (DM.FieldType in [ftDate,ftDateTime]) and (DM.BinType in [binQuarter,binYear,binMonth]) then
        begin
          if (StartEdit.text <> '') then
            TCubeDim(DM).StartValue := DatetoStr(StrtoDate(StartEdit.text));
        end
        else if (DM.BinType = binSet) then
        begin
          DM.StartValue := StartEdit.text;
        end;
      except
        on exception do
        begin
          FieldList.itemIndex := fLastSelected;
          raise ECubeDesignError.createRes(@sIllegalValueForBin);
        end;
      end;
      DM.ValueCount := ValueCount;
    end;
  end;
  bBinEdited := false;
  bEditing := false;
end;

procedure TDSSCubeEditor.InitCapacityPage;
var
  i: integer;
  iActiveSums, iNeededSums, ICurrSums: integer;
  iActiveDims, iNeededDims, iCurrDims: integer;
  iNeededCP, iActiveCP, iCurrCP: integer;
begin
  if not assigned(myMap) then Exit;
  iActiveSums := 0;
  iNeededSums := 0;
  iCurrSUms := 0;
  iActiveDims := 0;
  iNeededDims := 0;
  iCurrDims := 0;
  iNeededCP := 1;
  iActiveCP := 1;
  iCurrCP := 1;
  for i := 0 to myMap.count-1 do
  begin
    if (myMap[i].DimensionType = dimDimension) then
    begin
      if (myMap[i].Loaded) then
      begin
        iCurrDims := iCurrDims + 1;
        if (myMap[i].ValueCount <= 0) then
          iCurrCP := 0
        else
          iCurrCP := iCurrCP * myMap[i].ValueCount;
      end;
      case myMap[i].ActiveFlag of
        diActive:
        begin
          iActiveDims := iActiveDims + 1;
          if (myMap[i].ValueCount <= 0) then
            iActiveCP := 0
          else
            iActiveCP := iActiveCP * myMap[i].ValueCount;
        end;
        diAsNeeded:
        begin
          iNeededDims := iNeededDims + 1;
          if (myMap[i].ValueCount <= 0) then
            iNeededCP := 0
          else
            iNeededCP := iNeededCP * myMap[i].ValueCount;
        end;
      end;
    end
    else if (myMap[i].derivedfrom < 0) then
    begin
      if (myMap[i].loaded) then iCurrSums := iCurrSums + 1;
      case myMap[i].ActiveFlag of
        diActive: iActiveSums := iActiveSums + 1;
        diAsNeeded: iNeededSums := iNeededSums + 1;
      end;
    end;
  end;
  nActiveDims.caption := inttostr(iActiveDims);
  nActiveSums.caption := inttostr(iActiveSums);
  nDemandDims.caption := inttostr(iNeededDims+iActiveDims);
  nDemandSums.caption := inttostr(iNeededSums+iActiveSums);
  nCurrDims.caption := inttostr(iCurrDims);
  nCurrSums.caption := inttostr(iCurrSums);
  if (iActiveCP > 0) and (iNeededCP > 0) then
    nDemandCells.Caption := inttostr((iNeededSums + iActiveSums) * iActiveCP * iNeededCP)
  else
    nDemandCells.Caption := sNotAvailable;
  if (iCurrCP > 0) then
    nCurrCells.Caption := IntToStr(iCurrCP * iCurrSums)
  else
    nCurrCells.Caption := sNotAvailable;
end;

procedure TDssCubeEditor.radioMetaDataClick(Sender: TObject);
begin
  myObject.DesignState := dsMetaData;
end;

procedure TDssCubeEditor.RadioDimensionDataClick(Sender: TObject);
begin
  myObject.DesignState := dsDimensionData;
end;

procedure TDssCubeEditor.RadioAllDataClick(Sender: TObject);
begin
  myObject.DesignState := dsAllData;
end;

procedure TDssCubeEditor.RadioNoDataClick(Sender: TObject);
begin
  myObject.DesignState := dsNoData;
end;

procedure TDssCubeEditor.OKButtonClick(Sender: TObject);
begin
  try
    SFinalize;
  except
    on E: exception do
    begin
      raise Exception.create(E.Message);
      Exit;
    end;
  end;
  Close;
end;

procedure TDSSCubeEditor.HandleFieldEdit(Sender: TObject);
var
  DM: TCubeDim;
begin
  if (Sender = FormatEdit) then
  begin
    bEditing := true;
    if (TEdit(Sender).text <> '') then FFormatCopy := TEdit(Sender).text;
  end;
  if (Sender = CaptionEdit) then
  begin
    bEditing := true;
    if (TEdit(Sender).text <> '') then FNameCopy := TEdit(Sender).text;
  end;
  if (Sender = BaseNameEdit) then bEditing := true;
  if (Sender = ActiveEdit) then
  begin
    bEditing := true;
    FActiveCopy := TActiveFlags(TComboBox(Sender).itemindex);
  end;
  if (Sender = TypeEdit) then
  begin
    bEditing := true;
    FTypeCopy := TDimFlags(TComboBox(Sender).itemindex);
  end;
  if (Sender = BinEdit) then
  begin
    bBinEdited := true;
    bEditing := true;
    FBinTypeCopy := TBinType(TComboBox(Sender).itemindex);
    DM := myMap[fLastSelected];
    if (FBinTypeCopy <> DM.BinType) then
    begin
      if (FBinTypeCopy in [binQuarter, binYear, binMonth])then
      begin
        if (DM.FieldType in [ftDate,ftDateTime]) then
        begin
          FStartValueCopy := TCubeDim(DM).StartValue;
          StartEdit.text := TCubeDim(DM).StartValue;
          StartEdit.enabled := true;
          StartLabel.enabled := true;
        end
        else
        begin
          ShowMessage(sDateBinningNotAllowed);
          TComboBox(Sender).itemIndex := 0;
        end;
      end
      else if (FBinTypeCopy = binSet) then
      begin
        StartEdit.enabled := true;
        StartEdit.text := '';
        StartLabel.enabled := true;
      end
      else
      begin
        StartEdit.Text := '';
        StartEdit.enabled := false;
        StartLabel.enabled := false;
      end;
    end;
  end;
  if (Sender = StartEdit) then
  begin
    bEditing := true;
    bBinEdited := true;
  end;
end;

procedure TDSSCubeEditor.HandleBeginEdit(Sender: TObject; var Key: Char);
begin
  bEditing := true;
end;

procedure TDSSCubeEditor.ActiveEditChange(Sender: TObject);
begin
  bEditing := true;
end;

procedure TDSSCubeEditor.CancelButtonClick(Sender: TObject);
begin
  Close;
end;

procedure TDSSCubeEditor.PagerChange(Sender: TObject);
begin
  CommitEdit;
  if (Pager.ActivePage.Name = 'MemoryControl') then
    InitCapacityPage;
end;

procedure TDSSCubeEditor.GetValueCounts;
var
  Map: TCubeDims;
  i: integer;
  Cells, Dims, Sums: integer;
  dState: TCubeDataState;
begin
  Map := TCubeDims.create(myObject, TCubeDim);
  dState := myObject.DesignState;
  Dims := strtoint(MaxDims.text);
  Sums := strtoint(maxSums.text);
  Cells := strtoint(maxCells.text);
  try
    Map.assign(myMap);
    myObject.maxDimensions := 16;
    myObject.maxSummaries := 32;
    myObject.maxCells := 200000000;
    for i := 0 to Map.count-1 do
      Map[i].ActiveFlag := diAsNeeded;
    myObject.DesignState := dsDimensionData;
    if assigned(myObject.DataSet) then
    begin
      bForceRefresh := true;
      if (myObject.DataSet.Active) then
        myObject.Refresh(Map, true)
      else
      begin
        if assigned(myObject.DimensionMap) then
          myObject.DimensionMap.assign(Map);
        myObject.DataSet.Active := true;
      end;
      for i := 0 to myMap.count-1 do
        myMap[i].ValueCount := myObject.DimensionMap[i].ValueCount;
    end;
  finally
    Map.free;
    myObject.DesignState := dstate;
    myObject.MaxDimensions := Dims;
    myObject.MaxSummaries := Sums;
    myObject.MaxCells := Cells;
  end;
end;

procedure TDSSCubeEditor.GetCellCountsClick(Sender: TObject);
begin
  GetValueCounts;
  UpdateLists;
  InitCapacityPage;
end;

procedure TDSSCubeEditor.FormKeyPress(Sender: TObject; var Key: Char);
begin
  if (Key = Chr(13)) then
    OKButtonClick(Self)
  else if (Key = Chr(27)) then
    CancelButtonClick(self);
end;

procedure TDSSCubeEditor.HelpButtonClick(Sender: TObject);
begin
  Application.HelpContext(hcDDecisionCubeEditor);
end;

end.
