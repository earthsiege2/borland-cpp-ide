//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "mainform.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Find1Click(TObject *Sender)
{
    FindDialog1->FindText = RichEdit1->SelText;
    FindDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Replace1Click(TObject *Sender)
{
    ReplaceDialog1->FindText = RichEdit1->SelText;
    ReplaceDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Find(TObject *Sender)
{
    TSearchTypes st;
    TFindDialog *cd;
    int newpos;

    if ((cd = dynamic_cast<TFindDialog *> (Sender)) == 0)
        MessageBox(NULL, "Dynamic Cast Failed!", "Find/Rep", MB_OK);

    if (cd->Options.Contains(frMatchCase))
        st << stMatchCase;
    if (cd->Options.Contains(frWholeWord))
        st << stWholeWord;

    if (RichEdit1->SelLength)
        RichEdit1->SelStart += 1;

    newpos = RichEdit1->FindText(cd->FindText,
                        RichEdit1->SelStart,
                        RichEdit1->Text.Length(),
                        st);

    if (newpos != -1)
    {
        RichEdit1->SelStart = newpos;
        RichEdit1->SelLength = cd->FindText.Length();
    }
    else
    {
        MessageBox(NULL, "End of document reached.", "Find/Rep", MB_OK);
        RichEdit1->SelStart = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Replace(TObject *Sender)
{
    if (RichEdit1->SelLength == 0)
        Find(Sender);
    else
    {
        RichEdit1->SelText =  ReplaceDialog1->ReplaceText;
        Find(Sender);
    }

    if (ReplaceDialog1->Options.Contains(frReplaceAll))
        while (RichEdit1->SelLength !=0)
            Replace(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
    RichEdit1->SelStart = 0;
}
//---------------------------------------------------------------------------
