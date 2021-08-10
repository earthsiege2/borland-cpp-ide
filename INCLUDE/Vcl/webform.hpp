// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebForm.pas' rev: 6.00

#ifndef WebFormHPP
#define WebFormHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Contnrs.hpp>	// Pascal unit
#include <MidItems.hpp>	// Pascal unit
#include <WebModu.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webform
{
//-- type declarations -------------------------------------------------------
__interface IGetAdapterVariableName;
typedef System::DelphiInterface<IGetAdapterVariableName> _di_IGetAdapterVariableName;
__interface INTERFACE_UUID("{0D4BF7F5-332A-11D4-A474-00C04F6BB853}") IGetAdapterVariableName  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetAdapterVariableName(void) = 0 ;
	__property AnsiString AdapterVariableName = {read=GetAdapterVariableName};
};

__interface IGetAdapterOfDisplay;
typedef System::DelphiInterface<IGetAdapterOfDisplay> _di_IGetAdapterOfDisplay;
__interface INTERFACE_UUID("{CB84BC96-4C65-11D4-A48B-00C04F6BB853}") IGetAdapterOfDisplay  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall GetAdapter(void) = 0 ;
};

__interface IGetVariablesContainerOfDisplay;
typedef System::DelphiInterface<IGetVariablesContainerOfDisplay> _di_IGetVariablesContainerOfDisplay;
__interface INTERFACE_UUID("{D36B6884-33DE-4E50-8397-45A085C09D95}") IGetVariablesContainerOfDisplay  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall GetVariablesContainer(void) = 0 ;
};

__interface IGetAdapterModeOfDisplay;
typedef System::DelphiInterface<IGetAdapterModeOfDisplay> _di_IGetAdapterModeOfDisplay;
__interface INTERFACE_UUID("{C4175F0B-BF2F-4C2A-ADAA-50F7DD3A8BE2}") IGetAdapterModeOfDisplay  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetAdapterModeOfDisplay(void) = 0 ;
	virtual AnsiString __fastcall GetAdapterModeOfAdapter(void) = 0 ;
};

class DELPHICLASS TAbstractControlRequirements;
class PASCALIMPLEMENTATION TAbstractControlRequirements : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall RequiresMultipartForm(void) = 0 ;
	virtual bool __fastcall IsFunctionDefined(const AnsiString AName) = 0 ;
	virtual void __fastcall DefineFunction(const AnsiString AName, const AnsiString ABody) = 0 ;
	virtual void __fastcall DefineVariable(const AnsiString AName, const AnsiString AValue, bool AAdapter) = 0 ;
	virtual bool __fastcall IsVariableDefined(const AnsiString AName) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractControlRequirements(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractControlRequirements(void) { }
	#pragma option pop
	
};


__interface IGetControlRequirements;
typedef System::DelphiInterface<IGetControlRequirements> _di_IGetControlRequirements;
__interface INTERFACE_UUID("{4AB9249B-D98D-462D-9AE0-6820D208EF8E}") IGetControlRequirements  : public IInterface 
{
	
public:
	virtual void __fastcall GetControlRequirements(TAbstractControlRequirements* ARequirements) = 0 ;
};

class DELPHICLASS TAdapterControlGroup;
class PASCALIMPLEMENTATION TAdapterControlGroup : public Miditems::TWebControlGroup 
{
	typedef Miditems::TWebControlGroup inherited;
	
private:
	Classes::TComponent* FAdapter;
	Sitecomp::TNotifyList* FNotifyList;
	AnsiString FAdapterMode;
	bool FAddDefaultFields;
	void __fastcall SetAddDefaultFields(const bool Value);
	
protected:
	void __fastcall GetControlRequirements(TAbstractControlRequirements* ARequirements);
	virtual void __fastcall ImplGetControlRequirements(TAbstractControlRequirements* ARequirements);
	AnsiString __fastcall GetAdapterModeOfDisplay();
	AnsiString __fastcall GetAdapterModeOfAdapter();
	void __fastcall GetDesigntimeWarnings(Sitecomp::TAbstractDesigntimeWarnings* AWarnings);
	void __fastcall AddNotify(System::TObject* ANotify);
	void __fastcall RemoveNotify(System::TObject* ANotify);
	void __fastcall NotifyAdapterChange(Classes::TComponent* Sender);
	Classes::TComponent* __fastcall GetAdapter(void);
	Webcomp::TWebComponentList* __fastcall GetVisibleFields(void);
	void __fastcall GetFieldsList(Classes::TStrings* List);
	Classes::TComponent* __fastcall FindField(const AnsiString AName);
	bool __fastcall IsFieldInUse(const AnsiString AName);
	AnsiString __fastcall GetAdapterVariableName();
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SetAdapter(const Classes::TComponent* Value);
	void __fastcall CreateDefaultFields(void);
	virtual void __fastcall AdapterChange(void);
	
public:
	__fastcall virtual TAdapterControlGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TAdapterControlGroup(void);
	__property bool AddDefaultFields = {read=FAddDefaultFields, write=SetAddDefaultFields, default=1};
	__property Webcomp::TWebComponentList* VisibleFields = {read=GetVisibleFields};
	__property Classes::TComponent* Adapter = {read=GetAdapter, write=SetAdapter};
	__property AnsiString AdapterMode = {read=FAdapterMode, write=FAdapterMode};
private:
	void *__IWebDataFields;	/* Sitecomp::IWebDataFields */
	void *__INotifyAdapterChange;	/* Sitecomp::INotifyAdapterChange */
	void *__IGetAdapterVariableName;	/* Webform::IGetAdapterVariableName */
	void *__IGetAdapterOfDisplay;	/* Webform::IGetAdapterOfDisplay */
	void *__INotifyList;	/* Sitecomp::INotifyList */
	void *__IGetVariablesContainerOfDisplay;	/* Webform::IGetVariablesContainerOfDisplay [GetVariablesContainer=GetAdapter] */
	void *__IGetDesigntimeWarnings;	/* Sitecomp::IGetDesigntimeWarnings */
	void *__IGetAdapterModeOfDisplay;	/* Webform::IGetAdapterModeOfDisplay */
	void *__IGetControlRequirements;	/* Webform::IGetControlRequirements */
	
public:
	operator IGetControlRequirements*(void) { return (IGetControlRequirements*)&__IGetControlRequirements; }
	operator IGetAdapterModeOfDisplay*(void) { return (IGetAdapterModeOfDisplay*)&__IGetAdapterModeOfDisplay; }
	operator IGetDesigntimeWarnings*(void) { return (IGetDesigntimeWarnings*)&__IGetDesigntimeWarnings; }
	operator IGetVariablesContainerOfDisplay*(void) { return (IGetVariablesContainerOfDisplay*)&__IGetVariablesContainerOfDisplay; }
	operator INotifyList*(void) { return (INotifyList*)&__INotifyList; }
	operator IGetAdapterOfDisplay*(void) { return (IGetAdapterOfDisplay*)&__IGetAdapterOfDisplay; }
	operator IGetAdapterVariableName*(void) { return (IGetAdapterVariableName*)&__IGetAdapterVariableName; }
	operator INotifyAdapterChange*(void) { return (INotifyAdapterChange*)&__INotifyAdapterChange; }
	operator IWebDataFields*(void) { return (IWebDataFields*)&__IWebDataFields; }
	
};


