/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UPrint.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrintForm *PrintForm;
//---------------------------------------------------------------------------
__fastcall TPrintForm::TPrintForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrintForm::FormCreate(TObject *Sender)
{
  LineSeries1->FillSampleValues(30); // <-- we need some random values
}
//---------------------------------------------------------------------------
void __fastcall TPrintForm::BitBtn1Click(TObject *Sender)
{
  int h,w;
  Screen->Cursor = crHourGlass; // <-- nice detail }
  try {
    Printer()->BeginDoc();       // <-- start printer job
    try {
      // now print some text on Printer()->canvas
      Printer()->Canvas->Font->Name = "Arial";
      Printer()->Canvas->Font->Size = 10;             // <-- set the font size
      Printer()->Canvas->Font->Style.Clear();
      Printer()->Canvas->TextOut(0,0,Edit1->Text);   // <-- print some text

      h = Printer()->PageHeight; // <-- get page height
      w = Printer()->PageWidth;  // <-- get page width

      // And now print the chart component
      Chart1->PrintPartial( Rect(
        w / 5,          // <-- 20% left margin
        h / 3 ,         // <-- 33% top margin
        w - (w / 5),    // <-- 20% right margin
        h - (h / 5)));  // <-- 20% bottom margin


      // print more text
      Printer()->Canvas->Font->Name = "Arial";
      Printer()->Canvas->Font->Size = 12;             // <-- set the font size
      Printer()->Canvas->Font->Style = TFontStyles() << fsItalic;
      Printer()->Canvas->TextOut(0,60,Edit1->Text+" ...again");   // <-- print some text

      Printer()->EndDoc(); // <-- end job and print !!
    }
    catch (...) {
      // just in case an error happens
      Printer()->Abort();
      Printer()->EndDoc();
      throw;       // <-- rethrow the exception !!!
    }
  }
  __finally {
    Screen->Cursor = crDefault; // <-- restore cursor
  }
}
//---------------------------------------------------------------------------
