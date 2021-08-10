// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBPWDlg.pas' rev: 5.00

#ifndef DBPWDlgHPP
#define DBPWDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbpwdlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPasswordDialog;
class PASCALIMPLEMENTATION TPasswordDialog : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TEdit* Edit;
	Stdctrls::TButton* AddButton;
	Stdctrls::TButton* RemoveButton;
	Stdctrls::TButton* RemoveAllButton;
	Stdctrls::TButton* OKButton;
	Stdctrls::TButton* CancelButton;
	void __fastcall EditChange(System::TObject* Sender);
	void __fastcall AddButtonClick(System::TObject* Sender);
	void __fastcall RemoveButtonClick(System::TObject* Sender);
	void __fastcall RemoveAllButtonClick(System::TObject* Sender);
	void __fastcall OKButtonClick(System::TObject* Sender);
	
private:
	bool PasswordAdded;
	Classes::TComponent* FSession;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPasswordDialog(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPasswordDialog(Classes::TComponent* AOwner, 
		int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPasswordDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPasswordDialog(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall PasswordDialog(Classes::TComponent* ASession);

}	/* namespace Dbpwdlg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dbpwdlg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBPWDlg
