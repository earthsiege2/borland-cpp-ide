//---------------------------------------------------------------------------
#ifndef baseclssH
#define baseclssH
//---------------------------------------------------------------------------

#include <toolsapi.hpp>

namespace OTAClasses
{
  /* TOTAUnknown */
  class TOTAUnknown : public IUnknown
  {
    private:
      long m_Count;
    public:
      /* IUnknown */
      virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,
                                        void __RPC_FAR *__RPC_FAR *ppvObject);
      virtual ULONG STDMETHODCALLTYPE AddRef(void);
      virtual ULONG STDMETHODCALLTYPE Release(void);

      TOTAUnknown() :  m_Count(0)
      {
      }
      virtual ~TOTAUnknown(void)
      {
      }
  };

  /* TOTANotifier */
  class TOTANotifier : public IOTANotifier
  {
    private:
      long m_Count;
    public:
      /* IUnknown */
      virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,
                                        void __RPC_FAR *__RPC_FAR *ppvObject);
      virtual ULONG STDMETHODCALLTYPE AddRef(void);
      virtual ULONG STDMETHODCALLTYPE Release(void);
      /* IOTANotifier */
      virtual void __fastcall AfterSave(void);
      virtual void __fastcall BeforeSave(void);
      virtual void __fastcall Destroyed(void);
      virtual void __fastcall Modified(void);

      TOTANotifier() :  m_Count(0)
      {
      }
      virtual ~TOTANotifier(void)
      {
      }
  };

  /* TOTAKeyboardBinding */
  class TOTAKeyboardBinding : public IOTAKeyboardBinding
  {
    private:
      long m_Count;
    public:
      /* IUnknown */
      virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,
                                        void __RPC_FAR *__RPC_FAR *ppvObject);
      virtual ULONG STDMETHODCALLTYPE AddRef(void);
      virtual ULONG STDMETHODCALLTYPE Release(void);
      /* IOTANotifier */
      virtual void __fastcall AfterSave(void);
      virtual void __fastcall BeforeSave(void);
      virtual void __fastcall Destroyed(void);
      virtual void __fastcall Modified(void);
      /* IOTAKeyboardBinding */
      virtual TBindingType __fastcall GetBindingType(void);
      virtual AnsiString __fastcall GetDisplayName(void);
      virtual AnsiString __fastcall GetName(void);
      virtual void __fastcall BindKeyboard(const _di_IOTAKeyBindingServices BindingServices);

      TOTAKeyboardBinding() :  m_Count(0)
      {
      }
      virtual ~TOTAKeyboardBinding(void)
      {
      }
  };

} /* namespace OTAClasses */
#endif
