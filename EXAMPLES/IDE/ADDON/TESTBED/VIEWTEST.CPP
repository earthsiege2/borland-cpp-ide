/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  viewtest.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.18  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\iproj.h>

#include "viewtest.h"
#include "prjview.h"
#include "textview.h"
#include "msgview.h"
#include "pdview.h"
#include "propview.h"
#include "prjwin.h"
#include "pdwin.h"

/******************************************************************************
*
* This example demonstrates how to create views that belong to different regions
*
******************************************************************************/

static IViewType* g_projectViewType;
static IViewType* g_textViewType;
static IViewType* g_projectDetailViewType;
static IViewType* g_MonitorViewType;
static IViewType* g_propertyViewType;

//
// NOTE: The regions that have been set in the examples is overridden by
//       the script code. Read ssinit.spp for detail
//
ViewTest::ViewTest() 
{
  //
  // Create IViewType and register IUserViewFactory. This must be done
  // during startup.
  //
  
  //
  // Create project view factory
  //
  g_projectViewType = ::CreateViewType();
  if (g_projectViewType == NULL) {
    return;
  }
  //
  // add ref before passed as argument
  //
  g_projectViewType->AddRef();
  new ProjectViewFactory(g_projectViewType);

  //
  // Create text view factory
  //
  g_textViewType = ::CreateViewType();
  if (g_textViewType == NULL) {
    return;
  }

  //
  // Initialize view type diffreently here. This is a less preferred way to do it
  //
  IPolyString* viewType = MakePolyString("AddOnTextView");

  //
  // Editor region set in startup.spp
  //
  g_textViewType->Init(new TextViewFactory, viewType, 0, 0, 813, 358);

  //
  // Create project detail view factory
  //
  g_projectDetailViewType = ::CreateViewType();
  if (g_projectDetailViewType == NULL) {
    return;
  }
  //
  // add ref before passed as argument
  //
  g_projectDetailViewType->AddRef();
  new ProjectDetailViewFactory(g_projectDetailViewType);

  //
  // Create Monitor view factory
  //
  g_MonitorViewType = ::CreateViewType();
  if (g_MonitorViewType == NULL) {
    return;
  }
  //
  // add ref before passed as argument
  //
  g_MonitorViewType->AddRef();
  new MonitorViewFactory(g_MonitorViewType);
  //
  // Create Property view factory
  //
  g_propertyViewType = ::CreateViewType();
  if (g_propertyViewType == NULL) {
    return;
  }
  //
  // add ref before passed as argument
  //
  g_propertyViewType->AddRef();
  new PropertyViewFactory(g_propertyViewType);

}

//.............................................................................
ViewTest::~ViewTest()
{
   if ( g_projectViewType ) {
      g_projectViewType->Release();
      g_projectViewType = NULL;
   }
   if ( g_textViewType ) {
      g_textViewType->Release();
      g_textViewType = NULL;
   }
   if ( g_projectDetailViewType ) {
      g_projectDetailViewType->Release();
      g_projectDetailViewType = NULL;
   }
   if ( g_MonitorViewType ) {
      g_MonitorViewType->Release();
      g_MonitorViewType = NULL;
   }
   if ( g_propertyViewType ) {
      g_propertyViewType->Release();
      g_propertyViewType = NULL;
   }

}
//.............................................................................
BOOL ViewTest::Init()
{
  return TRUE;
}
//.............................................................................
void ViewTest::UnInit()
{
}
//.............................................................................
const char * ViewTest::GetName()
{
  return "View mgmt test";
}
//.............................................................................
const char * ViewTest::GetTestDescription( int testNum )
{
  switch ( testNum ) {
    case 1:
      return "Create project view";
    case 2:
      return "Create edit view";
    case 3:
      return "Create project detail view";
    case 4:
      return "Create Monitor view";
  }
  return "This test not implemented";
} 

void ViewTest::DoTest1()
{
  //
  // call IViewType::CreateInstance() to create a user view in IDE
  //
  IPolyString* title = MakePolyString("Addon Project View");
  IViewParentWnd* pvp = g_projectViewType->CreateInstance(title);
  if (pvp) {
    pvp->Display();
    pvp->Release();
  }
}

void ViewTest::DoTest2()
{
  //
  // call IViewType::CreateInstance() to create a user view in IDE
  //
  IPolyString* title = MakePolyString("Addon Text View");
  IViewParentWnd* pvp = g_textViewType->CreateInstance(title);
  if (pvp) {
    pvp->Display();
    pvp->Release();
  }

  title = MakePolyString("Addon Property View");
  pvp = g_propertyViewType->CreateInstance(title);
  if (pvp) {
    pvp->Display();
    pvp->Release();
  }

}

void ViewTest::DoTest3()
{
  //
  // call IViewType::CreateInstance() to create a user view in IDE
  //
  IPolyString* title = MakePolyString("Addon Project Detail View");
  IViewParentWnd* pvp = g_projectDetailViewType->CreateInstance(title);
  if (pvp) {
   pvp->Display();
   IViewClient* vClient = pvp->GetViewClient();
   ProjectDetailView* mv = GetProjectDetailViewFromHWND(vClient->GetHwnd());
   mv->ShowSelectedNodes();
   vClient->Release();
   pvp->Release();
  }
}

void ViewTest::DoTest4()
{
  //
  // call IViewType::CreateInstance() to create a user view in IDE
  //
  IPolyString* title = MakePolyString("Addon Monitor View");
  IViewParentWnd* pvp = g_MonitorViewType->CreateInstance(title);
  if (pvp) {
   pvp->Display();
   pvp->Release();
  }
}

//.............................................................................
void ViewTest::DoTest( int testNum )
{
  switch ( testNum ) {
    case 1: {
      DoTest1();
      break;
    }
    case 2:
      DoTest2();
      break;
    case 3:
      DoTest3();
      break;
    case 4:
      DoTest4();
      break;
    default: {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      break;
    }
  }
}

//
// create a addon project view and set the top node 
//
void  CreateNewProjectView(ProjectNode node) {

  IPolyString* title = MakePolyString("Addon Project View");
  IViewParentWnd* pvp = g_projectViewType->CreateInstance(title);
  if (pvp) {
   pvp->Display();

   IViewClient* vClient = pvp->GetViewClient();
   TreeModel* tm = GetTreeModelFromHWND(vClient->GetHwnd());
   tm->SetTopNode(node);
   vClient->Release();
   pvp->Release();
  }
}

void  CreateDetailView(ProjectNode* nodes, int nNodes) {

  IPolyString* title = MakePolyString("Addon Project Detail View");
  IViewParentWnd* pvp = g_projectDetailViewType->CreateInstance(title);
  if (pvp) {
    pvp->Display();

    IViewClient* vClient = pvp->GetViewClient();
    ProjectDetailView* mv = GetProjectDetailViewFromHWND(vClient->GetHwnd());
    mv->ShowNodes(nodes, nNodes);
    vClient->Release();

    pvp->Release();
  }
}
