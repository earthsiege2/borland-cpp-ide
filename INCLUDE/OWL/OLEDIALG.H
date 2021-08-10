//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of class TOleDialog, a TDialog that can host OLE controls.
//----------------------------------------------------------------------------
#if !defined(OWL_OLEDIALG_H)
#define OWL_OLEDIALG_H

#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_OLEWINDO_H)
# include <owl/olewindo.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TOleDialog
// ~~~~~ ~~~~~~~~~~
class _USERCLASS TOleDialog : public TOleWindow, public TDialog {
  public:
    TOleDialog(TWindow* parent, TResId resId, TModule* module = 0);
   ~TOleDialog();

    void      SetupWindow();
    bool      IdleAction(long idleCount);
    bool      PreProcessMsg(MSG& msg);

  protected:
    bool      EvOcViewSetSiteRect(TRect far* rect);

  protected:
    HWND      CheckChild(HWND);
    void      LoadControl(HWND hControl);
    void      LoadControl(TString ProgId, TRect position); 

  DECLARE_RESPONSE_TABLE(TOleDialog);
};

//
// class TRegisterOcxWnd
// ~~~~~ ~~~~~~~~~~~~~~~
class _USERCLASS TRegisterOcxWnd {
  public:
    TRegisterOcxWnd(HINSTANCE);
   ~TRegisterOcxWnd();

  protected:
    HINSTANCE HAppInst;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#endif  // OWL_OLEDIALG_H
