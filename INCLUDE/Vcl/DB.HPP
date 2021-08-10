// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DB.pas' rev: 6.00

#ifndef DBHPP
#define DBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <FMTBcd.hpp>	// Pascal unit
#include <SqlTimSt.hpp>	// Pascal unit
#include <MaskUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Db
{
    typedef TDateTimeBase TDateTimeAlias;
}

namespace Db
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EDatabaseError;
class PASCALIMPLEMENTATION EDatabaseError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDatabaseError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDatabaseError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDatabaseError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDatabaseError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDatabaseError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDatabaseError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDatabaseError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDatabaseError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDatabaseError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EUpdateError;
class PASCALIMPLEMENTATION EUpdateError : public EDatabaseError 
{
	typedef EDatabaseError inherited;
	
private:
	int FErrorCode;
	int FPreviousError;
	AnsiString FContext;
	Sysutils::Exception* FOriginalException;
	
public:
	__fastcall EUpdateError(AnsiString NativeError, AnsiString Context, int ErrCode, int PrevError, Sysutils::Exception* E);
	__fastcall virtual ~EUpdateError(void);
	__property AnsiString Context = {read=FContext};
	__property int ErrorCode = {read=FErrorCode, nodefault};
	__property int PreviousError = {read=FPreviousError, nodefault};
	__property Sysutils::Exception* OriginalException = {read=FOriginalException};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EUpdateError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDatabaseError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EUpdateError(int Ident)/* overload */ : EDatabaseError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EUpdateError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDatabaseError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EUpdateError(const AnsiString Msg, int AHelpContext) : EDatabaseError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EUpdateError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDatabaseError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EUpdateError(int Ident, int AHelpContext)/* overload */ : EDatabaseError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EUpdateError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDatabaseError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFieldType { ftUnknown, ftString, ftSmallint, ftInteger, ftWord, ftBoolean, ftFloat, ftCurrency, ftBCD, ftDate, ftTime, ftDateTime, ftBytes, ftVarBytes, ftAutoInc, ftBlob, ftMemo, ftGraphic, ftFmtMemo, ftParadoxOle, ftDBaseOle, ftTypedBinary, ftCursor, ftFixedChar, ftWideString, ftLargeint, ftADT, ftArray, ftReference, ftDataSet, ftOraBlob, ftOraClob, ftVariant, ftInterface, ftIDispatch, ftGuid, ftTimeStamp, ftFMTBcd };
#pragma option pop

#pragma option push -b-
enum TDataSetState { dsInactive, dsBrowse, dsEdit, dsInsert, dsSetKey, dsCalcFields, dsFilter, dsNewValue, dsOldValue, dsCurValue, dsBlockRead, dsInternalCalc, dsOpening };
#pragma option pop

#pragma option push -b-
enum TDataEvent { deFieldChange, deRecordChange, deDataSetChange, deDataSetScroll, deLayoutChange, deUpdateRecord, deUpdateState, deCheckBrowseMode, dePropertyChange, deFieldListChange, deFocusControl, deParentScroll, deConnectChange };
#pragma option pop

#pragma option push -b-
enum TUpdateStatus { usUnmodified, usModified, usInserted, usDeleted };
#pragma option pop

typedef Set<TUpdateStatus, usUnmodified, usDeleted>  TUpdateStatusSet;

#pragma option push -b-
enum TUpdateAction { uaFail, uaAbort, uaSkip, uaRetry, uaApplied };
#pragma option pop

#pragma option push -b-
enum DB__3 { rtModified, rtInserted, rtDeleted, rtUnmodified };
#pragma option pop

typedef Set<DB__3, rtModified, rtUnmodified>  TUpdateRecordTypes;

#pragma option push -b-
enum TUpdateMode { upWhereAll, upWhereChanged, upWhereKeyOnly };
#pragma option pop

#pragma option push -b-
enum TUpdateKind { ukModify, ukInsert, ukDelete };
#pragma option pop

class DELPHICLASS TDataSet;
typedef void __fastcall (__closure *TUpdateErrorEvent)(TDataSet* DataSet, EDatabaseError* E, TUpdateKind UpdateKind, TUpdateAction &UpdateAction);

typedef void __fastcall (__closure *TUpdateRecordEvent)(TDataSet* DataSet, TUpdateKind UpdateKind, TUpdateAction &UpdateAction);

typedef void __fastcall (__closure *TLoginEvent)(System::TObject* Sender, AnsiString Username, AnsiString Password);

typedef void __fastcall (__closure *TConnectChangeEvent)(System::TObject* Sender, bool Connecting);

class DELPHICLASS TCustomConnection;
class PASCALIMPLEMENTATION TCustomConnection : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TList* FClients;
	Classes::TList* FDataSets;
	Classes::TList* FConnectEvents;
	bool FLoginPrompt;
	bool FStreamedConnected;
	Classes::TNotifyEvent FAfterConnect;
	Classes::TNotifyEvent FAfterDisconnect;
	Classes::TNotifyEvent FBeforeConnect;
	Classes::TNotifyEvent FBeforeDisconnect;
	TLoginEvent FOnLogin;
	
protected:
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	virtual bool __fastcall GetConnected(void);
	virtual TDataSet* __fastcall GetDataSet(int Index);
	virtual int __fastcall GetDataSetCount(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall RegisterClient(System::TObject* Client, TConnectChangeEvent Event = 0x0);
	virtual void __fastcall SetConnected(bool Value);
	void __fastcall SendConnectEvent(bool Connecting);
	__property bool StreamedConnected = {read=FStreamedConnected, write=FStreamedConnected, nodefault};
	virtual void __fastcall UnRegisterClient(System::TObject* Client);
	
public:
	__fastcall virtual TCustomConnection(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomConnection(void);
	void __fastcall Open(void)/* overload */;
	void __fastcall Close(void);
	__property bool Connected = {read=GetConnected, write=SetConnected, default=0};
	__property TDataSet* DataSets[int Index] = {read=GetDataSet};
	__property int DataSetCount = {read=GetDataSetCount, nodefault};
	__property bool LoginPrompt = {read=FLoginPrompt, write=FLoginPrompt, default=0};
	__property Classes::TNotifyEvent AfterConnect = {read=FAfterConnect, write=FAfterConnect};
	__property Classes::TNotifyEvent BeforeConnect = {read=FBeforeConnect, write=FBeforeConnect};
	__property Classes::TNotifyEvent AfterDisconnect = {read=FAfterDisconnect, write=FAfterDisconnect};
	__property Classes::TNotifyEvent BeforeDisconnect = {read=FBeforeDisconnect, write=FBeforeDisconnect};
	__property TLoginEvent OnLogin = {read=FOnLogin, write=FOnLogin};
};


class DELPHICLASS TNamedItem;
class PASCALIMPLEMENTATION TNamedItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FName;
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	virtual void __fastcall SetDisplayName(const AnsiString Value);
	
__published:
	__property AnsiString Name = {read=FName, write=SetDisplayName};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TNamedItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TNamedItem(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TDefUpdateMethod)(void);

class DELPHICLASS TDefCollection;
class PASCALIMPLEMENTATION TDefCollection : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
private:
	TDataSet* FDataSet;
	bool FUpdated;
	Classes::TNotifyEvent FOnUpdate;
	int FInternalUpdateCount;
	
protected:
	void __fastcall DoUpdate(System::TObject* Sender);
	virtual void __fastcall SetItemName(Classes::TCollectionItem* AItem);
	virtual void __fastcall Update(Classes::TCollectionItem* AItem);
	void __fastcall UpdateDefs(TDefUpdateMethod AMethod);
	__property Classes::TNotifyEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
	
public:
	__fastcall TDefCollection(TDataSet* ADataSet, Classes::TPersistent* AOwner, TMetaClass* AClass);
	TNamedItem* __fastcall Find(const AnsiString AName);
	void __fastcall GetItemNames(Classes::TStrings* List);
	int __fastcall IndexOf(const AnsiString AName);
	__property TDataSet* DataSet = {read=FDataSet};
	__property bool Updated = {read=FUpdated, write=FUpdated, nodefault};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TDefCollection(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TFieldClass;

#pragma option push -b-
enum TFieldAttribute { faHiddenCol, faReadonly, faRequired, faLink, faUnNamed, faFixed };
#pragma option pop

typedef Set<TFieldAttribute, faHiddenCol, faFixed>  TFieldAttributes;

class DELPHICLASS TFieldDef;
class DELPHICLASS TFieldDefs;
class PASCALIMPLEMENTATION TFieldDefs : public TDefCollection 
{
	typedef TDefCollection inherited;
	
public:
	TFieldDef* operator[](int Index) { return Items[Index]; }
	
private:
	TFieldDef* FParentDef;
	bool FHiddenFields;
	TFieldDef* __fastcall GetFieldDef(int Index);
	void __fastcall SetFieldDef(int Index, TFieldDef* Value);
	void __fastcall SetHiddenFields(bool Value);
	
protected:
	void __fastcall FieldDefUpdate(System::TObject* Sender);
	void __fastcall ChildDefUpdate(System::TObject* Sender);
	virtual void __fastcall SetItemName(Classes::TCollectionItem* AItem);
	
public:
	__fastcall TFieldDefs(Classes::TPersistent* AOwner);
	TFieldDef* __fastcall AddFieldDef(void);
	HIDESBASE TFieldDef* __fastcall Find(const AnsiString Name);
	HIDESBASE void __fastcall Update(void);
	HIDESBASE void __fastcall Add(const AnsiString Name, TFieldType DataType, int Size = 0x0, bool Required = false);
	__property bool HiddenFields = {read=FHiddenFields, write=SetHiddenFields, nodefault};
	__property TFieldDef* Items[int Index] = {read=GetFieldDef, write=SetFieldDef/*, default*/};
	__property TFieldDef* ParentDef = {read=FParentDef};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TFieldDefs(void) { }
	#pragma option pop
	
};


class DELPHICLASS TField;
class DELPHICLASS TObjectField;
class PASCALIMPLEMENTATION TFieldDef : public TNamedItem 
{
	typedef TNamedItem inherited;
	
private:
	TFieldDefs* FChildDefs;
	int FPrecision;
	int FFieldNo;
	int FSize;
	bool FInternalCalcField;
	TFieldType FDataType;
	TFieldAttributes FAttributes;
	TField* __fastcall CreateFieldComponent(Classes::TComponent* Owner, TObjectField* ParentField = (TObjectField*)(0x0), AnsiString FieldName = "");
	TFieldDefs* __fastcall GetChildDefs(void);
	TMetaClass* __fastcall GetFieldClass(void);
	int __fastcall GetFieldNo(void);
	TFieldDef* __fastcall GetParentDef(void);
	bool __fastcall GetRequired(void);
	int __fastcall GetSize(void);
	void __fastcall ReadRequired(Classes::TReader* Reader);
	void __fastcall SetAttributes(TFieldAttributes Value);
	void __fastcall SetChildDefs(TFieldDefs* Value);
	void __fastcall SetDataType(TFieldType Value);
	void __fastcall SetPrecision(int Value);
	void __fastcall SetRequired(bool Value);
	void __fastcall SetSize(int Value);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	
public:
	__fastcall TFieldDef(TFieldDefs* Owner, const AnsiString Name, TFieldType DataType, int Size, bool Required, int FieldNo)/* overload */;
	__fastcall virtual ~TFieldDef(void);
	TFieldDef* __fastcall AddChild(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	TField* __fastcall CreateField(Classes::TComponent* Owner, TObjectField* ParentField = (TObjectField*)(0x0), const AnsiString FieldName = "", bool CreateChildren = true);
	bool __fastcall HasChildDefs(void);
	__property TMetaClass* FieldClass = {read=GetFieldClass};
	__property int FieldNo = {read=GetFieldNo, write=FFieldNo, stored=false, nodefault};
	__property bool InternalCalcField = {read=FInternalCalcField, write=FInternalCalcField, nodefault};
	__property TFieldDef* ParentDef = {read=GetParentDef};
	__property bool Required = {read=GetRequired, write=SetRequired, nodefault};
	
__published:
	__property TFieldAttributes Attributes = {read=FAttributes, write=SetAttributes, default=0};
	__property TFieldDefs* ChildDefs = {read=GetChildDefs, write=SetChildDefs, stored=HasChildDefs};
	__property TFieldType DataType = {read=FDataType, write=SetDataType, default=0};
	__property int Precision = {read=FPrecision, write=SetPrecision, default=0};
	__property int Size = {read=GetSize, write=SetSize, default=0};
};


#pragma option push -b-
enum TIndexOption { ixPrimary, ixUnique, ixDescending, ixCaseInsensitive, ixExpression, ixNonMaintained };
#pragma option pop

typedef Set<TIndexOption, ixPrimary, ixNonMaintained>  TIndexOptions;

class DELPHICLASS TIndexDef;
class DELPHICLASS TIndexDefs;
class PASCALIMPLEMENTATION TIndexDef : public TNamedItem 
{
	typedef TNamedItem inherited;
	
private:
	AnsiString FSource;
	AnsiString FFieldExpression;
	AnsiString FDescFields;
	AnsiString FCaseInsFields;
	TIndexOptions FOptions;
	int FGroupingLevel;
	AnsiString __fastcall GetExpression();
	AnsiString __fastcall GetFields();
	void __fastcall SetDescFields(const AnsiString Value);
	void __fastcall SetCaseInsFields(const AnsiString Value);
	void __fastcall SetExpression(const AnsiString Value);
	void __fastcall SetFields(const AnsiString Value);
	void __fastcall SetOptions(TIndexOptions Value);
	void __fastcall SetSource(const AnsiString Value);
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	
public:
	__fastcall TIndexDef(TIndexDefs* Owner, const AnsiString Name, const AnsiString Fields, TIndexOptions Options)/* overload */;
	virtual void __fastcall Assign(Classes::TPersistent* ASource);
	__property AnsiString FieldExpression = {read=FFieldExpression};
	
__published:
	__property AnsiString CaseInsFields = {read=FCaseInsFields, write=SetCaseInsFields};
	__property AnsiString DescFields = {read=FDescFields, write=SetDescFields};
	__property AnsiString Expression = {read=GetExpression, write=SetExpression};
	__property AnsiString Fields = {read=GetFields, write=SetFields};
	__property TIndexOptions Options = {read=FOptions, write=SetOptions, default=0};
	__property AnsiString Source = {read=FSource, write=SetSource};
	__property int GroupingLevel = {read=FGroupingLevel, write=FGroupingLevel, default=0};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIndexDef(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TIndexDefs : public TDefCollection 
{
	typedef TDefCollection inherited;
	
public:
	TIndexDef* operator[](int Index) { return Items[Index]; }
	
private:
	TIndexDef* __fastcall GetIndexDef(int Index);
	void __fastcall SetIndexDef(int Index, TIndexDef* Value);
	
public:
	__fastcall TIndexDefs(TDataSet* ADataSet);
	TIndexDef* __fastcall AddIndexDef(void);
	HIDESBASE TIndexDef* __fastcall Find(const AnsiString Name);
	HIDESBASE void __fastcall Update(void);
	TIndexDef* __fastcall FindIndexForFields(const AnsiString Fields);
	TIndexDef* __fastcall GetIndexForFields(const AnsiString Fields, bool CaseInsensitive);
	HIDESBASE void __fastcall Add(const AnsiString Name, const AnsiString Fields, TIndexOptions Options);
	__property TIndexDef* Items[int Index] = {read=GetIndexDef, write=SetIndexDef/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TIndexDefs(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFlatList;
class PASCALIMPLEMENTATION TFlatList : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	TDataSet* FDataSet;
	bool FLocked;
	bool FUpdated;
	
protected:
	void __fastcall ListChanging(System::TObject* Sender);
	System::TObject* __fastcall FindItem(const AnsiString Name, bool MustExist);
	virtual int __fastcall GetCount(void);
	virtual bool __fastcall GetUpdated(void);
	virtual void __fastcall UpdateList(void) = 0 ;
	__property bool Updated = {read=GetUpdated, write=FUpdated, nodefault};
	__property bool Locked = {read=FLocked, write=FLocked, nodefault};
	
public:
	__fastcall TFlatList(TDataSet* ADataSet);
	void __fastcall Update(void);
	__property TDataSet* DataSet = {read=FDataSet};
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TFlatList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFieldDefList;
class PASCALIMPLEMENTATION TFieldDefList : public TFlatList 
{
	typedef TFlatList inherited;
	
public:
	TFieldDef* operator[](int Index) { return FieldDefs[Index]; }
	
private:
	TFieldDef* __fastcall GetFieldDef(int Index);
	
protected:
	virtual bool __fastcall GetUpdated(void);
	virtual void __fastcall UpdateList(void);
	
public:
	TFieldDef* __fastcall FieldByName(const AnsiString Name);
	HIDESBASE TFieldDef* __fastcall Find(const AnsiString Name);
	__property TFieldDef* FieldDefs[int Index] = {read=GetFieldDef/*, default*/};
public:
	#pragma option push -w-inl
	/* TFlatList.Create */ inline __fastcall TFieldDefList(TDataSet* ADataSet) : TFlatList(ADataSet) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TFieldDefList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFieldList;
class PASCALIMPLEMENTATION TFieldList : public TFlatList 
{
	typedef TFlatList inherited;
	
public:
	TField* operator[](int Index) { return Fields[Index]; }
	
private:
	TField* __fastcall GetField(int Index);
	
protected:
	virtual void __fastcall UpdateList(void);
	
public:
	TField* __fastcall FieldByName(const AnsiString Name);
	HIDESBASE TField* __fastcall Find(const AnsiString Name);
	__property TField* Fields[int Index] = {read=GetField/*, default*/};
public:
	#pragma option push -w-inl
	/* TFlatList.Create */ inline __fastcall TFieldList(TDataSet* ADataSet) : TFlatList(ADataSet) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TFieldList(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFieldKind { fkData, fkCalculated, fkLookup, fkInternalCalc, fkAggregate };
#pragma option pop

typedef Set<TFieldKind, fkData, fkAggregate>  TFieldKinds;

class DELPHICLASS TFields;
class PASCALIMPLEMENTATION TFields : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TField* operator[](int Index) { return Fields[Index]; }
	
private:
	Classes::TList* FList;
	TDataSet* FDataSet;
	int FSparseFields;
	Classes::TNotifyEvent FOnChange;
	TFieldKinds FValidFieldKinds;
	
protected:
	void __fastcall Changed(void);
	void __fastcall CheckFieldKind(TFieldKind FieldKind, TField* Field);
	int __fastcall GetCount(void);
	TField* __fastcall GetField(int Index);
	void __fastcall SetField(int Index, TField* Value);
	void __fastcall SetFieldIndex(TField* Field, int Value);
	__property int SparseFields = {read=FSparseFields, write=FSparseFields, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TFieldKinds ValidFieldKinds = {read=FValidFieldKinds, write=FValidFieldKinds, nodefault};
	
public:
	__fastcall TFields(TDataSet* ADataSet);
	__fastcall virtual ~TFields(void);
	void __fastcall Add(TField* Field);
	void __fastcall CheckFieldName(const AnsiString FieldName);
	void __fastcall CheckFieldNames(const AnsiString FieldNames);
	void __fastcall Clear(void);
	TField* __fastcall FindField(const AnsiString FieldName);
	TField* __fastcall FieldByName(const AnsiString FieldName);
	TField* __fastcall FieldByNumber(int FieldNo);
	void __fastcall GetFieldNames(Classes::TStrings* List);
	int __fastcall IndexOf(TField* Field);
	void __fastcall Remove(TField* Field);
	__property int Count = {read=GetCount, nodefault};
	__property TDataSet* DataSet = {read=FDataSet};
	__property TField* Fields[int Index] = {read=GetField, write=SetField/*, default*/};
};


#pragma option push -b-
enum TProviderFlag { pfInUpdate, pfInWhere, pfInKey, pfHidden };
#pragma option pop

typedef Set<TProviderFlag, pfInUpdate, pfHidden>  TProviderFlags;

typedef void __fastcall (__closure *TFieldNotifyEvent)(TField* Sender);

typedef void __fastcall (__closure *TFieldGetTextEvent)(TField* Sender, AnsiString &Text, bool DisplayText);

typedef void __fastcall (__closure *TFieldSetTextEvent)(TField* Sender, const AnsiString Text);

typedef TField* *TFieldRef;

typedef Set<char, 0, 255>  TFieldChars;

#pragma option push -b-
enum TAutoRefreshFlag { arNone, arAutoInc, arDefault };
#pragma option pop

struct TLookupListEntry;
typedef TLookupListEntry *PLookupListEntry;

struct TLookupListEntry
{
	Variant Key;
	Variant Value;
} ;

class DELPHICLASS TLookupList;
class PASCALIMPLEMENTATION TLookupList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FList;
	
public:
	__fastcall TLookupList(void);
	__fastcall virtual ~TLookupList(void);
	void __fastcall Add(const Variant &AKey, const Variant &AValue);
	void __fastcall Clear(void);
	Variant __fastcall ValueOfKey(const Variant &AKey);
};


class PASCALIMPLEMENTATION TField : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TAutoRefreshFlag FAutoGenerateValue;
	TDataSet* FDataSet;
	AnsiString FFieldName;
	TFields* FFields;
	TFieldType FDataType;
	bool FReadOnly;
	TFieldKind FFieldKind;
	Classes::TAlignment FAlignment;
	bool FVisible;
	bool FRequired;
	bool FValidating;
	int FSize;
	int FOffset;
	int FFieldNo;
	int FDisplayWidth;
	AnsiString FDisplayLabel;
	AnsiString FEditMask;
	void *FValueBuffer;
	TDataSet* FLookupDataSet;
	AnsiString FKeyFields;
	AnsiString FLookupKeyFields;
	AnsiString FLookupResultField;
	bool FLookupCache;
	TLookupList* FLookupList;
	AnsiString FAttributeSet;
	AnsiString FCustomConstraint;
	AnsiString FImportedConstraint;
	AnsiString FConstraintErrorMessage;
	AnsiString FDefaultExpression;
	AnsiString FOrigin;
	TProviderFlags FProviderFlags;
	TObjectField* FParentField;
	TFieldChars FValidChars;
	TFieldNotifyEvent FOnChange;
	TFieldNotifyEvent FOnValidate;
	TFieldGetTextEvent FOnGetText;
	TFieldSetTextEvent FOnSetText;
	void __fastcall CalcLookupValue(void);
	bool __fastcall GetCalculated(void);
	AnsiString __fastcall GetDisplayLabel();
	AnsiString __fastcall GetDisplayName();
	AnsiString __fastcall GetDisplayText();
	int __fastcall GetDisplayWidth(void);
	AnsiString __fastcall GetEditText();
	AnsiString __fastcall GetFullName();
	int __fastcall GetIndex(void);
	bool __fastcall GetIsIndexField(void);
	bool __fastcall GetLookup(void);
	TLookupList* __fastcall GetLookupList(void);
	Variant __fastcall GetCurValue();
	Variant __fastcall GetNewValue();
	Variant __fastcall GetOldValue();
	bool __fastcall IsDisplayLabelStored(void);
	bool __fastcall IsDisplayWidthStored(void);
	void __fastcall ReadAttributeSet(Classes::TReader* Reader);
	void __fastcall ReadCalculated(Classes::TReader* Reader);
	void __fastcall ReadLookup(Classes::TReader* Reader);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetCalculated(bool Value);
	void __fastcall SetDisplayLabel(AnsiString Value);
	void __fastcall SetDisplayWidth(int Value);
	void __fastcall SetEditMask(const AnsiString Value);
	void __fastcall SetEditText(const AnsiString Value);
	void __fastcall SetFieldName(const AnsiString Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetLookup(bool Value);
	void __fastcall SetLookupDataSet(TDataSet* Value);
	void __fastcall SetLookupKeyFields(const AnsiString Value);
	void __fastcall SetLookupResultField(const AnsiString Value);
	void __fastcall SetKeyFields(const AnsiString Value);
	void __fastcall SetLookupCache(const bool Value);
	void __fastcall SetNewValue(const Variant &Value);
	void __fastcall SetReadOnly(const bool Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall ValidateLookupInfo(bool All);
	void __fastcall WriteAttributeSet(Classes::TWriter* Writer);
	void __fastcall WriteCalculated(Classes::TWriter* Writer);
	void __fastcall WriteLookup(Classes::TWriter* Writer);
	
protected:
	DYNAMIC EDatabaseError* __fastcall AccessError(const AnsiString TypeName);
	virtual void __fastcall Bind(bool Binding);
	void __fastcall CheckInactive(void);
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual void __fastcall Change(void);
	void __fastcall DataChanged(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall FreeBuffers(void);
	virtual Fmtbcd::TBcd __fastcall GetAsBCD();
	virtual bool __fastcall GetAsBoolean(void);
	virtual Variant __fastcall GetAsByteArray();
	virtual System::Currency __fastcall GetAsCurrency(void);
	virtual System::TDateTime __fastcall GetAsDateTime(void);
	virtual double __fastcall GetAsFloat(void);
	virtual int __fastcall GetAsInteger(void);
	virtual Sqltimst::TSQLTimeStamp __fastcall GetAsSqlTimeStamp();
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual bool __fastcall GetCanModify(void);
	virtual AnsiString __fastcall GetClassDesc();
	virtual int __fastcall GetDataSize(void);
	virtual void __fastcall CopyData(void * Source, void * Dest);
	virtual int __fastcall GetDefaultWidth(void);
	virtual int __fastcall GetFieldNo(void);
	virtual bool __fastcall GetHasConstraints(void);
	virtual bool __fastcall GetIsNull(void);
	virtual int __fastcall GetSize(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall PropertyChanged(bool LayoutAffected);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	virtual void __fastcall SetAsBCD(const Fmtbcd::TBcd &Value);
	virtual void __fastcall SetAsBoolean(bool Value);
	virtual void __fastcall SetAsByteArray(const Variant &Value);
	virtual void __fastcall SetAsCurrency(System::Currency Value);
	virtual void __fastcall SetAsDateTime(System::TDateTime Value);
	virtual void __fastcall SetAsFloat(double Value);
	virtual void __fastcall SetAsInteger(int Value);
	virtual void __fastcall SetAsSQLTimeStamp(const Sqltimst::TSQLTimeStamp &Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetAsVariant(const Variant &Value);
	virtual void __fastcall SetDataSet(TDataSet* ADataSet);
	void __fastcall SetDataType(TFieldType Value);
	virtual void __fastcall SetFieldKind(TFieldKind Value);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	virtual void __fastcall SetParentField(TObjectField* AField);
	virtual void __fastcall SetSize(int Value);
	virtual void __fastcall SetText(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	void __fastcall SetAutoGenerateValue(const TAutoRefreshFlag Value);
	
public:
	__fastcall virtual TField(Classes::TComponent* AOwner);
	__fastcall virtual ~TField(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall AssignValue(const System::TVarRec &Value);
	virtual void __fastcall Clear(void);
	void __fastcall FocusControl(void);
	bool __fastcall GetData(void * Buffer, bool NativeFormat = true);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	/* virtual class method */ virtual bool __fastcall IsBlob(TMetaClass* vmt);
	virtual bool __fastcall IsValidChar(char InputChar);
	void __fastcall RefreshLookupList(void);
	void __fastcall SetData(void * Buffer, bool NativeFormat = true);
	virtual void __fastcall SetFieldType(TFieldType Value);
	void __fastcall Validate(void * Buffer);
	__property Fmtbcd::TBcd AsBCD = {read=GetAsBCD, write=SetAsBCD};
	__property bool AsBoolean = {read=GetAsBoolean, write=SetAsBoolean, nodefault};
	__property System::Currency AsCurrency = {read=GetAsCurrency, write=SetAsCurrency};
	__property System::TDateTime AsDateTime = {read=GetAsDateTime, write=SetAsDateTime};
	__property Sqltimst::TSQLTimeStamp AsSQLTimeStamp = {read=GetAsSqlTimeStamp, write=SetAsSQLTimeStamp};
	__property double AsFloat = {read=GetAsFloat, write=SetAsFloat};
	__property int AsInteger = {read=GetAsInteger, write=SetAsInteger, nodefault};
	__property AnsiString AsString = {read=GetAsString, write=SetAsString};
	__property Variant AsVariant = {read=GetAsVariant, write=SetAsVariant};
	__property AnsiString AttributeSet = {read=FAttributeSet, write=FAttributeSet};
	__property bool Calculated = {read=GetCalculated, write=SetCalculated, default=0};
	__property bool CanModify = {read=GetCanModify, nodefault};
	__property Variant CurValue = {read=GetCurValue};
	__property TDataSet* DataSet = {read=FDataSet, write=SetDataSet, stored=false};
	__property int DataSize = {read=GetDataSize, nodefault};
	__property TFieldType DataType = {read=FDataType, nodefault};
	__property AnsiString DisplayName = {read=GetDisplayName};
	__property AnsiString DisplayText = {read=GetDisplayText};
	__property AnsiString EditMask = {read=FEditMask, write=SetEditMask};
	__property AnsiString EditMaskPtr = {read=FEditMask};
	__property int FieldNo = {read=GetFieldNo, nodefault};
	__property AnsiString FullName = {read=GetFullName};
	__property bool IsIndexField = {read=GetIsIndexField, nodefault};
	__property bool IsNull = {read=GetIsNull, nodefault};
	__property bool Lookup = {read=GetLookup, write=SetLookup, nodefault};
	__property TLookupList* LookupList = {read=GetLookupList};
	__property Variant NewValue = {read=GetNewValue, write=SetNewValue};
	__property int Offset = {read=FOffset, nodefault};
	__property Variant OldValue = {read=GetOldValue};
	__property TObjectField* ParentField = {read=FParentField, write=SetParentField};
	__property int Size = {read=GetSize, write=SetSize, nodefault};
	__property AnsiString Text = {read=GetEditText, write=SetEditText};
	__property TFieldChars ValidChars = {read=FValidChars, write=FValidChars};
	__property Variant Value = {read=GetAsVariant, write=SetAsVariant};
	
__published:
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property TAutoRefreshFlag AutoGenerateValue = {read=FAutoGenerateValue, write=SetAutoGenerateValue, default=0};
	__property AnsiString CustomConstraint = {read=FCustomConstraint, write=FCustomConstraint};
	__property AnsiString ConstraintErrorMessage = {read=FConstraintErrorMessage, write=FConstraintErrorMessage};
	__property AnsiString DefaultExpression = {read=FDefaultExpression, write=FDefaultExpression};
	__property AnsiString DisplayLabel = {read=GetDisplayLabel, write=SetDisplayLabel, stored=IsDisplayLabelStored};
	__property int DisplayWidth = {read=GetDisplayWidth, write=SetDisplayWidth, stored=IsDisplayWidthStored, nodefault};
	__property TFieldKind FieldKind = {read=FFieldKind, write=SetFieldKind, default=0};
	__property AnsiString FieldName = {read=FFieldName, write=SetFieldName};
	__property bool HasConstraints = {read=GetHasConstraints, default=0};
	__property int Index = {read=GetIndex, write=SetIndex, stored=false, nodefault};
	__property AnsiString ImportedConstraint = {read=FImportedConstraint, write=FImportedConstraint};
	__property TDataSet* LookupDataSet = {read=FLookupDataSet, write=SetLookupDataSet};
	__property AnsiString LookupKeyFields = {read=FLookupKeyFields, write=SetLookupKeyFields};
	__property AnsiString LookupResultField = {read=FLookupResultField, write=SetLookupResultField};
	__property AnsiString KeyFields = {read=FKeyFields, write=SetKeyFields};
	__property bool LookupCache = {read=FLookupCache, write=SetLookupCache, default=0};
	__property AnsiString Origin = {read=FOrigin, write=FOrigin};
	__property TProviderFlags ProviderFlags = {read=FProviderFlags, write=FProviderFlags, default=3};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property bool Required = {read=FRequired, write=FRequired, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property TFieldNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TFieldGetTextEvent OnGetText = {read=FOnGetText, write=FOnGetText};
	__property TFieldSetTextEvent OnSetText = {read=FOnSetText, write=FOnSetText};
	__property TFieldNotifyEvent OnValidate = {read=FOnValidate, write=FOnValidate};
};


class DELPHICLASS TStringField;
class PASCALIMPLEMENTATION TStringField : public TField 
{
	typedef TField inherited;
	
private:
	bool FFixedChar;
	bool FTransliterate;
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual Fmtbcd::TBcd __fastcall GetAsBCD();
	virtual bool __fastcall GetAsBoolean(void);
	virtual System::TDateTime __fastcall GetAsDateTime(void);
	virtual double __fastcall GetAsFloat(void);
	virtual int __fastcall GetAsInteger(void);
	virtual Sqltimst::TSQLTimeStamp __fastcall GetAsSqlTimeStamp();
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	bool __fastcall GetValue(AnsiString &Value);
	virtual void __fastcall SetAsBCD(const Fmtbcd::TBcd &Value);
	virtual void __fastcall SetAsBoolean(bool Value);
	virtual void __fastcall SetAsDateTime(System::TDateTime Value);
	virtual void __fastcall SetAsFloat(double Value);
	virtual void __fastcall SetAsInteger(int Value);
	virtual void __fastcall SetAsSQLTimeStamp(const Sqltimst::TSQLTimeStamp &Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TStringField(Classes::TComponent* AOwner);
	__property AnsiString Value = {read=GetAsString, write=SetAsString};
	
__published:
	__property EditMask ;
	__property bool FixedChar = {read=FFixedChar, write=FFixedChar, default=0};
	__property Size  = {default=20};
	__property bool Transliterate = {read=FTransliterate, write=FTransliterate, default=1};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TStringField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWideStringField;
class PASCALIMPLEMENTATION TWideStringField : public TStringField 
{
	typedef TStringField inherited;
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual void __fastcall CopyData(void * Source, void * Dest);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	WideString __fastcall GetAsWideString();
	virtual int __fastcall GetDataSize(void);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	void __fastcall SetAsWideString(const WideString Value);
	
public:
	__fastcall virtual TWideStringField(Classes::TComponent* AOwner);
	__property WideString Value = {read=GetAsWideString, write=SetAsWideString};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TWideStringField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TNumericField;
class PASCALIMPLEMENTATION TNumericField : public TField 
{
	typedef TField inherited;
	
private:
	AnsiString FDisplayFormat;
	AnsiString FEditFormat;
	
protected:
	void __fastcall RangeError(Extended Value, Extended Min, Extended Max);
	void __fastcall SetDisplayFormat(const AnsiString Value);
	void __fastcall SetEditFormat(const AnsiString Value);
	
public:
	__fastcall virtual TNumericField(Classes::TComponent* AOwner);
	
__published:
	__property Alignment  = {default=1};
	__property AnsiString DisplayFormat = {read=FDisplayFormat, write=SetDisplayFormat};
	__property AnsiString EditFormat = {read=FEditFormat, write=SetEditFormat};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TNumericField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIntegerField;
class PASCALIMPLEMENTATION TIntegerField : public TNumericField 
{
	typedef TNumericField inherited;
	
private:
	int FMinRange;
	int FMaxRange;
	int FMinValue;
	int FMaxValue;
	void __fastcall CheckRange(int Value, int Min, int Max);
	void __fastcall SetMaxValue(int Value);
	void __fastcall SetMinValue(int Value);
	
protected:
	virtual double __fastcall GetAsFloat(void);
	virtual int __fastcall GetAsInteger(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	bool __fastcall GetValue(int &Value);
	virtual void __fastcall SetAsFloat(double Value);
	virtual void __fastcall SetAsInteger(int Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TIntegerField(Classes::TComponent* AOwner);
	__property int Value = {read=GetAsInteger, write=SetAsInteger, nodefault};
	
__published:
	__property int MaxValue = {read=FMaxValue, write=SetMaxValue, default=0};
	__property int MinValue = {read=FMinValue, write=SetMinValue, default=0};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TIntegerField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSmallintField;
class PASCALIMPLEMENTATION TSmallintField : public TIntegerField 
{
	typedef TIntegerField inherited;
	
protected:
	virtual int __fastcall GetDataSize(void);
	
public:
	__fastcall virtual TSmallintField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TSmallintField(void) { }
	#pragma option pop
	
};


typedef __int64 Largeint;

class DELPHICLASS TLargeintField;
class PASCALIMPLEMENTATION TLargeintField : public TNumericField 
{
	typedef TNumericField inherited;
	
private:
	__int64 FMinValue;
	__int64 FMaxValue;
	void __fastcall CheckRange(__int64 Value, __int64 Min, __int64 Max);
	
protected:
	virtual double __fastcall GetAsFloat(void);
	virtual int __fastcall GetAsInteger(void);
	__int64 __fastcall GetAsLargeint(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	bool __fastcall GetValue(__int64 &Value);
	virtual void __fastcall SetAsFloat(double Value);
	virtual void __fastcall SetAsInteger(int Value);
	void __fastcall SetAsLargeint(__int64 Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TLargeintField(Classes::TComponent* AOwner);
	__property __int64 AsLargeInt = {read=GetAsLargeint, write=SetAsLargeint};
	__property __int64 Value = {read=GetAsLargeint, write=SetAsLargeint};
	
__published:
	__property __int64 MaxValue = {read=FMaxValue, write=FMaxValue, default=0};
	__property __int64 MinValue = {read=FMinValue, write=FMinValue, default=0};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TLargeintField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWordField;
class PASCALIMPLEMENTATION TWordField : public TIntegerField 
{
	typedef TIntegerField inherited;
	
protected:
	virtual int __fastcall GetDataSize(void);
	
public:
	__fastcall virtual TWordField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TWordField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAutoIncField;
class PASCALIMPLEMENTATION TAutoIncField : public TIntegerField 
{
	typedef TIntegerField inherited;
	
public:
	__fastcall virtual TAutoIncField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TAutoIncField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFloatField;
class PASCALIMPLEMENTATION TFloatField : public TNumericField 
{
	typedef TNumericField inherited;
	
private:
	bool FCurrency;
	bool FCheckRange;
	int FPrecision;
	double FMinValue;
	double FMaxValue;
	void __fastcall SetCurrency(bool Value);
	void __fastcall SetMaxValue(double Value);
	void __fastcall SetMinValue(double Value);
	void __fastcall SetPrecision(int Value);
	void __fastcall UpdateCheckRange(void);
	
protected:
	virtual double __fastcall GetAsFloat(void);
	virtual int __fastcall GetAsInteger(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	virtual void __fastcall SetAsFloat(double Value);
	virtual void __fastcall SetAsInteger(int Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TFloatField(Classes::TComponent* AOwner);
	__property double Value = {read=GetAsFloat, write=SetAsFloat};
	
__published:
	__property bool currency = {read=FCurrency, write=SetCurrency, default=0};
	__property double MaxValue = {read=FMaxValue, write=SetMaxValue};
	__property double MinValue = {read=FMinValue, write=SetMinValue};
	__property int Precision = {read=FPrecision, write=SetPrecision, default=15};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TFloatField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCurrencyField;
class PASCALIMPLEMENTATION TCurrencyField : public TFloatField 
{
	typedef TFloatField inherited;
	
public:
	__fastcall virtual TCurrencyField(Classes::TComponent* AOwner);
	
__published:
	__property currency  = {default=1};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TCurrencyField(void) { }
	#pragma option pop
	
};


typedef AnsiString DB__82[2];

class DELPHICLASS TBooleanField;
class PASCALIMPLEMENTATION TBooleanField : public TField 
{
	typedef TField inherited;
	
private:
	AnsiString FDisplayValues;
	AnsiString FTextValues[2];
	void __fastcall LoadTextValues(void);
	void __fastcall SetDisplayValues(const AnsiString Value);
	
protected:
	virtual bool __fastcall GetAsBoolean(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual void __fastcall SetAsBoolean(bool Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TBooleanField(Classes::TComponent* AOwner);
	__property bool Value = {read=GetAsBoolean, write=SetAsBoolean, nodefault};
	
__published:
	__property AnsiString DisplayValues = {read=FDisplayValues, write=SetDisplayValues};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TBooleanField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDateTimeField;
class PASCALIMPLEMENTATION TDateTimeField : public TField 
{
	typedef TField inherited;
	
private:
	AnsiString FDisplayFormat;
	bool __fastcall GetValue(System::TDateTime &Value);
	void __fastcall SetDisplayFormat(const AnsiString Value);
	
protected:
	virtual void __fastcall CopyData(void * Source, void * Dest);
	virtual System::TDateTime __fastcall GetAsDateTime(void);
	virtual double __fastcall GetAsFloat(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	virtual void __fastcall SetAsDateTime(System::TDateTime Value);
	virtual void __fastcall SetAsFloat(double Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TDateTimeField(Classes::TComponent* AOwner);
	__property System::TDateTime Value = {read=GetAsDateTime, write=SetAsDateTime};
	
__published:
	__property AnsiString DisplayFormat = {read=FDisplayFormat, write=SetDisplayFormat};
	__property EditMask ;
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TDateTimeField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSQLTimeStampField;
class PASCALIMPLEMENTATION TSQLTimeStampField : public TField 
{
	typedef TField inherited;
	
private:
	AnsiString FDisplayFormat;
	bool __fastcall GetValue(Sqltimst::TSQLTimeStamp &Value);
	void __fastcall SetDisplayFormat(const AnsiString Value);
	
protected:
	virtual void __fastcall CopyData(void * Source, void * Dest);
	virtual Sqltimst::TSQLTimeStamp __fastcall GetAsSQLTimeStamp();
	virtual System::TDateTime __fastcall GetAsDateTime(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	virtual void __fastcall SetAsSQLTimeStamp(const Sqltimst::TSQLTimeStamp &Value);
	virtual void __fastcall SetAsDateTime(System::TDateTime Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TSQLTimeStampField(Classes::TComponent* AOwner);
	__property Sqltimst::TSQLTimeStamp Value = {read=GetAsSqlTimeStamp, write=SetAsSQLTimeStamp};
	
__published:
	__property AnsiString DisplayFormat = {read=FDisplayFormat, write=SetDisplayFormat};
	__property EditMask ;
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TSQLTimeStampField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDateField;
class PASCALIMPLEMENTATION TDateField : public TDateTimeField 
{
	typedef TDateTimeField inherited;
	
protected:
	virtual int __fastcall GetDataSize(void);
	
public:
	__fastcall virtual TDateField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TDateField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTimeField;
class PASCALIMPLEMENTATION TTimeField : public TDateTimeField 
{
	typedef TDateTimeField inherited;
	
protected:
	virtual int __fastcall GetDataSize(void);
	
public:
	__fastcall virtual TTimeField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TTimeField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBinaryField;
class PASCALIMPLEMENTATION TBinaryField : public TField 
{
	typedef TField inherited;
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual void __fastcall CopyData(void * Source, void * Dest);
	virtual AnsiString __fastcall GetAsString();
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	virtual Variant __fastcall GetAsVariant();
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetText(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TBinaryField(Classes::TComponent* AOwner);
	
__published:
	__property Size  = {default=16};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TBinaryField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBytesField;
class PASCALIMPLEMENTATION TBytesField : public TBinaryField 
{
	typedef TBinaryField inherited;
	
protected:
	virtual int __fastcall GetDataSize(void);
	
public:
	__fastcall virtual TBytesField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TBytesField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TVarBytesField;
class PASCALIMPLEMENTATION TVarBytesField : public TBytesField 
{
	typedef TBytesField inherited;
	
protected:
	virtual int __fastcall GetDataSize(void);
	virtual void __fastcall SetAsByteArray(const Variant &Value);
	
public:
	__fastcall virtual TVarBytesField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TVarBytesField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBCDField;
class PASCALIMPLEMENTATION TBCDField : public TNumericField 
{
	typedef TNumericField inherited;
	
private:
	bool FCurrency;
	bool FCheckRange;
	System::Currency FMinValue;
	System::Currency FMaxValue;
	int FPrecision;
	void __fastcall SetCurrency(bool Value);
	void __fastcall SetMaxValue(System::Currency Value);
	void __fastcall SetMinValue(System::Currency Value);
	void __fastcall SetPrecision(int Value);
	void __fastcall UpdateCheckRange(void);
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual void __fastcall CopyData(void * Source, void * Dest);
	virtual Fmtbcd::TBcd __fastcall GetAsBCD();
	virtual System::Currency __fastcall GetAsCurrency(void);
	virtual double __fastcall GetAsFloat(void);
	virtual int __fastcall GetAsInteger(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	bool __fastcall GetValue(System::Currency &Value);
	virtual void __fastcall SetAsBCD(const Fmtbcd::TBcd &Value);
	virtual void __fastcall SetAsCurrency(System::Currency Value);
	virtual void __fastcall SetAsFloat(double Value);
	virtual void __fastcall SetAsInteger(int Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TBCDField(Classes::TComponent* AOwner);
	__property System::Currency Value = {read=GetAsCurrency, write=SetAsCurrency};
	
__published:
	__property bool currency = {read=FCurrency, write=SetCurrency, default=0};
	__property System::Currency MaxValue = {read=FMaxValue, write=SetMaxValue};
	__property System::Currency MinValue = {read=FMinValue, write=SetMinValue};
	__property int Precision = {read=FPrecision, write=SetPrecision, default=0};
	__property Size  = {default=4};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TBCDField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFMTBCDField;
class PASCALIMPLEMENTATION TFMTBCDField : public TNumericField 
{
	typedef TNumericField inherited;
	
private:
	bool FCurrency;
	bool FCheckRange;
	AnsiString FMinValue;
	AnsiString FMaxValue;
	int FPrecision;
	void __fastcall BcdRangeError(const Variant &Value, AnsiString Max, AnsiString Min);
	void __fastcall SetCurrency(bool Value);
	void __fastcall SetMaxValue(AnsiString Value);
	void __fastcall SetMinValue(AnsiString Value);
	void __fastcall SetPrecision(int Value);
	void __fastcall UpdateCheckRange(void);
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual void __fastcall CopyData(void * Source, void * Dest);
	virtual System::Currency __fastcall GetAsCurrency(void);
	virtual Fmtbcd::TBcd __fastcall GetAsBCD();
	virtual double __fastcall GetAsFloat(void);
	virtual int __fastcall GetAsInteger(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	bool __fastcall GetValue(Fmtbcd::TBcd &Value);
	virtual void __fastcall SetAsCurrency(System::Currency Value);
	virtual void __fastcall SetAsBCD(const Fmtbcd::TBcd &Value);
	virtual void __fastcall SetAsFloat(double Value);
	virtual void __fastcall SetAsInteger(int Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TFMTBCDField(Classes::TComponent* AOwner);
	__property Fmtbcd::TBcd Value = {read=GetAsBCD, write=SetAsBCD};
	
__published:
	__property bool currency = {read=FCurrency, write=SetCurrency, default=0};
	__property AnsiString MaxValue = {read=FMaxValue, write=SetMaxValue};
	__property AnsiString MinValue = {read=FMinValue, write=SetMinValue};
	__property int Precision = {read=FPrecision, write=SetPrecision, default=0};
	__property Size  = {default=4};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TFMTBCDField(void) { }
	#pragma option pop
	
};


typedef TFieldType TBlobType;

class DELPHICLASS TBlobField;
class PASCALIMPLEMENTATION TBlobField : public TField 
{
	typedef TField inherited;
	
private:
	int FModifiedRecord;
	bool FModified;
	bool FGraphicHeader;
	bool FTransliterate;
	TBlobType __fastcall GetBlobType(void);
	bool __fastcall GetModified(void);
	void __fastcall LoadFromBlob(TBlobField* Blob);
	void __fastcall LoadFromStrings(Classes::TStrings* Strings);
	void __fastcall LoadFromStreamPersist(Classes::_di_IStreamPersist StreamPersist);
	void __fastcall SaveToStrings(Classes::TStrings* Strings);
	void __fastcall SaveToStreamPersist(Classes::_di_IStreamPersist StreamPersist);
	void __fastcall SetBlobType(TBlobType Value);
	void __fastcall SetModified(bool Value);
	bool __fastcall SupportsStreamPersist(const Classes::TPersistent* Persistent, Classes::_di_IStreamPersist &StreamPersist);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall FreeBuffers(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetBlobSize(void);
	virtual AnsiString __fastcall GetClassDesc();
	virtual bool __fastcall GetIsNull(void);
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetText(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TBlobField(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	/* virtual class method */ virtual bool __fastcall IsBlob(TMetaClass* vmt);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall SaveToFile(const AnsiString FileName);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall SetFieldType(TFieldType Value);
	__property int BlobSize = {read=GetBlobSize, nodefault};
	__property bool Modified = {read=GetModified, write=SetModified, nodefault};
	__property AnsiString Value = {read=GetAsString, write=SetAsString};
	__property bool Transliterate = {read=FTransliterate, write=FTransliterate, nodefault};
	
__published:
	__property TBlobType BlobType = {read=GetBlobType, write=SetBlobType, default=15};
	__property bool GraphicHeader = {read=FGraphicHeader, write=FGraphicHeader, default=1};
	__property Size  = {default=0};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TBlobField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMemoField;
class PASCALIMPLEMENTATION TMemoField : public TBlobField 
{
	typedef TBlobField inherited;
	
public:
	__fastcall virtual TMemoField(Classes::TComponent* AOwner);
	
__published:
	__property Transliterate  = {default=1};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TMemoField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGraphicField;
class PASCALIMPLEMENTATION TGraphicField : public TBlobField 
{
	typedef TBlobField inherited;
	
public:
	__fastcall virtual TGraphicField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TGraphicField(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TObjectField : public TField 
{
	typedef TField inherited;
	
public:
	Variant operator[](int Index) { return FieldValues[Index]; }
	
private:
	TFields* FFields;
	TFields* FOwnedFields;
	AnsiString FObjectType;
	int FTotalSize;
	bool FUnNamed;
	void __fastcall DataSetChanged(void);
	void __fastcall ReadUnNamed(Classes::TReader* Reader);
	void __fastcall WriteUnNamed(Classes::TWriter* Writer);
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall FreeBuffers(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual int __fastcall GetDefaultWidth(void);
	int __fastcall GetFieldCount(void);
	virtual TFields* __fastcall GetFields(void);
	virtual Variant __fastcall GetFieldValue(int Index);
	virtual bool __fastcall GetHasConstraints(void);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	virtual void __fastcall SetDataSet(TDataSet* ADataSet);
	virtual void __fastcall SetFieldKind(TFieldKind Value);
	virtual void __fastcall SetFieldValue(int Index, const Variant &Value);
	virtual void __fastcall SetParentField(TObjectField* AField);
	void __fastcall SetUnNamed(bool Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TObjectField(Classes::TComponent* AOwner);
	__fastcall virtual ~TObjectField(void);
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TFields* Fields = {read=GetFields};
	__property Variant FieldValues[int Index] = {read=GetFieldValue, write=SetFieldValue/*, default*/};
	__property bool UnNamed = {read=FUnNamed, default=0};
	
__published:
	__property AnsiString ObjectType = {read=FObjectType, write=FObjectType};
};


class DELPHICLASS TADTField;
class PASCALIMPLEMENTATION TADTField : public TObjectField 
{
	typedef TObjectField inherited;
	
private:
	void __fastcall FieldsChanged(System::TObject* Sender);
	
protected:
	virtual int __fastcall GetSize(void);
	
public:
	__fastcall virtual TADTField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TObjectField.Destroy */ inline __fastcall virtual ~TADTField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TArrayField;
class PASCALIMPLEMENTATION TArrayField : public TObjectField 
{
	typedef TObjectField inherited;
	
protected:
	virtual void __fastcall Bind(bool Binding);
	virtual void __fastcall SetSize(int Value);
	
public:
	__fastcall virtual TArrayField(Classes::TComponent* AOwner);
	__property Size  = {default=10};
public:
	#pragma option push -w-inl
	/* TObjectField.Destroy */ inline __fastcall virtual ~TArrayField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetField;
class PASCALIMPLEMENTATION TDataSetField : public TObjectField 
{
	typedef TObjectField inherited;
	
private:
	TDataSet* FOwnedDataSet;
	TDataSet* FNestedDataSet;
	bool FIncludeObjectField;
	TDataSet* __fastcall GetNestedDataSet(void);
	void __fastcall AssignNestedDataSet(TDataSet* Value);
	void __fastcall SetIncludeObjectField(bool Value);
	
protected:
	virtual void __fastcall Bind(bool Binding);
	virtual bool __fastcall GetCanModify(void);
	virtual TFields* __fastcall GetFields(void);
	
public:
	__fastcall virtual TDataSetField(Classes::TComponent* AOwner);
	__fastcall virtual ~TDataSetField(void);
	__property TDataSet* NestedDataSet = {read=GetNestedDataSet};
	
__published:
	__property bool IncludeObjectField = {read=FIncludeObjectField, write=SetIncludeObjectField, default=0};
};


class DELPHICLASS TReferenceField;
class PASCALIMPLEMENTATION TReferenceField : public TDataSetField 
{
	typedef TDataSetField inherited;
	
private:
	AnsiString FReferenceTableName;
	
protected:
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TReferenceField(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property AnsiString ReferenceTableName = {read=FReferenceTableName, write=FReferenceTableName};
	__property Size  = {default=0};
public:
	#pragma option push -w-inl
	/* TDataSetField.Destroy */ inline __fastcall virtual ~TReferenceField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TVariantField;
class PASCALIMPLEMENTATION TVariantField : public TField 
{
	typedef TField inherited;
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual Fmtbcd::TBcd __fastcall GetAsBCD();
	virtual bool __fastcall GetAsBoolean(void);
	virtual System::TDateTime __fastcall GetAsDateTime(void);
	virtual Sqltimst::TSQLTimeStamp __fastcall GetAsSqlTimeStamp();
	virtual double __fastcall GetAsFloat(void);
	virtual int __fastcall GetAsInteger(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDefaultWidth(void);
	virtual void __fastcall SetAsBCD(const Fmtbcd::TBcd &Value);
	virtual void __fastcall SetAsBoolean(bool Value);
	virtual void __fastcall SetAsSqlTimeStamp(const Sqltimst::TSQLTimeStamp &Value);
	virtual void __fastcall SetAsDateTime(System::TDateTime Value);
	virtual void __fastcall SetAsFloat(double Value);
	virtual void __fastcall SetAsInteger(int Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TVariantField(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TVariantField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TInterfaceField;
class PASCALIMPLEMENTATION TInterfaceField : public TField 
{
	typedef TField inherited;
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	System::_di_IInterface __fastcall GetValue();
	virtual Variant __fastcall GetAsVariant();
	void __fastcall SetValue(const System::_di_IInterface Value);
	virtual void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual TInterfaceField(Classes::TComponent* AOwner);
	__property System::_di_IInterface Value = {read=GetValue, write=SetValue};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TInterfaceField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIDispatchField;
class PASCALIMPLEMENTATION TIDispatchField : public TInterfaceField 
{
	typedef TInterfaceField inherited;
	
protected:
	HIDESBASE _di_IDispatch __fastcall GetValue();
	HIDESBASE void __fastcall SetValue(const _di_IDispatch Value);
	
public:
	__fastcall virtual TIDispatchField(Classes::TComponent* AOwner);
	__property _di_IDispatch Value = {read=GetValue, write=SetValue};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TIDispatchField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGuidField;
class PASCALIMPLEMENTATION TGuidField : public TStringField 
{
	typedef TStringField inherited;
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	GUID __fastcall GetAsGuid();
	virtual int __fastcall GetDefaultWidth(void);
	void __fastcall SetAsGuid(const GUID &Value);
	
public:
	__fastcall virtual TGuidField(Classes::TComponent* AOwner);
	__property GUID AsGuid = {read=GetAsGuid, write=SetAsGuid};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TGuidField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAggregateField;
class PASCALIMPLEMENTATION TAggregateField : public TField 
{
	typedef TField inherited;
	
private:
	bool FActive;
	bool FCurrency;
	AnsiString FDisplayName;
	AnsiString FDisplayFormat;
	AnsiString FExpression;
	int FGroupingLevel;
	AnsiString FIndexName;
	void *FHandle;
	int FPrecision;
	TFieldType FResultType;
	virtual void __fastcall SetHandle(void * Value);
	void __fastcall SetActive(bool Value);
	virtual void * __fastcall GetHandle(void);
	void __fastcall SetGroupingLevel(int Value);
	void __fastcall SetIndexName(AnsiString Value);
	void __fastcall SetExpression(AnsiString Value);
	void __fastcall SetPrecision(int Value);
	void __fastcall SetCurrency(bool Value);
	
protected:
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual void __fastcall GetText(AnsiString &Text, bool DisplayText);
	void __fastcall Reset(void);
	void __fastcall SetDisplayFormat(const AnsiString Value);
	
public:
	__fastcall virtual TAggregateField(Classes::TComponent* AOwner);
	__property void * Handle = {read=GetHandle, write=SetHandle};
	__property TFieldType ResultType = {read=FResultType, write=FResultType, nodefault};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool currency = {read=FCurrency, write=SetCurrency, default=0};
	__property AnsiString DisplayName = {read=FDisplayName, write=FDisplayName};
	__property AnsiString DisplayFormat = {read=FDisplayFormat, write=SetDisplayFormat};
	__property AnsiString Expression = {read=FExpression, write=SetExpression};
	__property FieldKind  = {default=4};
	__property int GroupingLevel = {read=FGroupingLevel, write=SetGroupingLevel, default=0};
	__property AnsiString IndexName = {read=FIndexName, write=SetIndexName};
	__property int Precision = {read=FPrecision, write=SetPrecision, default=15};
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TAggregateField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataLink;
class DELPHICLASS TDataSource;
typedef void __fastcall (__closure *TDataChangeEvent)(System::TObject* Sender, TField* Field);

class PASCALIMPLEMENTATION TDataSource : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TDataSet* FDataSet;
	Classes::TList* FDataLinks;
	bool FEnabled;
	bool FAutoEdit;
	TDataSetState FState;
	Classes::TNotifyEvent FOnStateChange;
	TDataChangeEvent FOnDataChange;
	Classes::TNotifyEvent FOnUpdateData;
	void __fastcall AddDataLink(TDataLink* DataLink);
	void __fastcall DataEvent(TDataEvent Event, int Info);
	void __fastcall NotifyDataLinks(TDataEvent Event, int Info);
	void __fastcall NotifyLinkTypes(TDataEvent Event, int Info, bool LinkType);
	void __fastcall RemoveDataLink(TDataLink* DataLink);
	void __fastcall SetDataSet(TDataSet* ADataSet);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetState(TDataSetState Value);
	void __fastcall UpdateState(void);
	
protected:
	__property Classes::TList* DataLinks = {read=FDataLinks};
	
public:
	__fastcall virtual TDataSource(Classes::TComponent* AOwner);
	__fastcall virtual ~TDataSource(void);
	void __fastcall Edit(void);
	bool __fastcall IsLinkedTo(TDataSet* DataSet);
	__property TDataSetState State = {read=FState, nodefault};
	
__published:
	__property bool AutoEdit = {read=FAutoEdit, write=FAutoEdit, default=1};
	__property TDataSet* DataSet = {read=FDataSet, write=SetDataSet};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property Classes::TNotifyEvent OnStateChange = {read=FOnStateChange, write=FOnStateChange};
	__property TDataChangeEvent OnDataChange = {read=FOnDataChange, write=FOnDataChange};
	__property Classes::TNotifyEvent OnUpdateData = {read=FOnUpdateData, write=FOnUpdateData};
};


class PASCALIMPLEMENTATION TDataLink : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TDataSource* FDataSource;
	TDataLink* FNext;
	int FBufferCount;
	int FFirstRecord;
	bool FReadOnly;
	bool FActive;
	bool FVisualControl;
	bool FEditing;
	bool FUpdating;
	bool FDataSourceFixed;
	TDataSet* __fastcall GetDataSet(void);
	void __fastcall SetActive(bool Value);
	void __fastcall SetDataSource(TDataSource* ADataSource);
	void __fastcall SetEditing(bool Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall UpdateRange(void);
	void __fastcall UpdateState(void);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall CheckBrowseMode(void);
	virtual void __fastcall DataEvent(TDataEvent Event, int Info);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall FocusControl(TFieldRef Field);
	virtual int __fastcall GetActiveRecord(void);
	virtual bool __fastcall GetBOF(void);
	virtual int __fastcall GetBufferCount(void);
	virtual bool __fastcall GetEOF(void);
	virtual int __fastcall GetRecordCount(void);
	virtual void __fastcall LayoutChanged(void);
	virtual int __fastcall MoveBy(int Distance);
	virtual void __fastcall RecordChanged(TField* Field);
	virtual void __fastcall SetActiveRecord(int Value);
	virtual void __fastcall SetBufferCount(int Value);
	virtual void __fastcall UpdateData(void);
	__property bool VisualControl = {read=FVisualControl, write=FVisualControl, nodefault};
	
public:
	__fastcall TDataLink(void);
	__fastcall virtual ~TDataLink(void);
	bool __fastcall Edit(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	void __fastcall UpdateRecord(void);
	__property bool Active = {read=FActive, nodefault};
	__property int ActiveRecord = {read=GetActiveRecord, write=SetActiveRecord, nodefault};
	__property bool BOF = {read=GetBOF, nodefault};
	__property int BufferCount = {read=FBufferCount, write=SetBufferCount, nodefault};
	__property TDataSet* DataSet = {read=GetDataSet};
	__property TDataSource* DataSource = {read=FDataSource, write=SetDataSource};
	__property bool DataSourceFixed = {read=FDataSourceFixed, write=FDataSourceFixed, nodefault};
	__property bool Editing = {read=FEditing, nodefault};
	__property bool Eof = {read=GetEOF, nodefault};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, nodefault};
	__property int RecordCount = {read=GetRecordCount, nodefault};
};


class DELPHICLASS TDetailDataLink;
class PASCALIMPLEMENTATION TDetailDataLink : public TDataLink 
{
	typedef TDataLink inherited;
	
protected:
	virtual TDataSet* __fastcall GetDetailDataSet(void);
	
public:
	__property TDataSet* DetailDataSet = {read=GetDetailDataSet};
public:
	#pragma option push -w-inl
	/* TDataLink.Create */ inline __fastcall TDetailDataLink(void) : TDataLink() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataLink.Destroy */ inline __fastcall virtual ~TDetailDataLink(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMasterDataLink;
class PASCALIMPLEMENTATION TMasterDataLink : public TDetailDataLink 
{
	typedef TDetailDataLink inherited;
	
private:
	TDataSet* FDataSet;
	AnsiString FFieldNames;
	Classes::TList* FFields;
	Classes::TNotifyEvent FOnMasterChange;
	Classes::TNotifyEvent FOnMasterDisable;
	void __fastcall SetFieldNames(const AnsiString Value);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall CheckBrowseMode(void);
	virtual TDataSet* __fastcall GetDetailDataSet(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(TField* Field);
	
public:
	__fastcall TMasterDataLink(TDataSet* DataSet);
	__fastcall virtual ~TMasterDataLink(void);
	__property AnsiString FieldNames = {read=FFieldNames, write=SetFieldNames};
	__property Classes::TList* Fields = {read=FFields};
	__property Classes::TNotifyEvent OnMasterChange = {read=FOnMasterChange, write=FOnMasterChange};
	__property Classes::TNotifyEvent OnMasterDisable = {read=FOnMasterDisable, write=FOnMasterDisable};
};


class DELPHICLASS TDataSetDesigner;
class PASCALIMPLEMENTATION TDataSetDesigner : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TDataSet* FDataSet;
	bool FSaveActive;
	
public:
	__fastcall TDataSetDesigner(TDataSet* DataSet);
	__fastcall virtual ~TDataSetDesigner(void);
	void __fastcall BeginDesign(void);
	virtual void __fastcall DataEvent(TDataEvent Event, int Info);
	void __fastcall EndDesign(void);
	__property TDataSet* DataSet = {read=FDataSet};
};


class DELPHICLASS TCheckConstraint;
class PASCALIMPLEMENTATION TCheckConstraint : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FImportedConstraint;
	AnsiString FCustomConstraint;
	AnsiString FErrorMessage;
	bool FFromDictionary;
	void __fastcall SetImportedConstraint(const AnsiString Value);
	void __fastcall SetCustomConstraint(const AnsiString Value);
	void __fastcall SetErrorMessage(const AnsiString Value);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual AnsiString __fastcall GetDisplayName();
	
__published:
	__property AnsiString CustomConstraint = {read=FCustomConstraint, write=SetCustomConstraint};
	__property AnsiString ErrorMessage = {read=FErrorMessage, write=SetErrorMessage};
	__property bool FromDictionary = {read=FFromDictionary, write=FFromDictionary, nodefault};
	__property AnsiString ImportedConstraint = {read=FImportedConstraint, write=SetImportedConstraint};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TCheckConstraint(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TCheckConstraint(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCheckConstraints;
class PASCALIMPLEMENTATION TCheckConstraints : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TCheckConstraint* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TPersistent* FOwner;
	HIDESBASE TCheckConstraint* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TCheckConstraint* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TCheckConstraints(Classes::TPersistent* Owner);
	HIDESBASE TCheckConstraint* __fastcall Add(void);
	__property TCheckConstraint* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TCheckConstraints(void) { }
	#pragma option pop
	
};


typedef AnsiString TBlobData;

#pragma option push -b-
enum TParamType { ptUnknown, ptInput, ptOutput, ptInputOutput, ptResult };
#pragma option pop

typedef Set<TParamType, ptUnknown, ptResult>  TParamTypes;

class DELPHICLASS TParam;
class DELPHICLASS TParams;
class PASCALIMPLEMENTATION TParam : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	TParam* FParamRef;
	AnsiString FNativeStr;
	Variant FData;
	int FPrecision;
	int FNumericScale;
	bool FNull;
	AnsiString FName;
	TFieldType FDataType;
	bool FBound;
	TParamType FParamType;
	int FSize;
	TParam* __fastcall ParamRef(void);
	TDataSet* __fastcall GetDataSet(void);
	bool __fastcall IsParamStored(void);
	TFieldType __fastcall GetDataType(void);
	TParamType __fastcall GetParamType(void);
	void __fastcall SetParamType(TParamType Value);
	
protected:
	void __fastcall AssignParam(TParam* Param);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	Fmtbcd::TBcd __fastcall GetAsFMTBCD();
	System::Currency __fastcall GetAsBCD(void);
	bool __fastcall GetAsBoolean(void);
	System::TDateTime __fastcall GetAsDateTime(void);
	Sqltimst::TSQLTimeStamp __fastcall GetAsSQLTimeStamp();
	System::Currency __fastcall GetAsCurrency(void);
	double __fastcall GetAsFloat(void);
	int __fastcall GetAsInteger(void);
	AnsiString __fastcall GetAsMemo();
	AnsiString __fastcall GetAsString();
	Variant __fastcall GetAsVariant();
	bool __fastcall GetIsNull(void);
	bool __fastcall IsEqual(TParam* Value);
	void __fastcall SetAsBCD(const System::Currency Value);
	void __fastcall SetAsFMTBCD(const Fmtbcd::TBcd &Value);
	void __fastcall SetAsBlob(const AnsiString Value);
	void __fastcall SetAsBoolean(bool Value);
	void __fastcall SetAsCurrency(const System::Currency Value);
	void __fastcall SetAsDate(const System::TDateTime Value);
	void __fastcall SetAsDateTime(const System::TDateTime Value);
	void __fastcall SetAsSQLTimeStamp(const Sqltimst::TSQLTimeStamp &Value);
	void __fastcall SetAsFloat(const double Value);
	void __fastcall SetAsInteger(int Value);
	void __fastcall SetAsMemo(const AnsiString Value);
	void __fastcall SetAsString(const AnsiString Value);
	void __fastcall SetAsSmallInt(int Value);
	void __fastcall SetAsTime(const System::TDateTime Value);
	void __fastcall SetAsVariant(const Variant &Value);
	void __fastcall SetAsWord(int Value);
	void __fastcall SetDataType(TFieldType Value);
	void __fastcall SetText(const AnsiString Value);
	virtual AnsiString __fastcall GetDisplayName();
	__property TDataSet* DataSet = {read=GetDataSet};
	
public:
	__fastcall virtual TParam(Classes::TCollection* Collection)/* overload */;
	__fastcall TParam(TParams* AParams, TParamType AParamType)/* overload */;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall AssignField(TField* Field);
	void __fastcall AssignFieldValue(TField* Field, const Variant &Value);
	void __fastcall Clear(void);
	void __fastcall GetData(void * Buffer);
	int __fastcall GetDataSize(void);
	void __fastcall LoadFromFile(const AnsiString FileName, TBlobType BlobType);
	void __fastcall LoadFromStream(Classes::TStream* Stream, TBlobType BlobType);
	void __fastcall SetBlobData(void * Buffer, int Size);
	void __fastcall SetData(void * Buffer);
	__property System::Currency AsBCD = {read=GetAsBCD, write=SetAsBCD};
	__property Fmtbcd::TBcd AsFMTBCD = {read=GetAsFMTBCD, write=SetAsFMTBCD};
	__property AnsiString AsBlob = {read=GetAsString, write=SetAsBlob};
	__property bool AsBoolean = {read=GetAsBoolean, write=SetAsBoolean, nodefault};
	__property System::Currency AsCurrency = {read=GetAsCurrency, write=SetAsCurrency};
	__property System::TDateTime AsDate = {read=GetAsDateTime, write=SetAsDate};
	__property System::TDateTime AsDateTime = {read=GetAsDateTime, write=SetAsDateTime};
	__property double AsFloat = {read=GetAsFloat, write=SetAsFloat};
	__property int AsInteger = {read=GetAsInteger, write=SetAsInteger, nodefault};
	__property int AsSmallInt = {read=GetAsInteger, write=SetAsSmallInt, nodefault};
	__property Sqltimst::TSQLTimeStamp AsSQLTimeStamp = {read=GetAsSQLTimeStamp, write=SetAsSQLTimeStamp};
	__property AnsiString AsMemo = {read=GetAsMemo, write=SetAsMemo};
	__property AnsiString AsString = {read=GetAsString, write=SetAsString};
	__property System::TDateTime AsTime = {read=GetAsDateTime, write=SetAsTime};
	__property int AsWord = {read=GetAsInteger, write=SetAsWord, nodefault};
	__property bool Bound = {read=FBound, write=FBound, nodefault};
	__property bool IsNull = {read=GetIsNull, nodefault};
	__property AnsiString NativeStr = {read=FNativeStr, write=FNativeStr};
	__property AnsiString Text = {read=GetAsString, write=SetText};
	
__published:
	__property TFieldType DataType = {read=GetDataType, write=SetDataType, nodefault};
	__property int Precision = {read=FPrecision, write=FPrecision, default=0};
	__property int NumericScale = {read=FNumericScale, write=FNumericScale, default=0};
	__property AnsiString Name = {read=FName, write=FName};
	__property TParamType ParamType = {read=GetParamType, write=SetParamType, nodefault};
	__property int Size = {read=FSize, write=FSize, default=0};
	__property Variant Value = {read=GetAsVariant, write=SetAsVariant, stored=IsParamStored};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TParam(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TParams : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TParam* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TPersistent* FOwner;
	Variant __fastcall GetParamValue(const AnsiString ParamName);
	void __fastcall ReadBinaryData(Classes::TStream* Stream);
	void __fastcall SetParamValue(const AnsiString ParamName, const Variant &Value);
	HIDESBASE TParam* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TParam* Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	TDataSet* __fastcall GetDataSet(void);
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	__fastcall TParams(Classes::TPersistent* Owner)/* overload */;
	void __fastcall AssignValues(TParams* Value);
	__fastcall TParams(void)/* overload */;
	void __fastcall AddParam(TParam* Value);
	void __fastcall RemoveParam(TParam* Value);
	TParam* __fastcall CreateParam(TFieldType FldType, const AnsiString ParamName, TParamType ParamType);
	void __fastcall GetParamList(Classes::TList* List, const AnsiString ParamNames);
	bool __fastcall IsEqual(TParams* Value);
	AnsiString __fastcall ParseSQL(AnsiString SQL, bool DoCreate);
	TParam* __fastcall ParamByName(const AnsiString Value);
	TParam* __fastcall FindParam(const AnsiString Value);
	__property TParam* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property Variant ParamValues[AnsiString ParamName] = {read=GetParamValue, write=SetParamValue};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TParams(void) { }
	#pragma option pop
	
};


__interface IProviderSupport;
typedef System::DelphiInterface<IProviderSupport> _di_IProviderSupport;
__interface IProviderSupport  : public IInterface 
{
	
public:
	virtual void __fastcall PSEndTransaction(bool Commit) = 0 ;
	virtual void __fastcall PSExecute(void) = 0 ;
	virtual int __fastcall PSExecuteStatement(const AnsiString ASQL, TParams* AParams, void * ResultSet = (void *)(0x0)) = 0 ;
	virtual void __fastcall PSGetAttributes(Classes::TList* List) = 0 ;
	virtual TIndexDef* __fastcall PSGetDefaultOrder(void) = 0 ;
	virtual AnsiString __fastcall PSGetKeyFields(void) = 0 ;
	virtual TParams* __fastcall PSGetParams(void) = 0 ;
	virtual AnsiString __fastcall PSGetQuoteChar(void) = 0 ;
	virtual AnsiString __fastcall PSGetTableName(void) = 0 ;
	virtual TIndexDefs* __fastcall PSGetIndexDefs(TIndexOptions IndexTypes = (System::Set<TIndexOption, ixPrimary, ixNonMaintained> () << TIndexOption(0) << TIndexOption(1) << TIndexOption(2) << TIndexOption(3) << TIndexOption(4) << TIndexOption(5) )) = 0 ;
	virtual EUpdateError* __fastcall PSGetUpdateException(Sysutils::Exception* E, EUpdateError* Prev) = 0 ;
	virtual bool __fastcall PSInTransaction(void) = 0 ;
	virtual bool __fastcall PSIsSQLBased(void) = 0 ;
	virtual bool __fastcall PSIsSQLSupported(void) = 0 ;
	virtual void __fastcall PSReset(void) = 0 ;
	virtual void __fastcall PSSetParams(TParams* AParams) = 0 ;
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText) = 0 ;
	virtual void __fastcall PSStartTransaction(void) = 0 ;
	virtual bool __fastcall PSUpdateRecord(TUpdateKind UpdateKind, TDataSet* Delta) = 0 ;
};

typedef void *TBookmark;

typedef AnsiString TBookmarkStr;

#pragma option push -b-
enum TBookmarkFlag { bfCurrent, bfBOF, bfEOF, bfInserted };
#pragma option pop

typedef TBookmarkFlag *PBookmarkFlag;

typedef DynamicArray<char * >  TBufferList;

#pragma option push -b-
enum TGetMode { gmCurrent, gmNext, gmPrior };
#pragma option pop

#pragma option push -b-
enum TGetResult { grOK, grBOF, grEOF, grError };
#pragma option pop

#pragma option push -b-
enum DB__06 { rmExact, rmCenter };
#pragma option pop

typedef Set<DB__06, rmExact, rmCenter>  TResyncMode;

#pragma option push -b-
enum TDataAction { daFail, daAbort, daRetry };
#pragma option pop

#pragma option push -b-
enum TBlobStreamMode { bmRead, bmWrite, bmReadWrite };
#pragma option pop

#pragma option push -b-
enum TLocateOption { loCaseInsensitive, loPartialKey };
#pragma option pop

typedef Set<TLocateOption, loCaseInsensitive, loPartialKey>  TLocateOptions;

typedef void __fastcall (__closure *TDataOperation)(void);

typedef void __fastcall (__closure *TDataSetNotifyEvent)(TDataSet* DataSet);

typedef void __fastcall (__closure *TDataSetErrorEvent)(TDataSet* DataSet, EDatabaseError* E, TDataAction &Action);

#pragma option push -b-
enum TFilterOption { foCaseInsensitive, foNoPartialCompare };
#pragma option pop

typedef Set<TFilterOption, foCaseInsensitive, foNoPartialCompare>  TFilterOptions;

typedef void __fastcall (__closure *TFilterRecordEvent)(TDataSet* DataSet, bool &Accept);

struct TPacketAttribute;
typedef TPacketAttribute *PPacketAttribute;

struct TPacketAttribute
{
	AnsiString Name;
	OleVariant Value;
	bool IncludeInDelta;
} ;

typedef DynamicArray<Byte >  TBlobByteData;

#pragma option push -b-
enum TGroupPosInd { gbFirst, gbMiddle, gbLast };
#pragma option pop

typedef Set<TGroupPosInd, gbFirst, gbLast>  TGroupPosInds;

class PASCALIMPLEMENTATION TDataSet : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
public:
	Variant operator[](AnsiString FieldName) { return FieldValues[FieldName]; }
	
private:
	TFields* FFields;
	TFields* FAggFields;
	TFieldDefs* FFieldDefs;
	TFieldDefList* FFieldDefList;
	TFieldList* FFieldList;
	Classes::TList* FDataSources;
	TDataLink* FFirstDataLink;
	int FBufferCount;
	int FRecordCount;
	int FActiveRecord;
	int FCurrentRecord;
	DynamicArray<char * >  FBuffers;
	char *FCalcBuffer;
	int FBookmarkSize;
	int FCalcFieldsSize;
	TDataSetDesigner* FDesigner;
	int FDisableCount;
	int FBlobFieldCount;
	AnsiString FFilterText;
	int FBlockReadSize;
	TCheckConstraints* FConstraints;
	TDataSetField* FDataSetField;
	bool FIsUniDirectional;
	Classes::TList* FNestedDataSets;
	TMetaClass*FNestedDatasetClass;
	void *FReserved;
	int FFieldNoOfs;
	TFilterOptions FFilterOptions;
	TDataSetState FState;
	TDataEvent FEnableEvent;
	TDataSetState FDisableState;
	bool FBOF;
	bool FEOF;
	bool FModified;
	bool FStreamedActive;
	bool FInternalCalcFields;
	bool FFound;
	bool FDefaultFields;
	bool FAutoCalcFields;
	bool FFiltered;
	bool FObjectView;
	bool FSparseArrays;
	bool FInternalOpenComplete;
	TDataSetNotifyEvent FBeforeOpen;
	TDataSetNotifyEvent FAfterOpen;
	TDataSetNotifyEvent FBeforeClose;
	TDataSetNotifyEvent FAfterClose;
	TDataSetNotifyEvent FBeforeInsert;
	TDataSetNotifyEvent FAfterInsert;
	TDataSetNotifyEvent FBeforeEdit;
	TDataSetNotifyEvent FAfterEdit;
	TDataSetNotifyEvent FBeforePost;
	TDataSetNotifyEvent FAfterPost;
	TDataSetNotifyEvent FBeforeCancel;
	TDataSetNotifyEvent FAfterCancel;
	TDataSetNotifyEvent FBeforeDelete;
	TDataSetNotifyEvent FAfterDelete;
	TDataSetNotifyEvent FBeforeRefresh;
	TDataSetNotifyEvent FAfterRefresh;
	TDataSetNotifyEvent FBeforeScroll;
	TDataSetNotifyEvent FAfterScroll;
	TDataSetNotifyEvent FOnNewRecord;
	TDataSetNotifyEvent FOnCalcFields;
	TDataSetErrorEvent FOnEditError;
	TDataSetErrorEvent FOnPostError;
	TDataSetErrorEvent FOnDeleteError;
	TFilterRecordEvent FOnFilterRecord;
	void __fastcall AddDataSource(TDataSource* DataSource);
	void __fastcall AddRecord(const System::TVarRec * Values, const int Values_Size, bool Append);
	void __fastcall BeginInsertAppend(void);
	void __fastcall CheckCanModify(void);
	void __fastcall CheckOperation(TDataOperation Operation, TDataSetErrorEvent ErrorEvent);
	void __fastcall CheckParentState(void);
	void __fastcall CheckRequiredFields(void);
	void __fastcall DoInternalOpen(void);
	void __fastcall EndInsertAppend(void);
	bool __fastcall GetActive(void);
	char * __fastcall GetBuffer(int Index);
	int __fastcall GetFieldCount(void);
	Variant __fastcall GetFieldValue(const AnsiString FieldName);
	bool __fastcall GetFound(void);
	Classes::TList* __fastcall GetNestedDataSets(void);
	void __fastcall MoveBuffer(int CurIndex, int NewIndex);
	void __fastcall RemoveDataSource(TDataSource* DataSource);
	void __fastcall SetBufferCount(int Value);
	void __fastcall SetConstraints(TCheckConstraints* Value);
	void __fastcall SetFieldDefs(TFieldDefs* Value);
	void __fastcall SetFieldValue(const AnsiString FieldName, const Variant &Value);
	void __fastcall SetSparseArrays(bool Value);
	
protected:
	virtual void __fastcall PSEndTransaction(bool Commit);
	virtual void __fastcall PSExecute(void);
	virtual int __fastcall PSExecuteStatement(const AnsiString ASQL, TParams* AParams, void * ResultSet = (void *)(0x0));
	virtual void __fastcall PSGetAttributes(Classes::TList* List);
	virtual TIndexDef* __fastcall PSGetDefaultOrder(void);
	virtual AnsiString __fastcall PSGetKeyFields();
	virtual TParams* __fastcall PSGetParams(void);
	virtual AnsiString __fastcall PSGetQuoteChar();
	virtual AnsiString __fastcall PSGetTableName();
	virtual TIndexDefs* __fastcall PSGetIndexDefs(TIndexOptions IndexTypes);
	virtual EUpdateError* __fastcall PSGetUpdateException(Sysutils::Exception* E, EUpdateError* Prev);
	virtual bool __fastcall PSInTransaction(void);
	virtual bool __fastcall PSIsSQLBased(void);
	virtual bool __fastcall PSIsSQLSupported(void);
	virtual void __fastcall PSReset(void);
	virtual void __fastcall PSSetParams(TParams* AParams);
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText);
	virtual void __fastcall PSStartTransaction(void);
	virtual bool __fastcall PSUpdateRecord(TUpdateKind UpdateKind, TDataSet* Delta);
	virtual void __fastcall ResetAggField(TField* Field);
	void __fastcall BindFields(bool Binding);
	bool __fastcall BookmarkAvailable(void);
	virtual void __fastcall CalculateFields(char * Buffer);
	virtual void __fastcall CheckActive(void);
	void __fastcall CheckBiDirectional(void);
	virtual void __fastcall CheckFieldCompatibility(TField* Field, TFieldDef* FieldDef);
	virtual void __fastcall CheckInactive(void);
	virtual void __fastcall ClearBuffers(void);
	virtual void __fastcall ClearCalcFields(char * Buffer);
	virtual void __fastcall CloseBlob(TField* Field);
	virtual void __fastcall CloseCursor(void);
	virtual void __fastcall CreateFields(void);
	virtual TDataSet* __fastcall CreateNestedDataSet(TDataSetField* DataSetField);
	virtual void __fastcall DataConvert(TField* Field, void * Source, void * Dest, bool ToNative);
	virtual void __fastcall DataEvent(TDataEvent Event, int Info);
	virtual void __fastcall DefChanged(System::TObject* Sender);
	virtual void __fastcall DestroyFields(void);
	virtual void __fastcall DoAfterCancel(void);
	virtual void __fastcall DoAfterClose(void);
	virtual void __fastcall DoAfterDelete(void);
	virtual void __fastcall DoAfterEdit(void);
	virtual void __fastcall DoAfterInsert(void);
	virtual void __fastcall DoAfterOpen(void);
	virtual void __fastcall DoAfterPost(void);
	virtual void __fastcall DoAfterRefresh(void);
	virtual void __fastcall DoAfterScroll(void);
	virtual void __fastcall DoBeforeCancel(void);
	virtual void __fastcall DoBeforeClose(void);
	virtual void __fastcall DoBeforeDelete(void);
	virtual void __fastcall DoBeforeEdit(void);
	virtual void __fastcall DoBeforeInsert(void);
	virtual void __fastcall DoBeforeOpen(void);
	virtual void __fastcall DoBeforePost(void);
	virtual void __fastcall DoBeforeRefresh(void);
	virtual void __fastcall DoBeforeScroll(void);
	virtual void __fastcall DoOnCalcFields(void);
	virtual void __fastcall DoOnNewRecord(void);
	TField* __fastcall FieldByNumber(int FieldNo);
	virtual bool __fastcall FindRecord(bool Restart, bool GoForward);
	virtual void __fastcall FreeFieldBuffers(void);
	virtual Variant __fastcall GetAggregateValue(TField* Field);
	virtual int __fastcall GetAggRecordCount(TGroupPosInd Grp);
	virtual void __fastcall ActivateBuffers(void);
	virtual AnsiString __fastcall GetBookmarkStr();
	virtual void __fastcall GetCalcFields(char * Buffer);
	virtual bool __fastcall GetCanModify(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual TDataSource* __fastcall GetDataSource(void);
	virtual TMetaClass* __fastcall GetFieldClass(TFieldType FieldType);
	virtual AnsiString __fastcall GetFieldFullName(TField* Field);
	virtual Variant __fastcall GetStateFieldValue(TDataSetState State, TField* Field);
	virtual bool __fastcall GetIsIndexField(TField* Field);
	TIndexDefs* __fastcall GetIndexDefs(TIndexDefs* IndexDefs, TIndexOptions IndexTypes);
	virtual int __fastcall GetNextRecords(void);
	virtual bool __fastcall GetNextRecord(void);
	virtual int __fastcall GetPriorRecords(void);
	virtual bool __fastcall GetPriorRecord(void);
	virtual int __fastcall GetRecordCount(void);
	virtual int __fastcall GetRecNo(void);
	virtual void __fastcall InitFieldDefs(void);
	void __fastcall InitFieldDefsFromFields(void);
	virtual void __fastcall InitRecord(char * Buffer);
	virtual void __fastcall InternalCancel(void);
	virtual void __fastcall InternalEdit(void);
	virtual void __fastcall InternalInsert(void);
	virtual void __fastcall InternalRefresh(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall OpenCursor(bool InfoQuery = false);
	void __fastcall OpenCursorComplete(void);
	void __fastcall OpenParentDataSet(TDataSet* ParentDataSet);
	virtual void __fastcall RefreshInternalCalcFields(char * Buffer);
	void __fastcall RestoreState(const TDataSetState Value);
	virtual void __fastcall BlockReadNext(void);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetBookmarkStr(const AnsiString Value);
	virtual void __fastcall SetBlockReadSize(int Value);
	virtual void __fastcall SetBufListSize(int Value);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	virtual void __fastcall SetCurrentRecord(int Index);
	virtual void __fastcall SetDataSetField(const TDataSetField* Value);
	void __fastcall SetDefaultFields(const bool Value);
	virtual void __fastcall SetFiltered(bool Value);
	virtual void __fastcall SetFilterOptions(TFilterOptions Value);
	virtual void __fastcall SetFilterText(const AnsiString Value);
	void __fastcall SetFound(const bool Value);
	void __fastcall SetModified(bool Value);
	virtual void __fastcall SetName(const AnsiString Value);
	void __fastcall SetObjectView(const bool Value);
	virtual void __fastcall SetOnFilterRecord(const TFilterRecordEvent Value);
	virtual void __fastcall SetRecNo(int Value);
	void __fastcall SetState(TDataSetState Value);
	virtual void __fastcall SetStateFieldValue(TDataSetState State, TField* Field, const Variant &Value);
	TDataSetState __fastcall SetTempState(const TDataSetState Value);
	void __fastcall SetUniDirectional(const bool Value);
	char * __fastcall TempBuffer(void);
	void __fastcall UpdateBufferCount(void);
	virtual void __fastcall UpdateIndexDefs(void);
	__property int ActiveRecord = {read=FActiveRecord, nodefault};
	__property int CurrentRecord = {read=FCurrentRecord, nodefault};
	__property int BlobFieldCount = {read=FBlobFieldCount, nodefault};
	__property int BookmarkSize = {read=FBookmarkSize, write=FBookmarkSize, nodefault};
	__property char * Buffers[int Index] = {read=GetBuffer};
	__property int BufferCount = {read=FBufferCount, nodefault};
	__property char * CalcBuffer = {read=FCalcBuffer};
	__property int CalcFieldsSize = {read=FCalcFieldsSize, nodefault};
	__property TCheckConstraints* Constraints = {read=FConstraints, write=SetConstraints};
	__property int FieldNoOfs = {read=FFieldNoOfs, write=FFieldNoOfs, nodefault};
	__property bool InternalCalcFields = {read=FInternalCalcFields, nodefault};
	__property Classes::TList* NestedDataSets = {read=GetNestedDataSets};
	__property TMetaClass* NestedDataSetClass = {read=FNestedDatasetClass, write=FNestedDatasetClass};
	__property void * Reserved = {read=FReserved, write=FReserved};
	virtual char * __fastcall AllocRecordBuffer(void);
	virtual void __fastcall FreeRecordBuffer(char * &Buffer);
	virtual void __fastcall GetBookmarkData(char * Buffer, void * Data);
	virtual TBookmarkFlag __fastcall GetBookmarkFlag(char * Buffer);
	virtual Word __fastcall GetRecordSize(void);
	virtual void __fastcall InternalAddRecord(void * Buffer, bool Append);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalFirst(void);
	virtual void __fastcall InternalGotoBookmark(void * Bookmark);
	virtual void __fastcall InternalInitRecord(char * Buffer);
	virtual void __fastcall InternalLast(void);
	virtual void __fastcall InternalPost(void);
	virtual void __fastcall InternalSetToRecord(char * Buffer);
	virtual void __fastcall SetBookmarkFlag(char * Buffer, TBookmarkFlag Value);
	virtual void __fastcall SetBookmarkData(char * Buffer, void * Data);
	virtual void __fastcall SetFieldData(TField* Field, void * Buffer)/* overload */;
	virtual void __fastcall SetFieldData(TField* Field, void * Buffer, bool NativeFormat)/* overload */;
	virtual TGetResult __fastcall GetRecord(char * Buffer, TGetMode GetMode, bool DoCheck) = 0 ;
	virtual void __fastcall InternalClose(void) = 0 ;
	virtual void __fastcall InternalHandleException(void) = 0 ;
	virtual void __fastcall InternalInitFieldDefs(void) = 0 ;
	virtual void __fastcall InternalOpen(void) = 0 ;
	virtual bool __fastcall IsCursorOpen(void) = 0 ;
	
public:
	__fastcall virtual TDataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TDataSet(void);
	char * __fastcall ActiveBuffer(void);
	void __fastcall Append(void);
	void __fastcall AppendRecord(const System::TVarRec * Values, const int Values_Size);
	virtual bool __fastcall BookmarkValid(void * Bookmark);
	virtual void __fastcall Cancel(void);
	void __fastcall CheckBrowseMode(void);
	void __fastcall ClearFields(void);
	void __fastcall Close(void);
	bool __fastcall ControlsDisabled(void);
	virtual int __fastcall CompareBookmarks(void * Bookmark1, void * Bookmark2);
	virtual Classes::TStream* __fastcall CreateBlobStream(TField* Field, TBlobStreamMode Mode);
	void __fastcall CursorPosChanged(void);
	void __fastcall Delete(void);
	void __fastcall DisableControls(void);
	void __fastcall Edit(void);
	void __fastcall EnableControls(void);
	TField* __fastcall FieldByName(const AnsiString FieldName);
	TField* __fastcall FindField(const AnsiString FieldName);
	bool __fastcall FindFirst(void);
	bool __fastcall FindLast(void);
	bool __fastcall FindNext(void);
	bool __fastcall FindPrior(void);
	void __fastcall First(void);
	virtual void __fastcall FreeBookmark(void * Bookmark);
	virtual void * __fastcall GetBookmark(void);
	virtual bool __fastcall GetCurrentRecord(char * Buffer);
	virtual void __fastcall GetDetailDataSets(Classes::TList* List);
	virtual void __fastcall GetDetailLinkFields(Classes::TList* MasterFields, Classes::TList* DetailFields);
	virtual int __fastcall GetBlobFieldData(int FieldNo, TBlobByteData &Buffer);
	virtual bool __fastcall GetFieldData(TField* Field, void * Buffer)/* overload */;
	virtual bool __fastcall GetFieldData(int FieldNo, void * Buffer)/* overload */;
	virtual bool __fastcall GetFieldData(TField* Field, void * Buffer, bool NativeFormat)/* overload */;
	void __fastcall GetFieldList(Classes::TList* List, const AnsiString FieldNames);
	void __fastcall GetFieldNames(Classes::TStrings* List);
	void __fastcall GotoBookmark(void * Bookmark);
	HIDESBASE void __fastcall Insert(void);
	void __fastcall InsertRecord(const System::TVarRec * Values, const int Values_Size);
	bool __fastcall IsEmpty(void);
	bool __fastcall IsLinkedTo(TDataSource* DataSource);
	virtual bool __fastcall IsSequenced(void);
	void __fastcall Last(void);
	virtual bool __fastcall Locate(const AnsiString KeyFields, const Variant &KeyValues, TLocateOptions Options);
	virtual Variant __fastcall Lookup(const AnsiString KeyFields, const Variant &KeyValues, const AnsiString ResultFields);
	int __fastcall MoveBy(int Distance);
	void __fastcall Next(void);
	void __fastcall Open(void);
	virtual void __fastcall Post(void);
	void __fastcall Prior(void);
	void __fastcall Refresh(void);
	virtual void __fastcall Resync(TResyncMode Mode);
	void __fastcall SetFields(const System::TVarRec * Values, const int Values_Size);
	virtual int __fastcall Translate(char * Src, char * Dest, bool ToOem);
	void __fastcall UpdateCursorPos(void);
	void __fastcall UpdateRecord(void);
	virtual TUpdateStatus __fastcall UpdateStatus(void);
	__property TFields* AggFields = {read=FAggFields};
	__property bool Bof = {read=FBOF, nodefault};
	__property AnsiString Bookmark = {read=GetBookmarkStr, write=SetBookmarkStr};
	__property bool CanModify = {read=GetCanModify, nodefault};
	__property TDataSetField* DataSetField = {read=FDataSetField, write=SetDataSetField};
	__property TDataSource* DataSource = {read=GetDataSource};
	__property bool DefaultFields = {read=FDefaultFields, nodefault};
	__property TDataSetDesigner* Designer = {read=FDesigner};
	__property bool Eof = {read=FEOF, nodefault};
	__property int BlockReadSize = {read=FBlockReadSize, write=SetBlockReadSize, nodefault};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TFieldDefs* FieldDefs = {read=FFieldDefs, write=SetFieldDefs};
	__property TFieldDefList* FieldDefList = {read=FFieldDefList};
	__property TFields* Fields = {read=FFields};
	__property TFieldList* FieldList = {read=FFieldList};
	__property Variant FieldValues[AnsiString FieldName] = {read=GetFieldValue, write=SetFieldValue/*, default*/};
	__property bool Found = {read=GetFound, nodefault};
	__property bool IsUniDirectional = {read=FIsUniDirectional, default=0};
	__property bool Modified = {read=FModified, nodefault};
	__property bool ObjectView = {read=FObjectView, write=SetObjectView, nodefault};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property int RecNo = {read=GetRecNo, write=SetRecNo, nodefault};
	__property Word RecordSize = {read=GetRecordSize, nodefault};
	__property bool SparseArrays = {read=FSparseArrays, write=SetSparseArrays, nodefault};
	__property TDataSetState State = {read=FState, nodefault};
	__property AnsiString Filter = {read=FFilterText, write=SetFilterText};
	__property bool Filtered = {read=FFiltered, write=SetFiltered, default=0};
	__property TFilterOptions FilterOptions = {read=FFilterOptions, write=SetFilterOptions, default=0};
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property bool AutoCalcFields = {read=FAutoCalcFields, write=FAutoCalcFields, default=1};
	__property TDataSetNotifyEvent BeforeOpen = {read=FBeforeOpen, write=FBeforeOpen};
	__property TDataSetNotifyEvent AfterOpen = {read=FAfterOpen, write=FAfterOpen};
	__property TDataSetNotifyEvent BeforeClose = {read=FBeforeClose, write=FBeforeClose};
	__property TDataSetNotifyEvent AfterClose = {read=FAfterClose, write=FAfterClose};
	__property TDataSetNotifyEvent BeforeInsert = {read=FBeforeInsert, write=FBeforeInsert};
	__property TDataSetNotifyEvent AfterInsert = {read=FAfterInsert, write=FAfterInsert};
	__property TDataSetNotifyEvent BeforeEdit = {read=FBeforeEdit, write=FBeforeEdit};
	__property TDataSetNotifyEvent AfterEdit = {read=FAfterEdit, write=FAfterEdit};
	__property TDataSetNotifyEvent BeforePost = {read=FBeforePost, write=FBeforePost};
	__property TDataSetNotifyEvent AfterPost = {read=FAfterPost, write=FAfterPost};
	__property TDataSetNotifyEvent BeforeCancel = {read=FBeforeCancel, write=FBeforeCancel};
	__property TDataSetNotifyEvent AfterCancel = {read=FAfterCancel, write=FAfterCancel};
	__property TDataSetNotifyEvent BeforeDelete = {read=FBeforeDelete, write=FBeforeDelete};
	__property TDataSetNotifyEvent AfterDelete = {read=FAfterDelete, write=FAfterDelete};
	__property TDataSetNotifyEvent BeforeScroll = {read=FBeforeScroll, write=FBeforeScroll};
	__property TDataSetNotifyEvent AfterScroll = {read=FAfterScroll, write=FAfterScroll};
	__property TDataSetNotifyEvent BeforeRefresh = {read=FBeforeRefresh, write=FBeforeRefresh};
	__property TDataSetNotifyEvent AfterRefresh = {read=FAfterRefresh, write=FAfterRefresh};
	__property TDataSetNotifyEvent OnCalcFields = {read=FOnCalcFields, write=FOnCalcFields};
	__property TDataSetErrorEvent OnDeleteError = {read=FOnDeleteError, write=FOnDeleteError};
	__property TDataSetErrorEvent OnEditError = {read=FOnEditError, write=FOnEditError};
	__property TFilterRecordEvent OnFilterRecord = {read=FOnFilterRecord, write=SetOnFilterRecord};
	__property TDataSetNotifyEvent OnNewRecord = {read=FOnNewRecord, write=FOnNewRecord};
	__property TDataSetErrorEvent OnPostError = {read=FOnPostError, write=FOnPostError};
private:
	void *__IProviderSupport;	/* Db::IProviderSupport */
	
public:
	operator IProviderSupport*(void) { return (IProviderSupport*)&__IProviderSupport; }
	
};


struct TDateTimeRec
{
	
	union
	{
		struct 
		{
			TDateTimeAlias DateTime;
			
		};
		struct 
		{
			int Time;
			
		};
		struct 
		{
			int Date;
			
		};
		
	};
} ;

typedef AnsiString DB__26[38];

#pragma option push -b-
enum TDBScreenCursor { dcrDefault, dcrHourGlass, dcrSQLWait, dcrOther };
#pragma option pop

__interface IDBScreen;
typedef System::DelphiInterface<IDBScreen> _di_IDBScreen;
__interface INTERFACE_UUID("{29A1C508-6ADC-44CD-88DE-4F51B25D5995}") IDBScreen  : public IInterface 
{
	
public:
	virtual TDBScreenCursor __fastcall GetCursor(void) = 0 ;
	virtual void __fastcall SetCursor(TDBScreenCursor Cursor) = 0 ;
	__property TDBScreenCursor Cursor = {read=GetCursor, write=SetCursor};
};

__interface IDBApplication;
typedef System::DelphiInterface<IDBApplication> _di_IDBApplication;
__interface INTERFACE_UUID("{FAA0DF76-EC6A-48AA-9754-2D36DF815C0D}") IDBApplication  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetTitle(void) = 0 ;
	virtual void __fastcall ProcessMessages(void) = 0 ;
	virtual void __fastcall SetTitle(const AnsiString Value) = 0 ;
	__property AnsiString Title = {read=GetTitle, write=SetTitle};
};

__interface IDBSession;
typedef System::DelphiInterface<IDBSession> _di_IDBSession;
__interface INTERFACE_UUID("{CC2448FB-B672-4BA2-93F7-77CBEDA815FE}") IDBSession  : public IInterface 
{
	
public:
	virtual void __fastcall AddPassword(const AnsiString APassword) = 0 ;
	virtual void __fastcall RemovePassword(const AnsiString APassword) = 0 ;
	virtual void __fastcall RemoveAllPasswords(void) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
#define ftNonTextTypes (System::Set<TFieldType, ftUnknown, ftFMTBcd> () << TFieldType(12) << TFieldType(13) << TFieldType(15) << TFieldType(16) << TFieldType(17) << TFieldType(18) << TFieldType(19) << TFieldType(20) << TFieldType(21) << TFieldType(22) << TFieldType(26) << TFieldType(27) << TFieldType(28) << TFieldType(29) )
#define ftFixedSizeTypes (System::Set<TFieldType, ftUnknown, ftFMTBcd> () << TFieldType(2) << TFieldType(3) << TFieldType(4) << TFieldType(5) << TFieldType(6) << TFieldType(7) << TFieldType(9) << TFieldType(10) << TFieldType(11) << TFieldType(14) << TFieldType(25) << TFieldType(34) << TFieldType(35) << TFieldType(36) << TFieldType(37) << TFieldType(38) << TFieldType(39) )
#define dsEditModes (System::Set<TDataSetState, dsInactive, dsOpening> () << TDataSetState(2) << TDataSetState(3) << TDataSetState(4) )
#define dsWriteModes (System::Set<TDataSetState, dsInactive, dsOpening> () << TDataSetState(2) << TDataSetState(3) << TDataSetState(4) << TDataSetState(5) << TDataSetState(6) << TDataSetState(7) << TDataSetState(11) )
extern PACKAGE TMetaClass*DefaultFieldClasses[38];
extern PACKAGE AnsiString FieldTypeNames[38];
extern PACKAGE Word FieldTypeVarMap[38];
#define ObjectFieldTypes (System::Set<TFieldType, ftUnknown, ftFMTBcd> () << TFieldType(26) << TFieldType(27) << TFieldType(28) << TFieldType(29) )
static const Word dsMaxStringSize = 0x2000;
extern PACKAGE void __fastcall (*RegisterFieldsProc)(TMetaClass* * FieldClassess, const int FieldClassess_Size);
extern PACKAGE bool __fastcall (*LoginDialogProc)(const AnsiString ADatabaseName, AnsiString &AUserName, AnsiString &APassword);
extern PACKAGE bool __fastcall (*LoginDialogExProc)(const AnsiString ADatabaseName, AnsiString &AUserName, AnsiString &APassword, bool NameReadOnly);
extern PACKAGE bool __fastcall (*RemoteLoginDialogProc)(AnsiString &AUserName, AnsiString &APassword);
extern PACKAGE void __fastcall (*ScreenCursorProc)(const int CurIndex);
extern PACKAGE bool __fastcall (*PasswordDialog)(const _di_IDBSession ASession);
extern PACKAGE _di_IDBScreen DBScreen;
extern PACKAGE _di_IDBApplication DBApplication;
extern PACKAGE void __fastcall DatabaseError(const AnsiString Message, Classes::TComponent* Component = (Classes::TComponent*)(0x0));
extern PACKAGE void __fastcall DatabaseErrorFmt(const AnsiString Message, const System::TVarRec * Args, const int Args_Size, Classes::TComponent* Component = (Classes::TComponent*)(0x0));
extern PACKAGE TField* __fastcall GetFieldProperty(TDataSet* DataSet, Classes::TComponent* Control, const AnsiString FieldName);
extern PACKAGE void __fastcall DisposeMem(void *Buffer, int Size);
extern PACKAGE bool __fastcall BuffersEqual(void * Buf1, void * Buf2, int Size);
extern PACKAGE AnsiString __fastcall ExtractFieldName(const AnsiString Fields, int &Pos);
extern PACKAGE void __fastcall RegisterFields(TMetaClass* * FieldClasses, const int FieldClasses_Size);
extern PACKAGE TFieldType __fastcall VarTypeToDataType(int VarType);

}	/* namespace Db */
using namespace Db;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DB
