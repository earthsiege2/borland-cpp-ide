// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BubblEdi.pas' rev: 5.00

#ifndef BubblEdiHPP
#define BubblEdiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <BubbleCh.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Bubbledi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBubbleSeriesEditor;
class PASCALIMPLEMENTATION TBubbleSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CB3dPoint;
	Stdctrls::TCheckBox* CBInflate;
	Buttons::TBitBtn* BPoinPenCol;
	Extctrls::TRadioGroup* RGStyle;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TCheckBox* CBPointColorDef;
	Buttons::TBitBtn* BPointFillColor;
	Stdctrls::TCheckBox* CBColorEach;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CB3dPointClick(System::TObject* Sender);
	void __fastcall BPointFillColorClick(System::TObject* Sender);
	void __fastcall CBPointColorDefClick(System::TObject* Sender);
	void __fastcall BPoinPenColClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBInflateClick(System::TObject* Sender);
	void __fastcall RGStyleClick(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	
public:
	Bubblech::TBubbleSeries* TheSeries;
	void __fastcall Enable3DPoint(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBubbleSeriesEditor(Classes::TComponent* AOwner)
		 : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBubbleSeriesEditor(Classes::TComponent* AOwner
		, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBubbleSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBubbleSeriesEditor(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Bubbledi */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Bubbledi;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BubblEdi
