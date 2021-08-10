//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.26  $
//
// Definition of classes for CommonControl encapsulation
//----------------------------------------------------------------------------
#if !defined(OWL_COMMCTRL_H)
#define OWL_COMMCTRL_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#if !defined(__RICHEDIT_H) && defined(BI_PLAT_WIN32)
# include <richedit.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

//
// Property sheets notify property pages of events via the standard WM_NOTIFY/
// NMHDR* mechanism. However, there is no Control ID involved in this
// particular flavour of notification. The WM_NOTIFY handler of ObjectWindows
// relies on the CtlID for subdispatching. Hence, we'll have 'PropPageID' as
// the default identifier so that we do not have to repeat dispatching logic
// in the 'EvNotify' of TPropertyPage.
//
const int PropPageID = 0xFFF0;

//----------------------------------------------------------------------------


//
// Get the necessary system headers
//
#if !defined(_INC_COMMCTRL)
# include <commctrl.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// Define some missing commctrl structs
//
#if !defined(BI_PLAT_WIN32)
  typedef struct _IMAGEINFO {
    HBITMAP hbmImage;
    HBITMAP hbmMask;
    int     Unused1;
    int     Unused2;
    RECT    rcImage;
  } IMAGEINFO;
#endif

//----------------------------------------------------------------------------
// Forward declaration of classes used in dispatch macros
//
class _OWLCLASS THdrItem;


//
// class TCommCtrlDll
// ~~~~~ ~~~~~~~~~~~~
// Actual TModule derivative that wraps the common control DLL
//
class _OWLCLASS TCommCtrlDll : public TModule {
  public:
    TCommCtrlDll();

    TModuleProcV0 InitCommonControls;

#if defined(BI_PLAT_WIN32)
    TModuleProc3<int,HIMAGELIST,HBITMAP,COLORREF> ImageList_AddMasked;
    TModuleProc4<BOOL,HIMAGELIST,int,int,int>ImageList_BeginDrag;

    TModuleProcV0 ImageList_EndDrag;
    TModuleProc3<BOOL,HWND,int,int> ImageList_DragEnter;
    TModuleProc1<BOOL,HWND> ImageList_DragLeave;
    TModuleProc2<BOOL,int,int> ImageList_DragMove;
    TModuleProc4<BOOL,HIMAGELIST,int,int,int> ImageList_SetDragCursorImage;

    TModuleProc1<BOOL,BOOL> ImageList_DragShowNolock;
    TModuleProc2<HIMAGELIST,POINT FAR*,POINT FAR*> ImageList_GetDragImage;

    TModuleProc10<BOOL,HIMAGELIST,int,HDC,int,int,int,int,COLORREF,COLORREF,UINT> ImageList_DrawEx;
    TModuleProc3<BOOL,HIMAGELIST,int FAR*,int FAR*> ImageList_GetIconSize;
    TModuleProc3<HICON,HIMAGELIST,int,UINT> ImageList_GetIcon;
    TModuleProc3<BOOL,HIMAGELIST,int,IMAGEINFO FAR*> ImageList_GetImageInfo;
    TModuleProc4<BOOL,HIMAGELIST,int,HBITMAP,HBITMAP> ImageList_Replace;
    TModuleProc2<BOOL,HIMAGELIST,int> ImageList_Remove;
    TModuleProc7<HIMAGELIST,HINSTANCE,LPCSTR,int,int,COLORREF,UINT,UINT> ImageList_LoadImage;
    TModuleProc6<HIMAGELIST,HIMAGELIST,int,HIMAGELIST,int,int,int> ImageList_Merge;
    TModuleProc3<BOOL,HIMAGELIST,int,int> ImageList_SetIconSize;
#endif

    TModuleProc5<HBITMAP,HINSTANCE,int,UINT,LPCOLORMAP,int> CreateMappedBitmap;
    TModuleProc1<HPROPSHEETPAGE,LPCPROPSHEETPAGE> CreatePropertySheetPage;
    TModuleProc4<HWND,LONG,LPCSTR,HWND,UINT> CreateStatusWindow;
    TModuleProc13<HWND,HWND,DWORD,UINT,int,HINSTANCE,UINT,LPCTBBUTTON,int,int,
                   int,int,int,UINT> CreateToolbarEx;
    TModuleProc12<HWND,DWORD,int,int,int,int,HWND,int,HINSTANCE,HWND,int,int,
                   int> CreateUpDownControl;
    TModuleProc1<BOOL,HPROPSHEETPAGE> DestroyPropertySheetPage;
    TModuleProcV3<HWND,HWND,int> DrawInsert;
    TModuleProcV4<HDC,LPRECT,LPCSTR,UINT> DrawStatusText;
    TModuleProcV3<HWND,LPRECT,LPINT> GetEffectiveClientRect;

    TModuleProc5<HIMAGELIST,int,int,UINT,int,int> ImageList_Create;
    TModuleProc1<BOOL,HIMAGELIST> ImageList_Destroy;
    TModuleProc1<int,HIMAGELIST> ImageList_GetImageCount;
    TModuleProc3<int,HIMAGELIST,HBITMAP,HBITMAP> ImageList_Add;
    TModuleProc3<int,HIMAGELIST,int,HICON> ImageList_ReplaceIcon;
    TModuleProc2<COLORREF,HIMAGELIST,COLORREF> ImageList_SetBkColor;
    TModuleProc1<COLORREF,HIMAGELIST> ImageList_GetBkColor;
    TModuleProc3<BOOL,HIMAGELIST,int,int> ImageList_SetOverlayImage;
    TModuleProc6<BOOL,HIMAGELIST,int,HDC,int,int,UINT> ImageList_Draw;

    TModuleProc3<int,HWND,POINT,BOOL> LBItemFromPt;
    TModuleProc1<BOOL,HWND> MakeDragList;
    TModuleProcV7<UINT,TParam1,TParam2,HMENU,HINSTANCE,HWND,UINT FAR*> MenuHelp;
    TModuleProc1<int,LPCPROPSHEETHEADER> PropertySheet;
    TModuleProc3<BOOL,HWND,UINT,LPINT> ShowHideMenuCtl;
};



//
// Simple wrapper class which creates a single instance of the TCommCtrlDll
// class defined above.
//
class _OWLCLASS TCommCtrl {
  public:
    static TCommCtrlDll* Dll();
    static bool          IsAvailable();
};


//
// class TXCommCtrl
// ~~~~~ ~~~~~~~~~~
// Exception object thrown by the Common Control wrappers of ObjectWindows.
//
class _OWLCLASS_RTL TXCommCtrl : public TXOwl {
  public:
    TXCommCtrl();
#if defined(BI_NO_COVAR_RET)
    TXBase*     Clone();
#else
    TXCommCtrl* Clone();
#endif
    void        Throw();
    static void Raise();
};

//
// class TNotify
// ~~~~~ ~~~~~~~
// TNotify is a thin wrapper around the NMHDR structure. It's a
// place-holder for future enhancements for handling notifications.
//
class _OWLCLASS TNotify : public NMHDR {
  public:
    TNotify();
    TNotify(HWND ctl, uint id, uint code);
};


//----------------------------------------------------------------------------
// Structures used for UpDown (Spin Ctrl) notifications
//----------------------------------------------------------------------------
//
// class TNmUpDown
// ~~~~~ ~~~~~~~~~
// TNmUpDown is a wrapper of the NM_UPDOWN structure sent with
// notifications from an 'UpDown' control.
//
class _OWLCLASS TNmUpDown : public NM_UPDOWN {
  public:
    TNmUpDown(HWND hwnd, uint id, uint code, int pos, int delta);  

    // Allows the notification structure to be transparently treated an
    // an NMHDR structure thereby eliminating the need to explicitly refer
    // to the NMHDR data member [always the first member of notification
    // structures]
    //
    operator  NMHDR&() { return hdr; }
};



//----------------------------------------------------------------------------
// Structures used for Tab Control notifications
//----------------------------------------------------------------------------
//
// class TTabKeyDown
// ~~~~~ ~~~~~~~~~~~
// Wrapper of the TC_KEYDOWN structure sent to the parent of a tabcontrol
// to notify that a key has been pressed
//
class _OWLCLASS TTabKeyDown : public TC_KEYDOWN {
  public:
    TTabKeyDown();
    TTabKeyDown(HWND ctl, uint id, uint code, uint16 vk, uint flg);

    operator  NMHDR&() { return hdr; }
};



//----------------------------------------------------------------------------
// Structures used for tooltip notifications & API
//----------------------------------------------------------------------------
//
// class TTooltipText
// ~~~~~ ~~~~~~~~~~~~
// TTooltipText identifies a tool for which text is to be displayed. It
// is sent to the parent of the tooltip via a WM_NOTIFY/TTN_NEEDTEXT
// notification. It receives the text to be displayed.
//
class _OWLCLASS TTooltipText : public TOOLTIPTEXT {
  public:
    operator  NMHDR&() { return hdr; }

