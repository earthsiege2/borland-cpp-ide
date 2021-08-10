//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Defines class TBWindow, a BWCC friendly derivation of TWindow
//----------------------------------------------------------------------------
#ifndef __BWINDOW_H
#define __BWINDOW_H

#ifndef __WINDOW_H
  #include <owl\window.h>
#endif

//
//  class TBWindow
//  ----- --------
//
class _EXPCLASS TBWindow : public TWindow {
  public:
    TBWindow(TWindow*        parent,
             const char far* name,
             TModule*        module = 0);

  protected:
    char far* GetClassName();
    void      GetWindowClass(WNDCLASS& wndClass);

  DECLARE_STREAMABLE_FROM_BASE(_EXPCLASS, TBWindow, TWindow);
};

#endif //__BWINDOW_H
