// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DesignIntf.pas' rev: 6.00

#ifndef DesignIntfHPP
#define DesignIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <IniFiles.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Designintf
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TPropKind { pkProperties, pkEvents };
#pragma option pop

__interface IProperty;
typedef System::DelphiInterface<IProperty> _di_IProperty;
typedef void __fastcall (__closure *TGetPropProc)(const _di_IProperty Prop);

#pragma option push -b-
enum TPropertyAttribute { paValueList, paSubProperties, paDialog, paMultiSelect, paAutoUpdate, paSortList, paReadOnly, paRevertable, paFullWidthName, paVolatileSubProperties, paVCL, paNotNestable };
#pragma option pop

typedef Set<TPropertyAttribute, paValueList, paNotNestable>  TPropertyAttributes;

__interface INTERFACE_UUID("{7ED7BF29-E349-11D3-AB4A-00C04FB17A72}") IProperty  : public IInterface 
{
	
public:
	virtual void __fastcall Activate(void) = 0 ;
	virtual bool __fastcall AllEqual(void) = 0 ;
	virtual bool __fastcall AutoFill(void) = 0 ;
	virtual void __fastcall Edit(void) = 0 ;
	virtual bool __fastcall HasInstance(Classes::TPersistent* Instance) = 0 ;
	virtual TPropertyAttributes __fastcall GetAttributes(void) = 0 ;
	virtual int __fastcall GetEditLimit(void) = 0 ;
	virtual bool __fastcall GetEditValue(/* out */ AnsiString &Value) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual void __fastcall GetProperties(TGetPropProc Proc) = 0 ;
	virtual Typinfo::PPropInfo __fastcall GetPropInfo(void) = 0 ;
	virtual Typinfo::PTypeInfo __fastcall GetPropType(void) = 0 ;
	virtual AnsiString __fastcall GetValue(void) = 0 ;
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc) = 0 ;
	virtual void __fastcall Revert(void) = 0 ;
	virtual void __fastcall SetValue(const AnsiString Value) = 0 ;
	virtual bool __fastcall ValueAvailable(void) = 0 ;
};

__interface IMethodProperty;
typedef System::DelphiInterface<IMethodProperty> _di_IMethodProperty;
__interface INTERFACE_UUID("{392CBF4A-F078-47E9-B731-0E0B7F1F4998}") IMethodProperty  : public IInterface 
{
	
};

__interface IActivatable;
typedef System::DelphiInterface<IActivatable> _di_IActivatable;
__interface INTERFACE_UUID("{F00AA4BD-3459-43E9-ACB2-97DBD1663AFF}") IActivatable  : public IInterface 
{
	
public:
	virtual void __fastcall Activate(void) = 0 ;
};

__interface IReferenceProperty;
typedef System::DelphiInterface<IReferenceProperty> _di_IReferenceProperty;
__interface INTERFACE_UUID("{C7EE2B1E-3F89-40AD-9250-D2667BA3D46B}") IReferenceProperty  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall GetComponentReference(void) = 0 ;
};

__interface IDesignerSelections;
typedef System::DelphiInterface<IDesignerSelections> _di_IDesignerSelections;
__interface INTERFACE_UUID("{7ED7BF30-E349-11D3-AB4A-00C04FB17A72}") IDesignerSelections  : public IInterface 
{
	
public:
	Classes::TPersistent* operator[](int Index) { return Items[Index]; }
	
public:
	virtual int __fastcall Add(const Classes::TPersistent* Item) = 0 ;
	virtual bool __fastcall Equals(const _di_IDesignerSelections List) = 0 ;
	virtual Classes::TPersistent* __fastcall Get(int Index) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	__property int Count = {read=GetCount};
	__property Classes::TPersistent* Items[int Index] = {read=Get/*, default*/};
};

