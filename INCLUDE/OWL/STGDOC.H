//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
//----------------------------------------------------------------------------
#if !defined(OWL_STGDOC_H)
#define OWL_STGDOC_H

#if !defined(OWL_DOCVIEW_H)
# include <owl/docview.h>
#endif
#if !defined(__IOSTREAM_H)
# include <iostream.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// Forward reference OLE interface without including headers
//
#if defined(BI_PLAT_WIN16)
  class __huge IStorage;
  class __huge IStream;
#else
  class IStorage;
  class IStream;
#endif

//
// class TStorageDocument
// ~~~~~ ~~~~~~~~~~~~~~~~
class _USERCLASS TStorageDocument : public TDocument {
  public:
    enum TStgDocProp {
      PrevProperty = TDocument::NextProperty-1,
      CreateTime,        // FILETIME
      ModifyTime,        // FILETIME
      AccessTime,        // FILETIME
      StorageSize,       // ulong
      IStorageInstance,  // IStorage*
      NextProperty,
    };
    TStorageDocument(TDocument* parent = 0);
   ~TStorageDocument();
    virtual bool  ReleaseDoc();

    // Implement virtual methods of TDocument
    //
    TInStream*    InStream(int omode, const char far* strmId=0);
    TOutStream*   OutStream(int omode, const char far* strmId=0);
    bool          Open(int omode, const char far* stgId);
    bool          Close();
    bool          Commit(bool force = false);
    bool          CommitTransactedStorage();
    bool          Revert(bool clear = false);
    bool          SetDocPath(const char far* path);
    bool          IsOpen();

    int           FindProperty(const char far* name);  // return index
    int           PropertyFlags(int index);
    const char*   PropertyName(int index);
    int           PropertyCount();
    int           GetProperty(int index, void far* dest, int textlen=0);
    bool          SetProperty(int index, const void far* src);

    // Additional methods for obtaining or changing the IStorage
    //
    virtual bool  SetStorage(IStorage* stg, bool remember = true);  // Set a new IStorage
    virtual bool  RestoreStorage();
    virtual IStorage* GetNewStorage();
    IStorage*     GetStorage();

    virtual bool  OpenHandle(int omode, HANDLE hGlobal); // open on global memory
    virtual bool  SetHandle(int omode, HANDLE hGlobal, bool create = false, bool remember = false);
    virtual bool  GetHandle(HGLOBAL* handle);

  protected:
    int           GetThisOpen();
    IStorage*     GetOrgStorageI();
    ILockBytes*   GetLockBytes();

  protected_data:
    int           ThisOpen;    // Actual mode bits used for opening storage
    IStorage*     StorageI;    // Current IStorage instance, 0 if not open
    IStorage*     OrgStorageI; // Pointer to original IStorage interface
    ILockBytes*   LockBytes;   // Pointer to ILockBytes used, if any

  private:
    bool          CanRelease;  // Can we release the IStorage?
    int           OpenCount;

    void          DetachStream(TStream& strm); // Override TDocument virtual

  DECLARE_STREAMABLE(_OWLCLASS, TStorageDocument,1);
  friend class _OWLCLASS_RTL TStorageInStream;
  friend class _OWLCLASS_RTL TStorageOutStream;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

// --------------------------------------------------------------------------
// Inline implementations

//
// Construct a default Storage document object
//
inline TStorageDocument::TStorageDocument(TDocument* parent)
:
  TDocument(parent), StorageI(0), OpenCount(0), CanRelease(false),
  OrgStorageI(0), LockBytes(0)
{
}

//
// Return 'true' if the storage document object has opened an OLE storage.
// Return 'false' otherwise.
//
inline bool TStorageDocument::IsOpen() {
  return (StorageI != 0);
}

//
// Return the number of properties supported by the storage document object.
// NOTE: The number includes the inherited properties of the storage 
//       document object.
//
inline int TStorageDocument::PropertyCount() {
  return NextProperty - 1;
}

//
// Return the IStorage interface pointer currently associated with the 
// storage document object. Returns 0 if no storage is currently opened.
//
inline IStorage* TStorageDocument::GetStorage() {
  return StorageI;
}

//
// Return the mode bits used to open the storage currently associated with 
// this storage object.
//
inline int TStorageDocument::GetThisOpen() {
  return ThisOpen;
}

//
// Return a pointer to the original IStorage interface associated with this
// storage document object.
//
inline IStorage* TStorageDocument::GetOrgStorageI() {
  return OrgStorageI;
}

//
// Return a pointer to the ILockBytes interface currently being used by this
// storage document object. Return 0 if no ILockBytes interface is in use.
//
inline ILockBytes* TStorageDocument::GetLockBytes() {
  return LockBytes;
}


#endif  // OWL_STGDOC_H
