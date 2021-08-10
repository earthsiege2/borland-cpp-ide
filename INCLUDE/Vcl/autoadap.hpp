// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AutoAdap.pas' rev: 6.00

#ifndef AutoAdapHPP
#define AutoAdapHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebCntxt.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <WebAuto.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <WebScript_TLB.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Autoadap
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBaseAdapterWrapper;
class PASCALIMPLEMENTATION TBaseAdapterWrapper : public Webauto::TWebComponentsWrapper 
{
	typedef Webauto::TWebComponentsWrapper inherited;
	
protected:
	Webscript_tlb::_di_IComponentsWrapper FFields;
	Webscript_tlb::_di_IComponentsWrapper FActions;
	HRESULT __safecall Get_Name_(WideString &Get_Name__result);
	HRESULT __safecall Get_ClassName_(WideString &Get_ClassName__result);
	HRESULT __safecall Get_Fields(Webscript_tlb::_di_IComponentsWrapper &Get_Fields_result);
	HRESULT __safecall Get_Actions(Webscript_tlb::_di_IComponentsWrapper &Get_Actions_result);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Create */ inline __fastcall virtual TBaseAdapterWrapper(Classes::TComponent* AObject) : Webauto::TWebComponentsWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TBaseAdapterWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TBaseAdapterWrapper(const System::_di_IInterface Controller) : Webauto::TWebComponentsWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TBaseAdapterWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : Webauto::TWebComponentsWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IComponentWrapper;	/* Webscript_tlb::IComponentWrapper */
	
public:
	operator IComponentWrapper*(void) { return (IComponentWrapper*)&__IComponentWrapper; }
	
};


typedef TMetaClass*TAdapterWrapperClass;

