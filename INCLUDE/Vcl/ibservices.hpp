// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBServices.pas' rev: 6.00

#ifndef IBServicesHPP
#define IBServicesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBExternals.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibservices
{
//-- type declarations -------------------------------------------------------
typedef AnsiString IBServices__1[12];

#pragma option push -b-
enum TProtocol { TCP, SPX, NamedPipe, Local };
#pragma option pop

#pragma option push -b-
enum TOutputBufferOption { ByLine, ByChunk };
#pragma option pop

class DELPHICLASS TIBCustomService;
typedef void __fastcall (__closure *TLoginEvent)(TIBCustomService* Database, Classes::TStrings* LoginParams);

class PASCALIMPLEMENTATION TIBCustomService : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FIBLoaded;
	bool FParamsChanged;
	char *FSPB;
	char *FQuerySPB;
	short FSPBLength;
	short FQuerySPBLength;
	Ib::TTraceFlags FTraceFlags;
	TLoginEvent FOnLogin;
	bool FLoginPrompt;
	int FBufferSize;
	char *FOutputBuffer;
	AnsiString FQueryParams;
	AnsiString FServerName;
	void * *FHandle;
	bool FStreamedActive;
	Classes::TNotifyEvent FOnAttach;
	TOutputBufferOption FOutputBufferOption;
	TProtocol FProtocol;
	Classes::TStrings* FParams;
	bool __fastcall GetActive(void);
	AnsiString __fastcall GetServiceParamBySPB(const int Idx);
	void __fastcall SetActive(const bool Value);
	void __fastcall SetBufferSize(const int Value);
	void __fastcall SetParams(const Classes::TStrings* Value);
	void __fastcall SetServerName(const AnsiString Value);
	void __fastcall SetProtocol(const TProtocol Value);
	void __fastcall SetServiceParamBySPB(const int Idx, const AnsiString Value);
	int __fastcall IndexOfSPBConst(AnsiString st);
	void __fastcall ParamsChange(System::TObject* Sender);
	void __fastcall ParamsChanging(System::TObject* Sender);
	void __fastcall CheckServerName(void);
	int __fastcall Call(int ErrCode, bool RaiseError);
	AnsiString __fastcall ParseString(int &RunLen);
	int __fastcall ParseInteger(int &RunLen);
	void __fastcall GenerateSPB(Classes::TStrings* sl, AnsiString &SPB, short &SPBLength);
	
protected:
	virtual void __fastcall Loaded(void);
	bool __fastcall Login(void);
	void __fastcall CheckActive(void);
	void __fastcall CheckInactive(void);
	__property char * OutputBuffer = {read=FOutputBuffer};
	__property TOutputBufferOption OutputBufferOption = {read=FOutputBufferOption, write=FOutputBufferOption, nodefault};
	__property int BufferSize = {read=FBufferSize, write=SetBufferSize, default=32000};
	void __fastcall InternalServiceQuery(void);
	__property AnsiString ServiceQueryParams = {read=FQueryParams, write=FQueryParams};
	
public:
	__fastcall virtual TIBCustomService(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBCustomService(void);
	void __fastcall Attach(void);
	void __fastcall Detach(void);
	__property Ibexternals::PVoid Handle = {read=FHandle};
	__property AnsiString ServiceParamBySPB[int Idx] = {read=GetServiceParamBySPB, write=SetServiceParamBySPB};
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property AnsiString ServerName = {read=FServerName, write=SetServerName};
	__property TProtocol Protocol = {read=FProtocol, write=SetProtocol, default=3};
	__property Classes::TStrings* Params = {read=FParams, write=SetParams};
	__property bool LoginPrompt = {read=FLoginPrompt, write=FLoginPrompt, default=1};
	__property Ib::TTraceFlags TraceFlags = {read=FTraceFlags, write=FTraceFlags, nodefault};
	__property Classes::TNotifyEvent OnAttach = {read=FOnAttach, write=FOnAttach};
	__property TLoginEvent OnLogin = {read=FOnLogin, write=FOnLogin};
};


typedef DynamicArray<AnsiString >  IBServices__4;

class DELPHICLASS TDatabaseInfo;
class PASCALIMPLEMENTATION TDatabaseInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int NoOfAttachments;
	int NoOfDatabases;
	DynamicArray<AnsiString >  DbName;
	__fastcall TDatabaseInfo(void);
	__fastcall virtual ~TDatabaseInfo(void);
};


