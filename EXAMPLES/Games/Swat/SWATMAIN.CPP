//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include "swatmain.h"
#include "about.h"
#include "options.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
#pragma resource "extrares.RES"
TSwatForm *SwatForm;

TPoint Holes[5] = {TPoint(10, 10) ,TPoint(200, 10) ,TPoint(100, 100),
                   TPoint(10, 200) ,TPoint(200, 200)};

//---------------------------------------------------------------------------
__fastcall TSwatForm::TSwatForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSwatForm::DisplayAbout(TObject *Sender)
{
    AboutBox->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TSwatForm::FormCreate(TObject *Sender)
{
    Screen->Cursors[crMaletUp] = LoadCursor(HInstance, "Malet");
    Screen->Cursors[crMaletDown] = LoadCursor(HInstance, "MaletDown");
    Screen->Cursor = TCursor(crMaletUp);

    randomize();

    Live = new Graphics::TBitmap;
    Live->LoadFromResourceName((int)HInstance, "Live");
    Dead = new Graphics::TBitmap;
    Dead->LoadFromResourceName((int)HInstance, "Dead");

    IsGameOver = true;
    IsPause = false;
    LiveTime = 10;
    Frequence = 20;
    GameTime = 150;        // fifteen seconds

    Application->OnMinimize = Pause1Click;
    Application->OnRestore = Pause1Click;
}
//---------------------------------------------------------------------
void __fastcall TSwatForm::TimerTick(TObject *Sender)
{
    Timer1->Tag++;
    int i = random(Frequence);
    if (i < 5)
    {
        if (HoleInfo[i].Time == 0)
        {
            HoleInfo[i].Time = Timer1->Tag + LiveTime;
            HoleInfo[i].Dead = false;
            Canvas->Draw(Holes[i].x, Holes[i].y, Live);
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (Timer1->Tag > HoleInfo[i].Time && HoleInfo[i].Time != 0)
        {
            HoleInfo[i].Time = 0;
            if (!HoleInfo[i].Dead)
            {
                Score += MissedCritter;
                Escaped++;
            }
            Canvas->FillRect(Rect(Holes[i].x, Holes[i].y,
                            Holes[i].x + Dead->Width, Holes[i].y + Dead->Height));
        }
    }
    WriteScore();
    if (Timer1->Tag >= GameTime)
        Stop1Click(this);
}
//---------------------------------------------------------------------------
void __fastcall TSwatForm::WriteScore(void)
{
    TimeLabel->Caption = IntToStr(GameTime - Timer1->Tag);
    HitsLabel->Caption = IntToStr(Hits);
    MissLabel->Caption = IntToStr(Miss);
    EscapedLabel->Caption = IntToStr(Escaped);
    ScoreLabel->Caption = IntToStr(Score);
}
void __fastcall TSwatForm::New1Click(TObject *Sender)
{
    Timer1->Enabled = true;
    Timer1->Tag = 0;
    Score = 0;
    Hits = 0;
    Miss = 0;
    Escaped = 0;
    if (IsPause)
    {
        IsPause = false;
        Pause1->Caption = "&Pause";
    }
    GameOverImage->Visible = false;
    IsGameOver = false;
    memset(HoleInfo, 0, sizeof(HoleInfo));
    New1->Enabled = false;
    Options1->Enabled = false;
    Stop1->Enabled = true;
}
//---------------------------------------------------------------------
void __fastcall TSwatForm::Stop1Click(TObject *Sender)
{
    Timer1->Enabled = false;
    IsPause = false;
    GameOverImage->Visible = true;
    IsGameOver = true;
    Timer1->Tag = GameTime;
    New1->Enabled = true;
    Options1->Enabled = true;
    Stop1->Enabled = false;
    for (int i = 0; i < 5; i++)
    {
        if (HoleInfo[i].Time != 0)
        {
            Canvas->FillRect(Rect(Holes[i].x, Holes[i].y,
                          Holes[i].x + Dead->Width, Holes[i].y + Dead->Height));
        }
    }
}
//---------------------------------------------------------------------
void __fastcall TSwatForm::Pause1Click(TObject *Sender)
{
    if (IsGameOver)
        return;

    if (IsPause)
    {
        IsPause = false;
        Pause1->Caption = "&Pause";
        Stop1->Enabled = true;
        Timer1->Enabled = true;
    }
    else
    {
        IsPause = true;
        Pause1->Caption = "&Continue";
        Stop1->Enabled = false;
        Timer1->Enabled = false;
    }
}
//---------------------------------------------------------------------
void __fastcall TSwatForm::Options1Click(TObject *Sender)
{
    OptionsDlg->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TSwatForm::FormDestroy(TObject *Sender)
{
    delete Live;
    delete Dead;
}
//---------------------------------------------------------------------
void __fastcall TSwatForm::FormMouseDown(TObject *Sender, TMouseButton Button,
    TShiftState Shift, int X, int Y)
{
    Screen->Cursor = TCursor(crMaletDown);

    if (IsGameOver || IsPause)
        return;

    bool hit = false;
    for (int i = 0; i < 5; i++)
    {
        if (!HoleInfo[i].Dead && HoleInfo[i].Time != 0)
        {
            if (X > Holes[i].x && X < (Holes[i].x + Live->Width) &&
                Y > Holes[i].y && Y < (Holes[i].y + Live->Height))
            {
                Score += HitPoints;
                HoleInfo[i].Dead = true;
                HoleInfo[i].Time = Timer1->Tag + 2 * LiveTime;
                Hits++;
                hit = true;
                Canvas->Draw(Holes[i].x, Holes[i].y, Dead);
            }
        }
    }
    if (!hit)
    {
        Score += MissedPoints;
        Miss++;
    }
    WriteScore();    
}
//---------------------------------------------------------------------------
void __fastcall TSwatForm::FormMouseUp(TObject *Sender, TMouseButton Button,
    TShiftState Shift, int X, int Y)
{
    Screen->Cursor = TCursor(crMaletUp);    
}
//---------------------------------------------------------------------------
