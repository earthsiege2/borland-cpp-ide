// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Dbedit.pas' rev: 6.00

#ifndef DbeditHPP
#define DbeditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDBEditForm;
class PASCALIMPLEMENTATION TDBEditForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* DatabaseName;
	Stdctrls::TLabel* Label1;
	Stdctrls::TComboBox* AliasName;
	Stdctrls::TLabel* Label2;
	Stdctrls::TComboBox* DriverName;
	Stdctrls::TLabel* Label3;
	Stdctrls::TMemo* DatabaseParams;
	Stdctrls::TButton* DefaultsButton;
	Stdctrls::TButton* ClearButton;
	Stdctrls::TGroupBox* GroupBox3;
	Stdctrls::TCheckBox* LoginPrompt;
	Stdctrls::TCheckBox* KeepConnection;
	Stdctrls::TButton* OkButton;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TButton* HelpButton;
	void __fastcall AliasNameChange(System::TObject* Sender);
	void __fastcall AliasNameDropDown(System::TObject* Sender);
	void __fastcall DriverNameChange(System::TObject* Sender);
	void __fastcall DriverNameDropDown(System::TObject* Sender);
	void __fastcall DefaultsButtonClick(System::TObject* Sender);
	void __fastcall ClearButtonClick(System::TObject* Sender);
	void __fastcall OkButtonClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	
private:
	Dbtables::TDatabase* Database;
	bool __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDBEditForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDBEditForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDBEditForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBEditForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditDatabase(Dbtables::TDatabase* ADatabase);

}	/* namespace Dbedit */
using namespace Dbedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dbedit
