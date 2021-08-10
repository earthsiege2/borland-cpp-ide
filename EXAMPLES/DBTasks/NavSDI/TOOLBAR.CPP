//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ToolBar.h"
#include "DM.h"
#include "About.h"
#include "custdata.h"
#include "custords.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfmToolBar *fmToolBar;
//---------------------------------------------------------------------------
__fastcall TfmToolBar::TfmToolBar(TComponent* Owner)
  : TForm(Owner)
{
  Orders1->Checked = true;
  Customers1->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TfmToolBar::First1Click(TObject *Sender)
{
  DM1->Customer->First();
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::Next1Click(TObject *Sender)
{
  DM1->Customer->Next();
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::Prior1Click(TObject *Sender)
{
  DM1->Customer->Prior();
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::Last1Click(TObject *Sender)
{
  DM1->Customer->Last();
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::Delete1Click(TObject *Sender)
{
  DM1->Customer->Delete();
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::Insert1Click(TObject *Sender)
{
  DM1->Customer->Insert();
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::Cancel1Click(TObject *Sender)
{
  DM1->Customer->Cancel();
  UpdateMenu();
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::Close1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::About1Click(TObject *Sender)
{
  fmAboutBox->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::Messages1Click(TObject *Sender)
{
  Messages1->Checked = !Messages1->Checked;
}
//---------------------------------------------------------------------
void __fastcall TfmToolBar::SetNavigator(const TDataSource* ds)
{
  if(DBNavigator1->DataSource != ds){
    if(Messages1->Checked)
      ShowMessage(AnsiString("Changing DBNavigator's datasource to ") + ds->Name);
    DBNavigator1->DataSource = (TDataSource*) ds;
    UpdateMenu();
   }

}

void __fastcall TfmToolBar::UpdateMenu()
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
void __fastcall TfmToolBar::Customers1Click(TObject *Sender)
{
  Customers1->Checked = !Customers1->Checked;
  fmCustomer->Visible = Customers1->Checked;        
}
//---------------------------------------------------------------------------

void __fastcall TfmToolBar::Orders1Click(TObject *Sender)
{
  Orders1->Checked = !Orders1->Checked;
  fmCustOrd->Visible = Orders1->Checked;
}
//---------------------------------------------------------------------------

