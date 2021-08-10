// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBLogDlg.pas' rev: 5.00

#ifndef DBLogDlgHPP
#define DBLogDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Dblogdlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TLoginDialog;
class PASCALIMPLEMENTATION TLoginDialog : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* Panel;
	Extctrls::TBevel* Bevel;
	Stdctrls::TLabel* DatabaseName;
	Stdctrls::TButton* OKButton;
	Stdctrls::TButton* CancelButton;
	Extctrls::TPanel* Panel1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Password;
	Stdctrls::TEdit* UserName;
	void __fastcall FormShow(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TLoginDialog(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TLoginDialog(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TLoginDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLoginDialog(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall LoginDialog(const AnsiString ADatabaseName, AnsiString &AUserName, AnsiString 
	&APassword);
extern PACKAGE bool __fastcall LoginDialogEx(const AnsiString ADatabaseName, AnsiString &AUserName, 
	AnsiString &APassword, bool NameReadOnly);
extern PACKAGE bool __fastcall RemoteLoginDialog(AnsiString &AUserName, AnsiString &APassword);

}	/* namespace Dblogdlg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dblogdlg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBLogDlg
