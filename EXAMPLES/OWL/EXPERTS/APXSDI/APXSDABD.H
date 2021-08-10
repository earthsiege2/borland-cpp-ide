//----------------------------------------------------------------------------
//  Project ApxSdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdi Application
//  FILE:         apxsdabd.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxSdiAboutDlg (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(apxsdabd_h)              // Sentry, use file only if it's not already included.
#define apxsdabd_h

#include <owl/static.h>

#include "apxsdapp.rh"                  // Definition of all resources.


//{{TDialog = TApxSdiAboutDlg}}
class TApxSdiAboutDlg : public TDialog {
  public:
    TApxSdiAboutDlg(TWindow* parent, TResId resId = IDD_ABOUT, TModule* module = 0);
    virtual ~TApxSdiAboutDlg();

//{{TApxSdiAboutDlgVIRTUAL_BEGIN}}
  public:
    void SetupWindow();
//{{TApxSdiAboutDlgVIRTUAL_END}}
};    //{{TApxSdiAboutDlg}}


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


#endif  // apxsdabd_h sentry.
