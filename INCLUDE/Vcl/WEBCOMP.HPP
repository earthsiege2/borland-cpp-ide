// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebComp.pas' rev: 6.00

#ifndef WebCompHPP
#define WebCompHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Masks.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webcomp
{
//-- type declarations -------------------------------------------------------
__interface IProducerEditorViewSupport;
typedef System::DelphiInterface<IProducerEditorViewSupport> _di_IProducerEditorViewSupport;
__interface INTERFACE_UUID("{72B13C95-E75C-11D4-A549-00C04F6BB853}") IProducerEditorViewSupport  : public IInterface 
{
	
public:
	virtual bool __fastcall HasScriptView(void) = 0 ;
	virtual bool __fastcall HasXMLBrowserView(void) = 0 ;
	virtual bool __fastcall HasXSLBrowserView(void) = 0 ;
	virtual bool __fastcall HasHTMLBrowserView(void) = 0 ;
	virtual Classes::TStream* __fastcall GetXMLData(bool &Owned) = 0 ;
	virtual Classes::TStream* __fastcall GetXSLData(bool &Owned) = 0 ;
	virtual AnsiString __fastcall GetTemplateFileType(void) = 0 ;
};

__interface IGetXMLStream;
typedef System::DelphiInterface<IGetXMLStream> _di_IGetXMLStream;
__interface INTERFACE_UUID("{646363DA-6311-4750-A187-A9B416B7CAF8}") IGetXMLStream  : public IInterface 
{
	
public:
	virtual Classes::TStream* __fastcall GetXMLStream(bool &Owned) = 0 ;
};

__interface ISetWebContentOptions;
typedef System::DelphiInterface<ISetWebContentOptions> _di_ISetWebContentOptions;
class DELPHICLASS TWebContentOptions;
__interface INTERFACE_UUID("{7FD48995-5814-11D4-A492-00C04F6BB853}") ISetWebContentOptions  : public IInterface 
{
	
public:
	virtual void __fastcall SetWebContentOptions(TWebContentOptions* AOptions) = 0 ;
};

__interface INotifyWebActivate;
typedef System::DelphiInterface<INotifyWebActivate> _di_INotifyWebActivate;
__interface INTERFACE_UUID("{CE18BE42-1358-11D4-ABF4-F18FFAD12B3C}") INotifyWebActivate  : public IInterface 
{
	
public:
	virtual void __fastcall NotifyActivate(void) = 0 ;
	virtual void __fastcall NotifyDeactivate(void) = 0 ;
};

__interface INotifyActivateModule;
typedef System::DelphiInterface<INotifyActivateModule> _di_INotifyActivateModule;
__interface INTERFACE_UUID("{02B08C86-80D4-42D7-A84A-C0A09F42BDD1}") INotifyActivateModule  : public IInterface 
{
	
public:
	virtual void __fastcall NotifyActivateModule(Classes::TComponent* AWebModule) = 0 ;
	virtual void __fastcall NotifyDeactivateModule(Classes::TComponent* AWebModule) = 0 ;
};

__interface IWebVariablesContainerName;
typedef System::DelphiInterface<IWebVariablesContainerName> _di_IWebVariablesContainerName;
__interface INTERFACE_UUID("{14A3B5AC-7A5C-4279-BB7C-B3D6E2EDD7F1}") IWebVariablesContainerName  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetContainerName(void) = 0 ;
	__property AnsiString ContainerName = {read=GetContainerName};
};

typedef TObject TWebComponentContainer;
;

__interface IWebComponentContainer;
typedef System::DelphiInterface<IWebComponentContainer> _di_IWebComponentContainer;
__interface INTERFACE_UUID("{44957E12-E039-11D2-AA46-00A024C11562}") IWebComponentContainer  : public IInterface 
{
	
public:
	virtual int __fastcall GetComponentCount(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetComponent(int I) = 0 ;
	__property int ComponentCount = {read=GetComponentCount};
	__property Classes::TComponent* Components[int I] = {read=GetComponent};
};

__interface IWebComponentEditor;
typedef System::DelphiInterface<IWebComponentEditor> _di_IWebComponentEditor;
__interface INTERFACE_UUID("{13F59F61-EF85-11D2-AFB1-00C04FB16EC3}") IWebComponentEditor  : public IInterface 
{
	
public:
	virtual bool __fastcall CanAddClass(Classes::TComponent* AParent, TMetaClass* AClass) = 0 ;
};

__interface IAddFieldsEditor;
typedef System::DelphiInterface<IAddFieldsEditor> _di_IAddFieldsEditor;
__interface INTERFACE_UUID("{73506463-4D5E-11D4-A48B-00C04F6BB853}") IAddFieldsEditor  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetNewFieldPrefix(void) = 0 ;
	virtual AnsiString __fastcall GetAddFieldsItem(void) = 0 ;
	virtual AnsiString __fastcall GetAddAllFieldsItem(void) = 0 ;
	virtual AnsiString __fastcall GetAddFieldsDlgCaption(void) = 0 ;
};

__interface IGetWebComponentNodeName;
typedef System::DelphiInterface<IGetWebComponentNodeName> _di_IGetWebComponentNodeName;
__interface INTERFACE_UUID("{CB84BC91-4C65-11D4-A48B-00C04F6BB853}") IGetWebComponentNodeName  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetWebComponentNodeName(void) = 0 ;
};

__interface IWebComponentEditorHelper;
typedef System::DelphiInterface<IWebComponentEditorHelper> _di_IWebComponentEditorHelper;
__interface INTERFACE_UUID("{13F59F61-EF85-11D2-AFB1-00C04FB16EC3}") IWebComponentEditorHelper  : public IInterface 
{
	
public:
	virtual bool __fastcall CanAddClassHelper(Classes::TComponent* AEditor, Classes::TComponent* AParent, TMetaClass* AClass) = 0 ;
};

__interface IWebComponentCommands;
typedef System::DelphiInterface<IWebComponentCommands> _di_IWebComponentCommands;
__interface INTERFACE_UUID("{FCB67B0D-F357-11D2-AFB6-00C04FB16EC3}") IWebComponentCommands  : public IInterface 
{
	
public:
	virtual void __fastcall ExecuteVerb(Classes::TComponent* AComponent, int Index) = 0 ;
	virtual AnsiString __fastcall GetVerb(Classes::TComponent* AComponent, int Index) = 0 ;
	virtual int __fastcall GetVerbCount(Classes::TComponent* AComponent) = 0 ;
};

__interface IWebComponent;
typedef System::DelphiInterface<IWebComponent> _di_IWebComponent;
__interface INTERFACE_UUID("{EB813782-EEAE-11D2-AFB0-00C04FB16EC3}") IWebComponent  : public IInterface 
{
	
public:
	virtual int __fastcall GetIndex(void) = 0 ;
	virtual void __fastcall SetIndex(int Value) = 0 ;
	virtual void __fastcall SetContainer(System::TObject* Container) = 0 ;
	virtual System::TObject* __fastcall GetContainer(void) = 0 ;
	virtual void __fastcall SetComponentList(System::TObject* List) = 0 ;
	__property int Index = {read=GetIndex, write=SetIndex};
	__property System::TObject* Container = {read=GetContainer, write=SetContainer};
	__property System::TObject* ComponentList = {write=SetComponentList};
};

__interface ITopLevelWebComponent;
typedef System::DelphiInterface<ITopLevelWebComponent> _di_ITopLevelWebComponent;
__interface INTERFACE_UUID("{B591F71D-94D0-11D4-A4EA-00C04F6BB853}") ITopLevelWebComponent  : public IInterface 
{
	
};

__interface IGetWebComponentList;
typedef System::DelphiInterface<IGetWebComponentList> _di_IGetWebComponentList;
__interface INTERFACE_UUID("{5CDEB0F2-EEF9-11D2-AFB1-00C04FB16EC3}") IGetWebComponentList  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall GetComponentList(void) = 0 ;
	virtual System::TObject* __fastcall GetDefaultComponentList(void) = 0 ;
};

#pragma option push -b-
enum TWebContentFlag { coNoScript, coLocalPaths, coNoExecuteScript };
#pragma option pop

typedef Set<TWebContentFlag, coNoScript, coNoExecuteScript>  TWebContentFlags;

class PASCALIMPLEMENTATION TWebContentOptions : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TWebContentFlags FFlags;
	
public:
	__fastcall TWebContentOptions(TWebContentFlags AFlags);
	__property TWebContentFlags Flags = {read=FFlags, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebContentOptions(void) { }
	#pragma option pop
	
};


typedef TObject TLayout;
;

__interface IWebContent;
typedef System::DelphiInterface<IWebContent> _di_IWebContent;
__interface INTERFACE_UUID("{1B3E1CD1-DF59-11D2-AA45-00A024C11562}") IWebContent  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall Content(TWebContentOptions* Options, System::TObject* ParentLayout) = 0 ;
};

#pragma option push -b-
enum TLabelPosition { lposLeft, lposRight, lposAbove, lposBelow };
#pragma option pop

class DELPHICLASS TLayoutAttributes;
class PASCALIMPLEMENTATION TLayoutAttributes : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString LabelAttributes;
	AnsiString ControlAttributes;
	TLabelPosition LabelPosition;
	__fastcall TLayoutAttributes(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TLayoutAttributes(void) { }
	#pragma option pop
	
};


__interface ILayoutWebContent;
typedef System::DelphiInterface<ILayoutWebContent> _di_ILayoutWebContent;
__interface INTERFACE_UUID("{4E810ED1-F09B-11D2-AA53-00A024C11562}") ILayoutWebContent  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall LayoutButton(const AnsiString HTMLButton, TLayoutAttributes* Attributes) = 0 ;
	virtual AnsiString __fastcall LayoutField(const AnsiString HTMLField, TLayoutAttributes* Attributes) = 0 ;
	virtual AnsiString __fastcall LayoutLabelAndField(const AnsiString HTMLLabel, const AnsiString HTMLField, TLayoutAttributes* Attributes) = 0 ;
	virtual AnsiString __fastcall LayoutTable(const AnsiString HTMLTable, TLayoutAttributes* Attributes) = 0 ;
};

class DELPHICLASS TLayoutWebContent;
class PASCALIMPLEMENTATION TLayoutWebContent : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	System::TObject* FParentLayout;
	
protected:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	AnsiString __fastcall LayoutButton(const AnsiString HTMLButton, TLayoutAttributes* Attributes);
	AnsiString __fastcall LayoutField(const AnsiString HTMLField, TLayoutAttributes* Attributes);
	AnsiString __fastcall LayoutLabelAndField(const AnsiString HTMLLabel, const AnsiString HTMLField, TLayoutAttributes* Attributes);
	AnsiString __fastcall LayoutTable(const AnsiString HTMLTable, TLayoutAttributes* Attributes);
	virtual AnsiString __fastcall ImplLayoutButton(const AnsiString HTMLButton, TLayoutAttributes* Attributes) = 0 ;
	virtual AnsiString __fastcall ImplLayoutField(const AnsiString HTMLField, TLayoutAttributes* Attributes) = 0 ;
	virtual AnsiString __fastcall ImplLayoutLabelAndField(const AnsiString HTMLLabel, const AnsiString HTMLField, TLayoutAttributes* Attributes) = 0 ;
	virtual AnsiString __fastcall ImplLayoutTable(const AnsiString HTMLTable, TLayoutAttributes* Attributes) = 0 ;
	
public:
	__fastcall TLayoutWebContent(System::TObject* AParentLayout);
	__property System::TObject* ParentLayout = {read=FParentLayout};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TLayoutWebContent(void) { }
	#pragma option pop
	
