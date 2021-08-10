//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of Common Dialog abstract base class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

//
// Diagnostic group for Common Dialog
//
OWL_DIAGINFO;
DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlCommDialog, 1, 0);

DEFINE_RESPONSE_TABLE1(TCommonDialog, TDialog)
  EV_WM_CLOSE,
  EV_COMMAND(IDOK, CmOkCancel),
  EV_COMMAND(IDCANCEL, CmOkCancel),
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TCommonDialog);

//
//
//
TCommonDialog::TCommonDialog(TWindow*        parent,
                             const char far* title,
                             TModule*        module)
:
  TDialog(parent, 0, module),
  CDTitle(title)
{
  TRACEX(OwlCommDialog, OWL_CDLEVEL, "TCommonDialog constructed @" << (void*)this);
}

//
// Generate message in diagnostic libraries.
//
TCommonDialog::~TCommonDialog()
{
  TRACEX(OwlCommDialog, OWL_CDLEVEL, "TCommonDialog destructed @" << (void*)this);
}

//
// Override virtual to set the caption.
//
void
TCommonDialog::SetupWindow()
{
  TRACEX(OwlCommDialog, 1, "TCommonDialog::SetupWindow() @" << (void*)this);

  TDialog::SetupWindow();
  if (CDTitle)
    SetCaption(CDTitle);
}

//
// Default handler for a modeless common dialog.
// Wrong usage if here.
//
HWND TCommonDialog::DoCreate()
{
  TRACEX(OwlCommDialog, 0, "Wrong usage for a modal common dialog. Use Execute() instead.");
  return 0;
}

//
// Default handler for a modal common dialog.
// Wrong usage if here.
//
int TCommonDialog::DoExecute()
{
  TRACEX(OwlCommDialog, 0, "Wrong usage for a modeless common dialog. Use Create() instead.");
  return IDCANCEL;
}

