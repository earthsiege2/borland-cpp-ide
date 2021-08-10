//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992,1994 by Borland International
//
//   TicTacToe Demo Program
//
//   Plays a game of TicTacToe with the user.
//
//   TGameApp - Main TicTacToe application, derived from TApplication
//   TGame -   Game document
//   TGameOptionsBox - A TDialog box for setting TicTacToe options
//   TGameView -   View window for the game, derived from TToolBox
//   Square - Game squares (gadgets), derived from TButtonGadget
//   TAboutBox - A TDialog box for info about TicTacToe
//
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/decframe.h>
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
#include <owl/ocfevent.h>
#include <ocf/ocreg.h>
#include <ocf/ocapp.h>
#include <ocf/ocdoc.h>
#include <ocf/ocremvie.h>
#include <ocf/ocstorag.h>
#include <owl/controlb.h>
#include <owl/olefacto.h>

#include "ttt.h"

#define WM_GAMEVIEWSYNC WM_USER + 100

const char  GameStreamName[] = "TicTacToe";
const int DllIdleTime = 200;    // time in MS for idle action polling
const int TTT_DLLIDLE = 32000;  // Idle timer ID for DLL servers

// App dictionary & Ole registrar objects
//
DEFINE_APP_DICTIONARY(AppDictionary);
static TPointer<TOcRegistrar> Registrar;

REGISTRATION_FORMAT_BUFFER(100)

BEGIN_REGISTRATION(AppReg)
#if defined(BI_APP_DLL)
 REGDATA(clsid,      "{5E4BD420-8ABC-101B-A23B-CE4E85D07ED2}")
// REGDATA(progid,     "TicTacToe.DllServer")
#else
 REGDATA(clsid,      "{5E4BD425-8ABC-101B-A23B-CE4E85D07ED2}")
// REGDATA(progid,     "TicTacToe.Application")
#endif
 REGDATA(description, "TicTacToe Application")
 REGDATA(appname,     "TicTacToe")
END_REGISTRATION

BEGIN_REGISTRATION(DocReg)
#if defined(BI_APP_DLL)
 REGDATA(progid,     "TicTacToeDll.Game.1")
 REGDATA(description,"TicTacToeDll Game")
// REGDATA(serverctx, "Inproc")
#else
 REGDATA(progid,     "TicTacToeExe.Game.1")
 REGDATA(description,"TicTacToeExe Game")
// REGDATA(debugger,   "tdw")
#endif
 REGDATA(menuname,   "Game")
 REGDATA(insertable, "")
 REGDATA(extension,  "ttt")
 REGDATA(docfilter,  "*.ttt")
 REGDATA(verb0,      "&Play")
 REGFORMAT(0, ocrEmbedSource,  ocrContent, ocrIStorage, ocrGet)
 REGFORMAT(1, ocrMetafilePict, ocrContent, ocrMfPict,   ocrGet)
END_REGISTRATION

TRegLink* RegLinkHead;
TRegLink  tttGameLink(::DocReg, ::RegLinkHead);

//----------------------------------------------------------------------------

class TGameApp : public TApplication, public TOcModule {
  public:
    TGameApp();
   ~TGameApp();
    TUnknown* CreateOleObject(uint32 options, TRegLink* link);

  private:
    void   CmAbout();
    void   InitMainWindow();

  DECLARE_RESPONSE_TABLE(TGameApp);
};
DEFINE_RESPONSE_TABLE1(TGameApp, TApplication)
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

