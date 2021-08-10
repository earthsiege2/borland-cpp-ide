// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DesignWindows.pas' rev: 6.00

#ifndef DesignWindowsHPP
#define DesignWindowsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComponentDesigner.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Designwindows
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDesignWindow;
class PASCALIMPLEMENTATION TDesignWindow : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
private:
	Designintf::_di_IDesignerSelections FSelection;
	Classes::TComponent* FOwner;
	Designintf::_di_IDesigner FDesigner;
	Componentdesigner::_di_IComponentDesigner FComponentDesigner;
	bool FActive;
	void __fastcall ComponentRead(Classes::TComponent* Component);
	void __fastcall ReaderSetName(Classes::TReader* Reader, Classes::TComponent* Component, AnsiString &Name);
	HIDESBASE MESSAGE void __fastcall WMActivate(Messages::TWMActivate &Msg);
	
protected:
	DYNAMIC void __fastcall Activated(void);
	void __fastcall ActivateInspector(char Ch);
	bool __fastcall ClipboardComponents(void);
	void __fastcall CopyComponents(Classes::TComponent* Root, const Designintf::_di_IDesignerSelections Components);
	void __fastcall PasteComponents(Classes::TComponent* AOwner, Classes::TComponent* AParent, const Designintf::_di_IDesignerSelections Components);
	void __fastcall SetSelection(const Designintf::_di_IDesignerSelections Components);
	virtual AnsiString __fastcall UniqueName(Classes::TComponent* Component);
	
public:
	__fastcall virtual TDesignWindow(Classes::TComponent* AOwner);
	__fastcall virtual ~TDesignWindow(void);
	virtual Designintf::TEditState __fastcall GetEditState(void);
	virtual bool __fastcall EditAction(Designintf::TEditAction Action);
	virtual void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, Classes::TPersistent* Item);
	virtual void __fastcall ItemInserted(const Designintf::_di_IDesigner ADesigner, Classes::TPersistent* Item);
	virtual void __fastcall SelectionChanged(const Designintf::_di_IDesigner ADesigner, const Designintf::_di_IDesignerSelections ASelection);
	virtual void __fastcall DesignerOpened(const Designintf::_di_IDesigner Designer, bool AResurrecting);
	virtual void __fastcall DesignerClosed(const Designintf::_di_IDesigner Designer, bool AGoingDormant);
	virtual void __fastcall ItemsModified(const Designintf::_di_IDesigner Designer);
	virtual void __fastcall WindowHide(void);
	virtual void __fastcall WindowShow(void);
	__property bool Active = {read=FActive, nodefault};
	__property Designintf::_di_IDesigner Designer = {read=FDesigner, write=FDesigner};
	__property Componentdesigner::_di_IComponentDesigner ComponentDesigner = {read=FComponentDesigner};
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDesignWindow(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDesignWindow(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
private:
	void *__IDesignWindow;	/* Designintf::IDesignWindow */
	void *__IEditHandler;	/* Designintf::IEditHandler */
	void *__IActivatable;	/* Designintf::IActivatable */
	
public:
	operator IActivatable*(void) { return (IActivatable*)&__IActivatable; }
	operator IEditHandler*(void) { return (IEditHandler*)&__IEditHandler; }
	operator IDesignNotification*(void) { return (IDesignNotification*)&__IDesignWindow; }
	operator IDesignWindow*(void) { return (IDesignWindow*)&__IDesignWindow; }
	operator IInterface*(void) { return (IInterface*)&__IActivatable; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Designwindows */
using namespace Designwindows;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DesignWindows
