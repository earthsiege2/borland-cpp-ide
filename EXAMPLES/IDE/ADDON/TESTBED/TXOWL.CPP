/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   Created: 1/1/96
   Copyright (c) 1987, 1996 Borland International Inc.  All Rights Reserved.
   $Revision:   1.15  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\itx.h>
#include <ideaddon\iproj.h>
#include <ideaddon\itarg.h>
#include "txowl.h"
#include "tests.hrc"
#include "txowl.uid"

#include <windowsx.h>

#define OWL_TARGET_PROPERTY "OwlTarget"

extern HINSTANCE ghInst;

///////////////////////////////////////////////////////////////////////////////

#define OWL_APP_TYPE_STR "Win32 OWL Aplication [.exe]"
#define OWL_PLATFORM_STR "Win32"
#define OWL_IMAGE_STR   "GUI"
#define OWL_NODETYPE_STR ".exe"
#define CPP_NODETYPE_STR ".cpp"

///////////////////////////////////////////////////////////////////////////////
OwlTarget::~OwlTarget() {
  if ( d_targetMgr ) {
    d_targetMgr->Release();
  }
  if ( d_targetMgr ) {
    d_targetMgr->Release();
  }
  if (d_IdeObj) {
    d_IdeObj->Release();
  }
};

void OwlTarget::SetIDEObj(LPUNKNOWN ideObj) {

  d_IdeObj = ideObj;
  //
  // Get the ITargetManager interface and register our target type
  //
  d_IdeObj->QueryInterface(IID_Addon_ITargetManager, (LPVOID*)&d_targetMgr);
  d_targetMgr->QueryInterface(  IID_Addon_ITargetManagerPropertyDialog
                              , (LPVOID*)&d_targetMgrDlg);
  d_hTarget = d_targetMgr->AddTargetType(this
                                      , MakePolyString(OWL_APP_TYPE_STR)
                                      , ghInst
                                      , IDD_WIN32_OWL_TARGET);
};

static OwlTargetData p_defaultTargetData = { 0, 0};


void OwlTarget::Setup(ProjectNode node) {

  if (node) {
    //
    // If we are editing a node, try to get information from the node 
    //    
    IProjectServer* projectServer;
    d_IdeObj->QueryInterface(IID_Addon_IProjectServer
                            , (LPVOID*)&projectServer);

    UINT dataSize;
    IPolyString* propertyName = MakePolyString(OWL_TARGET_PROPERTY);

    void* p = projectServer->NodePropertyFind(  node
                                              , propertyName
                                              , &dataSize );
    projectServer->Release();
    if (dataSize >= sizeof(d_targetData)) {
      d_targetData = *(OwlTargetData*)p;
    } else {
      //
      // Should not get here, but get the default anyway.
      //
      d_targetData = p_defaultTargetData;
    }

  } else {
    //
    // try to get the default state settings
    //
    d_targetData = p_defaultTargetData;
  }
}

void OwlTarget::GetDlgItems() {
  HWND hwndCtl = d_targetMgrDlg->GetControlWindow(IDC_BWCC);
  d_targetData.d_fBWCC = Button_GetCheck(hwndCtl);

  hwndCtl = d_targetMgrDlg->GetControlWindow(IDC_DYNAMIC_LIB);
  d_targetData.d_fDynamic = Button_GetCheck(hwndCtl);
};

void OwlTarget::SetDlgItems() {

  ITargetManagerDialogControl* advanceBut 
              = d_targetMgrDlg->GetAdvancedButton();
  advanceBut->Enable(0);
  advanceBut->Release();
  //
  // add platform Win32
  //
  ITargetManagerDialogList* pltm = d_targetMgrDlg->GetPlatformList();
  pltm->Clear();
  IPolyString* platFormStr = MakePolyString(OWL_PLATFORM_STR);
  platFormStr->AddRef();
  pltm->Add(platFormStr, d_hTarget);
  pltm->Select(platFormStr);
  pltm->Release();

  //
  // add image GUI
  //
  ITargetManagerDialogList* image = d_targetMgrDlg->GetImageList();
  image->Clear();
  image->Add(MakePolyString(OWL_IMAGE_STR), d_hTarget);
  image->Select(MakePolyString(OWL_IMAGE_STR));
  image->Release();

  //
  // initialize our own fields
  //
  HWND hwndCtl = d_targetMgrDlg->GetControlWindow(IDC_BWCC);
  Button_SetCheck(hwndCtl, d_targetData.d_fBWCC);
  hwndCtl = d_targetMgrDlg->GetControlWindow(IDC_DYNAMIC_LIB);
  Button_SetCheck(hwndCtl, d_targetData.d_fDynamic);

  hwndCtl = d_targetMgrDlg->GetControlWindow(IDC_STATIC_LIB);
  Button_SetCheck(hwndCtl, !d_targetData.d_fDynamic);
};

void OwlTarget::OnCommand(UINT id) {
  //
  // we don't need to do anything here
  //
  switch (id) {
    case IDC_BWCC:
      {
      }
      break;
    case IDC_DYNAMIC_LIB:
      {
      }
      break;
    case IDC_STATIC_LIB:
      {
      }
      break;
    default:
      break;
  };
}


void OwlTarget::AdvancedDialog(HWND /* hwndParent*/ )
{
  //
  // do advance dialog
  //
}

void OwlTarget::PlatformSelectionChangeNotification(UINT /*id*/) {

}

///////////////////////////////////////////////////////////////////////////////

BOOL OwlTarget::IsTargetable(IPolyString* fileExt) {
  //
  // We can target any files with extension .exe
  //
  BOOL targetable = (lstrcmpi(fileExt->GetCstr(), OWL_NODETYPE_STR) == 0);
  fileExt->Release();
  return targetable;
};

HRESULT OwlTarget::GetClassID(CLSID *pClassID) {
  *pClassID = IID_Win32_OWL_Target;
  return S_OK;
};

ProjectNode OwlTarget::
ConvertNodeToTarget(ProjectNode nodeTarget, IPolyString* name) {

  IProjectServer* projectServer;
  d_IdeObj->QueryInterface( IID_Addon_IProjectServer
                          , (LPVOID*)&projectServer);

  ITargetServer* targetServer;
  d_IdeObj->QueryInterface( IID_Addon_ITargetServer
                          , (LPVOID*)&targetServer);

  char path_buffer[_MAX_PATH];
  char drive[_MAX_DRIVE];
  char dir[_MAX_DIR];
  char fname[_MAX_FNAME];
  char ext[_MAX_EXT];


  if ( !nodeTarget ) {
    //
    // nodeTarget is NULL, we are asked to create a new target from the root
    // node.
    //

    //
    // if name == foo.exe, it will become foo.exe
    // if name == foo.ext, it will become foo.exe
    //
    // Is this right? Win95 does support multiple extensions.
    //
    // or maybe it should be
    //
    // if name == foo.exe, it will become foo.exe
    // if name == foo.ext, it will become foo.ext.exe
    //
    _splitpath(name->GetCstr(), drive, dir, fname, ext );
    name->Release();
    //
    // Creating a new target
    //
    _makepath(path_buffer, drive, dir, fname, OWL_NODETYPE_STR);

    //
    // Call TargetAdd() to create an IDE stock target.
    //
    nodeTarget = targetServer->TargetAdd( 
                          MakePolyString(path_buffer),    // node name
                          0,                              // parent node
                          TT_Application,                // target type
                          TP_Win32,                      // target platform
                          (TargetStdLibs)                // libs
                             (  TL_Owl
                             |  TL_Bids
                             |  TL_Rtl
                             |  (d_targetData.d_fBWCC ? TL_Bwcc : 0)
                             |  (d_targetData.d_fDynamic ? TL_Dynamic : 0) ),
                          TM_Gui);                        // target model

    //
    // new target, creates skeleton node.
    //
    _makepath(path_buffer, drive, dir, fname, CPP_NODETYPE_STR);
    projectServer->NodeAdd(nodeTarget, MakePolyString(path_buffer));
  } else {
    //
    // A valid nodeTarget, we are asked to convert a node to a target
    //
    nodeTarget = targetServer->ConvertNodeToTarget( nodeTarget,
                          TT_Application,                // target type
                          TP_Win32,                      // target platform
                          (TargetStdLibs)                // libs
                             (  TL_Owl
                             |  TL_Bids
                             |  TL_Rtl
                             |  (d_targetData.d_fBWCC ? TL_Bwcc : 0)
                             |  (d_targetData.d_fDynamic ? TL_Dynamic : 0) ),
                          TM_Gui);                        // target model

  }
  targetServer->Release();

  IPolyString* propertyName = MakePolyString(OWL_TARGET_PROPERTY);

  projectServer->NodePropertySet( nodeTarget
                                , propertyName
                                , &d_targetData
                                , sizeof(d_targetData) );

  projectServer->Release();

  ((ITargetType*)this)->AddRef();
  d_targetMgr->TreatAsTarget(this, nodeTarget);

  return nodeTarget;
}

STDMETHODIMP OwlTarget::ConvertTargetToNode(ProjectNode nodeTarget) {

  IProjectServer* projectServer;
  d_IdeObj->QueryInterface( IID_Addon_IProjectServer
                          , (LPVOID*)&projectServer);

  //
  // remove target template nodes if there are any.
  // we asked ITargetServer to make the target, so we also ask ITargetServer
  // to convert the target to node.
  //
  ITargetServer* targetServer;
  d_IdeObj->QueryInterface( IID_Addon_ITargetServer
                          , (LPVOID*)&targetServer);
  targetServer->ConvertTargetToNode(nodeTarget);
  targetServer->Release();
  
  //
  // remove private target property
  //
  IPolyString* propertyName = MakePolyString(OWL_TARGET_PROPERTY);
  projectServer->NodePropertyRemove(  nodeTarget
                                    , propertyName );

  projectServer->Release();
  return NOERROR;
}

///////////////////////////////////////////////////////////////////////////////
OwlTargetImpl::OwlTargetImpl(LPUNKNOWN ideObj)
              : IUnknownImp<OwlTarget>(IID_IUnknown) {

  SetIDEObj(ideObj);
};

STDMETHODIMP
OwlTargetImpl::QueryInterface(REFIID riid, LPVOID FAR* ppobj) {
  if (riid == IID_IUnknown) {
   *ppobj = (LPVOID)(ITargetPropertyPage *) this;
  } else if ((riid == IID_Addon_ITargetType)) {
    *ppobj = (LPVOID)(ITargetType*)this;
  } else {
    *ppobj = NULL;
    return ResultFromScode(E_NOINTERFACE);
  }
  AddRef();
  return NOERROR;
}
