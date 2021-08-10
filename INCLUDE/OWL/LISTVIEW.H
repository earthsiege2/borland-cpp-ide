//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Defines class TListView
//----------------------------------------------------------------------------
#if !defined(OWL_LISTVIEW_H)
#define OWL_LISTVIEW_H

#if !defined(OWL_DOCMANAG_H)
# include <owl/docmanag.h>
#endif
#if !defined(OWL_LISTBOX_H)
# include <owl/listbox.h>
#endif
#include <owl/listview.rh>

//
//  class TListView
//  ----- ---------
//
class _OWLCLASS TListView : public TListBox, public TView {
  public:
    TListView(TDocument& doc, TWindow* parent = 0);
    static const char far* StaticName() {return "List View";}  // put in resource
    int  DirtyFlag;

    //
    // overridden virtuals from TView
    //
    const char far* GetViewName() {return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    bool     SetDocTitle(const char far* docname, int index)
                          {return TListBox::SetDocTitle(docname, index); }

    //
    // overridden virtuals from TListBox
    //
    int  AddString(const char far* str);

    //
    // overridden virtuals from TWindow
    //
    bool CanClose()   {return TListBox::CanClose() && Doc->CanClose();}
    bool Create();

  protected:
    long Origin;
    int  MaxWidth;    // maximum horizontal extent
    void SetExtent(const char far* str);
    bool LoadData(int top, int sel);
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
    uint EvGetDlgCode(MSG far*);
    bool VnDocClosed(int omode);
    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnIsWindow(HWND hWnd) {return HWindow == hWnd;}
    bool VnIsDirty() {return DirtyFlag != 0;}
    void CmSelChange() {} // to prevent interpreting as unprocessed accelerator

  DECLARE_RESPONSE_TABLE(TListView);
  DECLARE_STREAMABLE(_OWLCLASS, TListView,1);
};

#endif  // OWL_LISTVIEW_H

