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

// C++ TLBWRTR : $Revision:   1.0.1.0.1.2  $
// File generated on 1/29/2002 1:28:06 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office10\msoutl.olb (1)
// LIBID: {00062FFF-0000-0000-C000-000000000046}
// LCID: 0
// Helpfile: c:\program files\microsoft office\office10\VBAOL10.CHM
// HelpString: Microsoft Outlook 10.0 Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v2.2 Office, (C:\Program Files\Common Files\Microsoft Shared\Office10\MSO.DLL)
// Errors:
//   Hint: Symbol 'Application' renamed to 'OutlookApplication'
//   Hint: Symbol 'Application' renamed to 'OutlookApplication'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <oleserver.hpp>
#include <dbolectl.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "Outlook_XP_srvr.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Outlook_xp
{

_ApplicationPtr& TOutlookApplication::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TOutlookApplication::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TOutlookApplication::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TOutlookApplication::Disconnect()
{
  if (m_DefaultIntf) {
    Quit();
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TOutlookApplication::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TOutlookApplication::ConnectTo(_ApplicationPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TOutlookApplication::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_OutlookApplication;
  sd.IntfIID = __uuidof(_Application);
  sd.EventIID= __uuidof(ApplicationEvents_10);
  ServerData = &sd;
}

void __fastcall TOutlookApplication::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61442: {
      if (OnItemSend) {
        (OnItemSend)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61443: {
      if (OnNewMail) {
        (OnNewMail)(this);
      }
      break;
      }
    case 61444: {
      if (OnReminder) {
        (OnReminder)(this, TVariant(params[0]));
      }
      break;
      }
    case 61445: {
      if (OnOptionsPagesAdd) {
        (OnOptionsPagesAdd)(this, (Outlook_xp::PropertyPages*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnStartup) {
        (OnStartup)(this);
      }
      break;
      }
    case 61447: {
      if (OnQuit) {
        (OnQuit)(this);
      }
      break;
      }
    case 64106: {
      if (OnAdvancedSearchComplete) {
        (OnAdvancedSearchComplete)(this, (Outlook_xp::Search*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 64107: {
      if (OnAdvancedSearchStopped) {
        (OnAdvancedSearchStopped)(this, (Outlook_xp::Search*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 64144: {
      if (OnMAPILogonComplete) {
        (OnMAPILogonComplete)(this);
      }
      break;
      }
    default:
      break;
  }
}


};     // namespace Outlook_xp


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Outlook_xp_srvr
{

void __fastcall PACKAGE Register()
{
  // [1]
  TComponentClass cls_svr[] = {
                              __classid(Outlook_xp::TOutlookApplication)
                           };
  RegisterComponents("OfficeXP", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Outlook_xp_srvr
