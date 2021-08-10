//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef MDIEditH
#define MDIEditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <Printers.hpp>
#include <Clipbrd.hpp>
//---------------------------------------------------------------------------
class TEditForm : public TForm
{
__published:	// IDE-managed Components 
    TRichEdit *Editor;
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Open1;
    TMenuItem *Close1;
    TMenuItem *Save1;
    TMenuItem *Saveas1;
    TMenuItem *Print1;
    TMenuItem *Printersetup1;
    TMenuItem *N2;
    TMenuItem *Exit1;
    TMenuItem *Edit1;
    TMenuItem *Cut1;
    TMenuItem *Copy1;
    TMenuItem *Paste1;
    TMenuItem *Delete1;
    TMenuItem *N3;
    TMenuItem *Selectall1;
    TMenuItem *Character1;
    TMenuItem *Left1;
    TMenuItem *Right1;
    TMenuItem *Center1;
    TMenuItem *N4;
    TMenuItem *Wordwrap1;
    TMenuItem *N5;
    TMenuItem *Font1;
    TPopupMenu *PopupMenu1;
    TMenuItem *Cut2;
    TMenuItem *Copy2;
    TMenuItem *Paste2;
    TSaveDialog *SaveFileDialog;
    TFontDialog *FontDialog1;
    TPrinterSetupDialog *PrinterSetupDialog1;
    TPrintDialog *PrintDialog1;
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Open1Click(TObject *Sender);
    void __fastcall Close1Click(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall Save1Click(TObject *Sender);
    void __fastcall Saveas1Click(TObject *Sender);
    void __fastcall Print1Click(TObject *Sender);
    void __fastcall Printersetup1Click(TObject *Sender);
    void __fastcall Cut1Click(TObject *Sender);
    void __fastcall Copy1Click(TObject *Sender);
    void __fastcall Paste1Click(TObject *Sender);
    void __fastcall Delete1Click(TObject *Sender);
    void __fastcall Selectall1Click(TObject *Sender);
    void __fastcall Font1Click(TObject *Sender);
    void __fastcall Wordwrap1Click(TObject *Sender);
    void __fastcall Left1Click(TObject *Sender);
    void __fastcall Edit1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
    AnsiString PathName;
public:		// User declarations
    void    __fastcall Open(const AnsiString AFileName);
    virtual __fastcall TEditForm(TComponent* Owner);
    
};
//---------------------------------------------------------------------------
extern TEditForm *EditForm;
//---------------------------------------------------------------------------

#endif
