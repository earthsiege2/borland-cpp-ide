//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "wizmain.h"
#include "frmmain.h"

//---------------------------------------------------------------------------
/* IUnknown */
HRESULT STDMETHODCALLTYPE TActionServices::QueryInterface(REFIID riid,
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
ULONG STDMETHODCALLTYPE TActionServices::AddRef(void)
{
  return InterlockedIncrement(&m_Count);
};
//---------------------------------------------------------------------------
ULONG STDMETHODCALLTYPE TActionServices::Release(void)
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
void __fastcall TActionServices::AfterSave(void)
{
};
//---------------------------------------------------------------------------
void __fastcall TActionServices::BeforeSave(void)
{
};
//---------------------------------------------------------------------------
void __fastcall TActionServices::Destroyed(void)
{
};
//---------------------------------------------------------------------------
void __fastcall TActionServices::Modified(void)
{
};
//---------------------------------------------------------------------------
/* IOTAWizard */
AnsiString __fastcall TActionServices::GetIDString(void)
{
  return "Borland.ActionServices.Demo.1"; /* do not localize */
};
//---------------------------------------------------------------------------
AnsiString __fastcall TActionServices::GetName(void)
{
  return "Borland.ActionServices.Demo"; /* do not localize */
};
//---------------------------------------------------------------------------
TWizardState __fastcall TActionServices::GetState(void)
{
  return TWizardState() << wsEnabled;
};
//---------------------------------------------------------------------------
void __fastcall TActionServices::Execute(void)
{
  m_Form->Show();
};
//---------------------------------------------------------------------------
/* IOTAMenuWizard */
AnsiString __fastcall TActionServices::GetMenuText(void)
{
  return "Test Action Services";
};
//---------------------------------------------------------------------------


#pragma package(smart_init)