private:
	void *__ILayoutWebContent;	/* Webcomp::ILayoutWebContent */
	
public:
	operator ILayoutWebContent*(void) { return (ILayoutWebContent*)&__ILayoutWebContent; }
	
};


class DELPHICLASS TWebComponentList;
class PASCALIMPLEMENTATION TWebComponentList : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	Classes::TComponent* operator[](int Index) { return WebComponents[Index]; }
	
private:
	Classes::TComponent* FParentComponent;
	Classes::TList* FList;
	Classes::TNotifyEvent FOnChange;
	int FLockNotifyCount;
	bool FNotifyPending;
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall Changed(void);
	int __fastcall GetCount(void);
	Classes::TComponent* __fastcall GetComponent(int Index);
	virtual Classes::TComponent* __fastcall NewComponent(Classes::TComponent* AOwner);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	int __fastcall WebComponentContainer_GetComponentCount(void);
	Classes::TComponent* __fastcall WebComponentContainer_GetComponent(int I);
	
public:
	__fastcall TWebComponentList(Classes::TComponent* AParentComponent);
	__fastcall virtual ~TWebComponentList(void);
	void __fastcall LockNotify(void);
	void __fastcall UnlockNotify(void);
	bool __fastcall NotifyLocked(void);
	void __fastcall Add(Classes::TComponent* Component);
	void __fastcall SetComponentIndex(Classes::TComponent* Component, int Value);
	void __fastcall Clear(void);
	int __fastcall IndexOf(Classes::TComponent* Component);
	void __fastcall Remove(Classes::TComponent* Component);
	__property int Count = {read=GetCount, nodefault};
	__property Classes::TComponent* WebComponents[int Index] = {read=GetComponent/*, default*/};
	__property Classes::TComponent* ParentComponent = {read=FParentComponent};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
private:
	void *__IWebComponentContainer;	/* Webcomp::IWebComponentContainer [GetComponent=WebComponentContainer_GetComponent, GetComponentCount=WebComponentContainer_GetComponentCount] */
	
public:
	operator IWebComponentContainer*(void) { return (IWebComponentContainer*)&__IWebComponentContainer; }
	
};


class DELPHICLASS TWebComponentClassDescription;
class PASCALIMPLEMENTATION TWebComponentClassDescription : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TMetaClass*ComponentClass;
	AnsiString ComponentClassName;
	System::TObject* Editor;
	bool FrameClass;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TWebComponentClassDescription(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebComponentClassDescription(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TEnumWebComponentsProc)(TWebComponentClassDescription* WebComponentClass, void * Info);

class DELPHICLASS TWebComponentsEditorHelper;
class PASCALIMPLEMENTATION TWebComponentsEditorHelper : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	bool __fastcall CanAddClassHelper(Classes::TComponent* AEditor, Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClassHelper(Classes::TComponent* AEditor, Classes::TComponent* AParent, TMetaClass* AClass);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TWebComponentsEditorHelper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebComponentsEditorHelper(void) { }
	#pragma option pop
	
private:
	void *__IWebComponentEditorHelper;	/* Webcomp::IWebComponentEditorHelper */
	
public:
	operator IWebComponentEditorHelper*(void) { return (IWebComponentEditorHelper*)&__IWebComponentEditorHelper; }
	
};


typedef void __fastcall (__closure *TGetComponentListEvent)(System::TObject* Sender, TWebComponentList* &AList);

typedef void __fastcall (__closure *TSetComponentListEvent)(System::TObject* Sender, TWebComponentList* AList);

class DELPHICLASS TWebContainerComponentHelper;
class PASCALIMPLEMENTATION TWebContainerComponentHelper : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TComponent* FComponent;
	TWebComponentList* FWebComponents;
	TGetComponentListEvent FOnGetDefaultComponentList;
	TSetComponentListEvent FOnSetDefaultComponentList;
	
protected:
	System::TObject* __fastcall GetComponentList(void);
	System::TObject* __fastcall GetDefaultComponentList(void);
	TWebComponentList* __fastcall GetDefaultWebComponents(void);
	void __fastcall SetDefaultWebComponents(TWebComponentList* AList);
	__property TGetComponentListEvent OnGetDefaultComponentList = {read=FOnGetDefaultComponentList, write=FOnGetDefaultComponentList};
	__property TSetComponentListEvent OnSetDefaultComponentList = {read=FOnSetDefaultComponentList, write=FOnSetDefaultComponentList};
	
public:
	void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	__fastcall TWebContainerComponentHelper(Classes::TComponent* AComponent, TGetComponentListEvent AOnGetDefaultComponentList, TSetComponentListEvent AOnSetDefaultComponentList);
	__fastcall virtual ~TWebContainerComponentHelper(void);
	__property TWebComponentList* Webcomponents = {read=FWebComponents};
	__property TWebComponentList* DefaultWebComponents = {read=GetDefaultWebComponents, write=SetDefaultWebComponents};
};


