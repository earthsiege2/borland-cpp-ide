//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LogLab.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCustomLabelsForm *CustomLabelsForm;
//---------------------------------------------------------------------------
__fastcall TCustomLabelsForm::TCustomLabelsForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TCustomLabelsForm::FormCreate(TObject *Sender)
{
  // Axis settings
  Chart1->BottomAxis->Logarithmic = true;
  Chart1->BottomAxis->TickOnLabelsOnly = true;
  Chart1->BottomAxis->SetMinMax( 10.0, 1000);
  Chart1->LeftAxis->Logarithmic = true;
  Chart1->LeftAxis->TickOnLabelsOnly = true;
  Chart1->LeftAxis->SetMinMax( 10.0, 1000);

  // adding XY values to Series1
  Series1->XValues->DateTime = false;
  Series1->AddXY( 100, 100, "", clTeeColor );
  Series1->AddXY( 500, 200, "", clTeeColor );
  Series1->AddXY( 800, 300, "", clTeeColor );
  Series1->AddXY( 200, 200, "", clTeeColor );  // Axis settings
  Chart1->BottomAxis->Logarithmic = true;
  Chart1->BottomAxis->TickOnLabelsOnly = true;
  Chart1->BottomAxis->SetMinMax( 10.0, 1000);
  Chart1->LeftAxis->Logarithmic = true;
  Chart1->LeftAxis->TickOnLabelsOnly = true;
  Chart1->LeftAxis->SetMinMax( 10.0, 1000);

  // adding XY values to Series1
  Series1->XValues->DateTime = false;
  Series1->AddXY( 100, 100, "", clTeeColor );
  Series1->AddXY( 500, 200, "", clTeeColor );
  Series1->AddXY( 800, 300, "", clTeeColor );
  Series1->AddXY( 200, 200, "", clTeeColor );
}
//---------------------------------------------------------------------------
