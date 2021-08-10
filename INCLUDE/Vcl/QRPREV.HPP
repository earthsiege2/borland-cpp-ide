// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRPrev.pas' rev: 5.00

#ifndef QRPrevHPP
#define QRPrevHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ImgList.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <ToolWin.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <qr3const.hpp>	// Pascal unit
#include <QRPrntr.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Qrprev
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRStandardPreview;
class PASCALIMPLEMENTATION TQRStandardPreview : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TStatusBar* StatusBar;
	Comctrls::TToolBar* ToolBar1;
	Comctrls::TToolButton* ZoomFit;
	Comctrls::TToolButton* Zoom100;
	Comctrls::TToolButton* ZoomToWidth;
	Comctrls::TToolButton* Separator1;
	Comctrls::TToolButton* FirstPage;
	Comctrls::TToolButton* PreviousPage;
	Comctrls::TToolButton* ToolButton2;
	Comctrls::TToolButton* LastPage;
	Comctrls::TToolButton* Separator2;
	Comctrls::TToolButton* PrintSetup;
	Comctrls::TToolButton* Print;
	Comctrls::TToolButton* Separator3;
	Comctrls::TToolButton* SaveReport;
	Comctrls::TToolButton* LoadReport;
	Comctrls::TToolButton* Separator4;
	Controls::TImageList* Images;
	Comctrls::TToolButton* ToolButton1;
	Buttons::TSpeedButton* ExitButton;
	Qrprntr::TQRPreview* QRPreview;
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall ZoomToFitClick(System::TObject* Sender);
	void __fastcall ZoomTo100Click(System::TObject* Sender);
	void __fastcall ZoomToWidthClick(System::TObject* Sender);
	void __fastcall FirstPageClick(System::TObject* Sender);
	void __fastcall PrevPageClick(System::TObject* Sender);
	void __fastcall NextPageClick(System::TObject* Sender);
	void __fastcall LastPageClick(System::TObject* Sender);
	void __fastcall PrintClick(System::TObject* Sender);
	void __fastcall ExitClick(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall SaveClick(System::TObject* Sender);
	void __fastcall PrintSetupClick(System::TObject* Sender);
	void __fastcall LoadClick(System::TObject* Sender);
	void __fastcall QRPreviewPageAvailable(System::TObject* Sender, int PageNum);
	void __fastcall QRPreviewProgressUpdate(System::TObject* Sender, int Progress);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	Qrprntr::TQRPrinter* FQRPrinter;
	Comctrls::TProgressBar* Gauge;
	int LastProgress;
	
public:
	__fastcall virtual TQRStandardPreview(Classes::TComponent* AOwner, Qrprntr::TQRPrinter* aQRPrinter)
		;
	HIDESBASE void __fastcall Show(void);
	void __fastcall UpdateInfo(void);
	__property Qrprntr::TQRPrinter* QRPrinter = {read=FQRPrinter, write=FQRPrinter};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TQRStandardPreview(Classes::TComponent* AOwner) : 
		Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TQRStandardPreview(Classes::TComponent* AOwner
		, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TQRStandardPreview(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRStandardPreview(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrprev */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Qrprev;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRPrev
