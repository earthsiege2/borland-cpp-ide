//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// Tool to generate a GUID from the network card ID, using the OLE 2 API func.
//----------------------------------------------------------------------------
#define STRICT
#include <windows.h>
#include <string.h>
#include <compobj.h>

int CALLBACK __export
GuidProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM /*lParam*/)
{
  if (msg == WM_COMMAND && wParam != 'G')   // ignore msgs from edit control
    ::EndDialog(hDlg, TRUE);                // quit on OK or ESC or Alt-F4
  else if (msg != WM_INITDIALOG)
    return 0;
  else {                                    // do all the work at INITDIALOG
    GUID id;
    IMalloc* alloc;
    char far* guidStr = 0;
    ::CoInitialize(0);                      // init OLE to get memory for GUID
    ::CoGetMalloc(MEMCTX_TASK, &alloc);
    ::CoCreateGuid(&id);
    ::StringFromCLSID(id, &guidStr);
    if (guidStr) {
      ::OpenClipboard(hDlg);                // copy GUID string to clipboard
      ::EmptyClipboard();
      HANDLE cbhdl = ::GlobalAlloc(GHND,lstrlen(guidStr)+1);
      char far* cbdata = (char far*)::GlobalLock(cbhdl);
      lstrcpy(cbdata, guidStr);
      ::GlobalUnlock(cbhdl);
      ::SetClipboardData(CF_TEXT, cbhdl);
      ::CloseClipboard();
      ::SetDlgItemText(hDlg, 'G', guidStr); // show GUID, overwrites error msg
    }
    if (alloc) {
      alloc->Free(guidStr);
      alloc->Release();
    }
    ::CoUninitialize();
  }
  return 1;
}

int far PASCAL
WinMain(HINSTANCE hInst, HINSTANCE/*hPrev*/, char far*/*cmdLine*/, int/*show*/)
{
  return ::DialogBox(hInst, "GuidDlg", 0,(DLGPROC)GuidProc);
}