class DELPHICLASS TAbstractFormRequirements;
class PASCALIMPLEMENTATION TAbstractFormRequirements : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual bool __fastcall IsFunctionDefined(const AnsiString AName) = 0 ;
	virtual void __fastcall DefineFunction(const AnsiString AName, const AnsiString ABody) = 0 ;
	virtual bool __fastcall IsVariableDefined(const AnsiString AName) = 0 ;
	virtual void __fastcall DefineVariable(const AnsiString AName, const AnsiString AValue) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractFormRequirements(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractFormRequirements(void) { }
	#pragma option pop
	
};


__interface IGetFormRequirements;
typedef System::DelphiInterface<IGetFormRequirements> _di_IGetFormRequirements;
__interface INTERFACE_UUID("{C990BD6A-9250-4C70-B873-F54B3A71DADD}") IGetFormRequirements  : public IInterface 
{
	
public:
	virtual void __fastcall GetFormRequirements(TAbstractFormRequirements* ARequirements) = 0 ;
};

#pragma option push -b-
enum TDisplayFieldHideOption { hoHideOnNoInputAccess, hoHideOnNoDisplayAccess, hoHideOnFieldNotVisible, hoHideAlways };
#pragma option pop

typedef Set<TDisplayFieldHideOption, hoHideOnNoInputAccess, hoHideAlways>  TDisplayFieldHideOptions;

class DELPHICLASS TAdapterDataDisplay;
class PASCALIMPLEMENTATION TAdapterDataDisplay : public Miditems::TWebDataDisplay 
{
	typedef Miditems::TWebDataDisplay inherited;
	
private:
	AnsiString FFieldName;
	TDisplayFieldHideOptions FHideOptions;
	Httpprod::THTMLAlign FAlign;
	Httpprod::THTMLVAlign FVAlign;
	
protected:
	virtual AnsiString __fastcall FormatCaption();
	Classes::TComponent* __fastcall FindAssociatedField(void);
	virtual AnsiString __fastcall GetCaption();
	virtual void __fastcall SetCaption(AnsiString Value);
	virtual AnsiString __fastcall FieldConditions(Webcomp::TWebContentOptions* Options);
	AnsiString __fastcall GetAdapterModeOfAdapter();
	AnsiString __fastcall FormatColumnHeading(Webcomp::TWebContentOptions* Options);
	AnsiString __fastcall FormatColumnData(const AnsiString Content, Webcomp::TWebContentOptions* Options);
	virtual AnsiString __fastcall ImplFormatColumnHeading(Webcomp::TWebContentOptions* Options);
	virtual AnsiString __fastcall ImplFormatColumnData(const AnsiString Content, Webcomp::TWebContentOptions* Options);
	void __fastcall GetDesigntimeWarnings(Sitecomp::TAbstractDesigntimeWarnings* AWarnings);
	Classes::TComponent* __fastcall GetVariablesContainer(void);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	void __fastcall GetControlRequirements(TAbstractControlRequirements* ARequirements);
	virtual void __fastcall ImplGetControlRequirements(TAbstractControlRequirements* ARequirements);
	void __fastcall RestoreDefaults(void);
	virtual void __fastcall ImplRestoreDefaults(void);
	AnsiString __fastcall GetFieldName();
	void __fastcall SetFieldName(const AnsiString Value);
	AnsiString __fastcall GetAdapterVariableName();
	
public:
	__fastcall virtual TAdapterDataDisplay(Classes::TComponent* AOwner);
	__property AnsiString FieldName = {read=GetFieldName, write=SetFieldName};
	__property TDisplayFieldHideOptions HideOptions = {read=FHideOptions, write=FHideOptions, default=4};
	__property Httpprod::THTMLAlign Align = {read=FAlign, write=FAlign, default=0};
	__property Httpprod::THTMLVAlign VAlign = {read=FVAlign, write=FVAlign, default=0};
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TAdapterDataDisplay(void) { }
	#pragma option pop
	
private:
	void *__IWebGetFieldName;	/* Sitecomp::IWebGetFieldName */
	void *__IWebSetFieldName;	/* Sitecomp::IWebSetFieldName */
	void *__IGetAdapterVariableName;	/* Webform::IGetAdapterVariableName */
	void *__IRestoreDefaults;	/* Miditems::IRestoreDefaults */
	void *__IGetControlRequirements;	/* Webform::IGetControlRequirements */
	void *__IGetVariablesContainerOfDisplay;	/* Webform::IGetVariablesContainerOfDisplay */
	void *__IGetDesigntimeWarnings;	/* Sitecomp::IGetDesigntimeWarnings */
	void *__IFormatColumn;	/* Miditems::IFormatColumn */
	
public:
	operator IFormatColumn*(void) { return (IFormatColumn*)&__IFormatColumn; }
	operator IGetDesigntimeWarnings*(void) { return (IGetDesigntimeWarnings*)&__IGetDesigntimeWarnings; }
	operator IGetVariablesContainerOfDisplay*(void) { return (IGetVariablesContainerOfDisplay*)&__IGetVariablesContainerOfDisplay; }
	operator IGetControlRequirements*(void) { return (IGetControlRequirements*)&__IGetControlRequirements; }
	operator IRestoreDefaults*(void) { return (IRestoreDefaults*)&__IRestoreDefaults; }
	operator IGetAdapterVariableName*(void) { return (IGetAdapterVariableName*)&__IGetAdapterVariableName; }
	operator IWebSetFieldName*(void) { return (IWebSetFieldName*)&__IWebSetFieldName; }
	operator IWebGetFieldName*(void) { return (IWebGetFieldName*)&__IWebGetFieldName; }
	
};


typedef TMetaClass*TAdapterDataDisplayClass;

class DELPHICLASS TAdapterActionsListHelper;
class PASCALIMPLEMENTATION TAdapterActionsListHelper : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TComponent* FComponent;
	Webcomp::TWebContainerComponentHelper* FHelper;
	bool FAddDefaultActions;
	void __fastcall CreateDefaultActions(void);
	void __fastcall SetAddDefaultActions(const bool Value);
	
protected:
	Webcomp::TWebComponentList* __fastcall GetVisibleActions(void);
	void __fastcall GetActionsList(Classes::TStrings* List);
	Classes::TComponent* __fastcall FindAction(const AnsiString AName);
	bool __fastcall IsActionInUse(const AnsiString AName);
	AnsiString __fastcall GetNewFieldPrefix();
	AnsiString __fastcall GetAddFieldsItem();
	AnsiString __fastcall GetAddAllFieldsItem();
	AnsiString __fastcall GetAddFieldsDlgCaption();
	
