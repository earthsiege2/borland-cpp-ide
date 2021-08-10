// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Ixedit.pas' rev: 6.00

#ifndef IxeditHPP
#define IxeditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <LibHelp.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
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

namespace Ixedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIndexFiles;
class PASCALIMPLEMENTATION TIndexFiles : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TListBox* ListBox1;
	Stdctrls::TButton* Add;
	Stdctrls::TButton* Delete;
	Stdctrls::TButton* Ok;
	Stdctrls::TButton* Cancel;
	Stdctrls::TButton* Help;
	Stdctrls::TButton* Clear;
	Dialogs::TOpenDialog* OpenDialog;
	void __fastcall ListBox1Click(System::TObject* Sender);
	void __fastcall AddClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall ClearClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall HelpClick(System::TObject* Sender);
	
private:
	Dbtables::TTable* FTable;
	bool FNoItems;
	AnsiString FEmpty;
	void __fastcall AddEmpty(void);
	bool __fastcall IsDBaseTable(void);
	void __fastcall RemoveEmpty(void);
	void __fastcall SetButtons(void);
	
public:
	__property Dbtables::TTable* Table = {read=FTable};
	__property bool NoItems = {read=FNoItems, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TIndexFiles(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TIndexFiles(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TIndexFiles(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TIndexFiles(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditIndexFiles(Dbtables::TTable* ATable, Classes::TStrings* List);

}	/* namespace Ixedit */
using namespace Ixedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Ixedit
