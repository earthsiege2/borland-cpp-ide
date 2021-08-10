//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "mdimain.h"
#include "mdichild.h"
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
void __fastcall TMainForm::About1Click(TObject *Sender)
{
  TAboutBox* AboutBox = new TAboutBox(this);
  AboutBox->ShowModal();
  delete AboutBox;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ArrangeIcons1Click(TObject *Sender)
{
  ArrangeIcons();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Cascade1Click(TObject *Sender)
{
  Cascade();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Close1Click(TObject *Sender)
{
  if (ActiveMDIChild != NULL)
    this->ActiveMDIChild->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseAll1Click(TObject *Sender)
{
  int i;
  for (i = 0; i < MDIChildCount; i++)
      MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CopyButtonClick(TObject *Sender)
{
  if (this->ActiveMDIChild != NULL)
    ((TMDIChildForm*)this->ActiveMDIChild)->OleContainer1->Copy();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CutButtonClick(TObject *Sender)
{
  if (ActiveMDIChild != NULL){
      TMDIChildForm* ch = (TMDIChildForm*) this->ActiveMDIChild;
      ch->OleContainer1->Copy();
      ch->OleContainer1->DestroyObject();
      CutButton->Enabled = False;
      CopyButton->Enabled = False;
      PasteButton->Enabled = True;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Exit1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::File1Click(TObject *Sender)
{
  if (this->ActiveMDIChild != NULL){
    TMDIChildForm* ch = (TMDIChildForm*) this->ActiveMDIChild;
    Save1->Enabled = ch->OleContainer1->Modified;
    SaveAs1->Enabled = ch->OleContainer1->Modified;
  }
  else {
    Save1->Enabled = False;
    SaveAs1->Enabled = False;
  }
  Close2->Enabled = this->ActiveMDIChild != NULL;
  CloseAll1->Enabled = this->ActiveMDIChild != NULL;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LinkButtonClick(TObject *Sender)
{
  TMDIChildForm* MDIChild;

  if (ActiveMDIChild == NULL) {

    if (OpenDialog1->Execute()){

      MDIChild = new TMDIChildForm(this);
      MDIChild->CreateFromFile(OpenDialog1->FileName, True);
    }
  }
  else{
    MDIChild = (TMDIChildForm*) this->ActiveMDIChild;
    if ((MDIChild->OleContainer1->State == osEmpty) ||
        (MessageDlg("Replace existing object?",
                    mtConfirmation,
                    TMsgDlgButtons() << mbOK << mbCancel,
                    0) == mrOk))
      if (OpenDialog1->Execute())
        MDIChild->CreateFromFile(OpenDialog1->FileName, True);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
  Application->OnHint = ShowHint;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::New1Click(TObject *Sender)
{
  MDIChildForm = new TMDIChildForm(this);
  MDIChildForm->InsertObject1Click(Sender);
  if (MDIChildForm->OleContainer1->NewInserted)
    MDIChildForm->OleContainer1->DoVerb(ovPrimary);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Open1Click(TObject *Sender)
{
    if (OpenDialog1->Execute()){
        TMDIChildForm* ch = new TMDIChildForm(this);
          ch->CreateFromFile(OpenDialog1->FileName, False);
      CutButton->Enabled = True;
      CopyButton->Enabled = True;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Paste1Click(TObject *Sender)
{
  if (ActiveMDIChild == NULL)
    return;

  TMDIChildForm* ch = (TMDIChildForm*) this->ActiveMDIChild;
    if ((ch->OleContainer1->State == osEmpty) ||
        (MessageDlg("Replace existing object?",
                    mtConfirmation,
                    TMsgDlgButtons() << mbOK << mbCancel,
                    0) == mrOk)){
        ch->OleContainer1->Paste();
        CutButton->Enabled = True;
        CopyButton->Enabled = True;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Save1Click(TObject *Sender)
{
  TMDIChildForm* ch = (TMDIChildForm*) this->ActiveMDIChild;

  if (((ch->FileName.Length()) == 0) || (Sender == SaveAs1)) {
    if (SaveDialog1->Execute())
      ch->SaveFile(SaveDialog1->FileName);
  }
  else
    ch->SaveFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Tile1Click(TObject *Sender)
{
  TileMode = tbHorizontal;
  Tile();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TileHorizontally1Click(TObject *Sender)
{
  TileMode = tbVertical;
  Tile();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Window2Click(TObject *Sender)
{
  Tile1->Enabled               = (ActiveMDIChild != NULL);
  TileHorizontally1->Enabled   = (ActiveMDIChild != NULL);
  Cascade1->Enabled            = (ActiveMDIChild != NULL);
  ArrangeIcons1->Enabled       = (ActiveMDIChild != NULL);
}
//---------------------------------------------------------------------
void __fastcall TMainForm::ShowHint(TObject *Sender)
{
  StatusBar->Panels->Items[0]->Text = Application->Hint;
}
//---------------------------------------------------------------------
void __fastcall TMainForm::Object2Click(TObject *Sender)
{
  if ((this->ActiveMDIChild) != NULL)
    ((TMDIChildForm*) this->ActiveMDIChild)->OleContainer1->ObjectPropertiesDialog();
}//---------------------------------------------------------------------------
