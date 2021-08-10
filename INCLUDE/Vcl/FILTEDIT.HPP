// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'FiltEdit.pas' rev: 5.00

#ifndef FiltEditHPP
#define FiltEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Tabs.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Filtedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFilterEditor;
class PASCALIMPLEMENTATION TFilterEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TBevel* Bevel1;
	Stdctrls::TButton* OKButton;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TButton* HelpButton;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall HelpBtnClick(System::TObject* Sender);
	
private:
	void __fastcall SetFilter(AnsiString Value);
	AnsiString __fastcall GetFilter();
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFilterEditor(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFilterEditor(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFilterEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFilterEditor(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TFilterProperty;
class PASCALIMPLEMENTATION TFilterProperty : public Dsgnintf::TStringProperty 
{
	typedef Dsgnintf::TStringProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFilterProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFilterProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Filtedit */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Filtedit;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FiltEdit
