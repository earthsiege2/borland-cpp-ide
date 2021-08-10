//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ShellCtrls"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::actnBackUpdate(TObject *Sender)
{
    actnBack->Enabled = ShellTreeView1->SelectedFolder()->Level;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::actnBackExecute(TObject *Sender)
{
    ShellListView1->Back();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::actnRefreshExecute(TObject *Sender)
{
    ShellListView1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::actnIconUpdate(TObject *Sender)
{
    switch (ShellListView1->ViewStyle)
    {
        case vsIcon:
            actnIcon->Checked = true;
            break;
        case vsList:
            actnList->Checked = true;
            break;
        case vsReport:
            actnReport->Checked = true;
            break;
        case vsSmallIcon:
            actnSmallIcon->Checked = true;
            break;

    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::actnIconExecute(TObject *Sender)
{
    // The tag of the action contains the view style
    TAction *actn = dynamic_cast<TAction *>(Sender);
    ShellListView1->ViewStyle = (TViewStyle)actn->Tag;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    // Initialize the tags
    actnIcon->Tag = (int)vsIcon;
    actnList->Tag = (int)vsList;
    actnReport->Tag = (int)vsReport;
    actnSmallIcon->Tag = (int)vsSmallIcon;    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::actnSortedUpdate(TObject *Sender)
{
  actnSorted->Checked = ShellListView1->Sorted;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::actnSortedExecute(TObject *Sender)
{
  ShellListView1->Sorted = actnSorted->Checked;
}
//---------------------------------------------------------------------------


