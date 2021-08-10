//----------------------------------------------------------------------------
// ObjectComponents - (C) Copyright 1994 by Borland International
// Localization test
//----------------------------------------------------------------------------
#include <winsys/wsysinc.h>
#include <stdio.h>
#include <winsys/lclstrng.h>
#include "localize.rh"

#if !defined(BI_PLAT_WIN32) // WINNLS defines these for WIN32
# include "olenls.h"
#endif

TLangId TLocaleString::NativeLangId = 0x0009; // = LANG_ENGLISH;

#define WM_USERSTAT (WM_USER + 100)

bool CALLBACK __export
DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  if (msg == WM_INITDIALOG) {
    return 1;
  } else if (msg == WM_COMMAND) {
    ::PostMessage(hDlg, WM_USERSTAT, wParam, lParam);
    return 1;
  } else if (msg == WM_CLOSE) {
    ::PostMessage(hDlg, WM_USERSTAT, IDABORT, 0);
    return 1;
  }
  return 0;
}

int PASCAL
WinMain(HINSTANCE hInst, HINSTANCE/*prev*/, char far* /*cmdLine*/, int/*show*/)
{
  HWND hWnd = ::CreateDialog(hInst, MAKEINTRESOURCE(IDD_OUT), 0, (DLGPROC)DlgProc);
  if (!hWnd) {
    ::MessageBox(0, "Could Not Create Dialog Box", "Error", MB_OK);
    return 1;
  }
  for(;;) {
    MSG msg;
    int id = 0;
    while (!id && ::GetMessage(&msg, 0, 0, 0)) {
      if (msg.message == WM_USERSTAT)
        id = msg.wParam;
      else
        ::IsDialogMessage(hWnd, &msg);
    }
    if (id == IDABORT || id == IDOK)
      break;
    if (id & 0x8000) {
      id &= ~0x8000;
      for (int w = IDC_FIRSTWORD; w <= IDC_LASTWORD; w++) {
        char buf[50];
//      TLocaleString word = (const char*)buf;
        TLocaleString word;
        word = (const char*)buf;
        ::GetDlgItemText(hWnd, w, buf, sizeof(buf)-1);
        const char* xlat = word.Translate((TLangId)id);
        ::SetDlgItemText(hWnd, w + IDC_FIRSTXLAT - IDC_FIRSTWORD, xlat);
      }
    }
  }
  ::DestroyWindow(hWnd);
  return 0;
}
