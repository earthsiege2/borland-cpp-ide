#ifndef __PRJWIN_H
#define __PRJWIN_H
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  prjwin.h
  Created: 12/1/95
  Copyright (c) 1995, Borland International
  $Revision:   1.13  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <commctrl.h>
#include <ideaddon\imake.h>
#include <ideaddon\itool.h>

/****************************************************************************
* 
* TreeController
*
****************************************************************************/

class TreeController {
public:
  TreeController();
  ~TreeController();

  HWND        InitWindow(HWND hwndParent);
  unsigned    AddBranch(HTREEITEM tiParent, ProjectNode node);
  BOOL        AddTreeViewItems();
  HTREEITEM  AddOneItem(HTREEITEM hParent, LPCSTR szText, HTREEITEM hInsAfter, int iImage, LPARAM lParam);

  HTREEITEM  FindItem(HTREEITEM hitem, ProjectNode node);
  ProjectNode GetNodeFromItem(HTREEITEM ti);
  HTREEITEM  GetItemFromNode(ProjectNode node);
  void        OnExpanded(LPNM_TREEVIEW lpNMTreeView);

  void        SetImage(HTREEITEM  ti, unsigned idxImage);
  void        GetItem(HTREEITEM ti, TV_ITEM& item, unsigned mask);
  void        SetTopNode(ProjectNode topNode);
  ProjectNode GetTopNode() { return d_topNode; };
  void        DeleteTreeItem(ProjectNode node);
  void        AddNode(ProjectNode node);
  void        RemoveNodeFromProject(ProjectNode node);
  void        AddNodeToProject(ProjectNode node, char* name);

  HWND            d_hwnd;  // handle to the tree view window

protected:
  IProjectServer* d_projectServer;
  ProjectNode    d_topNode;

  // image list indices
  int d_idxCloseFolder, d_idxOpenFolder, d_idxFile, d_idxRoot;
};


class TreeModel {
public:
  TreeModel(HWND hwnd);
  ~TreeModel();

  void            SetSelected(HTREEITEM item);
  void            OnCommand(WORD wID, WORD wNotifyCode);
  TreeController* GetController();
  void            Attach(TreeController* tc);
  ProjectNode    GetSelectedNode();
  void            Resize(int w, int h);
  void            SetTopNode(ProjectNode topNode);
  ProjectNode    GetTopNode();
  void            SetProjectViewClient(IProjectViewClient*);

  void            OnNodeDeleted(ProjectNode node);
  void            OnNodeAdd(ProjectNode node);

  BOOL            GetNewNodeName(char* buf, int bufSize);

  HWND            d_hwnd;

protected:
  IMakeServer*    d_makeServer;
  IToolServer*    d_toolServer;
  HTREEITEM      d_selectedItem;
  TreeController* d_tc;
  IProjectViewClient* d_client;
};

inline TreeController* TreeModel::GetController() {
  return d_tc;
};

inline void TreeModel::Attach(TreeController* tc) {
  d_tc = tc;
};

inline void TreeModel::SetTopNode(ProjectNode topNode) {
  d_tc->SetTopNode(topNode);
  d_tc->AddTreeViewItems();
};

inline ProjectNode TreeModel::GetTopNode() {
  return d_tc->GetTopNode();
};

#define GetTreeModelFromHWND(hWnd) ((TreeModel*)GetWindowLong(hWnd, GWL_USERDATA))

#endif
