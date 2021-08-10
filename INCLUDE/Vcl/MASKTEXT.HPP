// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MaskText.pas' rev: 5.00

#ifndef MaskTextHPP
#define MaskTextHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Mask.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Masktext
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMaskTextProperty;
class PASCALIMPLEMENTATION TMaskTextProperty : public Dsgnintf::TStringProperty 
{
	typedef Dsgnintf::TStringProperty inherited;
	
public:
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall Edit(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TMaskTextProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TMaskTextProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMaskTextForm;
class PASCALIMPLEMENTATION TMaskTextForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label3;
	Mask::TMaskEdit* TestEdit;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* EditMask;
	Stdctrls::TButton* OKButton;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TButton* HelpButton;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TMaskTextForm(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TMaskTextForm(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TMaskTextForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMaskTextForm(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TMaskTextForm* MaskTextForm;
extern PACKAGE bool __fastcall EditMaskText(const AnsiString Mask, AnsiString &MaskText);

}	/* namespace Masktext */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Masktext;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MaskText
