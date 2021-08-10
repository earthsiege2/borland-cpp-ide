//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Base OLE UI dialog class definitions
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/owlpch.h>
#include <owl/oledlg.h>

//
// The following option forces the GUID into the code segment
//
#pragma option -zE_TEXT -zFCODE

//
// Bolero's OLEUILinkContainer's GUID
//
extern "C" const GUID far IID_IOleUILinkContainer = { 0x000004FF, 0x0000,
                                                      0x0000,
                           { 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 } };
