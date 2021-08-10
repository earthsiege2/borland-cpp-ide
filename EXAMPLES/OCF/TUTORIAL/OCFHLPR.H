// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// ---------------------------------------------------------------------------
#if !defined(OCFHLPR_H)
#define OCFHLPR_H

#if !defined(OCF_OCREMVIE_H)
# include <ocf/ocremvie.h>
#endif

#include <commdlg.h>

//
// Forward ref.
//
class TOleWin;


//
// Prototypes of Accessors
//
TOcApp*   GetOcApp();


//
// Encapsulates a clientDC configured for OLE operations
//
class OleClientDC {
  public:
    OleClientDC(TOleWin&, bool scale = true);
   ~OleClientDC();

    //
    // HDC conversion operator for convenience
    //
    operator        HDC () const;

  protected:
    HDC             Hdc;          //  Actual Handle to Device Context
    HWND            HWnd;         //  Handle of Window whose DC was retrieved
};


//
// Class encapsulating menu description for menu merging purposes
//
class MenuDescr : public TOcMenuDescr {
  public:
    MenuDescr(HMENU,
              int fileGrp = 0, int editGrp = 0,
              int contGrp = 0, int objGrp = 0,
              int winGrp  = 0, int hlpGrp = 0);
    //
    // HMENU conversion operator for easy handling
    //
    operator HMENU() const { return HMenu; }

  private:
    MenuDescr(const TOcMenuDescr&);
};


//
// Object which initializes OLE and creates the basic OCF Helper objects
// required by any application supporting Linking and Embedding
//
class TOleInitEx : public TOleInit {
  public:
    TOleInitEx(TRegList& regInfo,
               TComponentFactory callback,
               string& cmdLine, TRegLink* linkHead = 0,
               HINSTANCE hInst = ::_hInstance);
   ~TOleInitEx();

  protected:
    TOcRegistrar*   OcRegistrar;
    TOcApp*&        OcApp;
};


//
// Handles OCF messages/events for an OLE Frame Window
//
class TOleFrameWin {
  public:
    TOleFrameWin(HWND);

    void            OnCreate();
    void            OnDestroy();
    void            OnActivateApp(bool);
    operator        HWND() const {return Hwnd; };
  protected:
    HWND            Hwnd;
};


//
// Object which handles OCF messages/events for an OLE Window and
// provide various default behaviour.
//
class TOleWin : public TOcMenuDescr {
  public:
    TOleWin(HWND hwnd);

    operator        HWND() const {return Hwnd; };
    void            SetWinMenu(const TOcMenuDescr& menuDescr);
    HMENU           GetWinMenu() const {return HMenu; };
    HMENU           GetMergedMenu() const {return MergedMenu; };

    //
    // Windows message handlers
    //
    void            OnCreate();
    void            OnDestroy();
    void            OnSize();
    void            OnPaint(HDC hdc, PAINTSTRUCT& ps);

    bool            OnCommand(UINT);
    void            OnInitMenuPopup(HMENU hMenu, int item);
    void            OnInitMenu(HMENU hMenu);

    bool            OnLButtonDown(int x, int y, UINT keyFlags);
    bool            OnLButtonDblClk(int x, int y, UINT keyFlags);
    bool            OnRButtonDown(int x, int y, UINT keyFlags);

    void            OnActivate(bool);
    void            OnSetFocus(HWND lostFocus);

    //
    // OCF event handlers
    //
    const char far* OnOcViewTitle();
    void            OnOcViewSetTitle(const char far*);
    bool            OnOcViewSetSiteRect(TRect far*);
    bool            OnOcViewGetScale(TOcScaleFactor far*);
    bool            OnOcViewPartInvalid(TOcPartChangeInfo far*);
    bool            OnOcViewGetSiteRect(TRect far*);
    bool            OnOcViewDrop(TOcDragDrop far*);
    LRESULT         OnOcEvent(WPARAM wParam, LPARAM lParam);

    //
    // The following events are actually sent to the frame
    // However, the latter can delegate to the OLE Window
    //
    bool            OnOcAppInsMenus(TOcMenuDescr far* sharedMenu);
    HMENU           OnOcAppMenus(TOcMenuDescr far* menuDescr);
    HMENU           OnOcAppRestoreUI();

    //
    // OLE UI Dialog methods
    //
    void            EditInsertObject();
    void            EditPasteSpecial();
    void            EditConvert();
    void            EditLinks();

