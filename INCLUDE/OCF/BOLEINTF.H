// $Header:   N:\admin\ocf\include\ocf\boleintf.h_v   2.0.1.0   10 Apr 1995 18:04:52   CQUINN  $
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   ObjectComponents BOcOle engine linking & embedding interfaces
//----------------------------------------------------------------------------
#if !defined(OCF_BOLEINTF_H)
#define OCF_BOLEINTF_H

#if !defined(OCF_OCOBJECT_H)
# include <ocf/ocobject.h>    // get ocf structs & enums
#endif
#if !defined(OSL_GEOMETRY_H)
# include <osl/geometry.h>    // TPoint, TSize & TRect
#endif
#if defined(WIN32)
# include "pshpack8.h"
#endif

//
// BOcOle DLL name, entry point and version resource
//
#if defined(BI_PLAT_WIN32)
# define BOLEDLL "BOCOF.DLL"
# define BOLEDLLW "BOCOFW.DLL"
#else
# define BOLEDLL "BOCOLE.DLL"
# define BOLEDLLW BOLEDLL
#endif
#define BOLEBIND "CreateClassMgr"
#define BOLE_FILEVER_LS 0x00010053L
#define BOLE_FILEVER_MS 0x00010000L

//
// GUIDs exported by the BOcOle DLL
//
#if defined(INIT_BGUID)
# define DEFINE_BOLEGUID(name, l) \
         EXTERN_C __export const GUID CDECL FAR name = \
         { l, 0, 0, {0xC0,0,0,0,0,0,0,0x46} }
#else
# define DEFINE_BOLEGUID(name, l) EXTERN_C const GUID CDECL FAR name
#endif

DEFINE_BOLEGUID(IID_IBPart,          0x02A104L);
DEFINE_BOLEGUID(IID_IBSite,          0x02A105L);
DEFINE_BOLEGUID(IID_IBContainer,     0x02A106L);
DEFINE_BOLEGUID(IID_IBDocument,      0x02A107L);
DEFINE_BOLEGUID(IID_IBService,       0x02A108L);
DEFINE_BOLEGUID(IID_IBApplication,   0x02A109L);
DEFINE_BOLEGUID(IID_IBClassMgr,      0x02A10AL);
DEFINE_BOLEGUID(IID_IBLinkInfo,      0x02A10BL);
DEFINE_BOLEGUID(IID_IBLinkable,      0x02A10CL);
DEFINE_BOLEGUID(IID_IBRootLinkable,  0x02A10DL);
DEFINE_BOLEGUID(IID_IBContains,      0x02A10EL);
DEFINE_BOLEGUID(IID_BOleDocument,    0x02A10FL);
DEFINE_BOLEGUID(IID_BOlePart,        0x02A110L);
DEFINE_BOLEGUID(IID_IBDataConsumer,  0x02A111L);
DEFINE_BOLEGUID(IID_IBDataProvider,  0x02A112L);
DEFINE_BOLEGUID(IID_IBWindow,        0x02A113L);
DEFINE_BOLEGUID(IID_IBDataNegotiator,0x02A114L);
DEFINE_BOLEGUID(IID_IBDropDest,      0x02A115L);
DEFINE_BOLEGUID(IID_BOleShadowData,  0x02A116L);
DEFINE_BOLEGUID(IID_IBClass,         0x02A117L);
DEFINE_BOLEGUID(IID_IBOverrideBrowseLinks, 0x02A118L);
DEFINE_BOLEGUID(IID_BOleSite,        0x02A119L);
DEFINE_BOLEGUID(IID_IBSite2,         0x02A11AL);
DEFINE_BOLEGUID(IID_IBOverrideHelpButton,  0x02A11BL);
DEFINE_BOLEGUID(IID_IBDataProvider2,  0x02A11CL);
DEFINE_BOLEGUID(IID_IBPart2,          0x02A11DL);
//DEFINE_BOLEGUID(IID_BOlePart2,        0x02A11EL);

//
// BOle Class ids for instantiating BOle objects (helpers)
//
typedef uint32 BCID;
const BCID  cidBOleService      = 1L;   //
const BCID  cidBOleDocument     = 2L;   // helper for containers
const BCID  cidBOlePart         = 3L;   // helper for sites
const BCID  cidBOleSite         = 4L;   // helper for parts
const BCID  cidBOleInProcSite   = 5L;   // helper for parts
const BCID  cidBOleContainer    = 6L;   // helper for part documents
const BCID  cidBOleData         = 7L;   // helper for data transfer
const BCID  cidBOleFactory      = 8L;   // helper for class factory
const BCID  cidBOleShadowData   = 9L;   // helper for non delayed rendering
const BCID  cidBOleInProcHandler= 10L;  // helper for dll handler parts

