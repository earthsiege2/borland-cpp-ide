[!outputon] // $Revision:   1.9.1.0.1.2  $
// [!HeaderName] : Declaration of the [!CoClassName]

#ifndef [!IDEHeaderName]
#define [!IDEHeaderName]

#define ATL_FREE_THREADED
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MidConst.hpp>

#include "[!TypeLibModuleName].H"
#include <atl/atlvcl.h>


[!if=(MTSObject, "TRUE")]
#define _MTX_NOFORCE_LIBS
#include <mtx.h>
#include <vcl\mtshlpr.h>
[!endif]

[!if=(ObjectControl, "TRUE")]
// Forward ref. of IAppServer/IObjectControl implementor
[!else]
// Forward ref. of IAppServer implementor
[!endif]


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class T[!CoClassName] : public TCRemoteDataModule
{
__published:  // IDE-managed Components
private:      // User declarations
public:       // User declarations
  __fastcall T[!CoClassName](TComponent* Owner);

[!if=(ObjectControl, "TRUE")]
  Classes::TNotifyEvent FOnActivate;        // Expose IObjectControl.Activate as VCL event
  Classes::TNotifyEvent FOnDeactivate;      // Expose IObjectControl.Deactivate as VCL event
[!endif]
__published:
[!if=(ObjectControl, "TRUE")]
  __property Classes::TNotifyEvent OnActivate   = {read=FOnActivate,   write=FOnActivate};
  __property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate};
[!endif]
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE T[!CoClassName] *[!CoClassName];


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
[!if=(ObjectControl, "TRUE")]
class ATL_NO_VTABLE [!ClassName]: REMOTEDATAMODULE_IMPL([!ClassName], [!CoClassName], T[!CoClassName], [!InterfaceName]),
                                  public IObjectControl
[!if=(ConnectionPointsEnabled, "TRUE")]
                                 ,public IConnectionPointContainerImpl<[!ClassName]>,
                                  public TEvents_[!CoClassName]<[!ClassName]>
[!endif]
[!else]
class ATL_NO_VTABLE [!ClassName]: REMOTEDATAMODULE_IMPL([!ClassName], [!CoClassName], T[!CoClassName], [!InterfaceName])
[!if=(ConnectionPointsEnabled, "TRUE")]
                                 ,public IConnectionPointContainerImpl<[!ClassName]>,
                                  public TEvents_[!CoClassName]<[!ClassName]>
[!endif]
[!endif]
{
public:

BEGIN_COM_MAP([!ClassName])
[!if=(ObjectControl, "TRUE")]
  COM_INTERFACE_ENTRY(IObjectControl)
[!endif]
  RDMOBJECT_COM_INTERFACE_ENTRIES([!InterfaceName])
[!if=(ConnectionPointsEnabled, "TRUE")]
  COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
[!endif]
END_COM_MAP()

[!if=(ConnectionPointsEnabled, "TRUE")]
BEGIN_CONNECTION_POINT_MAP([!ClassName])
  CONNECTION_POINT_ENTRY(DIID_I[!CoClassName]Events)
END_CONNECTION_POINT_MAP()

[!endif]
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
  DECLARE_PROGID(_T(""));
  DECLARE_DESCRIPTION(_T("[!Description]"));

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TRemoteDataModuleRegistrar regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    // Disable these flags in order to disable use by socket or web connections.
    // Also set other flags to configure the behavior of your application server.
    // For more information, see atlmod.h and atlvcl.cpp.
    regObj.Singleton = false;
    regObj.EnableWeb = true;
    regObj.EnableSocket = true;
    return regObj.UpdateRegistry(bRegister);
  }

[!if=(ObjectControl, "TRUE")]
  // Inline methods to facilitate access to IObjectContext interface
  //
  void    SetComplete()       { m_spObjectContext->SetComplete();   } 
  void    SetAbort()          { m_spObjectContext->SetAbort();      }
  void    EnableCommit()      { m_spObjectContext->EnableCommit();  }
  void    DisableCommit()     { m_spObjectContext->DisableCommit(); }
  bool    IsInTransaction()   { return m_spObjectContext->IsInTransaction() != 0;  }
  bool    IsSecurityEnabled() { return m_spObjectContext->IsSecurityEnabled() != 0;}
  HRESULT IsCallerInRole(BSTR str, BOOL* bVal)    
  { 
    return m_spObjectContext->IsCallerInRole(str, bVal);   
  }
  bool    IsCallerInRole(BSTR str)
  {
    BOOL bVal;
    OLECHECK(IsCallerInRole(str, &bVal));
    return bVal != VARIANT_FALSE;
  }

// IObjectControl
public:
  STDMETHOD(Activate)();
  STDMETHOD_(BOOL, CanBePooled)();
  STDMETHOD_(void, Deactivate)();


  // Data member hold IObjectContext interface
  //
  CComPtr<IObjectContext> m_spObjectContext;
[!endif]

// [!InterfaceName]
protected:
};

#endif  // [!IDEHeaderName]