    //
    // OCF Helper functions
    //
    bool            Deactivate();
    void            SetSelection(TOcPart*);
    void            GetInsertPosition(TRect& rect);
    void            InvalidatePart(TOcInvalidate invalid);
    bool            PaintParts(HDC dc, bool erase, TRect& rect, bool metafile);
    void            GetLogPerUnit(TSize&);
    void            SetupDC(HDC dc, bool scale = true);

    //
    // Accessors
    //
    TOcDocument*    GetOcDoc() {return OcDoc;}
    TOcView*        GetOcView() {return OcView;}
    TOcRemView*     GetOcRemView() {return TYPESAFE_DOWNCAST(OcView, TOcRemView);}
    bool            IsEmbedded() {return Embedded; }
    bool            SelectEmbedded();

    //
    // extra user info
    //
    void*           GetUserInfo()         {return UserInfo;}
    void*           SetUserInfo(void* ui);

  protected:
    HWND            Hwnd;
    TOcDocument*    OcDoc;
    TOcView*        OcView;
    TOcScaleFactor  Scale;
    TOcPart*        DragPart;
    bool            Embedded;
    TRect           Pos;
    bool            ShowObjects;
    HMENU           MergedMenu;
    void*           UserInfo;
};


inline
OleClientDC::OleClientDC(TOleWin& win, bool scale)
            :HWnd(win), Hdc(GetDC(win))
{
  win.SetupDC(*this, scale);
}


inline
OleClientDC::operator HDC() const
{
  return Hdc;
}


inline
OleClientDC::~OleClientDC()
{
  ReleaseDC(HWnd, Hdc);
}


//
//
//
inline
MenuDescr::MenuDescr(HMENU menu, int fileGrp, int editGrp,
                     int contGrp, int objGrp,
                     int winGrp, int hlpGrp)
{
  HMenu = menu;
  Width[0] = fileGrp;
  Width[1] = editGrp;
  Width[2] = contGrp;
  Width[3] = objGrp;
  Width[4] = winGrp;
  Width[5] = hlpGrp;
}


bool MergeContainerMenu(TOcMenuDescr& dst, const TOcMenuDescr& src);
bool MergeServerMenu(TOcMenuDescr& dst, const TOcMenuDescr& src);


// -------------------------------------------------------------------------
// Wrappers for common Windows routines
// -------------------------------------------------------------------------
bool GetOpenFileName(HWND owner, const char* filter, char* fileName,
                     int size, DWORD flags = OFN_OVERWRITEPROMPT);
bool GetSaveFileName(HWND owner, const char* filter, char* fileName,
                     int size, DWORD flags = OFN_OVERWRITEPROMPT);



// -------------------------------------------------------------------------
// Macros/templates to simplify OCF Event handling
// -------------------------------------------------------------------------

//
// Function template to send OCF events
//
template <class T> inline LRESULT
SendOCFEvent(HWND hwnd, int ocfCode, const T far* t = 0)
{
  return SendMessage(hwnd, WM_OCEVENT, ocfCode, LPARAM(t));
}


// -------------------------------------------------------------------------
//  Frame Events
// -------------------------------------------------------------------------

//
// LRESULT MainWnd_OnOcEvent(HWND hwnd, WPARAM wParam, LPARAM lParam)
//
#define HANDLE_WM_OCEVENT(hwnd, wParam, lParam, fn)\
  (LRESULT)(fn)((hwnd), (wParam), (lParam))

//
// macros for WM_OCEVENT subdispatching
//
#define HANDLE_OCF(hwnd, message, fn) \
  case (message): return (LRESULT)HANDLE_##message((hwnd), (lParam), (fn))

//
// bool Cls_OnOcAppInsMenus(HWND hwnd, TOcMenuDescr far* menuDescr)
//
#define HANDLE_OC_APPINSMENUS(hwnd, lParam, fn) \
    (LRESULT)(UINT)(bool)(fn)((hwnd), (TOcMenuDescr far*)(lParam))

//
// bool Cls_OnOcAppMenus(HWND hwnd, TOcMenuDescr far* menuDescr)
//
#define HANDLE_OC_APPMENUS(hwnd, lParam, fn) \
    (LRESULT)(UINT)(bool)(fn)((hwnd), (TOcMenuDescr far*)(lParam))

