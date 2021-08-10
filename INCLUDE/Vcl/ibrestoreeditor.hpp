// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBRestoreEditor.pas' rev: 6.00

#ifndef IBRestoreEditorHPP
#define IBRestoreEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibrestoreeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmIBRestoreEditor;
class PASCALIMPLEMENTATION TfrmIBRestoreEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Grids::TStringGrid* sgDatabaseFiles;
	Extctrls::TPanel* Panel1;
	Stdctrls::TButton* OKBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TButton* HelpBtn;
	void __fastcall sgDatabaseFilesDrawCell(System::TObject* Sender, int ACol, int ARow, const Types::TRect &Rect, Grids::TGridDrawState State);
	void __fastcall sgDatabaseFilesKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall sgDatabaseFilesSelectCell(System::TObject* Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall FormCreate(System::TObject* Sender);
	
public:
	__fastcall TfrmIBRestoreEditor(Classes::TComponent* AOwner, Classes::TStrings* Values);
	void __fastcall GetStrings(Classes::TStrings* s);
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmIBRestoreEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmIBRestoreEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TfrmIBRestoreEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ibrestoreeditor */
using namespace Ibrestoreeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBRestoreEditor
