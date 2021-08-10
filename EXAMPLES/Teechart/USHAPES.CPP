//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UShapes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TShapesForm *ShapesForm;
//---------------------------------------------------------------------------
__fastcall TShapesForm::TShapesForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TShapesForm::FormCreate(TObject *Sender)
{
  LineSeries1->XValues->DateTime = false;
  LineSeries1->Clear();
  LineSeries1->Add( 100, "Jan", clTeeColor );
  LineSeries1->Add( 140, "Feb", clTeeColor );
  LineSeries1->Add( 120, "Mar", clTeeColor );
  LineSeries1->Add( 110, "Apr", clTeeColor );
  LineSeries1->Add(  80, "May", clTeeColor );
  LineSeries1->Add(  90, "Jun", clTeeColor );
  LineSeries1->Add(  75, "Jul", clTeeColor );
  LineSeries1->Add(  85, "Aug", clTeeColor );
  LineSeries1->Add(  95, "Sep", clTeeColor );
  LineSeries1->Add( 105, "Oct", clTeeColor );
  LineSeries1->Add( 100, "Nov", clTeeColor );
  LineSeries1->Add(  90, "Dec", clTeeColor );

  LineSeries2->XValues->DateTime = false;
  LineSeries2->Clear();
  LineSeries2->Add(  60, "Jan", clTeeColor );
  LineSeries2->Add( 100, "Feb", clTeeColor );
  LineSeries2->Add(  20, "Mar", clTeeColor );
  LineSeries2->Add(  70, "Apr", clTeeColor );
  LineSeries2->AreaBrush = bsCross;

  ChartShape1->X0 =    2;
  ChartShape1->X1 =    8;
  ChartShape1->Y0 =  100;
  ChartShape1->Y1 =  130;

  ChartShape2->X0 =    5;
  ChartShape2->X1 =    9;
  ChartShape2->Y0 =   60;
  ChartShape2->Y1 =   80;

  ChartShape3->X0 =    1;
  ChartShape3->X1 =    4;
  ChartShape3->Y0 =  135;
  ChartShape3->Y1 =  120;

  ChartShape3->Cursor = crCross;

}
//---------------------------------------------------------------------------

void __fastcall TShapesForm::ChartShape3Click(TChartSeries *Sender,
      int ValueIndex, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ShowMessage("You clicked the ChartShape3 (Rectangle)");
}
//---------------------------------------------------------------------------
