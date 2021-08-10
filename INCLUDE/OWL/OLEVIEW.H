//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
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

//---------------------  Additional notification messages ---------------------
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

//
// class TOleView
// ----- --------
//
// The ole 2 window view class. Used as a view in doc/view model
//
class _USERCLASS TOleView : public TOleWindow, public TView {
  public:
    TOleView(TDocument& doc, TWindow* parent = 0);
   ~TOleView();

    static const char far* StaticName() {return "Ole View";}

    // Inherited virtuals from TView
    //
    const char far* GetViewName() {return StaticName();}
    TWindow* GetWindow() {return (TWindow*)this;}
    bool     SetDocTitle(const char far* docname, int index)
               {return TWindow::SetDocTitle(docname, index);}
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


//=====================  TOleLinkView  =======================================

class _DOCVIEWCLASS TOleLinkView : public TView {
  public:
    TOleLinkView(TDocument& doc, TOcLinkView& view);
   ~TOleLinkView();

    virtual bool VnLinkView(TOcLinkView& view);
    virtual bool VnLinkMoniker(TString& moniker);
    virtual bool UpdateLinks();
    TString& GetMoniker();

    static const char far* StaticName()
    {
      return "Link View";
    }

    const char far* GetViewName()
    {
      return StaticName();
    }

  protected:
    TOcLinkView&  OcLinkView;     // TOcLinkView partner for this view

  DECLARE_RESPONSE_TABLE(TOleLinkView);
};

#endif  // OWL_OLEVIEW_H
