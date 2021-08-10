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

// C++ TLBWRTR : $Revision:   1.0.1.0.1.1  $
// File generated on 1/24/2002 7:03:18 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\winnt\system32\msxml3.dll (1)
// LIBID: {F5078F18-C551-11D3-89B9-0000F81FE221}
// LCID: 0
// Helpfile: 
// HelpString: Microsoft XML, v3.0
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
// Errors:
//   Hint: Symbol 'DOMDocument' renamed to 'msDOMDocument'
//   Hint: Symbol 'DOMDocument26' renamed to 'msDOMDocument26'
//   Hint: Symbol 'DOMDocument30' renamed to 'msDOMDocument30'
//   Hint: Symbol 'FreeThreadedDOMDocument' renamed to 'msFreeThreadedDOMDocument'
//   Hint: Symbol 'FreeThreadedDOMDocument26' renamed to 'msFreeThreadedDOMDocument26'
//   Hint: Symbol 'FreeThreadedDOMDocument30' renamed to 'msFreeThreadedDOMDocument30'
//   Hint: Symbol 'XMLSchemaCache' renamed to 'msXMLSchemaCache'
//   Hint: Symbol 'XMLSchemaCache26' renamed to 'msXMLSchemaCache26'
//   Hint: Symbol 'XMLSchemaCache30' renamed to 'msXMLSchemaCache30'
//   Hint: Symbol 'XSLTemplate' renamed to 'msXSLTemplate'
//   Hint: Symbol 'XSLTemplate26' renamed to 'msXSLTemplate26'
//   Hint: Symbol 'XSLTemplate30' renamed to 'msXSLTemplate30'
//   Hint: Symbol 'DSOControl' renamed to 'msDSOControl'
//   Hint: Symbol 'DSOControl26' renamed to 'msDSOControl26'
//   Hint: Symbol 'DSOControl30' renamed to 'msDSOControl30'
//   Hint: Symbol 'XMLHTTP' renamed to 'msXMLHTTP'
//   Hint: Symbol 'XMLHTTP26' renamed to 'msXMLHTTP26'
//   Hint: Symbol 'XMLHTTP30' renamed to 'msXMLHTTP30'
//   Hint: Symbol 'ServerXMLHTTP' renamed to 'msServerXMLHTTP'
//   Hint: Symbol 'ServerXMLHTTP30' renamed to 'msServerXMLHTTP30'
//   Hint: Symbol 'SAXXMLReader' renamed to 'msSAXXMLReader'
//   Hint: Symbol 'SAXXMLReader30' renamed to 'msSAXXMLReader30'
//   Hint: Symbol 'MXXMLWriter' renamed to 'msMXXMLWriter'
//   Hint: Symbol 'MXXMLWriter30' renamed to 'msMXXMLWriter30'
//   Hint: Symbol 'SAXAttributes' renamed to 'msSAXAttributes'
//   Hint: Symbol 'SAXAttributes30' renamed to 'msSAXAttributes30'
//   Hint: Symbol 'DOMDocument' renamed to 'msDOMDocument'
//   Hint: Symbol 'DOMDocument26' renamed to 'msDOMDocument26'
//   Hint: Symbol 'DOMDocument30' renamed to 'msDOMDocument30'
//   Hint: Symbol 'FreeThreadedDOMDocument' renamed to 'msFreeThreadedDOMDocument'
//   Hint: Symbol 'FreeThreadedDOMDocument26' renamed to 'msFreeThreadedDOMDocument26'
//   Hint: Symbol 'FreeThreadedDOMDocument30' renamed to 'msFreeThreadedDOMDocument30'
//   Hint: Symbol 'XMLSchemaCache' renamed to 'msXMLSchemaCache'
//   Hint: Symbol 'XMLSchemaCache26' renamed to 'msXMLSchemaCache26'
//   Hint: Symbol 'XMLSchemaCache30' renamed to 'msXMLSchemaCache30'
//   Hint: Symbol 'XSLTemplate' renamed to 'msXSLTemplate'
//   Hint: Symbol 'XSLTemplate26' renamed to 'msXSLTemplate26'
//   Hint: Symbol 'XSLTemplate30' renamed to 'msXSLTemplate30'
//   Hint: Symbol 'DSOControl' renamed to 'msDSOControl'
//   Hint: Symbol 'DSOControl26' renamed to 'msDSOControl26'
//   Hint: Symbol 'DSOControl30' renamed to 'msDSOControl30'
//   Hint: Symbol 'XMLHTTP' renamed to 'msXMLHTTP'
//   Hint: Symbol 'XMLHTTP26' renamed to 'msXMLHTTP26'
//   Hint: Symbol 'XMLHTTP30' renamed to 'msXMLHTTP30'
//   Hint: Symbol 'ServerXMLHTTP' renamed to 'msServerXMLHTTP'
//   Hint: Symbol 'ServerXMLHTTP30' renamed to 'msServerXMLHTTP30'
//   Hint: Symbol 'SAXXMLReader' renamed to 'msSAXXMLReader'
//   Hint: Symbol 'SAXXMLReader30' renamed to 'msSAXXMLReader30'
//   Hint: Symbol 'MXXMLWriter' renamed to 'msMXXMLWriter'
//   Hint: Symbol 'MXXMLWriter30' renamed to 'msMXXMLWriter30'
//   Hint: Symbol 'SAXAttributes' renamed to 'msSAXAttributes'
//   Hint: Symbol 'SAXAttributes30' renamed to 'msSAXAttributes30'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "MSXML3_SRVR.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Msxml3
{

IXMLDOMDocument2Ptr& TmsDOMDocument::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsDOMDocument::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsDOMDocument::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsDOMDocument::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsDOMDocument::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsDOMDocument::ConnectTo(IXMLDOMDocument2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsDOMDocument::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msDOMDocument;
  sd.IntfIID = __uuidof(IXMLDOMDocument2);
  sd.EventIID= __uuidof(XMLDOMDocumentEvents);
  ServerData = &sd;
}

void __fastcall TmsDOMDocument::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 198: {
      if (Onondataavailable) {
        (Onondataavailable)(this);
      }
      break;
      }
    case -609: {
      if (Ononreadystatechange) {
        (Ononreadystatechange)(this);
      }
      break;
      }
    default:
      break;
  }
}

