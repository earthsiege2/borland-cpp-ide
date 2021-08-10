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

// C++ TLBWRTR : $Revision:   1.0.2.1  $
// File generated on 1/24/2000 9:50:10 AM from Type Library described below.

// ************************************************************************ //
// Type Lib: g:\rampage\typelib\TypeLibraries\MSPPT8.olb (1)
// IID\LCID: {91493440-5A91-11CF-8700-00AA0060263B}\0
// Helpfile: D:\Program Files\Microsoft Office\Office\VBAPPT8.HLP
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v2.0 Office, (D:\Program Files\Microsoft Office\Office\MSO97.DLL)
//   (3) v5.0 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBEEXT1.OLB)
//   (4) v4.0 StdVCL, (C:\WINNT\System32\STDVCL40.DLL)
// Errors:
//   Hint: Symbol 'Application' renamed to 'PowerPointApplication'
//   Hint: Symbol 'Global' renamed to 'PowerPointGlobal'
//   Hint: Symbol 'Presentation' renamed to 'PowerPointPresentation'
//   Hint: Symbol 'Slide' renamed to 'PowerPointSlide'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Application' renamed to 'PowerPointApplication'
//   Hint: Symbol 'Global' renamed to 'PowerPointGlobal'
//   Hint: Symbol 'Presentation' renamed to 'PowerPointPresentation'
//   Hint: Symbol 'Slide' renamed to 'PowerPointSlide'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "PowerPoint_97_SRVR.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Powerpoint_97
{

_ApplicationPtr& TPowerPointApplication::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TPowerPointApplication::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TPowerPointApplication::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TPowerPointApplication::Disconnect()
{
  if (m_DefaultIntf) {
    Quit();
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TPowerPointApplication::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TPowerPointApplication::ConnectTo(_ApplicationPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TPowerPointApplication::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_PowerPointApplication;
  sd.IntfIID = __uuidof(_Application);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_GlobalPtr& TPowerPointGlobal::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TPowerPointGlobal::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TPowerPointGlobal::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TPowerPointGlobal::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TPowerPointGlobal::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TPowerPointGlobal::ConnectTo(_GlobalPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TPowerPointGlobal::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_PowerPointGlobal;
  sd.IntfIID = __uuidof(_Global);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_PresentationPtr& TPowerPointPresentation::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TPowerPointPresentation::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TPowerPointPresentation::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TPowerPointPresentation::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TPowerPointPresentation::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TPowerPointPresentation::ConnectTo(_PresentationPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TPowerPointPresentation::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_PowerPointPresentation;
  sd.IntfIID = __uuidof(_Presentation);
  sd.EventIID= __uuidof(PresEvents);
  ServerData = &sd;
}

void __fastcall TPowerPointPresentation::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    default:
      break;
  }
}

_SlidePtr& TPowerPointSlide::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TPowerPointSlide::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TPowerPointSlide::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TPowerPointSlide::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TPowerPointSlide::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TPowerPointSlide::ConnectTo(_SlidePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TPowerPointSlide::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_PowerPointSlide;
  sd.IntfIID = __uuidof(_Slide);
  sd.EventIID= __uuidof(SldEvents);
  ServerData = &sd;
}

void __fastcall TPowerPointSlide::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    default:
      break;
  }
}


};     // namespace Powerpoint_97


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Powerpoint_97_srvr
{

void __fastcall PACKAGE Register()
{
  // [4]
  TComponentClass cls_svr[] = {
                              __classid(Powerpoint_97::TPowerPointApplication), 
                              __classid(Powerpoint_97::TPowerPointGlobal), 
                              __classid(Powerpoint_97::TPowerPointPresentation), 
                              __classid(Powerpoint_97::TPowerPointSlide)
                           };
  RegisterComponents("Servers", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Powerpoint_97_srvr
