//---------------------------------------------------------------------------
#ifndef WizMainH
#define WizMainH

#include <sysutils.hpp>
#include <toolsapi.hpp>

class TPackageServices : public IOTAMenuWizard
{
  private:
    int FIndex;
    long m_Count;
  public:
    /* IUnknown */
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,
                                                     void __RPC_FAR *__RPC_FAR *ppvObject);
    virtual ULONG STDMETHODCALLTYPE AddRef( void);
    virtual ULONG STDMETHODCALLTYPE Release( void);
    /* IOTANotifier */
    virtual void __fastcall AfterSave(void);
    virtual void __fastcall BeforeSave(void);
    virtual void __fastcall Destroyed(void);
    virtual void __fastcall Modified(void);
    /* IOTAWizard */
    virtual AnsiString __fastcall GetIDString(void);
    virtual AnsiString __fastcall GetName(void);
    virtual TWizardState __fastcall GetState(void);
    virtual void __fastcall Execute(void);
    /* IOTAMenuWizard */
    virtual AnsiString __fastcall GetMenuText(void);
    __property int Index = {read=FIndex, write=FIndex};

    TPackageServices() : m_Count(0)
    {
    }
    virtual ~TPackageServices(void)
    {
    }
};

//---------------------------------------------------------------------------
#endif
