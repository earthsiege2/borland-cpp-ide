// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------

#if !defined(SIMBOR_H)
#define SIMBOR_H

#include <owl/owlcore.h>
#include <owl/listbox.h>
#include <owl/scrollba.h>
#include <owl/static.h>
#include <owl/gdiobjec.h>
#include "SimBor.rh"

//
// class SimBorApplication
// ~~~~~ ~~~~~~~~~~~~~~~~~
class TSimBorApp : public TApplication {
  public:
    TSimBorApp();
   ~TSimBorApp();

    void InitMainWindow();
};

//
// class SimBorWindow
// ~~~~~ ~~~~~~~~~~~~
class TSimBorWindow : public TWindow {
  public:
    TSimBorWindow();
   ~TSimBorWindow();

  protected:
    void CmDialog();

  DECLARE_RESPONSE_TABLE(TSimBorWindow);
};

//
// class TSimulatedBorlandDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~
class TSimulatedBorlandDialog : public TDialog {
  public:
    TSimulatedBorlandDialog(TWindow*, TResId, TModule* = 0);
   ~TSimulatedBorlandDialog();

  protected:
    void EvPaint();
    HBRUSH EvCtlColor(HDC hDC, HWND hWndChild, uint ctlType);

    TBrush* BrDialog;

  DECLARE_RESPONSE_TABLE(TSimulatedBorlandDialog);
};


//
// class TSimBorDialog
// ~~~~~ ~~~~~~~~~~~~~
//  In TSimulatedBorlandDialog-derived classes, do NOT override EvPaint.
//  Also, if you override EvCtlColor, be sure to not trap
//  CTLCOLOR_DIALOG or else the dialog will not look like a
//  Borland dialog.
//
class TSimBorDialog : public TSimulatedBorlandDialog {
  public:
    TSimBorDialog(TWindow*, TResId);
   ~TSimBorDialog();

    void SetupWindow();

  protected:
    HBRUSH EvCtlColor(HDC hDC, HWND hWndChild, uint ctlType);

    TListBox*   ListBox;
    TScrollBar* ScrollBar;
    TStatic*    Static;

    TBrush* BrListBox;
    TBrush* BrScrollBar;
    TBrush* BrStatic;

  DECLARE_RESPONSE_TABLE(TSimBorDialog);
};

#endif // SIMBOR_H


