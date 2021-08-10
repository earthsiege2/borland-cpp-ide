//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include "thsort.h"
#include "sortthd.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TThreadSortForm *ThreadSortForm;
//---------------------------------------------------------------------
Boolean ArraysRandom;
TSortArray BubbleSortArray, SelectionSortArray, QuickSortArray;

//---------------------------------------------------------------------
__fastcall TThreadSortForm::TThreadSortForm(TComponent *Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------
void __fastcall TThreadSortForm::PaintArray(TPaintBox *Box, int const *A, 
  int const ASize)
{
  int i;
  TCanvas *canvas;

  canvas = Box->Canvas;
  canvas->Pen->Color = clRed;

  for (i=0; i <= ASize; i++)
    PaintLine(canvas, i, A[i]);
}
//---------------------------------------------------------------------
void __fastcall TThreadSortForm::BubbleSortBoxPaint(TObject * /*Sender*/)
{
  PaintArray(BubbleSortBox, EXISTINGARRAY(BubbleSortArray));
}
//---------------------------------------------------------------------
void __fastcall TThreadSortForm::SelectionSortBoxPaint(TObject * /*Sender*/)
{
  PaintArray(SelectionSortBox, EXISTINGARRAY(SelectionSortArray));
}
//---------------------------------------------------------------------
void __fastcall TThreadSortForm::QuickSortBoxPaint(TObject * /*Sender*/)
{
  PaintArray(QuickSortBox, EXISTINGARRAY(QuickSortArray));
}
//---------------------------------------------------------------------
void __fastcall TThreadSortForm::FormCreate(TObject * /*Sender*/)
{
  RandomizeArrays();
}
//---------------------------------------------------------------------
void __fastcall TThreadSortForm::StartBtnClick(TObject * /*Sender*/)
{
  TBubbleSort *bubble;  
  TSelectionSort *selsort;
  TQuickSort *qsort;

  RandomizeArrays();
  ThreadsRunning = 3;

  bubble = new TBubbleSort(BubbleSortBox, EXISTINGARRAY(BubbleSortArray));
  bubble->OnTerminate = ThreadDone;

  selsort = new TSelectionSort(SelectionSortBox,
    EXISTINGARRAY(SelectionSortArray));
  selsort->OnTerminate = ThreadDone;

  qsort = new TQuickSort(QuickSortBox, EXISTINGARRAY(QuickSortArray));
  qsort->OnTerminate = ThreadDone;

  StartBtn->Enabled = False;
}
//---------------------------------------------------------------------
void __fastcall TThreadSortForm::RandomizeArrays()
{
  int i;

  if (! ArraysRandom)
  {
    Randomize();
    for (i=0; i < ARRAYSIZE(BubbleSortArray); i++)
      BubbleSortArray[i] = random(170);

    memcpy(SelectionSortArray, BubbleSortArray, sizeof(SelectionSortArray));
    memcpy(QuickSortArray, BubbleSortArray, sizeof(QuickSortArray));

    ArraysRandom = True;
    Repaint();
  }
}
//---------------------------------------------------------------------
void __fastcall TThreadSortForm::ThreadDone(TObject * /*Sender*/)
{
  ThreadsRunning--;
  if (! ThreadsRunning)
  {
    StartBtn->Enabled = True;
    StartBtn->SetFocus();
    ArraysRandom = False;
  }
}
//---------------------------------------------------------------------
