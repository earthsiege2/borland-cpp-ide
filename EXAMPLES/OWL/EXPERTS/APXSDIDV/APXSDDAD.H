//----------------------------------------------------------------------------
//  Project ApxSdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdiDv Application
//  FILE:         apxsddad.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxSdiDvAboutDlg (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(apxsddad_h)              // Sentry, use file only if it's not already included.
#define apxsddad_h

#include <owl/static.h>

#include "apxsddva.rh"                  // Definition of all resources.


//{{TDialog = TApxSdiDvAboutDlg}}
class TApxSdiDvAboutDlg : public TDialog {
  public:
    TApxSdiDvAboutDlg(TWindow* parent, TResId resId = IDD_ABOUT, TModule* module = 0);
    virtual ~TApxSdiDvAboutDlg();

//{{TApxSdiDvAboutDlgVIRTUAL_BEGIN}}
  public:
    void SetupWindow();
//{{TApxSdiDvAboutDlgVIRTUAL_END}}
};    //{{TApxSdiDvAboutDlg}}


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


#endif  // apxsddad_h sentry.
