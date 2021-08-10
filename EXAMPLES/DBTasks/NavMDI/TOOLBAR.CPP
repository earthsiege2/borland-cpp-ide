//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Toolbar.h"
#include "DM.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfmToolbar *fmToolbar;
//---------------------------------------------------------------------------
__fastcall TfmToolbar::TfmToolbar(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmToolbar::Close1Click(TObject *Sender)
{
  Application->Terminate();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::about1Click(TObject *Sender)
{
  fmAboutBox->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::Messages1Click(TObject *Sender)
{
  // Used to display messages on change of focus.
  Messages1->Checked = !Messages1->Checked;
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::Tile1Click(TObject *Sender)
{
  Tile();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::Cascade1Click(TObject *Sender)
{
  Cascade();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::First1Click(TObject *Sender)
{
  DBNavigator1->BtnClick(nbFirst);
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::Next1Click(TObject *Sender)
{
  DBNavigator1->BtnClick(nbNext);
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::Prior1Click(TObject *Sender)
{
  DBNavigator1->BtnClick(nbPrior);
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::Last1Click(TObject *Sender)
{
  DBNavigator1->BtnClick(nbLast);
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::Delete1Click(TObject *Sender)
{
  DBNavigator1->BtnClick(nbDelete);
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::Insert1Click(TObject *Sender)
{
  DBNavigator1->BtnClick(nbInsert);
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::Cancel1Click(TObject *Sender)
{
  DBNavigator1->BtnClick(nbCancel);
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::SetNavigator(const TDataSource* ds)
{
  if(DBNavigator1->DataSource != ds){
    if(Messages1->Checked)
      ShowMessage(AnsiString("Changing DBNavigator's datasource to ") + ds->Name);
    DBNavigator1->DataSource = (TDataSource*) ds;
    UpdateMenu();
   }

}
//---------------------------------------------------------------------
void __fastcall TfmToolbar::UpdateMenu()
{
  First1->Enabled = !DBNavigator1->DataSource->DataSet->Bof;
  Next1->Enabled = !DBNavigator1->DataSource->DataSet->Eof;
  Prior1->Enabled = !DBNavigator1->DataSource->DataSet->Bof;
  Last1->Enabled = !DBNavigator1->DataSource->DataSet->Eof;
  Insert1->Enabled = DBNavigator1->DataSource->DataSet->State == dsBrowse;
  Delete1->Enabled = DBNavigator1->DataSource->DataSet->State == dsBrowse;
  Cancel1->Enabled = DBNavigator1->DataSource->DataSet->State == dsEdit ||
                     DBNavigator1->DataSource->DataSet->State == dsInsert;
}
//---------------------------------------------------------------------

void __fastcall TfmToolbar::FormShow(TObject *Sender)
{
  UpdateMenu();	
}
//---------------------------------------------------------------------
