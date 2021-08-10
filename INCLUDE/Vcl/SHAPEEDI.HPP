// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ShapeEdi.pas' rev: 6.00

#ifndef ShapeEdiHPP
#define ShapeEdiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeShape.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Shapeedi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartShapeEditor;
class PASCALIMPLEMENTATION TChartShapeEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* BShapePen;
	Stdctrls::TButton* BShapeBrush;
	Extctrls::TShape* SHColor;
	Stdctrls::TEdit* SEX0;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* LX1;
	Stdctrls::TEdit* SEX1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* SEY0;
	Stdctrls::TLabel* LY1;
	Stdctrls::TEdit* SEY1;
	Stdctrls::TButton* Button1;
	Extctrls::TRadioGroup* RGAlign;
	Stdctrls::TLabel* Label5;
	Stdctrls::TMemo* MemoText;
	Stdctrls::TCheckBox* CBTrans;
	Stdctrls::TButton* BShapeColor;
	Stdctrls::TComboBox* CBStyle;
	Stdctrls::TLabel* Label3;
	void __fastcall BShapePenClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SHColorMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall SEX0Change(System::TObject* Sender);
	void __fastcall SEY0Change(System::TObject* Sender);
	void __fastcall SEX1Change(System::TObject* Sender);
	void __fastcall SEY1Change(System::TObject* Sender);
	void __fastcall BShapeBrushClick(System::TObject* Sender);
	void __fastcall MemoTextChange(System::TObject* Sender);
	void __fastcall RGAlignClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall CBTransClick(System::TObject* Sender);
	void __fastcall BShapeColorClick(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	
private:
	bool CreatingForm;
	
public:
	Teeshape::TChartShape* TheSeries;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TChartShapeEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TChartShapeEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TChartShapeEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartShapeEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Shapeedi */
using namespace Shapeedi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ShapeEdi
