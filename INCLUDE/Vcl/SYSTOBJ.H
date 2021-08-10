// SYSTOBJ.H: Pascal TObject and Interface types
// Copyright (c) 1997, 1999 Borland International

#if !defined(SYSTOBJ_H)
#define SYSTOBJ_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif
#if !defined(DSTRING_H)
#include <dstring.h>
#endif
#if !defined(WSTRING_H)
#include <wstring.h>
#endif

#pragma option push -w-inl -w-lvc

namespace System
{
        struct PACKAGE TInterfaceEntry
        {
          TGUID IID;
          Pointer VTable;
          int IOffset;
        };
        typedef TInterfaceEntry *PInterfaceEntry;

        struct PACKAGE TInterfaceTable
        {
          int EntryCount;
          TInterfaceEntry Entries[];
        };
        typedef TInterfaceTable *PInterfaceTable;

        // NOTE: Do not mess with TObject unless you really know what you're doing.
        //       In particular, do not add, remove or change the order of virtual methods.
        //
        class DELPHICLASS TObject
        {
        public:
                          __fastcall  TObject(); /* Body provided by VCL {} */

                          __fastcall Free();
          TClass  __fastcall ClassType();
          void    __fastcall CleanupInstance();
          void *  __fastcall FieldAddress(const ShortString &Name);

          /*         class method */ static TObject * __fastcall InitInstance(TClass cls, void *instance);
          /*         class method */ static ShortString __fastcall ClassName(TClass cls);
          /*         class method */ static bool __fastcall ClassNameIs(TClass cls, const AnsiString string);
          /*         class method */ static TClass __fastcall ClassParent(TClass cls);
          /*         class method */ static void * __fastcall ClassInfo(TClass cls);
          /*         class method */ static long __fastcall InstanceSize(TClass cls);
          /*         class method */ static bool __fastcall InheritsFrom(TClass cls, TClass aClass);
          /*         class method */ static void * __fastcall MethodAddress(TClass cls, const ShortString &Name);
          /*         class method */ static ShortString __fastcall MethodName(TClass cls, void *Address);
          
          /* Hack: GetInterface is an untyped out object parameter and
           * so is mangled as a void*. In practice, however, it is
           * really a void**. Be sure when using this method to provide
           * two levels of indirection and cast away one of them.
           */

          bool __fastcall GetInterface(const TGUID &IID, /* out */ void *Obj);

          /*         class method */ static PInterfaceEntry __fastcall GetInterfaceEntry(const TGUID IID);
          /*         class method */ static PInterfaceTable * __fastcall GetInterfaceTable(void);

          ShortString __fastcall ClassName()
          {
                return ClassName(ClassType());
          }

          bool __fastcall ClassNameIs(const AnsiString string)
          {
                return ClassNameIs(ClassType(), string);
          }

          TClass __fastcall ClassParent()
          {
                return ClassParent(ClassType());
          }

          void * __fastcall ClassInfo()
          {
                return ClassInfo(ClassType());
          }

          long __fastcall InstanceSize()
          {
                return InstanceSize(ClassType());
          }

          bool __fastcall InheritsFrom(TClass aClass)
          {
                return InheritsFrom(ClassType(), aClass);
          }

          void * __fastcall MethodAddress(const ShortString &Name)
          {
                return MethodAddress(ClassType(), Name);
          }

          ShortString __fastcall MethodName(void *Address)
          {
                return MethodName(ClassType(), Address);
          }

          virtual HResult __fastcall SafeCallException(TObject *ExceptObject, void *ExceptAddr);
          virtual void __fastcall AfterConstruction();
          virtual void __fastcall BeforeDestruction();
          virtual void __fastcall Dispatch(void *Message);
          virtual void __fastcall DefaultHandler(void* Message);

        private:
          virtual TObject* __fastcall NewInstance(TClass cls);

        public:
          virtual void __fastcall FreeInstance();
          virtual __fastcall ~TObject();  /* Body provided by VCL {} */
        };

        class PACKAGE TMetaClass
        {
        public:
          TObject * __fastcall InitInstance(void *instance)
          {
                return TObject::InitInstance(this, instance);
          }

          ShortString __fastcall ClassName()
          {
                return TObject::ClassName(this);
          }

          bool __fastcall ClassNameIs(const AnsiString &string)
          {
                return TObject::ClassNameIs(this,string);
          }

          TClass __fastcall ClassParent()
          {
                return TObject::ClassParent(this);
          }

