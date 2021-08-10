//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef swatH
#define swatH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------

struct THole {
  int  Time;
  bool Dead;
};

class TSwatForm : public TForm
{
__published:
    TImage *Image1;
    TMainMenu *MainMenu1;
    TMenuItem *Gamr1;
    TMenuItem *New1;
    TMenuItem *Options1;
    TMenuItem *Stop1;
    TMenuItem *Pause1;
    TMenuItem *About1;
    TTimer *Timer1;
    TImage *GameOverImage;
    TLabel *TimeLabel;
    TLabel *MissLabel;
    TLabel *HitsLabel;
    TLabel *EscapedLabel;
    TLabel *ScoreLabel;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall TimerTick(TObject *Sender);
    void __fastcall DisplayAbout(TObject *Sender);
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Stop1Click(TObject *Sender);
    void __fastcall Pause1Click(TObject *Sender);
    
    void __fastcall Options1Click(TObject *Sender);
    
    void __fastcall WriteScore(void);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
    TShiftState Shift, int X, int Y);
    void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
    TShiftState Shift, int X, int Y);
private:        // private user declarations
    int         Score, LiveTime, Frequence, GameTime;
    int         Hits, Miss, Escaped;
    bool        IsGameOver, IsPause;
    Graphics::TBitmap*    Live;
    Graphics::TBitmap*    Dead;
    THole       HoleInfo[5];
public:         // public user declarations
    virtual __fastcall TSwatForm(TComponent* Owner);
friend class TOptionsDlg;
};
//---------------------------------------------------------------------------
extern TSwatForm *SwatForm;
//---------------------------------------------------------------------------
const int crMaletUp    = 5;
const int crMaletDown  = 6;

const int MissedPoints  = -2;
const int HitPoints     = 5;
const int MissedCritter = -1;
const int CritterSize   = 72;
const int TimerId       = 1;
#endif
