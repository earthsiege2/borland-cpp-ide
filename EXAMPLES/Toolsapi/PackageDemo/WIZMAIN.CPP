//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <toolsapi.hpp>

#include "wizmain.h"
#include "formmain.h"

//---------------------------------------------------------------------------
/* IUnknown */
HRESULT STDMETHODCALLTYPE TPackageServices::QueryInterface(REFIID riid,
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
ULONG STDMETHODCALLTYPE TPackageServices::AddRef(void)
{
  return InterlockedIncrement(&m_Count);
};
//---------------------------------------------------------------------------
ULONG STDMETHODCALLTYPE TPackageServices::Release(void)
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
void __fastcall TPackageServices::AfterSave(void)
{
};
//---------------------------------------------------------------------------
void __fastcall TPackageServices::BeforeSave(void)
{
};
//---------------------------------------------------------------------------
void __fastcall TPackageServices::Destroyed(void)
{
};
//---------------------------------------------------------------------------
void __fastcall TPackageServices::Modified(void)
{
};
//---------------------------------------------------------------------------
/* IOTAWizard */
AnsiString __fastcall TPackageServices::GetIDString(void)
{
  return "Borland.PackageServices.Demo.1"; /* do not localize */
};
//---------------------------------------------------------------------------
AnsiString __fastcall TPackageServices::GetName(void)
{
  return "Borland.PackageServices.Demo"; /* do not localize */
};
//---------------------------------------------------------------------------
TWizardState __fastcall TPackageServices::GetState(void)
{
  TWizardState Result;
  Result << wsEnabled;
  return Result;
};
//---------------------------------------------------------------------------
void __fastcall TPackageServices::Execute(void)
{
  int i;       
  _di_IOTAPackageServices Temp;
  HRESULT hr;
  TPackageForm *Form = new TPackageForm(NULL);

  if (BorlandIDEServices != NULL)
  {
    __try
    {
      hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAPackageServices), (void **)&Temp);
      if (SUCCEEDED(hr))
      {
        for (i = 0; i < Temp->GetPackageCount(); i++)
          Form->ListBox1->Items->Add(Temp->PackageNames[i]);

        Form->ShowModal();
      }
    }
    __finally
    {
      delete Form;
    }
  }
};
//---------------------------------------------------------------------------
/* IOTAMenuWizard */
AnsiString __fastcall TPackageServices::GetMenuText(void)
{
  return "Test Package Services";
};
//---------------------------------------------------------------------------

#pragma package(smart_init)
