//
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Definition of Compound Document TOcView Class
//----------------------------------------------------------------------------
#if !defined(OCF_OCVIEW_H)
#define OCF_OCVIEW_H

#if !defined(OCF_OCDOC_H)
# include <ocf/ocdoc.h>      // Client related
#endif

#if !defined(OCF_OCAPP_H)
# include <ocf/ocapp.h>      // Client related
#endif

// Classes referenced
//
class _ICLASS TOcStorage;
class _ICLASS TOcDataProvider;
class TRegList;

// View options flags, set with SetOption
//
enum TOcViewOptions {
  voNoInPlace        = 0x0001, // If FALSE, allow inplace activate in container
  voNoNestedInPlace  = 0x0002, // If FALSE, allow nested inplace activate " "
  voNoInPlaceServer  = 0x0004, // If FALSE, allow server to activate inplace
};

//
// Clipboard format wrapper
//
class TOcFormat {
  public:
    TOcFormat();
    TOcFormat(uint fmtId, char far* fmtName, char far* fmtResultName,
              uint fmtMedium, bool fmtIsLinkable,
              uint aspect = 1, uint direction = 1);

    void operator =(const TOcFormatInfo&);
    bool operator ==(const TOcFormat& other) {return ToBool(&other == this);}
    void SetFormatId(uint id) {Id = id;}
    void SetFormatName(char far* name, TOcApp& ocApp);
    void SetFormatName(uint id, TOcApp& ocApp);
    void SetMedium(uint medium) {Medium = (ocrMedium)medium;}
    void SetAspect(uint aspect) {Aspect = aspect;}
    void SetDirection(uint direction) {Direction = direction;}
    void SetLinkable(bool link = true) {IsLinkable = link;}
    void Disable(bool disable = true) {Disabled = disable;}

    uint GetFormatId() const {return Id;}
    char far* GetRegName() {return RegName;}
    char far* GetFormatName() {return Name;}
    uint GetMedium() const {return Medium;}
    uint GetAspect() const {return Aspect;}
    uint GetDirection() const {return Direction;}
    bool IsDisabled() const {return Disabled;}

    void GetFormatInfo(TOcFormatInfo far& f);

  private:
    uint      Id;
    char      RegName[32];
    char      Name[32];
    char      ResultName[32];
    ocrMedium Medium;
    bool      IsLinkable;

    uint Aspect;      // last three data members added & maintained by ocf
    uint Direction;
    bool Disabled;    // Format not available
};

//
// Container of clipboard formats with iterator
//
class TOcFormatList : private TICVectorImp<TOcFormat> {
  public:
    TOcFormatList();
   ~TOcFormatList();
    void operator delete(void* ptr) {TStandardAllocator::operator delete(ptr);}

    TOcFormat*&  operator [](unsigned index) {return Base::operator[](index);}
    void         Clear(int del = 1) {Base::Flush(del);}
    int          Add(TOcFormat* format) {return Base::Add(format);}
    int          IsEmpty() const {return Base::IsEmpty();}
    unsigned     Find(const TOcFormat* format) const {return Base::Find(format);}
    virtual uint Count() const {return Base::Count();}
    int          Detach(const TOcFormat* format, int del = 0)
                    {return Base::Detach(Find(format), del);}
    TOcFormat* Find(uint const id) const;

  private:
    typedef TICVectorImp<TOcFormat> Base;
    friend class TOcFormatListIter;
};

//
//
//
class TOcFormatListIter : public TICVectorIteratorImp<TOcFormat> {
  private:
    typedef TICVectorIteratorImp<TOcFormat> Base;
  public:
    TOcFormatListIter(const TOcFormatList& c) : Base(c) {}
    operator   int() const {return Base::operator int();}
    TOcFormat* Current() const {return Base::Current();}
    TOcFormat* operator ++(int) {return Base::operator ++(0);}
    TOcFormat* operator ++() {return Base::operator ++();}
    void       Restart() {Base::Restart();}
    void       Restart(unsigned start, unsigned stop) {Base::Restart(start, stop);}
};

//----------------------------------------------------------------------------

//
// class TOcView
// ----- -------
// The TOcView partner is a container (viewer) of a given (server/client)
// document.
//
class _ICLASS TOcView : public TUnknown,
                        public IBContainer,
                        public IBContains,
                        public IBDropDest {
  public:
    TOcView(TOcDocument& doc, TRegList* regList=0, IUnknown* outer=0);

    virtual void   ReleaseObject();

    TOcDocument& GetOcDocument() {return OcDocument;}

    // Helper functions
    //
    IBRootLinkable* GetLinkable() {return BLDocumentI;}

    // Clipboard support
    //
    bool         RegisterClipFormats(TRegList& regList);
    bool         BrowseClipboard(TOcInitInfo& initInfo);
    bool         PasteNative(TOcInitInfo& init, TPoint far* where = 0);
    bool         Paste(bool linking = false);
    void         SetOcData(TOcDataProvider* ocData = 0) {OcData = ocData;}
    TOcDataProvider* GetOcData() {return OcData;}

    // View related
    //
    void         SetupWindow(HWND hWin, bool embedded = false);
    TPoint       GetOrigin() const {return Origin;}
    TRect        GetWindowRect() const;
    void         ScrollWindow(int dx, int dy);
    void         InvalidatePart(TOcPartChangeInfo& changeInfo);
    virtual void Rename();
    TOcLinkView* GetDocLink();
    bool         IsOptionSet(uint32 option) const;
    void         SetOption(uint32 bit, bool state);

    // Get/Set active part
    //
    TOcPart*     GetActivePart() {return ActivePart;}
    void         SetActivePart(TOcPart* part) {ActivePart = part;} // Internal use
    bool         ActivatePart(TOcPart* part);

    // IBDocument pass-thrus
    //
    void         EvResize();
    void         EvActivate(bool activate);
    virtual void EvClose();
    virtual bool EvSetFocus(bool set);
    bool         EnumLinks(IBLinkInfo far* far*);
    bool         BrowseLinks();
    bool         UpdateLinks();

    // Object reference & lifetime managment
    // For internal OCF use only
    //
    ulong   _IFUNC AddRef() {return GetOuter()->AddRef();}
    ulong   _IFUNC Release() {return GetOuter()->Release();}
    HRESULT _IFUNC QueryInterface(const GUID far& iid, void far*far* iface)
                     {return GetOuter()->QueryInterface(iid, iface);}
  protected:
    // IBContains implementation for BOle to use
    //
    HRESULT _IFUNC Init(LPCOLESTR);
    HRESULT _IFUNC GetPart(IBPart far* far*, LPCOLESTR);

    // IBDataNegotiator implementation
    //
    uint     _IFUNC CountFormats();
    HRESULT  _IFUNC GetFormat(uint, TOcFormatInfo far*);

    // IBWindow implementation
    //
    HWND     _IFUNC GetWindow();
    HRESULT  _IFUNC GetWindowRect(TRect far* r);
    LPCOLESTR _IFUNC GetWindowTitle();
    void     _IFUNC AppendWindowTitle(LPCOLESTR title);
    HRESULT  _IFUNC SetStatusText(LPCOLESTR text);
    HRESULT  _IFUNC RequestBorderSpace(const TRect far*);
    HRESULT  _IFUNC SetBorderSpace(const TRect far*);
    HRESULT  _IFUNC InsertContainerMenus(HMENU, TOcMenuWidths far*);
    HRESULT  _IFUNC SetFrameMenu(HMENU);
    void     _IFUNC RestoreUI();
    HRESULT  _IFUNC Accelerator(MSG far*);
    HRESULT  _IFUNC GetAccelerators(HACCEL far*, int far*);

    // IBDropDest implementation
    //
    HRESULT  _IFUNC Drop(TOcInitInfo far*, TPoint far*, const TRect far*);
    void     _IFUNC DragFeedback(TPoint far*, const TRect far*, TOcMouseAction, uint, HRESULT& hr);
    HRESULT  _IFUNC Scroll(TOcScrollDir scrollDir);
    HRESULT  _IFUNC GetScrollRect(TRect far*);

    // IBContainer implementation
    //
    HRESULT  _IFUNC FindDropDest(TPoint far*, IBDropDest far* far*);
    HRESULT  _IFUNC AllowInPlace();
    HRESULT  _IFUNC BringToFront();

  protected:
    uint32 ForwardEvent(int eventId, const void far* param);
    uint32 ForwardEvent(int eventId, uint32 param = 0);

  protected:
   ~TOcView();
    void Shutdown();// called from derived class destructor to release helpers

    // TUnknown overrides
    //
    HRESULT      QueryObject(const IID far& iid, void far* far* iface);

    // BOle side support
    //
    IUnknown*       BDocument;   // Document helper object
    IBDocument*     BDocumentI;  // Document interface on the document
    IUnknown*       BContainer;  // Container helper object
    IBRootLinkable* BLDocumentI; // RootLinkable interface on the container

    // OC wiring
    //
    TOcApp&         OcApp;        // Our OC application object
    TOcDocument&    OcDocument;   // Our OC document object

    // App side support
    //
    HWND            Win;          // Actual app container window
    TOcPart*        ActivePart;   // Currently active part, if any

    uint32          Options;

#if defined(BI_DATA_NEAR)
    TPoint&          Origin;       // Origin of view topleft relative to the document
    TSize&           Extent;       // Extent of view's perception of document?
    string&          WinTitle;     // Merged window title string
    TOcFormatList&   FormatList;   // list of clipboard formats supported
    TString&         OrgTitle;     // Original window title string
#else
    TPoint           Origin;
    TSize            Extent;
    string           WinTitle;
    TOcFormatList    FormatList;
    TString          OrgTitle;     // Original window title string
#endif
    int              LinkFormat;   // adjustment for format count
    TRegList*        RegList;
    TOcDataProvider* OcData;       // Dataprovider representing this view

  friend class _ICLASS TOcPart;
  friend class _ICLASS TOcDataProvider;
  friend class _ICLASS TOcLinkView;
};

//----------------------------------------------------------------------------

//
// Subdispatch IDs for TOcApp clients
//
#define OC_VIEWTITLE          0x0200  // Get view window title
#define OC_VIEWSETTITLE       0x0201  // Set view window title
#define OC_VIEWBORDERSPACEREQ 0x0202  // Request/Set border space in view
#define OC_VIEWBORDERSPACESET 0x0203  // Request/Set border space in view
#define OC_VIEWDROP           0x0204  // Accept a drop
#define OC_VIEWDRAG           0x0205  // Provide drag feedback (c&s)
#define OC_VIEWSCROLL         0x0206  // scroll view
#define OC_VIEWPARTINVALID    0x0207  // a part needs repainting

#define OC_VIEWPAINT          0x0300  // paint remote view. Like WM_PAINT + extra
#define OC_VIEWLOADPART       0x0301  // ask server to load document
#define OC_VIEWSAVEPART       0x0302  // ask server to save document
#define OC_VIEWCLOSE          0x0303  // Tell server to close this remote view
#define OC_VIEWINSMENUS       0x0304  // ask server to insert its menus in mbar
#define OC_VIEWSHOWTOOLS      0x0305  // ask server to show its tools
#define OC_VIEWGETPALETTE     0x0306  //
#define OC_VIEWCLIPDATA       0x0307  // ask server for a clip data in a format
#define OC_VIEWSETDATA        0x0308  // set format data into server
#define OC_VIEWPARTSIZE       0x0309  // ask server for a its extent
#define OC_VIEWOPENDOC        0x030A  // ask server for a its extent
#define OC_VIEWATTACHWINDOW   0x030B  // ask server to attach to its owner window
#define OC_VIEWSETSCALE       0x030C  // ask server to handle scaling
#define OC_VIEWGETSCALE       0x030D  // ask container to give scaling info
#define OC_VIEWGETSITERECT    0x030E  // ask container for the site rect
#define OC_VIEWSETSITERECT    0x030F  // ask container to set the site rect
#define OC_VIEWGETITEMNAME    0x0310  // ask server to name its content or selection
#define OC_VIEWSETLINK        0x0311  // ask server to establish link to item
#define OC_VIEWBREAKLINK      0x0312  // ask server to break link to item
#define OC_VIEWPARTACTIVATE   0x0313  // let container know the part is activated
#define OC_VIEWPASTEOBJECT    0x0314  // let container know a part is pasted
#define OC_VIEWDOVERB         0x0315  // ask server to do a verb

#define OC_USEREVENT          0xF000  // User defined events


struct TOcDragDrop {   // for viewdrop & viewdrag
  TOcInitInfo far*  InitInfo;  // ViewDrop event only, else 0
  TPoint*           Where;
  TRect*            Pos;
};

struct TOcViewPaint {   // for part adornment painting over part, & painting views
  HDC        DC;
  TRect*     Pos;
  TRect*     Clip;
  TOcAspect  Aspect;
  bool       PaintSelection;  // paint the selection only
  TString*   Moniker;         // moniker if any
  void*      UserData;        // User data

};

//
// Use when doing parts save and load
//
class TOcSaveLoad {
public:
  TOcSaveLoad()
    : StorageI(0), SameAsLoad(false), Remember(true), SaveSelection(false),
      UserData(0) {}
  TOcSaveLoad(IStorage* storageI, bool sameAsLoad = true, bool remember = false,
              bool saveSelection = false, void* userData = 0) {
      StorageI      = storageI;
      SameAsLoad    = sameAsLoad;
      Remember      = remember;
      SaveSelection = saveSelection;
      UserData      = userData;
    }

public:
  IStorage far* StorageI;
  bool          SameAsLoad;      // Same IStorage as one used for loading
  bool          Remember;        // whether to keep the IStorage ptr after save/load
  bool          SaveSelection;   // whether to save only the selection
  void*         UserData;        // User data
};

struct TOcToolBarInfo {
  bool  Show;        // whether this is a show or a hide
  HWND  HFrame;      // Container frame for show, Server frame for hide
  HWND  HLeftTB;
  HWND  HTopTB;
  HWND  HRightTB;
  HWND  HBottomTB;
};

//
// Used to obtain the size of the rectangle that encloses the selection
//
class TOcPartSize {
public:
  TOcPartSize() : PartRect(0, 0, 0, 0), Selection(false), Moniker(0), UserData(0) {};
  TOcPartSize(TRect rect, bool selection = false, TString* moniker = 0, void* userData = 0) {
    PartRect  = rect;
    Selection = selection;
    Moniker   = moniker;
    UserData  = userData;
  }
  TOcPartSize(bool selection, TString* moniker = 0, void* userData = 0)
    : PartRect(0, 0, 0, 0) {
    Selection = selection;
    Moniker   = moniker;
    UserData  = userData;
  }

public:
  TRect    PartRect;     // rect enclosing the whole/part of the embedded object
  bool     Selection;    // whether we want rect for the whole or part(selection)
  TString* Moniker;      // we want the selection rect for moniker
  void*    UserData;     // User data
};

//
// Used to obtain the item name for building monikers
//
class TOcItemName {
public:
  TOcItemName() : Selection(false) {};
  TOcItemName(bool selection) {
    Selection = selection;
  }

public:
  TString Name;        // item moniker
  bool    Selection;   // whether we want name for the whole or part(selection)
};

//
// Used to obtain the native clipboard format data
//
class TOcFormatData {
public:
  TOcFormatData(TOcFormat& format, void* userData = 0, HANDLE handle = 0,
                bool paste = false, TPoint far* where = 0)
    : Format(format), UserData(userData), Handle(handle),
      Paste(paste), Where(where) {}

public:
  TOcFormat&  Format;        // Clipboard format
  void*       UserData;      // User data for mapping to a selection
  HANDLE      Handle;        // clipboard data in handle
  bool        Paste;         // are we doing a paste?
  TPoint far* Where;         // Where to drop this data
};

//
// Used to obtain the item name for building monikers
//
class TOcItemLink {
public:
  TOcItemLink(const char far* moniker, TOcLinkView* view){
    Moniker    = moniker;
    OcLinkView = view;
  };

public:

  const char far*  Moniker;      // item moniker
  TOcLinkView*     OcLinkView;   // view associated with the link
};

//----------------------------------------------------------------------------

//
// class TOcScaleFactor
// ----- --------------
//
class TOcScaleFactor {
  public:
    TOcScaleFactor();
    TOcScaleFactor(const TRect& siteRect, const TSize& partSize);
    TOcScaleFactor(const TOcScaleInfo far& scaleInfo);

    TOcScaleFactor& operator =(const TOcScaleInfo far& scaleInfo);
    TOcScaleFactor& operator =(const TOcScaleFactor& scaleFactor);
    void GetScaleFactor(TOcScaleInfo far& scaleInfo) const;

    bool IsZoomed();
    void SetScale(uint16 percent);
    uint16 GetScale();
    void Reset();

  public:
    TSize        SiteSize;
    TSize        PartSize;
};


inline bool TOcView::IsOptionSet(uint32 option) const
               {return ToBool(Options & option);}
inline void TOcView::SetOption(uint32 bit, bool state)
               {if (state) Options |= bit; else Options &= ~bit;}

#endif  // OCF_OCVIEW_H

