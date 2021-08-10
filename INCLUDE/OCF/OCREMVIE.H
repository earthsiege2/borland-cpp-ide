//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// Definition of TOcRemView Class
//----------------------------------------------------------------------------
#if !defined(OCF_OCREMVIE_H)
#define OCF_OCREMVIE_H

#if !defined(OCF_OCVIEW_H)
# include <ocf/ocview.h>
#endif

//
// class TOcRemView
// ~~~~~ ~~~~~~~~~~
// Remote Viewer object for a server document
//
class _ICLASS TOcRemView : public TOcView, public IBPart2 {
  public:
    TOcRemView(TOcDocument& doc, TOcContainerHost* cs, TOcServerHost* ss,
               TRegList* regList=0, IUnknown* outer=0);

    // Compatibility
    TOcRemView(TOcDocument& doc, TRegList* regList = 0, IUnknown* outer = 0);

    virtual void   ReleaseObject();

    // IBSite pass-thrus
    //
    void    Invalidate(TOcInvalidate);
    void    Disconnect();
    virtual bool EvSetFocus(bool set);

    // IBDocument pass-thrus
    //
    void   EvClose();
    void   Rename();
    TString GetContainerTitle();
    void   GetInitialRect(bool selection = false);
    bool   Save(IStorage* storageI);
    bool   Load(IStorage* storageI);

    // IBApplication pass-thrus
    //
    bool   SetContainerStatusText(const char far* text);

    // Server State and Kind accessors, etc.
    //
    enum TState {                  // Current state of this server view
      Hidden,                        //  Hidden & ready to go
      Closing,                       //  Shutting down
      OpenEditing,                   //  Open editing
      InPlaceActive,                 //  Inplace active
    };
    enum TKind {                   // What kind of server view this is
      DontKnow,                      //  Don't know yet, wait for Init()
      Embedding,                     //  Normal Embedding
      LoadFromFile,                  //  Transient load-from-file
      Link,                          //  Load-from-file is really a link
    };
    TState  GetState() const {return State;}
    TKind   GetKind() const {return Kind;}

    // Used by TOcLinkView to let us know our state was changed
    //
    void    SetOpenEditing() {State = OpenEditing;}

    // Object reference & lifetime managment
    //
    ulong   _IFUNC AddRef();
    ulong   _IFUNC Release();
    HRESULT _IFUNC QueryInterface(const GUID far& iid, void far*far* iface);

  protected:
    // IBContains forwarding to base
    //
    HRESULT _IFUNC Init(LPCOLESTR path);
    HRESULT _IFUNC GetPart(IBPart far* far*, LPCOLESTR);

    // IBContainer implementation for Bolero to use
    //
    HRESULT  _IFUNC BringToFront();

    // TUnknown virtual overrides
    //
    HRESULT      QueryObject(const IID far& iid, void far* far* iface);

    // IBContainer forwarding to base
    //
    void    _IFUNC DragFeedback(TPoint far* p, const TRect far* r,
                                TOcMouseAction a, uint cf, HRESULT& hr);

    HRESULT _IFUNC AllowInPlace();

    // IBDataNegotiator implementation to eliminate ambiguity
    //
    uint     _IFUNC CountFormats();
    HRESULT  _IFUNC GetFormat(uint index, TOcFormatInfo far* fmt);

    // IBDataProvider2 implementation
    //
    HANDLE  _IFUNC  GetFormatData(TOcFormatInfo far*);
    HRESULT _IFUNC  SetFormatData(TOcFormatInfo far* fmt, HANDLE data, BOOL release);
    HRESULT _IFUNC  Draw(HDC, const RECTL far*, const RECTL far*, TOcAspect, TOcDraw bd);
    HRESULT _IFUNC  GetPartSize(TSize far*);
    HRESULT _IFUNC  Save(IStorage*, BOOL sameAsLoad, BOOL remember);

    // IBPart(2) implementation
    //
    HRESULT _IFUNC  Init(IBSite far*, TOcInitInfo far*);
    HRESULT _IFUNC  Close();
    HRESULT _IFUNC  CanOpenInPlace();
    HRESULT _IFUNC  SetPartSize(TSize far*);
    HRESULT _IFUNC  SetPartPos(TRect far*);
    HRESULT _IFUNC  Activate(BOOL);
    HRESULT _IFUNC  Show(BOOL);
    HRESULT _IFUNC  Open(BOOL);
    HRESULT _IFUNC  EnumVerbs(TOcVerb far*);
    HRESULT _IFUNC  DoVerb(uint);
    HWND    _IFUNC  OpenInPlace(HWND);
    HRESULT _IFUNC  InsertMenus(HMENU, TOcMenuWidths far*);
    HRESULT _IFUNC  ShowTools(BOOL);
    void    _IFUNC  FrameResized(const TRect far*, BOOL);
    HRESULT _IFUNC  DragFeedback(TPoint far*, BOOL);
    HRESULT _IFUNC  GetPalette(LOGPALETTE far* far*);
    HRESULT _IFUNC  SetHost(IBContainer far* objContainer);
    HRESULT _IFUNC  DoQueryInterface(const IID far& iid, void far* far* pif);
    LPOLESTR _IFUNC GetName(TOcPartName);

  protected:
    void            Init();          // Constructor helper
                   ~TOcRemView();

    IBContainer*    BContainerI;     //
    IBLinkable*     BLSiteI;         // for site moniker
    IUnknown*       BSite;           // In-place site helper
    IBSite*         BSiteI;          // Site interface
    IBApplication*  BAppI;           // Site's application interface
    HWND            HRealParent;     // View's real parent
    TOcToolBarInfo  ToolBarInfo;     // Inplace tool bar info

    TState          State;           // Current state of this server view
    TKind           Kind;            // What kind of server view this is
};

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline bool TOcRemView::SetContainerStatusText(const char far* text)
{
  return HRIsOK(BAppI->SetStatusText(OleStr(text)));
}

#endif  // OCF_OCREMVIE_H
