//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// ADOPT.CPP
//
// Implements the function for adopting the VCL's hidden main window
// as a child of an OWL window.
//----------------------------------------------------------------------------
#define STRICT                  // required for OWL/VCL compatibility
#include <vcl\vcl.h>
#pragma hdrstop
#include "adopt.h"

//
// Associate VCL form with an OWL parent.
//
void AdoptVCLAppWindow(HWND newParent)
{
  SetParent(Application->Handle, newParent);
  return;
}

  
