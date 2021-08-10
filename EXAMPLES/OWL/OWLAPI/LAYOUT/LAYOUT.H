//------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//------------------------------------------------------------------------
#ifndef __LAYOUT_H
#define __LAYOUT_H

#ifndef __OWL_DECMDIFR_H
  #include <owl\decmdifr.h>
#endif

#ifndef __OWL_COLOR_H
  #include <owl\color.h>
#endif

#ifndef __LAYOUTRC_H
  #include "layout.rh"
#endif
#ifndef __LAYDIA_H
  #include "laydia.h"
#endif

class TMyChildWindow : public TWindow {
  public:
    TMyChildWindow(TWindow* parent, int id, char far* title,
                   TColor color);
};

const int MaxChildren = 5;

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

    TLayoutDialog *LayoutDialog;

  DECLARE_RESPONSE_TABLE(TMyLayout);
};

#endif
