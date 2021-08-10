//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of class TDecoratedMDIFrame
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_DECMDIFR_H)
# include <owl/decmdifr.h>
#endif

#if !defined(SECTION) || SECTION == 1

//
// make sure that TDecoratedFrame is first in the list so we find its
// WM_SIZE handler
//
DEFINE_RESPONSE_TABLE2(TDecoratedMDIFrame, TDecoratedFrame, TMDIFrame)
END_RESPONSE_TABLE;

TDecoratedMDIFrame::TDecoratedMDIFrame(const char far* title,
                                       TResId          menuResId,
                                       TMDIClient&     clientWnd,
                                       bool            trackMenuSelection,
                                       TModule*        module)
:
  TMDIFrame(title, menuResId, clientWnd, module),
  TDecoratedFrame(0, title, &clientWnd, trackMenuSelection, module),
  TFrameWindow(0, title, &clientWnd, false, module),
  TWindow(0, title, module)
{
}

//
//
//
TResult
TDecoratedMDIFrame::DefWindowProc(uint message, TParam1 param1, TParam2 param2)
{
  //
  // ::DefFrameProc() will response to WM_SIZE by making the MDI client the
  // same size as the client rectangle; this conflicts with what TLayoutWindow
  // has done
  //
  return message == WM_SIZE ?
                      0 :
                      TMDIFrame::DefWindowProc(message, param1, param2);
}

#endif
#if !defined(SECTION) || SECTION == 2


IMPLEMENT_STREAMABLE4(TDecoratedMDIFrame, TMDIFrame, TDecoratedFrame,
                      TFrameWindow, TWindow);
#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
TDecoratedMDIFrame::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TMDIFrame*)GetObject(), is);
  ReadBaseObject((TDecoratedFrame*)GetObject(), is);
  return GetObject();
}

//
//
//
void
TDecoratedMDIFrame::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TMDIFrame*)GetObject(), os);
  WriteBaseObject((TDecoratedFrame*)GetObject(), os);
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
