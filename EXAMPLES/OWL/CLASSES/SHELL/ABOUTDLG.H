//----------------------------------------------------------------------------
//  Project Shell
//  Borland International
//  Copyright © 1995, 1996 Borland International. All Rights Reserved.
//
//  SUBSYSTEM:    shell.exe Application
//  FILE:         aboutdlg.h
//  AUTHOR:       The OWL Team
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TShellAboutDlg (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(aboutdlg_h)              // Sentry, use file only if it's not already included.
#define aboutdlg_h

#include <owl\dialog.h>;
#include "shellapp.rh"                  // Definition of all resources.


//{{TDialog = TShellAboutDlg}}
class TShellAboutDlg : public TDialog {
  public:
    TShellAboutDlg(TWindow* parent, TResId resId = IDD_ABOUT, TModule* module = 0);
    virtual ~TShellAboutDlg();

//{{ShellAboutDlgVIRTUAL_BEGIN}}
  public:
    void SetupWindow();
//{{ShellAboutDlgVIRTUAL_END}}
};    //{{TShellAboutDlg}}


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


#endif  // aboutdlg_h sentry.
