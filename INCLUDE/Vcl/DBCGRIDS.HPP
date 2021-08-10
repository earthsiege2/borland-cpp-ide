// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBCGrids.pas' rev: 5.00

#ifndef DBCGridsHPP
#define DBCGridsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Db.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbcgrids
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDBCtrlGridLink;
class DELPHICLASS TDBCtrlGrid;
class DELPHICLASS TDBCtrlPanel;
class PASCALIMPLEMENTATION TDBCtrlPanel : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	TDBCtrlGrid* FDBCtrlGrid;
	HIDESBASE MESSAGE void __fastcall CMControlListChange(Controls::TCMControlListChange &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall PaintWindow(HDC DC);
	
public:
	__fastcall TDBCtrlPanel(TDBCtrlGrid* DBCtrlGrid);
public:
	#pragma option push -w-inl
	/* TWinControl.Create */ inline __fastcall virtual TDBCtrlPanel(Classes::TComponent* AOwner) : Controls::TWinControl(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBCtrlPanel(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TDBCtrlPanel(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDBCtrlGridOrientation { goVertical, goHorizontal };
#pragma option pop

#pragma option push -b-
enum TDBCtrlGridBorder { gbNone, gbRaised };
#pragma option pop

typedef void __fastcall (__closure *TPaintPanelEvent)(TDBCtrlGrid* DBCtrlGrid, int Index);

#pragma option push -b-
enum TDBCtrlGridKey { gkNull, gkEditMode, gkPriorTab, gkNextTab, gkLeft, gkRight, gkUp, gkDown, gkScrollUp, 
	gkScrollDown, gkPageUp, gkPageDown, gkHome, gkEnd, gkInsert, gkAppend, gkDelete, gkCancel };
#pragma option pop

class PASCALIMPLEMENTATION TDBCtrlGrid : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	TDBCtrlGridLink* FDataLink;
	TDBCtrlPanel* FPanel;
	Graphics::TCanvas* FCanvas;
	int FColCount;
	int FRowCount;
	int FPanelWidth;
	int FPanelHeight;
	int FPanelIndex;
	int FPanelCount;
	int FBitmapCount;
	HBITMAP FPanelBitmap;
	HBITMAP FSaveBitmap;
	HDC FPanelDC;
	TDBCtrlGridOrientation FOrientation;
	TDBCtrlGridBorder FPanelBorder;
	bool FAllowInsert;
	bool FAllowDelete;
	bool FShowFocus;
	bool FFocused;
	bool FClicking;
	bool FSelColorChanged;
	int FScrollBarKind;
	Graphics::TColor FSelectedColor;
	TPaintPanelEvent FOnPaintPanel;
	bool __fastcall AcquireFocus(void);
	HIDESBASE void __fastcall AdjustSize(void);
	void __fastcall CreatePanelBitmap(void);
	void __fastcall DataSetChanged(bool Reset);
	void __fastcall DestroyPanelBitmap(void);
	void __fastcall DrawPanel(HDC DC, int Index);
	void __fastcall DrawPanelBackground(HDC DC, const Windows::TRect &R, bool Erase, bool Selected);
	Controls::TWinControl* __fastcall FindNext(Controls::TWinControl* StartControl, bool GoForward, int 
		&WrapFlag);
	Db::TDataSource* __fastcall GetDataSource(void);
	bool __fastcall GetEditMode(void);
	Windows::TRect __fastcall GetPanelBounds(int Index);
	bool __fastcall PointInPanel(const Windows::TSmallPoint P);
	void __fastcall Reset(void);
	void __fastcall Scroll(int Inc, bool ScrollLock);
	void __fastcall ScrollMessage(Messages::TWMScroll &Message);
	HIDESBASE void __fastcall SelectNext(bool GoForward);
	void __fastcall SetColCount(int Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetEditMode(bool Value);
	void __fastcall SetOrientation(TDBCtrlGridOrientation Value);
	void __fastcall SetPanelBorder(TDBCtrlGridBorder Value);
	void __fastcall SetPanelHeight(int Value);
	void __fastcall SetPanelIndex(int Value);
	void __fastcall SetPanelWidth(int Value);
	void __fastcall SetRowCount(int Value);
	void __fastcall SetSelectedColor(Graphics::TColor Value);
	void __fastcall UpdateDataLinks(Controls::TControl* Control, bool Inserting);
	void __fastcall UpdateScrollBar(void);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMChildKey(Controls::TCMChildKey &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC Classes::TComponent* __fastcall GetChildParent(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall PaintPanel(int Index);
	virtual void __fastcall PaintWindow(HDC DC);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	__property TDBCtrlPanel* Panel = {read=FPanel};
	
public:
	__fastcall virtual TDBCtrlGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBCtrlGrid(void);
	void __fastcall DoKey(TDBCtrlGridKey Key);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC void __fastcall GetTabOrderList(Classes::TList* List);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	__property bool EditMode = {read=GetEditMode, write=SetEditMode, nodefault};
	__property int PanelCount = {read=FPanelCount, nodefault};
	__property int PanelIndex = {read=FPanelIndex, write=SetPanelIndex, nodefault};
	
__published:
	__property Align ;
	__property bool AllowDelete = {read=FAllowDelete, write=FAllowDelete, default=1};
	__property bool AllowInsert = {read=FAllowInsert, write=FAllowInsert, default=1};
	__property Anchors ;
	__property int ColCount = {read=FColCount, write=SetColCount, nodefault};
	__property Color ;
	__property Constraints ;
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property TDBCtrlGridOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0
		};
	__property TDBCtrlGridBorder PanelBorder = {read=FPanelBorder, write=SetPanelBorder, default=1};
	__property int PanelHeight = {read=FPanelHeight, write=SetPanelHeight, nodefault};
	__property int PanelWidth = {read=FPanelWidth, write=SetPanelWidth, nodefault};
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property TabOrder ;
	__property TabStop ;
	__property int RowCount = {read=FRowCount, write=SetRowCount, nodefault};
	__property Graphics::TColor SelectedColor = {read=FSelectedColor, write=SetSelectedColor, stored=FSelColorChanged
		, default=-2147483643};
	__property bool ShowFocus = {read=FShowFocus, write=FShowFocus, default=1};
	__property ShowHint ;
	__property Visible ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property TPaintPanelEvent OnPaintPanel = {read=FOnPaintPanel, write=FOnPaintPanel};
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBCtrlGrid(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDBCtrlGridLink : public Db::TDataLink 
{
	typedef Db::TDataLink inherited;
	
private:
	TDBCtrlGrid* FDBCtrlGrid;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	
public:
	__fastcall TDBCtrlGridLink(TDBCtrlGrid* DBCtrlGrid);
public:
	#pragma option push -w-inl
	/* TDataLink.Destroy */ inline __fastcall virtual ~TDBCtrlGridLink(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dbcgrids */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dbcgrids;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBCGrids
