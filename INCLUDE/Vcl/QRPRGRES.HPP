// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRPrgres.pas' rev: 6.00

#ifndef QRPrgresHPP
#define QRPrgresHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QR3Const.hpp>	// Pascal unit
#include <QRPrntr.hpp>	// Pascal unit
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

namespace Qrprgres
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRProgressForm;
class PASCALIMPLEMENTATION TQRProgressForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Info;
	Stdctrls::TButton* CancelButton;
	Comctrls::TProgressBar* Gauge;
	void __fastcall CancelButtonClick(System::TObject* Sender);
	
private:
	Qrprntr::TQRPrinter* FQRPrinter;
	
protected:
	MESSAGE void __fastcall CMQRPROGRESSUPDATE(void *Message);
	
public:
	__property Qrprntr::TQRPrinter* QRPrinter = {read=FQRPrinter, write=FQRPrinter};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TQRProgressForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TQRProgressForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TQRProgressForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRProgressForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrprgres */
using namespace Qrprgres;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRPrgres
