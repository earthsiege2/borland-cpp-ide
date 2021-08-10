//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef SortThdH
#define SortThdH
//----------------------------------------------------------------------------
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <System.hpp>
//----------------------------------------------------------------------------
extern void __fastcall PaintLine(TCanvas *Canvas, int i, int len);
//----------------------------------------------------------------------------
class TSortThread : public TThread
{
private: 
	TPaintBox *FBox;
	int *FSortArray;
	int FSize;
	int FA;
	int FB;
	int FI;
	int FJ;
	void __fastcall DoVisualSwap(void);
	
protected:
	virtual void __fastcall Execute(void);
	void __fastcall VisualSwap(int A, int B, int I, int J);
	virtual void __fastcall Sort(int *A, const int A_Size) = 0;
	
public:
	__fastcall TSortThread(TPaintBox *Box, int *SortArray, 
	    const int SortArray_Size);
};
//----------------------------------------------------------------------------
class TBubbleSort : public TSortThread
{
protected:
	virtual void __fastcall Sort(int *A, const int A_Size);
public:
	__fastcall TBubbleSort(TPaintBox *Box, int *SortArray, 
	    const int SortArray_Size);
};
//----------------------------------------------------------------------------
class TSelectionSort : public TSortThread
{
protected:
	virtual void __fastcall Sort(int *A, const int A_Size);
public:
	__fastcall TSelectionSort(TPaintBox *Box, int *SortArray, 
	    const int SortArray_Size);
};
//----------------------------------------------------------------------------
class TQuickSort : public TSortThread
{
protected:
	void __fastcall QuickSort(int *A, const int A_Size, int iLo, 
	  int iHi);
	virtual void __fastcall Sort(int *A, const int A_Size);
public:
	__fastcall TQuickSort(TPaintBox *Box, int *SortArray, 
	    const int SortArray_Size);
};
//----------------------------------------------------------------------------
#endif	
