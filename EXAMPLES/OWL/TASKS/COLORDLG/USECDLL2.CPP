//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "cctltest.h"

extern "C" BOOL FAR PASCAL
GetColor(HWND parentHandle, COLORREF& colorBuffer);

char appName[] = "DLL Test (non-OWL app)";

//
//
//
LRESULT
doProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  switch (message) {
    case WM_DESTROY:
      PostQuitMessage(0);
      break;

    case WM_COMMAND:
      if (LOWORD(lParam) == 0 && wParam == CM_COLOR) {
        COLORREF color = RGB(0x00, 0x00, 0x00);
        char msgStr[128];
        if (GetColor(hWnd, color)) {
          sprintf(msgStr,
           "RGB intensities:\r\n\r\n Red: %d\r\n Green: %d\r\n Blue: %d",
            GetRValue(color), GetGValue(color), GetBValue(color));
        }
        else
          strcpy(msgStr, "Cancelled");
        MessageBox(hWnd, msgStr, appName, MB_OK);
      }
      else
        return DefWindowProc(hWnd, message, wParam, lParam);
      break;

    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}


//
//
//
#if defined(BI_PLAT_WIN32)
LRESULT
FAR PASCAL _stdcall
WndProc(HWND h, UINT msg, WPARAM wParam, LPARAM lParam)
{
  return doProc(h, msg, wParam, lParam);
}

#else
LRESULT
FAR PASCAL __export
WndProc(HWND h, UINT msg, WPARAM wParam, LPARAM lParam)
{
  return doProc(h, msg, wParam, lParam);
}
#endif

//
//
//
int PASCAL
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, int cmdShow)
{
  if (!hPrevInstance) {
    WNDCLASS wndClass;
    wndClass.style         = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc   = WndProc;
    wndClass.cbClsExtra    = 0;
    wndClass.cbWndExtra    = 0;
    wndClass.hInstance     = hInstance;
    wndClass.hIcon         = LoadIcon(0, IDI_APPLICATION);
    wndClass.hCursor       = LoadCursor(0, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpszMenuName  = MAKEINTRESOURCE(IDM_APPMENU);
    wndClass.lpszClassName = appName;

    if (!RegisterClass(&wndClass))
      return FALSE;
  }

  HWND hWnd = CreateWindow(appName, appName, WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, hInstance, 0);

  ShowWindow(hWnd, cmdShow);

  MSG msg;
  while (GetMessage(&msg, 0, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return msg.wParam;
}
