//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// ADOPT.H
//
// Declares the function that lets OWL adopt the invisible
// main window that the VCL TApplication object always
// creates.
//
// If you omit the adoption step, you end up with two windows that
// both think they're the main one, and one of them doesn't close.
//
// We expect to make this step unnecessary before shipping.  
//----------------------------------------------------------------------------
#if !defined(_ADOPT_H)
#define _ADOPT_H

#if !defined(_INC_WINDOWS)
# if !defined(STRICT)           // required for OWL/VCL compatibility
#   define STRICT;
# endif
# include <windows.h>
#endif

// Makes newParent the parent window of the VCL form.
// (Normally the parent of a form is a hidden window managed
// by the VCL TApplication object.)
// 
// A good place to call this is SetupWindow because that's
// the first time you have an HWND to pass in.
//
void AdoptVCLAppWindow(HWND newParent);

#endif // _ADOPT_H
