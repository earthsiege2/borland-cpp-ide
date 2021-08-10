//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
//
//----------------------------------------------------------------------------
#if !defined(OWL_OLEWINDO_H)
#define OWL_OLEWINDO_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
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
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(OCF_OCLINK_H)
# include <ocf/oclink.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>


class _OWLCLASS TPopupMenu;
class _ICLASS   TOcControl;

//
// class TOleWindow
// ~~~~~ ~~~~~~~~~~
// The generic ole 2 window. Use as a client of a frame window.
//
class _USERCLASS TOleWindow : virtual public TWindow {
  public:
    TOleWindow(TWindow* parent = 0, TModule* module = 0);
   ~TOleWindow();

    // Accessors
    //
    TOcDocument* GetOcDoc();
    TOcView*     GetOcView();
    TOcRemView*  GetOcRemView();
    TOcApp*      GetOcApp();
    bool         HasActivePart();
    bool         SelectEmbedded();

    bool IsOpenEditing() const;
    bool IsRemote() const;

    virtual bool OleShutDown();
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
                                void* userData = 0);
    virtual bool PaintParts(TDC& dc, bool erase, TRect& rect, bool metafile);
    virtual bool PaintLink(TDC& dc, bool erase, TRect& rect,
                           TString& moniker);
    virtual void GetLogPerUnit(TSize& logPerUnit);
    virtual void SetScale(uint16 percent);
    virtual void SetSelection(TOcPart* part);
    virtual bool ShowCursor(HWND wnd, uint hitTest, uint mouseMsg);
    virtual bool StartDrag(uint modKeys, TPoint& point);
    virtual const char far* GetFileName();

  protected:
    void SetupWindow();
    void CleanupWindow();

    // Override virtual functions defined by TWindow
    //
    bool    PreProcessMsg(MSG& msg);
    bool    IdleAction(long idleCount);

    TResult EvCommand(uint id, HWND hWndCtl, uint notifyCode);
    void    EvCommandEnable(TCommandEnabler& commandEnabler);
    bool    CanClose();
    bool InClient(TDC& dc, TPoint& point);

    void EvPaint();
    void EvSize(uint sizeType, TSize& size);
    void EvMDIActivate(HWND hWndActivated, HWND hWndDeactivated);
    uint EvMouseActivate(HWND topParent, uint hitCode, uint msg);
    void EvSetFocus(HWND hWndLostFocus);

    virtual bool EvOcViewPartInvalid(TOcPartChangeInfo& changeInfo);

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
    void CmEditInsertControl();
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
    void CeEditInsertControl(TCommandEnabler& ce);
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

    TResult EvOcEvent(TParam1 param1, TParam2 param2);
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
    bool   EvOcPartInvalid(TOcPart far& /*part*/);
    bool   EvOcViewSavePart(TOcSaveLoad far& ocSave);
    bool   EvOcViewLoadPart(TOcSaveLoad far& ocLoad);
    bool   EvOcViewPaint(TOcViewPaint far& vp);
    bool   EvOcViewInsMenus(TOcMenuDescr far& sharedMenu);
    bool   EvOcViewShowTools(TOcToolBarInfo far& tbi);
    bool   EvOcViewGetPalette(LOGPALETTE far* far* palette);
    bool   EvOcViewClipData(TOcFormatData far& format);
    bool   EvOcViewSetData(TOcFormatData far& format);
    bool   EvOcViewClose();
    bool   EvOcViewPartSize(TOcPartSize far& size);
    bool   EvOcViewOpenDoc(const char far* path);
    bool   EvOcViewAttachWindow(bool attach);
    bool   EvOcViewSetScale(TOcScaleFactor& scaleFactor);
    bool   EvOcViewGetItemName(TOcItemName& item);
    bool   EvOcViewSetLink(TOcLinkView& view);
    bool   EvOcViewBreakLink(TOcLinkView& view);
    bool   EvOcViewDoVerb(uint verb);

    virtual bool   EvOcViewTransformCoords(uint verb);

    // Ambient property specific messages
    //
    virtual bool   EvOcAmbientGetBackColor(long* rgb);
    virtual bool   EvOcAmbientGetForeColor(long* rgb);
    virtual bool   EvOcAmbientGetLocaleID(long* locale);
    virtual bool   EvOcAmbientGetTextAlign(short* align);
    virtual bool   EvOcAmbientGetMessageReflect(bool* msgReflect);
    virtual bool   EvOcAmbientGetUserMode(bool* mode);
    virtual bool   EvOcAmbientGetUIDead(bool* dead);
    virtual bool   EvOcAmbientGetShowGrabHandles(bool* show);
    virtual bool   EvOcAmbientGetShowHatching(bool* show);
    virtual bool   EvOcAmbientGetDisplayAsDefault(bool* disp);
    virtual bool   EvOcAmbientGetSupportsMnemonics(bool* support);
    virtual bool   EvOcAmbientGetDisplayName(TString** name);
    virtual bool   EvOcAmbientGetScaleUnits(TString** units);
    virtual bool   EvOcAmbientGetFont(IDispatch** font);

    virtual bool   EvOcAmbientSetBackColor(long rgb);
    virtual bool   EvOcAmbientSetForeColor(long rgb);
    virtual bool   EvOcAmbientSetLocaleID(long locale);
    virtual bool   EvOcAmbientSetTextAlign(short align);
    virtual bool   EvOcAmbientSetMessageReflect(bool msgReflect);
    virtual bool   EvOcAmbientSetUserMode(bool mode);
    virtual bool   EvOcAmbientSetUIDead(bool dead);
    virtual bool   EvOcAmbientSetShowGrabHandles(bool show);
    virtual bool   EvOcAmbientSetShowHatching(bool show);
    virtual bool   EvOcAmbientSetDisplayAsDefault(bool disp);
    virtual bool   EvOcAmbientSetSupportsMnemonics(bool support);
    virtual bool   EvOcAmbientSetDisplayName(TString* name);
    virtual bool   EvOcAmbientSetScaleUnits(TString* units);
    virtual bool   EvOcAmbientSetFont(IDispatch* font);

    // Ctrl event specific messages
    //
    virtual bool   EvOcCtrlClick(TCtrlEvent* pev);
    virtual bool   EvOcCtrlDblClick(TCtrlEvent* pev);
    virtual bool   EvOcCtrlMouseDown(TCtrlMouseEvent* pev);
    virtual bool   EvOcCtrlMouseMove(TCtrlMouseEvent* pev);
    virtual bool   EvOcCtrlMouseUp(TCtrlMouseEvent* pev);
    virtual bool   EvOcCtrlKeyDown(TCtrlKeyEvent* pev);
    virtual bool   EvOcCtrlKeyUp(TCtrlKeyEvent* pev);
    virtual bool   EvOcCtrlErrorEvent(TCtrlErrorEvent* pev);
    virtual bool   EvOcCtrlFocus(TCtrlFocusEvent* pev);
    virtual bool   EvOcCtrlPropertyChange(TCtrlPropertyEvent* pev);
    virtual bool   EvOcCtrlPropertyRequestEdit(TCtrlPropertyEvent* pev);
    virtual bool   EvOcCtrlCustomEvent(TCtrlCustomEvent* pev);

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

    int               MinWidth;           // minimum width of part
    int               MinHeight;          // minimum height of part

  DECLARE_RESPONSE_TABLE(TOleWindow);
};


//
// class TOleClientDC
// ~~~~~ ~~~~~~~~~~~~
// The TOleClientDC is a client dc with window origin, ext, and viewport
// origin, ext, setup to reflect the current scrolling and scaling information.
//
class _USERCLASS TOleClientDC : public TClientDC {
  public:
    TOleClientDC(TOleWindow& win, bool scale = true);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

// --------------------------------------------------------------------------
// Inline implementation
//

//
// Return pointer to TOcDocument helper object associated with this window
//
inline TOcDocument* TOleWindow::GetOcDoc() {
  return OcDoc;
}

//
// Return pointer to the 'TOcView' helper object associated with this window
//
inline TOcView* TOleWindow::GetOcView() {
  return OcView;
}

//
// Return pointer to 'TOcRemView' object associated with this window.
// NOTE: Returns 0 in case of failure. For example, a TOleWindow of a 
//       container application does not have an associated 'TOcRemView'
//       and will return 0.
//
inline TOcRemView* TOleWindow::GetOcRemView() {
  return TYPESAFE_DOWNCAST(OcView, TOcRemView);
}

//
inline TOcApp* TOleWindow::GetOcApp() {
  return OcApp;
}

//
inline bool TOleWindow::SelectEmbedded() {
  return DragPart != 0;
}

//
inline bool TOleWindow::IsRemote() const {
  return Remote;
}

//
inline bool TOleWindow::PaintSelection(TDC& dc, bool erase,
                                       TRect& rect, void* userData) {
  return false;
}

//
inline bool TOleWindow::PaintLink(TDC& dc, bool erase,
                                  TRect& rect, TString& moniker) {
  return false;
}

//
inline bool TOleWindow::EvOcPartInvalid(TOcPart far& /*part*/) {
  return false;
}

// on linking must be implemented and return the file name
inline const char far* TOleWindow::GetFileName() {
  return NULL;
}

#endif
