//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "wizmain.h"

//---------------------------------------------------------------------------
/* IUnknown */
HRESULT STDMETHODCALLTYPE TNTAServices::QueryInterface(REFIID riid,
                                           void __RPC_FAR *__RPC_FAR *ppvObject)
{
  *ppvObject = NULL;

  if (IsEqualIID(riid, __uuidof(IUnknown)))
    *ppvObject = static_cast<IUnknown *>(this);
  else if (IsEqualIID(riid, __uuidof(IOTANotifier)))
    *ppvObject = static_cast<IOTANotifier *>(this);
  else if (IsEqualIID(riid, __uuidof(IOTAWizard)))
    *ppvObject = static_cast<IOTAWizard *>(this);
  else if (IsEqualIID(riid, __uuidof(IOTAMenuWizard)))
    *ppvObject = static_cast<IOTAMenuWizard *>(this);

  if (*ppvObject != NULL)
  {
    reinterpret_cast<IUnknown *>(*ppvObject)->AddRef();
    return S_OK;
  }

  return E_NOINTERFACE; 
};
//---------------------------------------------------------------------------
ULONG STDMETHODCALLTYPE TNTAServices::AddRef(void)
{
  return InterlockedIncrement(&m_Count);
};
//---------------------------------------------------------------------------
ULONG STDMETHODCALLTYPE TNTAServices::Release(void)
{
  if (InterlockedDecrement(&m_Count) == 0)
  {
    delete this;
    return 0;
  }
  return m_Count;
};
//---------------------------------------------------------------------------
/* IOTANotifier */
void __fastcall TNTAServices::AfterSave(void)
{
};
//---------------------------------------------------------------------------
void __fastcall TNTAServices::BeforeSave(void)
{
};
//---------------------------------------------------------------------------
void __fastcall TNTAServices::Destroyed(void)
{
};
//---------------------------------------------------------------------------
void __fastcall TNTAServices::Modified(void)
{
};
//---------------------------------------------------------------------------
/* IOTAWizard */
AnsiString __fastcall TNTAServices::GetIDString(void)
{
  return "Borland.NTAServices.Demo.1"; /* do not localize */
};
//---------------------------------------------------------------------------
AnsiString __fastcall TNTAServices::GetName(void)
{
  return "Borland.NTAServices.Demo"; /* do not localize */
};
//---------------------------------------------------------------------------
TWizardState __fastcall TNTAServices::GetState(void)
{
  TWizardState Result;
  Result << wsEnabled;
  return Result;
};
//---------------------------------------------------------------------------
void __fastcall TNTAServices::Execute(void)
{
  m_Form->ShowModal();
};
//---------------------------------------------------------------------------
/* IOTAMenuWizard */
AnsiString __fastcall TNTAServices::GetMenuText(void)
{
  return "Test Native Services";
};
//---------------------------------------------------------------------------


#pragma package(smart_init) 
