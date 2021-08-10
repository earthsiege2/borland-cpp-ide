//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of TClipboard which provides clipboard encapsulation
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_CLIPBOAR_H)
# include <owl/clipboar.h>
#endif

#if defined(OWL2_COMPAT)
//
// Global clipboard object obtained using GetClipboard(). This technique
// is obsolete.
//
// The recomended way is to construct a TClipboard object using the
// TClipboard(HWND) ctor below
//
TClipboard TClipboard::TheClipboard;
#endif

const char* TClipboard::DefaultProtocol = "StdFileEditing";

//
// Constructs a clipboard object to grab the clipboard given a window handle.
// This is the preferred method of getting the clipboard;
//
// Throws an exception on open failure if mustOpen is true (default)
// mustOpen can be passed as false for compatability
//
TClipboard::TClipboard(HWND hWnd, bool mustOpen)
{
  OpenClipboard(hWnd);
  if (mustOpen && !IsOpen)
    throw TXClipboard(IDS_CLIPBOARDBUSY);
}

//
// Destruct a clipboard object & close the clipboard if open
//
TClipboard::~TClipboard()
{
  if (IsOpen)
    ::CloseClipboard();
}

//
// Close the clipboard iff it is open
//
void
TClipboard::CloseClipboard()
{
  if (IsOpen) {
    ::CloseClipboard();
    IsOpen = false;
  }
}

//
// Open the clipboard
//
bool
TClipboard::OpenClipboard(HWND hWnd)
{
  return IsOpen = ::OpenClipboard(hWnd) != 0;
}

//----------------------------------------------------------------------------

//
// Construct an available format iterator for a clipboard.
//
#if __DEBUG >= 1
TClipboardFormatIterator::TClipboardFormatIterator(const TClipboard& clip)
#else
TClipboardFormatIterator::TClipboardFormatIterator(const TClipboard& /*clip*/)
#endif
{
  PRECONDITION(bool(clip));
  Restart();
}

//
// Restart the format iterator.
//
void
TClipboardFormatIterator::Restart()
{
  _Current = ::EnumClipboardFormats(0);
}

//
// Get the next available format.
//
uint
TClipboardFormatIterator::operator ++()
{
  return _Current = ::EnumClipboardFormats(_Current);
}

//
// Get the previous format.
//
uint
TClipboardFormatIterator::operator ++(int)
{
  uint current = _Current;
  _Current = ::EnumClipboardFormats(_Current);
  return current;
}

//----------------------------------------------------------------------------

//
// Create the TXClipboard exception with a string resource.
//
TXClipboard::TXClipboard(uint resId)
:
  TXOwl(resId)
{
}


//
// Clone the exception for safe throwing in Windows.
//
#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXClipboard*
#endif
TXClipboard::Clone()
{
  return new TXClipboard(*this);
}

//
// Throw the exception.
//
void
TXClipboard::Throw()
{
  THROW( *this );
}

//
// Throw the exception.
//
void
TXClipboard::Raise(uint resourceId)
{
  TXClipboard(resourceId).Throw();
}
