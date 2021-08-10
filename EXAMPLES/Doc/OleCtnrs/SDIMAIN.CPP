//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <memory>     //for STL auto_ptr
#include "sdimain.h"
#include "about.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Exit1Click(TObject *Sender)
{
  if (OleContainer1->State != osEmpty){
    switch(MessageDlg("Would you like to save the current OLE object?",
                      mtConfirmation,
                      TMsgDlgButtons() <<  mbYes << mbNo << mbCancel, 0)){
    case mrYes:
      Save1Click(Sender);
    case mrNo:
      Close();
      break;
    case mrCancel:
      break;
    }
  }
  else
    Close();
}
//---------------------------------------------------------------------
void __fastcall TMainForm::Save1Click(TObject *Sender)
{
    SaveDialog1->FileName = ObjectFileName;
    if ((SaveDialog1->FileName.Length() == 0) || (Sender == SaveAs1))
    {
      if (SaveDialog1->Execute())
      {
        OleContainer1->SaveToFile(SaveDialog1->FileName);
        ObjectFileName = SaveDialog1->FileName;
      }
    }
    else
      OleContainer1->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------
void __fastcall TMainForm::PasteSpecial1Click(TObject *Sender)
{
   if ((OleContainer1->State == osEmpty) ||
    (MessageDlg("Delete current OLE object?", mtConfirmation,
                TMsgDlgButtons() <<  mbOK << mbCancel, 0) == mrOk))
  {
    if (OleContainer1->PasteSpecialDialog())
    {
      CutButton->Enabled = True;
      CopyButton->Enabled = True;
      PasteButton->Enabled = OleContainer1->CanPaste;
    }
  }
}
//---------------------------------------------------------------------
void __fastcall TMainForm::Paste1Click(TObject *Sender)
{
  if ((OleContainer1->State == osEmpty) ||
    (MessageDlg("Replace existing object?", mtConfirmation,
                TMsgDlgButtons() <<  mbOK << mbCancel, 0) == mrOk))
  {
    OleContainer1->Paste();
    CopyButton->Enabled = True;
    CutButton->Enabled = True;
  }
}
//---------------------------------------------------------------------
void __fastcall TMainForm::Open1Click(TObject *Sender)
{
    if (OpenDialog1->Execute()){
      OleContainer1->CreateObjectFromFile(OpenDialog1->FileName, False);
      ObjectFileName = OpenDialog1->FileName;
      CutButton->Enabled = True;
      CopyButton->Enabled = True;
      PasteButton->Enabled = True;
    }
}
//---------------------------------------------------------------------
void __fastcall TMainForm::Object1Click(TObject *Sender)
{
   if ((OleContainer1->State == osEmpty) ||
    (MessageDlg("Delete current OLE object?", mtConfirmation,
                TMsgDlgButtons() <<  mbOK << mbCancel, 0) == mrOk))
    if (OleContainer1->InsertObjectDialog())
    {
      CutButton->Enabled = True;
      CopyButton->Enabled = True;
      PasteButton->Enabled = OleContainer1->CanPaste;
      OleContainer1->DoVerb(ovPrimary);
    }
}
//---------------------------------------------------------------------
void __fastcall TMainForm::New1Click(TObject *Sender)
{
  if ((OleContainer1->State == osEmpty) ||
    (MessageDlg("Delete existing object?", mtConfirmation,
                TMsgDlgButtons() <<  mbOK << mbCancel, 0) == mrOk))
    {
        OleContainer1->DestroyObject();
        Object1Click(Sender);
        OleContainer1->DoVerb(ovPrimary);
        ObjectFileName = "";
    }
}
//---------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
  ObjectFileName = "";
  Application->OnHint = ShowHint;
}
//---------------------------------------------------------------------
void __fastcall TMainForm::LinkButtonClick(TObject *Sender)
{
   if ((OleContainer1->State == osEmpty) ||
    (MessageDlg("Replace existing object?", mtConfirmation,
                TMsgDlgButtons() <<  mbOK << mbCancel, 0) == mrOk))
      if (OpenDialog1->Execute())
      {
        OleContainer1->CreateLinkToFile(OpenDialog1->FileName, False);
        ObjectFileName = OpenDialog1->FileName;
        CutButton->Enabled = True;
        CopyButton->Enabled = True;
        PasteButton->Enabled = OleContainer1->CanPaste;
      }
}
//---------------------------------------------------------------------
void __fastcall TMainForm::File1Click(TObject *Sender)
{
    Save1->Enabled = OleContainer1->Modified;
    SaveAs1->Enabled = OleContainer1->Modified;
}
//---------------------------------------------------------------------
void __fastcall TMainForm::Edit1Click(TObject *Sender)
{
    Cut1->Enabled = OleContainer1->State != osEmpty;
    Copy1->Enabled = OleContainer1->State != osEmpty;
    Paste1->Enabled = OleContainer1->CanPaste;
    PasteSpecial1->Enabled = OleContainer1->CanPaste;
}
//---------------------------------------------------------------------
void __fastcall TMainForm::CutButtonClick(TObject *Sender)
{
   if (OleContainer1->State != osEmpty)
      OleContainer1->Copy();
      OleContainer1->DestroyObject();
      CopyButton->Enabled = False;
      PasteButton->Enabled = OleContainer1->CanPaste;
      ObjectFileName = "";
}
//---------------------------------------------------------------------
void __fastcall TMainForm::Cut1Click(TObject *Sender)
{
  OleContainer1->Copy();
  OleContainer1->DestroyObject();
  CutButton->Enabled = False;
  CopyButton->Enabled = False;
  PasteButton->Enabled = OleContainer1->CanPaste;

}
//---------------------------------------------------------------------
void __fastcall TMainForm::Copy1Click(TObject *Sender)
{
  OleContainer1->Copy();
  PasteButton->Enabled = True;
}
//---------------------------------------------------------------------
void __fastcall TMainForm::About1Click(TObject *Sender)
{
   std::auto_ptr<TAboutBox> AboutBox(new TAboutBox(this));
   AboutBox->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TMainForm::ShowHint(TObject *Sender)
{
  StatusBar->Panels->Items[0]->Text = Application->Hint;
}