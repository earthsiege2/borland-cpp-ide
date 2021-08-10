{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxgraph;

interface

uses
  SysUtils, Windows, Controls, StdCtrls, Graphics, DB, Classes, Grids,
  Dialogs, mxstore, mxbutton, mxConsts, MXDB, forms, extctrls, chart,
  series, teengine, TeeProcs, MXGrid;

type
  TDimEvent = procedure (Sender: TObject; iDim: Integer) of object;

  TSeriesType = (stNormal, stTemplate, st1D);

  TCustomDecisionGraph = class;

  TDecisionGraphDataLink = class(TDecisionDataLink)
  private
    FGraph: TCustomDecisionGraph;
  protected
    procedure DecisionDataEvent(Event: TDecisionDataEvent); override;
  public
    constructor Create(AGraph: TCustomDecisionGraph);
    destructor Destroy; override;
  end;

  TCustomDecisionGraph = class(TCustomChart)
  private
    FActive: Boolean;
    FDataLink: TDecisionGraphDataLink;
    FOwner: TComponent;
    FColors: array[0..15] of TColor;
    FGraphName: string;
    procedure NewDataStructure;
    procedure NewGraphLayout;
    function MakeNewSeries(iDim: Integer; index: integer; sType: TSeriesType): TChartSeries;
    function GetCleanDimName(iDim: Integer): string;
    function GetLabel(iDim: Integer; ValueIndex: Integer): string;
    function GetDecisionSource: TDecisionSource;
    procedure SetDecisionSource(Value: TDecisionSource);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    property DecisionSource: TDecisionSource read GetDecisionSource write SetDecisionSource;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Updated; override;
  end;

  TDecisionGraph = class(TCustomDecisionGraph)
  public
  published
    property DecisionSource;
    property AllowPanning;
    property AllowZoom;
    property AnimatedZoom;
    property AnimatedZoomSteps;
    property BackImage;
    property BackImageInside;
    property BackImageMode;
    property BottomWall;
    property Foot;
    property Gradient;
    property LeftWall;
    property MarginBottom;
    property MarginLeft;
    property MarginRight;
    property MarginTop;
    property Title;
    { TCustomChart Events }
    property OnAllowScroll;
    property OnClickAxis;
    property OnClickLegend;
    property OnClickSeries;
    property OnClickBackground;
    property OnGetLegendPos;
    property OnGetLegendRect;
    property OnScroll;
    property OnUndoZoom;
    property OnZoom;
    { TCustomAxisPanel properties }
    property AxisVisible;
    property BackColor;
    property BottomAxis;
    property Chart3DPercent;
    property ClipPoints;
    property Frame;
    property LeftAxis;
    property Legend;
    property MaxPointsPerPage;
    property Monochrome;
    property Page;
    property RightAxis;
    property ScaleLastPage;
    property SeriesList;
    property TopAxis;
    property View3D;
    property View3DWalls;
    { TCustomAxisPanel events }
    property OnAfterDraw;
    property OnGetAxisLabel;
    property OnGetLegendText;
    property OnGetNextAxisLabel;
    property OnPageChange;
    { TPanel properties }
    property Align;
    property Anchors;
    property AutoSize;
    property BevelInner;
    property BevelOuter;
    property BevelWidth;
    property BorderWidth;
    property BorderStyle;
    property Color;
    property Constraints;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property ParentColor;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Visible;
    { TPanel events }
    property OnCanResize;
    property OnClick;
    property OnConstrainedResize;
    property OnDblClick;
    property OnDockDrop;
    property OnDockOver;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnGetSiteInfo;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnResize;
    property OnStartDock;
    property OnStartDrag;
    property OnUnDock;
  end;

implementation

constructor TCustomDecisionGraph.Create(AOwner: TComponent);
var
  i: Integer;
begin
  inherited Create(AOwner);
  FOwner := AOwner;
  FActive := False;
  FDataLink := TDecisionGraphDataLink.Create(Self);
  FDataLink.FGraph := Self;
  FGraphName := '';
  for i := 0 to 15 do
    FColors[i] := GetDefaultColor(i);
  NewDataStructure; { to initialize the dimension information }
  RCS;
end;

destructor TCustomDecisionGraph.Destroy;
begin
  FDataLink.Free;
  FDataLink := nil;
  inherited Destroy;
end;

procedure TCustomDecisionGraph.Updated;
begin
  inherited Updated;
  NewGraphLayout;       { Force data update in case series were manipulated. }
end;
procedure TCustomDecisionGraph.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited;
  if (AComponent is TPivotButton) and (Operation = opInsert) then
  begin
    if assigned(DecisionSource) then
      TPivotButton(AComponent).DecisionSource := DecisionSource;
  end;
end;

procedure TCustomDecisionGraph.NewDataStructure;
var
  i: Integer;
  aSeries: TChartSeries;  
begin
  if assigned(DecisionSource) and DecisionSource.Ready then
    with DecisionSource do
    begin
    {
      This code is executed when the dataset has changed is some way.  Note
      that we only execute here when the dataset is active, so if the dataset
      goes inactive, all series information is preserved until the next time
      the dataset goes active.

      This code is used to clean up templates which are no longer in use,
      and to make new ones as needed for newly added dimensions
    }
    for i := 0 to SeriesCount-1 do
    begin
      if (tssIsTemplate in series[i].style) then
        series[i].style := series[i].style - [tssIsPersistent];
    end;
    { For each dimension, build a new template or use an old one if it exists }
    for i := 0 to DecisionSource.nDims-1 do
    begin
      aSeries := MakeNewSeries(i, 0, stTemplate);
      aSeries.style := aSeries.style + [tssIsPersistent];   { tag it as in use }
    end;
    { Now delete unused Templates, whether or not they are marked persistent. }
      for i := SeriesCount-1 downto 0 do
      begin
        aSeries := series[i];
        if (tssIsTemplate in aSeries.style) and not(tssIsPersistent in aSeries.style)
        and not (csAncestor in Series[i].ComponentState) then
        begin
          RemoveSeries(aSeries);
     	  aSeries.Free;
        end;
      end;
    end;
  NewGraphLayout;
end;

{
  NewGraphLayout:  this routine is called when the crosstab source pivots or
                   some other change has occurred in the display
}

procedure TCustomDecisionGraph.NewGraphLayout;
var
  I,J:Integer;
  nSeries: Integer;
  aSeries: TChartSeries;
  RowDim:  Integer;
  ColDim:  Integer;
begin
  {
    Always display the first RowDim graphed against the first ColDim
    if there is only one active Row dimension or only one active Col dimension,
    then use that one in a one-dimensional graph

    Before changing to the current pivot state, make a pass through the previous
    series set and do the following:
    1.  if a series is active and the Identifier field is not set, that means that
        it was added manually by the user.  All such series are marked
        tssIsPersistent and are given an identifier (fGraphName) which attaches
        them to the pivot state in which they were created.
    2.  Mark any series linked to a persistent series as also persistent
    3.  Mark all series inactive.  Later activate the ones in use for the current pivot state
  }
  for i := 0 to SeriesCount-1 do
  begin
    if (Series[i].active) and (Series[i].identifier = '') then
    begin
      Series[i].style := Series[i].style + [tssIsPersistent];
      Series[i].identifier := '::' + fGraphName;  { intl ok }
    end;
    if (tssIsPersistent in Series[i].style) then
    begin
      for j := 0 to Series[i].LinkedSeries.count-1 do
      begin
        TChartSeries(Series[i].LinkedSeries[j]).style := TChartSeries(Series[i].LinkedSeries[j]).style + [tssIsPersistent];
      end;
    end;
    Series[i].Active := False;
  end;
  if assigned(DecisionSource) and DecisionSource.Ready then
  begin
    RowDim := DecisionSource.GetActiveDim(dgRow,0,true);
    ColDim := DecisionSource.GetActiveDim(dgCol,0,true);
  end
  else
  begin
    RowDim := -1;
    ColDim := -1;
  end;
  if (RowDim >= 0) or (ColDim >= 0) then
  begin
    with DecisionSource do
    begin
      if (ColDim < 0) then
      begin
        ColDim := RowDim;
        RowDim := -1;
      end;
      fGraphName := GetDimensionName(ColDim);
      if (RowDim >= 0) then
        fGraphName := fGraphName + '+' + GetDimensionName(RowDim);
      {
        if RowDim is a real dimension, iterate over its values and build a
        series for ColDIm for each value.  If RowDIm <0, build one series
        which iterates all values and builds a 1d graph for ColDim
      }
      if (RowDim < 0) then
        nSeries := 1
      else
        nSeries := GetDimensionMemberCount(RowDim);
      for i := 0 to nSeries-1 do
      begin
        if (RowDim < 0) then
        begin
          aSeries := MakeNewSeries(ColDim, 0, St1D);
          aSeries.ColorEachPoint := true;
        end
        else
          aSeries := MakeNewSeries(RowDim, i, stNormal);
        aSeries.clear;
        for j := 0 to DecisionSource.GetDimensionMemberCount(ColDim)-1 do
        begin
          aSeries.AddY(DecisionSource.Get2DDataAsVariant(RowDim,ColDim,i,j),
          GetLabel(ColDim,j), clTeeColor);
        end;
        aSeries.active := True;
      end;
      { title the x-axis graph with ColDim }
      if (ColDim >= 0) then
      begin
        BottomAxis.Title.Caption := DecisionSource.GetDimensionName(ColDim);
        TopAxis.Title.Caption := DecisionSource.GetDimensionName(ColDim);
      end;
      { title the y-axis with the summary name }
      if (DecisionSource.nSums > 0) then
      begin
        LeftAxis.Title.Caption := DecisionSource.GetSummaryName(DecisionSource.CurrentSum);
        RightAxis.Title.Caption := DecisionSource.GetSummaryName(DecisionSource.CurrentSum);
      end
      else
      begin
        LeftAxis.Title.Caption := '';
        RightAxis.Title.Caption := '';
      end;
    end;
    {
      Add the axis labels

      Now remove any series which are not currently in use, are not templates,
      or are not marked as persistent.  Mark persistent series which were
      created by the user active if they match the Current Graph Name identifier.
    }
    for i := SeriesCount-1 downto 0 do
    begin
      aSeries := Series[i];
      if (aSeries.Active) or (tssIsTemplate in aSeries.style) then
        Continue;
      if (tssIsPersistent in aSeries.style)then
      begin
        aSeries.Active := (aSeries.Identifier = '::' + fGraphName); { intl ok }
        continue;
      end;
      if (csAncestor in Series[i].ComponentState) then Continue; { don't remove if from ancestor }
      RemoveSeries(aSeries);
      aSeries.Free;
    end;
  end
  else   				{ quiescent state }
  begin
    fGraphName := '';
    for i := 0 to SeriesCount-1 do
      Series[i].Active := False;
    BottomAxis.Title.Caption := '';
    TopAxis.Title.Caption := '';
    LeftAxis.Title.Caption := '';
    RightAxis.Title.Caption := '';
  end;

  for i := 0 to ControlCount-1 do
  begin
    if (Controls[i] is TPivotButton) then
    begin
      TPivotButton(Controls[i]).NewState;
    end;
  end;
end;

function TCustomDecisionGraph.MakeNewSeries(iDim: Integer; index: integer; sType: tSeriesType): TChartSeries;
var
  i, j: Integer;
  sName, sTempName, sTitle: string;
begin
  Result := nil;
  sTempName := sTemplatePrefix + DecisionSource.GetDimensionName(iDim);   { name of the template for this dim }
  case sType of
    stNormal:
    begin
      sName := GetCleanDimName(iDim) + '_F' + inttostr(index);
      sTitle := GetLabel(iDim, index);
    end;
    stTemplate:
    begin
      sName := GetCleanDimName(iDim);
      sTitle := sTempName;
    end;
    st1D:
    begin
      sName := GetCleanDimName(iDim) + '_1D';
      sTitle := '1D ' + sTempName;
    end;
  end;

  for j := 0 to SeriesCount-1 do
  begin
    if (Series[j].Name = sName) or (Series[j].Identifier = sTitle) then
      Result := series[j];
  end;
  { if now found, then add a new series }
  if not assigned(Result) then
  begin
    if (sType <> stTemplate) then
    begin
      for i := 0 to SeriesCount-1 do   { search for the relevant template, and use it }
      begin
        if (series[i].Identifier = sTempName) then
        begin
          Result := CreateNewSeries(self.Parent, self, TChartSeriesClass(Series[i].ClassType), nil);
          Result.Assign(Series[i]);
          break;
        end;
      end;
    end;
    if not assigned(Result) then    { default if template not found or creating a template }
      Result := CreateNewSeries(self.Parent, self, TBarSeries, nil);
    Result.Identifier := sTitle;
    Result.Style := [tssHideDataSource, tssDenyClone];
    if (sType = stTemplate) then
      Result.style := Result.style + [tssIsTemplate, tssDenyDelete];
    Result.Marks.Visible := False;
    Result.SeriesColor := FColors[index mod 16];
    Result.Title := sTitle;
  end;
end;

{ These are internal routines to service external hooks. }

function TCustomDecisionGraph.GetDecisionSource: TDecisionSource;
begin
  Result := TDecisionSource(FDataLink.DecisionSource);
end;

procedure TCustomDecisionGraph.SetDecisionSource(Value: TDecisionSource);
var
  oldSource: TDecisionSource;
begin
  oldSource := FDatalink.DecisionSource;
  FDataLink.DecisionSource := Value;
  if (Value <> oldSource) then NewDataStructure;
end;

function TCustomDecisionGraph.GetCleanDimName(iDim: Integer): string;
var
  i: integer;
  postName: string;
  x: char;
begin
  Result := DecisionSource.GetDimensionName(iDim);
  Result := AnsiUpperCase(Result);
  i := 1;
  while (i <= length(Result)) do
  begin
    x := Result[i];
    if (x in LeadBytes) then
    begin
      Result[i] := '_';
      Result[i+1] := '_';
      Inc(i);
    end
    else if (x<'0') or ((X>'9') and (x<'A')) or (x>'Z') then
    begin
      Result[i] := '_';
    end;
    Inc(i);
  end;
  if (Copy(Self.Name,1,13) = 'DecisionGraph') then
  begin
    postName := Copy(self.Name,14,length(self.Name));
    if (postName <> '1') then Result := Result + '_' + postName;
  end
  else
    Result := Result + '_' + self.Name;
end;

function TCustomDecisionGraph.GetLabel(iDim: Integer; ValueIndex: Integer):string;
begin
  Result := '';
  if assigned(DecisionSource) then
    Result := DecisionSource.GetMemberAsString(IDim, ValueIndex);
end;

  { Datalink Methods }

procedure TDecisionGraphDataLink.DecisionDataEvent(Event: TDecisionDataEvent);
begin
  if not assigned(FGraph) then Exit;
  if FBlocked then Exit;
  FBlocked := True;
  case Event of
    xeSummaryChanged : FGraph.NewGraphLayout;
    xePivot          : FGraph.NewGraphLayout;
    xeNewMetaData    : FGraph.NewDataStructure;
    xeStateChanged   : FGraph.NewGraphLayout;
    xeSourceChange:
    begin
      FGraph.SetDecisionSource(FDecisionSource);
      FGraph.NewDataStructure;
    end;
  end;
  FBlocked := False;
end;

constructor TDecisionGraphDataLink.Create(AGraph: TCustomDecisionGraph);
begin
  FGraph := AGraph;
end;

destructor TDecisionGraphDataLink.Destroy;
begin
  inherited Destroy;
end;

end.


