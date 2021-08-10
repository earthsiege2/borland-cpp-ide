//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
//   BitBlt demo window header
//----------------------------------------------------------------------------
#if !defined(BITBLT_H)
#define BITBLT_H

#include "demobase.h"
class _EXPCLASS TBitmap;

// BitBlt demo constants 
const int BackgroundId       = 100; // Bitmap ID of background bitmap 
const int ShipId             = 101; // Bitmap ID of Ship Bitmap 
const int MonoShipId         = 102; // Bitmap ID of Monochrome mask of ship 
const int BitmapSize         = 72;  // Size of Ship bitmap 

class TBitBltWindow : public TBaseDemoWindow {
  public:
    TBitBltWindow();
    ~TBitBltWindow();

  protected:
    void    SetupWindow();
    void    TimerTick();
    void    EvSize(uint SizeType, TSize& Size);
    void    Paint(TDC& dc, bool, TRect&);

  private:
    TPoint      WindowSize;
    TBitmap*    ScratchBitmap;
    TBitmap*    StretchedBkgnd;
    TBitmap*    Background;
    TBitmap*    MonoShip;
    TBitmap*    Ship;
    int         OldX;
    int         OldY;
    int         Delta;
    int         X;
    int         Y;
    int         CurClick;

    void        CalculateNewXY();

  DECLARE_RESPONSE_TABLE(TBitBltWindow);
  DECLARE_CASTABLE;
};

#endif  //  BITBLT_H
