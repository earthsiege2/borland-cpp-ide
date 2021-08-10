//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include "options.h"
#include "swatmain.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TOptionsDlg *OptionsDlg;
//--------------------------------------------------------------------- 
__fastcall TOptionsDlg::TOptionsDlg(TComponent* AOwner)
  : TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TOptionsDlg::FormShow(TObject *Sender)
{
    char timebuf[6];

    SpeedSet->Position = SpeedSet->Max + 1 - SwatForm->LiveTime;
    PopulationSet->Position = SwatForm->Frequence;
    GameTimeSet->Text = itoa(SwatForm->GameTime, timebuf, 10);
}
//---------------------------------------------------------------------
void __fastcall TOptionsDlg::OKBtnClick(TObject *Sender)
{
    SwatForm->LiveTime = SpeedSet->Max + 1 - SpeedSet->Position;
    SwatForm->Frequence = PopulationSet->Position;
    SwatForm->GameTime = atoi(GameTimeSet->Text.c_str());

    // limit the value of GameTime to a reasonable length
    if (SwatForm->GameTime < 1)
        SwatForm->GameTime = 150;
    if (SwatForm->GameTime > 9999)
        SwatForm->GameTime = 9999;
}
//---------------------------------------------------------------------
