//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.2  $
//
//----------------------------------------------------------------------------
#if !defined(OWL_OLEMDIFR_H)
#define OWL_OLEMDIFR_H

#if !defined(OWL_OLEFRAME_H)
# include <owl/oleframe.h>
#endif
#if !defined(OWL_MDI_H)
# include <owl/mdi.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TOleMDIFrame
// ~~~~~ ~~~~~~~~~~~~
// Decorated MDI frame that supports OLE 2 using OCF
//
class _USERCLASS TOleMDIFrame : public TOleFrame, public TMDIFrame {
  public:
    TOleMDIFrame(const char far* title,
                 TResId          menuResId,
                 TMDIClient&     clientWnd = *new TMDIClient,
                 bool            trackMenuSelection = false,
                 TModule*        module = 0);

   ~TOleMDIFrame();

  protected:
    TResult    DefWindowProc(uint message, TParam1 param1, TParam2 param2);
    bool       EvOcAppInsMenus(TOcMenuDescr far& sharedMenu);
    void       EvActivateApp(bool active, HTASK hTask);

  DECLARE_RESPONSE_TABLE(TOleMDIFrame);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

typedef TOleMDIFrame TOleMdiFrame;

#endif  // OWL_OLEMDIFR_H
