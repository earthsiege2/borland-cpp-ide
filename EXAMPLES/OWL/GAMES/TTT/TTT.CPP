//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1995 by Borland International, All Rights Reserved
//
//   TicTacToe Demo Program
//
//   Plays a game of TicTacToe with the user.
//
//   TTTTGameApp - Main TicTacToe application, derived from TApplication
//   TGameWindow - Main window for the app, derived from TWindow
//   Square - Game squares (windows), derived from TWindow
//   TGameAboutBox - A TDialog box for info about TicTacToe
//   TGameOptionsBox - A TDialog box for setting TicTacToe options
//   YouMeRadioButton - A radio button which controls game settings
//   XORadioButton - A radio button which controls game settings
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dialog.h>
#include <owl/dc.h>
#include <owl/button.h>
#include <owl/static.h>
#include <owl/radiobut.h>
#include <owl/groupbox.h>
#include "ttt.h"

const uint TGW_WIDTH = 280, TGW_HEIGHT = 300;
const uint TGAB_WIDTH = 250, TGAB_HEIGHT = 300;
const uint TGAB_INITIAL_X = 5, TGAB_INITIAL_Y = 10;

const uint SW_SIZE = 40;
const uint BOARDXOFFSET = 30+SW_SIZE+3;
const uint BOARDYOFFSET = 10+SW_SIZE+2;

enum TSquareStatus { SqsUnoccupied, SqsX, SqsO };


static const int freeMasks[] = {
  0x006, 0x005, 0x003, 0x030, 0x028, 0x018, 0x180, 0x140, 0x0C0, // row
  0x048, 0x041, 0x009, 0x090, 0x082, 0x012, 0x120, 0x104, 0x024, // col
  0x110, 0x101, 0x011, 0x050, 0x044, 0x014                       // diagonal
};

static const int winningMasks[] = {
  0x1C0, 0x038, 0x007, 0x124, 0x092, 0x049, 0x111, 0x054
};


//
//
//
static void
freeSquare(int mask, int i, int *row, int *col)
{
  int mode = i/9; // row, col, or diag
  if (mode == 0)
    mask ^= 0x007 << (i/3)*3;
  else if (mode == 1)
    mask ^= 0x049 << (i%9)/3;
  else if (((i%9)/3) == 0)
    mask ^= 0x111;
  else
    mask ^= 0x054;

  int j = 0;
  for (int test = 1; test; test <<= 1, j++)
    if (test & mask)
      break;
  *row = j/3;
  *col = j%3;
}

//----------------------------------------------------------------------------

class TSquare;

//
//
//
class TGame {
  public:
    TGame(TWindow* window);

    int      UserBoardMap;
    int      ComputerBoardMap;
    TSquareStatus UserSide;
    bool     ComputerGoesFirst;
    bool     Playing;
    TSquare* Board[3][3];

    void ComputerTurn(TWindow* window);
    bool GameOver() {return (UserBoardMap|ComputerBoardMap) == 0x1FF;}
    bool IsWon();

  private:
    void MakeMyMark(int r, int c);
    bool IsAWinner(int r, int c);
};

//
//
//
class TSquare : public TWindow {
  public:
    TSquare(TWindow*, int, int, TGame* game);
    void MakeAnX() {SquareStatus = SqsX; Invalidate();}
    void MakeAnO() {SquareStatus = SqsO; Invalidate();}
    void Reset() {SquareStatus = SqsUnoccupied;Invalidate();}

   void EvLButtonDown(uint, TPoint&);
   void EvPaint();
   TSquareStatus SquareStatus;

  private:
    int Row;
    int Col;
    TGame* Game;

  DECLARE_RESPONSE_TABLE(TSquare);
};

DEFINE_RESPONSE_TABLE1(TSquare, TWindow)
 EV_WM_PAINT,
 EV_WM_LBUTTONDOWN,
END_RESPONSE_TABLE;

//
//
//
TSquare::TSquare(TWindow* parent, int x, int y, TGame* game)
:
  TWindow(parent, ""),
  SquareStatus(SqsUnoccupied),
  Row(x), Col(y),
  Game(game)
{
  Attr.W = Attr.H = SW_SIZE;
  Attr.X = BOARDXOFFSET + y*(SW_SIZE+3); // x and y are reversed because
  Attr.Y = BOARDYOFFSET + x*(SW_SIZE+3); // of screen coordinates
  Attr.Style = WS_VISIBLE|WS_CHILD;
}

//
//
//
void
TSquare::EvLButtonDown(uint, TPoint&)
{
  if (Game->Playing && SquareStatus == SqsUnoccupied) {
    if (Game->UserSide == SqsX) {
      MakeAnX();
      Game->UserBoardMap |= 1 << (Row*3+Col);
    }
    else {
      MakeAnO();
      Game->UserBoardMap |= 1 << (Row*3+Col);
    }
    if (Game->IsWon()) {
      Game->Playing = false;
      Parent->MessageBox("You won!", "", MB_OK);
    }
    else if (Game->GameOver()) {
      Game->Playing = false;
      Parent->MessageBox("Scratch", "", MB_OK);
    }
    else
      Game->ComputerTurn(Parent);
  }
  else
    Parent->PostMessage(WM_COMMAND, CM_GAMENEW);
}

//
//
//
void
TSquare::EvPaint()
{
  TPaintDC paintDC(HWindow);
  if (SquareStatus == SqsO)
    paintDC.Ellipse(0,0,SW_SIZE,SW_SIZE);

  else if (SquareStatus == SqsX) {
    paintDC.MoveTo(0,0);
    paintDC.LineTo(SW_SIZE,SW_SIZE);
    paintDC.MoveTo(SW_SIZE,0);
    paintDC.LineTo(0,SW_SIZE);
  }
}

//----------------------------------------------------------------------------

//
//
//
TGame::TGame(TWindow* window)
{
  UserSide = SqsX;
  ComputerGoesFirst = false;
  Playing = true;
  UserBoardMap = ComputerBoardMap = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      Board[i][j] = new TSquare(window, i, j, this);
}

//
//
//
void
TGame::MakeMyMark(int row, int col)
{
  if (UserSide == SqsX)
    Board[row][col]->MakeAnO();
  else
    Board[row][col]->MakeAnX();
  ComputerBoardMap |= 1 << (row*3+col);
}

//
//
//
bool
TGame::IsAWinner(int row, int col)
{
  int map = ComputerBoardMap | (1 << (row*3+col));
  for (int i = 0; i < 8; i++)
    if ((map & winningMasks[i]) == winningMasks[i])
      return true;
  return false;
}

//
// The following routine can be improved upon.  Write your own
// version of this routine so that the machine always wins or draws the game.
//
void
TGame::ComputerTurn(TWindow* window)
{
  bool madeMove = false;

  // Look for a winning move first.
  //
  {
    for (int i = 0; i < 9; i++) {
      if (Board[i/3][i%3]->SquareStatus==SqsUnoccupied && IsAWinner(i/3,i%3)) {
        MakeMyMark(i/3,i%3);
        madeMove = true;
        break;
      }
    }
  }

  // Look for a blocking move
  //
  if (!madeMove) {
    for (int i = 0; i < 24; i++)
      if ((UserBoardMap & freeMasks[i]) == freeMasks[i]) {
        int targetRow, targetCol;
        freeSquare(freeMasks[i], i, &targetRow, &targetCol);
        if (ComputerBoardMap & (1 << (targetRow*3+targetCol)))
          continue;
        MakeMyMark(targetRow,targetCol);
        madeMove = true;
        break;
      }
  }

  // Nothing to block, go to the middle if empty, else look for a 'good' move
  //
  if (!madeMove) {
    if (!((ComputerBoardMap|UserBoardMap) & 0x010)) {
      MakeMyMark(1,1);
    }
    else {
      int i = 0;
      for (int mask = UserBoardMap|ComputerBoardMap; mask & 1; mask >>= 1)
        i++;
      MakeMyMark(i/3,i%3);
    }
  }

  // See if the game is voer now.
  //
  if (IsWon()) {
    Playing = false;
    window->MessageBox("I won!", "", MB_OK);
  }
  else if (GameOver()) {
    Playing = false;
    window->MessageBox("Scratch", "", MB_OK);
  }
}

//
//
//
bool
TGame::IsWon()
{
  for (int i = 0; i < 8; i++)
    if ((UserBoardMap & winningMasks[i]) == winningMasks[i] ||
          (ComputerBoardMap & winningMasks[i]) == winningMasks[i])
      return true;
  return false;
}

//----------------------------------------------------------------------------

//
//
//
class TGameAboutBox : public TDialog {
  public:
    TGameAboutBox::TGameAboutBox(TWindow* parent);
};

//
//
//
TGameAboutBox::TGameAboutBox(TWindow* parent)
:
  TDialog(parent, "ABOUT")
{
  char aboutstr[] = "Tic Tac Toe\n(c) Borland International\n 1992, 1995";
  TStatic* textPtr = new TStatic(this, IDSTATIC, aboutstr, 23, 20, 190,
                                 45, strlen(aboutstr));
  textPtr->Attr.Style |= SS_CENTER;
  new TButton(this, IDOK, "Ok", 80, 90, 40, 40, true);
}

//----------------------------------------------------------------------------

//
//
//
class TGameOptionsBox : public TDialog {
  public:
    TGameOptionsBox::TGameOptionsBox(TWindow* parent, TGame* game);
    virtual void SetupWindow();

    TGroupBox     *YouMeGroup, *XOGroup;
    TRadioButton  *You, *Me, *X, *O;
    TGame*         Game;

    void HandleYouMeGroupMsg(uint);
    void HandleXOGroupMsg(uint);

  DECLARE_RESPONSE_TABLE(TGameOptionsBox);
};

DEFINE_RESPONSE_TABLE1(TGameOptionsBox, TDialog)
  EV_CHILD_NOTIFY_ALL_CODES(IDYOUMEGROUP, HandleYouMeGroupMsg),
  EV_CHILD_NOTIFY_ALL_CODES(IDXOGROUP, HandleXOGroupMsg),
END_RESPONSE_TABLE;

//
//
//
TGameOptionsBox::TGameOptionsBox(TWindow* parent, TGame* game)
:
  TDialog(parent, "OPTIONS"),
  Game(game)
{
  new TButton(this, IDOK, "Ok", 30, 240, 40, 40, true);
  new TButton(this, IDCANCEL, "Cancel", 150, 240, 40, 40, true);
  YouMeGroup = new TGroupBox(this, IDYOUMEGROUP, "Who goes first?", 15,
                     30, 200, 20);
  You = new TRadioButton(this, IDYOU, "You (Human)", 15, 55, 150, 20, YouMeGroup);
  Me = new TRadioButton(this, IDME, "Me (Computer)", 15, 80, 150, 20, YouMeGroup);
  XOGroup = new TGroupBox(this, IDXOGROUP, "I am playing", 15, 120, 200, 20);
  X = new TRadioButton(this, IDX, "X\'s", 15, 145, 50, 20, XOGroup);
  O = new TRadioButton(this, IDO, "O\'s", 15, 170, 50, 20, XOGroup);
}

//
//
//
void
TGameOptionsBox::SetupWindow()
{
  TDialog::SetupWindow();
  if (Game->ComputerGoesFirst)
    Me->Check();
  else
    You->Check();

  if (Game->UserSide == SqsX)
    O->Check();
  else
    X->Check();
}

//
//
//
void
TGameOptionsBox::HandleYouMeGroupMsg(uint)
{
  Game->ComputerGoesFirst = (You->GetCheck() == BF_CHECKED) ? false : true;
}

//
//
//
void
TGameOptionsBox::HandleXOGroupMsg(uint)
{
  Game->UserSide = (X->GetCheck() == BF_CHECKED) ? SqsO : SqsX;
  Game->Playing = false;
  Parent->PostMessage(WM_COMMAND, CM_GAMENEW);
}

//----------------------------------------------------------------------------

//
//
//
class TGameWindow : public TFrameWindow {
  public:
    TGameWindow(TWindow* parent, const char* title);

    void EvPaint();
    void CmGameNew();
    void CmGameOptions();
    void CmAbout();

    TGame* Game;

  DECLARE_RESPONSE_TABLE(TGameWindow);
};

DEFINE_RESPONSE_TABLE1(TGameWindow, TFrameWindow)
  EV_WM_PAINT,
  EV_COMMAND(CM_GAMENEW, CmGameNew),
  EV_COMMAND(CM_GAMEOPTIONS, CmGameOptions),
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

//
//
//
TGameWindow::TGameWindow(TWindow* parent, const char* title)
:
  TFrameWindow(parent, title),
  TWindow(parent, title)
{
  AssignMenu("COMMANDS");
  Attr.X = TGAB_INITIAL_X;
  Attr.Y = TGAB_INITIAL_Y;
  Attr.W = TGW_WIDTH;
  Attr.H = TGW_HEIGHT;

  Game = new TGame(this);
}

//
//
//
void
TGameWindow::EvPaint()
{
  TPaintDC paintDC(HWindow);
  paintDC.MoveTo(BOARDXOFFSET+SW_SIZE+2, BOARDYOFFSET);
  paintDC.LineTo(BOARDXOFFSET+SW_SIZE+2, BOARDYOFFSET+SW_SIZE*3+6);
  paintDC.MoveTo(BOARDXOFFSET+SW_SIZE*2+5, BOARDYOFFSET);
  paintDC.LineTo(BOARDXOFFSET+SW_SIZE*2+5, BOARDYOFFSET+SW_SIZE*3+6);
  paintDC.MoveTo(BOARDXOFFSET, BOARDYOFFSET+SW_SIZE+2);
  paintDC.LineTo(BOARDXOFFSET+SW_SIZE*3+6, BOARDYOFFSET+SW_SIZE+2);
  paintDC.MoveTo(BOARDXOFFSET, BOARDYOFFSET+SW_SIZE*2+5);
  paintDC.LineTo(BOARDXOFFSET+SW_SIZE*3+6, BOARDYOFFSET+SW_SIZE*2+5);
}

//
//
//
void
TGameWindow::CmGameNew()
{
  Game->Playing = true;
  Game->UserBoardMap = 0;
  Game->ComputerBoardMap = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      Game->Board[i][j]->Reset();
  if (Game->ComputerGoesFirst)
    Game->ComputerTurn(this);
}

//
//
//
void
TGameWindow::CmGameOptions()
{
  TGameOptionsBox(this, Game).Execute();
}

//
//
//
void TGameWindow::CmAbout()
{
  TGameAboutBox(this).Execute();
}

//----------------------------------------------------------------------------

//
//
//
class TTTTGameApp : public TApplication {
  public:
    TTTTGameApp() : TApplication() {}

    void InitMainWindow();
};

//
//
//
void
TTTTGameApp::InitMainWindow()
{
  EnableBWCC();
  MainWindow = new TGameWindow(0, "TicTacToe");
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTTTGameApp().Run();
}
