[!outputon] // $Revision:   1.8.1.0.1.1  $
// [!HeaderName] : Declaration of the [!ClassName]

#ifndef [!IDEHeaderName]
#define [!IDEHeaderName]

[!if=(ThreadingModel, "tmSingle")]
#define ATL_APARTMENT_THREADED
[!endif]
[!if=(ThreadingModel, "tmApartment")]
#define ATL_APARTMENT_THREADED
[!endif]
[!if=(ThreadingModel, "tmBoth")]
#define ATL_FREE_THREADED
[!endif]
[!if=(ThreadingModel, "tmFree")]
#define ATL_FREE_THREADED
[!endif]
[!if=(ThreadingModel, "tmNeutral")]
#define ATL_APARTMENT_THREADED
[!endif]

#include "[!TypeLibModuleName].H"

#define _MTX_NOFORCE_LIBS
#include <vcl\mtshlpr.h>


/////////////////////////////////////////////////////////////////////////////
// [!ClassName]     Implements [!InterfaceName], default interface of [!CoClassName]
[!if=(ConnectionPointsEnabled, "TRUE")]
//                  and [!InterfaceName]Events, the default source interface
[!endif]
// ThreadingModel : [!ThreadingModel]
// Dual Interface : [!Dual]
// Event Support  : [!ConnectionPointsEnabled]
// Default ProgID : [!ProgID]
// Description    : [!Description]
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE [!ClassName] : 
[!if=(ThreadingModel, "tmSingle")]
  public CComObjectRootEx<CComSingleThreadModel>,
[!endif]
[!if=(ThreadingModel, "tmApartment")]
  public CComObjectRootEx<CComSingleThreadModel>,
[!endif]
[!if=(ThreadingModel, "tmBoth")]
  public CComObjectRootEx<CComMultiThreadModel>,
[!endif]
[!if=(ThreadingModel, "tmFree")]
  public CComObjectRootEx<CComMultiThreadModel>,
[!endif]
[!if=(ThreadingModel, "tmNeutral")]
  public CComObjectRootEx<CComMultiThreadModel>,
[!endif]
  public CComCoClass<[!ClassName], &CLSID_[!CoClassName]>,
[!if=(ObjectControl, "TRUE")]
  public IObjectControl,
[!endif]
[!if=(Dual, "TRUE")]
  public IDispatchImpl<[!InterfaceName], &IID_[!InterfaceName], &LIBID_[!LibName]>
[!else]
  public [!InterfaceName]
[!endif]
{
public:
  [!ClassName]()
  {
  }

  // Data used when registering Object 
  //
[!if=(ThreadingModel, "tmSingle")]
  DECLARE_THREADING_MODEL(otSingle);
[!endif]
[!if=(ThreadingModel, "tmApartment")]
  DECLARE_THREADING_MODEL(otApartment);
[!endif]
[!if=(ThreadingModel, "tmFree")]    // MTS does not support Free Threading Model (Default to Both)
  DECLARE_THREADING_MODEL(otBoth);
[!endif]
[!if=(ThreadingModel, "tmBoth")]
  DECLARE_THREADING_MODEL(otBoth);
[!endif]
  DECLARE_PROGID(_T(""));
  DECLARE_DESCRIPTION(_T("[!Description]"));

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<[!ClassName]> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }

DECLARE_NOT_AGGREGATABLE([!ClassName])

BEGIN_COM_MAP([!ClassName])
  COM_INTERFACE_ENTRY([!InterfaceName])
[!if=(ObjectControl, "TRUE")]
  COM_INTERFACE_ENTRY(IObjectControl)
[!endif]
[!if=(Dual, "TRUE")]
  COM_INTERFACE_ENTRY(IDispatch)
[!endif]
END_COM_MAP()

[!if=(ObjectControl, "TRUE")]
// IObjectControl
public:
  STDMETHOD(Activate)();
  STDMETHOD_(BOOL, CanBePooled)();
  STDMETHOD_(void, Deactivate)();

  CComPtr<IObjectContext> m_spObjectContext;

[!endif]
// [!InterfaceName]
public:

};

#endif //[!IDEHeaderName]