    // Set the text to be displayed for the tool.
    //
    void        SetText(char far* buff);
    void        SetText(int resId, HINSTANCE hInstance);
    void        CopyText(const char far* buff);
};



//----------------------------------------------------------------------------
// Structures used for Column Header notifications
//----------------------------------------------------------------------------
//
// class THdrNotify
// ~~~~~ ~~~~~~~~~~
// THdrNotify encapsulates the 'HD_NOTIFY' structure which is sent
// with the WM_NOTIFY messages sent by the HeaderControl to its parent.
//
class _OWLCLASS THdrNotify : public HD_NOTIFY {
  public:
    operator  NMHDR&() { return hdr; }
};



//----------------------------------------------------------------------------
// Structures used for RichEdit notifications and API
//----------------------------------------------------------------------------
#if defined(BI_PLAT_WIN32)
//
// class TEnDropFiles
// ~~~~~ ~~~~~~~~~~~~
// Structure sent with EN_DROPFILES notification.
//
class _OWLCLASS TEnDropFiles : public ENDROPFILES {
  public:
    operator  NMHDR&() { return nmhdr; }
};

//
// class TMsgFilter
// ~~~~~ ~~~~~~~~~~
// Structure sent with EN_MSGFILTER notification
//
class _OWLCLASS TMsgFilter : public MSGFILTER {
  public:
    operator  NMHDR&() { return nmhdr; }
};

//
// class TEnProtected
// ~~~~~ ~~~~~~~~~~~~
// Structure sent with EN_PROTECTED notification
//
class _OWLCLASS TEnProtected : public ENPROTECTED {
  public:
    operator  NMHDR&() { return nmhdr; }
};

//
// class TReqResize
// ~~~~~ ~~~~~~~~~~
// Structure sent with EN_REQUESTRESIZE notification
//
class _OWLCLASS TReqResize : public REQRESIZE {
  public:
    operator  NMHDR&() { return nmhdr; }
};

//
// class TSelChange
// ~~~~~ ~~~~~~~~~~
// Structure sent with EN_SELCHANGE notification
//
class _OWLCLASS TSelChange : public SELCHANGE {
  public:
    operator  NMHDR&() { return nmhdr; }
};

#endif  //  BI_PLAT_WIN32

//
// Forward declarations of notifications
//

#include <pshpack1.h>

//----------------------------------------------------------------------------
// Structures used for ListView control (TListWindow) notifications
//----------------------------------------------------------------------------
//
// class TLwNotify
// ~~~~~ ~~~~~~~~~
// Basic TListWindow notification
//
class _OWLCLASS TLwNotify : public _NM_LISTVIEW {
  public:
    operator  NMHDR&() { return hdr; }
};

//
// class TLwDispInfoNotify
// ~~~~~ ~~~~~~~~~~~~~~~~~
// A TListWindow notification to repaint an item.
//
class _OWLCLASS TLwDispInfoNotify : public _LV_DISPINFO {
  public:
    operator  NMHDR&() { return hdr; }
};

//
// class TLwKeyDownNotify
// ~~~~~ ~~~~~~~~~~~~~~~~
// A TListWindow notification that a key has been pressed.
//
class _OWLCLASS TLwKeyDownNotify : public _LV_KEYDOWN {
  public:
    operator  NMHDR&() { return hdr; }
};



//----------------------------------------------------------------------------
// Structures used for TreeView control (TTreeWindow) notifications
//----------------------------------------------------------------------------
//
// class TTwNotify
// ~~~~~ ~~~~~~~~~
// Basic TTreeWindow notification
//
class _OWLCLASS TTwNotify : public NM_TREEVIEW {
  public:
    operator  NMHDR&() { return hdr; }
};

//
// class TTwDispInfoNotify
// ~~~~~ ~~~~~~~~~~~~~~~~~
// A TTreeWindow notification to repaint an item.
//
class _OWLCLASS TTwDispInfoNotify : public TV_DISPINFO {
  public:
    operator  NMHDR&() { return hdr; }
};

//
// class TTwKeyDownNotify
// ~~~~~ ~~~~~~~~~~~~~~~~
// A TTreeWindow notification that a key has been pressed.
//
class _OWLCLASS TTwKeyDownNotify : public TV_KEYDOWN {
  public:
    operator  NMHDR&() { return hdr; }
};

