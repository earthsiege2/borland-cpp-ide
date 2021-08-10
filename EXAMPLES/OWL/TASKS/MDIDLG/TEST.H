//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    Test.h
//
// Date:        27-Apr-95
//
// Description:
//----------------------------------------------------------------------------
#if !defined(Test_H)
#define Test_H

#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_MDI_H)
# include <owl/mdi.h>
#endif
#if !defined(OWL_MDICHILD_H)
# include <owl/mdichild.h>
#endif
#if !defined(OWL_HLPMANAG_H)
# include <owl/hlpmanag.h>
#endif
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif

#include "Test.rh"
#include "helpids.hh"

//
// class TTestApplication
// ~~~~~ ~~~~~~~~~~~~~~~~
class TTestApp : public TApplication, public THelpFileManager {
  public:
    TTestApp(const char far* name = 0);
   ~TTestApp();

    void InitMainWindow();
    void CmAbout();

  DECLARE_RESPONSE_TABLE(TTestApp);
};


//
// class TAboutDialog
// ~~~~~ ~~~~~~~~~~~~
class TAboutDialog : public TDialog {
  public:
    TAboutDialog(TWindow* parent, TResId resId);

    void SetupWindow();
    void CleanupWindow();

  DECLARE_HELPCONTEXT(TAboutDialog);
};


//
// class TTestClient
// ~~~~~ ~~~~~~~~~~~
class TTestClient : public TMDIClient {
  public:
    TTestClient(TModule* module = 0);
   ~TTestClient();

    void SetupWindow();
    void CleanupWindow();

  protected:
    void CmCreateChild();

  DECLARE_RESPONSE_TABLE(TTestClient);
  DECLARE_HELPCONTEXT(TTestClient);
};


//
// class TTestWindow
// ~~~~~ ~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow(TWindow* parent, const char far* title = 0, TModule* module = 0);
   ~TTestWindow();

    void SetupWindow();
    void CleanupWindow();

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

#endif


