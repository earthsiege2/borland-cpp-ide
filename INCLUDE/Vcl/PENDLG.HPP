// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PenDlg.pas' rev: 5.00

#ifndef PenDlgHPP
#define PenDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComCtrls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Pendlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPenDialog;
class PASCALIMPLEMENTATION TPenDialog : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TEdit* SEWidth;
	Stdctrls::TLabel* LWidth;
	Extctrls::TRadioGroup* RGStyle;
	Stdctrls::TButton* Button1;
	Stdctrls::TGroupBox* GroupBox1;
	Extctrls::TShape* SHColor;
	Stdctrls::TButton* BColor;
	Stdctrls::TButton* Button3;
	Comctrls::TUpDown* UDWidth;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall RGStyleClick(System::TObject* Sender);
	void __fastcall SEWidthChange(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall BColorClick(System::TObject* Sender);
	void __fastcall SHColorMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState 
		Shift, int X, int Y);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Tecanvas::TChartPen* BackupPen;
	void __fastcall RefreshShape(void);
	void __fastcall EnablePenStyle(void);
	
public:
	Graphics::TPen* ThePen;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPenDialog(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPenDialog(Classes::TComponent* AOwner, int Dummy
		) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPenDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPenDialog(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Graphics::TColor __fastcall EditColor(Classes::TComponent* AOwner, Graphics::TColor AColor
	);
extern PACKAGE void __fastcall EditChartPen(Classes::TComponent* AOwner, Tecanvas::TChartPen* ChartPen
	);
extern PACKAGE void __fastcall EditPen(Classes::TComponent* AOwner, Graphics::TPen* APen);
extern PACKAGE void __fastcall TeeLoadClearImage(Classes::TComponent* AOwner, Graphics::TPicture* AImage
	);
extern PACKAGE void __fastcall ShowControls(bool Show, Controls::TControl* const * AControls, const 
	int AControls_Size);
extern PACKAGE void __fastcall EnableControls(bool Show, Controls::TControl* const * AControls, const 
	int AControls_Size);
extern PACKAGE bool __fastcall TeeYesNo(const AnsiString Message);

}	/* namespace Pendlg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Pendlg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PenDlg
