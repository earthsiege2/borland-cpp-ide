// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBAdapt.pas' rev: 6.00

#ifndef DBAdaptHPP
#define DBAdaptHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebAdapt.hpp>	// Pascal unit
#include <AdaptReq.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <WebContnrs.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbadapt
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TDataSetAdapterRequestParamOption { poLocateParams, poCurrentPage };
#pragma option pop

typedef Set<TDataSetAdapterRequestParamOption, poLocateParams, poCurrentPage>  TDataSetAdapterRequestParamOptions;

#pragma option push -b-
enum TDataSetAdapterMode { amInsert, amEdit, amBrowse, amQuery };
#pragma option pop

typedef Set<TDataSetAdapterMode, amInsert, amQuery>  TDataSetAdapterModes;

typedef AnsiString DBAdapt__1[4];

class DELPHICLASS TLocateParams;
class DELPHICLASS TLocateParamsList;
class PASCALIMPLEMENTATION TLocateParams : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString operator[](int I) { return Items[I]; }
	
private:
	AnsiString FAdapterName;
	Classes::TStrings* FParams;
	int __fastcall GetCount(void);
	AnsiString __fastcall GetParamName(int I);
	AnsiString __fastcall GetParamValue(int I);
	AnsiString __fastcall GetItem(int I);
	
public:
	__fastcall TLocateParams(TLocateParamsList* AList);
	__fastcall virtual ~TLocateParams(void);
	__property AnsiString AdapterName = {read=FAdapterName, write=FAdapterName};
	__property int Count = {read=GetCount, nodefault};
	void __fastcall AddParam(const AnsiString ANameValue)/* overload */;
	void __fastcall AddParam(const AnsiString AName, const AnsiString AValue)/* overload */;
	__property AnsiString ParamNames[int I] = {read=GetParamName};
	__property AnsiString ParamValues[int I] = {read=GetParamValue};
	__property AnsiString Items[int I] = {read=GetItem/*, default*/};
};


class PASCALIMPLEMENTATION TLocateParamsList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TLocateParams* operator[](int I) { return Items[I]; }
	
private:
	Contnrs::TObjectList* FList;
	int __fastcall GetCount(void);
	TLocateParams* __fastcall GetItem(int I);
	
public:
	__fastcall TLocateParamsList(void);
	__fastcall virtual ~TLocateParamsList(void);
	void __fastcall Clear(void);
	TLocateParams* __fastcall Add(void);
	__property int Count = {read=GetCount, nodefault};
	__property TLocateParams* Items[int I] = {read=GetItem/*, default*/};
	TLocateParams* __fastcall ItemByAdapterName(const AnsiString AName);
};


__interface IKeyParams;
typedef System::DelphiInterface<IKeyParams> _di_IKeyParams;
__interface IKeyParams  : public IInterface 
{
	
public:
	virtual int __fastcall Count(void) = 0 ;
	virtual AnsiString __fastcall GetName(int I) = 0 ;
	virtual AnsiString __fastcall GetValue(int I) = 0 ;
	__property AnsiString Names[int I] = {read=GetName};
	__property AnsiString Values[int I] = {read=GetValue};
};

__interface IGetDataSetKeyName;
typedef System::DelphiInterface<IGetDataSetKeyName> _di_IGetDataSetKeyName;
__interface INTERFACE_UUID("{A9F1BBDE-9B0A-49E6-AFB9-C19E52A84E83}") IGetDataSetKeyName  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetKeyName(void) = 0 ;
	__property AnsiString KeyName = {read=GetKeyName};
};

__interface IAdapterDataSetComponent;
typedef System::DelphiInterface<IAdapterDataSetComponent> _di_IAdapterDataSetComponent;
__interface INTERFACE_UUID("{D62DBBC1-2C40-11D4-A46E-00C04F6BB853}") IAdapterDataSetComponent  : public IInterface 
{
	
public:
	virtual Db::TDataSet* __fastcall GetDataSet(void) = 0 ;
	virtual void __fastcall SetDataSet(Db::TDataSet* Value) = 0 ;
	__property Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
};

__interface IPrepareDataSet;
typedef System::DelphiInterface<IPrepareDataSet> _di_IPrepareDataSet;
__interface INTERFACE_UUID("{444E2D2E-F1A6-485D-B0E3-1CF925A4713B}") IPrepareDataSet  : public IInterface 
{
	
public:
	virtual void __fastcall PrepareDataSet(void) = 0 ;
};

class DELPHICLASS TCustomDataSetAdapter;
class PASCALIMPLEMENTATION TCustomDataSetAdapter : public Webadapt::TDefaultFieldsPagedAdapter 
{
	typedef Webadapt::TDefaultFieldsPagedAdapter inherited;
	
private:
	Db::TDataSet* FDataSet;
	Db::TDataLink* FDesignerDataLink;
	TLocateParamsList* FLocateParamsList;
	Classes::TNotifyEvent FOnPrepareDataSet;
	bool FDataSetPrepared;
	TDataSetAdapterMode FMode;
	int FDataSetRecNo;
	bool FInIterator;
	TCustomDataSetAdapter* FMasterAdapter;
	Contnrs::TComponentList* FDetailAdapters;
	TCustomDataSetAdapter* FAdapterRowNotFound;
	bool FInDefaultMode;
	TDataSetAdapterMode __fastcall GetMode(void);
	void __fastcall CreateDataLink(void);
	void __fastcall SetMasterAdapter(const TCustomDataSetAdapter* Value);
	void __fastcall SetInDefaultMode(const bool Value);
	
protected:
	virtual void __fastcall ImplSetEchoActionFieldValues(bool AValue);
	virtual TDataSetAdapterMode __fastcall GetDefaultMode(void);
	Contnrs::TComponentList* __fastcall GetMasterDetailAdapters(void);
	void __fastcall GetKeyParamStrings(Classes::TStrings* AValues);
	bool __fastcall LocateKeyParams(_di_IKeyParams AParams);
	bool __fastcall LocateRequestRecord(Adaptreq::_di_IActionRequest AActionRequest);
	virtual void __fastcall OnDataSetStateChange(System::TObject* Sender);
	virtual bool __fastcall GetNextRecord(void);
	virtual bool __fastcall GetFirstRecord(void);
	virtual bool __fastcall GetEOF(void);
	virtual int __fastcall GetRecordIndex(void);
	virtual int __fastcall GetRecordCount(void);
	bool __fastcall FullyQualifyInputNames(void);
	virtual int __fastcall ImplGetIteratorIndex(void);
	virtual bool __fastcall ImplInIterator(void);
	virtual void __fastcall SetMode(const TDataSetAdapterMode Value);
	virtual Webadapt::TAdapterHiddenFieldOptions __fastcall GetHiddenFieldOptions(void);
	virtual void __fastcall AddDefaultFields(Webcomp::TWebComponentList* AComponents);
	virtual void __fastcall AddDefaultActions(Webcomp::TWebComponentList* AComponents);
	AnsiString __fastcall GetKeyFields();
	Db::_di_IProviderSupport __fastcall GetProviderSupport();
	void __fastcall GetKeyParams(TLocateParamsList* AParams, bool ARecurse);
	virtual void __fastcall UpdateFieldsValidateValues(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual bool __fastcall UpdateFieldsGetAnyChanges(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual void __fastcall UpdateFieldsUpdateValues(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual void __fastcall UpdateFieldsExecuteValues(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	void __fastcall GetDesigntimeWarnings(Sitecomp::TAbstractDesigntimeWarnings* AWarnings);
	virtual bool __fastcall ImplCanAddFieldClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddActionClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall ImplNotifyDeactivate(void);
	void __fastcall GetAdapterModeNames(Classes::TStrings* AStrings);
	void __fastcall GetRecordKeys(Classes::TStrings* AValues, bool &AFullyQualify);
	virtual void __fastcall ImplGetRecordKeys(Classes::TStrings* AValues, bool &AFullyQualify);
	AnsiString __fastcall GetAdapterMode();
	void __fastcall SetAdapterMode(const AnsiString AValue);
	void __fastcall RestoreDefaultAdapterMode(void);
	bool __fastcall GetNeedAdapterMode(void);
	Db::TDataSet* __fastcall GetDataSet(void);
	virtual void __fastcall ImplGetFieldsList(Classes::TStrings* AList);
	virtual void __fastcall ImplGetActionsList(Classes::TStrings* AList);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SetDataSet(Db::TDataSet* ADataSet);
	virtual void __fastcall PrepareDataSet(void);
	__property bool DataSetPrepared = {read=FDataSetPrepared, write=FDataSetPrepared, nodefault};
	__property TCustomDataSetAdapter* AdapterRowNotFound = {read=FAdapterRowNotFound, write=FAdapterRowNotFound};
	
public:
	TDataSetAdapterMode __fastcall StringToMode(const AnsiString AValue);
	virtual void __fastcall ExtractRequestParams(System::_di_IInterface ARequest);
	virtual void __fastcall EncodeActionParams(Sitecomp::_di_IAdapterItemRequestParams AParams);
	void __fastcall ExtractRequestParamsFlags(System::_di_IInterface ARequest, TDataSetAdapterRequestParamOptions AOptions);
	void __fastcall EncodeActionParamsFlags(Sitecomp::_di_IAdapterItemRequestParams AParams, TDataSetAdapterRequestParamOptions AOptions);
	bool __fastcall Locate(void);
	bool __fastcall SilentLocate(TLocateParamsList* AParams, bool ARecurse);
	void __fastcall ApplyAdapterMode(Adaptreq::_di_IActionRequest AActionRequest);
	bool __fastcall LocateAndApply(Adaptreq::_di_IActionRequest AActionRequest);
	__fastcall virtual TCustomDataSetAdapter(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDataSetAdapter(void);
	void __fastcall RaiseFieldNotFound(const AnsiString AFieldName);
	void __fastcall RaiseFieldChangedByAnotherUser(const AnsiString AFieldName);
	void __fastcall RaiseRowNotFound(void);
	void __fastcall RaiseNilDataSet(void);
	__property Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
	__property bool InDefaultMode = {read=FInDefaultMode, write=SetInDefaultMode, nodefault};
	__property TDataSetAdapterMode Mode = {read=GetMode, write=SetMode, nodefault};
	__property TLocateParamsList* LocateParamsList = {read=FLocateParamsList};
	__property Classes::TNotifyEvent OnPrepareDataSet = {read=FOnPrepareDataSet, write=FOnPrepareDataSet};
	__property Contnrs::TComponentList* DetailAdapters = {read=FDetailAdapters};
	__property TCustomDataSetAdapter* MasterAdapter = {read=FMasterAdapter, write=SetMasterAdapter};
private:
	void *__IAdapterMode;	/* Sitecomp::IAdapterMode */
	void *__IAdapterDataSetComponent;	/* Dbadapt::IAdapterDataSetComponent */
	void *__IGetDesigntimeWarnings;	/* Sitecomp::IGetDesigntimeWarnings */
	void *__IGetAdapterModeNames;	/* Webadapt::IGetAdapterModeNames */
	void *__IGetRecordKeys;	/* Webadapt::IGetRecordKeys */
	void *__IFullyQualifyInputNames;	/* Webadapt::IFullyQualifyInputNames */
	
public:
	operator IFullyQualifyInputNames*(void) { return (IFullyQualifyInputNames*)&__IFullyQualifyInputNames; }
	operator IGetRecordKeys*(void) { return (IGetRecordKeys*)&__IGetRecordKeys; }
	operator IGetAdapterModeNames*(void) { return (IGetAdapterModeNames*)&__IGetAdapterModeNames; }
	operator IGetDesigntimeWarnings*(void) { return (IGetDesigntimeWarnings*)&__IGetDesigntimeWarnings; }
	operator IAdapterDataSetComponent*(void) { return (IAdapterDataSetComponent*)&__IAdapterDataSetComponent; }
	operator IAdapterMode*(void) { return (IAdapterMode*)&__IAdapterMode; }
	
};


class DELPHICLASS TDataSetAdapter;
class PASCALIMPLEMENTATION TDataSetAdapter : public TCustomDataSetAdapter 
{
	typedef TCustomDataSetAdapter inherited;
	
__published:
	__property DataSet ;
	__property Data ;
	__property Actions ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property OnPrepareDataSet ;
	__property OnBeforeUpdateFields ;
	__property OnAfterUpdateFields ;
	__property OnBeforeValidateFields ;
	__property OnAfterValidateFields ;
	__property OnBeforeExecuteAction ;
	__property OnAfterExecuteAction ;
	__property OnBeforeGetActionResponse ;
	__property OnAfterGetActionResponse ;
	__property OnGetActionParams ;
	__property OnGetRecordCount ;
	__property PageSize  = {default=0};
	__property MasterAdapter ;
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapter.Create */ inline __fastcall virtual TDataSetAdapter(Classes::TComponent* AOwner) : TCustomDataSetAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomDataSetAdapter.Destroy */ inline __fastcall virtual ~TDataSetAdapter(void) { }
	#pragma option pop
	
};


__interface IDataSetAdapterFieldClass;
typedef System::DelphiInterface<IDataSetAdapterFieldClass> _di_IDataSetAdapterFieldClass;
__interface INTERFACE_UUID("{C42812E6-D7AD-490B-80C6-3834CE31B66C}") IDataSetAdapterFieldClass  : public IInterface 
{
	
};

typedef void __fastcall (__closure *TDataSetAdapterFieldGetValueEvent)(System::TObject* Sender, Db::TField* Field, Variant &Value);

typedef void __fastcall (__closure *TDataSetAdapterFieldGetStringEvent)(System::TObject* Sender, Db::TField* Field, AnsiString &Value);

typedef void __fastcall (__closure *TDataAdapterFieldValidateValueEvent)(System::TObject* Sender, Db::TField* Field, Adaptreq::_di_IActionFieldValue Value, bool &Handled);

typedef void __fastcall (__closure *TDataSetAdapterFieldValueEvent)(System::TObject* Sender, Db::TField* Field, const Variant &Value);

#pragma option push -b-
enum TDataSetAdapterFieldFlag { ffInKey, ffInOrigValues };
#pragma option pop

typedef Set<TDataSetAdapterFieldFlag, ffInKey, ffInOrigValues>  TDataSetAdapterFieldFlags;

class DELPHICLASS TBaseDataSetAdapterField;
class PASCALIMPLEMENTATION TBaseDataSetAdapterField : public Webadapt::TAdapterNamedField 
{
	typedef Webadapt::TAdapterNamedField inherited;
	
private:
	Db::TField* FField;
	AnsiString FDataSetField;
	TDataSetAdapterModes FFieldModes;
	TDataSetAdapterFieldFlags FFieldFlags;
	TDataSetAdapterFieldGetStringEvent FOnGetDisplayText;
	TDataSetAdapterFieldGetValueEvent FOnGetValue;
	
protected:
	virtual bool __fastcall FullyQualifyInputName(void);
	virtual Variant __fastcall GetDataSetFieldValue(Db::TField* Field);
	void __fastcall SetDataSetField(const AnsiString Value);
	Db::TDataSet* __fastcall GetDataSet(void);
	void __fastcall GetKeyParams(TLocateParamsList* Params);
	bool __fastcall GetReadOnly(void);
	void __fastcall PrepareDataSet(void);
	AnsiString __fastcall GetKeyName();
	virtual bool __fastcall ImplGetVisible(void);
	virtual bool __fastcall ImplGetRequired(void);
	void __fastcall UpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	void __fastcall CheckOrigValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual void __fastcall ImplCheckOrigValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	bool __fastcall CheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual bool __fastcall ImplCheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	AnsiString __fastcall GetViewMode(const AnsiString AAdapterMode);
	AnsiString __fastcall GetDisplayStyle(const AnsiString AAdapterMode);
	AnsiString __fastcall GetInputStyle(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterDisplayHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterDisplayViewModeType __fastcall GetViewModeType(const AnsiString AAdapterMode);
	virtual AnsiString __fastcall ImplAsFormatted();
	virtual void __fastcall ImplSetFieldName(const AnsiString Value);
	virtual Variant __fastcall ImplGetValue();
	virtual int __fastcall ImplGetDisplayWidth(void);
	virtual AnsiString __fastcall ImplGetDisplayLabel();
	HIDESBASE TCustomDataSetAdapter* __fastcall GetAdapter(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property TCustomDataSetAdapter* Adapter = {read=GetAdapter};
	__property AnsiString DataSetField = {read=FDataSetField, write=SetDataSetField};
	
public:
	__fastcall virtual TBaseDataSetAdapterField(Classes::TComponent* AOwner);
	Db::TField* __fastcall FindField(void);
	__property TDataSetAdapterModes FieldModes = {read=FFieldModes, write=FFieldModes, default=15};
	__property TDataSetAdapterFieldFlags FieldFlags = {read=FFieldFlags, write=FFieldFlags, default=2};
	__property TDataSetAdapterFieldGetValueEvent OnGetValue = {read=FOnGetValue, write=FOnGetValue};
	__property TDataSetAdapterFieldGetStringEvent OnGetDisplayText = {read=FOnGetDisplayText, write=FOnGetDisplayText};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TBaseDataSetAdapterField(void) { }
	#pragma option pop
	
private:
	void *__IGetHTMLStyle;	/* Sitecomp::IGetHTMLStyle */
	void *__IUpdateValue;	/* Webadapt::IUpdateValue */
	void *__ICheckValueChange;	/* Webadapt::ICheckValueChange */
	void *__IDataSetAdapterFieldClass;	/* Dbadapt::IDataSetAdapterFieldClass */
	void *__IGetDataSetKeyName;	/* Dbadapt::IGetDataSetKeyName */
	void *__IPrepareDataSet;	/* Dbadapt::IPrepareDataSet */
	
public:
	operator IPrepareDataSet*(void) { return (IPrepareDataSet*)&__IPrepareDataSet; }
	operator IGetDataSetKeyName*(void) { return (IGetDataSetKeyName*)&__IGetDataSetKeyName; }
	operator IDataSetAdapterFieldClass*(void) { return (IDataSetAdapterFieldClass*)&__IDataSetAdapterFieldClass; }
	operator ICheckValueChange*(void) { return (ICheckValueChange*)&__ICheckValueChange; }
	operator IUpdateValue*(void) { return (IUpdateValue*)&__IUpdateValue; }
	operator IGetHTMLStyle*(void) { return (IGetHTMLStyle*)&__IGetHTMLStyle; }
	
};


class DELPHICLASS TBaseDataSetAdapterInputField;
class PASCALIMPLEMENTATION TBaseDataSetAdapterInputField : public TBaseDataSetAdapterField 
{
	typedef TBaseDataSetAdapterField inherited;
	
private:
	bool FEchoActionFieldValue;
	TDataAdapterFieldValidateValueEvent FOnValidateValue;
	TDataSetAdapterFieldValueEvent FOnUpdateValue;
	
protected:
	void __fastcall ValidateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual void __fastcall ImplValidateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual void __fastcall ImplSetEchoActionFieldValue(bool AValue);
	virtual bool __fastcall ImplGetEchoActionFieldValue(void);
	bool __fastcall TestValueChange(Db::TField* AField, const AnsiString ANewValue);
	
public:
	__property TDataSetAdapterFieldValueEvent OnUpdateValue = {read=FOnUpdateValue, write=FOnUpdateValue};
	__property TDataAdapterFieldValidateValueEvent OnValidateValue = {read=FOnValidateValue, write=FOnValidateValue};
public:
	#pragma option push -w-inl
	/* TBaseDataSetAdapterField.Create */ inline __fastcall virtual TBaseDataSetAdapterInputField(Classes::TComponent* AOwner) : TBaseDataSetAdapterField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TBaseDataSetAdapterInputField(void) { }
	#pragma option pop
	
private:
	void *__IValidateValue;	/* Webadapt::IValidateValue */
	
public:
	operator IValidateValue*(void) { return (IValidateValue*)&__IValidateValue; }
	
};


class DELPHICLASS TCustomDataSetAdapterField;
class PASCALIMPLEMENTATION TCustomDataSetAdapterField : public TBaseDataSetAdapterInputField 
{
	typedef TBaseDataSetAdapterInputField inherited;
	
private:
	Sitecomp::_di_IValuesListAdapter FValuesList;
	void __fastcall SetValuesList(const Sitecomp::_di_IValuesListAdapter Value);
	
protected:
	virtual Variant __fastcall ImplGetValue();
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual void __fastcall ImplCheckOrigValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual bool __fastcall ImplCheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	Sitecomp::_di_IValuesListAdapter __fastcall GetAdapterValuesList();
	Variant __fastcall GetPrevValue();
	virtual Variant __fastcall ImplGetPrevValue();
	bool __fastcall GetNeedPrevValue(void);
	virtual bool __fastcall ImplGetNeedPrevValue(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__property Sitecomp::_di_IValuesListAdapter ValuesList = {read=FValuesList, write=SetValuesList};
public:
	#pragma option push -w-inl
	/* TBaseDataSetAdapterField.Create */ inline __fastcall virtual TCustomDataSetAdapterField(Classes::TComponent* AOwner) : TBaseDataSetAdapterInputField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomDataSetAdapterField(void) { }
	#pragma option pop
	
private:
	void *__IWebGetFieldPrevValue;	/* Webadapt::IWebGetFieldPrevValue */
	void *__IGetAdapterValuesList;	/* Sitecomp::IGetAdapterValuesList */
	void *__ICheckOrigValue;	/* Webadapt::ICheckOrigValue */
	
public:
	operator ICheckOrigValue*(void) { return (ICheckOrigValue*)&__ICheckOrigValue; }
	operator IGetAdapterValuesList*(void) { return (IGetAdapterValuesList*)&__IGetAdapterValuesList; }
	operator IWebGetFieldPrevValue*(void) { return (IWebGetFieldPrevValue*)&__IWebGetFieldPrevValue; }
	
};


class DELPHICLASS TDataSetAdapterField;
class PASCALIMPLEMENTATION TDataSetAdapterField : public TCustomDataSetAdapterField 
{
	typedef TCustomDataSetAdapterField inherited;
	
__published:
	__property DataSetField ;
	__property ValuesList ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property FieldModes  = {default=15};
	__property FieldFlags  = {default=2};
	__property OnGetValue ;
	__property OnUpdateValue ;
	__property OnValidateValue ;
	__property OnGetDisplayText ;
public:
	#pragma option push -w-inl
	/* TBaseDataSetAdapterField.Create */ inline __fastcall virtual TDataSetAdapterField(Classes::TComponent* AOwner) : TCustomDataSetAdapterField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomDataSetAdapterMemoField;
class PASCALIMPLEMENTATION TCustomDataSetAdapterMemoField : public TBaseDataSetAdapterInputField 
{
	typedef TBaseDataSetAdapterInputField inherited;
	
protected:
	bool __fastcall CheckOrUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex, bool AUpdate);
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual AnsiString __fastcall ImplAsFormatted();
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	virtual bool __fastcall ImplCheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual Variant __fastcall ImplGetValue();
public:
	#pragma option push -w-inl
	/* TBaseDataSetAdapterField.Create */ inline __fastcall virtual TCustomDataSetAdapterMemoField(Classes::TComponent* AOwner) : TBaseDataSetAdapterInputField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomDataSetAdapterMemoField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterMemoField;
class PASCALIMPLEMENTATION TDataSetAdapterMemoField : public TCustomDataSetAdapterMemoField 
{
	typedef TCustomDataSetAdapterMemoField inherited;
	
__published:
	__property DataSetField ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property FieldModes  = {default=15};
	__property FieldFlags  = {default=2};
	__property OnGetValue ;
	__property OnUpdateValue ;
	__property OnValidateValue ;
	__property OnGetDisplayText ;
public:
	#pragma option push -w-inl
	/* TBaseDataSetAdapterField.Create */ inline __fastcall virtual TDataSetAdapterMemoField(Classes::TComponent* AOwner) : TCustomDataSetAdapterMemoField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterMemoField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomDataSetAdapterAction;
class PASCALIMPLEMENTATION TCustomDataSetAdapterAction : public Webadapt::TImplementedAdapterAction 
{
	typedef Webadapt::TImplementedAdapterAction inherited;
	
private:
	TDataSetAdapterModes FActionModes;
	Webadapt::TActionGetEnabledEvent FOnGetEnabled;
	Webadapt::TActionExecuteEvent FOnExecute;
	
protected:
	Db::TDataSet* __fastcall GetDataSet(void);
	virtual bool __fastcall ImplGetVisible(void);
	virtual bool __fastcall ImplWebEnabled(void);
	HIDESBASE TCustomDataSetAdapter* __fastcall GetAdapter(void);
	__property TCustomDataSetAdapter* Adapter = {read=GetAdapter};
	
public:
	__fastcall virtual TCustomDataSetAdapterAction(Classes::TComponent* AOwner);
	__property Db::TDataSet* DataSet = {read=GetDataSet};
	__property ActionName ;
	__property Webadapt::TActionExecuteEvent OnExecute = {read=FOnExecute, write=FOnExecute};
	__property Webadapt::TActionGetEnabledEvent OnGetEnabled = {read=FOnGetEnabled, write=FOnGetEnabled};
	__property TDataSetAdapterModes ActionModes = {read=FActionModes, write=FActionModes, default=15};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomDataSetAdapterAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomDataSetAdapterRowAction;
class PASCALIMPLEMENTATION TCustomDataSetAdapterRowAction : public TCustomDataSetAdapterAction 
{
	typedef TCustomDataSetAdapterAction inherited;
	
protected:
	virtual void __fastcall ImplGetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams Params);
	virtual bool __fastcall ImplWebEnabled(void);
	
public:
	__fastcall virtual TCustomDataSetAdapterRowAction(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomDataSetAdapterRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterRowAction : public TCustomDataSetAdapterRowAction 
{
	typedef TCustomDataSetAdapterRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual void __fastcall ImplGetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams Params);
	
__published:
	__property OnGetParams ;
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property RedirectOptions  = {default=0};
	__property ActionModes  = {default=7};
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapterRowAction.Create */ inline __fastcall virtual TDataSetAdapterRowAction(Classes::TComponent* AOwner) : TCustomDataSetAdapterRowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterDeleteRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterDeleteRowAction : public TCustomDataSetAdapterRowAction 
{
	typedef TCustomDataSetAdapterRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property RedirectOptions  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapterRowAction.Create */ inline __fastcall virtual TDataSetAdapterDeleteRowAction(Classes::TComponent* AOwner) : TCustomDataSetAdapterRowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterDeleteRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterMoveRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterMoveRowAction : public TCustomDataSetAdapterRowAction 
{
	typedef TCustomDataSetAdapterRowAction inherited;
	
protected:
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapterRowAction.Create */ inline __fastcall virtual TDataSetAdapterMoveRowAction(Classes::TComponent* AOwner) : TCustomDataSetAdapterRowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterMoveRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterNextRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterNextRowAction : public TDataSetAdapterMoveRowAction 
{
	typedef TDataSetAdapterMoveRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property RedirectOptions  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapterRowAction.Create */ inline __fastcall virtual TDataSetAdapterNextRowAction(Classes::TComponent* AOwner) : TDataSetAdapterMoveRowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterNextRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterPrevRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterPrevRowAction : public TDataSetAdapterMoveRowAction 
{
	typedef TDataSetAdapterMoveRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property RedirectOptions  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapterRowAction.Create */ inline __fastcall virtual TDataSetAdapterPrevRowAction(Classes::TComponent* AOwner) : TDataSetAdapterMoveRowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterPrevRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterFirstRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterFirstRowAction : public TDataSetAdapterMoveRowAction 
{
	typedef TDataSetAdapterMoveRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property RedirectOptions  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapterRowAction.Create */ inline __fastcall virtual TDataSetAdapterFirstRowAction(Classes::TComponent* AOwner) : TDataSetAdapterMoveRowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterFirstRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterLastRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterLastRowAction : public TDataSetAdapterMoveRowAction 
{
	typedef TDataSetAdapterMoveRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property RedirectOptions  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapterRowAction.Create */ inline __fastcall virtual TDataSetAdapterLastRowAction(Classes::TComponent* AOwner) : TDataSetAdapterMoveRowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterLastRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterNewRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterNewRowAction : public TDataSetAdapterRowAction 
{
	typedef TDataSetAdapterRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__fastcall virtual TDataSetAdapterNewRowAction(Classes::TComponent* AOwner);
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property ActionModes  = {default=15};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterNewRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterCancelRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterCancelRowAction : public TCustomDataSetAdapterRowAction 
{
	typedef TCustomDataSetAdapterRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__fastcall virtual TDataSetAdapterCancelRowAction(Classes::TComponent* AOwner);
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property RedirectOptions  = {default=0};
	__property ActionModes  = {default=3};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterCancelRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterApplyRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterApplyRowAction : public TCustomDataSetAdapterRowAction 
{
	typedef TCustomDataSetAdapterRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__fastcall virtual TDataSetAdapterApplyRowAction(Classes::TComponent* AOwner);
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property RedirectOptions  = {default=0};
	__property ActionModes  = {default=3};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterApplyRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterRefreshRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterRefreshRowAction : public TCustomDataSetAdapterRowAction 
{
	typedef TCustomDataSetAdapterRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property RedirectOptions  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapterRowAction.Create */ inline __fastcall virtual TDataSetAdapterRefreshRowAction(Classes::TComponent* AOwner) : TCustomDataSetAdapterRowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterRefreshRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterEditRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterEditRowAction : public TCustomDataSetAdapterRowAction 
{
	typedef TCustomDataSetAdapterRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__fastcall virtual TDataSetAdapterEditRowAction(Classes::TComponent* AOwner);
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property ActionModes  = {default=15};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterEditRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterBrowseRowAction;
class PASCALIMPLEMENTATION TDataSetAdapterBrowseRowAction : public TCustomDataSetAdapterRowAction 
{
	typedef TCustomDataSetAdapterRowAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__fastcall virtual TDataSetAdapterBrowseRowAction(Classes::TComponent* AOwner);
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
	__property ActionModes  = {default=15};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterBrowseRowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetAdapterDataLink;
class PASCALIMPLEMENTATION TDataSetAdapterDataLink : public Db::TDataLink 
{
	typedef Db::TDataLink inherited;
	
private:
	Classes::TComponent* FAdapter;
	Classes::TNotifyEvent FOnDataSetStateChange;
	
protected:
	virtual void __fastcall RecordChanged(Db::TField* Field);
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	
public:
	__fastcall TDataSetAdapterDataLink(Classes::TComponent* AAdapter);
	__property Classes::TNotifyEvent OnDataSetStateChange = {read=FOnDataSetStateChange, write=FOnDataSetStateChange};
public:
	#pragma option push -w-inl
	/* TDataLink.Destroy */ inline __fastcall virtual ~TDataSetAdapterDataLink(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomDataSetValuesList;
class PASCALIMPLEMENTATION TCustomDataSetValuesList : public Webadapt::TBaseValuesListAdapter 
{
	typedef Webadapt::TBaseValuesListAdapter inherited;
	
private:
	Db::TDataSet* FDataSet;
	AnsiString FNameField;
	AnsiString FValueField;
	Webcontnrs::TNamedVariantsList* FCache;
	bool FCacheInUse;
	int FIndex;
	Classes::TNotifyEvent FOnPrepareDataSet;
	bool FDataSetPrepared;
	void __fastcall SetDataSet(const Db::TDataSet* Value);
	void __fastcall CacheValuesList(void);
	Db::TDataSet* __fastcall GetDataSet(void);
	void __fastcall PrepareDataSet(void);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual TMetaClass* __fastcall GetNameFieldClass(void);
	virtual TMetaClass* __fastcall GetValueFieldClass(void);
	void __fastcall GetDesigntimeWarnings(Sitecomp::TAbstractDesigntimeWarnings* AWarnings);
	virtual void __fastcall ImplNotifyDeactivate(void);
	virtual Variant __fastcall ImplGetListValue();
	virtual AnsiString __fastcall ImplGetListName();
	virtual AnsiString __fastcall ImplGetListNameOfValue(const Variant &Value);
	virtual bool __fastcall ImplStartIterator(void * &OwnerData);
	virtual bool __fastcall ImplNextIteration(void * &OwnerData);
	virtual void __fastcall ImplEndIterator(void * OwnerData);
	__property bool DataSetPrepared = {read=FDataSetPrepared, write=FDataSetPrepared, nodefault};
	
public:
	__fastcall virtual TCustomDataSetValuesList(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDataSetValuesList(void);
	__property AnsiString NameField = {read=FNameField, write=FNameField};
	__property AnsiString ValueField = {read=FValueField, write=FValueField};
	__property Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
	__property Classes::TNotifyEvent OnPrepareDataSet = {read=FOnPrepareDataSet, write=FOnPrepareDataSet};
private:
	void *__IGetDesigntimeWarnings;	/* Sitecomp::IGetDesigntimeWarnings */
	
public:
	operator IGetDesigntimeWarnings*(void) { return (IGetDesigntimeWarnings*)&__IGetDesigntimeWarnings; }
	
};


class DELPHICLASS TDataSetValuesList;
class PASCALIMPLEMENTATION TDataSetValuesList : public TCustomDataSetValuesList 
{
	typedef TCustomDataSetValuesList inherited;
	
__published:
	__property NameField ;
	__property ValueField ;
	__property DataSet ;
	__property OnPrepareDataSet ;
	__property Data ;
	__property Actions ;
public:
	#pragma option push -w-inl
	/* TCustomDataSetValuesList.Create */ inline __fastcall virtual TDataSetValuesList(Classes::TComponent* AOwner) : TCustomDataSetValuesList(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomDataSetValuesList.Destroy */ inline __fastcall virtual ~TDataSetValuesList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBaseDataSetAdapterImageField;
class PASCALIMPLEMENTATION TBaseDataSetAdapterImageField : public TBaseDataSetAdapterField 
{
	typedef TBaseDataSetAdapterField inherited;
	
public:
	#pragma option push -w-inl
	/* TBaseDataSetAdapterField.Create */ inline __fastcall virtual TBaseDataSetAdapterImageField(Classes::TComponent* AOwner) : TBaseDataSetAdapterField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TBaseDataSetAdapterImageField(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TDataSetAdapterImageFieldClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString DataSetAdapterModeNames[4];
extern PACKAGE TMetaClass*DataSetAdapterImageFieldClass;
#define AllActionParamOptions (System::Set<TDataSetAdapterRequestParamOption, poLocateParams, poCurrentPage> () << TDataSetAdapterRequestParamOption(0) << TDataSetAdapterRequestParamOption(1) )
#define AllImageParamOptions (System::Set<TDataSetAdapterRequestParamOption, poLocateParams, poCurrentPage> () << TDataSetAdapterRequestParamOption(0) )
extern PACKAGE void __fastcall AddLocateParamsString(AnsiString AAdapterName, AnsiString AKeyName, AnsiString AKeyValue, TLocateParamsList* AParams);

}	/* namespace Dbadapt */
using namespace Dbadapt;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBAdapt
