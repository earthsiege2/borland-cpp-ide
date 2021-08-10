// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// CppOcf0.cpp
// ---------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/defs.h>
#include <windowsx.h>
#include "cppocf0.h"

// Starting point of all Windows programs
//
int PASCAL
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
  char far* /*lpCmdLine*/, int nCmdShow)
{
  try {
    MSG msg;

    // Any previous instance?
    if (!hPrevInstance)
      // Initialize app-specific stuff
      if (!InitApplication(hInstance))
        return 0;

    // Instance-specific
    if (!InitInstance(hInstance, nCmdShow))
      return 0;

    // Standard Windows message loop
    while (GetMessage(&msg, 0, 0, 0)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }
  catch (...) {
    MessageBox(GetFocus(), "Unknown exception", "Exception caught", MB_OK);
  }
  return 0;
}


//
// Initialize application-specific stuff and register the class
//
bool
InitApplication(HINSTANCE hInstance)
{
  WNDCLASS wc;

  wc.style          = 0;
  wc.lpfnWndProc    = (WNDPROC) MainWndProc;
  wc.cbClsExtra     = 0;
  wc.cbWndExtra     = 0;
  wc.hInstance      = hInstance;
  wc.hIcon          = LoadIcon(0, IDI_APPLICATION);
  wc.hCursor        = LoadCursor(0, IDC_ARROW);
  wc.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wc.lpszMenuName   = MENUNAME;
  wc.lpszClassName  = CLASSNAME;
  return ToBool(RegisterClass(&wc));
}


//
// Initialize instance and display the main window
//
bool
InitInstance(HINSTANCE hInstance, int nCmdShow)
{
  HWND hwnd;

  hwnd = CreateWindow(CLASSNAME, TITLE,
    WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    0, 0, hInstance, 0);

  if (!hwnd)
    return false;
  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);
  return true;
}


//
// Standard message-handler routine for main window
//
long CALLBACK _export
MainWndProc(HWND hwnd, uint message, WPARAM wParam, LPARAM lParam)
{
  switch (message) {
    HANDLE_MSG(hwnd, WM_CREATE,   MainWnd_OnCreate);
    HANDLE_MSG(hwnd, WM_CLOSE,    MainWnd_OnClose);
    HANDLE_MSG(hwnd, WM_DESTROY,  MainWnd_OnDestroy);
    HANDLE_MSG(hwnd, WM_PAINT,    MainWnd_OnPaint);
    HANDLE_MSG(hwnd, WM_COMMAND,  MainWnd_OnCommand);
  }
  return DefWindowProc(hwnd, message, wParam, lParam);
}

bool
MainWnd_OnCreate(HWND /*hwnd*/, CREATESTRUCT FAR* /*lpCreateStruct*/)
{
  return true;
}

void
MainWnd_OnClose(HWND hwnd)
{
  DestroyWindow(hwnd);
}

void
MainWnd_OnDestroy(HWND /*hwnd*/)
{
  PostQuitMessage(0);
}

void
MainWnd_OnPaint(HWND hwnd)
{
  PAINTSTRUCT ps;
  BeginPaint(hwnd, &ps);

  RECT rect;
  GetClientRect(hwnd, &rect);

  EndPaint(hwnd, &ps);
}

void
MainWnd_OnCommand(HWND hwnd, int id, HWND /*hwndCtl*/, uint /*codeNotify*/)
{
  switch (id) {
    case CM_EXIT: {
      PostMessage(hwnd, WM_CLOSE, 0, 0);
      break;
    }
  }
}
