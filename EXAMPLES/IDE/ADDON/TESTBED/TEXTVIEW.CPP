/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  textview.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.13  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop
#include <ideaddon\isbar.h>
#include <windowsx.h>

#include "textview.h"

/******************************************************************************
*
*
* TextViewClient
*
*
******************************************************************************/
 struct IViewClientFile : IViewClient, IViewFile {};

class TextViewClient : public IUnknownImp<IViewClientFile> {
public:
  TextViewClient();
  ~TextViewClient();

  //IUnknown members
  STDMETHODIMP QueryInterface (THIS_ REFIID, LPVOID FAR *);

  virtual HWND  GetHwnd();
  virtual long  GetRestoreDataLen();
  virtual void* GetRestoreData();
  virtual BOOL  CanClose();

  virtual unsigned CommandSupported( IPolyString* );
  virtual void ExecuteCommand( IPolyString* );
  virtual void PropertyChangeNotify();
  HWND    Create(IViewParentWnd* wndServer, void * restoreData);

  //
  // IViewFile
  //
  virtual BOOL IsDirty();
  virtual BOOL Save();
  virtual BOOL SaveAs(IPolyString* FileName);
  virtual BOOL Close();
  virtual BOOL Print(BOOL noDialogs);

protected:
  HWND            d_hwnd;
  IViewParentWnd* d_viewParent;
  char d_textBuf[256];
};

TextViewClient::TextViewClient()
              : IUnknownImp<IViewClientFile>(IID_IUnknown) {
  d_hwnd = 0;
  d_viewParent = 0;
};

TextViewClient::~TextViewClient() {
  if (d_viewParent) {
    d_viewParent->Release();
  }
  if ( IsWindow(d_hwnd) )
    DestroyWindow(d_hwnd);
};


STDMETHODIMP
TextViewClient::QueryInterface (REFIID riid, LPVOID FAR* ppobj)
{
  if ((riid == IID_IUnknown) || (riid == IID_Addon_IViewClient) ) {
    IViewClient* vc = this;
    *ppobj = vc;
  } else if (riid == IID_Addon_IViewFile) {
    IViewFile* vf = this;
    *ppobj = vf;
  } else {
    *ppobj = NULL;
    return ResultFromScode(E_NOINTERFACE);
  }
  ((LPUNKNOWN)*ppobj)->AddRef();
  return NOERROR;
}

static WNDPROC OldViewParentWndProc;

LONG APIENTRY ViewParentWndProc(
  HWND hWnd,                /* window handle                   */
  UINT message,            /* type of message                */
  UINT wParam,              /* additional information         */
  LONG lParam)              /* additional information         */
{
  if (message == WM_COMMAND) {
    WORD wNotifyCode = HIWORD(wParam);
    //
    // the edit control is modified, notify parent about the new modified state
    //
    if ( wNotifyCode == EN_CHANGE) {
      HWND hwndChild = GetWindow(hWnd, GW_CHILD);
      IViewParentWnd* wndServer =
            (IViewParentWnd*)GetWindowLong(hwndChild, GWL_USERDATA);
      if ( wndServer ) {
        wndServer->UpdateModifyState();
      }
    }
  };
  return OldViewParentWndProc(hWnd, message, wParam, lParam);
};

HWND TextViewClient::Create(IViewParentWnd* wndServer, void * restoreData) {

  d_viewParent = wndServer;
  HWND parentHwnd = wndServer->GetHwnd();

  //
  // just create a window edit control
  //
  d_hwnd = CreateWindowEx(  WS_EX_CLIENTEDGE,      /* extended styles            */
                            "EDIT",                /* class name                  */
                            "",                    /* window name                */
                            WS_CHILDWINDOW |        /* overlapped window           */
                            ES_MULTILINE|
                            WS_VISIBLE  |
                            WS_HSCROLL |            /* horizontal scroll bar       */
                            WS_VSCROLL,            /* vertical scroll bar        */
                            CW_USEDEFAULT,          /* default horizontal position */
                            CW_USEDEFAULT,          /* default vertical position   */
                            CW_USEDEFAULT,          /* default width               */
                            CW_USEDEFAULT,          /* default height             */
                            (HWND) parentHwnd,      /* parent or owner window     */
                            (HMENU) NULL,          /* class menu used            */
                            NULL/*hinstance*/,      /* instance handle             */
                            NULL);                  /* no window creation data     */
  //
  // limit the number of characters allowed
  //
  Edit_LimitText(d_hwnd, sizeof(d_textBuf) - 1);

  //
  // initialize the data with the data from desktop file
  //
  if (restoreData)
    SetWindowText(d_hwnd, (char*)restoreData);

  Edit_SetModify(d_hwnd, FALSE);
  SetWindowLong(d_hwnd, GWL_USERDATA, (LONG)wndServer);
  OldViewParentWndProc = SubclassWindow(parentHwnd, ViewParentWndProc);
  return d_hwnd;

};

HWND TextViewClient::GetHwnd()
{
  return d_hwnd;
};

long  TextViewClient::GetRestoreDataLen()
{
  return GetWindowTextLength(d_hwnd) + /* plus \0 */1; 
};

//
// Save the data user entered to the destop file
//
void* TextViewClient::GetRestoreData()
{

  //
  // This is kind of the problem of the interface.  Client has to make sure the
  //  pointer returned remain valid.
  //
  GetWindowText(
                d_hwnd,        // handle of window or control with text
                d_textBuf,          // address of buffer for text
                sizeof(d_textBuf)  // maximum number of characters to copy
               ); 
  return d_textBuf;
};

