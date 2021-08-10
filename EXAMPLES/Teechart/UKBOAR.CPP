/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UKBoar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKeyboardForm *KeyboardForm;
//---------------------------------------------------------------------------
__fastcall TKeyboardForm::TKeyboardForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKeyboardForm::FormCreate(TObject *Sender)
{
  LineSeries1->FillSampleValues(500);
  AnimatedZoomFactor = 4;
}
//---------------------------------------------------------------------------
void __fastcall TKeyboardForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  double XDelta,YDelta,XRange,YRange;
  // initialize some temporary variables
  XDelta = 0;
  YDelta = 0;
  XRange = LineSeries1->GetHorizAxis->Maximum - LineSeries1->GetHorizAxis->Minimum;
  YRange = LineSeries1->GetVertAxis->Maximum - LineSeries1->GetVertAxis->Minimum;
  // handle keyboard !!!
  if (Shift.Contains(ssShift)) {
    switch (Key) {
      case VK_LEFT :
      case VK_UP   : {
        Chart1->ZoomPercent( 110 );
        break;
      }
      case VK_RIGHT :
      case VK_DOWN  : {
        Chart1->ZoomPercent( 90 );
        break;
      }
    }
    return;
  }
  else switch (Key) {
    case VK_LEFT  : XDelta = -XRange/100; break;
    case VK_RIGHT : XDelta =  XRange/100; break;
    case VK_UP    : YDelta =  YRange/100; break;
    case VK_DOWN  : YDelta = -YRange/100; break;
    case VK_NEXT  : YDelta = -YRange/10; break;
    case VK_PRIOR : YDelta =  YRange/10; break;
    case VK_SPACE : {
      Chart1->UndoZoom();
      return;
    }  // <-- reset scrolling
  }
  // just to make this example a little better
  if (!InvertScroll->Checked) {
    XDelta = -XDelta;
    YDelta = -YDelta;
  }
  // apply scrolling !!!
  Chart1->LeftAxis->Scroll(YDelta,CheckLimits->Checked);
  Chart1->RightAxis->Scroll(YDelta,CheckLimits->Checked);
  Chart1->BottomAxis->Scroll(XDelta,CheckLimits->Checked);
  Chart1->TopAxis->Scroll(XDelta,CheckLimits->Checked);
  Chart1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKeyboardForm::CheckLimitsClick(TObject *Sender)
{
  ShowMessage("Please zoom before scrolling.");
  Chart1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKeyboardForm::InvertScrollClick(TObject *Sender)
{
  Chart1->SetFocus();
}
//---------------------------------------------------------------------------
