// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXDIMEDT.pas' rev: 6.00

#ifndef MXDIMEDTHPP
#define MXDIMEDTHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DesignWindows.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <MXDCONST.hpp>	// Pascal unit
#include <Mxstore.hpp>	// Pascal unit
#include <MXDB.hpp>	// Pascal unit
#include <MXGRID.hpp>	// Pascal unit
#include <Mxconsts.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxdimedt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDimEditor;
class PASCALIMPLEMENTATION TDimEditor : public Designwindows::TDesignWindow 
{
	typedef Designwindows::TDesignWindow inherited;
	
__published:
	Stdctrls::TListBox* DimListBox1;
	void __fastcall DimListBox1Click(System::TObject* Sender);
	
private:
	Classes::TCollection* myDims;
	Forms::TCustomForm* myForm;
	Designintf::_di_IDesigner myDesigner;
	Classes::TComponent* myObject;
	void __fastcall UpdateSelection(void);
	void __fastcall UpdateList(void);
	
protected:
	virtual AnsiString __fastcall UniqueName(Classes::TComponent* Component);
	DYNAMIC void __fastcall Activated(void);
	
public:
	virtual void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, Classes::TPersistent* AItem);
	virtual void __fastcall DesignerClosed(const Designintf::_di_IDesigner ADesigner, bool AGoingDormant);
	virtual void __fastcall ItemsModified(const Designintf::_di_IDesigner ADesigner);
public:
	#pragma option push -w-inl
	/* TDesignWindow.Create */ inline __fastcall virtual TDimEditor(Classes::TComponent* AOwner) : Designwindows::TDesignWindow(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TDimEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDimEditor(Classes::TComponent* AOwner, int Dummy) : Designwindows::TDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDimEditor(HWND ParentWindow) : Designwindows::TDesignWindow(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowDisplayDimEditor(const Designintf::_di_IDesigner Designer, Classes::TComponent* anObject);

}	/* namespace Mxdimedt */
using namespace Mxdimedt;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXDIMEDT
