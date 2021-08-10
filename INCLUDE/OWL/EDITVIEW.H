//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Defines class TEditView
//----------------------------------------------------------------------------
#if !defined(OWL_EDITVIEW_H)
#define OWL_EDITVIEW_H

#if !defined(OWL_DOCMANAG_H)
# include <owl/docmanag.h>
#endif
#if !defined(OWL_EDITSEAR_H)
# include <owl/editsear.h>
#endif

//
//  class TEditView
//  ----- ---------
//
class _OWLCLASS TEditView : public TEditSearch, public TView {
  public:
    TEditView(TDocument& doc, TWindow* parent = 0);
   ~TEditView();
    static const char far* StaticName() {return "Edit View";}  // put in resource
    //
    // overridden virtuals from TView
    //
    const char far*   GetViewName(){return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    bool     SetDocTitle(const char far* docname, int index)
                          {return TEditSearch::SetDocTitle(docname, index); }
    //
    // overridden virtuals from TWindow
    //
    bool   Create();
    void   PerformCreate(int menuOrId);
    bool   CanClose()   {return TEditSearch::CanClose() && Doc->CanClose();}

  protected:
    long   Origin;
    bool   LoadData();
    //
    // message response functions
    //
    void   EvNCDestroy();
    bool   VnCommit(bool force);
    bool   VnRevert(bool clear);
    bool   VnIsWindow(HWND hWnd) {return HWindow == hWnd;}
    bool   VnIsDirty()  {return TEditSearch::IsModified();}
    bool   VnDocClosed(int omode);
        
  DECLARE_RESPONSE_TABLE(TEditView);
  DECLARE_STREAMABLE(_OWLCLASS, TEditView,1);
};

#endif  // OWL_EDITVIEW_H

