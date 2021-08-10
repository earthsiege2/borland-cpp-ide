// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Arrowedi.pas' rev: 6.00

#ifndef ArrowediHPP
#define ArrowediHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ArrowCha.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Arrowedi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TArrowSeriesEditor;
class PASCALIMPLEMENTATION TArrowSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Buttons::TBitBtn* BPen;
	Buttons::TBitBtn* BBrush;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* SEArrowWidth;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* SEArrowHeight;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TCheckBox* CBColorEach;
	Buttons::TBitBtn* BArrowColor;
	Extctrls::TShape* SHArrowColor;
	Comctrls::TUpDown* UDArrowWidth;
	Comctrls::TUpDown* UDArrowHeight;
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall BArrowColorClick(System::TObject* Sender);
	void __fastcall BPenClick(System::TObject* Sender);
	void __fastcall BBrushClick(System::TObject* Sender);
	void __fastcall SEArrowWidthChange(System::TObject* Sender);
	void __fastcall SEArrowHeightChange(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SHArrowColorMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	bool CreatingForm;
	
public:
	Arrowcha::TArrowSeries* Arrow;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TArrowSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TArrowSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TArrowSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TArrowSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Arrowedi */
using namespace Arrowedi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Arrowedi
