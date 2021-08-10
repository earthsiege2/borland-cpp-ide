/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   Created: 1/22/96
   Copyright (c) 1987, 1996 Borland International Inc.  All Rights Reserved.
   $Revision:   1.16  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __ADDONPG_H
#define __ADDONPG_H

#include <ideaddon\iproj.h>
#include <ideaddon\ioption.h>
#include <ideaddon\comhelp.h>

class AddonPageBase : public IUnknownImp<IMpdPage> {
public:
  AddonPageBase();

  virtual VOID Init(HWND hDlg, IStatusBar* isb);
  virtual HINSTANCE    GetHInstance();
  virtual UINT          GetResourceId();
  virtual IPolyString*  GetPageTitle();
  virtual UINT          GetPageStyle();

  virtual BOOL CanClose() {return 1;};
  virtual void SetDlgItems(){};
  virtual void GetDlgItems(){};
  virtual BOOL IsModified();
  virtual VOID Undo();
  virtual LRESULT OnCommand(UINT id, HWND hWndCtl, UINT notifyCode) { return 0;};

  virtual void Help(BOOL fF1Key);
  virtual void DisplayPageStatus();

  //
  // derived methods
  //
      void SetStatusText(char* t);
      void SetModified(BOOL mod) { d_modified = mod; };
  //
  //  new
  //
      void SetInfo(UINT pStyle, UINT pid, char* title);

protected:
  // private variables
  BOOL                      d_modified;
  HWND                      d_hDlg;
  IStatusBar*              d_statusBar;
  UINT                      d_pageResource;
  UINT                      d_pageStyle;
  char*                    d_pageTitle;
};


class IMpdChapterAddon : public IUnknownImp<IMpdChapter> {
public:
  IMpdChapterAddon();
  ~IMpdChapterAddon();

  virtual void      Init();

  virtual void      SetEditNode(ProjectNode);
  virtual IMpdPage* OpenPage(UINT pid, ProjectNode node);
  virtual UINT      GetPageCount();
  virtual IMpdPage* GetPage(UINT iPage);
  virtual void      Close(UINT fOk);

protected:
  unsigned        d_nPages;
  AddonPageBase*  d_pages[3];
};

class IMpdProjectChapterAddon : public IMpdChapterAddon {
public:
  IMpdProjectChapterAddon();
  ~IMpdProjectChapterAddon();

  virtual void      Init();

  virtual UINT GetResourceId();
  virtual IMpdPage* OpenPage(UINT pid, ProjectNode node);

protected:
  IProjectServer*  d_projectServer;
  IOptionSetServer* d_optionSetServer;
};

#endif // __ADDONPG_H
