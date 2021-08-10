// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// Simple OLE Container using OCF
// ---------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/ocapp.h>
#include <ocf/ocdoc.h>
#include <ocf/ocview.h>
#include <ocf/ocremvie.h>
#include <ocf/ocpart.h>
#include <ocf/ocstorag.h>
#include <classlib/arrays.h>
#include <cstring.h>
#include <windowsx.h>
#include "cppocf3.h"
#include "ocfhlpr.h"

//
// MDI Window Style constants
//
const DWORD MDIClientStyle = MDIS_ALLCHILDSTYLES | WS_GROUP | WS_TABSTOP |
                             WS_CLIPCHILDREN|WS_CLIPSIBLINGS | WS_VSCROLL|
                             WS_HSCROLL | WS_VISIBLE| WS_CHILD;
const DWORD MDIChildStyle  = WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS |
                             WS_CLIPCHILDREN |WS_SYSMENU | WS_CAPTION |
                             WS_THICKFRAME |WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

//
// Macros/constants
//
#define DEFEXT  "sc3"
#define DEFDESC "Sample Container 3"


//
// Global variables
//
const  char childClassName[]  = "__fenêtreOLE";
const  char frameClassName[]  = "__fenêtrePrincipale";
const  char appTitle[]        = DEFDESC;
const  char untitled[]        = "Untitled";
const  char AboutMsg[]        = "C++ OLE Container using OCF";
const  char AboutTitle[]      = "About "DEFDESC;

static char FileName[MAXPATH] = {0};
const  char Filter[]          = DEFDESC"\0*."DEFEXT"\0";


//
// App/Frame related variables
//
HWND      Frame     = 0;
HWND      Client    = 0;
HWND      StatusBar = 0;
HMENU     FrameMenu = 0;
uint      ChildID   = 0x1000;
HINSTANCE HInstance = 0;


//
// OCF variables
//
static TRegLink* RegLinkHead = 0;
static TRect     Decorations(0, 0, 0, 0);

//
// registration information
//
REGISTRATION_FORMAT_BUFFER(100)

BEGIN_REGISTRATION(AppReg)
  REGDATA(clsid,    "{8646DB82-94E5-101B-B01F-00608CC04F66}")
  REGDATA(appname,  "SampContainer")
END_REGISTRATION

//
// Register clipboard formats
//
BEGIN_REGISTRATION(DocReg)
  REGDATA(progid,      "Sample.Container.3")
  REGDATA(description, DEFDESC)
  REGDATA(extension,   DEFEXT)
  REGDATA(docfilter,   "*." DEFEXT)
  REGFORMAT(0, ocrEmbedSource,  ocrContent,  ocrIStorage, ocrGet)
  REGFORMAT(1, ocrMetafilePict, ocrContent,  ocrMfPict|ocrStaticMed, ocrGet)
  REGFORMAT(2, ocrBitmap, ocrContent,  ocrGDI|ocrStaticMed, ocrGet)
  REGFORMAT(3, ocrDib, ocrContent,  ocrHGlobal|ocrStaticMed, ocrGet)
  REGFORMAT(4, ocrLinkSource, ocrContent,  ocrIStream, ocrGet)
END_REGISTRATION
static TRegLink  DocLink(DocReg, RegLinkHead);


//
// Application's Entry Point
//
int PASCAL
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
      char far* lpCmdLine, int nCmdShow)
{
  HInstance = hInstance;
  try {
    // Initialize OLE
    //
    string cmdLine(lpCmdLine);
    TOleInitEx oleInit(::AppReg, /*Factory Callback*/0, cmdLine,
                       ::RegLinkHead, hInstance);

    // Initialize application related items (eg. Window Classes)
    //
    if (!hPrevInstance  && (!InitFrame(hInstance) || !InitChild(hInstance)))
      return 0;

    // Initialize per-instanace related items (eg. create main window)
    //
    if (!InitInstance(hInstance, nCmdShow))
      return 0;

    // Standard Windows message loop
    //
    MSG msg;
    while (GetMessage(&msg, 0, 0, 0)) {
      if (!TranslateMDISysAccel(Client, &msg)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }
    }
  }

  catch (TXBase& xbase) {
    MessageBox(GetFocus(), xbase.why().c_str(), "Exception caught", MB_OK);
  }
  return 0;
}


