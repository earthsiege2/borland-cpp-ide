//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.2  $
//
// Definition of class TMDIChild.
//----------------------------------------------------------------------------
#if !defined(OWL_MDICHILD_H)
#define OWL_MDICHILD_H

#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>


class _OWLCLASS TMDIClient;

//
// class TMDIChild
// ~~~~~ ~~~~~~~~~
class _OWLCLASS TMDIChild : virtual public TFrameWindow {
  public:
    TMDIChild(TMDIClient&     parent,
              const char far* title = 0,
              TWindow*        clientWnd = 0,
              bool            shrinkToClient = false,
              TModule*        module = 0);

    TMDIChild(HWND hWnd, TModule* module = 0);

   ~TMDIChild();

    // Override virtual methods defined by TWindow
    //
    bool       PreProcessMsg(MSG& msg);
    bool       ShowWindow(int cmdShow);
    bool       EnableWindow(bool enable);
    void       Destroy(int retVal = 0);

  protected:
    void       PerformCreate(int menuOrId);
    TResult    DefWindowProc(uint msg, TParam1 param1, TParam2 param2);
    void       EvMDIActivate(HWND hWndActivated, HWND hWndDeactivated);
    bool       EvNCActivate(bool active);

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TMDIChild(const TMDIChild&);
    TMDIChild& operator =(const TMDIChild&);

  DECLARE_RESPONSE_TABLE(TMDIChild);
  DECLARE_STREAMABLE(_OWLCLASS, TMDIChild, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

typedef TMDIChild TMdiChild;

#endif  // OWL_MDICHILD_H
