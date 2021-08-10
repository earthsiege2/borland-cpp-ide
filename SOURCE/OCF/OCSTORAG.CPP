//
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Implementation of TOcStorage & TOcStream IStorage/IStream encapsulation
//----------------------------------------------------------------------------
#include <ocf/ocfpch.h>
#include <ocf/ocobject.h>
#include <ocf/ocstorag.h>
#include <osl/geometry.h>
#include <iostream.h>

DIAG_DEFINE_GROUP(OcExcept, true, 1);

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

//
// Storage sharing mode bit mask
//
#define STGM_SHARE_MASK    (STGM_SHARE_DENY_NONE | STGM_SHARE_DENY_READ| \
                            STGM_SHARE_DENY_WRITE | STGM_SHARE_EXCLUSIVE)

//----------------------------------------------------------------------------
// TXObjComp


TXObjComp::~TXObjComp()
{
}

TXObjComp* TXObjComp::Clone()
{
  return new TXObjComp(*this);
}

void TXObjComp::Throw()
{
  THROW( *this );
}
 
void TXObjComp::Check(HRESULT stat, TError err, const char far* arg)
{
  if (FAILED(stat))
    Throw(err, stat, arg);
}

static char* sObjCompErrMsgs[] = {
  "",                                           // xNoError
  "Could not locate " BOLEDLL,                  // xBOleLoadFail
  "Incompatible version of " BOLEDLL,           // xBOleVersFail
  "Could not obtain BOle ClassMgr",             // xBOleBindFail
  "Document factory [un]registration failed",   // xDocFactoryFail
  "Missing Root IStorage in OcDocument",        // xMissingRootIStorage
  "Internal OcPart creation error",             // xInternalPartError
  "OcPart initialization failure",              // xPartInitError
  "Unable to open/create RootStorage on '%s'",  // xRootStorageOpenError
  "Unable to open/create Storage '%s'",         // xStorageOpenError
  "Unable to open/create Storage on ILockBytes",// xStorageILockError
  "Unable to open/create Stream '%s'"           // xStreamOpenError
};

void TXObjComp::Throw(TError err, HRESULT hr, const char far* arg)
{
  if (!InstanceCount) {
    char buf[128+1];
    wsprintf(buf, sObjCompErrMsgs[err], arg);

    if (hr != HR_FAIL) {  // generic error, dont bother with message.
      strcat(buf, ": ");
      int len = strlen(buf);
      OleErrorFromCode(hr, buf + len, sizeof buf - len - 2);
    }
    strcat(buf, ".");

    WARNX(OcExcept, hr != HR_NOERROR, 0, buf);
    throw TXObjComp(err, buf, hr);
  }
}

//----------------------------------------------------------------------------
// TOcStream

//
//
//
TOcStream::TOcStream(TOcStorage& storage, const char far* name, bool create, uint32 mode)
{
  // Make sure that the transacted mode is off since streams don't support
  // this mode. Also make sure that the stream is opened in exclusive mode.
  //
  mode &= ~STGM_TRANSACTED;
  mode = (mode & ~STGM_SHARE_MASK) | STGM_SHARE_EXCLUSIVE;

  HRESULT hr = storage.OpenStream(name, 0, mode, 0, &StreamI);
  if (!StreamI && create)
    hr = storage.CreateStream(name, mode, 0, 0, &StreamI);
  TXObjComp::Check(hr, TXObjComp::xStreamOpenError, name);
}

//
//
//
TOcStream::TOcStream(TOcStream& stream)
{
  stream.Clone(&StreamI);
  // if (!StreamI) throw...?
}

//
//
//
TOcStream::TOcStream(IStream* stream)
:
  StreamI(stream)
{
}

//
//
//
TOcStream::~TOcStream()
{
  if (StreamI)
    StreamI->Release();
}

//
//
//
IStream*
TOcStream::GetIStream()
{
  return StreamI;
}

//
//
//
HRESULT
TOcStream::Read(void HUGE* pv, ulong cb, ulong far* read)
{
  PRECONDITION(pv && read && StreamI);

  return StreamI->Read(pv, cb, read);
}

//
//
//
HRESULT
TOcStream::Write(void const HUGE* pv, ulong cb, ulong far* written)
{
  PRECONDITION(pv && written && StreamI);

  return StreamI->Write(pv, cb, written);
}

//
//
//
HRESULT
TOcStream::Seek(int64 move, uint32 origin, uint64 far* newPosition)
{
  PRECONDITION(newPosition && StreamI);

  return StreamI->Seek(move, origin, (ULARGE_INTEGER*)newPosition);
}

//
//
//
HRESULT
TOcStream::SetSize(uint64 newSize)
{
  return StreamI->SetSize(newSize);
}

