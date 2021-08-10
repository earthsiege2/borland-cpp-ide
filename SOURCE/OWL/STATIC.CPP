//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of class TStatic.  This defines the basic behavior of static
// text controls
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_STATIC_H)
# include <owl/static.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

#if defined(BI_COMP_BORLANDC)
# include <bwcc.h>
#endif

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TStatic,TControl)
  EV_WM_SIZE,
END_RESPONSE_TABLE;

//
// Constructor for a TStatic object
//
// By default, static controls have left-justified text
//
TStatic::TStatic(TWindow*        parent,
                 int             id,
                 const char far* title,
                 int x, int y, int w, int h,
                 uint            textLimit,
                 TModule*        module)
:
  TControl(parent, id, title, x, y, w, h, module),
  TextLimit(textLimit)
{
  Attr.Style = (Attr.Style | SS_LEFT) & ~WS_TABSTOP;
}

//
// Constructor for a TStatic to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition
//
// Initializes its data fields using passed parameters
//
// Data transfer is disabled, by default, for the TStatic
//
TStatic::TStatic(TWindow*   parent,
                 int        resourceId,
                 uint       textLimit,
                 TModule*   module)
:
  TControl(parent, resourceId, module),
  TextLimit(textLimit)
{
  DisableTransfer();
}

//
// Static controls don't repaint when they are re-sized
// This will force them to be re-painted
//
void
TStatic::EvSize(uint sizeType, TSize& size)
{
  Invalidate();
  TControl::EvSize(sizeType, size);
}

//
// Returns name of predefined BWCC or Windows static class
//
char far*
TStatic::GetClassName()
{
#if defined(BI_COMP_BORLANDC)
  if (GetApplication()->BWCCEnabled())
    return STATIC_CLASS;
  else
#endif
    return "STATIC";
}

//
// Transfers state information for TStatic controls
//
// The direction passed specifies whether data is to be read from or
// written to the passed buffer, or whether the data element size is simply to
// be returned
//
// The return value is the size (in bytes) of the transfer data
//
uint
TStatic::Transfer(void* buffer, TTransferDirection direction)
{
  if (direction == tdGetData)
    GetText((char far*)buffer, TextLimit);

  else if (direction == tdSetData)
    SetText((char far*)buffer);

  return TextLimit;
}

//
// Clears the text contents of this control
//
void
TStatic::Clear()
{
  SetText("");
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TStatic, TControl);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Reads an instance of TStatic from the passed ipstream
//
void*
TStatic::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TControl*)GetObject(), is);
  is >> GetObject()->TextLimit;
  return GetObject();
}

#if !defined(BI_NO_OBJ_STREAMING)

//
// Writes the TStatic to the passed opstream
//
void
TStatic::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TControl*)GetObject(), os);
  os << GetObject()->TextLimit;
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif

