// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TreeIntf.pas' rev: 6.00

#ifndef TreeIntfHPP
#define TreeIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ImgList.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <IniFiles.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Treeintf
{
//-- type declarations -------------------------------------------------------
typedef TMetaClass*TSprigClass;

class DELPHICLASS TSprig;
typedef void __fastcall (__closure *TSprigAction)(TSprig* AItem);

typedef TMetaClass*TRootSprigClass;

__interface ISprigCollection;
typedef System::DelphiInterface<ISprigCollection> _di_ISprigCollection;
class DELPHICLASS TRootSprig;
__interface ISprigDesigner;
typedef System::DelphiInterface<ISprigDesigner> _di_ISprigDesigner;
__interface INTERFACE_UUID("{0B6ABAEE-E1A4-4DAC-8E20-C6B741A5082D}") ISprigCollection  : public IInterface 
{
	
public:
	virtual bool __fastcall RootSprigAssigned(void) = 0 ;
	virtual TRootSprig* __fastcall RootSprig(void) = 0 ;
	virtual _di_ISprigDesigner __fastcall GetSprigDesigner(void) = 0 ;
	virtual void __fastcall SetSprigDesigner(const _di_ISprigDesigner ASprigDesigner) = 0 ;
	__property _di_ISprigDesigner SprigDesigner = {read=GetSprigDesigner, write=SetSprigDesigner};
};

__interface INTERFACE_UUID("{6AC141E3-2FBE-425E-B299-AB29E7DF3FBB}") ISprigDesigner  : public IInterface 
{
	
public:
	virtual Comctrls::TCustomTreeView* __fastcall GetTreeView(void) = 0 ;
	virtual void __fastcall BeforeItemsModified(void) = 0 ;
	virtual void __fastcall AfterItemsModified(void) = 0 ;
	virtual TRootSprig* __fastcall GetRootSprig(void) = 0 ;
	virtual void __fastcall SetRootSprig(TRootSprig* ARootSprig) = 0 ;
	__property TRootSprig* RootSprig = {read=GetRootSprig, write=SetRootSprig};
};

class DELPHICLASS TInformant;
class PASCALIMPLEMENTATION TInformant : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FNotifyList;
	int FDisableNotify;
	bool FNotifyNeeded;
	bool FDestroying;
	
protected:
	virtual void __fastcall Changed(TInformant* AObj);
	
public:
	virtual void __fastcall BeforeDestruction(void);
	__fastcall virtual ~TInformant(void);
	__property bool Destroying = {read=FDestroying, nodefault};
	void __fastcall DisableNotify(void);
	void __fastcall EnableNotify(void);
	void __fastcall Notification(void);
	void __fastcall Notify(TInformant* AObj);
	void __fastcall Unnotify(TInformant* AObj);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TInformant(void) : System::TObject() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TSprigDeleteStyle { dsNormal, dsIgnore, dsAbort, dsCustom };
#pragma option pop

class PASCALIMPLEMENTATION TSprig : public TInformant 
{
	typedef TInformant inherited;
	
public:
	TSprig* operator[](int Index) { return Items[Index]; }
	
private:
	TRootSprig* FRoot;
	TSprig* FParent;
	Contnrs::TObjectList* FList;
	Classes::TPersistent* FItem;
	Comctrls::TTreeNode* FTreeNode;
	Imglist::TImageIndex FImageIndex;
	AnsiString FCaption;
	bool FExpanded;
	bool FInvalid;
	bool FCollectionsDone;
	bool FHidden;
	bool FHiddenTested;
	void __fastcall SetExpanded(const bool Value);
	
protected:
	TSprig* __fastcall GetItem(int Index);
	virtual AnsiString __fastcall UniqueName();
	AnsiString __fastcall CaptionFor(const AnsiString AName, const AnsiString ALabel = "", const AnsiString AClass = "");
	void __fastcall ReparentChildren(void);
	virtual void __fastcall SelectItems(const Classes::TPersistent* * AItems, const int AItems_Size, bool ARuntimeChange = true);
	virtual void __fastcall RuntimeChange(void);
	virtual void __fastcall DesigntimeChange(void);
	virtual TSprig* __fastcall FindItem(Classes::TPersistent* AItem, bool Recurse);
	virtual TSprig* __fastcall FindItemByName(const AnsiString AName, TMetaClass* AClass, bool Recurse);
	virtual TSprig* __fastcall FindItemByPath(const AnsiString APath, bool Recurse = true);
	virtual bool __fastcall GetDesigner(/* out */ Designintf::_di_IDesigner &ADesigner);
	virtual Imglist::TImageIndex __fastcall GetImageIndex(void);
	virtual void __fastcall SetImageIndex(const Imglist::TImageIndex Value);
	virtual Imglist::TImageIndex __fastcall GetStateIndex(void);
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall EnsureUpdate(void);
	virtual void __fastcall EndUpdate(void);
	virtual AnsiString __fastcall GetAddType(int Index);
	
public:
	__fastcall virtual TSprig(Classes::TPersistent* AItem)/* overload */;
	__fastcall virtual ~TSprig(void);
	void __fastcall Invalidate(void);
	virtual bool __fastcall Transient(void);
	virtual bool __fastcall AnyProblems(void);
	__property bool Invalid = {read=FInvalid, nodefault};
	__property Classes::TPersistent* Item = {read=FItem};
	virtual bool __fastcall Hidden(void);
	virtual bool __fastcall Ghosted(void);
	virtual Classes::TPersistent* __fastcall FocusItem(void);
	virtual TMetaClass* __fastcall ItemClass(void);
	virtual TSprig* __fastcall Owner(void);
	virtual void __fastcall VisualRefresh(void);
	virtual Comctrls::TTreeNode* __fastcall TreeNodeFor(Comctrls::TCustomTreeView* ATreeView);
	__property Comctrls::TTreeNode* TreeNode = {read=FTreeNode};
	__property bool Expanded = {read=FExpanded, write=SetExpanded, nodefault};
	__property Imglist::TImageIndex ImageIndex = {read=GetImageIndex, write=SetImageIndex, nodefault};
	__property Imglist::TImageIndex StateIndex = {read=GetStateIndex, nodefault};
	void __fastcall ClearTreeNode(void)/* overload */;
	void __fastcall ClearTreeNode(bool ARecurse, bool AFreeNode = true)/* overload */;
	virtual AnsiString __fastcall Name();
	virtual AnsiString __fastcall Caption();
	virtual AnsiString __fastcall Hint();
	virtual void __fastcall PrepareMenu(const Designmenus::_di_IMenuItems AItems);
	virtual bool __fastcall ShowRegisteredMenus(void);
	TMetaClass* __fastcall DragClass(void);
	virtual bool __fastcall DragOver(TSprig* AItem);
	virtual bool __fastcall DragOverTo(TSprig* AParent);
	virtual bool __fastcall DragDrop(TSprig* AItem);
	virtual bool __fastcall DragDropTo(TSprig* AParent);
	virtual bool __fastcall PaletteOver(TMetaClass* ASprigClass, TMetaClass* AClass);
	/* virtual class method */ virtual bool __fastcall PaletteOverTo(TMetaClass* vmt, TSprig* AParent, TMetaClass* AClass);
	TSprig* __fastcall Add(TSprig* AItem);
	TSprig* __fastcall Find(Classes::TPersistent* AItem, bool Recurse = true)/* overload */;
	TSprig* __fastcall Find(const AnsiString AName, bool Recurse = true)/* overload */;
	TSprig* __fastcall Find(const AnsiString AName, TMetaClass* AClass, bool Recurse = true)/* overload */;
	TSprig* __fastcall FindPath(const AnsiString APath, bool Recurse = true);
	int __fastcall IndexOf(TSprig* AItem);
	void __fastcall ForEach(TSprigAction ABefore, TSprigAction AAfter = 0x0);
	void __fastcall ClearUnneededSprigs(void);
	virtual TSprigDeleteStyle __fastcall DeleteStyle(void);
	virtual bool __fastcall CustomDelete(void);
	virtual bool __fastcall CanMove(bool AUp);
	virtual bool __fastcall Move(bool AUp);
	virtual bool __fastcall CanAdd(void);
	virtual int __fastcall AddTypeCount(void);
	__property AnsiString AddTypes[int Index] = {read=GetAddType};
	virtual void __fastcall AddType(int Index);
	virtual void __fastcall SortItems(void);
	virtual bool __fastcall SortByIndex(void);
	virtual bool __fastcall IncludeIndexInCaption(void);
	virtual int __fastcall ItemIndex(void);
	virtual bool __fastcall CopyGlyph(Graphics::TBitmap* ABitmap);
	__property TRootSprig* Root = {read=FRoot};
	__property TSprig* Parent = {read=FParent};
	bool __fastcall Parents(TSprig* ASprig);
	AnsiString __fastcall Path();
	__property TSprig* Items[int Index] = {read=GetItem/*, default*/};
	int __fastcall Count(void);
	int __fastcall Index(void);
	virtual void __fastcall Reparent(void);
	virtual Classes::TComponent* __fastcall Construct(TMetaClass* AClass);
	TSprig* __fastcall SeekParent(Classes::TPersistent* AItem, bool Recurse = true)/* overload */;
	TSprig* __fastcall SeekParent(const AnsiString AName, bool Recurse = true)/* overload */;
	TSprig* __fastcall SeekParent(const AnsiString AName, TMetaClass* AClass, bool Recurse = true)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall ParentProperty(TMetaClass* vmt);
	virtual void __fastcall FigureParent(void);
	virtual void __fastcall FigureChildren(void);
};


class DELPHICLASS TAbstractSprig;
class PASCALIMPLEMENTATION TAbstractSprig : public TSprig 
{
	typedef TSprig inherited;
	
public:
	virtual bool __fastcall Ghosted(void);
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TAbstractSprig(Classes::TPersistent* AItem)/* overload */ : TSprig(AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TAbstractSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTransientSprig;
class PASCALIMPLEMENTATION TTransientSprig : public TAbstractSprig 
{
	typedef TAbstractSprig inherited;
	
public:
	virtual bool __fastcall Transient(void);
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TTransientSprig(Classes::TPersistent* AItem)/* overload */ : TAbstractSprig(AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TTransientSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAbstractCollectionSprig;
class PASCALIMPLEMENTATION TAbstractCollectionSprig : public TAbstractSprig 
{
	typedef TAbstractSprig inherited;
	
public:
	__fastcall virtual TAbstractCollectionSprig(Classes::TPersistent* AItem)/* overload */;
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TAbstractCollectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTransientCollectionSprig;
class PASCALIMPLEMENTATION TTransientCollectionSprig : public TTransientSprig 
{
	typedef TTransientSprig inherited;
	
public:
	__fastcall virtual TTransientCollectionSprig(Classes::TPersistent* AItem)/* overload */;
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TTransientCollectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPersistentSprig;
class PASCALIMPLEMENTATION TPersistentSprig : public TSprig 
{
	typedef TSprig inherited;
	
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TPersistentSprig(Classes::TPersistent* AItem)/* overload */ : TSprig(AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TPersistentSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComponentSprig;
class PASCALIMPLEMENTATION TComponentSprig : public TPersistentSprig 
{
	typedef TPersistentSprig inherited;
	
private:
	TSprig* FOwner;
	
public:
	__fastcall virtual TComponentSprig(Classes::TPersistent* AItem)/* overload */;
	__fastcall TComponentSprig(Classes::TPersistent* AItem, TSprig* AOwner)/* overload */;
	virtual AnsiString __fastcall UniqueName();
	virtual TSprig* __fastcall Owner(void);
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TComponentSprig(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TComponentSprigClass;

class DELPHICLASS TSprigIndex;
class PASCALIMPLEMENTATION TSprigIndex : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Contnrs::TObjectList* FList;
	
public:
	__fastcall TSprigIndex(void);
	__fastcall virtual ~TSprigIndex(void);
	void __fastcall Add(TSprig* ASprig);
	void __fastcall Remove(TSprig* ASprig);
	TSprig* __fastcall Find(Classes::TPersistent* AItem);
};


class PASCALIMPLEMENTATION TRootSprig : public TPersistentSprig 
{
	typedef TPersistentSprig inherited;
	
private:
	TSprigIndex* FIndex;
	Classes::TList* FNamedItems;
	Classes::TList* FPathedItems;
	bool FRepopulating;
	bool FParentChanges;
	_di_ISprigDesigner FSprigDesigner;
	Designintf::_di_IDesigner FDesigner;
	bool FRepopulateNeeded;
	bool FNeedUpdate;
	int FUpdateLocks;
	void __fastcall ValidateParent(TSprig* AItem);
	void __fastcall PreRefreshTreeView(TSprig* AItem);
	void __fastcall PostRefreshTreeView(TSprig* AItem);
	void __fastcall DepopulateTreeView(TSprig* AItem);
	void __fastcall RestoreExpandState(TSprig* AItem);
	void __fastcall StoreExpandState(TSprig* AItem);
	void __fastcall SetSprigDesigner(const _di_ISprigDesigner ASprigDesigner);
	void __fastcall SelectionSurvey(/* out */ TSprigDeleteStyle &ADeleteStyle, /* out */ bool &AAllVisible);
	
protected:
	virtual TSprig* __fastcall FindItem(Classes::TPersistent* AItem, bool Recurse = true);
	virtual TSprig* __fastcall FindItemByName(const AnsiString AName, TMetaClass* AClass, bool Recurse);
	virtual TSprig* __fastcall FindItemByPath(const AnsiString APath, bool Recurse = true);
	void __fastcall AddItem(TSprig* ASprig);
	void __fastcall RemoveItem(TSprig* ASprig);
	virtual bool __fastcall GetDesigner(/* out */ Designintf::_di_IDesigner &ADesigner);
	virtual AnsiString __fastcall GetAddType(int Index);
	bool __fastcall SelectedSprig(TSprig* &ASprig);
	
public:
	__fastcall virtual TRootSprig(Classes::TPersistent* AItem)/* overload */;
	__fastcall virtual ~TRootSprig(void);
	virtual void __fastcall FigureParent(void);
	__property _di_ISprigDesigner SprigDesigner = {read=FSprigDesigner, write=SetSprigDesigner};
	__property Designintf::_di_IDesigner Designer = {read=FDesigner, write=FDesigner};
	__property bool Repopulating = {read=FRepopulating, nodefault};
	bool __fastcall Repopulate(void);
	Comctrls::TCustomTreeView* __fastcall TreeView(void);
	void __fastcall RefreshTreeView(void);
	void __fastcall StoreTreeState(void);
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall EnsureUpdate(void);
	virtual void __fastcall EndUpdate(void);
	void __fastcall ItemDeleted(Classes::TPersistent* AItem);
	void __fastcall ItemInserted(void);
	void __fastcall ItemsModified(bool AForceRepopulate = true);
	virtual void __fastcall RuntimeChange(void);
	virtual void __fastcall DesigntimeChange(void);
	virtual void __fastcall SelectItems(const Classes::TPersistent* * AItems, const int AItems_Size, bool ARuntimeChange = true);
	virtual bool __fastcall CanMove(bool AUp);
	virtual bool __fastcall Move(bool AUp);
	virtual bool __fastcall CanAdd(void);
	virtual void __fastcall AddType(int Index);
	virtual int __fastcall AddTypeCount(void);
	bool __fastcall EditAction(Designintf::TEditAction Action);
	Designintf::TEditState __fastcall GetEditState(void);
	virtual TSprigDeleteStyle __fastcall DeleteStyle(void);
	virtual bool __fastcall PaletteOver(TMetaClass* ASprigClass, TMetaClass* AClass);
	virtual bool __fastcall AcceptsClass(TMetaClass* AClass);
	__property bool RepopulateNeeded = {read=FRepopulateNeeded, write=FRepopulateNeeded, nodefault};
};


class DELPHICLASS TSprigTreeNode;
class PASCALIMPLEMENTATION TSprigTreeNode : public Comctrls::TTreeNode 
{
	typedef Comctrls::TTreeNode inherited;
	
public:
	__fastcall virtual ~TSprigTreeNode(void);
public:
	#pragma option push -w-inl
	/* TTreeNode.Create */ inline __fastcall TSprigTreeNode(Comctrls::TTreeNodes* AOwner) : Comctrls::TTreeNode(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TPropertySprig;
class PASCALIMPLEMENTATION TPropertySprig : public TPersistentSprig 
{
	typedef TPersistentSprig inherited;
	
public:
	virtual bool __fastcall Ghosted(void);
	virtual TSprigDeleteStyle __fastcall DeleteStyle(void);
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TPropertySprig(Classes::TPersistent* AItem)/* overload */ : TPersistentSprig(AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TPropertySprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCollectionSprig;
class PASCALIMPLEMENTATION TCollectionSprig : public TPropertySprig 
{
	typedef TPropertySprig inherited;
	
private:
	AnsiString FPropName;
	TSprig* FOwner;
	
protected:
	virtual AnsiString __fastcall GetAddType(int Index);
	
public:
	__fastcall virtual TCollectionSprig(Classes::TPersistent* AItem)/* overload */;
	virtual AnsiString __fastcall Name();
	virtual AnsiString __fastcall Caption();
	virtual void __fastcall FigureParent(void);
	virtual void __fastcall FigureChildren(void);
	virtual TSprig* __fastcall Owner(void);
	virtual bool __fastcall SortByIndex(void);
	virtual void __fastcall AddType(int Index);
	virtual int __fastcall AddTypeCount(void);
	virtual TSprigDeleteStyle __fastcall DeleteStyle(void);
	virtual bool __fastcall CustomDelete(void);
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TCollectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCollectionItemSprig;
class PASCALIMPLEMENTATION TCollectionItemSprig : public TPersistentSprig 
{
	typedef TPersistentSprig inherited;
	
private:
	TSprig* FOwner;
	
protected:
	virtual AnsiString __fastcall GetAddType(int Index);
	
public:
	virtual AnsiString __fastcall Name();
	virtual void __fastcall FigureParent(void);
	virtual TSprig* __fastcall Owner(void);
	virtual bool __fastcall Ghosted(void);
	virtual int __fastcall ItemIndex(void);
	virtual bool __fastcall IncludeIndexInCaption(void);
	virtual bool __fastcall DragOverTo(TSprig* AParent);
	virtual bool __fastcall DragDropTo(TSprig* AParent);
	virtual void __fastcall AddType(int Index);
	virtual int __fastcall AddTypeCount(void);
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TCollectionItemSprig(Classes::TPersistent* AItem)/* overload */ : TPersistentSprig(AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TCollectionItemSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSprigType;
class PASCALIMPLEMENTATION TSprigType : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FGroup;
	TMetaClass*FClass;
	TMetaClass*FSprigClass;
	
public:
	__fastcall TSprigType(const TMetaClass* AClass, const TMetaClass* ASprigClass);
	int __fastcall Score(const TMetaClass* AClass);
	__property TMetaClass* SprigClass = {read=FSprigClass};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSprigType(void) { }
	#pragma option pop
	
};


typedef DynamicArray<GUID >  TGUIDArray;

class DELPHICLASS TSprigIntfType;
class PASCALIMPLEMENTATION TSprigIntfType : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FGroup;
	DynamicArray<GUID >  FInterfaces;
	TMetaClass*FSprigClass;
	
public:
	__fastcall TSprigIntfType(const TGUIDArray AInterfaces, const TMetaClass* ASprigClass);
	bool __fastcall Match(const TMetaClass* AClass);
	__property TMetaClass* SprigClass = {read=FSprigClass};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSprigIntfType(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSprigTypeList;
class PASCALIMPLEMENTATION TSprigTypeList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Contnrs::TObjectList* FList;
	TMetaClass*FLastClass;
	TMetaClass*FLastSprigClass;
	Contnrs::TObjectList* FInterfaceList;
	
protected:
	void __fastcall ClearCache(void);
	TMetaClass* __fastcall MatchCache(const TMetaClass* AClass);
	TMetaClass* __fastcall MatchClass(const TMetaClass* AClass);
	
public:
	__fastcall TSprigTypeList(void);
	__fastcall virtual ~TSprigTypeList(void);
	TMetaClass* __fastcall Match(const TMetaClass* AClass);
	void __fastcall Add(const TMetaClass* AClass, const TMetaClass* ASprigClass)/* overload */;
	void __fastcall Add(const TGUIDArray AInterfaces, const TMetaClass* ASprigClass)/* overload */;
	void __fastcall FreeEditorGroup(int AGroup);
};


class DELPHICLASS TDragSprigs;
class PASCALIMPLEMENTATION TDragSprigs : public Controls::TDragControlObjectEx 
{
	typedef Controls::TDragControlObjectEx inherited;
	
private:
	Classes::TList* FSprigs;
	TSprig* __fastcall GetSprig(int Index);
	
public:
	__fastcall virtual TDragSprigs(Controls::TControl* AControl);
	__fastcall virtual ~TDragSprigs(void);
	void __fastcall Add(TSprig* ASprig);
	int __fastcall Count(void);
	__property TSprig* Sprigs[int Index] = {read=GetSprig};
};


class DELPHICLASS TRootSprigList;
class PASCALIMPLEMENTATION TRootSprigList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Contnrs::TBucketList* FList;
	
public:
	__fastcall TRootSprigList(void);
	__fastcall virtual ~TRootSprigList(void);
	bool __fastcall FindRoot(const Designintf::_di_IDesigner ADesigner, /* out */ TRootSprig* &ARootSprig);
	void __fastcall DesignerClosed(const Designintf::_di_IDesigner ADesigner, bool AGoingDormant);
	void __fastcall DesignerOpened(const Designintf::_di_IDesigner ADesigner, bool AResurrecting);
	void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, Classes::TPersistent* AItem);
	void __fastcall ItemInserted(const Designintf::_di_IDesigner ADesigner, Classes::TPersistent* AItem);
	void __fastcall ItemsModified(const Designintf::_di_IDesigner ADesigner);
};


typedef bool __fastcall (__closure *TCopySprigGlyphFunc)(TSprig* ASprig, Graphics::TBitmap* ABitmap);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool GShowClassNameInTreeView;
static const Shortint CFakeSprigImage = 0x0;
static const Shortint CFakeCollectionSprigImage = 0x1;
static const Shortint CPersistentSprigImage = 0x2;
static const Shortint CCollectionSprigImage = 0x3;
static const Shortint CComponentSprigImage = 0x4;
static const Shortint CDataModuleSprigImage = 0x5;
static const Shortint CControlSprigImage = 0x6;
static const Shortint CUIControlSprigImage = 0x7;
static const Shortint CUIContainerSprigImage = 0x8;
static const Shortint CFormSprigImage = 0x9;
static const Shortint CGhostedOffset = 0xa;
static const Shortint CNoStateImage = 0x0;
static const Shortint CCheckOutStateImage = 0x1;
#define CCollectionName "<Collection.%s>"
extern PACKAGE int CUIControlImageIndex[2];
extern PACKAGE TCopySprigGlyphFunc CopySprigGlyphFunc;
extern PACKAGE void __fastcall RegisterSprigType(const TMetaClass* AClass, TMetaClass* ASprigClass)/* overload */;
extern PACKAGE void __fastcall RegisterSprigType(const TGUIDArray AInterfaces, TMetaClass* ASprigClass)/* overload */;
extern PACKAGE TMetaClass* __fastcall FindBestSprigClass(TMetaClass* AClass)/* overload */;
extern PACKAGE TMetaClass* __fastcall FindBestSprigClass(TMetaClass* AClass, TMetaClass* AMinimumSprigClass)/* overload */;
extern PACKAGE void __fastcall RegisterRootSprigType(const TMetaClass* AClass, TMetaClass* ASprigClass)/* overload */;
extern PACKAGE void __fastcall RegisterRootSprigType(const TGUIDArray AInterfaces, TMetaClass* ASprigClass)/* overload */;
extern PACKAGE TMetaClass* __fastcall FindBestRootSprigClass(TMetaClass* AClass)/* overload */;
extern PACKAGE TMetaClass* __fastcall FindBestRootSprigClass(TMetaClass* AClass, TMetaClass* AMinimumSprigClass)/* overload */;
extern PACKAGE TRootSprigList* __fastcall RootSprigList(void);

}	/* namespace Treeintf */
using namespace Treeintf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TreeIntf