//
// Forward declarations
//
class _ICLASS IBClassMgr;
class _ICLASS IBPart;
class _ICLASS IBService;
class _ICLASS IBLinkable;
class _ICLASS IBRootLinkable;
class _ICLASS IBContains;
class _ICLASS IBDocument;
class _ICLASS IBContainer;
class _ICLASS IBSite;
class _ICLASS IBApplication;
class _ICLASS IBLinkInfo;
class _ICLASS IBDataNegotiator;
class _ICLASS IBDataProvider;
class _ICLASS IBDataConsumer;
class _ICLASS IBWindow;
class _ICLASS IBDropDest;
class _ICLASS IBClass;
class _ICLASS IBOverrideBrowseLinks;
class _ICLASS IBSite2;
class _ICLASS IBOverrideHelpButton;
class _ICLASS IBPart2;
class _ICLASS IBDataProvider2;


//
// IClassMgr abstract base class
//
class _ICLASS IBClassMgr : public IUnknown {
  public:
   virtual HRESULT _IFUNC ComponentCreate(
      IUnknown far* far* ppRet,
      IUnknown far* pAggregator,
      BCID     idClass
     )  = 0;
   virtual HRESULT _IFUNC ComponentInfoGet(
      IUnknown far* far* ppInfo,
      IUnknown far* pAggregator,
      BCID     idClass
     )  = 0;
};

//
// IBDataNegotiator -- Enumerats formats for drag/drop and paste
//
class _ICLASS IBDataNegotiator : public IUnknown {
  public:
    virtual uint     _IFUNC CountFormats()                      = 0;
    virtual HRESULT  _IFUNC GetFormat(uint, TOcFormatInfo far*) = 0;
};

//
// IBDataConsumer -- Supported by containers who want to accept drag/drop
//                   and paste. No new methods over the negotiator, so
//                   this is just a placeholder for the consumer name.
//
class _ICLASS IBDataConsumer : public IBDataNegotiator {
};

//
// IBDataProvider -- Supported by parts and/or sites which can be
//                   copied to the OLE2 clipboard
//
class _ICLASS IBDataProvider : public IBDataNegotiator {
  public:
    virtual HANDLE  _IFUNC GetFormatData(TOcFormatInfo far*)       = 0;
    virtual HRESULT _IFUNC Draw(HDC, const RECTL far*,
                                const RECTL far*, TOcAspect,
                                TOcDraw bd = drNone)               = 0;
    virtual HRESULT _IFUNC GetPartSize(TSize far*)                 = 0;
    virtual HRESULT _IFUNC Save(IStorage far*, bool fSamAsLoad,
                                bool fRemember)                    = 0;
};


// IBDataProvider2 -- new version of IBDataProvider
//
class _ICLASS IBDataProvider2 : public IBDataProvider {
  public:

    virtual HRESULT _IFUNC SetFormatData(TOcFormatInfo far* fmt, HANDLE data, BOOL release) = 0;
};


//
// IBPart -- Supported by server objects
//
class _ICLASS IBPart : public IBDataProvider {
  public:
    virtual HRESULT _IFUNC Init(IBSite far*, TOcInitInfo far*)     = 0;
    virtual HRESULT _IFUNC Close()                                 = 0;
    virtual HRESULT _IFUNC CanOpenInPlace()                        = 0;
    virtual HRESULT _IFUNC SetPartSize(TSize far*)                 = 0;
    virtual HRESULT _IFUNC SetPartPos(TRect far*)                  = 0;
    virtual HRESULT _IFUNC Activate(bool)                          = 0;
    virtual HRESULT _IFUNC Show(bool)                              = 0;
    virtual HRESULT _IFUNC Open(bool)                              = 0;
    virtual HRESULT _IFUNC EnumVerbs(TOcVerb far*)                 = 0;
    virtual HRESULT _IFUNC DoVerb(uint)                            = 0;
    virtual HWND    _IFUNC OpenInPlace(HWND)                       = 0;
    virtual HRESULT _IFUNC InsertMenus(HMENU, TOcMenuWidths far*)  = 0;
    virtual HRESULT _IFUNC ShowTools(bool)                         = 0;
    virtual void    _IFUNC FrameResized(const TRect far*, bool)    = 0;
    virtual HRESULT _IFUNC DragFeedback(TPoint far*, bool)         = 0;
    virtual HRESULT _IFUNC GetPalette(LOGPALETTE far* far*)        = 0;
    virtual HRESULT _IFUNC SetHost(IBContainer far* pObjContainer) = 0;
    virtual HRESULT _IFUNC DoQueryInterface(const IID far& iid, void far* far* pif)= 0;

