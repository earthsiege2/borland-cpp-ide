//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Definition of class TFileWindow.  This defines the OWL 1.0 compatible
//   file edit window
//----------------------------------------------------------------------------
#ifndef __FILEWND_H
#define __FILEWND_H

#ifndef __EDITWND_H
  #include "editwnd.h"
#endif __EDITWND_H

#ifndef __FILEDIAL_H
  #include "filedial.h"
#endif __FILEDIAL_H

#pragma option -Vo-
#if     defined(__BCOPT__) && !defined(_ALLOW_po)
#pragma option -po-
#endif

_CLASSDEF(TFileWindow)

//
//  class TFileWindow
//  ----- -----------
//
class _EXPCLASS TFileWindow : public TEditWindow {
  public:
    char far*  FileName;
    BOOL       IsNewFile;

    TFileWindow(TWindow*        parent,
                const char far* title,
                const char far* fileName,
                TModule*        module = 0);

   ~TFileWindow();

    virtual BOOL  CanClear();
    virtual BOOL  CanClose() {return CanClear();}

    void          NewFile();
    void          Open();
    BOOL          Read(const char far* fileName = 0);
    void          ReplaceWith(const char far* filename);
    BOOL          Save();
    BOOL          SaveAs();
    void          SetFileName(const char far* filename);
    BOOL          Write(const char far* fileName = 0);

  protected:
    //
    // menu command response functions
    //
    void          CmFileNew() {NewFile();}    // CM_FILENEW
    void          CmFileOpen() {Open();}      // CM_FILEOPEN
    void          CmFileSave() {Save();}      // CM_FILESAVE
    void          CmFileSaveAs() {SaveAs();}  // CM_FILESAVEAS

    virtual void SetupWindow();

  DECLARE_RESPONSE_TABLE(TFileWindow);
  DECLARE_STREAMABLE(_EXPCLASS, TFileWindow, 1);
};

#pragma option -Vo.
#if     defined(__BCOPT__) && !defined(_ALLOW_po)
#pragma option -po.
#endif

#endif //__FILEWND_H
