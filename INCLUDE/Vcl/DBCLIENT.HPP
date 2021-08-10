// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBClient.pas' rev: 6.00

#ifndef DBClientHPP
#define DBClientHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <SqlTimSt.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <DBCommon.hpp>	// Pascal unit
#include <DSIntf.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbclient
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EDBClient;
class PASCALIMPLEMENTATION EDBClient : public Db::EDatabaseError 
{
	typedef Db::EDatabaseError inherited;
	
private:
	Word FErrorCode;
	
public:
	__fastcall EDBClient(AnsiString Message, Word ErrorCode);
	__property Word ErrorCode = {read=FErrorCode, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDBClient(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Db::EDatabaseError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDBClient(int Ident)/* overload */ : Db::EDatabaseError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDBClient(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Db::EDatabaseError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDBClient(const AnsiString Msg, int AHelpContext) : Db::EDatabaseError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDBClient(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Db::EDatabaseError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDBClient(int Ident, int AHelpContext)/* overload */ : Db::EDatabaseError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDBClient(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Db::EDatabaseError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDBClient(void) { }
	#pragma option pop
	
};


class DELPHICLASS EReconcileError;
class PASCALIMPLEMENTATION EReconcileError : public EDBClient 
{
	typedef EDBClient inherited;
	
private:
	AnsiString FContext;
	Word FPreviousError;
	
public:
	__fastcall EReconcileError(AnsiString NativeError, AnsiString Context, Word ErrorCode, Word PreviousError);
	__property AnsiString Context = {read=FContext};
	__property Word PreviousError = {read=FPreviousError, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EReconcileError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDBClient(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EReconcileError(int Ident)/* overload */ : EDBClient(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EReconcileError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDBClient(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EReconcileError(const AnsiString Msg, int AHelpContext) : EDBClient(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EReconcileError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDBClient(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EReconcileError(int Ident, int AHelpContext)/* overload */ : EDBClient(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EReconcileError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDBClient(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EReconcileError(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TGetUsernameEvent)(System::TObject* Sender, AnsiString &Username);

class DELPHICLASS TCustomRemoteServer;
class PASCALIMPLEMENTATION TCustomRemoteServer : public Db::TCustomConnection 
{
	typedef Db::TCustomConnection inherited;
	
private:
	Variant FAppServer;
	TGetUsernameEvent FOnGetUsername;
	
protected:
	virtual Variant __fastcall GetAppServer();
	virtual void __fastcall SetAppServer(const Variant &Value);
	virtual OleVariant __fastcall GetServerList();
	virtual void __fastcall GetProviderNames(Classes::TGetStrProc Proc);
	__property TGetUsernameEvent OnGetUsername = {read=FOnGetUsername, write=FOnGetUsername};
	
public:
	__fastcall virtual TCustomRemoteServer(Classes::TComponent* AOwner);
	virtual Midas::_di_IAppServer __fastcall GetServer();
	__property Variant AppServer = {read=GetAppServer};
public:
	#pragma option push -w-inl
	/* TCustomConnection.Destroy */ inline __fastcall virtual ~TCustomRemoteServer(void) { }
	#pragma option pop
	
};


class DELPHICLASS TConnectionBroker;
class PASCALIMPLEMENTATION TConnectionBroker : public TCustomRemoteServer 
{
	typedef TCustomRemoteServer inherited;
	
private:
	TCustomRemoteServer* FConnection;
	bool FStreamedConnected;
	void __fastcall SetConnection(const TCustomRemoteServer* Value);
	
protected:
	virtual Variant __fastcall GetAppServer();
	virtual bool __fastcall GetConnected(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetConnected(bool Value);
	
public:
	virtual Midas::_di_IAppServer __fastcall GetServer();
	
__published:
	__property Connected  = {default=0};
	__property TCustomRemoteServer* Connection = {read=FConnection, write=SetConnection};
	__property LoginPrompt  = {default=0};
	__property AfterConnect ;
	__property AfterDisconnect ;
	__property BeforeConnect ;
	__property BeforeDisconnect ;
	__property OnGetUsername ;
	__property OnLogin ;
public:
	#pragma option push -w-inl
	/* TCustomRemoteServer.Create */ inline __fastcall virtual TConnectionBroker(Classes::TComponent* AOwner) : TCustomRemoteServer(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomConnection.Destroy */ inline __fastcall virtual ~TConnectionBroker(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAggregate;
typedef void __fastcall (__closure *TAggUpdateEvent)(TAggregate* Agg);

typedef DynamicArray<Byte >  DBClient__6;

class DELPHICLASS TCustomClientDataSet;
class DELPHICLASS TAggregates;
class PASCALIMPLEMENTATION TAggregates : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TAggregate* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TPersistent* FOwner;
	HIDESBASE TAggregate* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TAggregate* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TAggregates(Classes::TPersistent* Owner);
	HIDESBASE TAggregate* __fastcall Add(void);
	HIDESBASE void __fastcall Clear(void);
	TAggregate* __fastcall Find(const AnsiString DisplayName);
	int __fastcall IndexOf(const AnsiString DisplayName);
	__property TAggregate* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TAggregates(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDataSetOption { doDisableInserts, doDisableDeletes, doDisableEdits, doNoResetCall };
#pragma option pop

typedef Set<TDataSetOption, doDisableInserts, doNoResetCall>  TDataSetOptions;

typedef DynamicArray<Byte >  DBClient__01;

struct TKeyBuffer;
typedef TKeyBuffer *PKeyBuffer;

#pragma option push -b-
enum TReconcileAction { raSkip, raAbort, raMerge, raCorrect, raCancel, raRefresh };
#pragma option pop

typedef void __fastcall (__closure *TReconcileErrorEvent)(TCustomClientDataSet* DataSet, EReconcileError* E, Db::TUpdateKind UpdateKind, TReconcileAction &Action);

typedef void __fastcall (__closure *TRemoteEvent)(System::TObject* Sender, OleVariant &OwnerData);

#pragma option push -b-
enum TFetchOption { foRecord, foBlobs, foDetails };
#pragma option pop

typedef Set<TFetchOption, foRecord, foDetails>  TFetchOptions;

#pragma option push -b-
enum TDataPacketFormat { dfBinary, dfXML, dfXMLUTF8 };
#pragma option pop

typedef DynamicArray<Dsintf::DSFLDDesc >  TFieldDescList;

#pragma option push -b-
enum TKeyIndex { kiLookup, kiRangeStart, kiRangeEnd, kiCurRangeStart, kiCurRangeEnd, kiSave };
#pragma option pop

class PASCALIMPLEMENTATION TCustomClientDataSet : public Db::TDataSet 
{
	typedef Db::TDataSet inherited;
	
private:
	Classes::TList* FActiveAggLists;
	Classes::TBits* FAggFieldsUpdated;
	bool FAggFieldsInit;
	int FAggFieldsSize;
	int FAggGrpIndOfs;
	int FAggFieldsOfs;
	int FAggGrpIndSize;
	TAggregates* FAggregates;
	bool FAggregatesActive;
	AnsiString FCommandText;
	bool FDisableStringTrim;
	Dsintf::_di_IDSBase FDSBase;
	Dsintf::_di_IDSCursor FDSCursor;
	TDataSetOptions FDSOptions;
	Dsintf::_di_IDSCursor FFindCursor;
	TCustomClientDataSet* FCloneSource;
	TCustomClientDataSet* FReconcileDataSet;
	tagSAFEARRAY *FSavedPacket;
	tagSAFEARRAY *FDeltaPacket;
	Db::TParams* FParams;
	Db::TIndexDefs* FIndexDefs;
	AnsiString FIndexName;
	void *FExprFilter;
	void *FFuncFilter;
	AnsiString FFileName;
	char *FFilterBuffer;
	int FGroupingLevel;
	DynamicArray<Byte >  FLastParentBM;
	Db::TMasterDataLink* FMasterLink;
	int FIndexFieldMap[16];
	TKeyBuffer *FKeyBuffers[6];
	TKeyBuffer *FKeyBuffer;
	char *FNewValueBuffer;
	char *FOldValueBuffer;
	char *FCurValueBuffer;
	int FIndexFieldCount;
	int FIndexGroupingLevel;
	Midas::_di_IAppServer FAppServer;
	AnsiString FProviderName;
	TCustomRemoteServer* FRemoteServer;
	int FPacketRecords;
	int FConstDisableCount;
	int FMaxAggGroupingLevel;
	TCustomClientDataSet* FParentDataSet;
	Word FKeySize;
	int FRecordSize;
	int FBookmarkOfs;
	int FRecInfoOfs;
	int FRecBufSize;
	bool FReadOnly;
	bool FFieldsIndex;
	bool FCanModify;
	bool FInReconcileCallback;
	bool FNotifyCallback;
	bool FOpeningFile;
	bool FProviderEOF;
	bool FFetchOnDemand;
	bool FStoreDefs;
	bool FSavePacketOnClose;
	TReconcileErrorEvent FOnReconcileError;
	Db::TUpdateStatusSet FStatusFilter;
	TRemoteEvent FBeforeApplyUpdates;
	TRemoteEvent FAfterApplyUpdates;
	TRemoteEvent FBeforeGetRecords;
	TRemoteEvent FAfterGetRecords;
	TRemoteEvent FBeforeRowRequest;
	TRemoteEvent FAfterRowRequest;
	TRemoteEvent FBeforeExecute;
	TRemoteEvent FAfterExecute;
	TRemoteEvent FBeforeGetParams;
	TRemoteEvent FAfterGetParams;
	TConnectionBroker* FConnectionBroker;
	void __fastcall AddExprFilter(const AnsiString Expr, Db::TFilterOptions Options);
	void __fastcall AddFuncFilter(void);
	Word __stdcall CalcFieldsCallBack(char * RecBuf);
	void __fastcall CheckFieldProps(void);
	void __fastcall CheckMasterRange(void);
	void __fastcall CheckProviderEOF(void);
	void __fastcall ClearActiveAggs(void);
	void __fastcall ClearSavedPacket(void);
	void __fastcall CloseAggs(void);
	Dsintf::_di_IDSBase __fastcall CreateDSBase();
	Dsintf::_di_IDSCursor __fastcall CreateDSCursor(Dsintf::_di_IDSCursor SourceCursor);
	void __fastcall DecodeIndexDesc(const Dsintf::DSIDXDesc &IndexDesc, AnsiString &Name, AnsiString &Fields, AnsiString &DescFields, AnsiString &CaseInsFields, Db::TIndexOptions &Options);
	void __fastcall EncodeFieldDesc(Dsintf::DSFLDDesc &FieldDesc, const AnsiString Name, Db::TFieldType DataType, int Size, int Precision, bool Calculated, Db::TFieldAttributes Attributes);
	void __fastcall EncodeIndexDesc(Dsintf::DSIDXDesc &IndexDesc, const AnsiString Name, const AnsiString Fields, const AnsiString DescFields, const AnsiString CaseInsFields, Db::TIndexOptions Options);
	void __fastcall FetchMoreData(bool All);
	BOOL __stdcall FilterCallback(char * RecBuf);
	void __fastcall DoAggUpdates(bool IsUpdate);
	Classes::TList* __fastcall GetActiveAggs(int Index);
	bool __fastcall GetActiveRecBuf(char * &RecBuf);
	void __fastcall GetAggFieldData(char * Buffer);
	int __fastcall GetChangeCount(void);
	OleVariant __fastcall GetData();
	int __fastcall GetDataSize(void);
	OleVariant __fastcall GetDelta();
	HIDESBASE Db::TIndexDefs* __fastcall GetIndexDefs(void);
	AnsiString __fastcall GetIndexFieldNames();
	AnsiString __fastcall GetIndexName();
	bool __fastcall GetLogChanges(void);
	AnsiString __fastcall GetMasterFields();
	bool __fastcall GetProviderEOF(void);
	int __fastcall GetSavePoint(void);
	bool __fastcall GetHasAppServer(void);
	void __fastcall InitBufferPointers(bool GetProps);
	Db::TGroupPosInds __fastcall InternalGetGroupState(int Level);
	void __fastcall InternalFetch(TFetchOptions Options);
	void __fastcall MasterChanged(System::TObject* Sender);
	void __fastcall MasterDisabled(System::TObject* Sender);
	void __stdcall NotifyCallback(void);
	void __fastcall ReadData(Classes::TStream* Stream);
	int __stdcall ReconcileCallback(int iRslt, Dsintf::DSAttr iUpdateKind, int iResAction, int iErrCode, char * pErrMessage, char * pErrContext, void * pRecUpd, void * pRecOrg, void * pRecConflict, int iLevels, System::PInteger piFieldIDs);
	void __fastcall ResetAgg(TAggregate* Agg, bool DeleteFirst);
	void __fastcall ResetAllAggs(bool Value);
	void __fastcall ResetGrouping(void);
	void __fastcall SetAggsActive(bool Value);
	void __fastcall SetConnectionBroker(const TConnectionBroker* Value);
	void __fastcall SaveDataPacket(TDataPacketFormat Format = (TDataPacketFormat)(0x0));
	void __fastcall SetData(const OleVariant &Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetDisableStringTrim(bool Value);
	void __fastcall SetIndex(const AnsiString Value, bool FieldsIndex);
	void __fastcall SetIndexDefs(Db::TIndexDefs* Value);
	void __fastcall SetFileName(const AnsiString Value);
	void __fastcall SetIndexFieldNames(const AnsiString Value);
	void __fastcall SetIndexName(const AnsiString Value);
	void __fastcall SetLogChanges(bool Value);
	void __fastcall SetMasterFields(const AnsiString Value);
	void __fastcall SetNotifyCallback(void);
	void __fastcall SetParams(Db::TParams* Value);
	void __fastcall SetProviderEOF(bool Value);
	void __fastcall SetProviderName(const AnsiString Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetSavePoint(int Value);
	void __fastcall SortOnFields(Dsintf::_di_IDSCursor Cursor, const AnsiString Fields, bool CaseInsensitive, bool Descending);
	void __fastcall SetupConstraints(void);
	void __fastcall SetupInternalCalcFields(bool Add);
	void __fastcall WriteData(Classes::TStream* Stream);
	void __fastcall SetStatusFilter(const Db::TUpdateStatusSet Value);
	AnsiString __fastcall GetXMLData();
	void __fastcall SetXMLData(const AnsiString Value);
	
protected:
	virtual Db::TIndexDefs* __fastcall PSGetIndexDefs(Db::TIndexOptions IndexTypes);
	virtual void __fastcall DoAfterApplyUpdates(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeApplyUpdates(OleVariant &OwnerData);
	virtual OleVariant __fastcall DoApplyUpdates(const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount);
	virtual void __fastcall DoAfterGetParams(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeGetParams(OleVariant &OwnerData);
	virtual void __fastcall DoAfterGetRecords(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeGetRecords(OleVariant &OwnerData);
	virtual OleVariant __fastcall DoGetRecords(int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, const OleVariant &Params);
	virtual void __fastcall DoAfterRowRequest(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeRowRequest(OleVariant &OwnerData);
	virtual OleVariant __fastcall DoRowRequest(const OleVariant &Row, int RequestType);
	virtual void __fastcall DoAfterExecute(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeExecute(OleVariant &OwnerData);
	virtual void __fastcall DoExecute(const OleVariant &Params);
	virtual void __fastcall ResetAggField(Db::TField* Field);
	void __fastcall ActivateFilters(void);
	virtual void __fastcall AddDataPacket(const OleVariant &Data, bool HitEOF);
	void __fastcall AddFieldDesc(TFieldDescList FieldDescs, int &DescNo, int &FieldID, Db::TFieldDefs* FieldDefs);
	void __fastcall AllocKeyBuffers(void);
	virtual char * __fastcall AllocRecordBuffer(void);
	void __fastcall Check(Word Status);
	virtual void __fastcall CheckDetailRecords(void);
	void __fastcall CheckSetKeyMode(void);
	virtual void __fastcall ClearCalcFields(char * Buffer);
	virtual void __fastcall CloseCursor(void);
	virtual void __fastcall DataConvert(Db::TField* Field, void * Source, void * Dest, bool ToNative);
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	void __fastcall DeactivateFilters(void);
	virtual void __fastcall DefChanged(System::TObject* Sender);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DestroyLookupCursor(void);
	virtual void __fastcall DoBeforeInsert(void);
	virtual void __fastcall DoOnNewRecord(void);
	virtual bool __fastcall FindRecord(bool Restart, bool GoForward);
	void __fastcall FreeKeyBuffers(void);
	virtual void __fastcall FreeRecordBuffer(char * &Buffer);
	virtual Variant __fastcall GetAggregateValue(Db::TField* Field);
	virtual Midas::_di_IAppServer __fastcall GetAppServer();
	virtual void __fastcall GetBookmarkData(char * Buffer, void * Data);
	virtual Db::TBookmarkFlag __fastcall GetBookmarkFlag(char * Buffer);
	virtual bool __fastcall GetCanModify(void);
	virtual Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetIndexField(int Index);
	int __fastcall GetIndexFieldCount(void);
	virtual bool __fastcall GetIsIndexField(Db::TField* Field);
	PKeyBuffer __fastcall GetKeyBuffer(TKeyIndex KeyIndex);
	bool __fastcall GetKeyExclusive(void);
	int __fastcall GetKeyFieldCount(void);
	virtual Db::TGetResult __fastcall GetRecord(char * Buffer, Db::TGetMode GetMode, bool DoCheck);
	virtual int __fastcall GetRecordCount(void);
	virtual int __fastcall GetRecNo(void);
	virtual Word __fastcall GetRecordSize(void);
	virtual TCustomRemoteServer* __fastcall GetRemoteServer(void);
	virtual Variant __fastcall GetStateFieldValue(Db::TDataSetState State, Db::TField* Field);
	PKeyBuffer __fastcall InitKeyBuffer(PKeyBuffer Buffer);
	virtual void __fastcall InitRecord(char * Buffer);
	virtual void __fastcall InternalAddRecord(void * Buffer, bool Append);
	virtual void __fastcall InternalCancel(void);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalEdit(void);
	virtual void __fastcall InternalFirst(void);
	OleVariant __fastcall InternalGetOptionalParam(const AnsiString ParamName, int FieldNo = 0x0);
	virtual void __fastcall InternalGotoBookmark(void * Bookmark);
	virtual void __fastcall InternalHandleException(void);
	virtual void __fastcall InternalInitFieldDefs(void);
	virtual void __fastcall InternalInitRecord(char * Buffer);
	virtual void __fastcall InternalInsert(void);
	virtual void __fastcall InternalLast(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalRefresh(void);
	virtual void __fastcall InternalPost(void);
	virtual void __fastcall InternalSetToRecord(char * Buffer);
	virtual bool __fastcall IsCursorOpen(void);
	virtual void __fastcall Loaded(void);
	bool __fastcall LocateRecord(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions Options, bool SyncCursor);
	virtual void __fastcall OpenCursor(bool InfoQuery);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall PostKeyBuffer(bool Commit);
	virtual void __fastcall RefreshInternalCalcFields(char * Buffer);
	void __fastcall ReadDataPacket(Classes::TStream* Stream, bool ReadSize);
	bool __fastcall ResetCursorRange(void);
	virtual void __fastcall SetAggregates(TAggregates* Value);
	virtual void __fastcall SetAppServer(Midas::_di_IAppServer Value);
	virtual void __fastcall SetBookmarkData(char * Buffer, void * Data);
	virtual void __fastcall SetBookmarkFlag(char * Buffer, Db::TBookmarkFlag Value);
	virtual void __fastcall SetCommandText(AnsiString Value);
	bool __fastcall SetCursorRange(void);
	virtual void __fastcall SetDataSetField(const Db::TDataSetField* Value);
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	void __fastcall SetFilterData(const AnsiString Text, Db::TFilterOptions Options);
	virtual void __fastcall SetFiltered(bool Value);
	virtual void __fastcall SetFilterOptions(Db::TFilterOptions Value);
	virtual void __fastcall SetFilterText(const AnsiString Value);
	void __fastcall SetIndexField(int Index, Db::TField* Value);
	void __fastcall SetKeyBuffer(TKeyIndex KeyIndex, bool Clear);
	void __fastcall SetKeyExclusive(bool Value);
	void __fastcall SetKeyFieldCount(int Value);
	void __fastcall SetKeyFields(TKeyIndex KeyIndex, const System::TVarRec * Values, const int Values_Size);
	void __fastcall SetLinkRanges(Classes::TList* MasterFields);
	virtual void __fastcall SetOnFilterRecord(const Db::TFilterRecordEvent Value);
	virtual void __fastcall SetRecNo(int Value);
	virtual void __fastcall SetRemoteServer(TCustomRemoteServer* Value);
	void __fastcall SwitchToIndex(const AnsiString IndexName);
	void __fastcall SyncCursors(Dsintf::_di_IDSCursor Cursor1, Dsintf::_di_IDSCursor Cursor2);
	virtual void __fastcall UpdateIndexDefs(void);
	void __fastcall WriteDataPacket(Classes::TStream* Stream, bool WriteSize, TDataPacketFormat Format = (TDataPacketFormat)(0x0));
	bool __fastcall ConstraintsStored(void);
	__property Active  = {default=0};
	__property TAggregates* Aggregates = {read=FAggregates, write=SetAggregates};
	__property bool AggregatesActive = {read=FAggregatesActive, write=SetAggsActive, default=0};
	__property AutoCalcFields  = {default=1};
	__property AnsiString CommandText = {read=FCommandText, write=SetCommandText};
	__property TConnectionBroker* ConnectionBroker = {read=FConnectionBroker, write=SetConnectionBroker};
	__property Constraints  = {stored=ConstraintsStored};
	__property DataSetField ;
	__property bool DisableStringTrim = {read=FDisableStringTrim, write=SetDisableStringTrim, default=0};
	__property Dsintf::_di_IDSBase DSBase = {read=FDSBase, write=FDSBase};
	__property Dsintf::_di_IDSCursor DSCursor = {read=FDSCursor};
	__property AnsiString FileName = {read=FFileName, write=SetFileName};
	__property Filter ;
	__property Filtered  = {default=0};
	__property FilterOptions  = {default=0};
	__property FieldDefs  = {stored=FStoreDefs};
	__property Db::TIndexDefs* IndexDefs = {read=GetIndexDefs, write=SetIndexDefs, stored=FStoreDefs};
	__property AnsiString IndexFieldNames = {read=GetIndexFieldNames, write=SetIndexFieldNames};
	__property AnsiString IndexName = {read=GetIndexName, write=SetIndexName};
	__property bool FetchOnDemand = {read=FFetchOnDemand, write=FFetchOnDemand, default=1};
	__property AnsiString MasterFields = {read=GetMasterFields, write=SetMasterFields};
	__property Db::TDataSource* MasterSource = {read=GetDataSource, write=SetDataSource};
	__property ObjectView  = {default=1};
	__property int PacketRecords = {read=FPacketRecords, write=FPacketRecords, default=-1};
	__property Db::TParams* Params = {read=FParams, write=SetParams};
	__property bool ProviderEOF = {read=GetProviderEOF, write=SetProviderEOF, nodefault};
	__property AnsiString ProviderName = {read=FProviderName, write=SetProviderName};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property TCustomRemoteServer* RemoteServer = {read=GetRemoteServer, write=SetRemoteServer};
	__property bool StoreDefs = {read=FStoreDefs, write=FStoreDefs, default=0};
	__property BeforeOpen ;
	__property AfterOpen ;
	__property BeforeClose ;
	__property AfterClose ;
	__property BeforeInsert ;
	__property AfterInsert ;
	__property BeforeEdit ;
	__property AfterEdit ;
	__property BeforePost ;
	__property AfterPost ;
	__property BeforeCancel ;
	__property AfterCancel ;
	__property BeforeDelete ;
	__property AfterDelete ;
	__property BeforeScroll ;
	__property AfterScroll ;
	__property BeforeRefresh ;
	__property AfterRefresh ;
	__property OnCalcFields ;
	__property OnDeleteError ;
	__property OnEditError ;
	__property OnFilterRecord ;
	__property OnNewRecord ;
	__property OnPostError ;
	__property TReconcileErrorEvent OnReconcileError = {read=FOnReconcileError, write=FOnReconcileError};
	__property TRemoteEvent BeforeApplyUpdates = {read=FBeforeApplyUpdates, write=FBeforeApplyUpdates};
	__property TRemoteEvent AfterApplyUpdates = {read=FAfterApplyUpdates, write=FAfterApplyUpdates};
	__property TRemoteEvent BeforeGetRecords = {read=FBeforeGetRecords, write=FBeforeGetRecords};
	__property TRemoteEvent AfterGetRecords = {read=FAfterGetRecords, write=FAfterGetRecords};
	__property TRemoteEvent BeforeRowRequest = {read=FBeforeRowRequest, write=FBeforeRowRequest};
	__property TRemoteEvent AfterRowRequest = {read=FAfterRowRequest, write=FAfterRowRequest};
	__property TRemoteEvent BeforeExecute = {read=FBeforeExecute, write=FBeforeExecute};
	__property TRemoteEvent AfterExecute = {read=FAfterExecute, write=FAfterExecute};
	__property TRemoteEvent BeforeGetParams = {read=FBeforeGetParams, write=FBeforeGetParams};
	__property TRemoteEvent AfterGetParams = {read=FAfterGetParams, write=FAfterGetParams};
	
public:
	__fastcall virtual TCustomClientDataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomClientDataSet(void);
	void __fastcall AddIndex(const AnsiString Name, const AnsiString Fields, Db::TIndexOptions Options, const AnsiString DescFields = "", const AnsiString CaseInsFields = "", const int GroupingLevel = 0x0);
	void __fastcall AppendData(const OleVariant &Data, bool HitEOF);
	void __fastcall ApplyRange(void);
	virtual int __fastcall ApplyUpdates(int MaxErrors);
	virtual bool __fastcall BookmarkValid(void * Bookmark);
	virtual void __fastcall Cancel(void);
	void __fastcall CancelRange(void);
	void __fastcall CancelUpdates(void);
	virtual Classes::TStream* __fastcall CreateBlobStream(Db::TField* Field, Db::TBlobStreamMode Mode);
	void __fastcall CreateDataSet(void);
	virtual void __fastcall CloneCursor(TCustomClientDataSet* Source, bool Reset, bool KeepSettings = false);
	virtual int __fastcall CompareBookmarks(void * Bookmark1, void * Bookmark2);
	bool __fastcall ConstraintsDisabled(void);
	virtual OleVariant __fastcall DataRequest(const OleVariant &Data);
	void __fastcall DeleteIndex(const AnsiString Name);
	void __fastcall DisableConstraints(void);
	void __fastcall EnableConstraints(void);
	void __fastcall EditKey(void);
	void __fastcall EditRangeEnd(void);
	void __fastcall EditRangeStart(void);
	void __fastcall EmptyDataSet(void);
	virtual void __fastcall Execute(void);
	void __fastcall FetchBlobs(void);
	void __fastcall FetchDetails(void);
	void __fastcall RefreshRecord(void);
	void __fastcall FetchParams(void);
	virtual bool __fastcall FindKey(const System::TVarRec * KeyValues, const int KeyValues_Size);
	void __fastcall FindNearest(const System::TVarRec * KeyValues, const int KeyValues_Size);
	virtual bool __fastcall GetCurrentRecord(char * Buffer);
	virtual bool __fastcall GetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	virtual bool __fastcall GetFieldData(int FieldNo, void * Buffer)/* overload */;
	Db::TGroupPosInds __fastcall GetGroupState(int Level);
	void __fastcall GetIndexInfo(AnsiString IndexName);
	void __fastcall GetIndexNames(Classes::TStrings* List);
	int __fastcall GetNextPacket(void);
	OleVariant __fastcall GetOptionalParam(const AnsiString ParamName);
	void __fastcall GotoCurrent(TCustomClientDataSet* DataSet);
	bool __fastcall GotoKey(void);
	void __fastcall GotoNearest(void);
	__property bool HasAppServer = {read=GetHasAppServer, nodefault};
	virtual bool __fastcall Locate(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions Options);
	virtual Variant __fastcall Lookup(const AnsiString KeyFields, const Variant &KeyValues, const AnsiString ResultFields);
	void __fastcall LoadFromFile(const AnsiString FileName = "");
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall MergeChangeLog(void);
	virtual void __fastcall Post(void);
	bool __fastcall Reconcile(const OleVariant &Results);
	void __fastcall RevertRecord(void);
	void __fastcall SaveToFile(const AnsiString FileName = "", TDataPacketFormat Format = (TDataPacketFormat)(0x0));
	void __fastcall SaveToStream(Classes::TStream* Stream, TDataPacketFormat Format = (TDataPacketFormat)(0x0));
	void __fastcall SetAltRecBuffers(char * Old, char * New, char * Cur);
	void __fastcall SetKey(void);
	void __fastcall SetOptionalParam(const AnsiString ParamName, const OleVariant &Value, bool IncludeInDelta = false);
	void __fastcall SetProvider(Classes::TComponent* Provider);
	void __fastcall SetRange(const System::TVarRec * StartValues, const int StartValues_Size, const System::TVarRec * EndValues, const int EndValues_Size);
	void __fastcall SetRangeEnd(void);
	void __fastcall SetRangeStart(void);
	bool __fastcall UndoLastChange(bool FollowChange);
	virtual Db::TUpdateStatus __fastcall UpdateStatus(void);
	__property Classes::TList* ActiveAggs[int Index] = {read=GetActiveAggs};
	__property int ChangeCount = {read=GetChangeCount, nodefault};
	__property TCustomClientDataSet* CloneSource = {read=FCloneSource};
	__property OleVariant Data = {read=GetData, write=SetData};
	__property AnsiString XMLData = {read=GetXMLData, write=SetXMLData};
	__property Midas::_di_IAppServer AppServer = {read=GetAppServer, write=SetAppServer};
	__property int DataSize = {read=GetDataSize, nodefault};
	__property OleVariant Delta = {read=GetDelta};
	__property int GroupingLevel = {read=FGroupingLevel, nodefault};
	__property int IndexFieldCount = {read=GetIndexFieldCount, nodefault};
	__property Db::TField* IndexFields[int Index] = {read=GetIndexField, write=SetIndexField};
	__property bool KeyExclusive = {read=GetKeyExclusive, write=SetKeyExclusive, nodefault};
	__property int KeyFieldCount = {read=GetKeyFieldCount, write=SetKeyFieldCount, nodefault};
	__property Word KeySize = {read=FKeySize, nodefault};
	__property bool LogChanges = {read=GetLogChanges, write=SetLogChanges, nodefault};
	__property int SavePoint = {read=GetSavePoint, write=SetSavePoint, nodefault};
	__property Db::TUpdateStatusSet StatusFilter = {read=FStatusFilter, write=SetStatusFilter, nodefault};
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ TDataSet::SetFieldData(Field, Buffer, NativeFormat); }
	
public:
	inline bool __fastcall  GetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ return TDataSet::GetFieldData(Field, Buffer, NativeFormat); }
	
};


class PASCALIMPLEMENTATION TAggregate : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FExpression;
	#pragma pack(push, 1)
	Dsintf::DSFLDDesc FFldDesc;
	#pragma pack(pop)
	
	Dsintf::hDSAggregate FHAggregate;
	AnsiString FAggregateName;
	int FGroupingLevel;
	TCustomClientDataSet* FDataSet;
	AnsiString FIndexName;
	DynamicArray<Byte >  FDataBuffer;
	Db::TFieldType FDataType;
	int FDataSize;
	Classes::TBits* FDependentFields;
	int FRecBufOfs;
	bool FInUse;
	bool FActive;
	bool FVisible;
	bool FOutOfDate;
	TAggUpdateEvent FOnUpdate;
	void __fastcall SetActive(bool Value);
	void __fastcall SetExpression(const AnsiString Text);
	void __fastcall SetGroupingLevel(int GroupingLevel);
	void __fastcall SetIndexName(AnsiString Value);
	
protected:
	void __fastcall Activate(void);
	__property Classes::TBits* DependentFields = {read=FDependentFields};
	__property int RecBufOfs = {read=FRecBufOfs, write=FRecBufOfs, nodefault};
	
public:
	__fastcall TAggregate(TAggregates* Aggregates, TCustomClientDataSet* ADataSet)/* overload */;
	__fastcall virtual ~TAggregate(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual AnsiString __fastcall GetDisplayName();
	Variant __fastcall Value();
	__property Dsintf::hDSAggregate AggHandle = {read=FHAggregate, write=FHAggregate, nodefault};
	__property bool InUse = {read=FInUse, write=FInUse, default=0};
	__property TCustomClientDataSet* DataSet = {read=FDataSet};
	__property int DataSize = {read=FDataSize, nodefault};
	__property Db::TFieldType DataType = {read=FDataType, nodefault};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property AnsiString AggregateName = {read=FAggregateName, write=FAggregateName};
	__property AnsiString Expression = {read=FExpression, write=SetExpression};
	__property int GroupingLevel = {read=FGroupingLevel, write=SetGroupingLevel, default=0};
	__property AnsiString IndexName = {read=FIndexName, write=SetIndexName};
	__property bool Visible = {read=FVisible, write=FVisible, default=1};
	__property TAggUpdateEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
};


struct TRecInfo;
typedef TRecInfo *PRecInfo;

#pragma pack(push, 1)
struct TRecInfo
{
	int RecordNumber;
	Db::TBookmarkFlag BookmarkFlag;
	Dsintf::DSAttr Attribute;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct DBClient__8
{
	
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TKeyBuffer
{
	bool Modified;
	bool Exclusive;
	int FieldCount;
	DBClient__8 Data;
} ;
#pragma pack(pop)

class DELPHICLASS TClientDataSet;
class PASCALIMPLEMENTATION TClientDataSet : public TCustomClientDataSet 
{
	typedef TCustomClientDataSet inherited;
	
__published:
	__property Active  = {default=0};
	__property Aggregates ;
	__property AggregatesActive  = {default=0};
	__property AutoCalcFields  = {default=1};
	__property CommandText ;
	__property ConnectionBroker ;
	__property Constraints ;
	__property DataSetField ;
	__property DisableStringTrim  = {default=0};
	__property FileName ;
	__property Filter ;
	__property Filtered  = {default=0};
	__property FilterOptions  = {default=0};
	__property FieldDefs ;
	__property IndexDefs ;
	__property IndexFieldNames ;
	__property IndexName ;
	__property FetchOnDemand  = {default=1};
	__property MasterFields ;
	__property MasterSource ;
	__property ObjectView  = {default=1};
	__property PacketRecords  = {default=-1};
	__property Params ;
	__property ProviderName ;
	__property ReadOnly  = {default=0};
	__property RemoteServer ;
	__property StoreDefs  = {default=0};
	__property BeforeOpen ;
	__property AfterOpen ;
	__property BeforeClose ;
	__property AfterClose ;
	__property BeforeInsert ;
	__property AfterInsert ;
	__property BeforeEdit ;
	__property AfterEdit ;
	__property BeforePost ;
	__property AfterPost ;
	__property BeforeCancel ;
	__property AfterCancel ;
	__property BeforeDelete ;
	__property AfterDelete ;
	__property BeforeScroll ;
	__property AfterScroll ;
	__property BeforeRefresh ;
	__property AfterRefresh ;
	__property OnCalcFields ;
	__property OnDeleteError ;
	__property OnEditError ;
	__property OnFilterRecord ;
	__property OnNewRecord ;
	__property OnPostError ;
	__property OnReconcileError ;
	__property BeforeApplyUpdates ;
	__property AfterApplyUpdates ;
	__property BeforeGetRecords ;
	__property AfterGetRecords ;
	__property BeforeRowRequest ;
	__property AfterRowRequest ;
	__property BeforeExecute ;
	__property AfterExecute ;
	__property BeforeGetParams ;
	__property AfterGetParams ;
public:
	#pragma option push -w-inl
	/* TCustomClientDataSet.Create */ inline __fastcall virtual TClientDataSet(Classes::TComponent* AOwner) : TCustomClientDataSet(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomClientDataSet.Destroy */ inline __fastcall virtual ~TClientDataSet(void) { }
	#pragma option pop
	
};


class DELPHICLASS TClientBlobStream;
class PASCALIMPLEMENTATION TClientBlobStream : public Classes::TMemoryStream 
{
	typedef Classes::TMemoryStream inherited;
	
private:
	Db::TBlobField* FField;
	TCustomClientDataSet* FDataSet;
	char *FBuffer;
	int FFieldNo;
	bool FModified;
	void __fastcall ReadBlobData(void);
	
public:
	__fastcall TClientBlobStream(Db::TBlobField* Field, Db::TBlobStreamMode Mode);
	__fastcall virtual ~TClientBlobStream(void);
	virtual int __fastcall Write(const void *Buffer, int Count);
	void __fastcall Truncate(void);
};


//-- var, const, procedure ---------------------------------------------------
#define AllParamTypes (System::Set<Db::TParamType, ptUnknown, ptResult> () << Db::TParamType(0) << Db::TParamType(1) << Db::TParamType(2) << Db::TParamType(3) << Db::TParamType(4) )
static const Shortint AllRecords = 0xffffffff;
extern PACKAGE OleVariant __fastcall PackageParams(Db::TParams* Params, Db::TParamTypes Types = (System::Set<Db::TParamType, ptUnknown, ptResult> () << Db::TParamType(0) << Db::TParamType(1) << Db::TParamType(2) << Db::TParamType(3) << Db::TParamType(4) ));
extern PACKAGE void __fastcall UnpackParams(const OleVariant &Source, Db::TParams* Dest);

}	/* namespace Dbclient */
using namespace Dbclient;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBClient
