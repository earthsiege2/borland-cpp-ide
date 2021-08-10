//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implements classes TStorageDocument, TDocFile, streams
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/owlpch.h>
#include <owl/docview.h>      // force Windows headers in before OLE
#include <osl/ustring.h>
#include <owl/stgdoc.h>

// Simple refcount debug assistant
//
#if defined(CHECK_REFCOUNT)
static void RefCountCheck(IStorage far* si) {
  uint32 count = si->AddRef();
  count = si->Release();
}
#else
# define RefCountCheck(si)
#endif

const int B_size    = 516;                // default buffer size
const char DefaultStreamName[] = "Contents";

//
//  class TStorageBuf
//  ----- -----------
//
class  _OWLCLASS_RTL TStorageBuf : public streambuf {
  public:
    // constructors, destructor
    TStorageBuf _FAR * open(IStorage& stg, LPCSTR name, int omode);
    TStorageBuf();                       // make a closed TStorageBuf
    virtual ~TStorageBuf();

    int is_open() { return opened; }     // is the file open
    IStream* fd() { return strm; }

    TStorageBuf _FAR * close();          // flush and close file
//  TStorageBuf _FAR * attach(IStream*); // attach this TStorageBuf to opened IStream
    virtual int overflow(int = EOF);
    virtual int underflow();
    virtual int sync();
    virtual streampos  seekoff(streamoff, ios::seek_dir, int);
    virtual streambuf _FAR * setbuf(char _FAR *, int);

  protected:
//  IStorage* stg;       // parent storage
    IStream*  strm;
    int       mode;      // the opened mode
    short     opened;    // non-zero if stream is open
    uint64    last_seek;
    char      lahead[2]; // current input char if unbuffered
};

//
//  class TStorageStreamBase
//  ----- ------------------
//
class _OWLCLASS_RTL TStorageStreamBase : virtual public ios {
  public:
    TStorageStreamBase(IStorage& stg, const char far* name, int mode);
   ~TStorageStreamBase() {}
    void    setbuf(char _FAR *, int);
    void    close();

    TStorageBuf buf;
};

//
//  class TStorageInStream
//  ----- ----------------
//
class _OWLCLASS_RTL TStorageInStream : public TStorageStreamBase,
                                       public TInStream {
  public:
    TStorageInStream(TStorageDocument& doc,  const char far* name, int mode)
                           : TInStream(doc,         name,     mode),
                   TStorageStreamBase(*doc.StorageI,name,     mode) {}
   ~TStorageInStream() {}
};

//
//  class TStorageOutStream
//  ----- -----------------
//
class _OWLCLASS_RTL TStorageOutStream : public TStorageStreamBase,
                                        public TOutStream {
  public:
    TStorageOutStream(TStorageDocument& doc,  const char far* name, int mode)
                           : TOutStream(doc,         name,     mode),
                    TStorageStreamBase(*doc.StorageI,name,     mode) {}
   ~TStorageOutStream() {}
};


//----------------------------------------------------------------------------
//  class TStorageDocument
//

TStorageDocument::~TStorageDocument()
{
  ReleaseDoc();
  SetDirty(false); // ~TDocument() will Close() after destroying children
}

//
// Release the IStorage and close the document
//
bool
TStorageDocument::ReleaseDoc()
{
  CanRelease = true; // now we can release the storage
  return Close();
}

//
// Open the compound file with a given path
//
bool
TStorageDocument::Open(int omode, const char far* name)
{
  if (StorageI > 0) {
    return true;
  }
  do {  // establish try block
    bool stgopen = true;
    bool stgcreate = false;
    HRESULT hres;
    IStorage* parentStg;
    int pmode = 0;

    if (!omode)
      omode = GetOpenMode();

    if (GetParentDoc()) {
      pmode = GetParentDoc()->GetOpenMode();
      if (!(GetParentDoc()->Open(pmode ? pmode : omode, name)))
        return false;
    }
    ++OpenCount;
    if (!omode)
      omode = pmode;
    if (!(omode & (ofRead | ofWrite)))
      break;
    if (!(omode & shMask)) {
      if ((omode & (ofRead | ofWrite)) == (ofRead | ofWrite))
        omode |= shRead;       // let others read if we are read/write
      else
        omode |= shReadWrite;  // let others read/write if we are readonly
    }
    ThisOpen = omode;
    SetOpenMode(omode);  // remember the open mode
    if (name && name[0])
      SetDocPath(name);
    else
      name = GetDocPath();
    long shareMode = ((omode & shMask) - shCompat) >> 5;
    long grfMode = ((omode & (ofRead|ofWrite)) - 1)
                 | shareMode
                 | ((long)(omode & (ofTransacted|ofPreserve|ofPriority)) << 4)
                 | ((omode & ofTemporary) ? STGM_DELETEONRELEASE : 0);
    long childMode = (grfMode ^ shareMode) | STGM_SHARE_EXCLUSIVE;

    if (omode & ofWrite) {
      if (omode & ofNoReplace) {
        stgopen = false;
        stgcreate = true;
      }
      else if (!(omode & ofNoCreate)) {
        stgcreate = true;
        if (omode & ofTruncate || !(omode & (ofAtEnd | ofAppend))) {
          stgopen = false;
          grfMode |= STGM_CREATE;
          childMode |= STGM_CREATE;
        }
      }
    }
    if (GetParentDoc()) {
      if (!GetParentDoc()->GetProperty(FindProperty("IStorage Instance"),
                                       &parentStg, 0))
        break;
      if (stgopen) {
        hres = parentStg->OpenStorage(OleStr(name), 0, childMode, 0, 0, &StorageI);
        if (SUCCEEDED(hres))
          stgcreate = false;
      }
      if (stgcreate) {
        hres = parentStg->CreateStorage(OleStr(name), childMode, 0, 0, &StorageI);
      }
    }
    else {
      if (stgopen) {
        hres = ::StgOpenStorage(OleStr(name), 0, grfMode, 0, 0, &StorageI);
        if (SUCCEEDED(hres))
          stgcreate = false;
      }
      if (stgcreate) {
        hres = ::StgCreateDocfile(OleStr(name), grfMode, 0, &StorageI);
      }
    }
    RefCountCheck(StorageI);

    if (!SUCCEEDED(hres))
      break;
    NotifyViews(vnDocOpened,ThisOpen);
    return true;  // successful return
  } while (0);    // dummy for break scoping, never executed

  // exception handling
  //
  if (GetParentDoc())
    GetParentDoc()->Close();
  --OpenCount;

  return false;
}

const int stgRdWrMask  = (int)(STGM_READWRITE | STGM_READ | STGM_WRITE);
const int stgShareMask = (int)(STGM_SHARE_DENY_NONE | STGM_SHARE_DENY_READ |
                         STGM_SHARE_DENY_WRITE| STGM_SHARE_EXCLUSIVE);
const long stgModeMask  = (STGM_TRANSACTED | STGM_PRIORITY | STGM_CONVERT);

//
// Give an IStorage to document. This typically happens for OLE servers.
//
bool
TStorageDocument::SetStorage(IStorage* stg, bool remember)
{
  if (stg == StorageI)
    return true; // already set

  if (StorageI) {
    RefCountCheck(StorageI);
    if (remember) {
      StorageI->Release();  // Release the ole one
      OrgStorageI = 0;
    }
    else
      OrgStorageI = StorageI;
  }

  StorageI = stg;
  if (!StorageI)
    return true;  // done

  StorageI->AddRef();
  RefCountCheck(StorageI);

  STATSTG stgInfo;
  if (!SUCCEEDED(stg->Stat(&stgInfo, 0)))
    return false;

  SetOpenMode((int)((stgInfo.grfMode & stgRdWrMask) + 1)
           | (int)(((stgInfo.grfMode & stgShareMask) << 5) + shCompat)
           | (int)((stgInfo.grfMode & stgModeMask) >> 4)
           | ((stgInfo.grfMode & STGM_DELETEONRELEASE) ? ofTemporary : 0));

  ThisOpen = GetOpenMode();
  if (remember)
    if (stgInfo.pwcsName)
      SetDocPath(OleStr(stgInfo.pwcsName));
    else
      SetDocPath("  ");

  if (stgInfo.pwcsName) {
    IMalloc* memmgr;
    if (SUCCEEDED(CoGetMalloc(MEMCTX_TASK, &memmgr))) {
      memmgr->Free(stgInfo.pwcsName);    //!CQ really do this here?
      memmgr->Release();
    }
  }

//  NotifyViews(vnDocOpened,ThisOpen);
  return true;
}

//
// Restores the original root IStorage before the save operation
//
bool
TStorageDocument::RestoreStorage()
{
  if (OrgStorageI) {
    if (StorageI)
      StorageI->Release();

    StorageI = OrgStorageI;
    OrgStorageI = 0;
  }

  return true;
}

//
//  Create an istorage based on a memeroy handle
//
bool
TStorageDocument::OpenHandle(int omode, HANDLE hGlobal)
{
  int pmode = 0;

  if (!omode)
    omode = GetOpenMode();

  if (!omode)
    omode = pmode;
  if (!(omode & (ofRead | ofWrite)))
    return false;
  if (!(omode & shMask)) {
    if ((omode & (ofRead | ofWrite)) == (ofRead | ofWrite))
      omode |= shNone;
    else
      omode |= shReadWrite;  // let others read/write if we are readonly
  }
  ThisOpen = omode;
  SetOpenMode(omode);  // remember the open mode
  long shareMode = ((omode & shMask) - shCompat) >> 5;
  long grfMode = ((omode & (ofRead|ofWrite)) - 1)
               | shareMode
               | ((long)(omode & (ofTransacted|ofPreserve|ofPriority)) << 4)
               | STGM_CREATE;
  if (!SUCCEEDED(CreateILockBytesOnHGlobal(hGlobal, (omode & ofTemporary)!=0, &LockBytes)))
    return false;
  if (!SUCCEEDED(StgCreateDocfileOnILockBytes(LockBytes, grfMode, 0, &StorageI))) {
    LockBytes->Release();
    LockBytes = 0;
    return false;
  }
  ++OpenCount;
  NotifyViews(vnDocOpened,omode);
  return true;
}

//
//  Replace the IStorage with an istorage based on a memory handle
//
bool
TStorageDocument::SetHandle(int omode, HANDLE hGlobal, bool create, bool remember)
{
  int pmode = 0;

  if (!omode)
    omode = GetOpenMode();

  if (!omode)
    omode = pmode;
  if (!(omode & (ofRead | ofWrite)))
    return false;
  if (!(omode & shMask)) {
    if ((omode & (ofRead | ofWrite)) == (ofRead | ofWrite))
      omode |= shNone;
    else
      omode |= shReadWrite;  // let others read/write if we are readonly
  }
  ThisOpen = omode;
  SetOpenMode(omode);  // remember the open mode
  long shareMode = ((omode & shMask) - shCompat) >> 5;
  long grfMode = ((omode & (ofRead|ofWrite)) - 1)
               | shareMode
               | ((long)(omode & (ofTransacted|ofPreserve|ofPriority)) << 4);
  if (!SUCCEEDED(CreateILockBytesOnHGlobal(hGlobal, (omode & ofTemporary)!=0, &LockBytes)))
    return false;

  IStorage* storageI = 0;
  if (!SUCCEEDED(StgOpenStorageOnILockBytes(LockBytes, 0, grfMode, 0, 0, &storageI))) {
    if (create && !SUCCEEDED(StgCreateDocfileOnILockBytes(LockBytes,
                             grfMode |STGM_CREATE, 0, &storageI))) {
      LockBytes->Release();
      LockBytes = 0;
      return false;
    }

    if (!storageI)
      return false;
  }

  RefCountCheck(storageI);
  SetDocPath("ILockByte");
  SetStorage(storageI, remember);
  storageI->Release(); // release extra refcount held by SetStorage
  return true;
}

//
//  Get the global handle from ILockBytes
//
bool
TStorageDocument::GetHandle(HGLOBAL* handle)
{
  if (!LockBytes)
    return false;

  GetHGlobalFromILockBytes(LockBytes, handle);
  return true;
}

//
//
//
bool
TStorageDocument::Close()
{
  if (!StorageI || !CanRelease)
    return true;

  if (StorageI)
    StorageI->Release();

  StorageI = 0;
  NotifyViews(vnDocClosed,ThisOpen);
  SetDirty(false);
  CanRelease = false;
  if (GetParentDoc())
    GetParentDoc()->Close();
  return true;
}

//
//
//
void
TStorageDocument::DetachStream(TStream& strm)
{
  TDocument::DetachStream(strm);
  TStorageDocument::Close();
}

//
//
//
TInStream*
TStorageDocument::InStream(int omode, const char far* strmId)
{
  TInStream* inStream;
  if (omode == ofParent)
    omode = IsOpen() ? ThisOpen : GetOpenMode();
  if (!(omode & ofRead))
    return 0;
  if (!TStorageDocument::Open(GetOpenMode() ? GetOpenMode() | ofRead : omode, strmId))
    return 0;

  inStream = new TStorageInStream(*this, strmId, omode);
  if (inStream && !inStream->good()) {
    delete inStream;
    TStorageDocument::Close();  // close
    return 0;
  }

  return inStream;
}

//
//
//
TOutStream*
TStorageDocument::OutStream(int omode, const char far* strmId)
{
  TOutStream* outStream;
  if (omode == ofParent)
    omode = IsOpen() ? ThisOpen : GetOpenMode();
  if (!(omode & ofWrite))
    return 0;
  if (!TStorageDocument::Open(GetOpenMode() ? GetOpenMode() | ofWrite : omode, strmId))
    return 0;
  outStream = new TStorageOutStream(*this, strmId, omode); // change
  if (outStream && !outStream->good()) {
    delete outStream;
    TStorageDocument::Close();  // change
    return 0;
  }
  SetDirty();     // we don't really know at this point if it will be dirty!!
  return outStream;
}

//
//
//
bool
TStorageDocument::SetDocPath(const char far* path)
{
  TDocument::SetDocPath(path);
  return true;
}

//
//
//
bool
TStorageDocument::Commit(bool force)
{
  if (!TDocument::Commit(force))      // flush views and child docs
    return false;
  if (!StorageI)
    return true;                      // return OK if storage already released

  CommitTransactedStorage();
  SetDirty(false);
  return true;
}

//
//
//
bool
TStorageDocument::CommitTransactedStorage()
{
  HRESULT cres = StorageI->Commit(0);  // try 2phase commit first
  if (!SUCCEEDED(cres)) // check for STG_S_TRYOVERWRITE, but GetScode not in lib
    cres = StorageI->Commit(STGC_OVERWRITE);   // try less robust method
  if (!SUCCEEDED(cres))
    return false;

  return true;
}

//
//
//
bool
TStorageDocument::Revert(bool clear)
{
  if (!StorageI)
    return true;                    // return OK if storage already released
  if (!TDocument::Revert(clear) || !SUCCEEDED(StorageI->Revert()))
    return false;
  SetDirty(false);
  return true;
}

//
//
//
static char* PropNames[] = {
  "Create Time",      // CreateTime
  "Modify Time",      // ModifyTime
  "Access Time",      // AccessTime
  "Storage Size",     // StorageSize
  "IStorage Instance",// IStorageInstance
};

//
//
//
static int PropFlags[] = {
  pfGetBinary|pfGetText,   // CreateTime
  pfGetBinary|pfGetText,   // ModifyTime
  pfGetBinary|pfGetText,   // AccessTime
  pfGetBinary|pfGetText,   // StorageSize
  pfGetBinary,             // IStorage
};

//
//
//
const char*
TStorageDocument::PropertyName(int index)
{
  if (index <= PrevProperty)
    return TDocument::PropertyName(index);
  else if (index < NextProperty)
    return PropNames[index-PrevProperty-1];
  else
    return 0;
}

//
//
//
int
TStorageDocument::PropertyFlags(int index)
{
  if (index <= PrevProperty)
    return TDocument::PropertyFlags(index);
  else if (index < NextProperty)
    return PropFlags[index-PrevProperty-1];
  else
    return 0;
}

//
//
//
int
TStorageDocument::FindProperty(const char far* name)
{
  for (int i = 0; i < NextProperty-PrevProperty-1; i++)
    if (strcmp(PropNames[i], name) == 0)
      return i+PrevProperty+1;
  return 0;
}

//
//
//
int
TStorageDocument::GetProperty(int prop, void far* dest, int textlen)
{
  STATSTG stgInfo;

  switch (prop) {
    case IStorageInstance:
      if (textlen)
        return 0;
      *(IStorage*far*)dest = StorageI;
      return sizeof(IStorage*);

    default:
      if (StorageI) {
        StorageI->Stat(&stgInfo, STATFLAG_NONAME);
        switch (prop) {
          case StorageSize:
            if (!textlen) {
              *(ulong far*)dest = uint64(stgInfo.cbSize).LowPart;
              return sizeof(ulong);
            }
            else {
              char buf[10];
              int len = wsprintf(buf, "%ld", uint64(stgInfo.cbSize).LowPart);
              if (textlen > len)
                textlen = len;
              memcpy(dest, buf, textlen);
              *((char far*)dest + textlen) = 0;
              return len;
            }
          case AccessTime:
#if defined(BI_PLAT_WIN32)
            return FormatFileTime(&stgInfo.atime, dest, textlen);
#endif
          case CreateTime:
#if defined(BI_PLAT_WIN32)
            return FormatFileTime(&stgInfo.ctime, dest, textlen);
#endif
          case ModifyTime:
            return FormatFileTime(&stgInfo.mtime, dest, textlen);
        }
      }
      return TDocument::GetProperty(prop, dest, textlen);
  }
}

//
//
//
bool
TStorageDocument::SetProperty(int prop, const void far* src)
{
  // docfile properties currently not settable
  //
  return TDocument::SetProperty(prop, src);
}

//
//
//
IMPLEMENT_STREAMABLE1(TStorageDocument, TDocument);

//
//
//
void*
TStorageDocument::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TDocument*)GetObject(), is);
  return GetObject();
}

//
//
//
void
TStorageDocument::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TDocument*)GetObject(), os);
}

//----------------------------------------------------------------------------
//  class TStorageStreamBase
//

TStorageStreamBase::TStorageStreamBase(IStorage& stg, const char far* name, int mode)
:
  buf()
{
  ios::init(&buf);

  if (buf.is_open())
    clear(ios::failbit);     // fail - already open
  else if (buf.open(stg, name, mode))
    clear(ios::goodbit);     // successful open
  else
    clear(ios::badbit);      // open failed
}

void TStorageStreamBase::setbuf(char* newbuf, int len)
{
  if (buf.setbuf(newbuf, len))
    clear(ios::goodbit);
  else
    setstate(ios::failbit);
}

void TStorageStreamBase::close()
{
  if (buf.close())
    clear(ios::goodbit);
  else
    setstate(ios::failbit);
}

//----------------------------------------------------------------------------
//  class TStorageBuf
//

//
// make a closed TStorageBuf
//
TStorageBuf::TStorageBuf()
{
  mode = 0;
  opened = 0;
  char* p = new char[B_size];
  if (p) {
    setb(p, p+B_size, 1);   // ~streambuf() will delete buffer
    setp(p+4, p+4);
    setg(p, p+4, p+4);
  }
}

//
// We assume that mode= means that we attached to an already-open file,
// and should not now close it.  We do flush it in any case.
//
TStorageBuf::~TStorageBuf()
{
  if (mode)
    close();
  else
    overflow(EOF);
}

//
// Open or create IStream with mode and protection, attach to this TStorageBuf.
//
TStorageBuf* TStorageBuf::open(IStorage& stg, const char far* name, int omode)
{
  int     how;
  bool    stgopen = true;
  bool    stgcreate = false;
  HRESULT hres;

//int share = omode & shMask;
//if (share < shCompat)
//  share = shNone;
//how = (share-shCompat) >> 5;

  how = (int)STGM_SHARE_EXCLUSIVE;// must open streams and child stg exclusive

  if (opened || !omode)
    return 0;

  if (!name)
    name = DefaultStreamName;

  if (omode & ofWrite) {
    if (!(mode & (ofAtEnd | ofAppend | ofRead)))
      omode |= ofTruncate; // output implies truncate unless in, app, or ate
    if (omode & ofRead)
      how |= (int)STGM_READWRITE;
    else
      how |= (int)STGM_WRITE;
    if (omode & ofNoReplace) {
      stgopen = false;
      stgcreate = true;
    }
    else if (!(omode & ofNoCreate)) {
      stgcreate = true;
      if (omode & ofTruncate) {
        stgopen = false;
        how |= (int)STGM_CREATE;
      }
    }
  }
  else if (omode & ofRead)
      how |= (int)STGM_READ;
  else
      return 0;   // must specfify in, out, or in/out

//if (omode & ofAppend)    // what does this mean for docfile?!!
//    how |= O_APPEND;

  // now try to open
  //
  if (stgopen) {
    hres = stg.OpenStream(OleStr(name), 0, (uint32)how, 0, &strm);
    if (SUCCEEDED(hres))
      stgcreate = false;
    else
      return 0;
  }
  if (stgcreate) {
    hres = stg.CreateStream(OleStr(name), (uint32)how, 0, 0, &strm);
    if (!SUCCEEDED(hres) && !stgcreate) {
      return 0;
    }
  }

  // finish up
  //
  opened = 1;
  mode = omode;
  if ((omode & ofAtEnd) != 0
      && !SUCCEEDED(strm->Seek(int64(), STREAM_SEEK_END, &(ULARGE_INTEGER)last_seek))) {
    strm->Release();
    strm = 0;
    return 0;
  }
  char* b = base();       // buffer address
  int pb = b ? ((blen() > 8) ? 4 : 1) : 0;    // putback area size
  setp(b+pb, b+pb);
  setg(b, b+pb, b+pb);

  return this;
}

#if 0
//
// attach this TStorageBuf to open IStream -- assume fd is actually open
//
TStorageBuf* TStorageBuf::attach(IStream* f)
{
  STATSTG stat;
  if (opened)
    return 0;

  if (f->Stat(&stat, STATFLAG_NONAME) != 0)
    return 0;

  if (f->CreateStream(STREAMNAME,stat.grfMode & ~STGM_TRANSACTED,0,0,&strm)!)
    return 0;

  stg = f;        // assumed to be valid
  opened = 1;
  int rwmode = stat.grfMode & (STGM_READ | STGM_WRITE | STGM_READWRITE);
  mode = rwmode != STGM_WRITE ? ofRead : 0;
  if (rwmode != STGM_READ)
    mode |= ofWrite;

  char* b = base();       // buffer address
  if (!b) {
    b = new char[B_size];
    if (b)
      setb(b, b+B_size, 1);   // ~streambuf() will delete buffer
  }
  int pb = b ? ((blen() > 8) ? 4 : 1) : 0;    // putback area size
  setp(b+pb, b+pb);
  setg(b, b+pb, b+pb);
  return this;
}
#endif

streambuf* TStorageBuf::setbuf(char* b, int len)
{
  if (opened && base())
    return 0;        // already open with a buffer -- no change

  int pb;            // putback area size
  if (b && len > 0)  // use b as the new buffer
    pb = (len > 8) ? 4 : 1; // guard against tiny buffers
  else {             // unbuffered
    len = pb = 0;
    b = 0;
  }
  setb(b, b+len, 0);      // will delete old buffer if needed
  setp(b+pb, b+pb);
  setg(b, b+pb, b+pb);
  return this;
}

//
// Seek file to position.
// We take a simple approach, and don't check for small position changes
// within the current buffer.
//
streampos
TStorageBuf::seekoff(streamoff off, ios::seek_dir dir, int /* mode ignored */)
{
  long loff = off;
  HRESULT hres;
  unsigned long actual;
  int count = out_waiting();

  if (count) {  // flush the output
    hres = strm->Write(pbase(), (ulong)count, &actual);
    if (!SUCCEEDED(hres) || (int)actual != count)
      return EOF;
  }
  else if (dir == ios::cur)
    if ((count = in_avail()) != 0) {
      loff -= count;

      //  if we're in text mode, need to allow for newlines
      //  in the buffer
      //
      if ((mode & ofBinary) == 0) {
        char *tptr = gptr();
        while (tptr != egptr())
          if (*tptr++ == '\n')
            loff--;
      }
    }

  int w = (dir == ios::beg) ? STREAM_SEEK_SET
       : ((dir == ios::cur) ? STREAM_SEEK_CUR
       :       /* ios::end */ STREAM_SEEK_END);

  if (!SUCCEEDED(strm->Seek(int64(loff), w, &(ULARGE_INTEGER)last_seek)))
    return EOF; //?!!
  if (!unbuffered() && base()) {      // set up get and put areas
    int pb = (blen() > 8) ? 4 : 1;  // putback area size
    char *b = base();
    setp(b+pb, b+pb);
    setg(b, b+pb, b+pb);
  }
  return last_seek.LowPart;
}

//
//
//
int TStorageBuf::sync()
{
  HRESULT hres;
  if (!opened)
    return EOF;

  ulong actual;
  int count = out_waiting();
  if (count) {
    char* curp;
    char* srcp = pbase();
    char* endp = srcp + count;

    // convert LF's to CR/LF if text mode
    //
    if ((mode & ofBinary) == 0) {
      for (curp = srcp; curp < endp; curp++) {
        if (*curp == '\n') {
          *curp = '\r';
          count = (int)(curp - srcp + 1);
          hres = strm->Write(srcp, (unsigned long)count, &actual);
          if (!SUCCEEDED(hres) || (int)actual != count)
            return EOF;
          *(srcp = curp) = '\n';
        }
      }
      count = (int)(curp - srcp);  // write what remains in the buffer below
    }
    hres = strm->Write(srcp, (unsigned long)count, &actual);
    if (!SUCCEEDED(hres) || (int)actual != count)
        return EOF;

    // reset get and put areas
    //
    int pb = (blen() > 8) ? 4 : 1;  // putback area size
    char *b = base();
    setp(b+pb, b+blen());
    setg(b, b+pb, b+pb);

  }
  else if (in_avail()) {
    if (!SUCCEEDED(strm->Seek(int64(long(-in_avail())), STREAM_SEEK_CUR, &(ULARGE_INTEGER)last_seek)))
      return EOF;
    setg(eback(), gptr(), gptr());
    setp(gptr(), gptr());
  }
  return 0;
}

