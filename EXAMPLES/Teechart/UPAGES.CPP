/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UPages.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPagesForm *PagesForm;

/*
  This form demonstrates how Charts can be divided in several Pages->
  The main Chart property is "MaxPointsPerPage"->
  TeeChart automatically calculates the total number of pages based on that
  property->
  The other Paging properties and methods are:

    Chart->Page     : Longint    Sets and returns the current Chart Page->
    Chart->NumPages : Longint    Returns the Total Number of Pages->
    method Chart->NextPage ;     Goes to next page->
    method Chart->PreviousPage ; Goes to previous page->
*/

//---------------------------------------------------------------------------
__fastcall TPagesForm::TPagesForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPagesForm::FormCreate(TObject *Sender)
{
  LineSeries1->FillSampleValues(100);      // <-- some random points
  BubbleSeries1->FillSampleValues(100);
  ScrollBar1->Position = 10;         // <-- max number of points per page
  Chart1PageChange(Chart1);    // <-- repaint page / number of pages
}
//---------------------------------------------------------------------------
void __fastcall TPagesForm::Chart1PageChange(TObject *Sender)
{
  Chart1->UndoZoom();
  // show the current page number and the total number of pages
  // (like a report)
  Label1->Caption =
    String(Chart1->Page)+"/"+String(Chart1->NumPages());
  // enable or disable buttons
  ButtonPrevious->Enabled = Chart1->Page > 1;
  ButtonNext->Enabled = Chart1->Page < Chart1->NumPages();
  BLastPage->Enabled = ButtonNext->Enabled;
  BFirstPage->Enabled = ButtonPrevious->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TPagesForm::ButtonPreviousClick(TObject *Sender)
{
  Chart1->PreviousPage(); // <-- goto previous chart page
}
//---------------------------------------------------------------------------
void __fastcall TPagesForm::ButtonNextClick(TObject *Sender)
{
  Chart1->NextPage();  // <-- goto next chart page
}
//---------------------------------------------------------------------------
void __fastcall TPagesForm::CheckBox1Click(TObject *Sender)
{
  Chart1->ScaleLastPage = CheckBox1->Checked;  // <-- only for last page
}
//---------------------------------------------------------------------------
void __fastcall TPagesForm::BFirstPageClick(TObject *Sender)
{
  Chart1->Page = 1;  // go to first page
}
//---------------------------------------------------------------------------
void __fastcall TPagesForm::BLastPageClick(TObject *Sender)
{
  Chart1->Page = Chart1->NumPages();  // go to last page
}
//---------------------------------------------------------------------------
void __fastcall TPagesForm::ScrollBar1Change(TObject *Sender)
{
  // change the max number of points per page
  // a value of Zero means "No pages-> Show all points"
  Chart1->MaxPointsPerPage = ScrollBar1->Position;
  Chart1PageChange(Chart1); // <-- repaint page / number of pages
}
//---------------------------------------------------------------------------

