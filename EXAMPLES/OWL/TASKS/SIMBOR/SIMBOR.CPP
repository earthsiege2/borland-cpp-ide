// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#include "SimBor.h"

//
// SimBorWindow constructor
//
TSimBorWindow::TSimBorWindow()
:
  TWindow(0, 0, 0)
{
}

//
// SimBorWindow destructor
//
TSimBorWindow::~TSimBorWindow()
{
}

//
// Response table for SimBorWindow
//
DEFINE_RESPONSE_TABLE1(TSimBorWindow, TWindow)
  EV_COMMAND(CM_DIALOG, CmDialog),
END_RESPONSE_TABLE;


//
// CmDialog
//
void
TSimBorWindow::CmDialog()
{
  TSimBorDialog simBorDlg(this, IDD_SIMBORDLG);
  simBorDlg.Execute();
}
