//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
// $Revision:   10.12  $
//
// Implementation of classes TVbxControl and TBIVbxLibrary.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_VBXCTL_H)
# include <owl/vbxctl.h>
#endif

OWL_DIAGINFO;

//----------------------------------------------------------------------------

const char BIVbxClassPrefix[] = "THUNDER";

//
//
//
TBIVbxLibrary::TBIVbxLibrary()
{
  // Initialize the VBX support
  //
  if (!::VBXInit(_hInstance, BIVbxClassPrefix))
    TXVbxLibrary::Raise();
}

//
//
//
TBIVbxLibrary::~TBIVbxLibrary()
{
  ::VBXTerm();
}

//----------------------------------------------------------------------------

//
// Exception class for VBX errors other than initial DLL load
//

//
//
//
TXVbxLibrary::TXVbxLibrary()
:
  TXOwl(IDS_VBXLIBRARYFAIL)
{
}

#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXVbxLibrary*
#endif
TXVbxLibrary::Clone()
{
  return new TXVbxLibrary(*this);
}

//
//
//
void
TXVbxLibrary::Throw()
{
  THROW( *this );
}

//
//
//
void
TXVbxLibrary::Raise()
{
  TXVbxLibrary().Throw();
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE2(TVbxControl, TControl, TVbxEventHandler)
  EV_MESSAGE(WM_VSCROLL,EvDefaultProcessing),
  EV_MESSAGE(WM_HSCROLL,EvDefaultProcessing),
  EV_MESSAGE(WM_COMPAREITEM,EvDefaultProcessing),
  EV_MESSAGE(WM_DELETEITEM,EvDefaultProcessing),
  EV_MESSAGE(WM_DRAWITEM,EvDefaultProcessing),
  EV_MESSAGE(WM_MEASUREITEM,EvDefaultProcessing),
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TVbxControl);

//
// Constructor for a TVbxControl object
//
TVbxControl::TVbxControl(TWindow*        parent,
                         int             id,
                         const char far* vbxName,
                         const char far* vbxClass,
                         const char far* title,
                         int             x,
                         int             y,
                         int             w,
                         int             h,
                         long            initLen,
                         void far*       initData,
                         TModule*        module)
:
  TControl(parent, id, title, x, y, w, h, module)
{
  VbxName = strnewdup(vbxName);
  VbxClass = strnewdup(vbxClass);
  HCtl = 0;
  InitLen = initLen;
  InitData = initData;
  Attr.Style = 0;
}

//
// Constructor for a TVbxControl to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition
//
TVbxControl::TVbxControl(TWindow*   parent,
                         int        resourceId,
                         TModule*   module)
:
  TControl(parent, resourceId, module)
{
  VbxName = 0;
  VbxClass = 0;
  HCtl = 0;
  InitLen = 0;
  InitData = 0;
}

//
//
//
TVbxControl::~TVbxControl()
{
  delete[] VbxName;
  delete[] VbxClass;
}

//
//
//
void
TVbxControl::SetupWindow()
{
  TControl::SetupWindow();

  // If we haven't bound to HCtl yet, do it here
  //
  if (!HCtl)
    HCtl = ::VBXGetHctl(GetHandle());
}

//
//
//
TResult
TVbxControl::EvDefaultProcessing(TParam1, TParam2)
{
  return DefaultProcessing();
}

//
// Return name of VBX window class
//
char far*
TVbxControl::GetClassName()
{
  return "VBCONTROL";
}

//
// Perform MS Windows window creation
//
void
TVbxControl::PerformCreate(int menuOrId)
{
  HFORMFILE formFile = 0;

  if (InitData)
    formFile = ::VBXCreateFormFile(InitLen,InitData);

  HCtl = ::VBXCreate(Parent->GetHandle(), menuOrId, VbxName, VbxClass, Title,
                     Attr.Style, Attr.X, Attr.Y, Attr.W, Attr.H, formFile);
  if (formFile)
    ::VBXDeleteFormFile(formFile);

  SetHandle(::VBXGetHwnd(HCtl));
}

//
// Get a string property
//
bool
TVbxControl::GetProp(int prop, string& value, int /*index*/)
{
#if defined(BI_PLAT_WIN32)
  uint32 strHandle;
  if (!VBXGetProp(HCtl, prop, &strHandle))
    return false;

  char buf[256];
  *buf = 0xff;
  if (!::VBXGetCStringBuf(HSZ(strHandle), buf, sizeof(buf))
   && *buf == char(0xff))
    return false;
  value = buf;
  ::VBXDestroyCString(HSZ(strHandle));
  return true;
#else
  uint32 strHandle;
  if (!VBXGetProp(HCtl, prop, &strHandle))
    return false;

  char far* str = ::VBXGetCStringPtr(HSZ(strHandle));
  value = str;
  ::VBXDestroyCString(HSZ(strHandle));
  return true;
#endif
}

//
// Get a VBX property
//
bool
TVbxControl::GetVBXProperty(int propIndex, void far* value, int arrayIndex)
{
  if (arrayIndex == -1)
    return ::VBXGetProp(HCtl, propIndex, value);
  else
    return ::VBXGetArrayProp(HCtl, propIndex, arrayIndex, value);
}

//
// Set a VBX property
//
bool
TVbxControl::SetVBXProperty(int propIndex, int32 value, int arrayIndex)
{
  if (arrayIndex == -1)
    return ::VBXSetProp(HCtl, propIndex, value);
  else
    return ::VBXSetArrayProp(HCtl, propIndex, arrayIndex, value);
}


//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE(TVbxEventHandler)
  EV_MESSAGE(WM_VBXFIREEVENT, EvVbxDispatch),
  EV_MESSAGE(WM_VBXINITFORM, EvVbxInitForm),
END_RESPONSE_TABLE;

class TVbxEventInfo : public TEventHandler::TEventInfo {
  public:
    TVbxEventInfo(const char far* eventName, uint msg, uint id = 0)
      : TEventHandler::TEventInfo(msg, id), EventName(eventName) {}

    const char far* EventName;
};

//
// Compare a response table entry to an eventinfo struct, looking for a
// string version of an entry.
// String is in dispatcher field of the entry, & the Entry field of the info.
// If found, replace with i_LPARAM_Dispatch and insert the info's msg into
// the msg field.
//
static bool
VbxEqualOperator(TGenericTableEntry __RTFAR& entry,
                 TEventHandler::TEventInfo& info)
{
  if (entry.Msg == WM_VBXNAME && entry.Id == info.Id &&
      strcmpi((const char far*)(*(TVbxEventInfo*)&info).EventName,
              (const char far*)entry.Dispatcher) == 0) {
     entry.Msg = info.Msg;
     entry.Dispatcher = (TAnyDispatcher)::i_LPARAM_Dispatch;
     return true;
   }
   return false;
}

#if defined(BI_PLAT_WIN32)
//
// Find which VBX sent this event.
//
void
TVbxEventHandler::FindVBX(TWindow *c, LPPARAM p)
{
  if(!p->vbx) {
    TVbxControl *vbx = TYPESAFE_DOWNCAST(c, TVbxControl);
    if(vbx && HWND16TO32(vbx->GetHandle()) == p->hWnd)
      p->vbx = vbx;
  }
}

//
// This function determines which environment the
// application is running under, NT or other versions of Windows, and
// get the object pointer accordingly.
//
TWindow*
TVbxEventHandler::GetWindowPtr( HWND Window )
{
  if (!TSystem::IsNT()) {
#if defined(BI_NAMESPACE)
    return OWL::GetWindowPtr(Window);
#else
    return ::GetWindowPtr(Window);
#endif
  }

  TWindow *Dlg = TYPESAFE_DOWNCAST(this, TWindow);

  if(Dlg)  {
    PARAM p = {Window};
    Dlg->ForEach(LPFNFOREACH(FindVBX), &p);
    return p.vbx;
  }

  return NULL;
#pragma warn -aus
}
#pragma warn .aus
#endif BI_PLAT_WIN32

//
// Handle a VBX fire event message by forwarding to control and/or
// sub-dispatching to specific event handlers.
//
TResult
TVbxEventHandler::EvVbxDispatch(TParam1 p1, TParam2 p2)
{
  VBXEVENT far* e = (VBXEVENT far*)p2;
  TVbxEventInfo eventInfo(e->EventName, WM_VBXBASE + e->EventIndex,
                          ::GetDlgCtrlID(e->Window));

  // If the control is not us, then send the fire event message to it to give
  // it first crack.
  //
  TWindow* ctl = GetWindowPtr( e->Window );
  if (ctl &&
    STATIC_CAST(TEventHandler*, ctl) != STATIC_CAST(TEventHandler*, this))
    if (ctl->HandleMessage(WM_VBXFIREEVENT, p1, p2))
      return 1;

  // See if we have a handler for this event
  //
  if (Find(eventInfo) || Find(eventInfo, VbxEqualOperator))
    return Dispatch(eventInfo, p1, p2);
  return 0;
}

//
//
//
TResult
TVbxEventHandler::EvVbxInitForm(TParam1 p1, TParam2 p2)
{
  HWND hWnd = HWND(p1);
#if defined(BI_PLAT_WIN32)
  HINSTANCE hInst = HINSTANCE(::GetWindowLong(hWnd, GWL_HINSTANCE));
#else
  HINSTANCE hInst = HINSTANCE(::GetWindowWord(hWnd, GWW_HINSTANCE));
#endif
  return ::VBXInitDialog(hWnd, hInst, (char far*)p2) ? 1 : -1;
}
