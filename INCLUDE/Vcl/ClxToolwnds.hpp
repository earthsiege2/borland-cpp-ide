// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxToolWnds.pas' rev: 6.00

#ifndef ClxToolWndsHPP
#define ClxToolWndsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QActnList.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <ClxDesignWindows.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QComCtrls.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <QDialogs.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clxtoolwnds
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClxToolbarDesignWindow;
class PASCALIMPLEMENTATION TClxToolbarDesignWindow : public Clxdesignwindows::TClxDesignWindow 
{
	typedef Clxdesignwindows::TClxDesignWindow inherited;
	
__published:
	Qcomctrls::TToolBar* ToolBar1;
	Qextctrls::TSplitter* Splitter1;
	Qmenus::TPopupMenu* PopupMenu1;
	Qmenus::TPopupMenu* PopupMenu2;
	Qmenus::TMenuItem* Toolbar2;
	Qmenus::TMenuItem* Textlabels1;
	Qactnlist::TAction* TextLabelsCmd;
	Qactnlist::TAction* ToolbarCmd;
	void __fastcall Splitter1CanResize(System::TObject* Sender, int &NewSize, bool &Accept);
	void __fastcall Splitter1Moved(System::TObject* Sender);
	void __fastcall Textlabels1Click(System::TObject* Sender);
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
	/* TClxDesignWindow.Create */ inline __fastcall virtual TClxToolbarDesignWindow(Classes::TComponent* AOwner) : Clxdesignwindows::TClxDesignWindow(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TClxDesignWindow.Destroy */ inline __fastcall virtual ~TClxToolbarDesignWindow(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClxToolbarDesignWindow(Classes::TComponent* AOwner, int Dummy) : Clxdesignwindows::TClxDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TClxToolbarDesignWindow(Qt::QWidgetH* ParentWidget) : Clxdesignwindows::TClxDesignWindow(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Clxtoolwnds */
using namespace Clxtoolwnds;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxToolWnds
