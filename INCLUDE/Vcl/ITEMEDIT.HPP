// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ItemEdit.pas' rev: 5.00

#ifndef ItemEditHPP
#define ItemEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <LibHelp.hpp>	// Pascal unit
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

namespace Itemedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TItemInfo;
class PASCALIMPLEMENTATION TItemInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStringList* FSubItems;
	Classes::TList* FSubItemImages;
	AnsiString FCaption;
	int FImageIndex;
	int FStateIndex;
	
public:
	__fastcall TItemInfo(Comctrls::TListItem* Item);
	__fastcall virtual ~TItemInfo(void);
};


class DELPHICLASS TListViewItems;
class PASCALIMPLEMENTATION TListViewItems : public Forms::TForm 
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
	Stdctrls::TButton* Button7;
	void __fastcall NewClick(System::TObject* Sender);
	void __fastcall NewSubClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall ValueChange(System::TObject* Sender);
	void __fastcall TextExit(System::TObject* Sender);
	void __fastcall ImageExit(System::TObject* Sender);
	void __fastcall StateImageExit(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ApplyClick(System::TObject* Sender);
	void __fastcall TreeViewChange(System::TObject* Sender, Comctrls::TTreeNode* Node);
	void __fastcall TreeViewChanging(System::TObject* Sender, Comctrls::TTreeNode* Node, bool &AllowChange
		);
	void __fastcall TreeViewDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState 
		State, bool &Accept);
	void __fastcall TreeViewDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall TreeViewEdited(System::TObject* Sender, Comctrls::TTreeNode* Node, AnsiString &S);
	void __fastcall Button7Click(System::TObject* Sender);
	void __fastcall TreeViewKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall TreeViewEditing(System::TObject* Sender, Comctrls::TTreeNode* Node, bool &AllowEdit
		);
	
private:
	Comctrls::TListItems* FItems;
	bool FDropping;
	void __fastcall FlushControls(void);
	void __fastcall GetItem(TItemInfo* ItemInfo, Comctrls::TListItem* Value);
	void __fastcall SetItem(TItemInfo* Value);
	void __fastcall SetStates(void);
	void __fastcall SetSubItem(const AnsiString S, int ImageIndex);
	MESSAGE void __fastcall UMTreeEdit(Messages::TMessage &M);
	
public:
	__property Comctrls::TListItems* Items = {read=FItems};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TListViewItems(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TListViewItems(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TListViewItems(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TListViewItems(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word UM_TREEEDIT = 0x400;
extern PACKAGE bool __fastcall EditListViewItems(Comctrls::TListItems* AItems);

}	/* namespace Itemedit */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Itemedit;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ItemEdit
