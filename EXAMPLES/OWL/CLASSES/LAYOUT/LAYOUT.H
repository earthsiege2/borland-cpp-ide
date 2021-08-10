//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#ifndef LAYOUT_H
#define LAYOUT_H

#if !defined(OWL_DECMDIFR_H)
# include <owl/decmdifr.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif
#include "layout.rh"
#include "laydia.h"

//
// class TMyChildWindow
// ~~~~~ ~~~~~~~~~~~~~~
class TMyChildWindow : public TWindow {
  public:
    TMyChildWindow(TWindow* parent, int id, char far* title,
                   TColor color);
};

const int MaxChildren = 5;

//
// class TMyLayout
// ~~~~~ ~~~~~~~~~
class TMyLayout : public TLayoutWindow {
  public:
    TMyLayout(TWindow* parent);

  protected:
    void SetupWindow();

  private:
    void CmLayout();
    void CmReLayout();

  private:
    TChildInfo  ChildInfo[MaxChildren+1];

    TLayoutDialog* LayoutDialog;

  DECLARE_RESPONSE_TABLE(TMyLayout);
};

#endif
