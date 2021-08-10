//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "mdichild.h"
#include "mdimain.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMDIChildForm *MDIChildForm;
//---------------------------------------------------------------------------
__fastcall TMDIChildForm::TMDIChildForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::DeleteObject1Click(TObject *Sender)
{
  if ((OleContainer1->State == osEmpty) ||
      (MessageDlg("Replace existing object?",
                   mtConfirmation,
                   TMsgDlgButtons() << mbOK << mbCancel,
                   0) == mrOk)) {
    OleContainer1->DestroyObject();
    LocalMenu->Tag = 0;
    while (LocalMenu->Items->Count != 4)
      delete LocalMenu->Items->Items[0];
  }
  MainForm->SaveButton->Enabled = OleContainer1->State != osEmpty;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::Copy1Click(TObject *Sender)
{
  OleContainer1->Copy();
  MainForm->PasteButton->Enabled = True;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::CopyObject1Click(TObject *Sender)
{
  OleContainer1->Copy();
  MainForm->PasteButton->Enabled = True;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::Cut1Click(TObject *Sender)
{
  OleContainer1->Copy();
  OleContainer1->DestroyObject();
  MainForm->CutButton->Enabled = False;
  MainForm->CopyButton->Enabled = False;
  MainForm->PasteButton->Enabled = True;
  FFileName = "";
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::Edit1Click(TObject *Sender)
{
    Cut1->Enabled = OleContainer1->State != osEmpty;
    Copy1->Enabled = OleContainer1->State != osEmpty;
    Paste1->Enabled = OleContainer1->CanPaste;
    PasteSpecial1->Enabled = OleContainer1->CanPaste;
    Object2->Enabled = OleContainer1->State != osEmpty;
    CLear1->Enabled = OleContainer1->State != osEmpty;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::InsertObject1Click(TObject *Sender)
{
  if ((OleContainer1->State == osEmpty) ||
      (MessageDlg("Delete current OLE object?",
                   mtConfirmation,
                   TMsgDlgButtons() << mbOK << mbCancel,
                   0) == mrOk))
    if (OleContainer1->InsertObjectDialog()){
      MainForm->CutButton->Enabled = True;
      MainForm->CopyButton->Enabled = True;
      MainForm->SaveButton->Enabled = OleContainer1->Modified;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::LocalMenuPopup(TObject *Sender)
{
  int i;

  CopyObject1->Enabled = OleContainer1->State != osEmpty;
  DeleteObject1->Enabled = OleContainer1->State != osEmpty;
  Properties1->Enabled = OleContainer1->State != osEmpty;
  if (LocalMenu->Tag > 0)
    exit;
  if ((OleContainer1->State != osEmpty) && (OleContainer1->ObjectVerbs->Count > 0)){
    LocalMenu->Items->Insert(0, NewLine());
    for (i = 0; i < OleContainer1->ObjectVerbs->Count; i++)
      LocalMenu->Items->Insert(i, NewItem(OleContainer1->ObjectVerbs->Names[i],
                                          0, false, true, OnClick, 0, ""));
    LocalMenu->Tag = 1;
  } //if
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::FormActivate(TObject *Sender)
{
    MainForm->CopyButton->Enabled = OleContainer1->State != osEmpty;
    MainForm->CutButton->Enabled = OleContainer1->State != osEmpty;
    MainForm->PasteButton->Enabled = OleContainer1->CanPaste;
    MainForm->SaveButton->Enabled = OleContainer1->Modified;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action = caFree;
    MainForm->CutButton->Enabled = False;
    MainForm->CopyButton->Enabled = False;
    MainForm->PasteButton->Enabled = False;
    MainForm->SaveButton->Enabled = False;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  CanClose = True;
  if (OleContainer1->Modified)
    switch (MessageDlg("Would you like to save changes to the object?",
                       mtConfirmation,
                       TMsgDlgButtons() << mbYes <<  mbNo << mbCancel,
                       0)){
      case mrYes:
          MainForm->Save1Click(Sender);
          if (OleContainer1->Modified)
            CanClose = False;
          break;
      case mrCancel:
          CanClose = False;
          break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::FormCreate(TObject *Sender)
{
  FFileName = "";
  FSaved = False;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::Properties1Click(TObject *Sender)
{
  OleContainer1->ObjectPropertiesDialog();
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::OleContainer1Activate(TObject *Sender)
{
  OleContainer1->Modified = True;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::Paste1Click(TObject *Sender)
{
  if ((OleContainer1->State == osEmpty) ||
      (MessageDlg("Delete current OLE object?",
                   mtConfirmation,
                   TMsgDlgButtons() << mbOK << mbCancel,
                   0) == mrOk))
    OleContainer1->Paste();
  MainForm->SaveButton->Enabled = OleContainer1->Modified;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::PasteSpecial1Click(TObject *Sender)
{
 if ((OleContainer1->State == osEmpty) ||
       (MessageDlg("Delete current OLE object?",
                   mtConfirmation,
                   TMsgDlgButtons() << mbOK << mbCancel,
                   0) == mrOk)){
    if (OleContainer1->PasteSpecialDialog()){
      MainForm->CutButton->Enabled = True;
      MainForm->CopyButton->Enabled = True;
      MainForm->PasteButton->Enabled = OleContainer1->CanPaste;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMDIChildForm::VerbClick(TObject *Sender)
{
  OleContainer1->DoVerb(OleContainer1->ObjectVerbs->IndexOf(dynamic_cast<TMenuItem*>(Sender)->Caption));
}
//---------------------------------------------------------------------
void __fastcall TMDIChildForm::CreateFromFile( AnsiString FileName, bool Linked)
{
  if (Linked)
    OleContainer1->CreateLinkToFile(FileName, False);
  else
    OleContainer1->CreateObjectFromFile(FileName, False);
  Caption = FileName;
  FFileName = FileName;
}
//---------------------------------------------------------------------
void __fastcall TMDIChildForm::SaveFile( AnsiString FileName)
{
  OleContainer1->SaveToFile(FileName);
  FFileName = FileName;
  Caption = FFileName;
  OleContainer1->Modified = False;
}
//---------------------------------------------------------------------------
