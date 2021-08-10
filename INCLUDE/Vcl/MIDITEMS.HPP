// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MidItems.pas' rev: 5.00

#ifndef MidItemsHPP
#define MidItemsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <MidProd.hpp>	// Pascal unit
#include <PagItems.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <XMLBrokr.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Miditems
{
//-- type declarations -------------------------------------------------------
__interface IMidasWebDataSet;
typedef System::DelphiInterface<IMidasWebDataSet> _di_IMidasWebDataSet;
__interface INTERFACE_UUID("{1E494CD4-D598-11D2-AF8C-00C04FB16EC3}") IMidasWebDataSet  : public IUnknown 
	
{
	
public:
	virtual int __fastcall FieldCount(void) = 0 ;
	virtual Db::TFields* __fastcall Fields(void) = 0 ;
	virtual void __fastcall FetchParams(void) = 0 ;
	virtual Db::TParams* __fastcall Params(void) = 0 ;
	virtual int __fastcall ParamCount(void) = 0 ;
	virtual void __fastcall AddOnDataChange(const Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall RemoveOnDataChange(const Classes::TNotifyEvent Value) = 0 ;
};

__interface IDataSetComponent;
typedef System::DelphiInterface<IDataSetComponent> _di_IDataSetComponent;
class DELPHICLASS TXMLDataSet;
__interface INTERFACE_UUID("{D1AE355D-F1C3-11D2-AFB3-00C04FB16EC3}") IDataSetComponent  : public IUnknown 
	
{
	
public:
	virtual Xmlbrokr::TXMLBroker* __fastcall GetXMLBroker(void) = 0 ;
	virtual _di_IMidasWebDataSet __fastcall GetDataSet(void) = 0 ;
	virtual TXMLDataSet* __fastcall GetXMLDataSet(void) = 0 ;
	__property _di_IMidasWebDataSet DataSet = {read=GetDataSet};
	__property Xmlbrokr::TXMLBroker* XMLBroker = {read=GetXMLBroker};
	__property TXMLDataSet* XMLDataSet = {read=GetXMLDataSet};
};

__interface IQueryFields;
typedef System::DelphiInterface<IQueryFields> _di_IQueryFields;
__interface INTERFACE_UUID("{DADD9F42-FD2B-11D2-AA78-00A024C11562}") IQueryFields  : public IUnknown 
	
{
	
public:
	virtual void __fastcall ValidateDataSet(void) = 0 ;
	virtual bool __fastcall IsParamInUse(AnsiString AName) = 0 ;
	virtual void __fastcall GetParamsList(Classes::TStrings* AList) = 0 ;
};

__interface IValidateFields;
typedef System::DelphiInterface<IValidateFields> _di_IValidateFields;
__interface INTERFACE_UUID("{10A1C310-2E47-11D3-B00E-00C04FB16EC3}") IValidateFields  : public IUnknown 
	
{
	
public:
	virtual bool __fastcall GetEnableValidateFields(void) = 0 ;
	virtual void __fastcall SetEnableValidateFields(bool Value) = 0 ;
	virtual bool __fastcall ValidateFields(Webcomp::_di_IAddScriptElements AddIntf) = 0 ;
	__property bool EnableValidateFields = {read=GetEnableValidateFields, write=SetEnableValidateFields
		};
};

__interface IValidateField;
typedef System::DelphiInterface<IValidateField> _di_IValidateField;
__interface INTERFACE_UUID("{10A1C310-2E47-11D3-B00E-00C04FB16EC3}") IValidateField  : public IUnknown 
	
{
	
public:
	virtual bool __fastcall ValidateField(_di_IMidasWebDataSet DataSet, Webcomp::_di_IAddScriptElements 
		AddIntf) = 0 ;
};

__interface IDataSetFields;
typedef System::DelphiInterface<IDataSetFields> _di_IDataSetFields;
__interface INTERFACE_UUID("{394C5DD4-F252-11D2-AA55-00A024C11562}") IDataSetFields  : public IUnknown 
	
{
	
public:
	virtual void __fastcall ValidateDataSet(void) = 0 ;
	virtual void __fastcall GetFieldsList(Classes::TStrings* AList) = 0 ;
	virtual bool __fastcall IsFieldInUse(AnsiString AName) = 0 ;
	virtual bool __fastcall HasStatusField(void) = 0 ;
	virtual Webcomp::TWebComponentList* __fastcall GetVisibleFields(void) = 0 ;
	__property Webcomp::TWebComponentList* VisibleFields = {read=GetVisibleFields};
};

__interface IRestoreDefaults;
typedef System::DelphiInterface<IRestoreDefaults> _di_IRestoreDefaults;
__interface INTERFACE_UUID("{394C5DD3-F252-11D2-AA55-00A024C11562}") IRestoreDefaults  : public IUnknown 
	
{
	
public:
	virtual void __fastcall RestoreDefaults(void) = 0 ;
};

__interface IHTMLField;
typedef System::DelphiInterface<IHTMLField> _di_IHTMLField;
__interface INTERFACE_UUID("{C72355D9-FE5C-11D2-AFC5-00C04FB16EC3}") IHTMLField  : public IUnknown 
{
	
public:
	virtual AnsiString __fastcall GetHTMLControlName(void) = 0 ;
	__property AnsiString HTMLControlName = {read=GetHTMLControlName};
};

__interface IQueryField;
typedef System::DelphiInterface<IQueryField> _di_IQueryField;
__interface INTERFACE_UUID("{7C321115-FCFB-11D2-AFC3-00C04FB16EC3}") IQueryField  : public IHTMLField 
	
{
	
public:
	virtual AnsiString __fastcall GetParamName(void) = 0 ;
	virtual void __fastcall SetParamName(AnsiString AParamName) = 0 ;
	virtual AnsiString __fastcall GetText(void) = 0 ;
	virtual void __fastcall SetText(const AnsiString Value) = 0 ;
	__property AnsiString ParamName = {read=GetParamName, write=SetParamName};
	__property AnsiString Text = {read=GetText, write=SetText};
};

__interface IDataSetField;
typedef System::DelphiInterface<IDataSetField> _di_IDataSetField;
__interface INTERFACE_UUID("{394C5DD5-F252-11D2-AA55-00A024C11562}") IDataSetField  : public IHTMLField 
	
{
	
public:
	virtual void __fastcall SetFieldName(AnsiString AFieldName) = 0 ;
	virtual AnsiString __fastcall GetFieldName(void) = 0 ;
	virtual AnsiString __fastcall GetRowSetFieldAttributes(const AnsiString FieldVarName) = 0 ;
	__property AnsiString FieldName = {read=GetFieldName, write=SetFieldName};
};

__interface IStatusField;
typedef System::DelphiInterface<IStatusField> _di_IStatusField;
__interface INTERFACE_UUID("{DA9A7341-FE79-11D2-AFC5-00C04FB16EC3}") IStatusField  : public IHTMLField 
	
{
	
};

__interface IXMLDisplay;
typedef System::DelphiInterface<IXMLDisplay> _di_IXMLDisplay;
__interface INTERFACE_UUID("{394C5DD6-F252-11D2-AA55-00A024C11562}") IXMLDisplay  : public IUnknown 
	
{
	
public:
	virtual AnsiString __fastcall GetXMLDisplayName(void) = 0 ;
	virtual AnsiString __fastcall GetXMLRowSetName(void) = 0 ;
	virtual bool __fastcall GetIsMultipleRecordView(void) = 0 ;
	__property AnsiString XMLRowSetName = {read=GetXMLRowSetName};
	__property AnsiString XMLDisplayName = {read=GetXMLDisplayName};
	__property bool IsMultipleRecordView = {read=GetIsMultipleRecordView};
};

__interface IXMLDisplayReference;
typedef System::DelphiInterface<IXMLDisplayReference> _di_IXMLDisplayReference;
__interface INTERFACE_UUID("{675ABA92-F660-11D2-AA59-00A024C11562}") IXMLDisplayReference  : public IUnknown 
	
{
	
public:
	virtual Classes::TComponent* __fastcall GetXMLDisplayComponent(void) = 0 ;
	__property Classes::TComponent* XMLDisplayComponent = {read=GetXMLDisplayComponent};
};

__interface IHTMLForm;
typedef System::DelphiInterface<IHTMLForm> _di_IHTMLForm;
__interface INTERFACE_UUID("{394C5DD7-F252-11D2-AA55-00A024C11562}") IHTMLForm  : public IUnknown 
{
	
public:
	virtual AnsiString __fastcall GetHTMLFormName(void) = 0 ;
	virtual AnsiString __fastcall GetHTMLFormVarName(void) = 0 ;
	__property AnsiString HTMLFormName = {read=GetHTMLFormName};
	__property AnsiString HTMLFormVarName = {read=GetHTMLFormVarName};
};

__interface IFormatColumn;
typedef System::DelphiInterface<IFormatColumn> _di_IFormatColumn;
__interface INTERFACE_UUID("{3417E2F0-22A0-11D3-B003-00C04FB16EC3}") IFormatColumn  : public IUnknown 
	
{
	
public:
	virtual AnsiString __fastcall FormatColumnHeading(void) = 0 ;
	virtual AnsiString __fastcall FormatColumnData(AnsiString Content) = 0 ;
};

__interface IQueryForm;
typedef System::DelphiInterface<IQueryForm> _di_IQueryForm;
__interface INTERFACE_UUID("{95097A4B-3A12-11D3-B01B-00C04FB16EC3}") IQueryForm  : public IUnknown 
{
	
};

typedef TMetaClass*TWebDataInputClass;

class DELPHICLASS TXMLData;
class PASCALIMPLEMENTATION TXMLData : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TComponent* FParent;
	Xmlbrokr::TXMLBroker* FXMLBroker;
	Classes::TNotifyEvent FOnChange;
	
protected:
	void __fastcall Changed(void);
	virtual void __fastcall ChangedXMLBroker(void);
	virtual void __fastcall SetXMLBroker(const Xmlbrokr::TXMLBroker* Value);
	virtual Xmlbrokr::TXMLBroker* __fastcall GetXMLBroker(void);
	
public:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	__fastcall TXMLData(Classes::TComponent* AParent);
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TComponent* Parent = {read=FParent};
	__property Xmlbrokr::TXMLBroker* XMLBroker = {read=GetXMLBroker, write=SetXMLBroker};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLData(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TXMLDataSet : public TXMLData 
{
	typedef TXMLData inherited;
	
private:
	AnsiString FDataSetField;
	_di_IMidasWebDataSet FDataSet;
	Classes::TStrings* FDataSetPath;
	Classes::_di_IInterfaceList FDiscardDataSetList;
	
protected:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	void __fastcall ConnectionChange(Classes::TComponent* Sender, bool Connecting);
	virtual void __fastcall SetXMLBroker(const Xmlbrokr::TXMLBroker* Value);
	_di_IMidasWebDataSet __fastcall FindDataSet();
	bool __fastcall CompareXMLData(TXMLDataSet* XMLDataSet);
	virtual void __fastcall ChangedXMLBroker(void);
	virtual void __fastcall ChangedDataSetField(void);
	void __fastcall WrapperDataChange(System::TObject* Sender);
	void __fastcall SetDataSetField(const AnsiString Value);
	_di_IMidasWebDataSet __fastcall GetDataSet();
	_di_IMidasWebDataSet __fastcall CreateDataSet();
	Classes::TStrings* __fastcall GetDataSetPath(void);
	virtual AnsiString __fastcall GetDataSetField();
	__property Classes::TComponent* Parent = {read=FParent};
	
public:
	__fastcall TXMLDataSet(Classes::TComponent* AParent);
	__fastcall virtual ~TXMLDataSet(void);
	__property _di_IMidasWebDataSet DataSet = {read=GetDataSet};
	__property Classes::TStrings* DataSetPath = {read=GetDataSetPath};
	__property AnsiString DataSetField = {read=GetDataSetField, write=SetDataSetField};
private:
	void *__INotifyConnectionChange;	/* Xmlbrokr::INotifyConnectionChange */
	
public:
	operator INotifyConnectionChange*(void) { return (INotifyConnectionChange*)&__INotifyConnectionChange; }
		
	
};


class DELPHICLASS TXMLDataSetParent;
class PASCALIMPLEMENTATION TXMLDataSetParent : public TXMLDataSet 
{
	typedef TXMLDataSet inherited;
	
private:
	bool FUseParent;
	
protected:
	virtual AnsiString __fastcall GetDataSetField();
	virtual Xmlbrokr::TXMLBroker* __fastcall GetXMLBroker(void);
	void __fastcall SetUseParent(const bool Value);
	virtual void __fastcall ChangedDataSetField(void);
	virtual void __fastcall ChangedXMLBroker(void);
	virtual void __fastcall ChangedUseParent(void);
	AnsiString __fastcall ParentDataSetField();
	TXMLDataSet* __fastcall ParentXMLDataSet(void);
	Xmlbrokr::TXMLBroker* __fastcall ParentXMLBroker(void);
	__property bool UseParent = {read=FUseParent, write=SetUseParent, nodefault};
public:
	#pragma option push -w-inl
	/* TXMLDataSet.Create */ inline __fastcall TXMLDataSetParent(Classes::TComponent* AParent) : TXMLDataSet(
		AParent) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLDataSet.Destroy */ inline __fastcall virtual ~TXMLDataSetParent(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLDataParent;
class PASCALIMPLEMENTATION TXMLDataParent : public TXMLData 
{
	typedef TXMLData inherited;
	
private:
	bool FUseParent;
	
protected:
	virtual void __fastcall ChangedUseParent(void);
	virtual Xmlbrokr::TXMLBroker* __fastcall GetXMLBroker(void);
	void __fastcall SetUseParent(const bool Value);
	virtual void __fastcall ChangedXMLBroker(void);
	Xmlbrokr::TXMLBroker* __fastcall ParentXMLBroker(void);
	
__published:
	__property bool UseParent = {read=FUseParent, write=SetUseParent, nodefault};
public:
	#pragma option push -w-inl
	/* TXMLData.Create */ inline __fastcall TXMLDataParent(Classes::TComponent* AParent) : TXMLData(AParent
		) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLDataParent(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLDisplay;
class PASCALIMPLEMENTATION TXMLDisplay : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TComponent* FParent;
	Classes::TComponent* FDisplayComponent;
	Classes::TNotifyEvent FOnChange;
	
protected:
	void __fastcall Changed(void);
	void __fastcall SetDisplayComponent(const Classes::TComponent* Value);
	virtual Classes::TComponent* __fastcall GetDisplayComponent(void);
	virtual void __fastcall ChangedDisplayComponent(void);
	
public:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	__fastcall TXMLDisplay(Classes::TComponent* AParent);
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TComponent* Parent = {read=FParent};
	__property Classes::TComponent* DisplayComponent = {read=GetDisplayComponent, write=SetDisplayComponent
		};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLDisplay(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLDisplayParent;
class PASCALIMPLEMENTATION TXMLDisplayParent : public TXMLDisplay 
{
	typedef TXMLDisplay inherited;
	
private:
	bool FUseParent;
	
protected:
	virtual Classes::TComponent* __fastcall GetDisplayComponent(void);
	void __fastcall SetUseParent(const bool Value);
	virtual void __fastcall ChangedDisplayComponent(void);
	virtual void __fastcall ChangedUseParent(void);
	
public:
	__fastcall TXMLDisplayParent(Classes::TComponent* AParent);
	
__published:
	__property bool UseParent = {read=FUseParent, write=SetUseParent, default=1};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLDisplayParent(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebForm;
class PASCALIMPLEMENTATION TWebForm : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Webcomp::TWebComponentList* FContainer;
	Webcomp::TWebComponentList* FWebComponents;
	AnsiString FCustom;
	AnsiString FStyle;
	AnsiString FStyleRule;
	Classes::TComponent* FWebParent;
	Webcomp::TLayoutAttributes* FLayoutAttributes;
	
protected:
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	bool __fastcall CanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass) = 0 ;
	int __fastcall GetIndex(void);
	void __fastcall SetIndex(int Value);
	void __fastcall SetContainer(System::TObject* Container);
	System::TObject* __fastcall GetContainer(void);
	void __fastcall SetComponentList(System::TObject* List);
	AnsiString __fastcall Content(Webcomp::TWebContentOptions* Options, System::TObject* Layout);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* Layout
		) = 0 ;
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	System::TObject* __fastcall GetComponentList(void);
	System::TObject* __fastcall GetDefaultComponentList(void);
	void __fastcall AddElements(Webcomp::_di_IAddScriptElements AddIntf);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	System::TObject* __fastcall GetSubComponents(void);
	AnsiString __fastcall GetHTMLFormName();
	AnsiString __fastcall GetHTMLFormVarName();
	Webcomp::TWebComponentList* __fastcall GetVisibleFields(void);
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	void __fastcall SetWebParent(const Classes::TComponent* Value);
	__property Webcomp::TWebComponentList* VisibleFields = {read=GetVisibleFields};
	
public:
	__fastcall virtual TWebForm(Classes::TComponent* AComponent);
	__fastcall virtual ~TWebForm(void);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	__property Webcomp::TWebComponentList* WebComponents = {read=FWebComponents};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
private:
	void *__IWebComponent;	/* Webcomp::IWebComponent */
	void *__IWebContent;	/* Webcomp::IWebContent */
	void *__IWebComponentEditor;	/* Webcomp::IWebComponentEditor */
	void *__IScriptComponent;	/* Webcomp::IScriptComponent */
	void *__IGetWebComponentList;	/* Webcomp::IGetWebComponentList */
	void *__IHTMLForm;	/* Miditems::IHTMLForm */
	
public:
	operator IHTMLForm*(void) { return (IHTMLForm*)&__IHTMLForm; }
	operator IGetWebComponentList*(void) { return (IGetWebComponentList*)&__IGetWebComponentList; }
	operator IScriptComponent*(void) { return (IScriptComponent*)&__IScriptComponent; }
	operator IWebComponentEditor*(void) { return (IWebComponentEditor*)&__IWebComponentEditor; }
	operator IWebContent*(void) { return (IWebContent*)&__IWebContent; }
	operator IWebComponent*(void) { return (IWebComponent*)&__IWebComponent; }
	
};


#pragma option push -b-
enum TFormMethod { fmPost, fmGet };
#pragma option pop

class DELPHICLASS TCustomQueryForm;
class PASCALIMPLEMENTATION TCustomQueryForm : public TWebForm 
{
	typedef TWebForm inherited;
	
private:
	AnsiString FAction;
	TFormMethod FMethod;
	Classes::TStrings* FAssignStrings;
	
protected:
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	virtual AnsiString __fastcall GetHTMLFormTag(Webcomp::TWebContentOptions* Options);
	AnsiString __fastcall MethodString();
	void __fastcall AssignStringsCallback(Classes::TComponent* AComponent);
	
public:
	__fastcall virtual TCustomQueryForm(Classes::TComponent* AOwner);
	void __fastcall AssignStrings(Classes::TStrings* Value);
	__property AnsiString Action = {read=FAction, write=FAction};
	__property TFormMethod Method = {read=FMethod, write=FMethod, nodefault};
public:
	#pragma option push -w-inl
	/* TWebForm.Destroy */ inline __fastcall virtual ~TCustomQueryForm(void) { }
	#pragma option pop
	
private:
	void *__IQueryForm;	/* Miditems::IQueryForm */
	
public:
	operator IQueryForm*(void) { return (IQueryForm*)&__IQueryForm; }
	
};


class DELPHICLASS TQueryForm;
class PASCALIMPLEMENTATION TQueryForm : public TCustomQueryForm 
{
	typedef TCustomQueryForm inherited;
	
__published:
	__property Action ;
	__property Method ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TCustomQueryForm.Create */ inline __fastcall virtual TQueryForm(Classes::TComponent* AOwner) : TCustomQueryForm(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebForm.Destroy */ inline __fastcall virtual ~TQueryForm(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataForm;
class PASCALIMPLEMENTATION TDataForm : public TWebForm 
{
	typedef TWebForm inherited;
	
protected:
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	virtual AnsiString __fastcall GetHTMLFormTag(Webcomp::TWebContentOptions* Options);
	
__published:
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebForm.Create */ inline __fastcall virtual TDataForm(Classes::TComponent* AComponent) : TWebForm(
		AComponent) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebForm.Destroy */ inline __fastcall virtual ~TDataForm(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebControlGroup;
class PASCALIMPLEMENTATION TWebControlGroup : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Webcomp::TWebComponentList* FContainer;
	Webcomp::TWebComponentList* FWebComponents;
	bool FDefaultField;
	Webcomp::TWebComponentList* FDefaultWebComponents;
	Classes::TComponent* FWebParent;
	
protected:
	void __fastcall SetWebParent(const Classes::TComponent* Value);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	void __fastcall AddElements(Webcomp::_di_IAddScriptElements AddIntf);
	System::TObject* __fastcall GetSubComponents(void);
	virtual System::TObject* __fastcall ImplGetSubComponents(void);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	AnsiString __fastcall Content(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
		
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	int __fastcall GetIndex(void);
	void __fastcall SetIndex(int Value);
	void __fastcall SetContainer(System::TObject* Container);
	System::TObject* __fastcall GetContainer(void);
	void __fastcall SetComponentList(System::TObject* List);
	System::TObject* __fastcall GetComponentList(void);
	System::TObject* __fastcall GetDefaultComponentList(void);
	bool __fastcall CanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	__property Webcomp::TWebComponentList* DefaultWebComponents = {read=FDefaultWebComponents, write=FDefaultWebComponents
		};
	
public:
	__fastcall virtual TWebControlGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebControlGroup(void);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	__property Webcomp::TWebComponentList* WebFieldControls = {read=FWebComponents};
private:
	void *__IWebComponent;	/* Webcomp::IWebComponent */
	void *__IGetWebComponentList;	/* Webcomp::IGetWebComponentList */
	void *__IWebComponentEditor;	/* Webcomp::IWebComponentEditor */
	void *__IScriptComponent;	/* Webcomp::IScriptComponent */
	void *__IWebContent;	/* Webcomp::IWebContent */
	
public:
	operator IWebContent*(void) { return (IWebContent*)&__IWebContent; }
	operator IScriptComponent*(void) { return (IScriptComponent*)&__IScriptComponent; }
	operator IWebComponentEditor*(void) { return (IWebComponentEditor*)&__IWebComponentEditor; }
	operator IGetWebComponentList*(void) { return (IGetWebComponentList*)&__IGetWebComponentList; }
	operator IWebComponent*(void) { return (IWebComponent*)&__IWebComponent; }
	
};


class DELPHICLASS TCustomLayoutGroup;
class PASCALIMPLEMENTATION TCustomLayoutGroup : public TWebControlGroup 
{
	typedef TWebControlGroup inherited;
	
private:
	int FDisplayColumns;
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FStyleRule;
	Webcomp::TLayoutAttributes* FLayoutAttributes;
	
protected:
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	
public:
	__fastcall virtual TCustomLayoutGroup(Classes::TComponent* AComponent);
	__fastcall virtual ~TCustomLayoutGroup(void);
	__property int DisplayColumns = {read=FDisplayColumns, write=FDisplayColumns, nodefault};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
};


class DELPHICLASS TLayoutGroup;
class PASCALIMPLEMENTATION TLayoutGroup : public TCustomLayoutGroup 
{
	typedef TCustomLayoutGroup inherited;
	
__published:
	__property DisplayColumns ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TCustomLayoutGroup.Create */ inline __fastcall virtual TLayoutGroup(Classes::TComponent* AComponent
		) : TCustomLayoutGroup(AComponent) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomLayoutGroup.Destroy */ inline __fastcall virtual ~TLayoutGroup(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLDisplayGroup;
class PASCALIMPLEMENTATION TXMLDisplayGroup : public TWebControlGroup 
{
	typedef TWebControlGroup inherited;
	
private:
	TXMLDataSet* FXMLDataSet;
	bool FEnableValidateFields;
	
protected:
	AnsiString __fastcall GetDataSetField();
	void __fastcall SetDataSetField(const AnsiString Value);
	void __fastcall SetXMLBroker(const Xmlbrokr::TXMLBroker* Value);
	virtual void __fastcall XMLDataChange(System::TObject* Sender);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual System::TObject* __fastcall ImplGetSubComponents(void);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	AnsiString __fastcall GetXMLDisplayName();
	AnsiString __fastcall GetXMLRowSetName();
	bool __fastcall GetIsMultipleRecordView(void);
	virtual bool __fastcall ImplIsMultipleRecordView(void);
	_di_IMidasWebDataSet __fastcall GetDataSet();
	Xmlbrokr::TXMLBroker* __fastcall GetXMLBroker(void);
	TXMLDataSet* __fastcall GetXMLDataSet(void);
	virtual void __fastcall GetFieldsList(Classes::TStrings* List);
	bool __fastcall IsFieldInUse(AnsiString AName);
	Webcomp::TWebComponentList* __fastcall GetVisibleFields(void);
	bool __fastcall HasStatusField(void);
	void __fastcall ValidateDataSet(void);
	bool __fastcall ValidateFields(Webcomp::_di_IAddScriptElements AddIntf);
	bool __fastcall GetEnableValidateFields(void);
	void __fastcall SetEnableValidateFields(bool Value);
	virtual void __fastcall CreateDefaultFields(void);
	Classes::TComponent* __fastcall FindField(const AnsiString AName);
	__property TXMLDataSet* XMLDataSet = {read=FXMLDataSet};
	__property bool EnableValidateFields = {read=GetEnableValidateFields, write=SetEnableValidateFields
		, nodefault};
	
public:
	__fastcall virtual TXMLDisplayGroup(Classes::TComponent* AComponent);
	__fastcall virtual ~TXMLDisplayGroup(void);
	__property Webcomp::TWebComponentList* VisibleFields = {read=GetVisibleFields};
	
__published:
	__property Xmlbrokr::TXMLBroker* XMLBroker = {read=GetXMLBroker, write=SetXMLBroker};
	__property AnsiString XMLDataSetField = {read=GetDataSetField, write=SetDataSetField};
private:
	void *__IDataSetComponent;	/* Miditems::IDataSetComponent */
	void *__IDataSetFields;	/* Miditems::IDataSetFields */
	void *__IXMLDisplay;	/* Miditems::IXMLDisplay */
	void *__IValidateFields;	/* Miditems::IValidateFields */
	
public:
	operator IValidateFields*(void) { return (IValidateFields*)&__IValidateFields; }
	operator IXMLDisplay*(void) { return (IXMLDisplay*)&__IXMLDisplay; }
	operator IDataSetFields*(void) { return (IDataSetFields*)&__IDataSetFields; }
	operator IDataSetComponent*(void) { return (IDataSetComponent*)&__IDataSetComponent; }
	
};


class DELPHICLASS TGridRowAttributes;
class PASCALIMPLEMENTATION TGridRowAttributes : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Httpapp::THTMLAlign FAlign;
	AnsiString FBgColor;
	Httpapp::THTMLVAlign FVAlign;
	AnsiString FStyle;
	AnsiString FStyleRule;
	AnsiString FCustom;
	Classes::TComponent* FParent;
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TGridRowAttributes(Classes::TComponent* AParent);
	__property Classes::TComponent* Parent = {read=FParent};
	
__published:
	__property Httpapp::THTMLAlign Align = {read=FAlign, write=FAlign, default=0};
	__property AnsiString BgColor = {read=FBgColor, write=FBgColor};
	__property Httpapp::THTMLVAlign VAlign = {read=FVAlign, write=FVAlign, default=0};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGridRowAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGridAttributes;
class PASCALIMPLEMENTATION TGridAttributes : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Httpapp::THTMLAlign FAlign;
	int FBorder;
	AnsiString FBgColor;
	int FCellSpacing;
	int FCellPadding;
	AnsiString FStyle;
	AnsiString FStyleRule;
	AnsiString FCustom;
	Classes::TComponent* FParent;
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TGridAttributes(Classes::TComponent* AParent);
	__property Classes::TComponent* Parent = {read=FParent};
	
__published:
	__property Httpapp::THTMLAlign Align = {read=FAlign, write=FAlign, default=0};
	__property AnsiString BgColor = {read=FBgColor, write=FBgColor};
	__property int Border = {read=FBorder, write=FBorder, default=1};
	__property int CellSpacing = {read=FCellSpacing, write=FCellSpacing, default=-1};
	__property int CellPadding = {read=FCellPadding, write=FCellPadding, default=-1};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGridAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomDataGrid;
class PASCALIMPLEMENTATION TCustomDataGrid : public TXMLDisplayGroup 
{
	typedef TXMLDisplayGroup inherited;
	
private:
	int FDisplayRows;
	TGridAttributes* FTableAttributes;
	TGridRowAttributes* FHeadingAttributes;
	TGridRowAttributes* FRowAttributes;
	
protected:
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	virtual bool __fastcall ImplIsMultipleRecordView(void);
	AnsiString __fastcall FormatTable(Webcomp::TLayoutWebContent* Layout, Webcomp::TWebContentOptions* 
		Options);
	void __fastcall SetTableAttributes(const TGridAttributes* Value);
	void __fastcall SetHeadingAttributes(const TGridRowAttributes* Value);
	void __fastcall SetRowAttributes(const TGridRowAttributes* Value);
	
public:
	__fastcall virtual TCustomDataGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDataGrid(void);
	__property int DisplayRows = {read=FDisplayRows, write=FDisplayRows, default=4};
	__property TGridAttributes* TableAttributes = {read=FTableAttributes, write=SetTableAttributes};
	__property TGridRowAttributes* HeadingAttributes = {read=FHeadingAttributes, write=SetHeadingAttributes
		};
	__property TGridRowAttributes* RowAttributes = {read=FRowAttributes, write=SetRowAttributes};
private:
		
	void *__IDataSetComponent;	/* Miditems::IDataSetComponent */
	
public:
	operator IDataSetComponent*(void) { return (IDataSetComponent*)&__IDataSetComponent; }
	
};


class DELPHICLASS TDataGrid;
class PASCALIMPLEMENTATION TDataGrid : public TCustomDataGrid 
{
	typedef TCustomDataGrid inherited;
	
__published:
	__property DisplayRows ;
	__property TableAttributes ;
	__property HeadingAttributes ;
	__property RowAttributes ;
public:
	#pragma option push -w-inl
	/* TCustomDataGrid.Create */ inline __fastcall virtual TDataGrid(Classes::TComponent* AOwner) : TCustomDataGrid(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomDataGrid.Destroy */ inline __fastcall virtual ~TDataGrid(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomFieldGroup;
class PASCALIMPLEMENTATION TCustomFieldGroup : public TXMLDisplayGroup 
{
	typedef TXMLDisplayGroup inherited;
	
private:
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FStyleRule;
	Webcomp::TLayoutAttributes* FLayoutAttributes;
	
protected:
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	
public:
	__fastcall virtual TCustomFieldGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomFieldGroup(void);
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
};


class DELPHICLASS TQueryFieldGroup;
class PASCALIMPLEMENTATION TQueryFieldGroup : public TCustomFieldGroup 
{
	typedef TCustomFieldGroup inherited;
	
protected:
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	bool __fastcall IsParamInUse(AnsiString AName);
	void __fastcall GetParamsList(Classes::TStrings* List);
	Classes::TComponent* __fastcall FindParam(const AnsiString AName);
	
__published:
	__property Custom ;
	__property Style ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TCustomFieldGroup.Create */ inline __fastcall virtual TQueryFieldGroup(Classes::TComponent* AOwner
		) : TCustomFieldGroup(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomFieldGroup.Destroy */ inline __fastcall virtual ~TQueryFieldGroup(void) { }
	#pragma option pop
	
private:
	void *__IQueryFields;	/* Miditems::IQueryFields */
	
public:
	operator IQueryFields*(void) { return (IQueryFields*)&__IQueryFields; }
	
};


class DELPHICLASS TFieldGroup;
class PASCALIMPLEMENTATION TFieldGroup : public TCustomFieldGroup 
{
	typedef TCustomFieldGroup inherited;
	
protected:
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	
__published:
	__property Custom ;
	__property Style ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TCustomFieldGroup.Create */ inline __fastcall virtual TFieldGroup(Classes::TComponent* AOwner) : 
		TCustomFieldGroup(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomFieldGroup.Destroy */ inline __fastcall virtual ~TFieldGroup(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCaptionPosition { capLeft, capRight, capAbove, capBelow };
#pragma option pop

class DELPHICLASS TCaptionAttributes;
class PASCALIMPLEMENTATION TCaptionAttributes : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TComponent* FParent;
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FStyleRule;
	
public:
	__fastcall TCaptionAttributes(Classes::TComponent* AParent);
	__property Classes::TComponent* Parent = {read=FParent};
	
__published:
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TCaptionAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebDataDisplay;
class PASCALIMPLEMENTATION TWebDataDisplay : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Webcomp::TWebComponentList* FWebComponents;
	Classes::TComponent* FWebParent;
	bool FDefaultField;
	AnsiString FCaption;
	TCaptionPosition FCaptionPosition;
	TCaptionAttributes* FCaptionAttributes;
	int FTabIndex;
	AnsiString FCustom;
	AnsiString FStyle;
	Webcomp::TLayoutAttributes* FLayoutAttributes;
	AnsiString FStyleRule;
	
protected:
	int __fastcall GetIndex(void);
	void __fastcall SetIndex(int Value);
	void __fastcall SetContainer(System::TObject* Container);
	System::TObject* __fastcall GetContainer(void);
	void __fastcall SetComponentList(System::TObject* List);
	AnsiString __fastcall Content(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
		
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	AnsiString __fastcall GetHTMLControlName();
	virtual AnsiString __fastcall ImplGetHTMLControlName();
	virtual AnsiString __fastcall ControlContent(Webcomp::TWebContentOptions* Options) = 0 ;
	virtual AnsiString __fastcall LabelContent();
	virtual AnsiString __fastcall GetCaption();
	virtual void __fastcall SetCaption(AnsiString Value);
	virtual AnsiString __fastcall EventContent(Webcomp::TWebContentOptions* Options);
	void __fastcall SetWebParent(Classes::TComponent* Value);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	_di_IHTMLForm __fastcall GetHTMLForm();
	AnsiString __fastcall GetXmlDisplayName();
	AnsiString __fastcall GetXmlRowSetName();
	void __fastcall SetCaptionAttributes(const TCaptionAttributes* Value);
	virtual AnsiString __fastcall FormatCaption();
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	__property Webcomp::TLayoutAttributes* LayoutAttributes = {read=FLayoutAttributes};
	__property TCaptionPosition CaptionPosition = {read=FCaptionPosition, write=FCaptionPosition, default=0
		};
	
public:
	__fastcall virtual TWebDataDisplay(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebDataDisplay(void);
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsColumn() { return IsColumn(__classid(TWebDataDisplay)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsColumn(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsQueryField() { return IsQueryField(__classid(TWebDataDisplay)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsQueryField(TMetaClass* vmt);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	__property AnsiString Caption = {read=GetCaption, write=FCaption};
	__property int TabIndex = {read=FTabIndex, write=FTabIndex, default=-1};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
	__property TCaptionAttributes* CaptionAttributes = {read=FCaptionAttributes, write=SetCaptionAttributes
		};
private:
	void *__IWebComponent;	/* Webcomp::IWebComponent */
	void *__IWebContent;	/* Webcomp::IWebContent */
	void *__IHTMLField;	/* Miditems::IHTMLField */
	
public:
	operator IHTMLField*(void) { return (IHTMLField*)&__IHTMLField; }
	operator IWebContent*(void) { return (IWebContent*)&__IWebContent; }
	operator IWebComponent*(void) { return (IWebComponent*)&__IWebComponent; }
	
};


typedef TMetaClass*TWebDataDisplayClass;

class DELPHICLASS TWebDataInput;
class PASCALIMPLEMENTATION TWebDataInput : public TWebDataDisplay 
{
	typedef TWebDataDisplay inherited;
	
private:
	AnsiString FFieldName;
	AnsiString FParamName;
	
protected:
	void __fastcall RestoreDefaults(void);
	virtual void __fastcall ImplRestoreDefaults(void);
	bool __fastcall ValidateField(_di_IMidasWebDataSet DataSet, Webcomp::_di_IAddScriptElements AddIntf
		);
	void __fastcall SetFieldName(AnsiString Value);
	AnsiString __fastcall GetFieldName();
	virtual AnsiString __fastcall ImplGetFieldName();
	AnsiString __fastcall GetRowSetFieldAttributes(const AnsiString FieldVarName);
	virtual AnsiString __fastcall ImplGetRowSetFieldAttributes(const AnsiString FieldVarName);
	virtual AnsiString __fastcall ImplGetHTMLControlName();
	virtual void __fastcall RestoreFieldDefaults(Db::TField* AField);
	virtual Db::TField* __fastcall FindAssociatedField(_di_IMidasWebDataSet DataSet);
	virtual AnsiString __fastcall GetParamName();
	void __fastcall SetParamName(AnsiString Value);
	virtual AnsiString __fastcall GetCaption();
	virtual AnsiString __fastcall EventContent(Webcomp::TWebContentOptions* Options);
	virtual void __fastcall SetCaption(AnsiString Value);
	__property AnsiString ParamName = {read=GetParamName, write=SetParamName};
	
public:
	__property AnsiString FieldName = {read=GetFieldName, write=SetFieldName};
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Create */ inline __fastcall virtual TWebDataInput(Classes::TComponent* AOwner) : 
		TWebDataDisplay(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TWebDataInput(void) { }
	#pragma option pop
	
private:
	void *__IRestoreDefaults;	/* Miditems::IRestoreDefaults */
	void *__IDataSetField;	/* Miditems::IDataSetField */
	void *__IValidateField;	/* Miditems::IValidateField */
	
public:
	operator IValidateField*(void) { return (IValidateField*)&__IValidateField; }
	operator IDataSetField*(void) { return (IDataSetField*)&__IDataSetField; }
	operator IRestoreDefaults*(void) { return (IRestoreDefaults*)&__IRestoreDefaults; }
	
};


class DELPHICLASS TWebStatus;
class PASCALIMPLEMENTATION TWebStatus : public TWebDataDisplay 
{
	typedef TWebDataDisplay inherited;
	
private:
	int FDisplayWidth;
	
protected:
	virtual AnsiString __fastcall ImplGetHTMLControlName();
	virtual AnsiString __fastcall GetCaption();
	virtual AnsiString __fastcall ControlContent(Webcomp::TWebContentOptions* Options);
	
public:
	/*         class method */ static AnsiString __fastcall Identifier(TMetaClass* vmt);
	__fastcall virtual TWebStatus(Classes::TComponent* AOwner);
	__property int DisplayWidth = {read=FDisplayWidth, write=FDisplayWidth, default=1};
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TWebStatus(void) { }
	#pragma option pop
	
private:
	void *__IStatusField;	/* Miditems::IStatusField */
	
public:
	operator IStatusField*(void) { return (IStatusField*)&__IStatusField; }
	
};


typedef TMetaClass*TWebStatusClass;

class DELPHICLASS TFieldStatus;
class PASCALIMPLEMENTATION TFieldStatus : public TWebStatus 
{
	typedef TWebStatus inherited;
	
__published:
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebStatus.Create */ inline __fastcall virtual TFieldStatus(Classes::TComponent* AOwner) : TWebStatus(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TFieldStatus(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStatusColumn;
class PASCALIMPLEMENTATION TStatusColumn : public TWebStatus 
{
	typedef TWebStatus inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsColumn() { return IsColumn(__classid(TStatusColumn)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsColumn(TMetaClass* vmt);
	
__published:
	__property Caption ;
	__property CaptionAttributes ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebStatus.Create */ inline __fastcall virtual TStatusColumn(Classes::TComponent* AOwner) : TWebStatus(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TStatusColumn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebTextInput;
class PASCALIMPLEMENTATION TWebTextInput : public TWebDataInput 
{
	typedef TWebDataInput inherited;
	
private:
	int FDisplayWidth;
	bool FReadOnly;
	
protected:
	virtual void __fastcall AddAttributes(AnsiString &Attrs);
	virtual AnsiString __fastcall ControlContent(Webcomp::TWebContentOptions* Options);
	virtual void __fastcall RestoreFieldDefaults(Db::TField* AField);
	virtual AnsiString __fastcall ImplGetRowSetFieldAttributes(const AnsiString FieldVarName);
	
public:
	__fastcall virtual TWebTextInput(Classes::TComponent* AOwner);
	__property int DisplayWidth = {read=FDisplayWidth, write=FDisplayWidth, nodefault};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TWebTextInput(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFieldText;
class PASCALIMPLEMENTATION TFieldText : public TWebTextInput 
{
	typedef TWebTextInput inherited;
	
__published:
	__property DisplayWidth ;
	__property ReadOnly ;
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
	__property FieldName ;
	__property TabIndex ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebTextInput.Create */ inline __fastcall virtual TFieldText(Classes::TComponent* AOwner) : TWebTextInput(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TFieldText(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTextColumn;
class PASCALIMPLEMENTATION TTextColumn : public TWebTextInput 
{
	typedef TWebTextInput inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsColumn() { return IsColumn(__classid(TTextColumn)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsColumn(TMetaClass* vmt);
	
__published:
	__property DisplayWidth ;
	__property ReadOnly ;
	__property Caption ;
	__property CaptionAttributes ;
	__property FieldName ;
	__property TabIndex ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebTextInput.Create */ inline __fastcall virtual TTextColumn(Classes::TComponent* AOwner) : TWebTextInput(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TTextColumn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQueryText;
class PASCALIMPLEMENTATION TQueryText : public TWebTextInput 
{
	typedef TWebTextInput inherited;
	
private:
	AnsiString FText;
	int FMaxWidth;
	
protected:
	AnsiString __fastcall GetText();
	virtual void __fastcall AddAttributes(AnsiString &Attrs);
	void __fastcall SetText(const AnsiString Value);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsQueryField() { return IsQueryField(__classid(TQueryText)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsQueryField(TMetaClass* vmt);
	__fastcall virtual TQueryText(Classes::TComponent* AOwner);
	
__published:
	__property ParamName ;
	__property DisplayWidth ;
	__property ReadOnly ;
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
	__property FieldName ;
	__property TabIndex ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property AnsiString Text = {read=GetText, write=SetText};
	__property int MaxWidth = {read=FMaxWidth, write=FMaxWidth, default=-1};
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TQueryText(void) { }
	#pragma option pop
	
private:
	void *__IQueryField;	/* Miditems::IQueryField */
	
public:
	operator IQueryField*(void) { return (IQueryField*)&__IQueryField; }
	
};


#pragma option push -b-
enum TTextAreaWrap { wrOff, wrPhysical, wrVirtual };
#pragma option pop

class DELPHICLASS TWebTextAreaInput;
class PASCALIMPLEMENTATION TWebTextAreaInput : public TWebDataInput 
{
	typedef TWebDataInput inherited;
	
private:
	bool FReadOnly;
	TTextAreaWrap FWrap;
	int FDisplayWidth;
	int FDisplayRows;
	
protected:
	virtual void __fastcall AddAttributes(AnsiString &Attrs);
	virtual AnsiString __fastcall ControlContent(Webcomp::TWebContentOptions* Options);
	virtual void __fastcall RestoreFieldDefaults(Db::TField* AField);
	virtual AnsiString __fastcall ImplGetRowSetFieldAttributes(const AnsiString FieldVarName);
	virtual AnsiString __fastcall EventContent(Webcomp::TWebContentOptions* Options);
	
public:
	__fastcall virtual TWebTextAreaInput(Classes::TComponent* AOwner);
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property TTextAreaWrap Wrap = {read=FWrap, write=FWrap, nodefault};
	__property int DisplayWidth = {read=FDisplayWidth, write=FDisplayWidth, nodefault};
	__property int DisplayRows = {read=FDisplayRows, write=FDisplayRows, nodefault};
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TWebTextAreaInput(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFieldTextArea;
class PASCALIMPLEMENTATION TFieldTextArea : public TWebTextAreaInput 
{
	typedef TWebTextAreaInput inherited;
	
__published:
	__property ReadOnly ;
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
	__property FieldName ;
	__property Wrap ;
	__property DisplayWidth ;
	__property DisplayRows ;
	__property TabIndex ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebTextAreaInput.Create */ inline __fastcall virtual TFieldTextArea(Classes::TComponent* AOwner
		) : TWebTextAreaInput(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TFieldTextArea(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQueryTextArea;
class PASCALIMPLEMENTATION TQueryTextArea : public TWebTextAreaInput 
{
	typedef TWebTextAreaInput inherited;
	
private:
	Classes::TStrings* FLines;
	
protected:
	virtual void __fastcall AddAttributes(AnsiString &Attrs);
	void __fastcall SetLines(const Classes::TStrings* Value);
	virtual AnsiString __fastcall ControlContent(Webcomp::TWebContentOptions* Options);
	void __fastcall SetText(const AnsiString Value);
	AnsiString __fastcall GetText();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsQueryField() { return IsQueryField(__classid(TQueryTextArea)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsQueryField(TMetaClass* vmt);
	__fastcall virtual TQueryTextArea(Classes::TComponent* AOwner);
	__fastcall virtual ~TQueryTextArea(void);
	
__published:
	__property ParamName ;
	__property ReadOnly ;
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
	__property FieldName ;
	__property Wrap ;
	__property DisplayWidth ;
	__property DisplayRows ;
	__property TabIndex ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property Classes::TStrings* Lines = {read=FLines, write=SetLines};
private:
	void *__IQueryField;	/* Miditems::IQueryField */
	
public:
	operator IQueryField*(void) { return (IQueryField*)&__IQueryField; }
	
};


class DELPHICLASS TTextAreaColumn;
class PASCALIMPLEMENTATION TTextAreaColumn : public TWebTextAreaInput 
{
	typedef TWebTextAreaInput inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsColumn() { return IsColumn(__classid(TTextAreaColumn)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsColumn(TMetaClass* vmt);
	
__published:
	__property ReadOnly ;
	__property Caption ;
	__property CaptionAttributes ;
	__property FieldName ;
	__property Wrap ;
	__property DisplayWidth ;
	__property DisplayRows ;
	__property TabIndex ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebTextAreaInput.Create */ inline __fastcall virtual TTextAreaColumn(Classes::TComponent* AOwner
		) : TWebTextAreaInput(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TTextAreaColumn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebListInput;
class PASCALIMPLEMENTATION TWebListInput : public TWebDataInput 
{
	typedef TWebDataInput inherited;
	
private:
	Classes::TStrings* FValues;
	Classes::TStrings* FItems;
	Db::TDataSet* FDataSet;
	AnsiString FValuesField;
	AnsiString FItemsField;
	
protected:
	void __fastcall AddElements(Webcomp::_di_IAddScriptElements AddIntf);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	System::TObject* __fastcall GetSubComponents(void);
	void __fastcall SetItems(const Classes::TStrings* Value);
	void __fastcall SetValues(const Classes::TStrings* Value);
	void __fastcall SetDataSet(const Db::TDataSet* Value);
	virtual AnsiString __fastcall FormatInputs(Classes::TStrings* ItemsStrings, Classes::TStrings* ValuesStrings
		, Webcomp::TWebContentOptions* Options) = 0 ;
	virtual AnsiString __fastcall ControlContent(Webcomp::TWebContentOptions* Options);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TWebListInput(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebListInput(void);
	__property Classes::TStrings* Values = {read=FValues, write=SetValues};
	__property Classes::TStrings* Items = {read=FItems, write=SetItems};
	__property Db::TDataSet* DataSet = {read=FDataSet, write=SetDataSet};
	__property AnsiString ValuesField = {read=FValuesField, write=FValuesField};
	__property AnsiString ItemsField = {read=FItemsField, write=FItemsField};
private:
	void *__IScriptComponent;	/* Webcomp::IScriptComponent */
	
public:
	operator IScriptComponent*(void) { return (IScriptComponent*)&__IScriptComponent; }
	
};


class DELPHICLASS TWebRadioGroupInput;
class PASCALIMPLEMENTATION TWebRadioGroupInput : public TWebListInput 
{
	typedef TWebListInput inherited;
	
private:
	bool FReadOnly;
	int FDisplayWidth;
	int FDisplayColumns;
	
protected:
	virtual void __fastcall AddAttributes(AnsiString &Attrs);
	virtual AnsiString __fastcall FormatInputs(Classes::TStrings* ItemsStrings, Classes::TStrings* ValuesStrings
		, Webcomp::TWebContentOptions* Options);
	virtual void __fastcall RestoreFieldDefaults(Db::TField* AField);
	virtual int __fastcall GetCheckIndex(Classes::TStrings* ItemsStrings, Classes::TStrings* ValuesStrings
		);
	virtual AnsiString __fastcall EventContent(Webcomp::TWebContentOptions* Options);
	virtual AnsiString __fastcall ImplGetRowSetFieldAttributes(const AnsiString FieldVarName);
	
public:
	__fastcall virtual TWebRadioGroupInput(Classes::TComponent* AOwner);
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, nodefault};
	__property int DisplayWidth = {read=FDisplayWidth, write=FDisplayWidth, nodefault};
	__property int DisplayColumns = {read=FDisplayColumns, write=FDisplayColumns, nodefault};
public:
	#pragma option push -w-inl
	/* TWebListInput.Destroy */ inline __fastcall virtual ~TWebRadioGroupInput(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFieldRadioGroup;
class PASCALIMPLEMENTATION TFieldRadioGroup : public TWebRadioGroupInput 
{
	typedef TWebRadioGroupInput inherited;
	
__published:
	__property ReadOnly ;
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
	__property FieldName ;
	__property DisplayWidth ;
	__property DisplayColumns ;
	__property TabIndex ;
	__property Values ;
	__property Items ;
	__property DataSet ;
	__property ValuesField ;
	__property ItemsField ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebRadioGroupInput.Create */ inline __fastcall virtual TFieldRadioGroup(Classes::TComponent* AOwner
		) : TWebRadioGroupInput(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebListInput.Destroy */ inline __fastcall virtual ~TFieldRadioGroup(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQueryRadioGroup;
class PASCALIMPLEMENTATION TQueryRadioGroup : public TWebRadioGroupInput 
{
	typedef TWebRadioGroupInput inherited;
	
private:
	AnsiString FText;
	
protected:
	AnsiString __fastcall GetText();
	void __fastcall SetText(const AnsiString Value);
	virtual int __fastcall GetCheckIndex(Classes::TStrings* ItemsStrings, Classes::TStrings* ValuesStrings
		);
	virtual void __fastcall AddAttributes(AnsiString &Attrs);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsQueryField() { return IsQueryField(__classid(TQueryRadioGroup)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsQueryField(TMetaClass* vmt);
	
__published:
	__property ParamName ;
	__property ReadOnly ;
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
	__property FieldName ;
	__property DisplayWidth ;
	__property DisplayColumns ;
	__property TabIndex ;
	__property Values ;
	__property Items ;
	__property DataSet ;
	__property ValuesField ;
	__property ItemsField ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property AnsiString Text = {read=GetText, write=SetText};
public:
	#pragma option push -w-inl
	/* TWebRadioGroupInput.Create */ inline __fastcall virtual TQueryRadioGroup(Classes::TComponent* AOwner
		) : TWebRadioGroupInput(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebListInput.Destroy */ inline __fastcall virtual ~TQueryRadioGroup(void) { }
	#pragma option pop
	
private:
	void *__IQueryField;	/* Miditems::IQueryField */
	
public:
	operator IQueryField*(void) { return (IQueryField*)&__IQueryField; }
	
};


class DELPHICLASS TWebSelectOptionsInput;
class PASCALIMPLEMENTATION TWebSelectOptionsInput : public TWebListInput 
{
	typedef TWebListInput inherited;
	
private:
	int FDisplayRows;
	
protected:
	virtual void __fastcall AddAttributes(AnsiString &Attrs);
	virtual int __fastcall GetSelectIndex(Classes::TStrings* ItemsStrings, Classes::TStrings* ValuesStrings
		);
	virtual AnsiString __fastcall FormatInputs(Classes::TStrings* ItemsStrings, Classes::TStrings* ValuesStrings
		, Webcomp::TWebContentOptions* Options);
	virtual AnsiString __fastcall EventContent(Webcomp::TWebContentOptions* Options);
	
public:
	__fastcall virtual TWebSelectOptionsInput(Classes::TComponent* AOwner);
	__property int DisplayRows = {read=FDisplayRows, write=FDisplayRows, nodefault};
public:
	#pragma option push -w-inl
	/* TWebListInput.Destroy */ inline __fastcall virtual ~TWebSelectOptionsInput(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFieldSelectOptions;
class PASCALIMPLEMENTATION TFieldSelectOptions : public TWebSelectOptionsInput 
{
	typedef TWebSelectOptionsInput inherited;
	
__published:
	__property DisplayRows ;
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
	__property FieldName ;
	__property TabIndex ;
	__property Values ;
	__property Items ;
	__property DataSet ;
	__property ValuesField ;
	__property ItemsField ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebSelectOptionsInput.Create */ inline __fastcall virtual TFieldSelectOptions(Classes::TComponent* 
		AOwner) : TWebSelectOptionsInput(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebListInput.Destroy */ inline __fastcall virtual ~TFieldSelectOptions(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQuerySelectOptions;
class PASCALIMPLEMENTATION TQuerySelectOptions : public TWebSelectOptionsInput 
{
	typedef TWebSelectOptionsInput inherited;
	
private:
	AnsiString FText;
	
protected:
	AnsiString __fastcall GetText();
	void __fastcall SetText(const AnsiString Value);
	virtual int __fastcall GetSelectIndex(Classes::TStrings* ItemsStrings, Classes::TStrings* ValuesStrings
		);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsQueryField() { return IsQueryField(__classid(TQuerySelectOptions)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsQueryField(TMetaClass* vmt);
	
__published:
	__property ParamName ;
	__property DisplayRows ;
	__property Caption ;
	__property CaptionAttributes ;
	__property CaptionPosition ;
	__property FieldName ;
	__property TabIndex ;
	__property Values ;
	__property Items ;
	__property DataSet ;
	__property ValuesField ;
	__property ItemsField ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property AnsiString Text = {read=GetText, write=SetText};
public:
	#pragma option push -w-inl
	/* TWebSelectOptionsInput.Create */ inline __fastcall virtual TQuerySelectOptions(Classes::TComponent* 
		AOwner) : TWebSelectOptionsInput(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebListInput.Destroy */ inline __fastcall virtual ~TQuerySelectOptions(void) { }
	#pragma option pop
	
private:
	void *__IQueryField;	/* Miditems::IQueryField */
	
public:
	operator IQueryField*(void) { return (IQueryField*)&__IQueryField; }
	
};


class DELPHICLASS TSelectOptionsColumn;
class PASCALIMPLEMENTATION TSelectOptionsColumn : public TWebSelectOptionsInput 
{
	typedef TWebSelectOptionsInput inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall IsColumn() { return IsColumn(__classid(TSelectOptionsColumn)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall IsColumn(TMetaClass* vmt);
	
__published:
	__property DisplayRows ;
	__property Caption ;
	__property CaptionAttributes ;
	__property FieldName ;
	__property TabIndex ;
	__property Values ;
	__property Items ;
	__property DataSet ;
	__property ValuesField ;
	__property ItemsField ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebSelectOptionsInput.Create */ inline __fastcall virtual TSelectOptionsColumn(Classes::TComponent* 
		AOwner) : TWebSelectOptionsInput(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebListInput.Destroy */ inline __fastcall virtual ~TSelectOptionsColumn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebButton;
class PASCALIMPLEMENTATION TWebButton : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TComponent* FWebParent;
	Webcomp::TWebComponentList* FWebButtonsList;
	bool FDefaultButton;
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FCaption;
	AnsiString FStyleRule;
	void __fastcall SetWebParent(const Classes::TComponent* Value);
	
protected:
	int __fastcall GetIndex(void);
	void __fastcall SetIndex(int Value);
	void __fastcall SetContainer(System::TObject* Container);
	System::TObject* __fastcall GetContainer(void);
	void __fastcall SetComponentList(System::TObject* List);
	AnsiString __fastcall Content(Webcomp::TWebContentOptions* Options, System::TObject* Layout);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* Layout
		) = 0 ;
	virtual AnsiString __fastcall GetCaption();
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	
public:
	__fastcall virtual TWebButton(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebButton(void);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	__property AnsiString Caption = {read=GetCaption, write=FCaption};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
private:
	void *__IWebComponent;	/* Webcomp::IWebComponent */
	void *__IWebContent;	/* Webcomp::IWebContent */
	
public:
	operator IWebContent*(void) { return (IWebContent*)&__IWebContent; }
	operator IWebComponent*(void) { return (IWebComponent*)&__IWebComponent; }
	
};


typedef TMetaClass*TWebButtonClass;

class DELPHICLASS TXMLDisplayReferenceButton;
class PASCALIMPLEMENTATION TXMLDisplayReferenceButton : public TWebButton 
{
	typedef TWebButton inherited;
	
private:
	TXMLDisplayParent* FXMLDisplay;
	
protected:
	bool __fastcall GetDisplayComponentParent(void);
	Classes::TComponent* __fastcall GetDisplayComponent(void);
	void __fastcall SetDisplayComponent(const Classes::TComponent* Value);
	void __fastcall SetDisplayComponentParent(const bool Value);
	AnsiString __fastcall GetXmlDisplayName();
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	__property TXMLDisplayParent* XMLDisplay = {read=FXMLDisplay};
	
public:
	__fastcall virtual TXMLDisplayReferenceButton(Classes::TComponent* AOwner);
	__fastcall virtual ~TXMLDisplayReferenceButton(void);
	__property Classes::TComponent* XMLComponent = {read=GetDisplayComponent, write=SetDisplayComponent
		};
	__property bool XMLUseParent = {read=GetDisplayComponentParent, write=SetDisplayComponentParent, default=1
		};
};


class DELPHICLASS TDataSetButton;
class PASCALIMPLEMENTATION TDataSetButton : public TXMLDisplayReferenceButton 
{
	typedef TXMLDisplayReferenceButton inherited;
	
protected:
	AnsiString DefaultCaption;
	AnsiString XMLMethodName;
	void __fastcall AddElements(Webcomp::_di_IAddScriptElements AddIntf);
	System::TObject* __fastcall GetSubComponents(void);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	virtual AnsiString __fastcall GetCaption();
	virtual AnsiString __fastcall GetMethodName();
	
__published:
	__property XMLComponent ;
	__property XMLUseParent ;
	__property Style ;
	__property Custom ;
	__property Caption ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Create */ inline __fastcall virtual TDataSetButton(Classes::TComponent* 
		AOwner) : TXMLDisplayReferenceButton(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TDataSetButton(void) { }
	#pragma option pop
	
private:
	void *__IScriptComponent;	/* Webcomp::IScriptComponent */
	
public:
	operator IScriptComponent*(void) { return (IScriptComponent*)&__IScriptComponent; }
	
};


class DELPHICLASS TFirstButton;
class PASCALIMPLEMENTATION TFirstButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TFirstButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TFirstButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLastButton;
class PASCALIMPLEMENTATION TLastButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TLastButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TLastButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPriorButton;
class PASCALIMPLEMENTATION TPriorButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TPriorButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TPriorButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TNextButton;
class PASCALIMPLEMENTATION TNextButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TNextButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TNextButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPriorPageButton;
class PASCALIMPLEMENTATION TPriorPageButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TPriorPageButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TPriorPageButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TNextPageButton;
class PASCALIMPLEMENTATION TNextPageButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TNextPageButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TNextPageButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TUndoButton;
class PASCALIMPLEMENTATION TUndoButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TUndoButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TUndoButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDeleteButton;
class PASCALIMPLEMENTATION TDeleteButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TDeleteButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TDeleteButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TInsertButton;
class PASCALIMPLEMENTATION TInsertButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TInsertButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TInsertButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPostButton;
class PASCALIMPLEMENTATION TPostButton : public TDataSetButton 
{
	typedef TDataSetButton inherited;
	
public:
	__fastcall virtual TPostButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceButton.Destroy */ inline __fastcall virtual ~TPostButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLButton;
class PASCALIMPLEMENTATION TXMLButton : public TWebButton 
{
	typedef TWebButton inherited;
	
private:
	AnsiString FDefaultCaption;
	TXMLDataParent* FXMLData;
	
protected:
	Xmlbrokr::TXMLBroker* __fastcall GetXMLBroker(void);
	void __fastcall SetXMLBroker(const Xmlbrokr::TXMLBroker* Value);
	bool __fastcall GetXMLUseParent(void);
	void __fastcall SetXMLUseParent(const bool Value);
	virtual AnsiString __fastcall GetCaption();
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	__property TXMLDataParent* XMLData = {read=FXMLData};
	__property AnsiString DefaultCaption = {read=FDefaultCaption, write=FDefaultCaption};
	
public:
	__fastcall virtual TXMLButton(Classes::TComponent* AOwner);
	__fastcall virtual ~TXMLButton(void);
	__property Xmlbrokr::TXMLBroker* XMLBroker = {read=GetXMLBroker, write=SetXMLBroker};
	__property bool XMLUseParent = {read=GetXMLUseParent, write=SetXMLUseParent, nodefault};
};


class DELPHICLASS TApplyUpdatesButton;
class PASCALIMPLEMENTATION TApplyUpdatesButton : public TXMLButton 
{
	typedef TXMLButton inherited;
	
protected:
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	void __fastcall AddElements(Webcomp::_di_IAddScriptElements AddIntf);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	System::TObject* __fastcall GetSubComponents(void);
	
public:
	__fastcall virtual TApplyUpdatesButton(Classes::TComponent* AOwner);
	
__published:
	__property Custom ;
	__property Style ;
	__property StyleRule ;
	__property Caption ;
	__property XMLBroker ;
	__property XMLUseParent ;
public:
	#pragma option push -w-inl
	/* TXMLButton.Destroy */ inline __fastcall virtual ~TApplyUpdatesButton(void) { }
	#pragma option pop
	
private:
	void *__IScriptComponent;	/* Webcomp::IScriptComponent */
	
public:
	operator IScriptComponent*(void) { return (IScriptComponent*)&__IScriptComponent; }
	
};


class DELPHICLASS TXMLDisplayReferenceGroup;
class PASCALIMPLEMENTATION TXMLDisplayReferenceGroup : public TWebControlGroup 
{
	typedef TWebControlGroup inherited;
	
private:
	TXMLDisplay* FXMLDisplay;
	
protected:
	Classes::TComponent* __fastcall GetXMLDisplayComponent(void);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	void __fastcall SetXMLDisplayComponent(const Classes::TComponent* Value);
	__property TXMLDisplay* XMLDisplay = {read=FXMLDisplay};
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TXMLDisplayReferenceGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TXMLDisplayReferenceGroup(void);
	__property Classes::TComponent* XMLComponent = {read=GetXMLDisplayComponent, write=SetXMLDisplayComponent
		};
private:
	void *__IXMLDisplayReference;	/* Miditems::IXMLDisplayReference */
	
public:
	operator IXMLDisplayReference*(void) { return (IXMLDisplayReference*)&__IXMLDisplayReference; }
	
};


class DELPHICLASS TCustomDataNavigator;
class PASCALIMPLEMENTATION TCustomDataNavigator : public TXMLDisplayReferenceGroup 
{
	typedef TXMLDisplayReferenceGroup inherited;
	
private:
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FStyleRule;
	
protected:
	virtual System::TObject* __fastcall ImplGetSubComponents(void);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	Webcomp::TWebComponentList* __fastcall VisibleButtons(void);
	virtual void __fastcall GetDefaultButtons(void);
	
public:
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceGroup.Create */ inline __fastcall virtual TCustomDataNavigator(Classes::TComponent* 
		AOwner) : TXMLDisplayReferenceGroup(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLDisplayReferenceGroup.Destroy */ inline __fastcall virtual ~TCustomDataNavigator(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataNavigator;
class PASCALIMPLEMENTATION TDataNavigator : public TCustomDataNavigator 
{
	typedef TCustomDataNavigator inherited;
	
__published:
	__property XMLComponent ;
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TXMLDisplayReferenceGroup.Create */ inline __fastcall virtual TDataNavigator(Classes::TComponent* 
		AOwner) : TCustomDataNavigator(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLDisplayReferenceGroup.Destroy */ inline __fastcall virtual ~TDataNavigator(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQueryButton;
class PASCALIMPLEMENTATION TQueryButton : public TWebButton 
{
	typedef TWebButton inherited;
	
private:
	AnsiString FCaption;
	Classes::TComponent* FXMLComponent;
	bool FXMLUseParent;
	
protected:
	AnsiString DefaultCaption;
	AnsiString InputType;
	Classes::TComponent* __fastcall ParentXMLComponent(void);
	Classes::TComponent* __fastcall GetXMLComponent(void);
	void __fastcall SetXMLComponent(const Classes::TComponent* Value);
	void __fastcall SetXMLUseParent(const bool Value);
	virtual AnsiString __fastcall GetCaption();
	virtual AnsiString __fastcall GetInputType();
	virtual AnsiString __fastcall GetHTMLControlName();
	_di_IHTMLForm __fastcall GetHTMLForm();
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	virtual AnsiString __fastcall EventContent(Webcomp::TWebContentOptions* Options);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TQueryButton(Classes::TComponent* AOwner);
	
__published:
	__property AnsiString Caption = {read=GetCaption, write=FCaption};
	__property Custom ;
	__property Style ;
	__property StyleRule ;
	__property Classes::TComponent* XMLComponent = {read=GetXMLComponent, write=SetXMLComponent};
	__property bool XMLUseParent = {read=FXMLUseParent, write=SetXMLUseParent, default=1};
public:
	#pragma option push -w-inl
	/* TWebButton.Destroy */ inline __fastcall virtual ~TQueryButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSubmitQueryButton;
class PASCALIMPLEMENTATION TSubmitQueryButton : public TQueryButton 
{
	typedef TQueryButton inherited;
	
protected:
	virtual AnsiString __fastcall EventContent(Webcomp::TWebContentOptions* Options);
	
public:
	__fastcall virtual TSubmitQueryButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TWebButton.Destroy */ inline __fastcall virtual ~TSubmitQueryButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TResetQueryButton;
class PASCALIMPLEMENTATION TResetQueryButton : public TQueryButton 
{
	typedef TQueryButton inherited;
	
protected:
	virtual AnsiString __fastcall EventContent(Webcomp::TWebContentOptions* Options);
	
public:
	__fastcall virtual TResetQueryButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TWebButton.Destroy */ inline __fastcall virtual ~TResetQueryButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomQueryButtons;
class PASCALIMPLEMENTATION TCustomQueryButtons : public TWebControlGroup 
{
	typedef TWebControlGroup inherited;
	
private:
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FStyleRule;
	
protected:
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual void __fastcall ImplAddElements(Webcomp::_di_IAddScriptElements AddIntf);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout
		);
	Webcomp::TWebComponentList* __fastcall VisibleButtons(void);
	virtual void __fastcall GetDefaultButtons(void);
	
public:
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
public:
	#pragma option push -w-inl
	/* TWebControlGroup.Create */ inline __fastcall virtual TCustomQueryButtons(Classes::TComponent* AOwner
		) : TWebControlGroup(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebControlGroup.Destroy */ inline __fastcall virtual ~TCustomQueryButtons(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQueryButtons;
class PASCALIMPLEMENTATION TQueryButtons : public TCustomQueryButtons 
{
	typedef TCustomQueryButtons inherited;
	
__published:
	__property Style ;
	__property Custom ;
	__property StyleRule ;
public:
	#pragma option push -w-inl
	/* TWebControlGroup.Create */ inline __fastcall virtual TQueryButtons(Classes::TComponent* AOwner) : 
		TCustomQueryButtons(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebControlGroup.Destroy */ inline __fastcall virtual ~TQueryButtons(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TLayoutState { lsUnknown, lsFields, lsButtons };
#pragma option pop

class DELPHICLASS TFormLayout;
class PASCALIMPLEMENTATION TFormLayout : public Webcomp::TLayoutWebContent 
{
	typedef Webcomp::TLayoutWebContent inherited;
	
private:
	TLayoutState FLayoutState;
	bool FInTable;
	bool FInRow;
	AnsiString FTableHeader;
	int FColumnCount;
	int FColumnIndex;
	bool FBreakButtons;
	int FButtonIndex;
	
protected:
	virtual AnsiString __fastcall ImplLayoutButton(const AnsiString HTMLButton, Webcomp::TLayoutAttributes* 
		Attributes);
	virtual AnsiString __fastcall ImplLayoutField(const AnsiString HTMLField, Webcomp::TLayoutAttributes* 
		Attributes);
	virtual AnsiString __fastcall ImplLayoutLabelAndField(const AnsiString HTMLLabel, const AnsiString 
		HTMLField, Webcomp::TLayoutAttributes* Attributes);
	virtual AnsiString __fastcall ImplLayoutTable(const AnsiString HTMLTable, Webcomp::TLayoutAttributes* 
		Attributes);
	AnsiString __fastcall StartFields(int ColCount);
	AnsiString __fastcall EndButtons();
	AnsiString __fastcall StartButtons();
	AnsiString __fastcall EndFields();
	AnsiString __fastcall StartTable();
	AnsiString __fastcall EndTable();
	AnsiString __fastcall StartRow();
	AnsiString __fastcall EndRow();
	AnsiString __fastcall NextColumn(int SubItemCount);
	
public:
	__fastcall TFormLayout(System::TObject* AParentLayout);
	AnsiString __fastcall EndLayout();
	__property int ColumnCount = {read=FColumnCount, write=FColumnCount, nodefault};
	__property bool BreakButtons = {read=FBreakButtons, write=FBreakButtons, nodefault};
	__property AnsiString TableHeader = {read=FTableHeader, write=FTableHeader};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TFormLayout(void) { }
	#pragma option pop
	
};


typedef AnsiString MidItems__86[3];

typedef AnsiString MidItems__96[2];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString TextAreaWrap[3];
extern PACKAGE AnsiString FormMethodNames[2];
extern PACKAGE bool __fastcall CanAddClassHelper(Classes::TComponent* AEditor, Classes::TComponent* 
	AParent, TMetaClass* AClass);
extern PACKAGE void __fastcall AddIntAttrib(AnsiString &Attribs, const AnsiString Attrib, int Value)
	;
extern PACKAGE void __fastcall AddStringAttrib(AnsiString &Attribs, const AnsiString Attrib, const AnsiString 
	Value);
extern PACKAGE void __fastcall AddCustomAttrib(AnsiString &Attribs, AnsiString Value);
extern PACKAGE void __fastcall AddBoolAttrib(AnsiString &Attribs, const AnsiString Attrib, bool Value
	);
extern PACKAGE void __fastcall AddQuotedAttrib(AnsiString &Attribs, const AnsiString Attrib, const AnsiString 
	Value);
extern PACKAGE AnsiString __fastcall FormatColumnHeading(TWebDataDisplay* Field);
extern PACKAGE AnsiString __fastcall FormatColumnData(TWebDataDisplay* Field, AnsiString Content);
extern PACKAGE void __fastcall CreateDefaultButtonClasses(TMetaClass* const * Classes, const int Classes_Size
	, Webcomp::TWebComponentList* Container);
extern PACKAGE Httpapp::TCustomContentProducer* __fastcall FindProducer(Classes::TComponent* Component
	);
extern PACKAGE Httpapp::TCustomWebDispatcher* __fastcall FindDispatcher(Classes::TComponent* Component
	);
extern PACKAGE void __fastcall DeclareSubmitForm(Classes::TComponent* Component, Xmlbrokr::TXMLBroker* 
	XMLBroker, Webcomp::_di_IAddScriptElements AddIntf);
extern PACKAGE bool __fastcall GetItemValuesFromDataSet(Db::TDataSet* DataSet, const AnsiString ItemsField
	, const AnsiString ValuesField, Classes::TStrings* &ItemsStrings, Classes::TStrings* &ValuesStrings
	);

}	/* namespace Miditems */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Miditems;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MidItems
