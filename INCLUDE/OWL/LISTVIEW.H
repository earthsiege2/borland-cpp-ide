//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   include\owl\listview.h
//   Defines class TListView
//----------------------------------------------------------------------------
#if !defined(__OWL_LISTVIEW_H)
#define __OWL_LISTVIEW_H

#if !defined(__OWL_DOCMANAG_H)
  #include <owl\docmanag.h>
#endif
#if !defined(__OWL_LISTBOX_H)
  #include <owl\listbox.h>
#endif
#include <owl\listview.rc>

//
//  class TListView
//  ----- ---------
//
class _OWLCLASS TListView : public TListBox, public TView {
  public:
    TListView(TDocument& doc, TWindow* parent = 0);
    static LPCSTR StaticName() {return "List View";}  // put in resource
    BOOL DirtyFlag;
    //
    // overridden virtuals from TView
    //
    LPCSTR   GetViewName(){return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    BOOL     SetDocTitle(LPCSTR docname, int index)
                          {return TListBox::SetDocTitle(docname, index); }
    //
    // overridden virtuals from TWindow
    //
    BOOL CanClose()   {return TListBox::CanClose() && Doc->CanClose();}
    BOOL Create();

  protected:
    long Origin;
    int  MaxWidth;    // maximum horizontal extent
    void SetExtent(LPSTR str);
    BOOL LoadData(int top, int sel);
    //
    // message response functions
    //
    void CmEditUndo();
    void CmEditCut();
    void CmEditCopy();
    void CmEditPaste();
    void CmEditDelete();
    void CmEditClear();
    void CmEditAdd();
    void CmEditItem();
    UINT EvGetDlgCode(MSG far*);
    BOOL VnDocClosed(int omode);
    BOOL VnCommit(BOOL force);
    BOOL VnRevert(BOOL clear);
    BOOL VnIsWindow(HWND hWnd) {return HWindow == hWnd;}
    BOOL VnIsDirty()       {return DirtyFlag;}
    void CmSelChange(){} // to prevent interpreting as unprocessed accelerator

  DECLARE_RESPONSE_TABLE(TListView);
  DECLARE_STREAMABLE(_OWLCLASS, TListView,1);
};

#endif  // __OWL_LISTVIEW_H