__interface IDesigner;
typedef System::DelphiInterface<IDesigner> _di_IDesigner;
__interface INTERFACE_UUID("{A29C6480-D4AF-11D3-BA96-0080C78ADCDB}") IDesigner  : public IInterface 
{
	
public:
	virtual void __fastcall Activate(void) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	virtual System::TMethod __fastcall CreateMethod(const AnsiString Name, Typinfo::PTypeData TypeData) = 0 ;
	virtual AnsiString __fastcall GetMethodName(const System::TMethod &Method) = 0 ;
	virtual void __fastcall GetMethods(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc) = 0 ;
	virtual AnsiString __fastcall GetPathAndBaseExeName(void) = 0 ;
	virtual AnsiString __fastcall GetPrivateDirectory(void) = 0 ;
	virtual AnsiString __fastcall GetBaseRegKey(void) = 0 ;
	virtual Inifiles::TCustomIniFile* __fastcall GetIDEOptions(void) = 0 ;
	virtual void __fastcall GetSelections(const _di_IDesignerSelections List) = 0 ;
	virtual bool __fastcall MethodExists(const AnsiString Name) = 0 ;
	virtual void __fastcall RenameMethod(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall SelectComponent(Classes::TPersistent* Instance) = 0 ;
	virtual void __fastcall SetSelections(const _di_IDesignerSelections List) = 0 ;
	virtual void __fastcall ShowMethod(const AnsiString Name) = 0 ;
	virtual void __fastcall GetComponentNames(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc) = 0 ;
	virtual Classes::TComponent* __fastcall GetComponent(const AnsiString Name) = 0 ;
	virtual AnsiString __fastcall GetComponentName(Classes::TComponent* Component) = 0 ;
	virtual Classes::TPersistent* __fastcall GetObject(const AnsiString Name) = 0 ;
	virtual AnsiString __fastcall GetObjectName(Classes::TPersistent* Instance) = 0 ;
	virtual void __fastcall GetObjectNames(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc) = 0 ;
	virtual bool __fastcall MethodFromAncestor(const System::TMethod &Method) = 0 ;
	virtual Classes::TComponent* __fastcall CreateComponent(TMetaClass* ComponentClass, Classes::TComponent* Parent, int Left, int Top, int Width, int Height) = 0 ;
	virtual Classes::TComponent* __fastcall CreateCurrentComponent(Classes::TComponent* Parent, const Types::TRect &Rect) = 0 ;
	virtual bool __fastcall IsComponentLinkable(Classes::TComponent* Component) = 0 ;
	virtual bool __fastcall IsComponentHidden(Classes::TComponent* Component) = 0 ;
	virtual void __fastcall MakeComponentLinkable(Classes::TComponent* Component) = 0 ;
	virtual void __fastcall Revert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo) = 0 ;
	virtual bool __fastcall GetIsDormant(void) = 0 ;
	virtual void __fastcall GetProjectModules(Classes::TGetModuleProc Proc) = 0 ;
	virtual _di_IDesigner __fastcall GetAncestorDesigner(void) = 0 ;
	virtual bool __fastcall IsSourceReadOnly(void) = 0 ;
	virtual Types::TPoint __fastcall GetScrollRanges(const Types::TPoint &ScrollPosition) = 0 ;
	virtual void __fastcall Edit(const Classes::TComponent* Component) = 0 ;
	virtual void __fastcall ChainCall(const AnsiString MethodName, const AnsiString InstanceName, const AnsiString InstanceMethod, Typinfo::PTypeData TypeData) = 0 ;
	virtual void __fastcall CopySelection(void) = 0 ;
	virtual void __fastcall CutSelection(void) = 0 ;
	virtual bool __fastcall CanPaste(void) = 0 ;
	virtual void __fastcall PasteSelection(void) = 0 ;
	virtual void __fastcall DeleteSelection(bool ADoAll = false) = 0 ;
	virtual void __fastcall ClearSelection(void) = 0 ;
	virtual void __fastcall NoSelection(void) = 0 ;
	virtual void __fastcall ModuleFileNames(AnsiString &ImplFileName, AnsiString &IntfFileName, AnsiString &FormFileName) = 0 ;
	virtual AnsiString __fastcall GetRootClassName(void) = 0 ;
	virtual AnsiString __fastcall UniqueName(const AnsiString BaseName) = 0 ;
	virtual Classes::TComponent* __fastcall GetRoot(void) = 0 ;
	virtual Classes::TShiftState __fastcall GetShiftState(void) = 0 ;
	virtual void __fastcall ModalEdit(char EditKey, const _di_IActivatable ReturnWindow) = 0 ;
	virtual void __fastcall SelectItemName(const AnsiString PropertyName) = 0 ;
	virtual void __fastcall Resurrect(void) = 0 ;
	__property Classes::TComponent* Root = {read=GetRoot};
	__property bool IsDormant = {read=GetIsDormant};
	__property _di_IDesigner AncestorDesigner = {read=GetAncestorDesigner};
};

typedef void __fastcall (__closure *TGetDesignerEvent)(System::TObject* Sender, /* out */ _di_IDesigner &ADesigner);

