//----------------------------------------------------------------------------
// ObjectComponents
// Copyright 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.7  $
//
// Definition of TOcStorage & TOcStream classes
//----------------------------------------------------------------------------
#if !defined(OCF_OCSTORAG_H)
#define OCF_OCSTORAG_H

#if !defined(OCF_DEFS_H)
# include <ocf/defs.h>
#endif

//
// Classes referenced
//
class _ICLASS IRootStorage;
class _ICLASS IStorage;
class _ICLASS IStream;
class _ICLASS ILockBytes;
class _ICLASS IEnumSTATSTG;

#if defined(BI_NAMESPACE)
namespace OCF {
#endif

//
// Classes defined
//
class _ICLASS TOcStream;
class _ICLASS TOcStorage;

#if defined(BI_NAMESPACE)
} // namespace OCF
#endif

//----------------------------------------------------------------------------
// Storage specific definitions & types, primarily for use under Win16
//
#if !defined(HUGE)
# if defined(BI_PLAT_WIN16)
#   define HUGE  __huge
# else
#   define HUGE
# endif
#endif

#if !defined(BI_PLAT_WIN32)

#if !defined(_COMPOBJ_H_)
  struct far ULARGE_INTEGER {unsigned long LowPart; unsigned long HighPart;};
  struct far  LARGE_INTEGER {unsigned long LowPart;   signed long HighPart;};
#endif

typedef char far* far* SNB;

#if !defined(_FILETIME_)
# define _FILETIME_
  struct far FILETIME {uint32 dwLowDateTime; uint32 dwHighDateTime;};
#endif

#if !defined(_STORAGE_H_)
struct far STATSTG {
  char far* pwcsName;
  uint32    type;
  ULARGE_INTEGER cbSize;
  FILETIME  mtime;
  FILETIME  ctime;
  FILETIME  atime;
  uint32    grfMode;
  uint32    grfLocksSupported;
  IID       clsid;
  uint32    grfStateBits;
  uint32    reserved;
};
#define STATFLAG_NONAME 1

#define STGM_DIRECT           0x00000000L
#define STGM_TRANSACTED       0x00010000L
#define STGM_READ             0x00000000L
#define STGM_WRITE            0x00000001L
#define STGM_READWRITE        0x00000002L
#define STGM_SHARE_EXCLUSIVE  0x00000010L
#define STGM_SHARE_DENY_WRITE 0x00000020L
#define STGM_SHARE_DENY_READ  0x00000030L
#define STGM_SHARE_DENY_NONE  0x00000040L
#define STGM_CREATE           0x00001000L
#define STGM_TRANSACTED       0x00010000L
#define STGM_CONVERT          0x00020000L
#define STGM_PRIORITY         0x00040000L
#define STGM_DELETEONRELEASE  0x04000000L

enum STREAM_SEEK {
  STREAM_SEEK_SET = 0,
  STREAM_SEEK_CUR = 1,
  STREAM_SEEK_END = 2
};

enum STGC {
  STGC_DEFAULT = 0,
  STGC_OVERWRITE  = 1,
  STGC_ONLYIFCURRENT  = 2,
  STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE = 4
};

DEFINE_OLEGUID(IID_IRootStorage, 0x00000012L, 0, 0);    // coguid.h

class _ICLASS IStream : public IUnknown {
  public:
    virtual HRESULT _IFUNC Read(void _huge*, uint32, uint32 far*);
    virtual HRESULT _IFUNC Write(void const _huge*, uint32, uint32 far*);
    virtual HRESULT _IFUNC Seek(LARGE_INTEGER, uint32, ULARGE_INTEGER far*);
    virtual HRESULT _IFUNC SetSize(ULARGE_INTEGER);
    virtual HRESULT _IFUNC CopyTo(IStream*, ULARGE_INTEGER, ULARGE_INTEGER far*, ULARGE_INTEGER far*);
    virtual HRESULT _IFUNC Commit(uint32);
    virtual HRESULT _IFUNC Revert();
    virtual HRESULT _IFUNC LockRegion(ULARGE_INTEGER, ULARGE_INTEGER, uint32);
    virtual HRESULT _IFUNC UnlockRegion(ULARGE_INTEGER, ULARGE_INTEGER, uint32);
    virtual HRESULT _IFUNC Stat(STATSTG far*, uint32);
    virtual HRESULT _IFUNC Clone(IStream* far*);
};

class _ICLASS IStorage : public IUnknown {
  public:
    virtual HRESULT _IFUNC CreateStream(const char far*, uint32, uint32, uint32, IStream* far*);
    virtual HRESULT _IFUNC OpenStream(const char far*, void far*, uint32, uint32, IStream* far*);
    virtual HRESULT _IFUNC CreateStorage(const char far*, uint32, uint32, uint32, IStorage* far*);
    virtual HRESULT _IFUNC OpenStorage(const char far*, IStorage*, uint32, SNB, uint32, IStorage* far*);
    virtual HRESULT _IFUNC CopyTo(uint32, IID const far*, SNB, IStorage*);
    virtual HRESULT _IFUNC MoveElementTo(char const far*, IStorage*, char const far*, uint32);
    virtual HRESULT _IFUNC Commit(uint32);
    virtual HRESULT _IFUNC Revert();
    virtual HRESULT _IFUNC EnumElements(uint32, void far*, uint32, IEnumSTATSTG* far*);
    virtual HRESULT _IFUNC DestroyElement(const char far*);
    virtual HRESULT _IFUNC RenameElement(const char far*, const char far*);
    virtual HRESULT _IFUNC SetElementTimes(const char far*, FILETIME const far*, FILETIME const far*, FILETIME const far*);
    virtual HRESULT _IFUNC SetClass(const IID far&);
    virtual HRESULT _IFUNC SetStateBits(uint32, uint32);
    virtual HRESULT _IFUNC Stat(STATSTG far*, uint32);
};

class _ICLASS IRootStorage : public IUnknown {
  public:
    virtual HRESULT _IFUNC SwitchToFile(const char far* lpstrFile);
};

class _ICLASS ILockBytes : public IUnknown {};  // member functions not called
#endif  // #if !defined(_STORAGE_H_)
#endif  // #if !defined(BI_PLAT_WIN32)

#if defined(BI_NAMESPACE)
namespace OCF {
#endif

//
// class TOcStream
// ~~~~~ ~~~~~~~~~
class _OCFCLASS TOcStream {
  public:
    TOcStream(TOcStorage& storage, const char far* name, bool create,
              uint32 mode = STGM_READWRITE);
    TOcStream(TOcStream& stream);
    TOcStream(IStream* stream);
   ~TOcStream();

    IStream* GetIStream();

    HRESULT Read(void HUGE* pv, ulong cb, ulong far* read = 0);
    HRESULT Write(void const HUGE* pv, ulong cb, ulong far* written = 0);
    HRESULT Seek(int64 move, uint32 origin= STREAM_SEEK_SET,
                 uint64 far* newPosition = 0);
    HRESULT SetSize(uint64 newSize);
    HRESULT CopyTo(TOcStream& stream, uint64 cb, uint64 far* read = 0,
                   uint64 far* written = 0);
    HRESULT Commit(uint32 commitFlags);
    HRESULT Revert();
    HRESULT LockRegion(uint64 offset, uint64 cb, uint32 lockType);
    HRESULT UnlockRegion(uint64 offset, uint64 cb, uint32 lockType);
    HRESULT Stat(STATSTG far* statstg, uint32 statFlag);

  protected:
    HRESULT Clone(IStream far* far* ppstm);

    IStream* StreamI;
};

//
// class TOcStorage
// ~~~~~ ~~~~~~~~~~
class _OCFCLASS TOcStorage {
  public:
    TOcStorage(const char far* fileName, bool create,
               uint32 mode = STGM_READWRITE|STGM_TRANSACTED);
    TOcStorage(ILockBytes far* lkbyt, bool create,
               uint32 mode = STGM_READWRITE|STGM_TRANSACTED);
    TOcStorage(TOcStorage& parent, const char far* name, bool create,
               uint32 mode = STGM_READWRITE);
    TOcStorage(IStorage* storage);
   ~TOcStorage();

    IStorage* GetIStorage();

    HRESULT CopyTo(uint32 ciidExclude, IID const far* rgiidExclude,
                   SNB snbExclude, TOcStorage& dest);
    HRESULT MoveElementTo(char const far* name, TOcStorage& dest,
                          char const far* newName, uint32 grfFlags);
    HRESULT Commit(uint32 grfCommitFlags);
    HRESULT Revert();
    HRESULT EnumElements(uint32 reserved1, void far* reserved2,
                         uint32 reserved3, IEnumSTATSTG far*far* ppenm);
    HRESULT DestroyElement(const char far* name);
    HRESULT RenameElement(const char far* oldName, const char far* newName);
    HRESULT SetElementTimes(const char far* name, FILETIME const far* pctime,
                            FILETIME const far* patime,
                            FILETIME const far* pmtime);
    HRESULT SetClass(const IID far& clsid);
    HRESULT SetStateBits(uint32 grfStateBits, uint32 grfMask);
    HRESULT Stat(STATSTG far *pstatstg, uint32 grfStatFlag);

    HRESULT SwitchToFile(const char far* newPath);

    static HRESULT IsStorageFile(const char far* pwcsName);
    static HRESULT IsStorageILockBytes(ILockBytes far* plkbyt);
    static HRESULT SetTimes(char const far* lpszName,
                            FILETIME const far* pctime,
                            FILETIME const far* patime,
                            FILETIME const far* pmtime);

  protected:
    HRESULT CreateStream(const char far* name, uint32 mode, uint32 rsrvd1,
                         uint32 rsrvd2, IStream far* far* stream);
    HRESULT OpenStream(const char far* name, void far *rsrvd1, uint32 grfMode,
                       uint32 rsrvd2, IStream far *far *stream);
    HRESULT CreateStorage(const char far* name, uint32 mode, uint32 rsrvd1,
                          uint32 rsrvd2, IStorage far*far* storage);
    HRESULT OpenStorage(const char far* name, IStorage far* stgPriority,
                        uint32 mode, SNB snbExclude, uint32 rsrvd,
                        IStorage far*far* storage);
    ulong   AddRef();
    ulong   Release();

#if 0  // not currently implemented
//    TOcStorage*    GetParent() const {return Parent;}
//    int            GetOpenMode() const {return OpenMode;}
//    void           SetOpenMode(int mode) const {OpenMode = mode;}

  protected:
//    int         ThisOpen;     // actual mode bits used for opening storage

  private:
//    int         OpenMode;     // mode and protection flags
//    int         OpenCount;
//    TOcStorage* Parent;
#endif
    IStorage*   StorageI;

  friend TOcStream;
};

#if defined(BI_NAMESPACE)
} // namespace OCF
#endif

#endif  // OCF_OCSTORAG_H
