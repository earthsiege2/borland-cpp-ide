// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXQEDCOM.pas' rev: 6.00

#ifndef MXQEDCOMHPP
#define MXQEDCOMHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <BDE.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxqedcom
{
//-- type declarations -------------------------------------------------------
typedef Word UINT16;

typedef Word *pUINT16;

typedef unsigned UINT32;

typedef void *pVOID;

#pragma option push -b-
enum StmtType { sTypeSelect, sTypeInsert, sTypeDelete, sTypeUpdate, sTypeDDL };
#pragma option pop

#pragma option push -b-
enum JoinType { joinNone, joinInner, joinLeft, joinRight, joinFull };
#pragma option pop

#pragma option push -b
enum QNodeType { qnodeNA, qnodeAdd, qnodeAvg, qnodeCount, qnodeMax, qnodeMin, qnodeTotal, qnodeAlias, qnodeAnd, qnodeConstant, qnodeDivide, qnodeEqual, qnodeField, qnodeGreaterEq, qnodeGreater, qnodeLessEq, qnodeLike, qnodeLess, qnodeMultiply, qnodeNotEqual, qnodeNot, qnodeOr, qnodeSubtract, qnodeColumn, qnodeCast, qnodeAssign, qnodeIsNull, qnodeExists, qnodeVariable, qnodeSelect, qnodeNegate, qnodeUdf, qnodeIN, qnodeANY, qnodeALL, qnodeTrim, qnodeLower, qnodeUpper, qnodeSubstring, qnodeList, qnodeExtract, qnodeCorrVar, qnodeTrue, qnodeNotAnd, qnodeNotOr, qnodeUnknown, qnodeConcatenate, qnodeGetDateTime };
#pragma option pop

class DELPHICLASS IExpr;
typedef IExpr* *pIExpr;

class DELPHICLASS IField;
typedef IField* *pIField;

class DELPHICLASS ITable;
typedef ITable* *pITable;

class DELPHICLASS IProjector;
typedef IProjector* *pIProjector;

class DELPHICLASS IOrderBy;
typedef IOrderBy* *pIOrderBy;

class DELPHICLASS IGroupBy;
typedef IGroupBy* *pIGroupBy;

class DELPHICLASS IJoinExpr;
typedef IJoinExpr* *pIJoinExpr;

class DELPHICLASS IJoin;
typedef IJoin* *pIJoin;

__interface IQStmt;
typedef System::DelphiInterface<IQStmt> _di_IQStmt;
typedef _di_IQStmt *pIQStmt;

#pragma option push -b
enum ExprCat { exprCatWhere, exprCatHaving };
#pragma option pop

#pragma option push -b
enum dialect_ansi { DIALECT, ANSI, DIALECTANSI };
#pragma option pop

#pragma pack(push, 4)
struct DeletedObj
{
	Word iNumProjector;
	Word iNumWhere;
	Word iNumJoin;
	Word iNumGroupBy;
	Word iNumHaving;
	Word iNumOrderBy;
	IProjector* *pProjector;
	IExpr* *pWhere;
	IJoin* *pJoin;
	IGroupBy* *pGroupBy;
	IExpr* *pHaving;
	IOrderBy* *pOrderBy;
} ;
#pragma pack(pop)

typedef DeletedObj *pDeletedObj;

typedef pDeletedObj *ppDeletedObj;

class PASCALIMPLEMENTATION ITable : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual Word __stdcall GetName(char * &Name) = 0 ;
	virtual Word __stdcall GetDbName(char * &DbName) = 0 ;
	virtual Word __stdcall GetDrvType(char * &DrvType) = 0 ;
	virtual Word __stdcall GetAlias(char * &Alias) = 0 ;
	virtual Word __stdcall FetchField(Word FldIndex, IField* &pField) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall ITable(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ITable(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION IProjector : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual Word __stdcall GetQualifier(char * &Qualifier) = 0 ;
	virtual Word __stdcall GetName(char * &Name) = 0 ;
	virtual Word __stdcall GetIsAliased(BOOL &IsAliased) = 0 ;
	virtual Word __stdcall GetBaseName(char * &BaseName) = 0 ;
	virtual Word __stdcall FetchExpr(IExpr* &ppExpr) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IProjector(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IProjector(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION IGroupBy : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual Word __stdcall FetchField(IField* &ppField) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IGroupBy(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IGroupBy(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION IOrderBy : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual Word __stdcall GetPosition(Word &Position) = 0 ;
	virtual Word __stdcall GetIsDescend(BOOL &IsDescend) = 0 ;
	virtual Word __stdcall ChangeDescend(BOOL bDescend) = 0 ;
	virtual Word __stdcall FetchProjector(IProjector* &ppProjector) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IOrderBy(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IOrderBy(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION IField : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual Word __stdcall GetName(char * &ppFldName) = 0 ;
	virtual Word __stdcall FetchTable(ITable* &ppTable) = 0 ;
	virtual Word __stdcall GetDataType(Word &iFldType, Word &iSubType) = 0 ;
	virtual Word __stdcall GetTable_Field(char * &Tbl_Fld) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IField(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IField(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION IExpr : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual Word __stdcall GetNodeType(QNodeType &nodeType) = 0 ;
	virtual Word __stdcall GetNumbSubExprs(Word &number) = 0 ;
	virtual Word __stdcall GetSQLText(char * &ppSQLText) = 0 ;
	virtual Word __stdcall FetchSubExpr(Word number, IExpr* &ppExpr) = 0 ;
	virtual Word __stdcall AddSubExpr_Text(char * sqlText, IExpr* &pObj, IExpr* pBefThisObj) = 0 ;
	virtual Word __stdcall AddSubExpr_node(QNodeType qNodeType, IExpr* &pObj, IExpr* pBefThisObj) = 0 ;
	virtual Word __stdcall AddSubExpr_field(IField* pField, IExpr* &pObj, pIExpr pBefThisObj) = 0 ;
	virtual Word __stdcall ChangeNodeType(QNodeType nodeType) = 0 ;
	virtual Word __stdcall DeleteSubExpr(IExpr* pObj) = 0 ;
	virtual Word __stdcall MoveSubExpr(IExpr* pObj, IExpr* pBefThisObj) = 0 ;
	virtual Word __stdcall GetParentExpr(IExpr* pRootExpr, IExpr* &ppParentExpr, IExpr* &ppNextSiblingExpr) = 0 ;
	virtual Word __stdcall GetNumCells(Word &nCells) = 0 ;
	virtual Word __stdcall GetCell(Word index, IExpr* &ppCell, char * &ppText1, char * &ppText2) = 0 ;
	virtual Word __stdcall FetchField(IField* &ppField) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IExpr(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IExpr(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION IJoinExpr : public IExpr 
{
	typedef IExpr inherited;
	
public:
	virtual Word __stdcall FetchFieldLeft(IField* &ppField) = 0 ;
	virtual Word __stdcall FetchFieldRight(IField* &ppField) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IJoinExpr(void) : IExpr() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IJoinExpr(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION IJoin : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual Word __stdcall FetchTableLeft(ITable* &ppTable) = 0 ;
	virtual Word __stdcall FetchTableRight(ITable* &ppTable) = 0 ;
	virtual Word __stdcall GetJoinType(JoinType &joinType) = 0 ;
	virtual Word __stdcall GetNumExprs(Word &number) = 0 ;
	virtual Word __stdcall GetSQLText(char * &ppSQLText) = 0 ;
	virtual Word __stdcall FetchJoinExpr(Word number, IExpr* &ppExpr) = 0 ;
	virtual Word __stdcall GetIndexForJoinExpr(IJoinExpr* pJoinExpr, Word &index) = 0 ;
	virtual Word __stdcall AddJoinExpr(Word FldNumLeft, Word FldNumRight, QNodeType MathOp, IExpr* &ppObj, IExpr* pBefThisObj) = 0 ;
	virtual Word __stdcall AddJoinExpr_useFldName(char * FldNameLeft, char * FldNameRight, QNodeType MathOp, IExpr* &ppObj, IExpr* pBefThisObj) = 0 ;
	virtual Word __stdcall DeleteJoinExpr(IExpr* pObj) = 0 ;
	virtual Word __stdcall ChangeJoinType(JoinType JoinType_input) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IJoin(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IJoin(void) { }
	#pragma option pop
	
};


__interface IQStmt  : public IInterface 
{
	
public:
	virtual Word __stdcall Initialize(Bde::hDBIDb hDb, char * pszQuery) = 0 ;
	virtual Word __stdcall GetStmtType(StmtType &stmtType) = 0 ;
	virtual Word __stdcall GetNumInputTables(Word &Num) = 0 ;
	virtual Word __stdcall GetNumProjectors(Word &Num) = 0 ;
	virtual Word __stdcall GetNumGroupBy(Word &Num) = 0 ;
	virtual Word __stdcall GetNumOrderBy(Word &Num) = 0 ;
	virtual Word __stdcall GetNumJoins(Word &Num) = 0 ;
	virtual Word __stdcall GetHasWherePred(BOOL &Has) = 0 ;
	virtual Word __stdcall GetHasHavingPred(BOOL &Has) = 0 ;
	virtual Word __stdcall GetIsDistinct(BOOL &IsDistinct) = 0 ;
	virtual Word __stdcall SetDistinct(BOOL IsDistinct) = 0 ;
	virtual Word __stdcall GetSQLText(char * &sqlText, unsigned &DialectDrvType, BOOL bInnerJoinUseKeyword, dialect_ansi lang) = 0 ;
	virtual Word __stdcall FetchInputTable(Word index, ITable* &pTable) = 0 ;
	virtual Word __stdcall FetchProjector(Word index, IProjector* &pProjector) = 0 ;
	virtual Word __stdcall FetchGroupBy(Word index, IGroupBy* &pGroupBy) = 0 ;
	virtual Word __stdcall FetchOrderBy(Word index, IOrderBy* &pOrderBy) = 0 ;
	virtual Word __stdcall FetchJoin(Word index, IJoin* &pJoin) = 0 ;
	virtual Word __stdcall FetchWhereExpr(IExpr* &Expr) = 0 ;
	virtual Word __stdcall FetchHavingExpr(IExpr* &Expr) = 0 ;
	virtual Word __stdcall GetIndexForInputTable(ITable* pObj, Word &index) = 0 ;
	virtual Word __stdcall GetIndexForJoin(IJoin* pObj, Word &index) = 0 ;
	virtual Word __stdcall GetIndexForProjector(IProjector* pObj, Word &index) = 0 ;
	virtual Word __stdcall GetIndexForGroupBy(IGroupBy* pObj, Word &index) = 0 ;
	virtual Word __stdcall GetIndexForOrderBy(IOrderBy* pObj, Word &index) = 0 ;
	virtual Word __stdcall AddInputTable(char * Name, char * DbName, char * DrvType, char * Alias, ITable* &pObj, ITable* BefThisObj) = 0 ;
	virtual Word __stdcall DeleteInputTable(ITable* Table, pDeletedObj &pDelObj) = 0 ;
	virtual Word __stdcall AddJoin(ITable* TableLeft, ITable* TableRight, JoinType eJoinType, IJoin* &pObj, IJoin* BefThisObj) = 0 ;
	virtual Word __stdcall DeleteJoin(IJoin* Obj) = 0 ;
	virtual Word __stdcall AddProjector_FldNum(ITable* Table, Word FldSeqNum, IProjector* &pObj, IProjector* BefThisObj, BOOL bAddGroupBY) = 0 ;
	virtual Word __stdcall AddProjector_field(IField* Field, IProjector* &pObj, IProjector* BefThisObj, BOOL bAddGroupBY) = 0 ;
	virtual Word __stdcall AddProjector_text(char * sqlText, IProjector* &pObj, IProjector* BefThisObj) = 0 ;
	virtual Word __stdcall AddProjector_node(QNodeType qNodeType, IProjector* &pObj, IProjector* BefThisObj, BOOL bAddGroupBy) = 0 ;
	virtual Word __stdcall DeleteProjector(IProjector* pObj, pDeletedObj &pDelObj) = 0 ;
	virtual Word __stdcall GenerateDefProjName(IProjector* Proj) = 0 ;
	virtual Word __stdcall IsField(char * sqlText, IField* &pField) = 0 ;
	virtual Word __stdcall AddGroupBy_FieldNo(ITable* pTable, Word FldIndex, IGroupBy* &pObj, IGroupBy* pBefThisObj) = 0 ;
	virtual Word __stdcall AddGroupBy_Field(IField* pField, IGroupBy* &pObj, IGroupBy* pBefThisObj) = 0 ;
	virtual Word __stdcall DeleteGroupBy(IGroupBy* pObj) = 0 ;
	virtual Word __stdcall AddGroupBy_automatic(void) = 0 ;
	virtual Word __stdcall AddOrderBy(IProjector* pProjector, Word iPosition, BOOL bDesc, IOrderBy* &pObj, IOrderBy* pBefThisObj) = 0 ;
	virtual Word __stdcall DeleteOrderBy(IOrderBy* pObj) = 0 ;
	virtual Word __stdcall SetTableAlias(ITable* pTable, char * newAlias) = 0 ;
	virtual Word __stdcall SetProjectorName(IProjector* pProj, char * newName) = 0 ;
	virtual Word __stdcall MoveProjector(IProjector* pObj, IProjector* pBefThisObj) = 0 ;
	virtual Word __stdcall MoveTable(ITable* pObj, ITable* pBefThisObj) = 0 ;
	virtual Word __stdcall MoveGroupBy(IGroupBy* pObj, IGroupBy* pBefThisObj) = 0 ;
	virtual Word __stdcall MoveOrderBy(IOrderBy* pObj, IOrderBy* pBefThisObj) = 0 ;
	virtual Word __stdcall MakeComment(char * pComment, BOOL bFront) = 0 ;
	virtual Word __stdcall ExprTextToObj(IExpr* &pExpr, ExprCat ec, IExpr* rootExpr) = 0 ;
	virtual Word __stdcall ExprObjToText(IExpr* &pExpr, IExpr* rootExpr) = 0 ;
	virtual Word __stdcall ProjTextToObj(IProjector* pProj) = 0 ;
	virtual Word __stdcall ProjObjToText(IProjector* pProj) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID CLSID_IDSQL32;
extern PACKAGE GUID IID_IQStmt;

}	/* namespace Mxqedcom */
using namespace Mxqedcom;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXQEDCOM
