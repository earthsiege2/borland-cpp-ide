//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// Definition of TOcLinkView Class
//----------------------------------------------------------------------------
#if !defined(OCF_OCLINK_H)
#define OCF_OCLINK_H

#if !defined(OCF_OCBOCOLE_H)
# include <ocf/ocbocole.h>
#endif
#if !defined(OCF_OCREG_H)
# include <ocf/ocreg.h>
#endif
#if !defined(OCF_OCOBJECT_H)
# include <ocf/ocobject.h>
#endif
#if !defined(CLASSLIB_VECTIMP_H)
# include <classlib/vectimp.h>
#endif
#if !defined(WINSYS_GEOMETRY_H)
# include <winsys/geometry.h>
#endif

class _ICLASS TOcView;

//
// class TOcLinkView
// ~~~~~ ~~~~~~~~~~~
// Link Viewer object for a server document
//
class _ICLASS TOcLinkView : public TUnknown,
//                            public IBPart2 {
                            public IBPart {
  public:
    TOcLinkView(TOcView* ocView, TRegList* regList = 0, IUnknown* outer = 0);
    int Detach();

    // IBSite pass-thrus
    //
    void    Invalidate(TOcInvalidate);
    void    Disconnect();

    // Misc status accessors, etc.
    //
    void     GetLinkRect();
    void     SetMoniker(const char far* name);
    TString& GetMoniker() {return Moniker;};

    // Object reference & lifetime managment
    //
    ulong   _IFUNC AddRef() {return GetOuter()->AddRef();}
    ulong   _IFUNC Release() {return GetOuter()->Release();}
    HRESULT _IFUNC QueryInterface(const GUID far& iid, void far*far* iface)
                     {return GetOuter()->QueryInterface(iid, iface);}

  protected:
    // TUnknown virtual overrides
    //
    HRESULT      QueryObject(const IID far& iid, void far* far* iface);

    // IBDataNegotiator implementation
    //
    uint     _IFUNC CountFormats();
    HRESULT  _IFUNC GetFormat(uint index, TOcFormatInfo far* fmt);

    // IBDataProvider2 implementation
    //
    HANDLE  _IFUNC  GetFormatData(TOcFormatInfo far*);
    HRESULT _IFUNC  Draw(HDC, const RECTL far*, const RECTL far*, TOcAspect, TOcDraw bd);
    HRESULT _IFUNC  GetPartSize(TSize far*);
    HRESULT _IFUNC  Save(IStorage*, BOOL sameAsLoad, BOOL remember);
//    HRESULT _IFUNC  SetFormatData(TOcFormatInfo far* fmt, HANDLE data, bool release);

    // IBPart2 implementation
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

#if defined(BI_DATA_NEAR)
    TPoint&         Origin;  // Origin of view topleft relative to the document
    TSize&          Extent;  // size of the document containing selection
#else
    TPoint          Origin;
    TSize           Extent;
#endif

  private:
   ~TOcLinkView();

    TOcView*        OcView;          // Our hosting view that link is on
    IUnknown*       BSite;           // In-place site helper object
    IBSite*         BSiteI;          // Site interface
    IBApplication*  BAppI;           // Site's application interface

#if defined(BI_DATA_NEAR)
    TString&        Moniker;         //
#else
    TString         Moniker;
#endif

  friend class TOcLinkCollection;
};

//
// class TOcLinkCollection
// ~~~~~ ~~~~~~~~~~~~~~~~~
// Container of link views with iterator
//
class TOcLinkCollection : private TCVectorImp<TOcLinkView*> {
  private:
    typedef TCVectorImp<TOcLinkView*> Base;
    friend class TOcLinkCollectionIter;
  public:
    TOcLinkCollection();
   ~TOcLinkCollection();
    void operator delete(void* ptr) {TStandardAllocator::operator delete(ptr);}

    void Clear();
    int Add(TOcLinkView* const& View) {return Base::Add(View);}
    int IsEmpty() const {return Base::IsEmpty();}
    unsigned Find(TOcLinkView* const& view) const {return Base::Find(view);}
    virtual unsigned Count() const {return Base::Count();}
    int Detach(TOcLinkView* const& view, int del = 0);
    TOcLinkView* Find(TString const moniker) const;
};
typedef TOcLinkCollection TOcViewCollection;  // For compatibility only

//
// class TOcLinkCollectionIter
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~
// Iterator for view collection
//
class TOcLinkCollectionIter : private TCVectorIteratorImp<TOcLinkView*> {
  private:
    typedef TCVectorIteratorImp<TOcLinkView*> Base;
  public:
    TOcLinkCollectionIter(const TOcLinkCollection& c) : Base(c) {}
    operator int() const {return Base::operator int();}
    TOcLinkView* Current() const {return Base::Current();}
    TOcLinkView* operator ++(int) {return Base::operator ++(0);}
    TOcLinkView* operator ++() {return Base::operator ++();}
    void Restart() {Base::Restart();}
    void Restart(unsigned start, unsigned stop) {Base::Restart(start, stop);}
};
typedef TOcLinkCollectionIter TOcViewCollectionIter;  // For compatibility only

#endif  // OCF_OCLINK_H
