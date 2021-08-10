{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

{ BDE Query Edit COM API  }

unit mxqedcom;

interface

uses
  Windows, BDE, ActiveX, ComObj, WinTypes, WinProcs;

const
  CLSID_IDSQL32: TGUID = (
      D1:  $FB99D700;
      D2:  $18B9;
      D3:  $11D0;
      D4:  ($a4, $cf, $0, $a0, $24, $c9, $19, $36));

  IID_IQStmt: TGUID = (
      D1:  $FB99D701;
      D2:  $18B9;
      D3:  $11D0;
      D4:  ($a4, $cf, $0, $a0, $24, $c9, $19, $36));


type
   UINT16 = Word;  { unsigned 16-bit }
   pUINT16 = ^UINT16;
   UINT32 = Cardinal;  { unsigned 32-bit }
   pVOID = Pointer;

  StmtType = (sTypeSelect, sTypeInsert, sTypeDelete, sTypeUpdate, sTypeDDL);

  { Enumerates the types of join }
  JoinType =  (joinNone, joinInner, joinLeft, joinRight, joinFull);

  {$Z4}
  QNodeType = (qnodeNA, qnodeAdd, qnodeAvg, qnodeCount, qnodeMax, qnodeMin, qnodeTotal,
               qnodeAlias, qnodeAnd, qnodeConstant, qnodeDivide, qnodeEqual,
               qnodeField, qnodeGreaterEq, qnodeGreater, qnodeLessEq, qnodeLike,
               qnodeLess, qnodeMultiply, qnodeNotEqual, qnodeNot, qnodeOr, qnodeSubtract,
               qnodeColumn, qnodeCast, qnodeAssign, qnodeIsNull, qnodeExists, qnodeVariable,
               qnodeSelect, qnodeNegate, qnodeUdf, qnodeIN, qnodeANY, qnodeALL, qnodeTrim,
               qnodeLower, qnodeUpper, qnodeSubstring, qnodeList, qnodeExtract, qnodeCorrVar,
               qnodeTrue, qnodeNotAnd, qnodeNotOr, qnodeUnknown, qnodeConcatenate,
               qnodeGetDateTime);

  pIExpr      = ^IExpr;
  pIField     = ^IField;
  pITable     = ^ITable;
  pIProjector = ^IProjector;
  pIOrderBy   = ^IOrderBy;
  pIGroupBy   = ^IGroupBy;
  pIJoinExpr  = ^IJoinExpr;
  pIJoin      = ^IJoin;
  pIQStmt     = ^IQStmt;

  ExprCat = (exprCatWhere, exprCatHaving);

  dialect_ansi = (DIALECT, ANSI, DIALECTANSI);

  { When an input table is deleted, all related items are deleted. }
  DeletedObj = record
    iNumProjector,
    iNumWhere,
    iNumJoin,
    iNumGroupBy,
    iNumHaving,
    iNumOrderBy: UINT16;
    pProjector: pIProjector;
    pWhere: pIExpr;
    pJoin: pIJoin;
    pGroupBy: pIGroupBy;
    pHaving: pIExpr;
    pOrderBy: pIOrderBy;   
  end;


  pDeletedObj = ^DeletedObj;
  ppDeletedObj = ^pDeletedObj;
    
  IField = class;
  IExpr = class;
     
  ITable = class(TObject)
  public
    function GetName(var Name: PChar): DBIResult; virtual; stdcall; abstract;
    function GetDbName(var DbName: PChar): DBIResult; virtual; stdcall; abstract;
    function GetDrvType(var DrvType: PChar): DBIResult; virtual; stdcall; abstract;
    function GetAlias(var Alias: PChar): DBIResult; virtual; stdcall; abstract;
    function FetchField(FldIndex: UINT16; var pField: IField): DBIResult; virtual; stdcall; abstract;
  end;

  IProjector = class(TObject)
  public
    function GetQualifier(var Qualifier: PChar): DBIResult; virtual; stdcall; abstract;
    function GetName(var Name: PChar): DBIResult; virtual; stdcall; abstract;
    function GetIsAliased(var IsAliased: LongBool): DBIResult; virtual; stdcall; abstract;
    {
      When the projector is a simple field or an aggregate of a simple field,
        GetBaseName gets the field name.
      else
        GetBaseName gets NULL.
    }
    function GetBaseName(var BaseName: PChar): DBIResult; virtual; stdcall; abstract;
    function FetchExpr(var ppExpr: IExpr): DBIResult; virtual; stdcall; abstract;
  end;

  IGroupBy = class(TObject)
  public
    function FetchField(var ppField: IField): DBIResult; virtual; stdcall; abstract;
  end;

  IOrderBy = class(TObject)
  public
    function GetPosition(var Position: UINT16): DBIResult; virtual; stdcall; abstract;
    function GetIsDescend(var IsDescend: LongBool): DBIResult; virtual; stdcall; abstract;
    function ChangeDescend(bDescend: LongBool): DBIResult; virtual; stdcall; abstract;
    function FetchProjector(var ppProjector: IProjector): DBIResult; virtual; stdcall; abstract;
  end;

  IField = class(TObject)
  public
    function GetName(var ppFldName: PChar): DBIResult; virtual; stdcall; abstract;
    function FetchTable(var ppTable: ITable): DBIResult; virtual; stdcall; abstract;
    function GetDataType(var iFldType: UINT16; var iSubType: UINT16): DBIResult; virtual; stdcall; abstract;
    function GetTable_Field(var Tbl_Fld: PChar): DBIResult; virtual; stdcall; abstract;
  end;

  IExpr = class(TObject)
  public
    function GetNodeType(var nodeType: QNodeType): DBIResult; virtual; stdcall; abstract;
    function GetNumbSubExprs(var number: UINT16): DBIResult; virtual; stdcall; abstract;
    function GetSQLText(var ppSQLText: PChar): DBIResult; virtual; stdcall; abstract;
    function FetchSubExpr(number:UINT16; var ppExpr:IExpr): DBIResult; virtual; stdcall; abstract;
    function AddSubExpr_Text(sqlText: PChar; var pObj: IExpr; pBefThisObj: IExpr): DBIResult; virtual; stdcall; abstract;
    function AddSubExpr_node(qNodeType: QNodeType; var pObj: IExpr; pBefThisObj: IExpr): DBIResult; virtual; stdcall; abstract;
    function AddSubExpr_field(pField: IField; var pObj: IExpr; pBefThisObj: pIExpr): DBIResult; virtual; stdcall; abstract;
    function ChangeNodeType(nodeType: QNodeType): DBIResult; virtual; stdcall; abstract;
    function DeleteSubExpr(pObj : IExpr): DBIResult; virtual; stdcall; abstract;
    function MoveSubExpr(pObj, pBefThisObj: IExpr): DBIResult; virtual; stdcall; abstract;
    function GetParentExpr(pRootExpr: IExpr; var ppParentExpr: IExpr; var ppNextSiblingExpr: IExpr): DBIResult; virtual; stdcall; abstract;
    function GetNumCells(var nCells : UINT16): DBIResult; virtual; stdcall; abstract;
    function GetCell(index : UINT16; var ppCell: IExpr; var ppText1: PChar; var ppText2: PChar): DBIResult; virtual; stdcall; abstract;
    { Only when it's a field node. }
    function FetchField(var ppField: IField): DBIResult; virtual; stdcall; abstract;
  end;

  IJoinExpr = class(IExpr)
  public
    function FetchFieldLeft(var ppField: IField): DBIResult; virtual; stdcall; abstract;
    function FetchFieldRight(var ppField: IField): DBIResult; virtual; stdcall; abstract;
  end;

  IJoin = class(TObject)
  public
    function FetchTableLeft(var ppTable: ITable): DBIResult; virtual; stdcall; abstract;
    function FetchTableRight(var ppTable: ITable): DBIResult; virtual; stdcall; abstract;
    function GetJoinType(var joinType: JoinType): DBIResult; virtual; stdcall; abstract;
    function GetNumExprs(var number: UINT16): DBIResult; virtual; stdcall; abstract;
    function GetSQLText(var ppSQLText: PChar): DBIResult; virtual; stdcall; abstract;
    function FetchJoinExpr(number: UINT16; var ppExpr: IExpr): DBIResult; virtual; stdcall; abstract;
    function GetIndexForJoinExpr(pJoinExpr: IJoinExpr; var index: UINT16): DBIResult; virtual; stdcall; abstract;
    function AddJoinExpr(FldNumLeft: UINT16; FldNumRight: UINT16; MathOp: QNodetype;
                         var ppObj: IExpr; pBefThisObj: IExpr): DBIResult; virtual; stdcall; abstract;
    function AddJoinExpr_useFldName(FldNameLeft: PChar; FldNameRight: PChar; MathOp: QNodetype;
                                    var ppObj: IExpr; pBefThisObj: IExpr): DBIResult; virtual; stdcall; abstract;
    function DeleteJoinExpr(pObj: IExpr): DBIResult; virtual; stdcall; abstract;
    function ChangeJoinType(JoinType_input: JoinType): DBIResult; virtual; stdcall; abstract;
  end;

  IQStmt = interface(IUnknown)
    function Initialize(hDb: hDBIDb; pszQuery: PChar): DBIResult; stdcall;
    function GetStmtType(var stmtType: StmtType): DBIResult; stdcall;
    function GetNumInputTables(var Num: UINT16): DBIResult; stdcall;
    function GetNumProjectors(var Num: UINT16): DBIResult; stdcall;
    function GetNumGroupBy(var Num: UINT16): DBIResult; stdcall;
    function GetNumOrderBy(var Num: UINT16): DBIResult; stdcall;
    function GetNumJoins(var Num: UINT16): DBIResult; stdcall;
    function GetHasWherePred(var Has: LongBool): DBIResult; stdcall;
    function GetHasHavingPred(var Has: LongBool): DBIResult; stdcall;
    function GetIsDistinct(var IsDistinct: LongBool): DBIResult; stdcall;
    function SetDistinct(IsDistinct: LongBool): DBIResult; stdcall;
    function GetSQLText(var sqlText: PChar; var DialectDrvType: UINT32; 
                        bInnerJoinUseKeyword: LongBool; lang: dialect_ansi): DBIResult; stdcall;
    function FetchInputTable(index: UINT16; var pTable: ITable): DBIResult; stdcall;
    function FetchProjector(index: UINT16; var pProjector: IProjector): DBIResult; stdcall;
    function FetchGroupBy(index: UINT16; var pGroupBy: IGroupBy): DBIResult; stdcall;
    function FetchOrderBy(index: UINT16; var pOrderBy: IOrderBy): DBIResult; stdcall;
    function FetchJoin(index: UINT16; var pJoin: IJoin): DBIResult; stdcall;
    function FetchWhereExpr(var Expr: IExpr): DBIResult; stdcall;
    function FetchHavingExpr(var Expr: IExpr): DBIResult; stdcall;
    function GetIndexForInputTable(pObj: ITable; var index:UINT16): DBIResult; stdcall;
    function GetIndexForJoin(pObj: IJoin; var index:UINT16): DBIResult;stdcall;
    function GetIndexForProjector(pObj: IProjector; var index:UINT16): DBIResult; stdcall;
    function GetIndexForGroupBy(pObj: IGroupBy; var index:UINT16): DBIResult; stdcall;
    function GetIndexForOrderBy(pObj: IOrderBy; var index:UINT16): DBIResult; stdcall;
    function AddInputTable(Name: PChar; DbName: PChar; DrvType: PChar; Alias: PChar;
                           var pObj: ITable; BefThisObj: ITable): DBIResult; stdcall;
    function DeleteInputTable(Table: ITable; var pDelObj: pDeletedObj): DBIResult; stdcall;
    function AddJoin(TableLeft: ITable; TableRight: ITable; eJoinType: JoinType;
                     var pObj: IJoin; BefThisObj: IJoin): DBIResult; stdcall;
    function DeleteJoin(Obj: IJoin): DBIResult; stdcall;
    function AddProjector_FldNum(Table: ITable; FldSeqNum: UINT16; var pObj: IProjector;
                                 BefThisObj: IProjector; bAddGroupBY: LongBool): DBIResult; stdcall;
    function AddProjector_field(Field: IField; var pObj: IProjector; BefThisObj: IProjector;
                                bAddGroupBY: LongBool): DBIResult; stdcall;
    function AddProjector_text(sqlText: PChar; var pObj: IProjector; BefThisObj: IProjector): DBIResult; stdcall;
    function AddProjector_node(qNodeType: QNodeType; var pObj: IProjector;
                               BefThisObj: IProjector; bAddGroupBy: LongBool): DBIResult; stdcall;
    function DeleteProjector(pObj: IProjector; var pDelObj: pDeletedObj): DBIResult; stdcall;

    { Create a default projector name for the input projector }
    function GenerateDefProjName(Proj: IProjector): DBIResult; stdcall;
    {
     If the input sqlText is a field, the format is qualifier.fieldName.
     Note: If the qualifier need to be quoted (e.g. contains special character,
           or keyword, or all numbers), it should be quoted in sqlText.
     If it is field, *ppField points to the field. Otherwise *ppField is NULL.
    }
    function IsField(sqlText: PChar; var pField: IField): DBIResult; stdcall;
    function AddGroupBy_FieldNo(pTable: ITable; FldIndex: UINT16; var pObj: IGroupBy;
                                pBefThisObj: IGroupBy): DBIResult; stdcall;
    function AddGroupBy_Field(pField: IField; var pObj: IGroupBy; pBefThisObj: IGroupBy): DBIResult; stdcall;
    function DeleteGroupBy(pObj: IGroupBy): DBIResult; stdcall;
    function AddGroupBy_automatic: DBIResult; stdcall;
    function AddOrderBy(pProjector: IProjector; iPosition: UINT16; bDesc: BOOL;
                        var pObj: IOrderBy; pBefThisObj: IOrderBy): DBIResult; stdcall;
    function DeleteOrderBy(pObj: IOrderBy): DBIResult; stdcall;
    function SetTableAlias(pTable: ITable; newAlias: PChar): DBIResult; stdcall;
    function SetProjectorName(pProj: IProjector; newName: PChar): DBIResult; stdcall;
    function MoveProjector(pObj, pBefThisObj: IProjector): DBIResult; stdcall;
    function MoveTable(pObj, pBefThisObj: ITable): DBIResult; stdcall;
    function MoveGroupBy(pObj, pBefThisObj: IGroupBy): DBIResult; stdcall;
    function MoveOrderBy(pObj, pBefThisObj: IOrderBy): DBIResult; stdcall;
    function MakeComment(pComment: PChar; bFront: LongBool): DBIResult; stdcall;
    function ExprTextToObj(var pExpr: IExpr; ec: ExprCat; rootExpr: IExpr): DBIResult; stdcall;
    function ExprObjToText(var pExpr: IExpr; rootExpr: IExpr): DBIResult; stdcall;
    function ProjTextToObj(pProj: IProjector): DBIResult; stdcall;
    function ProjObjToText(pProj: IProjector): DBIResult; stdcall;
end;

implementation

end.

