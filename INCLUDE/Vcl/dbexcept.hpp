// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DbExcept.pas' rev: 6.00

#ifndef DbExceptHPP
#define DbExceptHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbexcept
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDbEngineErrorDlg;
class PASCALIMPLEMENTATION TDbEngineErrorDlg : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* BasicPanel;
	Extctrls::TPanel* DetailsPanel;
	Stdctrls::TLabel* BDELabel;
	Stdctrls::TLabel* NativeLabel;
	Stdctrls::TMemo* DbMessageText;
	Stdctrls::TEdit* DbResult;
	Stdctrls::TEdit* DbCatSub;
	Stdctrls::TEdit* NativeResult;
	Stdctrls::TButton* BackBtn;
	Stdctrls::TButton* NextBtn;
	Extctrls::TPanel* ButtonPanel;
	Stdctrls::TButton* DetailsBtn;
	Stdctrls::TButton* OKBtn;
	Extctrls::TPanel* IconPanel;
	Extctrls::TImage* IconImage;
	Extctrls::TPanel* TopPanel;
	Stdctrls::TLabel* ErrorText;
	Extctrls::TPanel* RightPanel;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BackClick(System::TObject* Sender);
	void __fastcall NextClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall DetailsBtnClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Forms::TExceptionEvent FPrevOnException;
	Dbtables::EDBEngineError* FDbException;
	int FDetailsHeight;
	int CurItem;
	AnsiString FDetails;
	void __fastcall HandleException(System::TObject* Sender, Sysutils::Exception* E);
	void __fastcall SwitchDetails(void);
	void __fastcall ShowError(void);
	
public:
	void __fastcall HookExceptions(void);
	Controls::TModalResult __fastcall ShowException(Dbtables::EDBEngineError* Error);
	__property Dbtables::EDBEngineError* DbException = {read=FDbException, write=FDbException};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDbEngineErrorDlg(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDbEngineErrorDlg(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDbEngineErrorDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDbEngineErrorDlg(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TDbEngineErrorDlg* DbEngineErrorDlg;

}	/* namespace Dbexcept */
using namespace Dbexcept;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DbExcept
