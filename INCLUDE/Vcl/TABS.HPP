// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Tabs.pas' rev: 5.00

#ifndef TabsHPP
#define TabsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Tabs
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TScrollBtn { sbLeft, sbRight };
#pragma option pop

class DELPHICLASS TScroller;
class PASCALIMPLEMENTATION TScroller : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	int FMin;
	int FMax;
	int FPosition;
	Classes::TNotifyEvent FOnClick;
	int FChange;
	Graphics::TBitmap* Bitmap;
	bool Pressed;
	bool Down;
	TScrollBtn Current;
	int pWidth;
	int pHeight;
	void __fastcall SetMin(int Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetPosition(int Value);
	bool __fastcall CanScrollLeft(void);
	bool __fastcall CanScrollRight(void);
	HIDESBASE void __fastcall DoMouseDown(int X);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseMove(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	
public:
	__fastcall virtual TScroller(Classes::TComponent* AOwner);
	__fastcall virtual ~TScroller(void);
	virtual void __fastcall Paint(void);
	
__published:
	__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
	__property int Min = {read=FMin, write=SetMin, default=0};
	__property int Max = {read=FMax, write=SetMax, default=0};
	__property int Position = {read=FPosition, write=SetPosition, default=0};
	__property int Change = {read=FChange, write=FChange, default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TScroller(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TTabList;
class DELPHICLASS TTabSet;
#pragma option push -b-
enum TTabStyle { tsStandard, tsOwnerDraw };
#pragma option pop

typedef void __fastcall (__closure *TMeasureTabEvent)(System::TObject* Sender, int Index, int &TabWidth
	);

typedef void __fastcall (__closure *TDrawTabEvent)(System::TObject* Sender, Graphics::TCanvas* TabCanvas
	, const Windows::TRect &R, int Index, bool Selected);

typedef void __fastcall (__closure *TTabChangeEvent)(System::TObject* Sender, int NewTab, bool &AllowChange
	);

#pragma option push -b-
enum TEdgeType { etNone, etFirstIsSel, etFirstNotSel, etLastIsSel, etLastNotSel, etNotSelToSel, etSelToNotSel, 
	etNotSelToNotSel };
#pragma option pop

class PASCALIMPLEMENTATION TTabSet : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	int FStartMargin;
	int FEndMargin;
	Classes::TStrings* FTabs;
	int FTabIndex;
	int FFirstIndex;
	int FVisibleTabs;
	Graphics::TColor FSelectedColor;
	Graphics::TColor FUnselectedColor;
	Graphics::TColor FBackgroundColor;
	bool FDitherBackground;
	bool FAutoScroll;
	TTabStyle FStyle;
	int FOwnerDrawHeight;
	TMeasureTabEvent FOnMeasureTab;
	TDrawTabEvent FOnDrawTab;
	TTabChangeEvent FOnChange;
	Controls::TImageList* ImageList;
	Graphics::TBitmap* MemBitmap;
	Graphics::TBitmap* BrushBitmap;
	Classes::TList* TabPositions;
	int FTabHeight;
	TScroller* Scroller;
	bool FDoFix;
	void __fastcall SetSelectedColor(Graphics::TColor Value);
	void __fastcall SetUnselectedColor(Graphics::TColor Value);
	void __fastcall SetBackgroundColor(Graphics::TColor Value);
	void __fastcall SetDitherBackground(bool Value);
	void __fastcall SetAutoScroll(bool Value);
	void __fastcall SetStartMargin(int Value);
	void __fastcall SetEndMargin(int Value);
	void __fastcall SetTabIndex(int Value);
	void __fastcall SetFirstIndex(int Value);
	void __fastcall SetTabList(Classes::TStrings* Value);
	void __fastcall SetTabStyle(TTabStyle Value);
	void __fastcall SetTabHeight(int Value);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	void __fastcall PaintEdge(int X, int Y, int H, TEdgeType Edge);
	void __fastcall CreateBrushPattern(Graphics::TBitmap* Bitmap);
	int __fastcall CalcTabPositions(int Start, int Stop, Graphics::TCanvas* Canvas, int First);
	void __fastcall CreateScroller(void);
	void __fastcall InitBitmaps(void);
	void __fastcall DoneBitmaps(void);
	void __fastcall CreateEdgeParts(void);
	void __fastcall FixTabPos(void);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	void __fastcall ScrollClick(System::TObject* Sender);
	void __fastcall ReadIntData(Classes::TReader* Reader);
	void __fastcall ReadBoolData(Classes::TReader* Reader);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall DrawTab(Graphics::TCanvas* TabCanvas, const Windows::TRect &R, int Index, bool 
		Selected);
	bool __fastcall CanChange(int NewIndex);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall MeasureTab(int Index, int &TabWidth);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	
public:
	__fastcall virtual TTabSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TTabSet(void);
	int __fastcall ItemAtPos(const Windows::TPoint &Pos);
	Windows::TRect __fastcall ItemRect(int Item);
	HIDESBASE void __fastcall SelectNext(bool Direction);
	__property Canvas ;
	__property int FirstIndex = {read=FFirstIndex, write=SetFirstIndex, default=0};
	
__published:
	__property Align ;
	__property Anchors ;
	__property bool AutoScroll = {read=FAutoScroll, write=SetAutoScroll, default=1};
	__property Graphics::TColor BackgroundColor = {read=FBackgroundColor, write=SetBackgroundColor, default=-2147483633
		};
	__property Constraints ;
	__property bool DitherBackground = {read=FDitherBackground, write=SetDitherBackground, default=1};
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property int EndMargin = {read=FEndMargin, write=SetEndMargin, default=5};
	__property Font ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property int StartMargin = {read=FStartMargin, write=SetStartMargin, default=5};
	__property Graphics::TColor SelectedColor = {read=FSelectedColor, write=SetSelectedColor, default=-2147483633
		};
	__property TTabStyle Style = {read=FStyle, write=SetTabStyle, default=0};
	__property int TabHeight = {read=FOwnerDrawHeight, write=SetTabHeight, default=20};
	__property Classes::TStrings* Tabs = {read=FTabs, write=SetTabList};
	__property int TabIndex = {read=FTabIndex, write=SetTabIndex, default=-1};
	__property Graphics::TColor UnselectedColor = {read=FUnselectedColor, write=SetUnselectedColor, default=-2147483643
		};
	__property Visible ;
	__property int VisibleTabs = {read=FVisibleTabs, nodefault};
	__property OnClick ;
	__property TTabChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnDragDrop ;
	__property OnDragOver ;
	__property TDrawTabEvent OnDrawTab = {read=FOnDrawTab, write=FOnDrawTab};
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property TMeasureTabEvent OnMeasureTab = {read=FOnMeasureTab, write=FOnMeasureTab};
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTabSet(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTabList : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	TTabSet* Tabs;
	
public:
	virtual void __fastcall Insert(int Index, const AnsiString S);
	virtual void __fastcall Delete(int Index);
	virtual int __fastcall Add(const AnsiString S);
	virtual void __fastcall Put(int Index, const AnsiString S);
	virtual void __fastcall Clear(void);
	virtual void __fastcall AddStrings(Classes::TStrings* Strings);
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TTabList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTabList(void) : Classes::TStringList() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TEdgePart { epSelectedLeft, epUnselectedLeft, epSelectedRight, epUnselectedRight };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Tabs */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Tabs;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Tabs
