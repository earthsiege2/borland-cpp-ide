// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StdActnMenus.pas' rev: 6.00

#ifndef StdActnMenusHPP
#define StdActnMenusHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ToolWin.hpp>	// Pascal unit
#include <ActnCtrls.hpp>	// Pascal unit
#include <ActnMan.hpp>	// Pascal unit
#include <ActnMenus.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "dclact.lib"

namespace Stdactnmenus
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStandardMenuItem;
class PASCALIMPLEMENTATION TStandardMenuItem : public Actnmenus::TCustomMenuItem 
{
	typedef Actnmenus::TCustomMenuItem inherited;
	
private:
	AnsiString FNoPrefix;
	
protected:
	HIDESBASE MESSAGE void __fastcall CMTextchanged(Messages::TMessage &Message);
	virtual void __fastcall DrawBackground(Types::TRect &PaintRect);
	virtual void __fastcall DrawGlyph(const Types::TPoint &Location);
	virtual void __fastcall DrawSeparator(const int Offset);
	virtual void __fastcall DrawText(Types::TRect &Rect, unsigned &Flags, AnsiString Text);
public:
	#pragma option push -w-inl
	/* TCustomMenuItem.Create */ inline __fastcall virtual TStandardMenuItem(Classes::TComponent* AOwner) : Actnmenus::TCustomMenuItem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomMenuItem.Destroy */ inline __fastcall virtual ~TStandardMenuItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStandardMenuButton;
class PASCALIMPLEMENTATION TStandardMenuButton : public Actnmenus::TCustomMenuButton 
{
	typedef Actnmenus::TCustomMenuButton inherited;
	
public:
	#pragma option push -w-inl
	/* TCustomMenuButton.Destroy */ inline __fastcall virtual ~TStandardMenuButton(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomButtonControl.Create */ inline __fastcall virtual TStandardMenuButton(Classes::TComponent* AOwner) : Actnmenus::TCustomMenuButton(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TStandardMenuPopup;
class PASCALIMPLEMENTATION TStandardMenuPopup : public Actnmenus::TCustomActionPopupMenu 
{
	typedef Actnmenus::TCustomActionPopupMenu inherited;
	
protected:
	virtual void __fastcall NCPaint(HDC DC);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Messages::TWMNCCalcSize &Message);
	
public:
	__fastcall virtual TStandardMenuPopup(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomActionPopupMenu.Destroy */ inline __fastcall virtual ~TStandardMenuPopup(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TStandardMenuPopup(HWND ParentWindow) : Actnmenus::TCustomActionPopupMenu(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TStandardAddRemoveItem;
class PASCALIMPLEMENTATION TStandardAddRemoveItem : public Actnmenus::TCustomAddRemoveItem 
{
	typedef Actnmenus::TCustomAddRemoveItem inherited;
	
protected:
	virtual void __fastcall DrawBackground(Types::TRect &PaintRect);
	virtual void __fastcall DrawGlyph(const Types::TPoint &Location);
	virtual void __fastcall DrawText(Types::TRect &Rect, unsigned &Flags, AnsiString Text);
public:
	#pragma option push -w-inl
	/* TCustomMenuItem.Create */ inline __fastcall virtual TStandardAddRemoveItem(Classes::TComponent* AOwner) : Actnmenus::TCustomAddRemoveItem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomMenuItem.Destroy */ inline __fastcall virtual ~TStandardAddRemoveItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStandardCustomizePopup;
class PASCALIMPLEMENTATION TStandardCustomizePopup : public Actnmenus::TCustomizeActionToolBar 
{
	typedef Actnmenus::TCustomizeActionToolBar inherited;
	
public:
	__fastcall virtual TStandardCustomizePopup(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomizeActionToolBar.Destroy */ inline __fastcall virtual ~TStandardCustomizePopup(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TStandardCustomizePopup(HWND ParentWindow) : Actnmenus::TCustomizeActionToolBar(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RegisterStandardMenus(void);

}	/* namespace Stdactnmenus */
using namespace Stdactnmenus;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StdActnMenus
