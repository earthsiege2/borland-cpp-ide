//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of Common Dialog abstract class
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/commdial.h>
#include <owl/applicat.h>

DEFINE_RESPONSE_TABLE1(TCommonDialog, TDialog)
  EV_WM_CLOSE,
  EV_COMMAND(IDOK, CmOkCancel),
  EV_COMMAND(IDCANCEL, CmOkCancel),
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TCommonDialog);

TCommonDialog::TCommonDialog(TWindow*        parent, 
                             const char far* title,
                             TModule*        module)
:
  TDialog(parent, 0, module),
  CDTitle(title)
{
}

void
TCommonDialog::SetupWindow()
{
  TDialog::SetupWindow();
  if (CDTitle)
    SetCaption(CDTitle);
}
