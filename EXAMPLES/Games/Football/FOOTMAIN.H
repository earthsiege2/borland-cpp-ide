//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef footmainH
#define footmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
const int RBTOP = 58;
const int RBMIDDLE = 74;
const int RBBOTTOM = 90;
const int RBLEFT = 36;
const int TACKLETOP = 59;
const int TACKLEMIDDLE = 75;
const int TACKLEBOTTOM = 91;
const int TACKLEROW1 = 104;
const int TACKLEROW2 = 148;
const int TACKLEROW3 = 236;

struct spot
{
    TLabel* player;
    bool    rb;
};

//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:    // IDE-managed Components 
    TImage *Image7;
    TLabel *HomeDisplay;
    TLabel *TimeDisplay;
    TLabel *VisitorDisplay;
    TLabel *Runningback;
    TLabel *Tackler1;
    TLabel *Tackler2;
    TLabel *Tackler3;
    TLabel *Tackler4;
    TLabel *Tackler5;
    TTimer *Timer;
    TMainMenu *MainMenu1;
    TMenuItem *Help1;
    TMenuItem *About1;
    TMenuItem *File1;
    TMenuItem *Exit1;
    TLabel *HomeLabel;
    TLabel *TimeLabel;
    TLabel *VisitorLabel;
    TTimer *Clock;
    TImage *Forward;
    TImage *Image2;
    TImage *Image3;
    TImage *KickButton;
    TImage *Score;
    TLabel *Label2;
    TLabel *Label1;
    TTrackBar *OnOffSwitch;
    TLabel *Label3;
    TLabel *DownDisplay;
    TLabel *FieldPosDisplay;
    TLabel *YTGDisplay;
    TLabel *DownLabel;
    TLabel *FieldPosLabel;
    TLabel *YTGLabel;
    TButton *Computer;
   TImage *Back;
    void __fastcall MoveForward(TObject *Sender);
    void __fastcall MoveUp(TObject *Sender);
    void __fastcall MoveDown(TObject *Sender);
    void __fastcall Switched(TObject *Sender);
    void __fastcall TimerTimer(TObject *Sender);
    void __fastcall ResetGame(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);
    
    
    void __fastcall ShowStats(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y);
    
    void __fastcall HideStats(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y);

    void __fastcall Kick(TObject *Sender);
    void __fastcall ClockTick(TObject *Sender);
    
    void __fastcall ComputerClick(TObject *Sender);
   void __fastcall FormKeyPress(TObject *Sender, char &Key);
   void __fastcall MoveBack(TObject *Sender);
private:        // User declarations
    spot field[10][3];  // the X and Y coordinates of the field
    int  rbx, rby;      // the X and Y coordinates of the runningback
    bool running;
    TLabel *LastSack;
    int YardsToGo;
    int Down;
    int FieldPosition;
    int Home;
    int Visitor;
    int Quarter;
    float TimeLeft;
    void __fastcall ShowField(bool visible);
    void __fastcall ResetField(void);
    void __fastcall Sacked(TLabel*);
    void __fastcall ShowDisplay(bool visible);
    void __fastcall TogglePlay(bool toggle);
public:         // User declarations
    virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
