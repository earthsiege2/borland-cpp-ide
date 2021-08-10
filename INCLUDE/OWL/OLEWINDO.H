//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(OWL_OLEWINDO_H)
#define OWL_OLEWINDO_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_OCFEVENT_H)
# include <owl/ocfevent.h>
#endif
#if !defined(OCF_OCREMVIE_H)
# include <ocf/ocremvie.h>
#endif
#if !defined(OCF_OCPART_H)
# include <ocf/ocpart.h>
#endif
#if !defined(OWL_UIHANDLE_H)
# include <owl/uihandle.h>
#endif
#if !defined(OCF_OCLINK_H)
# include <ocf/oclink.h>
#endif

//
// class TOleWindow
// ----- ----------
//
// The generic ole 2 window. Use as a client of a frame window.
//
class _USERCLASS TOleWindow : public TWindow {
  public:
    TOleWindow(TWindow* parent = 0, TModule* module = 0);
   ~TOleWindow();

    // Accessors
    //
    TOcDocument* GetOcDoc() {return OcDoc;}
    TOcView*     GetOcView() {return OcView;}
    TOcRemView*  GetOcRemView() {return TYPESAFE_DOWNCAST(OcView, TOcRemView);}
    TOcApp*      GetOcApp() {return OcApp;}
    bool         HasActivePart();
    bool         SelectEmbedded() {return DragPart != 0;}
    bool         OleShutDown();

    bool IsOpenEditing() const;
    bool IsRemote() const {return Remote;}

    virtual void SetupDC(TDC& dc, bool scale = true);
    virtual TOcView* CreateOcView(TRegLink* link, bool isRemote, IUnknown* outer);

  protected:
    // Overridables
    //
    virtual void GetInsertPosition(TRect& rect);
    virtual void InvalidatePart(TOcInvalidate invalid); // server only
    virtual bool Deactivate();
    virtual bool Select(uint modKeys, TPoint& point);
    virtual bool PaintSelection(TDC& dc, bool erase, TRect& rect,
                                void* userData = 0){return false;}
    virtual bool PaintParts(TDC& dc, bool erase, TRect& rect, bool metafile);
    virtual bool PaintLink(TDC& dc, bool erase, TRect& rect,
                           TString& moniker) {return false;}
    virtual void GetLogPerUnit(TSize& logPerUnit);
    virtual void SetScale(uint16 percent);
    virtual void SetSelection(TOcPart* part);
    virtual bool ShowCursor(HWND wnd, uint hitTest, uint mouseMsg);

  protected:
    void SetupWindow();
    void CleanupWindow();
    bool IdleAction(long idleCount);

    LRESULT EvCommand(uint id, HWND hWndCtl, uint notifyCode);
    void    EvCommandEnable(TCommandEnabler& commandEnabler);
    bool    CanClose();
    bool InClient(TDC& dc, TPoint& point);

    void EvPaint();
    void EvSize(uint sizeType, TSize& size);
    void EvMDIActivate(HWND hWndActivated, HWND hWndDeactivated);
    uint EvMouseActivate(HWND topParent, uint hitCode, uint msg);
    void EvSetFocus(HWND hWndLostFocus);

    virtual bool EvOcViewPartInvalid(TOcPartChangeInfo& changeInfo);

    void EvClose();
    void CmFileClose();
    void CeFileClose(TCommandEnabler& ce);

    void CmEditDelete();
    void CmEditCut();
    void CmEditCopy();
    void CmEditPaste();
    void CmEditPasteSpecial();
    void CmEditPasteLink();
    void CmEditLinks();
    void CmEditConvert();
    void CmEditInsertObject();
    void CmEditShowObjects();

    void CeEditDelete(TCommandEnabler& ce);
    void CeEditCut(TCommandEnabler& ce);
    void CeEditCopy(TCommandEnabler& ce);
    void CeEditPaste(TCommandEnabler& ce);
    void CeEditPasteSpecial(TCommandEnabler& ce);
    void CeEditPasteLink(TCommandEnabler& ce);
    void CeEditLinks(TCommandEnabler& ce);
    void CeEditObject(TCommandEnabler& ce);
    void CeEditConvert(TCommandEnabler& ce);
    void CeEditVerbs(TCommandEnabler& ce);
    void CeEditInsertObject(TCommandEnabler& ce);
    void CeEditShowObjects(TCommandEnabler& ce);

    void EvMouseMove(uint modKeys, TPoint& point);
    void EvRButtonDown(uint modKeys, TPoint& point);
    void EvLButtonUp(uint modKeys, TPoint& point);
    void EvLButtonDown(uint modKeys, TPoint& point);
    void EvLButtonDblClk(uint modKeys, TPoint& point);
    bool EvSetCursor(HWND hWndCursor, uint hitTest, uint mouseMsg);
    void EvDropFiles(TDropInfo dropInfo);
    void EvHScroll(uint scrollCode, uint thumbPos, HWND hWndCtl);
    void EvVScroll(uint scrollCode, uint thumbPos, HWND hWndCtl);
    void EvMenuSelect(uint menuItemId, uint flags, HMENU hMenu);

    LRESULT EvOcEvent(WPARAM wParam, LPARAM lParam);
//    uint32 EvOcViewDiscardUndo(void far* undo);

    // Container specific messages
    //
    const char far* EvOcViewTitle();
    void   EvOcViewSetTitle(const char far* title);

    bool   EvOcViewBorderSpaceReq(TRect far* rect);
    bool   EvOcViewBorderSpaceSet(TRect far* rect);
    bool   EvOcViewDrop(TOcDragDrop far& ddInfo);
    bool   EvOcViewDrag(TOcDragDrop far& ddInfo);
    bool   EvOcViewScroll(TOcScrollDir scrollDir);
    bool   EvOcViewGetScale(TOcScaleFactor& scaleFactor);
    bool   EvOcViewGetSiteRect(TRect far* rect);
    bool   EvOcViewSetSiteRect(TRect far* rect);
    bool   EvOcViewPartActivate(TOcPart& ocPart);
    bool   EvOcViewPasteObject(TOcInitInfo& init);

    // Server specific messages
    //
    bool   EvOcPartInvalid(TOcPart far& /*part*/) {return false;}
    bool   EvOcViewSavePart(TOcSaveLoad far& ocSave);
    bool   EvOcViewLoadPart(TOcSaveLoad far& ocLoad);
    bool   EvOcViewPaint(TOcViewPaint far& vp);
    bool   EvOcViewInsMenus(TOcMenuDescr far& sharedMenu);
    bool   EvOcViewShowTools(TOcToolBarInfo far& tbi);
    bool   EvOcViewGetPalette(LOGPALETTE far* far* palette);
    bool   EvOcViewClipData(TOcFormatData far& format);
    bool   EvOcViewClose();
    bool   EvOcViewPartSize(TOcPartSize far& size);
    bool   EvOcViewOpenDoc(const char far* path);
    bool   EvOcViewAttachWindow(bool attach);
    bool   EvOcViewSetScale(TOcScaleFactor& scaleFactor);
    bool   EvOcViewGetItemName(TOcItemName& item);
    bool   EvOcViewSetLink(TOcLinkView& view);
    bool   EvOcViewBreakLink(TOcLinkView& view);

    TPopupMenu* CreateVerbPopup(const TOcVerb& ocVerb);
    void EvDoVerb(uint whichVerb);
    void Init();

  protected:
    TOcPart*          DragPart;
    TUIHandle::TWhere DragHit;
    TDC*              DragDC;
    TPoint            DragPt;
    TRect             DragRect;
    TPoint            DragStart;
    TOcScaleFactor    Scale;              // current scaling factor
    TRect             Pos;                // current position

    TOcDocument*      OcDoc;              // associated OCF document partner
    TOcView*          OcView;             // associated OCF view partner
    TOcApp*           OcApp;              // associated OCF app partner
    string            ContainerName;      // Name for this container

    bool              Remote;             // Using a remote OC view?
    bool              ShowObjects;        // Show embedded part frames?

  DECLARE_RESPONSE_TABLE(TOleWindow);
};


//
// class TOleClientDC
// ----- ------------
//
// The TOleClientDC is a client dc with window origin, ext, and viewport
// origin, ext set up to reflect the current scrolling and scaling information.
//
class TOleClientDC : public TClientDC {
  public:
    TOleClientDC(TOleWindow& win, bool scale = true);
};


#endif