class DELPHICLASS TBaseRecordsAdapterWrapper;
class PASCALIMPLEMENTATION TBaseRecordsAdapterWrapper : public TBaseAdapterWrapper 
{
	typedef TBaseAdapterWrapper inherited;
	
protected:
	HRESULT __safecall Get_Records(Webscript_tlb::_di_IAdapterRecordsWrapper &Get_Records_result);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Create */ inline __fastcall virtual TBaseRecordsAdapterWrapper(Classes::TComponent* AObject) : TBaseAdapterWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TBaseRecordsAdapterWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TBaseRecordsAdapterWrapper(const System::_di_IInterface Controller) : TBaseAdapterWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TBaseRecordsAdapterWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TBaseAdapterWrapper(Factory, Controller) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterWrapper;
class PASCALIMPLEMENTATION TAdapterWrapper : public TBaseRecordsAdapterWrapper 
{
	typedef TBaseRecordsAdapterWrapper inherited;
	
protected:
	virtual System::TObject* __fastcall FindObject(const AnsiString AName);
	HRESULT __safecall Get_Errors(Webscript_tlb::_di_IAdapterErrorsWrapper &Get_Errors_result);
	HRESULT __safecall Get_Mode(WideString &Get_Mode_result);
	HRESULT __safecall Set_Mode(const WideString Value);
	HRESULT __safecall Get_CanView(Word &Get_CanView_result);
	HRESULT __safecall Get_CanModify(Word &Get_CanModify_result);
	HRESULT __safecall Get_HiddenFields(Webscript_tlb::_di_IAdapterHiddenFieldsWrapper &Get_HiddenFields_result);
	HRESULT __safecall Get_HiddenRecordFields(Webscript_tlb::_di_IAdapterHiddenFieldsWrapper &Get_HiddenRecordFields_result);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Create */ inline __fastcall virtual TAdapterWrapper(Classes::TComponent* AObject) : TBaseRecordsAdapterWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TAdapterWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterWrapper(const System::_di_IInterface Controller) : TBaseRecordsAdapterWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TBaseRecordsAdapterWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IAdapterWrapper;	/* Webscript_tlb::IAdapterWrapper */
	
public:
	operator IAdapterWrapper*(void) { return (IAdapterWrapper*)&__IAdapterWrapper; }
	
};


class DELPHICLASS TAdapterValuesListWrapper;
class PASCALIMPLEMENTATION TAdapterValuesListWrapper : public TBaseRecordsAdapterWrapper 
{
	typedef TBaseRecordsAdapterWrapper inherited;
	
protected:
	virtual System::TObject* __fastcall FindObject(const AnsiString AName);
	HIDESBASE HRESULT __safecall Get_Records(Webscript_tlb::_di_IAdapterRecordsWrapper &Get_Records_result);
	HRESULT __safecall Get_Value(OleVariant &Get_Value_result);
	HRESULT __safecall Get_ValueName(WideString &Get_ValueName_result);
	HRESULT __safecall Get_Image(Webscript_tlb::_di_IAdapterImageWrapper &Get_Image_result);
	HRESULT __safecall NameOfValue(const OleVariant Value, WideString &NameOfValue_result);
	HRESULT __safecall ImageOfValue(const OleVariant Value, Webscript_tlb::_di_IAdapterImageWrapper &ImageOfValue_result);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Create */ inline __fastcall virtual TAdapterValuesListWrapper(Classes::TComponent* AObject) : TBaseRecordsAdapterWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TAdapterValuesListWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterValuesListWrapper(const System::_di_IInterface Controller) : TBaseRecordsAdapterWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterValuesListWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TBaseRecordsAdapterWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IAdapterValuesListWrapper;	/* Webscript_tlb::IAdapterValuesListWrapper */
	
public:
	operator IAdapterValuesListWrapper*(void) { return (IAdapterValuesListWrapper*)&__IAdapterValuesListWrapper; }
	
};


class DELPHICLASS TAdapterFieldValuesWrapper;
class PASCALIMPLEMENTATION TAdapterFieldValuesWrapper : public TBaseRecordsAdapterWrapper 
{
	typedef TBaseRecordsAdapterWrapper inherited;
	
protected:
	virtual System::TObject* __fastcall FindObject(const AnsiString AName);
	HIDESBASE HRESULT __safecall Get_Records(Webscript_tlb::_di_IAdapterRecordsWrapper &Get_Records_result);
	HRESULT __safecall Get_Value(OleVariant &Get_Value_result);
	HRESULT __safecall HasValue(const OleVariant Value, Word &HasValue_result);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Create */ inline __fastcall virtual TAdapterFieldValuesWrapper(Classes::TComponent* AObject) : TBaseRecordsAdapterWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TAdapterFieldValuesWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterFieldValuesWrapper(const System::_di_IInterface Controller) : TBaseRecordsAdapterWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterFieldValuesWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TBaseRecordsAdapterWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IAdapterFieldValuesWrapper;	/* Webscript_tlb::IAdapterFieldValuesWrapper */
	
public:
	operator IAdapterFieldValuesWrapper*(void) { return (IAdapterFieldValuesWrapper*)&__IAdapterFieldValuesWrapper; }
	
};


class DELPHICLASS TAdapterComponentsWrapper;
class PASCALIMPLEMENTATION TAdapterComponentsWrapper : public Webauto::TWebComponentsWrapper 
{
	typedef Webauto::TWebComponentsWrapper inherited;
	
private:
	_di_IEnumVariant FEnumerator;
	
protected:
	HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result);
	virtual System::TObject* __fastcall FindObject(const AnsiString AName);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Create */ inline __fastcall virtual TAdapterComponentsWrapper(Classes::TComponent* AObject) : Webauto::TWebComponentsWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TAdapterComponentsWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterComponentsWrapper(const System::_di_IInterface Controller) : Webauto::TWebComponentsWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterComponentsWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : Webauto::TWebComponentsWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IComponentsWrapper;	/* Webscript_tlb::IComponentsWrapper */
	
public:
	operator IComponentsWrapper*(void) { return (IComponentsWrapper*)&__IComponentsWrapper; }
	
};


class DELPHICLASS TAdapterRecordsWrapper;
class PASCALIMPLEMENTATION TAdapterRecordsWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	Classes::TComponent* FAdapter;
	_di_IEnumVariant FEnumerator;
	
protected:
	HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result);
	
public:
	__fastcall TAdapterRecordsWrapper(Classes::TComponent* AAdapter);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterRecordsWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterRecordsWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TAdapterRecordsWrapper(void) { }
	#pragma option pop
	
private:
	void *__IAdapterRecordsWrapper;	/* Webscript_tlb::IAdapterRecordsWrapper */
	
public:
	operator IAdapterRecordsWrapper*(void) { return (IAdapterRecordsWrapper*)&__IAdapterRecordsWrapper; }
	
};