//
//
//
int TStorageBuf::underflow()
{
  HRESULT  hres;
  ulong    actual;
  unsigned count;  // input character count
  int      c;      // the return value

  if (!opened || (mode & (ofRead | ofWrite)) == ofWrite)
    return EOF;

  if (in_avail())                   // no action needed
    return (unsigned char)*gptr();

  if (!unbuffered() && base()) {    // this is buffered
    if (sync() != 0)
      return EOF;

    // find buffer data
    //
    int pb = (blen() > 8) ? 4 : 1;  // putback area size
    char* begp = base() + pb;

    // read in a new buffer
    //
    hres = strm->Read(begp, blen()-pb, &actual);
    if (!SUCCEEDED(hres))
      return EOF;
    count = (unsigned)actual;

    // remove CR's if text mode
    //
    if ((mode & ofBinary) == 0) {
      char* endp = begp + count;
      char* dstp = 0;
      char* srcp = 0;
      char* curp;

      for (curp = begp;  curp < endp; curp++) {
        if (*curp == '\r') {
          if (dstp) {
            memcpy(dstp, srcp, (int)(curp - srcp));
            dstp += (int)(curp - srcp);
          }
          else
            dstp = curp;
          srcp = curp + 1;
        }
      }
      if (dstp) {
        endp = dstp + (int)(curp - srcp);
        if (curp != srcp)
          memcpy(dstp, srcp, (int)(curp - srcp));
      }
      count = (int)(endp - begp);
    }

    // set up get and put areas
    //
    setg(base(), begp, begp + count);
    setp(begp, begp);

    if (count)
      c = (unsigned char)*gptr();

  }
  else {     // this is not buffered
    for (;;) {
      hres = strm->Read(lahead, 1, &actual);
      if (!SUCCEEDED(hres) || actual == 0) {
        c = EOF;
        setg(0, 0, 0);
      }
      else {
        c = (unsigned char)lahead[0];
        if ((mode & ofBinary) == 0  && c == '\r')
          continue;
        setg(lahead, lahead, lahead+1);
      }
      break;
    }
  }
  if (!count)
    c = EOF;    // end of file
  return c;
}

//
// always flush
//
int TStorageBuf::overflow(int c)
{
  if (!opened || (mode & (ofRead | ofWrite)) == ofRead)
    return EOF;

  if (unbuffered() || !base()) {
    if (c != EOF) {
      int count;
      char b[2];
      if (c == '\n' && (mode & ofBinary) == 0) {
        b[0] = '\r';
        b[1] = (char)c;
        count = 2;
      }
      else {
        b[0] = (char)c;
        count = 1;
      }
      ulong actual = 0;
      strm->Write(&c, (ulong)count, &actual);
      if ((int)actual != count)
        return EOF;
    }
  }
  else {    // now we know this is buffered and state is not bad

    // resets get and put areas
    //
    if (sync() != 0)
      return EOF;

    // reset get and put areas
    //
    int pb = (blen() > 8) ? 4 : 1;  // putback area size
    char *b = base();
    setp(b+pb, b+blen());
    setg(b, b+pb, b+pb);

    if (c != EOF) {
      sputc(c);
      gbump(1);       // pptr and gptr must be the same
    }
  }
  return 1;
}

//
// flush and close file
//
TStorageBuf* TStorageBuf::close()
{
  if (!opened)
    return 0;         // nothing to do

  int ores = 0;       // result of overflow()
  if (out_waiting() && overflow(EOF) == EOF)
    ores = 1;
  if ((mode & ofWrite) /* && !strm->Commit(0) */)
    ores = 1;

  strm->Release();    //! Question: should we release if commit fails?!!
  strm = 0;
  opened = 0;
  return ores ? 0 : this;
}
