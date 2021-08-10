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
// File generated on 1/29/2002 1:27:59 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office10\msacc.olb (1)
// LIBID: {4AFFC9A0-5F99-101B-AF4E-00AA003F0F07}
// LCID: 0
// Helpfile: c:\program files\microsoft office\office10\vbaac10.chm
// HelpString: Microsoft Access 10.0 Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v5.0 DAO, (C:\Program Files\Common Files\Microsoft Shared\DAO\dao360.dll)
//   (3) v2.2 Office, (C:\Program Files\Common Files\Microsoft Shared\Office10\MSO.DLL)
//   (4) v2.5 ADODB, (C:\Program Files\Common Files\System\ADO\msado25.tlb)
//   (5) v5.3 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB)
//   (6) v1.0 OWC10, (C:\Program Files\Common Files\Microsoft Shared\Web Components\10\OWC10.DLL)
// Errors:
//   Hint: Symbol 'Hyperlink' renamed to 'AccessHyperlink'
//   Hint: Symbol 'Page' renamed to 'AccessPage'
//   Hint: Symbol 'Control' renamed to 'AccessControl'
//   Hint: Symbol 'Controls' renamed to 'Controls_'
//   Hint: Symbol 'Label' renamed to 'AccessLabel'
//   Hint: Symbol 'Rectangle' renamed to 'AccessRectangle'
//   Hint: Symbol 'Line' renamed to 'AccessLine'
//   Hint: Symbol 'Image' renamed to 'AccessImage'
//   Hint: Symbol 'CommandButton' renamed to 'AccessCommandButton'
//   Hint: Symbol 'OptionButton' renamed to 'AccessOptionButton'
//   Hint: Symbol 'CheckBox' renamed to 'AccessCheckBox'
//   Hint: Symbol 'OptionGroup' renamed to 'AccessOptionGroup'
//   Hint: Symbol 'BoundObjectFrame' renamed to 'AccessBoundObjectFrame'
//   Hint: Symbol 'TextBox' renamed to 'AccessTextBox'
//   Hint: Symbol 'ListBox' renamed to 'AccessListBox'
//   Hint: Symbol 'ComboBox' renamed to 'AccessComboBox'
//   Hint: Symbol 'ObjectFrame' renamed to 'AccessObjectFrame'
//   Hint: Symbol 'PageBreak' renamed to 'AccessPageBreak'
//   Hint: Symbol 'ToggleButton' renamed to 'AccessToggleButton'
//   Hint: Symbol 'PaletteButton' renamed to 'AccessPaletteButton'
//   Hint: Symbol 'SubForm' renamed to 'AccessSubForm'
//   Hint: Symbol 'SubReport' renamed to 'AccessSubReport'
//   Hint: Symbol 'CustomControl' renamed to 'AccessCustomControl'
//   Hint: Symbol 'TabControl' renamed to 'AccessTabControl'
//   Hint: Symbol 'Section' renamed to 'AccessSection'
//   Hint: Symbol 'GroupLevel' renamed to 'AccessGroupLevel'
//   Hint: Symbol 'Forms' renamed to 'Forms_'
//   Hint: Symbol 'Application' renamed to 'AccessApplication'
//   Hint: Symbol 'References' renamed to 'AccessReferences'
//   Hint: Symbol 'WebOptions' renamed to 'AccessWebOptions'
//   Hint: Symbol 'Form' renamed to 'AccessForm'
//   Hint: Symbol 'Report' renamed to 'AccessReport'
//   Hint: Symbol 'Set' renamed to 'Set_'
//   Hint: Symbol 'Hyperlink' renamed to 'AccessHyperlink'
//   Hint: Symbol 'Page' renamed to 'AccessPage'
//   Hint: Symbol 'Control' renamed to 'AccessControl'
//   Hint: Symbol 'Controls' renamed to 'Controls_'
//   Hint: Symbol 'Label' renamed to 'AccessLabel'
//   Hint: Symbol 'Rectangle' renamed to 'AccessRectangle'
//   Hint: Symbol 'Line' renamed to 'AccessLine'
//   Hint: Symbol 'Image' renamed to 'AccessImage'
//   Hint: Symbol 'CommandButton' renamed to 'AccessCommandButton'
//   Hint: Symbol 'OptionButton' renamed to 'AccessOptionButton'
//   Hint: Symbol 'CheckBox' renamed to 'AccessCheckBox'
//   Hint: Symbol 'OptionGroup' renamed to 'AccessOptionGroup'
//   Hint: Symbol 'BoundObjectFrame' renamed to 'AccessBoundObjectFrame'
//   Hint: Symbol 'TextBox' renamed to 'AccessTextBox'
//   Hint: Symbol 'ListBox' renamed to 'AccessListBox'
//   Hint: Symbol 'ComboBox' renamed to 'AccessComboBox'
//   Hint: Symbol 'ObjectFrame' renamed to 'AccessObjectFrame'
//   Hint: Symbol 'PageBreak' renamed to 'AccessPageBreak'
//   Hint: Symbol 'ToggleButton' renamed to 'AccessToggleButton'
//   Hint: Symbol 'PaletteButton' renamed to 'AccessPaletteButton'
//   Hint: Symbol 'SubForm' renamed to 'AccessSubForm'
//   Hint: Symbol 'SubReport' renamed to 'AccessSubReport'
//   Hint: Symbol 'CustomControl' renamed to 'AccessCustomControl'
//   Hint: Symbol 'TabControl' renamed to 'AccessTabControl'
//   Hint: Symbol 'Section' renamed to 'AccessSection'
//   Hint: Symbol 'GroupLevel' renamed to 'AccessGroupLevel'
//   Hint: Symbol 'Forms' renamed to 'Forms_'
//   Hint: Symbol 'Application' renamed to 'AccessApplication'
//   Hint: Symbol 'References' renamed to 'AccessReferences'
//   Hint: Symbol 'WebOptions' renamed to 'AccessWebOptions'
//   Hint: Symbol 'Form' renamed to 'AccessForm'
//   Hint: Symbol 'Report' renamed to 'AccessReport'
//   Hint: Symbol 'Set' renamed to 'Set_'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "Access_XP_srvr.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Access_xp
{

_FormatConditionPtr& TFormatCondition::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TFormatCondition::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TFormatCondition::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TFormatCondition::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TFormatCondition::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TFormatCondition::ConnectTo(_FormatConditionPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TFormatCondition::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_FormatCondition;
  sd.IntfIID = __uuidof(_FormatCondition);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_HyperlinkPtr& TAccessHyperlink::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAccessHyperlink::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAccessHyperlink::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAccessHyperlink::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAccessHyperlink::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAccessHyperlink::ConnectTo(_HyperlinkPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAccessHyperlink::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AccessHyperlink;
  sd.IntfIID = __uuidof(_Hyperlink);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_ApplicationPtr& TAccessApplication::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAccessApplication::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAccessApplication::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAccessApplication::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAccessApplication::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAccessApplication::ConnectTo(_ApplicationPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAccessApplication::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AccessApplication;
  sd.IntfIID = __uuidof(_Application);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_ReferencesPtr& TAccessReferences::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAccessReferences::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAccessReferences::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAccessReferences::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAccessReferences::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAccessReferences::ConnectTo(_ReferencesPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAccessReferences::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AccessReferences;
  sd.IntfIID = __uuidof(_References);
  sd.EventIID= __uuidof(_References_Events);
  ServerData = &sd;
}

void __fastcall TAccessReferences::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 0: {
      if (OnItemAdded) {
        (OnItemAdded)(this, (Access_xp::Reference*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 1: {
      if (OnItemRemoved) {
        (OnItemRemoved)(this, (Access_xp::Reference*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_DataAccessPagePtr& TDataAccessPage::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TDataAccessPage::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TDataAccessPage::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TDataAccessPage::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TDataAccessPage::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TDataAccessPage::ConnectTo(_DataAccessPagePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TDataAccessPage::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_DataAccessPage;
  sd.IntfIID = __uuidof(_DataAccessPage);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllForms::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllForms::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllForms::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllForms::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllForms::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllForms::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllForms::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllForms;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllReports::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllReports::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllReports::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllReports::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllReports::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllReports::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllReports::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllReports;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllMacros::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllMacros::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllMacros::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllMacros::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllMacros::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllMacros::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllMacros::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllMacros;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllModules::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllModules::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllModules::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllModules::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllModules::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllModules::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllModules::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllModules;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllDataAccessPages::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllDataAccessPages::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllDataAccessPages::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllDataAccessPages::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllDataAccessPages::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllDataAccessPages::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllDataAccessPages::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllDataAccessPages;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllTables::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllTables::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllTables::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllTables::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllTables::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllTables::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllTables::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllTables;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllQueries::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllQueries::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllQueries::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllQueries::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllQueries::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllQueries::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllQueries::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllQueries;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllViews::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllViews::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllViews::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllViews::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllViews::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllViews::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllViews::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllViews;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllStoredProcedures::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllStoredProcedures::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllStoredProcedures::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllStoredProcedures::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllStoredProcedures::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllStoredProcedures::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllStoredProcedures::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllStoredProcedures;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

AllObjectsPtr& TAllDatabaseDiagrams::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllDatabaseDiagrams::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllDatabaseDiagrams::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllDatabaseDiagrams::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllDatabaseDiagrams::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllDatabaseDiagrams::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllDatabaseDiagrams::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllDatabaseDiagrams;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_CurrentProjectPtr& TCurrentProject::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCurrentProject::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCurrentProject::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCurrentProject::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCurrentProject::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCurrentProject::ConnectTo(_CurrentProjectPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCurrentProject::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CurrentProject;
  sd.IntfIID = __uuidof(_CurrentProject);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_CurrentDataPtr& TCurrentData::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCurrentData::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCurrentData::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCurrentData::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCurrentData::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCurrentData::ConnectTo(_CurrentDataPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCurrentData::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CurrentData;
  sd.IntfIID = __uuidof(_CurrentData);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_CurrentProjectPtr& TCodeProject::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCodeProject::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCodeProject::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCodeProject::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCodeProject::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCodeProject::ConnectTo(_CurrentProjectPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCodeProject::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CodeProject;
  sd.IntfIID = __uuidof(_CurrentProject);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_CurrentDataPtr& TCodeData::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCodeData::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCodeData::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCodeData::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCodeData::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCodeData::ConnectTo(_CurrentDataPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCodeData::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CodeData;
  sd.IntfIID = __uuidof(_CurrentData);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_DefaultWebOptionsPtr& TDefaultWebOptions::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TDefaultWebOptions::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TDefaultWebOptions::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TDefaultWebOptions::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TDefaultWebOptions::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TDefaultWebOptions::ConnectTo(_DefaultWebOptionsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TDefaultWebOptions::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_DefaultWebOptions;
  sd.IntfIID = __uuidof(_DefaultWebOptions);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_WebOptionsPtr& TAccessWebOptions::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAccessWebOptions::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAccessWebOptions::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAccessWebOptions::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAccessWebOptions::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAccessWebOptions::ConnectTo(_WebOptionsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAccessWebOptions::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AccessWebOptions;
  sd.IntfIID = __uuidof(_WebOptions);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_PrinterPtr& TPrinter::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TPrinter::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TPrinter::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TPrinter::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TPrinter::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TPrinter::ConnectTo(_PrinterPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TPrinter::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_Printer;
  sd.IntfIID = __uuidof(_Printer);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_Form2Ptr& TAccessForm::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAccessForm::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAccessForm::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAccessForm::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAccessForm::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAccessForm::ConnectTo(_Form2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAccessForm::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AccessForm;
  sd.IntfIID = __uuidof(_Form2);
  sd.EventIID= __uuidof(_FormEvents);
  ServerData = &sd;
}

void __fastcall TAccessForm::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 2067: {
      if (OnLoad1) {
        (OnLoad1)(this);
      }
      break;
      }
    case 2058: {
      if (OnCurrent1) {
        (OnCurrent1)(this);
      }
      break;
      }
    case 2059: {
      if (OnBeforeInsert) {
        (OnBeforeInsert)(this, TVariant(params[0]));
      }
      break;
      }
    case 2060: {
      if (OnAfterInsert) {
        (OnAfterInsert)(this);
      }
      break;
      }
    case 2061: {
      if (OnBeforeUpdate) {
        (OnBeforeUpdate)(this, TVariant(params[0]));
      }
      break;
      }
    case 2062: {
      if (OnAfterUpdate) {
        (OnAfterUpdate)(this);
      }
      break;
      }
    case 2063: {
      if (OnDelete1) {
        (OnDelete1)(this, TVariant(params[0]));
      }
      break;
      }
    case 2064: {
      if (OnBeforeDelConfirm) {
        (OnBeforeDelConfirm)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2065: {
      if (OnAfterDelConfirm) {
        (OnAfterDelConfirm)(this, TVariant(params[0]));
      }
      break;
      }
    case 2066: {
      if (OnOpen1) {
        (OnOpen1)(this, TVariant(params[0]));
      }
      break;
      }
    case 2068: {
      if (OnResize1) {
        (OnResize1)(this);
      }
      break;
      }
    case 2069: {
      if (OnUnload1) {
        (OnUnload1)(this, TVariant(params[0]));
      }
      break;
      }
    case 2070: {
      if (OnClose1) {
        (OnClose1)(this);
      }
      break;
      }
    case 2071: {
      if (OnActivate1) {
        (OnActivate1)(this);
      }
      break;
      }
    case 2072: {
      if (OnDeactivate1) {
        (OnDeactivate1)(this);
      }
      break;
      }
    case 2073: {
      if (OnGotFocus1) {
        (OnGotFocus1)(this);
      }
      break;
      }
    case 2074: {
      if (OnLostFocus1) {
        (OnLostFocus1)(this);
      }
      break;
      }
    case -600: {
      if (OnClick1) {
        (OnClick1)(this);
      }
      break;
      }
    case -601: {
      if (OnDblClick1) {
        (OnDblClick1)(this, TVariant(params[0]));
      }
      break;
      }
    case -605: {
      if (OnMouseDown1) {
        (OnMouseDown1)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]));
      }
      break;
      }
    case -606: {
      if (OnMouseMove1) {
        (OnMouseMove1)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]));
      }
      break;
      }
    case -607: {
      if (OnMouseUp1) {
        (OnMouseUp1)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]));
      }
      break;
      }
    case -602: {
      if (OnKeyDown1) {
        (OnKeyDown1)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case -603: {
      if (OnKeyPress1) {
        (OnKeyPress1)(this, TVariant(params[0]));
      }
      break;
      }
    case -604: {
      if (OnKeyUp1) {
        (OnKeyUp1)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2083: {
      if (OnError1) {
        (OnError1)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2084: {
      if (OnTimer1) {
        (OnTimer1)(this);
      }
      break;
      }
    case 2155: {
      if (OnFilter1) {
        (OnFilter1)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2156: {
      if (OnApplyFilter1) {
        (OnApplyFilter1)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2205: {
      if (OnDirty1) {
        (OnDirty1)(this, TVariant(params[0]));
      }
      break;
      }
    case 2145: {
      if (OnUndo1) {
        (OnUndo1)(this, TVariant(params[0]));
      }
      break;
      }
    case 2334: {
      if (OnRecordExit1) {
        (OnRecordExit1)(this, TVariant(params[0]));
      }
      break;
      }
    case 2369: {
      if (OnBeginBatchEdit) {
        (OnBeginBatchEdit)(this, TVariant(params[0]));
      }
      break;
      }
    case 2370: {
      if (OnUndoBatchEdit) {
        (OnUndoBatchEdit)(this, TVariant(params[0]));
      }
      break;
      }
    case 2371: {
      if (OnBeforeBeginTransaction) {
        IDispatch* tmp1 = TVariant(params[1]);
        (OnBeforeBeginTransaction)(this, TVariant(params[0]), (Adodb_xp::Connection**)&tmp1);
      }
      break;
      }
    case 2372: {
      if (OnAfterBeginTransaction) {
        IDispatch* tmp0 = TVariant(params[0]);
        (OnAfterBeginTransaction)(this, (Adodb_xp::Connection**)&tmp0);
      }
      break;
      }
    case 2373: {
      if (OnBeforeCommitTransaction) {
        IDispatch* tmp1 = TVariant(params[1]);
        (OnBeforeCommitTransaction)(this, TVariant(params[0]), (Adodb_xp::Connection**)&tmp1);
      }
      break;
      }
    case 2374: {
      if (OnAfterCommitTransaction) {
        IDispatch* tmp0 = TVariant(params[0]);
        (OnAfterCommitTransaction)(this, (Adodb_xp::Connection**)&tmp0);
      }
      break;
      }
    case 2375: {
      if (OnRollbackTransaction) {
        IDispatch* tmp0 = TVariant(params[0]);
        (OnRollbackTransaction)(this, (Adodb_xp::Connection**)&tmp0);
      }
      break;
      }
    case 2383: {
      if (OnConnect1) {
        (OnConnect1)(this);
      }
      break;
      }
    case 2384: {
      if (OnDisconnect1) {
        (OnDisconnect1)(this);
      }
      break;
      }
    case 2385: {
      if (OnPivotTableChange) {
        (OnPivotTableChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 2386: {
      if (OnQuery) {
        (OnQuery)(this);
      }
      break;
      }
    case 2387: {
      if (OnBeforeQuery) {
        (OnBeforeQuery)(this);
      }
      break;
      }
    case 2388: {
      if (OnSelectionChange) {
        (OnSelectionChange)(this);
      }
      break;
      }
    case 2389: {
      if (OnCommandBeforeExecute) {
        (OnCommandBeforeExecute)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2390: {
      if (OnCommandChecked) {
        (OnCommandChecked)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2391: {
      if (OnCommandEnabled) {
        (OnCommandEnabled)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2392: {
      if (OnCommandExecute) {
        (OnCommandExecute)(this, TVariant(params[0]));
      }
      break;
      }
    case 2394: {
      if (OnDataSetChange) {
        (OnDataSetChange)(this);
      }
      break;
      }
    case 2395: {
      if (OnBeforeScreenTip) {
        (OnBeforeScreenTip)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2399: {
      if (OnBeforeRender) {
        (OnBeforeRender)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]));
      }
      break;
      }
    case 2397: {
      if (OnAfterRender) {
        (OnAfterRender)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2396: {
      if (OnAfterFinalRender) {
        (OnAfterFinalRender)(this, TVariant(params[0]));
      }
      break;
      }
    case 2398: {
      if (OnAfterLayout) {
        (OnAfterLayout)(this, TVariant(params[0]));
      }
      break;
      }
    case 2401: {
      if (OnMouseWheel) {
        (OnMouseWheel)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2402: {
      if (OnViewChange) {
        (OnViewChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 2403: {
      if (OnDataChange) {
        (OnDataChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

_Report2Ptr& TAccessReport::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAccessReport::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAccessReport::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAccessReport::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAccessReport::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAccessReport::ConnectTo(_Report2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAccessReport::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AccessReport;
  sd.IntfIID = __uuidof(_Report2);
  sd.EventIID= __uuidof(_ReportEvents);
  ServerData = &sd;
}

void __fastcall TAccessReport::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 2066: {
      if (OnOpen1) {
        (OnOpen1)(this, TVariant(params[0]));
      }
      break;
      }
    case 2070: {
      if (OnClose1) {
        (OnClose1)(this);
      }
      break;
      }
    case 2071: {
      if (OnActivate1) {
        (OnActivate1)(this);
      }
      break;
      }
    case 2072: {
      if (OnDeactivate1) {
        (OnDeactivate1)(this);
      }
      break;
      }
    case 2083: {
      if (OnError1) {
        (OnError1)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2161: {
      if (OnNoData1) {
        (OnNoData1)(this, TVariant(params[0]));
      }
      break;
      }
    case 2162: {
      if (OnPage1) {
        (OnPage1)(this);
      }
      break;
      }
    default:
      break;
  }
}

AllObjectsPtr& TAllFunctions::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAllFunctions::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAllFunctions::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAllFunctions::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAllFunctions::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAllFunctions::ConnectTo(AllObjectsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAllFunctions::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AllFunctions;
  sd.IntfIID = __uuidof(AllObjects);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}


};     // namespace Access_xp


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Access_xp_srvr
{

void __fastcall PACKAGE Register()
{
  // [25]
  TComponentClass cls_svr[] = {
                              __classid(Access_xp::TFormatCondition), 
                              __classid(Access_xp::TAccessHyperlink), 
                              __classid(Access_xp::TAccessApplication), 
                              __classid(Access_xp::TAccessReferences), 
                              __classid(Access_xp::TDataAccessPage), 
                              __classid(Access_xp::TAllForms), 
                              __classid(Access_xp::TAllReports), 
                              __classid(Access_xp::TAllMacros), 
                              __classid(Access_xp::TAllModules), 
                              __classid(Access_xp::TAllDataAccessPages), 
                              __classid(Access_xp::TAllTables), 
                              __classid(Access_xp::TAllQueries), 
                              __classid(Access_xp::TAllViews), 
                              __classid(Access_xp::TAllStoredProcedures), 
                              __classid(Access_xp::TAllDatabaseDiagrams), 
                              __classid(Access_xp::TCurrentProject), 
                              __classid(Access_xp::TCurrentData), 
                              __classid(Access_xp::TCodeProject), 
                              __classid(Access_xp::TCodeData), 
                              __classid(Access_xp::TDefaultWebOptions), 
                              __classid(Access_xp::TAccessWebOptions), 
                              __classid(Access_xp::TPrinter), 
                              __classid(Access_xp::TAccessForm), 
                              __classid(Access_xp::TAccessReport), 
                              __classid(Access_xp::TAllFunctions)
                           };
  RegisterComponents("OfficeXP", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Access_xp_srvr
