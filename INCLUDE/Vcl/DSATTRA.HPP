// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DSAttrA.pas' rev: 5.00

#ifndef DSAttrAHPP
#define DSAttrAHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <LibHelp.hpp>	// Pascal unit
#include <DRIntf.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dsattra
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAssociateAttributes;
class PASCALIMPLEMENTATION TAssociateAttributes : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OKBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TButton* HelpBtn;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TListBox* AttributeNamesList;
	Stdctrls::TEdit* Edit;
	void __fastcall OKBtnClick(System::TObject* Sender);
	void __fastcall CancelBtnClick(System::TObject* Sender);
	void __fastcall HelpBtnClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall EditChange(System::TObject* Sender);
	void __fastcall EditKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall ListBoxClick(System::TObject* Sender);
	void __fastcall ListBoxDblClick(System::TObject* Sender);
	
private:
	void __fastcall AddToList(const AnsiString Value);
	
public:
	bool __fastcall Execute(Drintf::TAttrID &AttrID, bool &Continue);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAssociateAttributes(Classes::TComponent* AOwner
		) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAssociateAttributes(Classes::TComponent* AOwner
		, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAssociateAttributes(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAssociateAttributes(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall GetAssociateAttributes(Drintf::TAttrID &AttrID, bool &Continue);

}	/* namespace Dsattra */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dsattra;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DSAttrA
