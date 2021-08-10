//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\swindobj.cpp
//   Streamable object implementation for TWindow.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\window.h>
#include <owl\scroller.h>

extern WNDPROC CreateInstanceThunk(TWindow*);

IMPLEMENT_STREAMABLE(TWindow);

const int StreamIsTop      = 1;
const int StreamIsTopChild = 2;

void *
TWindow::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TWindow* o = GetObject();
  int flags;
  is >> flags;
  if (flags & StreamIsTop) {
    o->ChildList = 0;   // indicate no children connected yet
    return o;           // we only need to read our child list
  }

  o->HWindow = 0;
  o->Parent = 0;
  o->SiblingList = 0;
  o->ChildList = 0;
  o->TransferBuffer = 0;
  o->DefaultProc = 0;
  o->hAccel = 0;
  o->SetUniqueId();

  o->Application = GetApplicationObject();
  o->Thunk = CreateInstanceThunk(o);

  is >> o->Module;
  TResId TempId;
  is >> TempId;
  o->Title = TempId;
  is >> o->Flags;

  if (o->IsFlagSet(wfFromResource)) {
    o->DefaultProc = (WNDPROC)::DefWindowProc;
    memset(&o->Attr, 0, sizeof(o->Attr));

  } else {
    long  temp;
    is >> o->Attr.Style >> o->Attr.ExStyle >>
          o->Attr.X >> o->Attr.Y >> o->Attr.W >> o->Attr.H >> temp;
    o->Attr.Param = (char far*)temp;

    o->DefaultProc = (WNDPROC)::DefWindowProc;
  }

  is >> o->Attr.Id
     >> o->Attr.Menu
     >> o->Attr.AccelTable;

  is >> o->ZOrder;

  is >> o->Parent;
  if (flags & StreamIsTopChild)
    o->Parent->ChildList = o;  // set parent's child pointer to this
  is >> o->ChildList;
  is >> o->SiblingList;

  is >> o->Scroller;
  if (o->Scroller)
    o->Scroller->SetWindow(o);

  o->HCursor = 0;
  is >> o->CursorModule >> o->CursorResId;
  o->SetCursor(o->CursorModule, o->CursorResId);
  is >> o->BkgndColor;

  return o;
}

void
TWindow::Streamer::Write(opstream& os) const
{
  TWindow* o = GetObject();

  o->AssignZOrder();
  int flags = 0;
  if (o->IsFlagSet(wfStreamTop) || o->IsFlagSet(wfMainWindow))
    flags |= StreamIsTop;
  else if ((o->Parent->IsFlagSet(wfStreamTop) || o->Parent->IsFlagSet(wfMainWindow))
		 && o->Parent->ChildList == o)
    flags |= StreamIsTopChild;
  os << flags;

  if (flags & StreamIsTop) {
    return;
  }

  os << o->Module;
  os << TResId(o->Title);

  DWORD saveFlags = o->Flags;
  if (o->HWindow)
    saveFlags |= wfAutoCreate;
  os << saveFlags;

  if (!o->IsFlagSet(wfFromResource)) {
    DWORD saveStyle = o->Attr.Style &
                      ~(WS_MINIMIZE | WS_MAXIMIZE | WS_DISABLED | WS_VISIBLE);

    if (o->HWindow)
      saveStyle |= o->GetWindowLong(GWL_STYLE) &
                   (WS_MINIMIZE | WS_MAXIMIZE | WS_DISABLED | WS_VISIBLE);

    os << saveStyle << o->Attr.ExStyle <<
          o->Attr.X << o->Attr.Y << o->Attr.W << o->Attr.H <<
          long(o->Attr.Param);
  }

  os << o->Attr.Id
     << o->Attr.Menu
     << o->Attr.AccelTable;

  os << o->ZOrder;

  os << o->Parent;
  os << o->ChildList;
  os << o->SiblingList;

  os << o->Scroller;

  os << o->CursorModule << o->CursorResId;
  os << o->BkgndColor;
}
