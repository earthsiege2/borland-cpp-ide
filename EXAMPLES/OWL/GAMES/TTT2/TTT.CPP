//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992,1994 by Borland International
//
//   TicTacToe Demo Program
//
//   Plays a game of TicTacToe with the user.
//
//   TTTTGameApp - Main TicTacToe application, derived from TApplication
//   TGameView -   View window for the game, derived from TToolBox
//   Square - Game squares (gadgets), derived from TButtonGadget
//   TGameAboutBox - A TDialog box for info about TicTacToe
//   TGameOptionsBox - A TDialog box for setting TicTacToe options
//   YouMeRadioButton - A radio button which controls game settings
//   XORadioButton - A radio button which controls game settings
//
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
#include <owl/buttonga.h>
#include <owl/toolbox.h>
#include <owl/celarray.h>
#include <owl/buttonga.h>
#include "ttt.h"

#define WM_VIEWSYNC WM_USER + 100

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
freeSquare(int mask, int i, int& square)
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
  int j, test;
  for (j = 0, test = 1; test; test <<= 1, j++)
    if (test & mask)
      break;
  square = j;
}

//----------------------------------------------------------------------------

enum TSquareState {
  SqsEmpty,
  SqsX,
  SqsO,
  SqsCount
};

class TGame {
  public:
    TGame(int dim);

    void New();
    void SetView(TWindow* view) {View = view;}

    int  GetDimension() const {return Dim;}  // Dim x Dim game
    bool IsOver();// const;
    bool IsWon();// const;
    bool IsPlaying() const {return Playing;}
    TSquareState GetState(int sq) const;
//    TSquareState GetState(int row, int col) const
//        {return GetState(row*GetDimension + col);}

    void UserTurn(int sq);
    void ComputerTurn();

  private:
    int          Dim;
    int          UserBoardMap;
    int          ComputerBoardMap;
    TSquareState UserSide;
    TSquareState ComputerSide;
    bool         ComputerGoesFirst;
    bool         Playing;
    TWindow*     View;
    friend class TGameOptionsBox; // sleazy

  private:
    void SetState(int sq, TSquareState state);
    void MakeAMark(int sq, TSquareState mark);
    bool IsAWinner(int sq) const;
};

TGame::TGame(int dim)
{
  UserSide = SqsX;
  ComputerSide = SqsO;
  ComputerGoesFirst = false;
  Playing = true;
  UserBoardMap = ComputerBoardMap = 0;
  Dim = dim;
}

void
TGame::New()
{
  Playing = true;
  UserBoardMap = 0;
  ComputerBoardMap = 0;
  ComputerSide = UserSide==SqsX ? SqsO : SqsX;

  if (ComputerGoesFirst)
    ComputerTurn();

  if (View)
   View->PostMessage(WM_VIEWSYNC, 0xFFFF);
}

void
TGame::MakeAMark(int sq, TSquareState mark)
{
  SetState(sq, mark);
  if (View)
    View->PostMessage(WM_VIEWSYNC, sq);
}

bool
TGame::IsOver()
{
  if ((UserBoardMap|ComputerBoardMap) == 0x1FF)
    Playing = false;
  return !Playing;
}

bool
TGame::IsWon()
{
  for (int i = 0; i < 8; i++)
    if ((UserBoardMap & winningMasks[i]) == winningMasks[i] ||
        (ComputerBoardMap & winningMasks[i]) == winningMasks[i]) {
      Playing = false;
      return true;
    }
  return false;
}

TSquareState
TGame::GetState(int sq) const
{
  int mask = 1 << sq;

  if (ComputerBoardMap & mask)
    return ComputerSide;
  if (UserBoardMap & mask)
    return UserSide;
  return SqsEmpty;
}

void
TGame::SetState(int sq, TSquareState state)
{
  int mask = 1 << sq;

  if (state == SqsEmpty) {
    ComputerBoardMap &= ~mask;
    UserBoardMap &= ~mask;

  } else if (state == UserSide) {
    ComputerBoardMap &= ~mask;
    UserBoardMap |= mask;

  } else {
    ComputerBoardMap |= mask;
    UserBoardMap &= ~mask;
  }
}

bool
TGame::IsAWinner(int sq) const
{
  int map = ComputerBoardMap | (1 << sq);
  for (int i = 0; i < 8; i++)
    if ((map & winningMasks[i]) == winningMasks[i])
      return true;
  return false;
}

//
//
//
void
TGame::UserTurn(int sq)
{
  if (GetState(sq) == SqsEmpty)
    MakeAMark(sq, UserSide);
}

//
//
//
void
TGame::ComputerTurn()
{
  bool madeMove = false;

  // Look for a winning move first.
  //
  {
    for (int i = 0; i < Dim*Dim; i++) {
      if (GetState(i) == SqsEmpty && IsAWinner(i)) {
        MakeAMark(i, ComputerSide);
        madeMove = true;
        break;
      }
    }
  }

  // Look for a blocking move. This is the key to not losing the game!
  //
  if (!madeMove) {
    for (int i = 0; i < 24; i++)
      if ((UserBoardMap & freeMasks[i]) == freeMasks[i]) {
        int sq;
        freeSquare(freeMasks[i], i, sq);
        if (GetState(sq) == ComputerSide)
          continue;
        MakeAMark(sq, ComputerSide);
        madeMove = true;
        break;
      }
  }

  // Nothing to block, go to the middle if empty, else first open corner, else
  // first open edge
  // Game can be beaten if user knows how computer plays: try 5,7,8, & 2 to win
  //
  if (!madeMove) {
    int mask = UserBoardMap|ComputerBoardMap;
    if (!(mask & 0x010)) {
      MakeAMark(4, ComputerSide);    // #4 is the middle of 3x3

    }
    else if ((mask & 0x145) != 0x145) {  // corner mask
      int sq;
      if (!(mask & 0x001))
        sq = 0;
      else if (!(mask & 0x004))
        sq = 2;
      else if (!(mask & 0x040))
        sq = 6;
      else  // 0x100
        sq = 8;
      MakeAMark(sq, ComputerSide);    // #4 is the middle of 3x3

    }
    else {
      int i;
      for (i = 0; mask & 1; mask >>= 1)
        i++;
      MakeAMark(i, ComputerSide);
    }
  }

  // See if the game is over now.
  //
  if (IsWon() || IsOver())
    Playing = false;
}

//----------------------------------------------------------------------------

class TSquare : public TButtonGadget {
  public:
    TSquare(int id);
   ~TSquare();

    void      SetGlyph(int g);
    void      Paint(TDC& dc);

  protected:
    void      Activate(TPoint& p);
    int       Glyph;

  private:
    static TCelArray*  StateCels[3];
};
typedef TSquare* PTSquare;

TCelArray* TSquare::StateCels[SqsCount]; // entry for each state
static TResId StateResId[SqsCount] = { IDB_EMPTY, IDB_X, IDB_O };

TSquare::TSquare(int id)
:
  TButtonGadget(IDB_EMPTY, id, NonExclusive, true, Up, false),
  Glyph(0)
{
}

TSquare::~TSquare()
{
  CelArray = 0;
}

void
TSquare::SetGlyph(int g)
{
  Glyph = g;
  SetButtonState(Glyph ? Down : Up);
  Invalidate();
}

void
TSquare::Paint(TDC& dc)
{
  // Fool button gadget into making our special state cel arrays
  //
  TSize test;
  test = dc.GetWindowExt();
  test = dc.GetViewportExt();
  test = dc.GetWindowOrg();
  test = dc.GetViewportOrg();

  delete CelArray;   // delete any that might have been created
  for (int i = 0; i < SqsCount; i++)
    if (!StateCels[i]) {
      ResId = StateResId[i];
      CelArray = 0;     
      BuildCelArray();
      StateCels[i] = CelArray;
    }

  // Slip in the correct cel array just before painting
  //
  CelArray = StateCels[Glyph];
  TButtonGadget::Paint(dc);
  CelArray = 0;
  for(int i=0; i<3; i++)  {
   delete StateCels[i];
   StateCels[i] = 0;
  }
}

//
// Modify activate behavior to make the buttons 'sticky'
//
void
TSquare::Activate(TPoint& pt)
{
  if (!Glyph) {
    TButtonGadget::Activate(pt);
    Window->PostMessage(WM_COMMAND, GetId()); // post to owner view too
  } else
    CancelPressed(pt);
}

//----------------------------------------------------------------------------

class TGameView : public TToolBox {
  public:
    TGameView(TGame* game);
   ~TGameView();

  private:
    void      SetupWindow();
    TResult   EvCommand(uint id, HWND hWndCtl, uint notifyCode);
    void      EvCommandEnable(TCommandEnabler& ce);
    TResult   EvViewSync(TParam1 param1, TParam2 param2);

    enum TEndReason { Scratch, UserWon, ComputerWon };
    void      GameOver(TEndReason why);

    TGame*    Game;
    TSquare** Board;
    int       Dim;

  DECLARE_RESPONSE_TABLE(TGameView);
};

DEFINE_RESPONSE_TABLE1(TGameView, TToolBox)
  EV_MESSAGE(WM_VIEWSYNC, EvViewSync),
END_RESPONSE_TABLE;

TGameView::TGameView(TGame* game)
:
  TToolBox(0, game->GetDimension()),
  Game(game)
{
  Dim = Game->GetDimension();
  Board = new PTSquare[Dim*Dim];

  for (int i = 0; i < Dim; i++)
    for (int j = 0; j < Dim; j++) {
      TSquare* sq = new TSquare(CM_SQUARE + i*Dim + j);
      Board[i*Dim + j] = sq;
      Insert(*sq);
    }
}

TGameView::~TGameView()
{
  delete[] Board;
}

void
TGameView::SetupWindow()
{
  TWindow::SetupWindow();
}

void
TGameView::GameOver(TEndReason why)
{
  static char* msgs[] = { "Scratch", "You won!", "I won!" };
  MessageBox(msgs[why], "Game Over", MB_OK);
}

TResult
TGameView::EvCommand(uint id, HWND hWndCtl, uint notifyCode)
{
  if (id >= CM_SQUARE
      && id < CM_SQUARE+Game->GetDimension()*Game->GetDimension()
      && !hWndCtl) {

    int square = id - CM_SQUARE;

    if (Game->GetState(square) != SqsEmpty)// || !Game->IsPlaying())
      return 0;

    Game->UserTurn(square);

    if (Game->IsWon())
      GameOver(UserWon);

    else if (Game->IsOver())
      GameOver(Scratch);

    else {
      Game->ComputerTurn();

      // See if the game is over now.
      //
      if (Game->IsWon())
        GameOver(ComputerWon);

      else if (Game->IsOver())
        GameOver(Scratch);
    }
    return 0;
  }
  return TToolBox::EvCommand(id, hWndCtl, notifyCode);
}

void
TGameView::EvCommandEnable(TCommandEnabler& ce)
{
  if (ce.Id >= CM_SQUARE
      && ce.Id < CM_SQUARE+Game->GetDimension()*Game->GetDimension())
    ce.Enable(Game->IsPlaying());
  else
    TToolBox::EvCommandEnable(ce);
}

LRESULT
TGameView::EvViewSync(WPARAM wParam, LPARAM)
{
  if (wParam == 0xFFFF)
    for (int i = 0; i < Dim*Dim; i++)
      Board[i]->SetGlyph(Game->GetState(i));

  else
    Board[wParam]->SetGlyph(Game->GetState(wParam));

  return 0;
}

//----------------------------------------------------------------------------

class TGameAboutBox : public TDialog {
  public:
    TGameAboutBox::TGameAboutBox(TWindow* parent);
};

TGameAboutBox::TGameAboutBox(TWindow* parent)
:
  TDialog(parent, "IDD_ABOUT")
{
  char aboutstr[] = "Tic Tac Toe\n(C) Borland International\n 1992,1994";
  TStatic* textPtr = new TStatic(this, IDSTATIC, aboutstr, 23, 20, 190,
        45, strlen(aboutstr));
  textPtr->Attr.Style |= SS_CENTER;
  new TButton(this, IDOK, "Ok", 80, 90, 40, 40, true);
}

//----------------------------------------------------------------------------

class TGameOptionsBox : public TDialog {
  public:
    TGameOptionsBox(TWindow* parent, TGame* game);

  private:
    void SetupWindow();

    TGroupBox     *YouMeGroup, *XOGroup;
    TRadioButton  *You, *Me, *X, *O;
    TGame*         Game;

    void HandleYouMeGroupMsg(UINT);
    void HandleXOGroupMsg(UINT);

  DECLARE_RESPONSE_TABLE(TGameOptionsBox);
};
DEFINE_RESPONSE_TABLE1(TGameOptionsBox, TDialog)
  EV_CHILD_NOTIFY_ALL_CODES(IDYOUMEGROUP, HandleYouMeGroupMsg),
  EV_CHILD_NOTIFY_ALL_CODES(IDXOGROUP, HandleXOGroupMsg),
END_RESPONSE_TABLE;

TGameOptionsBox::TGameOptionsBox(TWindow* parent, TGame* game)
:
  TDialog(parent, "IDD_OPTIONS"),
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

void
TGameOptionsBox::HandleYouMeGroupMsg(uint)
{
  Game->ComputerGoesFirst = (You->GetCheck() == BF_CHECKED) ? false : true;
}

void
TGameOptionsBox::HandleXOGroupMsg(uint)
{
  Game->UserSide = (X->GetCheck() == BF_CHECKED) ? SqsO : SqsX;
  Game->Playing = false;
  Parent->PostMessage(WM_COMMAND, CM_GAMENEW);
}

//----------------------------------------------------------------------------

class TGameApp : public TApplication {
  public:
   TGameApp() :   TApplication("TicTacToe"), Game(0) {}
   ~TGameApp() { delete Game; }

  private:
   void CmGameNew();
   void CmGameOptions();
   void CmAbout();
   void InitMainWindow();

   TGame*  Game;

  DECLARE_RESPONSE_TABLE(TGameApp);
};

DEFINE_RESPONSE_TABLE1(TGameApp, TApplication)
  EV_COMMAND(CM_GAMENEW, CmGameNew),
  EV_COMMAND(CM_GAMEOPTIONS, CmGameOptions),
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

void
TGameApp::InitMainWindow()
{
  Game = new TGame(3);                         // game 'document'
  TGameView* gameView = new TGameView(Game);   // view of game
  Game->SetView(gameView);

  TFrameWindow* frame = new TFrameWindow(0, GetName(), gameView, true, this);
  frame->Attr.Style &= ~(WS_THICKFRAME|WS_MAXIMIZEBOX);
  frame->SetIcon(this, IDI_TTT);
  frame->AssignMenu("IDM_TTTGAME");

  SetMainWindow(frame);
  EnableBWCC();
}

void
TGameApp::CmGameNew()
{
  Game->New();
}

void
TGameApp::CmGameOptions()
{
  TGameOptionsBox(GetMainWindow(), Game).Execute();
}

void
TGameApp::CmAbout()
{
  TGameAboutBox(GetMainWindow()).Execute();
}

//----------------------------------------------------------------------------

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TGameApp().Run();
}
