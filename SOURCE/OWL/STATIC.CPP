//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\static.h
//   Implementation of class TStatic.  This defines the basic behavior of
//   static controls
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\static.h>
#include <owl\applicat.h>
#include <bwcc.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TStatic,TControl)
  EV_WM_SIZE,
END_RESPONSE_TABLE;

//
// constructor for a TStatic object
//
// by default, static controls have left-justified text
//
TStatic::TStatic(TWindow*        parent,
                 int             id,
                 const char far* title,
                 int x, int y, int w, int h,
                 UINT            textLen,
                 TModule*        module)
  : TControl(parent, id, title, x, y, w, h, module)
{
  TextLen = textLen;
  Attr.Style = (Attr.Style | SS_LEFT) & ~WS_TABSTOP;
}

//
// constructor for a TStatic to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition
//
// initializes its data fields using passed parameters
//
// data transfer is disabled, by default, for the TStatic
//
TStatic::TStatic(TWindow*   parent,
                 int        resourceId,
                 UINT       textLen,
                 TModule*   module)
  : TControl(parent, resourceId, module)
{
  TextLen = textLen;
  DisableTransfer();
}

//
// Static controls don't repaint when they are re-sized
// This will force them to be re-painted
//
void
TStatic::EvSize(UINT sizeType, TSize& size)
{
  Invalidate();
  TControl::EvSize(sizeType,size);
}

//
// Return name of predefined BWCC or Windows static class
//
char far *
TStatic::GetClassName()
{
  if (GetApplication()->BWCCEnabled())
    return STATIC_CLASS;
  else
    return "STATIC";
}

//
// transfers state information for TStatic controls
//
// the direction passed specifies whether data is to be read from or
// written to the passed buffer, or whether the data element size is simply to
// be returned
//
// the return value is the size (in bytes) of the transfer data
//
UINT
TStatic::Transfer(void* buffer, TTransferDirection direction)
{
  if (direction == tdGetData)
    GetText((char far*)buffer, TextLen);

  else if (direction == tdSetData)
    SetText((char far*)buffer);

  return TextLen;
}

void
TStatic::Clear()
{
  SetText("");
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TStatic, TControl);

//
// reads an instance of TStatic from the passed ipstream
//
void*
TStatic::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TControl*)GetObject(), is);
  is >> GetObject()->TextLen;
  return GetObject();
}

//
// writes the TStatic to the passed opstream
//
void
TStatic::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TControl*)GetObject(), os);
  os << GetObject()->TextLen;
}

#endif

