// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TabNotBk.pas' rev: 6.00

#ifndef TabNotBkHPP
#define TabNotBkHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Tabnotbk
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TPageChangeEvent)(System::TObject* Sender, int NewTab, bool &AllowChange);

class DELPHICLASS TTabPage;
class PASCALIMPLEMENTATION TTabPage : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
protected:
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	
public:
	__fastcall virtual TTabPage(Classes::TComponent* AOwner);
	
__published:
	__property Caption ;
	__property Height  = {stored=false};
	__property TabOrder  = {stored=false, default=-1};
	__property Visible  = {stored=false, default=1};
	__property Width  = {stored=false};
	__property Enabled  = {stored=false, default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTabPage(HWND ParentWindow) : Controls::TWinControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TTabPage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTabbedNotebook;
class PASCALIMPLEMENTATION TTabbedNotebook : public Comctrls::TCustomTabControl 
{
	typedef Comctrls::TCustomTabControl inherited;
	
private:
	Classes::TList* FPageList;
	Classes::TStrings* FAccess;
	int FPageIndex;
	Graphics::TFont* FTabFont;
	int FTabsPerRow;
	Classes::TNotifyEvent FOnClick;
	TPageChangeEvent FOnChange;
	AnsiString __fastcall GetActivePage();
	void __fastcall SetPages(Classes::TStrings* Value);
	void __fastcall SetActivePage(const AnsiString Value);
	void __fastcall SetTabFont(Graphics::TFont* Value);
	void __fastcall SetTabsPerRow(int NewTabCount);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	
protected:
	virtual void __fastcall AlignControls(Controls::TControl* AControl, Types::TRect &Rect);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	DYNAMIC Classes::TComponent* __fastcall GetChildOwner(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	void __fastcall SetPageIndex(int Value);
	virtual void __fastcall ShowControl(Controls::TControl* AControl);
	MESSAGE void __fastcall CMTabFontChanged(Messages::TMessage &Message);
	
public:
	__fastcall virtual TTabbedNotebook(Classes::TComponent* AOwner);
	__fastcall virtual ~TTabbedNotebook(void);
	int __fastcall GetIndexForPage(const AnsiString PageName);
	__property Graphics::TFont* TopFont = {read=FTabFont};
	void __fastcall TabFontChanged(System::TObject* Sender);
	
__published:
	__property AnsiString ActivePage = {read=GetActivePage, write=SetActivePage, stored=false};
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Constraints ;
	__property Enabled  = {default=1};
	__property int PageIndex = {read=FPageIndex, write=SetPageIndex, default=0};
	__property Classes::TStrings* Pages = {read=FAccess, write=SetPages, stored=false};
	__property Font ;
	__property int TabsPerRow = {read=FTabsPerRow, write=SetTabsPerRow, default=3};
	__property Graphics::TFont* TabFont = {read=FTabFont, write=SetTabFont};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TPageChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnContextPopup ;
	__property OnEnter ;
	__property OnExit ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTabbedNotebook(HWND ParentWindow) : Comctrls::TCustomTabControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word CM_TABFONTCHANGED = 0xb064;

}	/* namespace Tabnotbk */
using namespace Tabnotbk;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TabNotBk
