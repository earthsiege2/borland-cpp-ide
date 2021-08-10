// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeExport.pas' rev: 6.00

#ifndef TeExportHPP
#define TeExportHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
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

namespace Teexport
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeExportForm;
class PASCALIMPLEMENTATION TTeeExportForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Extctrls::TRadioGroup* RGFormat;
	Stdctrls::TButton* Button3;
	Dialogs::TSaveDialog* SaveDialog1;
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall RGFormatClick(System::TObject* Sender);
	
public:
	Teeprocs::TCustomTeePanel* ExportPanel;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeExportForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeExportForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeExportForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeExportForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


typedef void __fastcall (*TExportSaveProc)(Teeprocs::TCustomTeePanel* ExportPanel, const AnsiString AFileName);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TExportSaveProc TeeExportSave;
extern PACKAGE void __fastcall SaveTeeToFile(Teeprocs::TCustomTeePanel* ATree, const AnsiString AName);
extern PACKAGE void __fastcall LoadTeeFromFile(Teeprocs::TCustomTeePanel* &ATree, const AnsiString AName);

}	/* namespace Teexport */
using namespace Teexport;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeExport
