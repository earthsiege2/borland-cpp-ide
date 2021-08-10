//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
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

//
// forward reference OLE interface without including headers
//
#if defined(BI_PLAT_WIN16)
  class __huge IStorage;
  class __huge IStream;
#else
  class IStorage;
  class IStream;
#endif

//
//  class TStorageDocument
//  ----- ----------------
//
class _USERCLASS TStorageDocument : public TDocument {
  public:
    enum TStgDocProp {
      PrevProperty = TDocument::NextProperty-1,
      CreateTime,        // FILETIME
      ModifyTime,        // FILETIME
      AccessTime,        // FILETIME
      StorageSize,       // unsigned long
      IStorageInstance,  // IStorage*
      NextProperty,
    };
    TStorageDocument(TDocument* parent = 0)
                     : TDocument(parent), StorageI(0), OpenCount(0),
                       CanRelease(false), OrgStorageI(0), LockBytes(0) {}
   ~TStorageDocument();
    virtual bool ReleaseDoc();

    // implement virtual methods of TDocument
    //
    TInStream*  InStream(int omode, const char far* strmId=0);
    TOutStream* OutStream(int omode, const char far* strmId=0);
    bool        Open(int omode, const char far* stgId);
    bool        Close();
    bool        Commit(bool force = false);
    bool        CommitTransactedStorage();
    bool        Revert(bool clear = false);
    bool        SetDocPath(const char far* path);
    bool        IsOpen()  {return (StorageI != 0);}

    int         FindProperty(const char far* name);  // return index
    int         PropertyFlags(int index);
    const char* PropertyName(int index);
    int         PropertyCount() {return NextProperty - 1;}
    int         GetProperty(int index, void far* dest, int textlen=0);
    bool        SetProperty(int index, const void far* src);

    // additional methods for obtaining IStorage
    //
    virtual bool  SetStorage(IStorage* stg, bool remember = true);  // Set a new IStorage
    virtual bool  RestoreStorage();
    virtual bool  OpenHandle(int omode, HANDLE hGlobal); // open on global memory
    virtual bool  SetHandle(int omode, HANDLE hGlobal, bool create = false, bool remember = false);
    virtual bool  GetHandle(HGLOBAL* handle);

    IStorage*     GetStorage() {return StorageI;}

  protected:
    int         ThisOpen;        // actual mode bits used for opening storage
    IStorage*   StorageI;        // current IStorage instance, 0 if not open
    IStorage*   OrgStorageI;     // original IStorage
    ILockBytes* LockBytes;       // ILockBytes used, if any

  private:
    bool        CanRelease;      // can we release the IStorage?

  private:
    int         OpenCount;
    void        DetachStream(TStream& strm);  // override TDocument virtual

  DECLARE_STREAMABLE(_OWLCLASS, TStorageDocument,1);
  friend class _OWLCLASS_RTL TStorageInStream;
  friend class _OWLCLASS_RTL TStorageOutStream;
};

#endif  // OWL_STGDOC_H
