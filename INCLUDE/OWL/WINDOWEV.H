//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Event response table macros for windows messages
//----------------------------------------------------------------------------
#if !defined(OWL_WINDOWEV_H)
#define OWL_WINDOWEV_H

#if !defined(OWL_EVENTHAN_H)
# include <owl/eventhan.h>
#endif

//
// general purpose WM_* macro
//
// wparam and lparam are passed, i.e: LPARAM method(WPARAM, LPARAM)
//
#define EV_MESSAGE(message, method)\
  {message, 0, (TAnyDispatcher)::I32_WPARAM_LPARAM_Dispatch,\
   (TMyPMF)LRESULT_WPARAM_LPARAM_Sig(&TMyClass::method)}

//
// registered messages
//
#define EV_REGISTERED(str, method)\
  EV_MESSAGE(::RegisterWindowMessage(str), method)

//
// handler for child ID notifications that are handled at the child's parent
//
// no arguments are passed, i.e: void method()
//
#define EV_CHILD_NOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::method)}

//
// handler for child ID notifications that are handled at the child's parent
//
// the notification code is passed in as an argument; this allows multiple
// notifications to be handled by a single response function, i.e:
//   void method(uint notifyCode)
//
#define EV_CHILD_NOTIFY_AND_CODE(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_U_Sig(&TMyClass::method)}

//
// generic handler for child ID notification: rather than specify the
// specific notification codes you are interested in ALL notifications
// from the child are passed to the response function
//
// the notification code is passed in as an argument, i.e.:
//   void method(uint notifyCode)
//
#define EV_CHILD_NOTIFY_ALL_CODES(id, method)\
  {UINT_MAX, id, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_U_Sig(&TMyClass::method)}

//
// handler for child ID notifications that are handled at the child
//
// no arguments are passed, i.e: void method()
//
#define EV_NOTIFY_AT_CHILD(notifyCode, method)\
  {notifyCode, UINT_MAX, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::method)}

//
// handler for menu/accelerator/push buttons
//
// no arguments are passed, i.e: void method()
//
#define EV_COMMAND(id, method)\
  {0, id, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::method)}

//
// handler for menu/accelerator/push buttons
//
// the menu id is passed in as an argument; this allows multiple
// commands to be handled by a single response function.
//  void method(uint commandId)
//
#define EV_COMMAND_AND_ID(id, method)\
  {0, id, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_U_Sig(&TMyClass::method)}

//
// handler for command enabling
//  void method(uint commandId)
//
#define EV_COMMAND_ENABLE(id, method)\
  {WM_COMMAND_ENABLE, id, (TAnyDispatcher)::v_POINTER_Dispatch,\
   (TMyPMF)v_COMMANDENABLER_Sig(&TMyClass::method)}

//
// handlers for document and view notifications
//
#define EV_OWLDOCUMENT(id, method)\
  {WM_OWLDOCUMENT, id, (TAnyDispatcher)::v_POINTER_Dispatch,\
   (TMyPMF)v_OWLDOCUMENT_Sig(&TMyClass::method)}

#define EV_OWLVIEW(id, method)\
  {WM_OWLVIEW, id, (TAnyDispatcher)::v_POINTER_Dispatch,\
   (TMyPMF)v_OWLVIEW_Sig(&TMyClass::method)}

#define EV_OWLNOTIFY(id, method)\
  {WM_OWLNOTIFY, id, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)B_LPARAM_Sig(&TMyClass::method)}

#define EV_VIEWNOTIFY(id, method) \
  {WM_OWLNOTIFY, id, (TAnyDispatcher)::U_LPARAM_Dispatch, \
  (TMyPMF)B_LPARAM_Sig(&TMyClass::method)}

//
// macros for specific WM_* messages
//
#define EV_WM_ACTIVATE\
  {WM_ACTIVATE, 0, (TAnyDispatcher)::v_Activate_Dispatch,\
   (TMyPMF)v_U_B_W_Sig(&TMyClass::EvActivate)}

#define EV_WM_ACTIVATEAPP\
  {WM_ACTIVATEAPP, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_B_HTASK_Sig(&TMyClass::EvActivateApp)}

