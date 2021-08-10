// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DesignMenus.pas' rev: 6.00

#ifndef DesignMenusHPP
#define DesignMenusHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Designmenus
{
//-- type declarations -------------------------------------------------------
__interface IMenuItems;
typedef System::DelphiInterface<IMenuItems> _di_IMenuItems;
__interface IMenuItem;
typedef System::DelphiInterface<IMenuItem> _di_IMenuItem;
__interface INTERFACE_UUID("{C9CC6C38-C96A-4514-8D6F-1D121727BFAF}") IMenuItems  : public IInterface 
{
	
public:
	virtual _di_IMenuItem __fastcall GetItem(int Index) = 0 ;
	virtual bool __fastcall SameAs(const System::_di_IInterface AItem) = 0 ;
	virtual _di_IMenuItem __fastcall Find(const WideString ACaption) = 0 ;
	virtual _di_IMenuItem __fastcall FindByName(const AnsiString AName) = 0 ;
	virtual int __fastcall Count(void) = 0 ;
	__property _di_IMenuItem Items[int Index] = {read=GetItem};
	virtual void __fastcall Clear(void) = 0 ;
	virtual _di_IMenuItem __fastcall AddItem(const WideString ACaption, Classes::TShortCut AShortCut, bool AChecked, bool AEnabled, Classes::TNotifyEvent AOnClick = 0x0, Classes::THelpContext hCtx = (Classes::THelpContext)(0x0), const AnsiString AName = "") = 0 /* overload */;
	virtual _di_IMenuItem __fastcall AddItem(Classes::TBasicAction* AAction, const AnsiString AName = "") = 0 /* overload */;
	virtual _di_IMenuItem __fastcall InsertItem(const WideString ACaption, Classes::TShortCut AShortCut, bool AChecked, bool AEnabled, Classes::TNotifyEvent AOnClick = 0x0, Classes::THelpContext hCtx = (Classes::THelpContext)(0x0), const AnsiString AName = "") = 0 /* overload */;
	virtual _di_IMenuItem __fastcall InsertItem(int Index, const WideString ACaption, Classes::TShortCut AShortCut, bool AChecked, bool AEnabled, Classes::TNotifyEvent AOnClick = 0x0, Classes::THelpContext hCtx = (Classes::THelpContext)(0x0), const AnsiString AName = "") = 0 /* overload */;
	virtual _di_IMenuItem __fastcall InsertItem(Classes::TBasicAction* AAction, const AnsiString AName = "") = 0 /* overload */;
	virtual _di_IMenuItem __fastcall InsertItem(int Index, Classes::TBasicAction* AAction, const AnsiString AName = "") = 0 /* overload */;
	virtual _di_IMenuItem __fastcall AddLine(const AnsiString AName = "") = 0 ;
	virtual _di_IMenuItem __fastcall InsertLine(const AnsiString AName = "") = 0 /* overload */;
	virtual _di_IMenuItem __fastcall InsertLine(int Index, const AnsiString AName = "") = 0 /* overload */;
};

__interface IMenu;
typedef System::DelphiInterface<IMenu> _di_IMenu;
__interface INTERFACE_UUID("{0993FAE4-17E2-4EB7-81DF-26634D7F9E16}") IMenu  : public IInterface 
{
	
public:
	virtual _di_IMenuItems __fastcall Items(void) = 0 ;
};

__interface IMainMenu;
typedef System::DelphiInterface<IMainMenu> _di_IMainMenu;
__interface INTERFACE_UUID("{5D137DC1-73F4-48CB-8351-E14A369AE924}") IMainMenu  : public IMenu 
{
	
};

__interface IPopupMenu;
typedef System::DelphiInterface<IPopupMenu> _di_IPopupMenu;
__interface INTERFACE_UUID("{E2E9ED8C-4D54-482B-AC62-23F1CEBFE414}") IPopupMenu  : public IMenu 
{
	
public:
	virtual void __fastcall Popup(int X, int Y) = 0 ;
	virtual Classes::TComponent* __fastcall PopupComponent(void) = 0 ;
};

__interface INTERFACE_UUID("{DAF029E1-9592-4B07-A450-A10056A2B9B5}") IMenuItem  : public IMenuItems 
{
	
public:
	virtual WideString __fastcall GetCaption(void) = 0 ;
	virtual void __fastcall SetCaption(const WideString ACaption) = 0 ;
	virtual bool __fastcall GetChecked(void) = 0 ;
	virtual void __fastcall SetChecked(bool AChecked) = 0 ;
	virtual bool __fastcall GetEnabled(void) = 0 ;
	virtual void __fastcall SetEnabled(bool AEnabled) = 0 ;
	virtual Byte __fastcall GetGroupIndex(void) = 0 ;
	virtual void __fastcall SetGroupIndex(Byte AGroupIndex) = 0 ;
	virtual Classes::THelpContext __fastcall GetHelpContext(void) = 0 ;
	virtual void __fastcall SetHelpContext(Classes::THelpContext AHelpContext) = 0 ;
	virtual AnsiString __fastcall GetHint(void) = 0 ;
	virtual void __fastcall SetHint(const AnsiString AHint) = 0 ;
	virtual bool __fastcall GetRadioItem(void) = 0 ;
	virtual void __fastcall SetRadioItem(bool ARadioItem) = 0 ;
	virtual Classes::TShortCut __fastcall GetShortCut(void) = 0 ;
	virtual void __fastcall SetShortCut(Classes::TShortCut AShortCut) = 0 ;
	virtual int __fastcall GetTag(void) = 0 ;
	virtual void __fastcall SetTag(int AValue) = 0 ;
	virtual bool __fastcall GetVisible(void) = 0 ;
	virtual void __fastcall SetVisible(bool AVisible) = 0 ;
	virtual AnsiString __fastcall Name(void) = 0 ;
	virtual int __fastcall MenuIndex(void) = 0 ;
	virtual _di_IMenuItem __fastcall Parent(void) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual bool __fastcall IsLine(void) = 0 ;
	__property WideString Caption = {read=GetCaption, write=SetCaption};
	__property bool Checked = {read=GetChecked, write=SetChecked};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled};
	__property Byte GroupIndex = {read=GetGroupIndex, write=SetGroupIndex};
	__property Classes::THelpContext HelpContext = {read=GetHelpContext, write=SetHelpContext};
	__property AnsiString Hint = {read=GetHint, write=SetHint};
	__property bool RadioItem = {read=GetRadioItem, write=SetRadioItem};
	__property Classes::TShortCut ShortCut = {read=GetShortCut, write=SetShortCut};
	__property int Tag = {read=GetTag, write=SetTag};
	__property bool Visible = {read=GetVisible, write=SetVisible};
};

#pragma option push -b-
enum TLocalMenuType { lmBase, lmModule, lmSelection, lmComponent };
#pragma option pop

typedef Set<TLocalMenuType, lmBase, lmComponent>  TLocalMenuTypes;

__interface IDesignLocalMenu;
typedef System::DelphiInterface<IDesignLocalMenu> _di_IDesignLocalMenu;
__interface INTERFACE_UUID("{70ED1A8D-6275-4BC8-813C-F6D9066FD6BB}") IDesignLocalMenu  : public IInterface 
{
	
public:
	virtual _di_IPopupMenu __fastcall BuildLocalMenu(TLocalMenuTypes Allow = (System::Set<TLocalMenuType, lmBase, lmComponent> () << TLocalMenuType(0) << TLocalMenuType(1) << TLocalMenuType(2) << TLocalMenuType(3) )) = 0 ;
	virtual void __fastcall InvokeLocalMenu(int X, int Y) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
#define CNoLocalMenus EMPTYSET
#define CAllLocalMenus (System::Set<TLocalMenuType, lmBase, lmComponent> () << TLocalMenuType(0) << TLocalMenuType(1) << TLocalMenuType(2) << TLocalMenuType(3) )
extern PACKAGE TLocalMenuTypes CLocalMenusIf[2];

}	/* namespace Designmenus */
using namespace Designmenus;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DesignMenus
