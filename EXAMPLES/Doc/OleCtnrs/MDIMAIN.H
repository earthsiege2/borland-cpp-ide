//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mdimainH
#define mdimainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Toolbar;
	TSpeedButton *SpeedButton1;
	TSpeedButton *LinkButton;
	TSpeedButton *CopyButton;
	TSpeedButton *CutButton;
	TSpeedButton *PasteButton;
	TSpeedButton *OpenButton;
	TSpeedButton *NewButton;
	TSpeedButton *SaveButton;
	TPanel *StatusPanel;
	TStatusBar *StatusBar;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *New1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *SaveAs1;
	TMenuItem *N2;
	TMenuItem *Close2;
	TMenuItem *CloseAll1;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TMenuItem *Window2;
	TMenuItem *Tile1;
	TMenuItem *TileHorizontally1;
	TMenuItem *Cascade1;
	TMenuItem *ArrangeIcons1;
	TMenuItem *Help1;
	TMenuItem *About1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	void __fastcall About1Click(TObject *Sender);
	void __fastcall ArrangeIcons1Click(TObject *Sender);
	void __fastcall Cascade1Click(TObject *Sender);
	void __fastcall Close1Click(TObject *Sender);
	void __fastcall CloseAll1Click(TObject *Sender);
	void __fastcall CopyButtonClick(TObject *Sender);
	void __fastcall CutButtonClick(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall File1Click(TObject *Sender);
	void __fastcall LinkButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall New1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Paste1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Tile1Click(TObject *Sender);
	void __fastcall TileHorizontally1Click(TObject *Sender);
	void __fastcall Window2Click(TObject *Sender);
    void __fastcall Object2Click(TObject *Sender);
private:	// User declarations
    void __fastcall ShowHint(TObject *Sender);
public:		// User declarations
	virtual __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
