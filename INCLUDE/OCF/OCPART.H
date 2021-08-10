//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// Definition of TOcPart class
//----------------------------------------------------------------------------
#if !defined(OCF_OCPART_H)
#define OCF_OCPART_H

#if !defined(OCF_OCBOCOLE_H)
# include <ocf/ocbocole.h>
#endif
#if !defined(OCF_OCOBJECT_H)
# include <ocf/ocobject.h>
#endif
#if !defined(OCF_AUTODEFS_H)
# include <ocf/autodefs.h>
#endif
#if !defined(CLASSLIB_VECTIMP_H)
# include <classlib/vectimp.h>
#endif
#if !defined(WINSYS_GEOMETRY_H)
# include <winsys/geometry.h>
#endif

//
// Classes referenced
//
class _ICLASS TOcStorage;
class _ICLASS TOcDocument;
class TOcVerb;

//
// class TOcPart
// ~~~~~ ~~~~~~~
// OC part class represents an embeded or linked part in a document
//
class _ICLASS TOcPart : public TUnknown, protected IBSite2 {
  public:
    TOcPart(TOcDocument& document, int id = 0);
    TOcPart(TOcDocument& document, const char far* name);
    TOcPart(TOcDocument& document, TOcInitInfo far& initInfo, TRect pos,
            int id = 0);

    virtual bool Init(TOcInitInfo far* initInfo, TRect pos);

    void    Delete();

    bool    operator ==(const TOcPart& other) {return ToBool(&other == this);}

    // Delegated doc functions from TOcDocument
    //
    IBPart*     GetBPartI()  {return BPartI;}
    TOcStorage* GetStorage() {return Storage;}
    void        SetStorage(IStorage* storage, bool remember = true);
    bool    Save(bool SameAsLoad = true, bool remember = true);
    bool    Load();
    int     Detach();
    void    FinishLoading();

    // Position & size information
    //
    TPoint  GetPos() const {return Pos;}
    void    SetPos(const TPoint& pos);
    TSize   GetSize() const;
    void    SetSize(const TSize& size);
    TRect   GetRect() const {return TRect(Pos, Size);}
    void    UpdateRect();
    bool    IsVisible(const TRect& logicalRect) const
              {return ToBool(IsVisible() && logicalRect.Touches(GetRect()));}

    // Flag accessor functions
    //
    void    Select(bool select)
              {if (select) Flags |= Selected; else Flags &= ~Selected;}
    bool    IsSelected() const {return ToBool(Flags&Selected);}
    void    SetVisible(bool visible);
    bool    IsVisible() const {return ToBool(Flags&Visible);}
    bool    IsActive() const {return ToBool(Flags&Active);}
    void    SetActive() {Flags |= Active;}
    bool    IsLink() const {return ToBool(Flags&Link);}

    // Naming
    //
    TString    GetName() {return Name;}
    void       Rename();

    // Pass thru functions to corresponding IBPart
    //
    bool    Save(IStorage* storage, bool sameAsLoad, bool remember);
    bool    Draw(HDC dc, const TRect& pos, const TRect& clip, TOcAspect aspect = asDefault);
    bool    Activate(bool activate);
    bool    Show(bool show) {return HRSucceeded(BPartI->Show(show));}
    bool    Open(bool open) {return HRSucceeded(BPartI->Open(open));}
    HWND    OpenInPlace(HWND hwnd) {return BPartI->OpenInPlace(hwnd);}
    bool    CanOpenInPlace() {return HRSucceeded(BPartI->CanOpenInPlace());}
    bool    Close();
    bool    SetHost(IBContainer far* container)
              {return HRSucceeded(BPartI->SetHost(container));}

    bool    EnumVerbs(const TOcVerb&);
    bool    DoVerb(uint);
    LPCOLESTR    GetServerName(TOcPartName partName)
        {return const_cast<LPOLESTR>(BPartI->GetName((TOcPartName)partName));}
    HRESULT QueryServer(const IID far& iid, void far* far* iface);

    bool    SetFormatData(TOcFormatInfo far* fmt, HANDLE data, bool release);

    // Object reference & lifetime managment
    // For internal OCF use only
    //
    ulong   _IFUNC AddRef() {return GetOuter()->AddRef();}
    ulong   _IFUNC Release() {return GetOuter()->Release();}
    HRESULT _IFUNC QueryInterface(const GUID far& iid, void far*far* iface)
                     {return GetOuter()->QueryInterface(iid, iface);}

  protected:
   ~TOcPart();

    virtual bool InitObj (TOcInitInfo far* initInfo);

    // TUnknown virtual overrides
    //
    HRESULT      QueryObject(const IID far& iid, void far* far* iface);

    // IBSite implementation for BOle to use
    //
    HRESULT   _IFUNC SiteShow(BOOL);
    HRESULT   _IFUNC DiscardUndo();
    HRESULT   _IFUNC GetSiteRect(TRect far*, TRect far*);
    HRESULT   _IFUNC SetSiteRect(const TRect far*);
    HRESULT   _IFUNC SetSiteExtent(const TSize far*);
    HRESULT   _IFUNC GetZoom(TOcScaleInfo far* scale);
    void      _IFUNC Invalidate(TOcInvalidate);
    void      _IFUNC OnSetFocus(BOOL set);
    HRESULT   _IFUNC Init(IBDataProvider far*, IBPart far*, LPCOLESTR, BOOL);
    void      _IFUNC Disconnect();

    // IBSite2 implementation for BOle to use
    //
    HRESULT   _IFUNC GetParentWindow(HWND FAR*);

  protected:
    IUnknown*    BPart;      // Our corresponding helper object & interfaces
    IBPart*      BPartI;
    IBLinkable*  BLPartI;

    TOcDocument& OcDocument; // The OC document we are imbeded in
    TOcStorage*  Storage;    // The storage we are in

#if defined(BI_DATA_NEAR)
    string&      Name;       // Name of this part
    TPoint&      Pos;        // position of this part in the document
    TSize&       Size;       // Keep our idea of size independently
#else
    string       Name;
    TPoint       Pos;
    TSize        Size;
#endif
    enum TFlag { Visible=0x01, Selected=0x02, Active=0x04, Link=0x08,
                 Closing=0x10, OcxDefault=0x20, OcxCancel=0x40 };
    uint16       Flags;      // Is this part Selected/Visible/Active/ALink?

  friend class TOcPartCollection;
};

//
// class TOcPartCollection
// ~~~~~ ~~~~~~~~~~~~~~~~~
// Container of parts with iterator
//
class TOcPartCollection : private TCVectorImp<TOcPart*> {
  private:
    typedef TCVectorImp<TOcPart*> Base;
    friend class TOcPartCollectionIter;
  public:
    TOcPartCollection();
   ~TOcPartCollection();
    void operator delete(void* ptr) {TStandardAllocator::operator delete(ptr);}

    void Clear();
    int Add(TOcPart* const& part) {return Base::Add(part);}
    int IsEmpty() const {return Base::IsEmpty();}
    unsigned Find(TOcPart* const& part) const {return Base::Find(part);}
    virtual unsigned Count() const {return Base::Count();}
    int Detach(TOcPart* const& part, int del = 0);

    TOcPart*   Locate(TPoint& point);
    bool       SelectAll(bool select = false);
};

//
// class TOcPartCollectionIter
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~
//
class TOcPartCollectionIter : private TCVectorIteratorImp<TOcPart*> {
  private:
    typedef TCVectorIteratorImp<TOcPart*> Base;
  public:
    TOcPartCollectionIter(const TOcPartCollection& c) : Base(c) {}
    operator int() const {return Base::operator int();}
    TOcPart* Current() const {return Base::Current();}
    TOcPart* operator ++(int) {return Base::operator ++(0);}
    TOcPart* operator ++() {return Base::operator ++();}
    void Restart() {Base::Restart();}
    void Restart(unsigned start, unsigned stop) {Base::Restart(start, stop);}
};

//
// class TOcVerb
// ~~~~~ ~~~~~~~
class TOcVerb {
  public:
    TOcVerb();

  public:
    LPCOLESTR   TypeName;
    LPCOLESTR   VerbName;
    uint        VerbIndex;
    bool        CanDirty;
};

//
// class TOcPartChangeInfo
// ~~~~~ ~~~~~~~~~~~~~~~~~
// View/Data change info
//
class TOcPartChangeInfo {
  public:
    TOcPartChangeInfo(TOcPart* part, TOcInvalidate type = invView)
      : Part(part), Type(type) {}

    bool     IsDataChange() {return Type & invData;}
    bool     IsViewChange() {return Type & invView;}

    void     SetDataChange() {Type |= invData;}
    void     SetViewChange() {Type |= invView;}

    TOcPart* GetPart() {return Part;}
    void     SetPart(TOcPart* part) {Part = part;}

    int      GetType() {return Type;}

  protected:
    int         Type;  // what type of change
    TOcPart*    Part;
};

#endif  // OCF_OCPART_H
