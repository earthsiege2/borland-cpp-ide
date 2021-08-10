// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Pageinfo.pas' rev: 5.00

#ifndef PageinfoHPP
#define PageinfoHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Pageinfo
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPageInfoDlg;
class PASCALIMPLEMENTATION TPageInfoDlg : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TEdit* edPageName;
	Stdctrls::TEdit* edPageContext;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TButton* BitBtn1;
	Stdctrls::TButton* BitBtn2;
	Stdctrls::TButton* BitBtn3;
	void __fastcall OKClick(System::TObject* Sender);
	void __fastcall BitBtn3Click(System::TObject* Sender);
	
private:
	void __fastcall SetPageName(const AnsiString Name);
	AnsiString __fastcall GetPageName();
	void __fastcall SetPageContext(Classes::THelpContext Context);
	Classes::THelpContext __fastcall GetPageContext(void);
	
public:
	__property AnsiString PageName = {read=GetPageName, write=SetPageName};
	__property Classes::THelpContext PageContext = {read=GetPageContext, write=SetPageContext, nodefault
		};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPageInfoDlg(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPageInfoDlg(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPageInfoDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPageInfoDlg(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Pageinfo */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Pageinfo;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Pageinfo
