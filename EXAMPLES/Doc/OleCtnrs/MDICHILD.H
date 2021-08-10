//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mdichildH
#define mdichildH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <OleCtnrs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMDIChildForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TOleContainer *OleContainer1;
	TPopupMenu *LocalMenu;
	TMenuItem *InsertObject1;
	TMenuItem *CopyObject1;
	TMenuItem *DeleteObject1;
	TMenuItem *Properties1;
	TMainMenu *MainMenu1;
	TMenuItem *Edit1;
	TMenuItem *Cut1;
	TMenuItem *Copy1;
	TMenuItem *Paste1;
	TMenuItem *PasteSpecial1;
	TMenuItem *CLear1;
	TMenuItem *N3;
	TMenuItem *Object2;
	TMenuItem *Insert1;
	void __fastcall DeleteObject1Click(TObject *Sender);
	void __fastcall Copy1Click(TObject *Sender);
	void __fastcall CopyObject1Click(TObject *Sender);
	void __fastcall Cut1Click(TObject *Sender);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall InsertObject1Click(TObject *Sender);
	void __fastcall LocalMenuPopup(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Properties1Click(TObject *Sender);
	void __fastcall OleContainer1Activate(TObject *Sender);
	void __fastcall Paste1Click(TObject *Sender);
	void __fastcall PasteSpecial1Click(TObject *Sender);
private:	// User declarations
    TFileName FFileName;
    bool FSaved;
    void __fastcall VerbClick(TObject *Sender);
public:		// User declarations
    void __fastcall CreateFromFile(TFileName FileName, bool Linked);
    void __fastcall SaveFile(TFileName FileName);
    __property TFileName FileName = {read=FFileName};
	virtual __fastcall TMDIChildForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TMDIChildForm *MDIChildForm;
//---------------------------------------------------------------------------
#endif
