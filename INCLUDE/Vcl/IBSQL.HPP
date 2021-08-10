// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBSQL.pas' rev: 5.00

#ifndef IBSQLHPP
#define IBSQLHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBUtils.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <IBExternals.hpp>	// Pascal unit
#include <IBErrorCodes.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibsql
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBXSQLVAR;
class DELPHICLASS TIBSQL;
class DELPHICLASS TIBXSQLDA;
class PASCALIMPLEMENTATION TIBXSQLVAR : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TIBSQL* FSQL;
	int FIndex;
	bool FModified;
	AnsiString FName;
	Ibheader::TXSQLVAR *FXSQLVAR;
	double __fastcall AdjustScale(__int64 Value, int Scale);
	System::Currency __fastcall AdjustScaleToCurrency(__int64 Value, int Scale);
	System::Currency __fastcall GetAsCurrency(void);
	__int64 __fastcall GetAsInt64(void);
	System::TDateTime __fastcall GetAsDateTime(void);
	double __fastcall GetAsDouble(void);
	float __fastcall GetAsFloat(void);
	int __fastcall GetAsLong(void);
	void * __fastcall GetAsPointer(void);
	Ibheader::TGDS_QUAD __fastcall GetAsQuad();
	short __fastcall GetAsShort(void);
	AnsiString __fastcall GetAsString();
	Variant __fastcall GetAsVariant();
	Ibheader::PXSQLVAR __fastcall GetAsXSQLVAR(void);
	bool __fastcall GetIsNull(void);
	bool __fastcall GetIsNullable(void);
	int __fastcall GetSize(void);
	int __fastcall GetSQLType(void);
	void __fastcall SetAsCurrency(System::Currency Value);
	void __fastcall SetAsInt64(__int64 Value);
	void __fastcall SetAsDate(System::TDateTime Value);
	void __fastcall SetAsTime(System::TDateTime Value);
	void __fastcall SetAsDateTime(System::TDateTime Value);
	void __fastcall SetAsDouble(double Value);
	void __fastcall SetAsFloat(float Value);
	void __fastcall SetAsLong(int Value);
	void __fastcall SetAsPointer(void * Value);
	void __fastcall SetAsQuad(const Ibheader::TGDS_QUAD &Value);
	void __fastcall SetAsShort(short Value);
	void __fastcall SetAsString(AnsiString Value);
	void __fastcall SetAsVariant(const Variant &Value);
	void __fastcall SetAsXSQLVAR(Ibheader::PXSQLVAR Value);
	void __fastcall SetIsNull(bool Value);
	void __fastcall SetIsNullable(bool Value);
	
public:
	__fastcall TIBXSQLVAR(TIBSQL* Query);
	void __fastcall Assign(TIBXSQLVAR* Source);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall SaveToFile(const AnsiString FileName);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	__property System::TDateTime AsDate = {read=GetAsDateTime, write=SetAsDate};
	__property System::TDateTime AsTime = {read=GetAsDateTime, write=SetAsTime};
	__property System::TDateTime AsDateTime = {read=GetAsDateTime, write=SetAsDateTime};
	__property double AsDouble = {read=GetAsDouble, write=SetAsDouble};
	__property float AsFloat = {read=GetAsFloat, write=SetAsFloat};
	__property System::Currency AsCurrency = {read=GetAsCurrency, write=SetAsCurrency};
	__property __int64 AsInt64 = {read=GetAsInt64, write=SetAsInt64};
	__property int AsInteger = {read=GetAsLong, write=SetAsLong, nodefault};
	__property int AsLong = {read=GetAsLong, write=SetAsLong, nodefault};
	__property void * AsPointer = {read=GetAsPointer, write=SetAsPointer};
	__property Ibheader::TGDS_QUAD AsQuad = {read=GetAsQuad, write=SetAsQuad};
	__property short AsShort = {read=GetAsShort, write=SetAsShort, nodefault};
	__property AnsiString AsString = {read=GetAsString, write=SetAsString};
	__property Variant AsVariant = {read=GetAsVariant, write=SetAsVariant};
	__property Ibheader::PXSQLVAR AsXSQLVAR = {read=GetAsXSQLVAR, write=SetAsXSQLVAR};
	__property Ibheader::PXSQLVAR Data = {read=FXSQLVAR, write=FXSQLVAR};
	__property bool IsNull = {read=GetIsNull, write=SetIsNull, nodefault};
	__property bool IsNullable = {read=GetIsNullable, write=SetIsNullable, nodefault};
	__property int Index = {read=FIndex, nodefault};
	__property bool Modified = {read=FModified, write=FModified, nodefault};
	__property AnsiString Name = {read=FName};
	__property int Size = {read=GetSize, nodefault};
	__property int SQLType = {read=GetSQLType, nodefault};
	__property Variant Value = {read=GetAsVariant, write=SetAsVariant};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIBXSQLVAR(void) { }
	#pragma option pop
	
};


typedef TIBXSQLVAR* TIBXSQLVARArray[1];

typedef TIBXSQLVAR* *PIBXSQLVARArray;

class PASCALIMPLEMENTATION TIBXSQLDA : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	TIBSQL* FSQL;
	int FCount;
	Classes::TStrings* FNames;
	int FSize;
	Ibheader::TXSQLDA *FXSQLDA;
	TIBXSQLVAR* *FXSQLVARs;
	AnsiString FUniqueRelationName;
	bool __fastcall GetModified(void);
	AnsiString __fastcall GetNames();
	int __fastcall GetRecordSize(void);
	Ibheader::PXSQLDA __fastcall GetXSQLDA(void);
	TIBXSQLVAR* __fastcall GetXSQLVAR(int Idx);
	TIBXSQLVAR* __fastcall GetXSQLVARByName(AnsiString Idx);
	void __fastcall Initialize(void);
	void __fastcall SetCount(int Value);
	
public:
	__fastcall TIBXSQLDA(TIBSQL* Query);
	__fastcall virtual ~TIBXSQLDA(void);
	void __fastcall AddName(AnsiString FieldName, int Idx);
	TIBXSQLVAR* __fastcall ByName(AnsiString Idx);
	__property Ibheader::PXSQLDA AsXSQLDA = {read=GetXSQLDA};
	__property int Count = {read=FCount, write=SetCount, nodefault};
	__property bool Modified = {read=GetModified, nodefault};
	__property AnsiString Names = {read=GetNames};
	__property int RecordSize = {read=GetRecordSize, nodefault};
	__property TIBXSQLVAR* Vars[int Idx] = {read=GetXSQLVAR/*, default*/};
	__property AnsiString UniqueRelationName = {read=FUniqueRelationName};
};


#pragma option push -b-
enum TIBSQLTypes { SQLUnknown, SQLSelect, SQLInsert, SQLUpdate, SQLDelete, SQLDDL, SQLGetSegment, SQLPutSegment, 
	SQLExecProcedure, SQLStartTransaction, SQLCommit, SQLRollback, SQLSelectForUpdate, SQLSetGenerator 
	};
#pragma option pop

class DELPHICLASS TIBBatchInput;
class DELPHICLASS TIBBatchOutput;
class PASCALIMPLEMENTATION TIBSQL : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FIBLoaded;
	
protected:
	Ibdatabase::TIBBase* FBase;
	bool FBOF;
	bool FEOF;
	bool FGoToFirstRecordOnExecute;
	bool FOpen;
	bool FPrepared;
	int FRecordCount;
	AnsiString FCursor;
	void * *FHandle;
	Classes::TNotifyEvent FOnSQLChanging;
	Classes::TStrings* FSQL;
	bool FParamCheck;
	Classes::TStrings* FProcessedSQL;
	TIBXSQLDA* FSQLParams;
	TIBXSQLDA* FSQLRecord;
	TIBSQLTypes FSQLType;
	bool FGenerateParamNames;
	void __fastcall DoBeforeDatabaseDisconnect(System::TObject* Sender);
	Ibdatabase::TIBDatabase* __fastcall GetDatabase(void);
	Ibheader::PISC_DB_HANDLE __fastcall GetDBHandle(void);
	bool __fastcall GetEOF(void);
	TIBXSQLVAR* __fastcall GetFields(const int Idx);
	int __fastcall GetFieldIndex(AnsiString FieldName);
	AnsiString __fastcall GetPlan();
	int __fastcall GetRecordCount(void);
	int __fastcall GetRowsAffected(void);
	TIBXSQLDA* __fastcall GetSQLParams(void);
	Ibdatabase::TIBTransaction* __fastcall GetTransaction(void);
	Ibheader::PISC_TR_HANDLE __fastcall GetTRHandle(void);
	void __fastcall PreprocessSQL(void);
	void __fastcall SetDatabase(Ibdatabase::TIBDatabase* Value);
	void __fastcall SetSQL(Classes::TStrings* Value);
	void __fastcall SetTransaction(Ibdatabase::TIBTransaction* Value);
	void __fastcall SQLChanging(System::TObject* Sender);
	void __fastcall BeforeTransactionEnd(System::TObject* Sender);
	
