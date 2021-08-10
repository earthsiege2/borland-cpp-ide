/**********************************************************************
 *                                                                    *
 * C++Builder ASP support                                             *
 * Copyright (c) 1999, 2002 Borland Software Corporation              *
 **********************************************************************/

//---------------------------------------------------------------------------
#ifndef __ASPHLPR_H_
#define __ASPHLPR_H_
//---------------------------------------------------------------------------

#pragma hdrstop

#define _MTX_NOFORCE_LIBS
#include <asptlb.h>
#include <mtx.h>

#pragma option push -b -w-inl

namespace AspHlpr
{
  class TASPObject
  {
    private:
      CComPtr<IRequest> m_Request;
      CComPtr<IResponse> m_Response;
      CComPtr<IApplicationObject> m_Application;
      CComPtr<ISessionObject> m_Session;
      CComPtr<IServer> m_Server;
    public:
      STDMETHODIMP OnStartPage(LPUNKNOWN AScriptingContext);
      STDMETHODIMP OnEndPage(void);
      __property IRequest* Request = {read = m_Request.p};
      __property IResponse* Response = {read = m_Response.p};
      __property IApplicationObject* Application = {read = m_Application.p};
      __property ISessionObject* Session = {read = m_Session.p};
      __property IServer* Server = {read = m_Server.p}; 
  };

  class TMTSASPObject
  {
    private:
      CComPtr<IObjectContext> m_spObjectContext;
      CComPtr<IRequest> m_Request;
      CComPtr<IResponse> m_Response;
      CComPtr<IApplicationObject> m_Application;
      CComPtr<ISessionObject> m_Session;
      CComPtr<IServer> m_Server;
      IObjectContext* getObjectContext(void);
      IRequest* GetRequest(void);
      IResponse* GetResponse(void);
      IApplicationObject* GetApplication(void);
      ISessionObject* GetSession(void);
      IServer* GetServer(void);
    public:
      TMTSASPObject();
      ~TMTSASPObject();
      __property IRequest* Request = {read = GetRequest};
      __property IResponse* Response = {read = GetResponse};
      __property IApplicationObject* Application = {read = GetApplication};
      __property ISessionObject* Session = {read = GetSession};
      __property IServer* Server = {read = GetServer};
      __property IObjectContext* ObjectContext = {read = getObjectContext};
  };
}; /* namespace AspHlpr */

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace AspHlpr;
#endif

#pragma option pop

#endif /* __ASPHLPR_H_ */
