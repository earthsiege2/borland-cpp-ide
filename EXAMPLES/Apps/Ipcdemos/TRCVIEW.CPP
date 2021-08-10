//-----------------------------------------------------------------------------
#include "TrcView.h"
//-----------------------------------------------------------------------------
#pragma resource "*.DFM"

TTraceForm*  TraceForm;
__fastcall TTraceForm::TTraceForm(TComponent* Owner) : TForm(Owner)
{
}


void __fastcall TTraceForm::TraceDataKeyPress( TObject* Sender, Char& Key)
{
  if (Key == 0x27) Close();
}