public:
	__fastcall virtual TIBSQL(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBSQL(void);
	void __fastcall BatchInput(TIBBatchInput* InputObject);
	void __fastcall BatchOutput(TIBBatchOutput* OutputObject);
	int __fastcall Call(int ErrCode, bool RaiseError);
	void __fastcall CheckClosed(void);
	void __fastcall CheckOpen(void);
	void __fastcall CheckValidStatement(void);
	void __fastcall Close(void);
	TIBXSQLDA* __fastcall Current(void);
	void __fastcall ExecQuery(void);
	TIBXSQLVAR* __fastcall FieldByName(AnsiString FieldName);
	void __fastcall FreeHandle(void);
	TIBXSQLDA* __fastcall Next(void);
	void __fastcall Prepare(void);
	AnsiString __fastcall GetUniqueRelationName();
	__property bool BOF = {read=FBOF, nodefault};
	__property Ibheader::PISC_DB_HANDLE DBHandle = {read=GetDBHandle};
	__property bool Eof = {read=GetEOF, nodefault};
	__property TIBXSQLVAR* Fields[int Idx] = {read=GetFields};
	__property int FieldIndex[AnsiString FieldName] = {read=GetFieldIndex};
	__property bool Open = {read=FOpen, nodefault};
	__property TIBXSQLDA* Params = {read=GetSQLParams};
	__property AnsiString Plan = {read=GetPlan};
	__property bool Prepared = {read=FPrepared, nodefault};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property int RowsAffected = {read=GetRowsAffected, nodefault};
	__property TIBSQLTypes SQLType = {read=FSQLType, nodefault};
	__property Ibheader::PISC_TR_HANDLE TRHandle = {read=GetTRHandle};
	__property Ibexternals::PVoid Handle = {read=FHandle};
	__property bool GenerateParamNames = {read=FGenerateParamNames, write=FGenerateParamNames, nodefault
		};
	__property AnsiString UniqueRelationName = {read=GetUniqueRelationName};
	
__published:
	__property Ibdatabase::TIBDatabase* Database = {read=GetDatabase, write=SetDatabase};
	__property bool GoToFirstRecordOnExecute = {read=FGoToFirstRecordOnExecute, write=FGoToFirstRecordOnExecute
		, default=1};
	__property bool ParamCheck = {read=FParamCheck, write=FParamCheck, nodefault};
	__property Classes::TStrings* SQL = {read=FSQL, write=SetSQL};
	__property Ibdatabase::TIBTransaction* Transaction = {read=GetTransaction, write=SetTransaction};
	__property Classes::TNotifyEvent OnSQLChanging = {read=FOnSQLChanging, write=FOnSQLChanging};
};



class DELPHICLASS TIBBatch;
class PASCALIMPLEMENTATION TIBBatch : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	AnsiString FFilename;
	TIBXSQLDA* FColumns;
	TIBXSQLDA* FParams;
	
