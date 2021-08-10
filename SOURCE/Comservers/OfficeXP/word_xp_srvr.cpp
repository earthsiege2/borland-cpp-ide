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
// File generated on 1/29/2002 1:28:29 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office10\msword.olb (1)
// LIBID: {00020905-0000-0000-C000-000000000046}
// LCID: 0
// Helpfile: c:\program files\microsoft office\office10\VBAWD10.CHM
// HelpString: Microsoft Word 10.0 Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v2.2 Office, (C:\Program Files\Common Files\Microsoft Shared\Office10\MSO.DLL)
//   (3) v5.3 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB)
// Errors:
//   Hint: Symbol 'Window' renamed to 'WINDOW'
//   Hint: Symbol 'System' renamed to 'SYSTEM'
//   Hint: Symbol 'Global' renamed to 'WordGlobal'
//   Hint: Symbol 'Application' renamed to 'WordApplication'
//   Hint: Symbol 'Document' renamed to 'WordDocument'
//   Hint: Symbol 'Font' renamed to 'WordFont'
//   Hint: Symbol 'ParagraphFormat' renamed to 'WordParagraphFormat'
//   Hint: Symbol 'OLEControl' renamed to 'WordOLEControl'
//   Hint: Symbol 'LetterContent' renamed to 'WordLetterContent'
//   Hint: Enum Member 'emptyenum' of 'WdCharacterCaseHID' changed to 'emptyenum_'
//   Hint: Enum Member 'emptyenum' of 'WdParagraphAlignmentHID' changed to 'emptyenum__'
//   Hint: Enum Member 'emptyenum' of 'WdListNumberStyleHID' changed to 'emptyenum___'
//   Hint: Enum Member 'emptyenum' of 'WdNoteNumberStyleHID' changed to 'emptyenum____'
//   Hint: Enum Member 'emptyenum' of 'WdCaptionNumberStyleHID' changed to 'emptyenum_____'
//   Hint: Enum Member 'emptyenum' of 'WdPageNumberStyleHID' changed to 'emptyenum______'
//   Hint: Enum Member 'emptyenum' of 'WdStatisticHID' changed to 'emptyenum_______'
//   Hint: Enum Member 'emptyenum' of 'WdTabLeaderHID' changed to 'emptyenum________'
//   Hint: Enum Member 'emptyenum' of 'WdMeasurementUnitsHID' changed to 'emptyenum_________'
//   Hint: Enum Member 'emptyenum' of 'WdSortFieldTypeHID' changed to 'emptyenum__________'
//   Hint: Enum Member 'emptyenum' of 'WdWordDialogHID' changed to 'emptyenum___________'
//   Hint: Enum Member 'emptyenum' of 'WdHelpTypeHID' changed to 'emptyenum____________'
//   Hint: Enum Member 'emptyenum' of 'WdDictionaryTypeHID' changed to 'emptyenum_____________'
//   Hint: Enum Member 'emptyenum' of 'WdTextOrientationHID' changed to 'emptyenum______________'
//   Hint: Symbol 'ExitWindows' renamed to 'ExitWindoz'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Window' renamed to 'WINDOW'
//   Hint: Symbol 'System' renamed to 'SYSTEM'
//   Hint: Symbol 'Global' renamed to 'WordGlobal'
//   Hint: Symbol 'Application' renamed to 'WordApplication'
//   Hint: Symbol 'Document' renamed to 'WordDocument'
//   Hint: Symbol 'Font' renamed to 'WordFont'
//   Hint: Symbol 'ParagraphFormat' renamed to 'WordParagraphFormat'
//   Hint: Symbol 'OLEControl' renamed to 'WordOLEControl'
//   Hint: Symbol 'LetterContent' renamed to 'WordLetterContent'
//   Hint: Enum Member 'emptyenum' of 'WdCharacterCaseHID' changed to 'emptyenum_'
//   Hint: Enum Member 'emptyenum' of 'WdParagraphAlignmentHID' changed to 'emptyenum__'
//   Hint: Enum Member 'emptyenum' of 'WdListNumberStyleHID' changed to 'emptyenum___'
//   Hint: Enum Member 'emptyenum' of 'WdNoteNumberStyleHID' changed to 'emptyenum____'
//   Hint: Enum Member 'emptyenum' of 'WdCaptionNumberStyleHID' changed to 'emptyenum_____'
//   Hint: Enum Member 'emptyenum' of 'WdPageNumberStyleHID' changed to 'emptyenum______'
//   Hint: Enum Member 'emptyenum' of 'WdStatisticHID' changed to 'emptyenum_______'
//   Hint: Enum Member 'emptyenum' of 'WdTabLeaderHID' changed to 'emptyenum________'
//   Hint: Enum Member 'emptyenum' of 'WdMeasurementUnitsHID' changed to 'emptyenum_________'
//   Hint: Enum Member 'emptyenum' of 'WdSortFieldTypeHID' changed to 'emptyenum__________'
//   Hint: Enum Member 'emptyenum' of 'WdWordDialogHID' changed to 'emptyenum___________'
//   Hint: Enum Member 'emptyenum' of 'WdHelpTypeHID' changed to 'emptyenum____________'
//   Hint: Enum Member 'emptyenum' of 'WdDictionaryTypeHID' changed to 'emptyenum_____________'
//   Hint: Enum Member 'emptyenum' of 'WdTextOrientationHID' changed to 'emptyenum______________'
//   Hint: Symbol 'ExitWindows' renamed to 'ExitWindoz'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "Word_XP_srvr.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Word_xp
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
  sd.EventIID= __uuidof(ApplicationEvents3);
  ServerData = &sd;
}

void __fastcall TWordApplication::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnStartup) {
        (OnStartup)(this);
      }
      break;
      }
    case 2: {
      if (OnQuit) {
        (OnQuit)(this);
      }
      break;
      }
    case 3: {
      if (OnDocumentChange) {
        (OnDocumentChange)(this);
      }
      break;
      }
    case 4: {
      if (OnDocumentOpen) {
        (OnDocumentOpen)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 6: {
      if (OnDocumentBeforeClose) {
        (OnDocumentBeforeClose)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 7: {
      if (OnDocumentBeforePrint) {
        (OnDocumentBeforePrint)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 8: {
      if (OnDocumentBeforeSave) {
        (OnDocumentBeforeSave)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]));
      }
      break;
      }
    case 9: {
      if (OnNewDocument) {
        (OnNewDocument)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 10: {
      if (OnWindowActivate) {
        (OnWindowActivate)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), (Word_xp::WINDOW*)(LPDISPATCH)TVariant(params[1]));
      }
      break;
      }
    case 11: {
      if (OnWindowDeactivate) {
        (OnWindowDeactivate)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), (Word_xp::WINDOW*)(LPDISPATCH)TVariant(params[1]));
      }
      break;
      }
    case 12: {
      if (OnWindowSelectionChange) {
        (OnWindowSelectionChange)(this, (Word_xp::Selection*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 13: {
      if (OnWindowBeforeRightClick) {
        (OnWindowBeforeRightClick)(this, (Word_xp::Selection*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 14: {
      if (OnWindowBeforeDoubleClick) {
        (OnWindowBeforeDoubleClick)(this, (Word_xp::Selection*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 15: {
      if (OnEPostagePropertyDialog) {
        (OnEPostagePropertyDialog)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 16: {
      if (OnEPostageInsert) {
        (OnEPostageInsert)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 17: {
      if (OnMailMergeAfterMerge) {
        (OnMailMergeAfterMerge)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[1]));
      }
      break;
      }
    case 18: {
      if (OnMailMergeAfterRecordMerge) {
        (OnMailMergeAfterRecordMerge)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 19: {
      if (OnMailMergeBeforeMerge) {
        (OnMailMergeBeforeMerge)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]));
      }
      break;
      }
    case 20: {
      if (OnMailMergeBeforeRecordMerge) {
        (OnMailMergeBeforeRecordMerge)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 21: {
      if (OnMailMergeDataSourceLoad) {
        (OnMailMergeDataSourceLoad)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 22: {
      if (OnMailMergeDataSourceValidate) {
        (OnMailMergeDataSourceValidate)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 23: {
      if (OnMailMergeWizardSendToCustom) {
        (OnMailMergeWizardSendToCustom)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 24: {
      if (OnMailMergeWizardStateChange) {
        (OnMailMergeWizardStateChange)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]));
      }
      break;
      }
    case 25: {
      if (OnWindowSize) {
        (OnWindowSize)(this, (Word_xp::WordDocument*)(LPDISPATCH)TVariant(params[0]), (Word_xp::WINDOW*)(LPDISPATCH)TVariant(params[1]));
      }
      break;
      }
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

void __fastcall TWordDocument::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 4: {
      if (OnNew) {
        (OnNew)(this);
      }
      break;
      }
    case 5: {
      if (OnOpen) {
        (OnOpen)(this);
      }
      break;
      }
    case 6: {
      if (OnClose) {
        (OnClose)(this);
      }
      break;
      }
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


};     // namespace Word_xp


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Word_xp_srvr
{

void __fastcall PACKAGE Register()
{
  // [6]
  TComponentClass cls_svr[] = {
                              __classid(Word_xp::TWordGlobal), 
                              __classid(Word_xp::TWordApplication), 
                              __classid(Word_xp::TWordDocument), 
                              __classid(Word_xp::TWordFont), 
                              __classid(Word_xp::TWordParagraphFormat), 
                              __classid(Word_xp::TWordLetterContent)
                           };
  RegisterComponents("OfficeXP", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Word_xp_srvr
