//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef ThSortH
#define ThSortH
//----------------------------------------------------------------------------
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <System.hpp>
//----------------------------------------------------------------------------
class TThreadSortForm : public TForm
{
__published:
	TButton *StartBtn;
	TPaintBox *BubbleSortBox;
	TPaintBox *SelectionSortBox;
	TPaintBox *QuickSortBox;
	TLabel *Label1;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TLabel *Label2;
	TLabel *Label3;
	void __fastcall BubbleSortBoxPaint(TObject *Sender);
	void __fastcall SelectionSortBoxPaint(TObject *Sender);
	void __fastcall QuickSortBoxPaint(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StartBtnClick(TObject *Sender);
	
private: 
	int ThreadsRunning;
	void __fastcall RandomizeArrays(void);
	void __fastcall ThreadDone(TObject *Sender);
	
public:
	void __fastcall PaintArray(TPaintBox *Box, const int *A, const int A_Size);
    virtual __fastcall TThreadSortForm(TComponent *Owner);
};
//----------------------------------------------------------------------------
typedef int TSortArray[115];

typedef TSortArray *PSortArray;
//----------------------------------------------------------------------------
extern TThreadSortForm *ThreadSortForm;
extern bool ArraysRandom;
extern int BubbleSortArray[115];
extern int SelectionSortArray[115];
extern int QuickSortArray[115];
//----------------------------------------------------------------------------
#endif	
