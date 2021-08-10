//---------------------------------------------------------------------------

#ifndef FiltersH
#define FiltersH

#include <sysutils.hpp>
#include <toolsapi.hpp>

//---------------------------------------------------------------------------
class TPreprocessFilter: public IOTAToolsFilterNotifier
{
  protected:
    long m_Count;
  public:
    int FilterID;
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
    /* IOTAToolsFilterNotifiter */
  	virtual void __fastcall Filter(AnsiString FileName, int ErrorCode,
      Classes::TStrings* StdOut, Classes::TStrings* StdError);
  	virtual AnsiString __fastcall GetFilterName(void);

    __fastcall TPreprocessFilter() { m_Count = 0; FilterID = 0; };
    __fastcall virtual ~TPreprocessFilter() { };
};



extern TPreprocessFilter *PreprocessFilter;

#endif
