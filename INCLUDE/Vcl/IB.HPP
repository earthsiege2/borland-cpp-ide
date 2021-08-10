// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IB.pas' rev: 6.00

#ifndef IBHPP
#define IBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBXConst.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <IBUtils.hpp>	// Pascal unit
#include <IBExternals.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ib
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TTraceFlag { tfQPrepare, tfQExecute, tfQFetch, tfError, tfStmt, tfConnect, tfTransact, tfBlob, tfService, tfMisc };
#pragma option pop

typedef Set<TTraceFlag, tfQPrepare, tfMisc>  TTraceFlags;

class DELPHICLASS EIBError;
class PASCALIMPLEMENTATION EIBError : public Db::EDatabaseError 
{
	typedef Db::EDatabaseError inherited;
	
private:
	int FSQLCode;
	int FIBErrorCode;
	
public:
	__fastcall EIBError(int ASQLCode, AnsiString Msg)/* overload */;
	__fastcall EIBError(int ASQLCode, int AIBErrorCode, AnsiString Msg)/* overload */;
	__property int SQLCode = {read=FSQLCode, nodefault};
	__property int IBErrorCode = {read=FIBErrorCode, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Db::EDatabaseError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBError(int Ident)/* overload */ : Db::EDatabaseError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Db::EDatabaseError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBError(const AnsiString Msg, int AHelpContext) : Db::EDatabaseError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Db::EDatabaseError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBError(int Ident, int AHelpContext)/* overload */ : Db::EDatabaseError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Db::EDatabaseError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIBError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIBInterBaseError;
class PASCALIMPLEMENTATION EIBInterBaseError : public EIBError 
{
	typedef EIBError inherited;
	
public:
	#pragma option push -w-inl
	/* EIBError.Create */ inline __fastcall EIBInterBaseError(int ASQLCode, AnsiString Msg)/* overload */ : EIBError(ASQLCode, Msg) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBInterBaseError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIBError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBInterBaseError(int Ident)/* overload */ : EIBError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBInterBaseError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIBError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBInterBaseError(const AnsiString Msg, int AHelpContext) : EIBError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBInterBaseError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIBError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBInterBaseError(int Ident, int AHelpContext)/* overload */ : EIBError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBInterBaseError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIBError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIBInterBaseError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIBInterBaseRoleError;
class PASCALIMPLEMENTATION EIBInterBaseRoleError : public EIBError 
{
	typedef EIBError inherited;
	
public:
	#pragma option push -w-inl
	/* EIBError.Create */ inline __fastcall EIBInterBaseRoleError(int ASQLCode, AnsiString Msg)/* overload */ : EIBError(ASQLCode, Msg) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBInterBaseRoleError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIBError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBInterBaseRoleError(int Ident)/* overload */ : EIBError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBInterBaseRoleError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIBError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBInterBaseRoleError(const AnsiString Msg, int AHelpContext) : EIBError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBInterBaseRoleError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIBError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBInterBaseRoleError(int Ident, int AHelpContext)/* overload */ : EIBError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBInterBaseRoleError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIBError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIBInterBaseRoleError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIBClientError;
class PASCALIMPLEMENTATION EIBClientError : public EIBError 
{
	typedef EIBError inherited;
	
public:
	#pragma option push -w-inl
	/* EIBError.Create */ inline __fastcall EIBClientError(int ASQLCode, AnsiString Msg)/* overload */ : EIBError(ASQLCode, Msg) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBClientError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIBError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBClientError(int Ident)/* overload */ : EIBError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBClientError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIBError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBClientError(const AnsiString Msg, int AHelpContext) : EIBError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBClientError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIBError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBClientError(int Ident, int AHelpContext)/* overload */ : EIBError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBClientError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIBError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIBClientError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TIBDataBaseErrorMessage { ShowSQLCode, ShowIBMessage, ShowSQLMessage };
#pragma option pop

typedef Set<TIBDataBaseErrorMessage, ShowSQLCode, ShowSQLMessage>  TIBDataBaseErrorMessages;

#pragma option push -b-
enum TIBClientError { ibxeUnknownError, ibxeInterBaseMissing, ibxeInterBaseInstallMissing, ibxeIB60feature, ibxeNotSupported, ibxeNotPermitted, ibxeFileAccessError, ibxeConnectionTimeout, ibxeCannotSetDatabase, ibxeCannotSetTransaction, ibxeOperationCancelled, ibxeDPBConstantNotSupported, ibxeDPBConstantUnknown, ibxeTPBConstantNotSupported, ibxeTPBConstantUnknown, ibxeDatabaseClosed, ibxeDatabaseOpen, ibxeDatabaseNameMissing, ibxeNotInTransaction, ibxeInTransaction, ibxeTimeoutNegative, ibxeNoDatabasesInTransaction, ibxeUpdateWrongDB, ibxeUpdateWrongTR, ibxeDatabaseNotAssigned, ibxeTransactionNotAssigned, ibxeXSQLDAIndexOutOfRange, ibxeXSQLDANameDoesNotExist, ibxeEOF, ibxeBOF, ibxeInvalidStatementHandle, ibxeSQLOpen, ibxeSQLClosed, ibxeDatasetOpen, ibxeDatasetClosed, ibxeUnknownSQLDataType, ibxeInvalidColumnIndex, ibxeInvalidParamColumnIndex, ibxeInvalidDataConversion, ibxeColumnIsNotNullable, ibxeBlobCannotBeRead, ibxeBlobCannotBeWritten, ibxeEmptyQuery, ibxeCannotOpenNonSQLSelect, ibxeNoFieldAccess
	, ibxeFieldReadOnly, ibxeFieldNotFound, ibxeNotEditing, ibxeCannotInsert, ibxeCannotPost, ibxeCannotUpdate, ibxeCannotDelete, ibxeCannotRefresh, ibxeBufferNotSet, ibxeCircularReference, ibxeSQLParseError, ibxeUserAbort, ibxeDataSetUniDirectional, ibxeCannotCreateSharedResource, ibxeWindowsAPIError, ibxeColumnListsDontMatch, ibxeColumnTypesDontMatch, ibxeCantEndSharedTransaction, ibxeFieldUnsupportedType, ibxeCircularDataLink, ibxeEmptySQLStatement, ibxeIsASelectStatement, ibxeRequiredParamNotSet, ibxeNoStoredProcName, ibxeIsAExecuteProcedure, ibxeUpdateFailed, ibxeNotCachedUpdates, ibxeNotLiveRequest, ibxeNoProvider, ibxeNoRecordsAffected, ibxeNoTableName, ibxeCannotCreatePrimaryIndex, ibxeCannotDropSystemIndex, ibxeTableNameMismatch, ibxeIndexFieldMissing, ibxeInvalidCancellation, ibxeInvalidEvent, ibxeMaximumEvents, ibxeNoEventsRegistered, ibxeInvalidQueueing, ibxeInvalidRegistration, ibxeInvalidBatchMove, ibxeSQLDialectInvalid, ibxeSPBConstantNotSupported, ibxeSPBConstantUnknown, ibxeServiceActive, ibxeServiceInActive
	, ibxeServerNameMissing, ibxeQueryParamsError, ibxeStartParamsError, ibxeOutputParsingError, ibxeUseSpecificProcedures, ibxeSQLMonitorAlreadyPresent, ibxeCantPrintValue, ibxeEOFReached, ibxeEOFInComment, ibxeEOFInString, ibxeParamNameExpected, ibxeSuccess, ibxeDelphiException, ibxeNoOptionsSet, ibxeNoDestinationDirectory, ibxeNosourceDirectory, ibxeNoUninstallFile, ibxeOptionNeedsClient, ibxeOptionNeedsServer, ibxeInvalidOption, ibxeInvalidOnErrorResult, ibxeInvalidOnStatusResult, ibxeDPBConstantUnknownEx, ibxeTPBConstantUnknownEx, ibxeUnknownPlan, ibxeFieldSizeMismatch, ibxeEventAlreadyRegistered, ibxeStringTooLarge };
#pragma option pop

typedef int TStatusVector[20];

typedef int *PStatusVector;

typedef AnsiString IB__5[120];

//-- var, const, procedure ---------------------------------------------------
#define IBPalette1 "InterBase"
#define IBPalette2 "InterBase Admin"
static const Word IBLocalBufferLength = 0x200;
static const Word IBBigLocalBufferLength = 0x400;
static const Word IBHugeLocalBufferLength = 0x5000;
extern PACKAGE AnsiString IBErrorMessages[120];
extern PACKAGE _RTL_CRITICAL_SECTION IBCS;
extern PACKAGE void __fastcall IBAlloc(void *P, int OldSize, int NewSize);
extern PACKAGE void __fastcall IBError(TIBClientError ErrMess, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE void __fastcall IBDataBaseError(void);
extern PACKAGE Ibexternals::PISC_STATUS __fastcall StatusVector(void);
extern PACKAGE PStatusVector __fastcall StatusVectorArray(void);
extern PACKAGE bool __fastcall CheckStatusVector(const int * ErrorCodes, const int ErrorCodes_Size);
extern PACKAGE AnsiString __fastcall StatusVectorAsText();
extern PACKAGE void __fastcall SetIBDataBaseErrorMessages(TIBDataBaseErrorMessages Value);
extern PACKAGE TIBDataBaseErrorMessages __fastcall GetIBDataBaseErrorMessages(void);

}	/* namespace Ib */
using namespace Ib;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IB
