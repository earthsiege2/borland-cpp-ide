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

// C++ TLBWRTR : $Revision:   1.151.1.0.1.21  $
// File generated on 1/28/2002 7:55:39 AM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office97\office\msoutl8.olb (1)
// LIBID: {00062FFF-0000-0000-C000-000000000046}
// LCID: 0
// Helpfile: C:\Program Files\Microsoft Office\office97\Office\VBAOUTL.HLP
// HelpString: Microsoft Outlook 8.0 Object Library
// DepndLst: 
//   (1) v1.0 stdole, (C:\WINNT\System32\stdole32.tlb)
//   (2) v2.0 Office, (C:\Program Files\Microsoft Office\office97\Office\MSO97.DLL)
//   (3) v2.0 MSForms, (C:\WINNT\System32\FM20.DLL)
//   (4) v2.0 StdType, (C:\WINNT\System32\olepro32.dll)
// Errors:
//   Hint: Symbol 'Application' renamed to 'OutlookApplication'
//   Hint: Symbol 'Application' renamed to 'OutlookApplication'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "Outlook_97_SRVR.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Outlook_97
{

_DApplicationPtr& TOutlookApplication::GetDefaultInterface()
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

void __fastcall TOutlookApplication::ConnectTo(_DApplicationPtr intf)
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
  sd.IntfIID = __uuidof(_DApplication);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_DAppointmentItemPtr& TAppointmentItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAppointmentItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAppointmentItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAppointmentItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAppointmentItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAppointmentItem::ConnectTo(_DAppointmentItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAppointmentItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AppointmentItem;
  sd.IntfIID = __uuidof(_DAppointmentItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TAppointmentItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DContactItemPtr& TContactItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TContactItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TContactItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TContactItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TContactItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TContactItem::ConnectTo(_DContactItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TContactItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ContactItem;
  sd.IntfIID = __uuidof(_DContactItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TContactItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DJournalItemPtr& TJournalItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TJournalItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TJournalItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TJournalItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TJournalItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TJournalItem::ConnectTo(_DJournalItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TJournalItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_JournalItem;
  sd.IntfIID = __uuidof(_DJournalItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TJournalItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DMailItemPtr& TMailItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TMailItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TMailItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TMailItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TMailItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TMailItem::ConnectTo(_DMailItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TMailItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_MailItem;
  sd.IntfIID = __uuidof(_DMailItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TMailItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DMeetingRequestItemPtr& TMeetingRequestItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TMeetingRequestItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TMeetingRequestItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TMeetingRequestItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TMeetingRequestItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TMeetingRequestItem::ConnectTo(_DMeetingRequestItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TMeetingRequestItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_MeetingRequestItem;
  sd.IntfIID = __uuidof(_DMeetingRequestItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TMeetingRequestItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DNoteItemPtr& TNoteItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TNoteItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TNoteItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TNoteItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TNoteItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TNoteItem::ConnectTo(_DNoteItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TNoteItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_NoteItem;
  sd.IntfIID = __uuidof(_DNoteItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TNoteItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DPostItemPtr& TPostItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TPostItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TPostItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TPostItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TPostItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TPostItem::ConnectTo(_DPostItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TPostItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_PostItem;
  sd.IntfIID = __uuidof(_DPostItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TPostItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DRemoteItemPtr& TRemoteItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TRemoteItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TRemoteItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TRemoteItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TRemoteItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TRemoteItem::ConnectTo(_DRemoteItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TRemoteItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_RemoteItem;
  sd.IntfIID = __uuidof(_DRemoteItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TRemoteItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DReportItemPtr& TReportItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TReportItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TReportItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TReportItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TReportItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TReportItem::ConnectTo(_DReportItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TReportItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ReportItem;
  sd.IntfIID = __uuidof(_DReportItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TReportItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DTaskItemPtr& TTaskItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TTaskItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TTaskItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TTaskItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TTaskItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TTaskItem::ConnectTo(_DTaskItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TTaskItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_TaskItem;
  sd.IntfIID = __uuidof(_DTaskItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TTaskItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DTaskRequestItemPtr& TTaskRequestItem::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TTaskRequestItem::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TTaskRequestItem::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TTaskRequestItem::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TTaskRequestItem::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TTaskRequestItem::ConnectTo(_DTaskRequestItemPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TTaskRequestItem::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_TaskRequestItem;
  sd.IntfIID = __uuidof(_DTaskRequestItem);
  sd.EventIID= __uuidof(_DItemEvents);
  ServerData = &sd;
}

void __fastcall TTaskRequestItem::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 61441: {
      if (OnRead) {
        (OnRead)(this);
      }
      break;
      }
    case 61442: {
      if (OnWrite) {
        (OnWrite)(this);
      }
      break;
      }
    case 61443: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 61444: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
    case 61445: {
      if (OnSend) {
        (OnSend)(this);
      }
      break;
      }
    case 62566: {
      if (OnReply) {
        (OnReply)(this, TVariant(params[0]));
      }
      break;
      }
    case 62567: {
      if (OnReplyAll) {
        (OnReplyAll)(this, TVariant(params[0]));
      }
      break;
      }
    case 62568: {
      if (OnForward) {
        (OnForward)(this, TVariant(params[0]));
      }
      break;
      }
    case 61446: {
      if (OnCustomAction) {
        (OnCustomAction)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 61448: {
      if (OnCustomPropertyChange) {
        (OnCustomPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 61449: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}


};     // namespace Outlook_97


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Outlook_97_srvr
{

void __fastcall PACKAGE Register()
{
  // [12]
  TComponentClass cls_svr[] = {
                              __classid(Outlook_97::TOutlookApplication), 
                              __classid(Outlook_97::TAppointmentItem), 
                              __classid(Outlook_97::TContactItem), 
                              __classid(Outlook_97::TJournalItem), 
                              __classid(Outlook_97::TMailItem), 
                              __classid(Outlook_97::TMeetingRequestItem), 
                              __classid(Outlook_97::TNoteItem), 
                              __classid(Outlook_97::TPostItem), 
                              __classid(Outlook_97::TRemoteItem), 
                              __classid(Outlook_97::TReportItem), 
                              __classid(Outlook_97::TTaskItem), 
                              __classid(Outlook_97::TTaskRequestItem)
                           };
  RegisterComponents("Office97", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Outlook_97_srvr