    virtual LPOLESTR _IFUNC GetName(TOcPartName)                   = 0;
};


// IBPart2 -- Supported by server objects
//
class _ICLASS IBPart2 : public IBPart,
                        public IBDataProvider2 {
};


//
// IService abstract base class
//
class _ICLASS IBService : public IUnknown {
  public:
    virtual void     _IFUNC OnResize()                           = 0;
    virtual void     _IFUNC OnActivate(bool)                     = 0;
    virtual HRESULT  _IFUNC OnModalDialog(bool)                  = 0;
    virtual HRESULT  _IFUNC OnSetFocus(bool)                     = 0;

    virtual HRESULT  _IFUNC Init(IBApplication far*)             = 0;
    virtual HRESULT  _IFUNC RegisterClass(LPCOLESTR, IBClassMgr far*,
                                          BCID, bool embedInSelf,
                                          bool singleUse) = 0;
    virtual HRESULT  _IFUNC UnregisterClass(LPCOLESTR)           = 0;
    virtual HRESULT  _IFUNC TranslateAccel(MSG far*)             = 0;
    virtual TOcHelp  _IFUNC HelpMode(TOcHelp)                    = 0;
    virtual HRESULT  _IFUNC CanClose()                           = 0;

    virtual HRESULT  _IFUNC BrowseClipboard(TOcInitInfo far*)    = 0;
    virtual HRESULT  _IFUNC Browse(TOcInitInfo far*)             = 0;

    virtual HRESULT  _IFUNC Paste(TOcInitInfo far*)              = 0;
    virtual HRESULT  _IFUNC Clip(IBDataProvider far*, bool, bool,
                                 bool)                           = 0;
    virtual HRESULT  _IFUNC Drag(IBDataProvider far*, TOcDropAction,
                                 TOcDropAction far*)             = 0;
    virtual IStorage FAR* _IFUNC CreateStorageOnFile(LPCOLESTR,
                                                     bool)       = 0;
    virtual HRESULT _IFUNC ConvertUI(IBPart far*, bool,
                                     TOcConvertInfo far*)        = 0;
    virtual HRESULT _IFUNC ConvertGuts(IBPart far*, bool,
                                       TOcConvertInfo far*)      = 0;
    virtual TOcMenuEnable _IFUNC EnableEditMenu(TOcMenuEnable,
                                                IBDataConsumer far*)= 0;
};

//
// ILinkable abstract base class
//
class _ICLASS IBLinkable : public IUnknown {
  public:
    virtual HRESULT _IFUNC GetMoniker(IMoniker far* far* ppMon)    = 0;
    virtual HRESULT _IFUNC OnRename(IBLinkable far* pContainer,
                                    LPCOLESTR name)                = 0;
                            // pass 0 name when Doc closes
                            // pass boledoc for pContainer if root part(file)
};

//
//
//
class _ICLASS IBRootLinkable : public IBLinkable {
  public:
   virtual HRESULT _IFUNC Init(IBContains far* pC, LPCOLESTR szProgId) = 0;
   virtual HRESULT _IFUNC SetMoniker(IMoniker far* pMon)               = 0;
};
//
// on BOleLinkDoc used by Part servers and Linking Containers
// on BOleSite    used by parts
//

//
// IContains abstract base class
//
class _ICLASS IBContains : public IUnknown {
  public:
    virtual HRESULT _IFUNC Init(LPCOLESTR)                               = 0;
    virtual HRESULT _IFUNC GetPart(IBPart far* far*, LPCOLESTR)          = 0;
};
//
// on linkable containers (all Containers with BOleLinkDoc helper)
// on linkable server documents (with BOleLinkDoc helper)
// on intermediate parts (in addition to IPart)
//

//
// IBDocument -- Supported by BOleDocument one per container child window
//
class _ICLASS IBDocument : public IUnknown {
  public:
    virtual HRESULT _IFUNC Init(IBContainer far*)                  = 0;
    virtual void    _IFUNC OnResize()                              = 0;
    virtual void    _IFUNC OnActivate(bool)                        = 0;
    virtual void    _IFUNC OnClose()                               = 0;
    virtual HRESULT _IFUNC OnSetFocus(bool)                        = 0;

    virtual HRESULT _IFUNC EnumLinks(IBLinkInfo far* far*)         = 0;
    virtual HRESULT _IFUNC BrowseLinks()                           = 0;
    virtual HRESULT _IFUNC UpdateLinks()                           = 0;
};

//
// IBWindow -- Supported on child window *and* frame window of container apps
//
class _ICLASS IBWindow : public IUnknown {
  public:
    virtual HWND     _IFUNC GetWindow()                               = 0;
    virtual HRESULT  _IFUNC GetWindowRect(TRect far*)                 = 0;
    virtual LPCOLESTR _IFUNC GetWindowTitle()                         = 0;
    virtual void     _IFUNC AppendWindowTitle(LPCOLESTR)              = 0;
    virtual HRESULT  _IFUNC SetStatusText(LPCOLESTR)                  = 0;

    virtual HRESULT  _IFUNC RequestBorderSpace(const TRect far*)      = 0;
    virtual HRESULT  _IFUNC SetBorderSpace(const TRect far*)          = 0;

    virtual HRESULT  _IFUNC InsertContainerMenus(HMENU,
                                                 TOcMenuWidths far*)  = 0;
    virtual HRESULT  _IFUNC SetFrameMenu(HMENU)                       = 0;
    virtual void     _IFUNC RestoreUI()                               = 0;
    virtual HRESULT  _IFUNC Accelerator(MSG far*)                     = 0;
    virtual HRESULT  _IFUNC GetAccelerators(HACCEL far*, int far*)    = 0;
};

//
// IBContainer -- Supported by container app's document window
//
class _ICLASS IBContainer : public IBWindow {
  public:
    virtual HRESULT  _IFUNC FindDropDest(TPoint far*, IBDropDest far* far*)=0;
    virtual HRESULT  _IFUNC AllowInPlace()                          = 0;
    virtual HRESULT  _IFUNC BringToFront()                          = 0;
};

//
// IBDropDest -- Supported by container app's document window and/or other
//               areas inside the window.
//
class _ICLASS IBDropDest : public IBDataConsumer {
  public:
    virtual HRESULT  _IFUNC Drop(TOcInitInfo far*, TPoint far*,
                                 const TRect far*)                    = 0;
    virtual void     _IFUNC DragFeedback(TPoint far*, const TRect far*,
                                         TOcMouseAction, uint, HRESULT&) = 0;
    virtual HRESULT  _IFUNC Scroll(TOcScrollDir scrollDir)            = 0;
    virtual HRESULT  _IFUNC GetScrollRect(TRect far*)                 = 0;
};

//
// IBApplication -- Supported at frame window/app object of container apps
//
class _ICLASS IBApplication : public IBWindow {
  public:
    virtual LPCOLESTR   _IFUNC GetAppName()                           = 0;
    virtual TOcHelp  _IFUNC HelpMode(TOcHelp)                         = 0;
    virtual HRESULT  _IFUNC CanLink()                                 = 0;
    virtual HRESULT  _IFUNC CanEmbed()                                = 0;
    virtual HRESULT  _IFUNC IsMDI()                                   = 0;
    virtual HRESULT  _IFUNC OnModalDialog(bool)                       = 0;
    virtual void     _IFUNC DialogHelpNotify(TOcDialogHelp)           = 0;
    virtual void     _IFUNC ShutdownMaybe()                           = 0;
};

//
// IBSite -- Supported by container apps for each linked/embedded object
//
class _ICLASS IBSite : public IUnknown {
  public:
    virtual HRESULT _IFUNC SiteShow(bool)                             = 0;
    virtual HRESULT _IFUNC DiscardUndo()                              = 0;
    virtual HRESULT _IFUNC GetSiteRect(TRect far*, TRect far*)        = 0;
    virtual HRESULT _IFUNC SetSiteRect(const TRect far*)              = 0;
    virtual HRESULT _IFUNC SetSiteExtent(const TSize far*)            = 0;
    virtual HRESULT _IFUNC GetZoom(TOcScaleInfo far* pScale)          = 0;
    virtual void    _IFUNC Invalidate(TOcInvalidate)                  = 0;
    virtual void    _IFUNC OnSetFocus(bool)                           = 0;
    virtual HRESULT _IFUNC Init(IBDataProvider far*, IBPart far*,
                                LPCOLESTR, bool)                      = 0;
    virtual void    _IFUNC Disconnect()                               = 0;
};

//
// IBLinkInfo -- Supported by BOleParts which are link objects
//
class _ICLASS IBLinkInfo : public IUnknown {
  public:
    virtual HRESULT _IFUNC SourceBreak()                              = 0;
    virtual HRESULT _IFUNC SourceGet(LPOLESTR, uint count)            = 0;
    virtual HRESULT _IFUNC SourceSet(LPOLESTR)                        = 0;
    virtual HRESULT _IFUNC SourceOpen()                               = 0;
    virtual HRESULT _IFUNC UpdateGet(TOcLinkUpdate far*)              = 0;
    virtual HRESULT _IFUNC UpdateSet(TOcLinkUpdate)                   = 0;
    virtual HRESULT _IFUNC UpdateNow()                                = 0;
};

//
// IBClass -- Supported by BOleFactory
//
class _ICLASS IBClass : public IClassFactory {
  public:
    virtual HRESULT _IFUNC Init(bool selfEmbed, LPCOLESTR pszProgId,
                                IBClassMgr* pCM, BCID rid)            = 0;
    virtual HRESULT _IFUNC Register(bool singleUse)                   = 0;
    virtual HRESULT _IFUNC Revoke()                                   = 0;
    virtual HRESULT _IFUNC GetClassID(CLSID far* pOut)                = 0;
    virtual bool _IFUNC IsA(CLSID far& pOut)                          = 0;
    virtual bool _IFUNC AllowEmbedFromSelf()                          = 0;
    virtual HRESULT _IFUNC GetEmbeddingHelperFactory(LPUNKNOWN *ppF)  = 0;
};

//
// IBOverrideBrowseLinks -- Supported by containers(who aggregate BOleDoc)
//                          who want to override our BrowseLinks dialog.
//
class _ICLASS IBOverrideBrowseLinks : public IUnknown {
  public:
    virtual HRESULT    _IFUNC BrowseLinks()                        = 0;
};

//----------------------------------------------------------------------------
// Will eliminate this inline QI in favor of TUnknown version next rev.
//
inline HRESULT _IFUNC IUnknown_QueryInterface(IUnknown FAR *, REFIID iid, LPVOID FAR * pif)
{
  // To avoid handing out different IUnknown pointers for
  // the same Windows Object don't match here.
  // Only match in the main IUnknown in the outermost aggregator.
  //
  return ResultFromScode(E_NOINTERFACE);
}

#define DEFINE_INLINE_QI(I, P) \
inline HRESULT _IFUNC I##_QueryInterface(I FAR* This, REFIID iid, LPVOID FAR* pif) \
{                                            \
  return (iid == IID_##I) ?                  \
    (*pif = This), This->AddRef(), HR_OK : \
    P##_QueryInterface(This, iid, pif);      \
}

#define DEFINE_INLINE_QI2(I, P1, P2) \
inline HRESULT _IFUNC I##_QueryInterface(I FAR* This, REFIID iid, LPVOID FAR* pif) \
{                                            \
  return (iid == IID_##I) ?                  \
    (*pif = This), ((P1*)This)->AddRef(), HR_OK : \
    SUCCEEDED(P1##_QueryInterface(This, iid, pif))? HR_OK :\
    P2##_QueryInterface(This, iid, pif);      \
}

DEFINE_INLINE_QI(IBDataNegotiator, IUnknown)
DEFINE_INLINE_QI(IBDataConsumer, IUnknown)
DEFINE_INLINE_QI(IBDropDest, IBDataConsumer)
DEFINE_INLINE_QI(IBDataProvider, IBDataNegotiator)
DEFINE_INLINE_QI(IBPart, IBDataProvider)

DEFINE_INLINE_QI(IBWindow, IUnknown)
DEFINE_INLINE_QI(IBContainer, IBWindow)
DEFINE_INLINE_QI(IBApplication, IBWindow)

DEFINE_INLINE_QI(IBDocument, IUnknown)
DEFINE_INLINE_QI(IBService, IUnknown)
DEFINE_INLINE_QI(IBClassMgr, IUnknown)
DEFINE_INLINE_QI(IBLinkInfo, IUnknown)
DEFINE_INLINE_QI(IBSite, IUnknown)
DEFINE_INLINE_QI(IBContains, IUnknown)

DEFINE_INLINE_QI(IBLinkable, IUnknown)
DEFINE_INLINE_QI(IBRootLinkable, IBLinkable)
DEFINE_INLINE_QI(IClassFactory, IUnknown)
DEFINE_INLINE_QI(IBClass, IClassFactory)

DEFINE_INLINE_QI(IBOverrideBrowseLinks, IUnknown)
DEFINE_INLINE_QI(IBDataProvider2, IBDataProvider)
DEFINE_INLINE_QI2(IBPart2, IBPart, IBDataProvider2)

//----------------------------------------------------------------------------

#if defined(WIN32)
# include "poppack.h"
#endif

#endif  // OCF_BOLEINTF_H
