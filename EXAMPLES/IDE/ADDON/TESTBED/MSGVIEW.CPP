/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  msgview.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.16  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\imake.h>
#include <ideaddon\iproj.h>
#include <ideaddon\iide.h>
#include <windowsx.h>

#include "msgview.h"

extern HINSTANCE ghInst;

#define MV_FOREGROUND "Foreground"

struct INotificationMonitor : public IProjectClient
                            , public IMakeClient {
};

class NotificationMonitor : public IUnknownImp<INotificationMonitor> {
public:
  NotificationMonitor();
  ~NotificationMonitor();

  //.... IProjectClient methods ....
   virtual void OpenNotify( IPolyString * projectName );
   virtual void CloseNotify();
   virtual void NodeDeleteNotify( ProjectNode node );
   virtual void NodeAddNotify( ProjectNode node );
   virtual void NodeCopyNotify( ProjectNode, ProjectNode, BOOL ) {}
   virtual void NodeMoveNotify( ProjectNode, ProjectNode ) {}
   virtual void NodeChangeNotify( ProjectNode ) {}
   virtual void DependencyQueryResponder( ProjectNode node, 
                                          IPolyString * outputName );
   virtual BOOL HandleAddNodeUI() { return FALSE; }
                                          

   // IMakeClient
   virtual void MakeBeginNotify();
   virtual void MakeEndNotify();


           void SetHwnd(HWND hwnd);
           void Stop();
protected:
  // private variables
  IProjectServer* d_projectServer;
  IMakeServer*    d_makeServer;

  HWND            d_hwndList;

  int            d_projectOpened;
};


NotificationMonitor::NotificationMonitor() 
                    : IUnknownImp<INotificationMonitor>(IID_IUnknown) {
  d_projectServer = GET_INTERFACE( IProjectServer );
  d_makeServer  = GET_INTERFACE(IMakeServer);

  AddRef();
  d_projectServer->RegisterProjectClient( this );

  AddRef();
  d_makeServer->RegisterMakeClient( this );

};

void NotificationMonitor::Stop() {
  AddRef();
  d_makeServer->UnRegisterMakeClient( this );

  AddRef();
  d_projectServer->UnregisterProjectClient(this);
};

NotificationMonitor::~NotificationMonitor() {

  d_projectServer->Release();
  d_makeServer->Release();
};


void NotificationMonitor::SetHwnd(HWND hwnd) {
  d_hwndList = hwnd;
  if ( d_projectOpened ) {
    OpenNotify(0);
  }

};

//
// IProjectClient methods
//
void NotificationMonitor::OpenNotify( IPolyString * projectName ) {
  d_projectOpened = 1;
  if ( !IsWindow(d_hwndList) ) return;

  ListBox_AddString(d_hwndList, "OpenNotify");
  if (projectName)
    projectName->Release();
  d_projectOpened = 0;
}
//.............................................................................
void NotificationMonitor::CloseNotify() {
  if ( !IsWindow(d_hwndList) ) return;

  ListBox_AddString(d_hwndList, "CloseNotify");
}

void NotificationMonitor::NodeDeleteNotify( ProjectNode ) {
  if ( !IsWindow(d_hwndList) ) return;

  ListBox_AddString(d_hwndList, "NodeDeleteNotify");
}
//.............................................................................
void NotificationMonitor::NodeAddNotify( ProjectNode ) {
  if ( !IsWindow(d_hwndList) ) return;

  ListBox_AddString(d_hwndList, "NodeAddNotify");
}
//.............................................................................
void NotificationMonitor::DependencyQueryResponder( ProjectNode,
                          IPolyString *) {
}

void NotificationMonitor::MakeBeginNotify() {
  if ( !IsWindow(d_hwndList) ) return;

  ListBox_AddString(d_hwndList, "MakeBeginNotify");
};

void NotificationMonitor::MakeEndNotify() {
  if ( !IsWindow(d_hwndList) ) return;

  ListBox_AddString(d_hwndList, "MakeEndNotify");
};


/******************************************************************************
*
*
* MonitorViewClient
*
*
******************************************************************************/

class MonitorViewClient : public IViewClient {
public:
  MonitorViewClient();
  ~MonitorViewClient();

  //IUnknown members
  STDMETHODIMP QueryInterface (THIS_ REFIID, LPVOID FAR *);
  STDMETHODIMP_(ULONG) AddRef (THIS) { return m_RefCount++; }
  STDMETHODIMP_(ULONG) Release (THIS)
      {return --m_RefCount == 0 ? (delete this, 0) : m_RefCount; }

  virtual HWND      GetHwnd();
  virtual long      GetRestoreDataLen();
  virtual void*    GetRestoreData();
  virtual BOOL      CanClose();
  virtual unsigned  CommandSupported( IPolyString* );
  virtual void      ExecuteCommand( IPolyString* );
  virtual HWND      Create(IViewParentWnd* wndServer, void * restoreData);
  virtual void      PropertyChangeNotify();

protected:
  HWND                  d_hwnd;
  IViewParentWnd*      d_viewParent;
  NotificationMonitor*  d_monitor;
protected:
  // private variables
  ULONG                m_RefCount;
};

MonitorViewClient::MonitorViewClient() {
  m_RefCount = 1;
  d_hwnd = 0;
  d_viewParent = 0;
  d_monitor = 0;
};

MonitorViewClient::~MonitorViewClient() {
  if (d_viewParent) {
    d_viewParent->Release();
  }
  if ( IsWindow(d_hwnd) )
    DestroyWindow(d_hwnd);
  if (d_monitor) {
    d_monitor->Stop();
    d_monitor->Release();
  }
};


STDMETHODIMP
MonitorViewClient::QueryInterface (REFIID riid, LPVOID FAR* ppobj)
{
  if ((riid == IID_IUnknown)/* || (riid == IID_PUBLIC_)*/)
  {
    *ppobj = (LPVOID)this;
    AddRef();
   return NOERROR;
  }

  *ppobj = NULL;
  return ResultFromScode(E_NOINTERFACE);
}

HWND MonitorViewClient::Create(IViewParentWnd* wndServer, void * /*restoreData*/) {

  d_viewParent = wndServer;
  HWND hwndParent = wndServer->GetHwnd();
  //
  // just create a window listbox control
  //
  d_hwnd = CreateWindowEx(
                            0,                      /* no extended styles         */
                            "LISTBOX",              /* class name                 */
                            "",                    /* window name                */
                            WS_CHILDWINDOW |        /* overlapped window           */
                            WS_VISIBLE  |
                            WS_HSCROLL |            /* horizontal scroll bar       */
                            WS_VSCROLL,            /* vertical scroll bar        */
                            CW_USEDEFAULT,          /* default horizontal position */
                            CW_USEDEFAULT,          /* default vertical position   */
                            CW_USEDEFAULT,          /* default width               */
                            CW_USEDEFAULT,          /* default height             */
                            (HWND) hwndParent,      /* no parent or owner window   */
                            (HMENU) NULL,          /* class menu used            */
                            NULL/*hinstance*/,      /* instance handle             */
                            NULL);                  /* no window creation data     */

  d_monitor = new NotificationMonitor;
  d_monitor->SetHwnd(d_hwnd);
  return d_hwnd;

};

HWND MonitorViewClient::GetHwnd()
{
  return d_hwnd;
};

long  MonitorViewClient::GetRestoreDataLen()
{
  //
  // there is nothing to save.
  //
  return 0; 
};

//
// Save the data user entered to the destop file
//
void* MonitorViewClient::GetRestoreData()
{
  //
  // there is nothing to save.
  //
  return NULL;
};

BOOL  MonitorViewClient::CanClose()
{
  return 1;
};

unsigned MonitorViewClient::CommandSupported(IPolyString* cmdStr)
{
  cmdStr->Release();
  return CMD_UNKNOWN;
}


void MonitorViewClient::ExecuteCommand(IPolyString* cmdStr)
{
  cmdStr->Release();
}

void MonitorViewClient::PropertyChangeNotify() {

};
/************************************************************************************************************************/

MonitorViewFactory::MonitorViewFactory(IViewType* MonitorView) {
  m_RefCount = 1;

  MonitorView->Init(this
                    , MakePolyString("AddOnMonitorView")
                    , /* message region */ 0, 358, 813, 538);
  MonitorView->Release();
};

STDMETHODIMP
MonitorViewFactory::QueryInterface (REFIID riid, LPVOID FAR* ppobj)
{
  if ((riid == IID_IUnknown)/* || (riid == IID_PUBLIC_)*/)
  {
    *ppobj = (LPVOID)this;
    AddRef();
    return NOERROR;
  }

  *ppobj = NULL;
  return ResultFromScode(E_NOINTERFACE);
}

IViewClient* MonitorViewFactory::CreateView(IViewParentWnd* wndServer, void * restoreData) {
  MonitorViewClient* viewClient = new MonitorViewClient;
  viewClient->Create(wndServer, restoreData);
  return viewClient;
};

void MonitorViewFactory::InitializeProperty(IViewType* viewType) {
  viewType->Release();
}


//.............................................................................
