/////////////////////////////////////////////////////////////////////////
//  COMHLPR.CPP
//
//  $Revision:   1.2.2.0.1.0  $
//  $Date:   25 Jan 2002 13:02:00  $
//
//  Copyright (c) 1999, 2002 Borland Software Corporation
//////////////////////////////////////////////////////////////////////////
#include <oleserver.hpp>
#include <utilcls.h>


HRESULT COMHlpr_ConnectEvents(REFIID eventsIID, IUnknown* server, IUnknown* sink, DWORD &cookie)
{
  HRESULT hr = E_NOINTERFACE;
  TComInterface<IConnectionPointContainer, &IID_IConnectionPointContainer> pCPC;
  pCPC = server;
  if (pCPC)
  {
    TComInterface<IConnectionPoint, &IID_IConnectionPoint> pCP;
    hr = pCPC->FindConnectionPoint(eventsIID, &pCP);
    if (SUCCEEDED(hr))
      if (pCP)
        hr = pCP->Advise(sink, &cookie);
  }
  return hr;
}


HRESULT COMHlpr_DisconnectEvents(REFIID eventsIID, IUnknown* server, DWORD &cookie)
{
  if (cookie == 0)
    return CONNECT_E_NOCONNECTION;
  HRESULT hr = E_NOINTERFACE;
  TComInterface<IConnectionPointContainer, &IID_IConnectionPointContainer> pCPC;
  pCPC = server;
  if (pCPC)
  {
    TComInterface<IConnectionPoint, &IID_IConnectionPoint> pCP;
    hr = pCPC->FindConnectionPoint(eventsIID, &pCP);
    if (SUCCEEDED(hr))
      if (pCP)
        hr = pCP->Unadvise(cookie);
    if (SUCCEEDED(hr))
      cookie = 0;
  }
  return hr;
}




