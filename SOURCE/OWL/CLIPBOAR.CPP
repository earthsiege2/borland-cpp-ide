//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Clipboard encapsulation
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/clipboar.h>

//
// Global clipboard object obtained using GetClipboard(). This technique
// is obsolete.
// The recomended way is to construct a TClipboard object using the
// TClipboard(HWND) ctor
//
TClipboard TClipboard::TheClipboard;

const char* TClipboard::DefaultProtocol = "StdFileEditing";
    
//
// Construct a clipboard object to grab the clipboard given a window handle.
// This is the preferred method of getting the clipboard; the implementation
// is currently inline.
// Will eventually throw an exception on open failure.
//
//TClipboard::TClipboard(HWND hWnd)
//{
//  OpenClipboard(hWnd);
//  if (!IsOpen)
//    throw TXClipboard(IDS_CLIPBOARDBUSY);
//}
