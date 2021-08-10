//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Declaration of class TMDIChild.
//----------------------------------------------------------------------------
#if !defined(OWL_MDICHILD_H)
#define OWL_MDICHILD_H

#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif

class _OWLCLASS TMDIClient;

//
//  class TMDIChild
//  ----- ---------
//
class _OWLCLASS TMDIChild : virtual public TFrameWindow {
  public:
    TMDIChild(TMDIClient&     parent,
              const char far* title = 0,
              TWindow*        clientWnd = 0,
              bool            shrinkToClient = false,
              TModule*        module = 0);

    TMDIChild(HWND hWnd, TModule* module = 0);

   ~TMDIChild() {}

    //
    // override virtual methods defined by TWindow
    //
    bool       PreProcessMsg(MSG& msg);
    bool       ShowWindow(int cmdShow);
    bool       EnableWindow(bool enable);
    void       Destroy(int retVal = 0);

  protected:
    void       PerformCreate(int menuOrId);
    LRESULT    DefWindowProc(uint msg, WPARAM wParam, LPARAM lParam);
    void       EvMDIActivate(HWND hWndActivated,
                             HWND hWndDeactivated);
    bool       EvNCActivate(bool active);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TMDIChild(const TMDIChild&);
    TMDIChild& operator =(const TMDIChild&);

  DECLARE_RESPONSE_TABLE(TMDIChild);
  DECLARE_STREAMABLE(_OWLCLASS, TMDIChild, 1);
};

#endif  // OWL_MDICHILD_H
