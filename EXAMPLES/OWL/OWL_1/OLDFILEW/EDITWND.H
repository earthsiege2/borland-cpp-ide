//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Definition of class TEditWindow.  This defines the OWL 1.0 compatible
//   text edit window
//----------------------------------------------------------------------------
#ifndef __EDITWND_H
#define __EDITWND_H

#ifndef __EDIT_H
  #include "owl\edit.h"
#endif
#ifndef __CHECKBOX_H
  #include "owl\checkbox.h"
#endif
#ifndef __DIALOG_H
  #include "owl\dialog.h"
#endif

#pragma option -Vo-
#if     defined(__BCOPT__) && !defined(_ALLOW_po)
#pragma option -po-
#endif

//
//  struct TSearchStruct
//  ------ -------------
//
struct _CLASSTYPE TSearchStruct {
  char  SearchText[81];
  BOOL  CaseSensitive;
  char  ReplaceText[81];
  BOOL  ReplaceAll;
  BOOL  PromptOnReplace;
};

_CLASSDEF(TEditWindow)
_CLASSDEF(TSearchDialog)

//
//  class TEditWindow
//  ----- -----------
//
class _EXPCLASS TEditWindow : public TWindow {
  public:
    TEdit*         Editor;
    TSearchStruct  SearchStruct;
    BOOL           IsReplaceOp; // TRUE if search and replace search

    TEditWindow(TWindow*        parent,
                const char far* title,
                TModule*        module = 0);

    void  DoSearch();

  protected:
    //
    // message response functions
    //
    void          EvSize(UINT sizeType, TSize&);
    void          EvSetFocus(HWND lostFocus);

    //
    // menu command handlers
    //
    void          CmEditFind();      // CM_EDITFIND
    void          CmEditFindNext();  // CM_EDITFINDNEXT
    void          CmEditReplace();   // CM_EDITREPLACE

  DECLARE_RESPONSE_TABLE(TEditWindow);
  DECLARE_STREAMABLE(_EXPCLASS, TEditWindow, 1);
};


//
//  class TSearchDialog
//  ----- -------------
//
class _EXPCLASS TSearchDialog : public TDialog {
  public:
    TSearchDialog(TWindow*        parent,
                  int             resourceId,
                  TSearchStruct&  searchStruct,
                  TModule*        module = 0);
};

#pragma option -Vo.
#if     defined(__BCOPT__) && !defined(_ALLOW_po)
#pragma option -po.
#endif

#endif //__EDITWND_H
