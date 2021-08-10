//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
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

//
//  class TOleMDIFrame
//  ----- ------------
//
//  Decorated MDI frame that supports OLE 2 using OCF
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
    LRESULT    DefWindowProc(uint message, WPARAM wParam, LPARAM lParam);
    bool       EvOcAppInsMenus(TOcMenuDescr far& sharedMenu);
    void       EvActivateApp(bool active, HTASK hTask);

  DECLARE_RESPONSE_TABLE(TOleMDIFrame);
};

#endif  // OWL_OLEMDIFR_H
