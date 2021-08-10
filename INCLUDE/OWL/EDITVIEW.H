//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of class TEditView
//----------------------------------------------------------------------------
#if !defined(OWL_EDITVIEW_H)
#define OWL_EDITVIEW_H

#if !defined(OWL_DOCMANAG_H)
# include <owl/docmanag.h>
#endif
#if !defined(OWL_EDITSEAR_H)
# include <owl/editsear.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TEditView
// ~~~~~ ~~~~~~~~~
class _OWLCLASS TEditView : public TEditSearch, public TView {
  public:
    TEditView(TDocument& doc, TWindow* parent = 0);
   ~TEditView();
    static const char far* StaticName();  // put in resource

    // Overridden virtuals from TView
    //
    const char far* GetViewName();
    TWindow* GetWindow();
    bool     SetDocTitle(const char far* docname, int index);

    // Overridden virtuals from TWindow
    //
    bool   Create();
    void   PerformCreate(int menuOrId);
    bool   CanClose();

  protected:
    bool   LoadData();

    long   GetOrigin() const;
    void   SetOrigin(long origin);

    // message response functions
    //
    void   EvNCDestroy();
    bool   VnCommit(bool force);
    bool   VnRevert(bool clear);
    bool   VnIsWindow(HWND hWnd);
    bool   VnIsDirty() ;
    bool   VnDocClosed(int omode);

  protected_data:
    long   Origin;

  DECLARE_RESPONSE_TABLE(TEditView);
  DECLARE_STREAMABLE(_OWLCLASS, TEditView,1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementation
//

//
inline const char far* TEditView::StaticName() {
  return "Edit View";
}  // put in resource

//
inline const char far* TEditView::GetViewName() {
  return StaticName();
}

//
inline TWindow* TEditView::GetWindow() {
  return (TWindow*)this;
}

//
inline bool TEditView::SetDocTitle(const char far* docname, int index) {
  return TEditSearch::SetDocTitle(docname, index);
}

//
inline bool TEditView::CanClose() {
  return TEditSearch::CanClose() && Doc->CanClose();
}

//
// Return the position of the stream buffer at which the edit buffer is stored.
//
inline long TEditView::GetOrigin() const {
  return Origin;
}

//
// Sets the position of the stream buffer that the edit buffer is stored.
//
inline void TEditView::SetOrigin(long origin) {
  Origin = origin;
}

//
inline bool TEditView::VnIsDirty() {
  return TEditSearch::IsModified();
}


#endif  // OWL_EDITVIEW_H
