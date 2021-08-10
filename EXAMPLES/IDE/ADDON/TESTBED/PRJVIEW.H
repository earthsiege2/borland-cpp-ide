#ifndef __PRJVIEW_H
#define __PRJVIEW_H

#include <ideaddon\iview.h>

/******************************************************************************
*
*
* ProjectViewFactory
*
*
******************************************************************************/
struct ProjectViewFactory : IUnknownImp<IUserViewFactory> {

  ProjectViewFactory(IViewType* projectView);

  virtual IViewClient * CreateView(IViewParentWnd* wndServer,
                                    void * restoreData);
  virtual void InitializeProperty(IViewType* viewType);
};

struct IProjectViewClient : public IViewClient,
                            public IProjectClient {

  STDMETHODIMP QueryInterface (THIS_ REFIID, LPVOID FAR *) = 0;
  STDMETHODIMP_(ULONG) AddRef (THIS) =0 ;
  STDMETHODIMP_(ULONG) Release (THIS) = 0;
 
  virtual void      Stop() = 0;
};


#define UM_SETROOT (WM_USER + 1)
void  CreateNewProjectView(ProjectNode node);
HWND CreateTreeWindow(HINSTANCE hInstance, HWND hwndParent);

#endif // __PRJVIEW_H
