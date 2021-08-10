//----------------------------------------------------------------------------
// ObjectComponents - (C) Copyright 1994, 1996 by Borland International
// Automated calculator example demonstrating class hierarchy and collections
// Automation localized for simultaneous English and German use and typelibs
// The example can be built as an .EXE or as an inproc .DLL server
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#include <classlib/pointer.h>
#include <ocf/ocreg.h>
#include "autocalc.h"

BEGIN_REGISTRATION(AppReg)
  REGDATA(appname,    APP_NAME)
#if !defined(__DLL__) // building EXE application
  REGDATA(clsid,      "{877B6200-7627-101B-B87C-0000C057CE4E}")
  REGDATA(progid,     APP_NAME ".Application")
  REGDATA(description,"@AppName")
  REGDATA(cmdline,    "/Automation")
#if defined(BI_PLAT_WIN32)
  REGDATA(debugger,   "TD32")
#else
  REGDATA(debugger,   "TDW")
#endif
  REGDATA(debugclsid, "{877B6201-7627-101B-B87C-0000C057CE4E}")
  REGDATA(debugprogid,  APP_NAME ".Debug")
  REGDATA(debugdesc,"@AppName")
#else                 // building DLL inproc server
  REGDATA(clsid,      "{877B6280-7627-101B-B87C-0000C057CE4E}")
  REGDATA(progid,     APP_NAME ".DLLServer")
  REGDATA(description,"@AppDLLServer")
#endif                // common to both EXE and DLL
  REGDATA(typehelp,   "@typehelp")
  REGDATA(version,    "1.2")
END_REGISTRATION

BOOL InitApplication(HINSTANCE hInst);
long FAR PASCAL WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

TPointer<TRegistrar> Registrar;    // initialized at WinMain or LibMain

#if !defined(__DLL__)  // building EXE application

static const char* ErrorLookup(long errCode)
{
  static char buf[50];
  wsprintf(buf, "Error message #%ld", errCode);
  return buf;
}

int PASCAL
WinMain(HINSTANCE hInst, HINSTANCE prev, char far* cmdLine, int/*cmdShow*/)
{
  if(prev || InitApplication(hInst)) {
    try {
      string cmdLineString(cmdLine);
      ::Registrar=new TRegistrar(AppReg,TOcAutoFactory<TCalc>(),
                                 cmdLineString, hInst);
      TAutoCommand::SetErrorMsgHook(ErrorLookup);
      if (!::Registrar->IsOptionSet(amAnyRegOption))
        ::Registrar->Run();
      ::Registrar = 0;  // deletes registrar by replacing pointer
      return 0;
    }
    catch (TXBase& x) {
      ::MessageBox(0, x.why().c_str(), "OLE Exception", MB_OK);
    }
  }
  return 1;
}

#else  // building DLL inproc server

#if defined(BI_PLAT_WIN16)
int PASCAL
LibMain(HINSTANCE hInst, uint16 /*dataSeg*/, uint16 /*heapSize*/, char far* cmdLine)
{
#else
int WINAPI
DllEntryPoint(HINSTANCE hInst, uint32 reason, LPVOID)
{
  char* cmdLine = 0;
  if (reason != DLL_PROCESS_ATTACH)
    return 1;
#endif
  if (InitApplication(hInst)) {
    try {
      string cmdLineString(cmdLine);
      ::Registrar=new TRegistrar(AppReg,TOcAutoFactory<TCalc>(),
                                 cmdLineString, hInst);
      return 1;
    }
    catch (TXBase& x) {
      ::MessageBox(0, x.why().c_str(), "OLE Exception", MB_OK);
    }
  }
  return 0;
}

#endif  // the code following is common to both EXE and DLL builds

BOOL InitApplication(HINSTANCE hInst)
{
  WNDCLASS wc;
  wc.style            = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc      = WndProc;
  wc.cbClsExtra       = 0;
  wc.cbWndExtra       = DLGWINDOWEXTRA + sizeof(long);
  wc.hInstance        = hInst;
  wc.hIcon            = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON));
  wc.hCursor          = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground    = (HBRUSH)(COLOR_APPWORKSPACE+1);
  wc.lpszMenuName     = 0;
  wc.lpszClassName    = APP_NAME;
  return ::RegisterClass(&wc) != 0;
}

long PASCAL __export WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  TCalc* This = (TCalc*)::GetWindowLong(hwnd, DLGWINDOWEXTRA);
  switch(msg) {
  case WM_COMMAND:
    if (wParam < IDC_FIRSTID || wParam > IDC_LASTID)
      break;
    This->ButtonPush(wParam);
    return 0;

  case WM_ERASEBKGND:
    if (!This->GetWindow().Background) {
      This->GetWindow().Background = (long)::GetSysColor(COLOR_APPWORKSPACE);
      break;
    } else {
      HBRUSH brush = ::CreateSolidBrush(This->GetWindow().Background);
      ::UnrealizeObject(brush);
      HBRUSH oldbrush = (HBRUSH)::SelectObject((HDC)wParam, brush);
      ::PatBlt((HDC)wParam,0,0,10000,10000,PATCOPY);
      ::SelectObject((HDC)wParam, oldbrush);
      ::DeleteObject(brush);
      return 1;
    }

  case WM_DESTROY:
    if (This) {
      This->Closed();
      ::Registrar->ReleaseAutoApp(TAutoObject<TCalc>(This));
    }
    if (This->Options & amExeMode)
      PostQuitMessage(0);
    return 0;
  }
  return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

