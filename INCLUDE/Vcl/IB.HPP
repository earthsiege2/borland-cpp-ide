// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IB.pas' rev: 5.00

#ifndef IBHPP
#define IBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Db.hpp>	// Pascal unit
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
	/* Exception.CreateFmt */ inline __fastcall EIBError(const AnsiString Msg, const System::TVarRec * 
		Args, const int Args_Size) : Db::EDatabaseError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBError(int Ident)/* overload */ : Db::EDatabaseError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBError(int Ident, const System::TVarRec * Args, const 
		int Args_Size)/* overload */ : Db::EDatabaseError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBError(const AnsiString Msg, int AHelpContext) : Db::EDatabaseError(
		Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Db::EDatabaseError(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBError(int Ident, int AHelpContext)/* overload */
		 : Db::EDatabaseError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBError(System::PResStringRec ResStringRec, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Db::EDatabaseError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
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
	/* EIBError.Create */ inline __fastcall EIBInterBaseError(int ASQLCode, AnsiString Msg)/* overload */
		 : EIBError(ASQLCode, Msg) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBInterBaseError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : EIBError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBInterBaseError(int Ident)/* overload */ : EIBError(Ident
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBInterBaseError(int Ident, const System::TVarRec * 
		Args, const int Args_Size)/* overload */ : EIBError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBInterBaseError(const AnsiString Msg, int AHelpContext
		) : EIBError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBInterBaseError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : EIBError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBInterBaseError(int Ident, int AHelpContext)/* overload */
		 : EIBError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBInterBaseError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIBError(ResStringRec
		, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIBInterBaseError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIBClientError;
class PASCALIMPLEMENTATION EIBClientError : public EIBError 
{
	typedef EIBError inherited;
	
public:
	#pragma option push -w-inl
	/* EIBError.Create */ inline __fastcall EIBClientError(int ASQLCode, AnsiString Msg)/* overload */ : 
		EIBError(ASQLCode, Msg) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBClientError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : EIBError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBClientError(int Ident)/* overload */ : EIBError(Ident
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBClientError(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : EIBError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBClientError(const AnsiString Msg, int AHelpContext)
		 : EIBError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBClientError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : EIBError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBClientError(int Ident, int AHelpContext)/* overload */
		 : EIBError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBClientError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIBError(ResStringRec
		, Args, Args_Size, AHelpContext) { }
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
enum TIBClientError { ibxeUnknownError, ibxeInterBaseMissing, ibxeInterBaseInstallMissing, ibxeIB60feature, 
	ibxeNotSupported, ibxeNotPermitted, ibxeFileAccessError, ibxeConnectionTimeout, ibxeCannotSetDatabase, 
	ibxeCannotSetTransaction, ibxeOperationCancelled, ibxeDPBConstantNotSupported, ibxeDPBConstantUnknown, 
	ibxeTPBConstantNotSupported, ibxeTPBConstantUnknown, ibxeDatabaseClosed, ibxeDatabaseOpen, ibxeDatabaseNameMissing, 
	ibxeNotInTransaction, ibxeInTransaction, ibxeTimeoutNegative, ibxeNoDatabasesInTransaction, ibxeUpdateWrongDB, 
	ibxeUpdateWrongTR, ibxeDatabaseNotAssigned, ibxeTransactionNotAssigned, ibxeXSQLDAIndexOutOfRange, 
	ibxeXSQLDANameDoesNotExist, ibxeEOF, ibxeBOF, ibxeInvalidStatementHandle, ibxeSQLOpen, ibxeSQLClosed, 
	ibxeDatasetOpen, ibxeDatasetClosed, ibxeUnknownSQLDataType, ibxeInvalidColumnIndex, ibxeInvalidParamColumnIndex, 
	ibxeInvalidDataConversion, ibxeColumnIsNotNullable, ibxeBlobCannotBeRead, ibxeBlobCannotBeWritten, 
	ibxeEmptyQuery, ibxeCannotOpenNonSQLSelect, ibxeNoFieldAccess, ibxeFieldReadOnly, ibxeFieldNotFound, 
	ibxeNotEditing, ibxeCannotInsert, ibxeCannotPost, ibxeCannotUpdate, ibxeCannotDelete, ibxeCannotRefresh, 
	ibxeBufferNotSet, ibxeCircularReference, ibxeSQLParseError, ibxeUserAbort, ibxeDataSetUniDirectional, 
	ibxeCannotCreateSharedResource, ibxeWindowsAPIError, ibxeColumnListsDontMatch, ibxeColumnTypesDontMatch, 
	ibxeCantEndSharedTransaction, ibxeFieldUnsupportedType, ibxeCircularDataLink, ibxeEmptySQLStatement, 
	ibxeIsASelectStatement, ibxeRequiredParamNotSet, ibxeNoStoredProcName, ibxeIsAExecuteProcedure, ibxeUpdateFailed, 
	ibxeNotCachedUpdates, ibxeNotLiveRequest, ibxeNoProvider, ibxeNoRecordsAffected, ibxeNoTableName, ibxeCannotCreatePrimaryIndex, 
	ibxeCannotDropSystemIndex, ibxeTableNameMismatch, ibxeIndexFieldMissing, ibxeInvalidCancellation, ibxeInvalidEvent, 
	ibxeMaximumEvents, ibxeNoEventsRegistered, ibxeInvalidQueueing, ibxeInvalidRegistration, ibxeInvalidBatchMove, 
	ibxeSQLDialectInvalid, ibxeSPBConstantNotSupported, ibxeSPBConstantUnknown, ibxeServiceActive, ibxeServiceInActive, 
	ibxeServerNameMissing, ibxeQueryParamsError, ibxeStartParamsError, ibxeOutputParsingError, ibxeUseSpecificProcedures, 
	ibxeSQLMonitorAlreadyPresent };
#pragma option pop

typedef int TStatusVector[20];

typedef int *PStatusVector;

struct TIBTLGlobals
{
	int FStatusVector[20];
} ;

typedef TIBTLGlobals *PIBTLGlobals;

typedef AnsiString IB__4[98];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::ResourceString _SIBDatabaseEditor;
#define Ib_SIBDatabaseEditor System::LoadResourceString(&Ib::_SIBDatabaseEditor)
extern PACKAGE System::ResourceString _SIBTransactionEditor;
#define Ib_SIBTransactionEditor System::LoadResourceString(&Ib::_SIBTransactionEditor)
extern PACKAGE System::ResourceString _SDatabaseFilter;
#define Ib_SDatabaseFilter System::LoadResourceString(&Ib::_SDatabaseFilter)
extern PACKAGE System::ResourceString _SDisconnectDatabase;
#define Ib_SDisconnectDatabase System::LoadResourceString(&Ib::_SDisconnectDatabase)
extern PACKAGE System::ResourceString _SCommitTransaction;
#define Ib_SCommitTransaction System::LoadResourceString(&Ib::_SCommitTransaction)
extern PACKAGE System::ResourceString _SExecute;
#define Ib_SExecute System::LoadResourceString(&Ib::_SExecute)
extern PACKAGE System::ResourceString _SNoDataSet;
#define Ib_SNoDataSet System::LoadResourceString(&Ib::_SNoDataSet)
extern PACKAGE System::ResourceString _SSQLGenSelect;
#define Ib_SSQLGenSelect System::LoadResourceString(&Ib::_SSQLGenSelect)
extern PACKAGE System::ResourceString _SSQLNotGenerated;
#define Ib_SSQLNotGenerated System::LoadResourceString(&Ib::_SSQLNotGenerated)
extern PACKAGE System::ResourceString _SIBUpdateSQLEditor;
#define Ib_SIBUpdateSQLEditor System::LoadResourceString(&Ib::_SIBUpdateSQLEditor)
extern PACKAGE System::ResourceString _SSQLDataSetOpen;
#define Ib_SSQLDataSetOpen System::LoadResourceString(&Ib::_SSQLDataSetOpen)
extern PACKAGE System::ResourceString _SUnknownError;
#define Ib_SUnknownError System::LoadResourceString(&Ib::_SUnknownError)
extern PACKAGE System::ResourceString _SInterBaseMissing;
#define Ib_SInterBaseMissing System::LoadResourceString(&Ib::_SInterBaseMissing)
extern PACKAGE System::ResourceString _SInterBaseInstallMissing;
#define Ib_SInterBaseInstallMissing System::LoadResourceString(&Ib::_SInterBaseInstallMissing)
extern PACKAGE System::ResourceString _SIB60feature;
#define Ib_SIB60feature System::LoadResourceString(&Ib::_SIB60feature)
extern PACKAGE System::ResourceString _SNotSupported;
#define Ib_SNotSupported System::LoadResourceString(&Ib::_SNotSupported)
extern PACKAGE System::ResourceString _SNotPermitted;
#define Ib_SNotPermitted System::LoadResourceString(&Ib::_SNotPermitted)
extern PACKAGE System::ResourceString _SFileAccessError;
#define Ib_SFileAccessError System::LoadResourceString(&Ib::_SFileAccessError)
extern PACKAGE System::ResourceString _SConnectionTimeout;
#define Ib_SConnectionTimeout System::LoadResourceString(&Ib::_SConnectionTimeout)
extern PACKAGE System::ResourceString _SCannotSetDatabase;
#define Ib_SCannotSetDatabase System::LoadResourceString(&Ib::_SCannotSetDatabase)
extern PACKAGE System::ResourceString _SCannotSetTransaction;
#define Ib_SCannotSetTransaction System::LoadResourceString(&Ib::_SCannotSetTransaction)
extern PACKAGE System::ResourceString _SOperationCancelled;
#define Ib_SOperationCancelled System::LoadResourceString(&Ib::_SOperationCancelled)
extern PACKAGE System::ResourceString _SDPBConstantNotSupported;
#define Ib_SDPBConstantNotSupported System::LoadResourceString(&Ib::_SDPBConstantNotSupported)
extern PACKAGE System::ResourceString _SDPBConstantUnknown;
#define Ib_SDPBConstantUnknown System::LoadResourceString(&Ib::_SDPBConstantUnknown)
extern PACKAGE System::ResourceString _STPBConstantNotSupported;
#define Ib_STPBConstantNotSupported System::LoadResourceString(&Ib::_STPBConstantNotSupported)
extern PACKAGE System::ResourceString _STPBConstantUnknown;
#define Ib_STPBConstantUnknown System::LoadResourceString(&Ib::_STPBConstantUnknown)
extern PACKAGE System::ResourceString _SDatabaseClosed;
#define Ib_SDatabaseClosed System::LoadResourceString(&Ib::_SDatabaseClosed)
extern PACKAGE System::ResourceString _SDatabaseOpen;
#define Ib_SDatabaseOpen System::LoadResourceString(&Ib::_SDatabaseOpen)
extern PACKAGE System::ResourceString _SDatabaseNameMissing;
#define Ib_SDatabaseNameMissing System::LoadResourceString(&Ib::_SDatabaseNameMissing)
extern PACKAGE System::ResourceString _SNotInTransaction;
#define Ib_SNotInTransaction System::LoadResourceString(&Ib::_SNotInTransaction)
extern PACKAGE System::ResourceString _SInTransaction;
#define Ib_SInTransaction System::LoadResourceString(&Ib::_SInTransaction)
extern PACKAGE System::ResourceString _STimeoutNegative;
#define Ib_STimeoutNegative System::LoadResourceString(&Ib::_STimeoutNegative)
extern PACKAGE System::ResourceString _SNoDatabasesInTransaction;
#define Ib_SNoDatabasesInTransaction System::LoadResourceString(&Ib::_SNoDatabasesInTransaction)
extern PACKAGE System::ResourceString _SUpdateWrongDB;
#define Ib_SUpdateWrongDB System::LoadResourceString(&Ib::_SUpdateWrongDB)
extern PACKAGE System::ResourceString _SUpdateWrongTR;
#define Ib_SUpdateWrongTR System::LoadResourceString(&Ib::_SUpdateWrongTR)
extern PACKAGE System::ResourceString _SDatabaseNotAssigned;
#define Ib_SDatabaseNotAssigned System::LoadResourceString(&Ib::_SDatabaseNotAssigned)
extern PACKAGE System::ResourceString _STransactionNotAssigned;
#define Ib_STransactionNotAssigned System::LoadResourceString(&Ib::_STransactionNotAssigned)
extern PACKAGE System::ResourceString _SXSQLDAIndexOutOfRange;
#define Ib_SXSQLDAIndexOutOfRange System::LoadResourceString(&Ib::_SXSQLDAIndexOutOfRange)
extern PACKAGE System::ResourceString _SXSQLDANameDoesNotExist;
#define Ib_SXSQLDANameDoesNotExist System::LoadResourceString(&Ib::_SXSQLDANameDoesNotExist)
extern PACKAGE System::ResourceString _SEOF;
#define Ib_SEOF System::LoadResourceString(&Ib::_SEOF)
extern PACKAGE System::ResourceString _SBOF;
#define Ib_SBOF System::LoadResourceString(&Ib::_SBOF)
extern PACKAGE System::ResourceString _SInvalidStatementHandle;
#define Ib_SInvalidStatementHandle System::LoadResourceString(&Ib::_SInvalidStatementHandle)
extern PACKAGE System::ResourceString _SSQLOpen;
#define Ib_SSQLOpen System::LoadResourceString(&Ib::_SSQLOpen)
extern PACKAGE System::ResourceString _SSQLClosed;
#define Ib_SSQLClosed System::LoadResourceString(&Ib::_SSQLClosed)
extern PACKAGE System::ResourceString _SDatasetOpen;
#define Ib_SDatasetOpen System::LoadResourceString(&Ib::_SDatasetOpen)
extern PACKAGE System::ResourceString _SDatasetClosed;
#define Ib_SDatasetClosed System::LoadResourceString(&Ib::_SDatasetClosed)
extern PACKAGE System::ResourceString _SUnknownSQLDataType;
#define Ib_SUnknownSQLDataType System::LoadResourceString(&Ib::_SUnknownSQLDataType)
extern PACKAGE System::ResourceString _SInvalidColumnIndex;
#define Ib_SInvalidColumnIndex System::LoadResourceString(&Ib::_SInvalidColumnIndex)
extern PACKAGE System::ResourceString _SInvalidParamColumnIndex;
#define Ib_SInvalidParamColumnIndex System::LoadResourceString(&Ib::_SInvalidParamColumnIndex)
extern PACKAGE System::ResourceString _SInvalidDataConversion;
#define Ib_SInvalidDataConversion System::LoadResourceString(&Ib::_SInvalidDataConversion)
extern PACKAGE System::ResourceString _SColumnIsNotNullable;
#define Ib_SColumnIsNotNullable System::LoadResourceString(&Ib::_SColumnIsNotNullable)
extern PACKAGE System::ResourceString _SBlobCannotBeRead;
#define Ib_SBlobCannotBeRead System::LoadResourceString(&Ib::_SBlobCannotBeRead)
extern PACKAGE System::ResourceString _SBlobCannotBeWritten;
#define Ib_SBlobCannotBeWritten System::LoadResourceString(&Ib::_SBlobCannotBeWritten)
extern PACKAGE System::ResourceString _SEmptyQuery;
#define Ib_SEmptyQuery System::LoadResourceString(&Ib::_SEmptyQuery)
extern PACKAGE System::ResourceString _SCannotOpenNonSQLSelect;
#define Ib_SCannotOpenNonSQLSelect System::LoadResourceString(&Ib::_SCannotOpenNonSQLSelect)
extern PACKAGE System::ResourceString _SNoFieldAccess;
#define Ib_SNoFieldAccess System::LoadResourceString(&Ib::_SNoFieldAccess)
extern PACKAGE System::ResourceString _SFieldReadOnly;
#define Ib_SFieldReadOnly System::LoadResourceString(&Ib::_SFieldReadOnly)
extern PACKAGE System::ResourceString _SFieldNotFound;
#define Ib_SFieldNotFound System::LoadResourceString(&Ib::_SFieldNotFound)
extern PACKAGE System::ResourceString _SNotEditing;
#define Ib_SNotEditing System::LoadResourceString(&Ib::_SNotEditing)
extern PACKAGE System::ResourceString _SCannotInsert;
#define Ib_SCannotInsert System::LoadResourceString(&Ib::_SCannotInsert)
extern PACKAGE System::ResourceString _SCannotPost;
#define Ib_SCannotPost System::LoadResourceString(&Ib::_SCannotPost)
extern PACKAGE System::ResourceString _SCannotUpdate;
#define Ib_SCannotUpdate System::LoadResourceString(&Ib::_SCannotUpdate)
extern PACKAGE System::ResourceString _SCannotDelete;
#define Ib_SCannotDelete System::LoadResourceString(&Ib::_SCannotDelete)
extern PACKAGE System::ResourceString _SCannotRefresh;
#define Ib_SCannotRefresh System::LoadResourceString(&Ib::_SCannotRefresh)
extern PACKAGE System::ResourceString _SBufferNotSet;
#define Ib_SBufferNotSet System::LoadResourceString(&Ib::_SBufferNotSet)
extern PACKAGE System::ResourceString _SCircularReference;
#define Ib_SCircularReference System::LoadResourceString(&Ib::_SCircularReference)
extern PACKAGE System::ResourceString _SSQLParseError;
#define Ib_SSQLParseError System::LoadResourceString(&Ib::_SSQLParseError)
extern PACKAGE System::ResourceString _SUserAbort;
#define Ib_SUserAbort System::LoadResourceString(&Ib::_SUserAbort)
extern PACKAGE System::ResourceString _SDataSetUniDirectional;
#define Ib_SDataSetUniDirectional System::LoadResourceString(&Ib::_SDataSetUniDirectional)
extern PACKAGE System::ResourceString _SCannotCreateSharedResource;
#define Ib_SCannotCreateSharedResource System::LoadResourceString(&Ib::_SCannotCreateSharedResource)
	
extern PACKAGE System::ResourceString _SWindowsAPIError;
#define Ib_SWindowsAPIError System::LoadResourceString(&Ib::_SWindowsAPIError)
extern PACKAGE System::ResourceString _SColumnListsDontMatch;
#define Ib_SColumnListsDontMatch System::LoadResourceString(&Ib::_SColumnListsDontMatch)
extern PACKAGE System::ResourceString _SColumnTypesDontMatch;
#define Ib_SColumnTypesDontMatch System::LoadResourceString(&Ib::_SColumnTypesDontMatch)
extern PACKAGE System::ResourceString _SCantEndSharedTransaction;
#define Ib_SCantEndSharedTransaction System::LoadResourceString(&Ib::_SCantEndSharedTransaction)
extern PACKAGE System::ResourceString _SFieldUnsupportedType;
#define Ib_SFieldUnsupportedType System::LoadResourceString(&Ib::_SFieldUnsupportedType)
extern PACKAGE System::ResourceString _SCircularDataLink;
#define Ib_SCircularDataLink System::LoadResourceString(&Ib::_SCircularDataLink)
extern PACKAGE System::ResourceString _SEmptySQLStatement;
#define Ib_SEmptySQLStatement System::LoadResourceString(&Ib::_SEmptySQLStatement)
extern PACKAGE System::ResourceString _SIsASelectStatement;
#define Ib_SIsASelectStatement System::LoadResourceString(&Ib::_SIsASelectStatement)
extern PACKAGE System::ResourceString _SRequiredParamNotSet;
#define Ib_SRequiredParamNotSet System::LoadResourceString(&Ib::_SRequiredParamNotSet)
extern PACKAGE System::ResourceString _SNoStoredProcName;
#define Ib_SNoStoredProcName System::LoadResourceString(&Ib::_SNoStoredProcName)
extern PACKAGE System::ResourceString _SIsAExecuteProcedure;
#define Ib_SIsAExecuteProcedure System::LoadResourceString(&Ib::_SIsAExecuteProcedure)
extern PACKAGE System::ResourceString _SUpdateFailed;
#define Ib_SUpdateFailed System::LoadResourceString(&Ib::_SUpdateFailed)
extern PACKAGE System::ResourceString _SNotCachedUpdates;
#define Ib_SNotCachedUpdates System::LoadResourceString(&Ib::_SNotCachedUpdates)
extern PACKAGE System::ResourceString _SNotLiveRequest;
#define Ib_SNotLiveRequest System::LoadResourceString(&Ib::_SNotLiveRequest)
extern PACKAGE System::ResourceString _SNoProvider;
#define Ib_SNoProvider System::LoadResourceString(&Ib::_SNoProvider)
extern PACKAGE System::ResourceString _SNoRecordsAffected;
#define Ib_SNoRecordsAffected System::LoadResourceString(&Ib::_SNoRecordsAffected)
extern PACKAGE System::ResourceString _SNoTableName;
#define Ib_SNoTableName System::LoadResourceString(&Ib::_SNoTableName)
extern PACKAGE System::ResourceString _SCannotCreatePrimaryIndex;
#define Ib_SCannotCreatePrimaryIndex System::LoadResourceString(&Ib::_SCannotCreatePrimaryIndex)
extern PACKAGE System::ResourceString _SCannotDropSystemIndex;
#define Ib_SCannotDropSystemIndex System::LoadResourceString(&Ib::_SCannotDropSystemIndex)
extern PACKAGE System::ResourceString _STableNameMismatch;
#define Ib_STableNameMismatch System::LoadResourceString(&Ib::_STableNameMismatch)
extern PACKAGE System::ResourceString _SIndexFieldMissing;
#define Ib_SIndexFieldMissing System::LoadResourceString(&Ib::_SIndexFieldMissing)
extern PACKAGE System::ResourceString _SInvalidCancellation;
#define Ib_SInvalidCancellation System::LoadResourceString(&Ib::_SInvalidCancellation)
extern PACKAGE System::ResourceString _SInvalidEvent;
#define Ib_SInvalidEvent System::LoadResourceString(&Ib::_SInvalidEvent)
extern PACKAGE System::ResourceString _SMaximumEvents;
#define Ib_SMaximumEvents System::LoadResourceString(&Ib::_SMaximumEvents)
extern PACKAGE System::ResourceString _SNoEventsRegistered;
#define Ib_SNoEventsRegistered System::LoadResourceString(&Ib::_SNoEventsRegistered)
extern PACKAGE System::ResourceString _SInvalidQueueing;
#define Ib_SInvalidQueueing System::LoadResourceString(&Ib::_SInvalidQueueing)
extern PACKAGE System::ResourceString _SInvalidRegistration;
#define Ib_SInvalidRegistration System::LoadResourceString(&Ib::_SInvalidRegistration)
extern PACKAGE System::ResourceString _SInvalidBatchMove;
#define Ib_SInvalidBatchMove System::LoadResourceString(&Ib::_SInvalidBatchMove)
extern PACKAGE System::ResourceString _SSQLDialectInvalid;
#define Ib_SSQLDialectInvalid System::LoadResourceString(&Ib::_SSQLDialectInvalid)
extern PACKAGE System::ResourceString _SSPBConstantNotSupported;
#define Ib_SSPBConstantNotSupported System::LoadResourceString(&Ib::_SSPBConstantNotSupported)
extern PACKAGE System::ResourceString _SSPBConstantUnknown;
#define Ib_SSPBConstantUnknown System::LoadResourceString(&Ib::_SSPBConstantUnknown)
extern PACKAGE System::ResourceString _SServiceActive;
#define Ib_SServiceActive System::LoadResourceString(&Ib::_SServiceActive)
extern PACKAGE System::ResourceString _SServiceInActive;
#define Ib_SServiceInActive System::LoadResourceString(&Ib::_SServiceInActive)
extern PACKAGE System::ResourceString _SServerNameMissing;
#define Ib_SServerNameMissing System::LoadResourceString(&Ib::_SServerNameMissing)
extern PACKAGE System::ResourceString _SQueryParamsError;
#define Ib_SQueryParamsError System::LoadResourceString(&Ib::_SQueryParamsError)
extern PACKAGE System::ResourceString _SStartParamsError;
#define Ib_SStartParamsError System::LoadResourceString(&Ib::_SStartParamsError)
extern PACKAGE System::ResourceString _SOutputParsingError;
#define Ib_SOutputParsingError System::LoadResourceString(&Ib::_SOutputParsingError)
extern PACKAGE System::ResourceString _SUseSpecificProcedures;
#define Ib_SUseSpecificProcedures System::LoadResourceString(&Ib::_SUseSpecificProcedures)
extern PACKAGE System::ResourceString _SSQLMonitorAlreadyPresent;
#define Ib_SSQLMonitorAlreadyPresent System::LoadResourceString(&Ib::_SSQLMonitorAlreadyPresent)
#define IBPalette1 "InterBase"
#define IBPalette2 "InterBase Admin"
static const Word IBLocalBufferLength = 0x200;
static const Word IBBigLocalBufferLength = 0x400;
static const Word IBHugeLocalBufferLength = 0x5000;
extern PACKAGE AnsiString IBErrorMessages[98];
extern PACKAGE _RTL_CRITICAL_SECTION IBCS;
extern PACKAGE unsigned hIBTLGlobals;
extern PACKAGE void __fastcall IBAlloc(void *P, int OldSize, int NewSize);
extern PACKAGE void __fastcall IBError(TIBClientError ErrMess, const System::TVarRec * Args, const int 
	Args_Size);
extern PACKAGE void __fastcall IBDataBaseError(void);
extern PACKAGE void __fastcall InitializeIBTLGlobals(void);
extern PACKAGE void __fastcall FreeIBTLGlobals(void);
extern PACKAGE Ibexternals::PISC_STATUS __fastcall StatusVector(void);
extern PACKAGE PStatusVector __fastcall StatusVectorArray(void);
extern PACKAGE bool __fastcall CheckStatusVector(const int * ErrorCodes, const int ErrorCodes_Size);
	
extern PACKAGE AnsiString __fastcall StatusVectorAsText();
extern PACKAGE void __fastcall SetIBDataBaseErrorMessages(TIBDataBaseErrorMessages Value);
extern PACKAGE TIBDataBaseErrorMessages __fastcall GetIBDataBaseErrorMessages(void);

}	/* namespace Ib */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ib;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IB
