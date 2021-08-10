// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// CppOcf2.cpp
// ---------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/ocapp.h>
#include <windowsx.h>
#include <ocf/ocreg.h>
#include <ocf/ocdoc.h>
#include <ocf/ocview.h>
#include <ocf/ocremvie.h>
#include <ocf/ocpart.h>
#include "ocfevx.h"
#include "CppOcf2.h"

//
//
//
TOcRegistrar* OcRegistrar = 0;
TOcApp*       OcApp       = 0;

TOcDocument*  OcDoc       = 0;
TOcRemView*   OcRemView   = 0;

bool Inserted = false;
HWND HwndView = 0;
HWND HwndMain = 0;
TRegLink* RegLinkHead = 0;

//
// registration information
//
REGISTRATION_FORMAT_BUFFER(100)

BEGIN_REGISTRATION(AppReg)
  REGDATA(clsid,    "{BD5E4A81-A4EF-101B-B31B-0694B5E75735}")
  REGDATA(appname,  "Count Server")
END_REGISTRATION

BEGIN_REGISTRATION(DocReg)
  REGDATA(description,  "Count Server Document")
  REGDATA(progid,       APPSTRING".Document.2")
  REGDATA(appname,      "Count")
//  REGDATA(debugger,     "tdw")
//  REGDATA(debugprogid,  APPSTRING".Debug.2")
//  REGDATA(debugdesc,    "Count Server (debug) Document")
  REGDATA(menuname,     "CountDocument")
  REGDATA(insertable,   "")
  REGDATA(extension,    "scd")
  REGDATA(docfilter,    "*.scd")
  REGDATA(verb0,        "&Edit")
  REGDATA(verb1,        "&Open")
  REGFORMAT(0, ocrEmbedSource,  ocrContent, ocrIStorage, ocrGet)
  REGFORMAT(1, ocrMetafilePict, ocrContent, ocrMfPict,   ocrGet)
  REGFORMAT(2, ocrBitmap,       ocrContent,  ocrGDI|ocrStaticMed, ocrGet)
  REGFORMAT(3, ocrDib,          ocrContent,  ocrHGlobal|ocrStaticMed, ocrGet)
  REGFORMAT(4, ocrLinkSource,   ocrContent,  ocrIStream, ocrGet)
END_REGISTRATION

TRegLink DocLink(DocReg, RegLinkHead);

//
//
//
HWND CreateViewWindow(HWND hwndParent)
{
  RECT rect;

  GetClientRect(hwndParent, &rect);
  HWND hwnd = CreateWindow(VIEWCLASSNAME, "",
    WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE | WS_BORDER,
    rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,
    hwndParent, (HMENU)1, _hInstance, 0);
  return hwnd;
}

