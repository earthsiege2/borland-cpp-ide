//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
                                              
#include <stdlib.h>
#include <mmsystem.hpp>
#include "footmain.h"
#include "instr.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
char numbuf[10];
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MoveForward(TObject *Sender)
{
    if ((OnOffSwitch->Position == 2) || (LastSack != NULL))
        return;

    if (!running)
        TogglePlay(true);

    if (Runningback->Left < TACKLEROW3 - 2)
    {
        if (field[rbx+1][rby].player != NULL)
        {
            Sacked(field[rbx+1][rby].player);
            return;
        }
        field[rbx][rby].player = NULL;
        field[rbx][rby].rb = false;
        Runningback->Left += 22;
        rbx++;
    }
    else
    {
        if (field[0][rby].player != NULL)
        {
            Sacked(field[0][rby].player);
            return;
        }
        field[rbx][rby].player = NULL;
        field[rbx][rby].rb = false;
        Runningback->Left = RBLEFT;
        rbx = 0;
    }

    YardsToGo--;
    FieldPosition++;
    if (FieldPosition == 100)
    {
        sndPlaySound("td.wav", SND_SYNC);
        running = false;
        ShowField(false);
        Home+=7;
        HomeDisplay->Caption = itoa(Home, numbuf, 10);
        FieldPosition=80;  // Starting position for visitor
        Down = 1;
        YardsToGo = 10;
        Computer->Visible = true;
        return;
    }
    field[rbx][rby].player = Runningback;
    field[rbx][rby].rb = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MoveBack(TObject *Sender)
{
    if ((OnOffSwitch->Position == 2) || (LastSack != NULL))
        return;

    if (!running)
        TogglePlay(true);
    if(FieldPosition > 0)
    {
      if (Runningback->Left > RBLEFT + 2)
      {
          if (field[rbx-1][rby].player != NULL)
          {
              Sacked(field[rbx-1][rby].player);
              return;
          }
          field[rbx][rby].player = NULL;
          field[rbx][rby].rb = false;
          Runningback->Left -= 22;
          rbx--;
      }
      else
      {
          if (field[9][rby].player != NULL)
          {
              Sacked(field[9][rby].player);
              return;
          }
          field[rbx][rby].player = NULL;
          field[rbx][rby].rb = false;
          Runningback->Left = TACKLEROW3;
          rbx = 9;
      }

      YardsToGo++;
      FieldPosition--;

      field[rbx][rby].player = Runningback;
      field[rbx][rby].rb = true;
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::MoveUp(TObject *Sender)
{
    if ((OnOffSwitch->Position == 2) || (LastSack != NULL))
        return;

    if (!running)
        TogglePlay(true);

    if (Runningback->Top == RBTOP)
        return; // already as up as it gets

    if (field[rbx][rby-1].player != NULL)
    {
        Sacked(field[rbx][rby-1].player);
        return;
    }

    if (Runningback->Top == RBBOTTOM)
        Runningback->Top = RBMIDDLE;
    else if (Runningback->Top == RBMIDDLE)
        Runningback->Top = RBTOP;

    field[rbx][rby].player = NULL;
    field[rbx][rby].rb = false;
    rby--;
    field[rbx][rby].player = Runningback;
    field[rbx][rby].rb = true;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::MoveDown(TObject *Sender)
{
    if ((OnOffSwitch->Position == 2) || (LastSack != NULL))
        return;

    if (!running)
        TogglePlay(true);

    if (Runningback->Top == RBBOTTOM)
        return; // already as down as it gets

    if (field[rbx][rby+1].player != NULL)
    {
        Sacked(field[rbx][rby+1].player);
        return;
    }

    if (Runningback->Top == RBTOP)
        Runningback->Top = RBMIDDLE;
    else if (Runningback->Top == RBMIDDLE)
        Runningback->Top = RBBOTTOM;

    field[rbx][rby].player = NULL;
    field[rbx][rby].rb = false;
    rby++;
    field[rbx][rby].player = Runningback;
    field[rbx][rby].rb = true;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Switched(TObject *Sender)
{
    switch (OnOffSwitch->Position)
    {
            case 1:    {
                    Timer->Interval = 250;
                    HomeDisplay->Visible = true;
                    VisitorDisplay->Visible = true;
                    TimeDisplay->Visible = true;
                    ResetGame(NULL);
                    break;
                }
                case 2:    {
                    ShowField(false);
                    HomeDisplay->Visible = false;
                    VisitorDisplay->Visible = false;
                    TimeDisplay->Visible = false;
                    break;
                }
                case 3:    {
                    Timer->Interval = 100;
                    HomeDisplay->Visible = true;
                    VisitorDisplay->Visible = true;
                    TimeDisplay->Visible = true;
                    ResetGame(NULL);
                    break;
                }
        }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::ShowField(bool visible)
{
    Runningback->Visible = visible;
    Tackler1->Visible = visible;
    Tackler2->Visible = visible;
    Tackler3->Visible = visible;
    Tackler4->Visible = visible;
    Tackler5->Visible = visible;

}
//---------------------------------------------------------------------
void __fastcall TFormMain::TimerTimer(TObject *Sender)
{
    int x, y, newx, newy, direction;

    newy = y = random(3);
    newx = x = random(10);
    direction = random(2); // 0 is for x, 1 is for y

    if (!running)
    {
        if (LastSack != NULL)
            LastSack->Visible = !LastSack->Visible;
        return;
    }

    if (field[x][y].rb == true)
        return; // can't move the runningback!

    if (field[x][y].player == NULL)
        return; // no tacker at this spot

    if (field[x][y].player->Left <= RBLEFT)
        return; // already at the endzone

    if (direction == 0)  // we're moving horizontal
    {
        if (x < rbx)
            newx = x +1;
        else if (x > rbx)
            newx = x -1;
        else return;
        //  we're already horizontally lined up with rb
    }
    else if (direction == 1)  // we're moving vertical
    {
        if (y < rby)
            newy = y +1;
        else if (y > rby)
            newy = y -1;
        else return;
        //  we're already vertically lined up with rb
    }

    if (field[newx][newy].rb == true) // got him!
    {
        Sacked(field[x][y].player);
        return;
    }

    if (field[newx][newy].player == NULL) // not blocked
    {
        field[x][y].player->Left -= (22 * (x - newx));
        field[x][y].player->Top -= (16 * (y - newy));
        field[newx][newy].player = field[x][y].player;
        field[x][y].player = NULL;
        return;
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Sacked(TLabel *player)
{
    sndPlaySound("whistle.wav", SND_SYNC);
    running = false;
    LastSack = player;
    if (YardsToGo <=0)
    {
        Down = 1;
        YardsToGo = 10;
    }
    else
    {
        Down++;
        if (Down > 4)
        {
            sndPlaySound("whistle.wav", SND_SYNC);
            Down = 1;  // First down for visitor
            YardsToGo = 10;
            Computer->Visible = true;
        }
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::ResetGame(TObject *Sender)
{
    YardsToGo=10;
    Down=1;
    FieldPosition=20;
    Home=0;
    Visitor=0;
    Quarter = 1;
    TimeLeft=15;
    TimeDisplay->Caption = FloatToStrF(TimeLeft, ffGeneral, 4, 4);
    HomeDisplay->Caption = itoa(Home, numbuf, 10);
    VisitorDisplay->Caption = itoa(Visitor, numbuf, 10);
    randomize;
    ResetField();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::ResetField()
{
    TogglePlay(false);
    LastSack = NULL;

    // empty the field
    for (int y=0; y<3; y++)
        for (int x=0; x<10; x++)
        {
            field[x][y].player = NULL;
            field[x][y].rb = false;
        }

    // initial locations of players
    field[0][1].player=Runningback;
    field[0][1].rb=true;
    rbx = 0;
    rby = 1;
    field[3][0].player=Tackler1;
    field[3][1].player=Tackler2;
    field[3][2].player=Tackler3;
    field[5][1].player=Tackler4;
    field[9][1].player=Tackler5;

    Runningback->Left = RBLEFT;
    Runningback->Top = RBMIDDLE;
    Tackler1->Left = TACKLEROW1;
    Tackler1->Top = TACKLETOP;
    Tackler2->Left = TACKLEROW1;
    Tackler2->Top = TACKLEMIDDLE;
    Tackler3->Left = TACKLEROW1;
    Tackler3->Top = TACKLEBOTTOM;
    Tackler4->Left = TACKLEROW2;
    Tackler4->Top = TACKLEMIDDLE;
    Tackler5->Left = TACKLEROW3;
    Tackler5->Top = TACKLEMIDDLE;

    ShowField(true);
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Exit1Click(TObject *Sender)
{
    Application->Terminate();  
}
//---------------------------------------------------------------------
void __fastcall TFormMain::About1Click(TObject *Sender)
{
    About->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::ShowStats(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    if ((OnOffSwitch->Position == 2) || (running))
        return;

    if (Quarter == 5)
        return;

    YTGDisplay->Caption = itoa(YardsToGo, numbuf, 10);

    if (FieldPosition <= 50)
    {
        itoa(FieldPosition, numbuf, 10);
        strcat(numbuf, " <");
    }
    else
    {
        strcpy(numbuf, "> ");
        itoa(100 - FieldPosition, numbuf + 2, 10);
    }
    FieldPosDisplay->Caption = numbuf;

    DownDisplay->Caption = itoa(Down, numbuf, 10);

    ShowField(false);
    ShowDisplay(true);
}
//---------------------------------------------------------------------
void __fastcall TFormMain::HideStats(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    if ((OnOffSwitch->Position == 2) || (running))
        return;

    ShowDisplay(false);
    if (!Computer->Visible)
        ResetField();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::ShowDisplay(bool visible)
{
    DownLabel->Visible = visible;
    FieldPosLabel->Visible = visible;
    YTGLabel->Visible = visible;
    DownDisplay->Visible = visible;
    FieldPosDisplay->Visible = visible;
    YTGDisplay->Visible = visible;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Kick(TObject *Sender)
{
    if ((running) || (Down != 4))
        return;  // button only valid just before fourth down

    ShowField(false);
    FieldPosition += random(100);
    if (FieldPosition >= 100)
    {
        sndPlaySound("td.wav", SND_SYNC);
        Home+=3;
        HomeDisplay->Caption = itoa(Home, numbuf, 10);
        FieldPosition=80;  // Starting position for visitor
      }
    else
    {
        sndPlaySound("whistle.wav", SND_SYNC);
        sndPlaySound("whistle.wav", SND_SYNC);
    }
    Down = 1;  // first down for visitor
    YardsToGo = 10;
    Computer->Visible = true;
    LastSack = Runningback; // hack to keep movement keys disabled
}
//---------------------------------------------------------------------
void __fastcall TFormMain::ClockTick(TObject *Sender)
{
    if (!running)
        return;

    sndPlaySound("tick.wav", SND_ASYNC);
    TimeLeft -= 0.1;
    TimeDisplay->Caption = FloatToStrF(TimeLeft, ffGeneral, 4, 4);

    if (TimeLeft <= 0)
    {
        Quarter++;
        TimeLeft = 15;
    }
    if (Quarter >= 5)
    {
        // game over
        sndPlaySound("whistle.wav", SND_SYNC);
        sndPlaySound("whistle.wav", SND_SYNC);
        LastSack = Runningback; // hack to keep movement keys disabled
        TogglePlay(false);
        ShowField(false);
        ShowDisplay(true);
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::TogglePlay(bool toggle)
{
        running = toggle;
        Timer->Enabled = toggle;
        Clock->Enabled = toggle;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::ComputerClick(TObject *Sender)
{

    ShowField(false);
    FieldPosition -= random(100);
    if (FieldPosition <= 0)
    {
        sndPlaySound("td.wav", SND_ASYNC);
        Visitor+=7;
        VisitorDisplay->Caption = itoa(Visitor, numbuf, 10);
        FieldPosition=20;
    }
    else
    {
        sndPlaySound("whistle.wav", SND_SYNC);
        sndPlaySound("whistle.wav", SND_SYNC);
    }
    Computer->Visible = false;
    LastSack = Runningback; // hack to keep movement keys disabled
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FormKeyPress(TObject *Sender, char &Key)
{
  switch(Key)
  {
    case 'i':
      MoveUp(Sender);
      break;
    case 'k':
      MoveDown(Sender);
      break;
    case 'l':
      MoveForward(Sender);
      break;
    case 'j':
      MoveBack(Sender);
      break;
  }
}
//---------------------------------------------------------------------------