//
// bool Cls_OnOcAppProcessMsg(HWND hwnd, MSG far* msg)
//
#define HANDLE_OC_APPPROCESSMSG(hwnd, lParam, fn) \
    (LRESULT)(UINT)(fn)((hwnd), (MSG far*)(lParam))

//
// bool Cls_OnOcAppFrameRect(HWND hwnd, TRect far* rect)
//
#define HANDLE_OC_APPFRAMERECT(hwnd, lParam, fn) \
    (LRESULT)(UINT)(fn)((hwnd), (TRect far*)(lParam))

//
// bool Cls_OnOcAppBorderSpaceReq(HWND hwnd, TRect far* rect)
//
#define HANDLE_OC_APPBORDERSPACEREQ(hwnd, lParam, fn) \
    (LRESULT)(UINT)(fn)((hwnd), (TRect far*)(lParam))

//
// bool Cls_OnOcAppBorderSpaceSet(HWND hwnd, TRect far* rect)
//
#define HANDLE_OC_APPBORDERSPACESET(hwnd, lParam, fn) \
    (LRESULT)(UINT)(fn)((hwnd), (TRect far*)(lParam))

//
// void Cls_OnOcAppStatusText(HWND hwnd, const char far* text)
//
#define HANDLE_OC_APPSTATUSTEXT(hwnd, lParam, fn) \
    ((fn)((hwnd), (const char far*)(lParam)), 0L)

//
// void Cls_OnOcAppRestoreUI(HWND hwnd)
//
#define HANDLE_OC_APPRESTOREUI(hwnd, lParam, fn) \
    ((fn)((hwnd)), 0L)

//
// void Cls_OnOcAppDialogHelp(HWND hwnd, TOcDialogHelp far* dialogHelp)
//
#define HANDLE_OC_APPDIALOGHELP(hwnd, lParam, fn) \
    ((fn)((hwnd), (TOcDialogHelp far*)(lParam)), 0L)

//
// TOcView far* Cls_OnOcAppCreateComp(HWND hwnd, TDocTemplate far* docTemplate)
//
#define HANDLE_OC_APPCREATECOMP(hwnd, lParam, fn) \
    (LRESULT)(fn)((hwnd), (TDocTemplate far*)(lParam))

//
// bool Cls_OnOcAppShutDown(HWND hwnd)
//
#define HANDLE_OC_APPSHUTDOWN(hwnd, lParam, fn) \
    (LRESULT)(UINT)(fn)((hwnd))


// -------------------------------------------------------------------------
// View events
// -------------------------------------------------------------------------

//
// const char far* Cls_OnOcViewTitle(HWND hwnd)
//
#define HANDLE_OC_VIEWTITLE(hwnd, lParam, fn) \
    (LRESULT)(fn)((hwnd))

//
// void Cls_OnOcViewSetTitle(HWND hwnd, const char far* title)
//
#define HANDLE_OC_VIEWSETTITLE(hwnd, lParam, fn) \
  ((fn)((hwnd), (const char far*)(lParam)), 0)

//
// bool Cls_OnOcViewBorderSpaceReq(HWND hwnd, TRect far* rect)
//
#define HANDLE_OC_VIEWBORDERSPACEREQ(hwnd, lParam, fn) \
    (LRESULT)(UINT)(fn)((hwnd), (TRECT far*)(lParam))

//
// bool Cls_OnOcViewBorderSpaceSet(HWND hwnd, TRect far* rect)
//
#define HANDLE_OC_VIEWBORDERSPACESET(hwnd, lParam, fn) \
    (LRESULT)(UINT)(fn)((hwnd), (TRECT far*)(lParam))

//
// bool Cls_OnOcViewDrop(HWND hwnd, TOcDragDrop far* dragDropInfo)
//
#define HANDLE_OC_VIEWDROP(hwnd, lParam, fn) \
    (LRESULT)(fn)((hwnd), (TOcDragDrop far*)(lParam))

//
// bool Cls_OnOcViewDrag(HWND hwnd, TOcDragDrop far* dragDropInfo)
//
#define HANDLE_OC_VIEWDRAG(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcDragDrop far*)(lParam))

//
// bool Cls_OnOcViewScroll(HWND hwnd, TOcScrollDir far* scrollDir)
//
#define HANDLE_OC_VIEWSCROLL(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcScrollDir far*)(lParam))