class DELPHICLASS TWebContainerComponent;
class PASCALIMPLEMENTATION TWebContainerComponent : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TWebContainerComponentHelper* FWebContainerComponentHelper;
	void __fastcall OnGetDefaultComponentList(System::TObject* Sender, TWebComponentList* &AList);
	void __fastcall OnSetDefaultComponentList(System::TObject* Sender, TWebComponentList* AList);
	
protected:
	virtual System::TObject* __fastcall ImplGetDefaultComponentList(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	__property TWebContainerComponentHelper* WebContainerComponentHelper = {read=FWebContainerComponentHelper};
	TWebComponentList* __fastcall GetWebComponents(void);
	virtual TWebComponentList* __fastcall GetDefaultWebComponents(void);
	virtual void __fastcall SetDefaultWebComponents(TWebComponentList* AList);
	
public:
	__fastcall virtual TWebContainerComponent(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebContainerComponent(void);
private:
	void *__IGetWebComponentList;	/* Webcomp::IGetWebComponentList */
	
public:
	operator IGetWebComponentList*(void) { return (IGetWebComponentList*)&__IGetWebComponentList; }
	
};


class DELPHICLASS TWebContainedComponentHelper;
class PASCALIMPLEMENTATION TWebContainedComponentHelper : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TComponent* FComponent;
	bool FDefaultField;
	TWebComponentList* FContainerList;
	Classes::TComponent* FWebParent;
	Classes::TNotifyEvent FOnParentChanged;
	
protected:
	int __fastcall GetIndex(void);
	void __fastcall SetIndex(int Value);
	void __fastcall SetContainer(System::TObject* Container);
	System::TObject* __fastcall GetContainer(void);
	void __fastcall SetComponentList(System::TObject* List);
	void __fastcall SetWebParent(Classes::TComponent* Value);
	virtual void __fastcall ParentChanged(void);
	__property Classes::TNotifyEvent OnParentChanged = {read=FOnParentChanged, write=FOnParentChanged};
	
public:
	__fastcall TWebContainedComponentHelper(Classes::TComponent* AComponent, Classes::TNotifyEvent AOnParentChanged);
	__fastcall virtual ~TWebContainedComponentHelper(void);
	bool __fastcall IsDefaultField(void);
	__property Classes::TComponent* WebParent = {read=FWebParent};
	__property TWebComponentList* ContainerList = {read=FContainerList};
};


class DELPHICLASS TWebContainedComponent;
class PASCALIMPLEMENTATION TWebContainedComponent : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TWebContainedComponentHelper* FWebContainedComponentHelper;
	void __fastcall OnParentChanged(System::TObject* Sender);
	Classes::TComponent* __fastcall GetWebParent(void);
	
