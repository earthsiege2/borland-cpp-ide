//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#ifndef EDITBAR_H
#define EDITBAR_H

#ifndef OWL_WINDOW_H
# include <owl\window.h>
#endif

class TEditBarWindow : public TWindow {
  public:
    TEditBarWindow(TWindow* parent, const char* title);
    void Paint(TDC& dc, bool erase, TRect& rect);
    void EvLButtonUp(UINT, TPoint&);

    void GetWindowClass(WNDCLASS& WndClass) {
      TWindow::GetWindowClass(WndClass);
      WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
    }
    int GetSelectedItem() {return SelectedItem;}

  private:
    int   SelectedItem;
    TRect EditBarRect;

  DECLARE_RESPONSE_TABLE(TEditBarWindow);
};

#endif  // EDITBAR_H