//
// bool Cls_OnOcViewPartInvalid(HWND hwnd, TOcPartChangeInfo far* part)
//
#define HANDLE_OC_VIEWPARTINVALID(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcPartChangeInfo far*)(lParam))

//
// bool Cls_OnOcViewPaint(HWND hwnd, TOcViewPaint far* paintInfo)
//
#define HANDLE_OC_VIEWPAINT(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcViewPaint far*)(lParam))

//
// bool Cls_OnOcViewLoadPart(HWND hwnd, TOcSaveLoad far* loadInfo)
//
#define HANDLE_OC_VIEWLOADPART(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcSaveLoad far*)(lParam))

//
// bool Cls_OnOcViewSavePart(HWND hwnd, TOcSaveLoad far* saveInfo)
//
#define HANDLE_OC_VIEWSAVEPART(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcSaveLoad far*)(lParam))

//
// bool Cls_OnOcViewClose(HWND hwnd)
//
#define HANDLE_OC_VIEWCLOSE(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd))

//
// bool Cls_OnOcViewInsMenus(HWND hwnd, TOcMenuDescr far* menuDescr)
//
#define HANDLE_OC_VIEWINSMENUS(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcMenuDescr far*)(lParam))

//
// bool Cls_OnOcViewShowTools(HWND hwnd, TOcToolBar far* toolBarInfo)
//
#define HANDLE_OC_VIEWWSHOWTOOLS(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcToolBar far*)(lParam))

//
// bool Cls_OnOcViewGetPalette(HWND hwnd, LOGPALETTE far* far* paletteInfo)
//
#define HANDLE_OC_VIEWGETPALETTE(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (LOGPALETTE far* far*)(lParam))

//
// HANDLE Cls_OnOcViewClipData(HWND hwnd, TOcFormat far* formatInfo)
//
#define HANDLE_OC_VIEWCLIPDATA(hwnd, lParam, fn) \
  (LRESULT)(fn)((hwnd), (TOcFormat far*)(lParam))

//
// bool Cls_OnOcViewPartSize(HWND hwnd, TRect far* rect)
//
#define HANDLE_OC_VIEWPARTSIZE(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TRECT far*)(lParam))

//
// bool Cls_OnOcViewOpenDoc(HWND hwnd, const char far* text)
//
#define HANDLE_OC_VIEWOPENDOC(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (const char far*)(lParam))

//
// bool Cls_OnOcViewAttachWindow(HWND hwnd)
//
#define HANDLE_OC_VIEWATTACHWINDOW(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd))

//
// bool Cls_OnOcViewSetScale(HWND hwnd, TOcScaleFactor* scaleInfo)
//
#define HANDLE_OC_VIEWSETSCALE(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcScaleFactor*)(lParam))

//
// bool Cls_OnOcViewGetScale(HWND hwnd, TOcScaleFactor* scaleInfo)
//
#define HANDLE_OC_VIEWGETSCALE(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TOcScaleFactor*)(lParam))

//
// bool Cls_OnOcViewGetSiteRect(HWND hwnd, TRect far* rect)
//
#define HANDLE_OC_VIEWGETSITERECT(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TRect far*)(lParam))

//
// bool Cls_OnOcViewSetSiteRect(HWND hwnd, TRect far* rect)
//
#define HANDLE_OC_VIEWSETSITERECT(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TRect far*)(lParam))

//
// bool Cls_OnOcViewGetItemName(HWND hwnd, TOcItemName far* ocItemName)
//
#define HANDLE_OC_VIEWGETITEMNAME(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TRect far*)(lParam))

//
// bool Cls_OnOcViewSetLink(HWND hwnd, TOcLinkView far* ocLinkView)
//
#define HANDLE_OC_VIEWSETLINK(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TRect far*)(lParam))

//
// bool Cls_OnOcViewBreakLink(HWND hwnd, TOcLinkView far* ocLinkView)
//
#define HANDLE_OC_VIEWBREAKLINK(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TRect far*)(lParam))

//
// bool Cls_OnOcViewPartActivate(HWND hwnd, TOcPart far* ocPart)
//
#define HANDLE_OC_VIEWPARTACTIVATE(hwnd, lParam, fn) \
  (LRESULT)(UINT)(fn)((hwnd), (TRect far*)(lParam))

#endif  //  OCFHLPR_H
