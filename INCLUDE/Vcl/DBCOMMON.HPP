// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBCommon.pas' rev: 5.00

#ifndef DBCommonHPP
#define DBCommonHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Db.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbcommon
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TCANOperator { coNOTDEFINED, coISBLANK, coNOTBLANK, coEQ, coNE, coGT, coLT, coGE, coLE, coNOT, 
	coAND, coOR, coTUPLE2, coFIELD2, coCONST2, coMINUS, coADD, coSUB, coMUL, coDIV, coMOD, coREM, coSUM, 
	coCOUNT, coMIN, coMAX, coAVG, coCONT, coUDF2, coCONTINUE2, coLIKE, coIN, coLIST2, coUPPER, coLOWER, 
	coFUNC2, coLISTELEM2, coASSIGN };
#pragma option pop

#pragma option push -b-
enum NODEClass { nodeNULL, nodeUNARY, nodeBINARY, nodeCOMPARE, nodeFIELD, nodeCONST, nodeTUPLE, nodeCONTINUE, 
	nodeUDF, nodeLIST, nodeFUNC, nodeLISTELEM };
#pragma option pop

typedef DynamicArray<Byte >  TExprData;

typedef Byte TFieldMap[36];

#pragma option push -b-
enum TParserOption { poExtSyntax, poAggregate, poDefaultExpr, poUseOrigNames, poFieldNameGiven, poFieldDepend 
	};
#pragma option pop

typedef Set<TParserOption, poExtSyntax, poFieldDepend>  TParserOptions;

#pragma option push -b-
enum TExprNodeKind { enField, enConst, enOperator, enFunc };
#pragma option pop

#pragma option push -b-
enum TExprScopeKind { skField, skAgg, skConst };
#pragma option pop

struct TExprNode;
typedef TExprNode *PExprNode;

struct TExprNode
{
	TExprNode *FNext;
	TExprNodeKind FKind;
	bool FPartial;
	TCANOperator FOperator;
	Variant FData;
	TExprNode *FLeft;
	TExprNode *FRight;
	Db::TFieldType FDataType;
	int FDataSize;
	Classes::TList* FArgs;
	TExprScopeKind FScopeKind;
} ;

class DELPHICLASS TFilterExpr;
class PASCALIMPLEMENTATION TFilterExpr : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Db::TDataSet* FDataSet;
	Byte FFieldMap[36];
	Db::TFilterOptions FOptions;
	TParserOptions FParserOptions;
	TExprNode *FNodes;
	DynamicArray<Byte >  FExprBuffer;
	int FExprBufSize;
	int FExprNodeSize;
	int FExprDataSize;
	AnsiString FFieldName;
	Classes::TBits* FDependentFields;
	Db::TField* __fastcall FieldFromNode(PExprNode Node);
	char * __fastcall GetExprData(int Pos, int Size);
	int __fastcall PutConstBCD(const Variant &Value, int Decimals);
	int __fastcall PutConstBool(const Variant &Value);
	int __fastcall PutConstDate(const Variant &Value);
	int __fastcall PutConstDateTime(const Variant &Value);
	int __fastcall PutConstFloat(const Variant &Value);
	int __fastcall PutConstInt(Db::TFieldType DataType, const Variant &Value);
	int __fastcall PutConstNode(Db::TFieldType DataType, char * Data, int Size);
	int __fastcall PutConstStr(const AnsiString Value);
	int __fastcall PutConstTime(const Variant &Value);
	int __fastcall PutData(char * Data, int Size);
	int __fastcall PutExprNode(PExprNode Node, TCANOperator ParentOp);
	int __fastcall PutFieldNode(Db::TField* Field, PExprNode Node);
	int __fastcall PutNode(NODEClass NodeType, TCANOperator OpType, int OpCount);
	void __fastcall SetNodeOp(int Node, int Index, int Data);
	int __fastcall PutConstant(PExprNode Node);
	Db::TField* __fastcall GetFieldByName(AnsiString Name);
	
public:
	__fastcall TFilterExpr(Db::TDataSet* DataSet, Db::TFilterOptions Options, TParserOptions ParseOptions
		, const AnsiString FieldName, Classes::TBits* DepFields, const Byte * FieldMap);
	__fastcall virtual ~TFilterExpr(void);
	PExprNode __fastcall NewCompareNode(Db::TField* Field, TCANOperator Operator, const Variant &Value)
		;
	PExprNode __fastcall NewNode(TExprNodeKind Kind, TCANOperator Operator, const Variant &Data, PExprNode 
		Left, PExprNode Right);
	TExprData __fastcall GetFilterData(PExprNode Root);
	__property Db::TDataSet* DataSet = {write=FDataSet};
};


#pragma option push -b-
enum TExprToken { etEnd, etSymbol, etName, etLiteral, etLParen, etRParen, etEQ, etNE, etGE, etLE, etGT, 
	etLT, etADD, etSUB, etMUL, etDIV, etComma, etLIKE, etISNULL, etISNOTNULL, etIN };
#pragma option pop

class DELPHICLASS TExprParser;
class PASCALIMPLEMENTATION TExprParser : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TFilterExpr* FFilter;
	Byte FFieldMap[36];
	AnsiString FText;
	char *FSourcePtr;
	char *FTokenPtr;
	AnsiString FTokenString;
	AnsiString FStrTrue;
	AnsiString FStrFalse;
	TExprToken FToken;
	TExprToken FPrevToken;
	DynamicArray<Byte >  FFilterData;
	bool FNumericLit;
	int FDataSize;
	TParserOptions FParserOptions;
	AnsiString FFieldName;
	Db::TDataSet* FDataSet;
	Classes::TBits* FDependentFields;
	void __fastcall NextToken(void);
	bool __fastcall NextTokenIsLParen(void);
	PExprNode __fastcall ParseExpr(void);
	PExprNode __fastcall ParseExpr2(void);
	PExprNode __fastcall ParseExpr3(void);
	PExprNode __fastcall ParseExpr4(void);
	PExprNode __fastcall ParseExpr5(void);
	PExprNode __fastcall ParseExpr6(void);
	PExprNode __fastcall ParseExpr7(void);
	AnsiString __fastcall TokenName();
	bool __fastcall TokenSymbolIs(const AnsiString S);
	bool __fastcall TokenSymbolIsFunc(const AnsiString S);
	void __fastcall GetFuncResultInfo(PExprNode Node);
	void __fastcall TypeCheckArithOp(PExprNode Node);
	void __fastcall GetScopeKind(PExprNode Root, PExprNode Left, PExprNode Right);
	
public:
	__fastcall TExprParser(Db::TDataSet* DataSet, const AnsiString Text, Db::TFilterOptions Options, TParserOptions 
		ParserOptions, const AnsiString FieldName, Classes::TBits* DepFields, const Byte * FieldMap);
	__fastcall virtual ~TExprParser(void);
	void __fastcall SetExprParams(const AnsiString Text, Db::TFilterOptions Options, TParserOptions ParserOptions
		, const AnsiString FieldName);
	__property TExprData FilterData = {read=FFilterData};
	__property int DataSize = {read=FDataSize, nodefault};
};


struct TFieldInfo
{
	AnsiString DatabaseName;
	AnsiString TableName;
	AnsiString OriginalFieldName;
} ;

#pragma option push -b-
enum TSQLToken { stUnknown, stTableName, stFieldName, stAscending, stDescending, stSelect, stFrom, stWhere, 
	stGroupBy, stHaving, stUnion, stPlan, stOrderBy, stForUpdate, stEnd, stPredicate, stValue, stIsNull, 
	stIsNotNull, stLike, stAnd, stOr, stNumber, stAllFields, stComment, stDistinct };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
static const Shortint CANEXPRSIZE = 0xa;
static const Shortint CANHDRSIZE = 0x8;
static const Shortint CANEXPRVERSION = 0x2;
#define SQLSections (System::Set<TSQLToken, stUnknown, stDistinct> () )
extern PACKAGE TSQLToken __fastcall NextSQLToken(char * &p, /* out */ AnsiString &Token, TSQLToken CurSection
	);
extern PACKAGE AnsiString __fastcall GetTableNameFromSQL(const AnsiString SQL);
extern PACKAGE Db::TIndexDef* __fastcall GetIndexForOrderBy(const AnsiString SQL, Db::TDataSet* DataSet
	);
extern PACKAGE bool __fastcall GetFieldInfo(const AnsiString Origin, TFieldInfo &FieldInfo);

}	/* namespace Dbcommon */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dbcommon;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBCommon
