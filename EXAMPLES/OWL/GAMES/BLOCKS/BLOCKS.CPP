//--------------------------------------------------------------------------
// Turbo Blocks -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/window.h>
#include <owl/dialog.h>
//#include <mmsystem.h>

#include <string.h>

#include "blocks.rh"

const int GAME_WIDTH = 10;
const int GAME_HEIGHT = 20;
const char IniFilename[] = "BLOCKS.INI";

// TBlock is a structure which defines the geometric game piece
//
struct TBlock {
  int  size;          // 2x2, 3x3, or 4x4 (size of square which completely
                      // contains the piece)
  char elements[17];

  void rotate();
};

// Rotate -- rotate the block (only rotates one direction)
//
void TBlock::rotate() {
  int i,j;
  char tempBlock[17];

  switch (size) {
    case 4:
      strcpy(tempBlock,elements);
      for (i=0;i<4;i++)
       for (j=0;j<4;j++)
         tempBlock[i*4+j]=elements[j*4+i];
      strcpy(elements,tempBlock);
      break;

    case 3:
      strcpy(tempBlock,elements);
      for (i=0;i<3;i++)
       for (j=0;j<3;j++)
         tempBlock[(2-i)*4+j]=elements[j*4+i];
      strcpy(elements,tempBlock);
      break;

    case 2:  // no 2x2 blocks can rotate, so do nothing
      break;
  }
}

// Define all the game pieces.

TBlock blocks[7] = { {4, " *  "
                         " *  "
                         " *  "
                         " *  "},
                     {3, " ** "
                         " *  "
                         " *  "
                         "    "},
                     {3, "**  "
                         " *  "
                         " *  "
                         "    "},
                     {3, " *  "
                         "*** "
                         "    "
                         "    "},
                     {3, "**  "
                         " ** "
                         "    "
                         "    "},
                     {3, " ** "
                         "**  "
                         "    "
                         "    "},
                     {2, "**  "
                         "**  "
                         "    "
                         "    "} };

// these define the pens and brushes to be used for the various
// blocks.  each block type is a different color
//

TPen pen[8] = { TPen( TColor( 0, 0, 64 ) ),
                TPen( TColor( 0, 0, 255 ) ),
                TPen( TColor( 0, 255, 0 ) ),
                TPen( TColor( 255, 0, 0 ) ),
                TPen( TColor( 255,255,0 ) ),
                TPen( TColor( 255,0,255 ) ),
                TPen( TColor( 0,255,255 ) ),
                TPen( TColor( 255,255,255 ) ) };

TBrush* brush[8];


// BlocksWindow is the class that actually defines the game.  It is used
// as the client window inside of a TFrameWindow.
//
class TBlocksWindow: public TWindow {

  enum GameState { gsGameOver,         // game over, wait for newgame command
                   gsBlockDropping,    // normal mode, blocks are dropping
                   gsPaused };         // game is paused

  TMemoryDC *memDC;
  GameState gameState;                       // current state of the game
  TBlock    currentBlock;                    // currently falling block
  int       x,y,                             // current block position
            color;                           // current block color
  int       board[GAME_HEIGHT+1][GAME_WIDTH+2];  // the game grid
                                             // edge to make for easier edge detection
  uint      Timer;                           // ID of game timer
  uint      dropCount;                       // countdown to next time piece falls one row

  bool      dropping;                        // is the user holding the 'drop' key down?

  int       gameSpeed,blockSize;             // read from .INI file
public:
  TBlocksWindow( TWindow* parent );
  ~TBlocksWindow() {
    char temp[10];
    wsprintf(temp,"%d",gameSpeed);
    WritePrivateProfileString("blocks","gamespeed",temp,IniFilename);
    wsprintf(temp,"%d",blockSize);
    WritePrivateProfileString("blocks","blocksize",temp,IniFilename);
    delete memDC;
  }
  bool EvEraseBkgnd( HDC ) {    // since we paint the entire window, we
    return TRUE;                // don't want windows doing it for us.
  }                             // this will reduce flicker

