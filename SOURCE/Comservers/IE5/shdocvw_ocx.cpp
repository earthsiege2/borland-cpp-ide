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
// File generated on 1/24/2002 7:03:49 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: ..\typelibraries\shdocvw.dll (1)
// LIBID: {EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}
// LCID: 0
// Helpfile: 
// HelpString: Microsoft Internet Controls
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
// Errors:
//   Hint: Symbol 'WebBrowser_V1' renamed to 'CppWebBrowser_V1'
//   Hint: Symbol 'WebBrowser' renamed to 'CppWebBrowser'
//   Hint: Symbol 'InternetExplorer' renamed to 'CppInternetExplorer'
//   Hint: Symbol 'ShellBrowserWindow' renamed to 'CppShellBrowserWindow'
//   Hint: Symbol 'ShellWindows' renamed to 'CppShellWindows'
//   Hint: Symbol 'ShellUIHelper' renamed to 'CppShellUIHelper'
//   Hint: Symbol 'ShellNameSpace' renamed to 'ShellFavoritesNameSpace'
//   Hint: Symbol 'CScriptErrorList' renamed to 'CppCScriptErrorList'
//   Hint: Symbol 'SearchAssistantOC' renamed to 'CppSearchAssistantOC'
//   Hint: Symbol 'WebBrowser_V1' renamed to 'CppWebBrowser_V1'
//   Hint: Symbol 'WebBrowser' renamed to 'CppWebBrowser'
//   Hint: Symbol 'InternetExplorer' renamed to 'CppInternetExplorer'
//   Hint: Symbol 'ShellBrowserWindow' renamed to 'CppShellBrowserWindow'
//   Hint: Symbol 'ShellWindows' renamed to 'CppShellWindows'
//   Hint: Symbol 'ShellUIHelper' renamed to 'CppShellUIHelper'
//   Hint: Symbol 'ShellNameSpace' renamed to 'ShellFavoritesNameSpace'
//   Hint: Symbol 'CScriptErrorList' renamed to 'CppCScriptErrorList'
//   Hint: Symbol 'SearchAssistantOC' renamed to 'CppSearchAssistantOC'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <olectrls.hpp>
#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "SHDocVw_OCX.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Shdocvw_tlb
{



// *********************************************************************//
// OCX PROXY CLASS IMPLEMENTATION
// (The following variables/methods implement the class TCppWebBrowser_V1 which
// allows "WebBrowser Control" to be hosted in CBuilder IDE/apps).
// *********************************************************************//
int   TCppWebBrowser_V1::EventDispIDs[17] = {
    0x00000064, 0x00000065, 0x00000066, 0x0000006C, 0x00000068, 0x00000069,
    0x0000006A, 0x0000006B, 0x00000071, 0x000000C8, 0x000000C9, 0x000000CC,
    0x00000067, 0x0000006D, 0x0000006E, 0x0000006F, 0x00000070};

TControlData TCppWebBrowser_V1::CControlData =
{
  // GUID of CoClass and Event Interface of Control
  {0xEAB22AC3, 0x30C1, 0x11CF,{ 0xA7, 0xEB, 0x00,0x00, 0xC0, 0x5B,0xAE, 0x0B} }, // CoClass
  {0xEAB22AC2, 0x30C1, 0x11CF,{ 0xA7, 0xEB, 0x00,0x00, 0xC0, 0x5B,0xAE, 0x0B} }, // Events

  // Count of Events and array of their DISPIDs
  17, &EventDispIDs,

  // Pointer to Runtime License string
  NULL,  // HRESULT(0x80040111)

  // Flags for OnChanged PropertyNotification
  0x00000000,
  300,// (IDE Version)

  // Count of Font Prop and array of their DISPIDs
  0, NULL,

  // Count of Pict Prop and array of their DISPIDs
  0, NULL,
  0, // Reserved
  0, // Instance count (used internally)
  0, // List of Enum descriptions (internal)
};

GUID     TCppWebBrowser_V1::DEF_CTL_INTF = {0xEAB22AC1, 0x30C1, 0x11CF,{ 0xA7, 0xEB, 0x00,0x00, 0xC0, 0x5B,0xAE, 0x0B} };
TNoParam TCppWebBrowser_V1::OptParam;

static inline void ValidCtrCheck(TCppWebBrowser_V1 *)
{
   delete new TCppWebBrowser_V1((TComponent*)(0));
};

void __fastcall TCppWebBrowser_V1::InitControlData()
{
  ControlData = &CControlData;
};

void __fastcall TCppWebBrowser_V1::CreateControl()
{
  if (!m_OCXIntf)
  {
    _ASSERTE(DefaultDispatch);
    DefaultDispatch->QueryInterface(DEF_CTL_INTF, (LPVOID*)&m_OCXIntf);
  }
};

TCOMIWebBrowser __fastcall TCppWebBrowser_V1::GetDefaultInterface()
{
  CreateControl();
  return m_OCXIntf;
};

void __fastcall TCppWebBrowser_V1::GoBack(void)
{
  GetDefaultInterface()->GoBack();
}

void __fastcall TCppWebBrowser_V1::GoForward(void)
{
  GetDefaultInterface()->GoForward();
}

void __fastcall TCppWebBrowser_V1::GoHome(void)
{
  GetDefaultInterface()->GoHome();
}

void __fastcall TCppWebBrowser_V1::GoSearch(void)
{
  GetDefaultInterface()->GoSearch();
}

void __fastcall TCppWebBrowser_V1::Navigate(BSTR URL/*[in]*/, VARIANT* Flags/*[in,opt]*/, 
                                            VARIANT* TargetFrameName/*[in,opt]*/, 
                                            VARIANT* PostData/*[in,opt]*/, 
                                            VARIANT* Headers/*[in,opt]*/)
{
  GetDefaultInterface()->Navigate(URL/*[in]*/, Flags/*[in,opt]*/, TargetFrameName/*[in,opt]*/, 
                                  PostData/*[in,opt]*/, Headers/*[in,opt]*/);
}

void __fastcall TCppWebBrowser_V1::Refresh(void)
{
  GetDefaultInterface()->Refresh();
}

void __fastcall TCppWebBrowser_V1::Refresh2(VARIANT* Level/*[in,opt]*/)
{
  GetDefaultInterface()->Refresh2(Level/*[in,opt]*/);
}

void __fastcall TCppWebBrowser_V1::Stop(void)
{
  GetDefaultInterface()->Stop();
}

// StdProp:IDispatch
LPDISPATCH __fastcall TCppWebBrowser_V1::get_Application(void)
{
  return GetDefaultInterface()->get_Application();
}

// StdProp:IDispatch
LPDISPATCH __fastcall TCppWebBrowser_V1::get_Parent(void)
{
  return GetDefaultInterface()->get_Parent();
}

// StdProp:IDispatch
LPDISPATCH __fastcall TCppWebBrowser_V1::get_Container(void)
{
  return GetDefaultInterface()->get_Container();
}

// StdProp:IDispatch
LPDISPATCH __fastcall TCppWebBrowser_V1::get_Document(void)
{
  return GetDefaultInterface()->get_Document();
}



// *********************************************************************//
// OCX PROXY CLASS IMPLEMENTATION
// (The following variables/methods implement the class TCppWebBrowser which
// allows "WebBrowser Control" to be hosted in CBuilder IDE/apps).
// *********************************************************************//
int   TCppWebBrowser::EventDispIDs[32] = {
    0x00000066, 0x0000006C, 0x00000069, 0x0000006A, 0x00000068, 0x00000071,
    0x00000070, 0x000000FA, 0x000000FB, 0x000000FC, 0x00000103, 0x000000FD,
    0x000000FE, 0x000000FF, 0x00000100, 0x00000101, 0x00000102, 0x00000104,
    0x00000106, 0x00000108, 0x00000109, 0x0000010A, 0x0000010B, 0x00000107,
    0x0000010C, 0x0000010D, 0x0000010E, 0x0000010F, 0x000000E1, 0x000000E2,
    0x000000E3, 0x00000110};

TControlData TCppWebBrowser::CControlData =
{
  // GUID of CoClass and Event Interface of Control
  {0x8856F961, 0x340A, 0x11D0,{ 0xA9, 0x6B, 0x00,0xC0, 0x4F, 0xD7,0x05, 0xA2} }, // CoClass
  {0x34A715A0, 0x6587, 0x11D0,{ 0x92, 0x4A, 0x00,0x20, 0xAF, 0xC7,0xAC, 0x4D} }, // Events

  // Count of Events and array of their DISPIDs
  32, &EventDispIDs,

  // Pointer to Runtime License string
  NULL,  // HRESULT(0x80040111)

  // Flags for OnChanged PropertyNotification
  0x00000000,
  300,// (IDE Version)

  // Count of Font Prop and array of their DISPIDs
  0, NULL,

  // Count of Pict Prop and array of their DISPIDs
  0, NULL,
  0, // Reserved
  0, // Instance count (used internally)
  0, // List of Enum descriptions (internal)
};

GUID     TCppWebBrowser::DEF_CTL_INTF = {0xD30C1661, 0xCDAF, 0x11D0,{ 0x8A, 0x3E, 0x00,0xC0, 0x4F, 0xC9,0xE2, 0x6E} };
TNoParam TCppWebBrowser::OptParam;

static inline void ValidCtrCheck(TCppWebBrowser *)
{
   delete new TCppWebBrowser((TComponent*)(0));
};

void __fastcall TCppWebBrowser::InitControlData()
{
  ControlData = &CControlData;
};

void __fastcall TCppWebBrowser::CreateControl()
{
  if (!m_OCXIntf)
  {
    _ASSERTE(DefaultDispatch);
    DefaultDispatch->QueryInterface(DEF_CTL_INTF, (LPVOID*)&m_OCXIntf);
  }
};

IWebBrowser2Disp __fastcall TCppWebBrowser::GetDefaultInterface()
{
  CreateControl();
  return m_OCXIntf;
};

void __fastcall TCppWebBrowser::GoBack(void)
{
  GetDefaultInterface()->GoBack();
}

void __fastcall TCppWebBrowser::GoForward(void)
{
  GetDefaultInterface()->GoForward();
}

void __fastcall TCppWebBrowser::GoHome(void)
{
  GetDefaultInterface()->GoHome();
}

void __fastcall TCppWebBrowser::GoSearch(void)
{
  GetDefaultInterface()->GoSearch();
}

void __fastcall TCppWebBrowser::Navigate(BSTR URL/*[in]*/, VARIANT* Flags/*[in,opt]*/, 
                                         VARIANT* TargetFrameName/*[in,opt]*/, 
                                         VARIANT* PostData/*[in,opt]*/, VARIANT* Headers/*[in,opt]*/)
{
  GetDefaultInterface()->Navigate(URL/*[in]*/, Flags/*[in,opt]*/, TargetFrameName/*[in,opt]*/, 
                                  PostData/*[in,opt]*/, Headers/*[in,opt]*/);
}

void __fastcall TCppWebBrowser::Refresh(void)
{
  GetDefaultInterface()->Refresh();
}

void __fastcall TCppWebBrowser::Refresh2(VARIANT* Level/*[in,opt]*/)
{
  GetDefaultInterface()->Refresh2(Level/*[in,opt]*/);
}

void __fastcall TCppWebBrowser::Stop(void)
{
  GetDefaultInterface()->Stop();
}

void __fastcall TCppWebBrowser::Quit(void)
{
  GetDefaultInterface()->Quit();
}

void __fastcall TCppWebBrowser::ClientToWindow(int* pcx/*[in,out]*/, int* pcy/*[in,out]*/)
{
  GetDefaultInterface()->ClientToWindow(pcx/*[in,out]*/, pcy/*[in,out]*/);
}

void __fastcall TCppWebBrowser::PutProperty(BSTR Property/*[in]*/, VARIANT vtValue/*[in]*/)
{
  GetDefaultInterface()->PutProperty(Property/*[in]*/, vtValue/*[in]*/);
}

TVariant __fastcall TCppWebBrowser::GetProperty(BSTR Property/*[in]*/)
{
  return GetDefaultInterface()->GetProperty(Property/*[in]*/);
}

void __fastcall TCppWebBrowser::Navigate2(VARIANT* URL/*[in]*/, VARIANT* Flags/*[in,opt]*/, 
                                          VARIANT* TargetFrameName/*[in,opt]*/, 
                                          VARIANT* PostData/*[in,opt]*/, 
                                          VARIANT* Headers/*[in,opt]*/)
{
  GetDefaultInterface()->Navigate2(URL/*[in]*/, Flags/*[in,opt]*/, TargetFrameName/*[in,opt]*/, 
                                   PostData/*[in,opt]*/, Headers/*[in,opt]*/);
}

Shdocvw_tlb::OLECMDF __fastcall TCppWebBrowser::QueryStatusWB(Shdocvw_tlb::OLECMDID cmdID/*[in]*/)
{
  return GetDefaultInterface()->QueryStatusWB(cmdID/*[in]*/);
}

void __fastcall TCppWebBrowser::ExecWB(Shdocvw_tlb::OLECMDID cmdID/*[in]*/, 
                                       Shdocvw_tlb::OLECMDEXECOPT cmdexecopt/*[in]*/, 
                                       VARIANT* pvaIn/*[in,opt]*/, VARIANT* pvaOut/*[in,out,opt]*/)
{
  GetDefaultInterface()->ExecWB(cmdID/*[in]*/, cmdexecopt/*[in]*/, pvaIn/*[in,opt]*/, 
                                pvaOut/*[in,out,opt]*/);
}

void __fastcall TCppWebBrowser::ShowBrowserBar(VARIANT* pvaClsid/*[in]*/, 
                                               VARIANT* pvarShow/*[in,opt]*/, 
                                               VARIANT* pvarSize/*[in,opt]*/)
{
  GetDefaultInterface()->ShowBrowserBar(pvaClsid/*[in]*/, pvarShow/*[in,opt]*/, pvarSize/*[in,opt]*/);
}

// StdProp:IDispatch
LPDISPATCH __fastcall TCppWebBrowser::get_Application(void)
{
  return GetDefaultInterface()->get_Application();
}

// StdProp:IDispatch
LPDISPATCH __fastcall TCppWebBrowser::get_Parent(void)
{
  return GetDefaultInterface()->get_Parent();
}

// StdProp:IDispatch
LPDISPATCH __fastcall TCppWebBrowser::get_Container(void)
{
  return GetDefaultInterface()->get_Container();
}

// StdProp:IDispatch
LPDISPATCH __fastcall TCppWebBrowser::get_Document(void)
{
  return GetDefaultInterface()->get_Document();
}

IWebBrowser2Ptr& TCppInternetExplorer::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCppInternetExplorer::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCppInternetExplorer::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCppInternetExplorer::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCppInternetExplorer::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCppInternetExplorer::ConnectTo(IWebBrowser2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCppInternetExplorer::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CppInternetExplorer;
  sd.IntfIID = __uuidof(IWebBrowser2);
  sd.EventIID= __uuidof(DWebBrowserEvents2);
  ServerData = &sd;
}

void __fastcall TCppInternetExplorer::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 102: {
      if (OnStatusTextChange) {
        (OnStatusTextChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 108: {
      if (OnProgressChange) {
        (OnProgressChange)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 105: {
      if (OnCommandStateChange) {
        (OnCommandStateChange)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 106: {
      if (OnDownloadBegin) {
        (OnDownloadBegin)(this);
      }
      break;
      }
    case 104: {
      if (OnDownloadComplete) {
        (OnDownloadComplete)(this);
      }
      break;
      }
    case 113: {
      if (OnTitleChange) {
        (OnTitleChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 112: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 250: {
      if (OnBeforeNavigate2) {
        (OnBeforeNavigate2)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]), TVariant(params[4]), TVariant(params[5]), TVariant(params[6]));
      }
      break;
      }
    case 251: {
      if (OnNewWindow2) {
        IDispatch* tmp;
        (OnNewWindow2)(this, &tmp, TVariant(params[1]));
      }
      break;
      }
    case 252: {
      if (OnNavigateComplete2) {
        (OnNavigateComplete2)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 259: {
      if (OnDocumentComplete) {
        (OnDocumentComplete)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 253: {
      if (OnQuit) {
        (OnQuit)(this);
      }
      break;
      }
    case 254: {
      if (OnVisible) {
        (OnVisible)(this, TVariant(params[0]));
      }
      break;
      }
    case 255: {
      if (OnToolBar) {
        (OnToolBar)(this, TVariant(params[0]));
      }
      break;
      }
    case 256: {
      if (OnMenuBar) {
        (OnMenuBar)(this, TVariant(params[0]));
      }
      break;
      }
    case 257: {
      if (OnStatusBar) {
        (OnStatusBar)(this, TVariant(params[0]));
      }
      break;
      }
    case 258: {
      if (OnFullScreen) {
        (OnFullScreen)(this, TVariant(params[0]));
      }
      break;
      }
    case 260: {
      if (OnTheaterMode) {
        (OnTheaterMode)(this, TVariant(params[0]));
      }
      break;
      }
    case 262: {
      if (OnWindowSetResizable) {
        (OnWindowSetResizable)(this, TVariant(params[0]));
      }
      break;
      }
    case 264: {
      if (OnWindowSetLeft) {
        (OnWindowSetLeft)(this, TVariant(params[0]));
      }
      break;
      }
    case 265: {
      if (OnWindowSetTop) {
        (OnWindowSetTop)(this, TVariant(params[0]));
      }
      break;
      }
    case 266: {
      if (OnWindowSetWidth) {
        (OnWindowSetWidth)(this, TVariant(params[0]));
      }
      break;
      }
    case 267: {
      if (OnWindowSetHeight) {
        (OnWindowSetHeight)(this, TVariant(params[0]));
      }
      break;
      }
    case 263: {
      if (OnWindowClosing) {
        (OnWindowClosing)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 268: {
      if (OnClientToHostWindow) {
        (OnClientToHostWindow)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 269: {
      if (OnSetSecureLockIcon) {
        (OnSetSecureLockIcon)(this, TVariant(params[0]));
      }
      break;
      }
    case 270: {
      if (OnFileDownload) {
        (OnFileDownload)(this, TVariant(params[0]));
      }
      break;
      }
    case 271: {
      if (OnNavigateError) {
        (OnNavigateError)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]), TVariant(params[4]));
      }
      break;
      }
    case 225: {
      if (OnPrintTemplateInstantiation) {
        (OnPrintTemplateInstantiation)(this, TVariant(params[0]));
      }
      break;
      }
    case 226: {
      if (OnPrintTemplateTeardown) {
        (OnPrintTemplateTeardown)(this, TVariant(params[0]));
      }
      break;
      }
    case 227: {
      if (OnUpdatePageStatus) {
        (OnUpdatePageStatus)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]));
      }
      break;
      }
    case 272: {
      if (OnPrivacyImpactedStateChange) {
        (OnPrivacyImpactedStateChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

IWebBrowser2Ptr& TCppShellBrowserWindow::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCppShellBrowserWindow::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCppShellBrowserWindow::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCppShellBrowserWindow::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCppShellBrowserWindow::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCppShellBrowserWindow::ConnectTo(IWebBrowser2Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCppShellBrowserWindow::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CppShellBrowserWindow;
  sd.IntfIID = __uuidof(IWebBrowser2);
  sd.EventIID= __uuidof(DWebBrowserEvents2);
  ServerData = &sd;
}

void __fastcall TCppShellBrowserWindow::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 102: {
      if (OnStatusTextChange) {
        (OnStatusTextChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 108: {
      if (OnProgressChange) {
        (OnProgressChange)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 105: {
      if (OnCommandStateChange) {
        (OnCommandStateChange)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 106: {
      if (OnDownloadBegin) {
        (OnDownloadBegin)(this);
      }
      break;
      }
    case 104: {
      if (OnDownloadComplete) {
        (OnDownloadComplete)(this);
      }
      break;
      }
    case 113: {
      if (OnTitleChange) {
        (OnTitleChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 112: {
      if (OnPropertyChange) {
        (OnPropertyChange)(this, TVariant(params[0]));
      }
      break;
      }
    case 250: {
      if (OnBeforeNavigate2) {
        (OnBeforeNavigate2)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]), TVariant(params[4]), TVariant(params[5]), TVariant(params[6]));
      }
      break;
      }
    case 251: {
      if (OnNewWindow2) {
        IDispatch* tmp;
        (OnNewWindow2)(this, &tmp, TVariant(params[1]));
      }
      break;
      }
    case 252: {
      if (OnNavigateComplete2) {
        (OnNavigateComplete2)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 259: {
      if (OnDocumentComplete) {
        (OnDocumentComplete)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 253: {
      if (OnQuit) {
        (OnQuit)(this);
      }
      break;
      }
    case 254: {
      if (OnVisible) {
        (OnVisible)(this, TVariant(params[0]));
      }
      break;
      }
    case 255: {
      if (OnToolBar) {
        (OnToolBar)(this, TVariant(params[0]));
      }
      break;
      }
    case 256: {
      if (OnMenuBar) {
        (OnMenuBar)(this, TVariant(params[0]));
      }
      break;
      }
    case 257: {
      if (OnStatusBar) {
        (OnStatusBar)(this, TVariant(params[0]));
      }
      break;
      }
    case 258: {
      if (OnFullScreen) {
        (OnFullScreen)(this, TVariant(params[0]));
      }
      break;
      }
    case 260: {
      if (OnTheaterMode) {
        (OnTheaterMode)(this, TVariant(params[0]));
      }
      break;
      }
    case 262: {
      if (OnWindowSetResizable) {
        (OnWindowSetResizable)(this, TVariant(params[0]));
      }
      break;
      }
    case 264: {
      if (OnWindowSetLeft) {
        (OnWindowSetLeft)(this, TVariant(params[0]));
      }
      break;
      }
    case 265: {
      if (OnWindowSetTop) {
        (OnWindowSetTop)(this, TVariant(params[0]));
      }
      break;
      }
    case 266: {
      if (OnWindowSetWidth) {
        (OnWindowSetWidth)(this, TVariant(params[0]));
      }
      break;
      }
    case 267: {
      if (OnWindowSetHeight) {
        (OnWindowSetHeight)(this, TVariant(params[0]));
      }
      break;
      }
    case 263: {
      if (OnWindowClosing) {
        (OnWindowClosing)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 268: {
      if (OnClientToHostWindow) {
        (OnClientToHostWindow)(this, TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 269: {
      if (OnSetSecureLockIcon) {
        (OnSetSecureLockIcon)(this, TVariant(params[0]));
      }
      break;
      }
    case 270: {
      if (OnFileDownload) {
        (OnFileDownload)(this, TVariant(params[0]));
      }
      break;
      }
    case 271: {
      if (OnNavigateError) {
        (OnNavigateError)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]), TVariant(params[4]));
      }
      break;
      }
    case 225: {
      if (OnPrintTemplateInstantiation) {
        (OnPrintTemplateInstantiation)(this, TVariant(params[0]));
      }
      break;
      }
    case 226: {
      if (OnPrintTemplateTeardown) {
        (OnPrintTemplateTeardown)(this, TVariant(params[0]));
      }
      break;
      }
    case 227: {
      if (OnUpdatePageStatus) {
        (OnUpdatePageStatus)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]));
      }
      break;
      }
    case 272: {
      if (OnPrivacyImpactedStateChange) {
        (OnPrivacyImpactedStateChange)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

IShellWindowsPtr& TCppShellWindows::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCppShellWindows::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCppShellWindows::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCppShellWindows::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCppShellWindows::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCppShellWindows::ConnectTo(IShellWindowsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCppShellWindows::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CppShellWindows;
  sd.IntfIID = __uuidof(IShellWindows);
  sd.EventIID= __uuidof(DShellWindowsEvents);
  ServerData = &sd;
}

void __fastcall TCppShellWindows::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 200: {
      if (OnWindowRegistered) {
        (OnWindowRegistered)(this, TVariant(params[0]));
      }
      break;
      }
    case 201: {
      if (OnWindowRevoked) {
        (OnWindowRevoked)(this, TVariant(params[0]));
      }
      break;
      }
    default:
      break;
  }
}

IShellUIHelperPtr& TCppShellUIHelper::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCppShellUIHelper::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCppShellUIHelper::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCppShellUIHelper::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCppShellUIHelper::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCppShellUIHelper::ConnectTo(IShellUIHelperPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCppShellUIHelper::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CppShellUIHelper;
  sd.IntfIID = __uuidof(IShellUIHelper);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

IShellNameSpacePtr& TShellFavoritesNameSpace::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TShellFavoritesNameSpace::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TShellFavoritesNameSpace::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TShellFavoritesNameSpace::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TShellFavoritesNameSpace::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TShellFavoritesNameSpace::ConnectTo(IShellNameSpacePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TShellFavoritesNameSpace::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ShellFavoritesNameSpace;
  sd.IntfIID = __uuidof(IShellNameSpace);
  sd.EventIID= __uuidof(DShellNameSpaceEvents);
  ServerData = &sd;
}

void __fastcall TShellFavoritesNameSpace::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnFavoritesSelectionChange) {
        (OnFavoritesSelectionChange)(this, TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]), TVariant(params[4]), TVariant(params[5]), TVariant(params[6]));
      }
      break;
      }
    case 2: {
      if (OnSelectionChange) {
        (OnSelectionChange)(this);
      }
      break;
      }
    case 3: {
      if (OnDoubleClick) {
        (OnDoubleClick)(this);
      }
      break;
      }
    case 4: {
      if (OnInitialized) {
        (OnInitialized)(this);
      }
      break;
      }
    default:
      break;
  }
}

IScriptErrorListPtr& TCppCScriptErrorList::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCppCScriptErrorList::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCppCScriptErrorList::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCppCScriptErrorList::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCppCScriptErrorList::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCppCScriptErrorList::ConnectTo(IScriptErrorListPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCppCScriptErrorList::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CppCScriptErrorList;
  sd.IntfIID = __uuidof(IScriptErrorList);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

ISearchAssistantOC3Ptr& TCppSearchAssistantOC::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TCppSearchAssistantOC::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TCppSearchAssistantOC::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TCppSearchAssistantOC::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TCppSearchAssistantOC::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TCppSearchAssistantOC::ConnectTo(ISearchAssistantOC3Ptr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TCppSearchAssistantOC::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_CppSearchAssistantOC;
  sd.IntfIID = __uuidof(ISearchAssistantOC3);
  sd.EventIID= __uuidof(_SearchAssistantEvents);
  ServerData = &sd;
}

void __fastcall TCppSearchAssistantOC::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnNextMenuSelect) {
        (OnNextMenuSelect)(this, TVariant(params[0]));
      }
      break;
      }
    case 2: {
      if (OnNewSearch) {
        (OnNewSearch)(this);
      }
      break;
      }
    default:
      break;
  }
}


};     // namespace Shdocvw_tlb


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Shdocvw_ocx
{

void __fastcall PACKAGE Register()
{
  // [2]
  TComponentClass cls_ocx[] = {
                              __classid(Shdocvw_tlb::TCppWebBrowser)
                           };
  RegisterComponents("Internet", cls_ocx,
                     sizeof(cls_ocx)/sizeof(cls_ocx[0])-1);
  // [7]
  TComponentClass cls_svr[] = {
                              __classid(Shdocvw_tlb::TCppInternetExplorer), 
                              __classid(Shdocvw_tlb::TCppShellBrowserWindow), 
                              __classid(Shdocvw_tlb::TCppShellWindows), 
                              __classid(Shdocvw_tlb::TCppShellUIHelper), 
                              __classid(Shdocvw_tlb::TShellFavoritesNameSpace), 
                              __classid(Shdocvw_tlb::TCppCScriptErrorList), 
                              __classid(Shdocvw_tlb::TCppSearchAssistantOC)
                           };
  RegisterComponents("Servers", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Shdocvw_ocx
