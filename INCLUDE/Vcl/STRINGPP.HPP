// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StringPP.pas' rev: 6.00

#ifndef StringPPHPP
#define StringPPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <StdMain.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <AxCtrls.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <ComServ.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stringpp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStringsPropPage;
class PASCALIMPLEMENTATION TStringsPropPage : public Axctrls::TPropertyPage 
{
	typedef Axctrls::TPropertyPage inherited;
	
__published:
	Stdctrls::TButton* ClearBtn;
	Stdctrls::TStaticText* StaticText2;
	Stdctrls::TComboBox* PropName;
	Stdctrls::TMemo* StringMemo;
	Stdctrls::TLabel* Label1;
	void __fastcall ClearBtnClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall PropNameChange(System::TObject* Sender);
	void __fastcall PropNameClick(System::TObject* Sender);
	
private:
	Stdmain::TPropApplyList* ApplyList;
	
public:
	virtual void __fastcall UpdatePropertyPage(void);
	virtual void __fastcall UpdateObject(void);
public:
	#pragma option push -w-inl
	/* TPropertyPage.Create */ inline __fastcall virtual TStringsPropPage(Classes::TComponent* AOwner) : Axctrls::TPropertyPage(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyPage.Destroy */ inline __fastcall virtual ~TStringsPropPage(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TStringsPropPage(Classes::TComponent* AOwner, int Dummy) : Axctrls::TPropertyPage(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TStringsPropPage(HWND ParentWindow) : Axctrls::TPropertyPage(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Stringpp */
using namespace Stringpp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StringPP
