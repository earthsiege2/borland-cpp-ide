//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
//   Font demo window header
//----------------------------------------------------------------------------
#if !defined(FONT_H)
#define FONT_H

#include "demobase.h"

// Font demo constants
const int MaxNumFonts = 64; // Maximum number of fonts displayable in FontDemo

class TFontWindow : public TBaseDemoWindow {
  public:
    TFontWindow();
   ~TFontWindow();

  protected:
    void Paint(TDC&, bool, TRect&);
    void EvSize(uint SizeType, TSize& Size);

  private:
    long    FontsHeight;
    long    FontsWidth;

  DECLARE_RESPONSE_TABLE(TFontWindow);
  DECLARE_CASTABLE;
};

#endif  //  FONT_H
