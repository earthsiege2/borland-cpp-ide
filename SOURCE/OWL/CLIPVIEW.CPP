//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\clipview.cpp
//   implementation of class TClipboardViewer
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\clipview.h>

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

TClipboardViewer::TClipboardViewer(HWND hWnd, TModule*   module)
  : TWindow(hWnd, module)
{
}

TEventStatus
TClipboardViewer::DoChangeCBChain(HWND hWndRemoved, HWND hWndNext)
{
  if (hWndRemoved == HWndNext)
    HWndNext = hWndNext;

  else
    ForwardMessage(HWndNext);
  return esComplete;
}

TEventStatus
TClipboardViewer::DoDrawClipboard()
{
  if (HWndNext)
    ForwardMessage(HWndNext);
  return esPartial;
}

TEventStatus
TClipboardViewer::DoDestroy()
{
  ::ChangeClipboardChain(HWindow, HWndNext);
  return esPartial;
}

void
TClipboardViewer::SetupWindow()
{
  HWndNext = ::SetClipboardViewer(HWindow);
}

void
TClipboardViewer::EvChangeCBChain(HWND hWndRemoved, HWND hWndNext)
{
  if (hWndRemoved == HWndNext)
    HWndNext = hWndNext;

  else
    ForwardMessage(HWndNext);
}

void
TClipboardViewer::EvDrawClipboard()
{
  if (DoDrawClipboard() == esComplete)
    return;
  TWindow::EvDrawClipboard();
}

void
TClipboardViewer::EvDestroy()
{
  if (DoDestroy() == esComplete)
    return;
  TWindow::EvDestroy();
}
