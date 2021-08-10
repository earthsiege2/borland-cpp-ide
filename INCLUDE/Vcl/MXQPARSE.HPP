// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXQPARSE.pas' rev: 6.00

#ifndef MXQPARSEHPP
#define MXQPARSEHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Mxconsts.hpp>	// Pascal unit
#include <MXCOMMON.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <DBConsts.hpp>	// Pascal unit
#include <MXQEDCOM.hpp>	// Pascal unit
#include <BDE.hpp>	// Pascal unit
#include <DBCommon.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxqparse
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EQParseException;
class PASCALIMPLEMENTATION EQParseException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EQParseException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EQParseException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EQParseException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EQParseException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EQParseException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EQParseException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EQParseException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EQParseException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EQParseException(void) { }
	#pragma option pop
	
};


struct recProjectorInfo;
typedef recProjectorInfo *pRecProjInfo;

#pragma pack(push, 4)
struct recProjectorInfo
{
	int FieldNo;
	Db::TFieldType FieldType;
	AnsiString OutputName;
	AnsiString CompareName;
	AnsiString BaseName;
	Mxcommon::TDimFlags projType;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TQueryState { txNone, txAddingSum, txAddingDim, txDeletingSum, txDeletingDim };
#pragma option pop

class DELPHICLASS TXtabQuery;
class PASCALIMPLEMENTATION TXtabQuery : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Bde::_hDBIObj *Fhdb;
	Mxqedcom::_di_IQStmt pQStmt;
	Classes::TList* FProjectors;
	Classes::TList* FDimensions;
	Classes::TList* FAggregates;
	bool FcanDelete;
	bool FInitialized;
	void __fastcall setSQLString(AnsiString newStr);
	AnsiString __fastcall getSQLString();
	int __fastcall getNProjectors(void);
	int __fastcall getNDimensions(void);
	int __fastcall getNAggregates(void);
	recProjectorInfo __fastcall getProjector(int Index);
	recProjectorInfo __fastcall getAggregate(int Index);
	recProjectorInfo __fastcall getDimension(int Index);
	int __fastcall getNTables(void);
	AnsiString __fastcall getTableName(int index);
	void __fastcall buildProjectorMaps(void);
	Mxcommon::TDimFlags __fastcall XtabProjType(Mxqedcom::IExpr* Expr);
	Db::TFieldType __fastcall GetProjFieldType(Mxqedcom::IProjector* Proj);
	Db::TFieldType __fastcall GetExprFieldType(Mxqedcom::IExpr* Expr);
	
public:
	Mxcommon::TQueryError __fastcall IsLegal(void);
	bool __fastcall AllDimensionsGrouped(void);
	int __fastcall AddNewItem(AnsiString SQLTxt, Mxcommon::TDimFlags newAgg, int index, bool bGrouped, AnsiString Name);
	void __fastcall DeleteProjector(int ProjIndex);
	void __fastcall FixUpGroupBys(void);
	void __fastcall DeleteGroupBys(void);
	void __fastcall DeleteDimensions(void);
	void __fastcall DeleteSummaries(void);
	void __fastcall DeleteProjectors(void);
	void __fastcall AddWhereCondition(AnsiString Condition);
	void __fastcall AddWhereOp(AnsiString FieldName, const Variant &Condition, Mxqedcom::QNodeType Qtype);
	AnsiString __fastcall getDialectSQLString();
	void __fastcall AddTable(AnsiString tableName);
	__fastcall TXtabQuery(void);
	__fastcall virtual ~TXtabQuery(void);
	__property bool canDelete = {read=FcanDelete, write=FcanDelete, nodefault};
	__property recProjectorInfo Projector[int Index] = {read=getProjector};
	__property recProjectorInfo Aggregate[int Index] = {read=getAggregate};
	__property recProjectorInfo Dimension[int Index] = {read=getDimension};
	__property AnsiString TableName[int Index] = {read=getTableName};
	__property Bde::hDBIDb DBHandle = {read=Fhdb, write=Fhdb};
	
__published:
	__property AnsiString SQLString = {read=getSQLString, write=setSQLString};
	__property int NProjectors = {read=getNProjectors, nodefault};
	__property int NDimensions = {read=getNDimensions, nodefault};
	__property int NTables = {read=getNTables, nodefault};
	__property int NAggregates = {read=getNAggregates, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall BDEcheck(Word res);
extern PACKAGE Mxqedcom::QNodeType __fastcall ptToQNode(Mxcommon::TDimFlags pt);
extern PACKAGE AnsiString __fastcall BDEDLLPath();

}	/* namespace Mxqparse */
using namespace Mxqparse;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXQPARSE
