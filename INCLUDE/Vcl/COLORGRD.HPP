// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ColorGrd.pas' rev: 5.00

#ifndef ColorGrdHPP
#define ColorGrdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Colorgrd
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TGridOrdering { go16x1, go8x2, go4x4, go2x8, go1x16 };
#pragma option pop

class DELPHICLASS TColorGrid;
class PASCALIMPLEMENTATION TColorGrid : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	tagPALETTEENTRY FPaletteEntries[20];
	bool FClickEnablesColor;
	int FForegroundIndex;
	int FBackgroundIndex;
	bool FForegroundEnabled;
	bool FBackgroundEnabled;
	int FSelection;
	int FCellXSize;
	int FCellYSize;
	int FNumXSquares;
	int FNumYSquares;
	TGridOrdering FGridOrdering;
	bool FHasFocus;
	Classes::TNotifyEvent FOnChange;
	Controls::TMouseButton FButton;
	bool FButtonDown;
	void __fastcall DrawSquare(int Which, bool ShowSelector);
	void __fastcall DrawFgBg(void);
	void __fastcall UpdateCellSizes(bool DoRepaint);
	void __fastcall SetGridOrdering(TGridOrdering Value);
	Graphics::TColor __fastcall GetForegroundColor(void);
	Graphics::TColor __fastcall GetBackgroundColor(void);
	void __fastcall SetForegroundIndex(int Value);
	void __fastcall SetBackgroundIndex(int Value);
	void __fastcall SetSelection(int Value);
	void __fastcall EnableForeground(bool Value);
	void __fastcall EnableBackground(bool Value);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Change(void);
	int __fastcall SquareFromPos(int X, int Y);
	
public:
	__fastcall virtual TColorGrid(Classes::TComponent* AOwner);
	int __fastcall ColorToIndex(Graphics::TColor AColor);
	__property Graphics::TColor ForegroundColor = {read=GetForegroundColor, nodefault};
	__property Graphics::TColor BackgroundColor = {read=GetBackgroundColor, nodefault};
	
__published:
	__property Anchors ;
	__property bool ClickEnablesColor = {read=FClickEnablesColor, write=FClickEnablesColor, default=0};
		
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragMode ;
	__property Enabled ;
	__property TGridOrdering GridOrdering = {read=FGridOrdering, write=SetGridOrdering, default=2};
	__property int ForegroundIndex = {read=FForegroundIndex, write=SetForegroundIndex, default=0};
	__property int BackgroundIndex = {read=FBackgroundIndex, write=SetBackgroundIndex, default=0};
	__property bool ForegroundEnabled = {read=FForegroundEnabled, write=EnableForeground, default=1};
	__property bool BackgroundEnabled = {read=FBackgroundEnabled, write=EnableBackground, default=1};
	__property Font ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property int Selection = {read=FSelection, write=SetSelection, default=0};
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnClick ;
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
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TColorGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TColorGrid(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint NumPaletteEntries = 0x14;

}	/* namespace Colorgrd */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Colorgrd;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ColorGrd