#define EV_WM_ASKCBFORMATNAME\
  {WM_ASKCBFORMATNAME, 0, (TAnyDispatcher)::v_WPARAM_LPARAM_Dispatch,\
   (TMyPMF)v_U_S_Sig(&TMyClass::EvAskCBFormatName)}

#define EV_WM_CANCELMODE\
  {WM_CANCELMODE, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvCancelMode)}

#define EV_WM_CHANGECBCHAIN\
  {WM_CHANGECBCHAIN, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_W_W_Sig(&TMyClass::EvChangeCBChain)}

#define EV_WM_CHAR\
  {WM_CHAR, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_U_U_U_Sig(&TMyClass::EvChar)}

#define EV_WM_CHARTOITEM\
  {WM_CHARTOITEM, 0, (TAnyDispatcher)::i_U_W_U_Dispatch,\
   (TMyPMF)i_U_W_U_Sig(&TMyClass::EvCharToItem)}

#define EV_WM_CHILDACTIVATE\
  {WM_CHILDACTIVATE, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvChildActivate)}

#define EV_WM_CHILDINVALID\
  {WM_CHILDINVALID, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_W_Sig(&TMyClass::EvChildInvalid)}

#define EV_WM_CLOSE\
  {WM_CLOSE, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvClose)}

#define EV_WM_COMMNOTIFY\
  {WM_COMMNOTIFY, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_U_U_Sig(&TMyClass::EvCommNotify)}

#define EV_WM_COMPACTING\
  {WM_COMPACTING, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_U_Sig(&TMyClass::EvCompacting)}

#define EV_WM_COMPAREITEM\
  {WM_COMPAREITEM, 0, (TAnyDispatcher)::LRESULT_WPARAM_LPARAM_Dispatch,\
   (TMyPMF)LRESULT_U_COMPAREITEM_Sig(&TMyClass::EvCompareItem)}

#define EV_WM_CREATE\
  {WM_CREATE, 0, (TAnyDispatcher)::i_LPARAM_Dispatch,\
   (TMyPMF)i_CREATE_Sig(&TMyClass::EvCreate)}

#define EV_WM_CTLCOLOR\
  {WM_CTLCOLOR, 0, (TAnyDispatcher)::U_U_U_U_Dispatch,\
   (TMyPMF)HBRUSH_HDC_W_U_Sig(&TMyClass::EvCtlColor)}

#define EV_WM_DEADCHAR\
  {WM_DEADCHAR, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_U_U_U_Sig(&TMyClass::EvDeadChar)}

#define EV_WM_DELETEITEM\
  {WM_DELETEITEM, 0, (TAnyDispatcher)::v_WPARAM_LPARAM_Dispatch,\
   (TMyPMF)v_U_DELETEITEM_Sig(&TMyClass::EvDeleteItem)}

#define EV_WM_DESTROY\
  {WM_DESTROY, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvDestroy)}

#define EV_WM_DESTROYCLIPBOARD\
  {WM_DESTROYCLIPBOARD, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvDestroyClipboard)}

#define EV_WM_DEVMODECHANGE\
  {WM_DEVMODECHANGE, 0, (TAnyDispatcher)::v_LPARAM_Dispatch,\
   (TMyPMF)v_S_Sig(&TMyClass::EvDevModeChange)}

#define EV_WM_DRAWCLIPBOARD\
  {WM_DRAWCLIPBOARD, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvDrawClipboard)}

#define EV_WM_DRAWITEM\
  {WM_DRAWITEM, 0, (TAnyDispatcher)::v_WPARAM_LPARAM_Dispatch,\
   (TMyPMF)v_U_DRAWITEM_Sig(&TMyClass::EvDrawItem)}

#define EV_WM_DROPFILES\
  {WM_DROPFILES, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_DROP_Sig(&TMyClass::EvDropFiles)}

#define EV_WM_ENABLE\
  {WM_ENABLE, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_B_Sig(&TMyClass::EvEnable)}

#define EV_WM_ENDSESSION\
  {WM_ENDSESSION, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_B_Sig(&TMyClass::EvEndSession)}

#define EV_WM_ENTERIDLE\
  {WM_ENTERIDLE, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_U_W_Sig(&TMyClass::EvEnterIdle)}

#define EV_WM_ERASEBKGND\
  {WM_ERASEBKGND, 0, (TAnyDispatcher)::i_WPARAM_Dispatch,\
   (TMyPMF)B_HDC_Sig(&TMyClass::EvEraseBkgnd)}

#define EV_WM_FONTCHANGE\
  {WM_FONTCHANGE, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvFontChange)}

#define EV_WM_GETDLGCODE\
  {WM_GETDLGCODE, 0, (TAnyDispatcher)::U_LPARAM_Dispatch,\
   (TMyPMF)U_MSG_Sig(&TMyClass::EvGetDlgCode)}

#define EV_WM_GETFONT\
  {WM_GETFONT, 0, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)HFONT_Sig(&TMyClass::EvGetFont)}

#define EV_WM_GETMINMAXINFO\
  {WM_GETMINMAXINFO, 0, (TAnyDispatcher)::v_LPARAM_Dispatch,\
   (TMyPMF)v_MINMAXINFO_Sig(&TMyClass::EvGetMinMaxInfo)}

#define EV_WM_GETTEXT\
  {WM_GETTEXT, 0, (TAnyDispatcher)::v_WPARAM_LPARAM_Dispatch,\
   (TMyPMF)v_U_S_Sig(&TMyClass::EvGetText)}

#define EV_WM_GETTEXTLENGTH\
  {WM_GETTEXTLENGTH, 0, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)U_Sig(&TMyClass::EvGetTextLength)}

// Win32 only
//
#define EV_WM_HOTKEY\
  {WM_HOTKEY, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_i_Sig(&TMyClass::EvHotKey)}

#define EV_WM_HSCROLL\
  {WM_HSCROLL, 0, (TAnyDispatcher)::v_U_U_W_Dispatch,\
   (TMyPMF)v_U_U_W_Sig(&TMyClass::EvHScroll)}

#define EV_WM_HSCROLLCLIPBOARD\
  {WM_HSCROLLCLIPBOARD, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_W_U_U_Sig(&TMyClass::EvHScrollClipboard)}

#define EV_WM_ICONERASEBKGND\
  {WM_ICONERASEBKGND, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_HDC_Sig(&TMyClass::EvIconEraseBkgnd)}

#define EV_WM_INITMENU\
  {WM_INITMENU, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_HMENU_Sig(&TMyClass::EvInitMenu)}

#define EV_WM_INITMENUPOPUP\
  {WM_INITMENUPOPUP, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_HMENU_U_B_Sig(&TMyClass::EvInitMenuPopup)}

#define EV_WM_KEYDOWN\
  {WM_KEYDOWN, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_U_U_U_Sig(&TMyClass::EvKeyDown)}

#define EV_WM_KEYUP\
  {WM_KEYUP, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_U_U_U_Sig(&TMyClass::EvKeyUp)}

#define EV_WM_KILLFOCUS\
  {WM_KILLFOCUS, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_W_Sig(&TMyClass::EvKillFocus)}

#define EV_WM_LBUTTONDBLCLK\
  {WM_LBUTTONDBLCLK, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvLButtonDblClk)}

#define EV_WM_LBUTTONDOWN\
  {WM_LBUTTONDOWN, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvLButtonDown)}

#define EV_WM_LBUTTONUP\
  {WM_LBUTTONUP, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvLButtonUp)}

#define EV_WM_MBUTTONDBLCLK\
  {WM_MBUTTONDBLCLK, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvMButtonDblClk)}

#define EV_WM_MBUTTONDOWN\
  {WM_MBUTTONDOWN, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvMButtonDown)}

#define EV_WM_MBUTTONUP\
  {WM_MBUTTONUP, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvMButtonUp)}

#define EV_WM_MDIACTIVATE\
  {WM_MDIACTIVATE, 0, (TAnyDispatcher)::v_MdiActivate_Dispatch,\
   (TMyPMF)v_W_W_Sig(&TMyClass::EvMDIActivate)}

#define EV_WM_MDICREATE\
  {WM_MDICREATE, 0, (TAnyDispatcher)::i_LPARAM_Dispatch,\
   (TMyPMF)LRESULT_MDICREATESTRUCT_Sig(&TMyClass::EvMDICreate)}

