// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxDesignWindows.pas' rev: 6.00

#ifndef ClxDesignWindowsHPP
#define ClxDesignWindowsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComponentDesigner.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clxdesignwindows
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClxDesignWindow;
class PASCALIMPLEMENTATION TClxDesignWindow : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
private:
	Designintf::_di_IDesignerSelections FSelection;
	Classes::TComponent* FOwner;
	Designintf::_di_IDesigner FDesigner;
	Componentdesigner::_di_IComponentDesigner FComponentDesigner;
	bool FActive;
	void __fastcall ComponentRead(Classes::TComponent* Component);
	void __fastcall ReaderSetName(Classes::TReader* Reader, Classes::TComponent* Component, AnsiString &Name);
	
protected:
	DYNAMIC void __fastcall Activated(void);
	void __fastcall ActivateInspector(char Ch);
	bool __fastcall ClipboardComponents(void);
	void __fastcall CopyComponents(Classes::TComponent* Root, const Designintf::_di_IDesignerSelections Components);
	void __fastcall PasteComponents(Classes::TComponent* AOwner, Classes::TComponent* AParent, const Designintf::_di_IDesignerSelections Components);
	void __fastcall SetSelection(const Designintf::_di_IDesignerSelections Components);
	virtual AnsiString __fastcall UniqueName(Classes::TComponent* Component) = 0 ;
	
public:
	__fastcall virtual TClxDesignWindow(Classes::TComponent* AOwner);
	__fastcall virtual ~TClxDesignWindow(void);
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
	void __fastcall ForceActive(void);
	__property bool Active = {read=FActive, nodefault};
	__property Designintf::_di_IDesigner Designer = {read=FDesigner, write=FDesigner};
	__property Componentdesigner::_di_IComponentDesigner ComponentDesigner = {read=FComponentDesigner};
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClxDesignWindow(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TClxDesignWindow(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
private:
	void *__IDesignWindow;	/* Designintf::IDesignWindow */
	void *__IEditHandler;	/* Designintf::IEditHandler */
	void *__IActivatable;	/* Designintf::IActivatable [Activate=ForceActive] */
	
public:
	operator IActivatable*(void) { return (IActivatable*)&__IActivatable; }
	operator IEditHandler*(void) { return (IEditHandler*)&__IEditHandler; }
	operator IDesignNotification*(void) { return (IDesignNotification*)&__IDesignWindow; }
	operator IDesignWindow*(void) { return (IDesignWindow*)&__IDesignWindow; }
	operator IInterface*(void) { return (IInterface*)&__IEditHandler; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Clxdesignwindows */
using namespace Clxdesignwindows;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxDesignWindows
