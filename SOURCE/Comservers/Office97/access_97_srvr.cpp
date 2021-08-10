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
// File generated on 1/28/2002 7:56:00 AM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office\msacc8.olb (1)
// LIBID: {4AFFC9A0-5F99-101B-AF4E-00AA003F0F07}
// LCID: 0
// Helpfile: C:\Program Files\Microsoft Office\Office\acvba80.hlp
// HelpString: Microsoft Access 8.0 Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v4.0 DAO, (C:\Program Files\Common Files\Microsoft Shared\DAO\DAO350.DLL)
//   (3) v2.0 Office, (C:\Program Files\Microsoft Office\office97\Office\MSO97.DLL)
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
//   Hint: Symbol 'Form' renamed to 'AccessForm'
//   Hint: Symbol 'Forms' renamed to 'Forms_'
//   Hint: Symbol 'Report' renamed to 'AccessReport'
//   Hint: Symbol 'Application' renamed to 'AccessApplication'
//   Hint: Symbol 'References' renamed to 'AccessReferences'
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
//   Hint: Symbol 'Form' renamed to 'AccessForm'
//   Hint: Symbol 'Forms' renamed to 'Forms_'
//   Hint: Symbol 'Report' renamed to 'AccessReport'
//   Hint: Symbol 'Application' renamed to 'AccessApplication'
//   Hint: Symbol 'References' renamed to 'AccessReferences'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "Access_97_SRVR.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Access_97
{

IDoCmdPtr& TDoCmd::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TDoCmd::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TDoCmd::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TDoCmd::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TDoCmd::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TDoCmd::ConnectTo(IDoCmdPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TDoCmd::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_DoCmd;
  sd.IntfIID = __uuidof(IDoCmd);
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

_FormPtr& TAccessForm::GetDefaultInterface()
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

void __fastcall TAccessForm::ConnectTo(_FormPtr intf)
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
  sd.IntfIID = __uuidof(_Form);
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
    default:
      break;
  }
}

_ReportPtr& TAccessReport::GetDefaultInterface()
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

void __fastcall TAccessReport::ConnectTo(_ReportPtr intf)
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
  sd.IntfIID = __uuidof(_Report);
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
        (OnItemAdded)(this, (Access_97::Reference*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 1: {
      if (OnItemRemoved) {
        (OnItemRemoved)(this, (Access_97::Reference*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}


};     // namespace Access_97


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Access_97_srvr
{

void __fastcall PACKAGE Register()
{
  // [6]
  TComponentClass cls_svr[] = {
                              __classid(Access_97::TDoCmd), 
                              __classid(Access_97::TAccessHyperlink), 
                              __classid(Access_97::TAccessForm), 
                              __classid(Access_97::TAccessReport), 
                              __classid(Access_97::TAccessApplication), 
                              __classid(Access_97::TAccessReferences)
                           };
  RegisterComponents("Office97", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Access_97_srvr
