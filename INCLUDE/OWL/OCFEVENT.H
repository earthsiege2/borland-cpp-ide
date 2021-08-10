//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Definition of OWL signatures for ObjectConnections messages
//----------------------------------------------------------------------------
#if !defined(OWL_OCFEVENT_H)
#define OWL_OCFEVENT_H

#if !defined(OWL_EVENTHAN_H)
# include <owl/eventhan.h>
#endif
#if !defined(_OCMCLASS) && defined(BI_PLAT_WIN16)
# define _OCMCLASS _OWLCLASS
#endif
#if !defined(OCF_OCAPP_H)
# include <ocf/ocapp.h>
#endif
#if !defined(OCF_OCVIEW_H)
# include <ocf/ocview.h>
#endif

//----------------------------------------------------------------------------
// Signatures for ObjectComponents messages
//

template <class T>
inline bool(T::*B_OC_MD_Sig(bool(T::*pmf)(TOcMenuDescr far&)))(TOcMenuDescr far&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_DD_Sig(bool(T::*pmf)(TOcDragDrop far&)))(TOcDragDrop far&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_VSCROLL_Sig(bool(T::*pmf)(TOcScrollDir)))(TOcScrollDir)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_PCI_Sig(bool(T::*pmf)(TOcPartChangeInfo&)))(TOcPartChangeInfo&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_VP_Sig(bool(T::*pmf)(TOcViewPaint far&)))(TOcViewPaint far&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_VSP_Sig(bool(T::*pmf)(TOcSaveLoad far&)))(TOcSaveLoad far&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_VCF_Sig(bool(T::*pmf)(TOcFormatData far&)))(TOcFormatData far&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_VTB_Sig(bool(T::*pmf)(TOcToolBarInfo far&)))(TOcToolBarInfo far&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_VSS_Sig(bool(T::*pmf)(TOcScaleFactor&)))(TOcScaleFactor&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_PS_Sig(bool(T::*pmf)(TOcPartSize&)))(TOcPartSize&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_IT_Sig(bool(T::*pmf)(TOcItemName&)))(TOcItemName&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_SL_Sig(bool(T::*pmf)(TOcLinkView&)))(TOcLinkView&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_PA_Sig(bool(T::*pmf)(TOcPart&)))(TOcPart&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_OC_PO_Sig(bool(T::*pmf)(TOcInitInfo&)))(TOcInitInfo&)
{
  return pmf;
}

//----------------------------------------------------------------------------
// Event response table macros for ObjectConnections events
//

//
// Raw OC compound document family event
//
#define EV_OCEVENT(id, method)\
  {WM_OCEVENT, id, (TAnyDispatcher)::I32_LPARAM_Dispatch,\
   (TMyPMF)U32_VOIDFP_Sig(&TMyClass::method)}

//
// App and app frame window events
//
#define EV_OC_APPINSMENUS\
  {WM_OCEVENT, OC_APPINSMENUS, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_MD_Sig(&TMyClass::EvOcAppInsMenus)}

#define EV_OC_APPMENUS\
  {WM_OCEVENT, OC_APPMENUS, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_MD_Sig(&TMyClass::EvOcAppMenus)}

#define EV_OC_APPPROCESSMSG\
  {WM_OCEVENT, OC_APPPROCESSMSG, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_MSG_Sig(&TMyClass::EvOcAppProcessMsg)}

#define EV_OC_APPFRAMERECT\
  {WM_OCEVENT, OC_APPFRAMERECT, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_RECT_Sig(&TMyClass::EvOcAppFrameRect)}

#define EV_OC_APPBORDERSPACEREQ\
  {WM_OCEVENT, OC_APPBORDERSPACEREQ, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_RECT_Sig(&TMyClass::EvOcAppBorderSpaceReq)}

#define EV_OC_APPBORDERSPACESET\
  {WM_OCEVENT, OC_APPBORDERSPACESET, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_RECT_Sig(&TMyClass::EvOcAppBorderSpaceSet)}

#define EV_OC_APPSTATUSTEXT\
  {WM_OCEVENT, OC_APPSTATUSTEXT, (TAnyDispatcher)::v_POINTER_Dispatch,\
   (TMyPMF)v_CS_Sig(&TMyClass::EvOcAppStatusText)}

#define EV_OC_APPRESTOREUI\
  {WM_OCEVENT, OC_APPRESTOREUI, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvOcAppRestoreUI)}

#define EV_OC_APPDIALOGHELP\
  {WM_OCEVENT, OC_APPDIALOGHELP, (TAnyDispatcher)::v_U_Dispatch,\
   (TMyPMF)v_OC_AH_Sig(&TMyClass::EvOcAppDialogHelp)}

#define EV_OC_APPSHUTDOWN\
  {WM_OCEVENT, OC_APPSHUTDOWN, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)B_Sig(&TMyClass::EvOcAppShutdown)}

//
// View events
//
#define EV_OC_VIEWTITLE\
  {WM_OCEVENT, OC_VIEWTITLE, (TAnyDispatcher)::I32_Dispatch,\
   (TMyPMF)CS_Sig(&TMyClass::EvOcViewTitle)}

#define EV_OC_VIEWSETTITLE\
  {WM_OCEVENT, OC_VIEWSETTITLE, (TAnyDispatcher)::v_POINTER_Dispatch,\
   (TMyPMF)v_CS_Sig(&TMyClass::EvOcViewSetTitle)}

#define EV_OC_VIEWBORDERSPACEREQ\
  {WM_OCEVENT, OC_VIEWBORDERSPACEREQ, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_RECT_Sig(&TMyClass::EvOcViewBorderSpaceReq)}

#define EV_OC_VIEWBORDERSPACESET\
  {WM_OCEVENT, OC_VIEWBORDERSPACESET, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_RECT_Sig(&TMyClass::EvOcViewBorderSpaceSet)}

#define EV_OC_VIEWDROP\
  {WM_OCEVENT, OC_VIEWDROP, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_DD_Sig(&TMyClass::EvOcViewDrop)}

#define EV_OC_VIEWDRAG\
  {WM_OCEVENT, OC_VIEWDRAG, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_DD_Sig(&TMyClass::EvOcViewDrag)}

#define EV_OC_VIEWSCROLL\
  {WM_OCEVENT, OC_VIEWSCROLL, (TAnyDispatcher)::I32_U_Dispatch,\
   (TMyPMF)B_OC_VSCROLL_Sig(&TMyClass::EvOcViewScroll)}

#define EV_OC_VIEWPARTINVALID\
  {WM_OCEVENT, OC_VIEWPARTINVALID, (TAnyDispatcher)::U_POINTER_Dispatch,\
   (TMyPMF)B_OC_PCI_Sig(&TMyClass::EvOcViewPartInvalid)}

#define EV_OC_VIEWPAINT\
  {WM_OCEVENT, OC_VIEWPAINT, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_VP_Sig(&TMyClass::EvOcViewPaint)}

#define EV_OC_VIEWLOADPART\
  {WM_OCEVENT, OC_VIEWLOADPART, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_VSP_Sig(&TMyClass::EvOcViewLoadPart)}

#define EV_OC_VIEWSAVEPART\
  {WM_OCEVENT, OC_VIEWSAVEPART, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_VSP_Sig(&TMyClass::EvOcViewSavePart)}

#define EV_OC_VIEWCLOSE\
  {WM_OCEVENT, OC_VIEWCLOSE, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)B_Sig(&TMyClass::EvOcViewClose)}

#define EV_OC_VIEWINSMENUS\
  {WM_OCEVENT, OC_VIEWINSMENUS, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_MD_Sig(&TMyClass::EvOcViewInsMenus)}

#define EV_OC_VIEWSHOWTOOLS\
  {WM_OCEVENT, OC_VIEWSHOWTOOLS, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_VTB_Sig(&TMyClass::EvOcViewShowTools)}

#define EV_OC_VIEWGETPALETTE\
  {WM_OCEVENT, OC_VIEWGETPALETTE, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_PPALETTE_Sig(&TMyClass::EvOcViewGetPalette)}

#define EV_OC_VIEWCLIPDATA\
  {WM_OCEVENT, OC_VIEWCLIPDATA, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_VCF_Sig(&TMyClass::EvOcViewClipData)}

#define EV_OC_VIEWPARTSIZE\
  {WM_OCEVENT, OC_VIEWPARTSIZE, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_PS_Sig(&TMyClass::EvOcViewPartSize)}

#define EV_OC_VIEWOPENDOC\
  {WM_OCEVENT, OC_VIEWOPENDOC, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_CS_Sig(&TMyClass::EvOcViewOpenDoc)}

#define EV_OC_VIEWATTACHWINDOW\
  {WM_OCEVENT, OC_VIEWATTACHWINDOW, (TAnyDispatcher)::U_U_Dispatch,\
   (TMyPMF)B_B_Sig(&TMyClass::EvOcViewAttachWindow)}

#define EV_OC_VIEWSETSCALE\
  {WM_OCEVENT, OC_VIEWSETSCALE, (TAnyDispatcher)::U_POINTER_Dispatch,\
   (TMyPMF)B_OC_VSS_Sig(&TMyClass::EvOcViewSetScale)}

#define EV_OC_VIEWGETSCALE\
  {WM_OCEVENT, OC_VIEWGETSCALE, (TAnyDispatcher)::U_POINTER_Dispatch,\
   (TMyPMF)B_OC_VSS_Sig(&TMyClass::EvOcViewGetScale)}

#define EV_OC_VIEWGETSITERECT\
  {WM_OCEVENT, OC_VIEWGETSITERECT, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_RECT_Sig(&TMyClass::EvOcViewGetSiteRect)}

#define EV_OC_VIEWSETSITERECT\
  {WM_OCEVENT, OC_VIEWSETSITERECT, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_RECT_Sig(&TMyClass::EvOcViewSetSiteRect)}

#define EV_OC_VIEWGETITEMNAME\
  {WM_OCEVENT, OC_VIEWGETITEMNAME, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_IT_Sig(&TMyClass::EvOcViewGetItemName)}

#define EV_OC_VIEWSETLINK\
  {WM_OCEVENT, OC_VIEWSETLINK, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_SL_Sig(&TMyClass::EvOcViewSetLink)}

#define EV_OC_VIEWBREAKLINK\
  {WM_OCEVENT, OC_VIEWBREAKLINK, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_SL_Sig(&TMyClass::EvOcViewBreakLink)}

#define EV_OC_VIEWPARTACTIVATE\
  {WM_OCEVENT, OC_VIEWPARTACTIVATE, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_PA_Sig(&TMyClass::EvOcViewPartActivate)}

#define EV_OC_VIEWPASTEOBJECT\
  {WM_OCEVENT, OC_VIEWPASTEOBJECT, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_OC_PO_Sig(&TMyClass::EvOcViewPasteObject)}

#endif
