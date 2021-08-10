// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBExtract.pas' rev: 6.00

#ifndef IBExtractHPP
#define IBExtractHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBExternals.hpp>	// Pascal unit
#include <IBIntf.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <IBUtils.hpp>	// Pascal unit
#include <IBSQL.hpp>	// Pascal unit
#include <IBDatabaseInfo.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibextract
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TExtractObjectTypes { eoDatabase, eoDomain, eoTable, eoView, eoProcedure, eoFunction, eoGenerator, eoException, eoBLOBFilter, eoRole, eoTrigger, eoForeign, eoIndexes, eoChecks, eoData };
#pragma option pop

#pragma option push -b-
enum TExtractType { etDomain, etTable, etRole, etTrigger, etForeign, etIndex, etData, etGrant, etCheck, etAlterProc };
#pragma option pop

typedef Set<TExtractType, etDomain, etAlterProc>  TExtractTypes;

class DELPHICLASS TIBExtract;
class PASCALIMPLEMENTATION TIBExtract : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Ibdatabase::TIBDatabase* FDatabase;
	Ibdatabase::TIBTransaction* FTransaction;
	Classes::TStrings* FMetaData;
	Ibdatabaseinfo::TIBDatabaseInfo* FDatabaseInfo;
	bool FShowSystem;
	Ibdatabase::TIBDatabase* __fastcall GetDatabase(void);
	AnsiString __fastcall GetIndexSegments(AnsiString indexname);
	Ibdatabase::TIBTransaction* __fastcall GetTransaction(void);
	void __fastcall SetDatabase(const Ibdatabase::TIBDatabase* Value);
	void __fastcall SetTransaction(const Ibdatabase::TIBTransaction* Value);
	AnsiString __fastcall PrintValidation(AnsiString ToValidate, bool flag);
	void __fastcall ShowGrants(AnsiString MetaObject, AnsiString Terminator);
	void __fastcall ShowGrantRoles(AnsiString Terminator);
	void __fastcall GetProcedureArgs(AnsiString Proc);
	int __fastcall GetFieldLength(Ibsql::TIBSQL* sql);
	Ibsql::TIBSQL* __fastcall CreateIBSQL(void);
	
protected:
	bool __fastcall ExtractDDL(bool Flag, AnsiString TableName);
	bool __fastcall ExtractListTable(AnsiString RelationName, AnsiString NewName, bool DomainFlag);
	void __fastcall ExtractListView(AnsiString ViewName);
	void __fastcall ListData(AnsiString ObjectName);
	void __fastcall ListRoles(AnsiString ObjectName = "");
	void __fastcall ListGrants(void);
	void __fastcall ListProcs(AnsiString ProcedureName = "", bool AlterOnly = false);
	void __fastcall ListAllTables(bool flag);
	void __fastcall ListTriggers(AnsiString ObjectName = "", TExtractType ExtractType = (TExtractType)(0x3));
	void __fastcall ListCheck(AnsiString ObjectName = "", TExtractType ExtractType = (TExtractType)(0x8));
	AnsiString __fastcall PrintSet(bool &Used);
	void __fastcall ListCreateDb(AnsiString TargetDb = "");
	void __fastcall ListDomains(AnsiString ObjectName = "", TExtractType ExtractType = (TExtractType)(0x0));
	void __fastcall ListException(AnsiString ExceptionName = "");
	void __fastcall ListFilters(AnsiString FilterName = "");
	void __fastcall ListForeign(AnsiString ObjectName = "", TExtractType ExtractType = (TExtractType)(0x4));
	void __fastcall ListFunctions(AnsiString FunctionName = "");
	void __fastcall ListGenerators(AnsiString GeneratorName = "");
	void __fastcall ListIndex(AnsiString ObjectName = "", TExtractType ExtractType = (TExtractType)(0x5));
	void __fastcall ListViews(AnsiString ViewName = "");
	
