// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrLogDetailDlg.pas' rev: 6.00

#ifndef SvrLogDetailDlgHPP
#define SvrLogDetailDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Registry.hpp>	// Pascal unit
#include <SvrLogDetailFrame.hpp>	// Pascal unit
#include <SvrLogFrame.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
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

namespace Svrlogdetaildlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TLogDetail;
class PASCALIMPLEMENTATION TLogDetail : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Actnlist::TActionList* ActionList1;
	Actnlist::TAction* PrevAction;
	Actnlist::TAction* NextAction;
	Actnlist::TAction* CloseAction;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Stdctrls::TButton* Button3;
	Svrlogdetailframe::TLogDetailFrame* LogDetailFrame;
	void __fastcall PrevActionExecute(System::TObject* Sender);
	void __fastcall PrevActionUpdate(System::TObject* Sender);
	void __fastcall NextActionExecute(System::TObject* Sender);
	void __fastcall NextActionUpdate(System::TObject* Sender);
	void __fastcall CloseActionExecute(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
private:
	Svrlogframe::TLogFrame* FLogFrame;
	
public:
	__fastcall virtual TLogDetail(Classes::TComponent* AOwner);
	void __fastcall Load(Registry::TRegIniFile* Reg, const AnsiString Section);
	void __fastcall Save(Registry::TRegIniFile* Reg, const AnsiString Section);
	__property Svrlogframe::TLogFrame* LogFrame = {read=FLogFrame, write=FLogFrame};
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TLogDetail(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TLogDetail(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLogDetail(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TLogDetail* FLogDetail;

}	/* namespace Svrlogdetaildlg */
using namespace Svrlogdetaildlg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrLogDetailDlg
