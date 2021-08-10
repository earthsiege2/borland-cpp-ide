[!outputon] // $Revision:   1.12.1.5  $
[!if=(FreeThreadedMarshaler, "TRUE")]
  [!set(NeedsGetControllingUnknown, "TRUE")]
[!endif]
// [!HeaderName] : Declaration of the [!ClassName]

#ifndef [!IDEHeaderName]
#define [!IDEHeaderName]

#include "[!TypeLibModuleName].H"


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
[!if=(IObjectWithSite, "TRUE")]
  public IObjectWithSiteImpl<[!ClassName]>,
[!endif]
[!if=(ErrorInfoEnabled, "TRUE")]
  public ISupportErrorInfo,
[!endif]
[!if=(ConnectionPointsEnabled, "TRUE")]
  public IConnectionPointContainerImpl<[!ClassName]>,
  public TEvents_[!CoClassName]<[!ClassName]>, 
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
[!if=(FreeThreadedMarshaler, "TRUE")]
    m_pUnkMarshaler = NULL;
[!endif]
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
  DECLARE_PROGID("");
  DECLARE_DESCRIPTION("[!Description]");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<[!ClassName]> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


[!if=(Aggregatable, "NO")]
DECLARE_NOT_AGGREGATABLE([!ClassName])

[!endif]
[!if=(Aggregatable, "ONLY")]
DECLARE_ONLY_AGGREGATABLE([!ClassName])

[!endif]
[!if=(NeedsGetControllingUnknown, "TRUE")]
DECLARE_GET_CONTROLLING_UNKNOWN()

[!endif]
BEGIN_COM_MAP([!ClassName])
  COM_INTERFACE_ENTRY([!InterfaceName])
[!if=(Dual, "TRUE")]
  COM_INTERFACE_ENTRY2(IDispatch, [!InterfaceName])
[!endif]
[!if=(ErrorInfoEnabled, "TRUE")]
  COM_INTERFACE_ENTRY(ISupportErrorInfo)
[!endif]
[!if=(ConnectionPointsEnabled, "TRUE")]
  COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
[!endif]
[!if=(FreeThreadedMarshaler, "TRUE")]
  COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
[!endif]
[!if=(IObjectWithSite, "TRUE")]
  COM_INTERFACE_ENTRY_IMPL(IObjectWithSite)
[!endif]
END_COM_MAP()

[!if=(ConnectionPointsEnabled, "TRUE")]
BEGIN_CONNECTION_POINT_MAP([!ClassName])
  CONNECTION_POINT_ENTRY(DIID_I[!CoClassName]Events)
END_CONNECTION_POINT_MAP()

[!endif]
[!if=(FreeThreadedMarshaler, "TRUE")]
  HRESULT FinalConstruct()
  {
    return CoCreateFreeThreadedMarshaler(GetControllingUnknown(), &m_pUnkMarshaler.p);
  }

  void FinalRelease()
  {
    m_pUnkMarshaler.Release();
  }

  CComPtr<IUnknown> m_pUnkMarshaler;

[!endif]
[!if=(ErrorInfoEnabled, "TRUE")]
// ISupportsErrorInfo
  STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

[!endif]
// [!InterfaceName]
public:

};

#endif //[!IDEHeaderName]