#define EV_WM_MDIDESTROY\
  {WM_MDIDESTROY, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_W_Sig(&TMyClass::EvMDIDestroy)}

#define EV_WM_MENUCHAR\
  {WM_MENUCHAR, 0, (TAnyDispatcher)::I32_MenuChar_Dispatch,\
   (TMyPMF)LRESULT_U_U_HMENU_Sig(&TMyClass::EvMenuChar)}

#define EV_WM_MENUSELECT\
  {WM_MENUSELECT, 0, (TAnyDispatcher)::v_U_U_W_Dispatch,\
   (TMyPMF)v_U_U_HMENU_Sig(&TMyClass::EvMenuSelect)}

#define EV_WM_MEASUREITEM\
  {WM_MEASUREITEM, 0, (TAnyDispatcher)::v_WPARAM_LPARAM_Dispatch,\
   (TMyPMF)v_U_MEASUREITEM_Sig(&TMyClass::EvMeasureItem)}

#define EV_WM_MOUSEACTIVATE\
  {WM_MOUSEACTIVATE, 0, (TAnyDispatcher)::U_U_U_U_Dispatch,\
   (TMyPMF)U_W_U_U_Sig(&TMyClass::EvMouseActivate)}

#define EV_WM_MOUSEMOVE\
  {WM_MOUSEMOVE, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvMouseMove)}

#define EV_WM_MOVE\
  {WM_MOVE, 0, (TAnyDispatcher)::v_POINT_Dispatch,\
   (TMyPMF)v_POINT_Sig(&TMyClass::EvMove)}

#define EV_WM_NCACTIVATE\
  {WM_NCACTIVATE, 0, (TAnyDispatcher)::i_WPARAM_Dispatch,\
   (TMyPMF)B_B_Sig(&TMyClass::EvNCActivate)}

#define EV_WM_NCCALCSIZE\
  {WM_NCCALCSIZE, 0, (TAnyDispatcher)::U_WPARAM_LPARAM_Dispatch,\
   (TMyPMF)U_B_CALCSIZE_Sig(&TMyClass::EvNCCalcSize)}

#define EV_WM_NCCREATE\
  {WM_NCCREATE, 0, (TAnyDispatcher)::i_LPARAM_Dispatch,\
   (TMyPMF)B_CREATE_Sig(&TMyClass::EvNCCreate)}

#define EV_WM_NCDESTROY\
  {WM_NCDESTROY, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvNCDestroy)}

#define EV_WM_NCHITTEST\
  {WM_NCHITTEST, 0, (TAnyDispatcher)::U_POINT_Dispatch,\
   (TMyPMF)U_POINT_Sig(&TMyClass::EvNCHitTest)}

#define EV_WM_NCLBUTTONDBLCLK\
  {WM_NCLBUTTONDBLCLK, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCLButtonDblClk)}

#define EV_WM_NCLBUTTONDOWN\
  {WM_NCLBUTTONDOWN, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCLButtonDown)}

#define EV_WM_NCLBUTTONUP\
  {WM_NCLBUTTONUP, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCLButtonUp)}

#define EV_WM_NCMBUTTONDBLCLK\
  {WM_NCMBUTTONDBLCLK, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCMButtonDblClk)}

#define EV_WM_NCMBUTTONDOWN\
  {WM_NCMBUTTONDOWN, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCMButtonDown)}

#define EV_WM_NCMBUTTONUP\
  {WM_NCMBUTTONUP, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCMButtonUp)}

#define EV_WM_NCMOUSEMOVE\
  {WM_NCMOUSEMOVE, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCMouseMove)}

#define EV_WM_NCPAINT\
  {WM_NCPAINT, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvNCPaint)}

#define EV_WM_NCRBUTTONDBLCLK\
  {WM_NCRBUTTONDBLCLK, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCRButtonDblClk)}

#define EV_WM_NCRBUTTONDOWN\
  {WM_NCRBUTTONDOWN, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCRButtonDown)}

#define EV_WM_NCRBUTTONUP\
  {WM_NCRBUTTONUP, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvNCRButtonUp)}

#define EV_WM_NEXTDLGCTL\
  {WM_NEXTDLGCTL, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_U_U_Sig(&TMyClass::EvNextDlgCtl)}

#define EV_WM_PAINT\
  {WM_PAINT, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvPaint)}

#define EV_WM_PAINTCLIPBOARD\
  {WM_PAINTCLIPBOARD, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_W_H_Sig(&TMyClass::EvPaintClipboard)}

// Win32 only
//
#define EV_WM_PAINTICON\
  {WM_PAINTICON, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvPaintIcon)}

#define EV_WM_PALETTECHANGED\
  {WM_PALETTECHANGED, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_W_Sig(&TMyClass::EvPaletteChanged)}

#define EV_WM_PALETTEISCHANGING\
  {WM_PALETTEISCHANGING, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_W_Sig(&TMyClass::EvPaletteIsChanging)}

#define EV_WM_PARENTNOTIFY\
  {WM_PARENTNOTIFY, 0, (TAnyDispatcher)::v_ParentNotify_Dispatch,\
   (TMyPMF)v_U_U_U_Sig(&TMyClass::EvParentNotify)}

#define EV_WM_POWER\
  {WM_POWER, 0, (TAnyDispatcher)::i_WPARAM_Dispatch,\
   (TMyPMF)i_U_Sig(&TMyClass::EvPower)}

#define EV_WM_QUERYDRAGICON\
  {WM_QUERYDRAGICON, 0, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)H_Sig(&TMyClass::EvQueryDragIcon)}

#define EV_WM_QUERYENDSESSION\
  {WM_QUERYENDSESSION, 0, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)B_Sig(&TMyClass::EvQueryEndSession)}

#define EV_WM_QUERYNEWPALETTE\
  {WM_QUERYNEWPALETTE, 0, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)B_Sig(&TMyClass::EvQueryNewPalette)}

#define EV_WM_QUERYOPEN\
  {WM_QUERYOPEN, 0, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)B_Sig(&TMyClass::EvQueryOpen)}

#define EV_WM_QUEUESYNC\
  {WM_QUEUESYNC, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvQueueSync)}

#define EV_WM_RBUTTONDBLCLK\
  {WM_RBUTTONDBLCLK, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvRButtonDblClk)}

#define EV_WM_RBUTTONDOWN\
  {WM_RBUTTONDOWN, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvRButtonDown)}

#define EV_WM_RBUTTONUP\
  {WM_RBUTTONUP, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvRButtonUp)}

#define EV_WM_RENDERALLFORMATS\
  {WM_RENDERALLFORMATS, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvRenderAllFormats)}

#define EV_WM_RENDERFORMAT\
  {WM_RENDERFORMAT, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_U_Sig(&TMyClass::EvRenderFormat)}

#define EV_WM_SETCURSOR\
  {WM_SETCURSOR, 0, (TAnyDispatcher)::U_U_U_U_Dispatch,\
   (TMyPMF)B_W_U_U_Sig(&TMyClass::EvSetCursor)}

#define EV_WM_SETFOCUS\
  {WM_SETFOCUS, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_W_Sig(&TMyClass::EvSetFocus)}

#define EV_WM_SETFONT\
  {WM_SETFONT, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_HFONT_B_Sig(&TMyClass::EvSetFont)}

#define EV_WM_SETREDRAW\
  {WM_SETREDRAW, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_B_Sig(&TMyClass::EvSetRedraw)}

#define EV_WM_SETTEXT\
  {WM_SETTEXT, 0, (TAnyDispatcher)::v_LPARAM_Dispatch,\
   (TMyPMF)v_CS_Sig(&TMyClass::EvSetText)}

#define EV_WM_SHOWWINDOW\
  {WM_SHOWWINDOW, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_B_U_Sig(&TMyClass::EvShowWindow)}

#define EV_WM_SIZE\
  {WM_SIZE, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_SIZE_Sig(&TMyClass::EvSize)}

#define EV_WM_SIZECLIPBOARD\
  {WM_SIZECLIPBOARD, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_W_H_Sig(&TMyClass::EvSizeClipboard)}

#define EV_WM_SPOOLERSTATUS\
  {WM_SPOOLERSTATUS, 0, (TAnyDispatcher)::v_U_U_Dispatch,\
   (TMyPMF)v_U_U_Sig(&TMyClass::EvSpoolerStatus)}

