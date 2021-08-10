//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Definition of class TOleDialog, a TDialog that can host OLE controls.
//----------------------------------------------------------------------------
#if !defined(OWL_OLEDIALG_H)
#define OWL_OLEDIALG_H

// Class name of stub control within a dialog which TOleDialog replaces with
// an OCX at runtime. The caption of the control contains the ProgID of the
// OCX to be created by TOleDialog.
//
#if !defined(OCX_STUB_CLASS)
# define OCX_STUB_CLASS "OCX"
#endif

#if !defined(RC_INVOKED)

#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_OLEWINDO_H)
# include <owl/olewindo.h>
#endif

// Check that we're being used for a WIN32 target
//
#if !defined(BI_PLAT_WIN32)
# error OWL/OLEDIALOG.H can be used for WIN32 Targets only.
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
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

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // !RC_INVOKED
#endif  // OWL_OLEDIALG_H
