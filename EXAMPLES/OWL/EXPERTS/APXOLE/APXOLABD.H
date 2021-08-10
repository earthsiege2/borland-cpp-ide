//----------------------------------------------------------------------------
//  Project ApxOle
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxOle Application
//  FILE:         apxolabd.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxOleAboutDlg (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(apxolabd_h)              // Sentry, use file only if it's not already included.
#define apxolabd_h

#include <owl/static.h>

#include "apxolapp.rh"                  // Definition of all resources.


//{{TDialog = TApxOleAboutDlg}}
class TApxOleAboutDlg : public TDialog {
  public:
    TApxOleAboutDlg(TWindow* parent, TResId resId = IDD_ABOUT, TModule* module = 0);
    virtual ~TApxOleAboutDlg();

//{{TApxOleAboutDlgVIRTUAL_BEGIN}}
  public:
    void SetupWindow();
//{{TApxOleAboutDlgVIRTUAL_END}}
};    //{{TApxOleAboutDlg}}


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


#endif  // apxolabd_h sentry.
