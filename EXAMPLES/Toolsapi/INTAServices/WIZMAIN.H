//---------------------------------------------------------------------------
#ifndef WizMainH
#define WizMainH

#include <sysutils.hpp>
#include <toolsapi.hpp>

#include "formmain.h"

class TNTAServices : public IOTAMenuWizard
{
  private:
    long m_Count;
    TDisplayForm *m_Form;
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
    /* IOTAWizard */
    virtual AnsiString __fastcall GetIDString(void);
    virtual AnsiString __fastcall GetName(void);
    virtual TWizardState __fastcall GetState(void);
    virtual void __fastcall Execute(void);
    /* IOTAMenuWizard */
    virtual AnsiString __fastcall GetMenuText(void);

    TNTAServices() : m_Form(new TDisplayForm(NULL))
    {
    }
    virtual ~TNTAServices()
    {
      delete m_Form;
    }
};

//---------------------------------------------------------------------------
#endif
