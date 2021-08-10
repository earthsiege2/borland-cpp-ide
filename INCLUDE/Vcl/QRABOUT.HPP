// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'qrabout.pas' rev: 5.00

#ifndef qraboutHPP
#define qraboutHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ShellAPI.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrabout
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRAboutBox;
class PASCALIMPLEMENTATION TQRAboutBox : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TImage* Image1;
	Stdctrls::TButton* Button1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* VisitLabel;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* OrderLabel;
	Extctrls::TBevel* Bevel1;
	Stdctrls::TLabel* Label5;
	Extctrls::TImage* Image2;
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Label3Click(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TQRAboutBox(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TQRAboutBox(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TQRAboutBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRAboutBox(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrabout */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Qrabout;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// qrabout
