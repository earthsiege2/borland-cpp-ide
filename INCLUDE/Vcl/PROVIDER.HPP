// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Provider.pas' rev: 6.00

#ifndef ProviderHPP
#define ProviderHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SqlTimSt.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <DSIntf.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Provider
{
class DELPHICLASS EDSWriter;
#pragma pack(push, 4)
class PASCALIMPLEMENTATION EDSWriter : public Sysutils::Exception
{
  typedef Sysutils::Exception inherited;

private:
  int FErrorCode;

public:
  __fastcall EDSWriter(AnsiString ErrMsg, long Status);
  __property int ErrorCode = {read=FErrorCode, nodefault};
public:
  /* Exception.CreateFmt */ inline __fastcall EDSWriter(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
  /* Exception.CreateRes */ inline __fastcall EDSWriter(int Ident, Extended Dummy) : Sysutils::Exception(Ident, Dummy) { }
  /* Exception.CreateResFmt */ inline __fastcall EDSWriter(int Ident, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
  /* Exception.CreateHelp */ inline __fastcall EDSWriter(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
  /* Exception.CreateFmtHelp */ inline __fastcall EDSWriter(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
  /* Exception.CreateResHelp */ inline __fastcall EDSWriter(int Ident, int AHelpContext) : Sysutils::Exception(Ident, AHelpContext) { }
  /* Exception.CreateResFmtHelp */ inline __fastcall EDSWriter(int Ident, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }

public:
  /* TObject.Destroy */ inline __fastcall virtual ~EDSWriter(void) { }

};

#pragma pack(pop)
}

namespace Provider
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<Byte >  Provider__3;

class DELPHICLASS TCustomPacketWriter;
class PASCALIMPLEMENTATION TCustomPacketWriter : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Dsintf::_di_IDSWriter FIDSWriter;
	DynamicArray<Byte >  FBuffer;
	
protected:
	void __fastcall AddAttribute(Dsintf::TPcktAttrArea Area, const AnsiString ParamName, const OleVariant &Value, bool IncludeInDelta);
	void __fastcall Check(int Status);
	__property Dsintf::_di_IDSWriter DSWriter = {read=FIDSWriter};
	
public:
	__fastcall virtual TCustomPacketWriter(void);
	__fastcall virtual ~TCustomPacketWriter(void);
};


#pragma option push -b-
enum TGetRecordOption { grMetaData, grReset, grXML, grXMLUTF8 };
#pragma option pop

typedef Set<TGetRecordOption, grMetaData, grXMLUTF8>  TGetRecordOptions;

typedef OleVariant __fastcall (__closure *TDataRequestEvent)(System::TObject* Sender, const OleVariant &Input);

#pragma option push -b-
enum TProviderOption { poFetchBlobsOnDemand, poFetchDetailsOnDemand, poIncFieldProps, poCascadeDeletes, poCascadeUpdates, poReadOnly, poAllowMultiRecordUpdates, poDisableInserts, poDisableEdits, poDisableDeletes, poNoReset, poAutoRefresh, poPropogateChanges, poAllowCommandText, poRetainServerOrder };
#pragma option pop

typedef Set<TProviderOption, poFetchBlobsOnDemand, poRetainServerOrder>  TProviderOptions;

struct TPutFieldInfo;
typedef TPutFieldInfo *PPutFieldInfo;

typedef void __fastcall (__closure *TPutFieldProc)(PPutFieldInfo Info);

struct TPutFieldInfo
{
	int FieldNo;
	Db::TField* Field;
	Db::TDataSet* DataSet;
	int Size;
	bool IsDetail;
	bool Opened;
	TPutFieldProc PutProc;
	int LocalFieldIndex;
	void *FieldInfos;
} ;

typedef DynamicArray<TPutFieldInfo >  TInfoArray;

typedef void __fastcall (__closure *TGetParamsEvent)(Db::TDataSet* DataSet, Classes::TList* Params);

class DELPHICLASS TDataPacketWriter;
class PASCALIMPLEMENTATION TDataPacketWriter : public TCustomPacketWriter 
{
	typedef TCustomPacketWriter inherited;
	
private:
	bool FConstraints;
	DynamicArray<TPutFieldInfo >  FPutFieldInfo;
	TProviderOptions FOptions;
	TGetRecordOptions FPacketOptions;
	TGetParamsEvent FOnGetParams;
	void __fastcall FreeInfoRecords(TInfoArray &Info);
	int __fastcall GetFieldIdx(const AnsiString FieldName, const TInfoArray Info);
	void __fastcall AddExtraFieldProps(Db::TField* Field);
	TInfoArray __fastcall InitPutProcs(Db::TDataSet* ADataSet, int &GlobalIdx);
	void __fastcall RefreshPutProcs(Db::TDataSet* ADataSet, TInfoArray &Info);
	
protected:
	void __fastcall AddColumn(const TPutFieldInfo &Info);
	void __fastcall AddConstraints(Db::TDataSet* DataSet);
	void __fastcall AddDataSetAttributes(Db::TDataSet* DataSet);
	void __fastcall AddFieldLinks(const TInfoArray Info);
	void __fastcall AddIndexDefs(Db::TDataSet* DataSet, const TInfoArray Info);
	void __fastcall PutADTField(PPutFieldInfo Info);
	void __fastcall PutArrayField(PPutFieldInfo Info);
	void __fastcall PutBlobField(PPutFieldInfo Info);
	void __fastcall PutCalcField(PPutFieldInfo Info);
	void __fastcall PutDataSetField(PPutFieldInfo Info);
	void __fastcall PutField(PPutFieldInfo Info);
	void __fastcall PutStringField(PPutFieldInfo Info);
	void __fastcall PutWideStringField(PPutFieldInfo Info);
	void __fastcall PutVarBytesField(PPutFieldInfo Info);
	void __fastcall Reset(void);
	void __fastcall WriteMetaData(Db::TDataSet* DataSet, const TInfoArray Info, bool IsReference = false);
	int __fastcall WriteDataSet(Db::TDataSet* DataSet, TInfoArray &Info, int RecsOut);
	__property TGetParamsEvent OnGetParams = {read=FOnGetParams, write=FOnGetParams};
	
public:
	__fastcall virtual ~TDataPacketWriter(void);
	void __fastcall GetDataPacket(Db::TDataSet* DataSet, int &RecsOut, /* out */ OleVariant &Data);
	__property bool Constraints = {read=FConstraints, write=FConstraints, nodefault};
	__property TGetRecordOptions PacketOptions = {read=FPacketOptions, write=FPacketOptions, nodefault};
	__property TProviderOptions Options = {read=FOptions, write=FOptions, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomPacketWriter.Create */ inline __fastcall virtual TDataPacketWriter(void) : TCustomPacketWriter() { }
	#pragma option pop
	
};


class DELPHICLASS TPacketDataSet;
class PASCALIMPLEMENTATION TPacketDataSet : public Dbclient::TCustomClientDataSet 
{
	typedef Dbclient::TCustomClientDataSet inherited;
	
private:
	char *FOldRecBuf;
	char *FCurRecBuf;
	char *FCurValues;
	bool FUseCurValues;
	bool FWritingCurValues;
	bool FNewValuesModified;
	bool __fastcall GetStreamMetaData(void);
	void __fastcall SetStreamMetaData(bool Value);
	void __fastcall SetWritingCurValues(const bool Value);
	
protected:
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	virtual Variant __fastcall GetStateFieldValue(Db::TDataSetState State, Db::TField* Field);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalInitRecord(char * Buffer);
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	__property bool WritingCurValues = {read=FWritingCurValues, write=SetWritingCurValues, nodefault};
	
public:
	__fastcall virtual TPacketDataSet(Classes::TComponent* AOwner);
	void __fastcall AssignCurValues(Db::TDataSet* Source)/* overload */;
	void __fastcall AssignCurValues(const Variant &CurValues)/* overload */;
	void __fastcall CreateFromDelta(TPacketDataSet* Source);
	bool __fastcall HasCurValues(void);
	bool __fastcall HasMergeConflicts(void);
	void __fastcall InitAltRecBuffers(bool CheckModified = true);
	Db::TUpdateKind __fastcall UpdateKind(void);
	__property bool NewValuesModified = {read=FNewValuesModified, nodefault};
	__property bool StreamMetaData = {read=GetStreamMetaData, write=SetStreamMetaData, nodefault};
	__property bool UseCurValues = {read=FUseCurValues, write=FUseCurValues, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomClientDataSet.Destroy */ inline __fastcall virtual ~TPacketDataSet(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ TDataSet::SetFieldData(Field, Buffer, NativeFormat); }
	
};


class DELPHICLASS TCustomProvider;
class PASCALIMPLEMENTATION TCustomProvider : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FExported;
	TDataRequestEvent FOnDataRequest;
	Dbclient::TRemoteEvent FBeforeApplyUpdates;
	Dbclient::TRemoteEvent FAfterApplyUpdates;
	Dbclient::TRemoteEvent FBeforeGetRecords;
	Dbclient::TRemoteEvent FAfterGetRecords;
	Dbclient::TRemoteEvent FBeforeRowRequest;
	Dbclient::TRemoteEvent FAfterRowRequest;
	Dbclient::TRemoteEvent FBeforeExecute;
	Dbclient::TRemoteEvent FAfterExecute;
	Dbclient::TRemoteEvent FBeforeGetParams;
	Dbclient::TRemoteEvent FAfterGetParams;
	OleVariant __fastcall GetData();
	
protected:
	virtual OleVariant __fastcall InternalApplyUpdates(const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount) = 0 ;
	virtual OleVariant __fastcall InternalGetRecords(int Count, /* out */ int &RecsOut, TGetRecordOptions Options, const WideString CommandText, OleVariant &Params);
	virtual OleVariant __fastcall InternalRowRequest(const OleVariant &Row, Dbclient::TFetchOptions RequestType);
	virtual void __fastcall InternalExecute(const WideString CommandText, OleVariant &Params);
	virtual OleVariant __fastcall InternalGetParams(Db::TParamTypes Types = (System::Set<Db::TParamType, ptUnknown, ptResult> () << Db::TParamType(0) << Db::TParamType(1) << Db::TParamType(2) << Db::TParamType(3) << Db::TParamType(4) ));
	virtual void __fastcall DoAfterApplyUpdates(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeApplyUpdates(OleVariant &OwnerData);
	virtual void __fastcall DoAfterExecute(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeExecute(const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	virtual void __fastcall DoAfterGetParams(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeGetParams(OleVariant &OwnerData);
	virtual void __fastcall DoAfterGetRecords(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeGetRecords(int Count, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	virtual void __fastcall DoAfterRowRequest(OleVariant &OwnerData);
	virtual void __fastcall DoBeforeRowRequest(OleVariant &OwnerData);
	__property TDataRequestEvent OnDataRequest = {read=FOnDataRequest, write=FOnDataRequest};
	__property Dbclient::TRemoteEvent BeforeApplyUpdates = {read=FBeforeApplyUpdates, write=FBeforeApplyUpdates};
	__property Dbclient::TRemoteEvent AfterApplyUpdates = {read=FAfterApplyUpdates, write=FAfterApplyUpdates};
	__property Dbclient::TRemoteEvent BeforeGetRecords = {read=FBeforeGetRecords, write=FBeforeGetRecords};
	__property Dbclient::TRemoteEvent AfterGetRecords = {read=FAfterGetRecords, write=FAfterGetRecords};
	__property Dbclient::TRemoteEvent BeforeRowRequest = {read=FBeforeRowRequest, write=FBeforeRowRequest};
	__property Dbclient::TRemoteEvent AfterRowRequest = {read=FAfterRowRequest, write=FAfterRowRequest};
	__property Dbclient::TRemoteEvent BeforeExecute = {read=FBeforeExecute, write=FBeforeExecute};
	__property Dbclient::TRemoteEvent AfterExecute = {read=FAfterExecute, write=FAfterExecute};
	__property Dbclient::TRemoteEvent BeforeGetParams = {read=FBeforeGetParams, write=FBeforeGetParams};
	__property Dbclient::TRemoteEvent AfterGetParams = {read=FAfterGetParams, write=FAfterGetParams};
	
public:
	__fastcall virtual TCustomProvider(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomProvider(void);
	OleVariant __fastcall ApplyUpdates(const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount)/* overload */;
	OleVariant __fastcall ApplyUpdates(const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData)/* overload */;
	OleVariant __fastcall GetRecords(int Count, /* out */ int &RecsOut, int Options)/* overload */;
	OleVariant __fastcall GetRecords(int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData)/* overload */;
	OleVariant __fastcall RowRequest(const OleVariant &Row, int RequestType, OleVariant &OwnerData);
	void __fastcall Execute(const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	OleVariant __fastcall GetParams(OleVariant &OwnerData);
	virtual OleVariant __fastcall DataRequest(const OleVariant &Input);
	__property OleVariant Data = {read=GetData};
	__property bool Exported = {read=FExported, write=FExported, default=1};
};


#pragma option push -b-
enum TResolverResponse { rrSkip, rrAbort, rrMerge, rrApply, rrIgnore };
#pragma option pop

typedef void __fastcall (__closure *TProviderDataEvent)(System::TObject* Sender, Dbclient::TCustomClientDataSet* DataSet);

typedef void __fastcall (__closure *TBeforeUpdateRecordEvent)(System::TObject* Sender, Db::TDataSet* SourceDS, Dbclient::TCustomClientDataSet* DeltaDS, Db::TUpdateKind UpdateKind, bool &Applied);

typedef void __fastcall (__closure *TAfterUpdateRecordEvent)(System::TObject* Sender, Db::TDataSet* SourceDS, Dbclient::TCustomClientDataSet* DeltaDS, Db::TUpdateKind UpdateKind);

typedef void __fastcall (__closure *TResolverErrorEvent)(System::TObject* Sender, Dbclient::TCustomClientDataSet* DataSet, Db::EUpdateError* E, Db::TUpdateKind UpdateKind, TResolverResponse &Response);

class DELPHICLASS TBaseProvider;
class DELPHICLASS TCustomResolver;
class DELPHICLASS TUpdateTree;
class PASCALIMPLEMENTATION TUpdateTree : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TPacketDataSet* FDeltaDS;
	TPacketDataSet* FErrorDS;
	bool FOpened;
	Db::TDataSet* FSourceDS;
	TUpdateTree* FParent;
	Classes::TList* FDetails;
	void *FData;
	TCustomResolver* FResolver;
	AnsiString FName;
	int __fastcall GetDetailCount(void);
	TUpdateTree* __fastcall GetDetail(int Index);
	TPacketDataSet* __fastcall GetErrorDS(void);
	bool __fastcall GetHasErrors(void);
	bool __fastcall GetIsNested(void);
	TUpdateTree* __fastcall GetTree(const AnsiString AName);
	
protected:
	void __fastcall Clear(void);
	bool __fastcall DoUpdates(void);
	void __fastcall RefreshData(Dbclient::TFetchOptions Options);
	void __fastcall InitErrorPacket(Db::EUpdateError* E, TResolverResponse Response);
	void __fastcall InitData(Db::TDataSet* ASource);
	void __fastcall InitDelta(const OleVariant &ADelta)/* overload */;
	void __fastcall InitDelta(TPacketDataSet* ADelta)/* overload */;
	__property void * Data = {read=FData, write=FData};
	__property TPacketDataSet* Delta = {read=FDeltaDS};
	__property int DetailCount = {read=GetDetailCount, nodefault};
	__property TUpdateTree* Details[int Index] = {read=GetDetail};
	__property TPacketDataSet* ErrorDS = {read=GetErrorDS};
	__property bool HasErrors = {read=GetHasErrors, nodefault};
	__property AnsiString Name = {read=FName, write=FName};
	__property TUpdateTree* Parent = {read=FParent};
	__property Db::TDataSet* Source = {read=FSourceDS};
	__property bool IsNested = {read=GetIsNested, nodefault};
	
public:
	__fastcall TUpdateTree(TUpdateTree* AParent, TCustomResolver* AResolver);
	__fastcall virtual ~TUpdateTree(void);
};


class PASCALIMPLEMENTATION TCustomResolver : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TBaseProvider* FProvider;
	TResolverResponse FPrevResponse;
	int FErrorCount;
	int FMaxErrors;
	TUpdateTree* FUpdateTree;
	
protected:
	__property TBaseProvider* Provider = {read=FProvider};
	bool __fastcall HandleUpdateError(TUpdateTree* Tree, Db::EUpdateError* E, int &MaxErrors, int &ErrorCount);
	void __fastcall LogUpdateRecord(TUpdateTree* Tree);
	void __fastcall LogUpdateError(TUpdateTree* Tree, Db::EUpdateError* E, TResolverResponse Response);
	void __fastcall InitKeyFields(TUpdateTree* Tree, TPacketDataSet* ADelta);
	virtual void __fastcall InternalBeforeResolve(TUpdateTree* Tree);
	bool __fastcall InternalUpdateRecord(TUpdateTree* Tree);
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall EndUpdate(void);
	virtual void __fastcall InitTreeData(TUpdateTree* Tree);
	virtual void __fastcall FreeTreeData(TUpdateTree* Tree);
	virtual void __fastcall InitializeConflictBuffer(TUpdateTree* Tree) = 0 ;
	virtual void __fastcall DoUpdate(TUpdateTree* Tree) = 0 ;
	virtual void __fastcall DoDelete(TUpdateTree* Tree) = 0 ;
	virtual void __fastcall DoInsert(TUpdateTree* Tree) = 0 ;
	virtual OleVariant __fastcall RowRequest(const OleVariant &Row, Dbclient::TFetchOptions Options);
	virtual OleVariant __fastcall ApplyUpdates(const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount);
	
public:
	__fastcall TCustomResolver(TBaseProvider* AProvider);
	__fastcall virtual ~TCustomResolver(void);
};


class PASCALIMPLEMENTATION TBaseProvider : public TCustomProvider 
{
	typedef TCustomProvider inherited;
	
private:
	TPacketDataSet* FDataDS;
	Db::TUpdateMode FUpdateMode;
	TCustomResolver* FResolver;
	TProviderDataEvent FOnGetData;
	TProviderDataEvent FOnUpdateData;
	TResolverErrorEvent FOnUpdateError;
	TBeforeUpdateRecordEvent FBeforeUpdateRecord;
	TAfterUpdateRecordEvent FAfterUpdateRecord;
	TProviderOptions FProviderOptions;
	
protected:
	void __fastcall CheckResolver(void);
	virtual TCustomResolver* __fastcall CreateResolver(void);
	void __fastcall FreeResolver(void);
	virtual void __fastcall CreateDataPacket(TGetRecordOptions PacketOpts, TProviderOptions ProvOpts, int &RecsOut, OleVariant &Data);
	void __fastcall DoOnGetData(OleVariant &Data);
	void __fastcall DoOnUpdateData(TPacketDataSet* Delta);
	virtual void __fastcall LocateRecord(Db::TDataSet* Source, Db::TDataSet* Delta);
	virtual void __fastcall UpdateRecord(Db::TDataSet* Source, Db::TDataSet* Delta, bool BlobsOnly, bool KeyOnly);
	virtual void __fastcall FetchDetails(Db::TDataSet* Source, Db::TDataSet* Delta);
	virtual OleVariant __fastcall InternalRowRequest(const OleVariant &Row, Dbclient::TFetchOptions RequestType);
	virtual OleVariant __fastcall InternalApplyUpdates(const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount);
	virtual OleVariant __fastcall InternalGetRecords(int Count, /* out */ int &RecsOut, TGetRecordOptions Options, const WideString CommandText, OleVariant &Params);
	
public:
	__fastcall virtual TBaseProvider(Classes::TComponent* AOwner);
	__fastcall virtual ~TBaseProvider(void);
	__property TCustomResolver* Resolver = {read=FResolver};
	__property TProviderOptions Options = {read=FProviderOptions, write=FProviderOptions, default=0};
	__property Db::TUpdateMode UpdateMode = {read=FUpdateMode, write=FUpdateMode, default=0};
	__property OnDataRequest ;
	__property TProviderDataEvent OnGetData = {read=FOnGetData, write=FOnGetData};
	__property TProviderDataEvent OnUpdateData = {read=FOnUpdateData, write=FOnUpdateData};
	__property TResolverErrorEvent OnUpdateError = {read=FOnUpdateError, write=FOnUpdateError};
	__property TBeforeUpdateRecordEvent BeforeUpdateRecord = {read=FBeforeUpdateRecord, write=FBeforeUpdateRecord};
	__property TAfterUpdateRecordEvent AfterUpdateRecord = {read=FAfterUpdateRecord, write=FAfterUpdateRecord};
};


typedef void __fastcall (__closure *TGetTableNameEvent)(System::TObject* Sender, Db::TDataSet* DataSet, AnsiString &TableName);

typedef void __fastcall (__closure *TGetDSProps)(System::TObject* Sender, Db::TDataSet* DataSet, /* out */ OleVariant &Properties);

class DELPHICLASS TDataSetProvider;
class PASCALIMPLEMENTATION TDataSetProvider : public TBaseProvider 
{
	typedef TBaseProvider inherited;
	
private:
	Db::TDataSet* FDataSet;
	bool FDataSetOpened;
	TDataPacketWriter* FDSWriter;
	TGetDSProps FGetDSProps;
	Db::TParams* FParams;
	bool FResolveToDataSet;
	int FRecordsSent;
	bool FConstraints;
	bool FTransactionStarted;
	TGetTableNameEvent FGetTableName;
	void __fastcall CheckDataSet(void);
	bool __fastcall FindRecord(Db::TDataSet* Source, Db::TDataSet* Delta, Db::TUpdateMode UpdateMode);
	void __fastcall Reset(void);
	void __fastcall SetCommandText(const AnsiString CommandText);
	void __fastcall SetDataSet(Db::TDataSet* ADataSet);
	void __fastcall SetParams(const OleVariant &Values);
	void __fastcall SetResolveToDataSet(bool Value);
	
protected:
	virtual void __fastcall DoGetTableName(Db::TDataSet* DataSet, AnsiString &TableName);
	virtual void __fastcall DoBeforeGetRecords(int Count, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	virtual void __fastcall DoBeforeExecute(const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	virtual void __fastcall DoGetProviderAttributes(Db::TDataSet* DataSet, Classes::TList* List);
	virtual TCustomResolver* __fastcall CreateResolver(void);
	virtual void __fastcall CreateDataPacket(TGetRecordOptions PacketOpts, TProviderOptions ProvOpts, int &RecsOut, OleVariant &Data);
	Db::TDataSet* __fastcall GetDataSetFromDelta(TUpdateTree* ATree, Db::TDataSet* Source, Db::TDataSet* Delta, Db::TUpdateMode Mode);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall LocateRecord(Db::TDataSet* Source, Db::TDataSet* Delta);
	virtual void __fastcall UpdateRecord(Db::TDataSet* Source, Db::TDataSet* Delta, bool BlobsOnly, bool KeyOnly);
	virtual void __fastcall FetchDetails(Db::TDataSet* Source, Db::TDataSet* Delta);
	void __fastcall FetchDetailsFromServer(Db::TDataSet* Source, Db::TDataSet* Current, Db::TDataSet* Delta, TUpdateTree* ATree);
	virtual OleVariant __fastcall InternalRowRequest(const OleVariant &Row, Dbclient::TFetchOptions Options);
	virtual OleVariant __fastcall InternalGetParams(Db::TParamTypes Types = (System::Set<Db::TParamType, ptUnknown, ptResult> () << Db::TParamType(0) << Db::TParamType(1) << Db::TParamType(2) << Db::TParamType(3) << Db::TParamType(4) ));
	virtual void __fastcall InternalExecute(const WideString CommandText, OleVariant &Params);
	virtual OleVariant __fastcall InternalGetRecords(int Count, /* out */ int &RecsOut, TGetRecordOptions Options, const WideString CommandText, OleVariant &Params);
	virtual OleVariant __fastcall InternalApplyUpdates(const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount);
	__property Db::TParams* Params = {read=FParams};
	
public:
	__fastcall virtual TDataSetProvider(Classes::TComponent* AOwner);
	__fastcall virtual ~TDataSetProvider(void);
	
__published:
	__property Db::TDataSet* DataSet = {read=FDataSet, write=SetDataSet};
	__property bool Constraints = {read=FConstraints, write=FConstraints, default=0};
	__property bool ResolveToDataSet = {read=FResolveToDataSet, write=SetResolveToDataSet, default=0};
	__property Exported  = {default=1};
	__property Options  = {default=0};
	__property UpdateMode  = {default=0};
	__property OnDataRequest ;
	__property OnGetData ;
	__property OnUpdateData ;
	__property OnUpdateError ;
	__property AfterUpdateRecord ;
	__property BeforeUpdateRecord ;
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
	__property TGetTableNameEvent OnGetTableName = {read=FGetTableName, write=FGetTableName};
	__property TGetDSProps OnGetDataSetProperties = {read=FGetDSProps, write=FGetDSProps};
};


class DELPHICLASS TProvider;
class PASCALIMPLEMENTATION TProvider : public TDataSetProvider 
{
	typedef TDataSetProvider inherited;
	
public:
	#pragma option push -w-inl
	/* TDataSetProvider.Create */ inline __fastcall virtual TProvider(Classes::TComponent* AOwner) : TDataSetProvider(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataSetProvider.Destroy */ inline __fastcall virtual ~TProvider(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetResolver;
class PASCALIMPLEMENTATION TDataSetResolver : public TCustomResolver 
{
	typedef TCustomResolver inherited;
	
private:
	AnsiString FBookmark;
	bool FOpened;
	TDataSetProvider* __fastcall GetProvider(void);
	void __fastcall PutRecord(TUpdateTree* Tree);
	
protected:
	__property TDataSetProvider* Provider = {read=GetProvider};
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall DoUpdate(TUpdateTree* Tree);
	virtual void __fastcall DoDelete(TUpdateTree* Tree);
	virtual void __fastcall DoInsert(TUpdateTree* Tree);
	virtual void __fastcall EndUpdate(void);
	virtual void __fastcall InternalBeforeResolve(TUpdateTree* Tree);
	virtual void __fastcall InitializeConflictBuffer(TUpdateTree* Tree);
	
public:
	__fastcall TDataSetResolver(TDataSetProvider* AProvider);
public:
	#pragma option push -w-inl
	/* TCustomResolver.Destroy */ inline __fastcall virtual ~TDataSetResolver(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSQLResolver;
class PASCALIMPLEMENTATION TSQLResolver : public TCustomResolver 
{
	typedef TCustomResolver inherited;
	
private:
	Classes::TStringList* FSQL;
	Db::TParams* FParams;
	TDataSetProvider* __fastcall GetProvider(void);
	void __fastcall GenWhereSQL(TUpdateTree* Tree, Classes::TStrings* SQL, Db::TParams* Params, Db::TUpdateMode GenUpdateMode, AnsiString Alias);
	void __fastcall GenInsertSQL(TUpdateTree* Tree, Classes::TStrings* SQL, Db::TParams* Params);
	void __fastcall GenDeleteSQL(TUpdateTree* Tree, Classes::TStrings* SQL, Db::TParams* Params, AnsiString Alias);
	void __fastcall GenUpdateSQL(TUpdateTree* Tree, Classes::TStrings* SQL, Db::TParams* Params, AnsiString Alias);
	void __fastcall GenSelectSQL(TUpdateTree* Tree, Classes::TStrings* SQL, Db::TParams* Params, AnsiString Alias, Db::TUpdateMode Mode = (Db::TUpdateMode)(0x2));
	bool __fastcall UseFieldInUpdate(Db::TField* Field);
	bool __fastcall UseFieldInWhere(Db::TField* Field, Db::TUpdateMode Mode);
	void __fastcall InternalDoUpdate(TUpdateTree* Tree, Db::TUpdateKind UpdateKind);
	
protected:
	__property TDataSetProvider* Provider = {read=GetProvider};
	virtual void __fastcall InitializeConflictBuffer(TUpdateTree* Tree);
	virtual void __fastcall DoExecSQL(Classes::TStringList* SQL, Db::TParams* Params);
	virtual void __fastcall DoGetValues(Classes::TStringList* SQL, Db::TParams* Params, Db::TDataSet* DataSet);
	virtual void __fastcall InitTreeData(TUpdateTree* Tree);
	virtual void __fastcall FreeTreeData(TUpdateTree* Tree);
	virtual void __fastcall DoUpdate(TUpdateTree* Tree);
	virtual void __fastcall DoDelete(TUpdateTree* Tree);
	virtual void __fastcall DoInsert(TUpdateTree* Tree);
	
public:
	__fastcall TSQLResolver(TDataSetProvider* AProvider);
	__fastcall virtual ~TSQLResolver(void);
};


class DELPHICLASS TLocalAppServer;
class PASCALIMPLEMENTATION TLocalAppServer : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TCustomProvider* FProvider;
	bool FProviderCreated;
	
protected:
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	HRESULT __safecall AS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData, OleVariant &AS_ApplyUpdates_result);
	HRESULT __safecall AS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData, OleVariant &AS_GetRecords_result);
	HRESULT __safecall AS_DataRequest(const WideString ProviderName, const OleVariant Data, OleVariant &AS_DataRequest_result);
	HRESULT __safecall AS_GetProviderNames(OleVariant &AS_GetProviderNames_result);
	HRESULT __safecall AS_GetParams(const WideString ProviderName, OleVariant &OwnerData, OleVariant &AS_GetParams_result);
	HRESULT __safecall AS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType, OleVariant &OwnerData, OleVariant &AS_RowRequest_result);
	HRESULT __safecall AS_Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	HRESULT __stdcall InterfaceSupportsErrorInfo(const GUID &iid);
	
public:
	__fastcall TLocalAppServer(TCustomProvider* AProvider)/* overload */;
	__fastcall TLocalAppServer(Db::TDataSet* ADataset)/* overload */;
	__fastcall virtual ~TLocalAppServer(void);
	virtual HRESULT __fastcall SafeCallException(System::TObject* ExceptObject, void * ExceptAddr);
private:
	void *__IAppServer;	/* Midas::IAppServer */
	void *__ISupportErrorInfo;	/* ISupportErrorInfo */
	
public:
	operator ISupportErrorInfo*(void) { return (ISupportErrorInfo*)&__ISupportErrorInfo; }
	operator IAppServer*(void) { return (IAppServer*)&__IAppServer; }
	
};


__interface IProviderContainer;
typedef System::DelphiInterface<IProviderContainer> _di_IProviderContainer;
__interface INTERFACE_UUID("{EEE9FFD4-752F-11D4-80DD-00C04F6BB88C}") IProviderContainer  : public IInterface 
{
	
public:
	virtual void __fastcall RegisterProvider(TCustomProvider* Prov) = 0 ;
	virtual void __fastcall UnRegisterProvider(TCustomProvider* Prov) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool InformixLob;
extern PACKAGE int ResetOption;
extern PACKAGE int MetaDataOption;
extern PACKAGE int XMLOption;
extern PACKAGE int XMLUTF8Option;
extern PACKAGE System::TObject* __fastcall GetObjectProperty(Classes::TPersistent* Instance, const AnsiString PropName);
extern PACKAGE AnsiString __fastcall GetStringProperty(Classes::TPersistent* Instance, const AnsiString PropName);
extern PACKAGE Variant __fastcall VarArrayFromStrings(Classes::TStrings* Strings);

}	/* namespace Provider */
using namespace Provider;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Provider
