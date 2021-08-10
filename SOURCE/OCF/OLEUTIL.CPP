//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   OLE Utility class implementations
//----------------------------------------------------------------------------
#include <ocf/ocfpch.h>
#include <ocf/ocdefs.h>
#include <osl/ustring.h>

DIAG_DEFINE_GROUP(OcRefCount, true, 1);

#if defined(BI_PLAT_WIN16)
const char OleErrorStringsDLL[] = "OLE_ERR.DLL";
#else
const char OleErrorStringsDLL[] = "OLE_ERRF.DLL";
#endif 


TXOle::~TXOle()
{
}

TXOle* TXOle::Clone()
{
  return new TXOle(*this);
}

void TXOle::Throw()
{
  THROW( *this );
}
 
void TXOle::Check(HRESULT hr, const char far* msg)
{
  if (FAILED(hr))
    Throw(hr, msg);
}

void TXOle::Check(HRESULT hr)
{
  Check(hr, 0);
}

void TXOle::Throw(HRESULT hr, const char far* msg)
{
  if (!InstanceCount) {
    char buf[128+1];
    wsprintf(buf, "%s failed, ", msg ? msg : "OLE call");

    int len = strlen(buf);
    OleErrorFromCode(hr, buf + len, sizeof buf - len - 2);
    strcat(buf, ".");

    WARN(hr != HR_NOERROR, buf);
    throw TXOle(buf, hr);
  }
}

//
// If OLE-Error-String DLL exists, & msg string is there, then use
// it. Otherwise just use the number.
//
void TXOle::OleErrorFromCode(HRESULT stat, char far* buffer, int size)
{
  const   char HResultToStringIDFunc[] = "StringIDFromHResult";
  typedef int _export CALLBACK (*TStringIDFromHResult)(HRESULT hr);

  int len = 0;  
  OFSTRUCT ofs;
  if (OpenFile(OleErrorStringsDLL, &ofs, OF_EXIST) != HFILE_ERROR) {
    HINSTANCE hInst = LoadLibrary(OleErrorStringsDLL);
    if (hInst > (HINSTANCE)HINSTANCE_ERROR) {
      TStringIDFromHResult func =
          (TStringIDFromHResult)GetProcAddress(hInst, HResultToStringIDFunc);
      if (func) {
        int id = func(stat);
        if (id)
          len = ::LoadString(hInst, id, buffer, size);        
      }
      FreeLibrary(hInst);
    }
  }
  if (!len) {
    char numBuf[25];
    wsprintf(numBuf, "ErrorCode: %8lX", stat);
    strncat(buffer, numBuf, size - strlen(buffer) - 1);
  }
  buffer[size-1] = 0;
}

//----------------------------------------------------------------------------

void far*
TOleAllocator::Alloc(unsigned long size)
{
  void far* blk = Mem->Alloc(size);
  OLECALL(blk ? 0 : HR_OUTOFMEMORY, "IMalloc::Alloc");
  return blk;
}

//____________________________________________________________________________
//
// TClassId - GUID/IID/CLSID management implementation
//____________________________________________________________________________

TClassId::TClassId(const char far* idtxt) : Text(0)
{
  PRECONDITION(idtxt);

  OLECALL(::CLSIDFromString(OleStr((char far*)idtxt), &Guid), "Invalid GUID string");
}

TClassId::TClassId(const GUID far& guid, int offset) : Text(0), Guid(guid)
{
  Guid.Data1 += (long)offset;
}

TClassId::TClassId(TGenerate) : Text(0)
{
  OLECALL(::CoCreateGuid(&Guid), "CoCreateGuid");
}

TClassId::~TClassId()
{
  delete const_cast<char*>(Text);
}

TClassId::operator const char*()
{
  if (!Text) {
    Text = new char[38+1];
    wsprintf(const_cast<char*>(Text),
             "{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
             Guid.Data1, Guid.Data2, Guid.Data3,
             Guid.Data4[0], Guid.Data4[1], Guid.Data4[2], Guid.Data4[3],
             Guid.Data4[4], Guid.Data4[5], Guid.Data4[6], Guid.Data4[7]);
  }
  return Text;
}

TBaseClassId::TBaseClassId(const GUID far& guid, int maxAlloc)
             : TClassId(guid), MaxAlloc(maxAlloc), Offset(0) {}

TBaseClassId::TBaseClassId(const char far* idtxt, int maxAlloc)
             : TClassId(idtxt), MaxAlloc(maxAlloc), Offset(0) {}

TBaseClassId::TBaseClassId(TGenerate e, int maxAlloc)
             : TClassId(e), MaxAlloc(maxAlloc), Offset(0) {}

TBaseClassId::TBaseClassId(TRegList& regInfo, int maxAlloc)
             : TClassId(), MaxAlloc(maxAlloc), Offset(0)
{
  const char* str = regInfo["clsid"];
  // must check for valid clasid, else generate??  
  if (!str)
    OLECALL(HR_CLASS_CLASSNOTAVAILABLE, "Missing REGDATA clsid");
  OLECALL(::CLSIDFromString(OleStr((char far*)str), &Guid), "Invalid GUID string");
}

TClassId TBaseClassId::operator [](int offset)
{
  if(offset > Offset)
    OLECALL(HR_CLASS_CLASSNOTAVAILABLE, "Unassigned GUID");
  return TClassId(Guid, offset);
}

int TBaseClassId::AllocId()
{
  ++Offset;
  if(Offset >= MaxAlloc)
    OLECALL(HR_CLASS_CLASSNOTAVAILABLE, "GUID allocation exhausted");
  return Offset;
}

int TBaseClassId::GetOffset(const GUID far& guid)
{
  unsigned long offset = guid.Data1 - Guid.Data1;
  if ( offset >= (unsigned long)Offset &&
       ((long far*)&guid)[1] == ((long*)&Guid)[1] &&
       ((long far*)&guid)[2] == ((long*)&Guid)[2] &&
       ((long far*)&guid)[3] == ((long*)&Guid)[3] )
    return int(offset);
  else
    return -1;
}

//____________________________________________________________________________
//
// GUID compare routines use by implementations of IUnknown::QueryInterface
//       the low-order long word is verifed before calling these routines
//       success is indicated by virtue of assigment of the returned interface
//____________________________________________________________________________

void CmpGuid12(IUnknown* obj, REFIID req, REFIID ref, void far*far* pif)
{
  if ( ((long far*)&req)[1] == ((long far*)&ref)[1] &&
       ((long far*)&req)[2] == ((long far*)&ref)[2] &&
       ((long far*)&req)[3] == ((long far*)&ref)[3] ) {
    *pif = obj;
    obj->AddRef();
  }
} 

void CmpGuidOle(IUnknown* obj, REFIID req, void far*far* pif)
{
  if ( ((long far*)&req)[1] == 0x00000000L &&
       ((long far*)&req)[2] == 0x000000C0L &&
       ((long far*)&req)[3] == 0x46000000L ) {
    *pif = obj;
    obj->AddRef();
  }
}

//____________________________________________________________________________
//
// TUnknown - standard implementation of IUnknown
//____________________________________________________________________________

//
// Handy container to help watch COM object lifetime when debugging
//
#if (__DEBUG >= 2)
# include <classlib/bags.h>
  typedef TBagAsVector<TUnknown*> TUnknownBag;
  TUnknownBag* UnknownBag;
#endif

TUnknown::TUnknown() : Outer(&I)
{
#if (__DEBUG >= 2)
  if (!UnknownBag)
    UnknownBag = new TUnknownBag(100);
  UnknownBag->Add(this);
#endif
}

IUnknown& TUnknown::Aggregate(TUnknown& inner)
{
  if (I.Inner)
    return I.Inner->Aggregate(inner);
  ((IUnknown&)inner).AddRef();
  I.Inner = &inner;
  return *Outer;
}

TUnknown::~TUnknown()
{ 
#if (__DEBUG >= 2)
  UnknownBag->Detach(this);
#endif
  TRACEX(OcRefCount, 1,
         "~TUnknown() @" << (void*)this << ", RefCnt:" << I.RefCnt);
  WARNX(OcRefCount, I.RefCnt != 0, 0,
        "~TUnknown() @ " << (void*)this << ", RefCnt:" << I.RefCnt);

  // deleted by TUnknownI member
}

//
// QueryObject used when TUnknown is in constructor/destructor
//
HRESULT
TUnknown::QueryObject(const GUID far& /*iid*/, void far* far* /*pif*/)
{
  return ResultFromScode(E_NOINTERFACE);
}

HRESULT _IFUNC
TUnknown::TUnknownI::QueryInterface(const GUID far& iid, void far* far* pif)
{
  *pif = 0;
  if (iid.Data1 == 0) { // IID_IUnknown.Data1
    CmpGuidOle(this, iid, pif);
    if (*pif)
      return NOERROR;
  }
  if (Host().QueryObject(iid, pif) == NOERROR)
    return NOERROR;
  if (Inner)
    return Inner->ThisUnknown().QueryInterface(iid, pif);
  else
    return ResultFromScode(E_NOINTERFACE);
}

unsigned long _IFUNC
TUnknown::TUnknownI::AddRef()
{
  TRACEX(OcRefCount, 2,
         "AddRef on " << (void*)&Host() << " to " << (RefCnt+1));
  return ++RefCnt;
}

unsigned long _IFUNC
TUnknown::TUnknownI::Release()
{
  TRACEX(OcRefCount, 2,
         "Release on " << (void*)&Host() << " to " << (RefCnt-1));
  if (--RefCnt != 0)
    return RefCnt;
  if (Inner) {
    Inner->ThisUnknown().Release();
    Inner = 0;
  }
  delete &Host();
  return 0;
}

unsigned long
TUnknown::GetRefCount()
{
  if (Outer == &I)
    return I.RefCnt;
  Outer->AddRef();
  return Outer->Release();
}

TUnknown::TUnknownI::~TUnknownI()
{
  if (RefCnt)             // in case destructor called before RefCnt goes to 0
    ::CoDisconnectObject(this,0);// OLE will try to remove external references
}

//____________________________________________________________________________
//
// TLocaleString wrapper method replacements using OLE2 NLS functions for Win16
//____________________________________________________________________________

#if defined(BI_PLAT_WIN16)

TLangId
TLocaleString::GetSystemLangId()
{
  return ::GetSystemDefaultLangID();
}

TLangId
TLocaleString::GetUserLangId()
{
  return ::GetUserDefaultLangID();
}

int
TLocaleString::CompareLang(const char far* s1, const char far* s2, TLangId lang)
{
  return ::CompareStringA(lang, NORM_IGNORECASE | NORM_IGNORENONSPACE,
                          s1,-1, s2,-1) - 2;
}

#endif
