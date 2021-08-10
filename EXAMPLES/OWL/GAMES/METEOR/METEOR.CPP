//--------------------------------------------------------------------------
//  Turbo Meteor -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#include <owl/owlpch.h>     // all of OWL

#include "sprite.h"
#include "meteor.rh"

const METEOR_COUNT = 8;
const char IniFilename[] = "METEOR.INI";

// MeteorsWindow -- the game window
//
class MeteorWindow: public TWindow {

  uint UseCompatibleBitmap, // settings read from the INI file
       width,height;

  SpriteList sprites;       // list of all the sprites on the screen

  Ship       *ship;         // a seperate pointer to the ship, so we can adjust
                            // it's speed, etc.  the ship is also inserted into
                            // the sprite list

  Message    *scoreDisplay; // pointer to the score object, so we can update it

  TMemoryDC  *gameField;    // this is where the objects draw to, then it is
                            // BitBlt'ed to the window

  bool       rotateLeft,    // flags set when the player presses keys
             rotateRight,
             thrust,
             fire;

  long       score;
  int        shipsLeft;
  int        newShipCountdown;    // countdown to new player ship appearing
  bool       gameOver;

  uint shotDelay,shotDelayReset;  // used to limit how many shots can be fired

public:
  MeteorWindow( TWindow* parent );
  void SetupWindow();
  void CleanupWindow() {
    KillTimer(1);
  }

  // don't let windows paint our window, or it will flicker
  //
  BOOL EvEraseBkgnd( HDC ) {
    return true;
  }
  void Paint( TDC& dc, BOOL erase, TRect& rect );
  void EvTimer( UINT id );
  void EvKeyDown( uint key, uint repeatCount, uint flags );
  void EvKeyUp( uint key, uint repeatCount, uint flags );
  DECLARE_RESPONSE_TABLE( MeteorWindow );
};
DEFINE_RESPONSE_TABLE1( MeteorWindow, TWindow )
  EV_WM_TIMER,
  EV_WM_KEYDOWN,
  EV_WM_KEYUP,
END_RESPONSE_TABLE;

MeteorWindow::MeteorWindow( TWindow* parent ):
  TWindow( parent ) {

  width = GetPrivateProfileInt( "Display", "Width", 600, IniFilename );
  height = GetPrivateProfileInt( "Display", "Height", 400, IniFilename );
  UseCompatibleBitmap = GetPrivateProfileInt( "Display", "UseCompatibleBitmap",
                                              0, IniFilename );

  Attr.W = width;
  Attr.H = height;
  for (int i=0;i<METEOR_COUNT;i++)
    sprites.Add( new Meteor( TPoint( random(width), random(height) ),
										 TSize( random(5)-3, random(5)-3 ),
                               3, 3 ) );
  ship = new Ship( TPoint( width/2, height/2 ) );
  scoreDisplay = new Message(TPoint(5,5),25);
  scoreDisplay->SetText("");
  sprites.Add( ship );
  sprites.Add( scoreDisplay );
  rotateLeft = rotateRight = thrust = fire = false;
}

void MeteorWindow::SetupWindow() {
  TWindow::SetupWindow();

  // create a memory DC that we will copy the sprites to

  gameField = new TMemoryDC( TClientDC( HWindow ) );

  // a memory DC must have a bitmap selected into it before you can
  // draw on it.  A compatible bitmap may be slower on some video modes.

  if (UseCompatibleBitmap)
    gameField->SelectObject( TBitmap( TClientDC( HWindow ), width, height ) );
  else
    gameField->SelectObject( TBitmap( width, height ) );

  // set the pen color to white, and the textbackground color to black

  gameField->SelectObject( TPen( TColor( 255, 255, 255 ) ) );
  gameField->SetBkColor( TColor( 0,0,0 ) );

  // initialize a timer to run the game

  SetTimer( 1, 50 );

  shotDelay = shotDelayReset = 5;

  score=0;
  shipsLeft=4;
  gameOver=false;
  newShipCountdown=0;
}

// EvKeyDown/EvKeyUp -- sets/resets the appropriate flag to indicate that
// the player is holding a key down
//
void MeteorWindow::EvKeyDown( uint key, uint, uint ) {
  switch (key) {
    case VK_LEFT:
      rotateLeft = true;
      break;
    case VK_UP:
      thrust = true;
      break;
    case VK_RIGHT:
      rotateRight = true;
      break;
    case VK_SPACE:
      fire = true;
      break;
  }
}

void MeteorWindow::EvKeyUp( uint key, uint, uint ) {
  switch (key) {
    case VK_LEFT:
      rotateLeft = false;
      break;
    case VK_UP:
      thrust = false;
      break;
    case VK_RIGHT:
      rotateRight = false;
      break;
    case VK_SPACE:
      fire = false;
      shotDelay = 0;
      break;
  }
}

// EvTimer -- this is the heart of the game.  Every timer tick, we update
// all the sprites on the screen, check for collisions, and redraw everything
//
void MeteorWindow::EvTimer( UINT ) {
  char temp[20];
  int points;

  // ExtTextOut is faster than using FillRect

  gameField->ExtTextOut(0,0,ETO_OPAQUE,&GetClientRect(),"",0);

  // draw all the sprites to the memory DC, then update them all

  sprites.DrawAll( *gameField );

  // UpdateAll returns the number of points generated by bullets hitting
  // meteors.  If it returns a negative number, it means the ship was hit

  points = sprites.UpdateAll();

  if (points<0) {  // ship was hit
    ship->Explode();
    ship=0;
    points=0;
    newShipCountdown = 100;
    shipsLeft--;
    if (!shipsLeft)
      gameOver=true;
  }


  // if the ship was destroyed, adjust countdown to new ship

  if (newShipCountdown) {
    newShipCountdown--;
    if (newShipCountdown==0) {
      ship = new Ship( TPoint( width/2, height/2 ) );
      sprites.Add( ship );
    }
  }

  // depending on what keys the user has pressed, adjust the
  // ship position/thrust/etc

  if (ship) {
    if (rotateLeft) ship->Rotate( 15 );
    if (rotateRight) ship->Rotate( -15 );

    if (thrust)
      ship->AddThrust( +1 );
    else
      ship->AddThrust( -1 );

    // if the user is holding the spacebar, countdown to the next
    // shot

    if ((fire)&&(!shotDelay)) {
		sprites.Add( ship->CreateNewShot() );
      shotDelay = shotDelayReset;
    }
    if (shotDelay)
      shotDelay--;
  }

  // update the score display

  if (points) {
    score+=points;
    wsprintf(temp,"%8ld",score);
    temp[8]=' ';
    for (int i=0;i<shipsLeft;i++)
      temp[9+i]='*';
    temp[9+shipsLeft]=0;
    scoreDisplay->SetText(temp);
  }

  // bit-blit the memory DC to our windows DC

  TClientDC( HWindow ).BitBlt( GetClientRect(), /*0, 0, width, height,*/
                               *gameField, TPoint(0,0) );
}

// Paint -- in case we ever need to repaint (because another window was
// blocking us, etc), just bitblit the memory DC back to our window.
//
void MeteorWindow::Paint( TDC& dc, BOOL, TRect& ) {
  dc.BitBlt( GetClientRect(), *gameField, TPoint(0,0) );
}

// MeteorApp -- our application
//
class MeteorApp: public TApplication {
public:
  void InitMainWindow() {
    int width,height;
    TFrameWindow *fw = new TFrameWindow( 0, "Turbo Meteors",
													  new MeteorWindow(0), true );

    // to center our window in the middle of the screen, get the screen
    // resolution, and adjust our position accordingly

    width = TScreenDC().GetDeviceCaps( HORZRES );
    height = TScreenDC().GetDeviceCaps( VERTRES );

    fw->Attr.Style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
    fw->Attr.X = (width-600)/2;
    fw->Attr.Y = (height-400)/2-20;
    fw->SetIcon( this, ICON_1 );
    fw->AssignMenu( MENU_1 );
    SetMainWindow( fw );
  }
  void AboutBox() {
	 TDialog( GetMainWindow(), ABOUT_BOX ).Execute();
  }
  void Exit() {
	 GetMainWindow()->CloseWindow();
  }
  DECLARE_RESPONSE_TABLE( MeteorApp );
};
DEFINE_RESPONSE_TABLE1( MeteorApp, TApplication )
  EV_COMMAND( CM_HELPABOUT, AboutBox ),
  EV_COMMAND( CM_GAME_EXIT, Exit ),
END_RESPONSE_TABLE;

// the main program
//
int OwlMain( int, char *[] ) {
  randomize();
  return MeteorApp().Run();
}
