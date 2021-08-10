[!outputon] // $Revision:   1.4.1.0.1.1  $
// [!HeaderName] : Declaration of the [!ClassName]

#ifndef [!IDEHeaderName]
#define [!IDEHeaderName]

[!if=(ThreadingModel, "Single")]
#define ATL_APARTMENT_THREADED
[!endif]
[!if=(ThreadingModel, "Apartment")]
#define ATL_APARTMENT_THREADED
[!endif]
[!if=(ThreadingModel, "Both")]
#define ATL_FREE_THREADED
[!endif]
[!if=(ThreadingModel, "Free")]
#define ATL_FREE_THREADED
[!endif]
[!if=(ThreadingModel, "Neutral")]
#define ATL_APARTMENT_THREADED
[!endif]

#include "[!TypeLibModuleName].H"
#include <asphlpr.h>

/////////////////////////////////////////////////////////////////////////////
// [!ClassName]     Implements [!InterfaceName], default interface of [!CoClassName]
// ThreadingModel : [!ThreadingModel]
// Dual Interface : [!Dual]
// Default ProgID : [!ProgID]
// Description    : [!Description]
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE [!ClassName] : 
[!if=(ThreadingModel, "Single")]
  public CComObjectRootEx<CComSingleThreadModel>,
[!endif]
[!if=(ThreadingModel, "Apartment")]
  public CComObjectRootEx<CComSingleThreadModel>,
[!endif]
[!if=(ThreadingModel, "Both")]
  public CComObjectRootEx<CComMultiThreadModel>,
[!endif]
[!if=(ThreadingModel, "Free")]
  public CComObjectRootEx<CComMultiThreadModel>,
[!endif]
[!if=(ThreadingModel, "Neutral")]
  public CComObjectRootEx<CComMultiThreadModel>,
[!endif]
  public CComCoClass<[!ClassName], &CLSID_[!CoClassName]>,
[!if=(Dual, "TRUE")]
  public IDispatchImpl<[!InterfaceName], &IID_[!InterfaceName], &LIBID_[!LibName]>,
[!else]
  public [!InterfaceName],
[!endif]
  public TASPObject
{
public:
  [!ClassName]()
  {
  }

  // Data used when registering Object 
  //
[!if=(ThreadingModel, "Single")]
  DECLARE_THREADING_MODEL(otSingle);
[!endif]
[!if=(ThreadingModel, "Apartment")]
  DECLARE_THREADING_MODEL(otApartment);
[!endif]
[!if=(ThreadingModel, "Free")]
  DECLARE_THREADING_MODEL(otFree);
[!endif]
[!if=(ThreadingModel, "Both")]
  DECLARE_THREADING_MODEL(otBoth);
[!endif]
[!if=(ThreadingModel, "Neutral")]
  DECLARE_THREADING_MODEL(otNeutral);
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
[!if=(Dual, "TRUE")]
  COM_INTERFACE_ENTRY2(IDispatch, [!InterfaceName])
[!endif]
END_COM_MAP()

// [!InterfaceName]
public:

};

#endif //[IDEHeaderName]
