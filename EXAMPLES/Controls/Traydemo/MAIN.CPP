//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Trayicon"
#pragma link "trayicon"
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
  TrayIcon1->Visible = VisibleCheck->Checked;
  TrayIcon1->Hide = HideCheck->Checked;
  TrayIcon1->AnimateInterval = atoi(IntervalEdit->Text.c_str());  
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::HideCheckClick(TObject *Sender)
{
  TrayIcon1->Hide = HideCheck->Checked;
  Update();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::VisibleCheckClick(TObject *Sender)
{
  TrayIcon1->Visible = VisibleCheck->Checked;
  HideCheck->Enabled = VisibleCheck->Checked;
  AnimateCheck->Enabled = VisibleCheck->Checked;
  Update();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Restore1Click(TObject *Sender)
{
  TrayIcon1->Restore();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Exit1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::AnimateCheckClick(TObject *Sender)
{
  TrayIcon1->Animate = AnimateCheck->Checked;
  if (AnimateCheck->Checked == false)
    TrayIcon1->IconIndex = 0;
  Update();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::IntervalEditChange(TObject *Sender)
{
  TrayIcon1->AnimateInterval = atoi(IntervalEdit->Text.c_str());
}
//---------------------------------------------------------------------------