class DELPHICLASS TAdapterActionArrayWrapper;
class PASCALIMPLEMENTATION TAdapterActionArrayWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	System::_di_IInterface FAction;
	_di_IEnumVariant FEnumerator;
	
protected:
	HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result);
	
public:
	__fastcall TAdapterActionArrayWrapper(System::_di_IInterface AAction);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterActionArrayWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterActionArrayWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TAdapterActionArrayWrapper(void) { }
	#pragma option pop
	
private:
	void *__IAdapterActionArrayWrapper;	/* Webscript_tlb::IAdapterActionArrayWrapper */
	
public:
	operator IAdapterActionArrayWrapper*(void) { return (IAdapterActionArrayWrapper*)&__IAdapterActionArrayWrapper; }
	
};


class DELPHICLASS TAdapterErrorsWrapper;
class PASCALIMPLEMENTATION TAdapterErrorsWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	System::TObject* FErrors;
	_di_IEnumVariant FEnumerator;
	
protected:
	HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result);
	HRESULT __safecall DefineLabel(const System::_di_IInterface Object_, const WideString Value);
	HRESULT __safecall FieldErrors(const System::_di_IInterface Object_, Webscript_tlb::_di_IAdapterErrorsWrapper &FieldErrors_result);
	
public:
	__fastcall TAdapterErrorsWrapper(System::TObject* AErrors);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterErrorsWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterErrorsWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TAdapterErrorsWrapper(void) { }
	#pragma option pop
	
private:
	void *__IAdapterErrorsWrapper;	/* Webscript_tlb::IAdapterErrorsWrapper */
	
public:
	operator IAdapterErrorsWrapper*(void) { return (IAdapterErrorsWrapper*)&__IAdapterErrorsWrapper; }
	
};


class DELPHICLASS TAdapterHiddenFieldsWrapper;
class PASCALIMPLEMENTATION TAdapterHiddenFieldsWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	System::TObject* FHiddenFields;
	_di_IEnumVariant FEnumerator;
	
protected:
	HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result);
	HRESULT __safecall WriteFields(const _di_IDispatch Response);
	
public:
	__fastcall TAdapterHiddenFieldsWrapper(System::TObject* AHiddenFields);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterHiddenFieldsWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterHiddenFieldsWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TAdapterHiddenFieldsWrapper(void) { }
	#pragma option pop
	
private:
	void *__IAdapterHiddenFieldsWrapper;	/* Webscript_tlb::IAdapterHiddenFieldsWrapper */
	
public:
	operator IAdapterHiddenFieldsWrapper*(void) { return (IAdapterHiddenFieldsWrapper*)&__IAdapterHiddenFieldsWrapper; }
	
};


typedef void __fastcall (__closure *TNotificationProc)(Classes::TComponent* AComponent, Classes::TOperation Operation);

class DELPHICLASS TNotifier;
class PASCALIMPLEMENTATION TNotifier : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
protected:
	TNotificationProc FNotify;
	Classes::TComponent* FComponent;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual ~TNotifier(void);
	__fastcall TNotifier(TNotificationProc ANotify, Classes::TComponent* AComponent);
};


class DELPHICLASS TAdapterSubComponentWrapper;
class PASCALIMPLEMENTATION TAdapterSubComponentWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	System::_di_IInterface FIntf;
	TNotifier* FNotifier;
	
protected:
	Classes::TComponent* __fastcall GetComponent(void);
	HRESULT __safecall Get_Name(OleVariant &Get_Name_result);
	
public:
	__fastcall TAdapterSubComponentWrapper(Classes::TComponent* AObject)/* overload */;
	__fastcall TAdapterSubComponentWrapper(System::TInterfacedObject* AObject)/* overload */;
	__property System::_di_IInterface ObjectIntf = {read=FIntf};
	__fastcall virtual ~TAdapterSubComponentWrapper(void);
	void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterSubComponentWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterSubComponentWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IInterfaceComponentReference;	/* Classes::IInterfaceComponentReference */
	
public:
	operator IInterfaceComponentReference*(void) { return (IInterfaceComponentReference*)&__IInterfaceComponentReference; }
	
};


class DELPHICLASS TAdapterFieldWrapper;
class PASCALIMPLEMENTATION TAdapterFieldWrapper : public TAdapterSubComponentWrapper 
{
	typedef TAdapterSubComponentWrapper inherited;
	
private:
	WideString __fastcall AsEditText(const OleVariant &Value);
	
protected:
	HRESULT __safecall Get_Value(OleVariant &Get_Value_result);
	HRESULT __safecall Get_Values(Webscript_tlb::_di_IAdapterFieldValuesWrapper &Get_Values_result);
	HRESULT __safecall Get_DisplayText(WideString &Get_DisplayText_result);
	HRESULT __safecall Get_EditText(WideString &Get_EditText_result);
	HRESULT __safecall Get_InputName(WideString &Get_InputName_result);
	HRESULT __safecall Get_DisplayWidth(int &Get_DisplayWidth_result);
	HRESULT __safecall Get_MaxLength(int &Get_MaxLength_result);
	HRESULT __safecall Get_DisplayLabel(WideString &Get_DisplayLabel_result);
	HRESULT __safecall Get_ValuesList(Webscript_tlb::_di_IAdapterValuesListWrapper &Get_ValuesList_result);
	HRESULT __safecall Get_Image(Webscript_tlb::_di_IAdapterImageWrapper &Get_Image_result);
	HRESULT __safecall Get_DisplayStyle(WideString &Get_DisplayStyle_result);
	HRESULT __safecall Get_InputStyle(WideString &Get_InputStyle_result);
	HRESULT __safecall Get_ViewMode(WideString &Get_ViewMode_result);
	HRESULT __safecall Get_CanView(Word &Get_CanView_result);
	HRESULT __safecall Get_Required(Word &Get_Required_result);
	HRESULT __safecall Get_Visible(Word &Get_Visible_result);
	HRESULT __safecall Get_CanModify(Word &Get_CanModify_result);
	HRESULT __safecall IsEqual(const OleVariant Value, Word &IsEqual_result);
public:
	#pragma option push -w-inl
	/* TAdapterSubComponentWrapper.Create */ inline __fastcall TAdapterFieldWrapper(Classes::TComponent* AObject)/* overload */ : TAdapterSubComponentWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TAdapterSubComponentWrapper.Destroy */ inline __fastcall virtual ~TAdapterFieldWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterFieldWrapper(const System::_di_IInterface Controller) : TAdapterSubComponentWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterFieldWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TAdapterSubComponentWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IAdapterFieldWrapper;	/* Webscript_tlb::IAdapterFieldWrapper */
	
public:
	operator IAdapterFieldWrapper*(void) { return (IAdapterFieldWrapper*)&__IAdapterFieldWrapper; }
	
};


class DELPHICLASS TAdapterActionWrapper;
class PASCALIMPLEMENTATION TAdapterActionWrapper : public TAdapterSubComponentWrapper 
{
	typedef TAdapterSubComponentWrapper inherited;
	
protected:
	HRESULT __safecall Get_AsFieldValue(WideString &Get_AsFieldValue_result);
	HRESULT __safecall Get_AsHREF(WideString &Get_AsHREF_result);
	HRESULT __safecall LinkToPage(const WideString PageSuccess, const WideString PageFail, Webscript_tlb::_di_IAdapterActionWrapper &LinkToPage_result);
	HRESULT __safecall Get_DisplayLabel(WideString &Get_DisplayLabel_result);
	HRESULT __safecall Get_Enabled(Word &Get_Enabled_result);
	HRESULT __safecall Get_CanExecute(Word &Get_CanExecute_result);
	HRESULT __safecall Get_Visible(Word &Get_Visible_result);
	HRESULT __safecall Get_Array_(Webscript_tlb::_di_IAdapterActionArrayWrapper &Get_Array__result);
	HRESULT __safecall Get_DisplayStyle(WideString &Get_DisplayStyle_result);
public:
	#pragma option push -w-inl
	/* TAdapterSubComponentWrapper.Create */ inline __fastcall TAdapterActionWrapper(Classes::TComponent* AObject)/* overload */ : TAdapterSubComponentWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TAdapterSubComponentWrapper.Destroy */ inline __fastcall virtual ~TAdapterActionWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterActionWrapper(const System::_di_IInterface Controller) : TAdapterSubComponentWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterActionWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TAdapterSubComponentWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IAdapterActionWrapper;	/* Webscript_tlb::IAdapterActionWrapper */
	
public:
	operator IAdapterActionWrapper*(void) { return (IAdapterActionWrapper*)&__IAdapterActionWrapper; }
	
};


