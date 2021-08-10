//----------------------------------------------------------------------------
// ObjectComponents - (c) Copyright 1996, 1996 by Borland International
//
// $Revision:   2.0  $
//----------------------------------------------------------------------------
#if !defined(STRICT)
#define STRICT
#endif
#include <windows.h>
#include <windowsx.h>
#include <stdlib.h>
#include <ole2.h>
#include <initguid.h>
#include "usecom.rh"

#if defined(BI_COMP_BORLANDC)
# pragma hdrstop
#endif

#include "comintf.h"

// Global variables
//
LPCLASSFACTORY  pIClassFactory = 0;     // Pointer to class factory
LPCALENDAR      pICalendar     = 0;     // Pointer to calendar interface
LPSHAPE         pIShape        = 0;     // Pointer to shape interface


// Frame window's WNDPROC
//
LRESULT CALLBACK _export FrameWndProc(HWND, UINT, WPARAM, LPARAM);

// Frame window's class name
//
const char FrameClassName[] = "__fenêtrePrincipale";
const char FrameTitle[] = "COM Object User";


// App's entry point
//
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR /*lpCmdLine*/,  int nCmdShow)
{
  // Register main window class
  //
  if (!hPrevInstance) {
    WNDCLASS wc;
    wc.style            = CS_HREDRAW|CS_VREDRAW;
    wc.lpfnWndProc      = FrameWndProc;
    wc.cbClsExtra       = 0;
    wc.cbWndExtra       = 0;
    wc.hInstance        = hInstance;
    wc.hIcon            = LoadIcon(0, IDI_APPLICATION);
    wc.hCursor          = LoadCursor(0, IDC_ARROW);
    wc.hbrBackground    = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName     = 0;
    wc.lpszClassName    = FrameClassName;
    if (!RegisterClass(&wc))
        return -1;
  }

  // Create main/frame window
  //
  HWND hwnd;
  hwnd = CreateWindow(FrameClassName,
                      FrameTitle,
                      WS_OVERLAPPEDWINDOW,
                      CW_USEDEFAULT,
                      CW_USEDEFAULT,
                      CW_USEDEFAULT,
                      CW_USEDEFAULT,
                      0,
                      LoadMenu(hInstance, MAKEINTRESOURCE(ID_MAINMENU)),
                      hInstance,
                      0);

  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  // Init OLE
  //
  CoInitialize(0);

  // Spin message loop
  //
  MSG msg;
  while (GetMessage(&msg, NULL, NULL, NULL)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  // Unitialize OLE
  //
  CoUninitialize();

  return(msg.wParam);
}

// Handles WM_CREATE sent to frame window
//
BOOL
FrameOnCreate(HWND /*hwnd*/, CREATESTRUCT FAR* /*lpCreateStruct*/)
{
  return TRUE;
}

// Handles WM_DESTROY sent to frame window
//
void
FrameOnDestroy(HWND /*hwnd*/)
{
  // Release any interface pointers we have have laying around
  //
  if (pICalendar)
    pICalendar->Release();

  if (pIShape)
    pIShape->Release();

  // Post WM_QUIT to terminate message loop
  //
  PostQuitMessage(0);
}


// Retrieves class factory interface and asks factory
// to 'manufacture' requested interface..
//
void
CreateFromScatch(GUID id, LPVOID far* pInterface)
{
  // Retrieve class factory interface pointer to our custom COM object
  //
  HRESULT hr = CoGetClassObject(CLSID_UtilObject,
                                CLSCTX_INPROC_SERVER,
                                0,
                                IID_IClassFactory,
                                (LPVOID far*)&pIClassFactory);

  // Have class factory make the object for us - then release factory
  //
  if (SUCCEEDED(hr)) {
    pIClassFactory->CreateInstance(0, id, pInterface);
    pIClassFactory->Release();
    pIClassFactory = 0;
  }
}

// Handles WM_COMMAND sent to frame window
//
void
FrameOnCommand(HWND hwnd, int id, HWND /*hwndCtl*/, UINT /*codeNotify*/)
{
  switch(id) {
    //
    // Handle request to terminate
    //
    case CM_FILEEXIT:
      PostMessage(hwnd, WM_CLOSE, 0, 0);
      break;

    // Retrieve Shape interface
    //
    case CM_GETSHAPE:
      if (!pIShape) {
        if (pICalendar) {
          pICalendar->QueryInterface(IID_IShape, (LPVOID far*)&pIShape);
        } else {
          CreateFromScatch(IID_IShape, (LPVOID far*)&pIShape);
        }
        InvalidateRect(hwnd, 0, TRUE);
      }
      break;

    // Retrieve Calendar interface
    //
    case CM_GETCALENDAR:
      if (!pICalendar) {
        if (pIShape) {
          pIShape->QueryInterface(IID_ICalendar, (LPVOID far*)&pICalendar);
        } else {
          CreateFromScatch(IID_ICalendar, (LPVOID far*)&pICalendar);
        }
        InvalidateRect(hwnd, 0, TRUE);
      }
      break;

    // Release any interfaces we've acquired - Freeing unused libraries
    // after this should free the DLL (if no one else is using it).
    //
    case CM_RELEASEINTERFACES:
      if (pICalendar) {
        pICalendar->Release();
        pICalendar = 0;
      }
      if (pIShape) {
        pIShape->Release();
        pIShape = 0;
      }
      InvalidateRect(hwnd, 0, TRUE);
      break;

    // Handle request to free unused libraries. This is a good debugging
    // option as it tests to make sure that our custom COM DLL stays in
    // memory for as long as it is serving an object.
    //
    // NOTE: Retrieving a class factory interface does *NOT* lock down
    //       an inproc server - The LockServer method must be called if the
    //       factory interface is kept but no object is created.
    //
    case CM_FREEUNUSEDLIBRARIES:
      CoFreeUnusedLibraries();
      break;
  }
}

// Handles WM_PAINT sent to frame window
//
void
FrameOnPaint(HWND hwnd)
{
  PAINTSTRUCT ps;
  HDC dc = BeginPaint(hwnd, &ps);

  RECT rect;
  GetClientRect(hwnd, &rect);

  // Use IShape interface pointer to draw a few shapes
  //
  if (pIShape) {
    int width  = rect.right - rect.left;
    int height = rect.bottom- rect.top;

    for (int i=0; i<10; i++) {
      pIShape->Rectangle(dc, random(width/2), random(height/2),
                             random(width/2)+(width/2),
                             random(height/2)+(height/2),
                             RGB(random(0xff), random(0xff), random(0x0ff)));
    }
  }

  EndPaint(hwnd, &ps);
}

// Handles WM_INITMENU sent to frame window
//
void
FrameOnInitMenu(HWND /*hwnd*/, HMENU hMenu)
{
  EnableMenuItem(hMenu, CM_GETSHAPE,
                 MF_BYCOMMAND|((pIShape) ? MF_GRAYED : MF_ENABLED));
  EnableMenuItem(hMenu, CM_GETCALENDAR,
                 MF_BYCOMMAND|((pICalendar) ? MF_GRAYED : MF_ENABLED));
  EnableMenuItem(hMenu, CM_RELEASEINTERFACES,
                 MF_BYCOMMAND|
                 ((pICalendar || pIShape) ? MF_ENABLED : MF_GRAYED));
}

// Frame Window's Callback
//
LRESULT CALLBACK _export FrameWndProc(HWND hwnd, UINT msg,
                                      WPARAM wParam, LPARAM lParam)
{
  switch (msg) {
    HANDLE_MSG(hwnd, WM_CREATE,   FrameOnCreate);
    HANDLE_MSG(hwnd, WM_COMMAND,  FrameOnCommand);
    HANDLE_MSG(hwnd, WM_PAINT,    FrameOnPaint);
    HANDLE_MSG(hwnd, WM_DESTROY,  FrameOnDestroy);
    HANDLE_MSG(hwnd, WM_INITMENU, FrameOnInitMenu);
    default:
      break;
  }
  return DefWindowProc(hwnd, msg, wParam, lParam);
}




