//----------------------------------------------------------------------------
//  Project Animals
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    Animals Application
//  FILE:         AnmlsApp.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TAnimalsApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(anmlsapp_h)              // Sentry, use file only if it's not already included.
#define anmlsapp_h

#include <owl/opensave.h>


#include "BeastWin.rh"            // Definition of all resources.


//
// FrameWindow must be derived to override Paint for Preview and Print.
//
//{{TDecoratedFrame = TSDIDecFrame}}
class TSDIDecFrame : public TDecoratedFrame {
  public:
    TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection = false, TModule* module = 0);
    ~TSDIDecFrame();
};    //{{TSDIDecFrame}}


//{{TApplication = TAnimalsApp}}
class TAnimalsApp : public TApplication {
  private:


  public:
    TAnimalsApp();
    virtual ~TAnimalsApp();

//{{TAnimalsAppVIRTUAL_BEGIN}}
  public:
    virtual void InitMainWindow();
//{{TAnimalsAppVIRTUAL_END}}

//{{TAnimalsAppRSP_TBL_BEGIN}}
  protected:
    void CmHelpAbout();
//{{TAnimalsAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TAnimalsApp);
};    //{{TAnimalsApp}}


#endif  // anmlsapp_h sentry.