#define EV_WM_SYSCHAR\
  {WM_SYSCHAR, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_U_U_U_Sig(&TMyClass::EvSysChar)}

#define EV_WM_SYSCOLORCHANGE\
  {WM_SYSCOLORCHANGE, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvSysColorChange)}

#define EV_WM_SYSCOMMAND\
  {WM_SYSCOMMAND, 0, (TAnyDispatcher)::v_U_POINT_Dispatch,\
   (TMyPMF)v_U_POINT_Sig(&TMyClass::EvSysCommand)}

#define EV_WM_SYSDEADCHAR\
  {WM_SYSDEADCHAR, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_U_U_U_Sig(&TMyClass::EvSysDeadChar)}

#define EV_WM_SYSKEYDOWN\
  {WM_SYSKEYDOWN, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_U_U_U_Sig(&TMyClass::EvSysKeyDown)}

#define EV_WM_SYSKEYUP\
  {WM_SYSKEYUP, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_U_U_U_Sig(&TMyClass::EvSysKeyUp)}

#define EV_WM_SYSTEMERROR\
  {WM_SYSTEMERROR, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_U_Sig(&TMyClass::EvSystemError)}

#define EV_WM_TIMECHANGE\
  {WM_TIMECHANGE, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvTimeChange)}

#define EV_WM_TIMER\
  {WM_TIMER, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_U_Sig(&TMyClass::EvTimer)}

#define EV_WM_VKEYTOITEM\
  {WM_VKEYTOITEM, 0, (TAnyDispatcher)::i_U_W_U_Dispatch,\
   (TMyPMF)i_U_W_U_Sig(&TMyClass::EvVKeyToItem)}

#define EV_WM_VSCROLL\
  {WM_VSCROLL, 0, (TAnyDispatcher)::v_U_U_W_Dispatch,\
   (TMyPMF)v_U_U_W_Sig(&TMyClass::EvVScroll)}

#define EV_WM_VSCROLLCLIPBOARD\
  {WM_VSCROLLCLIPBOARD, 0, (TAnyDispatcher)::v_U_U_U_Dispatch,\
   (TMyPMF)v_W_U_U_Sig(&TMyClass::EvVScrollClipboard)}

#define EV_WM_WINDOWPOSCHANGED\
  {WM_WINDOWPOSCHANGED, 0, (TAnyDispatcher)::v_LPARAM_Dispatch,\
   (TMyPMF)v_WINDOWPOS_Sig(&TMyClass::EvWindowPosChanged)}

#define EV_WM_WINDOWPOSCHANGING\
  {WM_WINDOWPOSCHANGING, 0, (TAnyDispatcher)::v_LPARAM_Dispatch,\
   (TMyPMF)v_WINDOWPOS_Sig(&TMyClass::EvWindowPosChanging)}

#define EV_WM_WININICHANGE\
  {WM_WININICHANGE, 0, (TAnyDispatcher)::v_LPARAM_Dispatch,\
   (TMyPMF)v_S_Sig(&TMyClass::EvWinIniChange)}

//
// Control notification macros
//

#define EV_BN_CLICKED(id, method)   EV_CHILD_NOTIFY(id, BN_CLICKED, method)
#define EV_BN_DISABLE(id, method)   EV_CHILD_NOTIFY(id, BN_DISABLE, method)
#define EV_BN_DOUBLECLICKED(id, method)  EV_CHILD_NOTIFY(id, BN_DOUBLECLICKED, method)
#define EV_BN_HILITE(id, method)    EV_CHILD_NOTIFY(id, BN_HILITE, method)
#define EV_BN_PAINT(id, method)     EV_CHILD_NOTIFY(id, BN_PAINT, method)
#define EV_BN_UNHILITE(id, method)  EV_CHILD_NOTIFY(id, BN_UNHILITE, method)

