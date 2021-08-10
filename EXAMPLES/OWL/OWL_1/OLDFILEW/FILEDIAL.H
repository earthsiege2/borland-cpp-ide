//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Definition of class TFileDialog.  This defines the basic
//   behavior of the OWL 1.0 compatible TFileDialog
//----------------------------------------------------------------------------
#ifndef __FILEDIAL_H
#define __FILEDIAL_H

#ifndef __OWL_DIALOG_H
  #include <owl\dialog.h>
#endif
#ifndef __DIR_H
  #include <dir.h>
#endif

#pragma option -Vo-
#if     defined(__BCOPT__) && !defined(_ALLOW_po)
#pragma option -po-
#endif

#define FILESPEC  MAXPATH + MAXEXT

_CLASSDEF(TFileDialog)

//
//  class TFileDialog
//  ----- -----------
//
class _EXPCLASS TFileDialog : public TDialog {
  public:
    char far* FilePath;
    char      PathName[MAXPATH];
    char      Extension[MAXEXT];
    char      FileSpec[FILESPEC];

    TFileDialog(TWindow*  parent,
                int       resourceId,
                char far* filePath,
                TModule*  module = 0);

    virtual BOOL  CanClose();
    void          SelectFileName();
    void          UpdateFileName();
    BOOL          UpdateListBoxes();

    //
    // child notification handlers
    //
    void  FNameChange();     // EN_CHANGE for ID_FNAME
    void  FListChange();     // LBN_SELCHANGE for ID_FLIST
    void  FListDblClk();     // LBN_DBLCLK for ID_FLIST
    void  FListKillFocus();  // LBN_KILLFOCUS for ID_FLIST
    void  DListChange();     // LBN_SELCHANGE for ID_DLIST
    void  DListDblClk();     // LBN_DBLCLK for ID_DLIST
    void  DListKillFocus();  // LBN_KILLFOCUS for ID_DLIST

  protected:
    virtual void  SetupWindow();

  DECLARE_RESPONSE_TABLE(TFileDialog);
};

#pragma option -Vo.
#if     defined(__BCOPT__) && !defined(_ALLOW_po)
#pragma option -po.
#endif

#endif //__FILEDIAL_H
