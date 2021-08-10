// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// CppOcf1.cpp
// ---------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/ocapp.h>
#include <windowsx.h>
#include <ocf/ocdoc.h>
#include <ocf/ocview.h>
#include <ocf/ocpart.h>
#include "ocfevx.h"
#include "CppOcf1.h"

//
// OCF variables that are needed per window
//
TOcRegistrar* OcRegistrar = 0;
TOcApp*       OcApp       = 0;
TOcDocument*  OcDoc       = 0;
TOcView*      OcView      = 0;

bool Inserted = false;
HWND HwndView = 0;
TRegLink* RegLinkHead = 0;  // initialize reglink list

//
// registration information
//
REGISTRATION_FORMAT_BUFFER(100)

BEGIN_REGISTRATION(AppReg)
  REGDATA(clsid,    "{8646DB80-94E5-101B-B01F-00608CC04F66}")
END_REGISTRATION

//
// Starting point of all Windows programs
//
int PASCAL
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
        char far* lpCmdLine, int nCmdShow)
{
  try {
    TOleAllocator allocator(0);  // Required for OLE2
    MSG msg;

    // Initialize OCF objects
    //
    OcRegistrar = new TOcRegistrar(::AppReg, 0, string(lpCmdLine),
                                   ::RegLinkHead, hInstance);
    OcRegistrar->CreateOcApp(OcRegistrar->GetOptions(), OcApp);

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
  catch (TXBase& xbase) {
    MessageBox(GetFocus(), xbase.why().c_str(), "Exception caught", MB_OK);
  }

  // free the OCF object
  //
  delete OcRegistrar;
  return 0;
}


//
// Initialize application-specific stuff and register the class
//
bool
InitApplication(HINSTANCE hInstance)
{
  WNDCLASS wc;
  WNDCLASS wcView;

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

  RegisterClass(&wc);

  wcView.style          = 0;
  wcView.lpfnWndProc    = (WNDPROC) ViewWndProc;
  wcView.cbClsExtra     = 0;
  wcView.cbWndExtra     = 0;
  wcView.hInstance      = hInstance;
  wcView.hIcon          = LoadIcon(0, IDI_APPLICATION);
  wcView.hCursor        = LoadCursor(0, IDC_ARROW);
  wcView.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wcView.lpszMenuName   = 0;
  wcView.lpszClassName  = VIEWCLASSNAME;

  RegisterClass(&wcView);

  return true;
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
    HANDLE_MSG(hwnd, WM_COMMAND,  MainWnd_OnCommand);
    HANDLE_MSG(hwnd, WM_SIZE,     MainWnd_OnSize);

    // handle the OCF to application messages
    //
    HANDLE_MSG(hwnd, WM_OCEVENT,  MainWnd_OnOcEvent);
  }
  return DefWindowProc(hwnd, message, wParam, lParam);
}

bool
MainWnd_OnCreate(HWND hwnd, CREATESTRUCT FAR* /*lpCreateStruct*/)
{
  if (OcApp)
    OcApp->SetupWindow(hwnd);

  HwndView = CreateWindow(VIEWCLASSNAME, "",
    WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE | WS_BORDER,
    10, 10, 300, 300,
    hwnd, (HMENU)1, _hInstance, 0);

  return true;
}

void
MainWnd_OnClose(HWND hwnd)
{
  if (IsWindow(HwndView))
    DestroyWindow(HwndView);
  DestroyWindow(hwnd);
}

void
MainWnd_OnDestroy(HWND /*hwnd*/)
{

  PostQuitMessage(0);
}

void
MainWnd_OnCommand(HWND hwnd, int id, HWND /*hwndCtl*/, uint /*codeNotify*/)
{
  switch (id) {
    case CM_INSERTOBJECT: {
      try {
        TOcInitInfo initInfo(OcView);

        if (OcApp->Browse(initInfo)) {
          TRect rect(30, 30, 100, 100);
          new TOcPart(*OcDoc, initInfo, rect);
          Inserted = true;
        }
      }
      catch (TXBase& xbase) {
        MessageBox(GetFocus(), xbase.why().c_str(), "Exception caught", MB_OK);
      }
      break;
    }
    case CM_EXIT: {
      PostMessage(hwnd, WM_CLOSE, 0, 0);
      break;
    }
  }
}

void
MainWnd_OnSize(HWND hwnd, UINT /*state*/, int /*cx*/, int /*cy*/)
{
  if (IsWindow(HwndView)) {
    TRect rect;
    GetClientRect(hwnd, &rect);
    MoveWindow(HwndView, rect.left, rect.top, rect.right, rect.bottom, true);
  }
}

bool
MainWnd_OnOcAppFrameRect(HWND hwnd, TRect far* rect)
{
  GetClientRect(hwnd, rect);
  return true;
}

//
// Subdispatch OC_... messages
//
long
MainWnd_OnOcEvent(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
  switch (wParam) {
    HANDLE_OCF(hwnd, OC_APPFRAMERECT, MainWnd_OnOcAppFrameRect);
  }
  return false;
}

//
// view window
//
bool
ViewWnd_OnCreate(HWND hwnd, CREATESTRUCT FAR* /*lpCreateStruct*/)
{
  OcDoc  = new TOcDocument(*OcApp);
  OcView = new TOcView(*OcDoc);

  if (OcView)
    OcView->SetupWindow(hwnd);

  return true;
}

void
ViewWnd_OnClose(HWND hwnd)
{
  PostMessage(GetParent(hwnd), WM_CLOSE, 0, 0);
  DestroyWindow(hwnd);
}

void
ViewWnd_OnDestroy(HWND /*hwnd*/)
{
  for (TOcPartCollectionIter i(OcDoc->GetParts()); i; i++) {
    TOcPart& p = *i.Current();
    p.Activate(false);
  }

  if (OcView) {
    OcView->EvClose();
    OcView->ReleaseObject();
  }

  OcDoc->Close();

  if (OcApp) {
    OcApp->Release();
  }

  delete OcDoc;
}

void
ViewWnd_OnPaint(HWND hwnd)
{
  PAINTSTRUCT ps;
  HDC dc = BeginPaint(hwnd, &ps);

  RECT rect;
  GetClientRect(hwnd, &rect);

  TRect clientRect(rect);
  TRect logicalRect = clientRect;
  DPtoLP(dc, (POINT*)&logicalRect, 2);

  for (TOcPartCollectionIter i(OcDoc->GetParts()); i; i++) {
    TOcPart& p = *i.Current();
    if (p.IsVisible(logicalRect)) {
      TRect r = p.GetRect();
      p.Draw(dc, r, clientRect, asDefault);
    }
  }

  EndPaint(hwnd, &ps);
}

void
ViewWnd_OnSize(HWND /*hwnd*/, UINT /*state*/, int /*cx*/, int /*cy*/)
{
  if (OcView) {
    OcView->EvResize();
  }
}

//
// Standard message-handler routine for view window
//
long CALLBACK _export
ViewWndProc(HWND hwnd, uint message, WPARAM wParam, LPARAM lParam)
{
  switch (message) {
    HANDLE_MSG(hwnd, WM_CREATE,   ViewWnd_OnCreate);
    HANDLE_MSG(hwnd, WM_CLOSE,    ViewWnd_OnClose);
    HANDLE_MSG(hwnd, WM_DESTROY,  ViewWnd_OnDestroy);
    HANDLE_MSG(hwnd, WM_PAINT,    ViewWnd_OnPaint);

    // handle the OCF to application messages
    //
    HANDLE_MSG(hwnd, WM_OCEVENT,  ViewWnd_OnOcEvent);
  }
  return DefWindowProc(hwnd, message, wParam, lParam);
}


const char*
ViewWnd_OnOcViewTitle(HWND /*hwnd*/)
{
  return APPSTRING;
}


bool
ViewWnd_OnOcViewClose(HWND /*hwnd*/)
{
  if (OcDoc)
    OcDoc->Close();
  return true;
}

//
// Subdispatch OC_... messages
//
long
ViewWnd_OnOcEvent(HWND hwnd, WPARAM wParam, LPARAM /*lParam*/)
{
  switch (wParam) {
    HANDLE_OCF(hwnd, OC_VIEWCLOSE,  ViewWnd_OnOcViewClose);
    HANDLE_OCF(hwnd, OC_VIEWTITLE,  ViewWnd_OnOcViewTitle);
  }
  return false;
}


