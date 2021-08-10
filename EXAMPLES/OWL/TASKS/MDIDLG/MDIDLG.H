// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    MdiDlg.h
//
// Date:        27-Apr-95
//
// Description:
// ---------------------------------------------------------------------------
#if !defined(Mdi_Dialog)
#define Mdi_Dialog

#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_CHECKBOX_H)
# include <owl/checkbox.h>
#endif

#include "test.rh"

//
// class TMdiDlgDialog
// ~~~~~ ~~~~~~~~~~~~~~
class TMdiDialog : public TDialog {
  public:
    TMdiDialog(TWindow* parent, TResId resId);
   ~TMdiDialog();

    void SetupWindow();
    void CleanupWindow();

  protected:
    void CeNumber(TCommandEnabler& ce);
    void CeHelp(TCommandEnabler& ce);

  private:
    TEdit* Name;
    TEdit* Phone;
    TEdit* Number;
    TCheckBox* EnableNumber;
    TCheckBox* EnableHelp;

  DECLARE_RESPONSE_TABLE(TMdiDialog);
  DECLARE_HELPCONTEXT(TMdiDialog);
};

#endif

