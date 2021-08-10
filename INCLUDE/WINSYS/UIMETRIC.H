//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// Definition of TUIMetric, a UI metrics provider class
//----------------------------------------------------------------------------
#if !defined(WINSYS_UIMETRIC_H)
#define WINSYS_UIMETRIC_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if !defined(WINSYS_WSYSINC_H)
# include <winsys/wsysinc.h>
#endif

//
// class TUIMetric
// ~~~~~ ~~~~~~~~~~
class _WSYSCLASS TUIMetric {
  public:
    static const TUIMetric CxScreen;
    static const TUIMetric CyScreen;
    static const TUIMetric CxVScroll;
    static const TUIMetric CyHScroll;
    static const TUIMetric CyCaption;
    static const TUIMetric CxBorder;
    static const TUIMetric CyBorder;
    static const TUIMetric CxFixedFrame;
    static const TUIMetric CyFixedFrame;
    static const TUIMetric CyVThumb;
    static const TUIMetric CxHThumb;
    static const TUIMetric CxIcon;
    static const TUIMetric CyIcon;
    static const TUIMetric CxCursor;
    static const TUIMetric CyCursor;
    static const TUIMetric CyMenu;
    static const TUIMetric CxFullScreen;
    static const TUIMetric CyFullScreen;
    static const TUIMetric CyKanjiWindow;
    static const TUIMetric MousePresent;
    static const TUIMetric CyVScroll;
    static const TUIMetric CxHScroll;
    static const TUIMetric Debug;
    static const TUIMetric SwapButton;
    static const TUIMetric Reserved1;
    static const TUIMetric Reserved2;
    static const TUIMetric Reserved3;
    static const TUIMetric Reserved4;
    static const TUIMetric CxMin;
    static const TUIMetric CyMin;
    static const TUIMetric CxSize;
    static const TUIMetric CySize;
    static const TUIMetric CxSizeFrame;
    static const TUIMetric CySizeFrame;
    static const TUIMetric CxMinTrack;
    static const TUIMetric CyMinTrack;
    static const TUIMetric CxDoubleClk;
    static const TUIMetric CyDoubleClk;
    static const TUIMetric CxIconSpacing;
    static const TUIMetric CyIconSpacing;
    static const TUIMetric MenuDropAlignment;
    static const TUIMetric PenWindows;
    static const TUIMetric DbcsEnabled;
    static const TUIMetric CMouseButtons;
    static const TUIMetric Secure;
    static const TUIMetric CxEdge;
    static const TUIMetric CyEdge;
    static const TUIMetric CxMinSpacing;
    static const TUIMetric CyMinSpacing;
    static const TUIMetric CxSmIcon;
    static const TUIMetric CySmIcon;
    static const TUIMetric CySmCaption;
    static const TUIMetric CxSmSize;
    static const TUIMetric CySmSize;
    static const TUIMetric CxMenuSize;
    static const TUIMetric CyMenuSize;
    static const TUIMetric Arrange;
    static const TUIMetric CxMinimized;
    static const TUIMetric CyMinimized;
    static const TUIMetric CxMaxTrack;
    static const TUIMetric CyMaxTrack;
    static const TUIMetric CxMaximized;
    static const TUIMetric CyMaximized;
    static const TUIMetric ShowSounds;
    static const TUIMetric KeyboardPref;
    static const TUIMetric HighContrast;
    static const TUIMetric ScreenReader;
    static const TUIMetric CleanBoot;
    static const TUIMetric CxDrag;
    static const TUIMetric CyDrag;
    static const TUIMetric Network;
    static const TUIMetric CxMenuCheck;
    static const TUIMetric CyMenuCheck;
    static const TUIMetric SlowMachine;
    static const TUIMetric MideastEnabled;

    static const TUIMetric CxPixelsPerInch;
    static const TUIMetric CyPixelsPerInch;

    TUIMetric(int i);

    operator int() const;

    int Get() const;
    static int Get(int i);

  private:
    int I;
};

//
inline TUIMetric::TUIMetric(int i)
:
  I(i)
{
}

//
inline TUIMetric::operator int() const {
  return Get();
}

//
inline int TUIMetric::Get() const {
  return Get(I);
}

//
inline int TUIMetric::Get(int i) {
  return ::GetSystemMetrics(i);
}

#endif  // WINSYS_UIMETRIC_H
