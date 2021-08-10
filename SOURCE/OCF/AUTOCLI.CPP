//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.7  $
//
// OLE Automation Client Implementation
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#if !defined(OCF_AUTODEFS_H)
# include <ocf/autodefs.h>
#endif
#if !defined(SERVICES_MEMORY_H)
# include <services/memory.h>
#endif
#if !defined(CLASSLIB_POINTER_H)
# include <classlib/pointer.h>
#endif

TAutoProxyArgs::~TAutoProxyArgs()
{
}

//
//
void TAutoProxy::Bind(const char* progid)
{
  PRECONDITION(progid);

  GUID guid;
  TXOle::Check(CLSIDFromProgID(OleStr(progid), &guid), progid);
  Bind(guid);
}

//
//
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

//
//
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

//
//
void TAutoProxy::Bind(IDispatch* dsp)
{
  Unbind();
  That = dsp;
}

//
//
void TAutoProxy::Bind(IUnknown& unk)
{
  IDispatch* dsp;
  TXOle::Check(unk.QueryInterface(IID_IDispatch, (void FAR* FAR*)&dsp), "IUnknown");
  Bind(dsp);
}

//
//
void TAutoProxy::Bind(IDispatch& obj)
{
  Unbind();
  obj.AddRef();
  That = &obj;
}

//
//
void TAutoProxy::Bind(TAutoVal& val)
{
  if (val.GetDataType() == atVoid)
    That = 0;
  else
    // NOTE: The following call throws exception in case of failure
    //
    Bind((IDispatch&)val);
}

//
//
void TAutoProxy::MustBeBound()
{
  if (!That)
    TXAuto::Raise(TXAuto::xNotIDispatch);
}

//
//
IDispatch* TAutoProxy::GetObject(const char* progid)
{
  CLSID clsid;
  TXOle::Check(CLSIDFromProgID(OleStr(progid), &clsid));

  LPUNKNOWN  punk  = 0;
  LPDISPATCH pdisp = 0;
  HRESULT hr = GetActiveObject(clsid, 0, &punk);
  if (SUCCEEDED(hr)) {
    punk->QueryInterface(IID_IDispatch,
                         (void**)&pdisp);
    punk->Release();
  }
  return pdisp;
}

//
//
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
  int i;
  for (i = 0; i < count; i++) {
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

  delete[] args;
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
TAutoProxy::Invoke(uint16 attr, TAutoProxyArgs& args,
                   long* ids, unsigned named)
{
  // Check that we're bound
  //
  MustBeBound();

  VARIANT* retval = 0;
  if (!(attr & (acPropSet | acVoidRet))) {

    // NOTE: The first TAutoVal/VARIANT of TAutoProxyArgs (really TAutoArgs)
    //       is for the return value...
    retval = args;

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

  unsigned int errarg = 0;
  EXCEPINFO errinfo = {0};
  HRESULT stat = That->Invoke(funcId, IID_NULL, Lang,
                              uint16(attr & (acMethod | acPropSet | acPropGet)),
                              &params, retval, &errinfo, &errarg);

  // Restore function id incase PropSet
  //
  ids[0] = funcId;

  // Check for failure
  //
  if (stat != HR_NOERROR) {
    TAPointer<char> errMsg = new char[100];

    // Is there additional informatiol in the EXCEPINFO structure
    //
    if (stat == ResultFromScode(DISP_E_EXCEPTION)) {
      TString str(errinfo.bstrDescription);
      char *errDesc = errinfo.bstrDescription ? (char*)str : "";
      wsprintf(errMsg, "Invoke ID= %ld/%lX (%s) %s=%X", funcId, funcId,
                       errDesc,
                       errinfo.wCode ? "wCode" : "scode",
                       errinfo.wCode ? errinfo.wCode : errinfo.scode);
    }
    else if (stat == ResultFromScode(DISP_E_TYPEMISMATCH) ||
             stat == ResultFromScode(DISP_E_PARAMNOTFOUND)) {
      wsprintf(errMsg, "Invoke ID= %ld/%lX, arg Index:%d", funcId, funcId,
                        errarg);
    }
    else {
      wsprintf(errMsg, "Invoke Id= %ld/%lX", funcId, funcId);
    }
    TXOle::Check(stat, errMsg);
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