//
// Initialize main frame
//
bool
InitFrame(HINSTANCE hInstance)
{
  WNDCLASS wc;
  wc.style          = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc    = (WNDPROC)MainWndProc;
  wc.cbClsExtra     = 0;
  wc.cbWndExtra     = sizeof(TOleFrameWin*);
  wc.hInstance      = hInstance;
  wc.hIcon          = LoadIcon(0, IDI_APPLICATION);
  wc.hCursor        = LoadCursor(0, IDC_ARROW);
  wc.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
  wc.lpszMenuName   = 0;
  wc.lpszClassName  = frameClassName;

  return (RegisterClass(&wc) != 0);
}


//
// Initialize instance and display the main window
//
bool
InitInstance(HINSTANCE hInstance, int nCmdShow)
{
  Frame = CreateWindow(frameClassName, appTitle,
                       WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN |
                       WS_CLIPSIBLINGS,
                       CW_USEDEFAULT, CW_USEDEFAULT,
                       CW_USEDEFAULT, CW_USEDEFAULT,
                       0,
                       0,
                       hInstance,
                       0);
  if (!Frame)
    return false;

  ShowWindow(Frame, nCmdShow);
  UpdateWindow(Frame);

  return true;
}


//
// Accessor to retrieve OLE helper object associated with an HWND
//
TOleFrameWin*
GetOleFrameWinObj(HWND hwnd)
{
  return (TOleFrameWin*)(LONG)GetWindowLong(hwnd, 0);
}


//
// Function to associate an OLE Helper object with a window
//
void
SetOleFrameWinObj(HWND hwnd, TOleFrameWin* oleFrameWinObj)
{
  SetWindowLong(hwnd, 0, (LONG)oleFrameWinObj);
}


LRESULT
MainWnd_DefProc(HWND hwnd, uint msg, WPARAM wParam, LPARAM lParam)
{
  return DefFrameProc(hwnd, Client, msg, wParam, lParam);
}


//
// Returns frame's active child window handle
//
HWND
MainWnd_GetActiveChild(HWND /*hwnd*/)
{
  return IsWindow(Client) ? FORWARD_WM_MDIGETACTIVE(Client, SendMessage) : 0;
}


//
// Returns frame window
//
HWND
GetFrame()
{
   return Frame;
}


//
// Sets the Frame's menu
//
void
MainWnd_SetMenu(HWND hwnd, HMENU hMenu, int winIndex = 0)
{
  if (!hMenu && FrameMenu)
    hMenu = FrameMenu;

  if (IsWindow(Client)) {
    FORWARD_WM_MDISETMENU(Client, TRUE /*FALSE*/, hMenu, GetSubMenu(hMenu, winIndex),
                          SendMessage);
    DrawMenuBar(hwnd);
  }
}


//
// Closes all MDI Child Windows
//
void
MainWnd_CloseAll(HWND hwnd)
{
  if (!IsWindow(Client))
    return;

  //
  // Iterate through children to close them...
  //
  HWND child = MainWnd_GetActiveChild(hwnd);
  while (IsWindow(child)) {
    HWND next = GetWindow(child, GW_HWNDNEXT);
    FORWARD_WM_MDIDESTROY(Client, child, SendMessage);
    child = next;
  }
}


bool
MainWnd_OnCreate(HWND hwnd, CREATESTRUCT FAR* /*lpCreateStruct*/)
{
  TOleFrameWin* oleFrameWinObj = new TOleFrameWin(hwnd);
  SetOleFrameWinObj(hwnd, oleFrameWinObj);

  // Allow OLE Helper to perform initialization
  //
  oleFrameWinObj->OnCreate();

  // Set Frame window's menu
  //
  HINSTANCE hInstance = GetWindowInstance(hwnd);
  FrameMenu           = LoadMenu(hInstance, MAKEINTRESOURCE(ID_MAINMENU));

  if (FrameMenu)
    SetMenu(hwnd, FrameMenu);

  // Create MDI Client window
  //
  CLIENTCREATESTRUCT cs;
  memset(&cs, 0,  sizeof(cs));
  cs.hWindowMenu  = FrameMenu ? GetSubMenu(FrameMenu, 0) : 0;
  cs.idFirstChild = ChildID;
  Client = CreateWindow("MDICLIENT", "",
                        MDIClientStyle,
                        0, 0, 0, 0,
                        hwnd,
                        0,
                        hInstance,
                        (LPSTR)(LPCLIENTCREATESTRUCT)&cs);
  return (Client != 0);
}


//
//
//
void
MainWnd_OnDestroy(HWND hwnd)
{
  //
  // Allow OLE Helper object to perform cleanup
  //
  TOleFrameWin* oleFrameWinObj = GetOleFrameWinObj(hwnd);
  oleFrameWinObj->OnDestroy();

  // Delete OLE Helper object
  //
  delete oleFrameWinObj;

  // Usual posting of WM_QUIT
  //
  PostQuitMessage(0);
}


//
// Handles WM_CLOSE
//
void
MainWnd_OnClose(HWND hwnd)
{
  //
  // First restore the frame's original menu to allow proper cleanup
  //
  if (FrameMenu && GetMenu(hwnd) != FrameMenu) {
    MainWnd_SetMenu(hwnd, FrameMenu);
  }

  //
  // Close all children
  //
  MainWnd_CloseAll(hwnd);

  //
  // Pass on to default proc
  //
  FORWARD_WM_CLOSE(hwnd, MainWnd_DefProc);
}


//
// Create MDI child
//
HWND
MainWnd_CreateMDIChild(const char* className,
                       const char* title,
                       DWORD style,
                       int x, int y, int w, int h, HWND parent,
                       HINSTANCE hInstance, LPARAM lParam)
{
  MDICREATESTRUCT mcs;
  mcs.szClass = className;
  mcs.szTitle = title;
  mcs.hOwner  = hInstance;
  mcs.x       = x;
  mcs.y       = y;
  mcs.cx      = w;
  mcs.cy      = h;
  mcs.style   = style;
  mcs.lParam  = lParam;

  return FORWARD_WM_MDICREATE(parent, &mcs, SendMessage);
}


//
// Handle request to create a new MDI Child
//
HWND
MainWnd_NewChild(HWND hwnd)
{
  return IsWindow(Client) ?
         MainWnd_CreateMDIChild(childClassName, untitled, MDIChildStyle,
                                CW_USEDEFAULT, CW_USEDEFAULT,
                                CW_USEDEFAULT, CW_USEDEFAULT,
                                Client, GetWindowInstance(hwnd), 0) : 0;
}


//
// Handles WM_COMMAND sent to frame window
//
void
MainWnd_OnCommand(HWND hwnd, int id, HWND hwndCtl, uint codeNotify)
{
  switch (id) {
    // Handle Exit Request
    //
    case CM_FILEEXIT:
      PostMessage(hwnd, WM_CLOSE, 0, 0);
      break;

    case CM_FILENEW:
      MainWnd_NewChild(hwnd);
      break;

    case CM_FILEOPEN:
      // Prompt user - Create new window - have child load data
      //
      if (GetOpenFileName(hwnd, Filter, FileName, sizeof(FileName)))
        FORWARD_WM_COMMAND(MainWnd_NewChild(hwnd), id, hwndCtl,
                           codeNotify, SendMessage);
      break;

    case CM_FILESAVE:
    case CM_FILESAVEAS: {
      // Tell active child to save parts
      //
      HWND child = MainWnd_GetActiveChild(hwnd);
      FORWARD_WM_COMMAND(child, id, hwndCtl, codeNotify, SendMessage);
      break;
    }

    case CM_WINDOWCASCADECHILDREN:
      FORWARD_WM_MDICASCADE(Client, 0, SendMessage);
      break;

    case CM_WINDOWTILECHILDREN:
      FORWARD_WM_MDITILE(Client, 0, SendMessage);
      break;

    case CM_WINDOWARRANGEICONS:
      FORWARD_WM_MDIICONARRANGE(Client, SendMessage);
      break;

    case CM_WINDOWCLOSEALL:
      MainWnd_CloseAll(hwnd);
      break;

    case CM_HELPABOUT:
      MessageBox(hwnd, AboutMsg, AboutTitle, MB_OK|MB_ICONINFORMATION);
      break;

    // If we do not process the command, pass it on
    //
    default: {
      // forward messages to MDI frame
      FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, MainWnd_DefProc);

      // forward to active child too
      HWND child = MainWnd_GetActiveChild(hwnd);
      if (child)
        FORWARD_WM_COMMAND(child, id, hwndCtl, codeNotify, SendMessage);
    }
  }
}


//
// Resizes Client window
//
void
MainWnd_ResizeClient(HWND hwnd)
{
  if (IsWindow(Client)) {
    TRect rect;
    GetClientRect(hwnd, &rect);
    MoveWindow(Client,
               rect.left    + Decorations.left,
               rect.top     + Decorations.top,
               rect.right   - Decorations.right,
               rect.bottom  - Decorations.bottom,
               true);
  }
}


//
// Handles WM_SIZE be resizing client window
//
void
MainWnd_OnSize(HWND hwnd, uint /*state*/, int /*cx*/, int /*cy*/)
{
  MainWnd_ResizeClient(hwnd);
}


