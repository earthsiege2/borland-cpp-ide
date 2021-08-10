/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  prjwin.cpp
  Created: 11/28/95
  Copyright (c) 1995, Borland International
  $Revision:   1.16  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\iproj.h>
#include <ideaddon\iide.h>
#include "tests.hrc"
#include "prjview.h"
#include "prjwin.h"

#define NUM_BITMAPS 3
#define ID_TREEVIEW 1
#define BITMAP_WIDTH   18
#define BITMAP_HEIGHT 16

#define USE_QI 1

extern void CreateDetailView(ProjectNode* nodes, int nNodes);

/******************************************************************************
* This file implements the addon project window. It has the following features:
*
*  Edit           Open the selected node into the text editor. It does not check
*                  for file type.
*
*  New View       Create a new project window that has the same top node.
*
*  View from here Make the current selected node the top node in the addon
*                  project view.
*
*  Refresh         Refresh the addon project view content. The addon project view
*                  can not detect node change beside delete and add in the project.
*
*  Delete Node     Delete the selected node from the project
*
*  Add Node...     Add a node to the project.
*
*  Make           Make the selected node.
*
*  Build           Build the selected node.
*
*  Translate       Translate the selected node.
*
******************************************************************************/
class DependentCollector : public IProjectClient {
public:
  DependentCollector();
  ~DependentCollector();

  //IUnknown members
  STDMETHODIMP QueryInterface (THIS_ REFIID, LPVOID FAR *);
  STDMETHODIMP_(ULONG) AddRef (THIS) { return m_RefCount++; }
  STDMETHODIMP_(ULONG) Release (THIS)
      {return --m_RefCount == 0 ? (delete this, 0) : m_RefCount; }

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


   int  GetDependents(ProjectNode node, ProjectNode* nodes, int nNodes);
protected:
  // private variables
  ULONG          m_RefCount;
  IProjectServer* d_projectServer;

  ProjectNode*    d_nodes;
  int            d_nNodes;
  int            d_iNext;
};

DependentCollector::DependentCollector() {
  m_RefCount = 1;
  d_projectServer = GET_INTERFACE( IProjectServer );
};

DependentCollector::~DependentCollector() {
  d_projectServer->Release();
};


STDMETHODIMP
DependentCollector::QueryInterface (REFIID riid, LPVOID FAR* ppobj)
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

//
// IProjectClient methods
//
void DependentCollector::OpenNotify( IPolyString * projectName ) {
  projectName->Release();
}
//.............................................................................
void DependentCollector::CloseNotify() {
}

void DependentCollector::NodeDeleteNotify( ProjectNode ) {
}
//.............................................................................
void DependentCollector::NodeAddNotify( ProjectNode ) {
}
//.............................................................................
void DependentCollector::DependencyQueryResponder( ProjectNode node,
                          IPolyString * outputName) {
  outputName->Release();
  if (d_iNext >= d_nNodes)
   return;

  d_nodes[d_iNext] = node;
  ++d_iNext;
}

int DependentCollector::GetDependents(ProjectNode node, ProjectNode* nodes, int nNodes) {
  d_nodes = nodes;
  d_nNodes = nNodes;
  d_iNext = 0;
  d_projectServer->QueryDependencies(node, this);
  return d_iNext;
};

/******************************************************************************
*
* TreeController
*
******************************************************************************/

TreeController::TreeController() {
  d_projectServer = GET_INTERFACE(IProjectServer);
  d_topNode = 0;

}

TreeController::~TreeController() {
  d_projectServer->Release();
}

HWND TreeController::InitWindow(HWND hwndParent) {


  // Ensure that the common control DLL is loaded.
  InitCommonControls();

  // get the size and position of the parent window
  RECT rcl;          // rectangle for setting the size of the window
  GetClientRect(hwndParent, &rcl);
  HINSTANCE hInst = (HINSTANCE)GetWindowLong(hwndParent, GWL_HINSTANCE);

  // create the tree view window
  d_hwnd = CreateWindowEx(  WS_EX_CLIENTEDGE,
                            WC_TREEVIEW,                // tree view class
                            TEXT(""),                  // no default text
                            WS_VISIBLE | WS_CHILD
                            | WS_BORDER | TVS_HASLINES
                            | TVS_HASBUTTONS | TVS_LINESATROOT,
                            0, 0,
                            rcl.right - rcl.left, rcl.bottom - rcl.top - 15,
                            hwndParent,
                            (HMENU) ID_TREEVIEW,
                            hInst,
                            NULL );

  if (d_hwnd == NULL ) {
    MessageBox (NULL, TEXT("Tree View not created!"), NULL, MB_OK );
    return NULL;
  }

  HIMAGELIST hIml;    // handle to the image list
  // initialize the tree view window
  // First, create the image list we will need
  hIml = ImageList_Create( BITMAP_WIDTH,  // width
                        BITMAP_HEIGHT,                      // height
                        0,                                  // flags
                        NUM_BITMAPS,                        // number of bitmaps
                        0 );                                // amount to grow

  HBITMAP hBmp;      // handle to a bitmap
  // load the bitmaps and add them to the image lists
  hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_CLOSED_FOLDER));
  d_idxCloseFolder = ImageList_Add(hIml,        // handle to the imagelist
                           hBmp,        // handle to the bitmap
                           NULL);      // handle of the bitmap mask

  hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_OPEN_FOLDER));
  d_idxOpenFolder = ImageList_Add(hIml, hBmp, NULL);

  hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_FILE));
  d_idxFile = ImageList_Add(hIml, hBmp, NULL);

  // Associate the image list with the tree
  TreeView_SetImageList(d_hwnd, hIml, TVSIL_NORMAL);

  return d_hwnd;
}

void TreeController::GetItem(HTREEITEM  ti, TV_ITEM& item, unsigned mask) {
  item.hItem = ti;
  item.mask = mask;

  TreeView_GetItem(d_hwnd, &item);
}

void TreeController::SetImage(HTREEITEM ti, unsigned idxImage) {
  TV_ITEM item;
  GetItem(ti, item, TVIF_IMAGE | TVIF_SELECTEDIMAGE);
  item.iImage       = idxImage;
  item.iSelectedImage= idxImage;
  TreeView_SetItem(d_hwnd, &item);
};

void TreeController::SetTopNode(ProjectNode topNode) {
  d_topNode = topNode;
};
 
//
// initialize the treeview by adding project nodes
//
BOOL TreeController::AddTreeViewItems() {

  //
  // by default, display from project's top node
  //
  if (!d_topNode)
    d_topNode = d_projectServer->QueryTopNode();

  ProjectNode topNode = d_topNode;

  TreeView_DeleteAllItems(d_hwnd);

  IProjectNodeInfo* pni = d_projectServer->QueryNodeInfo( topNode );

  IPolyString* name = pni->GetInputLocation();
  if (name) {
    HTREEITEM hTRoot = AddOneItem((HTREEITEM)NULL
                                 , name->GetCstr()
                                 , (HTREEITEM)TVI_ROOT
                                 , d_idxCloseFolder
                                 , (LPARAM)topNode);
    name->Release();
    AddBranch(hTRoot, topNode);
  }
  return TRUE;
}

//
// get corresponding ProjectNode of a TREEITEM
//
ProjectNode TreeController::GetNodeFromItem(HTREEITEM ti) {
  TV_ITEM item;

  GetItem(ti, item, TVIF_PARAM);
  return (ProjectNode)item.lParam;
}

HTREEITEM TreeController::FindItem(HTREEITEM hitem, ProjectNode node) {

  ProjectNode iNode = GetNodeFromItem(hitem);
  if (node == iNode)
    return hitem;

  hitem = TreeView_GetChild(d_hwnd, hitem);

  while (hitem) {
    HTREEITEM itemFound = FindItem(hitem, node);
    if (itemFound)
      return itemFound;
    hitem = TreeView_GetNextSibling(d_hwnd, hitem);
  }
  return 0;
};

HTREEITEM TreeController::GetItemFromNode(ProjectNode node) {

  HTREEITEM root = TreeView_GetRoot(d_hwnd);
  return FindItem(root, node);
}
//
// add project nodes to the treeview
//
unsigned TreeController::AddBranch(HTREEITEM tiParent, ProjectNode node) {
  IProjectNodeInfo* pni = d_projectServer->QueryNodeInfo( node );

  ProjectNode childNode = pni->GetFirstChild();
  HTREEITEM tiPrevChild = TVI_FIRST;
  unsigned counter = 0;

  //
  // add all children of tiParent
  //
  while (childNode) {

    IProjectNodeInfo* childNodeInfo = d_projectServer->QueryNodeInfo( childNode );
    IPolyString* name = childNodeInfo->GetInputLocation();
    tiPrevChild = AddOneItem(tiParent, name->GetCstr(), tiPrevChild, d_idxFile, childNode);
    name->Release();
    //
    // increment child counter
    //
    ++counter;
    //
    // add children for the child that is just added
    //
    counter += AddBranch(tiPrevChild, childNode);
    //
    // get sibling
    //
    childNode = childNodeInfo->GetNextSibling();
    childNodeInfo->Release();
  };
  pni->Release();
  //
  // If tiParent has children, change parent's image to close folder
  //
  if (counter) {
    SetImage(tiParent, d_idxCloseFolder);
  }
  return counter;
}

//
// change image when user expand/collapse a tree item
//
void TreeController::OnExpanded(LPNM_TREEVIEW lpNMTreeView) {
  TV_ITEM      tviNew, tviChange, tviCurrent;

  tviNew = lpNMTreeView->itemNew;

  //
  // get current assigned image
  // 
  tviCurrent.hItem = tviNew.hItem;
  tviCurrent.mask = TVIF_IMAGE;
  TreeView_GetItem (d_hwnd, &tviCurrent);

  //
  // toggle image
  //  if action == expand and image == close folder
  //    image = open folder
  //
  tviChange.hItem = tviNew.hItem;
  tviChange.mask  = TVIF_IMAGE | TVIF_SELECTEDIMAGE;
  if ((lpNMTreeView->action == TVE_EXPAND) &&
      (tviCurrent.iImage == d_idxCloseFolder))  {       
    tviChange.iImage        = d_idxOpenFolder;
    tviChange.iSelectedImage= d_idxOpenFolder;
  } else {        
    tviChange.iImage        = d_idxCloseFolder;
    tviChange.iSelectedImage= d_idxCloseFolder;
  }
  TreeView_SetItem(d_hwnd, &tviChange);
}

void TreeController::AddNode(ProjectNode node) {
  IProjectNodeInfo* nodeInfo =  d_projectServer->QueryNodeInfo(node);
  if (nodeInfo) {
    ProjectNode parentNode = nodeInfo->GetParent();
    IPolyString* name = nodeInfo->GetInputLocation();

    HTREEITEM tiParent = GetItemFromNode(parentNode);
    AddOneItem(tiParent, name->GetCstr(), TVI_FIRST, d_idxFile, node);

    TV_ITEM item;
    item.hItem = tiParent;
    item.mask = TVIF_IMAGE;

    if ( TreeView_GetItem(d_hwnd, &item) ) {
      
      //
      // if it is a file, make it a folder
      //
      if ( item.iImage == d_idxFile )
        SetImage(tiParent, d_idxCloseFolder);

      nodeInfo->Release();
      name->Release();
    }
  }
};

void TreeController::DeleteTreeItem(ProjectNode node) {
  HTREEITEM hitem = GetItemFromNode(node);
  if (hitem)
    TreeView_DeleteItem(d_hwnd, hitem);
};

void TreeController::RemoveNodeFromProject(ProjectNode node) {

  d_projectServer->NodeRemove(node);
}

void TreeController::AddNodeToProject(ProjectNode node, char* name) {
   d_projectServer->NodeAdd(node, MakePolyString(name));
}

/****************************************************************************
* 
* TreeModel
*
****************************************************************************/

TreeModel::TreeModel(HWND hwnd) {

  d_makeServer  = GET_INTERFACE(IMakeServer);
  d_toolServer  = GET_INTERFACE(IToolServer);
  d_hwnd = hwnd;
  d_tc = 0;
  d_selectedItem = 0;
  d_client = 0;
}

TreeModel::~TreeModel() {
  d_makeServer->Release();
  d_toolServer->Release();
  if ( d_client ) {
    d_client->Stop();
    d_client->Release();
  }
};


void TreeModel::SetProjectViewClient(IProjectViewClient* client) {
  d_client = client;
};

        
void TreeModel::SetSelected(HTREEITEM item) {
  d_selectedItem = item;
}

ProjectNode TreeModel::GetSelectedNode() {
  return d_tc->GetNodeFromItem(d_selectedItem);
};

BOOL TreeModel::GetNewNodeName(char* buf, int bufSize) {
  
  OPENFILENAME ofn;      /* common dialog box structure  */

  memset(&ofn, 0, sizeof(ofn));
  char szFilter[260] = "Files(*.*)\0*.*\0\0";    /* filter string                */
  
  /* Set the members of the OPENFILENAME structure. */

  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hwndOwner = d_hwnd;
  ofn.lpstrFilter = szFilter;
  ofn.nFilterIndex = 1;
  ofn.lpstrFile = buf;
  ofn.nMaxFile = bufSize;
  ofn.lpstrTitle = "AddOn - add node";
  ofn.Flags = OFN_EXPLORER;

  /* Display the Open dialog box. */

  return GetOpenFileName(&ofn);

}

void TreeModel::OnCommand(WORD wID, WORD /*wNotifyCode*/) {
  switch (wID) {
    case IDM_MAKE:
    {
      ProjectNode nodes[1];
      nodes[0] = GetSelectedNode();
      d_makeServer->MakeNodes(MM_Make, nodes, 1);
    }
    break;
    case IDM_BUILD:
    {
      ProjectNode nodes[1];
      nodes[0] = GetSelectedNode();
      d_makeServer->MakeNodes(MM_Build, nodes, 1);
    }
    break;
    case IDM_TRANSLATE:
    {
      ProjectNode nodes[1];
      nodes[0] = GetSelectedNode();
      d_makeServer->MakeNodes(MM_Translate, nodes, 1);
    }
    break;
    case IDM_VIEW:
    {
      ToolObj toolObj = d_toolServer->ToolFind( ::MakePolyString ( "EditText" ) );
      d_toolServer->ToolInvoke(toolObj, GetSelectedNode());
    }
    break;
    case IDM_REFRESH:
    {
      d_tc->AddTreeViewItems();
    }
    break;
    case IDM_CREATENEWVIEW:
    {
      CreateNewProjectView(d_tc->GetTopNode());
    }
    break;
    case IDM_VIEWFROMHERE:
    {
      d_tc->SetTopNode(GetSelectedNode());
      d_tc->AddTreeViewItems();
    }
    break;
    case IDM_DELETENODE:
    {
      d_tc->RemoveNodeFromProject(GetSelectedNode());
    }
    break;
    case IDM_ADDNODE:
    {
    char buf[MAX_PATH] = "";
      if (GetNewNodeName(buf, sizeof(buf))) {
      d_tc->AddNodeToProject(GetSelectedNode(), buf);
    }
   }
   break;
   case IDM_VIEWDEP:
   {
    ProjectNode nodes[100]; // only do up to 100 nodes
    int nNodes = DependentCollector().GetDependents(GetSelectedNode()
                                   , nodes
                                   , sizeof(nodes)/sizeof(nodes[0]));
    CreateDetailView(nodes, nNodes);
   }
    break;
  };
};

void TreeModel::Resize(int w, int h) {
  MoveWindow(d_tc->d_hwnd, 0, 0, w, h, TRUE);
}

void TreeModel::OnNodeDeleted(ProjectNode node) {
  d_tc->DeleteTreeItem(node);
};

void TreeModel::OnNodeAdd(ProjectNode node) {
    d_tc->AddNode(node);
};

/***************************************************************************
* 
*   FUNCTION: AddOneItem(HTREEITEM, LPSTR, HTREEITEM, int)
*
*   PURPOSE: Inserts a tree view item in the specified place. 
*
****************************************************************************/

HTREEITEM TreeController::AddOneItem( HTREEITEM hParent
                                    , LPCSTR szText
                                    , HTREEITEM hInsAfter
                                    , int iImage
                                    , LPARAM lParam)
{
  HTREEITEM hItem;
  TV_ITEM tvI;
  TV_INSERTSTRUCT tvIns;

  tvI.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM;
  tvI.pszText = (char*)szText;
  tvI.cchTextMax = lstrlen(szText);
  tvI.iImage = iImage;
  tvI.iSelectedImage = iImage;
  tvI.lParam = lParam;

  tvIns.item = tvI;
  tvIns.hInsertAfter = hInsAfter;
  tvIns.hParent = hParent;
  
  hItem = (HTREEITEM)SendMessage(d_hwnd, TVM_INSERTITEM, 0,
    (LPARAM)(LPTV_INSERTSTRUCT)&tvIns);

  return (hItem);
}

/****************************************************************************
*
*   Context Menu Processing
*
****************************************************************************/
VOID APIENTRY DisplayContextMenu(HWND hwnd, POINT pt)
{
  // Load the menu resource.

  HINSTANCE hInst = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
  HMENU hmenu = LoadMenu(hInst, MAKEINTRESOURCE(IDR_ADDON_POPUP));  // top-level menu 
  if (hmenu == NULL)
      return;

  HMENU hmenuTrackPopup = GetSubMenu(hmenu, 0);  // pop-up menu

  // Display the floating pop-up menu. Track the right mouse
  // button on the assumption that this function is called
  // during WM_CONTEXTMENU processing.

  TrackPopupMenu(hmenuTrackPopup,
          TPM_LEFTALIGN | TPM_RIGHTBUTTON,
          pt.x, pt.y, 0, hwnd, NULL);

  // Destroy the menu.

  DestroyMenu(hmenu);
}


BOOL WINAPI OnContextMenu(HWND hwnd, int x, int y)
{
  RECT rc;                    // client area of window 
  POINT pt = { x, y };        // location of mouse click 

  // Get the bounding rectangle of the client area. 

  GetClientRect(hwnd, &rc);

  // Convert the mouse position to client coordinates. 

  ScreenToClient(hwnd, &pt);

  // If the position is in the client area, display a floating 
  // pop-up menu. 

  if (PtInRect(&rc, pt)) {
      ClientToScreen(hwnd, &pt);
      DisplayContextMenu(hwnd, pt);
      return TRUE;
  }
  // Return FALSE if no menu is displayed. 
  return FALSE;
}


LONG APIENTRY TreeViewWndProc(
  HWND hWnd,                /* window handle                   */
  UINT message,            /* type of message                */
  UINT wParam,              /* additional information         */
  LONG lParam)              /* additional information         */
{
  TreeModel* tm = GetTreeModelFromHWND(hWnd);
  switch (message)
  {

    case WM_CREATE:
    {
      // Create the tree view window and initialize its
      // image list
      TreeController* tc = new TreeController();
      TreeModel* tm = new TreeModel(hWnd);
      SetWindowLong(hWnd, GWL_USERDATA, (long)tm);

      tc->InitWindow(hWnd);
      tm->Attach(tc);
   }

      break;          
    case WM_SIZE:
    {
      tm->Resize(LOWORD(lParam), HIWORD(lParam));
    }
      break;
    case WM_CONTEXTMENU:
     if (!OnContextMenu(hWnd, LOWORD(lParam), HIWORD(lParam)))
       return DefWindowProc(hWnd, message, wParam, lParam);
     break;
    case WM_COMMAND:
    {
     tm->OnCommand(LOWORD(wParam), HIWORD(wParam)); 
    }
     break;

    case WM_NOTIFY:
    {
      LPNMHDR pnmh = (LPNMHDR) lParam;
      switch (pnmh->code) {
        case TVN_SELCHANGED:
        {
          LPNM_TREEVIEW ptv = (LPNM_TREEVIEW)lParam;
          tm->SetSelected(ptv->itemNew.hItem);
        };
        break;
        case TVN_ITEMEXPANDED:
        {
          tm->GetController()->OnExpanded((LPNM_TREEVIEW)lParam);
        }
        break;
      };
    }
      break;
    case UM_SETROOT:
    {
      TreeController* tc = tm->GetController();
      tc->SetTopNode((ProjectNode)lParam);
      tc->AddTreeViewItems();
    }
      break;
    case WM_DESTROY:
    {
      TreeController* tc = tm->GetController();
      delete tm;
      delete tc;
      SetWindowLong(hWnd, GWL_USERDATA, 0L);
    }
    default:
      return (DefWindowProc(hWnd, message, wParam, lParam));
  }
  return (0);
}

BOOL RegisterTreeViewClass(HINSTANCE hInstance)      /* current instance             */
{
  WNDCLASS  wcTreeView;

  if ( GetClassInfo(hInstance,              // handle of application instance
                    TEXT("TreeViewWClass"), // address of class name string
                    &wcTreeView)            // address of structure for class data
      ) {
    return TRUE;
  }

  /* Fill in window class structure with parameters that describe the      */
  /* main window.                                                          */

  wcTreeView.style = 0;                    
  wcTreeView.lpfnWndProc = (WNDPROC)TreeViewWndProc; 
  wcTreeView.cbClsExtra = 0;              
  wcTreeView.cbWndExtra = 0;              
  wcTreeView.hInstance = hInstance;
  wcTreeView.hIcon = NULL;
  wcTreeView.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcTreeView.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wcTreeView.lpszMenuName = NULL; 
  wcTreeView.lpszClassName = TEXT("TreeViewWClass");

  return (RegisterClass(&wcTreeView));
}

/****************************************************************************
*
*   FUNCTION: CreateTreeWindow(HINSTANCE hInstance, HWND hwndParent)
*
*   PURPOSE:  Creates a treeview window
*
****************************************************************************/

HWND CreateTreeWindow(HINSTANCE hInstance, HWND hwndParent) {

  RegisterTreeViewClass(hInstance);
  return CreateWindow(
                        TEXT("TreeViewWClass"),          
                        TEXT("TreeView Sample"), 
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



