// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ToolWnds.pas' rev: 6.00

#ifndef ToolWndsHPP
#define ToolWndsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <IniFiles.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ToolWin.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
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

namespace Toolwnds
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TToolbarDesignWindow;
class PASCALIMPLEMENTATION TToolbarDesignWindow : public Designwindows::TDesignWindow 
{
	typedef Designwindows::TDesignWindow inherited;
	
__published:
	Comctrls::TToolBar* ToolBar1;
	Extctrls::TSplitter* Splitter1;
	Menus::TPopupMenu* PopupMenu1;
	Actnlist::TActionList* ActionList1;
	Actnlist::TAction* ToolbarCmd;
	Actnlist::TAction* TextLabelsCmd;
	Menus::TMenuItem* Toolbar2;
	Menus::TPopupMenu* PopupMenu2;
	Menus::TMenuItem* TextLabels1;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Splitter1Moved(System::TObject* Sender);
	void __fastcall Splitter1CanResize(System::TObject* Sender, int &NewSize, bool &Accept);
	void __fastcall ToolbarCmdExecute(System::TObject* Sender);
	void __fastcall TextLabelsCmdExecute(System::TObject* Sender);
	void __fastcall ToolbarCmdUpdate(System::TObject* Sender);
	void __fastcall TextLabelsCmdUpdate(System::TObject* Sender);
	
private:
	bool FLargeButtons;
	bool __fastcall GetLargeButtons(void);
	void __fastcall SetLargeButtons(bool Value);
	
protected:
	virtual void __fastcall ResizeButtons(bool Large);
	
public:
	__property bool LargeButtons = {read=GetLargeButtons, write=SetLargeButtons, nodefault};
public:
	#pragma option push -w-inl
	/* TDesignWindow.Create */ inline __fastcall virtual TToolbarDesignWindow(Classes::TComponent* AOwner) : Designwindows::TDesignWindow(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TToolbarDesignWindow(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TToolbarDesignWindow(Classes::TComponent* AOwner, int Dummy) : Designwindows::TDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TToolbarDesignWindow(HWND ParentWindow) : Designwindows::TDesignWindow(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Toolwnds */
using namespace Toolwnds;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ToolWnds
