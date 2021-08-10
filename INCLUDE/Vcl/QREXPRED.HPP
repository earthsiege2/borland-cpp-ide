// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRExprEd.pas' rev: 6.00

#ifndef QRExprEdHPP
#define QRExprEdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Buttons.hpp>	// Pascal unit
#include <QRLablEd.hpp>	// Pascal unit
#include <QuickRpt.hpp>	// Pascal unit
#include <Mask.hpp>	// Pascal unit
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

namespace Qrexpred
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRExprEditorForm;
class PASCALIMPLEMENTATION TQRExprEditorForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Value;
	Stdctrls::TCheckBox* AutoSize;
	Stdctrls::TCheckBox* Stretch;
	Dialogs::TFontDialog* FontDialog1;
	Stdctrls::TButton* OKBtn;
	Stdctrls::TButton* Button4;
	Stdctrls::TCheckBox* Transparent;
	Mask::TMaskEdit* Width;
	Mask::TMaskEdit* Height;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Buttons::TSpeedButton* ShowExprBuilder;
	Stdctrls::TLabel* Label4;
	Stdctrls::TComboBox* Mask;
	void __fastcall ShowExprBuilderClick(System::TObject* Sender);
	
private:
	Forms::TCustomForm* DSForm;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TQRExprEditorForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TQRExprEditorForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TQRExprEditorForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRExprEditorForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRExprEditor;
class PASCALIMPLEMENTATION TQRExprEditor : public Qrlabled::TQRLabelEditor 
{
	typedef Qrlabled::TQRLabelEditor inherited;
	
protected:
	virtual TMetaClass* __fastcall GetPrintableClass(void);
	virtual AnsiString __fastcall GetValue();
	virtual AnsiString __fastcall GetGlyphResName();
	virtual AnsiString __fastcall GetControlName();
	virtual void __fastcall SetValue(AnsiString Value);
	
public:
	virtual bool __fastcall ShowEditor(void);
public:
	#pragma option push -w-inl
	/* TQRPrintableEditor.Create */ inline __fastcall virtual TQRExprEditor(Quickrpt::TQRPrintable* AControl) : Qrlabled::TQRLabelEditor(AControl) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRExprEditor(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrexpred */
using namespace Qrexpred;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRExprEd
