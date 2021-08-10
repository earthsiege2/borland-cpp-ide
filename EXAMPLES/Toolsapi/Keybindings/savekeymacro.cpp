//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "savekeymacro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TSaveKeyMacroDlg::TSaveKeyMacroDlg(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSaveKeyMacroDlg::Button1Click(TObject *Sender)
{
  if (SaveDialog1->Execute())
    Edit1->Text = SaveDialog1->FileName;
}
//---------------------------------------------------------------------------