//----------------------------------------------------------------------------

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
  for (int j = 0, test = 1; test; test <<= 1, j++)
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
    TGame(TGame* p = 0, int dim=3);

    void New();
    void SetView(TWindow* view) {View = view;}

    int  GetDimension() const {return Dim;}  // Dim x Dim game
    bool IsOver();// const;
    bool IsWon();// const;
    bool IsPlaying() const {return Playing;}
    TSquareState GetState(int sq) const;

    void UserTurn(int sq);
    void ComputerTurn();
    void SetApplication(TGameApp* app) {App = app;}
    TGameApp* GetApplication() {return App;}

  private:
    int          Dim;
    int          UserBoardMap;
    int          ComputerBoardMap;
    TSquareState UserSide;
    TSquareState ComputerSide;
    bool         ComputerGoesFirst;
    bool         Playing;
    TWindow*     View;
    TGameApp*    App;

    friend class TGameOptionsBox; // sleazy

  private:
    void SetState(int sq, TSquareState state);
    void MakeAMark(int sq, TSquareState mark);
    bool IsAWinner(int sq) const;

  friend class TGameView;
};

TGame::TGame(TGame* /*not used*/, int dim)
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
   View->PostMessage(WM_GAMEVIEWSYNC, 0xFFFF);
}

//
// Assign a square to user or computer and repaint the game board
//
void
TGame::MakeAMark(int sq, TSquareState mark)
{
  SetState(sq, mark);
  if (View)
    View->PostMessage(WM_GAMEVIEWSYNC, sq);
}

//
// Check if the game is over, ie, no more blank squares
//
bool
TGame::IsOver()
{
  if ((UserBoardMap|ComputerBoardMap) == 0x1FF)
    Playing = false;
  return !Playing;
}

//
// Check if the game is won by either user or computer
//
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

//
// Check if a square belongs to user or computer
//
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

//
// Assign a square to a user or computer or neither
//
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

//
// The computer tries to determine if there is a winning move
//
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

    } else if ((mask & 0x145) != 0x145) {  // corner mask
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

    } else {
      for (int i = 0; mask & 1; mask >>= 1)
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
  TDialog(parent, IDD_OPTIONS),
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
TGameOptionsBox::HandleYouMeGroupMsg(UINT)
{
  Game->ComputerGoesFirst = (You->GetCheck() == BF_CHECKED) ? false : true;
}

void
TGameOptionsBox::HandleXOGroupMsg(UINT)
{
  Game->UserSide = (X->GetCheck() == BF_CHECKED) ? SqsO : SqsX;
  Game->Playing = false;
  Parent->PostMessage(WM_COMMAND, CM_GAMENEW);
}

//----------------------------------------------------------------------------

class TSquare : public TButtonGadget {
  public:
    TSquare(int id);
   ~TSquare() {CelArray = 0;}

    void      SetGlyph(int g);
    void      Paint(TDC& dc);

  protected:
    void      Activate(TPoint& p);
    int       Glyph;

  private:
    static TCelArray*  StateCels[3];
  friend class TGameView;
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
  delete CelArray;   // delete any that might have been created
  for (int i = 0; i < SqsCount; i++)
    if (!StateCels[i]) {
      ResId = StateResId[i];
      CelArray = 0;     // leak?
      BuildCelArray();
      StateCels[i] = CelArray;
    }

  // slip in the correct cel array just before painting
  //
  CelArray = StateCels[Glyph];
  TButtonGadget::Paint(dc);
  CelArray = 0;
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
    TGameView(TGame& game);
   ~TGameView();
    TUnknown* SetupView(bool isEmbeded);
    TGame&    Game;

    static const char far* StaticName() {return "TGameView";}
  private:
    void      SetupWindow();
    void      CleanupWindow();
    LRESULT   EvCommand(UINT id, HWND hWndCtl, UINT notifyCode);
    void      EvCommandEnable(TCommandEnabler& ce);
    LRESULT   EvGameViewSync(WPARAM wParam, LPARAM lParam);

    LRESULT   EvOcEvent(WPARAM wParam, LPARAM lParam);

    const char far* EvOcViewTitle();
    bool   EvOcPartInvalid(TOcPart far&){return false;}
    bool   EvOcViewSavePart(TOcSaveLoad far& ocSave);
    bool   EvOcViewLoadPart(TOcSaveLoad far& ocLoad);
    bool   EvOcViewPaint(TOcViewPaint far&);
    bool   EvOcViewInsMenus(TOcMenuDescr far&);
    bool   EvOcViewShowTools(TOcToolBarInfo far&);
    bool   EvOcViewGetPalette(LOGPALETTE far* far*);
    bool   EvOcViewClipData(TOcFormatData far&);
    bool   EvOcViewClose();
    bool   EvOcViewAttachWindow(bool attach);

    void   CmGameNew();
    void   CmGameOptions();

    bool   IdleAction(long idleCount);
    
    enum TEndReason { Scratch, UserWon, ComputerWon };
    void      GameOver(TEndReason why);

    TSquare** Board;
    int       Dim;
    TControlBar* ToolBar;
    char*     ContainerName;
    bool      IsEmbedded;

  public:
    TOcRemView*  RemView;
    TOcDocument* Document;

  DECLARE_RESPONSE_TABLE(TGameView);
};

DEFINE_RESPONSE_TABLE1(TGameView, TToolBox)
  EV_MESSAGE(WM_GAMEVIEWSYNC, EvGameViewSync),
  EV_MESSAGE(WM_OCEVENT, EvOcEvent),

  EV_OC_VIEWPAINT,
  EV_OC_VIEWSAVEPART,
  EV_OC_VIEWLOADPART,
  EV_OC_VIEWINSMENUS,
  EV_OC_VIEWSHOWTOOLS,
  EV_OC_VIEWGETPALETTE,
  EV_OC_VIEWCLIPDATA,
  EV_OC_VIEWCLOSE,

  EV_OC_VIEWATTACHWINDOW, //!

  EV_COMMAND(CM_GAMENEW, CmGameNew),
  EV_COMMAND(CM_GAMEOPTIONS, CmGameOptions),
END_RESPONSE_TABLE;

TGameView::TGameView(TGame& game)
:
  Game(game),
  TToolBox(0, game.GetDimension(), AS_MANY_AS_NEEDED, Horizontal, game.GetApplication()),
  RemView(0)
{
  Dim = Game.GetDimension();
  Board = new PTSquare[Dim*Dim];
  ToolBar = 0;
  ContainerName = new char[255];
  IsEmbedded = false;

  TOcApp* ocApp = Game.GetApplication()->OcApp;
  Document = new TOcDocument(*ocApp, 0, 0);  // temp file (deletes on close)

  for (int i = 0; i < Dim; i++)
    for (int j = 0; j < Dim; j++) {
      TSquare* sq = new TSquare(CM_SQUARE + i*Dim + j);
      Board[i*Dim + j] = sq;
      Insert(*sq);
    }
  Game.SetView(this);

  ocApp->AddRef();
}

//
// Called after the window is created to create & attach to the OcRemView
//
TUnknown*
TGameView::SetupView(bool isEmbedded)
{
  IsEmbedded = isEmbedded;
  RemView = new TOcRemView(*Document, &::DocReg);
  RemView->SetupWindow(*this, isEmbedded);
  return RemView;
}

static TControlBar*
BuildControlBar(TWindow* parent, TControlBar::TTileDirection direction)
{
  TControlBar* cb = new TControlBar(parent, direction, new TGadgetWindowFont);
  cb->Insert(*new TButtonGadget(CM_GAMENEW, CM_GAMENEW));
  cb->Insert(*new TButtonGadget(CM_GAMEOPTIONS, CM_GAMEOPTIONS));
  cb->Insert(*new TButtonGadget(CM_ABOUT, CM_ABOUT));
  cb->Attr.Style |= WS_CLIPSIBLINGS;    // since toolbar may move around
  cb->Attr.X = cb->Attr.Y = 0;
  cb->Attr.W = 9999;
  cb->Attr.Id = IDW_TOOLBAR;
  return cb;
}

TGameView::~TGameView()
{
  if (Document)
    Document->Close();           // close all the embedded parts first
  if (RemView && !IsEmbedded)
    RemView->ReleaseObject();
  delete Document;
  Game.GetApplication()->OcApp->Release();

  delete [] Board;
  delete [] ContainerName;
}

void
TGameView::SetupWindow()
{
  TWindow::SetupWindow();
  SetFocus();
  ToolBar = BuildControlBar(this, TControlBar::Horizontal);
  ToolBar->Attr.Style &= ~WS_VISIBLE;
  ToolBar->Create();
}

void
TGameView::CleanupWindow()
{
  if (RemView && !IsEmbedded){
    RemView->EvClose();
  }
  TToolBox::CleanupWindow();
}

void
TGameView::GameOver(TEndReason why)
{
  static char* msgs[] = { "Scratch", "You won!", "I won!" };
  MessageBox(msgs[why], "Game Over", MB_OK);
}

LRESULT
TGameView::EvCommand(UINT id, HWND hWndCtl, UINT notifyCode)
{
  if (id >= CM_SQUARE
      && id < CM_SQUARE+Game.GetDimension()*Game.GetDimension()
      && !hWndCtl) {

    int square = id - CM_SQUARE;

    if (Game.GetState(square) != SqsEmpty)// || !Game->IsPlaying())
      return 0;

    Game.UserTurn(square);

    if (Game.IsWon())
      GameOver(UserWon);

    else if (Game.IsOver())
      GameOver(Scratch);

    else {
      Game.ComputerTurn();

      // See if the game is over now.
      //
      if (Game.IsWon())
        GameOver(ComputerWon);

      else if (Game.IsOver())
        GameOver(Scratch);
    }
    return 0;
  }
  return TToolBox::EvCommand(id, hWndCtl, notifyCode);
}

//
// Handle the command Ids for the TTT squares by hand, otherwise, if embeded
// route them normally, else forward to base
//
void
TGameView::EvCommandEnable(TCommandEnabler& ce)
{
  if (ce.Id >= CM_SQUARE
      && ce.Id < CM_SQUARE+Game.GetDimension()*Game.GetDimension()) {
    ce.Enable(Game.IsPlaying());
  }
  else if (IsEmbedded) {
    // Get the focus, in case it is a child that should receive the cmds
    // fall back to this window in case the Ole menu bar stole focus!
    //
    HWND  hCmdTarget = ::GetFocus();
    if (hCmdTarget != HWindow && !IsChild(hCmdTarget))
      hCmdTarget = HWindow;

    RouteCommandEnable(hCmdTarget, ce);
  }
  else
    TToolBox::EvCommandEnable(ce);
}

LRESULT
TGameView::EvGameViewSync(WPARAM wParam, LPARAM)
{
  if (wParam == 0xFFFF)
    for (int i = 0; i < Dim*Dim; i++)
      Board[i]->SetGlyph(Game.GetState(i));

  else
    Board[wParam]->SetGlyph(Game.GetState(wParam));

  if (RemView)
    RemView->Invalidate(invView);

  return 0;
}

//
// Handle & sub-dispatch the OC event message.
//
LRESULT
TGameView::EvOcEvent(WPARAM wParam, LPARAM lParam)
{
  TEventHandler::TEventInfo eventInfo(WM_OCEVENT, wParam);  //WM_OWLNOTIFY
  if (Find(eventInfo))
    return Dispatch(eventInfo, wParam, lParam);
  return 0;
}

//
// Return our frame's title
//
const char far*
TGameView::EvOcViewTitle()
{
  Parent->GetWindowText(ContainerName, 255 - 1);
  return ContainerName;
}

//
// Ask server to close the document
//
bool
TGameView::EvOcViewClose()
{
  if (Document)
    Document->Close();
  return true;
}


//
// Attach this view back to its owl parent for either open editing, or
// mearly inplace de-activating
//
bool
TGameView::EvOcViewAttachWindow(bool attach)
{

  TFrameWindow* mainWindow = GetApplication()->GetMainWindow();

  if (attach) {
    if (RemView->GetState()==TOcRemView::OpenEditing) {
      mainWindow->Show(SW_SHOW);    // in case it was hidden
      mainWindow->BringWindowToTop();

      // Derived class needs to managed setting up frame differently, like
      // for MDI etc.
      //
      mainWindow->SetClientWindow(this);
    }
  }

  return true;
}

//
// Save the game to the IStorage provided by the container
//
bool
TGameView::EvOcViewSavePart(TOcSaveLoad far& ocSave)
{
  PRECONDITION(ocSave.StorageI);

  Document->SetStorage(ocSave.StorageI);

  // Save remote view info such as origin and extent
  //
  RemView->Save(ocSave.StorageI);

  // Write out the embedded objects, if any
  //

  // Create/open a stream in our storage to save part information
  //
  TOcStorage Storage(ocSave.StorageI);
  STATSTG  statstg;
  if (!HRSucceeded(Storage.Stat(&statstg, STATFLAG_NONAME)))
    return false;

  TOcStream  stream(Storage, ::GameStreamName, true, statstg.grfMode);

  // Write Game data into stream
  //
  ulong count;
  if (!(SUCCEEDED(stream.Write(&Game.Dim, sizeof(int), &count)) &&
      SUCCEEDED(stream.Write(&Game.UserBoardMap, sizeof(int), &count)) &&
      SUCCEEDED(stream.Write(&Game.ComputerBoardMap, sizeof(int), &count)) &&
      SUCCEEDED(stream.Write(&Game.UserSide, sizeof(TSquareState), &count)) &&
      SUCCEEDED(stream.Write(&Game.ComputerSide, sizeof(TSquareState), &count)) &&
      SUCCEEDED(stream.Write(&Game.ComputerGoesFirst, sizeof(bool), &count)) &&
      SUCCEEDED(stream.Write(&Game.Playing, sizeof(bool), &count))))
    return false;

  for (int i = 0; i < Dim; i++)
    for (int j = 0; j < Dim; j++) {
      TSquare* sq = Board[i*Dim + j];
      if (!SUCCEEDED(stream.Write(&sq->Glyph, sizeof(int), &count)))
        return false;
    }

  return true;
}

//
// Load the game from the IStorage provided by the container
//
bool
TGameView::EvOcViewLoadPart(TOcSaveLoad far& ocLoad)
{
  PRECONDITION(ocLoad.StorageI);

  // Assign new storage to OcDocument
  //
  Document->SetStorage(ocLoad.StorageI);

  // Load remote view info such as origin and extent
  //
  RemView->Load(ocLoad.StorageI);

  // Read in the embedded objects, if any
  //
  // Create/open a stream in our storage to save part information
  //
  TOcStorage Storage(ocLoad.StorageI);
  STATSTG  statstg;
  if (!SUCCEEDED(Storage.Stat(&statstg, STATFLAG_NONAME)))
    return false;

  TOcStream  stream(Storage, ::GameStreamName, false, statstg.grfMode);


  // Read in the game data
  //
  ulong count;
  if (!(SUCCEEDED(stream.Read(&Game.Dim, sizeof(int), &count)) &&
      SUCCEEDED(stream.Read(&Game.UserBoardMap, sizeof(int), &count)) &&
      SUCCEEDED(stream.Read(&Game.ComputerBoardMap, sizeof(int), &count)) &&
      SUCCEEDED(stream.Read(&Game.UserSide, sizeof(TSquareState), &count)) &&
      SUCCEEDED(stream.Read(&Game.ComputerSide, sizeof(TSquareState), &count)) &&
      SUCCEEDED(stream.Read(&Game.ComputerGoesFirst, sizeof(bool), &count)) &&
      SUCCEEDED(stream.Read(&Game.Playing, sizeof(bool), &count))))
    return false;

  for (int i = 0; i < Dim; i++)
    for (int j = 0; j < Dim; j++) {
      TSquare* sq = Board[i*Dim + j];
      if (!SUCCEEDED(stream.Read(&sq->Glyph, sizeof(int), &count)))
        return false;
    }

  if (! ocLoad.Remember)
    Document->SetStorage((IStorage*)0);

  PostMessage(WM_GAMEVIEWSYNC, 0xFFFF);

  return true;
}

bool
TGameView::EvOcViewPaint(TOcViewPaint far& vp)
{
  // paint according to the view paint structure
  //
  TDC dc(vp.DC);

  Dim = Game.GetDimension();
  for (int i = 0; i < Dim; i++)
    for (int j = 0; j < Dim; j++) {
      TSquare* sq = Board[i*Dim + j];
      TPoint pt(-sq->GetBounds().left, -sq->GetBounds().top);
      dc.SetWindowOrg(pt);
      sq->Paint(dc);
    }
  return true;
}

bool
TGameView::EvOcViewInsMenus(TOcMenuDescr far& sharedMenu)
{
  // Recreate a temporary composite menu for frame and child
  //
  TMenuDescr compMenuDesc; // empty menudescr
  compMenuDesc.Merge(TMenuDescr("IDM_TTTSVRGAME",0,0,0,1,0,1));
  compMenuDesc.Merge(TMenuDescr(0,  -1, 0, -1, 0, -1, 0));

  TMenuDescr shMenuDescr(sharedMenu.HMenu,
                         sharedMenu.Width[0],
                         sharedMenu.Width[1],
                         sharedMenu.Width[2],
                         sharedMenu.Width[3],
                         sharedMenu.Width[4],
                         sharedMenu.Width[5]);
  shMenuDescr.Merge(compMenuDesc);

  for (int i = 0; i < 6; i++)
    sharedMenu.Width[i] = shMenuDescr.GetGroupCount(i);

  return true;
}

//
// Let OC have our toolbar to insert
//
bool
TGameView::EvOcViewShowTools(TOcToolBarInfo far& tbi)
{
  tbi.HTopTB = *ToolBar;
//  tbi.HBottomTB = *ToolBar;  // Can put it on the bottom too
  return true;
}

//
// Get server's color palette
//
bool
TGameView::EvOcViewGetPalette(LOGPALETTE far* far*)
{
  return false;
}

//
// Ask server to provide data according to the format in a handle
//
bool
TGameView::EvOcViewClipData(TOcFormatData far&)
{
  return 0;
}

void
TGameView::CmGameNew()
{
  Game.New();
}

void
TGameView::CmGameOptions()
{
  TGameOptionsBox(this, &Game).Execute();
}

static void
DoIdleAction(TWindow* win, void* idleCount)
{
  win->IdleAction(*(long*)idleCount);
}

//
// TFrameWindow processes idle action occurs once per block of messages
//
bool
TGameView::IdleAction(long idleCount)
{
  if (idleCount == 0) {
    // give child windows an opportunity to do any idle processing
    //
    ForEach(DoIdleAction, &idleCount);
  }
  return false;  // we don't need any more time for now
}

//----------------------------------------------------------------------------

class TAboutBox : public TDialog {
  public:
    TAboutBox::TAboutBox(TWindow* parent, TResId dlgId, const char far* msg);
};

TAboutBox::TAboutBox(TWindow* parent, TResId dlgId, const char far* msg)
:
  TDialog(parent, dlgId)
{
  TStatic* stat = new TStatic(this, IDSTATIC, msg, 23, 20, 190, 45, 0);
  stat->Attr.Style |= SS_CENTER;
  new TButton(this, IDOK, "OK", 80, 90, 40, 40, true);
}

//----------------------------------------------------------------------------

class TAppFrame : public TFrameWindow {
  public:
    TAppFrame(const char far* title,
              TResId          menuResId,
              TGameApp*       module);
   ~TAppFrame();

  private:
    void       SetupWindow();
    void       CleanupWindow();

    LRESULT    EvOcEvent(WPARAM wParam, LPARAM lParam);
    bool       EvOcAppShutdown();
    void       EvTimer(uint timerId);

    TGameApp*  GameApp;

  DECLARE_RESPONSE_TABLE(TAppFrame);
};
DEFINE_RESPONSE_TABLE1(TAppFrame, TFrameWindow)
  EV_WM_TIMER,
  EV_MESSAGE(WM_OCEVENT, EvOcEvent),
  EV_OC_APPSHUTDOWN,
END_RESPONSE_TABLE;

TAppFrame::TAppFrame(const char far* title,
                     TResId          menuResId,
                     TGameApp*       module)
:
  TFrameWindow(0, title, 0, true, module),
  GameApp(module)
{
  AssignMenu(menuResId);
}

TAppFrame::~TAppFrame()
{
}

void
TAppFrame::SetupWindow()
{
  TFrameWindow::SetupWindow();

  // Wire up ObjectConnections to our hWnd
  //
  GameApp->OcApp->SetupWindow(*this);

  // Create a timer to allow us to poll for idle time when we are a dll server
  //
  if (!GameApp->OcApp->IsOptionSet(amExeMode))
    SetTimer(TTT_DLLIDLE, DllIdleTime);
}

void
TAppFrame::CleanupWindow()
{
  if (!GameApp->OcApp->IsOptionSet(amExeMode))
    KillTimer(TTT_DLLIDLE);
}

bool
TAppFrame::EvOcAppShutdown()
{
  // called by TOcApp::ShutdownMaybe when last embedding is closed
  // if that's the only reason the app is up we need to shut ourselves down
  //
  SendMessage(WM_CLOSE);
  return true;
}

//
// Handle & sub-dispatch the OC event message to ourselves & to the app
//
LRESULT
TAppFrame::EvOcEvent(WPARAM wParam, LPARAM lParam)
{
  TEventHandler::TEventInfo eventInfo(WM_OCEVENT, wParam);
  if (Find(eventInfo))
    return Dispatch(eventInfo, wParam, lParam);
  if (GetApplication()->Find(eventInfo))
    return GetApplication()->Dispatch(eventInfo, wParam, lParam);
  return 0;
}

//
//
//
void
TAppFrame::EvTimer(uint timerId)
{
  if (timerId == TTT_DLLIDLE)
    GetApplication()->PostDispatchAction();
  TWindow::EvTimer(timerId);
}

//----------------------------------------------------------------------------

TGameApp::TGameApp()
:
  TApplication(::AppReg["description"], ::Module, &::AppDictionary)
{
  EnableBWCC();
}

TGameApp::~TGameApp()
{
}

void
TGameApp::InitMainWindow()
{
  nCmdShow = IsOptionSet(amEmbedding) ? SW_HIDE : SW_SHOWNORMAL;
  MainWindow = new TAppFrame(GetName(), "IDM_TTTGAME", this);
  MainWindow->Attr.Style &= ~(WS_THICKFRAME|WS_MAXIMIZEBOX);
  MainWindow->SetIcon(this, IDI_TTT);
}

TUnknown*
TGameApp::CreateOleObject(uint32 options, TRegLink* regLink)
{
  // create the only object we know about. If we served more objects, we would
  // need to examine regLink to determine which to create
  //
  TGame* game = new TGame;
  game->SetApplication(this);
  TGameView* view = new TGameView(*game);

  if (options & amRun)
    GetMainWindow()->SetClientWindow(view);
  else
    view->SetParent(GetMainWindow());

  if (!GetMainWindow()->HWindow)
    return 0;

  view->Create();
  return regLink ? view->SetupView(true) : 0;
}

void
TGameApp::CmAbout()
{
  TAboutBox(&TWindow(::GetFocus(), this),
            IDD_ABOUT,
            "Tic Tac Toe\n(C) Borland International\n 1992,1994"
            ).Execute();
}

//----------------------------------------------------------------------------

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  try {
    // App registration object
    //
    Registrar = new TOcRegistrar(AppReg, TOleFactory<TGameApp>(),
                                 TApplication::GetCmdLine(), ::RegLinkHead);

    // We are all done if one of the action options was specified on the
    // cmdLine
    //
    if (Registrar->IsOptionSet(amAnyRegOption))
      return 0;  // Could display a msg box here if desired
    
    return Registrar->Run();
  }
  catch (xmsg& x) {
    return ::HandleGlobalException(x, "Exception");
  }
}
