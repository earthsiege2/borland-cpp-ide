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
// File generated on 1/29/2002 1:28:12 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office10\msppt.olb (1)
// LIBID: {91493440-5A91-11CF-8700-00AA0060263B}
// LCID: 0
// Helpfile: c:\program files\microsoft office\office10\VBAPP10.CHM
// HelpString: Microsoft PowerPoint 10.0 Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v2.2 Office, (C:\Program Files\Common Files\Microsoft Shared\Office10\MSO.DLL)
//   (3) v5.3 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB)
// Errors:
//   Hint: Symbol 'Application' renamed to 'PowerPointApplication'
//   Hint: Symbol 'Global' renamed to 'PowerPointGlobal'
//   Hint: Symbol 'Presentation' renamed to 'PowerPointPresentation'
//   Hint: Symbol 'Slide' renamed to 'PowerPointSlide'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Application' renamed to 'PowerPointApplication'
//   Hint: Symbol 'Global' renamed to 'PowerPointGlobal'
//   Hint: Symbol 'Presentation' renamed to 'PowerPointPresentation'
//   Hint: Symbol 'Slide' renamed to 'PowerPointSlide'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "PowerPoint_XP_srvr.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Powerpoint_xp
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
  sd.EventIID= __uuidof(EApplication);
  ServerData = &sd;
}

void __fastcall TPowerPointApplication::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 2001: {
      if (OnWindowSelectionChange) {
        (OnWindowSelectionChange)(this, (Powerpoint_xp::Selection*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2002: {
      if (OnWindowBeforeRightClick) {
        (OnWindowBeforeRightClick)(this, (Powerpoint_xp::Selection*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2003: {
      if (OnWindowBeforeDoubleClick) {
        (OnWindowBeforeDoubleClick)(this, (Powerpoint_xp::Selection*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2004: {
      if (OnPresentationClose) {
        (OnPresentationClose)(this, (Powerpoint_xp::PowerPointPresentation*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2005: {
      if (OnPresentationSave) {
        (OnPresentationSave)(this, (Powerpoint_xp::PowerPointPresentation*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2006: {
      if (OnPresentationOpen) {
        (OnPresentationOpen)(this, (Powerpoint_xp::PowerPointPresentation*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2007: {
      if (OnNewPresentation) {
        (OnNewPresentation)(this, (Powerpoint_xp::PowerPointPresentation*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2008: {
      if (OnPresentationNewSlide) {
        (OnPresentationNewSlide)(this, (Powerpoint_xp::PowerPointSlide*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2009: {
      if (OnWindowActivate) {
        (OnWindowActivate)(this, (Powerpoint_xp::PowerPointPresentation*)(LPDISPATCH)TVariant(params[0]), (Powerpoint_xp::DocumentWindow*)(LPDISPATCH)TVariant(params[1]));
      }
      break;
      }
    case 2010: {
      if (OnWindowDeactivate) {
        (OnWindowDeactivate)(this, (Powerpoint_xp::PowerPointPresentation*)(LPDISPATCH)TVariant(params[0]), (Powerpoint_xp::DocumentWindow*)(LPDISPATCH)TVariant(params[1]));
      }
      break;
      }
    case 2011: {
      if (OnSlideShowBegin) {
        (OnSlideShowBegin)(this, (Powerpoint_xp::SlideShowWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2012: {
      if (OnSlideShowNextBuild) {
        (OnSlideShowNextBuild)(this, (Powerpoint_xp::SlideShowWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2013: {
      if (OnSlideShowNextSlide) {
        (OnSlideShowNextSlide)(this, (Powerpoint_xp::SlideShowWindow*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2014: {
      if (OnSlideShowEnd) {
        (OnSlideShowEnd)(this, (Powerpoint_xp::PowerPointPresentation*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2015: {
      if (OnPresentationPrint) {
        (OnPresentationPrint)(this, (Powerpoint_xp::PowerPointPresentation*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2016: {
      if (OnSlideSelectionChanged) {
        (OnSlideSelectionChanged)(this, (Powerpoint_xp::SlideRange*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2017: {
      if (OnColorSchemeChanged) {
        (OnColorSchemeChanged)(this, (Powerpoint_xp::SlideRange*)(LPDISPATCH)TVariant(params[0]));
      }
      break;
      }
    case 2018: {
      if (OnPresentationBeforeSave) {
        (OnPresentationBeforeSave)(this, (Powerpoint_xp::PowerPointPresentation*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      }
      break;
      }
    case 2019: {
      if (OnSlideShowNextClick) {
        (OnSlideShowNextClick)(this, (Powerpoint_xp::SlideShowWindow*)(LPDISPATCH)TVariant(params[0]), (Powerpoint_xp::Effect*)(LPDISPATCH)TVariant(params[1]));
      }
      break;
      }
    default:
      break;
  }
}


};     // namespace Powerpoint_xp


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Powerpoint_xp_srvr
{

void __fastcall PACKAGE Register()
{
  // [1]
  TComponentClass cls_svr[] = {
                              __classid(Powerpoint_xp::TPowerPointApplication)
                           };
  RegisterComponents("OfficeXP", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Powerpoint_xp_srvr
