/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UClick.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TClickingForm *ClickingForm;
//---------------------------------------------------------------------------
__fastcall TClickingForm::TClickingForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TClickingForm::FormCreate(TObject *Sender)
{
  // sample values
  Series1->Add( 100, "John",  clRed );
  Series1->Add(  70, "Mary",  clYellow );
  Series1->Add( 130, "Mike",  clBlue );
  Series1->Add( 190, "Peter", clGreen );

  // nice cursor
  Series1->Cursor = (TCursor)crTeeHand;
}

// Use this event to get notified when users click over a
// Series point (or Bar, or Line, etc)
//---------------------------------------------------------------------------
void __fastcall TClickingForm::Chart1ClickSeries(TCustomChart *Sender,
      TChartSeries *Series, int ValueIndex, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  ShowMessage( "Point has been clicked ! \n\n"
               "Series: "+Series->Name +"\n"+
               "Point Index: "+IntToStr( ValueIndex )+ "\n"+
               "Point Value: "+FloatToStr(Series->YValue[ValueIndex])+ "\n"+
               "Point Label: "+Series->XLabel[ValueIndex]+ "\n"+
               "Point Color: "+ColorToString(Series->ValueColor[ValueIndex])+"\n"+"\n"+
               "Advanced: "+"\n"+
               "Point X pixel coordinate: "+IntToStr(Series->CalcXPos(ValueIndex))+"\n"+
               "Point Y pixel coordinate: "+IntToStr(Series->CalcYPos(ValueIndex))
              );
}
//---------------------------------------------------------------------------
void __fastcall TClickingForm::Button1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TClickingForm::Chart1ClickLegend(TCustomChart *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int tmp = Chart1->Legend->Clicked(X,Y);
  if (tmp != -1)
    Chart1ClickSeries(Sender,Series1,tmp,Button,Shift,X,Y);
}
//---------------------------------------------------------------------------
void __fastcall TClickingForm::Chart1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  if (Chart1->Legend->Clicked(X,Y) != -1)
    Chart1->Cursor = (TCursor)crTeeHand;
  else
    Chart1->Cursor = crDefault;
  Chart1->OriginalCursor = Chart1->Cursor;
}
//---------------------------------------------------------------------------
 