//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "sortthd.h"
//---------------------------------------------------------------------
void __fastcall PaintLine(TCanvas *Canvas, int I, int Len)
{
  TPoint points[2];

  points[0] = Point(0, I*2+1);
  points[1] = Point(Len, I*2+1);

  Canvas->Polyline(EXISTINGARRAY(points));
}
//---------------------------------------------------------------------
__fastcall TSortThread::TSortThread(TPaintBox *Box, int *SortArray, 
    const int SortArray_Size)
    : TThread(False)
{
  FBox = Box;
  FSortArray = SortArray;
  FSize = SortArray_Size + 1;
  FreeOnTerminate = True;
}
//---------------------------------------------------------------------
/* Since DoVisualSwap uses a VCL component (i.e., the TPaintBox) it should never
  be called directly by this thread.  DoVisualSwap should be called by passing
  it to the Synchronize method which causes DoVisualSwap to be executed by the
  main VCL thread, avoiding multi-thread conflicts. See VisualSwap for an
  example of calling Synchronize. */

void __fastcall TSortThread::DoVisualSwap()
{
  TCanvas *canvas;
  canvas = FBox->Canvas;
  canvas->Pen->Color = TColor(clBtnFace);
  PaintLine(canvas, FI, FA);
  PaintLine(canvas, FJ, FB);
  canvas->Pen->Color = clRed;
  PaintLine(canvas, FI, FB);
  PaintLine(canvas, FJ, FA);
}
//---------------------------------------------------------------------
/* VisusalSwap is a wrapper on DoVisualSwap making it easier to use.  The
  parameters are copied to instance variables so they are accessable
  by the main VCL thread when it executes DoVisualSwap */

void __fastcall TSortThread::VisualSwap(int A, int B, int I, int J)
{
  FA = A;
  FB = B;
  FI = I;
  FJ = J;

  Synchronize(DoVisualSwap);
}
//---------------------------------------------------------------------
/* The Execute method is called when the thread starts */

void __fastcall TSortThread::Execute()
{
  Sort(FSortArray, FSize-1);
}
//---------------------------------------------------------------------
__fastcall TBubbleSort::TBubbleSort(TPaintBox *Box, int *SortArray, 
  const int SortArray_Size)
  : TSortThread(Box, SortArray, SortArray_Size)
{
}
//---------------------------------------------------------------------
void __fastcall TBubbleSort::Sort(int *A, int const AHigh)
{
  int I, J, T;

  for (I=AHigh; I >= 0; I--)
    for (J=0; J<=AHigh-1; J++)
      if (A[J] > A[J + 1])
      {
        VisualSwap(A[J], A[J + 1], J, J + 1);
        T = A[J];
        A[J] = A[J + 1];
        A[J + 1] = T;
        if (Terminated)
          return;
      }
}
//---------------------------------------------------------------------
__fastcall TSelectionSort::TSelectionSort(TPaintBox *Box, int *SortArray, 
  const int SortArray_Size)
  : TSortThread(Box, SortArray, SortArray_Size)
{
}
//---------------------------------------------------------------------
void __fastcall TSelectionSort::Sort(int *A, int const AHigh)
{
  int I, J, T;

  for (I=0; I <= AHigh-1; I++)
    for (J=AHigh; J >= I+1; J--)
      if (A[I] > A[J])
      {
        VisualSwap(A[I], A[J], I, J);
        T = A[I];
        A[I] = A[J];
        A[J] = T;
        if (Terminated) 
          return;
      }
}
//---------------------------------------------------------------------
__fastcall TQuickSort::TQuickSort(TPaintBox *Box, int *SortArray, 
  const int SortArray_Size)
  : TSortThread(Box, SortArray, SortArray_Size)
{
}
//---------------------------------------------------------------------
void __fastcall TQuickSort::QuickSort(int *A, int const AHigh, int iLo, int iHi)
{
  int Lo, Hi, Mid, T;

  Lo = iLo;
  Hi = iHi;
  Mid = A[(Lo+Hi)/2];

  do
  {
    if (Terminated)
      return; 
    while (A[Lo] < Mid)
        Lo++;
    while (A[Hi] > Mid) 
        Hi--;
    if (Lo <= Hi)
    {
      VisualSwap(A[Lo], A[Hi], Lo, Hi);
      T = A[Lo];
      A[Lo] = A[Hi];
      A[Hi] = T;
      Lo++;
      Hi--;
    }
  }
  while (Lo <= Hi);

  if (Hi > iLo) 
    QuickSort(A, AHigh, iLo, Hi);
  if (Lo < iHi) 
    QuickSort(A, AHigh, Lo, iHi);
}
//---------------------------------------------------------------------
void __fastcall TQuickSort::Sort(int *A, int const AHigh)
{
  QuickSort(A, AHigh, 0, AHigh);
}
//---------------------------------------------------------------------
   