//
// Handles WM_INITMENU message
//
void
MainWnd_OnInitMenu(HWND hwnd, HMENU hMenu)
{
  //
  // Pass on to child to handle menu enabling/disabling
  //
  HWND child = MainWnd_GetActiveChild(hwnd);
  if (child)
    FORWARD_WM_INITMENU(child, hMenu, SendMessage);
}


//
// Handles OCAPPFRAMERECT
//
bool
MainWnd_OnOcAppFrameRect(HWND hwnd, TRect far* rect)
{
  GetClientRect(hwnd, rect);
  return true;
}


//
// Pass on OCAPPINSMENU to active child so it may merge in its menu
//
bool
MainWnd_OnOcAppInsMenus(HWND hwnd, TOcMenuDescr far* sharedMenu)
{
  HWND child = MainWnd_GetActiveChild(hwnd);
  return child ? GetOleWinObj(child)->OnOcAppInsMenus(sharedMenu) : false;
}


//
// Set menu handle specified by active child
//
bool
MainWnd_OnOcAppMenus(HWND hwnd, TOcMenuDescr far* menuDescr)
{
  HWND child = MainWnd_GetActiveChild(hwnd);
  if (child) {
    HMENU menu = GetOleWinObj(child)->OnOcAppMenus(menuDescr);
    if (menu) {
      MainWnd_SetMenu(hwnd, menu);
      return true;
    }
  }
  return false;
}


bool
MainWnd_OnOcAppProcessMsg(HWND, MSG far*)
{
  return false;
}


bool
MainWnd_OnOcAppBorderSpaceReq(HWND, TRect far*)
{
  return true;  // We'll negotiate anything!
}


bool
MainWnd_OnOcAppBorderSpaceSet(HWND hwnd, TRect far* rect)
{
  if (rect) {
    // Store space requested
    //
    Decorations = *rect;

    // Resize our client window
    //
    MainWnd_ResizeClient(hwnd);
  }
  return true;
}


//
//
//
void
MainWnd_OnOcAppStatusText(HWND, const char far* /*text*/)
{
}


//
//
//
void
MainWnd_OnOcAppRestoreUI(HWND hwnd)
{
  HWND child = MainWnd_GetActiveChild(hwnd);
  if (child) {
    HMENU menu = GetOleWinObj(child)->OnOcAppRestoreUI();
    MainWnd_SetMenu(hwnd, menu ? menu : FrameMenu);
  }

  // Reset space allocated for decorations
  //
  Decorations.SetNull();
  MainWnd_ResizeClient(hwnd);
}


//
// Subdispatch OC_... messages
//
LRESULT
MainWnd_OnOcEvent(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
  switch (wParam) {
    HANDLE_OCF(hwnd, OC_APPFRAMERECT,       MainWnd_OnOcAppFrameRect);
    HANDLE_OCF(hwnd, OC_APPBORDERSPACESET,  MainWnd_OnOcAppBorderSpaceSet);
    HANDLE_OCF(hwnd, OC_APPBORDERSPACEREQ,  MainWnd_OnOcAppBorderSpaceReq);
    HANDLE_OCF(hwnd, OC_APPINSMENUS,        MainWnd_OnOcAppInsMenus);
    HANDLE_OCF(hwnd, OC_APPMENUS,           MainWnd_OnOcAppMenus);
    HANDLE_OCF(hwnd, OC_APPRESTOREUI,       MainWnd_OnOcAppRestoreUI);

    default:
      return 0;
  }
}


//
// Standard message-handler routine for main window
//
LRESULT CALLBACK _export
MainWndProc(HWND hwnd, uint message, WPARAM wParam, LPARAM lParam)
{
  switch (message) {
    HANDLE_MSG(hwnd, WM_CREATE,         MainWnd_OnCreate);
    HANDLE_MSG(hwnd, WM_CLOSE,          MainWnd_OnClose);
    HANDLE_MSG(hwnd, WM_DESTROY,        MainWnd_OnDestroy);
    HANDLE_MSG(hwnd, WM_COMMAND,        MainWnd_OnCommand);
    HANDLE_MSG(hwnd, WM_SIZE,           MainWnd_OnSize);
    HANDLE_MSG(hwnd, WM_INITMENU,       MainWnd_OnInitMenu);

    // handle the OCF events sent to the frame window
    //
    HANDLE_MSG(hwnd, WM_OCEVENT,  MainWnd_OnOcEvent);
  }
  return MainWnd_DefProc(hwnd, message, wParam, lParam);
}


// ----------------------------------------------------------------------------
//  MDI Child - related functions/handlers
// ----------------------------------------------------------------------------


