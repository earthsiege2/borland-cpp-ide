//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.13  $
//
// Classes for window system structure and type encapsulation
//----------------------------------------------------------------------------
#if !defined(WINSYS_WINCLASS_H)
#define WINSYS_WINCLASS_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if !defined(WINSYS_GEOMETRY_H)
# include <winsys/geometry.h>     // TPoint, et. al.
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// class TResId
// ~~~~~ ~~~~~~
// Resource Id class that can be constructed from a integer or string resource
// identifier. Does not own or delete the string.
//
class TResId {
  public:
    // Constructors
    //
    TResId() : Num(0) {}
    TResId(const _TCHAR far* resStr) : Str(resStr) {}
    TResId(int resNum) : Num(unsigned(resNum)) {}

    // Type Conversion operators & information
    //
    operator _TCHAR far*() {return (_TCHAR far*)Str;}
    bool IsString() const {return HiUint16(Num) != 0;}

  private:
    union {
      uint32          Num;  // Assumes that these 32bit fields will overlay
      const _TCHAR far* Str;
    };

  friend ipstream& _WSYSFUNC operator >>(ipstream& is, TResId& id);
  friend opstream& _WSYSFUNC operator <<(opstream& os, const TResId& id);
  friend ostream& _WSYSFUNC  operator <<(ostream& os, const TResId& id);
};

#if defined(BI_NAMESPACE)
}     // namespace ClassLib
#endif

//
// MSW only classes
//
#if defined(BI_PLAT_MSW)

# if !defined(WINSYS_WSYSINC_H)
#   include <winsys/wsysinc.h>
# endif
# if !defined(CLASSLIB_BAGS_H)
#   include <classlib/bags.h>
# endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// class TDropInfo
// ~~~~~ ~~~~~~~~~
// Encapsulation of a system drag-drop event object in an HDROP handle.
//
class TDropInfo {
  public:
    // Constructors
    //
    TDropInfo(HDROP handle) : Handle(handle) {}

    // Type Conversion operators
    //
    operator HDROP() {return Handle;}

    // Information access
    //
    uint DragQueryFile(uint index, _TCHAR far* name, uint nameLen)
           {return ::DragQueryFile(Handle, index, name, nameLen);}
    uint DragQueryFileCount() {return ::DragQueryFile(Handle, uint(-1), 0, 0);}
    uint DragQueryFileNameLen(uint index)
           {return ::DragQueryFile(Handle, index, 0, 0);}
    bool DragQueryPoint(TPoint& point)
           {return ::DragQueryPoint(Handle, &point);}
    void DragFinish() {::DragFinish(Handle);}

  private:
    HDROP  Handle;
};

//
// class TFileDrop
// ~~~~~ ~~~~~~~~~
// Encapsulation of information about a single dropped file, its name, where
// it was dropped, and whether or not it was in the client area
//
class _WSYSCLASS TFileDroplet {
  public:
    TFileDroplet(const _TCHAR* fileName, TPoint& p, bool inClient);
    TFileDroplet(TDropInfo& drop, int i);
   ~TFileDroplet();

    operator ==(const TFileDroplet& other) const {return &other == this;}

    const _TCHAR* GetName() const {return FileName;}
    TPoint      GetPoint() const {return Point;}
    bool        GetInClientArea() const {return InClientArea;}

  private:
    _TCHAR*   FileName;
    TPoint  Point;
    bool    InClientArea;

    // Hidden to prevent accidental copying or assignment
    //
    TFileDroplet(const TFileDroplet&);
    TFileDroplet& operator =(const TFileDroplet&);
};

typedef TIBagAsVector<TFileDroplet> TFileDropletList;
typedef TIBagAsVectorIterator<TFileDroplet> TFileDropletListIter;

