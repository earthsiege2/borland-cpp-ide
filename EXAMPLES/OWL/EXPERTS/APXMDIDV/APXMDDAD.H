//----------------------------------------------------------------------------
//  Project ApxMdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdiDv Application
//  FILE:         apxmddad.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiDvAboutDlg (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(apxmddad_h)              // Sentry, use file only if it's not already included.
#define apxmddad_h

#include <owl/static.h>

#include "apxmddva.rh"                  // Definition of all resources.


//{{TDialog = TApxMdiDvAboutDlg}}
class TApxMdiDvAboutDlg : public TDialog {
  public:
    TApxMdiDvAboutDlg(TWindow* parent, TResId resId = IDD_ABOUT, TModule* module = 0);
    virtual ~TApxMdiDvAboutDlg();

//{{TApxMdiDvAboutDlgVIRTUAL_BEGIN}}
  public:
    void SetupWindow();
//{{TApxMdiDvAboutDlgVIRTUAL_END}}
};    //{{TApxMdiDvAboutDlg}}


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


#endif  // apxmddad_h sentry.
