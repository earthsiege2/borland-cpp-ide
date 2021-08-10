//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
//----------------------------------------------------------------------------
#if !defined(OWL_OLEVIEW_H)
#define OWL_OLEVIEW_H

#if !defined(OWL_OLEWINDO_H)
# include <owl/olewindo.h>
#endif
#if !defined(OWL_DOCVIEW_H)
# include <owl/docview.h>
#endif
#if !defined(OWL_DOCMANAG_H)
# include <owl/docmanag.h>
#endif

//
// Additional notification messages
//
const int vnInvalidate  = 9;   // a rect in view needs repaint
const int vnLinkView    = 10;  // find view with matched TOcLinkView
const int vnLinkMoniker = 11;  // find view with matched moniker

NOTIFY_SIG(vnInvalidate, TRect&)
NOTIFY_SIG(vnLinkView, TOcLinkView&)
NOTIFY_SIG(vnLinkMoniker, TString&)

#define EV_VN_INVALIDATE  VN_DEFINE(vnInvalidate,  VnInvalidate,  long)
#define EV_VN_LINKVIEW    VN_DEFINE(vnLinkView,    VnLinkView,    long)
#define EV_VN_LINKMONIKER VN_DEFINE(vnLinkMoniker, VnLinkMoniker, long)

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TOleView
// ~~~~~ ~~~~~~~~
// The ole 2 window view class. Used as a view in doc/view model
//
class _USERCLASS TOleView : public TOleWindow, public TView {
  public:
    TOleView(TDocument& doc, TWindow* parent = 0);
   ~TOleView();

    static const char far* StaticName();

    // Inherited virtuals from TView
    //
    const char far* GetViewName();
    TWindow* GetWindow();
    bool     SetDocTitle(const char far* docname, int index);
    bool     OleShutDown();

  protected:
    bool CanClose();
    TOcView* CreateOcView(TRegLink* link, bool isEmbedded, IUnknown* outer);
    void CleanupWindow();
    bool OtherViewExists();

    // View notifications
    //
    bool VnInvalidate(TRect& rect);
    bool VnDocOpened(int omode);
    bool VnDocClosed(int omode);

    TMenuDescr* GetViewMenu();

    const char far* GetFileName();

    bool EvOcViewPartInvalid(TOcPartChangeInfo& changeInfo);
//    uint32 EvOcViewDiscardUndo(void far* undo);

    // Container specific messages
    //
//    bool   EvOcAppInsMenus(TOcMenuDescr far&);

    // Server specific messages
    //
    bool   EvOcViewClose();
    bool   EvOcViewSavePart(TOcSaveLoad far& ocSave);
    bool   EvOcViewLoadPart(TOcSaveLoad far& ocLoad);
    bool   EvOcViewOpenDoc(const char far* path);
    bool   EvOcViewInsMenus(TOcMenuDescr far& sharedMenu);
    bool   EvOcViewAttachWindow(bool attach);
    bool   EvOcViewSetLink(TOcLinkView& view);
    bool   EvOcViewBreakLink(TOcLinkView& view);
    bool   EvOcViewGetItemName(TOcItemName& item);

  private:
    bool   Destroying;

    // event handlers
    //
    bool     VnIsWindow(HWND hWnd);

  DECLARE_RESPONSE_TABLE(TOleView);
  DECLARE_STREAMABLE(_OWLCLASS, TOleView,1);
};

//
// class TOleLinkView
// ~~~~~ ~~~~~~~~~~~~
class _DOCVIEWCLASS TOleLinkView : public TView {
  public:
    TOleLinkView(TDocument& doc, TOcLinkView& view);
   ~TOleLinkView();

    virtual bool VnLinkView(TOcLinkView& view);
    virtual bool VnLinkMoniker(TString& moniker);
    virtual bool UpdateLinks();
    TString& GetMoniker();

    static const char far* StaticName();
    const char far* GetViewName();

  protected:
    TOcLinkView&  OcLinkView;     // TOcLinkView partner for this view

  DECLARE_RESPONSE_TABLE(TOleLinkView);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

// --------------------------------------------------------------------------
// Inline implementation
//

//
inline const char far* TOleView::StaticName() {
  return "Ole View";
}

//
inline const char far* TOleView::GetViewName() {
  return StaticName();
}

//
inline TWindow* TOleView::GetWindow() {
  return (TWindow*)this;
}

//
inline bool TOleView::SetDocTitle(const char far* docname, int index) {
  return TWindow::SetDocTitle(docname, index);
}

//
inline const char far* TOleView::GetFileName() {
  return GetDocument().GetTitle();
}

//
inline const char far* TOleLinkView::StaticName() {
  return "Link View";
}

//
inline const char far* TOleLinkView::GetViewName() {
  return StaticName();
}



#endif  // OWL_OLEVIEW_H
