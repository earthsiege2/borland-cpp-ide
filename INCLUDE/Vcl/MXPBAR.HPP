// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXPBAR.pas' rev: 6.00

#ifndef MXPBARHPP
#define MXPBARHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
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

namespace Mxpbar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EUserCanceled;
class PASCALIMPLEMENTATION EUserCanceled : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EUserCanceled(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EUserCanceled(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EUserCanceled(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EUserCanceled(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EUserCanceled(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EUserCanceled(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EUserCanceled(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EUserCanceled(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EUserCanceled(void) { }
	#pragma option pop
	
};


class DELPHICLASS TProgressDialog;
class PASCALIMPLEMENTATION TProgressDialog : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TProgressBar* ProgressBar;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TStaticText* StatusText;
	void __fastcall CancelButtonClick(System::TObject* Sender);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	bool FCanceled;
	int FInterval;
	int FCount;
	int FRealMax;
	bool FBuilding;
	bool BuildDone;
	AnsiString FExceptMessage;
	Classes::TNotifyEvent FOnPerformBuild;
	int __fastcall GetMax(void);
	void __fastcall SetMax(int Value);
	void __fastcall SetInterval(int Value);
	MESSAGE void __fastcall StartBuild(void *Message);
	
public:
	bool __fastcall StepProgress(void);
	void __fastcall ShowStatus(AnsiString Msg);
	int __fastcall UpdateProgress(void);
	void __fastcall Reset(void);
	__property int Max = {read=GetMax, write=SetMax, nodefault};
	__property bool Canceled = {read=FCanceled, write=FCanceled, nodefault};
	__property int Interval = {read=FInterval, write=SetInterval, nodefault};
	__property Classes::TNotifyEvent OnPerformBuild = {read=FOnPerformBuild, write=FOnPerformBuild};
	__property AnsiString ExceptMessage = {read=FExceptMessage, write=FExceptMessage};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TProgressDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TProgressDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TProgressDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TProgressDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TProgressDialog* ProgressDlg;

}	/* namespace Mxpbar */
using namespace Mxpbar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXPBAR
