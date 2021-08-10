//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(OWL_CLIPVIEW_H)
#define OWL_CLIPVIEW_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif

//
//  class TClipboardViewer
//  ----- ----------------
//
//  Mix-in class that registers as a clipboard viewer when the user interface
//  element is created and removes itself from the clipboard-viewer chain when
//  it is destroyed
//
class _OWLCLASS TClipboardViewer : virtual public TWindow {
  protected:
    TClipboardViewer();
    TClipboardViewer(HWND hWnd, TModule* module = 0);

    TEventStatus DoChangeCBChain(HWND hWndRemoved, HWND hWndNext);
    TEventStatus DoDestroy();
    TEventStatus DoDrawClipboard();  // pass to next window in clipboard-viewer chain

  protected:
    HWND  HWndNext;  // next window in clipboard-viewer chain

    //
    // override method defined by TWindow
    //
    void   SetupWindow();

    //
    // message response functions
    //
    void   EvChangeCBChain(HWND hWndRemoved, HWND hWndNext);
    void   EvDestroy();
    void   EvDrawClipboard();  // pass to next window in clipboard-viewer chain

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TClipboardViewer(const TClipboardViewer&);
    TClipboardViewer& operator =(const TClipboardViewer&);

  DECLARE_RESPONSE_TABLE(TClipboardViewer);
  DECLARE_CASTABLE;
};

#endif  // OWL_CLIPVIEW_H
