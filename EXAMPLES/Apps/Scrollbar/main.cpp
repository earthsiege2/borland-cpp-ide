//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ScrollBar1Scroll(TObject *Sender,
    TScrollCode ScrollCode, int &ScrollPos)
{
    char buf[5];
    PosEdit->Text = itoa(ScrollBar1->Position, buf, 10);

    switch (ScrollCode)
    {
        case scLineUp:
            Label2->Caption = "User clicked the top or left scroll arrow or presses the Up arrow key.";
            break;
        case scLineDown:
            Label2->Caption = "User clicked the bottom or right scroll arrow or pressed the Down arrow key.";
            break;
        case scPageUp:
            Label2->Caption = "User clicked the area to the left of the thumb tab or pressed the PgUp key.";
            break;
        case scPageDown:
            Label2->Caption = "User clicked the area to the right of the thumb tab or pressed the PgDn key.";
            break;
        case scPosition:
            Label2->Caption = "User positioned the thumb tab and released it.";
            break;
        case scTrack:
            Label2->Caption = "User is moving the thumb tab.";
            break;
        case scTop:
            Label2->Caption = "User moved the thumb tab to the top or far left on the scroll bar.";
            break;
        case scBottom:
            Label2->Caption = "User moved the thumb tab to the bottom or far right on the scroll bar.";
            break;
        case scEndScroll:
            Label2->Caption = "User is done moving the thumb tab on the scroll bar.";
            break;
        default:
            break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button1Click(TObject *Sender)
{
    char buf[5];

    if (atoi(PosEdit->Text.c_str()))
        ScrollBar1->Position = atoi(PosEdit->Text.c_str());
    else
        PosEdit->Text = itoa(ScrollBar1->Position, buf, 10);

    if (atoi(MinEdit->Text.c_str()))
        ScrollBar1->Min = atoi(MinEdit->Text.c_str());
    else
        MinEdit->Text = itoa(ScrollBar1->Min, buf, 10);

    if (atoi(MaxEdit->Text.c_str()))
        ScrollBar1->Max = atoi(MaxEdit->Text.c_str());
    else
        MaxEdit->Text = itoa(ScrollBar1->Max, buf, 10);

    if (atoi(LargeEdit->Text.c_str()))
        ScrollBar1->LargeChange = (short) atoi(LargeEdit->Text.c_str());
    else
        LargeEdit->Text = itoa(ScrollBar1->LargeChange, buf, 10);

    if (atoi(SmallEdit->Text.c_str()))
        ScrollBar1->SmallChange = (short) atoi(SmallEdit->Text.c_str());
    else
        SmallEdit->Text = itoa(ScrollBar1->SmallChange, buf, 10);
        
    Button1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
    char buf[5];
    PosEdit->Text = itoa(ScrollBar1->Position, buf, 10);
    MinEdit->Text = itoa(ScrollBar1->Min, buf, 10);
    MaxEdit->Text = itoa(ScrollBar1->Max, buf, 10);
    LargeEdit->Text = itoa(ScrollBar1->LargeChange, buf, 10);
    SmallEdit->Text = itoa(ScrollBar1->SmallChange, buf, 10);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::EnableButton(TObject *Sender, char &Key)
{
    Button1->Enabled = true;
}
//---------------------------------------------------------------------------
