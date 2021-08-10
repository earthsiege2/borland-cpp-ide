// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBDatabaseInfo.pas' rev: 5.00

#ifndef IBDatabaseInfoHPP
#define IBDatabaseInfoHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBDatabase.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <IBExternals.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibdatabaseinfo
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBDatabaseInfo;
class PASCALIMPLEMENTATION TIBDatabaseInfo : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
protected:
	bool FIBLoaded;
	Ibdatabase::TIBDatabase* FDatabase;
	Classes::TStringList* FUserNames;
	Classes::TStringList* FBackoutCount;
	Classes::TStringList* FDeleteCount;
	Classes::TStringList* FExpungeCount;
	Classes::TStringList* FInsertCount;
	Classes::TStringList* FPurgeCount;
	Classes::TStringList* FReadIdxCount;
	Classes::TStringList* FReadSeqCount;
	Classes::TStringList* FUpdateCount;
	int __fastcall GetAllocation(void);
	int __fastcall GetBaseLevel(void);
	AnsiString __fastcall GetDBFileName();
	AnsiString __fastcall GetDBSiteName();
	int __fastcall GetDBImplementationNo(void);
	int __fastcall GetDBImplementationClass(void);
	int __fastcall GetNoReserve(void);
	int __fastcall GetODSMinorVersion(void);
	int __fastcall GetODSMajorVersion(void);
	int __fastcall GetPageSize(void);
	AnsiString __fastcall GetVersion();
	int __fastcall GetCurrentMemory(void);
	int __fastcall GetForcedWrites(void);
	int __fastcall GetMaxMemory(void);
	int __fastcall GetNumBuffers(void);
	int __fastcall GetSweepInterval(void);
	Classes::TStringList* __fastcall GetUserNames(void);
	int __fastcall GetFetches(void);
	int __fastcall GetMarks(void);
	int __fastcall GetReads(void);
	int __fastcall GetWrites(void);
	Classes::TStringList* __fastcall GetBackoutCount(void);
	Classes::TStringList* __fastcall GetDeleteCount(void);
	Classes::TStringList* __fastcall GetExpungeCount(void);
	Classes::TStringList* __fastcall GetInsertCount(void);
	Classes::TStringList* __fastcall GetPurgeCount(void);
	Classes::TStringList* __fastcall GetReadIdxCount(void);
	Classes::TStringList* __fastcall GetReadSeqCount(void);
	Classes::TStringList* __fastcall GetUpdateCount(void);
	Classes::TStringList* __fastcall GetOperationCounts(int DBInfoCommand, Classes::TStringList* FOperation
		);
	int __fastcall GetReadOnly(void);
	int __fastcall GetLongDatabaseInfo(int DatabaseInfoCommand);
	AnsiString __fastcall GetStringDatabaseInfo(int DatabaseInfoCommand);
	int __fastcall GetDBSQLDialect(void);
	
public:
	__fastcall virtual TIBDatabaseInfo(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBDatabaseInfo(void);
	int __fastcall Call(int ErrCode, bool RaiseError);
	__property int Allocation = {read=GetAllocation, nodefault};
	__property int BaseLevel = {read=GetBaseLevel, nodefault};
	__property AnsiString DBFileName = {read=GetDBFileName};
	__property AnsiString DBSiteName = {read=GetDBSiteName};
	__property int DBImplementationNo = {read=GetDBImplementationNo, nodefault};
	__property int DBImplementationClass = {read=GetDBImplementationClass, nodefault};
	__property int NoReserve = {read=GetNoReserve, nodefault};
	__property int ODSMinorVersion = {read=GetODSMinorVersion, nodefault};
	__property int ODSMajorVersion = {read=GetODSMajorVersion, nodefault};
	__property int PageSize = {read=GetPageSize, nodefault};
	__property AnsiString Version = {read=GetVersion};
	__property int CurrentMemory = {read=GetCurrentMemory, nodefault};
	__property int ForcedWrites = {read=GetForcedWrites, nodefault};
	__property int MaxMemory = {read=GetMaxMemory, nodefault};
	__property int NumBuffers = {read=GetNumBuffers, nodefault};
	__property int SweepInterval = {read=GetSweepInterval, nodefault};
	__property Classes::TStringList* UserNames = {read=GetUserNames};
	__property int Fetches = {read=GetFetches, nodefault};
	__property int Marks = {read=GetMarks, nodefault};
	__property int Reads = {read=GetReads, nodefault};
	__property int Writes = {read=GetWrites, nodefault};
	__property Classes::TStringList* BackoutCount = {read=GetBackoutCount};
	__property Classes::TStringList* DeleteCount = {read=GetDeleteCount};
	__property Classes::TStringList* ExpungeCount = {read=GetExpungeCount};
	__property Classes::TStringList* InsertCount = {read=GetInsertCount};
	__property Classes::TStringList* PurgeCount = {read=GetPurgeCount};
	__property Classes::TStringList* ReadIdxCount = {read=GetReadIdxCount};
	__property Classes::TStringList* ReadSeqCount = {read=GetReadSeqCount};
	__property Classes::TStringList* UpdateCount = {read=GetUpdateCount};
	__property int DBSQLDialect = {read=GetDBSQLDialect, nodefault};
	__property int ReadOnly = {read=GetReadOnly, nodefault};
	
__published:
	__property Ibdatabase::TIBDatabase* Database = {read=FDatabase, write=FDatabase};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ibdatabaseinfo */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibdatabaseinfo;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBDatabaseInfo
