// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DesignEditors.pas' rev: 6.00

#ifndef DesignEditorsHPP
#define DesignEditorsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DesignMenus.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Designeditors
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 4)
struct TInstProp
{
	Classes::TPersistent* Instance;
	Typinfo::TPropInfo *PropInfo;
} ;
#pragma pack(pop)

typedef TInstProp TInstPropList[1024];

typedef TInstProp *PInstPropList;

class DELPHICLASS TPropertyEditor;
class PASCALIMPLEMENTATION TPropertyEditor : public Designintf::TBasePropertyEditor 
{
	typedef Designintf::TBasePropertyEditor inherited;
	
private:
	Designintf::_di_IDesigner FDesigner;
	TInstProp *FPropList;
	int FPropCount;
	AnsiString __fastcall GetPrivateDirectory();
	
protected:
	virtual void __fastcall SetPropEntry(int Index, Classes::TPersistent* AInstance, Typinfo::PPropInfo APropInfo);
	Extended __fastcall GetFloatValue(void);
	Extended __fastcall GetFloatValueAt(int Index);
	__int64 __fastcall GetInt64Value(void);
	__int64 __fastcall GetInt64ValueAt(int Index);
	System::TMethod __fastcall GetMethodValue();
	System::TMethod __fastcall GetMethodValueAt(int Index);
	int __fastcall GetOrdValue(void);
	int __fastcall GetOrdValueAt(int Index);
	AnsiString __fastcall GetStrValue();
	AnsiString __fastcall GetStrValueAt(int Index);
	Variant __fastcall GetVarValue();
	Variant __fastcall GetVarValueAt(int Index);
	System::_di_IInterface __fastcall GetIntfValue();
	System::_di_IInterface __fastcall GetIntfValueAt(int Index);
	void __fastcall Modified(void);
	void __fastcall SetFloatValue(Extended Value);
	void __fastcall SetMethodValue(const System::TMethod &Value);
	void __fastcall SetInt64Value(__int64 Value);
	void __fastcall SetOrdValue(int Value);
	void __fastcall SetStrValue(const AnsiString Value);
	void __fastcall SetVarValue(const Variant &Value);
	void __fastcall SetIntfValue(const System::_di_IInterface Value);
	bool __fastcall GetEditValue(/* out */ AnsiString &Value);
	bool __fastcall HasInstance(Classes::TPersistent* Instance);
	
public:
	__fastcall virtual TPropertyEditor(const Designintf::_di_IDesigner ADesigner, int APropCount);
	__fastcall virtual ~TPropertyEditor(void);
	virtual void __fastcall Activate(void);
	virtual bool __fastcall AllEqual(void);
	virtual bool __fastcall AutoFill(void);
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	Classes::TPersistent* __fastcall GetComponent(int Index);
	virtual int __fastcall GetEditLimit(void);
	virtual AnsiString __fastcall GetName();
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
	virtual Typinfo::PPropInfo __fastcall GetPropInfo(void);
	Typinfo::PTypeInfo __fastcall GetPropType(void);
	virtual AnsiString __fastcall GetValue();
	AnsiString __fastcall GetVisualValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall Initialize(void);
	void __fastcall Revert(void);
	virtual void __fastcall SetValue(const AnsiString Value);
	bool __fastcall ValueAvailable(void);
	__property Designintf::_di_IDesigner Designer = {read=FDesigner};
	__property AnsiString PrivateDirectory = {read=GetPrivateDirectory};
	__property int PropCount = {read=FPropCount, nodefault};
	__property AnsiString Value = {read=GetValue, write=SetValue};
private:
	void *__IProperty;	/* Designintf::IProperty */
	
public:
	operator IProperty*(void) { return (IProperty*)&__IProperty; }
	
};


class DELPHICLASS TOrdinalProperty;
class PASCALIMPLEMENTATION TOrdinalProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual int __fastcall GetEditLimit(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOrdinalProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
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
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TIntegerProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
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
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TCharProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TCharProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEnumProperty;
class PASCALIMPLEMENTATION TEnumProperty : public TOrdinalProperty 
{
	typedef TOrdinalProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TEnumProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TEnumProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBoolProperty;
class PASCALIMPLEMENTATION TBoolProperty : public TEnumProperty 
{
	typedef TEnumProperty inherited;
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TBoolProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TEnumProperty(ADesigner, APropCount) { }
	#pragma option pop
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
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TInt64Property(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
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
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFloatProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
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
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TStringProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
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
	__property int Element = {read=FElement, nodefault};
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
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
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
	virtual AnsiString __fastcall GetValue();
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TSetProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TSetProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TClassProperty;
class PASCALIMPLEMENTATION TClassProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
	virtual AnsiString __fastcall GetValue();
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TClassProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TClassProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMethodProperty;
class PASCALIMPLEMENTATION TMethodProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllNamed(void);
	virtual bool __fastcall AllEqual(void);
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual int __fastcall GetEditLimit(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString AValue);
	virtual AnsiString __fastcall GetFormMethodName();
	AnsiString __fastcall GetTrimmedEventName();
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TMethodProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TMethodProperty(void) { }
	#pragma option pop
	
private:
	void *__IMethodProperty;	/* Designintf::IMethodProperty */
	
public:
	operator IMethodProperty*(void) { return (IMethodProperty*)&__IMethodProperty; }
	
};


class DELPHICLASS TComponentProperty;
class PASCALIMPLEMENTATION TComponentProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
protected:
	bool __fastcall FilterFunc(const Designintf::_di_IProperty ATestEditor);
	virtual Classes::TComponent* __fastcall GetComponentReference(void);
	virtual Designintf::_di_IDesignerSelections __fastcall GetSelections();
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
	virtual int __fastcall GetEditLimit(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TComponentProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TComponentProperty(void) { }
	#pragma option pop
	
private:
	void *__IReferenceProperty;	/* Designintf::IReferenceProperty */
	
public:
	operator IReferenceProperty*(void) { return (IReferenceProperty*)&__IReferenceProperty; }
	
};


class DELPHICLASS TInterfaceProperty;
class PASCALIMPLEMENTATION TInterfaceProperty : public TComponentProperty 
{
	typedef TComponentProperty inherited;
	
private:
	Classes::TGetStrProc FGetValuesStrProc;
	
protected:
	void __fastcall ReceiveComponentNames(const AnsiString S);
	HIDESBASE Classes::TComponent* __fastcall GetComponent(const System::_di_IInterface AInterface);
	virtual Classes::TComponent* __fastcall GetComponentReference(void);
	virtual Designintf::_di_IDesignerSelections __fastcall GetSelections();
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TInterfaceProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TComponentProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TInterfaceProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComponentNameProperty;
class PASCALIMPLEMENTATION TComponentNameProperty : public TStringProperty 
{
	typedef TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual int __fastcall GetEditLimit(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TComponentNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TComponentNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDateProperty;
class PASCALIMPLEMENTATION TDateProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TDateProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDateProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTimeProperty;
class PASCALIMPLEMENTATION TTimeProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TTimeProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TTimeProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDateTimeProperty;
class PASCALIMPLEMENTATION TDateTimeProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TDateTimeProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDateTimeProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TVariantProperty;
class PASCALIMPLEMENTATION TVariantProperty : public TPropertyEditor 
{
	typedef TPropertyEditor inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TVariantProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TVariantProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComponentEditor;
class PASCALIMPLEMENTATION TComponentEditor : public Designintf::TBaseComponentEditor 
{
	typedef Designintf::TBaseComponentEditor inherited;
	
private:
	Classes::TComponent* FComponent;
	Designintf::_di_IDesigner FDesigner;
	
public:
	__fastcall virtual TComponentEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner);
	virtual void __fastcall Edit(void);
	virtual void __fastcall ExecuteVerb(int Index);
	Classes::TComponent* __fastcall GetComponent(void);
	Designintf::_di_IDesigner __fastcall GetDesigner();
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	bool __fastcall IsInInlined(void);
	virtual void __fastcall Copy(void);
	virtual void __fastcall PrepareItem(int Index, const Designmenus::_di_IMenuItem AItem);
	__property Classes::TComponent* Component = {read=FComponent};
	__property Designintf::_di_IDesigner Designer = {read=GetDesigner};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TComponentEditor(void) { }
	#pragma option pop
	
private:
	void *__IComponentEditor;	/* Designintf::IComponentEditor */
	
public:
	operator IComponentEditor*(void) { return (IComponentEditor*)&__IComponentEditor; }
	
};


class DELPHICLASS TDefaultEditor;
class PASCALIMPLEMENTATION TDefaultEditor : public TComponentEditor 
{
	typedef TComponentEditor inherited;
	
private:
	Designintf::_di_IProperty FFirst;
	Designintf::_di_IProperty FBest;
	bool FContinue;
	void __fastcall CheckEdit(const Designintf::_di_IProperty Prop);
	
protected:
	virtual void __fastcall EditProperty(const Designintf::_di_IProperty Prop, bool &Continue);
	
public:
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TDefaultEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDefaultEditor(void) { }
	#pragma option pop
	
private:
	void *__IDefaultEditor;	/* Designintf::IDefaultEditor */
	
public:
	operator IDefaultEditor*(void) { return (IDefaultEditor*)&__IDefaultEditor; }
	
};


class DELPHICLASS TSelectionEditor;
class PASCALIMPLEMENTATION TSelectionEditor : public Designintf::TBaseSelectionEditor 
{
	typedef Designintf::TBaseSelectionEditor inherited;
	
private:
	Designintf::_di_IDesigner FDesigner;
	
public:
	__fastcall virtual TSelectionEditor(const Designintf::_di_IDesigner ADesigner);
	virtual void __fastcall ExecuteVerb(int Index, const Designintf::_di_IDesignerSelections List);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual void __fastcall RequiresUnits(Classes::TGetStrProc Proc);
	virtual void __fastcall PrepareItem(int Index, const Designmenus::_di_IMenuItem AItem);
	__property Designintf::_di_IDesigner Designer = {read=FDesigner};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSelectionEditor(void) { }
	#pragma option pop
	
private:
	void *__ISelectionEditor;	/* Designintf::ISelectionEditor */
	
public:
	operator ISelectionEditor*(void) { return (ISelectionEditor*)&__ISelectionEditor; }
	
};


class DELPHICLASS TEditActionSelectionEditor;
class PASCALIMPLEMENTATION TEditActionSelectionEditor : public TSelectionEditor 
{
	typedef TSelectionEditor inherited;
	
private:
	void __fastcall HandleToBack(System::TObject* Sender);
	void __fastcall HandleToFront(System::TObject* Sender);
	
protected:
	Designintf::TEditState __fastcall GetEditState(void);
	void __fastcall EditAction(Designintf::TEditAction Action);
	void __fastcall HandleCopy(System::TObject* Sender);
	void __fastcall HandleCut(System::TObject* Sender);
	void __fastcall HandleDelete(System::TObject* Sender);
	void __fastcall HandlePaste(System::TObject* Sender);
	void __fastcall HandleSelectAll(System::TObject* Sender);
	void __fastcall HandleUndo(System::TObject* Sender);
	
public:
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual void __fastcall PrepareItem(int Index, const Designmenus::_di_IMenuItem AItem);
public:
	#pragma option push -w-inl
	/* TSelectionEditor.Create */ inline __fastcall virtual TEditActionSelectionEditor(const Designintf::_di_IDesigner ADesigner) : TSelectionEditor(ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEditActionSelectionEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomModule;
class PASCALIMPLEMENTATION TCustomModule : public Designintf::TBaseCustomModule 
{
	typedef Designintf::TBaseCustomModule inherited;
	
private:
	Classes::TComponent* FRoot;
	Designintf::_di_IDesigner FDesigner;
	Classes::TClassFinder* FFinder;
	
public:
	__fastcall virtual TCustomModule(Classes::TComponent* ARoot, const Designintf::_di_IDesigner ADesigner);
	__fastcall virtual ~TCustomModule(void);
	virtual void __fastcall ExecuteVerb(int Index);
	virtual Designintf::TCustomModuleAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual void __fastcall Saving(void);
	virtual void __fastcall PrepareItem(int Index, const Designmenus::_di_IMenuItem AItem);
	virtual void __fastcall ValidateComponent(Classes::TComponent* Component);
	virtual bool __fastcall ValidateComponentClass(TMetaClass* ComponentClass);
	virtual bool __fastcall Nestable(void);
	__property Classes::TComponent* Root = {read=FRoot};
	__property Designintf::_di_IDesigner Designer = {read=FDesigner};
private:
	void *__ICustomModule;	/* Designintf::ICustomModule */
	
public:
	operator ICustomModule*(void) { return (ICustomModule*)&__ICustomModule; }
	
};


typedef Classes::TComponent* __fastcall (*TGetTopLevelComponentFunc)(Classes::TComponent* Ignoring = (Classes::TComponent*)(0x0));

typedef void __fastcall (*TGroupChangeProc)(int AGroup);

__interface IDesignGroupChange;
typedef System::DelphiInterface<IDesignGroupChange> _di_IDesignGroupChange;
__interface INTERFACE_UUID("{8B5614E7-A726-4622-B2A7-F79340B1B78E}") IDesignGroupChange  : public IInterface 
{
	
public:
	virtual void __fastcall FreeEditorGroup(int Group) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TGetTopLevelComponentFunc GetTopLevelComponentFunc;
extern PACKAGE System::ResourceString _sClassNotApplicable;
#define Designeditors_sClassNotApplicable System::LoadResourceString(&Designeditors::_sClassNotApplicable)
extern PACKAGE System::ResourceString _sNotAvailable;
#define Designeditors_sNotAvailable System::LoadResourceString(&Designeditors::_sNotAvailable)
extern PACKAGE bool GReferenceExpandable;
extern PACKAGE bool GShowReadOnlyProps;
extern PACKAGE bool __fastcall PossibleStream(const AnsiString S);
extern PACKAGE void __fastcall GetComponentProperties(const Designintf::_di_IDesignerSelections Components, Typinfo::TTypeKinds Filter, const Designintf::_di_IDesigner Designer, Designintf::TGetPropProc Proc, Designintf::TPropertyEditorFilterFunc EditorFilterFunc = 0x0);
extern PACKAGE Designintf::_di_IComponentEditor __fastcall GetComponentEditor(Classes::TComponent* Component, const Designintf::_di_IDesigner Designer);
extern PACKAGE Designintf::_di_ISelectionEditorList __fastcall GetSelectionEditors(const Designintf::_di_IDesigner Designer, const Designintf::_di_IDesignerSelections Selections)/* overload */;
extern PACKAGE Designintf::_di_ISelectionEditorList __fastcall GetSelectionEditors(const Designintf::_di_IDesigner Designer)/* overload */;
extern PACKAGE Designintf::_di_ISelectionEditorList __fastcall GetSelectionEditors(const Designintf::_di_IDesigner Designer, Classes::TComponent* Component)/* overload */;
extern PACKAGE bool __fastcall ClassInheritsFrom(TMetaClass* ClassType, const AnsiString ClassName);
extern PACKAGE bool __fastcall AncestorNameMatches(TMetaClass* ClassType, TMetaClass* AncestorClass);
extern PACKAGE int __fastcall NewEditorGroup(void);
extern PACKAGE void __fastcall NotifyGroupChange(TGroupChangeProc AProc);
extern PACKAGE void __fastcall UnnotifyGroupChange(TGroupChangeProc AProc);
extern PACKAGE void __fastcall FreeEditorGroup(int Group);

}	/* namespace Designeditors */
using namespace Designeditors;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DesignEditors
