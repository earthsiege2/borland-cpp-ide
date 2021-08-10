// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AxMaxMin.pas' rev: 5.00

#ifndef AxMaxMinHPP
#define AxMaxMinHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Axmaxmin
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAxisMaxMin;
class PASCALIMPLEMENTATION TAxisMaxMin : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* BitBtn1;
	Stdctrls::TButton* BitBtn2;
	Stdctrls::TEdit* EMaximum;
	Stdctrls::TEdit* EMinimum;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BitBtn1Click(System::TObject* Sender);
	void __fastcall BitBtn2Click(System::TObject* Sender);
	
public:
	bool IsDateTime;
	double MaxMin;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAxisMaxMin(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAxisMaxMin(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAxisMaxMin(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAxisMaxMin(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Axmaxmin */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Axmaxmin;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AxMaxMin