  void SetupWindow();
  void CleanupWindow() {
    KillTimer( Timer );
  }
  void Pause();
  void PauseEnabler( TCommandEnabler& tce ) {
    if (gameState==gsGameOver)
      tce.Enable( false );
    else
      if (gameState==gsPaused)
        tce.SetText("Resume\tAlt+P");
      else
        tce.SetText("Pause\tAlt+P");
  }
  void NewGame();
  void ClearBoard();
  void NewBlock( int blockType );
  void RemoveLines();
  void PlaceBlock();
  bool HitTest( TBlock& block, int x, int y );
  void DrawBlock( TDC& dc, TBlock& block, TPoint& pos );
  void Paint( TDC&, bool, TRect& );
  void EvKeyDown( uint key, uint repeatCount, uint flags );
  void EvKeyUp( uint, uint, uint );
  void EvTimer( uint id );


  DECLARE_RESPONSE_TABLE( TBlocksWindow );
};

DEFINE_RESPONSE_TABLE1( TBlocksWindow, TWindow )
  EV_WM_KEYDOWN,
  EV_WM_KEYUP,
  EV_WM_ERASEBKGND,
  EV_WM_TIMER,
  EV_COMMAND( CM_GAMEPAUSE, Pause ),
  EV_COMMAND( CM_GAME_NEW, NewGame ),
  EV_COMMAND_ENABLE( CM_GAMEPAUSE, PauseEnabler ),
END_RESPONSE_TABLE;

// TBlocksWindow -- constructor.  Read the options from the INI file,
// set our game window size, and reset the game board.
//
TBlocksWindow::TBlocksWindow( TWindow* parent )  : TWindow( parent ) {

  blockSize = GetPrivateProfileInt( "blocks","blocksize",20,IniFilename);
  gameSpeed = GetPrivateProfileInt( "blocks","gamespeed",10,IniFilename);

  Attr.W = blockSize*GAME_WIDTH;
  Attr.H = blockSize*GAME_HEIGHT;

  ClearBoard();

  dropCount = 0;
  gameState = gsGameOver;
  dropping = false;
}

// SetupWindow -- after the window is created, we need to do a bit more
// work.  Create a timer to drive the game, and create a memory DC that
// will be used to draw the blocks off-screen.
//
void TBlocksWindow::SetupWindow() {
  TWindow::SetupWindow();

  Timer = 0;
  if (SetTimer( 1, 10 ))
    Timer=1;

  TClientDC dc( HWindow );
  memDC = new TMemoryDC( dc );
  memDC->SelectObject( TBitmap( dc, GAME_WIDTH*blockSize, GAME_HEIGHT*blockSize ) );
}

// RemoveLines -- checks for completed lines and removes them from
// the game board.  If lines are removed, higher lines are moved down
// to fill in the space.
//
void TBlocksWindow::RemoveLines() {
  int i,j,k,l;
  bool lineFull,linesRemoved;

  linesRemoved=false;
  j=GAME_HEIGHT-1;
  while (j>=0) {
    lineFull=true;
    for (i=1;i<=GAME_WIDTH;i++)
      if (board[j][i]==0)
        lineFull=false;
    if (lineFull) {
      linesRemoved=true;
      for (k=j;k>=1;k--)
        for (l=1;l<=GAME_WIDTH;l++)
          board[k][l]=board[k-1][l];
      for (l=1;l<=GAME_WIDTH;l++)
        board[0][l]=0;
    } else
      j--;
  }
  if (linesRemoved) {
//    sndPlaySound( "tada.wav", SND_ASYNC | SND_NODEFAULT );
    Invalidate();
  }
}

// NewGame -- start a new game.  First clear the board, then
// add the first block, and change the game state to gsBlockDropping
//
void TBlocksWindow::NewGame() {
  ClearBoard();
  NewBlock( random(7) );
  gameState = gsBlockDropping;
  Invalidate();
}

// ClearBoard -- resets the game board to be empty
//
void TBlocksWindow::ClearBoard() {
  int i,j;

  for (i=0;i<(GAME_HEIGHT+1);i++)
    for (j=0;j<(GAME_WIDTH+2);j++)
      board[i][j]=0;
  for (i=0;i<(GAME_HEIGHT+1);i++) {
    board[i][0] = -1;
    board[i][GAME_WIDTH+1] = -1;
  }
  for (j=0;j<(GAME_WIDTH+2);j++)
    board[GAME_HEIGHT][j]=-1;
}

