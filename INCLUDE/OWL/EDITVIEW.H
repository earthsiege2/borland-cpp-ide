//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   include\owl\editview.h
//   Defines classes TEditView
//----------------------------------------------------------------------------
#if !defined(__OWL_EDITVIEW_H)
#define __OWL_EDITVIEW_H

#if !defined(__OWL_DOCMANAG_H)
  #include <owl\docmanag.h>
#endif
#if !defined(__OWL_EDITSEAR_H)
  #include <owl\editsear.h>
#endif

//
//  class TEditView
//  ----- ---------
//
class _OWLCLASS TEditView : public TEditSearch, public TView {
  public:
    TEditView(TDocument& doc, TWindow* parent = 0);
   ~TEditView();
    static LPCSTR StaticName() {return "Edit View";}  // put in resource
    //
    // overridden virtuals from TView
    //
    LPCSTR   GetViewName(){return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    BOOL     SetDocTitle(LPCSTR docname, int index)
                          {return TEditSearch::SetDocTitle(docname, index); }
    //
    // overridden virtuals from TWindow
    //
    BOOL   Create();
    void   PerformCreate(int menuOrId);
    BOOL   CanClose()   {return TEditSearch::CanClose() && Doc->CanClose();}

  protected:
    long   Origin;
    BOOL   LoadData();
    //
    // message response functions
    //
    void   EvNCDestroy();
    BOOL   VnCommit(BOOL force);
    BOOL   VnRevert(BOOL clear);
    BOOL   VnIsWindow(HWND hWnd) {return HWindow == hWnd;}
    BOOL   VnIsDirty()  {return TEditSearch::IsModified();}
    BOOL   VnDocClosed(int omode);
        
  DECLARE_RESPONSE_TABLE(TEditView);
  DECLARE_STREAMABLE(_OWLCLASS, TEditView,1);
};

#endif  // __OWL_EDITVIEW_H

