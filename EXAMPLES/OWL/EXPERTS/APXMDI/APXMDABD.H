//----------------------------------------------------------------------------
//  Project ApxMdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdi Application
//  FILE:         apxmdabd.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiAboutDlg (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(apxmdabd_h)              // Sentry, use file only if it's not already included.
#define apxmdabd_h

#include <owl/static.h>

#include "apxmdapp.rh"                  // Definition of all resources.


//{{TDialog = TApxMdiAboutDlg}}
class TApxMdiAboutDlg : public TDialog {
  public:
    TApxMdiAboutDlg(TWindow* parent, TResId resId = IDD_ABOUT, TModule* module = 0);
    virtual ~TApxMdiAboutDlg();

//{{TApxMdiAboutDlgVIRTUAL_BEGIN}}
  public:
    void SetupWindow();
//{{TApxMdiAboutDlgVIRTUAL_END}}
};    //{{TApxMdiAboutDlg}}


// Reading the VERSIONINFO resource.
//
class TProjectRCVersion {
  public:
    TProjectRCVersion(TModule* module);
    virtual ~TProjectRCVersion();

    bool GetProductName(LPSTR& prodName);
    bool GetProductVersion(LPSTR& prodVersion);
    bool GetCopyright(LPSTR& copyright);
    bool GetDebug(LPSTR& debug);

  protected:
    uint8 far*  TransBlock;
    void far*   FVData;

  private:
    // Don't allow this object to be copied.
    //
    TProjectRCVersion(const TProjectRCVersion&);
    TProjectRCVersion& operator = (const TProjectRCVersion&);
};


#endif  // apxmdabd_h sentry.
