// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DsgnWnds.pas' rev: 5.00

#ifndef DsgnWndsHPP
#define DsgnWndsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DsgnIntf.hpp>	// Pascal unit
#include <LibIntf.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dsgnwnds
{
//-- type declarations -------------------------------------------------------
__interface IDesignWindowActions;
typedef System::DelphiInterface<IDesignWindowActions> _di_IDesignWindowActions;
__interface INTERFACE_UUID("{A0BF324F-D5A2-11D2-B726-00C04FA35D12}") IDesignWindowActions  : public IUnknown 
	
{
	
public:
	virtual void __fastcall WindowHide(void) = 0 ;
	virtual void __fastcall WindowShow(void) = 0 ;
};

__interface IDesignEditQuery;
typedef System::DelphiInterface<IDesignEditQuery> _di_IDesignEditQuery;
__interface INTERFACE_UUID("{32501230-D336-11D2-B725-00C04FA35D12}") IDesignEditQuery  : public IUnknown 
	
{
	
public:
	virtual Dsgnintf::TEditState __fastcall GetEditState(void) = 0 ;
	virtual void __fastcall EditAction(Dsgnintf::TEditAction Action) = 0 ;
};

class DELPHICLASS TDesignWindow;
class PASCALIMPLEMENTATION TDesignWindow : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
private:
	Dsgnintf::TDesignerSelectionList* FSelection;
	Classes::TComponent* FOwner;
	Dsgnintf::_di_IFormDesigner FDesigner;
	bool FActive;
	void __fastcall ComponentRead(Classes::TComponent* Component);
	void __fastcall ReaderSetName(Classes::TReader* Reader, Classes::TComponent* Component, AnsiString 
		&Name);
	HIDESBASE MESSAGE void __fastcall WMActivate(Messages::TWMActivate &Msg);
	
protected:
	DYNAMIC void __fastcall Activated(void);
	void __fastcall ActivateInspector(char Ch);
	bool __fastcall ClipboardComponents(void);
	void __fastcall CopyComponents(Classes::TComponent* Root, Dsgnintf::TDesignerSelectionList* Components
		);
	void __fastcall PasteComponents(Classes::TComponent* AOwner, Classes::TComponent* AParent, Dsgnintf::TDesignerSelectionList* 
		Components);
	void __fastcall SetSelection(Dsgnintf::TDesignerSelectionList* Components);
	virtual AnsiString __fastcall UniqueName(Classes::TComponent* Component) = 0 ;
	
public:
	__fastcall virtual TDesignWindow(Classes::TComponent* AOwner);
	__fastcall virtual ~TDesignWindow(void);
	virtual Dsgnintf::TEditState __fastcall GetEditState(void);
	virtual void __fastcall EditAction(Dsgnintf::TEditAction Action);
	void __fastcall ItemDeleted(const Dsgnintf::_di_IPersistent Item);
	void __fastcall ItemInserted(const Dsgnintf::_di_IPersistent Item);
	void __fastcall SelectionChanged(const Dsgnintf::_di_IDesignerSelections ASelection)/* overload */;
		
	void __fastcall DesignerInitialized(const _di_IUnknown Designer);
	void __fastcall DesignerClosed(const _di_IUnknown Designer);
	void __fastcall ItemsModified(const _di_IUnknown Designer);
	virtual void __fastcall ComponentDeleted(Dsgnintf::_di_IPersistent Component);
	virtual void __fastcall ComponentInserted(Dsgnintf::_di_IPersistent Component);
	virtual void __fastcall SelectionChanged(Dsgnintf::TDesignerSelectionList* ASelection)/* overload */
		;
	virtual void __fastcall FormClosed(Forms::TCustomForm* AForm);
	virtual void __fastcall FormModified(void);
	virtual void __fastcall WindowHide(void);
	virtual void __fastcall WindowShow(void);
	__property bool Active = {read=FActive, nodefault};
	__property Dsgnintf::_di_IFormDesigner Designer = {read=FDesigner, write=FDesigner};
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDesignWindow(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDesignWindow(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
private:
	void *__IDesignNotification;	/* Dsgnintf::IDesignNotification */
	void *__IDesignEditQuery;	/* Dsgnwnds::IDesignEditQuery */
	
public:
	operator IDesignEditQuery*(void) { return (IDesignEditQuery*)&__IDesignEditQuery; }
	operator IDesignNotification*(void) { return (IDesignNotification*)&__IDesignNotification; }
	operator IUnknown*(void) { return (IUnknown*)&__IDesignEditQuery; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dsgnwnds */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dsgnwnds;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DsgnWnds