// EvTimer -- called by the timer we created in SetupWindow.  Depending
// on the game state, do various things.
//
void TBlocksWindow::EvTimer( uint ) {

  switch (gameState) {
    case gsGameOver:            // no game in progress, do nothing
      break;

    case gsBlockDropping:       // game in progress
      dropCount++;                             // increment drop counter
      if ((dropping) ||
          (dropCount==gameSpeed)) {            // if time to drop
        dropCount=0;                           // reset counter
        y++;                                   // move block down
        if (HitTest( currentBlock, x, y ) ) {  // if it hit something
          y--;                                 // move it back up
          PlaceBlock();                        // make it permanent
          RemoveLines();
          NewBlock( random(7) );
         }
        Invalidate();                          // redraw game board
      }
      break;

    case gsPaused:            // game is paused
      break;
  }
}

// EvKeyUp/EvKeyDown -- respond to key press/release messages.  For the
// 'drop' key, we set a flag whenever the key is held down.  For the
// left/right/rotate keys, we only keep track of keydown events.
//
void TBlocksWindow::EvKeyUp( uint key, uint, uint ) {
  switch (key) {
    case VK_NUMPAD2:
    case VK_DOWN:
      dropping = false;
      break;
  }
}

void TBlocksWindow::EvKeyDown( uint key, uint /*repeat*/, uint /*flags*/ ) {
  if ( gameState == gsPaused ) {
    gameState = gsBlockDropping;
    Invalidate();
    return;
  }
  switch (key) {

    // move block left

    case VK_NUMPAD4:
    case VK_LEFT:
      x--;
      if (HitTest( currentBlock, x, y ))
        x++;
     else
       Invalidate();
     break;

    // move block right

    case VK_NUMPAD6:
    case VK_RIGHT:
      x++;
      if (HitTest( currentBlock, x, y ))
        x--;
      else
        Invalidate();
      break;

    // turn on fast dropping

    case VK_NUMPAD2:
    case VK_DOWN:
      dropping = true;
      break;

    // rotate block

    case VK_UP:
    case VK_NUMPAD5:
    case VK_SPACE:
      currentBlock.rotate();
      if (HitTest( currentBlock, x, y )) {
        currentBlock.rotate();
        currentBlock.rotate();
        currentBlock.rotate();
      }
      Invalidate();
      break;
  }
}

// Pause -- handler for the 'Pause' menu item
//
void TBlocksWindow::Pause() {
  if (gameState==gsBlockDropping)
    gameState=gsPaused;
  else
    if (gameState==gsPaused)
      gameState=gsBlockDropping;
  Invalidate();
}

// HitTest -- tests to see if a block overlaps any occupied square
//            on the board
//
bool TBlocksWindow::HitTest( TBlock& block, int x, int y ) {
  int i,j;
  for (i=0;i<4;i++)
    for (j=0;j<4;j++)
      if ( ((x+i)<(GAME_WIDTH+2)) &&
           ((x+i+1)>=0)  &&
           ((y+j)<(GAME_HEIGHT+1)) &&
           ((y+j)>=0) )             // make sure block in question is in range
        if (board[y+j][x+1+i]!=0)   // if the board piece is empty, skip test
          if (block.elements[j*4+i]=='*')
            return true;
  return false;
}

// NewBlock -- creates a new block at the top of the screen
//
void TBlocksWindow::NewBlock( int blockType ) {
  currentBlock = blocks[ blockType ];
  color = blockType+1;
  x = 4;
  y = 0;
  // if the new block hits anything on the screen, the game is over
  //
  if (HitTest( currentBlock, x, y )) {
    PlaceBlock();
    Invalidate();
    gameState = gsGameOver;
  }
}

// PlaceBlock -- puts the current block permanently into the board array.
//               this function is called when the block reaches the bottom
//               of the game board.
//
void TBlocksWindow::PlaceBlock() {
  int i,j;
  for (i=0;i<4;i++)
    for (j=0;j<4;j++)
      if (currentBlock.elements[j*4+i]=='*')
        board[y+j][x+1+i]=color;

  Invalidate();
  RemoveLines();
}

// DrawBlock -- draws an individual game piece.
//
void TBlocksWindow::DrawBlock( TDC& dc, TBlock& block, TPoint& pos ) {
  int i,j,size=block.size;
  dc.SelectObject( *brush[ color ] );
  dc.SelectObject( pen[ color ] );
  for (i=0;i<size;i++)
    for (j=0;j<size;j++)
      if (block.elements[j*4+i]=='*')
        dc.Rectangle( pos.x*blockSize+i*blockSize,
                      pos.y*blockSize+j*blockSize,
                      pos.x*blockSize+i*blockSize+blockSize,
                      pos.y*blockSize+j*blockSize+blockSize );
}