typedef DynamicArray<AnsiString >  IBServices__6;

typedef DynamicArray<AnsiString >  IBServices__7;

typedef DynamicArray<AnsiString >  IBServices__8;

class DELPHICLASS TLicenseInfo;
class PASCALIMPLEMENTATION TLicenseInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	DynamicArray<AnsiString >  Key;
	DynamicArray<AnsiString >  Id;
	DynamicArray<AnsiString >  Desc;
	int LicensedUsers;
	__fastcall TLicenseInfo(void);
	__fastcall virtual ~TLicenseInfo(void);
};


class DELPHICLASS TLicenseMaskInfo;
class PASCALIMPLEMENTATION TLicenseMaskInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int LicenseMask;
	int CapabilityMask;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TLicenseMaskInfo(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TLicenseMaskInfo(void) { }
	#pragma option pop
	
};


typedef DynamicArray<int >  IBServices__11;

typedef DynamicArray<int >  IBServices__21;

class DELPHICLASS TConfigFileData;
class PASCALIMPLEMENTATION TConfigFileData : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	DynamicArray<int >  ConfigFileValue;
	DynamicArray<int >  ConfigFileKey;
	__fastcall TConfigFileData(void);
	__fastcall virtual ~TConfigFileData(void);
};


typedef DynamicArray<AnsiString >  IBServices__41;

class DELPHICLASS TConfigParams;
class PASCALIMPLEMENTATION TConfigParams : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TConfigFileData* ConfigFileData;
	DynamicArray<AnsiString >  ConfigFileParams;
	AnsiString BaseLocation;
	AnsiString LockFileLocation;
	AnsiString MessageFileLocation;
	AnsiString SecurityDatabaseLocation;
	__fastcall TConfigParams(void);
	__fastcall virtual ~TConfigParams(void);
};


