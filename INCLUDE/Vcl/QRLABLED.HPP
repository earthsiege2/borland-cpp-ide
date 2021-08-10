// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRLablEd.pas' rev: 5.00

#ifndef QRLablEdHPP
#define QRLablEdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
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

namespace Qrlabled
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRLabelEditorForm;
class PASCALIMPLEMENTATION TQRLabelEditorForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Value;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button3;
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
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TQRLabelEditorForm(Classes::TComponent* AOwner) : 
		Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TQRLabelEditorForm(Classes::TComponent* AOwner
		, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TQRLabelEditorForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRLabelEditorForm(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRLabelEditor;
class PASCALIMPLEMENTATION TQRLabelEditor : public Quickrpt::TQRPrintableEditor 
{
	typedef Quickrpt::TQRPrintableEditor inherited;
	
protected:
	virtual Graphics::TColor __fastcall GetColor(void);
	virtual Graphics::TFont* __fastcall GetFont(void);
	virtual TMetaClass* __fastcall GetPrintableClass(void);
	virtual AnsiString __fastcall GetValue();
	virtual AnsiString __fastcall GetGlyphResName();
	virtual AnsiString __fastcall GetControlName();
	virtual void __fastcall SetColor(Graphics::TColor Value);
	virtual void __fastcall SetFont(Graphics::TFont* Value);
	virtual void __fastcall SetValue(AnsiString Value);
	
public:
	virtual bool __fastcall ShowEditor(void);
public:
	#pragma option push -w-inl
	/* TQRPrintableEditor.Create */ inline __fastcall virtual TQRLabelEditor(Quickrpt::TQRPrintable* AControl
		) : Quickrpt::TQRPrintableEditor(AControl) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRLabelEditor(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrlabled */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Qrlabled;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRLablEd
