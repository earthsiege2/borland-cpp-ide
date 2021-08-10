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
// File generated on 1/24/2000 9:49:21 AM from Type Library described below.

// ************************************************************************ //
// Type Lib: g:\rampage\typelib\TypeLibraries\MSWORD8.olb (1)
// IID\LCID: {00020905-0000-0000-C000-000000000046}\409
// Helpfile: g:\rampage\typelib\TypeLibraries\VBAWRD8.HLP
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v2.0 Office, (D:\Program Files\Microsoft Office\Office\MSO97.DLL)
//   (3) v5.0 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBEEXT1.OLB)
//   (4) v4.0 StdVCL, (C:\WINNT\System32\STDVCL40.DLL)
// Errors:
//   Hint: Symbol 'Window' renamed to 'WINDOW'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'System' renamed to 'SYSTEM'
//   Hint: Symbol 'Global' renamed to 'WordGlobal'
//   Hint: Symbol 'Application' renamed to 'WordApplication'
//   Hint: Symbol 'Document' renamed to 'WordDocument'
//   Hint: Symbol 'Font' renamed to 'WordFont'
//   Hint: Symbol 'ParagraphFormat' renamed to 'WordParagraphFormat'
//   Hint: Symbol 'OLEControl' renamed to 'WordOLEControl'
//   Hint: Symbol 'LetterContent' renamed to 'WordLetterContent'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'ExitWindows' renamed to 'ExitWindoz'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Window' renamed to 'WINDOW'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'System' renamed to 'SYSTEM'
//   Hint: Symbol 'Global' renamed to 'WordGlobal'
//   Hint: Symbol 'Application' renamed to 'WordApplication'
//   Hint: Symbol 'Document' renamed to 'WordDocument'
//   Hint: Symbol 'Font' renamed to 'WordFont'
//   Hint: Symbol 'ParagraphFormat' renamed to 'WordParagraphFormat'
//   Hint: Symbol 'OLEControl' renamed to 'WordOLEControl'
//   Hint: Symbol 'LetterContent' renamed to 'WordLetterContent'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'ExitWindows' renamed to 'ExitWindoz'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "Word_97_SRVR.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Word_97
{

_GlobalPtr& TWordGlobal::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TWordGlobal::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TWordGlobal::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TWordGlobal::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TWordGlobal::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TWordGlobal::ConnectTo(_GlobalPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TWordGlobal::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_WordGlobal;
  sd.IntfIID = __uuidof(_Global);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_ApplicationPtr& TWordApplication::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TWordApplication::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TWordApplication::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TWordApplication::Disconnect()
{
  if (m_DefaultIntf) {
    Quit();
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TWordApplication::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TWordApplication::ConnectTo(_ApplicationPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TWordApplication::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_WordApplication;
  sd.IntfIID = __uuidof(_Application);
  sd.EventIID= __uuidof(ApplicationEvents);
  ServerData = &sd;
}

void __fastcall TWordApplication::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    case 1:
      if (OnStartup)
        (OnStartup)(this);
      break;
    case 2:
      if (OnQuit)
        (OnQuit)(this);
      break;
    case 3:
      if (OnDocumentChange)
        (OnDocumentChange)(this);
      break;
    default:
      break;
  }
}

_DocumentPtr& TWordDocument::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TWordDocument::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TWordDocument::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TWordDocument::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TWordDocument::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TWordDocument::ConnectTo(_DocumentPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TWordDocument::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_WordDocument;
  sd.IntfIID = __uuidof(_Document);
  sd.EventIID= __uuidof(DocumentEvents);
  ServerData = &sd;
}

void __fastcall TWordDocument::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    case 4:
      if (OnNew)
        (OnNew)(this);
      break;
    case 5:
      if (OnOpen)
        (OnOpen)(this);
      break;
    case 6:
      if (OnClose)
        (OnClose)(this);
      break;
    default:
      break;
  }
}

_FontPtr& TWordFont::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TWordFont::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TWordFont::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TWordFont::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TWordFont::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TWordFont::ConnectTo(_FontPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TWordFont::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_WordFont;
  sd.IntfIID = __uuidof(_Font);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_ParagraphFormatPtr& TWordParagraphFormat::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TWordParagraphFormat::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TWordParagraphFormat::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TWordParagraphFormat::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TWordParagraphFormat::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TWordParagraphFormat::ConnectTo(_ParagraphFormatPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TWordParagraphFormat::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_WordParagraphFormat;
  sd.IntfIID = __uuidof(_ParagraphFormat);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_LetterContentPtr& TWordLetterContent::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TWordLetterContent::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TWordLetterContent::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TWordLetterContent::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TWordLetterContent::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TWordLetterContent::ConnectTo(_LetterContentPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TWordLetterContent::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_WordLetterContent;
  sd.IntfIID = __uuidof(_LetterContent);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}


};     // namespace Word_97


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Word_97_srvr
{

void __fastcall PACKAGE Register()
{
  // [6]
  TComponentClass cls_svr[] = {
                              __classid(Word_97::TWordGlobal), 
                              __classid(Word_97::TWordApplication), 
                              __classid(Word_97::TWordDocument), 
                              __classid(Word_97::TWordFont), 
                              __classid(Word_97::TWordParagraphFormat), 
                              __classid(Word_97::TWordLetterContent)
                           };
  RegisterComponents("Servers", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Word_97_srvr
