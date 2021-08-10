//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Example interactive debugging game
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dialog.h>
#include <owl\menu.h>
#include <owl\dc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "swat.h"

const int MissedPoints  = -2;
const int HitPoints     = 5;
const int MissedCritter = -1;
const int CritterSize   = 72;
const int MaxPop        = 35;
const int MaxLiveTime   = 30;
const int TimerId       = 1;

POINT Holes[5] = {
  { 10, 10 }, { 200, 10 }, { 100, 100 }, { 10, 200 }, { 200, 200 }
};

struct THole {
  int  Time;
  BOOL Dead;
};

class TGameWindow : public TWindow {
  public:
    TGameWindow();

    void         CreateTimer();
    void         DrawGameOver(TDC& DC);
    void         DrawCritter(TDC& DC, int CritterNumber);
    void         DrawScoreBoard(TDC& DC);
    void         WriteScore(TDC& dc);

  protected:
    void SetupWindow();
    void Paint(TDC&, BOOL, TRect&);

    // message response functions
    //
    void CmAbout();        // IDM_ABOUT
    void CmOptions();      // IDM_OPTION
    void CmPause();        // IDM_PAUSE
    void CmResetGame();    // IDM_RESET
    void CmStopGame();     // IDM_STOP
    void CeResetGame(TCommandEnabler&);
    void CeOptions(TCommandEnabler&); 
    void CeStopGame(TCommandEnabler&);
    BOOL EvEraseBkgnd(HDC hDC);
    void EvDestroy();
    void EvLButtonDown(UINT, TPoint&);
    void EvLButtonUp(UINT, TPoint&);
    void EvTimer(UINT timerID);
    void EvSize(UINT, TSize&);

  private:
    TBitmap*    Live;
    TBitmap*    Dead;
    TBitmap*    GameOver;
    TBitmap*    ScoreBoard;
    TCursor*    CursorDown;
    TCursor*    CursorUp;
    int         Counter, Score, LiveTime, Frequence, GameTime;
    int         Hits, Miss, Escaped;
    BOOL        IsGameOver, IsPause;
    THole       HoleInfo[5];

  friend class TOptionDialog;
  DECLARE_RESPONSE_TABLE(TGameWindow);
};

DEFINE_RESPONSE_TABLE1(TGameWindow, TWindow)
  EV_COMMAND(IDM_ABOUT, CmAbout),
  EV_COMMAND(IDM_PAUSE, CmPause),
  EV_COMMAND(IDM_OPTION, CmOptions),
  EV_COMMAND_ENABLE(IDM_OPTION, CeOptions),
  EV_COMMAND(IDM_RESET, CmResetGame),
  EV_COMMAND_ENABLE(IDM_RESET, CeResetGame),
  EV_COMMAND(IDM_STOP, CmStopGame),
  EV_COMMAND_ENABLE(IDM_STOP, CeStopGame),
  EV_WM_ERASEBKGND,
  EV_WM_DESTROY,
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONUP,
  EV_WM_TIMER,
  EV_WM_SIZE,
  EV_WM_PAINT,
END_RESPONSE_TABLE;

class TOptionDialog : public TDialog {
  public:
    TOptionDialog(TWindow* parent, char far* name)
        : TWindow(parent), TDialog(parent, name) {}

    BOOL  CanClose();
    void  SetupWindow();

    void  EvHScroll(UINT, UINT, HWND);

  DECLARE_RESPONSE_TABLE(TOptionDialog);
};
DEFINE_RESPONSE_TABLE1(TOptionDialog, TDialog)
  EV_WM_HSCROLL,
END_RESPONSE_TABLE;

//--------------- TOptionDialog ---------------

void
TOptionDialog::SetupWindow()
{
  TDialog::SetupWindow();
  TGameWindow* gameParent = (TGameWindow*)Parent; //can cast, no virtual bases
  
  ::SetScrollRange(GetDlgItem(IDD_LIVETIMESB), SB_CTL, 1, MaxLiveTime, FALSE);
  ::SetScrollRange(GetDlgItem(IDD_POPSB), SB_CTL, 1, MaxPop, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_LIVETIMESB), SB_CTL, MaxLiveTime + 1 - gameParent->LiveTime, TRUE);
  ::SetScrollPos(GetDlgItem(IDD_POPSB), SB_CTL, MaxPop+6-gameParent->Frequence, TRUE);
  char str[10];
  itoa(gameParent->GameTime / 10, str, 10);
  SetDlgItemText(IDD_INPUTEDITBOX, str);
}

void
TOptionDialog::EvHScroll(UINT scrollCode, UINT thumbPos, HWND WndCtrl)
{
  UINT Pos = ::GetScrollPos(WndCtrl, SB_CTL);
  const int PageStep = 10;

  switch (scrollCode) {
  case SB_LINEUP:
    Pos--;
    break;
  case SB_LINEDOWN:
    Pos++;
    break;
  case SB_PAGEUP:
    Pos -= PageStep;
    break;
  case SB_PAGEDOWN:
    Pos += PageStep;
    break;
  case SB_THUMBPOSITION:
  case SB_THUMBTRACK:
    Pos = thumbPos;
    break;
  }
  ::SetScrollPos(WndCtrl, SB_CTL, Pos, TRUE);
}

BOOL
TOptionDialog::CanClose()
{
  TGameWindow* gameParent = (TGameWindow*)Parent; //can cast, no virtual bases

  gameParent->LiveTime = MaxLiveTime + 1 - ::GetScrollPos(GetDlgItem(IDD_LIVETIMESB), SB_CTL);
  gameParent->Frequence = MaxPop + 1 - ::GetScrollPos(GetDlgItem(IDD_POPSB), SB_CTL) + 5;

  BOOL noError;
  int time = GetDlgItemInt(IDD_INPUTEDITBOX, &noError, FALSE) * 10;
  if (noError && time > 0) {
    gameParent->GameTime = time;
    return TRUE;
  } else {
    MessageBox("Game time must be between 0 and 9830!", "Error", MB_OK);
    return FALSE;
  }
}

// --------------- TGameWindow -----------------

TGameWindow::TGameWindow()
  : TWindow(0, 0, 0)
{
  Attr.W = 282;
  Attr.H = 400;
  randomize();

  IsGameOver = TRUE;
  IsPause = FALSE;
  LiveTime = 10;
  Frequence = 20;
  Counter = 0;
  Score = 0;
  Hits = 0;
  Miss = 0;
  Escaped = 0;
  GameTime = 150;        // fifteen seconds
    
  SetCursor(GetModule(), "Malet");
}

void
TGameWindow::SetupWindow()
{
  HINSTANCE inst = *GetModule();
  CursorDown = new TCursor(inst, "MaletDown");
  CursorUp = new TCursor(inst, "Malet");
  Live = new TBitmap(inst, "Live");
  Dead = new TBitmap(inst, "Dead");
  GameOver = new TBitmap(inst, "GameOver");
  ScoreBoard = new TBitmap(inst, "Board");
}

void
TGameWindow::CreateTimer()
{
  if (SetTimer(TimerId, 100, 0) == 0) {
    MessageBox("No Timers Left", GetApplication()->GetName(),
               MB_OK | MB_ICONEXCLAMATION);
    exit(1);
  }
}

static
void
DrawBMP(TDC& dc, int x, int y, TBitmap& bitmap)
{
  TMemoryDC memDC(dc);
  memDC.SelectObject(bitmap);

  BITMAP bm;
  bitmap.GetObject(bm);
  dc.BitBlt(x, y, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);
}

void
TGameWindow::DrawGameOver(TDC& dc)
{
  DrawBMP(dc, 10, 70, *GameOver);
}

void
TGameWindow::DrawCritter(TDC& dc, int critterNumber)
{
  if (HoleInfo[critterNumber].Time != 0) {
    TMemoryDC memDC(dc);
    if (HoleInfo[critterNumber].Dead)
      memDC.SelectObject(*Dead);
    else
      memDC.SelectObject(*Live);
    dc.BitBlt(Holes[critterNumber].x, Holes[critterNumber].y,
              CritterSize, CritterSize, memDC, 0, 0, SRCCOPY);
  } else {
    dc.SelectStockObject(LTGRAY_BRUSH);
    dc.SelectStockObject(NULL_PEN);
    dc.Rectangle(Holes[critterNumber], TSize(CritterSize+1,CritterSize+1));
  }
}

void
TGameWindow::DrawScoreBoard(TDC& dc)
{
  DrawBMP(dc, 11, 214, *ScoreBoard);
}

void
TGameWindow::WriteScore(TDC& dc)
{
  TBrush brush(TColor(128, 128, 0));    // Yellow
  dc.SelectObject(brush);
  dc.SelectStockObject(NULL_PEN);
  dc.SetBkMode(TRANSPARENT);

  // Timer
  dc.Rectangle(130, 252, 163, 275);
  char s[21];
  sprintf(s, "%3.3d", GameTime - Counter);
  s[3] = s[2];
  s[2]= '.';
  dc.TextOut(TPoint(130, 252), s, 4);

  // Hits
  dc.Rectangle(40, 310, 71, 329);
  sprintf(s, "%3.3d", Hits);
  dc.TextOut(TPoint(40, 310), s, strlen(s));

  // Misses
  dc.Rectangle(77, 310, 117, 329);
  sprintf(s, "%3.3d", Miss);
  dc.TextOut(TPoint(77, 310), s, strlen(s));

  // Escaped
  dc.Rectangle(133, 310, 174, 329);
  sprintf(s, "%3.3d", Escaped);
  dc.TextOut(TPoint(133, 310), s, strlen(s));

  // Total
  dc.Rectangle(203, 310, 239, 328);
  sprintf(s, "%3.3d", Score);
  dc.TextOut(TPoint(203, 310), s, strlen(s));

  dc.RestoreObjects();
}

void
TGameWindow::CmAbout()
{
  TDialog(this, "About").Execute();
}

void
TGameWindow::CmOptions()
{
  TOptionDialog(this, "OptionDlg").Execute();
}

void
TGameWindow::CmPause()
{
  if (IsGameOver)
    return;

  if (IsPause) {
    IsPause = FALSE;
    TMenu(*Parent).ModifyMenu(IDM_PAUSE, MF_BYCOMMAND, IDM_PAUSE, "&Pause");
    Parent->DrawMenuBar();
    CreateTimer();

  } else {
    IsPause = TRUE;
    KillTimer(TimerId);
    TMenu(*Parent).ModifyMenu(IDM_PAUSE, MF_BYCOMMAND, IDM_PAUSE, "&Continue");
    Parent->DrawMenuBar();
  }
}

void 
TGameWindow::CeResetGame(TCommandEnabler& cmdEnabler)
{
  cmdEnabler.Enable(IsGameOver ? true : false);
}

void 
TGameWindow::CeOptions(TCommandEnabler& cmdEnabler) 
{
  cmdEnabler.Enable(IsGameOver ? true : false);    
}

void 
TGameWindow::CeStopGame(TCommandEnabler& cmdEnabler)
{
  cmdEnabler.Enable((IsGameOver || IsPause) ? false : true);   
}

void
TGameWindow::CmResetGame()
{
  TMenu menu(*Parent);
  menu.ModifyMenu(IDM_PAUSE, MF_BYCOMMAND, IDM_PAUSE, "&Pause");
  Parent->DrawMenuBar();
  Invalidate(TRUE);
  CreateTimer();
  memset(HoleInfo, 0, sizeof(HoleInfo));
  Counter = 0;
  Score = 0;
  Hits = 0;
  Miss = 0;
  Escaped = 0;
  IsGameOver = FALSE;
  if (IsPause) {
    IsPause = FALSE;
    menu.ModifyMenu(IDM_PAUSE, MF_BYCOMMAND, IDM_PAUSE, "&Pause");
    Parent->DrawMenuBar();
  }
}

void
TGameWindow::CmStopGame()
{
  KillTimer(TimerId);
  TMenu menu(*Parent);
  menu.ModifyMenu(IDM_PAUSE, MF_BYCOMMAND|MF_GRAYED, IDM_PAUSE, "&Pause");
  IsPause = FALSE;
  Parent->DrawMenuBar();
  IsGameOver = TRUE;
  Invalidate(TRUE);
  Counter = GameTime;
}

BOOL
TGameWindow::EvEraseBkgnd(HDC hDC)
{
  TDC dc(hDC);
  dc.TextRect(GetClientRect(), TColor::LtGray);
  return TRUE;
}

void
TGameWindow::EvDestroy()
{
  delete Live;
  delete Dead;
  delete GameOver;
  delete ScoreBoard;
  KillTimer(TimerId);
  TWindow::EvDestroy();
}

void
TGameWindow::EvLButtonDown(UINT, TPoint& clickPoint)
{
  SetCursor(GetModule(), "MaletDown");

  TPoint point;
  GetCursorPos(point);
  SetCursorPos(point.x, point.y);
  if (IsGameOver || IsPause)
    return;

  TClientDC dc(*this);
  
  BOOL hit = FALSE;
  for (int i = 0; i < 5; i++) {
    if (!HoleInfo[i].Dead && HoleInfo[i].Time != 0) {
      TRect rect(Holes[i], TSize(CritterSize,CritterSize));
      point = clickPoint;
      if (rect.Contains(point)) {
        Score += HitPoints;
        HoleInfo[i].Dead = TRUE;
        HoleInfo[i].Time = Counter + 2 * LiveTime;
        Hits++;
        hit = TRUE;
        DrawCritter(dc, i);
      }
    }
  }
  if (!hit) {
    Score += MissedPoints;
    Miss++;
  }
  WriteScore(dc);
}

void
TGameWindow::EvLButtonUp(UINT, TPoint&)
{
  SetCursor(GetModule(), "Malet");

  TPoint point;
  GetCursorPos(point);
  SetCursorPos(point.x, point.y);
}

void
TGameWindow::EvTimer(UINT)
{
  TClientDC dc(*this);

  Counter++;
  int i = random(Frequence);
  if (i < 5) {
    if (HoleInfo[i].Time == 0) {
      HoleInfo[i].Time = Counter + LiveTime;
      HoleInfo[i].Dead = FALSE;
      DrawCritter(dc, i);
    }
  }
  for (i = 0; i < 5; i++) {
    if (Counter > HoleInfo[i].Time && HoleInfo[i].Time != 0) {
      HoleInfo[i].Time = 0;
      if (!HoleInfo[i].Dead) {
        Score += MissedCritter;
        Escaped++;
      }
      DrawCritter(dc, i);
    }
  }
  WriteScore(dc);
  if (Counter >= GameTime)
    CmStopGame();
}

void
TGameWindow::EvSize(UINT /*SizeType*/, TSize& /*Size*/)
{
  if (IsGameOver)
    return;
  if (IsIconic())    // Could check SizeType
    KillTimer(TimerId);
  else if (!IsPause)
    CreateTimer();
}

void
TGameWindow::Paint(TDC& dc, BOOL, TRect&)
{
  DrawScoreBoard(dc);
  WriteScore(dc);
  if (IsGameOver)
    DrawGameOver(dc);
  else
    for (int i = 0; i < 5; i++)
      DrawCritter(dc, i);
}

// --------------- TApp ------------------------

class TApp : public TApplication {
  public:
    TApp() : TApplication() {}
    void InitMainWindow() {
      EnableCtl3d();
      MainWindow = new TFrameWindow(0, "Swat!", new TGameWindow, TRUE);
      MainWindow->AssignMenu("SWATMENU");
      MainWindow->SetIcon(this, "Critter");
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TApp().Run();
}