class DELPHICLASS TAdapterImageWrapper;
class PASCALIMPLEMENTATION TAdapterImageWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	System::_di_IInterface FIntf;
	
protected:
	HRESULT __safecall Get_AsHREF(WideString &Get_AsHREF_result);
	
public:
	__fastcall TAdapterImageWrapper(System::_di_IInterface AIntf);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterImageWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterImageWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TAdapterImageWrapper(void) { }
	#pragma option pop
	
private:
	void *__IAdapterImageWrapper;	/* Webscript_tlb::IAdapterImageWrapper */
	
public:
	operator IAdapterImageWrapper*(void) { return (IAdapterImageWrapper*)&__IAdapterImageWrapper; }
	
};


class DELPHICLASS TImageProducerWrapper;
class PASCALIMPLEMENTATION TImageProducerWrapper : public TScriptComponent 
{
	typedef TScriptComponent inherited;
	
protected:
	HRESULT __safecall GetImage(const System::_di_IInterface Object_, const WideString Caption, Webscript_tlb::_di_IAdapterImageWrapper &GetImage_result);
	HRESULT __safecall GetEventImage(const System::_di_IInterface Object_, const WideString Event, const WideString Caption, Webscript_tlb::_di_IAdapterImageWrapper &GetEventImage_result);
	HRESULT __safecall GetDisplayStyle(const System::_di_IInterface Object_, WideString &GetDisplayStyle_result);
public:
	#pragma option push -w-inl
	/* TScriptComponent.Create */ inline __fastcall virtual TImageProducerWrapper(Classes::TComponent* AObject) : TScriptComponent(AObject) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TImageProducerWrapper(const System::_di_IInterface Controller) : TScriptComponent(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TImageProducerWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptComponent(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TImageProducerWrapper(void) { }
	#pragma option pop
	
private:
	void *__IImageProducerWrapper;	/* Webscript_tlb::IImageProducerWrapper */
	
public:
	operator IImageProducerWrapper*(void) { return (IImageProducerWrapper*)&__IImageProducerWrapper; }
	
};


class DELPHICLASS TAdapterRecordEnumerator;
class PASCALIMPLEMENTATION TAdapterRecordEnumerator : public Webauto::TIteratorSupport 
{
	typedef Webauto::TIteratorSupport inherited;
	
private:
	System::_di_IInterface FObjectIntf;
	Sitecomp::_di_IGetScriptObject FCurrent;
	
protected:
	virtual _di_IDispatch __fastcall GetCurrent();
	__property System::_di_IInterface ObjectIntf = {read=FObjectIntf};
	
public:
	__fastcall TAdapterRecordEnumerator(System::_di_IInterface AObjectIntf);
public:
	#pragma option push -w-inl
	/* TIteratorSupport.Destroy */ inline __fastcall virtual ~TAdapterRecordEnumerator(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterRecordEnumerator(const System::_di_IInterface Controller) : Webauto::TIteratorSupport(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterRecordEnumerator(TComObjectFactory* Factory, const System::_di_IInterface Controller) : Webauto::TIteratorSupport(Factory, Controller) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterFieldRecordEnumerator;
class PASCALIMPLEMENTATION TAdapterFieldRecordEnumerator : public Webauto::TIteratorSupport 
{
	typedef Webauto::TIteratorSupport inherited;
	
private:
	System::TObject* FObject;
	Sitecomp::_di_IGetScriptObject FCurrent;
	
protected:
	virtual _di_IDispatch __fastcall GetCurrent();
	__property System::TObject* Obj = {read=FObject};
	
public:
	__fastcall TAdapterFieldRecordEnumerator(System::TObject* AObject);
public:
	#pragma option push -w-inl
	/* TIteratorSupport.Destroy */ inline __fastcall virtual ~TAdapterFieldRecordEnumerator(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterFieldRecordEnumerator(const System::_di_IInterface Controller) : Webauto::TIteratorSupport(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterFieldRecordEnumerator(TComObjectFactory* Factory, const System::_di_IInterface Controller) : Webauto::TIteratorSupport(Factory, Controller) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterErrorEnumerator;
class PASCALIMPLEMENTATION TAdapterErrorEnumerator : public Webauto::TIteratorSupport 
{
	typedef Webauto::TIteratorSupport inherited;
	
private:
	Sitecomp::_di_IIterateIntfSupport FIterator;
	
protected:
	virtual _di_IDispatch __fastcall GetCurrent();
	
public:
	__fastcall TAdapterErrorEnumerator(System::TObject* AErrors);
public:
	#pragma option push -w-inl
	/* TIteratorSupport.Destroy */ inline __fastcall virtual ~TAdapterErrorEnumerator(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterErrorEnumerator(const System::_di_IInterface Controller) : Webauto::TIteratorSupport(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterErrorEnumerator(TComObjectFactory* Factory, const System::_di_IInterface Controller) : Webauto::TIteratorSupport(Factory, Controller) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterHiddenFieldsEnumerator;
class PASCALIMPLEMENTATION TAdapterHiddenFieldsEnumerator : public Webauto::TIteratorSupport 
{
	typedef Webauto::TIteratorSupport inherited;
	
private:
	Sitecomp::_di_IIterateIntfSupport FIterator;
	
protected:
	virtual _di_IDispatch __fastcall GetCurrent();
	
public:
	__fastcall TAdapterHiddenFieldsEnumerator(System::TObject* AHiddenFields);
public:
	#pragma option push -w-inl
	/* TIteratorSupport.Destroy */ inline __fastcall virtual ~TAdapterHiddenFieldsEnumerator(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterHiddenFieldsEnumerator(const System::_di_IInterface Controller) : Webauto::TIteratorSupport(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterHiddenFieldsEnumerator(TComObjectFactory* Factory, const System::_di_IInterface Controller) : Webauto::TIteratorSupport(Factory, Controller) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterRecordWrapper;
class PASCALIMPLEMENTATION TAdapterRecordWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	Classes::TComponent* FAdapter;
	TBaseAdapterWrapper* FAdapterWrapper;
	
public:
	__fastcall TAdapterRecordWrapper(Classes::TComponent* AAdapter, TMetaClass* AAdapterWrapperClass);
	__property TBaseAdapterWrapper* Impl = {read=FAdapterWrapper};
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterRecordWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterRecordWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TAdapterRecordWrapper(void) { }
	#pragma option pop
	
private:
	void *__IAdapterRecordWrapper;	/* Webscript_tlb::IAdapterRecordWrapper */
	
public:
	operator IAdapterRecordWrapper*(void) { return (IAdapterRecordWrapper*)&__IAdapterRecordWrapper; }
	
};


class DELPHICLASS TAdapterErrorWrapper;
class PASCALIMPLEMENTATION TAdapterErrorWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	Sitecomp::_di_IAdapterError FError;
	
protected:
	HRESULT __safecall Get_Message(WideString &Get_Message_result);
	HRESULT __safecall Get_Field(_di_IDispatch &Get_Field_result);
	HRESULT __safecall Get_ID(int &Get_ID_result);
	
public:
	__fastcall TAdapterErrorWrapper(const Sitecomp::_di_IAdapterError AError);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterErrorWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterErrorWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TAdapterErrorWrapper(void) { }
	#pragma option pop
	
private:
	void *__IAdapterErrorWrapper;	/* Webscript_tlb::IAdapterErrorWrapper */
	
public:
	operator IAdapterErrorWrapper*(void) { return (IAdapterErrorWrapper*)&__IAdapterErrorWrapper; }
	
};


class DELPHICLASS TAdapterHiddenFieldWrapper;
class PASCALIMPLEMENTATION TAdapterHiddenFieldWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	Sitecomp::_di_IAdapterHiddenField FParam;
	
protected:
	HRESULT __safecall Get_Name(WideString &Get_Name_result);
	HRESULT __safecall Get_Value(WideString &Get_Value_result);
	
public:
	__fastcall TAdapterHiddenFieldWrapper(const Sitecomp::_di_IAdapterHiddenField AParam);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TAdapterHiddenFieldWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TAdapterHiddenFieldWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TAdapterHiddenFieldWrapper(void) { }
	#pragma option pop
	
private:
	void *__IAdapterHiddenFieldWrapper;	/* Webscript_tlb::IAdapterHiddenFieldWrapper */
	
public:
	operator IAdapterHiddenFieldWrapper*(void) { return (IAdapterHiddenFieldWrapper*)&__IAdapterHiddenFieldWrapper; }
	
};


class DELPHICLASS TActionLink;
class PASCALIMPLEMENTATION TActionLink : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	System::_di_IInterface FAction;
	AnsiString FPage;
	AnsiString FErrorPage;
	
protected:
	void __fastcall GetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams AParams);
	AnsiString __fastcall GetSuccessPage();
	AnsiString __fastcall GetFailurePage();
	Classes::TComponent* __fastcall GetComponent(void);
	
public:
	__fastcall TActionLink(System::_di_IInterface AAction, const AnsiString APage, const AnsiString AErrorPage);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TActionLink(void) { }
	#pragma option pop
	
private:
	void *__IGetAdapterItemRequestParams;	/* Sitecomp::IGetAdapterItemRequestParams */
	void *__IGetAdapterRequestDefaultResponse;	/* Sitecomp::IGetAdapterRequestDefaultResponse */
	void *__IInterfaceComponentReference;	/* Classes::IInterfaceComponentReference */
	
public:
	operator IInterfaceComponentReference*(void) { return (IInterfaceComponentReference*)&__IInterfaceComponentReference; }
	operator IGetAdapterRequestDefaultResponse*(void) { return (IGetAdapterRequestDefaultResponse*)&__IGetAdapterRequestDefaultResponse; }
	operator IGetAdapterItemRequestParams*(void) { return (IGetAdapterItemRequestParams*)&__IGetAdapterItemRequestParams; }
	
};


class DELPHICLASS TWebEndUserWrapper;
class PASCALIMPLEMENTATION TWebEndUserWrapper : public TAdapterWrapper 
{
	typedef TAdapterWrapper inherited;
	
private:
	Httpprod::_di_IScriptContext FContext;
	Webcntxt::_di_IWebEndUser FEndUser;
	Webcntxt::_di_IWebEndUser __fastcall EndUser();
	
protected:
	HRESULT __safecall Get_DisplayName(WideString &Get_DisplayName_result);
	HRESULT __safecall Get_LoggedIn(Word &Get_LoggedIn_result);
	HRESULT __safecall Get_LoginFormAction(Webscript_tlb::_di_IAdapterActionWrapper &Get_LoginFormAction_result);
	HRESULT __safecall Get_LogoutAction(Webscript_tlb::_di_IAdapterActionWrapper &Get_LogoutAction_result);
	
public:
	__fastcall TWebEndUserWrapper(Httpprod::_di_IScriptContext AContext);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TWebEndUserWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebEndUserWrapper(const System::_di_IInterface Controller) : TAdapterWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebEndUserWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TAdapterWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IEndUserWrapper;	/* Webscript_tlb::IEndUserWrapper */
	
public:
	operator IEndUserWrapper*(void) { return (IEndUserWrapper*)&__IEndUserWrapper; }
	
};


class DELPHICLASS TWebApplicationWrapper;
class PASCALIMPLEMENTATION TWebApplicationWrapper : public TAdapterWrapper 
{
	typedef TAdapterWrapper inherited;
	
private:
	Httpprod::_di_IScriptContext FContext;
	Sitecomp::_di_IWebApplicationInfo FApplicationInfo;
	Sitecomp::_di_IWebApplicationInfo __fastcall ApplicationInfo();
	
protected:
	HRESULT __safecall Get_Title(WideString &Get_Title_result);
	HRESULT __safecall Get_Designing(Word &Get_Designing_result);
	HRESULT __safecall QualifyFileName(const WideString FileName, WideString &QualifyFileName_result);
	HRESULT __safecall Get_ModulePath(WideString &Get_ModulePath_result);
	HRESULT __safecall Get_ModuleFileName(WideString &Get_ModuleFileName_result);
	
public:
	__fastcall TWebApplicationWrapper(Httpprod::_di_IScriptContext AContext);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TWebApplicationWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebApplicationWrapper(const System::_di_IInterface Controller) : TAdapterWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebApplicationWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TAdapterWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IApplicationWrapper;	/* Webscript_tlb::IApplicationWrapper */
	
public:
	operator IApplicationWrapper*(void) { return (IApplicationWrapper*)&__IApplicationWrapper; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Autoadap */
using namespace Autoadap;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AutoAdap
