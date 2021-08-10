//---------------------------------------------------------------------------
#include <vcl.h>

#define INITGUID
#include <objbase.h>
#include <initguid.h>
#include <utilcls.h>
#include <atlbase.h>
#include <asptlb.h>                                             
#include <mtx.h>

#include <mtshlpr.h>
#include <asphlpr.h>
//---------------------------------------------------------------------------

STDMETHODIMP TASPObject::OnStartPage(LPUNKNOWN AScriptingContext)
{
  HRESULT hResult;

  if (!AScriptingContext)
    return E_POINTER;

  CComQIPtr<IScriptingContext, &IID_IScriptingContext> AContext = AScriptingContext;

  if (!AContext)
    return E_NOINTERFACE;

  hResult = AContext->get_Request(&m_Request);
  if (SUCCEEDED(hResult))
  {
    hResult = AContext->get_Response(&m_Response);
    if (SUCCEEDED(hResult))
    {
      hResult = AContext->get_Server(&m_Server);
      if (SUCCEEDED(hResult))
      {
        hResult = AContext->get_Session(&m_Session);
        if (SUCCEEDED(hResult))
          hResult = AContext->get_Application(&m_Application);
      }
    }
  }

  if (FAILED(hResult))
  {
    if (m_Request)
      m_Request.Release();
    if (m_Response)
      m_Response.Release();
    if (m_Server)
      m_Server.Release();
    if (m_Session)
      m_Session.Release();
    if (m_Application)
      m_Application.Release();
  }

  return hResult;
};
//---------------------------------------------------------------------------
STDMETHODIMP TASPObject::OnEndPage()
{
  HRESULT hr = E_FAIL;

  ATLTRY
  (
    m_Request.Release();
    m_Response.Release();
    m_Application.Release();
    m_Session.Release();
    m_Server.Release();
    hr = S_OK;
  )

  return hr;
};
//---------------------------------------------------------------------------
IRequest* TMTSASPObject::GetRequest(void)
{
  return m_Request.p;
};
//---------------------------------------------------------------------------
IResponse* TMTSASPObject::GetResponse(void)
{
  return m_Response.p;
};
//---------------------------------------------------------------------------
IApplicationObject* TMTSASPObject::GetApplication(void)
{
  return m_Application.p;
};
//---------------------------------------------------------------------------
ISessionObject* TMTSASPObject::GetSession(void)
{
  return m_Session.p;
};
//---------------------------------------------------------------------------
IServer* TMTSASPObject::GetServer(void)
{
  return m_Server.p;
};
//---------------------------------------------------------------------------
TMTSASPObject::TMTSASPObject()
{
  CComPtr<IGetContextProperties> ContextProperties;
  HRESULT hr = E_FAIL;
  TVariant var;
  IUnknown* Temp;

  static TMtsDll Mts;
  // note: this will throw if MTS services are not available.
  hr = Mts.Get_ObjectContext(&m_spObjectContext);

  if (SUCCEEDED(hr))
  {
    hr = m_spObjectContext->QueryInterface(IID_IGetContextProperties, (void **)&ContextProperties);
    if (SUCCEEDED(hr))
    {
      hr = ContextProperties->GetProperty(OLESTR("Request"), var); /* do not localize */
      if (SUCCEEDED(hr))
      {
        Temp = var; /* conversion AddRefs, be sure to Release() */
        hr = Temp->QueryInterface(IID_IRequest, (void **)&m_Request);
        Temp->Release();
        if (SUCCEEDED(hr))
          hr = ContextProperties->GetProperty(OLESTR("Response"), var); /* do not localize */
        if (SUCCEEDED(hr))
        {
          Temp = var; /* conversion AddRefs, be sure to Release() */
          hr = Temp->QueryInterface(IID_IResponse, (void **)&m_Response);
          Temp->Release();
          if (SUCCEEDED(hr))
            hr = ContextProperties->GetProperty(OLESTR("Application"), var); /* do not localize */
          if (SUCCEEDED(hr))
          {
            Temp = var; /* conversion AddRefs, be sure to Release() */
            hr = Temp->QueryInterface(IID_IApplicationObject, (void **)&m_Application);
            Temp->Release();
            if (SUCCEEDED(hr))
              hr = ContextProperties->GetProperty(OLESTR("Session"), var); /* do not localize */
            if (SUCCEEDED(hr))
            {
              Temp = var; /* conversion AddRefs, be sure to Release() */
              hr = Temp->QueryInterface(IID_ISessionObject, (void **)&m_Session);
              Temp->Release();
              if (SUCCEEDED(hr))
                hr = ContextProperties->GetProperty(OLESTR("Server"), var); /* do not localize */
              if (SUCCEEDED(hr))
              {
                Temp = var; /* conversion AddRefs, be sure to Release() */
                hr = Temp->QueryInterface(IID_IServer, (void **)&m_Server);
                Temp->Release();
              }
            }
          }
        }
      }
    }
  }
};
//---------------------------------------------------------------------------
TMTSASPObject::~TMTSASPObject()
{
  ATLTRY
  (
    if (m_spObjectContext)
      m_spObjectContext.Release();
    if (m_Request)
      m_Request.Release();
    if (m_Response)
      m_Response.Release();
    if (m_Application)
      m_Application.Release();
    if (m_Session)
      m_Session.Release();
    if (m_Server)
      m_Server.Release();
  )
};
//---------------------------------------------------------------------------
IObjectContext* TMTSASPObject::getObjectContext(void)
{
  return m_spObjectContext.p;
};
//---------------------------------------------------------------------------

#pragma package(smart_init)
 
