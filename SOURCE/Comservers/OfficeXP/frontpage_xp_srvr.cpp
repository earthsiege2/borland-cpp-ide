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

// C++ TLBWRTR : $Revision:   1.0.1.0.1.0  $
// File generated on 1/29/2002 1:29:49 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office10\frontpg.exe (1)
// LIBID: {3824BCD5-7042-11CE-8E17-0020AF9F9648}
// LCID: 0
// Helpfile: c:\program files\microsoft office\office10\vbafpw10.chm
// HelpString: Microsoft FrontPage 5.0 Web Object Reference Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v5.0 FrontPageEditor, (C:\PROGRA~1\MICROS~4\Office10\FPEDITAX.DLL)
//   (3) v2.2 Office, (C:\Program Files\Common Files\Microsoft Shared\Office10\MSO.DLL)
//   (4) v5.3 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB)
// Errors:
//   Hint: Symbol 'System' renamed to 'SYSTEM'
//   Hint: Symbol 'Application' renamed to 'App'
//   Hint: Symbol 'System' renamed to 'SYSTEM'
//   Hint: Symbol 'Application' renamed to 'App'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "FrontPage_XP_srvr.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Frontpage_xp
{

_ApplicationPtr& TApp::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TApp::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TApp::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TApp::Disconnect()
{
  if (m_DefaultIntf) {
    Quit();
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TApp::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TApp::ConnectTo(_ApplicationPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TApp::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_App;
  sd.IntfIID = __uuidof(_Application);
  sd.EventIID= __uuidof(_IApplicationEvents);
  ServerData = &sd;
}

void __fastcall TApp::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnWebNew) {
        (OnWebNew)(this, (Frontpage_xp::Web*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2: {
      if (OnWebOpen) {
        (OnWebOpen)(this, (Frontpage_xp::Web*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 3: {
      if (OnWebClose) {
        (OnWebClose)(this, (Frontpage_xp::Web*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 4: {
      if (OnBeforeWebPublish) {
        (OnBeforeWebPublish)(this, (Frontpage_xp::Web*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]));
      }
      break;
      }
    case 5: {
      if (OnAfterWebPublish) {
        (OnAfterWebPublish)(this, (Frontpage_xp::Web*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 6: {
      if (OnPageNew) {
        (OnPageNew)(this, (Frontpage_xp::PageWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 7: {
      if (OnPageOpen) {
        (OnPageOpen)(this, (Frontpage_xp::PageWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 8: {
      if (OnPageClose) {
        (OnPageClose)(this, (Frontpage_xp::PageWindow*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 9: {
      if (OnBeforePageSave) {
        (OnBeforePageSave)(this, (Frontpage_xp::PageWindow*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]));
      }
      break;
      }
    case 10: {
      if (OnAfterPageSave) {
        (OnAfterPageSave)(this, (Frontpage_xp::PageWindow*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 11: {
      if (OnWindowActivate) {
        (OnWindowActivate)(this, (Frontpage_xp::WebWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 12: {
      if (OnWindowDeactivate) {
        (OnWindowDeactivate)(this, (Frontpage_xp::WebWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 13: {
      if (OnBeforeWebWindowViewChange) {
        (OnBeforeWebWindowViewChange)(this, (Frontpage_xp::WebWindow*)(LPDISPATCH)TVariant(params[0]), (Frontpage_xp::FpWebViewModeEx)(int)TVariant(params[1]), TVariant(params[2]));
      }
      break;
      }
    case 14: {
      if (OnAfterWebWindowViewChange) {
        (OnAfterWebWindowViewChange)(this, (Frontpage_xp::WebWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 15: {
      if (OnRecalculateHyperlinks) {
        (OnRecalculateHyperlinks)(this, (Frontpage_xp::Web*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 16: {
      if (OnBeforePageWindowViewChange) {
        (OnBeforePageWindowViewChange)(this, (Frontpage_xp::PageWindow*)(LPDISPATCH)TVariant(params[0]), (Frontpage_xp::FpPageViewMode)(int)TVariant(params[1]), TVariant(params[2]));
      }
      break;
      }
    case 17: {
      if (OnAfterPageWindowViewChange) {
        (OnAfterPageWindowViewChange)(this, (Frontpage_xp::PageWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 18: {
      if (OnPageWindowActivate) {
        (OnPageWindowActivate)(this, (Frontpage_xp::PageWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 19: {
      if (OnWebFileCheckOut) {
        (OnWebFileCheckOut)(this, (Frontpage_xp::Web*)(LPDISPATCH)TVariant(params[0]), (Frontpage_xp::WebFile*)(LPDISPATCH)TVariant(params[1]), TVariant(params[2]), (Frontpage_xp::FpCheckOutOption*)(int*)TVariant(params[3]));
      }
      break;
      }
    case 20: {
      if (OnBeforeWebWindowSubViewChange) {
        (OnBeforeWebWindowSubViewChange)(this, (Frontpage_xp::WebWindow*)(LPDISPATCH)TVariant(params[0]), (Frontpage_xp::FpWebSubView)(int)TVariant(params[1]), TVariant(params[2]));
      }
      break;
      }
    case 21: {
      if (OnAfterWebWindowSubViewChange) {
        (OnAfterWebWindowSubViewChange)(this, (Frontpage_xp::WebWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

WebPtr& TWebEx::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TWebEx::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TWebEx::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TWebEx::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TWebEx::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TWebEx::ConnectTo(WebPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TWebEx::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_WebEx;
  sd.IntfIID = __uuidof(Web);
  sd.EventIID= __uuidof(_IWebEvents);
  ServerData = &sd;
}

void __fastcall TWebEx::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnBeforePublish) {
        (OnBeforePublish)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2: {
      if (OnAfterPublish) {
        (OnAfterPublish)(this, TVariant(params[0]));
      }
      break;
      }
    case 3: {
      if (OnRecalculateHyperlinks) {
        (OnRecalculateHyperlinks)(this, TVariant(params[0]));
      }
      break;
      }
    case 4: {
      if (OnWebFileCheckOut) {
        (OnWebFileCheckOut)(this, (Frontpage_xp::WebFile*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]), (Frontpage_xp::FpCheckOutOption*)(int*)TVariant(params[2]));
      }
      break;
      }
    case 5: {
      if (OnClose) {
        (OnClose)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

WebWindowPtr& TWebWindowEx::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TWebWindowEx::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TWebWindowEx::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TWebWindowEx::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TWebWindowEx::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TWebWindowEx::ConnectTo(WebWindowPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TWebWindowEx::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_WebWindowEx;
  sd.IntfIID = __uuidof(WebWindow);
  sd.EventIID= __uuidof(_IWebWindowEvents);
  ServerData = &sd;
}

void __fastcall TWebWindowEx::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnBeforeViewChange) {
        (OnBeforeViewChange)(this, (Frontpage_xp::FpWebViewModeEx)(int)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2: {
      if (OnAfterViewChange) {
        (OnAfterViewChange)(this);
      }
      break;
      }
    case 3: {
      if (OnActivate) {
        (OnActivate)(this);
      }
      break;
      }
    case 4: {
      if (OnDeactivate) {
        (OnDeactivate)(this);
      }
      break;
      }
    case 5: {
      if (OnBeforeSubViewChange) {
        (OnBeforeSubViewChange)(this, (Frontpage_xp::FpWebSubView)(int)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 6: {
      if (OnAfterSubViewChange) {
        (OnAfterSubViewChange)(this);
      }
      break;
      }
    default:
      break;
  }
}


};     // namespace Frontpage_xp


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Frontpage_xp_srvr
{

void __fastcall PACKAGE Register()
{
  // [3]
  TComponentClass cls_svr[] = {
                              __classid(Frontpage_xp::TApp), 
                              __classid(Frontpage_xp::TWebEx), 
                              __classid(Frontpage_xp::TWebWindowEx)
                           };
  RegisterComponents("OfficeXP", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Frontpage_xp_srvr
