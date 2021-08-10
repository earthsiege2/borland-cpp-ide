//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\decmdifr.cpp
//   Implementation of class TDecoratedMDIFrame
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\decmdifr.h>

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
                                       BOOL            trackMenuSelection,
                                       TModule*        module)
  : TMDIFrame(title, menuResId, clientWnd, module),
    TDecoratedFrame(0, title, &clientWnd, trackMenuSelection, module),
    TFrameWindow(0, title, &clientWnd, FALSE, module),
    TWindow(0, title, module)
{
}

LRESULT
TDecoratedMDIFrame::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
  //
  // ::DefFrameProc() will response to WM_SIZE by making the MDI client the
  // same size as the client rectangle; this conflicts with what TLayoutWindow
  // has done
  //
  return message == WM_SIZE ?
                      0 :
                      TMDIFrame::DefWindowProc(message, wParam, lParam);
}

#endif
#if !defined(SECTION) || SECTION == 2


IMPLEMENT_STREAMABLE4(TDecoratedMDIFrame, TMDIFrame, TDecoratedFrame,
                      TFrameWindow, TWindow);
void*
TDecoratedMDIFrame::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TMDIFrame*)GetObject(), is);
  ReadBaseObject((TDecoratedFrame*)GetObject(), is);
  return GetObject();
}

void
TDecoratedMDIFrame::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TMDIFrame*)GetObject(), os);
  WriteBaseObject((TDecoratedFrame*)GetObject(), os);
}

#endif

