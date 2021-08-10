// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// C++ TLBWRTR : $Revision:   1.0.1.3  $
// File generated on 1/24/2000 09:46:28 AM from Type Library described below.

// ************************************************************************ //
// Type Lib: d:\tlbgen\rampage\typelib\TypeLibraries\GRAPH9.olb (1)
// IID\LCID: {00020802-0000-0000-C000-000000000046}\0
// Helpfile: d:\tlbgen\rampage\typelib\TypeLibraries\VBAGRP9.CHM
// DepndLst: 
//   (1) v2.0 stdole, (D:\WINNT\System32\stdole2.tlb)
//   (2) v2.1 Office, (D:\msof2k\Office\mso9.dll)
//   (3) v4.0 StdVCL, (D:\tlbgen\rampage\typelib\typelibraries\testing\stdvcl40.tlb)
// Errors:
//   Hint: Symbol 'IFont' renamed to 'GraphIFont'
//   Hint: Symbol 'Application' renamed to 'GraphApplication'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'IFont' renamed to 'GraphIFont'
//   Hint: Symbol 'Application' renamed to 'GraphApplication'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'RGB' renamed to 'rgb'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "Graph_2K_SRVR.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Graph_2k
{

_GlobalPtr& TGlobal::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TGlobal::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TGlobal::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TGlobal::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TGlobal::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TGlobal::ConnectTo(_GlobalPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TGlobal::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_Global;
  sd.IntfIID = __uuidof(_Global);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}


};     // namespace Graph_2k


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Graph_2k_srvr
{

void __fastcall PACKAGE Register()
{
  // [1]
  TComponentClass cls_svr[] = {
                              __classid(Graph_2k::TGlobal)
                           };
  RegisterComponents("Servers", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Graph_2k_srvr
