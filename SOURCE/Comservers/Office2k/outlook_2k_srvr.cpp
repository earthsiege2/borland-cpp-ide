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

// C++ TLBWRTR : $Revision:   1.0.1.1  $
// File generated on 1/24/2000 09:45:44 AM from Type Library described below.

// ************************************************************************ //
// Type Lib: d:\tlbgen\rampage\typelib\TypeLibraries\MSOUTL9.olb (1)
// IID\LCID: {00062FFF-0000-0000-C000-000000000046}\0
// Helpfile: d:\tlbgen\rampage\typelib\TypeLibraries\VBAOUTL9.CHM
// DepndLst: 
//   (1) v2.0 stdole, (D:\WINNT\System32\stdole2.tlb)
//   (2) v2.1 Office, (D:\msof2k\Office\mso9.dll)
//   (3) v4.0 StdVCL, (D:\tlbgen\rampage\typelib\typelibraries\testing\stdvcl40.tlb)
// Errors:
//   Hint: Symbol 'Application' renamed to 'OutlookApplication'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Application' renamed to 'OutlookApplication'
//   Hint: Symbol 'Update' renamed to '_Update'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "Outlook_2K_SRVR.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Outlook_2k
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
  sd.EventIID= __uuidof(ApplicationEvents);
  ServerData = &sd;
}

void __fastcall TOutlookApplication::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    case 61442:
      if (OnItemSend)
        (OnItemSend)(this, TVariant(params[0]), TVariant(params[1]));
      break;
    case 61443:
      if (OnNewMail)
        (OnNewMail)(this);
      break;
    case 61444:
      if (OnReminder)
        (OnReminder)(this, TVariant(params[0]));
      break;
    case 61445:
      if (OnOptionsPagesAdd)
        (OnOptionsPagesAdd)(this, (Outlook_2k::PropertyPages*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 61446:
      if (OnStartup)
        (OnStartup)(this);
      break;
    case 61447:
      if (OnQuit)
        (OnQuit)(this);
      break;
    default:
      break;
  }
}


};     // namespace Outlook_2k


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Outlook_2k_srvr
{

void __fastcall PACKAGE Register()
{
  // [1]
  TComponentClass cls_svr[] = {
                              __classid(Outlook_2k::TOutlookApplication)
                           };
  RegisterComponents("Servers", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Outlook_2k_srvr