// Paint -- redraws the entire window.  Currently, whenever anything
// on the game board changes, we redraw the entire board.  This could
// obviously be improved, by only redrawing the area around the moving
// block.
//
void TBlocksWindow::Paint( TDC& dc, bool /*erase*/, TRect& /*rect*/ ) {
  int i,j;

  // if the game is paused, blank the screen (to prevent cheating!)

  if (gameState==gsPaused) {
    memDC->FillRect( GetClientRect(), *brush[0] );
    memDC->SetTextColor( TColor( 0, 255, 255 ) );
    memDC->SetBkColor( TColor( 0, 0, 128 ) );
    memDC->TextOut( blockSize*2,blockSize*9, " * * P A U S E D * * " );
    dc.BitBlt( GetClientRect(), *memDC, TPoint(0,0) );
    return;
  }

  // clear the memory DC

  memDC->FillRect( GetClientRect(), *brush[0] );

  // draw the permanent blocks

  for (j=0;j<GAME_HEIGHT;j++)
    for (i=0;i<GAME_WIDTH;i++)
      if ( board[j][i+1]!=0 ){
        memDC->SelectObject( pen[ board[j][i+1] ] );
        memDC->SelectObject( *brush[ board[j][i+1] ] );
        memDC->Rectangle( i*blockSize,j*blockSize,
                         i*blockSize+blockSize,j*blockSize+blockSize );
      }

  // display the game over message if the game has ended

  if (gameState == gsGameOver) {
    memDC->SetTextColor( TColor( 0, 255, 255 ) );
    memDC->SetBkColor( TColor( 0, 0, 128 ) );
    memDC->TextOut( blockSize*1.5,blockSize*9, "* G A M E   O V E R *");
  }

  // if a block is dropping, draw it

  if (gameState == gsBlockDropping)
    DrawBlock( *memDC, currentBlock, TPoint( x, y ) );

  // now copy the memory DC to the screen.

  dc.BitBlt( GetClientRect(), *memDC, TPoint(0,0) );
}

// TBlocksApp -- the main application.  InitMainWindow creates the
// framewindow, and inserts a TBlocksWindow as the client.  The app
// also responds to the 'Game|Exit' and 'Help|About' menu items.
//
class TBlocksApp: public TApplication {
public:
  void InitMainWindow() {
     TFrameWindow *fw = new TFrameWindow( 0, "Turbo Blocks",
                                          new TBlocksWindow(0), true );
     fw->Attr.Style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
     fw->AssignMenu( MAIN_MENU );
     fw->Attr.AccelTable = ACCELERATORS_1;
     fw->SetIcon( this, ICON_1 );

     SetMainWindow( fw );
  }
  void AboutBox() {
     TDialog( GetMainWindow(), ABOUT_BOX ).Execute();
  }
  void Exit() {
     GetMainWindow()->CloseWindow();
  }
  DECLARE_RESPONSE_TABLE( TBlocksApp );
};
DEFINE_RESPONSE_TABLE1( TBlocksApp, TApplication )
  EV_COMMAND( CM_HELP_ABOUT, AboutBox ),
  EV_COMMAND( CM_GAMEEXIT, Exit ),
END_RESPONSE_TABLE;

// the main program

int OwlMain( int, char *[] ) {

  brush[0] = new TBrush( TColor( 0, 0, 64 ) );
  brush[1] = new TBrush( TColor( 0, 0, 128 ) );
  brush[2] = new TBrush( TColor( 0, 128, 0 ) );
  brush[3] = new TBrush( TColor( 128, 0, 0 ) );
  brush[4] = new TBrush( TColor( 128,128,0 ) );
  brush[5] = new TBrush( TColor( 128,0,128 ) );
  brush[6] = new TBrush( TColor( 0,128,128 ) );
  brush[7] = new TBrush( TColor( 128,128,128 ) );

  randomize();
  int retVal = TBlocksApp().Run();

  for (int i = 0; i < 8 ; i++) {
    delete brush[i];
  }
  return retVal;
}
