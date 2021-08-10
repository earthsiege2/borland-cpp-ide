// EDITSERVERIMPL.H : Declaration of the TEditServerImpl

#ifndef __EDITSERVERIMPL_H_
#define __EDITSERVERIMPL_H_

#include "autosrv_TLB.H"


/////////////////////////////////////////////////////////////////////////////
// TEditServerImpl     Implements IEditServer, default interface of EditServer
// ThreadingModel : Neutral
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : autosrv.EditServer
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TEditServerImpl : 
  public CComObjectRootEx<CComMultiThreadModel>,
  public CComCoClass<TEditServerImpl, &CLSID_EditServer>,
  public IDispatchImpl<IEditServer, &IID_IEditServer, &LIBID_autosrv>
{
public:
  TEditServerImpl()
  {
  }

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otNeutral);
  DECLARE_PROGID("autosrv.EditServer");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TEditServerImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TEditServerImpl)
  COM_INTERFACE_ENTRY(IEditServer)
  COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IEditServer
public:
 
  STDMETHOD(Clear());
  STDMETHOD(SetThreeStr(BSTR s1, BSTR s2, BSTR s3, BSTR* result));
  STDMETHOD(get_EditNum(int* Value));
  STDMETHOD(get_EditStr(BSTR* Value));
  STDMETHOD(set_EditNum(int Value));
  STDMETHOD(set_EditStr(BSTR Value));
};

#endif //__EDITSERVERIMPL_H_
