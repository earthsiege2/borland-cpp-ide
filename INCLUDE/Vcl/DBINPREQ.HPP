// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dbinpreq.pas' rev: 6.00

#ifndef dbinpreqHPP
#define dbinpreqHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <BDE.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbinpreq
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TInputReqDialog;
class PASCALIMPLEMENTATION TInputReqDialog : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OKButton;
	Stdctrls::TButton* CancelButton;
	Extctrls::TPanel* InputOptions;
	Stdctrls::TCheckBox* NoPromptAgain;
	Stdctrls::TLabel* ErrorHelp;
	Stdctrls::TLabel* InputMessage;
	Extctrls::TPanel* ErrorGroupBox;
	Extctrls::TPanel* ErrorGoupBoxSpacer;
	Extctrls::TPanel* DescriptionGroupBox;
	Extctrls::TPanel* DescriptionGroupBoxSpacer;
	void __fastcall InputOptionsClick(System::TObject* Sender);
	
private:
	Bde::CBInputDesc *FCBInfo;
	int FSelection;
	void __fastcall SetCBInfo(Bde::CBInputDesc &CBInfo);
	void __fastcall GetCBInfo(Bde::CBInputDesc &CBInfo);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TInputReqDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TInputReqDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TInputReqDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TInputReqDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Bde::CBRType __fastcall InputRequest(Bde::CBInputDesc &InputReqInfo);

}	/* namespace Dbinpreq */
using namespace Dbinpreq;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// dbinpreq
