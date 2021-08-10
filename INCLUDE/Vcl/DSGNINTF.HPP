// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DsgnIntf.pas' rev: 5.00

#ifndef DsgnIntfHPP
#define DsgnIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <IniFiles.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dsgnintf
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TEditAction { eaUndo, eaRedo, eaCut, eaCopy, eaPaste, eaDelete, eaSelectAll, eaPrint, eaBringToFront, 
	eaSendToBack, eaAlignToGrid, eaFlipChildrenAll, eaFlipChildrenSelected };
#pragma option pop

#pragma option push -b-
enum DsgnIntf__1 { esCanUndo, esCanRedo, esCanCut, esCanCopy, esCanPaste, esCanDelete, esCanZOrder, 
	esCanAlignGrid, esCanEditOle, esCanTabOrder, esCanCreationOrder, esCanPrint, esCanSelectAll };
#pragma option pop

typedef Set<DsgnIntf__1, esCanUndo, esCanSelectAll>  TEditState;

__interface IEventInfos;
typedef System::DelphiInterface<IEventInfos> _di_IEventInfos;
__interface INTERFACE_UUID("{11667FF0-7590-11D1-9FBC-0020AF3D82DA}") IEventInfos  : public IUnknown 
	
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual AnsiString __fastcall GetEventValue(int Index) = 0 ;
	virtual AnsiString __fastcall GetEventName(int Index) = 0 ;
	virtual void __fastcall ClearEvent(int Index) = 0 ;
	__property int Count = {read=GetCount};
};

__interface IPersistent;
typedef System::DelphiInterface<IPersistent> _di_IPersistent;
__interface INTERFACE_UUID("{82330133-65D1-11D1-9FBB-0020AF3D82DA}") IPersistent  : public IUnknown 
	
{
	
public:
	virtual void __fastcall DestroyObject(void) = 0 ;
	virtual bool __fastcall Equals(const _di_IPersistent Other) = 0 ;
	virtual AnsiString __fastcall GetClassname(void) = 0 ;
	virtual _di_IEventInfos __fastcall GetEventInfos(void) = 0 ;
	virtual AnsiString __fastcall GetNamePath(void) = 0 ;
	virtual _di_IPersistent __fastcall GetOwner(void) = 0 ;
	virtual bool __fastcall InheritsFrom(const AnsiString Classname) = 0 ;
	virtual bool __fastcall IsComponent(void) = 0 ;
	virtual bool __fastcall IsControl(void) = 0 ;
	virtual bool __fastcall IsWinControl(void) = 0 ;
	__property AnsiString Classname = {read=GetClassname};
	__property _di_IPersistent Owner = {read=GetOwner};
	__property AnsiString NamePath = {read=GetNamePath};
	__property _di_IEventInfos EventInfos = {read=GetEventInfos};
};

__interface IComponent;
typedef System::DelphiInterface<IComponent> _di_IComponent;
__interface INTERFACE_UUID("{B2F6D681-5098-11D1-9FB5-0020AF3D82DA}") IComponent  : public IPersistent 
	
{
	
public:
	virtual _di_IComponent __fastcall FindComponent(const AnsiString Name) = 0 ;
	virtual int __fastcall GetComponentCount(void) = 0 ;
	virtual _di_IComponent __fastcall GetComponents(int Index) = 0 ;
	virtual Classes::TComponentState __fastcall GetComponentState(void) = 0 ;
	virtual Classes::TComponentStyle __fastcall GetComponentStyle(void) = 0 ;
	virtual Windows::TSmallPoint __fastcall GetDesignInfo(void) = 0 ;
	virtual Windows::TPoint __fastcall GetDesignOffset(void) = 0 ;
	virtual Windows::TPoint __fastcall GetDesignSize(void) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	HIDESBASE virtual _di_IComponent __fastcall GetOwner(void) = 0 ;
	virtual _di_IComponent __fastcall GetParent(void) = 0 ;
	virtual void __fastcall SetDesignInfo(const Windows::TSmallPoint Point) = 0 ;
	virtual void __fastcall SetDesignOffset(const Windows::TPoint &Point) = 0 ;
	virtual void __fastcall SetDesignSize(const Windows::TPoint &Point) = 0 ;
	virtual void __fastcall SetName(const AnsiString Value) = 0 ;
	__property int ComponentCount = {read=GetComponentCount};
	__property _di_IComponent Components[int Index] = {read=GetComponents};
	__property Classes::TComponentState ComponentState = {read=GetComponentState};
	__property Classes::TComponentStyle ComponentStyle = {read=GetComponentStyle};
	__property Windows::TSmallPoint DesignInfo = {read=GetDesignInfo, write=SetDesignInfo};
	__property Windows::TPoint DesignOffset = {read=GetDesignOffset, write=SetDesignOffset};
	__property Windows::TPoint DesignSize = {read=GetDesignSize, write=SetDesignSize};
	__property AnsiString Name = {read=GetName, write=SetName};
	__property _di_IComponent Owner = {read=GetOwner};
	__property _di_IComponent Parent = {read=GetParent};
};

__interface IImplementation;
typedef System::DelphiInterface<IImplementation> _di_IImplementation;
__interface INTERFACE_UUID("{F9D448F2-50BC-11D1-9FB5-0020AF3D82DA}") IImplementation  : public IUnknown 
	
{
	
public:
	virtual System::TObject* __fastcall GetInstance(void) = 0 ;
};

__interface IDesignerSelections;
typedef System::DelphiInterface<IDesignerSelections> _di_IDesignerSelections;
__interface INTERFACE_UUID("{82330134-65D1-11D1-9FBB-0020AF3D82DA}") IDesignerSelections  : public IUnknown 
	
{
	
public:
	virtual int __fastcall Add(const _di_IPersistent Item) = 0 ;
	virtual bool __fastcall Equals(const _di_IDesignerSelections List) = 0 ;
	virtual _di_IPersistent __fastcall Get(int Index) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IPersistent Items[int Index] = {read=Get/*, default*/};
};

__interface IComponentList;
typedef System::DelphiInterface<IComponentList> _di_IComponentList;
class DELPHICLASS TDesignerSelectionList;
__interface INTERFACE_UUID("{8ED8AD16-A241-11D1-AA94-00C04FB17A72}") IComponentList  : public IUnknown 
	
{
	
public:
	virtual TDesignerSelectionList* __fastcall GetComponentList(void) = 0 ;
};

class PASCALIMPLEMENTATION TDesignerSelectionList : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TList* FList;
	int __fastcall Intf_Add(const _di_IPersistent Item);
	bool __fastcall Intf_Equals(const _di_IDesignerSelections List);
	_di_IPersistent __fastcall Intf_Get(int Index);
	Classes::TPersistent* __fastcall Get(int Index);
	int __fastcall GetCount(void);
	TDesignerSelectionList* __fastcall GetComponentList(void);
	
public:
	__fastcall TDesignerSelectionList(void);
	__fastcall virtual ~TDesignerSelectionList(void);
	int __fastcall Add(Classes::TPersistent* Item);
	bool __fastcall Equals(TDesignerSelectionList* List);
	__property int Count = {read=GetCount, nodefault};
	__property Classes::TPersistent* Items[int Index] = {read=Get/*, default*/};
private:
	void *__IDesignerSelections;	/* Dsgnintf::IDesignerSelections [Get=Intf_Get, Equals=Intf_Equals, Add=Intf_Add
		] */
	void *__IComponentList;	/* Dsgnintf::IComponentList */
	
public:
	operator IComponentList*(void) { return (IComponentList*)&__IComponentList; }
	operator IDesignerSelections*(void) { return (IDesignerSelections*)&__IDesignerSelections; }
	
};


#pragma option push -b-
enum TLocalMenuFilter { lmModule, lmComponent, lmDesigner };
#pragma option pop

typedef Set<TLocalMenuFilter, lmModule, lmDesigner>  TLocalMenuFilters;

__interface IFormDesigner;
typedef System::DelphiInterface<IFormDesigner> _di_IFormDesigner;
__interface INTERFACE_UUID("{ADDD444D-1B03-11D3-A8F8-00C04FA32F53}") IFormDesigner  : public IDesigner 
	
{
	
public:
	virtual Sysutils::TMethod __fastcall CreateMethod(const AnsiString Name, Typinfo::PTypeData TypeData
		) = 0 ;
	virtual AnsiString __fastcall GetMethodName(const Sysutils::TMethod &Method) = 0 ;
	virtual void __fastcall GetMethods(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc) = 0 ;
	virtual AnsiString __fastcall GetPrivateDirectory(void) = 0 ;
	virtual void __fastcall GetSelections(const _di_IDesignerSelections List) = 0 ;
	virtual bool __fastcall MethodExists(const AnsiString Name) = 0 ;
	virtual void __fastcall RenameMethod(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall SelectComponent(Classes::TPersistent* Instance) = 0 ;
	virtual void __fastcall SetSelections(const _di_IDesignerSelections List) = 0 ;
	virtual void __fastcall ShowMethod(const AnsiString Name) = 0 ;
	virtual void __fastcall GetComponentNames(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc) = 0 
		;
	virtual Classes::TComponent* __fastcall GetComponent(const AnsiString Name) = 0 ;
	virtual AnsiString __fastcall GetComponentName(Classes::TComponent* Component) = 0 ;
	virtual Classes::TPersistent* __fastcall GetObject(const AnsiString Name) = 0 ;
	virtual AnsiString __fastcall GetObjectName(Classes::TPersistent* Instance) = 0 ;
	virtual void __fastcall GetObjectNames(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc) = 0 
		;
	virtual bool __fastcall MethodFromAncestor(const Sysutils::TMethod &Method) = 0 ;
	virtual Classes::TComponent* __fastcall CreateComponent(TMetaClass* ComponentClass, Classes::TComponent* 
		Parent, int Left, int Top, int Width, int Height) = 0 ;
	virtual bool __fastcall IsComponentLinkable(Classes::TComponent* Component) = 0 ;
	virtual void __fastcall MakeComponentLinkable(Classes::TComponent* Component) = 0 ;
	virtual void __fastcall Revert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo) = 0 ;
	virtual bool __fastcall GetIsDormant(void) = 0 ;
	virtual bool __fastcall HasInterface(void) = 0 ;
	virtual bool __fastcall HasInterfaceMember(const AnsiString Name) = 0 ;
	virtual void __fastcall AddToInterface(int InvKind, const AnsiString Name, Word VT, const AnsiString 
		TypeInfo) = 0 ;
	virtual void __fastcall GetProjectModules(Classes::TGetModuleProc Proc) = 0 ;
	virtual _di_IFormDesigner __fastcall GetAncestorDesigner(void) = 0 ;
	virtual bool __fastcall IsSourceReadOnly(void) = 0 ;
	virtual Controls::TWinControl* __fastcall GetContainerWindow(void) = 0 ;
	virtual void __fastcall SetContainerWindow(const Controls::TWinControl* NewContainer) = 0 ;
	virtual Windows::TPoint __fastcall GetScrollRanges(const Windows::TPoint &ScrollPosition) = 0 ;
	virtual void __fastcall Edit(const _di_IComponent Component) = 0 ;
	virtual Menus::TPopupMenu* __fastcall BuildLocalMenu(Menus::TPopupMenu* Base, TLocalMenuFilters Filter
		) = 0 ;
	virtual void __fastcall ChainCall(const AnsiString MethodName, const AnsiString InstanceName, const 
		AnsiString InstanceMethod, Typinfo::PTypeData TypeData) = 0 ;
	virtual void __fastcall CopySelection(void) = 0 ;
	virtual void __fastcall CutSelection(void) = 0 ;
	virtual bool __fastcall CanPaste(void) = 0 ;
	virtual void __fastcall PasteSelection(void) = 0 ;
	virtual void __fastcall DeleteSelection(void) = 0 ;
	virtual void __fastcall ClearSelection(void) = 0 ;
	virtual void __fastcall NoSelection(void) = 0 ;
	virtual void __fastcall ModuleFileNames(AnsiString &ImplFileName, AnsiString &IntfFileName, AnsiString 
		&FormFileName) = 0 ;
	virtual AnsiString __fastcall GetRootClassName(void) = 0 ;
	__property bool IsDormant = {read=GetIsDormant};
	__property _di_IFormDesigner AncestorDesigner = {read=GetAncestorDesigner};
	__property Controls::TWinControl* ContainerWindow = {read=GetContainerWindow, write=SetContainerWindow
		};
};

__interface IDesignNotification;
typedef System::DelphiInterface<IDesignNotification> _di_IDesignNotification;
__interface INTERFACE_UUID("{3250122F-D336-11D2-B725-00C04FA35D12}") IDesignNotification  : public IUnknown 
	
{
	
public:
	virtual void __fastcall ItemDeleted(const _di_IPersistent AItem) = 0 ;
	virtual void __fastcall ItemInserted(const _di_IPersistent AItem) = 0 ;
	virtual void __fastcall ItemsModified(const _di_IUnknown ADesigner) = 0 ;
	virtual void __fastcall SelectionChanged(const _di_IDesignerSelections ASelection) = 0 ;
	virtual void __fastcall DesignerInitialized(const _di_IUnknown ADesigner) = 0 ;
	virtual void __fastcall DesignerClosed(const _di_IUnknown ADesigner) = 0 ;
};

__interface IDesignerPopulateMenu;
typedef System::DelphiInterface<IDesignerPopulateMenu> _di_IDesignerPopulateMenu;
__interface INTERFACE_UUID("{66C7D913-EC70-11D2-AAD1-00C04FB16FBC}") IDesignerPopulateMenu  : public IUnknown 
	
{
	
public:
	virtual void __fastcall PopulateMenu(const Menus::TPopupMenu* APopupMenu) = 0 ;
};

#pragma option push -b-
enum TPropertyAttribute { paValueList, paSubProperties, paDialog, paMultiSelect, paAutoUpdate, paSortList, 
	paReadOnly, paRevertable, paFullWidthName };
#pragma option pop

typedef Set<TPropertyAttribute, paValueList, paFullWidthName>  TPropertyAttributes;

struct TInstProp
{
	Classes::TPersistent* Instance;
	Typinfo::TPropInfo *PropInfo;
} ;

typedef TInstProp TInstPropList[1024];

typedef TInstProp *PInstPropList;

class DELPHICLASS TPropertyEditor;
typedef void __fastcall (__closure *TGetPropEditProc)(TPropertyEditor* Prop);

class PASCALIMPLEMENTATION TPropertyEditor : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	_di_IFormDesigner FDesigner;
	TInstProp *FPropList;
	int FPropCount;
	AnsiString __fastcall GetPrivateDirectory();
	void __fastcall SetPropEntry(int Index, Classes::TPersistent* AInstance, Typinfo::PPropInfo APropInfo
		);
	
protected:
	__fastcall virtual TPropertyEditor(const _di_IFormDesigner ADesigner, int APropCount);
	Typinfo::PPropInfo __fastcall GetPropInfo(void);
	Extended __fastcall GetFloatValue(void);
	Extended __fastcall GetFloatValueAt(int Index);
	__int64 __fastcall GetInt64Value(void);
	__int64 __fastcall GetInt64ValueAt(int Index);
	Sysutils::TMethod __fastcall GetMethodValue();
	Sysutils::TMethod __fastcall GetMethodValueAt(int Index);
	int __fastcall GetOrdValue(void);
	int __fastcall GetOrdValueAt(int Index);
	AnsiString __fastcall GetStrValue();
	AnsiString __fastcall GetStrValueAt(int Index);
	Variant __fastcall GetVarValue();
	Variant __fastcall GetVarValueAt(int Index);
	void __fastcall Modified(void);
	void __fastcall SetFloatValue(Extended Value);
	void __fastcall SetMethodValue(const Sysutils::TMethod &Value);
	void __fastcall SetInt64Value(__int64 Value);
	void __fastcall SetOrdValue(int Value);
	void __fastcall SetStrValue(const AnsiString Value);
	void __fastcall SetVarValue(const Variant &Value);
	
public:
	__fastcall virtual ~TPropertyEditor(void);
	virtual void __fastcall Activate(void);
	virtual bool __fastcall AllEqual(void);
	virtual bool __fastcall AutoFill(void);
	virtual void __fastcall Edit(void);
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	Classes::TPersistent* __fastcall GetComponent(int Index);
	virtual int __fastcall GetEditLimit(void);
	virtual AnsiString __fastcall GetName();
	virtual void __fastcall GetProperties(TGetPropEditProc Proc);
	Typinfo::PTypeInfo __fastcall GetPropType(void);
	virtual AnsiString __fastcall GetValue();
	AnsiString __fastcall GetVisualValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall Initialize(void);
	void __fastcall Revert(void);
	virtual void __fastcall SetValue(const AnsiString Value);
	bool __fastcall ValueAvailable(void);
	DYNAMIC void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth
		);
	DYNAMIC void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &
		AHeight);
	DYNAMIC void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Windows::TRect 
		&ARect, bool ASelected);
	DYNAMIC void __fastcall PropDrawName(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, bool 
		ASelected);
	DYNAMIC void __fastcall PropDrawValue(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, bool 
		ASelected);
	__property _di_IFormDesigner Designer = {read=FDesigner};
	__property AnsiString PrivateDirectory = {read=GetPrivateDirectory};
	__property int PropCount = {read=FPropCount, nodefault};
	__property AnsiString Value = {read=GetValue, write=SetValue};
};


typedef TMetaClass*TPropertyEditorClass;

class DELPHICLASS TOrdinalProperty;
class PASCALIMPLEMENTATION TOrdinalProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual int __fastcall GetEditLimit(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOrdinalProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TOrdinalProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIntegerProperty;
class PASCALIMPLEMENTATION TIntegerProperty : public TOrdinalProperty 
{
	typedef TOrdinalProperty inherited;
	
public:
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TIntegerProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TIntegerProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCharProperty;
class PASCALIMPLEMENTATION TCharProperty : public TOrdinalProperty 
{
	typedef TOrdinalProperty inherited;
	
public:
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TCharProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TCharProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEnumProperty;
class PASCALIMPLEMENTATION TEnumProperty : public TOrdinalProperty 
{
	typedef TOrdinalProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TEnumProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TEnumProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBoolProperty;
class PASCALIMPLEMENTATION TBoolProperty : public TEnumProperty 
{
	typedef TEnumProperty inherited;
	
public:
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TBoolProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TEnumProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TBoolProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TInt64Property;
class PASCALIMPLEMENTATION TInt64Property : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual int __fastcall GetEditLimit(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TInt64Property(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TInt64Property(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFloatProperty;
class PASCALIMPLEMENTATION TFloatProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFloatProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFloatProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStringProperty;
class PASCALIMPLEMENTATION TStringProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual int __fastcall GetEditLimit(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TStringProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TStringProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TNestedProperty;
class PASCALIMPLEMENTATION TNestedProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	__fastcall TNestedProperty(TPropertyEditor* Parent);
	__fastcall virtual ~TNestedProperty(void);
};


class DELPHICLASS TSetElementProperty;
class PASCALIMPLEMENTATION TSetElementProperty : public TNestedProperty 
{
	typedef TNestedProperty inherited;
	
private:
	int FElement;
	
protected:
	__fastcall TSetElementProperty(TPropertyEditor* Parent, int AElement);
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetName();
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TNestedProperty.Destroy */ inline __fastcall virtual ~TSetElementProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSetProperty;
class PASCALIMPLEMENTATION TSetProperty : public TOrdinalProperty 
{
	typedef TOrdinalProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(TGetPropEditProc Proc);
	virtual AnsiString __fastcall GetValue();
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TSetProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TSetProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TClassProperty;
class PASCALIMPLEMENTATION TClassProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(TGetPropEditProc Proc);
	virtual AnsiString __fastcall GetValue();
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TClassProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TClassProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMethodProperty;
class PASCALIMPLEMENTATION TMethodProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual void __fastcall Edit(void);
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual int __fastcall GetEditLimit(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString AValue);
	virtual AnsiString __fastcall GetFormMethodName();
	AnsiString __fastcall GetTrimmedEventName();
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TMethodProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TMethodProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComponentProperty;
class PASCALIMPLEMENTATION TComponentProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual int __fastcall GetEditLimit(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TComponentProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TComponentProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComponentNameProperty;
class PASCALIMPLEMENTATION TComponentNameProperty : public TStringProperty 
{
	typedef TStringProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual int __fastcall GetEditLimit(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TComponentNameProperty(const _di_IFormDesigner 
		ADesigner, int APropCount) : TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TComponentNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFontNameProperty;
class PASCALIMPLEMENTATION TFontNameProperty : public TStringProperty 
{
	typedef TStringProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	DYNAMIC void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &
		AHeight);
	DYNAMIC void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth
		);
	DYNAMIC void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Windows::TRect 
		&ARect, bool ASelected);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFontNameProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFontNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFontCharsetProperty;
class PASCALIMPLEMENTATION TFontCharsetProperty : public TIntegerProperty 
{
	typedef TIntegerProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFontCharsetProperty(const _di_IFormDesigner 
		ADesigner, int APropCount) : TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFontCharsetProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TImeNameProperty;
class PASCALIMPLEMENTATION TImeNameProperty : public TStringProperty 
{
	typedef TStringProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TImeNameProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TImeNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TColorProperty;
class PASCALIMPLEMENTATION TColorProperty : public TIntegerProperty 
{
	typedef TIntegerProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
	DYNAMIC void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth
		);
	DYNAMIC void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Windows::TRect 
		&ARect, bool ASelected);
	DYNAMIC void __fastcall PropDrawValue(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, bool 
		ASelected);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TColorProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TColorProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBrushStyleProperty;
class PASCALIMPLEMENTATION TBrushStyleProperty : public TEnumProperty 
{
	typedef TEnumProperty inherited;
	
public:
	DYNAMIC void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth
		);
	DYNAMIC void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Windows::TRect 
		&ARect, bool ASelected);
	DYNAMIC void __fastcall PropDrawValue(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, bool 
		ASelected);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TBrushStyleProperty(const _di_IFormDesigner 
		ADesigner, int APropCount) : TEnumProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TBrushStyleProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPenStyleProperty;
class PASCALIMPLEMENTATION TPenStyleProperty : public TEnumProperty 
{
	typedef TEnumProperty inherited;
	
public:
	DYNAMIC void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth
		);
	DYNAMIC void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Windows::TRect 
		&ARect, bool ASelected);
	DYNAMIC void __fastcall PropDrawValue(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, bool 
		ASelected);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TPenStyleProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TEnumProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TPenStyleProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCursorProperty;
class PASCALIMPLEMENTATION TCursorProperty : public TIntegerProperty 
{
	typedef TIntegerProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
	DYNAMIC void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &
		AHeight);
	DYNAMIC void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth
		);
	DYNAMIC void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Windows::TRect 
		&ARect, bool ASelected);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TCursorProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TCursorProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFontProperty;
class PASCALIMPLEMENTATION TFontProperty : public TClassProperty 
{
	typedef TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual TPropertyAttributes __fastcall GetAttributes(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFontProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFontProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TModalResultProperty;
class PASCALIMPLEMENTATION TModalResultProperty : public TIntegerProperty 
{
	typedef TIntegerProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TModalResultProperty(const _di_IFormDesigner 
		ADesigner, int APropCount) : TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TModalResultProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TShortCutProperty;
class PASCALIMPLEMENTATION TShortCutProperty : public TOrdinalProperty 
{
	typedef TOrdinalProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TShortCutProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TShortCutProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMPFilenameProperty;
class PASCALIMPLEMENTATION TMPFilenameProperty : public TStringProperty 
{
	typedef TStringProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual TPropertyAttributes __fastcall GetAttributes(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TMPFilenameProperty(const _di_IFormDesigner 
		ADesigner, int APropCount) : TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TMPFilenameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTabOrderProperty;
class PASCALIMPLEMENTATION TTabOrderProperty : public TIntegerProperty 
{
	typedef TIntegerProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TTabOrderProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TTabOrderProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCaptionProperty;
class PASCALIMPLEMENTATION TCaptionProperty : public TStringProperty 
{
	typedef TStringProperty inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TCaptionProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TCaptionProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDateProperty;
class PASCALIMPLEMENTATION TDateProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TDateProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDateProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTimeProperty;
class PASCALIMPLEMENTATION TTimeProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TTimeProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TTimeProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDateTimeProperty;
class PASCALIMPLEMENTATION TDateTimeProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TDateTimeProperty(const _di_IFormDesigner ADesigner
		, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDateTimeProperty(void) { }
	#pragma option pop
	
};


__interface IComponentEditor;
typedef System::DelphiInterface<IComponentEditor> _di_IComponentEditor;
__interface INTERFACE_UUID("{ABBE7252-5495-11D1-9FB5-0020AF3D82DA}") IComponentEditor  : public IUnknown 
	
{
	
public:
	virtual void __fastcall Edit(void) = 0 ;
	virtual void __fastcall ExecuteVerb(int Index) = 0 ;
	virtual _di_IComponent __fastcall GetIComponent(void) = 0 ;
	virtual _di_IFormDesigner __fastcall GetDesigner(void) = 0 ;
	virtual AnsiString __fastcall GetVerb(int Index) = 0 ;
	virtual int __fastcall GetVerbCount(void) = 0 ;
	virtual void __fastcall PrepareItem(int Index, const Menus::TMenuItem* AItem) = 0 ;
	virtual void __fastcall Copy(void) = 0 ;
};

class DELPHICLASS TComponentEditor;
class PASCALIMPLEMENTATION TComponentEditor : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TComponent* FComponent;
	_di_IFormDesigner FDesigner;
	
public:
	__fastcall virtual TComponentEditor(Classes::TComponent* AComponent, _di_IFormDesigner ADesigner);
	virtual void __fastcall Edit(void);
	virtual void __fastcall ExecuteVerb(int Index);
	_di_IComponent __fastcall GetIComponent();
	_di_IFormDesigner __fastcall GetDesigner();
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	bool __fastcall IsInInlined(void);
	virtual void __fastcall PrepareItem(int Index, const Menus::TMenuItem* AItem);
	virtual void __fastcall Copy(void);
	__property Classes::TComponent* Component = {read=FComponent};
	__property _di_IFormDesigner Designer = {read=GetDesigner};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TComponentEditor(void) { }
	#pragma option pop
	
private:
	void *__IComponentEditor;	/* Dsgnintf::IComponentEditor */
	
public:
	operator IComponentEditor*(void) { return (IComponentEditor*)&__IComponentEditor; }
	
};


typedef TMetaClass*TComponentEditorClass;

__interface IDefaultEditor;
typedef System::DelphiInterface<IDefaultEditor> _di_IDefaultEditor;
__interface INTERFACE_UUID("{5484FAE1-5C60-11D1-9FB6-0020AF3D82DA}") IDefaultEditor  : public IComponentEditor 
	
{
	
};

class DELPHICLASS TDefaultEditor;
class PASCALIMPLEMENTATION TDefaultEditor : public TComponentEditor 
{
	typedef TComponentEditor inherited;
	
private:
	TPropertyEditor* FFirst;
	TPropertyEditor* FBest;
	bool FContinue;
	void __fastcall CheckEdit(TPropertyEditor* PropertyEditor);
	
protected:
	virtual void __fastcall EditProperty(TPropertyEditor* PropertyEditor, bool &Continue, bool &FreeEditor
		);
	
public:
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TDefaultEditor(Classes::TComponent* AComponent
		, _di_IFormDesigner ADesigner) : TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDefaultEditor(void) { }
	#pragma option pop
	
private:
	void *__IDefaultEditor;	/* Dsgnintf::IDefaultEditor */
	
public:
	operator IDefaultEditor*(void) { return (IDefaultEditor*)&__IDefaultEditor; }
	
};


typedef void __fastcall (*TFreeCustomModulesProc)(int Group);

typedef TMetaClass* __fastcall (*TPropertyMapperFunc)(Classes::TPersistent* Obj, Typinfo::PPropInfo 
	PropInfo);

#pragma option push -b-
enum TCustomModuleAttribute { cmaVirtualSize };
#pragma option pop

typedef Set<TCustomModuleAttribute, cmaVirtualSize, cmaVirtualSize>  TCustomModuleAttributes;

class DELPHICLASS TCustomModule;
class PASCALIMPLEMENTATION TCustomModule : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	_di_IComponent FRoot;
	
public:
	__fastcall virtual TCustomModule(_di_IComponent ARoot);
	virtual void __fastcall ExecuteVerb(int Index);
	virtual Forms::TCustomForm* __fastcall CreateDesignerForm(Forms::_di_IDesigner Designer);
	virtual TCustomModuleAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual void __fastcall PrepareItem(int Index, const Menus::TMenuItem* AItem);
	virtual void __fastcall Saving(void);
	virtual void __fastcall ValidateComponent(_di_IComponent Component);
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall Nestable() { return Nestable(__classid(TCustomModule)
		); }
	#pragma option pop
	/*         class method */ static bool __fastcall Nestable(TMetaClass* vmt);
	__property _di_IComponent Root = {read=FRoot};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCustomModule(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TCustomModuleClass;

typedef void __fastcall (*TRegisterCustomModuleProc)(int Group, TMetaClass* ComponentBaseClass, TMetaClass* 
	CustomModuleClass);

__interface ICustomModuleSettings;
typedef System::DelphiInterface<ICustomModuleSettings> _di_ICustomModuleSettings;
__interface INTERFACE_UUID("{50947DAD-E627-11D2-B728-00C04FA35D12}") ICustomModuleSettings  : public IUnknown 
	
{
	
public:
	virtual AnsiString __fastcall IniSection(void) = 0 ;
};

__interface ICustomModuleProjectSettings;
typedef System::DelphiInterface<ICustomModuleProjectSettings> _di_ICustomModuleProjectSettings;
__interface INTERFACE_UUID("{78E12CC2-DBCC-11D2-B727-00C04FA35D12}") ICustomModuleProjectSettings  : public ICustomModuleSettings 
	
{
	
public:
	virtual void __fastcall SaveProjectState(Inifiles::TMemIniFile* AFile) = 0 ;
	virtual void __fastcall LoadProjectState(Inifiles::TMemIniFile* AFile) = 0 ;
};

__interface ICustomModuleUnitSettings;
typedef System::DelphiInterface<ICustomModuleUnitSettings> _di_ICustomModuleUnitSettings;
__interface INTERFACE_UUID("{78E12CC1-DBCC-11D2-B727-00C04FA35D12}") ICustomModuleUnitSettings  : public ICustomModuleSettings 
	
{
	
public:
	virtual void __fastcall SaveUnitState(Inifiles::TMemIniFile* AFile) = 0 ;
	virtual void __fastcall LoadUnitState(Inifiles::TMemIniFile* AFile) = 0 ;
};

__interface IDesignerPersistence;
typedef System::DelphiInterface<IDesignerPersistence> _di_IDesignerPersistence;
__interface INTERFACE_UUID("{D32194C2-EECF-11D2-AAD2-00C04FB16FBC}") IDesignerPersistence  : public IUnknown 
	
{
	
public:
	virtual void __fastcall Save(const _di_IStream Stream) = 0 ;
	virtual void __fastcall Load(const _di_IStream Stream) = 0 ;
};

typedef void __fastcall (*TGroupChangeProc)(int AGroup);

class DELPHICLASS TPropertyFilter;
class PASCALIMPLEMENTATION TPropertyFilter : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Masks::TMask* FMask;
	TMetaClass*FComponentClass;
	Typinfo::TTypeInfo *FPropertyType;
	int FGroup;
	
public:
	__fastcall TPropertyFilter(const AnsiString APropertyName, TMetaClass* AComponentClass, Typinfo::PTypeInfo 
		APropertyType);
	__fastcall virtual ~TPropertyFilter(void);
	bool __fastcall Match(const AnsiString APropertyName, TMetaClass* AComponentClass, Typinfo::PTypeInfo 
		APropertyType);
	__property TMetaClass* ComponentClass = {read=FComponentClass};
	__property Typinfo::PTypeInfo PropertyType = {read=FPropertyType};
};


typedef TMetaClass*TPropertyCategoryClass;

class DELPHICLASS TPropertyCategory;
class PASCALIMPLEMENTATION TPropertyCategory : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Contnrs::TObjectList* FList;
	int FMatchCount;
	TPropertyEditor* FEditor;
	bool FEnabled;
	bool FVisible;
	int FGroup;
	
protected:
	TPropertyFilter* __fastcall GetFilter(int Index);
	
public:
	__fastcall TPropertyCategory(void);
	__fastcall virtual ~TPropertyCategory(void);
	TPropertyFilter* __fastcall Add(TPropertyFilter* AFilter);
	int __fastcall Count(void);
	bool __fastcall Match(const AnsiString APropertyName, TMetaClass* AComponentClass, Typinfo::PTypeInfo 
		APropertyType);
	void __fastcall ClearMatches(void);
	void __fastcall FreeEditorGroup(int AGroup);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TPropertyCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TPropertyCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
	DYNAMIC void __fastcall PropDraw(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, bool ASelected
		);
	__property TPropertyFilter* Filters[int Index] = {read=GetFilter};
	__property int MatchCount = {read=FMatchCount, nodefault};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
	__property TPropertyEditor* Editor = {read=FEditor, write=FEditor};
};


#pragma option push -b-
enum TPropertyCategoryVisibleMode { pcvAll, pcvToggle, pcvNone, pcvNotListed, pcvOnlyListed };
#pragma option pop

class DELPHICLASS TPropertyCategoryList;
class PASCALIMPLEMENTATION TPropertyCategoryList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Contnrs::TObjectList* FList;
	TPropertyCategory* FMiscCategory;
	
protected:
	TPropertyCategory* __fastcall GetCategory(int Index);
	AnsiString __fastcall GetHiddenCategories();
	void __fastcall SetHiddenCategories(const AnsiString Value);
	
public:
	__fastcall TPropertyCategoryList(void);
	__fastcall virtual ~TPropertyCategoryList(void);
	TPropertyCategory* __fastcall FindCategory(TMetaClass* ACategoryClass);
	int __fastcall IndexOf(TMetaClass* ACategoryClass)/* overload */;
	int __fastcall IndexOf(const AnsiString ACategoryName)/* overload */;
	void __fastcall ClearMatches(void);
	void __fastcall FreeEditorGroup(int AGroup);
	TPropertyCategory* __fastcall MiscCategory(void);
	int __fastcall Count(void);
	bool __fastcall Match(const AnsiString APropertyName, TMetaClass* AComponentClass, Typinfo::PTypeInfo 
		APropertyType);
	bool __fastcall ChangeVisibility(TPropertyCategoryVisibleMode AMode)/* overload */;
	bool __fastcall ChangeVisibility(TPropertyCategoryVisibleMode AMode, TMetaClass* const * AClasses, 
		const int AClasses_Size)/* overload */;
	__property AnsiString HiddenCategories = {read=GetHiddenCategories, write=SetHiddenCategories};
	__property TPropertyCategory* Categories[int Index] = {read=GetCategory/*, default*/};
};


class DELPHICLASS TActionCategory;
class PASCALIMPLEMENTATION TActionCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TActionCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TActionCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TActionCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TActionCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataCategory;
class PASCALIMPLEMENTATION TDataCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TDataCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TDataCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TDataCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TDataCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDatabaseCategory;
class PASCALIMPLEMENTATION TDatabaseCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TDatabaseCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TDatabaseCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TDatabaseCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TDatabaseCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDragNDropCategory;
class PASCALIMPLEMENTATION TDragNDropCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TDragNDropCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TDragNDropCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TDragNDropCategory(void) : TPropertyCategory() { }
		
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TDragNDropCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpCategory;
class PASCALIMPLEMENTATION THelpCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(THelpCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(THelpCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall THelpCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~THelpCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLayoutCategory;
class PASCALIMPLEMENTATION TLayoutCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TLayoutCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TLayoutCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TLayoutCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TLayoutCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLegacyCategory;
class PASCALIMPLEMENTATION TLegacyCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TLegacyCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TLegacyCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TLegacyCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TLegacyCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLinkageCategory;
class PASCALIMPLEMENTATION TLinkageCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TLinkageCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TLinkageCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TLinkageCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TLinkageCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLocaleCategory;
class PASCALIMPLEMENTATION TLocaleCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TLocaleCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TLocaleCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TLocaleCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TLocaleCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLocalizableCategory;
class PASCALIMPLEMENTATION TLocalizableCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TLocalizableCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TLocalizableCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TLocalizableCategory(void) : TPropertyCategory() { }
		
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TLocalizableCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMiscellaneousCategory;
class PASCALIMPLEMENTATION TMiscellaneousCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TMiscellaneousCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TMiscellaneousCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TMiscellaneousCategory(void) : TPropertyCategory()
		 { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TMiscellaneousCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TVisualCategory;
class PASCALIMPLEMENTATION TVisualCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TVisualCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TVisualCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TVisualCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TVisualCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TInputCategory;
class PASCALIMPLEMENTATION TInputCategory : public TPropertyCategory 
{
	typedef TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TInputCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TInputCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TInputCategory(void) : TPropertyCategory() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TInputCategory(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE _di_IPersistent __fastcall (*MakeIPersistentProc)(Classes::TPersistent* Instance);
extern PACKAGE _di_IComponent __fastcall (*MakeIComponentProc)(Classes::TComponent* Instance);
#define cNoLocalMenus (System::Set<TLocalMenuFilter, lmModule, lmDesigner> () )
#define cAllLocalMenus EMPTYSET
extern PACKAGE TLocalMenuFilters cLocalMenusIf[2];
extern PACKAGE bool FontNamePropertyDisplayFontNames;
extern PACKAGE TFreeCustomModulesProc FreeCustomModulesProc;
extern PACKAGE TRegisterCustomModuleProc RegisterCustomModuleProc;
extern PACKAGE Byte MaxIdentLength;
extern PACKAGE AnsiString BaseRegistryKey;
extern PACKAGE void __fastcall RegisterPropertyEditor(Typinfo::PTypeInfo PropertyType, TMetaClass* ComponentClass
	, const AnsiString PropertyName, TMetaClass* EditorClass);
extern PACKAGE void __fastcall RegisterPropertyMapper(TPropertyMapperFunc Mapper);
extern PACKAGE void __fastcall GetComponentProperties(TDesignerSelectionList* Components, Typinfo::TTypeKinds 
	Filter, _di_IFormDesigner Designer, TGetPropEditProc Proc);
extern PACKAGE void __fastcall RegisterComponentEditor(TMetaClass* ComponentClass, TMetaClass* ComponentEditor
	);
extern PACKAGE TComponentEditor* __fastcall GetComponentEditor(Classes::TComponent* Component, _di_IFormDesigner 
	Designer);
extern PACKAGE int __fastcall NewEditorGroup(void);
extern PACKAGE void __fastcall NotifyGroupChange(TGroupChangeProc AProc);
extern PACKAGE void __fastcall UnNotifyGroupChange(TGroupChangeProc AProc);
extern PACKAGE void __fastcall FreeEditorGroup(int Group);
extern PACKAGE void __fastcall RegisterCustomModule(TMetaClass* ComponentBaseClass, TMetaClass* CustomModuleClass
	);
extern PACKAGE _di_IPersistent __fastcall MakeIPersistent(Classes::TPersistent* Instance);
extern PACKAGE Classes::TPersistent* __fastcall ExtractPersistent(const _di_IUnknown Intf);
extern PACKAGE Classes::TPersistent* __fastcall TryExtractPersistent(const _di_IUnknown Intf);
extern PACKAGE _di_IComponent __fastcall MakeIComponent(Classes::TComponent* Instance);
extern PACKAGE Classes::TComponent* __fastcall ExtractComponent(const _di_IUnknown Intf);
extern PACKAGE Classes::TComponent* __fastcall TryExtractComponent(const _di_IUnknown Intf);
extern PACKAGE _di_IDesignerSelections __fastcall CreateSelectionList();
extern PACKAGE TPropertyFilter* __fastcall RegisterPropertyInCategory(TMetaClass* ACategoryClass, const 
	AnsiString APropertyName)/* overload */;
extern PACKAGE TPropertyFilter* __fastcall RegisterPropertyInCategory(TMetaClass* ACategoryClass, TMetaClass* 
	AComponentClass, const AnsiString APropertyName)/* overload */;
extern PACKAGE TPropertyFilter* __fastcall RegisterPropertyInCategory(TMetaClass* ACategoryClass, Typinfo::PTypeInfo 
	APropertyType, const AnsiString APropertyName)/* overload */;
extern PACKAGE TPropertyFilter* __fastcall RegisterPropertyInCategory(TMetaClass* ACategoryClass, Typinfo::PTypeInfo 
	APropertyType)/* overload */;
extern PACKAGE TPropertyCategory* __fastcall RegisterPropertiesInCategory(TMetaClass* ACategoryClass
	, const System::TVarRec * AFilters, const int AFilters_Size)/* overload */;
extern PACKAGE TPropertyCategory* __fastcall RegisterPropertiesInCategory(TMetaClass* ACategoryClass
	, TMetaClass* AComponentClass, const AnsiString * AFilters, const int AFilters_Size)/* overload */;
	
extern PACKAGE TPropertyCategory* __fastcall RegisterPropertiesInCategory(TMetaClass* ACategoryClass
	, Typinfo::PTypeInfo APropertyType, const AnsiString * AFilters, const int AFilters_Size)/* overload */
	;
extern PACKAGE bool __fastcall IsPropertyInCategory(TMetaClass* ACategoryClass, TMetaClass* AComponentClass
	, const AnsiString APropertyName)/* overload */;
extern PACKAGE bool __fastcall IsPropertyInCategory(TMetaClass* ACategoryClass, const AnsiString AClassName
	, const AnsiString APropertyName)/* overload */;
extern PACKAGE TPropertyCategoryList* __fastcall PropertyCategoryList(void);

}	/* namespace Dsgnintf */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dsgnintf;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DsgnIntf