#define EV_CBN_CLOSEUP(id, method)    EV_CHILD_NOTIFY(id, CBN_CLOSEUP, method)
#define EV_CBN_DBLCLK(id, method)     EV_CHILD_NOTIFY(id, CBN_DBLCLK, method)
#define EV_CBN_DROPDOWN(id, method)   EV_CHILD_NOTIFY(id, CBN_DROPDOWN, method)
#define EV_CBN_EDITCHANGE(id, method) EV_CHILD_NOTIFY(id, CBN_EDITCHANGE, method)
#define EV_CBN_EDITUPDATE(id, method) EV_CHILD_NOTIFY(id, CBN_EDITUPDATE, method)
#define EV_CBN_ERRSPACE(id, method)   EV_CHILD_NOTIFY(id, CBN_ERRSPACE, method)
#define EV_CBN_KILLFOCUS(id, method)  EV_CHILD_NOTIFY(id, CBN_KILLFOCUS, method)
#define EV_CBN_SELCHANGE(id, method)  EV_CHILD_NOTIFY(id, CBN_SELCHANGE, method)
#define EV_CBN_SELENDCANCEL(id, method) EV_CHILD_NOTIFY(id, CBN_SELENDCANCEL, method)
#define EV_CBN_SELENDOK(id, method)   EV_CHILD_NOTIFY(id, CBN_SELENDOK, method)
#define EV_CBN_SETFOCUS(id, method)   EV_CHILD_NOTIFY(id, CBN_SETFOCUS, method)

#define EV_EN_CHANGE(id, method)    EV_CHILD_NOTIFY(id, EN_CHANGE, method)
#define EV_EN_ERRSPACE(id, method)  EV_CHILD_NOTIFY(id, EN_ERRSPACE, method)
#define EV_EN_HSCROLL(id, method)   EV_CHILD_NOTIFY(id, EN_HSCROLL, method)
#define EV_EN_KILLFOCUS(id, method) EV_CHILD_NOTIFY(id, EN_KILLFOCUS, method)
#define EV_EN_MAXTEXT(id, method)   EV_CHILD_NOTIFY(id, EN_MAXTEXT, method)
#define EV_EN_SETFOCUS(id, method)  EV_CHILD_NOTIFY(id, EN_SETFOCUS, method)
#define EV_EN_UPDATE(id, method)    EV_CHILD_NOTIFY(id, EN_UPDATE, method)
#define EV_EN_VSCROLL(id, method)   EV_CHILD_NOTIFY(id, EN_VSCROLL, method)

#define EV_LBN_DBLCLK(id, method)    EV_CHILD_NOTIFY(id, LBN_DBLCLK, method)
#define EV_LBN_ERRSPACE(id, method)  EV_CHILD_NOTIFY(id, LBN_ERRSPACE, method)
#define EV_LBN_KILLFOCUS(id, method) EV_CHILD_NOTIFY(id, LBN_KILLFOCUS, method)
#define EV_LBN_SELCANCEL(id, method) EV_CHILD_NOTIFY(id, LBN_SELCANCEL, method)
#define EV_LBN_SELCHANGE(id, method) EV_CHILD_NOTIFY(id, LBN_SELCHANGE, method)
#define EV_LBN_SETFOCUS(id, method)  EV_CHILD_NOTIFY(id, LBN_SETFOCUS, method)

#define EV_SB_LINEDOWN(id, method)   EV_CHILD_NOTIFY(id, SB_LINEDOWN, method)
#define EV_SB_LINEUP(id, method)     EV_CHILD_NOTIFY(id, SB_LINEUP, method)
#define EV_SB_PAGEDOWN(id, method)   EV_CHILD_NOTIFY(id, SB_PAGEDOWN, method)
#define EV_SB_PAGEUP(id, method)     EV_CHILD_NOTIFY(id, SB_PAGEUP, method)
#define EV_SB_TOP(id, method)        EV_CHILD_NOTIFY(id, SB_TOP, method)
#define EV_SB_BOTTOM(id, method)     EV_CHILD_NOTIFY(id, SB_BOTTOM, method)
#define EV_SB_THUMBPOSITION(id, method) EV_CHILD_NOTIFY(id, SB_THUMBPOSITION, method)
#define EV_SB_ENDSCROLL(id, method)  EV_CHILD_NOTIFY(id, SB_ENDSCROLL, method)
#define EV_SB_BEGINTRACK(id, method) EV_CHILD_NOTIFY(id, 9, method)

#endif  // OWL_WINDOWEV_H