IXMLDOMDocument2Ptr& TmsDOMDocument26::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsDOMDocument26::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsDOMDocument26::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsDOMDocument26::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsDOMDocument26::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsDOMDocument26::ConnectTo(IXMLDOMDocument2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsDOMDocument26::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msDOMDocument26;
  sd.IntfIID = __uuidof(IXMLDOMDocument2);
  sd.EventIID= __uuidof(XMLDOMDocumentEvents);
  ServerData = &sd;
}

void __fastcall TmsDOMDocument26::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 198: {
      if (Onondataavailable) {
        (Onondataavailable)(this);
      }
      break;
      }
    case -609: {
      if (Ononreadystatechange) {
        (Ononreadystatechange)(this);
      }
      break;
      }
    default:
      break;
  }
}

IXMLDOMDocument2Ptr& TmsDOMDocument30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsDOMDocument30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsDOMDocument30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsDOMDocument30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsDOMDocument30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsDOMDocument30::ConnectTo(IXMLDOMDocument2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsDOMDocument30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msDOMDocument30;
  sd.IntfIID = __uuidof(IXMLDOMDocument2);
  sd.EventIID= __uuidof(XMLDOMDocumentEvents);
  ServerData = &sd;
}

void __fastcall TmsDOMDocument30::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 198: {
      if (Onondataavailable) {
        (Onondataavailable)(this);
      }
      break;
      }
    case -609: {
      if (Ononreadystatechange) {
        (Ononreadystatechange)(this);
      }
      break;
      }
    default:
      break;
  }
}

IXMLDOMDocument2Ptr& TmsFreeThreadedDOMDocument::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsFreeThreadedDOMDocument::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsFreeThreadedDOMDocument::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsFreeThreadedDOMDocument::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsFreeThreadedDOMDocument::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsFreeThreadedDOMDocument::ConnectTo(IXMLDOMDocument2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsFreeThreadedDOMDocument::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msFreeThreadedDOMDocument;
  sd.IntfIID = __uuidof(IXMLDOMDocument2);
  sd.EventIID= __uuidof(XMLDOMDocumentEvents);
  ServerData = &sd;
}

void __fastcall TmsFreeThreadedDOMDocument::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 198: {
      if (Onondataavailable) {
        (Onondataavailable)(this);
      }
      break;
      }
    case -609: {
      if (Ononreadystatechange) {
        (Ononreadystatechange)(this);
      }
      break;
      }
    default:
      break;
  }
}

IXMLDOMDocument2Ptr& TmsFreeThreadedDOMDocument26::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsFreeThreadedDOMDocument26::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsFreeThreadedDOMDocument26::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsFreeThreadedDOMDocument26::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsFreeThreadedDOMDocument26::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsFreeThreadedDOMDocument26::ConnectTo(IXMLDOMDocument2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsFreeThreadedDOMDocument26::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msFreeThreadedDOMDocument26;
  sd.IntfIID = __uuidof(IXMLDOMDocument2);
  sd.EventIID= __uuidof(XMLDOMDocumentEvents);
  ServerData = &sd;
}

void __fastcall TmsFreeThreadedDOMDocument26::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 198: {
      if (Onondataavailable) {
        (Onondataavailable)(this);
      }
      break;
      }
    case -609: {
      if (Ononreadystatechange) {
        (Ononreadystatechange)(this);
      }
      break;
      }
    default:
      break;
  }
}

IXMLDOMDocument2Ptr& TmsFreeThreadedDOMDocument30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsFreeThreadedDOMDocument30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsFreeThreadedDOMDocument30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsFreeThreadedDOMDocument30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsFreeThreadedDOMDocument30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsFreeThreadedDOMDocument30::ConnectTo(IXMLDOMDocument2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsFreeThreadedDOMDocument30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msFreeThreadedDOMDocument30;
  sd.IntfIID = __uuidof(IXMLDOMDocument2);
  sd.EventIID= __uuidof(XMLDOMDocumentEvents);
  ServerData = &sd;
}

void __fastcall TmsFreeThreadedDOMDocument30::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 198: {
      if (Onondataavailable) {
        (Onondataavailable)(this);
      }
      break;
      }
    case -609: {
      if (Ononreadystatechange) {
        (Ononreadystatechange)(this);
      }
      break;
      }
    default:
      break;
  }
}

IXMLDOMSchemaCollectionPtr& TmsXMLSchemaCache::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsXMLSchemaCache::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsXMLSchemaCache::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsXMLSchemaCache::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsXMLSchemaCache::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsXMLSchemaCache::ConnectTo(IXMLDOMSchemaCollectionPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsXMLSchemaCache::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msXMLSchemaCache;
  sd.IntfIID = __uuidof(IXMLDOMSchemaCollection);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IXMLDOMSchemaCollectionPtr& TmsXMLSchemaCache26::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsXMLSchemaCache26::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsXMLSchemaCache26::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsXMLSchemaCache26::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsXMLSchemaCache26::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsXMLSchemaCache26::ConnectTo(IXMLDOMSchemaCollectionPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsXMLSchemaCache26::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msXMLSchemaCache26;
  sd.IntfIID = __uuidof(IXMLDOMSchemaCollection);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IXMLDOMSchemaCollectionPtr& TmsXMLSchemaCache30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsXMLSchemaCache30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsXMLSchemaCache30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsXMLSchemaCache30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsXMLSchemaCache30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsXMLSchemaCache30::ConnectTo(IXMLDOMSchemaCollectionPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsXMLSchemaCache30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msXMLSchemaCache30;
  sd.IntfIID = __uuidof(IXMLDOMSchemaCollection);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IXSLTemplatePtr& TmsXSLTemplate::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsXSLTemplate::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsXSLTemplate::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsXSLTemplate::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsXSLTemplate::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsXSLTemplate::ConnectTo(IXSLTemplatePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsXSLTemplate::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msXSLTemplate;
  sd.IntfIID = __uuidof(IXSLTemplate);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IXSLTemplatePtr& TmsXSLTemplate26::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsXSLTemplate26::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsXSLTemplate26::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsXSLTemplate26::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsXSLTemplate26::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsXSLTemplate26::ConnectTo(IXSLTemplatePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsXSLTemplate26::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msXSLTemplate26;
  sd.IntfIID = __uuidof(IXSLTemplate);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IXSLTemplatePtr& TmsXSLTemplate30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsXSLTemplate30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsXSLTemplate30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsXSLTemplate30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsXSLTemplate30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsXSLTemplate30::ConnectTo(IXSLTemplatePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsXSLTemplate30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msXSLTemplate30;
  sd.IntfIID = __uuidof(IXSLTemplate);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IDSOControlPtr& TmsDSOControl::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsDSOControl::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsDSOControl::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsDSOControl::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsDSOControl::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsDSOControl::ConnectTo(IDSOControlPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsDSOControl::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msDSOControl;
  sd.IntfIID = __uuidof(IDSOControl);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IDSOControlPtr& TmsDSOControl26::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsDSOControl26::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsDSOControl26::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsDSOControl26::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsDSOControl26::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsDSOControl26::ConnectTo(IDSOControlPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsDSOControl26::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msDSOControl26;
  sd.IntfIID = __uuidof(IDSOControl);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IDSOControlPtr& TmsDSOControl30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsDSOControl30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsDSOControl30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsDSOControl30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsDSOControl30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsDSOControl30::ConnectTo(IDSOControlPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsDSOControl30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msDSOControl30;
  sd.IntfIID = __uuidof(IDSOControl);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IXMLHTTPRequestPtr& TmsXMLHTTP::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsXMLHTTP::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsXMLHTTP::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsXMLHTTP::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsXMLHTTP::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsXMLHTTP::ConnectTo(IXMLHTTPRequestPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsXMLHTTP::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msXMLHTTP;
  sd.IntfIID = __uuidof(IXMLHTTPRequest);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IXMLHTTPRequestPtr& TmsXMLHTTP26::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsXMLHTTP26::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsXMLHTTP26::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsXMLHTTP26::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsXMLHTTP26::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsXMLHTTP26::ConnectTo(IXMLHTTPRequestPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsXMLHTTP26::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msXMLHTTP26;
  sd.IntfIID = __uuidof(IXMLHTTPRequest);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IXMLHTTPRequestPtr& TmsXMLHTTP30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsXMLHTTP30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsXMLHTTP30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsXMLHTTP30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsXMLHTTP30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsXMLHTTP30::ConnectTo(IXMLHTTPRequestPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsXMLHTTP30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msXMLHTTP30;
  sd.IntfIID = __uuidof(IXMLHTTPRequest);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IServerXMLHTTPRequestPtr& TmsServerXMLHTTP::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsServerXMLHTTP::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsServerXMLHTTP::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsServerXMLHTTP::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsServerXMLHTTP::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsServerXMLHTTP::ConnectTo(IServerXMLHTTPRequestPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsServerXMLHTTP::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msServerXMLHTTP;
  sd.IntfIID = __uuidof(IServerXMLHTTPRequest);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IServerXMLHTTPRequestPtr& TmsServerXMLHTTP30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsServerXMLHTTP30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsServerXMLHTTP30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsServerXMLHTTP30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsServerXMLHTTP30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsServerXMLHTTP30::ConnectTo(IServerXMLHTTPRequestPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsServerXMLHTTP30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msServerXMLHTTP30;
  sd.IntfIID = __uuidof(IServerXMLHTTPRequest);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IVBSAXXMLReaderPtr& TmsSAXXMLReader::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsSAXXMLReader::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsSAXXMLReader::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsSAXXMLReader::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsSAXXMLReader::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsSAXXMLReader::ConnectTo(IVBSAXXMLReaderPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsSAXXMLReader::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msSAXXMLReader;
  sd.IntfIID = __uuidof(IVBSAXXMLReader);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IVBSAXXMLReaderPtr& TmsSAXXMLReader30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsSAXXMLReader30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsSAXXMLReader30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsSAXXMLReader30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsSAXXMLReader30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsSAXXMLReader30::ConnectTo(IVBSAXXMLReaderPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsSAXXMLReader30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msSAXXMLReader30;
  sd.IntfIID = __uuidof(IVBSAXXMLReader);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IMXWriterPtr& TmsMXXMLWriter::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsMXXMLWriter::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsMXXMLWriter::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsMXXMLWriter::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsMXXMLWriter::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsMXXMLWriter::ConnectTo(IMXWriterPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsMXXMLWriter::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msMXXMLWriter;
  sd.IntfIID = __uuidof(IMXWriter);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IMXWriterPtr& TmsMXXMLWriter30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsMXXMLWriter30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsMXXMLWriter30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsMXXMLWriter30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsMXXMLWriter30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsMXXMLWriter30::ConnectTo(IMXWriterPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsMXXMLWriter30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msMXXMLWriter30;
  sd.IntfIID = __uuidof(IMXWriter);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IMXAttributesPtr& TmsSAXAttributes::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsSAXAttributes::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsSAXAttributes::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsSAXAttributes::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsSAXAttributes::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsSAXAttributes::ConnectTo(IMXAttributesPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsSAXAttributes::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msSAXAttributes;
  sd.IntfIID = __uuidof(IMXAttributes);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IMXAttributesPtr& TmsSAXAttributes30::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TmsSAXAttributes30::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TmsSAXAttributes30::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TmsSAXAttributes30::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TmsSAXAttributes30::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TmsSAXAttributes30::ConnectTo(IMXAttributesPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TmsSAXAttributes30::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_msSAXAttributes30;
  sd.IntfIID = __uuidof(IMXAttributes);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}


};     // namespace Msxml3


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Msxml3_srvr
{

void __fastcall PACKAGE Register()
{
  // [26]
  TComponentClass cls_svr[] = {
                              __classid(Msxml3::TmsDOMDocument), 
                              __classid(Msxml3::TmsDOMDocument26), 
                              __classid(Msxml3::TmsDOMDocument30), 
                              __classid(Msxml3::TmsFreeThreadedDOMDocument), 
                              __classid(Msxml3::TmsFreeThreadedDOMDocument26), 
                              __classid(Msxml3::TmsFreeThreadedDOMDocument30), 
                              __classid(Msxml3::TmsXMLSchemaCache), 
                              __classid(Msxml3::TmsXMLSchemaCache26), 
                              __classid(Msxml3::TmsXMLSchemaCache30), 
                              __classid(Msxml3::TmsXSLTemplate), 
                              __classid(Msxml3::TmsXSLTemplate26), 
                              __classid(Msxml3::TmsXSLTemplate30), 
                              __classid(Msxml3::TmsDSOControl), 
                              __classid(Msxml3::TmsDSOControl26), 
                              __classid(Msxml3::TmsDSOControl30), 
                              __classid(Msxml3::TmsXMLHTTP), 
                              __classid(Msxml3::TmsXMLHTTP26), 
                              __classid(Msxml3::TmsXMLHTTP30), 
                              __classid(Msxml3::TmsServerXMLHTTP), 
                              __classid(Msxml3::TmsServerXMLHTTP30), 
                              __classid(Msxml3::TmsSAXXMLReader), 
                              __classid(Msxml3::TmsSAXXMLReader30), 
                              __classid(Msxml3::TmsMXXMLWriter), 
                              __classid(Msxml3::TmsMXXMLWriter30), 
                              __classid(Msxml3::TmsSAXAttributes), 
                              __classid(Msxml3::TmsSAXAttributes30)
                           };
  RegisterComponents("XML3", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Msxml3_srvr
