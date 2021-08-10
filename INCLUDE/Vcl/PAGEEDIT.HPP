// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PageEdit.pas' rev: 5.00

#ifndef PageEditHPP
#define PageEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Pageedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TNotebookEditDlg;
class PASCALIMPLEMENTATION TNotebookEditDlg : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::THeader* Header1;
	Grids::TDrawGrid* Grid;
	Stdctrls::TButton* EditButton;
	Stdctrls::TButton* AddButton;
	Stdctrls::TButton* DeleteButton;
	Stdctrls::TButton* CloseButton;
	Stdctrls::TButton* DownButton;
	Stdctrls::TButton* UpButton;
	Stdctrls::TButton* HelpBtn;
	void __fastcall GridDrawCell(System::TObject* Sender, int Col, int Row, const Windows::TRect &Rect, 
		Grids::TGridDrawState State);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall MoveClick(System::TObject* Sender);
	void __fastcall EditClick(System::TObject* Sender);
	void __fastcall AddClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall HeaderSized(System::TObject* Sender, int ASection, int AWidth);
	void __fastcall HelpBtnClick(System::TObject* Sender);
	
private:
	Classes::TStrings* PageList;
	
public:
	bool Modified;
	void __fastcall SetPageList(Classes::TStrings* Value);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TNotebookEditDlg(Classes::TComponent* AOwner) : 
		Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TNotebookEditDlg(Classes::TComponent* AOwner, 
		int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TNotebookEditDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TNotebookEditDlg(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Pageedit */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Pageedit;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PageEdit
