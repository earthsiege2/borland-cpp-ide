// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AxisIncr.pas' rev: 5.00

#ifndef AxisIncrHPP
#define AxisIncrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Axisincr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAxisIncrement;
class PASCALIMPLEMENTATION TAxisIncrement : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TRadioGroup* RadioGroup1;
	Stdctrls::TComboBox* CBSteps;
	Stdctrls::TEdit* ECustom;
	Stdctrls::TButton* BitBtn1;
	Stdctrls::TButton* BitBtn2;
	Stdctrls::TLabel* Label1;
	Stdctrls::TCheckBox* CBExact;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall RadioGroup1Click(System::TObject* Sender);
	void __fastcall BitBtn1Click(System::TObject* Sender);
	void __fastcall CBExactClick(System::TObject* Sender);
	void __fastcall CBStepsChange(System::TObject* Sender);
	
private:
	void __fastcall SetEditText(void);
	
public:
	bool IsDateTime;
	bool IsExact;
	double Increment;
	Teeprocs::TDateTimeStep IStep;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAxisIncrement(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAxisIncrement(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAxisIncrement(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAxisIncrement(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString __fastcall GetIncrementText(Classes::TComponent* AOwner, const double Increment
	, bool IsDateTime, bool ExactDateTime, const AnsiString AFormat);

}	/* namespace Axisincr */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Axisincr;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AxisIncr
