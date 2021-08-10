//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "bufferlistform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TBufferListFrm::TBufferListFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBufferListFrm::BufferListBoxDblClick(TObject *Sender)
{
  if (BufferListBox->ItemIndex > -1)
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

