//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    Test.cpp
//
// Date:        27-Apr-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "Test.h"


//
// TestChild constructor
//
TTestWindow::TTestWindow(TWindow* parent, const char far* title,
  TModule* module)
:
  TWindow(parent, title, module)
{
}


//
// TestChild destructor
//
TTestWindow::~TTestWindow()
{
}


//
// SetupWindow
//
void
TTestWindow::SetupWindow()
{
  TWindow::SetupWindow();
  // put new stuff here
  //

}


//
// CleanupWindow
//
void TTestWindow::CleanupWindow()
{
  // put new stuff here
  //

  TWindow::CleanupWindow();
}


//
// Response table for TestChild
//
DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
END_RESPONSE_TABLE;