//
// View related global variables
//
static HDC DC                 = 0;
static HPEN OldPen            = 0;
static HPEN CurPen            = 0;
static TLine* ScratchLine     = 0;
static int CurrentPenSize     = 1;
static bool MouseCaptured     = false;
static COLORREF CurrentColor  = RGB(0, 0, 0);


//
// Initialize child window
//
bool
InitChild(HINSTANCE hInstance)
{
  WNDCLASS wcView;
  wcView.style          = CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW;
  wcView.lpfnWndProc    = (WNDPROC) ViewWndProc;
  wcView.cbClsExtra     = 0;
  wcView.cbWndExtra     = sizeof(TOleWin*);
  wcView.hInstance      = hInstance;
  wcView.hIcon          = LoadIcon(0, IDI_APPLICATION);
  wcView.hCursor        = LoadCursor(0, IDC_ARROW);
  wcView.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
  wcView.lpszMenuName   = 0;
  wcView.lpszClassName  = childClassName;

  return RegisterClass(&wcView) != 0;
}


//
// Accessor to retrieve OLE helper object associated with an HWND
//
TOleWin*
GetOleWinObj(HWND hwnd)
{
  return (TOleWin*)(LONG)GetWindowLong(hwnd, 0);
}


//
// Function to associate an OLE Helper object with a window
//
void
SetOleWinObj(HWND hwnd, TOleWin* oleWinObj)
{
  SetWindowLong(hwnd, 0, (LONG)oleWinObj);
}


ViewWndData*
GetViewWndData(HWND hwnd)
{
  TOleWin* oleWinObj = GetOleWinObj(hwnd);
  return (ViewWndData*)(oleWinObj ? oleWinObj->GetUserInfo() : 0);
}


ViewWndData*
SetViewWndData(HWND hwnd, ViewWndData* data)
{
  TOleWin* oleWinObj = GetOleWinObj(hwnd);
  return (ViewWndData*)(oleWinObj ? oleWinObj->SetUserInfo(data) : 0);
}


LRESULT
ViewWnd_DefProc(HWND hwnd, uint message, WPARAM wParam, LPARAM lParam)
{
  return DefMDIChildProc(hwnd, message, wParam, lParam);
}


//
// view window
//
BOOL
ViewWnd_OnCreate(HWND hwnd, CREATESTRUCT FAR* /*lpCreateStruct*/)
{
  // Create an OLE helper object
  //
  TOleWin* oleWinObj = new TOleWin(hwnd);
  SetOleWinObj(hwnd, oleWinObj);

  // Create per window data
  //
  ViewWndData* data = new ViewWndData;
  SetViewWndData(hwnd, data);

  // Call the OnCreate method to allow initialization
  //
  oleWinObj->OnCreate();

  //
  // Pass the OCF object our menu description
  //
  MenuDescr menuDescr(LoadMenu(GetWindowInstance(hwnd),
                               MAKEINTRESOURCE(ID_CHILDMENU)),
                      1,    // File group      (File)
                      2,    // Edit group      (Edit + Tools)
                      0,    // Container group
                      0,    // Object group
                      1,    // Window group    (Window)
                      1);   // Help group      (Help)
  oleWinObj->SetWinMenu(menuDescr);

  return true;
}


//
// Handles WM_DESTROY message
//
void
ViewWnd_OnDestroy(HWND hwnd)
{
  // cleanup per window data
  //
  ViewWndData* data = SetViewWndData(hwnd, 0);
  delete data;

  TOleWin* oleWinObj = GetOleWinObj(hwnd);

  //
  // Retrieve and cleanup our menu
  //
  HMENU hMenu = oleWinObj->GetWinMenu();
  if (hMenu)
    DestroyMenu(hMenu);

  // Allow OLE Helper to perform cleanup
  //
  oleWinObj->OnDestroy();

  // Cleanup C++ object
  //
  delete oleWinObj;
  FORWARD_WM_DESTROY(hwnd, ViewWnd_DefProc);
}


//
//
//
void
ViewWnd_OnMDIActivate(HWND hwnd, BOOL fActive, HWND /*hwndActivate*/,
                      HWND /*hwndDeactivate*/)
{
  //
  // Reset menu when we're deactivated
  //
  if (!fActive) {
    MainWnd_SetMenu(GetFrame(), 0);
  } else {
    //
    // Set the child's menu when it's activated
    //
    TOleWin* oleWinObj = GetOleWinObj(hwnd);
    HMENU currentMenu  = oleWinObj->GetMergedMenu();
    if (!currentMenu)
      currentMenu = oleWinObj->GetWinMenu();

    MainWnd_SetMenu(GetFrame(), currentMenu);
  }
}


//
//
//
void
ViewWnd_OnSetFocus(HWND hwnd, HWND hwndOldFocus)
{
  GetOleWinObj(hwnd)->OnSetFocus(hwndOldFocus);
}


//
// Handles WM_PAINT message
//
void
ViewWnd_OnPaint(HWND hwnd)
{
  PAINTSTRUCT ps;
  HDC dc = BeginPaint(hwnd, &ps);

  HPEN oldPen;
  ViewWndData* data = GetViewWndData(hwnd);
  if (data) {
    // go through array of lines
    //
    TLinesIterator linesIter(*data->Lines);
    while (linesIter) {
      // about to draw a line
      //
      TLine line = linesIter.Current();
      HPEN pen = CreatePen(PS_INSIDEFRAME, line.PenSize, line.Color);
      oldPen = SelectPen(dc, pen);

      // go through the points in a line
      //
      TPointsIterator pointsIter(line);
      bool firstPoint = true;

      while (pointsIter) {
        TPoint point = pointsIter.Current();
        if (firstPoint) {
          MoveToEx(dc, point.x, point.y, 0);
          firstPoint = false;
        } else {
          LineTo(dc, point.x, point.y);
        }
        pointsIter++;
      }

      SelectPen(dc, oldPen);
      DeletePen(pen);

      linesIter++;
    }
  }

  // OLE Helper will draw embedded parts
  //
  GetOleWinObj(hwnd)->OnPaint(dc, ps);

  EndPaint(hwnd, &ps);
}


//
// Handles WM_SIZE message
//
void
ViewWnd_OnSize(HWND hwnd, uint /*state*/, int /*cx*/, int /*cy*/)
{
  // Inform OLE Helper object that we've been resized
  //
  GetOleWinObj(hwnd)->OnSize();
}


//
// Handles CM_FILESAVEAS command
//
void
ViewWnd_OnFileSaveAs(HWND hwnd)
{
  ViewWndData* data = GetViewWndData(hwnd);
  if (data) {
    // Prompt user for file name
    //
    if (GetSaveFileName(hwnd, Filter, FileName, sizeof(FileName))) {
      // Create the file
      //
      TOcDocument* doc = GetOleWinObj(hwnd)->GetOcDoc();
      if (doc) {
        try {
          doc->SaveToFile(FileName);

          // Save the embedded objects
          //
          doc->SaveParts(0, true);

          // write out user data
          //
          TOcStorage* storage = doc->GetStorage();
          if (storage) {
            // create a storage within the file and save our data into it
            //
            TOcStream stream(*storage, DEFDESC, true, STGM_WRITE);

            int numLines = data->Lines->GetItemsInContainer();
            stream.Write(&numLines, sizeof numLines);

            // go through array of lines
            //
            TLinesIterator linesIter(*data->Lines);
            while (linesIter) {
              // get a line
              //
              TLine line = linesIter.Current();
              int numPoints = line.GetItemsInContainer();

              // save info about the line
              //
              stream.Write(&numPoints, sizeof numPoints);
              stream.Write(&line.Color, sizeof line.Color);
              stream.Write(&line.PenSize, sizeof line.PenSize);

              // save the points in the line
              //
              TPointsIterator pointsIter(line);
              while (pointsIter) {
                TPoint point = pointsIter.Current();
                stream.Write(&point, sizeof point);
                pointsIter++;
              }
              linesIter++;
            }

            stream.Commit(STGC_DEFAULT);
          }
          doc->GetStorage()->Commit(STGC_DEFAULT);

          // Update our caption with new file name
          //
          SetWindowText(hwnd, FileName);
        }

        catch(TXOle& xole) {
          MessageBox(hwnd, xole.why().c_str(), "EXCEPTION", MB_OK);
        }
      }
    }
  }
}