__interface IDesignNotification;
typedef System::DelphiInterface<IDesignNotification> _di_IDesignNotification;
__interface INTERFACE_UUID("{E8C9F739-5601-4ADD-9D95-594132D4CEFD}") IDesignNotification  : public IInterface 
{
	
public:
	virtual void __fastcall ItemDeleted(const _di_IDesigner ADesigner, Classes::TPersistent* AItem) = 0 ;
	virtual void __fastcall ItemInserted(const _di_IDesigner ADesigner, Classes::TPersistent* AItem) = 0 ;
	virtual void __fastcall ItemsModified(const _di_IDesigner ADesigner) = 0 ;
	virtual void __fastcall SelectionChanged(const _di_IDesigner ADesigner, const _di_IDesignerSelections ASelection) = 0 ;
	virtual void __fastcall DesignerOpened(const _di_IDesigner ADesigner, bool AResurrecting) = 0 ;
	virtual void __fastcall DesignerClosed(const _di_IDesigner ADesigner, bool AGoingDormant) = 0 ;
};

__interface IDesignWindow;
typedef System::DelphiInterface<IDesignWindow> _di_IDesignWindow;
__interface INTERFACE_UUID("{7ED7BF2E-E349-11D3-AB4A-00C04FB17A72}") IDesignWindow  : public IDesignNotification 
{
	
public:
	virtual void __fastcall WindowHide(void) = 0 ;
	virtual void __fastcall WindowShow(void) = 0 ;
};

typedef void __fastcall (*TRegisterDesignNotification)(const _di_IDesignNotification DesignNotification);

class DELPHICLASS TBasePropertyEditor;
class PASCALIMPLEMENTATION TBasePropertyEditor : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
protected:
	virtual void __fastcall Initialize(void) = 0 ;
	virtual void __fastcall SetPropEntry(int Index, Classes::TPersistent* AInstance, Typinfo::PPropInfo APropInfo) = 0 ;
	
