//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\mdichild.h
//   Declaration of class TMDIChild.
//----------------------------------------------------------------------------
#if !defined(__OWL_MDICHILD_H)
#define __OWL_MDICHILD_H

#if !defined(__OWL_FRAMEWIN_H)
  #include <owl\framewin.h>
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
              BOOL            shrinkToClient = FALSE,
              TModule*        module = 0);

    TMDIChild(HWND hWnd, TModule* module = 0);

   ~TMDIChild() {}

    //
    // override virtual methods defined by TWindow
    //
    BOOL       PreProcessMsg(MSG& msg);
    BOOL       ShowWindow(int cmdShow);
    BOOL       EnableWindow(BOOL enable);

  protected:
    void       Destroy(int retVal = 0);
    void       PerformCreate(int menuOrId);
    LRESULT    DefWindowProc(UINT msg, WPARAM wParam, LPARAM lParam);
    void       EvMDIActivate(HWND hWndActivated,
                             HWND hWndDeactivated);
    BOOL       EvNCActivate(BOOL active);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TMDIChild(const TMDIChild&);
    TMDIChild& operator =(const TMDIChild&);

  DECLARE_RESPONSE_TABLE(TMDIChild);
  DECLARE_STREAMABLE(_OWLCLASS, TMDIChild, 1);
};

#endif  // __OWL_MDICHILD_H
