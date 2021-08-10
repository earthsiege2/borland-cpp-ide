// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebAdapt.pas' rev: 6.00

#ifndef WebAdaptHPP
#define WebAdaptHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebCntxt.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <AdaptReq.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <WebContnrs.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webadapt
{
//-- type declarations -------------------------------------------------------
__interface IGetRecordKeys;
typedef System::DelphiInterface<IGetRecordKeys> _di_IGetRecordKeys;
__interface INTERFACE_UUID("{903C8BC5-1E1E-4592-BD13-99EB29819876}") IGetRecordKeys  : public IInterface 
{
	
public:
	virtual void __fastcall GetRecordKeys(Classes::TStrings* AParams, bool &AFullyQualify) = 0 ;
};

__interface ICheckOrigValue;
typedef System::DelphiInterface<ICheckOrigValue> _di_ICheckOrigValue;
__interface INTERFACE_UUID("{BE6A5DCD-A617-11D4-A4FE-00C04F6BB853}") ICheckOrigValue  : public IInterface 
{
	
public:
	virtual void __fastcall CheckOrigValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex) = 0 ;
};

__interface IValidateValue;
typedef System::DelphiInterface<IValidateValue> _di_IValidateValue;
__interface INTERFACE_UUID("{23EA6F48-DC46-47A7-8EC3-0FF9F59D8F57}") IValidateValue  : public IInterface 
{
	
public:
	virtual void __fastcall ValidateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex) = 0 ;
};

__interface ICheckValueChange;
typedef System::DelphiInterface<ICheckValueChange> _di_ICheckValueChange;
__interface INTERFACE_UUID("{7021B26D-B023-11D4-A50F-00C04F6BB853}") ICheckValueChange  : public IInterface 
{
	
public:
	virtual bool __fastcall CheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex) = 0 ;
};

__interface IGetAdapterModeNames;
typedef System::DelphiInterface<IGetAdapterModeNames> _di_IGetAdapterModeNames;
__interface INTERFACE_UUID("{2D71A94A-4D9B-498E-802E-9739C0CE5875}") IGetAdapterModeNames  : public IInterface 
{
	
public:
	virtual void __fastcall GetAdapterModeNames(Classes::TStrings* AStrings) = 0 ;
};

__interface IUpdateValue;
typedef System::DelphiInterface<IUpdateValue> _di_IUpdateValue;
__interface INTERFACE_UUID("{BE6A5DCE-A617-11D4-A4FE-00C04F6BB853}") IUpdateValue  : public IInterface 
{
	
public:
	virtual void __fastcall UpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex) = 0 ;
};

__interface IExecuteValue;
typedef System::DelphiInterface<IExecuteValue> _di_IExecuteValue;
__interface INTERFACE_UUID("{BBC8AA03-EEB8-4FB5-BADA-EE2543DC728D}") IExecuteValue  : public IInterface 
{
	
public:
	virtual void __fastcall ExecuteValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex) = 0 ;
};

__interface IClearAdapterValues;
typedef System::DelphiInterface<IClearAdapterValues> _di_IClearAdapterValues;
__interface INTERFACE_UUID("{274C6B5F-CAD6-11D4-A529-00C04F6BB853}") IClearAdapterValues  : public IInterface 
{
	
public:
	virtual void __fastcall ClearAdapterValues(void) = 0 ;
};

__interface IWebGetFieldPrevValue;
typedef System::DelphiInterface<IWebGetFieldPrevValue> _di_IWebGetFieldPrevValue;
__interface INTERFACE_UUID("{7AE6735B-6964-11D4-A4AA-00C04F6BB853}") IWebGetFieldPrevValue  : public IInterface 
{
	
public:
	virtual bool __fastcall GetNeedPrevValue(void) = 0 ;
	virtual Variant __fastcall GetPrevValue(void) = 0 ;
	__property Variant PrevValue = {read=GetPrevValue};
	__property bool NeedPrevValue = {read=GetNeedPrevValue};
};

__interface ISetWebFieldValue;
typedef System::DelphiInterface<ISetWebFieldValue> _di_ISetWebFieldValue;
__interface INTERFACE_UUID("{9E6E6A7E-574F-11D4-A491-00C04F6BB853}") ISetWebFieldValue  : public IInterface 
{
	
public:
	virtual void __fastcall SetValue(const Variant &AValue) = 0 ;
};

__interface IWebFieldsSubcomponent;
typedef System::DelphiInterface<IWebFieldsSubcomponent> _di_IWebFieldsSubcomponent;
__interface INTERFACE_UUID("{5D5A9FD6-9496-11D4-A4E9-00C04F6BB853}") IWebFieldsSubcomponent  : public IInterface 
{
	
};

__interface IWebActionsSubcomponent;
typedef System::DelphiInterface<IWebActionsSubcomponent> _di_IWebActionsSubcomponent;
__interface INTERFACE_UUID("{29764F06-D0D8-4334-AA97-CB25D40737AE}") IWebActionsSubcomponent  : public IInterface 
{
	
};

__interface IFullyQualifyInputNames;
typedef System::DelphiInterface<IFullyQualifyInputNames> _di_IFullyQualifyInputNames;
__interface INTERFACE_UUID("{C6224685-3BDA-4BC4-B618-E9F329845FC2}") IFullyQualifyInputNames  : public IInterface 
{
	
public:
	virtual bool __fastcall FullyQualifyInputNames(void) = 0 ;
};

class DELPHICLASS TAdapterSubComponent;
class PASCALIMPLEMENTATION TAdapterSubComponent : public Webcomp::TWebContainerComponent 
{
	typedef Webcomp::TWebContainerComponent inherited;
	
private:
	Classes::TComponent* FParent;
	int FIteratorIndex;
	Classes::TComponent* __fastcall GetAdapter(void);
	
protected:
	__property Classes::TComponent* Adapter = {read=GetAdapter};
	virtual Webcomp::TWebComponentList* __fastcall GetDefaultWebComponents(void);
	virtual void __fastcall SetDefaultWebComponents(Webcomp::TWebComponentList* AList);
	void __fastcall NotifyAdapterChange(void);
	bool __fastcall StartIterator(void * &OwnerData);
	bool __fastcall NextIteration(void * &OwnerData);
	void __fastcall EndIterator(void * OwnerData);
	System::TObject* __fastcall GetCurrentObject(void * OwnerData);
	Classes::TComponent* __fastcall FindVariable(const AnsiString AName);
	Classes::TComponent* __fastcall FindVariableContainer(const AnsiString AName);
	int __fastcall GetVariableCount(void);
	Classes::TComponent* __fastcall GetVariable(int I);
	virtual Classes::TComponent* __fastcall FindNamedVariable(const AnsiString AName);
	AnsiString __fastcall GetWebComponentNodeName();
	virtual AnsiString __fastcall ImplGetWebComponentNodeName();
	bool __fastcall CanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall SetWebParent(const Classes::TComponent* Value);
	virtual Webcomp::TWebComponentList* __fastcall GetVariablesInUse(void);
	__property Webcomp::TWebComponentList* VariablesInUse = {read=GetVariablesInUse};
	
public:
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
public:
	#pragma option push -w-inl
	/* TWebContainerComponent.Create */ inline __fastcall virtual TAdapterSubComponent(Classes::TComponent* AOwner) : Webcomp::TWebContainerComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainerComponent.Destroy */ inline __fastcall virtual ~TAdapterSubComponent(void) { }
	#pragma option pop
	
private:
	void *__IWebContainerSubComponent;	/* Sitecomp::IWebContainerSubComponent */
	void *__IWebComponentEditor;	/* Webcomp::IWebComponentEditor */
	void *__IWebVariablesContainer;	/* Httpprod::IWebVariablesContainer */
	void *__IGetWebComponentNodeName;	/* Webcomp::IGetWebComponentNodeName */
	void *__IIterateObjectSupport;	/* Sitecomp::IIterateObjectSupport */
	
public:
	operator IIterateObjectSupport*(void) { return (IIterateObjectSupport*)&__IIterateObjectSupport; }
	operator IGetWebComponentNodeName*(void) { return (IGetWebComponentNodeName*)&__IGetWebComponentNodeName; }
	operator IWebVariablesContainer*(void) { return (IWebVariablesContainer*)&__IWebVariablesContainer; }
	operator IWebComponentEditor*(void) { return (IWebComponentEditor*)&__IWebComponentEditor; }
	operator IWebContainerSubComponent*(void) { return (IWebContainerSubComponent*)&__IWebContainerSubComponent; }
	
};


class DELPHICLASS TAdapterFields;
class PASCALIMPLEMENTATION TAdapterFields : public TAdapterSubComponent 
{
	typedef TAdapterSubComponent inherited;
	
protected:
	bool __fastcall AdapterCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall SetWebParent(const Classes::TComponent* Value);
	virtual AnsiString __fastcall ImplGetWebComponentNodeName();
	
public:
	__property Webcomp::TWebComponentList* WebFields = {read=GetWebComponents};
public:
	#pragma option push -w-inl
	/* TWebContainerComponent.Create */ inline __fastcall virtual TAdapterFields(Classes::TComponent* AOwner) : TAdapterSubComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainerComponent.Destroy */ inline __fastcall virtual ~TAdapterFields(void) { }
	#pragma option pop
	
private:
	void *__IWebFieldsSubcomponent;	/* Webadapt::IWebFieldsSubcomponent */
	
public:
	operator IWebFieldsSubcomponent*(void) { return (IWebFieldsSubcomponent*)&__IWebFieldsSubcomponent; }
	
};


typedef TMetaClass*TAdapterFieldsClass;

class DELPHICLASS TAdapterDefaultFields;
class PASCALIMPLEMENTATION TAdapterDefaultFields : public TAdapterFields 
{
	typedef TAdapterFields inherited;
	
private:
	Webcomp::TWebComponentList* FDefaultWebComponents;
	
protected:
	virtual Webcomp::TWebComponentList* __fastcall GetDefaultWebComponents(void);
	virtual void __fastcall SetDefaultWebComponents(Webcomp::TWebComponentList* AList);
	AnsiString __fastcall GetNewFieldPrefix();
	AnsiString __fastcall GetAddFieldsItem();
	AnsiString __fastcall GetAddAllFieldsItem();
	AnsiString __fastcall GetAddFieldsDlgCaption();
	virtual Webcomp::TWebComponentList* __fastcall GetVariablesInUse(void);
	
public:
	virtual void __fastcall ClearDefaultComponents(void);
	__fastcall virtual ~TAdapterDefaultFields(void);
	__property Webcomp::TWebComponentList* DefaultWebComponents = {read=FDefaultWebComponents};
public:
	#pragma option push -w-inl
	/* TWebContainerComponent.Create */ inline __fastcall virtual TAdapterDefaultFields(Classes::TComponent* AOwner) : TAdapterFields(AOwner) { }
	#pragma option pop
	
private:
	void *__IAddFieldsEditor;	/* Webcomp::IAddFieldsEditor */
	
public:
	operator IAddFieldsEditor*(void) { return (IAddFieldsEditor*)&__IAddFieldsEditor; }
	
};


class DELPHICLASS TAdapterActions;
class PASCALIMPLEMENTATION TAdapterActions : public TAdapterSubComponent 
{
	typedef TAdapterSubComponent inherited;
	
protected:
	bool __fastcall AdapterCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall SetWebParent(const Classes::TComponent* Value);
	virtual AnsiString __fastcall ImplGetWebComponentNodeName();
	
public:
	__property Webcomp::TWebComponentList* WebActions = {read=GetWebComponents};
public:
	#pragma option push -w-inl
	/* TWebContainerComponent.Create */ inline __fastcall virtual TAdapterActions(Classes::TComponent* AOwner) : TAdapterSubComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainerComponent.Destroy */ inline __fastcall virtual ~TAdapterActions(void) { }
	#pragma option pop
	
private:
	void *__IWebActionsSubcomponent;	/* Webadapt::IWebActionsSubcomponent */
	
public:
	operator IWebActionsSubcomponent*(void) { return (IWebActionsSubcomponent*)&__IWebActionsSubcomponent; }
	
};


class DELPHICLASS TAdapterDefaultActions;
class PASCALIMPLEMENTATION TAdapterDefaultActions : public TAdapterActions 
{
	typedef TAdapterActions inherited;
	
private:
	Webcomp::TWebComponentList* FDefaultWebComponents;
	
protected:
	virtual Webcomp::TWebComponentList* __fastcall GetDefaultWebComponents(void);
	virtual void __fastcall SetDefaultWebComponents(Webcomp::TWebComponentList* AList);
	virtual Webcomp::TWebComponentList* __fastcall GetVariablesInUse(void);
	AnsiString __fastcall GetNewFieldPrefix();
	AnsiString __fastcall GetAddFieldsItem();
	AnsiString __fastcall GetAddAllFieldsItem();
	AnsiString __fastcall GetAddFieldsDlgCaption();
	
public:
	virtual void __fastcall ClearDefaultComponents(void);
	__fastcall virtual ~TAdapterDefaultActions(void);
	__property Webcomp::TWebComponentList* DefaultWebComponents = {read=GetDefaultWebComponents};
public:
	#pragma option push -w-inl
	/* TWebContainerComponent.Create */ inline __fastcall virtual TAdapterDefaultActions(Classes::TComponent* AOwner) : TAdapterActions(AOwner) { }
	#pragma option pop
	
private:
	void *__IAddFieldsEditor;	/* Webcomp::IAddFieldsEditor */
	
public:
	operator IAddFieldsEditor*(void) { return (IAddFieldsEditor*)&__IAddFieldsEditor; }
	
};


class DELPHICLASS TAdapterError;
class DELPHICLASS TAdapterErrorsList;
class DELPHICLASS TBaseAdapterErrorsList;
class PASCALIMPLEMENTATION TBaseAdapterErrorsList : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	int FIteratorIndex;
	
protected:
	int __fastcall GetErrorCount(void);
	Sitecomp::_di_IAdapterError __fastcall GetError(int I);
	bool __fastcall HasObjectErrors(const AnsiString AName);
	System::TObject* __fastcall GetObjectErrors(const AnsiString AName);
	virtual void __fastcall ImplClearErrors(void);
	virtual int __fastcall ImplGetErrorCount(void);
	virtual Sitecomp::_di_IAdapterError __fastcall ImplGetError(int I);
	virtual bool __fastcall ImplHasObjectErrors(const AnsiString AName);
	virtual System::TObject* __fastcall ImplGetObjectErrors(const AnsiString AName);
	virtual void __fastcall ImplDefineLabel(const AnsiString AName, const AnsiString ALabel);
	bool __fastcall StartIterator(void * &OwnerData);
	bool __fastcall NextIteration(void * &OwnerData);
	void __fastcall EndIterator(void * OwnerData);
	System::_di_IInterface __fastcall GetCurrentIntf(void * OwnerData);
	
public:
	void __fastcall DefineLabel(const AnsiString AName, const AnsiString ALabel);
	void __fastcall ClearErrors(void);
	__property int ErrorCount = {read=GetErrorCount, nodefault};
	__property Sitecomp::_di_IAdapterError Errors[int I] = {read=GetError};
	virtual void __fastcall AddError(Sysutils::Exception* AException, const AnsiString AObjectName = "")/* overload */;
	virtual void __fastcall AddError(const AnsiString AMessage, const AnsiString AObjectName = "", int AID = 0x0)/* overload */;
	virtual void __fastcall AddError(const AnsiString AMessage, System::TObject* AObject, int AID = 0x0)/* overload */;
	virtual void __fastcall AddError(Sysutils::Exception* AException, System::TObject* AObject)/* overload */;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TBaseAdapterErrorsList(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBaseAdapterErrorsList(void) { }
	#pragma option pop
	
private:
	void *__IAdapterErrors;	/* Sitecomp::IAdapterErrors */
	void *__IIterateIntfSupport;	/* Sitecomp::IIterateIntfSupport */
	
public:
	operator IIterateIntfSupport*(void) { return (IIterateIntfSupport*)&__IIterateIntfSupport; }
	operator IAdapterErrors*(void) { return (IAdapterErrors*)&__IAdapterErrors; }
	
};


class PASCALIMPLEMENTATION TAdapterErrorsList : public TBaseAdapterErrorsList 
{
	typedef TBaseAdapterErrorsList inherited;
	
private:
	System::TObject* FAdapter;
	Classes::TStrings* FMessages;
	Classes::TStrings* FFieldNames;
	Classes::TStrings* FLabels;
	AnsiString __fastcall GetFieldName(int I);
	int __fastcall GetID(int I);
	AnsiString __fastcall GetMessage(int I);
	
protected:
	virtual void __fastcall ImplClearErrors(void);
	virtual int __fastcall ImplGetErrorCount(void);
	virtual Sitecomp::_di_IAdapterError __fastcall ImplGetError(int I);
	virtual bool __fastcall ImplHasObjectErrors(const AnsiString AName);
	virtual System::TObject* __fastcall ImplGetObjectErrors(const AnsiString AName);
	virtual void __fastcall ImplDefineLabel(const AnsiString AName, const AnsiString ALabel);
	
public:
	__fastcall TAdapterErrorsList(System::TObject* AAdapter);
	__fastcall virtual ~TAdapterErrorsList(void);
	virtual void __fastcall AddError(Sysutils::Exception* AException, const AnsiString AObjectName = "")/* overload */;
	virtual void __fastcall AddError(const AnsiString AMessage, const AnsiString AObjectName = "", int AID = 0x0)/* overload */;
	virtual void __fastcall AddError(const AnsiString AMessage, System::TObject* AObject, int AID = 0x0)/* overload */;
	virtual void __fastcall AddError(Sysutils::Exception* AException, System::TObject* AObject)/* overload */;
	__property AnsiString Messages[int I] = {read=GetMessage};
	__property int IDs[int I] = {read=GetID};
	__property AnsiString FieldNames[int I] = {read=GetFieldName};
};


class PASCALIMPLEMENTATION TAdapterError : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TAdapterErrorsList* FErrors;
	int FIndex;
	
protected:
	AnsiString __fastcall GetErrorText();
	int __fastcall GetID(void);
	Classes::TComponent* __fastcall GetField(void);
	
public:
	__fastcall TAdapterError(TAdapterErrorsList* AErrors, int AIndex);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAdapterError(void) { }
	#pragma option pop
	
private:
	void *__IAdapterError;	/* Sitecomp::IAdapterError */
	
public:
	operator IAdapterError*(void) { return (IAdapterError*)&__IAdapterError; }
	
};


typedef DynamicArray<int >  WebAdapt__01;

class DELPHICLASS TAdapterObjectErrorsList;
class PASCALIMPLEMENTATION TAdapterObjectErrorsList : public TBaseAdapterErrorsList 
{
	typedef TBaseAdapterErrorsList inherited;
	
private:
	TAdapterErrorsList* FErrors;
	DynamicArray<int >  FIndexes;
	
protected:
	virtual int __fastcall ImplGetErrorCount(void);
	virtual Sitecomp::_di_IAdapterError __fastcall ImplGetError(int I);
	virtual void __fastcall ImplDefineLabel(const AnsiString AName, const AnsiString ALabel);
	
public:
	__fastcall TAdapterObjectErrorsList(TAdapterErrorsList* AErrors, const AnsiString AName);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAdapterObjectErrorsList(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TAdapterActionsClass;

__interface IGetAdapterErrorsList;
typedef System::DelphiInterface<IGetAdapterErrorsList> _di_IGetAdapterErrorsList;
__interface INTERFACE_UUID("{42DD8EB1-5D9A-11D4-A498-00C04F6BB853}") IGetAdapterErrorsList  : public IInterface 
{
	
public:
	virtual TBaseAdapterErrorsList* __fastcall GetAdapterErrorsList(void) = 0 ;
};

__interface IAdapterEditor;
typedef System::DelphiInterface<IAdapterEditor> _di_IAdapterEditor;
__interface INTERFACE_UUID("{42DD8EB2-5D9A-11D4-A498-00C04F6BB853}") IAdapterEditor  : public IInterface 
{
	
public:
	virtual bool __fastcall CanAddFieldClass(Classes::TComponent* AParent, TMetaClass* AClass) = 0 ;
	virtual bool __fastcall CanAddActionClass(Classes::TComponent* AParent, TMetaClass* AClass) = 0 ;
};

__interface ISetSubComponents;
typedef System::DelphiInterface<ISetSubComponents> _di_ISetSubComponents;
__interface INTERFACE_UUID("{274C6B60-CAD6-11D4-A529-00C04F6BB853}") ISetSubComponents  : public IInterface 
{
	
public:
	virtual void __fastcall SetActions(const TAdapterSubComponent* Value) = 0 ;
	virtual void __fastcall SetData(const TAdapterSubComponent* Value) = 0 ;
};

__interface IEchoAdapterFieldValues;
typedef System::DelphiInterface<IEchoAdapterFieldValues> _di_IEchoAdapterFieldValues;
__interface INTERFACE_UUID("{274C6B62-CAD6-11D4-A529-00C04F6BB853}") IEchoAdapterFieldValues  : public IInterface 
{
	
public:
	virtual void __fastcall SetEchoActionFieldValues(bool AValue) = 0 ;
	virtual bool __fastcall GetEchoActionFieldValues(void) = 0 ;
	__property bool EchoActionFieldValues = {read=GetEchoActionFieldValues, write=SetEchoActionFieldValues};
};

__interface ICreateActionRequestContext;
typedef System::DelphiInterface<ICreateActionRequestContext> _di_ICreateActionRequestContext;
__interface INTERFACE_UUID("{374E4AFB-D11F-11D4-A531-00C04F6BB853}") ICreateActionRequestContext  : public IInterface 
{
	
public:
	virtual void __fastcall CreateActionRequestContext(Sitecomp::_di_IAdapterDispatchParams DispatchParams) = 0 ;
};

class DELPHICLASS TAdapterHiddenFieldsList;
class PASCALIMPLEMENTATION TAdapterHiddenFieldsList : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	int FIteratorIndex;
	Classes::TStrings* FNames;
	Classes::TStrings* FValues;
	
protected:
	int __fastcall GetFieldCount(void);
	Sitecomp::_di_IAdapterHiddenField __fastcall GetField(int I);
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property Sitecomp::_di_IAdapterHiddenField Fields[int I] = {read=GetField};
	bool __fastcall StartIterator(void * &OwnerData);
	bool __fastcall NextIteration(void * &OwnerData);
	void __fastcall EndIterator(void * OwnerData);
	System::_di_IInterface __fastcall GetCurrentIntf(void * OwnerData);
	
public:
	__fastcall TAdapterHiddenFieldsList(void);
	__fastcall virtual ~TAdapterHiddenFieldsList(void);
	void __fastcall Clear(void);
	void __fastcall Add(const AnsiString AName, const AnsiString AValue);
private:
	void *__IAdapterHiddenFields;	/* Sitecomp::IAdapterHiddenFields */
	void *__IIterateIntfSupport;	/* Sitecomp::IIterateIntfSupport */
	
public:
	operator IIterateIntfSupport*(void) { return (IIterateIntfSupport*)&__IIterateIntfSupport; }
	operator IAdapterHiddenFields*(void) { return (IAdapterHiddenFields*)&__IAdapterHiddenFields; }
	
};


class DELPHICLASS TAdapterHiddenField;
class PASCALIMPLEMENTATION TAdapterHiddenField : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TAdapterHiddenFieldsList* FHiddenFields;
	int FIndex;
	
protected:
	AnsiString __fastcall GetName();
	AnsiString __fastcall GetValue();
	
public:
	__fastcall TAdapterHiddenField(TAdapterHiddenFieldsList* AHiddenFields, int AIndex);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAdapterHiddenField(void) { }
	#pragma option pop
	
private:
	void *__IAdapterHiddenField;	/* Sitecomp::IAdapterHiddenField */
	
public:
	operator IAdapterHiddenField*(void) { return (IAdapterHiddenField*)&__IAdapterHiddenField; }
	
};


typedef void __fastcall (__closure *TAdapterActionExecuteEvent)(System::TObject* Sender, System::TObject* Action, Classes::TStrings* Params);

typedef void __fastcall (__closure *TAdapterActionExecuteHandledEvent)(System::TObject* Sender, System::TObject* Action, Classes::TStrings* Params, bool &Handled);

typedef void __fastcall (__closure *TAdapterActionGetParamsEvent)(System::TObject* Sender, System::TObject* Action, Classes::TStrings* Params);

#pragma option push -b-
enum TIteratorMethod { itStart, itNext, itEnd };
#pragma option pop

typedef void __fastcall (__closure *TIterateRecordsEvent)(System::TObject* Sender, TIteratorMethod Action, bool &EOF);

typedef void __fastcall (__closure *TActionRequestFieldsEvent)(System::TObject* Sender, Adaptreq::_di_IActionRequest ActionRequest, Contnrs::TObjectList* AdapterFields);

typedef void __fastcall (__closure *TActionRequestFieldsHandledEvent)(System::TObject* Sender, Adaptreq::_di_IActionRequest ActionRequest, Contnrs::TObjectList* AdapterFields, bool &Handled);

typedef void __fastcall (__closure *TGetRecordCountEvent)(System::TObject* Sender, int &Count);

typedef void __fastcall (__closure *TGetRecordIndexEvent)(System::TObject* Sender, int &Index);

typedef void __fastcall (__closure *TGetEOFEvent)(System::TObject* Sender, bool &EOF);

typedef void __fastcall (__closure *TGetRecordEvent)(System::TObject* Sender, bool &EOF);

__interface IAdapterNotifyAdapterChange;
typedef System::DelphiInterface<IAdapterNotifyAdapterChange> _di_IAdapterNotifyAdapterChange;
__interface INTERFACE_UUID("{10D48060-2BD8-472E-871B-2933ACD8F3B3}") IAdapterNotifyAdapterChange  : public IInterface 
{
	
public:
	virtual void __fastcall NotifyAdapterChange(void) = 0 ;
};

__interface IIdentifyAdapter;
typedef System::DelphiInterface<IIdentifyAdapter> _di_IIdentifyAdapter;
__interface INTERFACE_UUID("{1A4AEC52-2960-46BD-89AC-1A5742A85089}") IIdentifyAdapter  : public IInterface 
{
	
};

#pragma option push -b-
enum TAdapterHiddenFieldOption { hoOrigValues, hoMode, hoRecordKeys };
#pragma option pop

typedef Set<TAdapterHiddenFieldOption, hoOrigValues, hoRecordKeys>  TAdapterHiddenFieldOptions;

class DELPHICLASS TCustomAdapter;
class PASCALIMPLEMENTATION TCustomAdapter : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Sitecomp::TNotifyList* FNotifyList;
	TAdapterFields* FData;
	TAdapterActions* FActions;
	TBaseAdapterErrorsList* FErrors;
	Sitecomp::_di_IAdapterErrors FErrorsIntf;
	TIterateRecordsEvent FOnIterateRecords;
	bool FEchoActionFieldValues;
	TActionRequestFieldsHandledEvent FOnBeforeValidateFields;
	TActionRequestFieldsEvent FOnAfterValidateFields;
	TActionRequestFieldsHandledEvent FOnBeforeUpdateFields;
	TActionRequestFieldsEvent FOnAfterUpdateFields;
	TAdapterActionExecuteHandledEvent FOnBeforeExecuteAction;
	TAdapterActionExecuteEvent FOnAfterExecuteAction;
	TAdapterActionExecuteEvent FOnAfterGetActionResponse;
	TAdapterActionExecuteHandledEvent FOnBeforeGetActionResponse;
	TAdapterActionGetParamsEvent FOnGetActionParams;
	AnsiString FViewAccess;
	AnsiString FModifyAccess;
	AnsiString FExecuteAccess;
	TAdapterHiddenFieldsList* FHiddenFields;
	TAdapterHiddenFieldsList* FHiddenRecordFields;
	Sitecomp::_di_IAdapterHiddenFields FHiddenFieldsIntf;
	Sitecomp::_di_IAdapterHiddenFields FHiddenRecordFieldsIntf;
	int FIteratorIndex;
	bool FInIterator;
	void __fastcall ListAdapterUpdateFields(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AList);
	
