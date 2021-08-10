/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  pdwin.h
  Created: 12/1/95
  Copyright (c) 1995, Borland International
  $Revision:   1.13  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#ifndef __MSGWIN_H
#define __MSGWIN_H

#include <ideaddon\iproj.h>
#include <ideaddon\itarg.h>
#include <ideaddon\imake.h>

class ProjectDetailView {
public:
  ProjectDetailView(HWND);
  ~ProjectDetailView();

  void            Resize(int w, int h);
  void            CreateList();
  void            ShowSelectedNodes();
  void            ShowNodes(ProjectNode* nodes, int numNodes);
  void            InitColumns();
  void            ShowNode(ProjectNode node);

protected:

  IProjectServer* d_projectServer;
  IMakeServer*    d_makeServer;
  ITargetServer*  d_targetServer;
  HWND            d_hwndList;
  HWND            d_hwnd;

};

#define GetProjectDetailViewFromHWND(hWnd) ((ProjectDetailView*)GetWindowLong(hWnd, GWL_USERDATA))


#endif // __MSGWIN_H
