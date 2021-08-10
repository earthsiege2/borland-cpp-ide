/////////////////////////////////////////////////////////////////////////
//  MTSHLPR.CPP -- transparent support for MTS and COM+
//
//  $Revision:   1.3.1.0.1.1  $
//  $Date:   25 Jan 2002 13:02:00  $
//
//  Copyright (c) 1999, 2002 Borland Software Corporation
//////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <sysutils.hpp>
#include "mtshlpr.h"
#include "mtshlpr.rh"

#pragma resource "mtshlpr.res"

#define COMPLUS 0
#define MTS 1
#define NOTSUPPORTED 1000

#undef GetObjectContext

TMtsDll::TMtsDll() 
{
  bool init = init_com();
  if (!init) { init = init_mts(); }
  if (!init) { throw Exception(LoadStr(sInitMTSServicesError)); }
}

TMtsDll::~TMtsDll()
{
  if (Library) delete Library;
}

bool TMtsDll::init_com() 
{
  TDll* comservices = new TDll("comsvcs.dll"); /* do not localize */
  HINSTANCE success = comservices->operator HINSTANCE ();
  if (success)
  {
    delete comservices;
    comservices = new TDll("ole32.dll"); /* do not localize */
    success = comservices->operator HINSTANCE();
  }
  if (success)
  {
    Library = comservices;
    Type = COMPLUS;
    return true;
  } else {
    delete comservices;
    return false;
  }
}

bool TMtsDll::init_mts()
{
  TDll* mtsservices = new TDll("mtxex.dll"); /* do not localize */
  HINSTANCE success = mtsservices->operator HINSTANCE();
  if (success)
  {
    Library = mtsservices;
    Type = MTS;
    return true;
  } else {
    delete mtsservices;
    return false;
  }
}

HRESULT TMtsDll::Get_ObjectContext(IObjectContext** ppInstanceContext)
{
  switch(Type) 
  {
    case COMPLUS :
    {
      TDllStdProc2<REFIID, IObjectContext**> BGetObjectContext(*Library, _T("CoGetObjectContext")); /* do not localize */
      HRESULT hr = E_FAIL;
      if (BGetObjectContext)
        hr = BGetObjectContext(IID_IObjectContext, ppInstanceContext);
      return hr;
    }
    case MTS :
    {
      TDllProc1<IObjectContext**> BGetObjectContext(*Library, _T("GetObjectContext")); /* do not localize */
      HRESULT hr = E_FAIL;
      if (BGetObjectContext)
        hr = BGetObjectContext(ppInstanceContext);
      return hr;
    }
    default :
    {
      throw Exception(LoadStr(sLoadMTSServicesError));
    }
  }
}

void* TMtsDll::SafeRef(REFIID rid, IUnknown* pUnknown)
{
  switch(Type)
  {
    case COMPLUS:
    {
      pUnknown->AddRef();
      return pUnknown; 
    }
    case MTS:
    {
      TDllProc2<REFIID, void*> BSafeRef(*Library, _T("SafeRef")); /* do not localize */
      if (BSafeRef)
        return BSafeRef(rid, pUnknown);
      else
        return 0;
    }
    default :
    {
      throw Exception(LoadStr(sLocateMTSServicesError));
    }
  }
}

extern long LockMode_SetGet = LockSetGet;
extern long LockMode_LockMethod = LockMethod;
extern long ReleaseMode_Standard = Standard;
extern long ReleaseMode_Process = Process;
