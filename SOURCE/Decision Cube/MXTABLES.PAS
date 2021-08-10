{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxtables;

interface

uses
  Windows, SysUtils, Graphics, Classes, Controls, Db, DBCommon, Bde,
  dbTables, mxcommon, mxqparse, mxqedcom, mxarrays;
  
type
  TQueryDim = class(TDimensionItem)
  public
    property Active;
  end;

  TQueryDimClass = class of TQueryDim;

  TQueryDims = class(TDimensionItems)
  private
  protected
    function GetQueryDim(Index: Integer): TQueryDim;
    procedure SetQueryDim(Index: Integer; Value: TQueryDim);
    constructor Create(Owner: TPersistent; ItemClass: TQueryDimClass);
  public
    function Add: TQueryDim;
    property Items[Index: Integer]: TQueryDim read GetQueryDim write SetQueryDim; default;
  end;

  TDecisionQuery = class(TQuery)
  end;

  function BuildDimensionMap(myQuery: TXtabQuery; Map: TQueryDims; SQLString: string): TQueryError;
  function BuildMasterDimensionMap(myQuery: TXtabQuery; Map: TQueryDims): TQueryError;
  function AddDimensionItem(myQuery: TXtabQuery; Map: TQueryDims; index: integer; Name: string): TQueryError;
  function RemoveDimensionItem(myQuery: TXtabQuery; Map: TQueryDims; index: integer): TQueryError;

implementation

uses
  mxstore, dbConsts, BDEConst, mxconsts;

{
  Build Dimension Map builds a correct map for the input Dataset
  The strategy for field naming differs depending on the type of dataset.
  for DecisionQuery:  Parses the masterSQL, assumies that the user intends
  all fields in query only if the query is a legal crosstab.
  for Queries:  Checks against the SQL string, assuming all are InQuery;
  for other Datasets: Assumes the Fields array is available

  This function attempts to preserve existing Mapitems.
  Field matching works as follows:

  Query, Decision Query projected fields have FieldName set to the value
  of their Projector.outputname at creation time, and it is never changed
  Matching is done against this name.
  Decision query derived fields have Map.DerivedFrom>=0 on creation.
  Fieldname set to Fieldname of the field on which they are based, and
  DimensionType set to the derived agg type.  The combination of type
  and the derived fieldname is used for matching.
  Name is never used for matching.
}

function BuildMasterDimensionMap(myQuery: TXtabQuery; Map: TQueryDims): TQueryError;
var
  i: integer;
  fQuery: TXtabQuery;
  SQLString: string;
begin
  fQuery := TXtabQuery.Create;
  fQuery.canDelete := false;
  try
    fQuery.DBHandle := myQuery.DBHandle;
    SQLString := myQuery.SQLString;
    if not CheckIfEmptyQuery(SQLString) then
    begin
      fQuery.SQLString := SQLString;
      fQuery.DeleteProjectors;
      SQLString := fQuery.SQLString;
    end;
    AddToQuerySelect(SQLString, '*') ;
    Result := BuildDimensionMap(fQuery, Map, SQLString);
    for i:= 0 to Map.count-1 do
      Map[i].active := false;
  finally
    fQuery.free;
  end;
end;

function BuildDimensionMap(myQuery: TXTabQuery; Map: TQueryDims; SQLString: string): TQueryError;
var
  j: Integer;
  NewItem: TQueryDim;
begin
  Result := tqeNotInitialized;
  if not assigned(Map) then Exit;
  {
    Set up a data base, TXTabQuery and get an
    initial projector list

    if the query string is empty, add a constant just to get it to parse
    without an error.  Then delete it.
  }
  if CheckifEmptyQUery(SQLString) then
  begin
    AddToQuerySelect(SQLString, '1') ;
    myQuery.SQLString := SQLString;
    for j := myQuery.NProjectors-1 downto 0 do
      myQuery.DeleteProjector(j);
  end
  else
    myQuery.SQLString := SQLString;
  {
    Pass back as a final result whether or not the query is legal
    Result := myQuery.isLegal;

    Now rebuild the dimension map.  Position items in the same order as the
    Query.

    First go through all the actually projected fields and see which
    ones match against the Map passed in.  Fields may be out of position,
    but cannot have different (fieldname,dimensiontype) combinations.

    First do the fields which are actually in the query (never derived fields)
  }
  Map.clear;
  for j := 0 to myQuery.NProjectors-1 do
  begin
    NewItem := Map.Add;
    if (NewItem.index <> j) then NewItem.Index := j;
    Map[j].Name := myQuery.Projector[j].OutputName;
    Map[j].FieldName := myQuery.Projector[j].CompareName;
    Map[j].BaseName := myQUery.Projector[j].BaseName;
    Map[j].DimensionType := MyQuery.Projector[j].ProjType;
    Map[j].FieldType := myQuery.Projector[j].FieldType;
    Map[j].active := True;
  end;
  MyQuery.FixUpGroupBys;
  Result := myQuery.isLegal;
end;

{
  Change the SQL query which will be run without changing the master query
  This function is used by the Cube manager to allow the running
  SQL to be altered from the Master
}

function AddDimensionItem(myQuery: TXtabQuery; Map: TQueryDims; index: integer; Name: string): TQueryError;
var
  proj: integer;
begin
  myQuery.canDelete := false;
  proj := myQuery.addNewItem(Map[index].basename,map[index].DimensionType, index, true, Name);
  Map[index].FieldName := myQuery.Projector[proj].CompareName;
  Map[index].Name := myQuery.Projector[proj].OutputName;
  Map[index].BaseName := myQuery.Projector[proj].BaseName;
  Map[index].DimensionType := MyQuery.Projector[proj].ProjType;
  Map[index].active := True;
  Result := tqeOK;
end;

function RemoveDimensionItem(myQuery: TXtabQuery; Map: TQueryDims; index: integer): TQueryError;
begin
  myQuery.canDelete := false;
  Map[index].active := false;
  myQuery.DeleteProjector(index);
  Result := myQuery.isLegal;
end;

  { DataCube Collection Definition }

constructor TQueryDims.Create(Owner: TPersistent; ItemClass: TQueryDimClass);
begin
  inherited Create(Owner, ItemClass);
end;

function TQueryDims.GetQueryDim(Index: Integer): TQueryDim;
begin
  Result := TQueryDim(inherited Items[Index]);
end;

procedure TQueryDims.SetQueryDim(Index: Integer; Value: TQueryDim);
begin
  Items[Index].Assign(Value);
end;

function TQueryDims.Add: TQueryDim;
begin
  Result := TQueryDim(inherited Add);
end;

end.
