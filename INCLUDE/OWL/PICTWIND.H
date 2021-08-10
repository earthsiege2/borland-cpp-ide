//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of class TPictureWindow
//----------------------------------------------------------------------------
#if !defined(OWL_PICTWIND_H)
#define OWL_PICTWIND_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>


class _OWLCLASS TDib;

//
// class TPictureWindow
// ~~~~~ ~~~~~~~~~~~~~~
// This class displays a dib in a window in different ways.
// The dib is owned by the window and will be deleted when the window is
// deleted.
//
class _OWLCLASS TPictureWindow : public TWindow {
  public:

    // How to display the bitmap within the window
    //
    enum TDisplayHow {
      UpperLeft = 0,      // Upper left corner
      Center,             // Always centered
      Stretch,            // Stretch to fit or shrink to fit
      // Scroll,             // implies Upperleft  
    };

    // constructor and destructor
    //
    TPictureWindow(TWindow* parent, TDib* dib, TDisplayHow = UpperLeft,
               const char far* title = 0, TModule* module = 0);
   ~TPictureWindow();

    // Use new dib and return old dib
    //
    TDib*       SetDib(TDib* newDib);
    TDib*       GetDib() const;

    void        SetHowToDisplay(TDisplayHow how);
    TDisplayHow GetHowToDisplay() const;

    // overridden from TWindow for CS_HREDRAW and CS_VREDRAW
    //
    char far* GetClassName();
    void      GetWindowClass(WNDCLASS& wndClass);

  protected:
    void Paint(TDC& dc, bool erase, TRect& rect);

  private:
    TDib* Dib;
    TDisplayHow HowToDisplay;
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the dib.
//
inline TDib*
TPictureWindow::GetDib() const
{
  return Dib;
}

//
// Return how the picture is displayed.
//
inline TPictureWindow::TDisplayHow
TPictureWindow::GetHowToDisplay() const
{
  return HowToDisplay;
}


#endif  // OWL_PICTWIND_H
