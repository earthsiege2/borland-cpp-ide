//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    MdiDlg.cpp
//
// Date:        27-Apr-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_VALIDATE_H)
# include <owl/validate.h>
#endif
#include "test.h"
#include "MdiDlg.h"


//
// constructor
//
TMdiDialog::TMdiDialog(TWindow* parent, TResId resId)
:
  TDialog(parent, resId)
{
  Name = new TEdit(this, IDC_NAME);
  Name->SetValidator(new TFilterValidator("A-Za-z. "));
  Phone = new TEdit(this, IDC_PHONE);
  Phone->SetValidator(new TPXPictureValidator("[(###)]###-####", true));
  Number = new TEdit(this, IDC_NUMBER);
  Number->SetValidator(new TRangeValidator(1, 999));
  EnableNumber = new TCheckBox(this, IDC_ENABLENUMBER);
  EnableHelp   = new TCheckBox(this, IDC_ENABLEHELP);
}


//
// destructor
//
TMdiDialog::~TMdiDialog()
{
}


//
// SetupWindow
//
void
TMdiDialog::SetupWindow()
{
  TDialog::SetupWindow();

  // put new stuff here
  //
  SETUP_HELPCONTEXT(TTestApp, TMdiDialog);
}


//
// CleanupWindow
//
void
TMdiDialog::CleanupWindow()
{
  // put new stuff here
  //
  CLEANUP_HELPCONTEXT(TTestApp, TMdiDialog);

  TDialog::CleanupWindow();
}

//
// Response table
//
DEFINE_RESPONSE_TABLE1(TMdiDialog, TDialog)
  EV_COMMAND_ENABLE(IDC_NUMBER, CeNumber),
  EV_COMMAND_ENABLE(IDHELP, CeHelp),
END_RESPONSE_TABLE;


DEFINE_HELPCONTEXT(TMdiDialog)
  HCENTRY_CONTROL(IDH_DLG_IDC_NAME,   IDC_NAME),
  HCENTRY_CONTROL(IDH_DLG_IDC_PHONE,  IDC_PHONE),
  HCENTRY_CONTROL(IDH_DLG_IDC_NUMBER, IDC_NUMBER),
  HCENTRY_CONTROL(IDH_DLG_IDOK,       IDOK),
  HCENTRY_CONTROL(IDH_DLG_IDCANCEL,   IDCANCEL),
  HCENTRY_CONTROL(IDH_DLG_IDHELP,     IDHELP),
END_HELPCONTEXT;


//
//
//
void
TMdiDialog::CeNumber(TCommandEnabler& ce)
{
  ce.Enable(EnableNumber->GetCheck() == BF_CHECKED ? true : false);
}


//
//
//
void
TMdiDialog::CeHelp(TCommandEnabler& ce)
{
  ce.Enable(ToBool(EnableHelp->GetCheck() == BF_CHECKED));
}