          void * __fastcall ClassInfo()
          {
                return TObject::ClassInfo(this);
          }

          long __fastcall InstanceSize()
          {
                return TObject::InstanceSize(this);
          }

          bool __fastcall InheritsFrom(TClass aClass)
          {
                return TObject::InheritsFrom(this, aClass);
          }

          void * __fastcall MethodAddress(const ShortString &Name)
          {
                return TObject::MethodAddress(this, Name);
          }

          ShortString __fastcall MethodName(void *Address)
          {
                return TObject::MethodName(this,Address);
          }
        };

        /* DelphiInterface
          This template class is to be used for allowing Delphi-owned interfaces to be returned
          from Pascal function to C++ functions.  Since Delphi automatically provides reference
          counting for these references (removing a huge burden from the programmer), the
          class implemented strives to maintain this feature for the C++ programmer.

          The following invariants must hold:
                sizeof(DelphiInterface<T>) == 4
                template DelphiInterface<T> must be marked DELPHIRETURN
                BCC32 for BCB 3.0 or later must be used to compile this template
                reference counting must be provided by the ctor, copy ctor, operator= and dtor.
                the template type T must be derived from a class which has an AddRef and Release.

          The following general rules apply:
                - the T* and T** operators do not perform reference counting; it is the
                  responsibility of the programmer to ensure that reference handling is
                  correctly performed when these two conversion operators are used.
                - taking the address of the interface stored in a DelphiInterface<T> does NOT:
                  - release the previous interface
                  - increment the reference count of the current interface
                        - it is the responsibility of the programmer to ensure that
                        reference counting is handled properly when the T** operator is used.
                - if no interface is stored in a DelphiInterface<T>, the T* operator will return 0.
        */
        template <class T> class RTL_DELPHIRETURN DelphiInterface
        {
        private:
          T       *intf;

          /* This is a temp hack to allow the C++ compiler to allow us to derrive
                 from DelphiInterface even though we're not implementing and methods
           */
  //    virtual void __InternalPureHack() = 0;

        public:
          __fastcall DelphiInterface<T>() : intf(0)
          {}

#if (__BORLANDC__ >= 0x550)
          // Allows a DelphiInterface<> to be created from another DelphiInterface<>.
          // With __uuidof(), we know the IID of our interface
          template <class ANOTHERINTF>
          __fastcall DelphiInterface<T>(const DelphiInterface<ANOTHERINTF> &rhs) : intf(0)
          {
            rhs->QueryInterface(__uuidof(T), (LPVOID*)(&intf));
          }
#endif

          __fastcall DelphiInterface<T>(const DelphiInterface<T> &rhs)
          {
                if (rhs.intf != 0)
                  rhs.intf->AddRef();
                intf = rhs.intf;
          }

          __fastcall DelphiInterface<T>(T* rhs)
          {
                if (rhs != 0)
                  rhs->AddRef();
                intf = rhs;
          }

          __fastcall ~DelphiInterface<T>()
          {
                if (intf != 0)
                  intf->Release();
                intf = 0;
          }

#if (__BORLANDC__ >= 0x550)
          // Allows a DelphiInterface<> to be assigned to another DelphiInterface<>.
          // With __uuidof(), we know the IID of our interface
          template <class ANOTHERINTF>
          DelphiInterface<T>& __fastcall operator =(DelphiInterface<ANOTHERINTF> &rhs)
          {
                Release();
                rhs->QueryInterface(__uuidof(T), (LPVOID*)(&intf));
          }
#endif
          DelphiInterface<T>& __fastcall operator =(DelphiInterface<T> &rhs)
          {
                if (rhs.intf != 0)
                  rhs.intf->AddRef();

                if (intf != 0)
                  intf->Release();

                intf = rhs.intf;
                return *this;
          }

          DelphiInterface<T>& __fastcall operator =(T *rhs)
          {
                if (rhs != 0)
                  rhs->AddRef();

                if (intf != 0)
                  intf->Release();

                intf = rhs;
                return *this;
          }

          T* __fastcall operator->() const
          {
                return intf;
          }

          bool operator ! () const
          {
                return (intf == 0);
          };

          __fastcall operator T*() const
          {
                return intf;
          }

          T& __fastcall operator *()
          {
                return *intf;
          }

          void Release()
          {
                if (intf)
                  intf->Release();
                intf = 0;
          }

          T** __fastcall operator &()
          {
                return &intf;
          }
        };

        class DELPHICLASS TInterfacedObject : public TObject
        {
        private:
          void    *IUnknown;
        protected:
      int     FRefCount;
          HResult __stdcall QueryInterface(const GUID& IID, /* out */ void **Obj);
          int __stdcall _AddRef(void);
          int __stdcall _Release(void);
        public:
      virtual void __fastcall BeforeDestruction();
          __property int RefCount       = { read=FRefCount };
        };
}

// Type definition of interfaces wrapped by a smart object
//
#if !defined(DECLARE_DINTERFACE_TYPE)
#define DECLARE_DINTERFACE_TYPE(iface) \
        interface iface;               \
        typedef System::DelphiInterface< iface >  _di_ ## iface;
#endif  // DECLARE_DINTERFACE_TYPE

DECLARE_DINTERFACE_TYPE(IUnknown)
DECLARE_DINTERFACE_TYPE(IDispatch)
DECLARE_DINTERFACE_TYPE(IAdviseSink)
DECLARE_DINTERFACE_TYPE(IDataAdviseHolder)
DECLARE_DINTERFACE_TYPE(IDataObject)
DECLARE_DINTERFACE_TYPE(IEnumOLEVERB)
DECLARE_DINTERFACE_TYPE(IEnumFORMATETC)
DECLARE_DINTERFACE_TYPE(IEnumSTATDATA)
DECLARE_DINTERFACE_TYPE(ILockBytes)
DECLARE_DINTERFACE_TYPE(IMalloc)
DECLARE_DINTERFACE_TYPE(IMoniker)
DECLARE_DINTERFACE_TYPE(IOleAdviseHolder)
DECLARE_DINTERFACE_TYPE(IOleClientSite)
DECLARE_DINTERFACE_TYPE(IOleContainer)
DECLARE_DINTERFACE_TYPE(IOleInPlaceActiveObject)
DECLARE_DINTERFACE_TYPE(IOleInPlaceFrame)
DECLARE_DINTERFACE_TYPE(IOleInPlaceObject)
DECLARE_DINTERFACE_TYPE(IOleInPlaceSite)
DECLARE_DINTERFACE_TYPE(IOleInPlaceUIWindow)
DECLARE_DINTERFACE_TYPE(IOleObject)
DECLARE_DINTERFACE_TYPE(IStorage)
DECLARE_DINTERFACE_TYPE(IStream)
DECLARE_DINTERFACE_TYPE(ITypeInfo)
DECLARE_DINTERFACE_TYPE(ICreateTypeInfo)
DECLARE_DINTERFACE_TYPE(ITypeLib)
DECLARE_DINTERFACE_TYPE(ICreateTypeLib)
DECLARE_DINTERFACE_TYPE(IConnectionPointContainer)
DECLARE_DINTERFACE_TYPE(IConnectionPoint)
DECLARE_DINTERFACE_TYPE(IEnumConnectionPoints)
DECLARE_DINTERFACE_TYPE(ISimpleFrameSite)
DECLARE_DINTERFACE_TYPE(IPropertyBag)
DECLARE_DINTERFACE_TYPE(IEnumConnections)
DECLARE_DINTERFACE_TYPE(IOleControl)
DECLARE_DINTERFACE_TYPE(IOleControlSite)
DECLARE_DINTERFACE_TYPE(IPerPropertyBrowsing)
DECLARE_DINTERFACE_TYPE(IFontDisp)
DECLARE_DINTERFACE_TYPE(IPersistStreamInit)
DECLARE_DINTERFACE_TYPE(IPicture)
DECLARE_DINTERFACE_TYPE(IPictureDisp)
DECLARE_DINTERFACE_TYPE(IPropertyPageSite)
DECLARE_DINTERFACE_TYPE(IOleClientSite)
DECLARE_DINTERFACE_TYPE(IErrorLog)
DECLARE_DINTERFACE_TYPE(IEnumOLEVERB)
DECLARE_DINTERFACE_TYPE(IOleDocumentView)
DECLARE_DINTERFACE_TYPE(IOleAdviseHolder)
DECLARE_DINTERFACE_TYPE(IOleContainer)
DECLARE_DINTERFACE_TYPE(IOleInPlaceActiveObject)
DECLARE_DINTERFACE_TYPE(IOleInPlaceObject)
DECLARE_DINTERFACE_TYPE(IOleInPlaceUIWindow)
DECLARE_DINTERFACE_TYPE(IOleInPlaceFrame)
DECLARE_DINTERFACE_TYPE(IOleObject)
DECLARE_DINTERFACE_TYPE(IOleInPlaceSite)

#pragma option pop

#endif
