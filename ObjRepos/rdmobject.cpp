[!outputon] // $Revision:   1.7  $
#include <vcl.h>
#pragma hdrstop

#include "[!HeaderName]"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"


/////////////////////////////////////////////////////////////////////////////
// Global instance of [!ClassName] 
/////////////////////////////////////////////////////////////////////////////
T[!CoClassName] *[!CoClassName];


/////////////////////////////////////////////////////////////////////////////
// T[!CoClassName]::T[!CoClassName]
/////////////////////////////////////////////////////////////////////////////
__fastcall T[!CoClassName]::T[!CoClassName](TComponent* Owner) : TCRemoteDataModule(Owner)
{
}


[!if=(ObjectControl, "TRUE")]
STDMETHODIMP [!ClassName]::Activate()
{
  // Retrieve ObjectContext
  //
  static TMtsDll Mts;
  HRESULT hr = E_FAIL;
  hr = Mts.Get_ObjectContext(&m_spObjectContext);

  // Fire 'OnActivate' Event 
  //
  if (m_DataModule->FOnActivate)
    m_DataModule->FOnActivate([!CoClassName]);

  if (SUCCEEDED(hr))
    return S_OK;
  return hr;
} 


STDMETHODIMP_(BOOL) [!ClassName]::CanBePooled()
{
[!if=(CanBePooled, "FALSE")]
  return FALSE;
[!else]
  return TRUE;
[!endif]
} 


STDMETHODIMP_(void) [!ClassName]::Deactivate()
{
  // Fire 'OnDeactivate' event 
  //
  if (m_DataModule->FOnDeactivate)
    m_DataModule->FOnDeactivate([!CoClassName]);

  // Release Object Context
  //
  m_spObjectContext.Release();
} 

[!endif]


