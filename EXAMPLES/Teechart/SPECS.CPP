//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "specs.h"
#include <TeeAbout.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChartSpecs *ChartSpecs;
//---------------------------------------------------------------------------
__fastcall TChartSpecs::TChartSpecs(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChartSpecs::BitBtn2Click(TObject *Sender)
{
  TTeeAboutForm* form = new TTeeAboutForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------
