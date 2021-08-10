//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmFingerDemo *frmFingerDemo;
//---------------------------------------------------------------------------
__fastcall TfrmFingerDemo::TfrmFingerDemo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmFingerDemo::bbtnQuerryClick(TObject *Sender)
{
     // Set the Query string for the Finger from the text entered
     IdFngFinger->CompleteQuery = edtQuerry->Text;
     // Do we want verbose query - not supported on many systems
     IdFngFinger->VerboseOutput = chkVerboseQuerry->Checked;
     // Do our query with the Finger function
     mmoQuerryResults->Lines->Text = IdFngFinger->Finger();
}
//---------------------------------------------------------------------------
