//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of Common Dialog abstract base class
//----------------------------------------------------------------------------
#if !defined(OWL_COMMDIAL_H)
#define OWL_COMMDIAL_H

#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(__COMMDLG_H)
# include <commdlg.h>
#endif
#if !defined(__CDERR_H)
# include <cderr.h>
#endif

class _OWLCLASS TCommonDialog : public TDialog {
  public:
    TCommonDialog(TWindow* parent, const char far* title = 0, TModule* module = 0);

    HWND DoCreate() {return 0;}
    int  DoExecute() {return IDCANCEL;}

  protected:
    const char far* CDTitle;

    void    SetupWindow();

    // Default behavior inline for message response functions
    //
    void CmOkCancel() {DefaultProcessing();} //EV_COMMAND(IDOK or IDCANCEL
    void EvClose() {DefaultProcessing();}    //EV_CLOSE
    void CmHelp() {DefaultProcessing();}     //EV_COMMAND(pshHelp,

  private:
    TCommonDialog(const TCommonDialog&);
    TCommonDialog& operator=(const TCommonDialog&);

  DECLARE_RESPONSE_TABLE(TCommonDialog);
  DECLARE_CASTABLE;
};

//
// Used internally by common dialogs
//
extern TProcInstance StdDlgProcInstance;

#endif  // OWL_COMMDIAL_H
