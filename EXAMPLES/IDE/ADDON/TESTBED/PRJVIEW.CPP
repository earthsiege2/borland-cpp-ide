/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  prjview.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.13  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\iproj.h>
#include <ideaddon\iide.h>
#include "prjview.h"
#include "prjwin.h"

extern HINSTANCE ghInst;

/******************************************************************************
*
* ProjectViewClient:  Demonstrates the implementations and uses of various
*                    Addon interfaces
*
* Interfaces implemented
*
*  IUserViewFactory
*  IViewClient
*
* Interfaces used
* 
*  IProjectServer
*  IMakeServer
*  IToolServer
*  IProjectServer
*  IProjectClient
*
******************************************************************************/

class ProjectViewClient : public IUnknownImp<IProjectViewClient> {
public:
  ProjectViewClient();
  ~ProjectViewClient();

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

  //
  // IViewClient methods
  //
  virtual HWND      GetHwnd();
  virtual long      GetRestoreDataLen();
  virtual void*    GetRestoreData();
  virtual BOOL      CanClose();
  virtual unsigned  CommandSupported( IPolyString* );
  virtual void      ExecuteCommand( IPolyString* );
  virtual HWND      Create(IViewParentWnd* wndServer, void * restoreData);
  virtual void      PropertyChangeNotify();

  virtual void      Stop();
protected:
  HWND            d_hwnd;
  IViewParentWnd* d_viewParent;

protected:
  ProjectNode    d_node;
  IProjectServer* d_projectServer;

  TreeModel*      d_tm;
};

ProjectViewClient::ProjectViewClient()
                  : IUnknownImp<IProjectViewClient>(IID_IUnknown) {
  d_hwnd = 0;
  d_viewParent = 0;
  d_projectServer = GET_INTERFACE( IProjectServer );

  AddRef();
  d_projectServer->RegisterProjectClient( this );
};

void ProjectViewClient::Stop() {
  AddRef();
  d_projectServer->UnregisterProjectClient( this );
}

ProjectViewClient::~ProjectViewClient() {
  if (d_viewParent) {
    d_viewParent->Release();
  }
  d_projectServer->Release();
  if ( IsWindow(d_hwnd) )
    DestroyWindow(d_hwnd);
};


HWND ProjectViewClient::Create(IViewParentWnd* wndServer, void * restoreData) {
  d_viewParent = wndServer;
  //
  // create our window
  //
  d_hwnd = CreateTreeWindow(ghInst, wndServer->GetHwnd());
  
  d_tm = GetTreeModelFromHWND(d_hwnd);
  if (restoreData) {
    //
    // If there is a valid restoreData, initialize the tree using the data as
    // the top node
    //
    d_node = *(ProjectNode*)restoreData;
  } else {
    //
    // Default the top node to project top node by setting d_node to 0.
    //
    d_node = 0;
  }
  d_tm->SetTopNode(d_node);
  AddRef();
  d_tm->SetProjectViewClient(this);

  return d_hwnd;

};

HWND ProjectViewClient::GetHwnd()
{
  return d_hwnd;
};

long  ProjectViewClient::GetRestoreDataLen()
{
  //
  // return the size of the data that is to be stored in destop file
  //
  return sizeof(d_node);
};

void* ProjectViewClient::GetRestoreData()
{
  //
  // The data saved here is the same as the restoreData argument
  // in IViewClient::Create(IViewParentWnd* wndServer, void * restoreData).
  //

  //
  // have to keep the return pointer valid, so we copy it here
  //
  d_node = d_tm->GetTopNode();
  //
  // return a valid pointer
  //
  return &d_node;
  
};

BOOL ProjectViewClient::CanClose()
{
  //
  // It is ok to close this window.
  //
  return 1;
};

unsigned ProjectViewClient::CommandSupported(IPolyString* cmdStr)
{
  cmdStr->Release();
  return CMD_UNKNOWN;
}


void ProjectViewClient::ExecuteCommand(IPolyString* cmdStr)
{
  cmdStr->Release();
}


void ProjectViewClient::PropertyChangeNotify() {
};


//
// IProjectClient methods
//
void ProjectViewClient::OpenNotify( IPolyString * projectName ) {
  projectName->Release();
}
//.............................................................................
void ProjectViewClient::CloseNotify() {
}

//
//  process node delete/add notification here.
//
//  NOTE: We do not get node change or node movement notifications
//
void ProjectViewClient::NodeDeleteNotify( ProjectNode node ) {
  d_tm->OnNodeDeleted(node);
}
//.............................................................................
void ProjectViewClient::NodeAddNotify( ProjectNode node ) {
  d_tm->OnNodeAdd(node);
}
//.............................................................................
void ProjectViewClient::DependencyQueryResponder( ProjectNode /*node*/, 
                                       IPolyString * /*outputName*/ ) {}


/******************************************************************************
*
*
* ProjectViewFactory
*
*
******************************************************************************/

ProjectViewFactory::ProjectViewFactory(IViewType* projectViewType) 
                  : IUnknownImp<IUserViewFactory>(IID_IUnknown)
{
  //
  // View type is "AddOnProjectView" and this view
  //  will stay in the project region
  //
  IPolyString* viewType = MakePolyString("AddOnProjectView");
  projectViewType->Init(this, viewType, /* project region */ 0, 358, 813, 538);

  projectViewType->Release();
};

void ProjectViewFactory::InitializeProperty(IViewType* projectViewType) {
  projectViewType->Release();
};

IViewClient* ProjectViewFactory::CreateView(IViewParentWnd* wndServer, void * restoreData) {
  ProjectViewClient* viewClient = new ProjectViewClient;
  viewClient->Create(wndServer, restoreData);
  return viewClient;
};