//
// class TProcInstance
// ~~~~~ ~~~~~~~~~~~~~
// A ProcInstance object. This encapsulates the MakeProcInstance call, which is
// really only needed in old Win3.X real mode. This exists now for Owl 2.x
// compatibility only
//
class TProcInstance {
  public:
#if defined(BI_PLAT_WIN16) && defined(OWL_PROCINSTANCE)
    TProcInstance(FARPROC p) {Instance = ::MakeProcInstance(p, _hInstance);}
   ~TProcInstance() {::FreeProcInstance(Instance);}
#else
    TProcInstance(FARPROC p) {Instance = FARPROC(p);}
#endif

    operator FARPROC() {return Instance;}

  private:
    FARPROC Instance;
};

//
// TResource simplifies access to a resource by encapsulating
// the find, load, lock and free steps for accessing a resource.
//   - 'T' represents a structure which defines the binary layout of the
//     resource.
//   - 'resType' is a constant string that defines the resource type.
//
// For example,
//
//     typedef TResource<DLGTEMPLATE, RT_DIALOG> TDlgResource;
//     TDlgResource dlgInfo(hInstance, IDD_ABOUTDLG);
//     DLGTEMPLATE* pDlgTmpl = dlgInfo;
//
template <class T, const _TCHAR far* resType>
class _WSYSCLASS TResource {
  public:
    TResource(HINSTANCE hModule, TResId resId);
#if defined(BI_PLAT_WIN32)
    TResource(HINSTANCE hModule, TResId resid, LANGID langid);
#endif
   ~TResource();
    bool      IsOK() const;     // Confirms whether resource was found
    operator  T*();             // Conversion operator to point to
                                // structure representing binary layout
                                // of the resource...
  protected:
    HGLOBAL   MemHandle;        // Handle of resource
    T*        MemPtr;           // Pointer to locked resource
};

//
// Loads & locks the specified resource..
//
template <class T, const _TCHAR far* resType>
TResource<T, resType>::TResource(HINSTANCE hModule, TResId resId)
:
  MemHandle(0),
  MemPtr(0)
{
  HRSRC resHandle = FindResource(hModule, resId, resType);
  if (resHandle) {
    MemHandle = LoadResource(hModule, resHandle);
    if (MemHandle)
      MemPtr = (T*)LockResource(MemHandle);
  }
}

#if defined(BI_PLAT_WIN32)
//
// Loads & locks a resource of the type 'resType' from the module
// (hModule). Accepts a LanguageID for localized resources.
//
template <class T, const _TCHAR far* resType>
TResource<T, resType>::TResource(HINSTANCE hModule, TResId resId, LANGID lcid)
:
  MemHandle(0),
  MemPtr(0)
{
  HRSRC resHandle = FindResourceEx(hModule, resId, resType, lcid);
  if (resHandle) {
    MemHandle = LoadResource(hModule, resHandle);
    if (MemHandle)
      MemPtr = (T*)LockResource(MemHandle);
  }
}
#endif

//
// Unlocks and frees the resource loaded earlier.
// NOTE: Unlocking and freeing of resources is not necessary in WIN32.
//
template <class T, const _TCHAR far* resType>
TResource<T, resType>::~TResource()
{
  // NOTE: UnlockResource and FreeResource are not necessary (albeit harmless)
  // in 32-bit
  //
#if defined(BI_PLAT_WIN16)
  if (MemHandle) {
    UnlockResource(MemHandle);
    FreeResource(MemHandle);
  }
#endif
  MemHandle = 0;
  MemPtr = 0;
}

//
// Returns true if resource was successfully loaded or false otherwise.
//
template <class T, const _TCHAR far* resType> bool
TResource<T, resType>::IsOK() const
{
  return ((MemHandle != 0) && (MemPtr != 0));
}

//
// Returns a pointer to the locked resource.
// NOTE: This operator eliminates the need to explicitly cast
//       LPVOID to a structure representing the actual layout
//       of individual resource types.
//
template <class T, const _TCHAR far* resType>
TResource<T, resType>::operator T* ()
{
  PRECONDITION(IsOK());
  return MemPtr;
}

#if defined(BI_NAMESPACE)
}     // namespace ClassLib
#endif

#endif  // BI_PLAT_MSW

#endif  // WINSYS_WINCLASS_H
