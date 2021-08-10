{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit MXReg;

interface

uses
  DsgnIntf, ChartReg, Chart;

type
  TDSSChartCompEditor = class(TChartCompEditor)
  public
    procedure Edit; override;
  end;

  procedure Register;

implementation

uses
  SysUtils, Classes, MXGrid, MXPivsrc, MXDB, MXdConst,
  Forms, Graphics, StdCtrls, Comctrls, mxstore, Controls,
  DBTables, mxgraph, BDEConst, mxbutton, mxtables, mxdssqry, mxdimedt, mxdcube,
  EditChar;

{ TQueryEditor }

type
  TDQueryEditor = class(TComponentEditor)
  public
    procedure ExecuteVerb(Index: Integer); override;
    function GetVerb(Index: Integer): string; override;
    function GetVerbCount: Integer; override;
  end;


procedure TDQueryEditor.ExecuteVerb(Index: Integer);
var
  Query: TQuery;
begin
  Query := Component as TQuery;
  case Index of
    0: ShowDSSQueryEditor(Designer, Query);
  end;
end;

function TDQueryEditor.GetVerb(Index: Integer): string;
begin
  case Index of
    0: Result := sQueryVerb1;
  end;
end;

function TDQueryEditor.GetVerbCount: Integer;
begin
  Result := 1;
end;

  { TSourceEditor }

type
  TSourceEditor = class(TComponentEditor)
  public
    procedure ExecuteVerb(Index: Integer); override;
    function GetVerb(Index: Integer): string; override;
    function GetVerbCount: Integer; override;
  end;

procedure TSourceEditor.ExecuteVerb(Index: Integer);
var
  Source: TDecisionSource;
begin
  Source := Component as TDecisionSource;
  case Index of
    0:
    begin
      Source.SparseRows := not Source.SparseRows;
      Source.SparseCols := Source.SparseRows;
    end;
  end;
end;

function TSourceEditor.GetVerb(Index: Integer): string;
var
  Source: TDecisionSource;
begin
  Source := Component as TDecisionSource;
  case Index of
    0:
    begin
      if Source.SparseRows then
        Result := sSourceVerb0
      else
        Result := sSourceVerb1;
    end;
  end;
end;

function TSourceEditor.GetVerbCount: Integer;
begin
  Result := 1;
end;

 { TCubeEditor }

type
  TCubeEditor = class(TComponentEditor)
  public
    procedure ExecuteVerb(Index: Integer); override;
    function GetVerb(Index: Integer): string; override;
    function GetVerbCount: Integer; override;
  end;

procedure TCubeEditor.ExecuteVerb(Index: Integer);
var
  Cube: TDecisionCube;
begin
  Cube := Component as TDecisionCube;
  case Index of
    0: ShowDSSCubeEditor(Designer, Cube);
    1:
    begin
      if (Cube.DataSet is TQuery) then
        ShowDssQueryEditor(Designer,TQuery(Cube.DataSet));
    end;
  end;
end;

function TCubeEditor.GetVerb(Index: Integer): string;
begin
  case Index of
    0: Result := SCubeVerb0;
    1: Result := SCubeVerb1;
  end;
end;

function TCubeEditor.GetVerbCount: Integer;
var
  Cube: TDecisionCube;
begin
  Cube := Component as TDecisionCube;
  if (Cube.DataSet is TQuery) and not (Cube.DataSet is TDecisionQuery) then
    Result := 2
  else
    Result := 1;
end;

  { TDSSChartCompEditor }

procedure TDSSChartCompEditor.Edit;
begin
  EditDSSChart(nil, TCustomChart(Component));
end;

  { TGridEditor }

type
  TGridEditor = class(TComponentEditor)
  public
    procedure ExecuteVerb(Index: Integer); override;
    function GetVerb(Index: Integer): string; override;
    function GetVerbCount: Integer; override;
  end;

procedure TGridEditor.ExecuteVerb(Index: Integer);
var
  Grid: TDecisionGrid;
begin
  Grid := Component as TDecisionGrid;
  case Index of
    0: Grid.Totals := not Grid.Totals;
  end;
end;

function TGridEditor.GetVerb(Index: Integer): string;
begin
  case Index of
    0: Result := sGridVerb0;
  end;
end;

function TGridEditor.GetVerbCount: Integer;
begin
  Result := 1;
end;

  { TDecisionGridDimsProperty }

type
  TDecisionGridDimsProperty = class(TComponentProperty)
  public
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
  end;

function TDecisionGridDimsProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

function TDecisionGridDimsProperty.GetValue: String;
begin
  Result := '(' + TDisplayDims.ClassName + ')';
end;

procedure TDecisionGridDimsProperty.Edit;
begin
  ShowDisplayDimEditor(Designer, GetComponent(0) as TDecisionGrid);
end;

  { TDimensionMapProperty }

type
  TDimensionMapProperty = class(TComponentProperty)
  public
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
  end;

function TDimensionMapProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

function TDimensionMapProperty.GetValue: String;
begin
  Result := 'TDimensionMaps';
end;

procedure TDimensionMapProperty.Edit;
begin
  ShowDSSCubeEditor(Designer, GetComponent(0)as TDecisionCube);
end;

  { TSummaryMapProperty }

type
  TSummaryMapProperty = class(TComponentProperty)
  public
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
  end;

function TSummaryMapProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

function TSummaryMapProperty.GetValue: String;
begin
  Result := 'TSummaryMaps';
end;

procedure TSummaryMapProperty.Edit;
begin
  ShowDSSQueryEditor(Designer, GetComponent(0) as TDecisionQuery);
end;

  { Registration }

procedure Register;
begin
  RegisterComponents(sComponentTabName, [TDecisionCube, TDecisionQuery,
                     TDecisionSource, TDecisionPivot, TDecisionGrid, TDecisionGraph]);

  RegisterNonActiveX([TDecisionCube, TDecisionQuery, TDecisionSource,
                      TDecisionPivot, TDecisionPivot, TDecisionGrid, TDecisionGraph,
                      TCustomDecisionGrid, TCustomDecisionGraph], axrIncludeDescendants);

  RegisterComponentEditor(TDecisionQuery, TDQueryEditor);
  RegisterComponentEditor(TDecisionCube, TCubeEditor);
  RegisterComponentEditor(TDecisionSource, TSourceEditor);
  RegisterComponentEditor(TDecisionGrid, TGridEditor);
  RegisterComponentEditor(TDecisionGraph,TDSSChartCompEditor);

  RegisterPropertyEditor(TypeInfo(TCollection), TDecisionGrid, 'Dimensions', TDecisionGridDimsProperty);
  RegisterPropertyEditor(TypeInfo(TCollection), TDecisionCube, 'DimensionMap', TDimensionMapProperty);
  RegisterPropertyEditor(TypeInfo(TCollection), TDecisionQuery, 'SummaryMap', TSummaryMapProperty);
  RegisterPropertyEditor(TypeInfo(TDate), nil, '', TDateProperty);
end;

end.

