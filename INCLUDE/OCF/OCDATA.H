//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// Definition of TOcDataProvider Class
//----------------------------------------------------------------------------
#if !defined(OCF_OCDATA_H)
#define OCF_OCDATA_H

#if !defined(OCF_OCVIEW_H)
# include <ocf/ocview.h>
#endif

//
// Callback function for user data clean up
//
typedef void (*TDeleteUserData)(void* userData);

//
// class TOcDataProvider
// ~~~~~ ~~~~~~~~~~~~~~~
// Data Provider object for a container document
//
class _OCFCLASS TOcDataProvider : public TUnknown,
                                  public IBDataProvider {  
  public:
    TOcDataProvider(TOcView& ocView, TRegList* regList, IUnknown* outer = 0,
                    void* userData = 0, TDeleteUserData callBack = 0);

    // Object reference & lifetime managment
    //
  public:
    ulong   _IFUNC AddRef() {return GetOuter()->AddRef();}
    ulong   _IFUNC Release() {return GetOuter()->Release();}
    HRESULT _IFUNC QueryInterface(const GUID far& iid, void far*far* iface)
                     {return GetOuter()->QueryInterface(iid, iface);}

    // Supporting methods
    //
    void    Disconnect();
    void    Rename();
    void*   GetUserData() {return UserData;}
    void    SetUserData(void* userData) {UserData = userData;}

  protected:
    // IBDataNegotiator implementation
    //
    UINT     _IFUNC CountFormats();
    HRESULT  _IFUNC GetFormat(uint index, TOcFormatInfo far* fmt);

    // IBDataProvider implementation
  //
    HANDLE  _IFUNC  GetFormatData(TOcFormatInfo far* fmt);
//    HRESULT _IFUNC  SetFormatData(TOcFormatInfo far* fmt, HANDLE data, bool release);
    HRESULT _IFUNC  Draw(HDC dc, const RECTL far*  pos, const RECTL far* clip,
                         TOcAspect aspect, TOcDraw bd);
    HRESULT _IFUNC  GetPartSize(TSize far* size);
    HRESULT _IFUNC  Save(IStorage*, BOOL sameAsLoad, BOOL remember);

#if defined(BI_DATA_NEAR)
    TPoint&        Origin;  // Origin of view topleft relative to the document
    TSize&         Extent;  // size of the document containing selection
#else
    TPoint         Origin;
    TSize          Extent;
#endif

  private:
   ~TOcDataProvider();

    // TUnknown overrides
    //
    HRESULT      QueryObject(const IID far& iid, void far* far* iface);

    TOcView&        OcView;
    IUnknown*       BSite;           // site helper
    IBSite*         BSiteI;          // Site interface
    IBLinkable*     BLSiteI;         // for item moniker
    void*           UserData;        // pointer to application specific data such as selection
    TDeleteUserData CBDelete;        // Call back function for cleaning up user data
};

#endif  // OCF_OCDATA_H
