// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Designer.pas' rev: 6.00

#ifndef DesignerHPP
#define DesignerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Designer
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TZOrder { zoFront, zoBack };
#pragma option pop

__interface IItem;
typedef System::DelphiInterface<IItem> _di_IItem;
__interface INTERFACE_UUID("{C41303AD-CAE3-11D3-AB47-00C04FB17A72}") IItem  : public IInterface 
{
	
public:
	virtual bool __fastcall Contains(const _di_IItem Item) = 0 ;
	virtual void __fastcall Delete(void) = 0 ;
	virtual Types::TPoint __fastcall GlobalToLocal(const Types::TPoint &Point) = 0 ;
	virtual Types::TPoint __fastcall LocalToGlobal(const Types::TPoint &Point) = 0 ;
	virtual bool __fastcall Equals(const _di_IItem Item) = 0 ;
	virtual Types::TRect __fastcall GetBoundsRect(void) = 0 ;
	virtual Types::TRect __fastcall GetExtendedRect(void) = 0 ;
	virtual Types::TRect __fastcall GetClientRect(void) = 0 ;
	virtual _di_IItem __fastcall GetParent(void) = 0 ;
	virtual bool __fastcall IsContainer(void) = 0 ;
	virtual bool __fastcall HasSelectableChildren(void) = 0 ;
	virtual void __fastcall SetBoundsRect(const Types::TRect &Value) = 0 ;
	virtual bool __fastcall Selectable(void) = 0 ;
	virtual void __fastcall ValidateDeletable(void) = 0 ;
	virtual void __fastcall Edit(void) = 0 ;
	__property Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property Types::TRect ClientRect = {read=GetClientRect};
	__property Types::TRect ExtendedRect = {read=GetExtendedRect};
	__property _di_IItem Parent = {read=GetParent};
};

__interface IGrabHandles;
typedef System::DelphiInterface<IGrabHandles> _di_IGrabHandles;
__interface INTERFACE_UUID("{C41303A9-CAE3-11D3-AB47-00C04FB17A72}") IGrabHandles  : public IInterface 
{
	
public:
	virtual _di_IItem __fastcall GetSelection(void) = 0 ;
	virtual void __fastcall SetSelection(const _di_IItem Value) = 0 ;
	virtual void __fastcall SetActive(bool Value) = 0 ;
	virtual void __fastcall Update(void) = 0 ;
	__property _di_IItem Selection = {read=GetSelection, write=SetSelection};
};

#pragma option push -b-
enum TDesignKeyCode { dkDelete, dkLeft, dkUp, dkRight, dkDown, dkTab, dkEnter, dkEscape, dkChar };
#pragma option pop

#pragma option push -b-
enum Designer__1 { gaLeft, gaTop, gaRight, gaBottom };
#pragma option pop

typedef Set<Designer__1, gaLeft, gaBottom>  TMoveAffects;

#pragma option push -b-
enum TDesignBoxStyle { dbsSelection, dbsItem };
#pragma option pop

__interface IDragBoxes;
typedef System::DelphiInterface<IDragBoxes> _di_IDragBoxes;
__interface IDragBoxes  : public IInterface 
{
	
public:
	virtual int __fastcall Add(const Types::TRect &Rect, TDesignBoxStyle Style) = 0 ;
	virtual void __fastcall Change(int Index, const Types::TRect &New) = 0 ;
	virtual void __fastcall MoveBy(int DX, int DY) = 0 ;
	virtual void __fastcall Done(void) = 0 ;
};

__interface IDesignSurfaceListener;
typedef System::DelphiInterface<IDesignSurfaceListener> _di_IDesignSurfaceListener;
__interface INTERFACE_UUID("{C41303AA-CAE3-11D3-AB47-00C04FB17A72}") IDesignSurfaceListener  : public IInterface 
{
	
public:
	virtual void __fastcall MouseDown(_di_IItem Sender, Classes::TShiftState Shift, int X, int Y, bool DoubleClick, TMoveAffects MoveAffects = System::Set<Designer__1, gaLeft, gaBottom> () ) = 0 ;
	virtual void __fastcall MouseMove(int X, int Y) = 0 ;
	virtual void __fastcall MouseUp(int X, int Y) = 0 ;
	virtual void __fastcall Key(TDesignKeyCode KeyCode, Classes::TShiftState Shift, wchar_t Ch) = 0 ;
	virtual void __fastcall CancelDragging(void) = 0 ;
};

__interface IDesignSurface;
typedef System::DelphiInterface<IDesignSurface> _di_IDesignSurface;
__interface INTERFACE_UUID("{C41303AB-CAE3-11D3-AB47-00C04FB17A72}") IDesignSurface  : public IInterface 
{
	
public:
	virtual void __fastcall AddListener(const _di_IDesignSurfaceListener Listener) = 0 ;
	virtual _di_IDragBoxes __fastcall BeginDragging(const _di_IItem Parent) = 0 ;
	virtual void __fastcall Close(void) = 0 ;
	virtual _di_IItem __fastcall CreateItem(const _di_IItem Parent, const Types::TRect &Rect) = 0 ;
	virtual Types::TPoint __fastcall CursorPosition(void) = 0 ;
	virtual void __fastcall DeleteSelection(void) = 0 ;
	virtual Types::TPoint __fastcall DesignerToGlobal(const Types::TPoint &Point) = 0 ;
	virtual void __fastcall DestroyItem(const _di_IItem Item) = 0 ;
	virtual _di_IItem __fastcall FindNextItem(const _di_IItem Item, bool GoForward) = 0 ;
	virtual void __fastcall Focus(void) = 0 ;
	virtual _di_IGrabHandles __fastcall GetGrabHandles(void) = 0 ;
	virtual _di_IItem __fastcall GetItems(int Index) = 0 ;
	virtual int __fastcall GetItemsCount(void) = 0 ;
	virtual Types::TPoint __fastcall GetOffset(void) = 0 ;
	virtual _di_IItem __fastcall GetRoot(void) = 0 ;
	virtual Types::TPoint __fastcall GlobalToDesigner(const Types::TPoint &Point) = 0 ;
	virtual bool __fastcall GridSnapDisabled(void) = 0 ;
	virtual void __fastcall RemoveListener(const _di_IDesignSurfaceListener Listener) = 0 ;
	virtual void __fastcall UpdateSelection(void) = 0 ;
	virtual void __fastcall ValidateModification(void) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	__property _di_IGrabHandles GrabHandles = {read=GetGrabHandles};
	__property _di_IItem Items[int Index] = {read=GetItems};
	__property int ItemsCount = {read=GetItemsCount};
	__property _di_IItem Root = {read=GetRoot};
};

__interface ITools;
typedef System::DelphiInterface<ITools> _di_ITools;
__interface INTERFACE_UUID("{C41303AF-CAE3-11D3-AB47-00C04FB17A72}") ITools  : public IInterface 
{
	
public:
	virtual bool __fastcall ToolSelected(void) = 0 ;
};

__interface ISelectionsListener;
typedef System::DelphiInterface<ISelectionsListener> _di_ISelectionsListener;
__interface ISelections;
typedef System::DelphiInterface<ISelections> _di_ISelections;
__interface INTERFACE_UUID("{3D642F40-D567-11D3-BA96-0080C78ADCDB}") ISelectionsListener  : public IInterface 
{
	
public:
	virtual void __fastcall SelectionChanged(const _di_ISelections Selections) = 0 ;
};

__interface INTERFACE_UUID("{C41303AC-CAE3-11D3-AB47-00C04FB17A72}") ISelections  : public IInterface 
{
	
public:
	_di_IItem operator[](int Index) { return Items[Index]; }
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IItem __fastcall GetItems(int Index) = 0 ;
	virtual int __fastcall GetSelectionLevel(void) = 0 ;
	virtual void __fastcall Add(const _di_IItem Item) = 0 ;
	virtual void __fastcall AddListener(const _di_ISelectionsListener Listener) = 0 ;
	virtual void __fastcall BeginSelections(void) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall EndSelections(void) = 0 ;
	virtual void __fastcall Remove(const _di_IItem Item) = 0 /* overload */;
	virtual void __fastcall Remove(int Index) = 0 /* overload */;
	virtual void __fastcall RemoveListener(const _di_ISelectionsListener Listener) = 0 ;
	virtual bool __fastcall Selected(const _di_IItem Item) = 0 ;
	virtual void __fastcall Toggle(const _di_IItem Item) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IItem Items[int Index] = {read=GetItems/*, default*/};
	__property int SelectionLevel = {read=GetSelectionLevel};
};

__interface ISurfaceDesigner;
typedef System::DelphiInterface<ISurfaceDesigner> _di_ISurfaceDesigner;
__interface INTERFACE_UUID("{BC9760BF-249C-433A-B2C9-85B59B2D3A9F}") ISurfaceDesigner  : public IInterface 
{
	
public:
	virtual void __fastcall Close(void) = 0 ;
	virtual void __fastcall CancelDragging(void) = 0 ;
	virtual bool __fastcall GetLocked(void) = 0 ;
	virtual Types::TPoint __fastcall GetGridSize(void) = 0 ;
	virtual void __fastcall Lock(void) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	virtual Types::TPoint __fastcall PointToGrid(const Types::TPoint &Pos, bool Force = false) = 0 ;
	virtual void __fastcall SetGridSize(const Types::TPoint &Value) = 0 ;
	virtual void __fastcall Unlock(void) = 0 ;
	virtual bool __fastcall GetGridAligned(void) = 0 ;
	virtual void __fastcall SetGridAligned(bool Value) = 0 ;
	__property bool Locked = {read=GetLocked};
	__property Types::TPoint GridSize = {read=GetGridSize, write=SetGridSize};
	__property bool GridAligned = {read=GetGridAligned, write=SetGridAligned};
};

#pragma option push -b-
enum TDragAction { daNone, daCreate, daSelect, daMove, daSize };
#pragma option pop

class DELPHICLASS TDesigner;
class PASCALIMPLEMENTATION TDesigner : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_IDesignSurface FDesignSurface;
	_di_ISelections FSelections;
	_di_IGrabHandles FGrabHandles;
	_di_ITools FTools;
	#pragma pack(push, 1)
	Types::TPoint FGridSize;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint FAnchor;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TRect FDragRect;
	#pragma pack(pop)
	
	TMoveAffects FDragAffects;
	TDragAction FDragAction;
	bool FLocked;
	bool FGridAlign;
	_di_IItem FDragParent;
	_di_IDragBoxes FBoxes;
	void __fastcall DoDragCreate(void);
	void __fastcall DoDragMove(void);
	void __fastcall DoDragSelect(void);
	void __fastcall DoDragSize(void);
	void __fastcall DragBoxesMoveTo(const Types::TRect &NewRect);
	void __fastcall DragBoxesOff(void);
	void __fastcall DragBoxesOn(void);
	_di_IItem __fastcall FindNearestItem(const _di_IItem Item, TDesignKeyCode Key);
	void __fastcall ForceCommonSelectParent(const _di_IItem Parent);
	Types::TRect __fastcall GetDragRect(const Types::TPoint &Pos);
	void __fastcall MoveBy(const Types::TPoint &Delta, bool Size);
	int __fastcall SnapToGrid(int Coord, int GridOffset, int GridSize, bool Force);
	
protected:
	void __fastcall MouseDown(_di_IItem Sender, Classes::TShiftState Shift, int X, int Y, bool DoubleClick, TMoveAffects MoveAffects);
	void __fastcall MouseMove(int X, int Y);
	void __fastcall MouseUp(int X, int Y);
	void __fastcall Key(TDesignKeyCode KeyCode, Classes::TShiftState Shift, wchar_t Ch);
	void __fastcall Close(void);
	void __fastcall CancelDragging(void);
	bool __fastcall GetLocked(void);
	Types::TPoint __fastcall PointToGrid(const Types::TPoint &Pos, bool Force = false);
	Types::TPoint __fastcall GetGridSize();
	void __fastcall SetGridSize(const Types::TPoint &Value);
	bool __fastcall GetGridAligned(void);
	void __fastcall SetGridAligned(bool Value);
	void __fastcall BeginSelect(void);
	void __fastcall ClearSelection(void);
	void __fastcall DragBegin(int X, int Y);
	void __fastcall DragCancel(void);
	void __fastcall DragEnd(int X, int Y, bool Accept);
	void __fastcall DragTo(int X, int Y);
	void __fastcall Edit(const _di_IItem Item);
	void __fastcall EndSelect(void);
	bool __fastcall IsDesignerSelected(void);
	void __fastcall Select(const _di_IItem Item, bool Extend);
	_di_IItem __fastcall SelectedItem();
	__property Types::TPoint Anchor = {read=FAnchor};
	__property TDragAction DragAction = {read=FDragAction, nodefault};
	__property TMoveAffects DragAffects = {read=FDragAffects, nodefault};
	__property _di_IItem DragParent = {read=FDragParent};
	__property Types::TRect DragRect = {read=FDragRect};
	__property _di_IDesignSurface DesignSurface = {read=FDesignSurface};
	__property _di_IGrabHandles GrabHandles = {read=FGrabHandles};
	__property bool GridAlign = {read=FGridAlign, nodefault};
	__property Types::TPoint GridSize = {read=FGridSize};
	__property _di_ISelections Selections = {read=FSelections};
	__property _di_ITools Tools = {read=FTools};
	
public:
	__fastcall TDesigner(const _di_IDesignSurface DesignSurface, const _di_ISelections Selections, const _di_ITools Tools);
	__fastcall virtual ~TDesigner(void);
	void __fastcall DeleteSelection(void);
	HIDESBASE void __fastcall Free(void);
	virtual void __fastcall Modified(void);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	__property bool Locked = {read=FLocked, nodefault};
private:
	void *__IDesignSurfaceListener;	/* Designer::IDesignSurfaceListener */
	void *__ISurfaceDesigner;	/* Designer::ISurfaceDesigner */
	
public:
	operator ISurfaceDesigner*(void) { return (ISurfaceDesigner*)&__ISurfaceDesigner; }
	operator IDesignSurfaceListener*(void) { return (IDesignSurfaceListener*)&__IDesignSurfaceListener; }
	
};


__interface IPersistentItem;
typedef System::DelphiInterface<IPersistentItem> _di_IPersistentItem;
__interface INTERFACE_UUID("{C41303B0-CAE3-11D3-AB47-00C04FB17A72}") IPersistentItem  : public IInterface 
{
	
public:
	virtual Classes::TPersistent* __fastcall GetItem(void) = 0 ;
	virtual AnsiString __fastcall GetNamePath(void) = 0 ;
};

class DELPHICLASS TPersistentItem;
class PASCALIMPLEMENTATION TPersistentItem : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TPersistent* FInstance;
	
protected:
	Classes::TPersistent* __fastcall GetItem(void);
	AnsiString __fastcall GetNamePath();
	bool __fastcall Contains(const _di_IItem Item);
	void __fastcall Delete(void);
	bool __fastcall Equals(const _di_IItem Item);
	Types::TRect __fastcall GetBoundsRect();
	Types::TRect __fastcall GetClientRect();
	Types::TRect __fastcall GetExtendedRect();
	_di_IItem __fastcall GetParent();
	bool __fastcall IsContainer(void);
	bool __fastcall HasSelectableChildren(void);
	void __fastcall SetBoundsRect(const Types::TRect &Value);
	void __fastcall ValidateDeletable(void);
	__property Classes::TPersistent* Instance = {read=FInstance};
	
public:
	__fastcall TPersistentItem(Classes::TPersistent* Instance);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TPersistentItem(void) { }
	#pragma option pop
	
private:
	void *__IPersistentItem;	/* Designer::IPersistentItem */
	
public:
	operator IPersistentItem*(void) { return (IPersistentItem*)&__IPersistentItem; }
	
};


typedef DynamicArray<Types::TRect >  Designer__5;

typedef DynamicArray<TDesignBoxStyle >  Designer__6;

class DELPHICLASS TXorDragBoxes;
class PASCALIMPLEMENTATION TXorDragBoxes : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	DynamicArray<Types::TRect >  FRects;
	DynamicArray<TDesignBoxStyle >  FKinds;
	int FUsed;
	void __fastcall DrawBoxes(void);
	
protected:
	int __fastcall Add(const Types::TRect &Rect, TDesignBoxStyle Style);
	void __fastcall Change(int Index, const Types::TRect &New);
	void __fastcall MoveBy(int DX, int DY);
	void __fastcall Done(void);
	Types::TRect __fastcall BoundingRect();
	virtual void __fastcall DrawBox(const Types::TRect &Rect, TDesignBoxStyle Kind) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TXorDragBoxes(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXorDragBoxes(void) { }
	#pragma option pop
	
private:
	void *__IDragBoxes;	/* Designer::IDragBoxes */
	
public:
	operator IDragBoxes*(void) { return (IDragBoxes*)&__IDragBoxes; }
	
};


class DELPHICLASS TNullTools;
class PASCALIMPLEMENTATION TNullTools : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
protected:
	bool __fastcall ToolSelected(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TNullTools(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TNullTools(void) { }
	#pragma option pop
	
private:
	void *__ITools;	/* Designer::ITools */
	
public:
	operator ITools*(void) { return (ITools*)&__ITools; }
	
};


class DELPHICLASS TSelectionListenerHelper;
class PASCALIMPLEMENTATION TSelectionListenerHelper : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::_di_IInterfaceList FList;
	
public:
	__fastcall TSelectionListenerHelper(void);
	void __fastcall AddListener(const _di_ISelectionsListener Listener);
	void __fastcall RemoveListener(const _di_ISelectionsListener Listener);
	void __fastcall SelectionChanged(const _di_ISelections Selections);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSelectionListenerHelper(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSimpleSelections;
class PASCALIMPLEMENTATION TSimpleSelections : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::_di_IInterfaceList FList;
	TSelectionListenerHelper* FListeners;
	int FBeginCount;
	bool FDirty;
	
protected:
	int __fastcall IndexOf(const _di_IItem Item);
	void __fastcall Modified(void);
	int __fastcall GetCount(void);
	_di_IItem __fastcall GetItems(int Index);
	int __fastcall GetSelectionLevel(void);
	void __fastcall BeginSelections(void);
	void __fastcall Add(const _di_IItem Item);
	void __fastcall Clear(void);
	void __fastcall EndSelections(void);
	void __fastcall Remove(const _di_IItem Item)/* overload */;
	void __fastcall Remove(int Index)/* overload */;
	bool __fastcall Selected(const _di_IItem Item);
	void __fastcall Toggle(const _di_IItem Item);
	__property TSelectionListenerHelper* Listeners = {read=FListeners};
	
public:
	__fastcall TSimpleSelections(void);
	__fastcall virtual ~TSimpleSelections(void);
private:
	void *__ISelections;	/* Designer::ISelections */
	
public:
	operator ISelections*(void) { return (ISelections*)&__ISelections; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall SameItem(const _di_IItem Item1, const _di_IItem Item2);
extern PACKAGE Classes::TPersistent* __fastcall ExtractPersistent(const _di_IItem Item);
extern PACKAGE Classes::TComponent* __fastcall ExtractComponent(const _di_IItem Item);

}	/* namespace Designer */
using namespace Designer;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Designer
