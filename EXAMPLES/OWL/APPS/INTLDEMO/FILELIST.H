//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1996 by Borland International
//   filelist.h
//----------------------------------------------------------------------------
#ifndef __FILELIST_H
#define __FILELIST_H

#if !defined(OWL_BUTTON_H)
#include <owl/button.h>
#endif
#include <bwcc.h>

class TFileListBox;

//
// class TFileListDialog
// ----- --------------- 
//
// Dialog box containing the FileListBox.
//
class TFileListDialog : public TDialog
{
  public:
    TFileListDialog(TWindow * parent, TModule* Module, int ResourceId = LIST_DIALOG);
    virtual ~TFileListDialog();

    void Sort(UINT);
    void ToLower(UINT);
    void View(UINT);
    void Help(UINT);

    virtual      char far* GetClassName()
    {
      return BORDLGCLASS;
    }

  private:
    TFileListBox* ListBox;
    TButton*      ViewButton;
    char*         StartDir;

  DECLARE_RESPONSE_TABLE(TFileListDialog);
};

#endif //__FILELIST_H