//
// Handles CM_FILEOPEN command by loading saved parts and line data
// (Variable 'FileName' contains the filename at this point)
//
void
ViewWnd_OnFileOpen(HWND hwnd)
{
  ViewWndData* data = GetViewWndData(hwnd);
  if (data) {
    TOcDocument* doc = GetOleWinObj(hwnd)->GetOcDoc();
    if (doc) {
      try {
        doc->SetStorage(FileName);
        // load embedded objects
        //
        doc->LoadParts();

        TOcStorage* storage = doc->GetStorage();
          if (storage) {
            // open the stream that contains the lines
            //
            TOcStream stream(*storage, DEFDESC, false, STGM_READ);

            // how many lines?
            //
            int numLines;
            stream.Read(&numLines, sizeof numLines);
            for (int i=0; i<numLines; i++) {
              // read the info about the line
              //
              int numPoints;
              stream.Read(&numPoints, sizeof(numPoints));
              stream.Read(&CurrentColor, sizeof(CurrentColor));
              stream.Read(&CurrentPenSize, sizeof(CurrentPenSize));
              ScratchLine = new TLine(CurrentPenSize, CurrentColor);

              // read the points
              //
              for (int j=0; j<numPoints; j++) {
                TPoint p;
                stream.Read(&p, sizeof p);
                ScratchLine->Add(p);
              }
              data->Lines->Add(*ScratchLine);
              delete ScratchLine;
              ScratchLine = 0;
            }
          InvalidateRect(hwnd, NULL, true);
        }
        SetWindowText(hwnd, FileName);
      }
      catch(TXOle& xole) {
         MessageBox(hwnd, xole.why().c_str(), "EXCEPTION", MB_OK);
      }
    }
  }
}


//
// Display Color Dialog to allow user to select pen color
//
void
ViewWnd_OnChoosePenColor(HWND hwnd)
{
  COLORREF userPal[16];
  memset(&userPal, 255, 16*sizeof(COLORREF));
  CHOOSECOLOR cc;
  memset(&cc, 0, sizeof cc);
  cc.lStructSize = sizeof cc;
  cc.hwndOwner = hwnd;
  cc.rgbResult = RGB(0, 0, 0);
  cc.lpCustColors = userPal;
  if (ChooseColor(&cc)) {
    CurrentColor = cc.rgbResult;
  }
}


//
// Handles WM_INITDIALOG for PenSize dialog
//
bool
PenDlg_OnInitDialog(HWND hwnd, HWND /*hwndFocus*/, LPARAM /*lParam*/)
{
  SetDlgItemInt(hwnd, IDC_PENSIZE, CurrentPenSize, false);
  return true;
}


//
// Handles WM_CLOSE message for PenSize dialog
//
void
PenDlg_OnClose(HWND hwnd)
{
  EndDialog(hwnd, IDCANCEL);
}


//
// Handles WM_COMMAND message from PenSize dialog
//
void
PenDlg_OnCommand(HWND hwnd, int id, HWND /*hwndCtl*/, uint /*codeNotify*/)
{
  switch (id) {
    case IDOK: {
      int penSize;
      int translated;
      penSize = GetDlgItemInt(hwnd, IDC_PENSIZE, &translated, FALSE);

#if !defined(NDEBUG)
      wsprintf(FileName, "ps = %d\n\r", penSize);
      OutputDebugString(FileName);
#endif

      if (penSize < 1 || 25 < penSize) {
        MessageBox(hwnd, "Pensize out of range.", "Error", MB_OK);
      } else {
        CurrentPenSize = penSize;
        EndDialog(hwnd, IDOK);
      }
      break;
    }
    case IDCANCEL: {
      EndDialog(hwnd, IDCANCEL);
      break;
    }
  }
}


//
// Callback of dialog which allows user to change pen size
//
bool CALLBACK _export
PenSizeDlgProc(HWND hwnd, uint message, WPARAM wParam, LPARAM lParam)
{
  switch (message) {
   case WM_INITDIALOG:
        HANDLE_WM_INITDIALOG(hwnd, wParam, lParam, PenDlg_OnInitDialog);
        return true;

   case WM_CLOSE:
        HANDLE_WM_CLOSE(hwnd, wParam, lParam, PenDlg_OnClose);
        return true;

   case WM_COMMAND:
        HANDLE_WM_COMMAND(hwnd, wParam, lParam, PenDlg_OnCommand);
        return true;
  }
  return false;
}


//
// Displays dialog which allows user to change pen size
//
void
ViewWnd_OnChoosePenSize(HWND hwnd)
{
  FARPROC proc = MakeProcInstance((FARPROC)PenSizeDlgProc, HInstance);
  DialogBox(HInstance, MAKEINTRESOURCE(ID_CHOOSEPENSIZE),
            hwnd, (DLGPROC)proc);
  FreeProcInstance(proc);
}


//
// Handles WM_COMMAND messages
//
void
ViewWnd_OnCommand(HWND hwnd, int id, HWND /*hwndCtl*/, uint /*codeNotify*/)
{
  switch(id) {
    case CM_FILEOPEN:
      ViewWnd_OnFileOpen(hwnd);
      break;

    case CM_FILESAVE:
    case CM_FILESAVEAS:
      ViewWnd_OnFileSaveAs(hwnd);
      break;

    case CM_PENCOLOR:
      ViewWnd_OnChoosePenColor(hwnd);
      break;

    case CM_PENSIZE:
      ViewWnd_OnChoosePenSize(hwnd);
      break;

    default:
      // Pass any command IDs that we're not handling to the OLE Helper
      // object. It will handle issues such as activating OLE UI dialogs.
      //
      GetOleWinObj(hwnd)->OnCommand(id);
      break;
  }
}


//
// Handles WM_LBUTTONDOWN message
//
void
ViewWnd_OnLButtonDown(HWND hwnd, bool fDoubleClick, int x, int y, uint keyFlags)
{
  // Pass LButtonDown/LButtonDblClk to the OLE Helper object.
  // It will deactiate/activate any OLE part if necessary
  //
  if (fDoubleClick)
    GetOleWinObj(hwnd)->OnLButtonDblClk(x, y, keyFlags);
  else {
    if (!GetOleWinObj(hwnd)->OnLButtonDown(x, y, keyFlags)) {
      if (!GetOleWinObj(hwnd)->SelectEmbedded()) {
        SetCapture(hwnd);
        MouseCaptured = true;
        ScratchLine = new TLine(CurrentPenSize, CurrentColor);
        TPoint p(x, y);
        ScratchLine->Add(p);

        CurPen = CreatePen(PS_INSIDEFRAME, CurrentPenSize, CurrentColor);
        DC = GetDC(hwnd);
        OldPen = SelectPen(DC, CurPen);
        MoveToEx(DC, x, y, 0);
      }
    }
  }
}


//
// Handles WM_MOUSEMOVE message
//
void
ViewWnd_OnMouseMove(HWND /*hwnd*/, int x, int y, uint /*keyFlags*/)
{
  if (MouseCaptured) {
    TPoint p(x, y);

    ScratchLine->Add(p);
    LineTo(DC, x, y);
  }
}


//
// Handles WM_LBUTTONUP message
//
void
ViewWnd_OnLButtonUp(HWND hwnd, int x, int y, uint /*keyFlags*/)
{
  if (MouseCaptured) {
    TPoint p(x, y);
    ScratchLine->Add(p);

    LineTo(DC, x, y);
    SelectPen(DC, OldPen);
    ReleaseDC(hwnd, DC);

    DeletePen(CurPen);

    ViewWndData* data = GetViewWndData(hwnd);
    data->Lines->Add(*ScratchLine);

    delete ScratchLine;
    ScratchLine = 0;

    ReleaseCapture();
    MouseCaptured = false;
  }
}


//
// Handles WM_INITMENU message
//
void
ViewWnd_OnInitMenu(HWND hwnd, HMENU hMenu)
{
  //
  // Allow OLE Helper object to enable/disable OLE related menuitems
  //
  GetOleWinObj(hwnd)->OnInitMenu(hMenu);
}


//
// Subdispatch OC_... messages
//
LRESULT
ViewWnd_OnOcEvent(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
  // Pass the WM_OCEVENT from OCF to the OLE Helper Object
  //
  return GetOleWinObj(hwnd)->OnOcEvent(wParam, lParam);
}


//
// Standard message-handler routine for view window
//
LRESULT CALLBACK _export
ViewWndProc(HWND hwnd, uint message, WPARAM wParam, LPARAM lParam)
{
  switch (message) {
    HANDLE_MSG(hwnd, WM_CREATE,         ViewWnd_OnCreate);
    HANDLE_MSG(hwnd, WM_DESTROY,        ViewWnd_OnDestroy);
    HANDLE_MSG(hwnd, WM_PAINT,          ViewWnd_OnPaint);
    HANDLE_MSG(hwnd, WM_COMMAND,        ViewWnd_OnCommand);
    HANDLE_MSG(hwnd, WM_LBUTTONDOWN,    ViewWnd_OnLButtonDown);
    HANDLE_MSG(hwnd, WM_LBUTTONDBLCLK,  ViewWnd_OnLButtonDown);
    HANDLE_MSG(hwnd, WM_MOUSEMOVE,      ViewWnd_OnMouseMove);
    HANDLE_MSG(hwnd, WM_LBUTTONUP,      ViewWnd_OnLButtonUp);
    HANDLE_MSG(hwnd, WM_INITMENU,       ViewWnd_OnInitMenu);
    HANDLE_MSG(hwnd, WM_MDIACTIVATE,    ViewWnd_OnMDIActivate);
    HANDLE_MSG(hwnd, WM_SETFOCUS,       ViewWnd_OnSetFocus);

    case WM_OCEVENT:
      return ViewWnd_OnOcEvent(hwnd, wParam, lParam);
  }

  return ViewWnd_DefProc(hwnd, message, wParam, lParam);
}