public:
	__fastcall virtual TIBExtract(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBExtract(void);
	AnsiString __fastcall GetArrayField(AnsiString FieldName);
	AnsiString __fastcall GetFieldType(int FieldType, int FieldSubType, int FieldScale, int FieldSize, int FieldPrec, int FieldLen);
	AnsiString __fastcall GetCharacterSets(short CharSetId, short Collation, bool CollateOnly);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall ExtractObject(TExtractObjectTypes ObjectType, AnsiString ObjectName = "", TExtractTypes ExtractTypes = System::Set<TExtractType, etDomain, etAlterProc> () );
	__property Ibdatabaseinfo::TIBDatabaseInfo* DatabaseInfo = {read=FDatabaseInfo};
	__property Classes::TStrings* Items = {read=FMetaData};
	
__published:
	__property Ibdatabase::TIBDatabase* Database = {read=GetDatabase, write=SetDatabase};
	__property Ibdatabase::TIBTransaction* Transaction = {read=GetTransaction, write=SetTransaction};
	__property bool ShowSystem = {read=FShowSystem, write=FShowSystem, nodefault};
};


#pragma pack(push, 4)
struct TSQLType
{
	int SqlType;
	AnsiString TypeName;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TPrivTypes
{
	int PrivFlag;
	AnsiString PrivString;
} ;
#pragma pack(pop)

typedef TSQLType TSQLTypes[14];

typedef TPrivTypes IBExtract__2[6];

typedef AnsiString IBExtract__3[9];

typedef AnsiString IBExtract__4[7];

typedef AnsiString IBExtract__5[3];

//-- var, const, procedure ---------------------------------------------------
static const Shortint priv_UNKNOWN = 0x1;
static const Shortint priv_SELECT = 0x2;
static const Shortint priv_INSERT = 0x4;
static const Shortint priv_UPDATE = 0x8;
static const Shortint priv_DELETE = 0x10;
static const Shortint priv_EXECUTE = 0x20;
static const Shortint priv_REFERENCES = 0x40;
extern PACKAGE TPrivTypes PrivTypes[6];
extern PACKAGE TSQLType ColumnTypes[14];
extern PACKAGE AnsiString SubTypes[9];
extern PACKAGE AnsiString TriggerTypes[7];
extern PACKAGE AnsiString IntegralSubtypes[3];
static const Shortint ODS_VERSION6 = 0x6;
static const Shortint ODS_VERSION7 = 0x7;
static const Shortint ODS_VERSION8 = 0x8;
static const Shortint ODS_VERSION9 = 0x9;
static const Shortint ODS_VERSION10 = 0xa;
static const Shortint FILE_shadow = 0x1;
static const Shortint FILE_inactive = 0x2;
static const Shortint FILE_manual = 0x4;
static const Shortint FILE_cache = 0x8;
static const Shortint FILE_conditional = 0x10;
static const Shortint LOG_serial = 0x1;
static const Shortint LOG_default = 0x2;
static const Shortint LOG_raw = 0x4;
static const Shortint LOG_overflow = 0x8;
static const Shortint MAX_INTSUBTYPES = 0x2;
static const Shortint MAXSUBTYPES = 0x8;
static const Shortint obj_relation = 0x0;
static const Shortint obj_view = 0x1;
static const Shortint obj_trigger = 0x2;
static const Shortint obj_computed = 0x3;
static const Shortint obj_validation = 0x4;
static const Shortint obj_procedure = 0x5;
static const Shortint obj_expression_index = 0x6;
static const Shortint obj_exception = 0x7;
static const Shortint obj_user = 0x8;
static const Shortint obj_field = 0x9;
static const Shortint obj_index = 0xa;
static const Shortint obj_count = 0xb;
static const Shortint obj_user_group = 0xc;
static const Shortint obj_sql_role = 0xd;

}	/* namespace Ibextract */
using namespace Ibextract;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBExtract
