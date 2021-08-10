// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrPropDlg.pas' rev: 6.00

#ifndef SvrPropDlgHPP
#define SvrPropDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SvrLogColSettingsFrame.hpp>	// Pascal unit
#include <SvrLogFrame.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Svrpropdlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDlgProperties;
class PASCALIMPLEMENTATION TDlgProperties : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OkButton;
	Stdctrls::TButton* CancelButton;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabConnection;
	Comctrls::TTabSheet* TabLog;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TComboBox* cbPort;
	Stdctrls::TGroupBox* GroupBox2;
	Svrlogcolsettingsframe::TLogColSettingsFrame* LogColSettingsFrame;
	Stdctrls::TGroupBox* GroupBox6;
	Stdctrls::TEdit* edLogMax;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* edLogDelete;
	Stdctrls::TLabel* Label5;
	Stdctrls::TCheckBox* cbActiveAtStartup;
	Stdctrls::TEdit* edDefault;
	Stdctrls::TEdit* edPath;
	Stdctrls::TButton* Button1;
	void __fastcall NumericKeyPress(System::TObject* Sender, char &Key);
	void __fastcall Button1Click(System::TObject* Sender);
	
private:
	AnsiString __fastcall GetServerPath();
	int __fastcall GetServerPort(void);
	void __fastcall SetServerPath(const AnsiString Value);
	void __fastcall SetServerPort(const int Value);
	AnsiString __fastcall GetDefaultURL();
	void __fastcall SetDefaultURL(const AnsiString Value);
	int __fastcall GetLogMax(void);
	void __fastcall SetLogMax(const int Value);
	int __fastcall GetLogDelete(void);
	void __fastcall SetLogDelete(const int Value);
	bool __fastcall GetActiveAtStartup(void);
	void __fastcall SetActiveAtStartup(const bool Value);
	void __fastcall SetLogFrame(const Svrlogframe::TLogFrame* Value);
	
public:
	void __fastcall UpdateColumns(void);
	__property AnsiString ServerSearchPath = {read=GetServerPath, write=SetServerPath};
	__property int ServerPort = {read=GetServerPort, write=SetServerPort, nodefault};
	__property AnsiString DefaultURL = {read=GetDefaultURL, write=SetDefaultURL};
	__property int LogMax = {read=GetLogMax, write=SetLogMax, nodefault};
	__property int LogDelete = {read=GetLogDelete, write=SetLogDelete, nodefault};
	__property bool ActiveAtStartup = {read=GetActiveAtStartup, write=SetActiveAtStartup, nodefault};
	__property Svrlogframe::TLogFrame* LogFrame = {write=SetLogFrame};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDlgProperties(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDlgProperties(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDlgProperties(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDlgProperties(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TDlgProperties* DlgProperties;

}	/* namespace Svrpropdlg */
using namespace Svrpropdlg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrPropDlg
