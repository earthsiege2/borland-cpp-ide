//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Font demo window header
//----------------------------------------------------------------------------
#ifndef __FONT_H
#define __FONT_H

#include "demobase.h"

// Font demo constants
const int MaxNumFonts = 64; // Maximum number of fonts displayable in FontDemo

class TFontWindow : public TBaseDemoWindow {
  public:
    TFontWindow();
   ~TFontWindow();

  protected:
    void Paint(TDC&, BOOL, TRect&);
    void EvSize(UINT SizeType, TSize& Size);

  private:
    long    FontsHeight;
    long    FontsWidth;

  DECLARE_RESPONSE_TABLE(TFontWindow);
  DECLARE_CASTABLE;
};

#endif