//
//
//
HRESULT
TOcStream::CopyTo(TOcStream& stream, uint64 cb, uint64 far* read, uint64 far* written)
{
  PRECONDITION(read);

  return StreamI->CopyTo(stream.GetIStream(), cb, (ULARGE_INTEGER*)read,
                         (ULARGE_INTEGER*)written);
}

//
//
//
HRESULT
TOcStream::Commit(uint32 commitFlags)
{
  return StreamI->Commit(commitFlags);
}

//
//
//
HRESULT
TOcStream::Revert()
{
  return StreamI->Revert();
}

//
//
//
HRESULT
TOcStream::LockRegion(uint64 offset, uint64 cb, uint32 lockType)
{
  return StreamI->LockRegion(offset, cb, lockType);
}

//
//
//
HRESULT
TOcStream::UnlockRegion(uint64 offset, uint64 cb, uint32 lockType)
{
  return StreamI->UnlockRegion(offset, cb, lockType);
}

//
//
//
HRESULT
TOcStream::Stat(STATSTG far* statstg, uint32 statFlag)
{
  PRECONDITION(statstg);

  return StreamI->Stat(statstg, statFlag);
}

//
//
//
HRESULT
TOcStream::Clone(IStream far* far* stream)
{
  PRECONDITION(stream);

  return StreamI->Clone(stream);
}

//----------------------------------------------------------------------------
// TOcStorage

//
//
//
TOcStorage::TOcStorage(const char far* fileName, bool create, uint32 mode)
{
//  Parent = 0;

  // Fill in the sharing mode based on the access
  //
  if ((mode & STGM_WRITE) || (mode & STGM_READWRITE))
    mode = (mode & ~STGM_SHARE_MASK) | STGM_SHARE_DENY_WRITE;
  else
    mode = (mode & ~STGM_SHARE_MASK) | STGM_SHARE_DENY_NONE;
  
  HRESULT hr;
  if (create) {
    mode |= STGM_CREATE;
    if (!fileName)
      mode |= STGM_DELETEONRELEASE;
    hr = ::StgCreateDocfile(OleStr(fileName), mode, 0, &StorageI);
  }
  else {
    hr = ::StgOpenStorage(OleStr(fileName), 0, mode, 0, 0, &StorageI);
  }
  RefCountCheck(StorageI);
  TXObjComp::Check(hr, TXObjComp::xRootStorageOpenError, fileName);
}

//
//
//
TOcStorage::TOcStorage(ILockBytes far* lkbyt, bool create, uint32 mode)
{
  PRECONDITION(lkbyt);

  // Fill in the sharing mode based on the access
  //
  if ((mode & STGM_WRITE) || (mode & STGM_READWRITE))
    mode = (mode & ~STGM_SHARE_MASK) | STGM_SHARE_DENY_WRITE;
  else
    mode = (mode & ~STGM_SHARE_MASK) | STGM_SHARE_DENY_NONE;
  
  HRESULT hr;
  if (create) {
    mode |= STGM_CREATE;
    hr = ::StgCreateDocfileOnILockBytes(lkbyt, mode, 0, &StorageI);
  }
  else {
    hr = ::StgOpenStorageOnILockBytes(lkbyt, 0,  // IStorage* priority???
             mode, 0, 0, &StorageI);
  }
  RefCountCheck(StorageI);
  TXObjComp::Check(hr, TXObjComp::xStorageILockError);
}

//
//
//
TOcStorage::TOcStorage(TOcStorage& parent, const char far* name, bool create, uint32 mode)
{
//  Parent = &parent;
  mode = (mode & ~STGM_SHARE_MASK) | STGM_SHARE_EXCLUSIVE;
  HRESULT hr;
  hr = parent.OpenStorage(name, 0, mode, 0, 0, &StorageI);
  if (!StorageI && create)
    hr = parent.CreateStorage(name, mode, 0, 0, &StorageI);

  RefCountCheck(StorageI);
  TXObjComp::Check(hr, TXObjComp::xStorageOpenError, name);
}

//
//
//
TOcStorage::TOcStorage(IStorage* storage)
:
  StorageI(storage)
{
  if (StorageI) {
    StorageI->AddRef();
    RefCountCheck(StorageI);
  }
}

//
//
//
TOcStorage::~TOcStorage()
{
  if (StorageI) {
    RefCountCheck(StorageI);
    StorageI->Release();
  }
}

//
//
//
ulong
TOcStorage::AddRef()
{
  return StorageI? StorageI->AddRef() : 0;
}

//
//
//
ulong
TOcStorage::Release()
{
  return StorageI? StorageI->Release() : 0;
}

//
//
//
IStorage*
TOcStorage::GetIStorage()
{
  return StorageI;
}

//
//
//
HRESULT
TOcStorage::CopyTo(uint32 ciidExclude, IID const far* rgiidExclude, SNB snbExclude, TOcStorage& dest)
{
  return StorageI->CopyTo(ciidExclude, rgiidExclude, snbExclude, dest.GetIStorage());
}

//
//
//
HRESULT
TOcStorage::MoveElementTo(char const far* name, TOcStorage& dest, char const far* newName, uint32 flags)
{
  return StorageI->MoveElementTo(OleStr(name), dest.GetIStorage(), OleStr(newName), flags);
}

//
//
//
HRESULT
TOcStorage::Commit(uint32 commitFlags)
{
  return StorageI->Commit(commitFlags);
}

//
//
//
HRESULT
TOcStorage::Revert()
{
  return StorageI->Revert();
}

//
//
//
HRESULT
TOcStorage::EnumElements(uint32 rsrvd1, void far* rsrvd2, uint32 rsrvd3, IEnumSTATSTG far*far* enm)
{
  return StorageI->EnumElements(rsrvd1, rsrvd2, rsrvd3, enm);
}

//
//
//
HRESULT
TOcStorage::DestroyElement(const char far* name)
{
  PRECONDITION(name);

  return StorageI->DestroyElement(OleStr(name));
}

//
//
//
HRESULT
TOcStorage::RenameElement(const char far* oldName, const char far* newName)
{
  return StorageI->RenameElement(OleStr(oldName), OleStr(newName));
}

//
//
//
HRESULT
TOcStorage::SetElementTimes(const char far* name, FILETIME const far* ctime, FILETIME const far* atime, FILETIME const far* mtime)
{
  return StorageI->SetElementTimes(OleStr(name), ctime, atime, mtime);
}

//
//
//
HRESULT
TOcStorage::SetClass(const IID far& clsid)
{
  return StorageI->SetClass(clsid);
}

//
//
//
HRESULT
TOcStorage::SetStateBits(uint32 stateBits, uint32 mask)
{
  return StorageI->SetStateBits(stateBits, mask);
}

//
//
//
HRESULT
TOcStorage::Stat(STATSTG far* statstg, uint32 statFlag)
{
  PRECONDITION(statstg);

  return StorageI->Stat(statstg, statFlag);
}

//
//
//
HRESULT
TOcStorage::SwitchToFile(const char far* newPath)
{
  if (!newPath)
    return HR_INVALIDARG;

  IRootStorage* rootStorageI;
  HRESULT hr = StorageI->QueryInterface(IID_IRootStorage, &(void far*)rootStorageI);
  if (HRSucceeded(hr)) {
    hr = rootStorageI->SwitchToFile(OleStr(const_cast<char far*>(newPath)));
    rootStorageI->Release();
  }
  return hr;
}

//
//
//
HRESULT
TOcStorage::CreateStream(const char far* name, uint32 mode, uint32 rsrvd1, uint32 rsrvd2, IStream far* far* stream)
{
  PRECONDITION(name);

  return StorageI->CreateStream(OleStr(name), mode, rsrvd1, rsrvd2, stream);
}

//
//
//
HRESULT
TOcStorage::OpenStream(const char far* name, void far *rsrvd1, uint32 mode, uint32 rsrvd2, IStream far*far* stream)
{
  PRECONDITION(name);

  return StorageI->OpenStream(OleStr(name), rsrvd1, mode, rsrvd2, stream);
}

//
//
//
HRESULT
TOcStorage::CreateStorage(const char far* name, uint32 mode, uint32 rsrvd1, uint32 rsrvd2, IStorage far*far* storage)
{
  PRECONDITION(StorageI && name);

  return StorageI->CreateStorage(OleStr(name), mode, rsrvd1, rsrvd2, storage);
}

//
//
//
HRESULT
TOcStorage::OpenStorage(const char far* name, IStorage far* stgPriority, uint32 mode, SNB snbExclude, uint32 rsrvd, IStorage far*far* storage)
{
  PRECONDITION(name);

  return StorageI->OpenStorage(OleStr(name), stgPriority, mode, snbExclude, rsrvd, storage);
}

//
//
//
HRESULT
TOcStorage::IsStorageFile(const char far* name)
{
  PRECONDITION(name);

  return ::StgIsStorageFile(OleStr(name));
}

//
//
//
HRESULT
TOcStorage::IsStorageILockBytes(ILockBytes far* lkbyt)
{
  PRECONDITION(lkbyt);

  return ::StgIsStorageILockBytes(lkbyt);
}

//
//
//
HRESULT
TOcStorage::SetTimes(char const far* name, FILETIME const far* ctime, FILETIME const far* atime, FILETIME const far* mtime)
{
  PRECONDITION(name);

  return ::StgSetTimes(OleStr(name), ctime, atime, mtime);
}