IUnknown*
ComponentFactory(IUnknown* outer, uint32 options, uint32 id)
{
  IUnknown* ifc = 0;

  if (!OcApp) {
    if (options & amShutdown)  // no app to shutdown!
      return 0;
    OcRegistrar->CreateOcApp(options, OcApp);
    if (IsWindow(HwndMain))
      OcApp->SetupWindow(HwndMain);
  }
  else if (options & amShutdown) {
    DestroyWindow(HwndMain);
    return 0;
  }

  if (id == 0)
    OcApp->SetOuter(outer);

  if (options & amRun) {
    if ((options & amEmbedding) == 0) {
      HwndView = CreateViewWindow(HwndMain);
    }
    MSG msg;
    // Standard Windows message loop
    while (GetMessage(&msg, 0, 0, 0)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  if (id) {
    OcDoc     = new TOcDocument(*OcApp);
    HwndView  = CreateViewWindow(HwndMain);
    OcRemView = new TOcRemView(*OcDoc, &DocReg);
    if (IsWindow(HwndView))
      OcRemView->SetupWindow(HwndView);
    ifc = OcRemView->SetOuter(outer);
  }
  return ifc;
}

//
// Starting point of all Windows programs
//
int PASCAL
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
        char far* lpCmdLine, int nCmdShow)
{
  try {
    TOleAllocator allocator(0); //required for OLE2
    string cmdLine(lpCmdLine);

    OcRegistrar = new TOcRegistrar(::AppReg, ComponentFactory, cmdLine,
                                   ::RegLinkHead, hInstance);

    // Any previous instance?
    if (!hPrevInstance)
      // Initialize app-specific stuff
      if (!InitApplication(hInstance))
        return 0;

    // Instance-specific
    if (OcRegistrar->IsOptionSet(amEmbedding) ||
      OcRegistrar->IsOptionSet(amAnyRegOption))
      nCmdShow = SW_HIDE;
    if (!InitInstance(hInstance, nCmdShow))
      return 0;

    if (!OcRegistrar->IsOptionSet(amAnyRegOption))
      OcRegistrar->Run();
    delete OcRegistrar;
  }
  catch (xmsg& x) {
    MessageBox(GetFocus(), x.why().c_str(), "Exception caught", MB_OK);
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
  WNDCLASS wcView;

  wc.style          = 0;
  wc.lpfnWndProc    = (WNDPROC) MainWndProc;
  wc.cbClsExtra     = 0;
  wc.cbWndExtra     = 0;
  wc.hInstance      = hInstance;
  wc.hIcon          = LoadIcon(0, IDI_APPLICATION);
  wc.hCursor        = LoadCursor(0, IDC_ARROW);
  wc.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wc.lpszMenuName   = 0;
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

  HwndMain = hwnd;
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
MainWnd_OnCommand(HWND /*hwnd*/, int id, HWND /*hwndCtl*/, uint /*codeNotify*/)
{
  switch (id) {
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

//
// Subdispatch OC_... messages
//
long
MainWnd_OnOcEvent(HWND hwnd, WPARAM wParam, LPARAM /*lParam*/)
{
  switch (wParam) {
    HANDLE_OCF(hwnd, OC_VIEWTITLE,        MainWnd_OnOcViewTitle);
    HANDLE_OCF(hwnd, OC_APPSHUTDOWN,      MainWnd_OnOcAppShutDown);
  }
  return false;
}

const char*
MainWnd_OnOcViewTitle(HWND /*hwnd*/)
{
  return APPSTRING;
}

bool
MainWnd_OnOcAppShutDown(HWND hwnd)
{
  PostMessage(hwnd, WM_CLOSE, 0, 0);
  return true;
}


static uint TimerId = 0;

bool
ViewWnd_OnCreate(HWND hwnd, CREATESTRUCT FAR* /*lpCreateStruct*/)
{
  TimerId = SetTimer(hwnd, 1, 1000, 0);
  return true;
}

void
ViewWnd_OnClose(HWND hwnd)
{
  DestroyWindow(hwnd);
}

void
ViewWnd_OnDestroy(HWND hwnd)
{
  KillTimer(hwnd, TimerId);
  if (OcDoc) {
    OcDoc->Close();
    delete OcDoc;
    OcDoc = 0;
  }
  if (IsWindow(HwndMain))
    PostMessage(HwndMain, WM_CLOSE, 0, 0);
  HwndView = 0;
}

char Buffer[80];
uint Counter = 0;

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

  wsprintf(Buffer, "%u", Counter);
  TextOut(dc, 0, 0, Buffer, lstrlen(Buffer));

  EndPaint(hwnd, &ps);
}

void
ViewWnd_OnSize(HWND /*hwnd*/, UINT /*state*/, int /*cx*/, int /*cy*/)
{
}

void
ViewWnd_OnTimer(HWND hwnd, UINT /*id*/)
{
  Counter++;
  InvalidateRect(hwnd, 0, true);
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
    HANDLE_MSG(hwnd, WM_TIMER,    ViewWnd_OnTimer);

    // handle the OCF to application messages
    //
    HANDLE_MSG(hwnd, WM_OCEVENT,  ViewWnd_OnOcEvent);
  }
  return DefWindowProc(hwnd, message, wParam, lParam);
}


//
// Subdispatch OC_... messages
//
long
ViewWnd_OnOcEvent(HWND hwnd, WPARAM wParam, LPARAM /*lParam*/)
{
  switch (wParam) {
    HANDLE_OCF(hwnd, OC_VIEWCLOSE, ViewWnd_OnOcViewClose);
  }
  return false;
}

bool
ViewWnd_OnOcViewClose(HWND /*hwnd*/)
{
  if (OcDoc)
    OcDoc->Close();
  return true;
}

