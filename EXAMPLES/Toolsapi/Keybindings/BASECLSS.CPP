//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "baseclss.h"
//---------------------------------------------------------------------------

namespace OTAClasses
{
  //---------------------------------------------------------------------------
  /* TOTAUnknown */
  HRESULT STDMETHODCALLTYPE TOTAUnknown::QueryInterface(REFIID riid,
                                    void __RPC_FAR *__RPC_FAR *ppvObject)
  {
    *ppvObject = NULL;

    if (IsEqualIID(riid, __uuidof(IUnknown)))
      *ppvObject = static_cast<IUnknown *>(this);

    if (*ppvObject)
    {
      reinterpret_cast<IUnknown *>(*ppvObject)->AddRef();
      return S_OK;
    }
    
    return E_NOINTERFACE;
  };
  //---------------------------------------------------------------------------
  ULONG STDMETHODCALLTYPE TOTAUnknown::AddRef(void)
  {
    return InterlockedIncrement(&m_Count);
  };
  //---------------------------------------------------------------------------
  ULONG STDMETHODCALLTYPE TOTAUnknown::Release(void)
  {
    if (InterlockedDecrement(&m_Count) == 0)
    {
      delete this;
      return 0;
    }
    return m_Count;
  };
  //---------------------------------------------------------------------------
  /* TOTANotifier */
  //---------------------------------------------------------------------------
  HRESULT STDMETHODCALLTYPE TOTANotifier::QueryInterface(REFIID riid,
                            void __RPC_FAR *__RPC_FAR *ppvObject)
  {
    *ppvObject = NULL;
    
    if (IsEqualIID(riid, __uuidof(IUnknown)))
      *ppvObject = static_cast<IUnknown *>(this);
    else if (IsEqualIID(riid, __uuidof(IOTANotifier)))
      *ppvObject = static_cast<IOTANotifier *>(this);

    if (*ppvObject)
    {
      reinterpret_cast<IUnknown *>(*ppvObject)->AddRef();
      return S_OK;
    }

    return E_NOINTERFACE;
  };
  //---------------------------------------------------------------------------
  ULONG STDMETHODCALLTYPE TOTANotifier::AddRef(void)
  {
    return InterlockedIncrement(&m_Count);
  };
  //---------------------------------------------------------------------------
  ULONG STDMETHODCALLTYPE TOTANotifier::Release(void)
  {
    if (InterlockedDecrement(&m_Count) == 0)
    {
      delete this;
      return 0;
    }
    return m_Count;
  };
  //---------------------------------------------------------------------------
  void __fastcall TOTANotifier::AfterSave(void)
  {
  };
  //---------------------------------------------------------------------------
  void __fastcall TOTANotifier::BeforeSave(void)
  {
  };
  //---------------------------------------------------------------------------
  void __fastcall TOTANotifier::Destroyed(void)
  {
  };
  //---------------------------------------------------------------------------
  void __fastcall TOTANotifier::Modified(void)
  {
  };
  //---------------------------------------------------------------------------
  /* TOTAKeyboardBinding */
  //---------------------------------------------------------------------------
  HRESULT STDMETHODCALLTYPE TOTAKeyboardBinding::QueryInterface(REFIID riid,
                                    void __RPC_FAR *__RPC_FAR *ppvObject)
  {
    *ppvObject = NULL;

    if (IsEqualIID(riid, __uuidof(IUnknown)))
      *ppvObject = static_cast<IUnknown *>(this);
    else if (IsEqualIID(riid, __uuidof(IOTANotifier)))
      *ppvObject = static_cast<IOTANotifier *>(this);
    else if (IsEqualIID(riid, __uuidof(IOTAKeyboardBinding)))
      *ppvObject = static_cast<IOTAKeyboardBinding *>(this);

    if (*ppvObject)
    {
      reinterpret_cast<IUnknown *>(*ppvObject)->AddRef();
      return S_OK;
    }

    return E_NOINTERFACE;
  };
  //---------------------------------------------------------------------------
  ULONG STDMETHODCALLTYPE TOTAKeyboardBinding::AddRef(void)
  {
    return InterlockedIncrement(&m_Count);
  };
  //---------------------------------------------------------------------------
  ULONG STDMETHODCALLTYPE TOTAKeyboardBinding::Release(void)
  {
    if (InterlockedDecrement(&m_Count) == 0)
    {
      delete this;
      return 0;
    }
    return m_Count;
  };
  //---------------------------------------------------------------------------
  void __fastcall TOTAKeyboardBinding::AfterSave(void)
  {
  };
  //---------------------------------------------------------------------------
  void __fastcall TOTAKeyboardBinding::BeforeSave(void)
  {
  };
  //---------------------------------------------------------------------------
  void __fastcall TOTAKeyboardBinding::Destroyed(void)
  {
  };
  //---------------------------------------------------------------------------
  void __fastcall TOTAKeyboardBinding::Modified(void)
  {
  };
  //---------------------------------------------------------------------------
  TBindingType __fastcall TOTAKeyboardBinding::GetBindingType(void)
  {
    return btPartial;
  };
  //---------------------------------------------------------------------------
  AnsiString __fastcall TOTAKeyboardBinding::GetDisplayName(void)
  {
    return "";
  };
  //---------------------------------------------------------------------------
  AnsiString __fastcall TOTAKeyboardBinding::GetName(void)
  {
    return "";
  };
  //---------------------------------------------------------------------------
  void __fastcall TOTAKeyboardBinding::BindKeyboard(const _di_IOTAKeyBindingServices BindingServices)
  {
  };
  //---------------------------------------------------------------------------
} /* namespace OTAClasses */

#pragma package(smart_init)