//
// class TTwHitTestInfo
// ~~~~~ ~~~~~~~~~~~~~~
// A TTreeWindow notification for hit-testing.
//
class _OWLCLASS TTwHitTestInfo : public TV_HITTESTINFO {
  public:
};


// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// DISPATCH.H
//
int32 _OWLFUNC
v_NMHDRCode_Dispatch(GENERIC& generic,
                     void    (GENERIC::*pmf)(uint),
                     uint     wParam,
                     int32    lParam);

//----------------------------------------------------------------------------
// SIGNATURE.H
//
template <class T>
inline void _CALLCNVN (T::*v_NMHDR_Sig(void _CALLCNVN (T::*pmf)(NMHDR far&)))(NMHDR far&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*b_NMHDR_Sig(bool _CALLCNVN (T::*pmf)(NMHDR far&)))(NMHDR far&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_NOTIFY_Sig(void _CALLCNVN (T::*pmf)(TNotify far&)))(TNotify far&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*b_NOTIFY_Sig(bool _CALLCNVN (T::*pmf)(TNotify far&)))(TNotify far&)
{
  return pmf;
}

template <class T>
inline int _CALLCNVN (T::*i_NOTIFY_Sig(int _CALLCNVN (T::*pmf)(TNotify far&)))(TNotify far&)
{
  return pmf;
}

//----------------------------------------------------------------------------
// WINDOWEV.H
//

//
// Notification handled by parent with handler returning void
//      i.e.  void method()
//
#define EV_COMMCTL_NOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_Dispatch,\
  (TMyPMF)v_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting notification
// code.        i.e. void method(uint notifyCode)
//
#define EV_COMMCTL_NOTIFY_AND_CODE(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_NMHDRCode_Dispatch,\
  (TMyPMF)v_U_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting NMHDR&
// as parameter.        i.e. void method(NMHDR& nmHdr)
//
#define EV_COMMCTL_NOTIFY_AND_NMHDR(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_NMHDR_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting NMHDR& and
// returning a bool.
//                      i.e. bool method(NMHDR& nmHdr)
//
#define EV_COMMCTL_NOTIFY_BOOL_AND_NMHDR(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_NMHDR_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TNotify&
// as parameter.
//                      i.e. void method(TNotify& nmHdr)
//
#define EV_COMMCTL_NOTIFY_AND_NOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_NOTIFY_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TNotify& and
// returning a bool.
//                      i.e. bool method(TNotify& nmHdr)
//
#define EV_COMMCTL_NOTIFY_BOOL_AND_NOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_NOTIFY_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TNotify& and
// returning an int.
//                      i.e. int method(TNotify& nmHdr)
//
#define EV_COMMCTL_NOTIFY_INT_AND_NOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::i_LPARAM_Dispatch,\
  (TMyPMF)i_NOTIFY_Sig(&TMyClass::method)}

#define EV_NM_CLICK(id, method)       EV_COMMCTL_NOTIFY(id, NM_CLICK, method)
#define EV_NM_DBLCLK(id, method)      EV_COMMCTL_NOTIFY(id, NM_DBLCLK, method)
#define EV_NM_KILLFOCUS(id, method)   EV_COMMCTL_NOTIFY(id, NM_KILLFOCUS, method)
#define EV_NM_OUTOFMEMORY(id, method) EV_COMMCTL_NOTIFY(id, NM_OUTOFMEMORY, method)
#define EV_NM_RCLICK(id, method)      EV_COMMCTL_NOTIFY(id, NM_RCLICK, method)
#define EV_NM_RDBLCLK(id, method)     EV_COMMCTL_NOTIFY(id, NM_RDBLCLK, method)
#define EV_NM_RETURN(id, method)      EV_COMMCTL_NOTIFY(id, NM_RETURN, method)
#define EV_NM_SETFOCUS(id, method)    EV_COMMCTL_NOTIFY(id, NM_SETFOCUS, method)

//----------------------------------------------------------------------------
// Header control notifications
//
template <class T>
inline void _CALLCNVN (T::*v_HEADERNOTIFY_Sig(void _CALLCNVN (T::*pmf)(THdrNotify far&)))(THdrNotify far&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*b_HEADERNOTIFY_Sig(bool _CALLCNVN (T::*pmf)(THdrNotify far&)))(THdrNotify far&)
{
  return pmf;
}

