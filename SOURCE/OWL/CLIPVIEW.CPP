//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of class TClipboardViewer, a TWindow mixin that allows a
// window to receive clipboard notifications appropriate for being a viewer
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_CLIPVIEW_H)
# include <owl/clipview.h>
#endif

OWL_DIAGINFO;

//
// We only want to search this mixin for events, so don't include any base
// classes in Find()
//
DEFINE_RESPONSE_TABLE(TClipboardViewer)
  EV_WM_CHANGECBCHAIN,
  EV_WM_DESTROY,
  EV_WM_DRAWCLIPBOARD,
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TClipboardViewer);

//
// Rely on TWindow's default ctor since we will always be mixed-in and another
// window will perform Init()
//
TClipboardViewer::TClipboardViewer()
{
  HWndNext = 0;
}

//
//
//
TClipboardViewer::TClipboardViewer(THandle handle, TModule* module)
:
  TWindow(handle, module)
{
}

//
//
//
TEventStatus
TClipboardViewer::DoChangeCBChain(THandle hWndRemoved, THandle hWndNext)
{
  if (hWndRemoved == HWndNext)
    HWndNext = hWndNext;

  else
    ForwardMessage(HWndNext);
  return esComplete;
}

//
//
//
TEventStatus
TClipboardViewer::DoDrawClipboard()
{
  if (HWndNext)
    ForwardMessage(HWndNext);
  return esPartial;
}

//
//
//
TEventStatus
TClipboardViewer::DoDestroy()
{
  ::ChangeClipboardChain(GetHandle(), HWndNext);
  return esPartial;
}

//
//
//
void
TClipboardViewer::SetupWindow()
{
  HWndNext = ::SetClipboardViewer(GetHandle());
}

//
//
//
void
TClipboardViewer::EvChangeCBChain(THandle hWndRemoved, THandle hWndNext)
{
  if (hWndRemoved == hWndNext)
    HWndNext = hWndNext;

  else
    ForwardMessage(HWndNext);
}

//
//
//
void
TClipboardViewer::EvDrawClipboard()
{
  if (DoDrawClipboard() == esComplete)
    return;
  TWindow::EvDrawClipboard();
}

//
//
//
void
TClipboardViewer::EvDestroy()
{
  if (DoDestroy() == esComplete)
    return;
  TWindow::EvDestroy();
}