BOOL  TextViewClient::CanClose()
{
  int l = GetWindowTextLength(d_hwnd);
  if (l == 0) {
    MessageBox(d_hwnd, "Window can not be closed. Please enter some text.","Addon Text View", MB_OK);
    return 0;
  };
  return 1;
};

unsigned TextViewClient::CommandSupported(IPolyString* cmdStr)
{
  char cmd[256];
  strcpy(cmd, cmdStr->GetCstr());
  cmdStr->Release();

  DWORD dw = Edit_GetSel(d_hwnd);
  WORD start = LOWORD(dw);
  WORD end = HIWORD(dw);

  if (stricmp(cmd, CMD_SELECTALL) == 0) {
    //
    // can not select all if there is no text
    //
    if (GetWindowTextLength(d_hwnd) == 0) {
      return CMD_UNAVAILABLE;
    }
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_CUT) == 0) {
    if ( start == end) {
      return CMD_UNAVAILABLE;
    }
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_CLEAR) == 0) {
    if ( start == end) {
      return CMD_UNAVAILABLE;
    }
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_COPY) == 0) {
    if ( start == end) {
      return CMD_UNAVAILABLE;
    }
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_PASTE) == 0) {
    //
    // always available
    //
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_UNDO) == 0) {
    if ( !Edit_CanUndo(d_hwnd) ) {
      return CMD_UNAVAILABLE;
    }
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_FIND) == 0) {
    //
    // always available
    //
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_REPLACE) == 0) {
    //
    // always available
    //
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_SEARCHAGAIN) == 0) {
    //
    // always available
    //
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_CLOSE) == 0) {
    //
    // always available
    //
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_SAVE) == 0) {
    //
    // always available
    //
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_SAVEAS) == 0) {
    //
    // always available
    //
    return CMD_AVAILABLE;
  } else if (stricmp(cmd, CMD_PRINT) == 0) {
    //
    // always available
    //
    return CMD_AVAILABLE;
  }
  return CMD_UNKNOWN;
}


void TextViewClient::ExecuteCommand(IPolyString* cmdStr)
{

  char cmd[256];
  strcpy(cmd, cmdStr->GetCstr());

  //
  // Let's test status bar here
  //
  IStatusBar* statusBar = (IStatusBar*)GetInterface(IID_Addon_IStatusBar);
  cmdStr->AddRef();
  statusBar->Display(cmdStr);
  statusBar->Release();

  cmdStr->Release();

  if (stricmp(cmd, CMD_SELECTALL) == 0) {
    //
    // select everything
    //
    Edit_SetSel(d_hwnd, 0, -1);
  } else if (stricmp(cmd, CMD_CUT) == 0) {
    SendMessage(d_hwnd, WM_CUT, 0, 0L);
  } else if (stricmp(cmd, CMD_CLEAR) == 0) {
    SendMessage(d_hwnd, WM_CLEAR, 0, 0L);
  } else if (stricmp(cmd, CMD_COPY) == 0) {
    SendMessage(d_hwnd, WM_COPY, 0, 0L);
  } else if (stricmp(cmd, CMD_PASTE) == 0) {
    SendMessage(d_hwnd, WM_PASTE, 0, 0L);
  } else if (stricmp(cmd, CMD_UNDO) == 0) {
    SendMessage(d_hwnd, WM_UNDO, 0, 0L);
  }
}

void TextViewClient::PropertyChangeNotify() {
};

BOOL TextViewClient::IsDirty() {
  return Edit_GetModify(d_hwnd);
};

//
// We are not doing any real file i/o here.
//
BOOL TextViewClient::Save() {
  Edit_SetModify(d_hwnd, FALSE);
  //
  // notify parent that our dirty state has changed
  //
  d_viewParent->UpdateModifyState();
  return TRUE;
};

BOOL TextViewClient::SaveAs(IPolyString* FileName) {
  if (FileName) {
    if (FileName->GetCstr() && *(FileName->GetCstr()) == '\0') {
      //
      // no real file name, release it
      //
      FileName->Release();
      FileName = 0;
    }
  }

  if (!FileName) {
    //
    // We don't have a file name yet. Display SaveAs dialog 
    //  and prompt for file name
    //

    //
    // make up a dummy file name. one would display FileSaveAs dialog
    // to get the filename from user 
    //
    FileName = MakePolyString("aFileName");
  }
  //
  // save file code here
  //

  FileName->Release();
  //
  // notify parent that our dirty state has changed
  //
  Edit_SetModify(d_hwnd, FALSE);
  d_viewParent->UpdateModifyState();
  return TRUE;
};

BOOL TextViewClient::Close() {
  return TRUE;
};

BOOL TextViewClient::Print(BOOL /*noDialogs*/) {
  return TRUE;
}

/******************************************************************************
*
*
* TextViewFactory
*
*
******************************************************************************/

TextViewFactory::TextViewFactory() {
  m_RefCount = 1;
};

STDMETHODIMP
TextViewFactory::QueryInterface (REFIID riid, LPVOID FAR* ppobj)
{
  if ((riid == IID_IUnknown))
  {
    *ppobj = (LPVOID)this;
    ((LPUNKNOWN)*ppobj)->AddRef();
    return NOERROR;
  }

  *ppobj = NULL;
  return ResultFromScode(E_NOINTERFACE);
}

IViewClient* TextViewFactory::CreateView(IViewParentWnd* wndServer, void * restoreData) {
  TextViewClient* viewClient = new TextViewClient;
  viewClient->Create(wndServer, restoreData);
  return viewClient;
};

void TextViewFactory::InitializeProperty(IViewType* viewType) {

  viewType->Release();
}

//.............................................................................