//
// Notification handled by parent with handler expecting THdrNotify&
// as parameter.        i.e. void method(THdrNotify& nmHdr)
//
#define EV_HEADERNOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_HEADERNOTIFY_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting THdrNotify& and
// returning a bool.
//                      i.e. bool method(THdrNotify& nmHdr)
//
#define EV_HEADERNOTIFY_BOOL(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_HEADERNOTIFY_Sig(&TMyClass::method)}

#define EV_HDN_BEGINTRACK(id, method)       EV_HEADERNOTIFY_BOOL(id, HDN_BEGINTRACK, method)
#define EV_HDN_DIVIDERDBLCLICK(id, method)  EV_HEADERNOTIFY(id, HDN_DIVIDERDBLCLICK, method)
#define EV_HDN_ENDTRACK(id, method)         EV_HEADERNOTIFY(id, HDN_ENDTRACK, method)
#define EV_HDN_ITEMCHANGED(id,method)       EV_HEADERNOTIFY(id, HDN_ITEMCHANGED, method)
#define EV_HDN_ITEMCHANGING(id,method)      EV_HEADERNOTIFY_BOOL(id, HDN_ITEMCHANGING, method)
#define EV_HDN_ITEMCLICK(id, method)        EV_HEADERNOTIFY(id, HDN_ITEMCLICK, method)
#define EV_HDN_TRACK(id, method)            EV_HEADERNOTIFY_BOOL(id, HDN_TRACK, method)

//----------------------------------------------------------------------------
// TabControl notifications
//

template <class T>
inline void _CALLCNVN (T::*v_KEYDOWNNOTIFY_Sig(void _CALLCNVN (T::*pmf)(TTabKeyDown far&)))(TTabKeyDown far&)
{
  return pmf;
}

//
// Notification handled by parent with handler expecting THdrNotify&
// as parameter.        i.e. void method(THdrNotify& nmHdr)
//
#define EV_TCN_KEYDOWN(id, method)\
  {TCN_KEYDOWN, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_KEYDOWNNOTIFY_Sig(&TMyClass::method)}


#define EV_TCN_SELCHANGE(id, method)    EV_COMMCTL_NOTIFY_AND_NOTIFY(id, TCN_SELCHANGE, method)
#define EV_TCN_SELCHANGING(id, method)  EV_COMMCTL_NOTIFY_BOOL_AND_NOTIFY(id, TCN_SELCHANGING, method)

//----------------------------------------------------------------------------
// Property Page Notifications
// NOTE: These macros hard-code the CtlID to PropPageID. Since Property
//       Pages do not have the concept of IDs [the way Ctls have an
//       ID by which their parent can identify them] this mechanism
//       facilitates NOTIFICATION dispatching.
//
#define EV_PSN_APPLY(method) \
        EV_COMMCTL_NOTIFY_INT_AND_NOTIFY(PropPageID, PSN_APPLY, method)

/*
#define EV_PSN_HASHELP(method) \
        EV_COMMCTL_NOTIFY_BOOL_AND_NOTIFY(PropPageID, PSN_HASHELP, method)
*/

#define EV_PSN_HELP(method) \
        EV_COMMCTL_NOTIFY_AND_NOTIFY(PropPageID, PSN_HELP, method)

#define EV_PSN_KILLACTIVE(method)\
        EV_COMMCTL_NOTIFY_BOOL_AND_NOTIFY(PropPageID, PSN_KILLACTIVE, method)

#define EV_PSN_QUERYCANCEL(method)\
        EV_COMMCTL_NOTIFY_BOOL_AND_NOTIFY(PropPageID, PSN_QUERYCANCEL, method)

#define EV_PSN_RESET(method)\
        EV_COMMCTL_NOTIFY_AND_NOTIFY(PropPageID, PSN_RESET, method)

#define EV_PSN_SETACTIVE(method)\
        EV_COMMCTL_NOTIFY_INT_AND_NOTIFY(PropPageID, PSN_SETACTIVE, method)

#define EV_PSN_WIZBACK(method)\
        EV_COMMCTL_NOTIFY_INT_AND_NOTIFY(PropPageID, PSN_WIZBACK, method)

#define EV_PSN_WIZFINISH(method)\
        EV_COMMCTL_NOTIFY_BOOL_AND_NOTIFY(PropPageID, PSN_WIZFINISH, method)

#define EV_PSN_WIZNEXT(method)\
        EV_COMMCTL_NOTIFY_INT_AND_NOTIFY(PropPageID, PSN_WIZNEXT, method)


