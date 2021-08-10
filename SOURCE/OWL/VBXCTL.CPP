//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\vbxctl.cpp
//   Implementation of class TVbxControl.
//----------------------------------------------------------------------------
#include "owl\owlpch.h"
#include "owl\vbxctl.h"

//----------------------------------------------------------------------------

const char BIVbxDllName[] = "bivbx10.dll";
const char BIVbxClassPrefix[] = "THUNDER";


TBIVbxLibrary::TBIVbxLibrary()
  : TModule(BIVbxDllName, TRUE)
{
  ::VBXInit(_hInstance, BIVbxClassPrefix);
}

TBIVbxLibrary::~TBIVbxLibrary()
{
  ::VBXTerm();
}
   
//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE2(TVbxControl, TControl, TVbxEventHandler)
  EV_MESSAGE(WM_VSCROLL,EvDefaultProcessing),
  EV_MESSAGE(WM_HSCROLL,EvDefaultProcessing),
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TVbxControl);

//
// constructor for a TVbxControl object
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
  : TControl(parent, id, title, x, y, w, h, module)
{
  VbxName = strnewdup(vbxName);
  VbxClass = strnewdup(vbxClass);
  HCtl = 0;
  InitLen = initLen;
  InitData = initData;
  Attr.Style = 0;
}

void
TVbxControl::SetupWindow()
{
  TControl::SetupWindow();
  //If we haven't bound to HCtl yet, do it here
  if (!HCtl)
    HCtl = ::VBXGetHctl(HWindow);
}

//
// constructor for a TVbxControl to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition
//
TVbxControl::TVbxControl(TWindow*   parent,
                         int        resourceId,
                         TModule*   module)
  : TControl(parent, resourceId, module)
{
  VbxName = 0;
  VbxClass = 0;
  HCtl = 0;
  InitLen = 0;
  InitData = 0;
}

TVbxControl::~TVbxControl()
{
  delete VbxName;
  delete VbxClass;
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

  HCtl = ::VBXCreate(Parent->HWindow, menuOrId, VbxName, VbxClass, Title,
                     Attr.Style, Attr.X, Attr.Y, Attr.W, Attr.H, formFile);
  if (formFile)
    ::VBXDeleteFormFile(formFile);

  HWindow = ::VBXGetHwnd(HCtl);
}

//
// Get a string property
//
BOOL
TVbxControl::GetProp(int prop, string& value, int /*index*/)
{
  long strHandle;
  if (!VBXGetProp(HCtl, prop, &strHandle))
    return FALSE;

  LPSTR str = ::VBXGetCStringPtr(HSZ(strHandle));
  value = str;
  ::VBXDestroyCString(HSZ(strHandle));
  return TRUE;
}

//
// Get a VBX property
//
BOOL
TVbxControl::GetVBXProperty(int propIndex, void far* value, int arrayIndex)
{
  if (arrayIndex == -1)
    return ::VBXGetProp(HCtl, propIndex, value);

  ELEMENTSTRUCT elem;
  elem.Value            = 0;
  elem.NumElems         = 1;
  elem.Element[0].Type  = PTYPE_SHORT;
  elem.Element[0].Index = arrayIndex;
  return ::VBXGetProp(HCtl, propIndex, &elem);
}

//
// Set a VBX property
//
BOOL
TVbxControl::SetVBXProperty(int propIndex, LONG value, int arrayIndex)
{
  if (arrayIndex == -1)
    return ::VBXSetProp(HCtl, propIndex, value);

  ELEMENTSTRUCT elem;
  elem.Value            = value;
  elem.NumElems         = 1;
  elem.Element[0].Type  = PTYPE_SHORT;
  elem.Element[0].Index = arrayIndex;
  return ::VBXSetProp(HCtl, propIndex, long(&elem));
}


//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE(TVbxEventHandler)
  EV_MESSAGE(WM_VBXFIREEVENT, EvVbxDispatch),
END_RESPONSE_TABLE;

class TVbxEventInfo : public TEventHandler::TEventInfo {
  public:
    TVbxEventInfo(LPCSTR eventName, UINT msg, UINT id = 0)
      : TEventHandler::TEventInfo(msg, id), EventName(eventName) {}

    LPCSTR EventName;
};

//
// Compare a response table entry to an eventinfo struct, looking for a
// string version of an entry.
// String is in dispatcher field of the entry, & the Entry field of the info.
// If found, replace with i_LPARAM_Dispatch and insert the info's msg into
// the msg field.
//
static BOOL
VbxEqualOperator(TGenericTableEntry __RTFAR& entry,
                 TEventHandler::TEventInfo& info)
{
  if (entry.Msg == WM_VBXNAME && entry.Id == info.Id &&
      strcmpi((LPCSTR)(*(TVbxEventInfo*)&info).EventName,
              (LPCSTR)entry.Dispatcher) == 0) {
     entry.Msg = info.Msg;
     entry.Dispatcher = (TAnyDispatcher)::i_LPARAM_Dispatch;
     return TRUE;
   }
   return FALSE;
}

//
// Handle a VBX fire event message by forwarding to control and/or 
// sub-dispatching to specific event handlers.
//
LRESULT
TVbxEventHandler::EvVbxDispatch(WPARAM wp, LPARAM lp)
{
  VBXEVENT far* e = (VBXEVENT far*)lp;
  TVbxEventInfo eventInfo(e->EventName, WM_VBXBASE + e->EventIndex,
                          ::GetDlgCtrlID(e->Window));

  //
  // If the control is not us, then send the fire event message to it to give
  // it first crack.
  //
  TWindow* ctl = GetWindowPtr(e->Window);
  if (ctl && 
    STATIC_CAST(TEventHandler*, ctl) != STATIC_CAST(TEventHandler*, this))
    if (ctl->HandleMessage(WM_VBXFIREEVENT, wp, lp))
      return 1;

  //
  // See if we have a handler for this event
  //
  if (Find(eventInfo) || Find(eventInfo, VbxEqualOperator))
    return Dispatch(eventInfo, wp, lp);
  return 0;
}
