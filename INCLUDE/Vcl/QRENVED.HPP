// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QREnvEd.pas' rev: 5.00

#ifndef QREnvEdHPP
#define QREnvEdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <qr3const.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <QRExpr.hpp>	// Pascal unit
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

namespace Qrenved
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQREnvironmentEditor;
class PASCALIMPLEMENTATION TQREnvironmentEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* VariableOKBtn;
	Stdctrls::TGroupBox* AvailableGB;
	Grids::TStringGrid* UDFGrid;
	Stdctrls::TButton* DeleteBtn;
	Stdctrls::TButton* EditBtn;
	Stdctrls::TButton* AddBtn;
	Stdctrls::TRadioButton* LocalCB;
	Stdctrls::TRadioButton* GlobalCB;
	Stdctrls::TGroupBox* NewEntryGB;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Name;
	Stdctrls::TEdit* Expression;
	Buttons::TSpeedButton* SpeedButton1;
	Stdctrls::TButton* NewOKBtn;
	Stdctrls::TButton* NewCancelBtn;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall UDFGridSetEditText(System::TObject* Sender, int ACol, int ARow, const AnsiString Value
		);
	void __fastcall EditBtnClick(System::TObject* Sender);
	void __fastcall LocalCBClick(System::TObject* Sender);
	void __fastcall VariableOKBtnClick(System::TObject* Sender);
	void __fastcall NewOKBtnClick(System::TObject* Sender);
	void __fastcall NewCancelBtnClick(System::TObject* Sender);
	void __fastcall AddBtnClick(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	
private:
	bool CloseDialog;
	int NewResult;
	Qrexpr::TQREvEnvironment* FEnvironment;
	Qrexpr::TQREvEnvironment* __fastcall WorkEnvironment(void);
	bool __fastcall GetNew(AnsiString &AName, AnsiString &AExpr);
	
public:
	void __fastcall PopulateGrid(void);
	__property Qrexpr::TQREvEnvironment* Environment = {read=FEnvironment, write=FEnvironment};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TQREnvironmentEditor(Classes::TComponent* AOwner
		) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TQREnvironmentEditor(Classes::TComponent* AOwner
		, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TQREnvironmentEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQREnvironmentEditor(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall EditEnvironment(Qrexpr::TQREvEnvironment* AEnvironment, bool AllowGlobalEnv
	, Controls::TWinControl* ParentControl);

}	/* namespace Qrenved */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Qrenved;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QREnvEd
