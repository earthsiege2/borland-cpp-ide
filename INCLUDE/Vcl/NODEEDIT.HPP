// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NodeEdit.pas' rev: 6.00

#ifndef NodeEditHPP
#define NodeEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Consts.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Nodeedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTreeViewItems;
class PASCALIMPLEMENTATION TTreeViewItems : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TGroupBox* PropGroupBox;
	Stdctrls::TButton* New;
	Stdctrls::TButton* Delete;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Comctrls::TTreeView* TreeView;
	Stdctrls::TButton* NewSub;
	Stdctrls::TEdit* Text;
	Stdctrls::TEdit* Image;
	Stdctrls::TEdit* StateImage;
	Stdctrls::TButton* Button4;
	Stdctrls::TButton* Cancel;
	Stdctrls::TButton* Apply;
	Stdctrls::TButton* Help;
	Stdctrls::TEdit* SelectedIndex;
	Stdctrls::TLabel* Label4;
	Stdctrls::TButton* Load;
	Dialogs::TOpenDialog* OpenDialog1;
	void __fastcall NewClick(System::TObject* Sender);
	void __fastcall NewSubClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall ValueChange(System::TObject* Sender);
	void __fastcall TextExit(System::TObject* Sender);
	void __fastcall ImageExit(System::TObject* Sender);
	void __fastcall StateImageExit(System::TObject* Sender);
	void __fastcall ApplyClick(System::TObject* Sender);
	void __fastcall TreeViewChange(System::TObject* Sender, Comctrls::TTreeNode* Node);
	void __fastcall TreeViewChanging(System::TObject* Sender, Comctrls::TTreeNode* Node, bool &AllowChange);
	void __fastcall SelectedIndexExit(System::TObject* Sender);
	void __fastcall LoadClick(System::TObject* Sender);
	void __fastcall TreeViewDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	void __fastcall TreeViewDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall TreeViewEdited(System::TObject* Sender, Comctrls::TTreeNode* Node, AnsiString &S);
	void __fastcall HelpClick(System::TObject* Sender);
	
private:
	Comctrls::TTreeNodes* FItems;
	bool FDropping;
	void __fastcall FlushControls(void);
	void __fastcall SetItem(Comctrls::TTreeNode* Value);
	void __fastcall SetStates(void);
	
public:
	__property Comctrls::TTreeNodes* Items = {read=FItems};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTreeViewItems(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTreeViewItems(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTreeViewItems(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTreeViewItems(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditTreeViewItems(Comctrls::TTreeNodes* AItems);

}	/* namespace Nodeedit */
using namespace Nodeedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NodeEdit
