//----------------------------------------------------------------------------
// ObjectComponents - (c) Copyright 1994 by Borland International
//
// $Revision:   2.0  $
//----------------------------------------------------------------------------
#if !defined(_CUSTOM_COM)
#define _CUSTOM_COM

#if   defined(BI_PLAT_WIN16)
# include <compobj.h>
#elif defined(BI_PLAT_WIN32)
# include <objbase.h>
#endif

// Shorten call type modifier
//
#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif

// {6034C8E0-C35B-101B-AFFC-00608C19FAA0}
//
DEFINE_GUID(CLSID_UtilObject, 0x6034C8E0L, 0xC35B, 0x101B,
                              0xAF, 0xFC, 0, 0x60, 0x8C, 0x19, 0xFA, 0xA0);

// {6034C8E1-C35B-101B-AFFC-00608C19FAA0}
//
DEFINE_GUID(IID_IShape,  0x6034C8E1L, 0xC35B, 0x101B,
                         0xAF, 0xFC, 0, 0x60, 0x8C, 0x19, 0xFA, 0xA0);

// {6034C8E2-C35B-101B-AFFC-00608C19FAA0}
//
DEFINE_GUID(IID_ICalendar, 0x6034C8E2L, 0xC35B, 0x101B,
                           0xAF, 0xFC, 0, 0x60, 0x8C, 0x19, 0xFA, 0xA0);

// An IShape interface
//
class IShape : public IUnknown {
  public:
    // IUnknown members
    //
    HRESULT _IFUNC QueryInterface (const GUID&, LPVOID far*) = 0;
    ULONG   _IFUNC AddRef (void)  = 0;
    ULONG   _IFUNC Release(void)  = 0;

	  // Methods of this interface
	  //
    virtual BOOL _IFUNC Rectangle(HDC dc, int left, int top,
                                  int right, int bottom,
                                  COLORREF fillColor) = 0;
    virtual BOOL _IFUNC Ellipse(HDC dc, int left, int top,
                                int right, int bottom,
                                COLORREF fillColor) = 0;
};
typedef IShape far* LPSHAPE;

// An ICalendar interface
//
class ICalendar : public IUnknown {
  public:
    // IUnknown members
    //
    HRESULT _IFUNC QueryInterface (const GUID&, LPVOID far*) = 0;
    ULONG   _IFUNC AddRef (void)  = 0;
    ULONG   _IFUNC Release(void)  = 0;

	  // Methods of this interface
	  //
    virtual int _IFUNC GetDayOf(int year, int month, int date) = 0;
};
typedef ICalendar far* LPCALENDAR;

#endif  //  _CUSTOM_COM
