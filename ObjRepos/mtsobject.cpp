[!outputon] // $Revision:   1.4.1.0  $
// [!CPPName] : Implementation of [!ClassName]

#include <vcl.h>
#pragma hdrstop

#include "[!HeaderName]"

/////////////////////////////////////////////////////////////////////////////
// [!ClassName]


[!if=(ObjectControl, "TRUE")]
STDMETHODIMP [!ClassName]::Activate()
{
  static TMtsDll Mts;
  HRESULT hr = E_FAIL;
  hr = Mts.Get_ObjectContext(&m_spObjectContext);
  if (SUCCEEDED(hr))
    return S_OK;
  return hr;
} 


STDMETHODIMP_(BOOL) [!ClassName]::CanBePooled()
{
[!if=(CanBePooled, "TRUE")]
  return TRUE;
[!else]
  return FALSE;
[!endif]
} 


STDMETHODIMP_(void) [!ClassName]::Deactivate()
{
  m_spObjectContext.Release();
} 

[!endif]