public:
	virtual void __fastcall ReadyFile(void) = 0 ;
	__property TIBXSQLDA* Columns = {read=FColumns};
	__property AnsiString Filename = {read=FFilename, write=FFilename};
	__property TIBXSQLDA* Params = {read=FParams};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIBBatch(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIBBatch(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TIBBatchInput : public TIBBatch 
{
	typedef TIBBatch inherited;
	
public:
	virtual bool __fastcall ReadParameters(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIBBatchInput(void) : TIBBatch() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIBBatchInput(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TIBBatchOutput : public TIBBatch 
{
	typedef TIBBatch inherited;
	
public:
	virtual bool __fastcall WriteColumns(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIBBatchOutput(void) : TIBBatch() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIBBatchOutput(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBOutputDelimitedFile;
class PASCALIMPLEMENTATION TIBOutputDelimitedFile : public TIBBatchOutput 
{
	typedef TIBBatchOutput inherited;
	
protected:
	unsigned FHandle;
	bool FOutputTitles;
	AnsiString FColDelimiter;
	AnsiString FRowDelimiter;
	
public:
	__fastcall virtual ~TIBOutputDelimitedFile(void);
	virtual void __fastcall ReadyFile(void);
	virtual bool __fastcall WriteColumns(void);
	__property AnsiString ColDelimiter = {read=FColDelimiter, write=FColDelimiter};
	__property bool OutputTitles = {read=FOutputTitles, write=FOutputTitles, nodefault};
	__property AnsiString RowDelimiter = {read=FRowDelimiter, write=FRowDelimiter};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIBOutputDelimitedFile(void) : TIBBatchOutput() { }
	#pragma option pop
	
};


class DELPHICLASS TIBInputDelimitedFile;
class PASCALIMPLEMENTATION TIBInputDelimitedFile : public TIBBatchInput 
{
	typedef TIBBatchInput inherited;
	
protected:
	AnsiString FColDelimiter;
	AnsiString FRowDelimiter;
	bool FEOF;
	Classes::TFileStream* FFile;
	char FLookAhead;
	bool FReadBlanksAsNull;
	bool FSkipTitles;
	
public:
	__fastcall virtual ~TIBInputDelimitedFile(void);
	int __fastcall GetColumn(AnsiString &Col);
	virtual bool __fastcall ReadParameters(void);
	virtual void __fastcall ReadyFile(void);
	__property AnsiString ColDelimiter = {read=FColDelimiter, write=FColDelimiter};
	__property bool ReadBlanksAsNull = {read=FReadBlanksAsNull, write=FReadBlanksAsNull, nodefault};
	__property AnsiString RowDelimiter = {read=FRowDelimiter, write=FRowDelimiter};
	__property bool SkipTitles = {read=FSkipTitles, write=FSkipTitles, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIBInputDelimitedFile(void) : TIBBatchInput() { }
	#pragma option pop
	
};


class DELPHICLASS TIBOutputRawFile;
class PASCALIMPLEMENTATION TIBOutputRawFile : public TIBBatchOutput 
{
	typedef TIBBatchOutput inherited;
	
protected:
	unsigned FHandle;
	
public:
	__fastcall virtual ~TIBOutputRawFile(void);
	virtual void __fastcall ReadyFile(void);
	virtual bool __fastcall WriteColumns(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIBOutputRawFile(void) : TIBBatchOutput() { }
	#pragma option pop
	
};


class DELPHICLASS TIBInputRawFile;
class PASCALIMPLEMENTATION TIBInputRawFile : public TIBBatchInput 
{
	typedef TIBBatchInput inherited;
	
protected:
	unsigned FHandle;
	
public:
	__fastcall virtual ~TIBInputRawFile(void);
	virtual bool __fastcall ReadParameters(void);
	virtual void __fastcall ReadyFile(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIBInputRawFile(void) : TIBBatchInput() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::ResourceString _SEOFInComment;
#define Ibsql_SEOFInComment System::LoadResourceString(&Ibsql::_SEOFInComment)
extern PACKAGE System::ResourceString _SEOFInString;
#define Ibsql_SEOFInString System::LoadResourceString(&Ibsql::_SEOFInString)
extern PACKAGE System::ResourceString _SParamNameExpected;
#define Ibsql_SParamNameExpected System::LoadResourceString(&Ibsql::_SParamNameExpected)

}	/* namespace Ibsql */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibsql;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBSQL
