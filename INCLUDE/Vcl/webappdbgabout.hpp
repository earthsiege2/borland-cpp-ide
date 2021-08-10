// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebAppDbgAbout.pas' rev: 6.00

#ifndef WebAppDbgAboutHPP
#define WebAppDbgAboutHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Webappdbgabout
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAboutBox;
class PASCALIMPLEMENTATION TAboutBox : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OKButton;
	Extctrls::TBevel* Bevel1;
	Stdctrls::TLabel* PhysMem;
	Stdctrls::TLabel* OS;
	Stdctrls::TLabel* Label3;
	Extctrls::TPanel* DetailsPanel;
	Extctrls::TPaintBox* Painter;
	Stdctrls::TLabel* Copyright;
	Stdctrls::TLabel* Version;
	Stdctrls::TLabel* SKUName;
	Extctrls::TImage* Logo;
	Stdctrls::TLabel* CompanyName;
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	void __fastcall InitializeCaptions(void);
	void __fastcall SetOSInfo(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAboutBox(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAboutBox(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAboutBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAboutBox(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::ResourceString _sMemKB;
#define Webappdbgabout_sMemKB System::LoadResourceString(&Webappdbgabout::_sMemKB)
extern PACKAGE void __fastcall ShowAboutBox(void);

}	/* namespace Webappdbgabout */
using namespace Webappdbgabout;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebAppDbgAbout
