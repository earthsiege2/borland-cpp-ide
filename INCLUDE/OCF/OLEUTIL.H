//
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Low level OLE Utility class definitions
//----------------------------------------------------------------------------
#if !defined(OCF_OLEUTIL_H)
#define OCF_OLEUTIL_H

#if !defined(OSL_DEFS_H)
# include <osl/defs.h>
#endif
#if !defined(__CSTRING_H)
# include <cstring.h>
#endif
#if !defined(OSL_EXCEPT_H)
# include <osl/except.h>
#endif

// For 16bit Ole2, can grab the headers now if the're not included already,
// For 32bit Ole2, it is too late
//
#if defined(BI_PLAT_WIN16)
# if !defined(__OLE2_H)
#   include <ole2.h>
# endif
# if !defined(__DISPATCH_H)
#   include <dispatch.h>
# endif
# if !defined(__OLENLS_H)
#   include <olenls.h>
# endif
#endif
#if defined(BI_PLAT_WIN32) && !defined(__OLE2_H) && !defined(_OLE2_H_)
# error INC_OLE2 must be defined before osl/defs.h is included. Include ocdefs.h first
#endif

// Force this pointers and vtable pointers far on interfaces
//
#if !defined(_ICLASS)
# if defined(__BORLANDC__)
#   if defined(BI_PLAT_WIN16)
#     define _ICLASS  __huge
#   else
#     define _ICLASS
#   endif
# else
#   define _ICLASS  FAR
# endif
#endif

#define _IFUNC STDMETHODCALLTYPE

class TRegList;

//____________________________________________________________________________
//
// TXOle - OLE API related exception object
//____________________________________________________________________________

class TXOle : public TXBase {
  public:
    TXOle(const string& msg, HRESULT stat);
    TXOle(const TXOle& src);
   ~TXOle();

    TXOle* Clone();
    void   Throw();

    static void Check(HRESULT stat, const char far* msg);
    static void Check(HRESULT stat);
    static void Throw(HRESULT stat, const char far* msg);
    static void OleErrorFromCode(HRESULT stat, char far* buffer, int size);

    const long  Stat;
};
inline TXOle::TXOle(const string& msg, HRESULT stat)
            : TXBase(msg), Stat((long)stat) {}
inline TXOle::TXOle(const TXOle& src)
            : TXBase(src), Stat(src.Stat) {}

#if (__DEBUG > 0) || defined(__WARN)
# define OLECALL(func, msg) TXOle::Check(func, msg)
#else
# define OLECALL(func, msg) TXOle::Check(func)
#endif

//____________________________________________________________________________
//
// TComRef - encapsulation of OLE interface pointers
//____________________________________________________________________________

template<class T> class TComRefBase {
  public:
         operator T far*() {return I;}
         operator T far* far*() {TComRefBase::~TComRefBase(); return &I;}
    int  operator !() {return I==0;}
    void operator delete(void* p) {((TComRefBase<T> far*)p)->I=0;}
  protected:
    TComRefBase(const TComRefBase<T>& i) : I(i.I) {I->AddRef();}
    TComRefBase(T far* i) : I(i) {}
    TComRefBase() : I(0) {}
   ~TComRefBase() {if (I) I->Release(); I = 0;}
    T* I;
  private:
    void* operator new(size_t) {return 0;}  // prohibit use of new
};

template<class T> class TComRef : public TComRefBase<T> {
  public:
    TComRef() : TComRefBase<T>() {}
    TComRef(T far* iface) : TComRefBase<T>(iface) {}
    TComRef(const TComRef<T>& i) : TComRefBase<T>(i) {}
    T far* operator =(T far* iface) {if(I)I->Release(); return I = iface;}
    T far* operator =(const TComRef<T>& i) {if(I)I->Release(); return I=i.I;}
    T far* operator->() {return I;} // should throw exception if I==0
};

//____________________________________________________________________________
//
// TBSTR - BASIC global string encapsulation
//____________________________________________________________________________

class TBSTR {
  public:
    TBSTR() : P(0) {}
    TBSTR(BSTR p) : P(p) {}
   ~TBSTR() {::SysFreeString(P);}
    BSTR   operator =(BSTR p) {if(P)::SysFreeString(P); return P = p;}
    TBSTR& operator =(const TBSTR& p){if(P)::SysFreeString(P);P=p.P;return *this;}
           operator BSTR() {return P;}
           operator BSTR far*() {if(P)::SysFreeString(P); return &P;}
    int    operator !() {return P==0;}
    void   operator ~() {if (P)::SysFreeString(P); P = 0;}
  protected:
    BSTR P;
  private:
    void* operator new(size_t) {return 0;} // prohibit use of new, delete, etc
    void  operator delete(void*) {}
};

//____________________________________________________________________________
//
// TOleAllocator - object to initialize OLE and access memory manager
//____________________________________________________________________________

class TOleAllocator {
  public:
    TOleAllocator();            // gets allocator, does not initialize OLE
    TOleAllocator(IMalloc* mem);// use 0 to initialize with OLE task allocator
   ~TOleAllocator();
    void far* Alloc(unsigned long size);
    void Free(void far* pv);
    IMalloc* Mem;
  private:
    bool Initialized;
};

inline
TOleAllocator::TOleAllocator(IMalloc* mem) : Initialized(true)
{
  OLECALL(OleInitialize(mem), "OleInitialize");
  OLECALL(CoGetMalloc(MEMCTX_TASK, &Mem), "CoGetMalloc");
}

inline
TOleAllocator::TOleAllocator() : Initialized(false)
{
  OLECALL(CoGetMalloc(MEMCTX_TASK, &Mem), "CoGetMalloc");
}

inline
TOleAllocator::~TOleAllocator()
{
  if (Mem)
    Mem->Release();
  if (Initialized)
    ::OleUninitialize();
}

inline void
TOleAllocator::Free(void far* pv)
{
  Mem->Free(pv);
}

//____________________________________________________________________________
//
// TClassId - GUID/IID/CLSID management
//____________________________________________________________________________

class far TClassId {
  public:
    enum TGenerate {Generate};
    TClassId(const GUID far& guid);
    TClassId(const char far* idtxt);
    TClassId(const TClassId& copy);
    TClassId(TGenerate);
    TClassId & operator =(const TClassId& copy);
    TClassId(const GUID far& guid, int offset);
   ~TClassId();
    operator GUID&();
    operator const char*();

  protected:
    TClassId();
    GUID Guid;
    const char* Text;
};

inline TClassId::TClassId(const GUID far& guid) : Text(0) { Guid = guid; }
inline TClassId::TClassId(const TClassId& copy) : Guid(copy.Guid), Text(0) {}
inline TClassId::TClassId() : Text(0) {}  // Guid must be set by derived class
inline TClassId::operator GUID&() { return Guid; }
inline TClassId& TClassId::operator =(const TClassId& copy)
                                     {Guid = copy.Guid; Text=0; return *this;}

class TBaseClassId : public TClassId {
  public:
    TBaseClassId(TRegList& regInfo, int maxAlloc = 256);
    TBaseClassId(const GUID far& guid, int maxAlloc = 256);
    TBaseClassId(const char far* idtxt, int maxAlloc = 256);
    TBaseClassId(TGenerate, int maxAlloc = 256);
    TClassId operator [](int offset);
    int AllocId();
    int GetOffset(const GUID far& guid); // returns -1 if not within range
  private:
    int Offset;    // last offset given out by AllocId(), creator reserves 0
    int MaxAlloc;
};

//____________________________________________________________________________
//
// Fast GUID compare functions, assume that low word has already matched OK
//____________________________________________________________________________

void CmpGuid12(IUnknown* This, REFIID req, REFIID ref, void far*far* pif);

void CmpGuidOle(IUnknown* This, REFIID req, void far*far* pif);

//____________________________________________________________________________
//
// TUnknown - Standard implementation of a controlling IUnknown for an object,
//            to be inherited with other COM interfaces into an implementation
//            class whose IUnknown implementation delegates to TUnknown::Outer.
//____________________________________________________________________________

class _ICLASS TUnknown {
  public:
    operator IUnknown&() {return *Outer;}
    operator IUnknown*() {Outer->AddRef(); return Outer;}
    IUnknown* SetOuter(IUnknown* outer = 0);
    IUnknown* GetOuter() {return Outer;}
    unsigned long GetRefCount();
    unsigned long AdjustRefCount(int i);
    IUnknown& Aggregate(TUnknown& inner);  // returns outermost IUnknown

  protected:
    IUnknown& ThisUnknown() {return I;}
    IUnknown* Outer;
    TUnknown();
    virtual ~TUnknown();
    virtual HRESULT QueryObject(const GUID far& iid, void far* far* pif);

  private:
    class _ICLASS TUnknownI : public IUnknown {
      public:
        HRESULT       _IFUNC QueryInterface(const GUID far& iid, void far*far* pif);
        unsigned long _IFUNC AddRef();
        unsigned long _IFUNC Release();
        TUnknownI() : RefCnt(0), Inner(0) {}
       ~TUnknownI();
        unsigned  RefCnt;  // object's reference count, remains 1 if aggregated
        TUnknown* Inner;   // chain of TUnknown-aggregated objects
      private:
        TUnknown& Host();
    } I;
  friend class TUnknownI;
};

inline IUnknown* TUnknown::SetOuter(IUnknown* outer)
{
  if (outer) {
    Outer = outer;
    if (I.Inner)
      I.Inner->SetOuter(outer);
  }
  return &I;
}

inline TUnknown& TUnknown::TUnknownI::Host()
{
  return *(TUnknown*)((char*)this-(int)(&((TUnknown*)0)->I));
}

inline unsigned long TUnknown::AdjustRefCount(int i)
{
  return (unsigned long)(I.RefCnt += i);
}

//____________________________________________________________________________
//
// Macros to generate COM mixin classes for use with TUnknown
//      Each base class must have an inline QueryInterface wrapper defined.
//
// DECLARE_COMBASES1(classname, base)    // declares support for 1 interface
// DECLARE_COMBASES2(classname, base, base)      // mixes in for 2 interfaces
//  .......
// DEFINE_COMBASES1(classname, base)  // implements IUnknown for 1 interface
// DEFINE_COMBASES2(classname, base, base)   // implements for 2 interfaces
//  ......
//
// Macros to generate inline QueryInterface wrappers for interfaces/delegates
//    (low GUID word may specify an explicit integer or an IID_whatever.Data1)
//    For efficiency they are void functions; check result pointer for success
//
// DEFINE_QI_BASE(cls, low)      // Inherited COM interface with IUnknown base
// DEFINE_QI_OLEBASE(cls, low)   // Inherited OLE interface using an OLE GUID
// DEFINE_QI_DERIVED(cls, base, low)     // COM interface derived from another
// DEFINE_QI_OLEDERIVED(cls, base, low)  // OLE interface derived from another
// DEFINE_QI_DELEGATE(cls, member)       // Inherited object with COM member
// DEFINE_QI_DELEGATE_TEST(cls, member)  // Object whose COM member may be 0
// DEFINE_QI_MEMBER(name, member)        // Used inside object with COM member
// DEFINE_QI_MEMBER_TEST(name, member)   // Where object's COM member may be 0
//
// Macro to invoke inline QueryInterface wrappers and return if successful
//    A list of these is generated by the DEFINE_COMBASESn(...) macro
//
// COMBASEQUERY(name) // Calls name_QueryInterface(), returns OK if success
//
// Macro to provide standard IUnknown implementation which forwards to Outer
//    This macro is automatically invoked by the DEFINE_COMBASESn(...) macro
//
// IUNKNOWN_FORWARD(cls, outer) // cls IUnknown implementation forwards to outer
//
// Example of user-written COM class inheriting from macro-generated mixin
//
//  class TSample : public classname {
//   public:
//    TSample(IUnknown* outer, IUnknown*far* pif) { *pif = SetOuter(outer); }
//  };
//____________________________________________________________________________

#define COMBASES_D(cls, bases)     \
  class cls : public TUnknown, bases { \
  protected:                        \
    virtual HRESULT _IFUNC QueryInterface(const GUID far& iid, void far*far* pif); \
    virtual unsigned long _IFUNC AddRef();  \
    virtual unsigned long _IFUNC Release(); \
    virtual HRESULT QueryObject(const GUID far& iid, void far*far* pif); \
            HRESULT QueryBases(const GUID far& iid, void far*far* pif) \
                               {return cls::QueryObject(iid, pif);} \
  }; // QueryBases() is an inline wrapper to this QueryObject() implementation

#define COMQRY1BASES(i1)             protected i1
#define COMQRY2BASES(i1,i2)          protected i1, COMQRY1BASES(i2)
#define COMQRY3BASES(i1,i2,i3)       protected i1, COMQRY2BASES(i2,i3)
#define COMQRY4BASES(i1,i2,i3,i4)    protected i1, COMQRY3BASES(i2,i3,i4)
#define COMQRY5BASES(i1,i2,i3,i4,i5) protected i1, COMQRY4BASES(i2,i3,i4,i5)

#define DECLARE_COMBASES1(cls,i1) \
  COMBASES_D(cls,COMQRY1BASES(i1))
#define DECLARE_COMBASES2(cls,i1,i2) \
  COMBASES_D(cls,COMQRY2BASES(i1,i2))
#define DECLARE_COMBASES3(cls,i1,i2,i3) \
  COMBASES_D(cls,COMQRY3BASES(i1,i2,i3))
#define DECLARE_COMBASES4(cls,i1,i2,i3,i4) \
  COMBASES_D(cls,COMQRY4BASES(i1,i2,i3,i4))
#define DECLARE_COMBASES5(cls,i1,i2,i3,i4,i5) \
  COMBASES_D(cls,COMQRY5BASES(i1,i2,i3,i4,i5))

#define IUNKNOWN_FORWARD(cls, outer) \
  HRESULT _IFUNC cls::QueryInterface(const GUID far& iid, void far* far* pif)\
                                 { return outer->QueryInterface(iid, pif); } \
  unsigned long _IFUNC cls::AddRef()  { return outer->AddRef(); } \
  unsigned long _IFUNC cls::Release() { return outer->Release(); }

#define COMBASES_I(cls, tests) \
  IUNKNOWN_FORWARD(cls, Outer) \
  HRESULT cls::QueryObject(const GUID far& iid, void far*far* pif) \
         { *pif = 0; tests return ResultFromScode(E_NOINTERFACE); }

#define COMBASEQUERY(cls) \
  cls##_QueryInterface(this,iid,pif); if(*pif) return NOERROR;

#define COMQRY1TEST(i1)             COMBASEQUERY(i1)
#define COMQRY2TEST(i1,i2)          COMBASEQUERY(i1) COMQRY1TEST(i2)
#define COMQRY3TEST(i1,i2,i3)       COMBASEQUERY(i1) COMQRY2TEST(i2,i3)
#define COMQRY4TEST(i1,i2,i3,i4)    COMBASEQUERY(i1) COMQRY3TEST(i2,i3,i4)
#define COMQRY5TEST(i1,i2,i3,i4,i5) COMBASEQUERY(i1) COMQRY3TEST(i2,i3,i4,i5)

#define DEFINE_COMBASES1(cls,i1) \
  COMBASES_I(cls,COMQRY1TEST(i1))
#define DEFINE_COMBASES2(cls,i1,i2) \
  COMBASES_I(cls,COMQRY2TEST(i1,i2))
#define DEFINE_COMBASES3(cls,i1,i2,i3) \
  COMBASES_I(cls,COMQRY3TEST(i1,i2,i3))
#define DEFINE_COMBASES4(cls,i1,i2,i3,i4) \
  COMBASES_I(cls,COMQRY4TEST(i1,i2,i3,i4))
#define DEFINE_COMBASES5(cls,i1,i2,i3,i4,i5) \
  COMBASES_I(cls,COMQRY5TEST(i1,i2,i3,i4,i5))

#define DEFINE_QI_BASE(cls, low) \
  inline void cls##_QueryInterface(cls* obj, REFIID iid, void FAR* FAR* pif) \
  {if (iid.Data1==low) CmpGuid12(obj, iid, IID_##cls, pif);}

#define DEFINE_QI_OLEBASE(cls, low) \
  inline void cls##_QueryInterface(cls* obj, REFIID iid, void FAR* FAR* pif) \
  {if (iid.Data1==low) CmpGuidOle(obj, iid, pif);}

#define DEFINE_QI_DERIVED(cls, base, low) \
  inline void cls##_QueryInterface(cls* obj, REFIID iid, void FAR* FAR* pif) \
  {if (iid.Data1==low) CmpGuid12(obj, iid, IID_##cls, pif); \
  else base##_QueryInterface(obj, iid, pif);}

#define DEFINE_QI_OLEDERIVED(cls, base, low) \
  inline void cls##_QueryInterface(cls* obj, REFIID iid, void FAR* FAR* pif) \
  {if (iid.Data1==low) CmpGuidOle(obj, iid, pif); \
  else base##_QueryInterface(obj, iid, pif);}

#define DEFINE_QI_DELEGATE(cls, member) \
  inline void cls##_QueryInterface(cls* obj, REFIID iid, void FAR* FAR* pif) \
  {obj->member->QueryInterface(iid, pif);}

#define DEFINE_QI_DELEGATE_TEST(cls, member) \
  inline void cls##_QueryInterface(cls* obj, REFIID iid, void FAR* FAR* pif) \
  {if (obj->member) obj->member->QueryInterface(iid, pif);}

#define DEFINE_QI_MEMBER(name, member) \
  void name##_QueryInterface(void far*, REFIID iid, void FAR* FAR* pif) \
  {member->QueryInterface(iid, pif);}

#define DEFINE_QI_MEMBER_TEST(name, member) \
  void name##_QueryInterface(void far*, REFIID iid, void FAR* FAR* pif) \
  {if (member) member->QueryInterface(iid, pif);}

#define DEFINE_COMBASE_DELEGATE(cls, ifc, member) \
  struct _ICLASS cls { \
    cls() : member(0) {} \
    ifc* member; \
    DEFINE_QI_MEMBER_TEST(cls, member) \
  };

#endif  //  OCF_OLEUTIL_H


