// MYAUTOIMPL.H : Declaration of the TMyAutoImpl

#ifndef __MYAUTOIMPL_H_
#define __MYAUTOIMPL_H_

#include "autosrvr_TLB.H"


/////////////////////////////////////////////////////////////////////////////
// TMyAutoImpl     Implements IMyAuto, default interface of MyAuto
// ThreadingModel : Neutral
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : autosrvr.MyAuto
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TMyAutoImpl : 
  public CComObjectRootEx<CComMultiThreadModel>,
  public CComCoClass<TMyAutoImpl, &CLSID_MyAuto>,
  public IDispatchImpl<IMyAuto, &IID_IMyAuto, &LIBID_autosrvr>
{
public:
  TMyAutoImpl()
  {
  }

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otNeutral);
  DECLARE_PROGID("autosrvr.MyAuto");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TMyAutoImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TMyAutoImpl)
  COM_INTERFACE_ENTRY(IMyAuto)
  COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IMyAuto
public:

  STDMETHOD(get_MyProp(BSTR* Value));
  STDMETHOD(set_MyProp(BSTR Value));
  STDMETHOD(ShowDialog());

private:
  WideString FMyProp;
};

#endif //__MYAUTOIMPL_H_
