// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BrushDlg.pas' rev: 5.00

#ifndef BrushDlgHPP
#define BrushDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
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

namespace Brushdlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBrushDialog;
class PASCALIMPLEMENTATION TBrushDialog : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TRadioGroup* RGStyle;
	Stdctrls::TButton* Button2;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TButton* BColor;
	Extctrls::TShape* SHColor;
	Stdctrls::TButton* Button3;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall RGStyleClick(System::TObject* Sender);
	void __fastcall BColorClick(System::TObject* Sender);
	void __fastcall SHColorMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState 
		Shift, int X, int Y);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	
private:
	Graphics::TBrush* BackupBrush;
	void __fastcall RedrawShape(void);
	
public:
	Graphics::TBrush* TheBrush;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBrushDialog(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBrushDialog(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBrushDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBrushDialog(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Graphics::TFont* __fastcall InternalEditFont(Classes::TComponent* AOwner, Graphics::TFont* 
	AFont);
extern PACKAGE void __fastcall EditChartBrush(Classes::TComponent* AOwner, Graphics::TBrush* ChartBrush
	);

}	/* namespace Brushdlg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Brushdlg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BrushDlg
