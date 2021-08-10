//--------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All rights Reserved
//
// TDiBitmap example program.
//--------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dibitmap.h>
#include "dibitmap.rh"

const int RandomMax = 10;
const int AbsoluteDelta = 6;
#if defined(BI_PLAT_WIN16)
const int NumOfBalls = 1;
#else
const int NumOfBalls = 16;
#endif

enum TBltType {
  BCopy,         // Blast whole bitmap up & hope it erases its trail
  BSprite,       // Sprite blt the bitmaps & leave a trail
  BSpriteEraseP, // Sprite blt the bitmaps on a PatBlt cleared dbl buffer
  BSpriteEraseM, // Sprite blt the bitmaps on a memset cleared dbl buffer
};

//
// class TSpeedBall
// ~~~~~ ~~~~~~~~~~
class TSpeedBall {
  public:
    // Variables for tracking speed ball position, limit and delta.
    //
    int XLimit;
    int YLimit;
    int XDelta;
    int YDelta;
    int XPos;
    int YPos;
    TDiBitmap*  Bitmap;

    operator TRect() {return TRect(XPos,YPos,XPos+Bitmap->Width(),YPos+Bitmap->Height());}

    void Move();
    void CopyBlt(TDiBitmap& dstBm);
    void SpriteBlt(TDiBitmap& dstBm);
    void Clear(TDC& dc);
};

void TSpeedBall::Move()
{
  XPos += XDelta;
  YPos += YDelta;

  if (XPos > XLimit) {
    XPos = XLimit;
    XDelta = -XDelta; //(random(RandomMax) + AbsoluteDelta);
  }
  else if (XPos < 0) {
    XPos = 0;
    XDelta = -XDelta; //random(RandomMax) + AbsoluteDelta;
  }

  if (YPos > YLimit) {
    YPos = YLimit;
    YDelta = -YDelta; //(random(RandomMax) + AbsoluteDelta);
  }
  else if (YPos < 0) {
    YPos = 0;
    YDelta = -YDelta; //random(RandomMax) + AbsoluteDelta;
  }
}

void TSpeedBall::CopyBlt(TDiBitmap& dstBm)
{
  dstBm.CopyBlt(XPos, YPos, *Bitmap, 0, 0);
}

void TSpeedBall::SpriteBlt(TDiBitmap& dstBm)
{
  dstBm.SpriteBlt(XPos, YPos, *Bitmap, 0, 0);
}

void TSpeedBall::Clear(TDC& dc)
{
  dc.PatBlt(XPos, YPos, Bitmap->Width(), Bitmap->Height(), BLACKNESS);
}

//--------------------------------------------------------------------------

//
// class TSpeedCourt
// ~~~~~ ~~~~~~~~~~~
class TSpeedCourt {
  public:
    TSpeedCourt(const TDib& ballDib, int numBalls = 16);
   ~TSpeedCourt();

    void Update(TDC& dc);
    void Refresh(TDC& dc);
    void Resize(TSize& newSize);

  private:
  public:
    // Speed balls
    //
    TSpeedBall*  Balls;
    int          BallCount;

    // State variable for blitting style
    //
    TBltType       BltType;
    TPalette*      Palette;
    TDibDC*        DisplayDC;
    TDiBitmap*     DisplayBitmap;
//    TDiBitmap*     BkgndBitmap;
};

//
//
//
TSpeedCourt::TSpeedCourt(const TDib& ballDib, int numBalls)
:
  BallCount(numBalls), Balls(0), Palette(0), DisplayDC(0), DisplayBitmap(0)
{
/*
  BkgndBitmap = new TDiBitmap(_hInstance, TResId(IDB_BKGND));
  {
    TScreenDC dc;
    TDibDC    ddc;
    ddc.SelectObject(*BkgndBitmap);
    ddc.BitBltToScreen(dc, 0,0,800,600);
  }
*/
  try {
    Palette  = new TPalette(ballDib);
    DisplayDC = new TDibDC;

    Balls = new TSpeedBall[BallCount];

    BltType = BCopy;
    for (int i = 0; i < BallCount; i++)
      Balls[i].Bitmap = 0;

    TDibDC ballDC;
    for (int i = 0; i < BallCount; i++) {
      Balls[i].Bitmap = new TDiBitmap(ballDib);
      ballDC.SelectObject(*Balls[i].Bitmap);
      ballDC.StretchDIBits(TRect(0, 0, Balls[i].Bitmap->Width(), Balls[i].Bitmap->Height()),
                            TRect(0, 0, Balls[i].Bitmap->Width(), Balls[i].Bitmap->Height()),
                            ballDib);
      Balls[i].XPos = 0;
      Balls[i].YPos = 0;
      Balls[i].XDelta = random(RandomMax) + AbsoluteDelta;
      Balls[i].YDelta = random(RandomMax) + AbsoluteDelta;
    }
  }
  catch (...) {
    throw;
  }
}

//
//
//
TSpeedCourt::~TSpeedCourt()
{
  delete Palette;
  delete DisplayDC;
  delete DisplayBitmap;
//  delete BkgndBitmap;

  if (Balls) {
    for (int i = 0; i < BallCount; i++)
      delete Balls[i].Bitmap;
    delete[] Balls;
  }
}

//
//
//
void TSpeedCourt::Update(TDC& dc)
{
  if (DisplayBitmap) {
//    DisplayDC->SelectPalette(*Palette);
//    DisplayDC->RealizePalette();
//    dc.SelectPalette(*Palette);
//    dc.RealizePalette();

    // Just blacken (zero) the bits ourselves
    //
    if (BltType == BSpriteEraseM) {
      memset(DisplayBitmap->GetBits(), 0, DisplayBitmap->Pitch()*DisplayBitmap->Height());
    }

    TRect dirty;
    dirty.SetNull();

    // Do a first pass over old positions building a dirty rect & erasing each
    // for BSpriteEraseP
    //
    if (BltType == BSpriteEraseP) {
//      TDibDC ddc;
//      ddc.SelectObject(*BkgndBitmap);
      for (int i = 0; i < BallCount; i++) {
        TSpeedBall& b(Balls[i]);
        b.Clear(*DisplayDC);  // Use GDI to clear just this rect
//        DisplayBitmap->CopyBlt(b.XPos, b.YPos, *BkgndBitmap,
//                               b.Bitmap->Width(), b.Bitmap->Height());
//        DisplayDC->BitBlt(b.XPos, b.YPos, b.Bitmap->Width(), b.Bitmap->Height(),
//                          ddc, b.XPos, b.YPos);
      }
    }
#if defined(BI_PLAT_WIN32)
    ::GdiFlush();  // Must flush GDI between GDI and Dib work
#endif

    // Do a second pass moving to new positions, building a dirty rect &
    // painting
    //
    for (int i = 0; i < BallCount; i++) {
      TSpeedBall& b(Balls[i]);
      dirty |= b;  // Old position
      b.Move();
      dirty |= b;  // New position

      if (BltType == BCopy) {
        b.CopyBlt(*DisplayBitmap);
      }
      else {  // BSprite or BSpriteEraseP or BSpriteEraseM
        b.SpriteBlt(*DisplayBitmap);
      }
    }
#if defined(BI_PLAT_WIN32)
    ::GdiFlush();  // Must flush GDI between GDI and Dib work
#endif
    DisplayDC->BitBltToScreen(dc, dirty.X(), dirty.Y(), dirty.Width(), dirty.Height(), dirty.X(), dirty.Y());
  }
}

//
//
//
void TSpeedCourt::Refresh(TDC& dc)
{
  dc.SelectObject(*Palette);
  dc.RealizePalette();
  DisplayDC->BitBltToScreen(dc, 0, 0,
                            DisplayBitmap->Width(), DisplayBitmap->Height());
}

