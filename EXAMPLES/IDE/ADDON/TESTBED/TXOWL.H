/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   Copyright (c) 1987, 1995 Borland International Inc.  All Rights Reserved.
   $Revision:   1.13  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __TXOWL_H
#define __TXOWL_H

#ifndef __ITX_H
  #include <ideaddon\itx.h>
#endif

#ifndef __COMHELP_H
  #include <ideaddon\comhelp.h>
#endif

struct OwlTargetData {
  BOOL d_fDynamic;
  BOOL d_fBWCC;
};

struct OwlTarget : ITargetType, ITargetPropertyPage {
  ~OwlTarget();
  //
  // ITargetType
  //
  virtual BOOL         IsTargetable(IPolyString* fileExt);
  virtual ProjectNode ConvertNodeToTarget(ProjectNode node, IPolyString* name);
  virtual STDMETHODIMP ConvertTargetToNode(ProjectNode node);
  virtual HRESULT     GetClassID(CLSID *pClassID);

  //
  // ITargetPropertyPage
  //
  virtual void          PlatformSelectionChangeNotification(UINT id);
  virtual void          AdvancedDialog(HWND hwndParent);
  virtual void          Setup(ProjectNode);
  virtual void          OnCommand(UINT id);
  virtual void          GetDlgItems();
  virtual void          SetDlgItems();

  //
  // Locals
  //
          void          SetIDEObj(LPUNKNOWN ideObj);

  HTARGET                        d_hTarget;

protected:
  LPUNKNOWN                      d_IdeObj;
  ITargetManager*                d_targetMgr;
  ITargetManagerPropertyDialog*  d_targetMgrDlg;

  OwlTargetData                  d_targetData;
};

struct OwlTargetImpl : IUnknownImp<OwlTarget> {
  OwlTargetImpl(LPUNKNOWN IdeObj);

  STDMETHODIMP QueryInterface (THIS_ REFIID, LPVOID FAR *);
};

#endif // __TXOWL_H
