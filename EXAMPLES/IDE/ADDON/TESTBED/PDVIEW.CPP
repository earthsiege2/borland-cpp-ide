/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  pdview.cpp
  Created: 12/1/95
  Copyright (c) 1995, Borland International
  $Revision:   1.16  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "pdview.h"
#include <windowsx.h>

extern HINSTANCE ghInst;
extern HWND CreateProjectDetailWindow(HINSTANCE hInstance, HWND hwndParent);


/******************************************************************************
*
*
* ProjectDetailViewClient
*
*
******************************************************************************/

class ProjectDetailViewClient : public IViewClient {
public:
  ProjectDetailViewClient();
  ~ProjectDetailViewClient();

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
   virtual void     PropertyChangeNotify();


  HWND    Create(IViewParentWnd* wndServer, void * restoreData);
protected:
  HWND  d_hwnd;
  IViewParentWnd* d_viewParent;

protected:
  // private variables
  ULONG    m_RefCount;
};

ProjectDetailViewClient::ProjectDetailViewClient() {
  m_RefCount = 1;
  d_hwnd = 0;
  d_viewParent = 0;
};

ProjectDetailViewClient::~ProjectDetailViewClient() {
  if (d_viewParent) {
    d_viewParent->Release();
  }
  if ( IsWindow(d_hwnd) )
    DestroyWindow(d_hwnd);
};


STDMETHODIMP
ProjectDetailViewClient::QueryInterface (REFIID riid, LPVOID FAR* ppobj)
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


HWND ProjectDetailViewClient::Create(IViewParentWnd* wndServer, void * /*restoreData*/) {

  d_viewParent = wndServer;
  HWND hwndParent = wndServer->GetHwnd();

  d_hwnd = CreateProjectDetailWindow(ghInst, hwndParent);
  return d_hwnd;

};

HWND ProjectDetailViewClient::GetHwnd()
{
  return d_hwnd;
};

long  ProjectDetailViewClient::GetRestoreDataLen()
{
  //
  // there is nothing to save.
  //
  return 0; 
};

//
// Save the data user entered to the destop file
//
void* ProjectDetailViewClient::GetRestoreData()
{
  //
  // there is nothing to save.
  //
  return NULL;
};

BOOL  ProjectDetailViewClient::CanClose()
{
  return 1;
};

unsigned ProjectDetailViewClient::CommandSupported(IPolyString* cmdStr)
{
  cmdStr->Release();
  return CMD_UNKNOWN;
}


void ProjectDetailViewClient::ExecuteCommand(IPolyString* cmdStr)
{
  cmdStr->Release();
}

void ProjectDetailViewClient::PropertyChangeNotify() {
};

/******************************************************************************
*
*
* ProjectDetailViewFactory
*
*
******************************************************************************/

ProjectDetailViewFactory::ProjectDetailViewFactory(IViewType* messageView) {
  m_RefCount = 1;

  messageView->Init(this
                    , MakePolyString("AddOnProjectDetailView")
                    , /* project region */ 0, 358, 813, 538);
  messageView->Release();
};

STDMETHODIMP
ProjectDetailViewFactory::QueryInterface (REFIID riid, LPVOID FAR* ppobj)
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

IViewClient* ProjectDetailViewFactory::CreateView(IViewParentWnd* wndServer, void * restoreData) {
  ProjectDetailViewClient* viewClient = new ProjectDetailViewClient;
  viewClient->Create(wndServer, restoreData);
  return viewClient;
};

void ProjectDetailViewFactory::InitializeProperty(IViewType* viewType) {
  viewType->Release();
}

//.............................................................................