//
//
//
void TSpeedCourt::Resize(TSize& newSize)
{
  if (DisplayDC && newSize.cx && newSize.cy) {
    delete DisplayBitmap;
    DisplayBitmap = new TDiBitmap(newSize.cx, newSize.cy, 256);
    DisplayDC->SelectObject(*DisplayBitmap);

    DisplayDC->SetDIBColorTable(0, Balls[0].Bitmap->NumColors(),
                                Balls[0].Bitmap->GetColors());

//    DisplayBitmap->CopyBlt(0, 0, *BkgndBitmap);
    DisplayDC->PatBlt(0, 0, newSize.cx, newSize.cy, BLACKNESS);

    for (int i = 0; i < BallCount; i++) {
      Balls[i].XLimit = newSize.cx - Balls[i].Bitmap->Width();
      Balls[i].YLimit = newSize.cy - Balls[i].Bitmap->Height();
    }
  }
}

//--------------------------------------------------------------------------

//
// class TSpeedBallWindow
// ~~~~~ ~~~~~~~~~~~~~~~~
class _USERCLASS TSpeedBallWindow : public TWindow {
  public:
    // Constructors
    //
    TSpeedBallWindow(TWindow* parent);

    // Overides
    //
    void SetupWindow();
    void CleanupWindow();

    bool IdleAction(long);
    void Paint(TDC&, bool, TRect&);

    // Event Handlers
    //
    void EvPaletteChanged(HWND hWndPalChg);
    bool EvQueryNewPalette();
    void EvSize(uint, TSize&);

    void CmBlitterBlocks();
    void CeBlitterBlocks(TCommandEnabler&);
    void CmBlitterSprites();
    void CeBlitterSprites(TCommandEnabler&);
    void CmBlitterSpritesEP();
    void CeBlitterSpritesEP(TCommandEnabler&);
    void CmBlitterSpritesEM();
    void CeBlitterSpritesEM(TCommandEnabler&);

  private:
    TSpeedCourt Court;
    TClientDC*  ClientDC;

  DECLARE_RESPONSE_TABLE(TSpeedBallWindow);
};

DEFINE_RESPONSE_TABLE1(TSpeedBallWindow,TWindow)
  EV_COMMAND       (CM_BLOCKS, CmBlitterBlocks),
  EV_COMMAND_ENABLE(CM_BLOCKS, CeBlitterBlocks),
  EV_COMMAND       (CM_SPRITES, CmBlitterSprites),
  EV_COMMAND_ENABLE(CM_SPRITES, CeBlitterSprites),
  EV_COMMAND       (CM_SPRITESEP, CmBlitterSpritesEP),
  EV_COMMAND_ENABLE(CM_SPRITESEP, CeBlitterSpritesEP),
  EV_COMMAND       (CM_SPRITESEM, CmBlitterSpritesEM),
  EV_COMMAND_ENABLE(CM_SPRITESEM, CeBlitterSpritesEM),
  EV_WM_SIZE,
  EV_WM_QUERYNEWPALETTE,
  EV_WM_PALETTECHANGED,
END_RESPONSE_TABLE;

//
// TSpeedBallWindow Contructor.  Initializes variables.
//
TSpeedBallWindow::TSpeedBallWindow(TWindow* parent)
:
  TWindow(parent, 0),
  ClientDC(0),
  Court(TDib(GetApplication()->GetInstance(), TResId(IDB_BALL)), NumOfBalls)
{
}

//
// Create a client DC for speed
//
void
TSpeedBallWindow::SetupWindow()
{
  TWindow::SetupWindow();
  ClientDC  = new TClientDC(*this);
}

void
TSpeedBallWindow::CleanupWindow()
{
  delete ClientDC;
  TWindow::CleanupWindow();
}

//
// Activates Palette, then blit's current double buffer.
//
void
TSpeedBallWindow::Paint(TDC& dc, bool, TRect&)
{
  Court.Refresh(dc);
}

//
// When nothing needs to be processed step the image then update the
// display.
//
bool
TSpeedBallWindow::IdleAction(long)
{
  Court.Update(*ClientDC);
  return true;  // Suck up as much time as we can get
}

//
// When the window size changes, resize the court
//
void
TSpeedBallWindow::EvSize(uint, TSize& newSize)
{
  if (ClientDC && newSize.cx && newSize.cy) {
    Court.Resize(newSize);
    Court.Refresh(*ClientDC);
  }
}

//
// Somebody changed the palette. If its not us, then we need to update.
//
void
TSpeedBallWindow::EvPaletteChanged(HWND hWndPalChg)
{
  if (hWndPalChg != GetHandle()) {
    TClientDC clientDC(*this);
#if defined(BI_PLAT_WIN16)
    Court.Palette->UnrealizeObject();
#endif
    clientDC.SelectObject(*Court.Palette, true);
    bool needsUpdate = clientDC.RealizePalette() > 0;
    if (needsUpdate)
      Invalidate(false);
  }
}

//
// Activate palette when told by windows.
//
bool
TSpeedBallWindow::EvQueryNewPalette()
{
  if (ClientDC && Court.Palette) {
    ClientDC->SelectObject(*Court.Palette);
    ClientDC->RealizePalette();
  }

  return true;
}

//
// CM_BLOCKS event response function.
//
void
TSpeedBallWindow::CmBlitterBlocks()
{
  Court.BltType = BCopy;
}

//
//
//
void
TSpeedBallWindow::CeBlitterBlocks(TCommandEnabler& ce)
{
  ce.SetCheck((Court.BltType == BCopy) ? TCommandEnabler::Checked :
                                   TCommandEnabler::Unchecked);
}

//
// CM_SPRITES event response function.
//
void
TSpeedBallWindow::CmBlitterSprites()
{
  Court.BltType = BSprite;
}

//
//
//
void
TSpeedBallWindow::CeBlitterSprites(TCommandEnabler& ce)
{
  ce.SetCheck((Court.BltType == BSprite) ? TCommandEnabler::Checked :
                                     TCommandEnabler::Unchecked);
}

//
// CM_SPRITESE event response function.
//
void
TSpeedBallWindow::CmBlitterSpritesEP()
{
  Court.BltType = BSpriteEraseP;
}

//
//
//
void
TSpeedBallWindow::CeBlitterSpritesEP(TCommandEnabler& ce)
{
  ce.SetCheck((Court.BltType == BSpriteEraseP) ? TCommandEnabler::Checked :
                                          TCommandEnabler::Unchecked);
}

//
// CM_SPRITESEM event response function.
//
void
TSpeedBallWindow::CmBlitterSpritesEM()
{
  Court.BltType = BSpriteEraseM;
}

//
//
//
void
TSpeedBallWindow::CeBlitterSpritesEM(TCommandEnabler& ce)
{
  ce.SetCheck((Court.BltType == BSpriteEraseM) ? TCommandEnabler::Checked :
                                          TCommandEnabler::Unchecked);
}

//--------------------------------------------------------------------------

//
// class TSpeedBallApplication
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~
// Derived TApplication object for setting TSpeedBallWindow
// as the client.
//
class TSpeedBallApplication : public TApplication {
  public:
    TSpeedBallApplication();

    void InitMainWindow();
};

//
// Do nothing constructor.
//
TSpeedBallApplication::TSpeedBallApplication()
{
}

//
// Set the main window to a TSpeedBallWindow object.
// Assign the menu.
//
void
TSpeedBallApplication::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, "TDiBitmap Speed Ball", new TSpeedBallWindow(0)));
  GetMainWindow()->Attr.W = 300;
  GetMainWindow()->Attr.H = 300;
  GetMainWindow()->AssignMenu(IDM_MENU);
  GetMainWindow()->SetIcon(this, IDI_ICON);
}

//
// Create and run the TSpeedBallApplication object.
//
int
OwlMain(int /*argc*/, char* /*argv*/[])
{
#if defined(BI_PLAT_WIN16)
  if (!TWinG::IsAvailable())
    throw TXOwl("WinG is not available");
#endif
  return TSpeedBallApplication().Run();
}
