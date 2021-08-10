//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "wpmmain.h"
#include <ctype.h>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::StartTimer(TObject *Sender, Word &Key,
      TShiftState Shift)
{
	if (RichEdit1->ReadOnly == false)
    {
		Timer1->Enabled = True;
	    Label1->Caption = "Test Started";
	    Label1->Font->Color = clGreen;
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::IncrementBar(TObject *Sender)
{
	if (ProgressBar1->Position == 59)
    {
	    Timer1->Enabled = False;
    	Label1->Caption = "Test Complete";
	    Label1->Font->Color = clRed;
        RichEdit1->ReadOnly = True;
        Label2->Caption = IntToStr(CalculateWPM()) + " Words Per Minute";
    }
    ProgressBar1->StepIt();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Button2Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Button1Click(TObject *Sender)
{
    	Timer1->Enabled = False;
        Label1->Caption = "Start typing to begin test";
	    Label1->Font->Color = clBlack;
        Label2->Caption = "";
        RichEdit1->SetTextBuf("");
        RichEdit1->ReadOnly = False;
        ProgressBar1->Position = 0;
}
//---------------------------------------------------------------------
int __fastcall TFormMain::CalculateWPM(void)
{
    int character=0;            // for iterating through text by character
    int count=0;                // for keeping track of the number of words
    bool betweenwords=true;     // for state information while scanning

    while ((RichEdit1->Lines->Text.c_str()[character++] != NULL))
    {
        if (isalnum(RichEdit1->Lines->Text.c_str()[character]))
    	{
    		if (betweenwords)
	        {
    	    	betweenwords = false;
        	    count++;
	        }
    	} else {
    		betweenwords = true;
	    }
    }
	return count;
}
//---------------------------------------------------------------------