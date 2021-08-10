//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef sdimainH
#define sdimainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <OleCtnrs.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:
    TPanel *Toolbar;
    TSpeedButton *SpeedButton1;
    TSpeedButton *LinkButton;
    TSpeedButton *CopyButton;
    TSpeedButton *CutButton;
    TSpeedButton *PasteButton;
    TSpeedButton *OpenButton;
    TSpeedButton *SaveButton;
    TPanel *StatusPanel;
    TStatusBar *StatusBar;
    TPanel *Panel1;
    TOleContainer *OleContainer1;
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Open1;
    TMenuItem *Save1;
    TMenuItem *SaveAs1;
    TMenuItem *N2;
    TMenuItem *Exit1;
    TMenuItem *Edit1;
    TMenuItem *Cut1;
    TMenuItem *Copy1;
    TMenuItem *Paste1;
    TMenuItem *PasteSpecial1;
    TMenuItem *N4;
    TMenuItem *Object1;
    TMenuItem *Help1;
    TMenuItem *About1;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    void __fastcall Save1Click(TObject *Sender);
    void __fastcall PasteSpecial1Click(TObject *Sender);
    void __fastcall Paste1Click(TObject *Sender);
    void __fastcall Open1Click(TObject *Sender);
    void __fastcall Object1Click(TObject *Sender);
    void __fastcall New1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall LinkButtonClick(TObject *Sender);
    void __fastcall File1Click(TObject *Sender);
    void __fastcall Edit1Click(TObject *Sender);
    void __fastcall CutButtonClick(TObject *Sender);
    void __fastcall Cut1Click(TObject *Sender);
    void __fastcall Copy1Click(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
private:    // private user declarations
    TFileName ObjectFileName;
    void __fastcall ShowHint(TObject* Sender);
public:     // public user declarations

    virtual __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