//----------------------------------------------------------------------------
// RichEdit Control notifications
//

#if defined(BI_PLAT_WIN32)

template <class T>
inline bool _CALLCNVN (T::*b_ENDROPFILES_Sig(bool _CALLCNVN (T::*pmf)(TEnDropFiles far&)))(TEnDropFiles far&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*b_MSGFILTER_Sig(bool _CALLCNVN (T::*pmf)(TMsgFilter far&)))(TMsgFilter far&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*b_PROTECTED_Sig(bool _CALLCNVN (T::*pmf)(TEnProtected far&)))(TEnProtected far&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_REQRESIZE_Sig(void _CALLCNVN (T::*pmf)(TReqResize far&)))(TReqResize far&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*b_SELCHANGE_Sig(bool _CALLCNVN (T::*pmf)(TSelChange far&)))(TSelChange far&)
{
  return pmf;
}

//
// Notification handled by parent with handler expecting TEnDropFiles& and
// returning a bool.
//                      i.e. bool method(TEnDropFiles& nmHdr)
//
#define EV_EN_DROPFILES(id, method)\
  {EN_DROPFILES, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_ENDROPFILES_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TMsgFilter& and
// returning a bool.
//                      i.e. bool method(TMsgFilter& nmHdr)
//
#define EV_EN_MSGFILTER(id, method)\
  {EN_MSGFILTER, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_MSGFILTER_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TEnProtected& and
// returning a bool.
//                      i.e. bool method(TEnProtected& nmHdr)
//
#define EV_EN_PROTECTED(id, method)\
  {EN_PROTECTED, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_PROTECTED_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TReqResize&.
//
//                      i.e. void method(TReqResize& nmHdr)
//
#define EV_EN_REQRESIZE(id, method)\
  {EN_REQUESTRESIZE, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_REQRESIZE_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TSelChange& and
// returning a bool.
//                      i.e. bool method(TSelChange& nmHdr)
//
#define EV_RICHED_EN_SELCHANGE(id, method)\
  {EN_SELCHANGE, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_SELCHANGE_Sig(&TMyClass::method)}

#endif  //  BI_PLAT_WIN32

//----------------------------------------------------------------------------
// UpDown Control notifications
//
//

//
//
//
inline
TNmUpDown::TNmUpDown(HWND hwnd, uint id, uint code, int pos, int delta)
{
  iPos = pos;
  iDelta = delta;
  hdr.hwndFrom = hwnd;
  hdr.idFrom = id;
  hdr.code = code;
}

template <class T>
inline bool _CALLCNVN (T::*b_NMUPDOWN_NOTIFY_Sig(bool _CALLCNVN (T::*pmf)(TNmUpDown far&)))(TNmUpDown far&)
{
  return pmf;
}

//
// Notification handled by parent expecting a TNmUpDown notification
//
//      i.e. bool HandleUpDown(TNmUpDown& updownNot);
//
#define EV_UDN_DELTAPOS(id, method) \
  {UDN_DELTAPOS, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_NMUPDOWN_NOTIFY_Sig(&TMyClass::method)}

//----------------------------------------------------------------------------
// Tooltip notification
//

template <class T>
inline void _CALLCNVN (T::*v_NEEDTEXT_Sig(void _CALLCNVN (T::*pmf)(TTooltipText far&)))(TTooltipText far&)
{
  return pmf;
}

#define EV_TTN_NEEDTEXT(id, method)  \
  {TTN_NEEDTEXT, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_NEEDTEXT_Sig(&TMyClass::method)}


//----------------------------------------------------------------------------
// TreeWind control notifications
//
template <class T>
inline void _CALLCNVN (T::*v_TREEWIND_NOTIFY_Sig(void _CALLCNVN (T::*pmf)(TTwNotify far&)))(TTwNotify far&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*b_TREEWIND_NOTIFY_Sig(bool _CALLCNVN (T::*pmf)(TTwNotify far&)))(TTwNotify far&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_TV_KEYDOWN_NOTIFY_Sig(void _CALLCNVN (T::*pmf)(TTwKeyDownNotify far&)))(TTwKeyDownNotify far&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*b_TV_DISPINFO_NOTIFY_Sig(bool _CALLCNVN (T::*pmf)(TTwDispInfoNotify far&)))(TTwDispInfoNotify far&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_TV_DISPINFO_NOTIFY_Sig(void _CALLCNVN (T::*pmf)(TTwDispInfoNotify far&)))(TTwDispInfoNotify far&)
{
  return pmf;
}

//
// Notification handled by parent with handler expecting TTwNotify&
// as parameter.        i.e. void method(TTwNotify& nmHdr)
//
#define EV_TREEWIND_NOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_TREEWIND_NOTIFY_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TTwNotify& and
// returning a bool.    i.e. bool method(TTwNotify& nmHdr)
//
#define EV_TREEWIND_NOTIFY_BOOL(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_TREEWIND_NOTIFY_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TTwDispInfoNotify&
// as parameter.        i.e. void method(TTwDispInfoNotify& nmHdr)
//
#define EV_TV_DISPINFO_NOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_TV_DISPINFO_NOTIFY_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TTwDispInfoNotify& and
// returning a bool.    i.e. bool method(TTwDispInfoNotify& nmHdr)
//
#define EV_TV_DISPINFO_NOTIFY_BOOL(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_TV_DISPINFO_NOTIFY_Sig(&TMyClass::method)}

#define EV_TVN_BEGINDRAG(id, method)      EV_TREEWIND_NOTIFY        (id, TVN_BEGINDRAG, method)
#define EV_TVN_BEGINLABELEDIT(id, method) EV_TV_DISPINFO_NOTIFY_BOOL(id, TVN_BEGINLABELEDIT, method)
#define EV_TVN_BEGINRDRAG(id, method)     EV_TREEWIND_NOTIFY        (id, TVN_BEGINRDRAG, method)
#define EV_TVN_DELETEITEM(id, method)     EV_TREEWIND_NOTIFY        (id, TVN_DELETEITEM, method)
#define EV_TVN_ENDLABELEDIT(id, method)   EV_TV_DISPINFO_NOTIFY     (id, TVN_ENDLABELEDIT, method)
#define EV_TVN_GETDISPINFO(id, method)    EV_TV_DISPINFO_NOTIFY     (id, TVN_GETDISPINFO, method)
#define EV_TVN_ITEMEXPANDED(id, method)   EV_TREEWIND_NOTIFY        (id, TVN_ITEMEXPANDED, method)
#define EV_TVN_ITEMEXPANDING(id, method)  EV_TREEWIND_NOTIFY_BOOL   (id, TVN_ITEMEXPANDING, method)
#define EV_TVN_SELCHANGED(id, method)     EV_TREEWIND_NOTIFY        (id, TVN_SELCHANGED, method)
#define EV_TVN_SELCHANGING(id, method)    EV_TREEWIND_NOTIFY_BOOL   (id, TVN_SELCHANGING, method)
#define EV_TVN_SETDISPINFO(id, method)    EV_TV_DISPINFO_NOTIFY     (id, TVN_SETDISPINFO, method)
#define EV_TVN_KEYDOWN(id, method)\
  {TVN_KEYDOWN, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_TV_KEYDOWN_NOTIFY_Sig(&TMyClass::method)}

//----------------------------------------------------------------------------
// ListWindow control notifications
//
template <class T>
inline void (T::*v_LISTWIND_NOTIFY_Sig(void (T::*pmf)(TLwNotify far&)))(TLwNotify far&)
{
  return pmf;
}

template <class T>
inline bool (T::*b_LISTWIND_NOTIFY_Sig(bool (T::*pmf)(TLwNotify far&)))(TLwNotify far&)
{
  return pmf;
}

template <class T>
inline void (T::*v_LV_KEYDOWN_NOTIFY_Sig(void (T::*pmf)(TLwKeyDownNotify far&)))(TLwKeyDownNotify far&)
{
  return pmf;
}

template <class T>
inline bool (T::*b_LV_DISPINFO_NOTIFY_Sig(bool (T::*pmf)(TLwDispInfoNotify far&)))(TLwDispInfoNotify far&)
{
  return pmf;
}

template <class T>
inline void (T::*v_LV_DISPINFO_NOTIFY_Sig(void (T::*pmf)(TLwDispInfoNotify far&)))(TLwDispInfoNotify far&)
{
  return pmf;
}

//
// Notification handled by parent with handler expecting TLwNotify&
// as parameter.        i.e. void method(TLwNotify& nmHdr)
//
#define EV_LISTWIND_NOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_LISTWIND_NOTIFY_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TLwNotify& and
// returning a bool.
//                      i.e. bool method(TLwNotify& nmHdr)
//
#define EV_LISTWIND_NOTIFY_BOOL(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_LISTWIND_NOTIFY_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TLwDispInfoNotify&
// as parameter.        i.e. void method(TLwDispInfoNotify& nmHdr)
//
#define EV_LV_DISPINFO_NOTIFY(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_LV_DISPINFO_NOTIFY_Sig(&TMyClass::method)}

//
// Notification handled by parent with handler expecting TLwDispInfoNotify& and
// returning a bool.
//                      i.e. bool method(TLwDispInfoNotify& nmHdr)
//
#define EV_LV_DISPINFO_NOTIFY_BOOL(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::B_LPARAM_Dispatch,\
  (TMyPMF)b_LV_DISPINFO_NOTIFY_Sig(&TMyClass::method)}

#define EV_LVN_KEYDOWN(id, method)\
  {LVN_KEYDOWN, id, (TAnyDispatcher)::v_LPARAM_Dispatch,\
  (TMyPMF)v_LV_KEYDOWN_NOTIFY_Sig(&TMyClass::method)}

#define EV_LVN_BEGINDRAG(id, method)        EV_LISTWIND_NOTIFY(id, LVN_BEGINDRAG, method)
#define EV_LVN_BEGINLABELEDIT(id, method)   EV_LV_DISPINFO_NOTIFY_BOOL(id, LVN_BEGINLABELEDIT, method)
#define EV_LVN_BEGINRDRAG(id, method)       EV_LISTWIND_NOTIFY(id, LVN_BEGINRDRAG, method)
#define EV_LVN_COLUMNCLICK(id, method)      EV_LISTWIND_NOTIFY(id, LVN_COLUMNCLICK, method)
#define EV_LVN_DELETEALLITEMS(id, method)   EV_LISTWIND_NOTIFY(id, LVN_DELETEALLITEMS, method)
#define EV_LVN_DELETEITEM(id, method)       EV_LISTWIND_NOTIFY(id, LVN_DELETEITEM, method)

#if 0   // LVN_ENDDRAG is documented but not defined (currently)
#define EV_LVN_ENDDRAG(id, method)          EV_LISTWIND_NOTIFY(id, LVN_ENDDRAG, method)
#endif

#if 0   // LVN_ENDRDRAG is documented but not defined (currently)
#define EV_LVN_ENDRDRAG(id, method)         EV_LISTWIND_NOTIFY(id, LVN_ENDRDRAG, method)
#endif

#define EV_LVN_ENDLABELEDIT(id, method)     EV_LV_DISPINFO_NOTIFY(id, LVN_ENDLABELEDIT, method)
#define EV_LVN_GETDISPINFO(id, method)      EV_LV_DISPINFO_NOTIFY(id, LVN_GETDISPINFO, method)
#define EV_LVN_INSERTITEM(id, method)       EV_LISTWIND_NOTIFY(id, LVN_INSERTITEM, method)
#define EV_LVN_ITEMCHANGED(id, method)      EV_LISTWIND_NOTIFY(id, LVN_ITEMCHANGED, method)
#define EV_LVN_ITEMCHANGING(id, method)     EV_LISTWIND_NOTIFY_BOOL(id, LVN_ITEMCHANGING, method)
#define EV_LVN_SETDISPINFO(id, method)      EV_LV_DISPINFO_NOTIFY(id, LVN_SETDISPINFO, method)

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implemenations
//

//
// Constructor to create a TNotify object [NMHDR wrapper] from the specified
// window handle, control id and notification code.
//
inline
TNotify::TNotify(HWND ctl, uint id, uint ctlCode) {
  hwndFrom = ctl;
  idFrom = id;
  code = ctlCode;
}

//
// Constructor to create a TNotify object whose members are initialized to
// zero.
//
inline
TNotify::TNotify() {
  hwndFrom = 0;
  idFrom = 0;
  code = 0;
}

//
// TTabKeyDown contains information about a key press in a tab control.
// This constructor initializes the structure NUL value for the
// virtual wVKey and flags members.
//
inline
TTabKeyDown::TTabKeyDown() {
  wVKey = 0;
  flags = 0;
}

//
// TTabKeyDown contains information about a key press in a tab control.
// This constructor initializes the members to the specified parameters.
//
inline TTabKeyDown::TTabKeyDown(HWND ctl, uint id, uint code, uint16 vk, uint flg)
{
  hdr.hwndFrom = ctl;
  hdr.idFrom = id;
  hdr.code = code;
  wVKey = vk;
  flags = flg;
}


#endif  // OWL_COMMCTRL_H