class DELPHICLASS TVersionInfo;
class PASCALIMPLEMENTATION TVersionInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString ServerVersion;
	AnsiString ServerImplementation;
	int ServiceVersion;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TVersionInfo(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TVersionInfo(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPropertyOption { Database, License, LicenseMask, ConfigParameters, Version };
#pragma option pop

typedef Set<TPropertyOption, Database, Version>  TPropertyOptions;

class DELPHICLASS TIBServerProperties;
class PASCALIMPLEMENTATION TIBServerProperties : public TIBCustomService 
{
	typedef TIBCustomService inherited;
	
private:
	TPropertyOptions FOptions;
	TDatabaseInfo* FDatabaseInfo;
	TLicenseInfo* FLicenseInfo;
	TLicenseMaskInfo* FLicenseMaskInfo;
	TVersionInfo* FVersionInfo;
	TConfigParams* FConfigParams;
	void __fastcall ParseConfigFileData(int &RunLen);
	
public:
	__fastcall virtual TIBServerProperties(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBServerProperties(void);
	void __fastcall Fetch(void);
	void __fastcall FetchDatabaseInfo(void);
	void __fastcall FetchLicenseInfo(void);
	void __fastcall FetchLicenseMaskInfo(void);
	void __fastcall FetchConfigParams(void);
	void __fastcall FetchVersionInfo(void);
	__property TDatabaseInfo* DatabaseInfo = {read=FDatabaseInfo};
	__property TLicenseInfo* LicenseInfo = {read=FLicenseInfo};
	__property TLicenseMaskInfo* LicenseMaskInfo = {read=FLicenseMaskInfo};
	__property TVersionInfo* VersionInfo = {read=FVersionInfo};
	__property TConfigParams* ConfigParams = {read=FConfigParams};
	
__published:
	__property TPropertyOptions Options = {read=FOptions, write=FOptions, nodefault};
};


class DELPHICLASS TIBControlService;
class PASCALIMPLEMENTATION TIBControlService : public TIBCustomService 
{
	typedef TIBCustomService inherited;
	
private:
	AnsiString FStartParams;
	char *FStartSPB;
	int FStartSPBLength;
	bool __fastcall GetIsServiceRunning(void);
	
protected:
	__property AnsiString ServiceStartParams = {read=FStartParams, write=FStartParams};
	virtual void __fastcall SetServiceStartOptions(void);
	void __fastcall ServiceStartAddParam(AnsiString Value, int param)/* overload */;
	void __fastcall ServiceStartAddParam(int Value, int param)/* overload */;
	void __fastcall InternalServiceStart(void);
	
public:
	__fastcall virtual TIBControlService(Classes::TComponent* AOwner);
	virtual void __fastcall ServiceStart(void);
	__property bool IsServiceRunning = {read=GetIsServiceRunning, nodefault};
public:
	#pragma option push -w-inl
	/* TIBCustomService.Destroy */ inline __fastcall virtual ~TIBControlService(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBControlAndQueryService;
class PASCALIMPLEMENTATION TIBControlAndQueryService : public TIBControlService 
{
	typedef TIBControlService inherited;
	
private:
	bool FEof;
	int FAction;
	void __fastcall SetAction(int Value);
	
protected:
	__property int Action = {read=FAction, write=SetAction, nodefault};
	
public:
	__fastcall virtual TIBControlAndQueryService(Classes::TComponent* AOwner);
	AnsiString __fastcall GetNextLine();
	AnsiString __fastcall GetNextChunk();
	__property bool Eof = {read=FEof, nodefault};
	
__published:
	__property BufferSize  = {default=32000};
public:
	#pragma option push -w-inl
	/* TIBCustomService.Destroy */ inline __fastcall virtual ~TIBControlAndQueryService(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TShutdownMode { Forced, DenyTransaction, DenyAttachment };
#pragma option pop

class DELPHICLASS TIBConfigService;
class PASCALIMPLEMENTATION TIBConfigService : public TIBControlService 
{
	typedef TIBControlService inherited;
	
private:
	AnsiString FDatabaseName;
	void __fastcall SetDatabaseName(const AnsiString Value);
	
public:
	virtual void __fastcall ServiceStart(void);
	void __fastcall ShutdownDatabase(TShutdownMode Options, int Wait);
	void __fastcall SetSweepInterval(int Value);
	void __fastcall SetDBSqlDialect(int Value);
	void __fastcall SetPageBuffers(int Value);
	void __fastcall ActivateShadow(void);
	void __fastcall BringDatabaseOnline(void);
	void __fastcall SetReserveSpace(bool Value);
	void __fastcall SetAsyncMode(bool Value);
	void __fastcall SetReadOnly(bool Value);
	
__published:
	__property AnsiString DatabaseName = {read=FDatabaseName, write=SetDatabaseName};
public:
	#pragma option push -w-inl
	/* TIBControlService.Create */ inline __fastcall virtual TIBConfigService(Classes::TComponent* AOwner) : TIBControlService(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TIBCustomService.Destroy */ inline __fastcall virtual ~TIBConfigService(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TLicensingAction { LicenseAdd, LicenseRemove };
#pragma option pop

class DELPHICLASS TIBLicensingService;
class PASCALIMPLEMENTATION TIBLicensingService : public TIBControlService 
{
	typedef TIBControlService inherited;
	
private:
	AnsiString FID;
	AnsiString FKey;
	TLicensingAction FAction;
	void __fastcall SetAction(TLicensingAction Value);
	
protected:
	virtual void __fastcall SetServiceStartOptions(void);
	
public:
	void __fastcall AddLicense(void);
	void __fastcall RemoveLicense(void);
	
__published:
	__property TLicensingAction Action = {read=FAction, write=SetAction, default=0};
	__property AnsiString Key = {read=FKey, write=FKey};
	__property AnsiString ID = {read=FID, write=FID};
public:
	#pragma option push -w-inl
	/* TIBControlService.Create */ inline __fastcall virtual TIBLicensingService(Classes::TComponent* AOwner) : TIBControlService(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TIBCustomService.Destroy */ inline __fastcall virtual ~TIBLicensingService(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBLogService;
class PASCALIMPLEMENTATION TIBLogService : public TIBControlAndQueryService 
{
	typedef TIBControlAndQueryService inherited;
	
protected:
	virtual void __fastcall SetServiceStartOptions(void);
public:
	#pragma option push -w-inl
	/* TIBControlAndQueryService.create */ inline __fastcall virtual TIBLogService(Classes::TComponent* AOwner) : TIBControlAndQueryService(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TIBCustomService.Destroy */ inline __fastcall virtual ~TIBLogService(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TStatOption { DataPages, DbLog, HeaderPages, IndexPages, SystemRelations };
#pragma option pop

typedef Set<TStatOption, DataPages, SystemRelations>  TStatOptions;

class DELPHICLASS TIBStatisticalService;
class PASCALIMPLEMENTATION TIBStatisticalService : public TIBControlAndQueryService 
{
	typedef TIBControlAndQueryService inherited;
	
private:
	AnsiString FDatabaseName;
	TStatOptions FOptions;
	void __fastcall SetDatabaseName(const AnsiString Value);
	
protected:
	virtual void __fastcall SetServiceStartOptions(void);
	
__published:
	__property AnsiString DatabaseName = {read=FDatabaseName, write=SetDatabaseName};
	__property TStatOptions Options = {read=FOptions, write=FOptions, nodefault};
public:
	#pragma option push -w-inl
	/* TIBControlAndQueryService.create */ inline __fastcall virtual TIBStatisticalService(Classes::TComponent* AOwner) : TIBControlAndQueryService(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TIBCustomService.Destroy */ inline __fastcall virtual ~TIBStatisticalService(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBBackupRestoreService;
class PASCALIMPLEMENTATION TIBBackupRestoreService : public TIBControlAndQueryService 
{
	typedef TIBControlAndQueryService inherited;
	
private:
	bool FVerbose;
	
__published:
	__property bool Verbose = {read=FVerbose, write=FVerbose, default=0};
public:
	#pragma option push -w-inl
	/* TIBControlAndQueryService.create */ inline __fastcall virtual TIBBackupRestoreService(Classes::TComponent* AOwner) : TIBControlAndQueryService(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TIBCustomService.Destroy */ inline __fastcall virtual ~TIBBackupRestoreService(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TBackupOption { IgnoreChecksums, IgnoreLimbo, MetadataOnly, NoGarbageCollection, OldMetadataDesc, NonTransportable, ConvertExtTables };
#pragma option pop

typedef Set<TBackupOption, IgnoreChecksums, ConvertExtTables>  TBackupOptions;

class DELPHICLASS TIBBackupService;
class PASCALIMPLEMENTATION TIBBackupService : public TIBBackupRestoreService 
{
	typedef TIBBackupRestoreService inherited;
	
private:
	AnsiString FDatabaseName;
	TBackupOptions FOptions;
	Classes::TStrings* FBackupFile;
	int FBlockingFactor;
	void __fastcall SetBackupFile(const Classes::TStrings* Value);
	
protected:
	virtual void __fastcall SetServiceStartOptions(void);
	
public:
	__fastcall virtual TIBBackupService(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBBackupService(void);
	
__published:
	__property Classes::TStrings* BackupFile = {read=FBackupFile, write=SetBackupFile};
	__property int BlockingFactor = {read=FBlockingFactor, write=FBlockingFactor, nodefault};
	__property AnsiString DatabaseName = {read=FDatabaseName, write=FDatabaseName};
	__property TBackupOptions Options = {read=FOptions, write=FOptions, nodefault};
};


#pragma option push -b-
enum TRestoreOption { DeactivateIndexes, NoShadow, NoValidityCheck, OneRelationAtATime, Replace, CreateNewDB, UseAllSpace };
#pragma option pop

typedef Set<TRestoreOption, DeactivateIndexes, UseAllSpace>  TRestoreOptions;

class DELPHICLASS TIBRestoreService;
class PASCALIMPLEMENTATION TIBRestoreService : public TIBBackupRestoreService 
{
	typedef TIBBackupRestoreService inherited;
	
private:
	Classes::TStrings* FDatabaseName;
	Classes::TStrings* FBackupFile;
	TRestoreOptions FOptions;
	int FPageSize;
	int FPageBuffers;
	void __fastcall SetBackupFile(const Classes::TStrings* Value);
	void __fastcall SetDatabaseName(const Classes::TStrings* Value);
	
protected:
	virtual void __fastcall SetServiceStartOptions(void);
	
public:
	__fastcall virtual TIBRestoreService(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBRestoreService(void);
	
__published:
	__property Classes::TStrings* DatabaseName = {read=FDatabaseName, write=SetDatabaseName};
	__property Classes::TStrings* BackupFile = {read=FBackupFile, write=SetBackupFile};
	__property int PageSize = {read=FPageSize, write=FPageSize, default=4096};
	__property int PageBuffers = {read=FPageBuffers, write=FPageBuffers, nodefault};
	__property TRestoreOptions Options = {read=FOptions, write=FOptions, default=32};
};


#pragma option push -b-
enum TValidateOption { LimboTransactions, CheckDB, IgnoreChecksum, KillShadows, MendDB, SweepDB, ValidateDB, ValidateFull };
#pragma option pop

typedef Set<TValidateOption, LimboTransactions, ValidateFull>  TValidateOptions;

#pragma option push -b-
enum TTransactionGlobalAction { CommitGlobal, RollbackGlobal, RecoverTwoPhaseGlobal, NoGlobalAction };
#pragma option pop

#pragma option push -b-
enum TTransactionState { LimboState, CommitState, RollbackState, UnknownState };
#pragma option pop

#pragma option push -b-
enum TTransactionAdvise { CommitAdvise, RollbackAdvise, UnknownAdvise };
#pragma option pop

#pragma option push -b-
enum TTransactionAction { CommitAction, RollbackAction };
#pragma option pop

class DELPHICLASS TLimboTransactionInfo;
class PASCALIMPLEMENTATION TLimboTransactionInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	bool MultiDatabase;
	int ID;
	AnsiString HostSite;
	AnsiString RemoteSite;
	AnsiString RemoteDatabasePath;
	TTransactionState State;
	TTransactionAdvise Advise;
	TTransactionAction Action;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TLimboTransactionInfo(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TLimboTransactionInfo(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TLimboTransactionInfo* >  IBServices__82;

class DELPHICLASS TIBValidationService;
class PASCALIMPLEMENTATION TIBValidationService : public TIBControlAndQueryService 
{
	typedef TIBControlAndQueryService inherited;
	
private:
	AnsiString FDatabaseName;
	TValidateOptions FOptions;
	DynamicArray<TLimboTransactionInfo* >  FLimboTransactionInfo;
	TTransactionGlobalAction FGlobalAction;
	void __fastcall SetDatabaseName(const AnsiString Value);
	TLimboTransactionInfo* __fastcall GetLimboTransactionInfo(int index);
	int __fastcall GetLimboTransactionInfoCount(void);
	
protected:
	virtual void __fastcall SetServiceStartOptions(void);
	
public:
	__fastcall virtual TIBValidationService(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBValidationService(void);
	void __fastcall FetchLimboTransactionInfo(void);
	void __fastcall FixLimboTransactionErrors(void);
	__property TLimboTransactionInfo* LimboTransactionInfo[int Index] = {read=GetLimboTransactionInfo};
	__property int LimboTransactionInfoCount = {read=GetLimboTransactionInfoCount, nodefault};
	
__published:
	__property AnsiString DatabaseName = {read=FDatabaseName, write=SetDatabaseName};
	__property TValidateOptions Options = {read=FOptions, write=FOptions, nodefault};
	__property TTransactionGlobalAction GlobalAction = {read=FGlobalAction, write=FGlobalAction, nodefault};
};


class DELPHICLASS TUserInfo;
class PASCALIMPLEMENTATION TUserInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString UserName;
	AnsiString FirstName;
	AnsiString MiddleName;
	AnsiString LastName;
	int GroupID;
	int UserID;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TUserInfo(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TUserInfo(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TSecurityAction { ActionAddUser, ActionDeleteUser, ActionModifyUser, ActionDisplayUser };
#pragma option pop

#pragma option push -b-
enum TSecurityModifyParam { ModifyFirstName, ModifyMiddleName, ModifyLastName, ModifyUserId, ModifyGroupId, ModifyPassword };
#pragma option pop

typedef Set<TSecurityModifyParam, ModifyFirstName, ModifyPassword>  TSecurityModifyParams;

typedef DynamicArray<TUserInfo* >  IBServices__13;

class DELPHICLASS TIBSecurityService;
class PASCALIMPLEMENTATION TIBSecurityService : public TIBControlAndQueryService 
{
	typedef TIBControlAndQueryService inherited;
	
private:
	int FUserID;
	int FGroupID;
	AnsiString FFirstName;
	AnsiString FUserName;
	AnsiString FPassword;
	AnsiString FSQLRole;
	AnsiString FLastName;
	AnsiString FMiddleName;
	DynamicArray<TUserInfo* >  FUserInfo;
	TSecurityAction FSecurityAction;
	TSecurityModifyParams FModifyParams;
	void __fastcall ClearParams(void);
	void __fastcall SetSecurityAction(TSecurityAction Value);
	void __fastcall SetFirstName(AnsiString Value);
	void __fastcall SetMiddleName(AnsiString Value);
	void __fastcall SetLastName(AnsiString Value);
	void __fastcall SetPassword(AnsiString Value);
	void __fastcall SetUserId(int Value);
	void __fastcall SetGroupId(int Value);
	void __fastcall FetchUserInfo(void);
	TUserInfo* __fastcall GetUserInfo(int Index);
	int __fastcall GetUserInfoCount(void);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetServiceStartOptions(void);
	
public:
	__fastcall virtual TIBSecurityService(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBSecurityService(void);
	void __fastcall DisplayUsers(void);
	void __fastcall DisplayUser(AnsiString UserName);
	void __fastcall AddUser(void);
	void __fastcall DeleteUser(void);
	void __fastcall ModifyUser(void);
	__property TUserInfo* UserInfo[int Index] = {read=GetUserInfo};
	__property int UserInfoCount = {read=GetUserInfoCount, nodefault};
	
__published:
	__property TSecurityAction SecurityAction = {read=FSecurityAction, write=SetSecurityAction, nodefault};
	__property AnsiString SQlRole = {read=FSQLRole, write=FSQLRole};
	__property AnsiString UserName = {read=FUserName, write=FUserName};
	__property AnsiString FirstName = {read=FFirstName, write=SetFirstName};
	__property AnsiString MiddleName = {read=FMiddleName, write=SetMiddleName};
	__property AnsiString LastName = {read=FLastName, write=SetLastName};
	__property int UserID = {read=FUserID, write=SetUserId, nodefault};
	__property int GroupID = {read=FGroupID, write=SetGroupId, nodefault};
	__property AnsiString Password = {read=FPassword, write=SetPassword};
};


//-- var, const, procedure ---------------------------------------------------
static const Word DefaultBufferSize = 0x7d00;
#define SPBPrefix "isc_spb_"
extern PACKAGE AnsiString SPBConstantNames[12];
extern PACKAGE int SPBConstantValues[12];

}	/* namespace Ibservices */
using namespace Ibservices;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBServices
