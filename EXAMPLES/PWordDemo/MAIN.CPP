//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 2000 Inprise Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPWordForm *PWordForm;
//---------------------------------------------------------------------------
__fastcall TPWordForm::TPWordForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPWordForm::btnCloseWordClick(TObject *Sender)
{
  OleVariant SaveChanges = wdDoNotSaveChanges;
  OleVariant OriginalFormat = Unassigned;
  OleVariant RouteDocument = Unassigned;
  try
  {
    WordApplication->Quit(SaveChanges, OriginalFormat, RouteDocument);
    WordApplication->Disconnect();
    btnCloseWord->Enabled = FALSE;
    btnPrint->Enabled = FALSE;
    btnPreview->Enabled = FALSE;
  }
  catch (Exception &exception)
  {
    Application->ShowException(&exception);
    WordApplication->Disconnect();
  }
}
//---------------------------------------------------------------------------
void __fastcall TPWordForm::btnPrintClick(TObject *Sender)
{
  WordDocument->PrintOut();
}
//---------------------------------------------------------------------------

void __fastcall TPWordForm::btnPreviewClick(TObject *Sender)
{
  WordDocument->PrintPreview();
}

//---------------------------------------------------------------------------
void TPWordForm::SetFont()
{
    WordFont->ConnectTo(WordDocument->Sentences->get_Last()->get_Font());
    if (ChkBoxUnderline->Checked)    WordFont->Underline = wdUnderlineWords;
    if (ChkBoxBold->Checked)         WordFont->Bold = 1;
    if (ChkBoxItalic->Checked)       WordFont->Italic = 1;
    if (ChkBoxEmboss->Checked)       WordFont->Emboss = 1;
    if (ChkBoxEngrave->Checked)      WordFont->Engrave = 1;
    if (ChkBoxShadow->Checked)       WordFont->Shadow = 1;
    if (ChkBoxDoublestrike->Checked) WordFont->DoubleStrikeThrough = 1;
    if (ChkBoxStrike->Checked)       WordFont->StrikeThrough = 1;
    WordFont->Size = StrToInt(Size->Text);
    if (Fonttype->ItemIndex >= 0)    WordFont->Name = StringToOleStr(Fonttype->Items->Strings[Fonttype->ItemIndex]);
}


void __fastcall TPWordForm::BtnInsertRecordClick(TObject *Sender)
{
  OleVariant Template = EmptyParam;
  OleVariant NewTemplate = False;
  OleVariant ItemIndex = 1;

  try
  {
    try
      {
        WordApplication->Connect();
      }
    catch (Exception &exception)
      {
        MessageDlg("Word may not be installed", mtError, TMsgDlgButtons() << mbYes, 0);
        Abort;
      }
    WordApplication->Visible = True;
    WordApplication->Caption = StringToOleStr("Borland automation");
    //Create new document
    if (ChkBoxNewDoc->Checked)
    {
      WordApplication->Documents->Add(Template, NewTemplate);
      //Assign WordDocument component
      WordDocument->ConnectTo(WordApplication->Documents->Item(ItemIndex));
    }
    //Turn Spell checking off because it takes a long time if enabled and slows down Winword
    WordApplication->Options->CheckSpellingAsYouType = False;
    WordApplication->Options->CheckGrammarAsYouType = False;
    //Insert data
    DBImgFishImg->CopyToClipboard();
    WordDocument->Sentences->Last->Paste();
    WordDocument->Range(EmptyParam, EmptyParam)->InsertAfter(StringToOleStr("Common Name: " + Table->Fields->Fields[2]->AsString + '\n'));
    SetFont();
    WordDocument->Range(EmptyParam, EmptyParam)->InsertAfter(StringToOleStr("Species Name:" + Table->Fields->Fields[3]->AsString + '\n'));
    WordDocument->Range(EmptyParam, EmptyParam)->InsertAfter(StringToOleStr("Length: " + Table->Fields->Fields[4]->AsString + '\n'));
    WordDocument->Range(EmptyParam, EmptyParam)->InsertAfter(StringToOleStr("===\n"));
    btnCloseWord->Enabled = True;
    btnPrint->Enabled = True;
    btnPreview->Enabled = True;
  }
  catch (Exception &exception)
  {
    Application->ShowException(&exception);
    WordApplication->Disconnect();
  }

}
//---------------------------------------------------------------------------


void __fastcall TPWordForm::FormCreate(TObject *Sender)
{
  Fonttype->Items = Screen->Fonts;
}
//---------------------------------------------------------------------------

void __fastcall TPWordForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  Table->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TPWordForm::FormActivate(TObject *Sender)
{
  Table->Open();        
}
//---------------------------------------------------------------------------

void __fastcall TPWordForm::WordApplicationDocumentChange(TObject *Sender)
{
  lbDocs->Items->Add(WordDocument->Name);
}
//---------------------------------------------------------------------------

