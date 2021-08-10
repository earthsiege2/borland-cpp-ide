{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxqparse;

interface

uses
  Windows, SysUtils, Classes, Dialogs, DB, DBTables, DBCommon,
  BDE, mxqedcom, DBConsts, Activex, ComObj, mxcommon, mxconsts;

type
  EQParseException = class(Exception);

  pRecProjInfo = ^recProjectorInfo;
  recProjectorInfo = record
    FieldNo: Integer;
    FieldType: TFieldType;
    OutputName: string;
    CompareName: string;
    BaseName: string;
    projType: TDimFlags;
  end;

  TQueryState = (txNone, txAddingSum, txAddingDim, txDeletingSum, txDeletingDim);

  TXtabQuery = class(TObject)
  private
    Fhdb: HDBIDB;
    pQStmt: IQStmt;
    FProjectors: TList;
    FDimensions: TList;
    FAggregates: TList;
    FcanDelete: boolean;
    FInitialized: boolean;
    procedure setSQLString(newStr: String);
    function getSQLString: string;
    function getNProjectors: Integer;
    function getNDimensions: Integer;
    function getNAggregates: Integer;
    function getProjector(Index: Integer): recProjectorInfo;
    function getAggregate(Index: Integer): recProjectorInfo;
    function getDimension(Index: Integer): recProjectorInfo;
    function getNTables: Integer;
    function getTableName(index: integer):string;
    procedure buildProjectorMaps;
    function XtabProjType(Expr: IExpr): TDimFlags;
    function GetProjFieldType(Proj: IProjector): TFieldType;
    function GetExprFieldType(Expr: IExpr): TFieldType;
  public
    function IsLegal: TQueryError;
    function AllDimensionsGrouped: Boolean;
    function AddNewItem(SQLTxt: string; newAgg: TDimFlags; index: integer; bGrouped: boolean; Name: string): integer;
    procedure DeleteProjector(ProjIndex: Integer);
    procedure FixUpGroupBys;
    procedure DeleteGroupBys;
    procedure DeleteDimensions;
    procedure DeleteSummaries;
    procedure DeleteProjectors;
    procedure AddWhereCondition(Condition: string);
    procedure AddWhereOp(FieldName: string; Condition: variant; Qtype: QNodeType);
    function getDialectSQLString: string;
    procedure AddTable(tableName: string);
    constructor Create;
    destructor Destroy; override;
    property canDelete: boolean read FcanDelete write FcanDelete;
    property Projector[Index: Integer]: recProjectorInfo read getProjector;
    property Aggregate[Index: Integer]: recProjectorInfo read getAggregate;
    property Dimension[Index: Integer]: recProjectorInfo read getDimension;
    property TableName [Index: Integer]: string read getTableName;
    property DBHandle: HdbiDB read Fhdb write Fhdb;
  published
    property SQLString: string read getSQLString write setSQLString;
    property NProjectors: Integer read getNProjectors;
    property NDimensions: Integer read getNDimensions;
    property NTables: Integer read getNTables;
    property NAggregates: Integer read getNAggregates;
  end;

  function ptToQNode(pt: TDimFlags): QNodeType;
  procedure BDEcheck(res: DBIResult);
  function BDEDLLPath: string;

implementation

function FormatVariantQuoted(Value: Variant): string;
var
  VarData: TVarData;
begin
  VarData := TVarData(Value);
  case TVarData(Value).vType of
    varDouble   : Result := FormatFloat('', Value);
    varCurrency : Result := FormatCurr('', Value);
    varDate     : Result := '"' + FormatDateTime('M/D/Y', Value) + '"';
    varInteger  : Result := FormatFloat('', Value);
    else
      Result := '"' + Value + '"';
  end;
end;

constructor TXTabQuery.create;
var
  bdepath: String;
begin
  { runtime registry initialization. }
  bdePath := BDEDLLPath;
  CreateRegKey('CLSID\{FB99D700-18B9-11D0-A4CF-00A024C91936}\InProcServer32', '', bdePath + 'IDSQL32.DLL');
  pQStmt := nil;
  FProjectors := TList.create;
  FDimensions := TList.create;
  FAggregates := TList.create;
  FcanDelete := false;
  FInitialized := false;
end;

destructor TXTabQuery.Destroy;
begin
  FProjectors.free;
  FDimensions.free;
  FAggregates.free;
  inherited Destroy;
end;

  { This initializes BDE with the SQL String - the parse tree is now ready for use}
  
procedure TXtabQuery.setSQLString(newStr: String);
const
  {
    !!! DO NOT REPLACE THESE WITH THE STANDARD IUnknown AND IClassFactory
    !!! SIGNATURES.  BDE EXPECTS THE FOLLOWING SIGNATURES RATHER THAN THE
    !!! STANDARD ONES IN ACTIVEX.PAS!
  }
  IID_BDE_IUnknown: TGUID = (
      D1:  $15030000;
      D2:  $0000;
      D3:  $0000;
      D4:  ($C0, $00, $00, $00, $00, $00, $00, $46));

  IID_BDE_IClassFactory: TGUID = (
      D1:  $16030000;
      D2:  $0000;
      D3:  $0000;
      D4:  ($C0, $00, $00, $00, $00, $00, $00, $46));
      
var
  nProjs, i: UINT16;
  proj: IProjector;
  ret: DBIResult;
  bDeleted: boolean;
  pDelObj: PDeletedObj;
  pQstmtFactory: IClassFactory;
  pQstmtUnknown: IUnknown;
begin
  if assigned(pQstmt) then pQstmt := nil;    { note: this calls release }
  if not assigned(pQstmt) then
  begin
    OleCheck(CoInitialize(nil));
    { ! DO NOT REPLACE IID_BDE_IClassFactory WITH IClassFactory.  See above. }
    OleCheck(CoGetClassObject(CLSID_IDSQL32, CLSCTX_INPROC_SERVER, nil, IID_BDE_IClassFactory, pQstmtFactory));
    { ! DO NOT REPLACE IID_BDE_IUnknown WITH IUnknown.  See above. }
    OleCheck(pQstmtFactory.CreateInstance(nil, IID_BDE_IUnknown, pQstmtUnknown));
    OleCheck(pQstmtUnknown.QueryInterface(IID_IQStmt, pQstmt));
  end;
  ret := pQstmt.Initialize(FhDb, PChar(newstr));
  if (ret = $2eaf) or (ret = $2eb7) then
    FixupGroupBys
  else
    BDECheck(ret);  { otherwise, surface the error. }
  FInitialized := true;
  BDECheck(pQStmt.GetNumProjectors(nProjs));
  bDeleted := false;
  if FcanDelete then
    for i := nProjs downto 1 do
    begin
      BDECheck(pQStmt.FetchProjector(i, proj));  { fetch the projector }
      BDECheck(pQStmt.ProjTextToObj(proj));
      if (GetProjFieldType(proj) in [ftUnknown,ftBytes, ftBlob]) then
      begin
        bDeleted := true;
        pQStmt.DeleteProjector(proj, pdelObj);
      end;
    end;
  if bDeleted then ShowMessage(SQParseRemovedField);
  buildProjectorMaps;
end;

{ Requests that BDE re-generate the string. }

function TXtabQuery.getSQLString: string;
var
  res: PChar;
  drvType: UINT32;
const
  useJoinKeyword = TRUE;
begin
  BDECheck(pQStmt.GetSQLText(res, drvType, useJoinKeyword, ANSI));
  Result := res;
end;

procedure TXtabQuery.AddTable(tableName: string);
var
  pTable: ITable;
begin
  BDECheck(pQStmt.AddInputTable(pchar(TableName), pchar(nil), nil, nil, pTable, nil));
end;

function TXtabQuery.getDialectSQLString: string;
var
  res: PChar;
  drvType: UINT32;
const
  useJoinKeyword = TRUE;
begin
  BDECheck(pQStmt.GetSQLText(res, drvType, useJoinKeyword, DIALECTANSI));
  Result := res;
end;

function TXtabQuery.IsLegal: TQueryError;
begin
  if (NDimensions <= 0) then
    Result := tqeNoDimensions
  else if (NAggregates <= 0) then
    Result := tqeNoAggs
  else if not AllDimensionsGrouped then
    Result := tqeNotGrouped
  else
    Result := tqeOK;
end;

function TXtabQuery.AllDimensionsGrouped : Boolean;
var
  nGroupedBy: UINT16;
begin
  Result := FALSE;
  BDECheck(pQStmt.GetNumGroupBy(nGroupedBy));
  if (nGroupedBy < NDimensions) then Exit;
  Result := TRUE;
end;

function TXtabQuery.AddNewItem(SQLTxt: string; newAgg: TDimFlags; index: integer; bGrouped: boolean; Name: string): integer;
var
  newProjExpr, newProjSubExpr: IExpr;
  befProj, newProj: IProjector;
  projField: IField;
  qnType: QNodeType;
  pDelObj: pDeletedObj;
begin
  newProj := nil;
  try
    befproj := nil;
    if (index < nProjectors) then
      BDECheck(pQStmt.FetchProjector(index + 1 ,befproj));  { fetch the projector }
    if (NewAgg = dimDimension) then  { add a new dimension }
    begin
      projField := nil;
      BDECheck(pQStmt.IsField(pchar(SQLTxt), projField));
      if (projField <> nil) then
        BDECheck(pQStmt.AddProjector_field(projField, newProj, befProj, true))  { add a new SUMMARY NODE }
      else
      begin
        BDECheck(pQStmt.AddProjector_text(pchar(SQLTxt), newProj, befProj));  { add a new SUMMARY NODE }
        BDECheck(pQStmt.ProjTextToObj(newproj));
      end;
    end
    else if (NewAgg = dimGenericAgg) then
    begin
      BDECheck(pQStmt.AddProjector_text(pchar(SQLTxt), newProj, befProj));  { add a new SUMMARY NODE }
      BDECheck(pQStmt.ProjTextToObj(newProj));
    end
    else  { add a new aggregator }
    begin
      qnType := ptToQNode(newAgg);  { convert to BDE QnodeType; }
      BDECheck(pQStmt.AddProjector_node(qnType, newProj, befProj, TRUE));  { add a new SUMMARY NODE }
      BDECheck(newproj.FetchExpr(newProjExpr));  { get the NEW expression -- First item is Summary node. }
      projField := nil;
      BDECheck(pQStmt.IsField(pchar(SQLTxt), projField));
      if (projField <> nil) then
        BDECheck(newProjExpr.AddSubExpr_field(projField, newProjSubExpr, nil))  { add the SQL for the argument to the agg. }
      else
      begin
        BDECheck(newProjExpr.AddSubExpr_text(pchar(SQLTxt), newProjSubExpr, nil)); { add the SQL for the argument to the agg. }
        BDECheck(pQStmt.ProjTextToObj(newproj));
      end;
    end;
    Result := Index;  { Result offset from 0 }
    if (name <> '') then
      BDECheck(pQStmt.SetProjectorName(newProj, pchar(name)))
    else
      BDECheck(pQStmt.GenerateDefProjName(newProj));
    buildProjectorMaps;
    if bGrouped then FixUpGroupBys;
  except
    on E: exception do
    begin
      if assigned(newproj) then pQStmt.DeleteProjector(newproj, pdelObj);
      raise EQParseException.create(e.message);
    end;
  end;
end;

procedure TXtabQuery.DeleteProjector(ProjIndex: Integer);
var
  proj: IProjector;
  projField: IField;
  nGroups: UINT16;
  groupby: IGroupBy;
  projExpr: iExpr;
  STRtEMP: pchar;
  fieldname: string;
  deleteName: string;
  nType: QnodeType;
  pDelObj: pDeletedObj;
  i: integer;
begin
  proj := nil;
  pQStmt.FetchProjector(ProjIndex + 1, proj);  { fetch the projector }
  try
    if (Projector[ProjIndex].projType = dimDimension) then
    begin
      BDECheck(proj.FetchExpr(projExpr));  { get its expression object }
      BDECheck(projExpr.GetNodeType(nType));
      if (nType = qnodeField) then  { if it's a field, delete it }
      begin
        projField := nil;
        BDECheck(projExpr.FetchField(projField));
        if (projField <> nil) then
        begin
          BDECheck(projField.GetTable_Field(strTemp));
          deleteName := strTemp;
          pQStmt.GetNumGroupBy(nGroups);
          for I := 0 to nGroups-1 do
          begin
            pQStmt.FetchGroupBy(I + 1, groupBy);
            groupBy.FetchField(projField);
            if (projField <> nil) then
            begin
              BDECheck(projField.GetTable_Field(strTemp));
              fieldName := strTemp;
              if (fieldName = deleteName) then
              begin
                pQStmt.DeleteGroupBy(groupBy);
                Break;
              end;
            end;
          end;
        end;
      end;
    end
    else
    begin
      {}
    end;
    pQStmt.DeleteProjector(proj, pDelObj);
    buildProjectorMaps;
  finally
    {}
  end;
end;

procedure TXtabQuery.DeleteGroupBys;
var
  nGroups: UINT16;
  groupby: IGroupBy;
  i: integer;
begin
  pQStmt.GetNumGroupBy(nGroups);
  for I := 0 to nGroups-1 do
  begin
    pQStmt.FetchGroupBy(1, groupBy);
    pQStmt.DeleteGroupBy(groupBy);
  end;
end;

procedure TXtabQuery.DeleteDimensions;
var
  i: integer;
begin
  for I := nProjectors-1 downto 0 do
  begin
    if (Projector[i].ProjType = dimDimension) then DeleteProjector(I);
  end;
  buildProjectorMaps;
end;

procedure TXtabQuery.DeleteSummaries;
var
  i: integer;
begin
  for I := nProjectors-1 downto 0 do
  begin
    if (Projector[i].ProjType <> dimDimension) then DeleteProjector(I);
  end;
  buildProjectorMaps;
end;

procedure TXtabQuery.DeleteProjectors;
var
  i: integer;
begin
  for I := nProjectors-1 downto 0 do
    DeleteProjector(I);
  buildProjectorMaps;
end;

procedure TXtabQuery.FixUpGroupBys;
var
  proj: IProjector;
  projField: IField;
  nGroups: UINT16;
  groupby: IGroupBy;
  projExpr: iExpr;
  i: integer;
  nType: qNodeTYpe;
begin
  pQStmt.GetNumGroupBy(nGroups);
  for I := 0 to nGroups-1 do
  begin
    pQStmt.FetchGroupBy(1, groupBy);
    pQStmt.DeleteGroupBy(groupBy);
  end;
  for i := 0 to NProjectors-1 do
  begin
    pQStmt.FetchProjector(i + 1, proj);  { fetch the projector }
    BDECheck(proj.FetchExpr(projExpr));  { get its expression object }
    if (XtabProjType(projExpr) = dimDimension) then
    begin
      BDECheck(projExpr.GetNodeType(nType));
      if (nType <> qnodeFIeld) then
        raise EQParseException.CreateRes(@sGroupOnExpressionError);
      projField := nil;
      BDECheck(projExpr.FetchField(projField));
      if (projField <> nil) then
        pQStmt.AddGroupBy_Field(projField, groupBy, nil);
    end;
  end;
  buildProjectorMaps;
end;

procedure TXTabQuery.AddWhereOp(FieldName: string; Condition: variant; Qtype: QNodeType);
var
  op: String;
begin
  case Qtype of
    qnodeEqual     : op := ' = ';
    qnodeGreaterEq : op := ' >= ';
    qnodeGreater   : op := ' > ';
    qnodeLessEq    : op := ' <= ';
    qnodeLess      : op := ' < ';
    qnodeNotEqual  : op := ' <> ';
    else
      op := ' = ';
  end;
  AddWhereCondition(FieldName + op + FormatVariantQuoted(Condition));
end;

procedure TXTabQuery.AddWhereCondition(Condition: String);
var
  whereExpr: iExpr;
  subExpr: iExpr;
  nType: QNodeType;
  oldCondition: pChar;
  i: integer;
  nSubs: UINT16;
begin
  BDECheck(pQStmt.FetchWhereExpr(whereExpr));
  BDECHeck(whereExpr.GetNodeType(nType));
  if (nType <> qNodeAnd) then
  begin
    BDECHECK(whereExpr.GetSQLText(oldCondition));
    BDECHECK(whereExpr.GetNumbSubExprs(nSubs));
    for i := 1 to nSubs do
    begin
      BDECHECK(whereExpr.FetchSubExpr(1, SubExpr));
      BDECHECK(whereExpr.DeleteSubExpr(SubExpr));
    end;
    BDECHECK(whereExpr.ChangeNodeType(qNodeAnd));
    BDECheck(whereExpr.AddSubExpr_Text(pchar(oldCondition), subExpr, nil));
  end;
  BDECheck(whereExpr.AddSubExpr_Text(pchar(Condition), subExpr, nil));
end;

function TXtabQuery.getNProjectors: Integer;
begin
  Result := FProjectors.count;
end;

function TXtabQuery.getNDimensions: Integer;
begin
  Result := FDimensions.count;
end;

function TXtabQuery.getNAggregates: Integer;
begin
  Result := FAggregates.Count;
end;

function TXtabQuery.getProjector(Index: Integer): recProjectorInfo;
begin
  Result := recProjectorInfo(FProjectors[index]^);
end;

function TXtabQuery.getAggregate(Index: Integer): recProjectorInfo;
begin
  Result := recProjectorInfo(FAggregates[index]^);
end;

function TXtabQuery.getDimension(Index: Integer): recProjectorInfo;
begin
  Result := recProjectorInfo(FDimensions[index]^);
end;

function TXTabQuery.getNTables: Integer;
var
  nTables: UINT16;

begin
  if assigned(pQStmt) and FInitialized then
  begin
    BDECheck(pQStmt.GetNumInputTables(nTables));
    Result := nTables;
  end
  else
    Result := 0;
end;

function TXTabQuery.getTableName(index: integer): string;
var
  pTable: ITable;
  temp: pChar;
begin
  BDECheck(pQStmt.FetchInputTable((index + 1), pTable));
  BDECheck(pTable.GetName(temp));
  Result := temp;
end;

procedure TXTabQuery.buildProjectorMaps;
var
  ind: integer;
  nProjs, i: UINT16;
  nSubs: UINT16;
  projExpr: IExpr;
  subExpr: IExpr;
  proj: IProjector;
  projfield: IField;
  strTemp: PChar;
  pInfo: pRecProjInfo;
  nType: QNodeType;
  dType, dSubType: UINT16;
  fError: string;
begin
  FProjectors.clear;  { clear the TLists. }
  FDimensions.clear;
  FAggregates.clear;
  fError := '';
  BDECheck(pQStmt.GetNumProjectors(nProjs));
  for i := 1 to nProjs do
  begin
    New(pInfo);
    try
      BDECheck(pQStmt.FetchProjector(i, proj));  { fetch the projector }
      BDECheck(proj.GetName(strTemp));  { get the output field name }
      BDECheck(proj.FetchExpr(projExpr));  { get its expression object }
      pInfo.FieldNo := i;
      pInfo.projType := XtabProjType(projExpr);
      FProjectors.add(pInfo);  { add to the field map }
      pInfo.OutputName := strTemp;
      BDECheck(projExpr.GetSQLText(strTemp));  { get the SQL for the argument to the agg }
      pInfo.CompareName := strTemp;
      {
        This is all to set the BaseName and the Fieldtype for all different types
        Note the Fieldtype is the type of the base field, not of the projector
      }
      if (pInfo.projType = dimDimension) then
      begin
        BDECheck(projExpr.GetNodeType(nType));  { get expr's node type; }
        if (nType = qnodeField) then
        begin
          projField := nil;
          BDECheck(projExpr.FetchField(projField));
          if (projField <> nil) then
          begin
            BDECheck(projField.GetTable_Field(strTemp));
            pInfo.BaseName := strTemp;
            BDECheck(projField.GetDataType(dType, dSubType));
            pInfo.FieldType := DataTypeMap[dType];
          end
          else
          begin
            pInfo.FieldType := ftUnknown;
            pInfo.BaseName := pInfo.CompareName;
          end;
        end
        else
        begin
          pInfo.FieldType := ftUnknown;
          pInfo.BaseName := pInfo.CompareName;
        end;
        FDimensions.add(pInfo);
      end
      else  { add an expression, either a single argument or multiply }
      begin
        if (AnsiUpperCase(pInfo.OutputName) = sCountStar) then
        begin
          pInfo.FieldType := ftUnknown;
          pInfo.BaseName := '*';
        end
        else
        begin
          BDECHECK(projExpr.GetNumbSubExprs(nSubs));
          if (nSubs = 0) then
            raise EQParseException.CreateRes(@sArgumentExpected)
          else if (nSubs > 1) then
          begin
            pInfo.FieldType := ftUnknown;  { don't allow a base type for complex expressions }
            pInfo.BaseName := pInfo.CompareName;
          end
          else
          begin
            BDECheck(projExpr.FetchSubExpr(1, subExpr));  { get the argument to the agg }
            BDECheck(subExpr.GetNodeType(nType));  { get expr's node type; }
            if (nType = qnodeField) then  { simple agg of a field }
            begin
              projField := nil;
              BDECheck(subExpr.FetchField(projField));
              if (projField <> nil) then
              begin
                BDECheck(projField.GetTable_Field(strTemp));
                pInfo.BaseName := strTemp;
                BDECheck(projField.GetDataType(dType, dSubType));
                pInfo.FieldType := DataTypeMap[dType];
              end
              else  { fieldtype of an expr that didn't get parse correctly }
              begin
                pInfo.FieldType := GetExprFieldType(subExpr);
                BDECheck(subExpr.GetSQLText(strtemp));
                pInfo.BaseName := strTemp;
              end;
            end
            else  { agg of something other than a field }
            begin
              BDECheck(subExpr.GetSQLText(strTemp));
              pInfo.FieldType := GetExprFieldType(subExpr);
              pInfo.BaseName := strTemp;
            end;
          end;
        end;
        FAggregates.add(pInfo);
      end;
    except
      on e: exception do
      begin
        ind := FProjectors.indexof(pInfo);
        if (ind >= 0) then FProjectors.Delete(ind);
        ind := FAggregates.indexof(pInfo);
        if (ind >= 0) then FAggregates.Delete(ind);
        ind := FDimensions.indexof(pInfo);
        if (ind >= 0) then FDimensions.Delete(ind);
        fError := e.message;
      end;
    end;
  end;
  if (fError <> '') then raise exception.Create(fError);
end;

{
  Determine the type of the expression passed in
  a GenericAgg
}

function TXtabQuery.XtabProjType(Expr: IExpr): TDimFlags;
var
  subExpr: IExpr;
  nType: QNodeType;
  i, nSubs: UINT16;
begin
  Result := dimDimension;
  BDECheck(Expr.GetNodeType(nType));
  case nType of
    qNodeField : Exit;
    qNodeAvg   : Result := dimAverage;
    qNodeCount : Result := dimCount;
    qnodeMax   : Result := dimMax;
    qnodeMin   : Result := dimMin;
    qnodeTotal : Result := dimSum;
    qnodeUnknown:
    begin
      Result := dimUnknown;
    end;
    else
    begin
      if (ntype in [qnodeAdd,qnodeConstant, qnodeDivide, qnodeMultiply,
      qnodeSubtract,qnodeCast,qnodeUdf,qnodeTrim,qnodeLower,
      qnodeUpper,qnodeSubstring,qnodeExtract,qnodeConcatenate])
      then
         Result := dimDimension
      else
        Result := dimUnknown;
    end;
  end;
  {
    if it is marked a dimension and we get here, it is not calculated expression
    Need to determine whether it contains an aggregator somewhere or not
    if so, type it as a "GenericAgg".  Otherwise, it is a dimension
  }
  if (Result = dimDimension) then
  begin
    BDECHECK(Expr.GetNumbSubExprs(nSubs));
    for i := 1 to nSubs do
    begin
      BDECheck(Expr.FetchSubExpr(i, subExpr));
      if (XtabProjType(subExpr) in [dimAverage, dimCount, dimMax, dimMin, dimSum, dimGenericAgg]) then
      begin
        Result := dimGenericAgg;
      end;
    end;
  end;
end;

function TXtabQuery.GetProjFieldType(Proj: IProjector): TFieldType;
var
  projExpr: iExpr;
  nType: QNodeType;
begin
  BDECheck(proj.FetchExpr (projExpr));  { get its expression object }
  Result := GetExprFieldType(projExpr);
  if (Result = ftUnknown) then
  begin
    BDECheck(projExpr.GetNodeType(nType));
    if (nType = qnodeConstant) then Result := ftFloat;
  end;
end;

{
  this is a very conservative field typing routine
  if it really doesn't know, it returns ftUnknown
  Type information can be gotten from fieldInfo or operators
}

function TXtabQuery.GetExprFieldType(Expr: IExpr): TFieldType;
var
  subExpr: IExpr;
  nType: QNodeType;
  i, nSubs: UINT16;
  projfield: IField;
  dType, dSubType: UINT16;
begin
  Result := ftUnknown;
  BDECheck(Expr.GetNodeType(nType));
  case nType of
    qNodeField:
    begin
      BDECheck(Expr.FetchField(projField));
      BDECheck(projField.GetDataType(dType, dSubType));
      Result := DataTypeMap[dType];
    end;
    qNodeCount,
    qNodeMultiply,
    qNodeDivide,
    qNodeSubtract,
    qNodeAvg,
    qNodeTotal: Result := ftFloat;
    qNodeUpper,
    qNodeLower,
    qNodeExtract,
    qNodeConcatenate,
    qNodeTrim,
    qNodeSubString: Result := ftString;
    else
    begin
      BDECHECK(Expr.GetNumbSubExprs(nSubs));
      for i := 1 to nSubs do
      begin
        BDECheck(Expr.FetchSubExpr(i, subExpr));
        Result := GetExprFieldType(subExpr);
        if (Result <> ftUnknown) then Break;
      end;
    end;
  end;
end;

procedure BDEcheck(res: DBIResult);
begin
  if (res <> DBIERR_NONE) then DBIError(res);
end;

function ptToQNode(pt: TDimFlags): QNodeType;
begin
  case pt of
    dimAverage: Result := QNodeAvg;
    dimCount: Result := QNodeCount;
    dimMin: Result := QNodeMin;
    dimMax: Result := QNodeMax;
    dimSum: Result := QNodeTotal;
    else
      Result := QNodeUnknown;
  end;
end;

function BDEDLLPath: string;
const
  BDEPath = 'SOFTWARE\BORLAND\DATABASE ENGINE';
  DLLpath = 'DLLPATH';
var
  Key: HKey;
  StrLen: Integer;
  Buffer: array[0..MAX_PATH] of Char;
begin
  if RegOpenKeyEx(HKEY_LOCAL_MACHINE, BDEPath, 0, KEY_READ, Key) = ERROR_SUCCESS then
  begin
    StrLen := SizeOf(Buffer);
    if (RegQueryValueEx(Key, DLLPath,  nil, nil, @Buffer, @StrLen) = ERROR_SUCCESS) then
    begin
      Result := Buffer;
      { Check for multiple directories, use only the first one }
      if (Pos(';', Result) > 0) then Result := Copy(Result, 1, Pos(';', Result) - 1);
      if (Length(Result) > 2) and (not IsPathDelimiter(Result, Length(Result))) then
        Result := Result + '\';
    end;
    RegCloseKey(Key);
  end;
end;

end.