protected:
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	void __fastcall SetWebParent(Classes::TComponent* Value);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	virtual bool __fastcall IsDefaultField(void);
	virtual void __fastcall ParentChanged(void);
	TWebComponentList* __fastcall GetContainerList(void);
	__property TWebContainedComponentHelper* WebContainedComponentHelper = {read=FWebContainedComponentHelper};
	__property Classes::TComponent* WebParent = {read=GetWebParent};
	
public:
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	__fastcall virtual TWebContainedComponent(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebContainedComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
private:
	void *__IWebComponent;	/* Webcomp::IWebComponent */
	
public:
	operator IWebComponent*(void) { return (IWebComponent*)&__IWebComponent; }
	
};


class DELPHICLASS TWebContainedContainerComponent;
class PASCALIMPLEMENTATION TWebContainedContainerComponent : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TWebContainerComponentHelper* FWebContainerComponentHelper;
	TWebContainedComponentHelper* FWebContainedComponentHelper;
	void __fastcall OnParentChanged(System::TObject* Sender);
	void __fastcall OnGetDefaultComponentList(System::TObject* Sender, TWebComponentList* &AList);
	void __fastcall OnSetDefaultComponentList(System::TObject* Sender, TWebComponentList* AList);
	Classes::TComponent* __fastcall GetWebParent(void);
	
protected:
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	void __fastcall SetWebParent(Classes::TComponent* Value);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	virtual bool __fastcall IsDefaultField(void);
	virtual void __fastcall ParentChanged(void);
	virtual System::TObject* __fastcall ImplGetDefaultComponentList(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	__property TWebContainerComponentHelper* WebContainerComponentHelper = {read=FWebContainerComponentHelper};
	__property TWebContainedComponentHelper* WebContainedComponentHelper = {read=FWebContainedComponentHelper};
	TWebComponentList* __fastcall GetWebComponents(void);
	TWebComponentList* __fastcall GetContainerList(void);
	virtual TWebComponentList* __fastcall GetDefaultWebComponents(void);
	virtual void __fastcall SetDefaultWebComponents(TWebComponentList* AList);
	__property Classes::TComponent* WebParent = {read=GetWebParent};
	
public:
	__fastcall virtual TWebContainedContainerComponent(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebContainedContainerComponent(void);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
private:
	void *__IGetWebComponentList;	/* Webcomp::IGetWebComponentList */
	void *__IWebComponent;	/* Webcomp::IWebComponent */
	
public:
	operator IWebComponent*(void) { return (IWebComponent*)&__IWebComponent; }
	operator IGetWebComponentList*(void) { return (IGetWebComponentList*)&__IGetWebComponentList; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall (*RegisterWebComponentsProc)(TMetaClass* * AClasses, const int AClasses_Size, System::TObject* Editor);
extern PACKAGE void __fastcall (*UnRegisterWebComponentsProc)(TMetaClass* * AClasses, const int AClasses_Size);
extern PACKAGE void __fastcall (*EnumRegisteredWebComponentsProc)(TEnumWebComponentsProc Proc, void * Info);
extern PACKAGE System::TObject* __fastcall (*FindWebComponentEditorHelperProc)(TMetaClass* AClass);
extern PACKAGE AnsiString __fastcall QualifyFileName(const AnsiString AFileName);
extern PACKAGE bool __fastcall DesigningComponent(Classes::TComponent* AComponent);
extern PACKAGE void __fastcall RegisterWebComponents(TMetaClass* * AClasses, const int AClasses_Size, System::TObject* Editor = (System::TObject*)(0x0));
extern PACKAGE void __fastcall UnRegisterWebComponents(TMetaClass* * AClasses, const int AClasses_Size);
extern PACKAGE void __fastcall EnumRegisteredWebComponents(TEnumWebComponentsProc Proc, void * Info);
extern PACKAGE System::TObject* __fastcall FindWebComponentEditorHelper(TMetaClass* AClass);
extern PACKAGE void __fastcall ValidateWebParent(Classes::TComponent* AComponent, Classes::TComponent* AParent);

}	/* namespace Webcomp */
using namespace Webcomp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebComp
