// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MaskProp.pas' rev: 6.00

#ifndef MaskPropHPP
#define MaskPropHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <MaskUtils.hpp>	// Pascal unit
#include <Mask.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Maskprop
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMaskProperty;
class PASCALIMPLEMENTATION TMaskProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TMaskProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TMaskProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMaskForm;
class PASCALIMPLEMENTATION TMaskForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TEdit* InputMask;
	Stdctrls::TLabel* Label1;
	Stdctrls::TListBox* ListBox1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Mask::TMaskEdit* TestEdit;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* Blanks;
	Extctrls::TBevel* Bevel1;
	Stdctrls::TCheckBox* SaveMaskCheck;
	Stdctrls::TButton* Masks;
	Dialogs::TOpenDialog* OpenDialog1;
	Stdctrls::TButton* OKButton;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TButton* HelpButton;
	void __fastcall BlanksChange(System::TObject* Sender);
	void __fastcall InputMaskChange(System::TObject* Sender);
	void __fastcall ListDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	void __fastcall ListBoxSelect(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall MasksClick(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	
private:
	bool FInEditChange;
	AnsiString __fastcall AddBlanks(AnsiString Value);
	void __fastcall LoadMaskList(const AnsiString FileName);
	
protected:
	AnsiString __fastcall GetListMaskValue(int Index);
	AnsiString __fastcall GetMaskValue(const AnsiString Value);
	virtual void __fastcall Loaded(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TMaskForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TMaskForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TMaskForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMaskForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TMaskForm* MaskForm;
extern PACKAGE bool __fastcall EditInputMask(AnsiString &InputMask, const AnsiString InitialDir);

}	/* namespace Maskprop */
using namespace Maskprop;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MaskProp