public:
	__fastcall TAdapterActionsListHelper(Classes::TComponent* AComponent, Webcomp::TWebContainerComponentHelper* AHelper);
	__property bool AddDefaultActions = {read=FAddDefaultActions, write=SetAddDefaultActions, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAdapterActionsListHelper(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TColumnHTMLElementType { coltDefault, coltText, coltImage, coltList };
#pragma option pop

class DELPHICLASS TCustomAdapterDisplayColumn;
class PASCALIMPLEMENTATION TCustomAdapterDisplayColumn : public TAdapterDataDisplay 
{
	typedef TAdapterDataDisplay inherited;
	
private:
	TColumnHTMLElementType FDisplayType;
	int FImageWidth;
	int FImageHeight;
	
protected:
	virtual void __fastcall ImplGetControlRequirements(TAbstractControlRequirements* ARequirements);
	virtual AnsiString __fastcall ImplFormatColumnHeading(Webcomp::TWebContentOptions* Options);
	bool __fastcall CanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	AnsiString __fastcall FormatTextDisplay(const AnsiString VarName, const AnsiString HTMLName);
	AnsiString __fastcall FormatListDisplay(const AnsiString VarName, const AnsiString HTMLName);
	AnsiString __fastcall FormatImage(const AnsiString VarName, const AnsiString HTMLName, Webcomp::TWebContentOptions* Options);
	virtual AnsiString __fastcall ControlContent(Webcomp::TWebContentOptions* Options);
	virtual void __fastcall ImplRestoreDefaults(void);
	
public:
	__fastcall virtual TCustomAdapterDisplayColumn(Classes::TComponent* AOwner);
	/* virtual class method */ virtual bool __fastcall IsColumn(TMetaClass* vmt);
	__property TColumnHTMLElementType DisplayType = {read=FDisplayType, write=FDisplayType, default=0};
	__property int ImageWidth = {read=FImageWidth, write=FImageWidth, default=-1};
	__property int ImageHeight = {read=FImageHeight, write=FImageHeight, default=-1};
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TCustomAdapterDisplayColumn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomAdapterCommandColumn;
class PASCALIMPLEMENTATION TCustomAdapterCommandColumn : public Miditems::TWebControlGroup 
{
	typedef Miditems::TWebControlGroup inherited;
	
private:
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FStyleRule;
	AnsiString FCaption;
	Miditems::TCaptionAttributes* FCaptionAttributes;
	int FDisplayColumns;
	TAdapterActionsListHelper* FAdapterActionsListHelper;
	Webcomp::TLayoutAttributes* FLayoutAttributes;
	Httpprod::THTMLAlign FAlign;
	Httpprod::THTMLVAlign FVAlign;
	AnsiString __fastcall GetCaption();
	void __fastcall SetCaptionAttributes(const Miditems::TCaptionAttributes* Value);
	void __fastcall SetCaption(const AnsiString Value);
	Webcomp::TWebComponentList* __fastcall GetVisibleActions(void);
	bool __fastcall GetAddDefaultCommands(void);
	void __fastcall SetAddDefaultCommands(const bool Value);
	bool __fastcall IsCaptionStored(void);
	
protected:
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	void __fastcall NotifyAdapterChange(Classes::TComponent* Sender);
	Sitecomp::TAdapterDisplayCharacteristics __fastcall GetAdapterDisplayCharacteristics(void);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	AnsiString __fastcall FormatColumnHeading(Webcomp::TWebContentOptions* Options);
	AnsiString __fastcall FormatColumnData(const AnsiString Content, Webcomp::TWebContentOptions* Options);
	__property TAdapterActionsListHelper* AdapterActionsListHelper = {read=FAdapterActionsListHelper};
	
public:
	__fastcall virtual TCustomAdapterCommandColumn(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAdapterCommandColumn(void);
	__property Webcomp::TWebComponentList* VisibleCommands = {read=GetVisibleActions};
	__property int DisplayColumns = {read=FDisplayColumns, write=FDisplayColumns, default=-1};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
	__property Miditems::TCaptionAttributes* CaptionAttributes = {read=FCaptionAttributes, write=SetCaptionAttributes};
	__property AnsiString Caption = {read=GetCaption, write=SetCaption, stored=IsCaptionStored};
	__property bool AddDefaultCommands = {read=GetAddDefaultCommands, write=SetAddDefaultCommands, default=1};
	__property Httpprod::THTMLAlign Align = {read=FAlign, write=FAlign, default=0};
	__property Httpprod::THTMLVAlign VAlign = {read=FVAlign, write=FVAlign, default=0};
private:
	void *__IWebActionsList;	/* Sitecomp::IWebActionsList */
	void *__IAddFieldsEditor;	/* Webcomp::IAddFieldsEditor */
	void *__IFormatColumn;	/* Miditems::IFormatColumn */
	void *__IGetAdapterDisplayCharacteristics;	/* Sitecomp::IGetAdapterDisplayCharacteristics */
	void *__INotifyAdapterChange;	/* Sitecomp::INotifyAdapterChange */
	
public:
	operator INotifyAdapterChange*(void) { return (INotifyAdapterChange*)&__INotifyAdapterChange; }
	operator IGetAdapterDisplayCharacteristics*(void) { return (IGetAdapterDisplayCharacteristics*)&__IGetAdapterDisplayCharacteristics; }
	operator IFormatColumn*(void) { return (IFormatColumn*)&__IFormatColumn; }
	operator IAddFieldsEditor*(void) { return (IAddFieldsEditor*)&__IAddFieldsEditor; }
	operator IWebActionsList*(void) { return (IWebActionsList*)&__IWebActionsList; }
	
};


class DELPHICLASS TAdapterCommandColumn;
class PASCALIMPLEMENTATION TAdapterCommandColumn : public TCustomAdapterCommandColumn 
{
	typedef TCustomAdapterCommandColumn inherited;
	
__published:
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property CaptionAttributes ;
	__property Caption ;
	__property DisplayColumns  = {default=-1};
	__property AddDefaultCommands  = {default=1};
	__property Align  = {default=0};
	__property VAlign  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomAdapterCommandColumn.Create */ inline __fastcall virtual TAdapterCommandColumn(Classes::TComponent* AOwner) : TCustomAdapterCommandColumn(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapterCommandColumn.Destroy */ inline __fastcall virtual ~TAdapterCommandColumn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGeneratedFunctions;
class PASCALIMPLEMENTATION TGeneratedFunctions : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStrings* FScript;
	Classes::TStrings* FNames;
	AnsiString __fastcall GetScript(int I);
	int __fastcall GetItemCount(void);
	AnsiString __fastcall GetName(int I);
	
public:
	__fastcall TGeneratedFunctions(void);
	__fastcall virtual ~TGeneratedFunctions(void);
	void __fastcall Add(const AnsiString AName, const AnsiString AScript);
	bool __fastcall Exists(const AnsiString AName);
	__property AnsiString Script[int I] = {read=GetScript};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property AnsiString Names[int I] = {read=GetName};
};


class DELPHICLASS TControlRequirements;
class PASCALIMPLEMENTATION TControlRequirements : public TAbstractControlRequirements 
{
	typedef TAbstractControlRequirements inherited;
	
private:
	TGeneratedFunctions* FGeneratedFunctions;
	bool FNeedMultipartForm;
	Classes::TStrings* FVariables;
	
public:
	virtual void __fastcall RequiresMultipartForm(void);
	virtual bool __fastcall IsFunctionDefined(const AnsiString AName);
	virtual void __fastcall DefineFunction(const AnsiString AName, const AnsiString ABody);
	virtual void __fastcall DefineVariable(const AnsiString AName, const AnsiString AValue, bool AAdapter);
	virtual bool __fastcall IsVariableDefined(const AnsiString AName);
	__fastcall TControlRequirements(void);
	__fastcall virtual ~TControlRequirements(void);
	__property bool NeedMultipartForm = {read=FNeedMultipartForm, nodefault};
};


__interface IGetAdapterFormLayout;
typedef System::DelphiInterface<IGetAdapterFormLayout> _di_IGetAdapterFormLayout;
class DELPHICLASS TAdapterFormLayout;
__interface INTERFACE_UUID("{C51059F2-AA91-11D4-A502-00C04F6BB853}") IGetAdapterFormLayout  : public IInterface 
{
	
public:
	virtual TAdapterFormLayout* __fastcall GetAdapterFormLayout(void) = 0 ;
};

class DELPHICLASS TCustomAdapterForm;
class PASCALIMPLEMENTATION TCustomAdapterForm : public Miditems::TWebControlGroup 
{
	typedef Miditems::TWebControlGroup inherited;
	
private:
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FStyleRule;
	Webcomp::TLayoutAttributes* FLayoutAttributes;
	TControlRequirements* FControlRequirements;
	TAdapterFormLayout* FFormLayout;
	Miditems::TFormMethod FFormMethod;
	AnsiString __fastcall FormatForm(System::TObject* ParentLayout, Webcomp::TWebContentOptions* Options);
	AnsiString __fastcall GetHTMLFormTag(Webcomp::TWebContentOptions* Options);
	TControlRequirements* __fastcall GetControlRequirements(void);
	
protected:
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	TAdapterFormLayout* __fastcall GetAdapterFormLayout(void);
	void __fastcall GetFormRequirements(TAbstractFormRequirements* ARequirements);
	AnsiString __fastcall GetHTMLFormName();
	AnsiString __fastcall GetHTMLFormVarName();
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	
public:
	__fastcall virtual TCustomAdapterForm(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAdapterForm(void);
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
	__property Miditems::TFormMethod FormMethod = {read=FFormMethod, write=FFormMethod, default=0};
private:
	void *__IHTMLForm;	/* Miditems::IHTMLForm */
	void *__IGetFormRequirements;	/* Webform::IGetFormRequirements */
	void *__IGetAdapterFormLayout;	/* Webform::IGetAdapterFormLayout */
	
public:
	operator IGetAdapterFormLayout*(void) { return (IGetAdapterFormLayout*)&__IGetAdapterFormLayout; }
	operator IGetFormRequirements*(void) { return (IGetFormRequirements*)&__IGetFormRequirements; }
	operator IHTMLForm*(void) { return (IHTMLForm*)&__IHTMLForm; }
	
};


class DELPHICLASS TAdapterForm;
class PASCALIMPLEMENTATION TAdapterForm : public TCustomAdapterForm 
{
	typedef TCustomAdapterForm inherited;
	
__published:
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property FormMethod  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomAdapterForm.Create */ inline __fastcall virtual TAdapterForm(Classes::TComponent* AOwner) : TCustomAdapterForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapterForm.Destroy */ inline __fastcall virtual ~TAdapterForm(void) { }
	#pragma option pop
	
};


__interface IAdapterDisplay;
typedef System::DelphiInterface<IAdapterDisplay> _di_IAdapterDisplay;
__interface INTERFACE_UUID("{73506462-4D5E-11D4-A48B-00C04F6BB853}") IAdapterDisplay  : public IInterface 
{
	
};

class DELPHICLASS TCustomAdapterGrid;
class PASCALIMPLEMENTATION TCustomAdapterGrid : public TAdapterControlGroup 
{
	typedef TAdapterControlGroup inherited;
	
private:
	TAdapterFormLayout* FTableLayout;
	Miditems::TGridAttributes* FTableAttributes;
	Miditems::TGridRowAttributes* FHeadingAttributes;
	Miditems::TGridRowAttributes* FRowAttributes;
	AnsiString __fastcall FormatTable(Webcomp::TLayoutWebContent* Layout, Webcomp::TWebContentOptions* Options);
	void __fastcall SetHeadingAttributes(const Miditems::TGridRowAttributes* Value);
	void __fastcall SetRowAttributes(const Miditems::TGridRowAttributes* Value);
	void __fastcall SetTableAttributes(const Miditems::TGridAttributes* Value);
	
protected:
	TAdapterFormLayout* __fastcall GetAdapterFormLayout(void);
	AnsiString __fastcall GetNewFieldPrefix();
	AnsiString __fastcall GetAddFieldsItem();
	AnsiString __fastcall GetAddAllFieldsItem();
	AnsiString __fastcall GetAddFieldsDlgCaption();
	Sitecomp::TAdapterDisplayCharacteristics __fastcall GetAdapterDisplayCharacteristics(void);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	
public:
	__fastcall virtual TCustomAdapterGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAdapterGrid(void);
	__property Miditems::TGridAttributes* TableAttributes = {read=FTableAttributes, write=SetTableAttributes};
	__property Miditems::TGridRowAttributes* HeadingAttributes = {read=FHeadingAttributes, write=SetHeadingAttributes};
	__property Miditems::TGridRowAttributes* RowAttributes = {read=FRowAttributes, write=SetRowAttributes};
private:
	void *__IAdapterDisplay;	/* Webform::IAdapterDisplay */
	void *__IGetAdapterDisplayCharacteristics;	/* Sitecomp::IGetAdapterDisplayCharacteristics */
	void *__IAddFieldsEditor;	/* Webcomp::IAddFieldsEditor */
	void *__IGetAdapterFormLayout;	/* Webform::IGetAdapterFormLayout */
	
public:
	operator IGetAdapterFormLayout*(void) { return (IGetAdapterFormLayout*)&__IGetAdapterFormLayout; }
	operator IAddFieldsEditor*(void) { return (IAddFieldsEditor*)&__IAddFieldsEditor; }
	operator IGetAdapterDisplayCharacteristics*(void) { return (IGetAdapterDisplayCharacteristics*)&__IGetAdapterDisplayCharacteristics; }
	operator IAdapterDisplay*(void) { return (IAdapterDisplay*)&__IAdapterDisplay; }
	
};


class DELPHICLASS TAdapterGrid;
class PASCALIMPLEMENTATION TAdapterGrid : public TCustomAdapterGrid 
{
	typedef TCustomAdapterGrid inherited;
	
__published:
	__property TableAttributes ;
	__property HeadingAttributes ;
	__property RowAttributes ;
	__property Adapter ;
	__property AdapterMode ;
	__property AddDefaultFields  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomAdapterGrid.Create */ inline __fastcall virtual TAdapterGrid(Classes::TComponent* AOwner) : TCustomAdapterGrid(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapterGrid.Destroy */ inline __fastcall virtual ~TAdapterGrid(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomAdapterFieldGroup;
class PASCALIMPLEMENTATION TCustomAdapterFieldGroup : public TAdapterControlGroup 
{
	typedef TAdapterControlGroup inherited;
	
private:
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FStyleRule;
	Webcomp::TLayoutAttributes* FLayoutAttributes;
	TAdapterFormLayout* FFormLayout;
	AnsiString __fastcall FormatFields(System::TObject* ParentLayout, Webcomp::TWebContentOptions* Options);
	
protected:
	AnsiString __fastcall GetNewFieldPrefix();
	AnsiString __fastcall GetAddFieldsItem();
	AnsiString __fastcall GetAddAllFieldsItem();
	AnsiString __fastcall GetAddFieldsDlgCaption();
	TAdapterFormLayout* __fastcall GetAdapterFormLayout(void);
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	Sitecomp::TAdapterDisplayCharacteristics __fastcall GetAdapterDisplayCharacteristics(void);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	
public:
	__fastcall virtual TCustomAdapterFieldGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAdapterFieldGroup(void);
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
private:
	void *__IAdapterDisplay;	/* Webform::IAdapterDisplay */
	void *__IGetAdapterDisplayCharacteristics;	/* Sitecomp::IGetAdapterDisplayCharacteristics */
	void *__IAddFieldsEditor;	/* Webcomp::IAddFieldsEditor */
	void *__IGetAdapterFormLayout;	/* Webform::IGetAdapterFormLayout */
	
public:
	operator IGetAdapterFormLayout*(void) { return (IGetAdapterFormLayout*)&__IGetAdapterFormLayout; }
	operator IAddFieldsEditor*(void) { return (IAddFieldsEditor*)&__IAddFieldsEditor; }
	operator IGetAdapterDisplayCharacteristics*(void) { return (IGetAdapterDisplayCharacteristics*)&__IGetAdapterDisplayCharacteristics; }
	operator IAdapterDisplay*(void) { return (IAdapterDisplay*)&__IAdapterDisplay; }
	
};


class DELPHICLASS TAdapterFieldGroup;
class PASCALIMPLEMENTATION TAdapterFieldGroup : public TCustomAdapterFieldGroup 
{
	typedef TCustomAdapterFieldGroup inherited;
	
__published:
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property Adapter ;
	__property AdapterMode ;
	__property AddDefaultFields  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomAdapterFieldGroup.Create */ inline __fastcall virtual TAdapterFieldGroup(Classes::TComponent* AOwner) : TCustomAdapterFieldGroup(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapterFieldGroup.Destroy */ inline __fastcall virtual ~TAdapterFieldGroup(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TInputFieldHTMLElementType { iftDefault, iftTextInput, iftPasswordInput, iftSelect, iftSelectMultiple, iftRadio, iftCheckBox, iftTextArea, iftFile };
#pragma option pop

#pragma option push -b-
enum TDisplayFieldHTMLElementType { dftDefault, dftText, dftImage, dftList };
#pragma option pop

#pragma option push -b-
enum TDisplayFieldViewMode { vmDefault, vmInput, vmDisplay, vmToggleOnAccess };
#pragma option pop

class DELPHICLASS TCustomAdapterDisplayField;
class PASCALIMPLEMENTATION TCustomAdapterDisplayField : public TAdapterDataDisplay 
{
	typedef TAdapterDataDisplay inherited;
	
private:
	int FDisplayWidth;
	TDisplayFieldHTMLElementType FDisplayType;
	TInputFieldHTMLElementType FInputType;
	int FSelectRows;
	int FImageWidth;
	int FImageHeight;
	int FMaxLength;
	int FDisplayRows;
	Miditems::TTextAreaWrap FWrap;
	TDisplayFieldViewMode FViewMode;
	int FDisplayColumns;
	AnsiString __fastcall FormatTextInput(const AnsiString VarName, const AnsiString HTMLName);
	AnsiString __fastcall FormatPasswordInput(const AnsiString VarName, const AnsiString HTMLName);
	AnsiString __fastcall FormatSelect(const AnsiString VarName, const AnsiString HTMLName, bool Multiple);
	bool __fastcall CalcInputElementType(TInputFieldHTMLElementType &AType);
	bool __fastcall CalcDisplayElementType(TDisplayFieldHTMLElementType &AType);
	bool __fastcall CalcDisplayFieldViewMode(TDisplayFieldViewMode &AMode);
	AnsiString __fastcall FormatTextDisplay(const AnsiString VarName, const AnsiString HTMLName);
	AnsiString __fastcall FormatListDisplay(const AnsiString VarName, const AnsiString HTMLName);
	AnsiString __fastcall FormatRadioGroup(const AnsiString VarName, const AnsiString HTMLName);
	AnsiString __fastcall FormatCheckBoxGroup(const AnsiString VarName, const AnsiString HTMLName);
	AnsiString __fastcall FormatInputGroup(const AnsiString FunctionName, const AnsiString VarName, const AnsiString HTMLName, int DisplayColumns);
	AnsiString __fastcall FormatTextArea(const AnsiString VarName, const AnsiString HTMLName);
	AnsiString __fastcall FormatImage(const AnsiString VarName, const AnsiString HTMLName, Webcomp::TWebContentOptions* Options);
	AnsiString __fastcall FormatFileInput(const AnsiString VarName, const AnsiString HTMLName);
	
protected:
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	void __fastcall AddAttributes(AnsiString &Attrs);
	virtual AnsiString __fastcall ControlContent(Webcomp::TWebContentOptions* Options);
	virtual void __fastcall ImplGetControlRequirements(TAbstractControlRequirements* ARequirements);
	virtual void __fastcall ImplRestoreDefaults(void);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	
public:
	__fastcall virtual TCustomAdapterDisplayField(Classes::TComponent* AOwner);
	__property int DisplayWidth = {read=FDisplayWidth, write=FDisplayWidth, default=-1};
	__property TDisplayFieldViewMode ViewMode = {read=FViewMode, write=FViewMode, default=0};
	__property TDisplayFieldHTMLElementType DisplayType = {read=FDisplayType, write=FDisplayType, default=0};
	__property TInputFieldHTMLElementType InputType = {read=FInputType, write=FInputType, default=0};
	__property int ImageWidth = {read=FImageWidth, write=FImageWidth, default=-1};
	__property int ImageHeight = {read=FImageHeight, write=FImageHeight, default=-1};
	__property int SelectRows = {read=FSelectRows, write=FSelectRows, default=0};
	__property int MaxLength = {read=FMaxLength, write=FMaxLength, default=-1};
	__property Miditems::TTextAreaWrap TextAreaWrap = {read=FWrap, write=FWrap, default=0};
	__property int DisplayRows = {read=FDisplayRows, write=FDisplayRows, default=-1};
	__property int DisplayColumns = {read=FDisplayColumns, write=FDisplayColumns, default=1};
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TCustomAdapterDisplayField(void) { }
	#pragma option pop
	
private:
	void *__IGetControlRequirements;	/* Webform::IGetControlRequirements */
	
public:
	operator IGetControlRequirements*(void) { return (IGetControlRequirements*)&__IGetControlRequirements; }
	
};


class DELPHICLASS TAdapterDisplayColumn;
class PASCALIMPLEMENTATION TAdapterDisplayColumn : public TCustomAdapterDisplayColumn 
{
	typedef TCustomAdapterDisplayColumn inherited;
	
__published:
	__property Caption ;
	__property CaptionAttributes ;
	__property FieldName ;
	__property DisplayType  = {default=0};
	__property ImageWidth  = {default=-1};
	__property ImageHeight  = {default=-1};
	__property HideOptions  = {default=4};
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property Align  = {default=0};
	__property VAlign  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomAdapterDisplayColumn.Create */ inline __fastcall virtual TAdapterDisplayColumn(Classes::TComponent* AOwner) : TCustomAdapterDisplayColumn(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TAdapterDisplayColumn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterDisplayField;
class PASCALIMPLEMENTATION TAdapterDisplayField : public TCustomAdapterDisplayField 
{
	typedef TCustomAdapterDisplayField inherited;
	
__published:
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property Caption ;
	__property DisplayColumns  = {default=1};
	__property CaptionAttributes ;
	__property DisplayWidth  = {default=-1};
	__property FieldName ;
	__property DisplayType  = {default=0};
	__property CaptionPosition  = {default=0};
	__property Align  = {default=0};
	__property VAlign  = {default=0};
	__property ImageWidth  = {default=-1};
	__property ImageHeight  = {default=-1};
	__property SelectRows  = {default=0};
	__property MaxLength  = {default=-1};
	__property TextAreaWrap  = {default=0};
	__property DisplayRows  = {default=-1};
	__property ViewMode  = {default=0};
	__property HideOptions  = {default=4};
	__property InputType  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomAdapterDisplayField.Create */ inline __fastcall virtual TAdapterDisplayField(Classes::TComponent* AOwner) : TCustomAdapterDisplayField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TAdapterDisplayField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomAdapterEditColumn;
class PASCALIMPLEMENTATION TCustomAdapterEditColumn : public TCustomAdapterDisplayField 
{
	typedef TCustomAdapterDisplayField inherited;
	
protected:
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
public:
	#pragma option push -w-inl
	/* TCustomAdapterDisplayField.Create */ inline __fastcall virtual TCustomAdapterEditColumn(Classes::TComponent* AOwner) : TCustomAdapterDisplayField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TCustomAdapterEditColumn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterEditColumn;
class PASCALIMPLEMENTATION TAdapterEditColumn : public TCustomAdapterEditColumn 
{
	typedef TCustomAdapterEditColumn inherited;
	
__published:
	__property Style ;
	__property Custom ;
	__property StyleRule ;
	__property Caption ;
	__property DisplayColumns  = {default=1};
	__property CaptionAttributes ;
	__property DisplayWidth  = {default=-1};
	__property FieldName ;
	__property DisplayType  = {default=0};
	__property CaptionPosition  = {default=0};
	__property Align  = {default=0};
	__property VAlign  = {default=0};
	__property ImageWidth  = {default=-1};
	__property ImageHeight  = {default=-1};
	__property SelectRows  = {default=0};
	__property MaxLength  = {default=-1};
	__property TextAreaWrap  = {default=0};
	__property DisplayRows  = {default=-1};
	__property ViewMode  = {default=0};
	__property HideOptions  = {default=4};
	__property InputType  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomAdapterDisplayField.Create */ inline __fastcall virtual TAdapterEditColumn(Classes::TComponent* AOwner) : TCustomAdapterEditColumn(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebDataDisplay.Destroy */ inline __fastcall virtual ~TAdapterEditColumn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterDisplayReferenceGroup;
class PASCALIMPLEMENTATION TAdapterDisplayReferenceGroup : public Miditems::TWebDisplayReferenceGroup 
{
	typedef Miditems::TWebDisplayReferenceGroup inherited;
	
protected:
	void __fastcall OnDisplayComponentChange(System::TObject* ASender);
	virtual void __fastcall DisplayComponentChange(void);
	virtual void __fastcall AdapterChange(void);
	void __fastcall GetDesigntimeWarnings(Sitecomp::TAbstractDesigntimeWarnings* AWarnings);
	Sitecomp::TAdapterDisplayCharacteristics __fastcall GetAdapterDisplayCharacteristics(void);
	void __fastcall NotifyAdapterChange(Classes::TComponent* Sender);
	virtual void __fastcall SetWebDisplayComponent(const Classes::TComponent* AComponent);
	
public:
	__fastcall virtual TAdapterDisplayReferenceGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TAdapterDisplayReferenceGroup(void);
	__property Classes::TComponent* DisplayComponent = {read=GetWebDisplayComponent, write=SetWebDisplayComponent};
private:
	void *__IGetDesigntimeWarnings;	/* Sitecomp::IGetDesigntimeWarnings */
	void *__INotifyAdapterChange;	/* Sitecomp::INotifyAdapterChange */
	void *__IGetAdapterDisplayCharacteristics;	/* Sitecomp::IGetAdapterDisplayCharacteristics */
	
public:
	operator IGetAdapterDisplayCharacteristics*(void) { return (IGetAdapterDisplayCharacteristics*)&__IGetAdapterDisplayCharacteristics; }
	operator INotifyAdapterChange*(void) { return (INotifyAdapterChange*)&__INotifyAdapterChange; }
	operator IGetDesigntimeWarnings*(void) { return (IGetDesigntimeWarnings*)&__IGetDesigntimeWarnings; }
	
};


class DELPHICLASS TCustomAdapterCommandGroup;
class PASCALIMPLEMENTATION TCustomAdapterCommandGroup : public TAdapterDisplayReferenceGroup 
{
	typedef TAdapterDisplayReferenceGroup inherited;
	
private:
	AnsiString FStyle;
	AnsiString FCustom;
	AnsiString FStyleRule;
	TAdapterFormLayout* FFormLayout;
	TAdapterActionsListHelper* FAdapterActionsListHelper;
	Webcomp::TWebComponentList* __fastcall GetVisibleCommands(void);
	bool __fastcall GetAddDefaultCommands(void);
	void __fastcall SetAddDefaultCommands(const bool Value);
	
protected:
	TAdapterFormLayout* __fastcall GetAdapterFormLayout(void);
	AnsiString __fastcall GetAdapterModeOfDisplay();
	AnsiString __fastcall GetAdapterModeOfAdapter();
	Classes::TComponent* __fastcall GetAdapter(void);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	__property Classes::TComponent* Adapter = {read=GetAdapter};
	__property TAdapterActionsListHelper* AdapterActionsListHelper = {read=FAdapterActionsListHelper};
	
public:
	__fastcall virtual TCustomAdapterCommandGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAdapterCommandGroup(void);
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
	__property Webcomp::TWebComponentList* VisibleCommands = {read=GetVisibleCommands};
	__property bool AddDefaultCommands = {read=GetAddDefaultCommands, write=SetAddDefaultCommands, default=1};
private:
	void *__IWebActionsList;	/* Sitecomp::IWebActionsList */
	void *__IGetAdapterOfDisplay;	/* Webform::IGetAdapterOfDisplay */
	void *__IGetVariablesContainerOfDisplay;	/* Webform::IGetVariablesContainerOfDisplay [GetVariablesContainer=GetAdapter] */
	void *__IAddFieldsEditor;	/* Webcomp::IAddFieldsEditor */
	void *__IGetAdapterModeOfDisplay;	/* Webform::IGetAdapterModeOfDisplay */
	void *__IGetAdapterFormLayout;	/* Webform::IGetAdapterFormLayout */
	
public:
	operator IGetAdapterFormLayout*(void) { return (IGetAdapterFormLayout*)&__IGetAdapterFormLayout; }
	operator IGetAdapterModeOfDisplay*(void) { return (IGetAdapterModeOfDisplay*)&__IGetAdapterModeOfDisplay; }
	operator IAddFieldsEditor*(void) { return (IAddFieldsEditor*)&__IAddFieldsEditor; }
	operator IGetVariablesContainerOfDisplay*(void) { return (IGetVariablesContainerOfDisplay*)&__IGetVariablesContainerOfDisplay; }
	operator IGetAdapterOfDisplay*(void) { return (IGetAdapterOfDisplay*)&__IGetAdapterOfDisplay; }
	operator IWebActionsList*(void) { return (IWebActionsList*)&__IWebActionsList; }
	
};


class DELPHICLASS TAdapterCommandGroup;
class PASCALIMPLEMENTATION TAdapterCommandGroup : public TCustomAdapterCommandGroup 
{
	typedef TCustomAdapterCommandGroup inherited;
	
__published:
	__property DisplayComponent ;
	__property Custom ;
	__property Style ;
	__property StyleRule ;
	__property AddDefaultCommands  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomAdapterCommandGroup.Create */ inline __fastcall virtual TAdapterCommandGroup(Classes::TComponent* AOwner) : TCustomAdapterCommandGroup(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapterCommandGroup.Destroy */ inline __fastcall virtual ~TAdapterCommandGroup(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TActionButtonHideOption { bhoHideOnNoExecuteAccess, bhoHideOnActionNotVisible, bhoHideOnDisabledAction, bhoHideAlways };
#pragma option pop

typedef Set<TActionButtonHideOption, bhoHideOnNoExecuteAccess, bhoHideAlways>  TActionButtonHideOptions;

#pragma option push -b-
enum TCommandHTMLElementType { ctDefault, ctButton, ctImage, ctAnchor, ctEventImages };
#pragma option pop

class DELPHICLASS TCustomAdapterActionButton;
class PASCALIMPLEMENTATION TCustomAdapterActionButton : public Miditems::TWebButton 
{
	typedef Miditems::TWebButton inherited;
	
private:
	AnsiString FActionName;
	TCommandHTMLElementType FDisplayType;
	AnsiString FPageName;
	AnsiString FErrorPageName;
	int FImageWidth;
	int FImageHeight;
	TActionButtonHideOptions FHideOptions;
	int FDisplayColumns;
	Sitecomp::_di_IActionImageProducer FImageProducer;
	Webcomp::TLayoutAttributes* FLayoutAttributes;
	Httpprod::THTMLAlign FAlign;
	Httpprod::THTMLVAlign FVAlign;
	void __fastcall SetImageProducer(const Sitecomp::_di_IActionImageProducer Value);
	Classes::TComponent* __fastcall GetImageProducerComponent(void);
	AnsiString __fastcall GetImageProducerVariableName();
	
protected:
	virtual Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	AnsiString __fastcall GetAdapterModeOfAdapter();
	AnsiString __fastcall GetHTMLFormVarName();
	void __fastcall GetDesigntimeWarnings(Sitecomp::TAbstractDesigntimeWarnings* AWarnings);
	void __fastcall GetControlRequirements(TAbstractControlRequirements* ARequirements);
	virtual void __fastcall ImplGetControlRequirements(TAbstractControlRequirements* ARequirements);
	void __fastcall RestoreDefaults(void);
	virtual void __fastcall ImplRestoreDefaults(void);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	AnsiString __fastcall GetActionName();
	void __fastcall SetActionName(const AnsiString AValue);
	virtual void __fastcall SetCaption(const AnsiString Value);
	virtual AnsiString __fastcall GetCaption();
	AnsiString __fastcall GetAdapterVariableName();
	Classes::TComponent* __fastcall FindAssociatedAction(void);
	
public:
	__fastcall virtual TCustomAdapterActionButton(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAdapterActionButton(void);
	__property AnsiString ActionName = {read=GetActionName, write=SetActionName};
	__property AnsiString PageName = {read=FPageName, write=FPageName};
	__property AnsiString ErrorPageName = {read=FErrorPageName, write=FErrorPageName};
	__property TCommandHTMLElementType DisplayType = {read=FDisplayType, write=FDisplayType, default=0};
	__property int ImageWidth = {read=FImageWidth, write=FImageWidth, default=-1};
	__property int ImageHeight = {read=FImageHeight, write=FImageHeight, default=-1};
	__property TActionButtonHideOptions HideOptions = {read=FHideOptions, write=FHideOptions, default=2};
	__property int DisplayColumns = {read=FDisplayColumns, write=FDisplayColumns, default=-1};
	__property Sitecomp::_di_IActionImageProducer ImageProducer = {read=FImageProducer, write=SetImageProducer};
	__property Httpprod::THTMLAlign Align = {read=FAlign, write=FAlign, default=0};
	__property Httpprod::THTMLVAlign VAlign = {read=FVAlign, write=FVAlign, default=0};
private:
	void *__IWebGetActionName;	/* Sitecomp::IWebGetActionName */
	void *__IWebSetActionName;	/* Sitecomp::IWebSetActionName */
	void *__IRestoreDefaults;	/* Miditems::IRestoreDefaults */
	void *__IGetControlRequirements;	/* Webform::IGetControlRequirements */
	void *__IGetAdapterVariableName;	/* Webform::IGetAdapterVariableName */
	void *__IGetDesigntimeWarnings;	/* Sitecomp::IGetDesigntimeWarnings */
	
public:
	operator IGetDesigntimeWarnings*(void) { return (IGetDesigntimeWarnings*)&__IGetDesigntimeWarnings; }
	operator IGetAdapterVariableName*(void) { return (IGetAdapterVariableName*)&__IGetAdapterVariableName; }
	operator IGetControlRequirements*(void) { return (IGetControlRequirements*)&__IGetControlRequirements; }
	operator IRestoreDefaults*(void) { return (IRestoreDefaults*)&__IRestoreDefaults; }
	operator IWebSetActionName*(void) { return (IWebSetActionName*)&__IWebSetActionName; }
	operator IWebGetActionName*(void) { return (IWebGetActionName*)&__IWebGetActionName; }
	
};


class DELPHICLASS TAdapterActionButton;
class PASCALIMPLEMENTATION TAdapterActionButton : public TCustomAdapterActionButton 
{
	typedef TCustomAdapterActionButton inherited;
	
__published:
	__property ActionName ;
	__property Style ;
	__property Custom ;
	__property Caption ;
	__property StyleRule ;
	__property PageName ;
	__property ErrorPageName ;
	__property HideOptions  = {default=2};
	__property DisplayType  = {default=0};
	__property ImageWidth  = {default=-1};
	__property ImageHeight  = {default=-1};
	__property DisplayColumns  = {default=-1};
	__property ImageProducer ;
	__property Align  = {default=0};
	__property VAlign  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomAdapterActionButton.Create */ inline __fastcall virtual TAdapterActionButton(Classes::TComponent* AOwner) : TCustomAdapterActionButton(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapterActionButton.Destroy */ inline __fastcall virtual ~TAdapterActionButton(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TLayoutState { lsUnknown, lsFields, lsButtons };
#pragma option pop

class PASCALIMPLEMENTATION TAdapterFormLayout : public Webcomp::TLayoutWebContent 
{
	typedef Webcomp::TLayoutWebContent inherited;
	
private:
	AnsiString FParentIndent;
	int FFieldLevel;
	int FTableLevel;
	TLayoutState FLayoutState;
	bool FInTable;
	bool FInRow;
	AnsiString FTableHeader;
	int FColumnCount;
	int FColumnIndex;
	bool FBreakButtons;
	int FButtonIndex;
	AnsiString FTableIndent;
	AnsiString FFieldIndent;
	
protected:
	TAdapterFormLayout* __fastcall GetAdapterFormLayout(void);
	AnsiString __fastcall GetTableIndent();
	AnsiString __fastcall GetChildTableIndent();
	AnsiString __fastcall GetFieldIndent();
	virtual AnsiString __fastcall ImplLayoutButton(const AnsiString HTMLButton, Webcomp::TLayoutAttributes* Attributes);
	virtual AnsiString __fastcall ImplLayoutField(const AnsiString HTMLField, Webcomp::TLayoutAttributes* Attributes);
	virtual AnsiString __fastcall ImplLayoutLabelAndField(const AnsiString HTMLLabel, const AnsiString HTMLField, Webcomp::TLayoutAttributes* Attributes);
	virtual AnsiString __fastcall ImplLayoutTable(const AnsiString HTMLTable, Webcomp::TLayoutAttributes* Attributes);
	AnsiString __fastcall StartFields(int ColCount);
	AnsiString __fastcall EndButtons();
	AnsiString __fastcall StartButtons();
	AnsiString __fastcall EndFields();
	AnsiString __fastcall StartTable();
	AnsiString __fastcall EndTable();
	AnsiString __fastcall StartRow();
	AnsiString __fastcall EndRow();
	AnsiString __fastcall NextColumn(int SubItemCount);
	AnsiString __fastcall EndField();
	
public:
	__fastcall TAdapterFormLayout(System::TObject* AParentLayout);
	AnsiString __fastcall EndLayout();
	__property int ColumnCount = {read=FColumnCount, write=FColumnCount, nodefault};
	__property bool BreakButtons = {read=FBreakButtons, write=FBreakButtons, nodefault};
	__property AnsiString TableHeader = {read=FTableHeader, write=FTableHeader};
	__property AnsiString FieldIndent = {read=GetFieldIndent};
	__property AnsiString TableIndent = {read=GetTableIndent};
	__property AnsiString ChildTableIndent = {read=GetChildTableIndent};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAdapterFormLayout(void) { }
	#pragma option pop
	
private:
	void *__IGetAdapterFormLayout;	/* Webform::IGetAdapterFormLayout */
	
public:
	operator IGetAdapterFormLayout*(void) { return (IGetAdapterFormLayout*)&__IGetAdapterFormLayout; }
	
};


class DELPHICLASS TCustomAdapterErrorList;
class PASCALIMPLEMENTATION TCustomAdapterErrorList : public Webcomp::TWebContainedComponent 
{
	typedef Webcomp::TWebContainedComponent inherited;
	
private:
	Classes::TComponent* FAdapter;
	Webcomp::TLayoutAttributes* FLayoutAttributes;
	Classes::TComponent* __fastcall GetAdapter(void);
	void __fastcall SetAdapter(const Classes::TComponent* Value);
	Webcomp::TLayoutAttributes* __fastcall GetLayoutAttributes(void);
	
protected:
	void __fastcall GetDesigntimeWarnings(Sitecomp::TAbstractDesigntimeWarnings* AWarnings);
	AnsiString __fastcall Content(Webcomp::TWebContentOptions* Options, System::TObject* Layout);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* Layout);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TCustomAdapterErrorList(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAdapterErrorList(void);
	__property Classes::TComponent* Adapter = {read=GetAdapter, write=SetAdapter};
private:
	void *__IWebContent;	/* Webcomp::IWebContent */
	void *__IGetDesigntimeWarnings;	/* Sitecomp::IGetDesigntimeWarnings */
	
public:
	operator IGetDesigntimeWarnings*(void) { return (IGetDesigntimeWarnings*)&__IGetDesigntimeWarnings; }
	operator IWebContent*(void) { return (IWebContent*)&__IWebContent; }
	
};


class DELPHICLASS TAdapterErrorList;
class PASCALIMPLEMENTATION TAdapterErrorList : public TCustomAdapterErrorList 
{
	typedef TCustomAdapterErrorList inherited;
	
__published:
	__property Adapter ;
public:
	#pragma option push -w-inl
	/* TCustomAdapterErrorList.Create */ inline __fastcall virtual TAdapterErrorList(Classes::TComponent* AOwner) : TCustomAdapterErrorList(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapterErrorList.Destroy */ inline __fastcall virtual ~TAdapterErrorList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDesigntimeWarnings;
class PASCALIMPLEMENTATION TDesigntimeWarnings : public Sitecomp::TAbstractDesigntimeWarnings 
{
	typedef Sitecomp::TAbstractDesigntimeWarnings inherited;
	
private:
	Classes::TStrings* FStrings;
	Contnrs::TObjectList* FObjects;
	
public:
	virtual void __fastcall AddString(AnsiString AWarning);
	virtual void __fastcall AddObject(System::TObject* AObject);
	__property Classes::TStrings* Strings = {read=FStrings};
	__fastcall TDesigntimeWarnings(void);
	__fastcall virtual ~TDesigntimeWarnings(void);
};


//-- var, const, procedure ---------------------------------------------------
#define sMultipartForm "multipart/form-data"
#define sFormPost "post"
#define sFormGet "get"
#define sDisplayText "<%%= %0:s.DisplayText %%>"
#define sFieldText "<%%= %0:s.EditText %%>"
extern PACKAGE Classes::TComponent* __fastcall FindVariablesContainer(Classes::TComponent* AComponent);
extern PACKAGE Classes::TComponent* __fastcall FindVariablesContainerInParent(Classes::TComponent* AComponent);
extern PACKAGE AnsiString __fastcall MakeAdapterVariableName(Classes::TComponent* AComponent);
extern PACKAGE AnsiString __fastcall MakeAdapterHTMLName(AnsiString AVarName);
extern PACKAGE AnsiString __fastcall GetAdapterModeOfAdapterInParent(Classes::TComponent* AComponent);
extern PACKAGE bool __fastcall CalcDisplayFieldViewMode(Classes::TComponent* AField, const AnsiString AAdapterMode, TDisplayFieldViewMode AViewMode, TDisplayFieldViewMode &AMode);
extern PACKAGE bool __fastcall CalcDisplayFieldHTMLElementType(Classes::TComponent* AField, const AnsiString AAdapterMode, TDisplayFieldHTMLElementType ADisplayType, TDisplayFieldHTMLElementType &AType);

}	/* namespace Webform */
using namespace Webform;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebForm
