/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  pdwin.cpp
  Created: 12/1/95
  Copyright (c) 1995, Borland International
  $Revision:   1.16  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <commctrl.h>
#include <ideaddon\iview.h>
#include <ideaddon\iide.h>
#include "pdwin.h"
#include "tests.hrc"

ProjectDetailView::ProjectDetailView(HWND hwnd) {

  d_projectServer = GET_INTERFACE(IProjectServer);
  d_makeServer = GET_INTERFACE(IMakeServer);
  d_targetServer = GET_INTERFACE(ITargetServer);
  d_hwnd = hwnd;
};

ProjectDetailView::~ProjectDetailView() {
  d_projectServer->Release();
  d_makeServer->Release();
  d_targetServer->Release();
};

void ProjectDetailView::CreateList() {

  RECT rcl;          // rectangle for setting the size of the window
  GetClientRect(d_hwnd, &rcl);

  d_hwndList = CreateWindowEx(WS_EX_NOPARENTNOTIFY,
                            WC_LISTVIEW,                // list view class
                            "",                        // no default text
                            WS_VISIBLE | WS_CHILD | WS_BORDER
                            | LVS_REPORT |WS_EX_CLIENTEDGE,
                            0, 0,
                            rcl.right - rcl.left, rcl.bottom - rcl.top,
                            d_hwnd,
                            (HMENU)1,
                            NULL,
                            NULL );
  InitColumns();
};

void ProjectDetailView::Resize(int w, int h) {
  MoveWindow(d_hwndList, 0, 0, w, h, TRUE);
}

static char* headers[] = {
                           "Name",
                           "Type",
                           "Description",
                           "Input Location",
                           "Input Age",
                           "Output Location",
                           "Output Age",
                           "Target",
                          };

#define NCOLUMNS sizeof(headers)/sizeof(headers[0])

void ProjectDetailView::InitColumns() {
  // Now initialize the columns we will need
  // Initialize the LV_COLUMN structure
  // the mask specifies that the .fmt, .ex, width, and .subitem members 
  // of the structure are valid,
  LV_COLUMN lvC;      // List View Column structure
  lvC.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
  lvC.fmt = LVCFMT_LEFT;  // left align the column
  lvC.cx = 75;            // width of the column, in pixels

  // Add the columns.
  int index;          // Index used in for loops
  for ( index = 0; index < NCOLUMNS; ++index ) {
   lvC.iSubItem = index;
   lvC.pszText = headers[index];
   if (ListView_InsertColumn(d_hwndList, index, &lvC) == -1)
     return;
  };
}

void ProjectDetailView::ShowNodes(ProjectNode* nodes, int numNodes) {
  unsigned i;
  for ( i = 0; i < numNodes; ++i ) {
    ShowNode(nodes[i]);
  }
};

void ProjectDetailView::ShowSelectedNodes() {
  int numNodes;
  ProjectNode * nodes = d_projectServer->QuerySelectedNodes( &numNodes );
  ShowNodes(nodes, numNodes);
}


void ProjectDetailView::ShowNode(ProjectNode node) {

  IProjectNodeInfo* pni = d_projectServer->QueryNodeInfo( node );
  if (!pni)
   return;

  long inputAge;
  long outputAge;

  if (d_makeServer) {
    inputAge = d_makeServer->NodeInputAge( node );
    outputAge = d_makeServer->NodeOutputAge( node );
  } else {
    inputAge = 0;
    outputAge = 0;
  }
  char items[20][256];
  int i = 0;

  IPolyString* name = pni->GetName();
  if (name) {
    strcpy(items[i++], name->GetCstr());
    name->Release();
  }
  IPolyString* nodeType = pni->GetNodeType();
  if (nodeType) {
    strcpy(items[i++], nodeType->GetCstr());
    nodeType->Release();
  }
  IPolyString* nodeDesc = pni->GetDescription();
  if (nodeDesc) {
    strcpy(items[i++], nodeDesc->GetCstr());
    nodeDesc->Release();
  }
  IPolyString* nodeInput = pni->GetInputLocation();
  if (nodeInput) {
    strcpy(items[i++], nodeInput->GetCstr());
    nodeInput->Release();
  }

  wsprintf(items[i++], "0x%x", inputAge);

  IPolyString* nodeOutput = pni->GetOutputLocation();
  if (nodeOutput) {
    strcpy(items[i++], nodeOutput->GetCstr());
    nodeOutput->Release();
  }

  wsprintf(items[i++], "0x%x", outputAge);
  pni->Release();

  if ( d_targetServer->NodeIsTarget(node) ) {
    strcpy(items[i++], "Yes");
  } else {
    strcpy(items[i++], "No");
  }


  //
  // insert text into the list here
  //
  LV_ITEM lvI;        // List view item structure
  lvI.mask = LVIF_TEXT | LVIF_STATE;
  lvI.state = 0;      //
  lvI.stateMask = 0;  //


  int index = ListView_GetItemCount(d_hwndList);
  lvI.iItem = index;
  lvI.iSubItem = 0;
  lvI.pszText = items[0]; 
  lvI.cchTextMax = strlen(items[0])+1;

  if (ListView_InsertItem(d_hwndList, &lvI) == -1)
    return;

  int iSubItem;      // Index for inserting sub items
  for (iSubItem = 1; iSubItem < NCOLUMNS; iSubItem++) {
    ListView_SetItemText( d_hwndList,
                          index,
                          iSubItem,
                          items[iSubItem]);
  }
};


LONG APIENTRY ProjectDetailViewWndProc(
  HWND hWnd,                /* window handle                   */
  UINT message,            /* type of message                */
  UINT wParam,              /* additional information         */
  LONG lParam)              /* additional information         */
{
  ProjectDetailView* mv = GetProjectDetailViewFromHWND(hWnd);
  switch (message)
  {

    case WM_CREATE:
    {
      // Create the tree view window and initialize its
      // image list
      mv = new ProjectDetailView(hWnd);
      SetWindowLong(hWnd, GWL_USERDATA, (long)mv);
      mv->CreateList();
   }
      break;          
    case WM_SIZE:
    {
      mv->Resize(LOWORD(lParam), HIWORD(lParam));
    }
      break;
    case WM_DESTROY:
    {
      delete mv;
      SetWindowLong(hWnd, GWL_USERDATA, 0L);
    }
    default:
      return (DefWindowProc(hWnd, message, wParam, lParam));
  }
  return (0);
}

BOOL RegisterProjectDetailViewClass(HINSTANCE hInstance)       /* current instance             */
{
  WNDCLASS  wcProjectDetailView;


  if ( GetClassInfo(hInstance,              // handle of application instance
                    TEXT("ProjectDetailViewWClass"),  // address of class name string
                    &wcProjectDetailView)           // address of structure for class data
      ) {
    return TRUE;
  }

  // Ensure that the common control DLL is loaded.
  InitCommonControls();


  /* Fill in window class structure with parameters that describe the      */
  /* main window.                                                          */

  wcProjectDetailView.style = 0;                     
  wcProjectDetailView.lpfnWndProc = (WNDPROC)ProjectDetailViewWndProc; 
  wcProjectDetailView.cbClsExtra = 0;             
  wcProjectDetailView.cbWndExtra = 0;             
  wcProjectDetailView.hInstance = hInstance;
  wcProjectDetailView.hIcon = NULL;
  wcProjectDetailView.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcProjectDetailView.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wcProjectDetailView.lpszMenuName =  NULL; 
  wcProjectDetailView.lpszClassName = TEXT("ProjectDetailViewWClass");

  return (RegisterClass(&wcProjectDetailView));
}

/****************************************************************************
*
*   FUNCTION: CreateProjectDetailWindow(HINSTANCE hInstance, HWND hwndParent)
*
*   PURPOSE:  Creates a ProjectDetailView window
*
****************************************************************************/

HWND CreateProjectDetailWindow(HINSTANCE hInstance, HWND hwndParent) {

  RegisterProjectDetailViewClass(hInstance);
  return CreateWindow(
                  TEXT("ProjectDetailViewWClass"),
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

