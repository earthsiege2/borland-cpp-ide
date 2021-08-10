//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
// OLE Automation Client Implementation
//----------------------------------------------------------------------------
#include <ocf/ocfpch.h>
#include <ocf/autodefs.h>

TAutoProxyArgs::~TAutoProxyArgs()
{
  while (Count >= 0)
    ::VariantClear((VARIANT far*)((TAutoVal*)(this+1)+Count--));
}

void TAutoProxy::Bind(const char far* progid)
{
  PRECONDITION(progid);

  GUID guid;
  TXOle::Check(CLSIDFromProgID(OleStr(progid), &guid), progid);
  Bind(guid);
}

void TAutoProxy::Bind(const GUID& guid)
{
  IUnknown* unk;
  HRESULT stat = ::CoCreateInstance(guid,0,CLSCTX_SERVER,IID_IUnknown,(void FAR*FAR*)&unk);
  if (stat != HR_NOERROR) {
    char guidBuf[60];
    TClassId copy(guid);
    lstrcpy (guidBuf, copy);
    TXOle::Check(stat, guidBuf);
  }
  Bind(unk);
}

void TAutoProxy::Bind(IUnknown* unk)
{
  if (!unk)
    return;
  IDispatch* dsp;
  HRESULT stat = unk->QueryInterface(IID_IDispatch, (void FAR* FAR*)&dsp);
  unk->Release();
  TXOle::Check(stat, "IUnknown");
  Bind(dsp);
}

void TAutoProxy::Bind(IDispatch* dsp)
{
  Unbind();
  That = dsp;
}

void TAutoProxy::Bind(IUnknown& unk)
{
  IDispatch* dsp;
  TXOle::Check(unk.QueryInterface(IID_IDispatch, (void FAR* FAR*)&dsp), "IUnknown");
  Bind(dsp);
}

void TAutoProxy::Bind(IDispatch& obj)
{
  Unbind();
  obj.AddRef();
  That = &obj;
}

void TAutoProxy::Bind(TAutoVal& val)
{
  if (val.GetDataType() == atVoid)
    That = 0;
  else
    Bind((IDispatch&)val);  // throws exception if fails
}

void TAutoProxy::MustBeBound()
{
  if (!That)
    throw TXAuto(TXAuto::xNotIDispatch);
}

long TAutoProxy::Lookup(const char far* name)
{
  if (!name)
    name = "(null)";  // force controlled failure
  long id;

  MustBeBound();
#if defined(BI_OLECHAR_WIDE)
  TString tsname(name);
  wchar_t* wname = tsname;
  TXOle::Check(That->GetIDsOfNames(IID_NULL, &wname, 1, Lang, &id), name);
#else
  TXOle::Check(That->GetIDsOfNames(IID_NULL, &const_cast<char far*>(name), 1, Lang, &id), name);
#endif
  return id;
}

void TAutoProxy::Lookup(const char far* names, long* ids, unsigned count)
{
  MustBeBound();

#if defined(BI_OLECHAR_WIDE)
  const char far* pc = names;
  for (int i = 0; i < count; i++) {
    pc += strlen(pc) + 1;
  }
  wchar_t* wnames = TUString::ConvertAtoW(names, pc-names-1);
  wchar_t** args = new wchar_t far*[count];
  wchar_t* pw = wnames;
  for (i = 0; i < count; i++) {
    args[i] = pw;
    pw += lstrlenW(pw) + 1;
  }
  HRESULT stat = That->GetIDsOfNames(IID_NULL, args, count, Lang, ids);
  delete wnames;
#else
  char far** args = new char far*[count];
  const char far* pc = names;
  for (int i = 0; i < count; i++) {
    args[i] = (char far*)pc; // for non-unicode, names separated by null bytes
    pc += strlen(pc) + 1;
  }
  HRESULT stat = That->GetIDsOfNames(IID_NULL, args, count, Lang, ids);
#endif
  delete [] args;
  if (stat) {
    int bad = 0;
    if ((stat = HR_DISP_UNKNOWNNAME) != HR_NOERROR)
      while (bad < count && ids[bad] != DISPID_UNKNOWN) {
        bad++;
        names += (strlen(names) + 1);
      }
    TXOle::Check(stat, names);
  }
}

TAutoVal&
TAutoProxy::Invoke(uint16 attr, TAutoProxyArgs& args, long* ids, unsigned named)
{
  EXCEPINFO errinfo;
  unsigned int errarg;
  VARIANT far* retval = 0;

  MustBeBound();
  if (!(attr & (acPropSet | acVoidRet))) {
    retval = args;
    ::VariantInit(retval);
  }
  DISPID funcId = ids[0];
  DISPPARAMS params;
  params.cArgs = args;
  params.cNamedArgs = named;  
  params.rgvarg = args;
  params.rgdispidNamedArgs = ids;
  if (attr & acPropSet) {
    ids[0] = DISPID_PROPERTYPUT;
    params.cNamedArgs++;
    params.cArgs++;
  } else {
    params.rgdispidNamedArgs++;
    params.rgvarg++;
  }
  HRESULT stat = That->Invoke(funcId, IID_NULL, Lang,
                              uint16(attr & (acMethod | acPropSet | acPropGet)),
                              &params, retval, &errinfo, &errarg);
  ids[0] = funcId;         // restore function id incase PropSet
  if (stat != HR_NOERROR) {
    char buf[50];
    wsprintf(buf, "Invoke Id = %ld", funcId);
    TXOle::Check(stat, buf);
  }
  return args;
}

TAutoEnumeratorBase::TAutoEnumeratorBase(const TAutoEnumeratorBase& copy)
{
  Current.Copy(copy.Current);
  Iterator = copy.Iterator;
  if (Iterator)
    TXOle::Check(Iterator->Clone(&Iterator));
}

void TAutoEnumeratorBase::operator =(const TAutoEnumeratorBase& copy)
{
  Current.Copy(copy.Current);
  Unbind();
  Iterator = copy.Iterator;
  if (Iterator)
    TXOle::Check(Iterator->Clone(&Iterator));
}

void TAutoEnumeratorBase::Bind(TAutoVal& val)
{
  Unbind();
  IUnknown& unk = val;
  TXOle::Check(unk.QueryInterface(IID_IEnumVARIANT, (void far* far*) &Iterator),
               "_NewEnum");
}

bool TAutoEnumeratorBase::Step()
{
  Clear();
  if (!Iterator)
    TXOle::Check(HR_NOINTERFACE, "_NewEnum");
  else if (HRIsOK(Iterator->Next(1,(VARIANT far*)&Current,0)))
    return true;
  return false;
}

