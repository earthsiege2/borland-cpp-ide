//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TListView
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

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TListView
// ~~~~~ ~~~~~~~~~
class _OWLCLASS TListView : public TListBox, public TView {
  public:
    TListView(TDocument& doc, TWindow* parent = 0);

    // Overridden virtuals from TView
    //
    const char far* GetViewName();
    TWindow* GetWindow();
    bool     SetDocTitle(const char far* docname, int index);

    // Overridden virtuals from TListBox
    //
    int  AddString(const char far* str);

    // Overridden virtuals from TWindow
    //
    bool CanClose();
    bool Create();

    static const char far* StaticName();  // put in resource

  protected:
    long GetOrigin() const;
    void SetOrigin(long origin);

    int  GetMaxWidth() const;
    void SetMaxWidth(int maxwidth);

    void SetExtent(const char far* str);
    bool LoadData(int top, int sel);

    // Message response functions
    //
    void CmEditUndo();
    void CmEditCut();
    void CmEditCopy();
    void CmEditPaste();
    void CmEditDelete();
    void CmEditClear();
    void CmEditAdd();
    void CmEditItem();
    void CmSelChange();

    uint EvGetDlgCode(MSG far*);

    bool VnDocClosed(int omode);
    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnIsWindow(HWND hWnd);
    bool VnIsDirty();

  public_data:
    int  DirtyFlag;   // flag to indicate if the view is dirty

  protected_data:
    long Origin;      // object's beginning position on the stream
    int  MaxWidth;    // maximum horizontal extent

  DECLARE_RESPONSE_TABLE(TListView);
  DECLARE_STREAMABLE(_OWLCLASS, TListView,1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the name of the view window.
//
inline const char far* TListView::StaticName() {
  return "List View";
}

//
// Return the name of the view window.
//
inline const char far* TListView::GetViewName() {
  return StaticName();
}

//
// Return the window object.
//
inline TWindow* TListView::GetWindow() {
  return (TWindow*)this;
}

//
// Set the title for the document.
//
inline bool TListView::SetDocTitle(const char far* docname, int index) {
  return TListBox::SetDocTitle(docname, index);
}

//
// Return true if both the listbox and the document can close.
//
inline bool TListView::CanClose() {
  return TListBox::CanClose() && Doc->CanClose();
}

//
// Return the origin position on the persistent stream.
//
inline long TListView::GetOrigin() const {
  return Origin;
}

//
// Set the position of the object.
//
inline void TListView::SetOrigin(long origin) {
  Origin = origin;
}

//
// Return the maximum width of the strings.
//
inline int TListView::GetMaxWidth() const {
  return MaxWidth;
}

//
// Set the maximum width of the strings.
//
inline void TListView::SetMaxWidth(int maxwidth) {
  MaxWidth = maxwidth;
}

//
// Return true if the view's window and the parameter is the same.
//
inline bool TListView::VnIsWindow(HWND hWnd) {
  return GetHandle() == hWnd;
}

//
// Return true if the view is dirty (modified) since the last save.
//
inline bool TListView::VnIsDirty() {
  return DirtyFlag != 0;
}


#endif  // OWL_LISTVIEW_H