protected:
	virtual TBaseAdapterErrorsList* __fastcall CreateErrorsList(void);
	virtual void __fastcall ExtractRequestParams(System::_di_IInterface ARequest);
	virtual void __fastcall EncodeActionParams(Sitecomp::_di_IAdapterItemRequestParams AParams);
	void __fastcall AddAdapterModeHiddenField(TAdapterHiddenFieldsList* AHiddenFields);
	void __fastcall AddRecordKeysHiddenFields(TAdapterHiddenFieldsList* AHiddenFields);
	void __fastcall AddOrigValueHiddenFields(TAdapterHiddenFieldsList* AHiddenFields);
	void __fastcall CheckModifyAccess(void);
	virtual void __fastcall UpdateFieldsValidateValues(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual void __fastcall UpdateRecordsValidateValues(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual bool __fastcall UpdateRecordsGetAnyChanges(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual bool __fastcall UpdateFieldsGetAnyChanges(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual void __fastcall UpdateFieldsUpdateValues(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual void __fastcall UpdateFieldsExecuteValues(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual void __fastcall UpdateRecordsUpdateValues(Adaptreq::_di_IActionRequest AActionRequest, Contnrs::TObjectList* AAdapterFields);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual TAdapterHiddenFieldOptions __fastcall GetHiddenFieldOptions(void);
	void __fastcall ListHiddenFields(TAdapterHiddenFieldsList* AHiddenFields);
	void __fastcall ListHiddenRecordFields(TAdapterHiddenFieldsList* AHiddenFields);
	virtual TMetaClass* __fastcall GetActionsClass(void);
	virtual TMetaClass* __fastcall GetDataClass(void);
	void __fastcall WebComponentsChange(System::TObject* Sender);
	void __fastcall ClearErrors(void);
	void __fastcall CreateActionRequestContext(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	bool __fastcall HasViewAccess(void);
	virtual bool __fastcall ImplHasViewAccess(void);
	bool __fastcall HasModifyAccess(void);
	virtual bool __fastcall ImplHasModifyAccess(void);
	bool __fastcall HasExecuteAccess(void);
	virtual bool __fastcall ImplHasExecuteAccess(void);
	virtual void __fastcall ImplSetEchoActionFieldValues(bool AValue);
	void __fastcall SetEchoActionFieldValues(bool AValue);
	virtual bool __fastcall ImplGetEchoActionFieldValues(void);
	bool __fastcall GetEchoActionFieldValues(void);
	virtual void __fastcall ImplSetActions(const TAdapterSubComponent* Value);
	void __fastcall SetActions(const TAdapterSubComponent* Value);
	virtual void __fastcall SetData(const TAdapterSubComponent* Value);
	virtual void __fastcall ImplSetData(const TAdapterSubComponent* Value);
	void __fastcall ClearAdapterValues(void);
	virtual void __fastcall ImplClearAdapterValues(void);
	int __fastcall GetIteratorIndex(void);
	virtual int __fastcall ImplGetIteratorIndex(void);
	bool __fastcall InIterator(void);
	virtual bool __fastcall ImplInIterator(void);
	bool __fastcall StartIterator(void * &OwnerData);
	virtual bool __fastcall ImplStartIterator(void * &OwnerData);
	bool __fastcall NextIteration(void * &OwnerData);
	virtual bool __fastcall ImplNextIteration(void * &OwnerData);
	void __fastcall EndIterator(void * OwnerData);
	virtual void __fastcall ImplEndIterator(void * OwnerData);
	_di_IDispatch __fastcall GetScriptObject();
	virtual _di_IDispatch __fastcall ImplGetScriptObject();
	bool __fastcall CanAddFieldClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddFieldClass(Classes::TComponent* AParent, TMetaClass* AClass);
	bool __fastcall CanAddActionClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddActionClass(Classes::TComponent* AParent, TMetaClass* AClass);
	TBaseAdapterErrorsList* __fastcall GetAdapterErrorsList(void);
	void __fastcall NotifyActivate(void);
	void __fastcall NotifyDeactivate(void);
	virtual void __fastcall ImplNotifyActivate(void);
	virtual void __fastcall ImplNotifyDeactivate(void);
	System::TObject* __fastcall GetAdapterErrors(void);
	System::TObject* __fastcall GetAdapterHiddenFields(void);
	System::TObject* __fastcall GetAdapterHiddenRecordFields(void);
	Classes::TComponent* __fastcall GetAdapterFields(void);
	Classes::TComponent* __fastcall GetAdapterActions(void);
	AnsiString __fastcall GetVariableName();
	virtual AnsiString __fastcall ImplGetVariableName();
	Classes::TComponent* __fastcall FindVariable(const AnsiString AName);
	Classes::TComponent* __fastcall FindVariableContainer(const AnsiString AName);
	int __fastcall GetVariableCount(void);
	Classes::TComponent* __fastcall GetVariable(int I);
	virtual Classes::TComponent* __fastcall FindNamedVariable(const AnsiString AName);
	Classes::TComponent* __fastcall FindNamedField(const AnsiString AName);
	Classes::TComponent* __fastcall FindNamedAction(const AnsiString AName);
	virtual Classes::TComponent* __fastcall ImplFindVariable(const AnsiString AName);
	virtual Classes::TComponent* __fastcall ImplFindVariableContainer(const AnsiString AName);
	virtual int __fastcall ImplGetVariableCount(void);
	virtual Classes::TComponent* __fastcall ImplGetVariable(int I);
	void __fastcall GetFieldsList(Classes::TStrings* AList);
	virtual void __fastcall ImplGetFieldsList(Classes::TStrings* AList);
	bool __fastcall IsFieldInUse(const AnsiString AName);
	Webcomp::TWebComponentList* __fastcall GetVisibleFields(void);
	virtual Webcomp::TWebComponentList* __fastcall ImplGetVisibleFields(void);
	Classes::TComponent* __fastcall FindField(const AnsiString AName);
	__property Webcomp::TWebComponentList* VisibleFields = {read=GetVisibleFields};
	void __fastcall GetActionsList(Classes::TStrings* AList);
	virtual void __fastcall ImplGetActionsList(Classes::TStrings* AList);
	bool __fastcall IsActionInUse(const AnsiString AName);
	Webcomp::TWebComponentList* __fastcall GetVisibleActions(void);
	virtual Webcomp::TWebComponentList* __fastcall ImplGetVisibleActions(void);
	Classes::TComponent* __fastcall FindAction(const AnsiString AName);
	__property Webcomp::TWebComponentList* VisibleActions = {read=GetVisibleActions};
	void __fastcall NotifyAdapterChange(void);
	__property Sitecomp::TNotifyList* NotifyList = {read=FNotifyList};
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	
public:
	__fastcall virtual TCustomAdapter(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAdapter(void);
	virtual bool __fastcall UpdateRecords(Adaptreq::_di_IActionRequest AActionRequest = (void *)(0x0));
	__property TIterateRecordsEvent OnIterateRecords = {read=FOnIterateRecords, write=FOnIterateRecords};
	__property TAdapterFields* Data = {read=FData};
	__property TAdapterActions* Actions = {read=FActions};
	__property TBaseAdapterErrorsList* Errors = {read=GetAdapterErrorsList};
	__property bool EchoActionFieldValues = {read=GetEchoActionFieldValues, write=SetEchoActionFieldValues, nodefault};
	__property TActionRequestFieldsHandledEvent OnBeforeUpdateFields = {read=FOnBeforeUpdateFields, write=FOnBeforeUpdateFields};
	__property TActionRequestFieldsEvent OnAfterUpdateFields = {read=FOnAfterUpdateFields, write=FOnAfterUpdateFields};
	__property TActionRequestFieldsHandledEvent OnBeforeValidateFields = {read=FOnBeforeValidateFields, write=FOnBeforeValidateFields};
	__property TActionRequestFieldsEvent OnAfterValidateFields = {read=FOnAfterValidateFields, write=FOnAfterValidateFields};
	__property AnsiString ViewAccess = {read=FViewAccess, write=FViewAccess};
	__property AnsiString ModifyAccess = {read=FModifyAccess, write=FModifyAccess};
	__property AnsiString ExecuteAccess = {read=FExecuteAccess, write=FExecuteAccess};
	__property TAdapterActionExecuteHandledEvent OnBeforeExecuteAction = {read=FOnBeforeExecuteAction, write=FOnBeforeExecuteAction};
	__property TAdapterActionExecuteEvent OnAfterExecuteAction = {read=FOnAfterExecuteAction, write=FOnAfterExecuteAction};
	__property TAdapterActionExecuteHandledEvent OnBeforeGetActionResponse = {read=FOnBeforeGetActionResponse, write=FOnBeforeGetActionResponse};
	__property TAdapterActionExecuteEvent OnAfterGetActionResponse = {read=FOnAfterGetActionResponse, write=FOnAfterGetActionResponse};
	__property TAdapterActionGetParamsEvent OnGetActionParams = {read=FOnGetActionParams, write=FOnGetActionParams};
private:
	void *__IIdentifyAdapter;	/* Webadapt::IIdentifyAdapter */
	void *__IWebVariableName;	/* Httpprod::IWebVariableName */
	void *__IWebVariablesContainer;	/* Httpprod::IWebVariablesContainer */
	void *__INotifyList;	/* Sitecomp::INotifyList */
	void *__IGetAdapterErrors;	/* Sitecomp::IGetAdapterErrors */
	void *__IGetAdapterErrorsList;	/* Webadapt::IGetAdapterErrorsList */
	void *__INotifyWebActivate;	/* Webcomp::INotifyWebActivate */
	void *__IAdapterEditor;	/* Webadapt::IAdapterEditor */
	void *__IGetScriptObject;	/* Sitecomp::IGetScriptObject */
	void *__IGetAdapterFields;	/* Sitecomp::IGetAdapterFields */
	void *__IGetAdapterActions;	/* Sitecomp::IGetAdapterActions */
	void *__IIteratorSupport;	/* Sitecomp::IIteratorSupport */
	void *__IClearAdapterValues;	/* Webadapt::IClearAdapterValues */
	void *__IEchoAdapterFieldValues;	/* Webadapt::IEchoAdapterFieldValues */
	void *__IAdapterAccess;	/* Sitecomp::IAdapterAccess */
	void *__IGetAdapterHiddenFields;	/* Sitecomp::IGetAdapterHiddenFields */
	void *__ICreateActionRequestContext;	/* Webadapt::ICreateActionRequestContext */
	void *__IWebDataFields;	/* Sitecomp::IWebDataFields */
	void *__IWebActionsList;	/* Sitecomp::IWebActionsList */
	void *__IAdapterNotifyAdapterChange;	/* Webadapt::IAdapterNotifyAdapterChange */
	void *__IIteratorIndex;	/* Sitecomp::IIteratorIndex */
	
public:
	operator IIteratorIndex*(void) { return (IIteratorIndex*)&__IIteratorIndex; }
	operator IAdapterNotifyAdapterChange*(void) { return (IAdapterNotifyAdapterChange*)&__IAdapterNotifyAdapterChange; }
	operator IWebActionsList*(void) { return (IWebActionsList*)&__IWebActionsList; }
	operator IWebDataFields*(void) { return (IWebDataFields*)&__IWebDataFields; }
	operator ICreateActionRequestContext*(void) { return (ICreateActionRequestContext*)&__ICreateActionRequestContext; }
	operator IGetAdapterHiddenFields*(void) { return (IGetAdapterHiddenFields*)&__IGetAdapterHiddenFields; }
	operator IAdapterAccess*(void) { return (IAdapterAccess*)&__IAdapterAccess; }
	operator IEchoAdapterFieldValues*(void) { return (IEchoAdapterFieldValues*)&__IEchoAdapterFieldValues; }
	operator IClearAdapterValues*(void) { return (IClearAdapterValues*)&__IClearAdapterValues; }
	operator IIteratorSupport*(void) { return (IIteratorSupport*)&__IIteratorSupport; }
	operator IGetAdapterActions*(void) { return (IGetAdapterActions*)&__IGetAdapterActions; }
	operator IGetAdapterFields*(void) { return (IGetAdapterFields*)&__IGetAdapterFields; }
	operator IGetScriptObject*(void) { return (IGetScriptObject*)&__IGetScriptObject; }
	operator IAdapterEditor*(void) { return (IAdapterEditor*)&__IAdapterEditor; }
	operator INotifyWebActivate*(void) { return (INotifyWebActivate*)&__INotifyWebActivate; }
	operator IGetAdapterErrorsList*(void) { return (IGetAdapterErrorsList*)&__IGetAdapterErrorsList; }
	operator IGetAdapterErrors*(void) { return (IGetAdapterErrors*)&__IGetAdapterErrors; }
	operator INotifyList*(void) { return (INotifyList*)&__INotifyList; }
	operator IWebVariablesContainer*(void) { return (IWebVariablesContainer*)&__IWebVariablesContainer; }
	operator IWebVariableName*(void) { return (IWebVariableName*)&__IWebVariableName; }
	operator IIdentifyAdapter*(void) { return (IIdentifyAdapter*)&__IIdentifyAdapter; }
	
};


class DELPHICLASS TAdapter;
class PASCALIMPLEMENTATION TAdapter : public TCustomAdapter 
{
	typedef TCustomAdapter inherited;
	
__published:
	__property Data ;
	__property Actions ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property OnIterateRecords ;
	__property OnBeforeUpdateFields ;
	__property OnAfterUpdateFields ;
	__property OnBeforeValidateFields ;
	__property OnAfterValidateFields ;
	__property OnBeforeExecuteAction ;
	__property OnAfterExecuteAction ;
	__property OnBeforeGetActionResponse ;
	__property OnAfterGetActionResponse ;
	__property OnGetActionParams ;
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TAdapter(Classes::TComponent* AOwner) : TCustomAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TAdapter(void) { }
	#pragma option pop
	
};


__interface IEchoActionFieldValue;
typedef System::DelphiInterface<IEchoActionFieldValue> _di_IEchoActionFieldValue;
__interface INTERFACE_UUID("{274C6B61-CAD6-11D4-A529-00C04F6BB853}") IEchoActionFieldValue  : public IInterface 
{
	
public:
	virtual void __fastcall SetEchoActionFieldValue(bool AValue) = 0 ;
	virtual bool __fastcall GetEchoActionFieldValue(void) = 0 ;
	__property bool EchoActionFieldValue = {read=GetEchoActionFieldValue, write=SetEchoActionFieldValue};
};

class DELPHICLASS TAdapterNamedField;
class PASCALIMPLEMENTATION TAdapterNamedField : public Webcomp::TWebContainedComponent 
{
	typedef Webcomp::TWebContainedComponent inherited;
	
private:
	AnsiString FFieldName;
	Classes::TComponent* FAdapter;
	AnsiString FViewAccess;
	AnsiString FModifyAccess;
	Adaptreq::_di_IActionFieldValue __fastcall GetActionOrigValue();
	Adaptreq::_di_IActionFieldValue __fastcall GetActionValue();
	bool __fastcall IsFieldNameStored(void);
	
protected:
	virtual AnsiString __fastcall GetDefaultDisplayLabel();
	void __fastcall CheckModifyAccess(void);
	void __fastcall CheckViewAccess(void);
	virtual void __fastcall ParentChanged(void);
	Classes::TComponent* __fastcall GetAdapter(void);
	__property Classes::TComponent* Adapter = {read=GetAdapter};
	virtual bool __fastcall FullyQualifyInputName(void);
	AnsiString __fastcall GetInputName();
	virtual AnsiString __fastcall ImplGetInputName();
	bool __fastcall GetVisible(void);
	bool __fastcall GetRequired(void);
	virtual bool __fastcall ImplGetVisible(void);
	virtual bool __fastcall ImplGetRequired(void);
	bool __fastcall HasViewAccess(void);
	virtual bool __fastcall ImplHasViewAccess(void);
	bool __fastcall HasModifyAccess(void);
	virtual bool __fastcall ImplHasModifyAccess(void);
	_di_IDispatch __fastcall GetScriptObject();
	virtual _di_IDispatch __fastcall ImplGetScriptObject();
	int __fastcall GetDisplayWidth(void);
	virtual int __fastcall ImplGetDisplayWidth(void);
	AnsiString __fastcall GetDisplayLabel();
	virtual AnsiString __fastcall ImplGetDisplayLabel();
	int __fastcall GetMaxLength(void);
	virtual int __fastcall ImplGetMaxLength(void);
	void __fastcall SetFieldName(const AnsiString AName);
	virtual void __fastcall ImplSetFieldName(const AnsiString Value);
	AnsiString __fastcall GetVariableName();
	Variant __fastcall GetValue();
	virtual AnsiString __fastcall ImplGetVariableName();
	virtual AnsiString __fastcall GetDefaultFieldName();
	virtual Variant __fastcall ImplGetValue();
	void __fastcall SetEchoActionFieldValue(bool AValue);
	virtual void __fastcall ImplSetEchoActionFieldValue(bool AValue);
	bool __fastcall GetEchoActionFieldValue(void);
	virtual bool __fastcall ImplGetEchoActionFieldValue(void);
	AnsiString __fastcall AsFormatted();
	virtual AnsiString __fastcall ImplAsFormatted();
	
public:
	__property AnsiString FieldName = {read=GetVariableName, write=SetFieldName, stored=IsFieldNameStored};
	__property Variant Value = {read=GetValue};
	__property AnsiString ViewAccess = {read=FViewAccess, write=FViewAccess};
	__property AnsiString ModifyAccess = {read=FModifyAccess, write=FModifyAccess};
	__property Adaptreq::_di_IActionFieldValue ActionValue = {read=GetActionValue};
	__property Adaptreq::_di_IActionFieldValue ActionOrigValue = {read=GetActionOrigValue};
	__property bool EchoActionFieldValue = {read=GetEchoActionFieldValue, write=SetEchoActionFieldValue, nodefault};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TAdapterNamedField(Classes::TComponent* AOwner) : Webcomp::TWebContainedComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterNamedField(void) { }
	#pragma option pop
	
private:
	void *__IWebVariableName;	/* Httpprod::IWebVariableName */
	void *__IWebInputName;	/* Sitecomp::IWebInputName */
	void *__IWebGetFieldValue;	/* Sitecomp::IWebGetFieldValue */
	void *__IEchoActionFieldValue;	/* Webadapt::IEchoActionFieldValue */
	void *__IAsFormatted;	/* Sitecomp::IAsFormatted */
	void *__IWebGetFieldName;	/* Sitecomp::IWebGetFieldName [GetFieldName=GetVariableName] */
	void *__IWebSetFieldName;	/* Sitecomp::IWebSetFieldName */
	void *__IWebGetDisplayWidth;	/* Sitecomp::IWebGetDisplayWidth */
	void *__IWebGetDisplayLabel;	/* Sitecomp::IWebGetDisplayLabel */
	void *__IWebGetMaxLength;	/* Sitecomp::IWebGetMaxLength */
	void *__IGetScriptObject;	/* Sitecomp::IGetScriptObject */
	void *__IAdapterFieldAccess;	/* Sitecomp::IAdapterFieldAccess */
	void *__IAdapterFieldAttributes;	/* Sitecomp::IAdapterFieldAttributes */
	
public:
	operator IAdapterFieldAttributes*(void) { return (IAdapterFieldAttributes*)&__IAdapterFieldAttributes; }
	operator IAdapterFieldAccess*(void) { return (IAdapterFieldAccess*)&__IAdapterFieldAccess; }
	operator IGetScriptObject*(void) { return (IGetScriptObject*)&__IGetScriptObject; }
	operator IWebGetMaxLength*(void) { return (IWebGetMaxLength*)&__IWebGetMaxLength; }
	operator IWebGetDisplayLabel*(void) { return (IWebGetDisplayLabel*)&__IWebGetDisplayLabel; }
	operator IWebGetDisplayWidth*(void) { return (IWebGetDisplayWidth*)&__IWebGetDisplayWidth; }
	operator IWebSetFieldName*(void) { return (IWebSetFieldName*)&__IWebSetFieldName; }
	operator IWebGetFieldName*(void) { return (IWebGetFieldName*)&__IWebGetFieldName; }
	operator IAsFormatted*(void) { return (IAsFormatted*)&__IAsFormatted; }
	operator IEchoActionFieldValue*(void) { return (IEchoActionFieldValue*)&__IEchoActionFieldValue; }
	operator IWebGetFieldValue*(void) { return (IWebGetFieldValue*)&__IWebGetFieldValue; }
	operator IWebInputName*(void) { return (IWebInputName*)&__IWebInputName; }
	operator IWebVariableName*(void) { return (IWebVariableName*)&__IWebVariableName; }
	
};


class DELPHICLASS TAdapterNamedDisplayField;
class PASCALIMPLEMENTATION TAdapterNamedDisplayField : public TAdapterNamedField 
{
	typedef TAdapterNamedField inherited;
	
private:
	AnsiString FDisplayLabel;
	int FDisplayWidth;
	bool FReadOnly;
	bool FRequired;
	bool __fastcall IsDisplayLabelStored(void);
	
protected:
	AnsiString __fastcall GetDisplayStyle(const AnsiString AAdapterMode);
	AnsiString __fastcall GetViewMode(const AnsiString AAdapterMode);
	AnsiString __fastcall GetInputStyle(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterDisplayHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterDisplayViewModeType __fastcall GetViewModeType(const AnsiString AAdapterMode);
	virtual AnsiString __fastcall ImplGetDisplayLabel();
	virtual int __fastcall ImplGetDisplayWidth(void);
	void __fastcall SetDisplayLabel(const AnsiString AValue);
	virtual bool __fastcall ImplGetRequired(void);
	
public:
	__fastcall virtual TAdapterNamedDisplayField(Classes::TComponent* AOwner);
	__property AnsiString DisplayLabel = {read=ImplGetDisplayLabel, write=SetDisplayLabel, stored=IsDisplayLabelStored};
	__property int DisplayWidth = {read=FDisplayWidth, write=FDisplayWidth, default=-1};
	__property bool Required = {read=FRequired, write=FRequired, default=0};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterNamedDisplayField(void) { }
	#pragma option pop
	
private:
	void *__IGetHTMLStyle;	/* Sitecomp::IGetHTMLStyle */
	
public:
	operator IGetHTMLStyle*(void) { return (IGetHTMLStyle*)&__IGetHTMLStyle; }
	
};


class DELPHICLASS TUpdateFileList;
class PASCALIMPLEMENTATION TUpdateFileList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Adaptreq::_di_IActionFieldValue FValue;
	Httpapp::TAbstractWebRequestFile* __fastcall GetFile(int I);
	int __fastcall GetCount(void);
	
public:
	__fastcall TUpdateFileList(Adaptreq::_di_IActionFieldValue AValue);
	__property int Count = {read=GetCount, nodefault};
	__property Httpapp::TAbstractWebRequestFile* Files[int I] = {read=GetFile};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TUpdateFileList(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TAdapterFieldValidateValueEvent)(System::TObject* Sender, Adaptreq::_di_IActionFieldValue AValue, bool &Handled);

typedef void __fastcall (__closure *TAdapterFieldGetValueEvent)(System::TObject* Sender, Variant &Value);

typedef void __fastcall (__closure *TAdapterFieldValueEvent)(System::TObject* Sender, const Variant &Value);

typedef void __fastcall (__closure *TAdapterFieldStringsEvent)(System::TObject* Sender, Classes::TStrings* Values);

typedef void __fastcall (__closure *TAdapterFieldBooleanValueEvent)(System::TObject* Sender, bool Value);

typedef void __fastcall (__closure *TAdapterFieldFileListEvent)(System::TObject* Sender, TUpdateFileList* Files);

typedef void __fastcall (__closure *TAdapterFieldFileEvent)(System::TObject* Sender, Httpapp::TAbstractWebRequestFile* AFile);

typedef void __fastcall (__closure *TAdapterFieldStringEvent)(System::TObject* Sender, AnsiString Value);

typedef void __fastcall (__closure *TAdapterFieldGetBooleanEvent)(System::TObject* Sender, bool &Value);

typedef void __fastcall (__closure *TAdapterFieldGetStringEvent)(System::TObject* Sender, AnsiString &Value);

typedef void __fastcall (__closure *TAdapterFieldGetMultiValueEvent)(System::TObject* Sender, int Index, Variant &Value);

typedef void __fastcall (__closure *TAdapterFieldGetMultiValueStringEvent)(System::TObject* Sender, int Index, AnsiString &Value);

typedef void __fastcall (__closure *TAdapterFieldGetValueCountEvent)(System::TObject* Sender, int &Count);

typedef void __fastcall (__closure *TAdapterFieldHasValueEvent)(System::TObject* Sender, const Variant &Value, bool &HasValue);

class DELPHICLASS TAdapterUpdateField;
class PASCALIMPLEMENTATION TAdapterUpdateField : public TAdapterNamedDisplayField 
{
	typedef TAdapterNamedDisplayField inherited;
	
private:
	Sitecomp::_di_IValuesListAdapter FValuesList;
	TAdapterFieldGetStringEvent FOnGetDisplayText;
	bool FEchoActionFieldValue;
	TAdapterFieldValidateValueEvent FOnValidateValue;
	void __fastcall SetValuesList(const Sitecomp::_di_IValuesListAdapter Value);
	
protected:
	virtual int __fastcall GetValueCount(void);
	virtual Variant __fastcall GetValues(int I);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall DoOnValidateValue(Adaptreq::_di_IActionFieldValue AValue, bool &AHandled);
	virtual bool __fastcall IsMultiValueField(void);
	virtual Variant __fastcall ConvertValues(Adaptreq::_di_IActionFieldValue AValue, int Index);
	virtual Variant __fastcall ConvertValue(Adaptreq::_di_IActionFieldValue AValue);
	virtual int __fastcall ConvertValueCount(Adaptreq::_di_IActionFieldValue AValue);
	bool __fastcall CheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual bool __fastcall ImplCheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	Sitecomp::_di_IValuesListAdapter __fastcall GetAdapterValuesList();
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	virtual AnsiString __fastcall ImplGetVariableName();
	virtual void __fastcall ImplSetFieldName(const AnsiString Value);
	virtual int __fastcall ImplGetDisplayWidth(void);
	virtual AnsiString __fastcall ImplGetDisplayLabel();
	virtual void __fastcall ImplSetEchoActionFieldValue(bool AValue);
	virtual bool __fastcall ImplGetEchoActionFieldValue(void);
	virtual AnsiString __fastcall ImplAsFormatted();
	void __fastcall ValidateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual void __fastcall ImplValidateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	void __fastcall UpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	
public:
	__fastcall virtual TAdapterUpdateField(Classes::TComponent* AOwner);
	__property Variant Value = {read=GetValue};
	__property Sitecomp::_di_IValuesListAdapter ValuesList = {read=FValuesList, write=SetValuesList};
	__property TAdapterFieldGetStringEvent OnGetDisplayText = {read=FOnGetDisplayText, write=FOnGetDisplayText};
	__property TAdapterFieldValidateValueEvent OnValidateValue = {read=FOnValidateValue, write=FOnValidateValue};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterUpdateField(void) { }
	#pragma option pop
	
private:
	void *__IGetAdapterValuesList;	/* Sitecomp::IGetAdapterValuesList */
	void *__IUpdateValue;	/* Webadapt::IUpdateValue */
	void *__IValidateValue;	/* Webadapt::IValidateValue */
	void *__ICheckValueChange;	/* Webadapt::ICheckValueChange */
	
public:
	operator ICheckValueChange*(void) { return (ICheckValueChange*)&__ICheckValueChange; }
	operator IValidateValue*(void) { return (IValidateValue*)&__IValidateValue; }
	operator IUpdateValue*(void) { return (IUpdateValue*)&__IUpdateValue; }
	operator IGetAdapterValuesList*(void) { return (IGetAdapterValuesList*)&__IGetAdapterValuesList; }
	
};


class DELPHICLASS TCustomAdapterField;
class PASCALIMPLEMENTATION TCustomAdapterField : public TAdapterUpdateField 
{
	typedef TAdapterUpdateField inherited;
	
private:
	TAdapterFieldGetValueEvent FOnGetValue;
	TAdapterFieldValueEvent FOnUpdateValue;
	
protected:
	virtual void __fastcall DoOnValidateValue(Adaptreq::_di_IActionFieldValue AValue, bool &AHandled);
	virtual Variant __fastcall ImplGetValue();
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	
public:
	__property TAdapterFieldGetValueEvent OnGetValue = {read=FOnGetValue, write=FOnGetValue};
	__property TAdapterFieldValueEvent OnUpdateValue = {read=FOnUpdateValue, write=FOnUpdateValue};
public:
	#pragma option push -w-inl
	/* TAdapterUpdateField.Create */ inline __fastcall virtual TCustomAdapterField(Classes::TComponent* AOwner) : TAdapterUpdateField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomAdapterField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterField;
class PASCALIMPLEMENTATION TAdapterField : public TCustomAdapterField 
{
	typedef TCustomAdapterField inherited;
	
__published:
	__property FieldName ;
	__property OnGetValue ;
	__property OnUpdateValue ;
	__property OnValidateValue ;
	__property OnGetDisplayText ;
	__property DisplayWidth  = {default=-1};
	__property DisplayLabel ;
	__property ValuesList ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property Required  = {default=0};
	__property ReadOnly  = {default=0};
public:
	#pragma option push -w-inl
	/* TAdapterUpdateField.Create */ inline __fastcall virtual TAdapterField(Classes::TComponent* AOwner) : TCustomAdapterField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBaseAdapterMultiValueField;
class PASCALIMPLEMENTATION TBaseAdapterMultiValueField : public TAdapterUpdateField 
{
	typedef TAdapterUpdateField inherited;
	
private:
	int FIteratorIndex;
	Classes::TComponent* FFieldValuesAdapter;
	
protected:
	virtual int __fastcall GetValueCount(void);
	virtual Variant __fastcall GetValues(int I);
	bool __fastcall StartValueIterator(void * &OwnerData);
	bool __fastcall NextValueIteration(void * &OwnerData);
	void __fastcall EndValueIterator(void * OwnerData);
	Variant __fastcall GetCurrentValue();
	virtual Variant __fastcall ImplGetCurrentValue();
	bool __fastcall HasValue(const Variant &AValue);
	virtual bool __fastcall ImplHasValue(const Variant &Value);
	Classes::TComponent* __fastcall GetFieldValuesAdapter(void);
	virtual Classes::TComponent* __fastcall ImplGetFieldValuesAdapter(void);
	
public:
	__fastcall virtual TBaseAdapterMultiValueField(Classes::TComponent* AOwner);
	__fastcall virtual ~TBaseAdapterMultiValueField(void);
private:
	void *__IGetFieldValuesAdapter;	/* Sitecomp::IGetFieldValuesAdapter */
	void *__IWebGetFieldValues;	/* Sitecomp::IWebGetFieldValues */
	
public:
	operator IWebGetFieldValues*(void) { return (IWebGetFieldValues*)&__IWebGetFieldValues; }
	operator IGetFieldValuesAdapter*(void) { return (IGetFieldValuesAdapter*)&__IGetFieldValuesAdapter; }
	
};


class DELPHICLASS TCustomAdapterMultiValueField;
class PASCALIMPLEMENTATION TCustomAdapterMultiValueField : public TBaseAdapterMultiValueField 
{
	typedef TBaseAdapterMultiValueField inherited;
	
private:
	TAdapterFieldGetMultiValueEvent FOnGetValues;
	TAdapterFieldGetValueCountEvent FOnGetValueCount;
	TAdapterFieldHasValueEvent FOnHasValue;
	TAdapterFieldStringsEvent FOnUpdateValues;
	TAdapterFieldStringsEvent FOnValidateValues;
	
protected:
	virtual Variant __fastcall GetValues(int I);
	virtual int __fastcall GetValueCount(void);
	virtual void __fastcall DoOnValidateValue(Adaptreq::_di_IActionFieldValue AValue, bool &AHandled);
	virtual bool __fastcall ImplHasValue(const Variant &Value);
	virtual Sitecomp::TAdapterDisplayHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	
public:
	__property int ValueCount = {read=GetValueCount, nodefault};
	__property Variant Values[int I] = {read=GetValues};
	__property TAdapterFieldGetMultiValueEvent OnGetValues = {read=FOnGetValues, write=FOnGetValues};
	__property TAdapterFieldGetValueCountEvent OnGetValueCount = {read=FOnGetValueCount, write=FOnGetValueCount};
	__property TAdapterFieldHasValueEvent OnHasValue = {read=FOnHasValue, write=FOnHasValue};
	__property TAdapterFieldStringsEvent OnUpdateValues = {read=FOnUpdateValues, write=FOnUpdateValues};
	__property TAdapterFieldStringsEvent OnValidateValues = {read=FOnValidateValues, write=FOnValidateValues};
public:
	#pragma option push -w-inl
	/* TBaseAdapterMultiValueField.Create */ inline __fastcall virtual TCustomAdapterMultiValueField(Classes::TComponent* AOwner) : TBaseAdapterMultiValueField(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseAdapterMultiValueField.Destroy */ inline __fastcall virtual ~TCustomAdapterMultiValueField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterMultiValueField;
class PASCALIMPLEMENTATION TAdapterMultiValueField : public TCustomAdapterMultiValueField 
{
	typedef TCustomAdapterMultiValueField inherited;
	
__published:
	__property OnGetValues ;
	__property OnGetValueCount ;
	__property OnHasValue ;
	__property FieldName ;
	__property DisplayWidth  = {default=-1};
	__property DisplayLabel ;
	__property ValuesList ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property Required  = {default=0};
	__property OnUpdateValues ;
	__property OnValidateValues ;
	__property ReadOnly  = {default=0};
public:
	#pragma option push -w-inl
	/* TBaseAdapterMultiValueField.Create */ inline __fastcall virtual TAdapterMultiValueField(Classes::TComponent* AOwner) : TCustomAdapterMultiValueField(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseAdapterMultiValueField.Destroy */ inline __fastcall virtual ~TAdapterMultiValueField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomAdapterBooleanField;
class PASCALIMPLEMENTATION TCustomAdapterBooleanField : public TAdapterUpdateField 
{
	typedef TAdapterUpdateField inherited;
	
private:
	TAdapterFieldGetBooleanEvent FOnGetValue;
	TAdapterFieldBooleanValueEvent FOnUpdateValue;
	
protected:
	virtual Variant __fastcall ConvertValue(Adaptreq::_di_IActionFieldValue AValue);
	bool __fastcall IsEqual(const Variant &AValue);
	virtual bool __fastcall ImplIsEqual(const Variant &AValue);
	virtual Sitecomp::TAdapterDisplayHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	virtual Variant __fastcall ImplGetValue();
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	
public:
	__property TAdapterFieldGetBooleanEvent OnGetValue = {read=FOnGetValue, write=FOnGetValue};
	__property TAdapterFieldBooleanValueEvent OnUpdateValue = {read=FOnUpdateValue, write=FOnUpdateValue};
public:
	#pragma option push -w-inl
	/* TAdapterUpdateField.Create */ inline __fastcall virtual TCustomAdapterBooleanField(Classes::TComponent* AOwner) : TAdapterUpdateField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomAdapterBooleanField(void) { }
	#pragma option pop
	
private:
	void *__IWebValueIsEqual;	/* Sitecomp::IWebValueIsEqual */
	
public:
	operator IWebValueIsEqual*(void) { return (IWebValueIsEqual*)&__IWebValueIsEqual; }
	
};


class DELPHICLASS TAdapterBooleanField;
class PASCALIMPLEMENTATION TAdapterBooleanField : public TCustomAdapterBooleanField 
{
	typedef TCustomAdapterBooleanField inherited;
	
__published:
	__property OnGetValue ;
	__property OnUpdateValue ;
	__property FieldName ;
	__property DisplayWidth  = {default=-1};
	__property DisplayLabel ;
	__property OnValidateValue ;
	__property ValuesList ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property ReadOnly  = {default=0};
public:
	#pragma option push -w-inl
	/* TAdapterUpdateField.Create */ inline __fastcall virtual TAdapterBooleanField(Classes::TComponent* AOwner) : TCustomAdapterBooleanField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterBooleanField(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TImageFieldGetParamsEvent)(System::TObject* Sender, Classes::TStrings* Params);

typedef void __fastcall (__closure *TImageFieldGetImageEvent)(System::TObject* Sender, Classes::TStrings* Params, AnsiString &MimeType, Classes::TStream* &Image, bool &Owned);

typedef void __fastcall (__closure *TImageFieldGetHREFEvent)(System::TObject* Sender, AnsiString &HREF);

class DELPHICLASS TCustomAdapterImageField;
class PASCALIMPLEMENTATION TCustomAdapterImageField : public TAdapterUpdateField 
{
	typedef TAdapterUpdateField inherited;
	
private:
	TImageFieldGetParamsEvent FOnGetParams;
	TImageFieldGetImageEvent FOnGetImage;
	TImageFieldGetHREFEvent FOnGetHREF;
	AnsiString FHREF;
	TAdapterFieldGetStringEvent FOnGetImageName;
	TAdapterFieldFileEvent FOnUploadFile;
	TAdapterFieldFileEvent FOnValidateFile;
	
protected:
	virtual void __fastcall RenderAdapterImage(Adaptreq::_di_IImageRequest ARequest, Adaptreq::_di_IImageResponse AResponse);
	virtual void __fastcall DoOnValidateValue(Adaptreq::_di_IActionFieldValue AValue, bool &AHandled);
	void __fastcall CreateRequestContext(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	void __fastcall ImplCreateRequestContext(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	bool __fastcall HandleRequest(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	virtual bool __fastcall ImplHandleRequest(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	virtual bool __fastcall ImplCheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	bool __fastcall WebImageHREF(AnsiString &AHREF);
	virtual bool __fastcall ImplWebImageHREF(AnsiString &AHREF);
	virtual Sitecomp::TAdapterDisplayHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	System::_di_IInterface __fastcall GetAdapterImage();
	void __fastcall GetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams AParams);
	virtual Variant __fastcall ImplGetValue();
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	
public:
	__property TAdapterFieldGetStringEvent OnGetImageName = {read=FOnGetImageName, write=FOnGetImageName};
	__property TAdapterFieldFileEvent OnUploadFile = {read=FOnUploadFile, write=FOnUploadFile};
	__property TAdapterFieldFileEvent OnValidateFile = {read=FOnValidateFile, write=FOnValidateFile};
	__property AnsiString HREF = {read=FHREF, write=FHREF};
	__property TImageFieldGetParamsEvent OnGetParams = {read=FOnGetParams, write=FOnGetParams};
	__property TImageFieldGetImageEvent OnGetImage = {read=FOnGetImage, write=FOnGetImage};
	__property TImageFieldGetHREFEvent OnGetHREF = {read=FOnGetHREF, write=FOnGetHREF};
	__property ReadOnly  = {default=0};
public:
	#pragma option push -w-inl
	/* TAdapterUpdateField.Create */ inline __fastcall virtual TCustomAdapterImageField(Classes::TComponent* AOwner) : TAdapterUpdateField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomAdapterImageField(void) { }
	#pragma option pop
	
private:
	void *__IGetAdapterImage;	/* Sitecomp::IGetAdapterImage */
	void *__IGetAdapterItemRequestParams;	/* Sitecomp::IGetAdapterItemRequestParams */
	void *__IAdapterRequestHandler;	/* Sitecomp::IAdapterRequestHandler */
	void *__IWebImageHREF;	/* Sitecomp::IWebImageHREF */
	
public:
	operator IWebImageHREF*(void) { return (IWebImageHREF*)&__IWebImageHREF; }
	operator IAdapterRequestHandler*(void) { return (IAdapterRequestHandler*)&__IAdapterRequestHandler; }
	operator IGetAdapterItemRequestParams*(void) { return (IGetAdapterItemRequestParams*)&__IGetAdapterItemRequestParams; }
	operator IGetAdapterImage*(void) { return (IGetAdapterImage*)&__IGetAdapterImage; }
	
};


class DELPHICLASS TAdapterImageField;
class PASCALIMPLEMENTATION TAdapterImageField : public TCustomAdapterImageField 
{
	typedef TCustomAdapterImageField inherited;
	
__published:
	__property OnGetParams ;
	__property OnGetImage ;
	__property OnGetImageName ;
	__property OnGetHREF ;
	__property OnValidateFile ;
	__property OnUploadFile ;
	__property HREF ;
	__property FieldName ;
	__property DisplayWidth  = {default=-1};
	__property DisplayLabel ;
	__property ValuesList ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property Required  = {default=0};
	__property ReadOnly  = {default=0};
public:
	#pragma option push -w-inl
	/* TAdapterUpdateField.Create */ inline __fastcall virtual TAdapterImageField(Classes::TComponent* AOwner) : TCustomAdapterImageField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterImageField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomAdapterFileField;
class PASCALIMPLEMENTATION TCustomAdapterFileField : public TBaseAdapterMultiValueField 
{
	typedef TBaseAdapterMultiValueField inherited;
	
private:
	TAdapterFieldFileListEvent FOnUploadFiles;
	TAdapterFieldGetMultiValueStringEvent FOnGetFileNames;
	TAdapterFieldGetValueCountEvent FOnGetFileCount;
	TAdapterFieldFileListEvent FOnValidateFiles;
	
protected:
	AnsiString __fastcall GetFileNames(int I);
	virtual Variant __fastcall GetValues(int I);
	virtual int __fastcall GetValueCount(void);
	virtual void __fastcall DoOnValidateValue(Adaptreq::_di_IActionFieldValue AValue, bool &AHandled);
	virtual bool __fastcall ImplCheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual Sitecomp::TAdapterDisplayHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	
public:
	__property TAdapterFieldFileListEvent OnValidateFiles = {read=FOnValidateFiles, write=FOnValidateFiles};
	__property TAdapterFieldFileListEvent OnUploadFiles = {read=FOnUploadFiles, write=FOnUploadFiles};
	__property int FileCount = {read=GetValueCount, nodefault};
	__property AnsiString FileNames[int I] = {read=GetFileNames};
	__property TAdapterFieldGetMultiValueStringEvent OnGetFileNames = {read=FOnGetFileNames, write=FOnGetFileNames};
	__property TAdapterFieldGetValueCountEvent OnGetFileCount = {read=FOnGetFileCount, write=FOnGetFileCount};
public:
	#pragma option push -w-inl
	/* TBaseAdapterMultiValueField.Create */ inline __fastcall virtual TCustomAdapterFileField(Classes::TComponent* AOwner) : TBaseAdapterMultiValueField(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseAdapterMultiValueField.Destroy */ inline __fastcall virtual ~TCustomAdapterFileField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterFileField;
class PASCALIMPLEMENTATION TAdapterFileField : public TCustomAdapterFileField 
{
	typedef TCustomAdapterFileField inherited;
	
__published:
	__property OnGetFileNames ;
	__property OnGetFileCount ;
	__property OnUploadFiles ;
	__property OnValidateFiles ;
	__property FieldName ;
	__property DisplayWidth  = {default=-1};
	__property DisplayLabel ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property Required  = {default=0};
	__property ReadOnly  = {default=0};
public:
	#pragma option push -w-inl
	/* TBaseAdapterMultiValueField.Create */ inline __fastcall virtual TAdapterFileField(Classes::TComponent* AOwner) : TCustomAdapterFileField(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseAdapterMultiValueField.Destroy */ inline __fastcall virtual ~TAdapterFileField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomAdapterMemoField;
class PASCALIMPLEMENTATION TCustomAdapterMemoField : public TAdapterUpdateField 
{
	typedef TAdapterUpdateField inherited;
	
private:
	TAdapterFieldGetStringEvent FOnGetValue;
	TAdapterFieldFileEvent FOnUploadFile;
	TAdapterFieldStringEvent FOnUpdateValue;
	
protected:
	virtual void __fastcall DoOnValidateValue(Adaptreq::_di_IActionFieldValue AValue, bool &AHandled);
	virtual bool __fastcall ImplCheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual Sitecomp::TAdapterDisplayHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	virtual Variant __fastcall ImplGetValue();
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	
public:
	__property TAdapterFieldStringEvent OnUpdateValue = {read=FOnUpdateValue, write=FOnUpdateValue};
	__property TAdapterFieldFileEvent OnUploadFile = {read=FOnUploadFile, write=FOnUploadFile};
	__property TAdapterFieldGetStringEvent OnGetValue = {read=FOnGetValue, write=FOnGetValue};
public:
	#pragma option push -w-inl
	/* TAdapterUpdateField.Create */ inline __fastcall virtual TCustomAdapterMemoField(Classes::TComponent* AOwner) : TAdapterUpdateField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomAdapterMemoField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterMemoField;
class PASCALIMPLEMENTATION TAdapterMemoField : public TCustomAdapterMemoField 
{
	typedef TCustomAdapterMemoField inherited;
	
__published:
	__property OnGetValue ;
	__property OnUpdateValue ;
	__property OnUploadFile ;
	__property FieldName ;
	__property DisplayWidth  = {default=-1};
	__property DisplayLabel ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property Required  = {default=0};
	__property ReadOnly  = {default=0};
public:
	#pragma option push -w-inl
	/* TAdapterUpdateField.Create */ inline __fastcall virtual TAdapterMemoField(Classes::TComponent* AOwner) : TCustomAdapterMemoField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterMemoField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDefaultFieldsAdapter;
class PASCALIMPLEMENTATION TDefaultFieldsAdapter : public TCustomAdapter 
{
	typedef TCustomAdapter inherited;
	
private:
	TAdapterDefaultFields* FData;
	TAdapterDefaultActions* FActions;
	
protected:
	virtual void __fastcall AddDefaultFields(Webcomp::TWebComponentList* AComponents);
	virtual void __fastcall AddDefaultActions(Webcomp::TWebComponentList* AComponents);
	void __fastcall DefaultWebComponentsChange(System::TObject* Sender);
	virtual TMetaClass* __fastcall GetActionsClass(void);
	virtual TMetaClass* __fastcall GetDataClass(void);
	virtual void __fastcall ImplSetActions(const TAdapterSubComponent* Value);
	virtual void __fastcall ImplSetData(const TAdapterSubComponent* Value);
	virtual Webcomp::TWebComponentList* __fastcall ImplGetVisibleFields(void);
	virtual Webcomp::TWebComponentList* __fastcall ImplGetVisibleActions(void);
	
public:
	__property TAdapterDefaultFields* Data = {read=FData};
	__property TAdapterDefaultActions* Actions = {read=FActions};
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TDefaultFieldsAdapter(Classes::TComponent* AOwner) : TCustomAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TDefaultFieldsAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDefaultFieldsPagedAdapter;
class PASCALIMPLEMENTATION TDefaultFieldsPagedAdapter : public TDefaultFieldsAdapter 
{
	typedef TDefaultFieldsAdapter inherited;
	
private:
	int FCurrentPage;
	int FPageSize;
	TGetRecordCountEvent FOnGetRecordCount;
	TGetRecordIndexEvent FOnGetRecordIndex;
	TGetEOFEvent FOnGetEOF;
	TGetRecordEvent FOnGetNextRecord;
	TGetRecordEvent FOnGetFirstRecord;
	
protected:
	virtual void __fastcall EncodeActionParams(Sitecomp::_di_IAdapterItemRequestParams AParams);
	virtual void __fastcall ExtractRequestParams(System::_di_IInterface ARequest);
	virtual bool __fastcall GetNextRecord(void);
	virtual bool __fastcall GetFirstRecord(void);
	virtual bool __fastcall GetEOF(void);
	virtual int __fastcall GetRecordIndex(void);
	virtual int __fastcall GetRecordCount(void);
	virtual void __fastcall ImplNotifyDeactivate(void);
	virtual bool __fastcall ImplCanAddActionClass(Classes::TComponent* AParent, TMetaClass* AClass);
	void __fastcall SkipToPage(void);
	bool __fastcall EndOfPage(void);
	virtual void __fastcall AddDefaultActions(Webcomp::TWebComponentList* AComponents);
	virtual void __fastcall ImplGetActionsList(Classes::TStrings* AList);
	int __fastcall GetPageCount(void);
	void __fastcall SetPageSize(const int Value);
	virtual bool __fastcall ImplNextIteration(void * &OwnerData);
	virtual bool __fastcall ImplStartIterator(void * &OwnerData);
	virtual void __fastcall ImplEndIterator(void * OwnerData);
	
public:
	__property TGetRecordIndexEvent OnGetRecordIndex = {read=FOnGetRecordIndex, write=FOnGetRecordIndex};
	__property TGetEOFEvent OnGetEOF = {read=FOnGetEOF, write=FOnGetEOF};
	__property TGetRecordCountEvent OnGetRecordCount = {read=FOnGetRecordCount, write=FOnGetRecordCount};
	__property TGetRecordEvent OnGetFirstRecord = {read=FOnGetFirstRecord, write=FOnGetFirstRecord};
	__property TGetRecordEvent OnGetNextRecord = {read=FOnGetNextRecord, write=FOnGetNextRecord};
	__property int PageSize = {read=FPageSize, write=SetPageSize, default=0};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property int CurrentPage = {read=FCurrentPage, write=FCurrentPage, nodefault};
	__property int RecordIndex = {read=GetRecordIndex, nodefault};
	__property int RecordCount = {read=GetRecordCount, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TDefaultFieldsPagedAdapter(Classes::TComponent* AOwner) : TDefaultFieldsAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TDefaultFieldsPagedAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomPagedAdapter;
class PASCALIMPLEMENTATION TCustomPagedAdapter : public TDefaultFieldsPagedAdapter 
{
	typedef TDefaultFieldsPagedAdapter inherited;
	
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TCustomPagedAdapter(Classes::TComponent* AOwner) : TDefaultFieldsPagedAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TCustomPagedAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPagedAdapter;
class PASCALIMPLEMENTATION TPagedAdapter : public TCustomPagedAdapter 
{
	typedef TCustomPagedAdapter inherited;
	
__published:
	__property Data ;
	__property Actions ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property OnBeforeUpdateFields ;
	__property OnAfterUpdateFields ;
	__property OnBeforeValidateFields ;
	__property OnAfterValidateFields ;
	__property OnBeforeExecuteAction ;
	__property OnAfterExecuteAction ;
	__property OnBeforeGetActionResponse ;
	__property OnAfterGetActionResponse ;
	__property OnGetActionParams ;
	__property OnGetRecordIndex ;
	__property OnGetRecordCount ;
	__property OnGetEOF ;
	__property OnGetFirstRecord ;
	__property OnGetNextRecord ;
	__property PageSize  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TPagedAdapter(Classes::TComponent* AOwner) : TCustomPagedAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TPagedAdapter(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TActionExecuteEvent)(System::TObject* Sender, Classes::TStrings* Params);

class DELPHICLASS TAdapterLoginField;
class DELPHICLASS TCustomLoginFormAdapter;
class PASCALIMPLEMENTATION TAdapterLoginField : public TAdapterNamedDisplayField 
{
	typedef TAdapterNamedDisplayField inherited;
	
protected:
	HIDESBASE TCustomLoginFormAdapter* __fastcall GetAdapter(void);
	
public:
	__property TCustomLoginFormAdapter* Adapter = {read=GetAdapter};
public:
	#pragma option push -w-inl
	/* TAdapterNamedDisplayField.Create */ inline __fastcall virtual TAdapterLoginField(Classes::TComponent* AOwner) : TAdapterNamedDisplayField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterLoginField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterUserNameField;
class PASCALIMPLEMENTATION TAdapterUserNameField : public TAdapterLoginField 
{
	typedef TAdapterLoginField inherited;
	
protected:
	virtual Variant __fastcall ImplGetValue();
	
__published:
	__property FieldName ;
	__property DisplayLabel ;
	__property DisplayWidth  = {default=-1};
public:
	#pragma option push -w-inl
	/* TAdapterNamedDisplayField.Create */ inline __fastcall virtual TAdapterUserNameField(Classes::TComponent* AOwner) : TAdapterLoginField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterUserNameField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterPasswordField;
class PASCALIMPLEMENTATION TAdapterPasswordField : public TAdapterLoginField 
{
	typedef TAdapterLoginField inherited;
	
protected:
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	virtual Variant __fastcall ImplGetValue();
	
__published:
	__property FieldName ;
	__property DisplayLabel ;
	__property DisplayWidth  = {default=-1};
public:
	#pragma option push -w-inl
	/* TAdapterNamedDisplayField.Create */ inline __fastcall virtual TAdapterPasswordField(Classes::TComponent* AOwner) : TAdapterLoginField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterPasswordField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterNextPageField;
class PASCALIMPLEMENTATION TAdapterNextPageField : public TAdapterLoginField 
{
	typedef TAdapterLoginField inherited;
	
private:
	Classes::TComponent* FPageList;
	bool FEchoActionFieldValue;
	
protected:
	virtual void __fastcall ImplSetEchoActionFieldValue(bool AValue);
	virtual bool __fastcall ImplGetEchoActionFieldValue(void);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	void __fastcall UpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual Variant __fastcall ImplGetValue();
	Sitecomp::_di_IValuesListAdapter __fastcall GetAdapterValuesList();
	
public:
	__fastcall virtual ~TAdapterNextPageField(void);
	
__published:
	__property FieldName ;
	__property DisplayLabel ;
	__property DisplayWidth  = {default=-1};
public:
	#pragma option push -w-inl
	/* TAdapterNamedDisplayField.Create */ inline __fastcall virtual TAdapterNextPageField(Classes::TComponent* AOwner) : TAdapterLoginField(AOwner) { }
	#pragma option pop
	
private:
	void *__IGetAdapterValuesList;	/* Sitecomp::IGetAdapterValuesList */
	void *__IUpdateValue;	/* Webadapt::IUpdateValue */
	
public:
	operator IUpdateValue*(void) { return (IUpdateValue*)&__IUpdateValue; }
	operator IGetAdapterValuesList*(void) { return (IGetAdapterValuesList*)&__IGetAdapterValuesList; }
	
};


typedef void __fastcall (__closure *TActionExecuteHandledEvent)(System::TObject* Sender, Classes::TStrings* Params, bool &Handled);

typedef void __fastcall (__closure *TActionGetParamsEvent)(System::TObject* Sender, Classes::TStrings* Params);

typedef void __fastcall (__closure *TActionGetEnabledEvent)(System::TObject* Sender, bool &Enabled);

typedef void __fastcall (__closure *THandledEvent)(System::TObject* Sender, bool &Handled);

class DELPHICLASS TBaseAdapterAction;
class PASCALIMPLEMENTATION TBaseAdapterAction : public Webcomp::TWebContainedComponent 
{
	typedef Webcomp::TWebContainedComponent inherited;
	
private:
	int FIteratorIndex;
	bool FInIterator;
	AnsiString FDisplayLabel;
	Classes::TComponent* FAdapter;
	AnsiString FExecuteAccess;
	TActionExecuteHandledEvent FOnBeforeExecute;
	TActionExecuteEvent FOnAfterExecute;
	TActionExecuteEvent FOnAfterGetResponse;
	TActionExecuteHandledEvent FOnBeforeGetResponse;
	Adaptreq::TAdapterActionRedirectOptions FRedirectOptions;
	TActionGetParamsEvent FOnGetParams;
	bool __fastcall IsDisplayLabelStored(void);
	
protected:
	virtual AnsiString __fastcall GetDefaultDisplayLabel();
	void __fastcall SetDisplayLabel(const AnsiString Value);
	void __fastcall CheckExecuteAccess(void);
	virtual void __fastcall ParentChanged(void);
	TCustomAdapter* __fastcall GetAdapter(void);
	__property TCustomAdapter* Adapter = {read=GetAdapter};
	TBaseAdapterErrorsList* __fastcall GetErrors(void);
	__property TBaseAdapterErrorsList* Errors = {read=GetErrors};
	virtual void __fastcall DoBeforeExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual void __fastcall DoAfterExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual void __fastcall DoBeforeGetExecuteActionResponse(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual void __fastcall DoAfterGetExecuteActionResponse(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	void __fastcall GetExecuteActionResponse(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual void __fastcall ImplGetExecuteActionResponse(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	void __fastcall ExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual int __fastcall GetItemCount(void);
	int __fastcall GetIteratorIndex(void);
	virtual int __fastcall ImplGetIteratorIndex(void);
	bool __fastcall InIterator(void);
	virtual bool __fastcall ImplInIterator(void);
	bool __fastcall IsDefaultAction(System::TObject* ADisplay);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	bool __fastcall GetIsAdapterActionList(void);
	virtual bool __fastcall ImplGetIsAdapterActionList(void);
	bool __fastcall GetVisible(void);
	virtual bool __fastcall ImplGetVisible(void);
	AnsiString __fastcall GetDisplayStyle(const AnsiString AAdapterMode);
	AnsiString __fastcall GetViewMode(const AnsiString AAdapterMode);
	AnsiString __fastcall GetInputStyle(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterActionHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterDisplayViewModeType __fastcall GetViewModeType(const AnsiString AAdapterMode);
	Adaptreq::TAdapterActionRedirectOptions __fastcall GetFailureOptions(void);
	Adaptreq::TAdapterActionRedirectOptions __fastcall GetSuccessOptions(void);
	virtual Adaptreq::TAdapterActionRedirectOptions __fastcall ImplGetFailureOptions(void);
	virtual Adaptreq::TAdapterActionRedirectOptions __fastcall ImplGetSuccessOptions(void);
	bool __fastcall StartIterator(void * &OwnerData);
	bool __fastcall NextIteration(void * &OwnerData);
	void __fastcall EndIterator(void * OwnerData);
	bool __fastcall ImplStartIterator(void * &OwnerData);
	bool __fastcall ImplNextIteration(void * &OwnerData);
	void __fastcall ImplEndIterator(void * OwnerData);
	void __fastcall CreateRequestContext(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	void __fastcall ImplCreateRequestContext(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	bool __fastcall HandleRequest(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	virtual bool __fastcall ImplHandleRequest(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	bool __fastcall HasExecuteAccess(void);
	virtual bool __fastcall ImplHasExecuteAccess(void);
	_di_IDispatch __fastcall GetScriptObject();
	virtual _di_IDispatch __fastcall ImplGetScriptObject();
	AnsiString __fastcall GetDisplayLabel();
	virtual AnsiString __fastcall ImplGetDisplayLabel();
	AnsiString __fastcall GetVariableName();
	AnsiString __fastcall ImplGetVariableName();
	void __fastcall GetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams Params);
	virtual void __fastcall ImplGetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams Params);
	bool __fastcall WebEnabled(void);
	virtual bool __fastcall ImplWebEnabled(void);
	AnsiString __fastcall GetActionName();
	virtual AnsiString __fastcall ImplGetActionName();
	virtual AnsiString __fastcall GetDefaultActionName();
	
public:
	__property AnsiString ActionName = {read=GetActionName};
	__property AnsiString ExecuteAccess = {read=FExecuteAccess, write=FExecuteAccess};
	__property AnsiString DisplayLabel = {read=ImplGetDisplayLabel, write=SetDisplayLabel, stored=IsDisplayLabelStored};
	__property TActionExecuteHandledEvent OnBeforeExecute = {read=FOnBeforeExecute, write=FOnBeforeExecute};
	__property TActionExecuteEvent OnAfterExecute = {read=FOnAfterExecute, write=FOnAfterExecute};
	__property TActionExecuteHandledEvent OnBeforeGetResponse = {read=FOnBeforeGetResponse, write=FOnBeforeGetResponse};
	__property TActionExecuteEvent OnAfterGetResponse = {read=FOnAfterGetResponse, write=FOnAfterGetResponse};
	__property Adaptreq::TAdapterActionRedirectOptions RedirectOptions = {read=FRedirectOptions, write=FRedirectOptions, default=0};
	__property TActionGetParamsEvent OnGetParams = {read=FOnGetParams, write=FOnGetParams};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property int ItemIndex = {read=FIteratorIndex, nodefault};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TBaseAdapterAction(Classes::TComponent* AOwner) : Webcomp::TWebContainedComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TBaseAdapterAction(void) { }
	#pragma option pop
	
private:
	void *__IWebVariableName;	/* Httpprod::IWebVariableName */
	void *__IWebEnabled;	/* Sitecomp::IWebEnabled */
	void *__IGetAdapterItemRequestParams;	/* Sitecomp::IGetAdapterItemRequestParams */
	void *__IWebGetActionName;	/* Sitecomp::IWebGetActionName */
	void *__IWebGetDisplayLabel;	/* Sitecomp::IWebGetDisplayLabel */
	void *__IGetScriptObject;	/* Sitecomp::IGetScriptObject */
	void *__IAdapterActionAccess;	/* Sitecomp::IAdapterActionAccess */
	void *__IAdapterRequestHandler;	/* Sitecomp::IAdapterRequestHandler */
	void *__IGetAdapterActionRedirectOptions;	/* Adaptreq::IGetAdapterActionRedirectOptions */
	void *__IGetHTMLStyle;	/* Sitecomp::IGetHTMLStyle */
	void *__IAdapterActionAttributes;	/* Sitecomp::IAdapterActionAttributes */
	void *__IIteratorSupport;	/* Sitecomp::IIteratorSupport */
	void *__IIteratorIndex;	/* Sitecomp::IIteratorIndex */
	void *__IIsAdapterActionList;	/* Sitecomp::IIsAdapterActionList */
	void *__IWebIsDefaultAction;	/* Sitecomp::IWebIsDefaultAction */
	
public:
	operator IWebIsDefaultAction*(void) { return (IWebIsDefaultAction*)&__IWebIsDefaultAction; }
	operator IIsAdapterActionList*(void) { return (IIsAdapterActionList*)&__IIsAdapterActionList; }
	operator IIteratorIndex*(void) { return (IIteratorIndex*)&__IIteratorIndex; }
	operator IIteratorSupport*(void) { return (IIteratorSupport*)&__IIteratorSupport; }
	operator IAdapterActionAttributes*(void) { return (IAdapterActionAttributes*)&__IAdapterActionAttributes; }
	operator IGetHTMLStyle*(void) { return (IGetHTMLStyle*)&__IGetHTMLStyle; }
	operator IGetAdapterActionRedirectOptions*(void) { return (IGetAdapterActionRedirectOptions*)&__IGetAdapterActionRedirectOptions; }
	operator IAdapterRequestHandler*(void) { return (IAdapterRequestHandler*)&__IAdapterRequestHandler; }
	operator IAdapterActionAccess*(void) { return (IAdapterActionAccess*)&__IAdapterActionAccess; }
	operator IGetScriptObject*(void) { return (IGetScriptObject*)&__IGetScriptObject; }
	operator IWebGetDisplayLabel*(void) { return (IWebGetDisplayLabel*)&__IWebGetDisplayLabel; }
	operator IWebGetActionName*(void) { return (IWebGetActionName*)&__IWebGetActionName; }
	operator IGetAdapterItemRequestParams*(void) { return (IGetAdapterItemRequestParams*)&__IGetAdapterItemRequestParams; }
	operator IWebEnabled*(void) { return (IWebEnabled*)&__IWebEnabled; }
	operator IWebVariableName*(void) { return (IWebVariableName*)&__IWebVariableName; }
	
};


class DELPHICLASS TCustomAdapterAction;
class PASCALIMPLEMENTATION TCustomAdapterAction : public TBaseAdapterAction 
{
	typedef TBaseAdapterAction inherited;
	
private:
	AnsiString FActionName;
	TActionExecuteEvent FOnExecute;
	TActionGetEnabledEvent FOnGetEnabled;
	bool __fastcall IsActionNameStored(void);
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	void __fastcall SetActionName(const AnsiString Value);
	void __fastcall ImplSetActionName(const AnsiString Value);
	virtual void __fastcall ImplGetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams Params);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall ImplGetActionName();
	virtual Adaptreq::TAdapterActionRedirectOptions __fastcall ImplGetSuccessOptions(void);
	
public:
	__property AnsiString ActionName = {read=ImplGetActionName, write=ImplSetActionName, stored=IsActionNameStored};
	__property TActionExecuteEvent OnExecute = {read=FOnExecute, write=FOnExecute};
	__property TActionGetEnabledEvent OnGetEnabled = {read=FOnGetEnabled, write=FOnGetEnabled};
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TCustomAdapterAction(Classes::TComponent* AOwner) : TBaseAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomAdapterAction(void) { }
	#pragma option pop
	
private:
	void *__IWebSetActionName;	/* Sitecomp::IWebSetActionName */
	
public:
	operator IWebSetActionName*(void) { return (IWebSetActionName*)&__IWebSetActionName; }
	
};


class DELPHICLASS TImplementedAdapterAction;
class PASCALIMPLEMENTATION TImplementedAdapterAction : public TCustomAdapterAction 
{
	typedef TCustomAdapterAction inherited;
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TImplementedAdapterAction(Classes::TComponent* AOwner) : TCustomAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TImplementedAdapterAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomPagedAdapterAction;
class PASCALIMPLEMENTATION TCustomPagedAdapterAction : public TImplementedAdapterAction 
{
	typedef TImplementedAdapterAction inherited;
	
protected:
	HIDESBASE TDefaultFieldsPagedAdapter* __fastcall GetAdapter(void);
	__property TDefaultFieldsPagedAdapter* Adapter = {read=GetAdapter};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TCustomPagedAdapterAction(Classes::TComponent* AOwner) : TImplementedAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomPagedAdapterAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomAdapterPageAction;
class PASCALIMPLEMENTATION TCustomAdapterPageAction : public TCustomPagedAdapterAction 
{
	typedef TCustomPagedAdapterAction inherited;
	
protected:
	virtual bool __fastcall GetNewPage(int &AValue);
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	virtual void __fastcall ImplGetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams Params);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual Sitecomp::TAdapterActionHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TCustomAdapterPageAction(Classes::TComponent* AOwner) : TCustomPagedAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomAdapterPageAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterNextPageAction;
class PASCALIMPLEMENTATION TAdapterNextPageAction : public TCustomAdapterPageAction 
{
	typedef TCustomAdapterPageAction inherited;
	
protected:
	virtual bool __fastcall GetNewPage(int &AValue);
	virtual AnsiString __fastcall GetDefaultActionName();
	virtual AnsiString __fastcall GetDefaultDisplayLabel();
	
__published:
	__property OnGetParams ;
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property RedirectOptions  = {default=0};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TAdapterNextPageAction(Classes::TComponent* AOwner) : TCustomAdapterPageAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterNextPageAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterPrevPageAction;
class PASCALIMPLEMENTATION TAdapterPrevPageAction : public TCustomAdapterPageAction 
{
	typedef TCustomAdapterPageAction inherited;
	
protected:
	virtual bool __fastcall GetNewPage(int &AValue);
	virtual AnsiString __fastcall GetDefaultActionName();
	virtual AnsiString __fastcall GetDefaultDisplayLabel();
	
__published:
	__property OnGetParams ;
	__property DisplayLabel ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property RedirectOptions  = {default=0};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TAdapterPrevPageAction(Classes::TComponent* AOwner) : TCustomAdapterPageAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterPrevPageAction(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TWebFormGetPageNameEvent)(System::TObject* Sender, int APageIndex, AnsiString &Value);

class DELPHICLASS TCustomAdapterGotoPageAction;
class PASCALIMPLEMENTATION TCustomAdapterGotoPageAction : public TCustomPagedAdapterAction 
{
	typedef TCustomPagedAdapterAction inherited;
	
private:
	TWebFormGetPageNameEvent FOnGetPageName;
	
protected:
	virtual int __fastcall GetItemCount(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplIsDefaultAction(System::TObject* ADisplay);
	virtual AnsiString __fastcall ImplGetDisplayLabel();
	virtual bool __fastcall ImplGetIsAdapterActionList(void);
	virtual void __fastcall ImplGetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams Params);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual Sitecomp::TAdapterActionHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	
public:
	__property TWebFormGetPageNameEvent OnGetPageName = {read=FOnGetPageName, write=FOnGetPageName};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TCustomAdapterGotoPageAction(Classes::TComponent* AOwner) : TCustomPagedAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomAdapterGotoPageAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterGotoPageAction;
class PASCALIMPLEMENTATION TAdapterGotoPageAction : public TCustomAdapterGotoPageAction 
{
	typedef TCustomAdapterGotoPageAction inherited;
	
__published:
	__property OnGetParams ;
	__property ExecuteAccess ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property RedirectOptions  = {default=0};
	__property OnGetPageName ;
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TAdapterGotoPageAction(Classes::TComponent* AOwner) : TCustomAdapterGotoPageAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterGotoPageAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomLoginFormAdapterAction;
class PASCALIMPLEMENTATION TCustomLoginFormAdapterAction : public TImplementedAdapterAction 
{
	typedef TImplementedAdapterAction inherited;
	
private:
	HIDESBASE TCustomLoginFormAdapter* __fastcall GetAdapter(void);
	
protected:
	__property TCustomLoginFormAdapter* Adapter = {read=GetAdapter};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TCustomLoginFormAdapterAction(Classes::TComponent* AOwner) : TImplementedAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomLoginFormAdapterAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLoginFormAdapterLoginAction;
class PASCALIMPLEMENTATION TLoginFormAdapterLoginAction : public TCustomLoginFormAdapterAction 
{
	typedef TCustomLoginFormAdapterAction inherited;
	
private:
	Classes::TStrings* __fastcall GetLoginStrings(void);
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual void __fastcall ImplGetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams Params);
	virtual AnsiString __fastcall NextPage();
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__property DisplayLabel ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
	__property OnGetParams ;
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TLoginFormAdapterLoginAction(Classes::TComponent* AOwner) : TCustomLoginFormAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TLoginFormAdapterLoginAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterAction;
class PASCALIMPLEMENTATION TAdapterAction : public TCustomAdapterAction 
{
	typedef TCustomAdapterAction inherited;
	
__published:
	__property ActionName ;
	__property ExecuteAccess ;
	__property OnExecute ;
	__property OnGetParams ;
	__property OnGetEnabled ;
	__property DisplayLabel ;
	__property RedirectOptions  = {default=0};
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TAdapterAction(Classes::TComponent* AOwner) : TCustomAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAbstractFieldValuesAdapter;
class PASCALIMPLEMENTATION TAbstractFieldValuesAdapter : public TDefaultFieldsAdapter 
{
	typedef TDefaultFieldsAdapter inherited;
	
protected:
	virtual TMetaClass* __fastcall GetValueFieldClass(void) = 0 ;
	virtual _di_IDispatch __fastcall ImplGetScriptObject();
	virtual bool __fastcall ImplStartIterator(void * &OwnerData);
	virtual bool __fastcall ImplNextIteration(void * &OwnerData);
	virtual void __fastcall ImplEndIterator(void * OwnerData);
	System::TObject* __fastcall GetField(void);
	virtual System::TObject* __fastcall ImplGetField(void) = 0 ;
	int __fastcall GetValueIndex(void);
	virtual int __fastcall ImplGetValueIndex(void) = 0 ;
	virtual bool __fastcall ImplCanAddFieldClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall ImplGetFieldsList(Classes::TStrings* AList);
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TAbstractFieldValuesAdapter(Classes::TComponent* AOwner) : TDefaultFieldsAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TAbstractFieldValuesAdapter(void) { }
	#pragma option pop
	
private:
	void *__IFieldValuesAdapter;	/* Sitecomp::IFieldValuesAdapter */
	
public:
	operator IFieldValuesAdapter*(void) { return (IFieldValuesAdapter*)&__IFieldValuesAdapter; }
	
};


class DELPHICLASS TFieldValuesAdapter;
class PASCALIMPLEMENTATION TFieldValuesAdapter : public TAbstractFieldValuesAdapter 
{
	typedef TAbstractFieldValuesAdapter inherited;
	
private:
	int FIteratorIndex;
	System::TObject* FField;
	
protected:
	virtual TMetaClass* __fastcall GetValueFieldClass(void);
	virtual System::TObject* __fastcall ImplGetField(void);
	virtual int __fastcall ImplGetValueIndex(void);
	virtual bool __fastcall ImplStartIterator(void * &OwnerData);
	virtual bool __fastcall ImplNextIteration(void * &OwnerData);
	virtual void __fastcall ImplEndIterator(void * OwnerData);
	__property System::TObject* Field = {read=FField};
	
public:
	__fastcall virtual TFieldValuesAdapter(Classes::TComponent* AOwner, System::TObject* AField);
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TFieldValuesAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFieldValuesValueField;
class PASCALIMPLEMENTATION TFieldValuesValueField : public TAdapterNamedField 
{
	typedef TAdapterNamedField inherited;
	
private:
	System::TObject* __fastcall GetField(void);
	
protected:
	virtual AnsiString __fastcall GetDefaultFieldName();
	virtual Variant __fastcall ImplGetValue();
	virtual AnsiString __fastcall ImplAsFormatted();
	__property System::TObject* Field = {read=GetField};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TFieldValuesValueField(Classes::TComponent* AOwner) : TAdapterNamedField(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TFieldValuesValueField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBaseValuesListAdapter;
class PASCALIMPLEMENTATION TBaseValuesListAdapter : public TDefaultFieldsAdapter 
{
	typedef TDefaultFieldsAdapter inherited;
	
protected:
	virtual TMetaClass* __fastcall GetNameFieldClass(void);
	virtual TMetaClass* __fastcall GetValueFieldClass(void);
	virtual _di_IDispatch __fastcall ImplGetScriptObject();
	virtual bool __fastcall ImplStartIterator(void * &OwnerData);
	virtual bool __fastcall ImplNextIteration(void * &OwnerData);
	virtual void __fastcall ImplEndIterator(void * OwnerData);
	Variant __fastcall GetListValue();
	AnsiString __fastcall GetListName();
	virtual Variant __fastcall ImplGetListValue();
	virtual AnsiString __fastcall ImplGetListName();
	AnsiString __fastcall GetListNameOfValue(const Variant &Value);
	System::_di_IInterface __fastcall GetListImageOfValue(const Variant &Value);
	virtual System::_di_IInterface __fastcall ImplGetListImageOfValue(const Variant &Value);
	System::_di_IInterface __fastcall GetListImage();
	virtual System::_di_IInterface __fastcall ImplGetListImage();
	virtual AnsiString __fastcall ImplGetListNameOfValue(const Variant &Value);
	virtual bool __fastcall ImplCanAddFieldClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall ImplGetFieldsList(Classes::TStrings* AList);
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TBaseValuesListAdapter(Classes::TComponent* AOwner) : TDefaultFieldsAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TBaseValuesListAdapter(void) { }
	#pragma option pop
	
private:
	void *__IValuesListAdapter;	/* Sitecomp::IValuesListAdapter */
	
public:
	operator IValuesListAdapter*(void) { return (IValuesListAdapter*)&__IValuesListAdapter; }
	
};


class DELPHICLASS TBaseValuesListField;
class PASCALIMPLEMENTATION TBaseValuesListField : public TAdapterNamedField 
{
	typedef TAdapterNamedField inherited;
	
protected:
	HIDESBASE TBaseValuesListAdapter* __fastcall GetAdapter(void);
	__property TBaseValuesListAdapter* Adapter = {read=GetAdapter};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TBaseValuesListField(Classes::TComponent* AOwner) : TAdapterNamedField(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TBaseValuesListField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TValuesListNameField;
class PASCALIMPLEMENTATION TValuesListNameField : public TBaseValuesListField 
{
	typedef TBaseValuesListField inherited;
	
protected:
	virtual AnsiString __fastcall GetDefaultFieldName();
	virtual Variant __fastcall ImplGetValue();
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TValuesListNameField(Classes::TComponent* AOwner) : TBaseValuesListField(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TValuesListNameField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TValuesListValueField;
class PASCALIMPLEMENTATION TValuesListValueField : public TBaseValuesListField 
{
	typedef TBaseValuesListField inherited;
	
protected:
	virtual AnsiString __fastcall GetDefaultFieldName();
	virtual Variant __fastcall ImplGetValue();
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TValuesListValueField(Classes::TComponent* AOwner) : TBaseValuesListField(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TValuesListValueField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomStringsValuesList;
class PASCALIMPLEMENTATION TCustomStringsValuesList : public TBaseValuesListAdapter 
{
	typedef TBaseValuesListAdapter inherited;
	
private:
	Classes::TStrings* FStrings;
	int FIndex;
	bool FStringsPrepared;
	Classes::TNotifyEvent FOnPrepareStrings;
	void __fastcall SetStrings(const Classes::TStrings* Value);
	Classes::TStrings* __fastcall GetStrings(void);
	
protected:
	__property bool StringsPrepared = {read=FStringsPrepared, write=FStringsPrepared, nodefault};
	virtual void __fastcall PrepareStrings(void);
	virtual TMetaClass* __fastcall GetNameFieldClass(void);
	virtual TMetaClass* __fastcall GetValueFieldClass(void);
	virtual void __fastcall ImplNotifyDeactivate(void);
	virtual Variant __fastcall ImplGetListValue();
	virtual AnsiString __fastcall ImplGetListName();
	virtual AnsiString __fastcall ImplGetListNameOfValue(const Variant &Value);
	virtual bool __fastcall ImplStartIterator(void * &OwnerData);
	virtual bool __fastcall ImplNextIteration(void * &OwnerData);
	virtual void __fastcall ImplEndIterator(void * OwnerData);
	
public:
	__fastcall virtual TCustomStringsValuesList(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomStringsValuesList(void);
	__property Classes::TStrings* Strings = {read=GetStrings, write=SetStrings};
	__property Classes::TNotifyEvent OnPrepareStrings = {read=FOnPrepareStrings, write=FOnPrepareStrings};
};


class DELPHICLASS TStringsValuesList;
class PASCALIMPLEMENTATION TStringsValuesList : public TCustomStringsValuesList 
{
	typedef TCustomStringsValuesList inherited;
	
__published:
	__property Strings ;
	__property Data ;
	__property Actions ;
	__property OnPrepareStrings ;
public:
	#pragma option push -w-inl
	/* TCustomStringsValuesList.Create */ inline __fastcall virtual TStringsValuesList(Classes::TComponent* AOwner) : TCustomStringsValuesList(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomStringsValuesList.Destroy */ inline __fastcall virtual ~TStringsValuesList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLogicalPageList;
class PASCALIMPLEMENTATION TLogicalPageList : public TCustomStringsValuesList 
{
	typedef TCustomStringsValuesList inherited;
	
public:
	__fastcall virtual TLogicalPageList(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomStringsValuesList.Destroy */ inline __fastcall virtual ~TLogicalPageList(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TValidateAdapterFieldEvent)(System::TObject* Sender, const Variant &Value, bool &Handled);

typedef void __fastcall (__closure *TLoginUserIDEvent)(System::TObject* Sender, const Variant &UserID);

class PASCALIMPLEMENTATION TCustomLoginFormAdapter : public TDefaultFieldsAdapter 
{
	typedef TDefaultFieldsAdapter inherited;
	
private:
	TValidateAdapterFieldEvent FOnValidateUserName;
	TValidateAdapterFieldEvent FOnValidatePassword;
	TLoginUserIDEvent FOnLogin;
	Webcntxt::_di_IWebEndUser FEndUser;
	Sitecomp::_di_IWebUserList FUserList;
	bool FPasswordRequired;
	AnsiString FNextPage;
	Variant __fastcall GetPassword();
	Variant __fastcall GetUserName();
	AnsiString __fastcall GetNextPage();
	
protected:
	void __fastcall RaiseBlankPassword(void);
	void __fastcall RaiseBlankUserName(void);
	Webcntxt::_di_IWebEndUser __fastcall EndUser();
	Sitecomp::_di_IWebUserList __fastcall UserList();
	void __fastcall ValidateUserName(void);
	void __fastcall ValidatePassword(void);
	void __fastcall ExecuteLogin(const Variant &AUserID);
	__property AnsiString NextPage = {read=GetNextPage, write=FNextPage};
	virtual void __fastcall ImplNotifyDeactivate(void);
	virtual bool __fastcall ImplCanAddFieldClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddActionClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall ImplGetFieldsList(Classes::TStrings* AList);
	virtual void __fastcall ImplGetActionsList(Classes::TStrings* AList);
	
public:
	__property TValidateAdapterFieldEvent OnValidateUserName = {read=FOnValidateUserName, write=FOnValidateUserName};
	__property TValidateAdapterFieldEvent OnValidatePassword = {read=FOnValidatePassword, write=FOnValidatePassword};
	__property TLoginUserIDEvent OnLogin = {read=FOnLogin, write=FOnLogin};
	__property bool PasswordRequired = {read=FPasswordRequired, write=FPasswordRequired, default=0};
	__property Variant Password = {read=GetPassword};
	__property Variant UserName = {read=GetUserName};
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TCustomLoginFormAdapter(Classes::TComponent* AOwner) : TDefaultFieldsAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TCustomLoginFormAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLoginFormAdapter;
class PASCALIMPLEMENTATION TLoginFormAdapter : public TCustomLoginFormAdapter 
{
	typedef TCustomLoginFormAdapter inherited;
	
__published:
	__property Data ;
	__property Actions ;
	__property OnValidateUserName ;
	__property OnValidatePassword ;
	__property OnLogin ;
	__property PasswordRequired  = {default=0};
	__property OnBeforeExecuteAction ;
	__property OnAfterExecuteAction ;
	__property OnBeforeGetActionResponse ;
	__property OnAfterGetActionResponse ;
	__property OnGetActionParams ;
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TLoginFormAdapter(Classes::TComponent* AOwner) : TCustomLoginFormAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TLoginFormAdapter(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TEndUserHandledEvent)(System::TObject* Sender, bool &Handled);

typedef void __fastcall (__closure *TEndUserIsLoggedInEvent)(System::TObject* Sender, bool &IsLoggedIn);

typedef void __fastcall (__closure *TEndUserUserIDEvent)(System::TObject* Sender, const Variant &UserID);

typedef void __fastcall (__closure *TEndUserGetUserIDEvent)(System::TObject* Sender, Variant &UserID);

typedef void __fastcall (__closure *TEndUserGetNameEvent)(System::TObject* Sender, AnsiString &Name);

typedef void __fastcall (__closure *TEndUserRightsEvent)(System::TObject* Sender, Classes::TStrings* Rights, bool &HasRights, bool &Handled);

class DELPHICLASS TBaseEndUserAdapter;
class PASCALIMPLEMENTATION TBaseEndUserAdapter : public TDefaultFieldsAdapter 
{
	typedef TDefaultFieldsAdapter inherited;
	
private:
	AnsiString FLoginPage;
	TEndUserHandledEvent FOnProduceLoginPage;
	TEndUserRightsEvent FOnHasRights;
	Sitecomp::_di_IWebUserList FUserList;
	
protected:
	Sitecomp::_di_IWebUserList __fastcall UserList();
	virtual Variant __fastcall GetUserID();
	virtual void __fastcall ExecuteLoginForm(void);
	virtual bool __fastcall CanExecuteLoginForm(void);
	virtual void __fastcall ExecuteLogout(void);
	virtual bool __fastcall CanExecuteLogout(void);
	virtual void __fastcall ExecuteLogin(const Variant &AUserID);
	virtual bool __fastcall GetLoggedInValue(void);
	virtual AnsiString __fastcall GetDisplayNameValue();
	virtual bool __fastcall CanProduceLoginPage(void);
	virtual bool __fastcall DoOnHasRights(TEndUserRightsEvent AEvent, const AnsiString ARights);
	AnsiString __fastcall GetDisplayName();
	virtual AnsiString __fastcall ImplGetDisplayName();
	bool __fastcall GetLoggedIn(void);
	virtual bool __fastcall ImplGetLoggedIn(void);
	Classes::TComponent* __fastcall GetLogoutAction(void);
	virtual Classes::TComponent* __fastcall ImplGetLogoutAction(void);
	Classes::TComponent* __fastcall GetLoginFormAction(void);
	Classes::TComponent* __fastcall ImplGetLoginFormAction(void);
	Classes::TComponent* __fastcall GetEndUserAdapter(void);
	virtual Classes::TComponent* __fastcall ImplGetEndUserAdapter(void);
	void __fastcall LogIn(const Variant &AUserID);
	virtual void __fastcall ImplLogIn(const Variant &AUserID);
	bool __fastcall ProduceLoginPage(void);
	virtual bool __fastcall ImplProduceLoginPage(void);
	bool __fastcall HasExecuteRights(AnsiString ARights);
	virtual bool __fastcall ImplHasExecuteRights(AnsiString ARights);
	bool __fastcall HasViewRights(AnsiString ARights);
	virtual bool __fastcall ImplHasViewRights(AnsiString ARights);
	bool __fastcall HasModifyRights(AnsiString ARights);
	virtual bool __fastcall ImplHasModifyRights(AnsiString ARights);
	virtual bool __fastcall ImplCanAddFieldClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddActionClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall ImplGetFieldsList(Classes::TStrings* AList);
	virtual void __fastcall ImplGetActionsList(Classes::TStrings* AList);
	
public:
	__property AnsiString LoginPage = {read=FLoginPage, write=FLoginPage};
	__property TEndUserHandledEvent OnProduceLoginPage = {read=FOnProduceLoginPage, write=FOnProduceLoginPage};
	__property TEndUserRightsEvent OnHasRights = {read=FOnHasRights, write=FOnHasRights};
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TBaseEndUserAdapter(Classes::TComponent* AOwner) : TDefaultFieldsAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TBaseEndUserAdapter(void) { }
	#pragma option pop
	
private:
	void *__IWebEndUser;	/* Webcntxt::IWebEndUser */
	
public:
	operator IWebEndUser*(void) { return (IWebEndUser*)&__IWebEndUser; }
	
};


class DELPHICLASS TCustomEndUserAdapter;
class PASCALIMPLEMENTATION TCustomEndUserAdapter : public TBaseEndUserAdapter 
{
	typedef TBaseEndUserAdapter inherited;
	
private:
	TEndUserIsLoggedInEvent FOnIsLoggedIn;
	TEndUserGetNameEvent FOnGetDisplayName;
	Classes::TNotifyEvent FOnLogout;
	TEndUserUserIDEvent FOnLogin;
	TEndUserGetUserIDEvent FOnGetUserID;
	
protected:
	virtual void __fastcall ExecuteLogout(void);
	virtual void __fastcall ExecuteLogin(const Variant &AUserID);
	virtual bool __fastcall GetLoggedInValue(void);
	virtual AnsiString __fastcall GetDisplayNameValue();
	virtual Variant __fastcall GetUserID();
	
public:
	__property TEndUserIsLoggedInEvent OnIsLoggedIn = {read=FOnIsLoggedIn, write=FOnIsLoggedIn};
	__property TEndUserGetNameEvent OnGetDisplayName = {read=FOnGetDisplayName, write=FOnGetDisplayName};
	__property Classes::TNotifyEvent OnLogout = {read=FOnLogout, write=FOnLogout};
	__property TEndUserUserIDEvent OnLogin = {read=FOnLogin, write=FOnLogin};
	__property TEndUserGetUserIDEvent OnGetUserID = {read=FOnGetUserID, write=FOnGetUserID};
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TCustomEndUserAdapter(Classes::TComponent* AOwner) : TBaseEndUserAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TCustomEndUserAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEndUserAdapter;
class PASCALIMPLEMENTATION TEndUserAdapter : public TCustomEndUserAdapter 
{
	typedef TCustomEndUserAdapter inherited;
	
__published:
	__property OnIsLoggedIn ;
	__property OnGetDisplayName ;
	__property OnLogout ;
	__property OnLogin ;
	__property OnProduceLoginPage ;
	__property LoginPage ;
	__property OnHasRights ;
	__property Data ;
	__property Actions ;
	__property OnBeforeExecuteAction ;
	__property OnAfterExecuteAction ;
	__property OnBeforeGetActionResponse ;
	__property OnAfterGetActionResponse ;
	__property OnGetActionParams ;
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TEndUserAdapter(Classes::TComponent* AOwner) : TCustomEndUserAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TEndUserAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomEndUserSessionAdapter;
class PASCALIMPLEMENTATION TCustomEndUserSessionAdapter : public TBaseEndUserAdapter 
{
	typedef TBaseEndUserAdapter inherited;
	
private:
	void __fastcall SetUserID(const Variant &Value);
	
protected:
	virtual void __fastcall ExecuteLogout(void);
	virtual void __fastcall ExecuteLogin(const Variant &AUserID);
	virtual bool __fastcall GetLoggedInValue(void);
	virtual AnsiString __fastcall GetDisplayNameValue();
	virtual Variant __fastcall GetUserID();
	
public:
	__property Variant UserID = {read=GetUserID, write=SetUserID};
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TCustomEndUserSessionAdapter(Classes::TComponent* AOwner) : TBaseEndUserAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TCustomEndUserSessionAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEndUserSessionAdapter;
class PASCALIMPLEMENTATION TEndUserSessionAdapter : public TCustomEndUserSessionAdapter 
{
	typedef TCustomEndUserSessionAdapter inherited;
	
__published:
	__property OnProduceLoginPage ;
	__property LoginPage ;
	__property OnHasRights ;
	__property Data ;
	__property Actions ;
	__property OnBeforeExecuteAction ;
	__property OnAfterExecuteAction ;
	__property OnBeforeGetActionResponse ;
	__property OnAfterGetActionResponse ;
	__property OnGetActionParams ;
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TEndUserSessionAdapter(Classes::TComponent* AOwner) : TCustomEndUserSessionAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TEndUserSessionAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomApplicationAdapter;
class PASCALIMPLEMENTATION TCustomApplicationAdapter : public TDefaultFieldsAdapter 
{
	typedef TDefaultFieldsAdapter inherited;
	
private:
	AnsiString FApplicationTitle;
	
protected:
	AnsiString __fastcall GetApplicationTitle();
	Classes::TComponent* __fastcall GetApplicationAdapter(void);
	virtual bool __fastcall ImplCanAddFieldClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddActionClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall ImplGetFieldsList(Classes::TStrings* AList);
	virtual void __fastcall ImplGetActionsList(Classes::TStrings* AList);
	
public:
	__property AnsiString ApplicationTitle = {read=FApplicationTitle, write=FApplicationTitle};
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TCustomApplicationAdapter(Classes::TComponent* AOwner) : TDefaultFieldsAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TCustomApplicationAdapter(void) { }
	#pragma option pop
	
private:
	void *__IWebApplicationInfo;	/* Sitecomp::IWebApplicationInfo */
	
public:
	operator IWebApplicationInfo*(void) { return (IWebApplicationInfo*)&__IWebApplicationInfo; }
	
};


class DELPHICLASS TApplicationAdapter;
class PASCALIMPLEMENTATION TApplicationAdapter : public TCustomApplicationAdapter 
{
	typedef TCustomApplicationAdapter inherited;
	
__published:
	__property ApplicationTitle ;
	__property Data ;
	__property Actions ;
	__property OnBeforeExecuteAction ;
	__property OnAfterExecuteAction ;
	__property OnBeforeGetActionResponse ;
	__property OnAfterGetActionResponse ;
	__property OnGetActionParams ;
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Create */ inline __fastcall virtual TApplicationAdapter(Classes::TComponent* AOwner) : TCustomApplicationAdapter(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TApplicationAdapter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomEndUserAdapterAction;
class PASCALIMPLEMENTATION TCustomEndUserAdapterAction : public TImplementedAdapterAction 
{
	typedef TImplementedAdapterAction inherited;
	
private:
	HIDESBASE TBaseEndUserAdapter* __fastcall GetAdapter(void);
	
protected:
	__property TBaseEndUserAdapter* Adapter = {read=GetAdapter};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TCustomEndUserAdapterAction(Classes::TComponent* AOwner) : TImplementedAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomEndUserAdapterAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEndUserAdapterLoginFormAction;
class PASCALIMPLEMENTATION TEndUserAdapterLoginFormAction : public TCustomEndUserAdapterAction 
{
	typedef TCustomEndUserAdapterAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__property DisplayLabel ;
	__property OnGetParams ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TEndUserAdapterLoginFormAction(Classes::TComponent* AOwner) : TCustomEndUserAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TEndUserAdapterLoginFormAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEndUserAdapterLogoutAction;
class PASCALIMPLEMENTATION TEndUserAdapterLogoutAction : public TCustomEndUserAdapterAction 
{
	typedef TCustomEndUserAdapterAction inherited;
	
protected:
	virtual void __fastcall ImplExecuteActionRequest(Adaptreq::_di_IActionRequest AActionRequest, Adaptreq::_di_IActionResponse AActionResponse);
	virtual bool __fastcall ImplWebEnabled(void);
	virtual AnsiString __fastcall GetDefaultActionName();
	
__published:
	__property DisplayLabel ;
	__property OnGetParams ;
	__property OnBeforeExecute ;
	__property OnAfterExecute ;
	__property OnBeforeGetResponse ;
	__property OnAfterGetResponse ;
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TEndUserAdapterLogoutAction(Classes::TComponent* AOwner) : TCustomEndUserAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TEndUserAdapterLogoutAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterEndUserField;
class PASCALIMPLEMENTATION TAdapterEndUserField : public TAdapterNamedDisplayField 
{
	typedef TAdapterNamedDisplayField inherited;
	
private:
	HIDESBASE TBaseEndUserAdapter* __fastcall GetAdapter(void);
	
protected:
	__property TBaseEndUserAdapter* Adapter = {read=GetAdapter};
public:
	#pragma option push -w-inl
	/* TAdapterNamedDisplayField.Create */ inline __fastcall virtual TAdapterEndUserField(Classes::TComponent* AOwner) : TAdapterNamedDisplayField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterEndUserField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterEndUserLoggedInField;
class PASCALIMPLEMENTATION TAdapterEndUserLoggedInField : public TAdapterEndUserField 
{
	typedef TAdapterEndUserField inherited;
	
protected:
	virtual AnsiString __fastcall GetDefaultFieldName();
	virtual Variant __fastcall ImplGetValue();
public:
	#pragma option push -w-inl
	/* TAdapterNamedDisplayField.Create */ inline __fastcall virtual TAdapterEndUserLoggedInField(Classes::TComponent* AOwner) : TAdapterEndUserField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterEndUserLoggedInField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterEndUserDisplayNameField;
class PASCALIMPLEMENTATION TAdapterEndUserDisplayNameField : public TAdapterEndUserField 
{
	typedef TAdapterEndUserField inherited;
	
protected:
	virtual AnsiString __fastcall GetDefaultFieldName();
	virtual Variant __fastcall ImplGetValue();
public:
	#pragma option push -w-inl
	/* TAdapterNamedDisplayField.Create */ inline __fastcall virtual TAdapterEndUserDisplayNameField(Classes::TComponent* AOwner) : TAdapterEndUserField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterEndUserDisplayNameField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomApplicationAdapterAction;
class PASCALIMPLEMENTATION TCustomApplicationAdapterAction : public TImplementedAdapterAction 
{
	typedef TImplementedAdapterAction inherited;
	
private:
	HIDESBASE TCustomApplicationAdapter* __fastcall GetAdapter(void);
	
protected:
	__property TCustomApplicationAdapter* Adapter = {read=GetAdapter};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Create */ inline __fastcall virtual TCustomApplicationAdapterAction(Classes::TComponent* AOwner) : TImplementedAdapterAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomApplicationAdapterAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterApplicationField;
class PASCALIMPLEMENTATION TAdapterApplicationField : public TAdapterNamedDisplayField 
{
	typedef TAdapterNamedDisplayField inherited;
	
private:
	HIDESBASE TCustomApplicationAdapter* __fastcall GetAdapter(void);
	
protected:
	__property TCustomApplicationAdapter* Adapter = {read=GetAdapter};
public:
	#pragma option push -w-inl
	/* TAdapterNamedDisplayField.Create */ inline __fastcall virtual TAdapterApplicationField(Classes::TComponent* AOwner) : TAdapterNamedDisplayField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterApplicationField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterApplicationTitleField;
class PASCALIMPLEMENTATION TAdapterApplicationTitleField : public TAdapterApplicationField 
{
	typedef TAdapterApplicationField inherited;
	
protected:
	virtual AnsiString __fastcall GetDefaultFieldName();
	virtual Variant __fastcall ImplGetValue();
public:
	#pragma option push -w-inl
	/* TAdapterNamedDisplayField.Create */ inline __fastcall virtual TAdapterApplicationTitleField(Classes::TComponent* AOwner) : TAdapterApplicationField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TAdapterApplicationTitleField(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAdapterException;
class PASCALIMPLEMENTATION EAdapterException : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
private:
	int FID;
	
public:
	__fastcall EAdapterException(const AnsiString AMsg, int AID, int Reserved);
	__property int ID = {read=FID, write=FID, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAdapterException(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAdapterException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAdapterException(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAdapterException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAdapterException(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAdapterException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAdapterException(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAdapterException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAdapterException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAdapterFieldException;
class PASCALIMPLEMENTATION EAdapterFieldException : public EAdapterException 
{
	typedef EAdapterException inherited;
	
private:
	AnsiString FFieldName;
	
public:
	__property AnsiString FieldName = {read=FFieldName, write=FFieldName};
	__fastcall EAdapterFieldException(const AnsiString AMsg, const AnsiString AFieldName, int AID);
public:
	#pragma option push -w-inl
	/* EAdapterException.CreateID */ inline __fastcall EAdapterFieldException(const AnsiString AMsg, int AID, int Reserved) : EAdapterException(AMsg, AID, Reserved) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAdapterFieldException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EAdapterException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAdapterFieldException(int Ident)/* overload */ : EAdapterException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAdapterFieldException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EAdapterException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAdapterFieldException(const AnsiString Msg, int AHelpContext) : EAdapterException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAdapterFieldException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EAdapterException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAdapterFieldException(int Ident, int AHelpContext)/* overload */ : EAdapterException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAdapterFieldException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EAdapterException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAdapterFieldException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall (*NotifyPossibleHTMLChange)(void);
#define sImageRequest "__img"
#define sActionRequestLong "__action"
#define sCurrentPage "_cp"
#define sNextPageAction "NextPage"
#define sPrevPageAction "PrevPage"
#define sGotoPageAction "GotoPage"
#define sLoginUserName "UserName"
#define sLoginPassword "Password"
extern PACKAGE void __fastcall RaiseMultipleValuesException(AnsiString AFieldName);
extern PACKAGE void __fastcall RaiseMultipleFilesException(AnsiString AFieldName);
extern PACKAGE void __fastcall RaiseFileUploadNotSupported(AnsiString AFieldName);
extern PACKAGE AnsiString __fastcall MakeValidAdapterFieldName(const AnsiString AFieldName);
extern PACKAGE AnsiString __fastcall MakeAdapterRequestIdentifier(Classes::TComponent* AComponent);
extern PACKAGE Classes::TComponent* __fastcall FindAdapterInParent(Classes::TComponent* AComponent);
extern PACKAGE void __fastcall AddDefaultFields(Classes::TStrings* AList, Webcomp::TWebComponentList* AComponents);
extern PACKAGE void __fastcall AddDefaultActions(Classes::TStrings* AList, Webcomp::TWebComponentList* AComponents);
extern PACKAGE Classes::TComponent* __fastcall FindAdapterField(Webcomp::TWebComponentList* AWebComponents, const AnsiString AName);
extern PACKAGE Classes::TComponent* __fastcall FindAdapterAction(Webcomp::TWebComponentList* AWebComponents, const AnsiString AName);

}	/* namespace Webadapt */
using namespace Webadapt;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebAdapt
