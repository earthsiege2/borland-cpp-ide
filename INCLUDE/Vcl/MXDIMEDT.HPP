// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'mxdimedt.pas' rev: 5.00

#ifndef mxdimedtHPP
#define mxdimedtHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DsgnWnds.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <mxdconst.hpp>	// Pascal unit
#include <mxstore.hpp>	// Pascal unit
#include <mxDB.hpp>	// Pascal unit
#include <mxgrid.hpp>	// Pascal unit
#include <mxConsts.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
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
class PASCALIMPLEMENTATION TDimEditor : public Dsgnwnds::TDesignWindow 
{
	typedef Dsgnwnds::TDesignWindow inherited;
	
__published:
	Stdctrls::TListBox* DimListBox1;
	void __fastcall DimListBox1Click(System::TObject* Sender);
	
private:
	Classes::TCollection* myDims;
	Forms::TCustomForm* myForm;
	Dsgnintf::_di_IFormDesigner myDesigner;
	Classes::TComponent* myObject;
	void __fastcall UpdateSelection(void);
	void __fastcall UpdateList(void);
	
protected:
	virtual AnsiString __fastcall UniqueName(Classes::TComponent* Component);
	DYNAMIC void __fastcall Activated(void);
	
public:
	virtual void __fastcall ComponentDeleted(Dsgnintf::_di_IPersistent Component);
	virtual void __fastcall FormClosed(Forms::TCustomForm* AForm);
	virtual void __fastcall FormModified(void);
public:
	#pragma option push -w-inl
	/* TDesignWindow.Create */ inline __fastcall virtual TDimEditor(Classes::TComponent* AOwner) : Dsgnwnds::TDesignWindow(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TDimEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDimEditor(Classes::TComponent* AOwner, int Dummy
		) : Dsgnwnds::TDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDimEditor(HWND ParentWindow) : Dsgnwnds::TDesignWindow(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowDisplayDimEditor(const Forms::_di_IDesigner Designer, Classes::TComponent* 
	anObject);

}	/* namespace Mxdimedt */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mxdimedt;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// mxdimedt
