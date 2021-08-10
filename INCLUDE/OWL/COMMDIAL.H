//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of Common Dialog abstract base class
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

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TCommonDialog
// ~~~~~ ~~~~~~~~~~~~~
class _OWLCLASS TCommonDialog : public TDialog {
  public:
    TCommonDialog(TWindow* parent, const char far* title = 0, TModule* module = 0);
   ~TCommonDialog();

    HWND DoCreate();
    int  DoExecute();

  protected:
    const char far* GetCDTitle() const;

    void SetupWindow();

    // Default behavior inline for message response functions
    //
    void CmOkCancel(); //EV_COMMAND(IDOK or IDCANCEL
    void EvClose();    //EV_CLOSE
    void CmHelp();     //EV_COMMAND(pshHelp,

  protected_data:
    const char far* CDTitle;

  private:
    TCommonDialog(const TCommonDialog&);
    TCommonDialog& operator=(const TCommonDialog&);

  DECLARE_RESPONSE_TABLE(TCommonDialog);
  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_PLAT_WIN16)
  typedef UINT (CALLBACK *LPOFNHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
  typedef UINT (CALLBACK *LPCCHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
  typedef UINT (CALLBACK *LPFRHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
  typedef UINT (CALLBACK *LPCFHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
  typedef UINT (CALLBACK *LPPRINTHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
  typedef UINT (CALLBACK *LPSETUPHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the title from the common dialog.
//
inline const char far* TCommonDialog::GetCDTitle() const
{
  return CDTitle;
}

//
inline void TCommonDialog::CmOkCancel()
{
  DefaultProcessing();
}

//
inline void TCommonDialog::EvClose()
{
  DefaultProcessing();
}

//
inline void TCommonDialog::CmHelp()
{
  DefaultProcessing();
}

#endif  // OWL_COMMDIAL_H
