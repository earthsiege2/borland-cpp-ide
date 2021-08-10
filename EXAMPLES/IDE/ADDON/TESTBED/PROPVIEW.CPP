/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  propview.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.12  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "propview.h"
#include <windowsx.h>

extern HINSTANCE ghInst;

#define TV_FOREGROUND "Foreground"
#define TV_BACKGROUND "Background"

static IViewType* g_viewTypeProperty;
/******************************************************************************
*
*
* PropertyView
*
*
******************************************************************************/

class PropertyView {
public:
  PropertyView(HWND hwnd);
  ~PropertyView();

  void            Paint();
  void            SetFont(const char* fontName
                          , INT fontSize
                          , LONG lfWeight
                          , BYTE lfItalic
                          , BYTE lfUnderline);

  void            SetFClr(COLORREF fClr) { d_fClr = fClr; };
  void            SetBClr(COLORREF bClr) { d_bClr = bClr; };

  COLORREF        d_fClr; 
  COLORREF        d_bClr; 
  HFONT          d_hFont;

protected:

  HWND            d_hwnd;

};

HWND CreateTextWindow(HINSTANCE hInstance, HWND hwndParent);
#define GetPropertyViewFromHWND(hWnd) ((PropertyView*)GetWindowLong(hWnd, GWL_USERDATA))


/******************************************************************************
*
*
* PropertyViewClient
*
*
******************************************************************************/

class PropertyViewClient : public IViewClient {
public:
  PropertyViewClient();
  ~PropertyViewClient();

  //IUnknown members
  STDMETHODIMP QueryInterface (THIS_ REFIID, LPVOID FAR *);
  STDMETHODIMP_(ULONG) AddRef (THIS) { return m_RefCount++; }
  STDMETHODIMP_(ULONG) Release (THIS)
      {return --m_RefCount == 0 ? (delete this, 0) : m_RefCount; }

  virtual HWND  GetHwnd();
  virtual long  GetRestoreDataLen();
  virtual void* GetRestoreData();
  virtual BOOL  CanClose();

  virtual unsigned CommandSupported( IPolyString* );
  virtual void ExecuteCommand( IPolyString* );
  virtual HWND Create(IViewParentWnd* wndServer, void * restoreData);
  virtual void PropertyChangeNotify();

  virtual void SetFont( IPolyString * propName, 
                        IPolyString * fontName, 
                        int fontSize,
                        FontAttribute attrib );
  virtual void SetColor(IPolyString * propName,
                        DWORD fore, 
                        DWORD back );

          void RefreshProperty();
protected:

  HWND            d_hwnd;
  IViewParentWnd* d_viewParent;

protected:
  // private variables
  ULONG    m_RefCount;
};

PropertyViewClient::PropertyViewClient() {
  m_RefCount = 1;
  d_hwnd = 0;
  d_viewParent = 0;
};

PropertyViewClient::~PropertyViewClient() {
  if (d_viewParent) {
    d_viewParent->Release();
  }
  if ( IsWindow(d_hwnd) )
    DestroyWindow(d_hwnd);
};


STDMETHODIMP
PropertyViewClient::QueryInterface (REFIID riid, LPVOID FAR* ppobj)
{
  if ((riid == IID_IUnknown)/* || (riid == IID_PUBLIC_)*/)
  {
    *ppobj = (LPVOID)this;
    ((LPUNKNOWN)*ppobj)->AddRef();
   return NOERROR;
  }

  *ppobj = NULL;
  return ResultFromScode(E_NOINTERFACE);
}

HWND PropertyViewClient::Create(IViewParentWnd* wndServer, void * /*restoreData*/) {

  d_viewParent = wndServer;

  d_hwnd = CreateTextWindow(ghInst, wndServer->GetHwnd());

  //
  // Addon view have to refresh here, since the properties the addon view
  //  register maybe overwritten by what is saved in desktop file
  //
  RefreshProperty();

  return d_hwnd;

};

void PropertyViewClient::RefreshProperty() {
  IPolyString* propName = MakePolyString(TV_FOREGROUND);
  propName->AddRef(); // do an extra addref so it will stick around

  propName->AddRef();
  IPolyString* fontName = g_viewTypeProperty->GetFontName(propName);

  propName->AddRef();
  int fontSize = g_viewTypeProperty->GetFontSize(propName);

  propName->AddRef();
  int attribute = g_viewTypeProperty->GetFontAttribute(propName);

  propName->AddRef();
  DWORD fore = g_viewTypeProperty->GetForegroundColor(propName);

  propName->AddRef();
  DWORD back = g_viewTypeProperty->GetBackgroundColor(propName);

  PropertyView* tv = GetPropertyViewFromHWND(d_hwnd);

  tv->SetFont(fontName->GetCstr()
                      , fontSize
                      , (int)attribute & (int)FA_Bold ? FW_BOLD : FW_NORMAL
                      , (BYTE)((int)attribute & (int)FA_Italic ? 1 : 0)
                      , (BYTE)((int)attribute & (int)FA_Underline ? 1 : 0));

  propName->Release();

  tv->SetFClr(fore);
  tv->SetBClr(back);

  InvalidateRect(d_hwnd, NULL, TRUE);
 
  fontName->Release();

  propName->Release(); // release the extra addref
};


HWND PropertyViewClient::GetHwnd()
{
  return d_hwnd;
};

long  PropertyViewClient::GetRestoreDataLen()
{
  return 0; 
};

//
// Save the data user entered to the destop file
//
void* PropertyViewClient::GetRestoreData()
{
  return NULL;
};

BOOL  PropertyViewClient::CanClose()
{
  return 1;
};

unsigned PropertyViewClient::CommandSupported(IPolyString* cmdStr)
{
  cmdStr->Release();
  return CMD_UNKNOWN;
}


void PropertyViewClient::ExecuteCommand(IPolyString* cmdStr)
{
  cmdStr->Release();
}

void PropertyViewClient::PropertyChangeNotify() {
  RefreshProperty();
};

//
// SetFont() and SetColor() will be obsolete
//
void PropertyViewClient::SetFont( IPolyString * propName, 
                                IPolyString * fontName, 
                                int fontSize,
                                FontAttribute attribute) {

  if (stricmp(TV_FOREGROUND, (char*)propName->GetCstr()) == 0) {

      PropertyView* tv = GetPropertyViewFromHWND(d_hwnd);
      tv->SetFont(fontName->GetCstr()
                          , fontSize
                          , (int)attribute & (int)FA_Bold ? FW_BOLD : FW_NORMAL
                          , (BYTE)((int)attribute & (int)FA_Italic ? 1 : 0)
                          , (BYTE)((int)attribute & (int)FA_Underline ? 1 : 0));
  } 
  propName->Release();
  fontName->Release();
  InvalidateRect(d_hwnd, NULL, TRUE);
};

void PropertyViewClient::SetColor(IPolyString * propName,
                                  DWORD fore, 
                                  DWORD back ) {
  PropertyView* tv = GetPropertyViewFromHWND(d_hwnd);
  if (stricmp(TV_FOREGROUND, (char*)propName->GetCstr()) == 0) {
    tv->SetFClr(fore);
    tv->SetBClr(back);
  }
  propName->Release();
  InvalidateRect(d_hwnd, NULL, TRUE);
};

/******************************************************************************
*
*
* PropertyViewFactory
*
*
******************************************************************************/

PropertyViewFactory::PropertyViewFactory(IViewType* viewType) {
  m_RefCount = 1;

  //
  // View type is "AddOnPropertyView" and this view
  //  will stay in the editor region
  //
  viewType->Init(this
                , MakePolyString("AddOnPropertyView")
                , 0, 0, 813, 358);
  viewType->Release();

  //
  //  This is wrong, I know.
  //
  g_viewTypeProperty = viewType;
};

STDMETHODIMP
PropertyViewFactory::QueryInterface (REFIID riid, LPVOID FAR* ppobj)
{
  if ((riid == IID_IUnknown)/* || (riid == IID_PUBLIC_)*/)
  {
    *ppobj = (LPVOID)this;
    ((LPUNKNOWN)*ppobj)->AddRef();
    return NOERROR;
  }

  *ppobj = NULL;
  return ResultFromScode(E_NOINTERFACE);
}

IViewClient* PropertyViewFactory::CreateView(IViewParentWnd* wndServer, void * restoreData) {
  PropertyViewClient* viewClient = new PropertyViewClient;
  viewClient->Create(wndServer, restoreData);
  return viewClient;
};

void PropertyViewFactory::InitializeProperty(IViewType* viewType) {

  IPolyString * propName;
  IPolyString * fontName;
  propName = MakePolyString(TV_FOREGROUND);
  fontName = MakePolyString("Courier");
  fontName->AddRef(); // addref for TV_BACKGROUND
  viewType->InitFontAndColorProperty(propName, 
                                    fontName,
                                    10,
                                    FA_Underline,
                                    GetSysColor(COLOR_WINDOWTEXT),
                                    GetSysColor(COLOR_WINDOW));

  propName = MakePolyString(TV_BACKGROUND);

  viewType->InitFontAndColorProperty(propName, 
                                    fontName,
                                    10,
                                    FA_Underline,
                                    GetSysColor(COLOR_WINDOWTEXT),
                                    GetSysColor(COLOR_WINDOW));
  viewType->Release();
}

//.............................................................................

PropertyView::PropertyView(HWND hwnd) {
  d_hwnd = hwnd;

  d_hFont = 0;

  d_fClr = GetSysColor(COLOR_WINDOWTEXT);
  d_bClr = GetSysColor(COLOR_WINDOW);
};

PropertyView::~PropertyView() {
  if ( d_hFont )
    DeleteObject(d_hFont);
}

void PropertyView::Paint() {

  PAINTSTRUCT ps;
  HDC hdc;

  hdc = BeginPaint (d_hwnd, &ps) ;
  /* Set text to white and background to green */

  SetTextColor(hdc, d_fClr);
  SetBkColor(hdc, d_bClr);

  HFONT hFontOld = (HFONT)SelectObject(hdc, d_hFont);

  static char t[] = "Font and Color Property";

  RECT rect;
  GetClientRect(d_hwnd, &rect);
  DrawText(hdc, t, -1, &rect, DT_CENTER|DT_VCENTER);

  SelectObject(hdc, hFontOld);

  EndPaint (d_hwnd, &ps) ;
}

void PropertyView::SetFont(const char* fontName
                          , INT fontSize
                          , LONG lfWeight
                          , BYTE lfItalic
                          , BYTE lfUnderline) {

  LOGFONT        lf;
  memset(&lf, 0, sizeof( lf ) );


  strcpy(lf.lfFaceName, fontName);

  HDC hdc = GetDC(d_hwnd);
  lf.lfHeight = -MulDiv(fontSize, GetDeviceCaps(hdc, LOGPIXELSY), 72);
  ReleaseDC(d_hwnd, hdc);

  lf.lfWeight = lfWeight;

  lf.lfItalic = lfItalic;
  lf.lfUnderline = lfUnderline;
  lf.lfStrikeOut = 0;
  lf.lfPitchAndFamily = DEFAULT_PITCH;


  HFONT hFont = CreateFontIndirect(&lf);
  if (hFont && d_hFont)
    DeleteObject(d_hFont);

  d_hFont = hFont;
}

LONG APIENTRY PropertyViewWndProc(
  HWND hWnd,                /* window handle                   */
  UINT message,            /* type of message                */
  UINT wParam,              /* additional information         */
  LONG lParam)              /* additional information         */
{
  PropertyView* pv = GetPropertyViewFromHWND(hWnd);
  switch (message)
  {

    case WM_CREATE:
    {
      // Create the tree view window and initialize its
      // image list
      pv = new PropertyView(hWnd);
      SetWindowLong(hWnd, GWL_USERDATA, (long)pv);
    }
      break;          
    case WM_PAINT:
    {
      pv->Paint();
      return 0;
    }
    case WM_DESTROY:
    {
      delete pv;
      SetWindowLong(hWnd, GWL_USERDATA, 0L);
    }
    default:
      return (DefWindowProc(hWnd, message, wParam, lParam));
  }
  return (0);
}

BOOL RegisterPropertyViewClass(HINSTANCE hInstance)      /* current instance             */
{
  WNDCLASS  wcPropertyView;


  if ( GetClassInfo(hInstance,              // handle of application instance
                    TEXT("PropertyViewWClass"), // address of class name string
                    &wcPropertyView)            // address of structure for class data
      ) {
    return TRUE;
  }

  /* Fill in window class structure with parameters that describe the      */
  /* main window.                                                          */

  wcPropertyView.style = 0;                    
  wcPropertyView.lpfnWndProc = (WNDPROC)PropertyViewWndProc; 
  wcPropertyView.cbClsExtra = 0;              
  wcPropertyView.cbWndExtra = 0;              
  wcPropertyView.hInstance = hInstance;
  wcPropertyView.hIcon = NULL;
  wcPropertyView.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcPropertyView.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wcPropertyView.lpszMenuName = NULL; 
  wcPropertyView.lpszClassName = TEXT("PropertyViewWClass");

  return (RegisterClass(&wcPropertyView));
}

/****************************************************************************
*
*   FUNCTION: CreateTextWindow(HINSTANCE hInstance, HWND hwndParent)
*
*   PURPOSE:  Creates a PropertyView window
*
****************************************************************************/

HWND CreateTextWindow(HINSTANCE hInstance, HWND hwndParent) {

  RegisterPropertyViewClass(hInstance);
  return CreateWindowEx(
                  WS_EX_CLIENTEDGE,
                  TEXT("PropertyViewWClass"),
                  TEXT(""),
                  WS_CHILD|WS_VISIBLE,
                  CW_USEDEFAULT,
                  CW_USEDEFAULT,
                  CW_USEDEFAULT,
                  CW_USEDEFAULT,
                  hwndParent,
                  NULL,
                  hInstance,
                  NULL);
};

//.............................................................................