public:
	__fastcall virtual TBasePropertyEditor(const _di_IDesigner ADesigner, int APropCount);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBasePropertyEditor(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TPropertyEditorClass;

typedef void __fastcall (*TRegisterPropertyEditorProc)(Typinfo::PTypeInfo PropertyType, TMetaClass* ComponentClass, const AnsiString PropertyName, TMetaClass* EditorClass);

typedef bool __fastcall (__closure *TPropertyEditorFilterFunc)(const _di_IProperty ATestEditor);

typedef void __fastcall (*TSetPropertyEditorGroupProc)(TMetaClass* EditorClass, TMetaClass* GroupClass);

typedef void __fastcall (*TRegisterPropertyInCategoryProc)(const AnsiString CategoryName, TMetaClass* ComponentClass, Typinfo::PTypeInfo PropertyType, const AnsiString PropertyName);

typedef TMetaClass* __fastcall (*TPropertyMapperFunc)(Classes::TPersistent* Obj, Typinfo::PPropInfo PropInfo);

typedef void __fastcall (*TRegisterPropertyMapperProc)(TPropertyMapperFunc Mapper);

__interface IComponentEditor;
typedef System::DelphiInterface<IComponentEditor> _di_IComponentEditor;
__interface INTERFACE_UUID("{ECACBA34-DCDF-4BE2-A645-E4404BC06106}") IComponentEditor  : public IInterface 
{
	
public:
	virtual void __fastcall Edit(void) = 0 ;
	virtual void __fastcall ExecuteVerb(int Index) = 0 ;
	virtual AnsiString __fastcall GetVerb(int Index) = 0 ;
	virtual int __fastcall GetVerbCount(void) = 0 ;
	virtual void __fastcall PrepareItem(int Index, const Designmenus::_di_IMenuItem AItem) = 0 ;
	virtual void __fastcall Copy(void) = 0 ;
	virtual bool __fastcall IsInInlined(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetComponent(void) = 0 ;
	virtual _di_IDesigner __fastcall GetDesigner(void) = 0 ;
};

class DELPHICLASS TBaseComponentEditor;
class PASCALIMPLEMENTATION TBaseComponentEditor : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	__fastcall virtual TBaseComponentEditor(Classes::TComponent* AComponent, _di_IDesigner ADesigner);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBaseComponentEditor(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TComponentEditorClass;

__interface IDefaultEditor;
typedef System::DelphiInterface<IDefaultEditor> _di_IDefaultEditor;
__interface INTERFACE_UUID("{5484FAE1-5C60-11D1-9FB6-0020AF3D82DA}") IDefaultEditor  : public IComponentEditor 
{
	
};

typedef void __fastcall (*TRegisterComponentEditorProc)(TMetaClass* ComponentClass, TMetaClass* ComponentEditor);

__interface ISelectionEditor;
typedef System::DelphiInterface<ISelectionEditor> _di_ISelectionEditor;
__interface INTERFACE_UUID("{B91F7A78-BB2C-45D9-957A-8A45A2D30435}") ISelectionEditor  : public IInterface 
{
	
public:
	virtual void __fastcall ExecuteVerb(int Index, const _di_IDesignerSelections List) = 0 ;
	virtual AnsiString __fastcall GetVerb(int Index) = 0 ;
	virtual int __fastcall GetVerbCount(void) = 0 ;
	virtual void __fastcall PrepareItem(int Index, const Designmenus::_di_IMenuItem AItem) = 0 ;
	virtual void __fastcall RequiresUnits(Classes::TGetStrProc Proc) = 0 ;
};

class DELPHICLASS TBaseSelectionEditor;
class PASCALIMPLEMENTATION TBaseSelectionEditor : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	__fastcall virtual TBaseSelectionEditor(const _di_IDesigner ADesigner);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBaseSelectionEditor(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TSelectionEditorClass;

__interface ISelectionEditorList;
typedef System::DelphiInterface<ISelectionEditorList> _di_ISelectionEditorList;
__interface INTERFACE_UUID("{C1360368-0099-4A7C-A4A8-7650503BA0C6}") ISelectionEditorList  : public IInterface 
{
	
public:
	_di_ISelectionEditor operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_ISelectionEditor __fastcall Get(int Index) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_ISelectionEditor Items[int Index] = {read=Get/*, default*/};
};

typedef void __fastcall (*TRegisterSelectionEditorProc)(TMetaClass* AClass, TMetaClass* AEditor);

#pragma option push -b-
enum TCustomModuleAttribute { cmaVirtualSize };
#pragma option pop

typedef Set<TCustomModuleAttribute, cmaVirtualSize, cmaVirtualSize>  TCustomModuleAttributes;

__interface ICustomModule;
typedef System::DelphiInterface<ICustomModule> _di_ICustomModule;
__interface INTERFACE_UUID("{95DA4A2B-D800-4CBB-B0B8-85AB7D3CFADA}") ICustomModule  : public IInterface 
{
	
public:
	virtual TCustomModuleAttributes __fastcall GetAttributes(void) = 0 ;
	virtual void __fastcall ExecuteVerb(int Index) = 0 ;
	virtual AnsiString __fastcall GetVerb(int Index) = 0 ;
	virtual int __fastcall GetVerbCount(void) = 0 ;
	virtual void __fastcall PrepareItem(int Index, const Designmenus::_di_IMenuItem AItem) = 0 ;
	virtual void __fastcall Saving(void) = 0 ;
	virtual void __fastcall ValidateComponent(Classes::TComponent* Component) = 0 ;
	virtual bool __fastcall ValidateComponentClass(TMetaClass* ComponentClass) = 0 ;
	virtual bool __fastcall Nestable(void) = 0 ;
};

class DELPHICLASS TBaseCustomModule;
class PASCALIMPLEMENTATION TBaseCustomModule : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	__fastcall virtual TBaseCustomModule(Classes::TComponent* ARoot, const _di_IDesigner Designer);
	/* virtual class method */ virtual TMetaClass* __fastcall DesignClass(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBaseCustomModule(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TCustomModuleClass;

typedef void __fastcall (*TRegisterCustomModuleProc)(int Group, TMetaClass* ComponentBaseClass, TMetaClass* CustomModuleClass);

class DELPHICLASS TDesignerSelections;
class PASCALIMPLEMENTATION TDesignerSelections : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	Classes::TPersistent* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TList* FList;
	
protected:
	int __fastcall Add(const Classes::TPersistent* Item);
	bool __fastcall Equals(const _di_IDesignerSelections List);
	Classes::TPersistent* __fastcall Get(int Index);
	int __fastcall GetCount(void);
	__property int Count = {read=GetCount, nodefault};
	__property Classes::TPersistent* Items[int Index] = {read=Get/*, default*/};
	
public:
	__fastcall virtual TDesignerSelections(void);
	__fastcall TDesignerSelections(const _di_IDesignerSelections Selections);
	__fastcall virtual ~TDesignerSelections(void);
private:
	void *__IDesignerSelections;	/* Designintf::IDesignerSelections */
	
public:
	operator IDesignerSelections*(void) { return (IDesignerSelections*)&__IDesignerSelections; }
	
};


#pragma option push -b-
enum TEditAction { eaUndo, eaRedo, eaCut, eaCopy, eaPaste, eaDelete, eaSelectAll, eaPrint, eaBringToFront, eaSendToBack, eaAlignToGrid, eaFlipChildrenAll, eaFlipChildrenSelected };
#pragma option pop

#pragma option push -b-
enum TEditStates { esCanUndo, esCanRedo, esCanCut, esCanCopy, esCanPaste, esCanDelete, esCanZOrder, esCanAlignGrid, esCanEditOle, esCanTabOrder, esCanCreationOrder, esCanPrint, esCanSelectAll, esCanCreateTemplate };
#pragma option pop

typedef Set<TEditStates, esCanUndo, esCanCreateTemplate>  TEditState;

__interface IImplementation;
typedef System::DelphiInterface<IImplementation> _di_IImplementation;
__interface INTERFACE_UUID("{F9D448F2-50BC-11D1-9FB5-0020AF3D82DA}") IImplementation  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall GetInstance(void) = 0 ;
};

__interface IEditHandler;
typedef System::DelphiInterface<IEditHandler> _di_IEditHandler;
__interface INTERFACE_UUID("{7ED7BF2D-E349-11D3-AB4A-00C04FB17A72}") IEditHandler  : public IInterface 
{
	
public:
	virtual bool __fastcall EditAction(TEditAction Action) = 0 ;
	virtual TEditState __fastcall GetEditState(void) = 0 ;
};

typedef IEditHandler IDesignEditQuery;
;

class DELPHICLASS TDragTarget;
class PASCALIMPLEMENTATION TDragTarget : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	_di_IDesigner FDesigner;
	
public:
	__fastcall virtual TDragTarget(const _di_IDesigner ADesigner);
	virtual bool __fastcall DragOver(System::TObject* Target, System::TObject* Source, int X, int Y, Controls::TDragState State) = 0 ;
	virtual void __fastcall DragDrop(System::TObject* Target, System::TObject* Source, int X, int Y) = 0 ;
	__property _di_IDesigner Designer = {read=FDesigner};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDragTarget(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TDragTargetClass;

typedef void __fastcall (*TRegisterDragTargetProc)(const AnsiString SourceName, TMetaClass* TargetClass);

typedef void __fastcall (*TRegisterDesignDragObject)(TMetaClass* DragObjectClass);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TRegisterDesignNotification RegisterDesignNotificationProc;
extern PACKAGE TRegisterDesignNotification UnregisterDesignNotificationProc;
extern PACKAGE TRegisterPropertyEditorProc RegisterPropertyEditorProc;
extern PACKAGE TSetPropertyEditorGroupProc SetPropertyEditorGroupProc;
extern PACKAGE System::ResourceString _sActionCategoryName;
#define Designintf_sActionCategoryName System::LoadResourceString(&Designintf::_sActionCategoryName)
extern PACKAGE System::ResourceString _sDataCategoryName;
#define Designintf_sDataCategoryName System::LoadResourceString(&Designintf::_sDataCategoryName)
extern PACKAGE System::ResourceString _sDatabaseCategoryName;
#define Designintf_sDatabaseCategoryName System::LoadResourceString(&Designintf::_sDatabaseCategoryName)
extern PACKAGE System::ResourceString _sDragNDropCategoryName;
#define Designintf_sDragNDropCategoryName System::LoadResourceString(&Designintf::_sDragNDropCategoryName)
extern PACKAGE System::ResourceString _sHelpCategoryName;
#define Designintf_sHelpCategoryName System::LoadResourceString(&Designintf::_sHelpCategoryName)
extern PACKAGE System::ResourceString _sLayoutCategoryName;
#define Designintf_sLayoutCategoryName System::LoadResourceString(&Designintf::_sLayoutCategoryName)
extern PACKAGE System::ResourceString _sLegacyCategoryName;
#define Designintf_sLegacyCategoryName System::LoadResourceString(&Designintf::_sLegacyCategoryName)
extern PACKAGE System::ResourceString _sLinkageCategoryName;
#define Designintf_sLinkageCategoryName System::LoadResourceString(&Designintf::_sLinkageCategoryName)
extern PACKAGE System::ResourceString _sLocaleCategoryName;
#define Designintf_sLocaleCategoryName System::LoadResourceString(&Designintf::_sLocaleCategoryName)
extern PACKAGE System::ResourceString _sLocalizableCategoryName;
#define Designintf_sLocalizableCategoryName System::LoadResourceString(&Designintf::_sLocalizableCategoryName)
extern PACKAGE System::ResourceString _sMiscellaneousCategoryName;
#define Designintf_sMiscellaneousCategoryName System::LoadResourceString(&Designintf::_sMiscellaneousCategoryName)
extern PACKAGE System::ResourceString _sVisualCategoryName;
#define Designintf_sVisualCategoryName System::LoadResourceString(&Designintf::_sVisualCategoryName)
extern PACKAGE System::ResourceString _sInputCategoryName;
#define Designintf_sInputCategoryName System::LoadResourceString(&Designintf::_sInputCategoryName)
extern PACKAGE TRegisterPropertyInCategoryProc RegisterPropertyInCategoryProc;
extern PACKAGE System::ResourceString _sInvalidFilter;
#define Designintf_sInvalidFilter System::LoadResourceString(&Designintf::_sInvalidFilter)
extern PACKAGE TRegisterPropertyMapperProc RegisterPropertyMapperProc;
extern PACKAGE TRegisterComponentEditorProc RegisterComponentEditorProc;
extern PACKAGE TRegisterSelectionEditorProc RegisterSelectionEditorProc;
extern PACKAGE TRegisterCustomModuleProc RegisterCustomModuleProc;
static const Shortint MaxIdentLength = 0x3f;
extern PACKAGE TRegisterDragTargetProc RegisterDragTargetProc;
extern PACKAGE TRegisterDesignDragObject RegisterDesignDragObjectProc;
extern PACKAGE void __fastcall RegisterPropertyMapper(TPropertyMapperFunc Mapper);
extern PACKAGE void __fastcall RegisterPropertyInCategory(const AnsiString CategoryName, const AnsiString PropertyName)/* overload */;
extern PACKAGE void __fastcall RegisterPropertyInCategory(const AnsiString CategoryName, TMetaClass* ComponentClass, const AnsiString PropertyName)/* overload */;
extern PACKAGE void __fastcall RegisterPropertyInCategory(const AnsiString CategoryName, Typinfo::PTypeInfo PropertyType, const AnsiString PropertyName)/* overload */;
extern PACKAGE void __fastcall RegisterPropertyInCategory(const AnsiString CategoryName, Typinfo::PTypeInfo PropertyType)/* overload */;
extern PACKAGE void __fastcall RegisterPropertiesInCategory(const AnsiString CategoryName, const System::TVarRec * Filters, const int Filters_Size)/* overload */;
extern PACKAGE void __fastcall RegisterPropertiesInCategory(const AnsiString CategoryName, TMetaClass* ComponentClass, const AnsiString * Filters, const int Filters_Size)/* overload */;
extern PACKAGE void __fastcall RegisterPropertiesInCategory(const AnsiString CategoryName, Typinfo::PTypeInfo PropertyType, const AnsiString * Filters, const int Filters_Size)/* overload */;
extern PACKAGE void __fastcall RegisterDesignNotification(const _di_IDesignNotification DesignNotification);
extern PACKAGE void __fastcall UnregisterDesignNotification(const _di_IDesignNotification DesignNotification);
extern PACKAGE void __fastcall RegisterComponentEditor(TMetaClass* ComponentClass, TMetaClass* ComponentEditor);
extern PACKAGE _di_IDesignerSelections __fastcall CreateSelectionList();
extern PACKAGE void __fastcall RegisterPropertyEditor(Typinfo::PTypeInfo PropertyType, TMetaClass* ComponentClass, const AnsiString PropertyName, TMetaClass* EditorClass);
extern PACKAGE void __fastcall SetPropertyEditorGroup(TMetaClass* EditorClass, TMetaClass* GroupClass);
extern PACKAGE void __fastcall UnlistPublishedProperty(TMetaClass* ComponentClass, const AnsiString PropertyName);
extern PACKAGE void __fastcall RegisterSelectionEditor(TMetaClass* AClass, TMetaClass* AEditor);
extern PACKAGE void __fastcall RegisterCustomModule(TMetaClass* ComponentBaseClass, TMetaClass* CustomModuleClass);
extern PACKAGE void __fastcall RegisterDragTarget(const AnsiString SourceName, TMetaClass* TargetClass);
extern PACKAGE void __fastcall RegisterDesignDragObject(TMetaClass* DragObjectClass);

}	/* namespace Designintf */
using namespace Designintf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DesignIntf
