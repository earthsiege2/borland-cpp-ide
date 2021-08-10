// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBSecurityEditor.pas' rev: 6.00

#ifndef IBSecurityEditorHPP
#define IBSecurityEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBXConst.hpp>	// Pascal unit
#include <IBServices.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibsecurityeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmIBSecurityEditor;
class PASCALIMPLEMENTATION TfrmIBSecurityEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label7;
	Stdctrls::TLabel* Label8;
	Stdctrls::TRadioButton* LocalRbtn;
	Stdctrls::TRadioButton* RemoteRbtn;
	Stdctrls::TEdit* ServerName;
	Stdctrls::TComboBox* Protocol;
	Extctrls::TPanel* Panel1;
	Stdctrls::TButton* OKBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TButton* HelpBtn;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* UserName;
	Stdctrls::TEdit* Password;
	Stdctrls::TMemo* ServiceParams;
	Stdctrls::TCheckBox* LoginPrompt;
	Stdctrls::TCheckBox* chkActive;
	void __fastcall LocalRbtnClick(System::TObject* Sender);
	void __fastcall RemoteRbtnClick(System::TObject* Sender);
	void __fastcall UserNameChange(System::TObject* Sender);
	void __fastcall PasswordChange(System::TObject* Sender);
	
private:
	Ibservices::TIBCustomService* FService;
	AnsiString __fastcall GetParam(AnsiString Name);
	void __fastcall AddParam(AnsiString Name, AnsiString Value);
	void __fastcall DeleteParam(AnsiString Name);
	
public:
	__property Ibservices::TIBCustomService* Service = {read=FService, write=FService};
	bool __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TfrmIBSecurityEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmIBSecurityEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmIBSecurityEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TfrmIBSecurityEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditIBSecurity(Ibservices::TIBCustomService* AService);

}	/* namespace Ibsecurityeditor */
using namespace Ibsecurityeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBSecurityEditor
