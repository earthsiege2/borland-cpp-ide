//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of classes TView & TWindowView
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_DOCMANAG_H)
# include <owl/docmanag.h>
#endif
#if !defined(OWL_APPDICT_H)
# include <owl/appdict.h>
#endif
#if !defined(OWL_DOCVIEW_RH)
# include <owl/docview.rh>
#endif
#include <string.h>
#include <stdio.h>

DIAG_DECLARE_GROUP(OwlDocView);        // General Doc/View diagnostic group

#if !defined(SECTION) || SECTION == 1

const uint MinUniqueViewId = 0x8000;
uint TView::NextViewId = MinUniqueViewId;

//
//
//
TView::TView(TDocument& doc)
:
  Tag(0), ViewMenu(0)
{
  ViewId = NextViewId;
  doc.AttachView(*this);
}

//
//
//
TView::~TView()
{
  delete ViewMenu;

  CHECK(Doc);
  if (Doc->DetachView(*this)) {
    delete Doc;
  }
}

//
//
//
void
TView::SetViewMenu(TMenuDescr* menu)
{
  delete ViewMenu;
  ViewMenu = menu;
  TDocTemplate* tpl = Doc->GetTemplate();
  if (tpl && ViewMenu && *ViewMenu->GetModule() == *tpl->GetModule())
    ViewMenu->SetModule(tpl->GetModule());// force same module alias as template
}

static char* TView_PropertyNames[] = {
  "View Class",      // ViewClass
  "View Name",       // ViewName
};

static int TView_PropertyFlags[] = {
  pfGetText|pfConstant,  // ViewClass
  pfGetText|pfConstant,  // ViewName
};

//
//
//
const char*
TView::PropertyName(int index)
{
  if (index <= PrevProperty) {
    TRACEX(OwlDocView, 0, "PropertyName(): index <= PrevProperty!");
    return 0;
  }
  else if (index < NextProperty)
    return TView_PropertyNames[index-PrevProperty-1];
  else {
    TRACEX(OwlDocView, 0, "PropertyName(): index >= NextProperty!");
    return 0;
  }
}

//
//
//
int
TView::PropertyFlags(int index)
{
  if (index <= PrevProperty) {
    TRACEX(OwlDocView, 0, "PropertyFlags(): index <= PrevProperty!");
    return 0;
  }
  else if (index < NextProperty)
    return TView_PropertyFlags[index-PrevProperty-1];
  else {
    TRACEX(OwlDocView, 0, "PropertyFlags(): index >= NextProperty!");
    return 0;
  }
}

//
//
//
int
TView::FindProperty(const char far* name)
{
  int i;
  for (i=0; i < NextProperty-PrevProperty-1; i++)
    if (strcmp(TView_PropertyNames[i], name) == 0)
      return i+PrevProperty+1;

  TRACEX(OwlDocView, 0, "FindProperty(): " \
        "index of [" << string(name) << "] not found" );
  return 0;
}

//
//
//
int
TView::GetProperty(int prop, void far* dest, int textlen)
{
  const char far* src;
  switch (prop) {

    case ViewClass:
      src = _TYPENAME(this);
      break;

    case ViewName:
      src = GetViewName();
      break;

    default:
      TRACEX(OwlDocView, 0, "GetProperty(): " \
            "invalid property [" << prop << "] specified!" );
      return 0;
  }

  if (!textlen) {
    TRACEX(OwlDocView, 0, "GetProperty(): 0-Length buffer specified!");
    return 0;
  }

  int srclen = src ? strlen(src) : 0;
  if (textlen > srclen)
    textlen = srclen;
  if (textlen)
    memcpy(dest, src, textlen);
  *((char far*)dest + textlen) = 0;
  return srclen;
}

//
// Increment an internal count used by the Doc/View subsystem to identify
// each view.
//
void
TView::BumpNextViewId()
{
  if (++NextViewId < MinUniqueViewId)
    NextViewId = MinUniqueViewId;
}

//----------------------------------------------------------------------------
// TWindowView Implementation
//

DEFINE_RESPONSE_TABLE1(TWindowView, TWindow)
  EV_VN_ISWINDOW,
END_RESPONSE_TABLE;

//
//
//
TWindowView::TWindowView(TDocument& doc, TWindow* parent)
:
  TView(doc),
  TWindow(parent, 0, doc.GetDocManager().GetApplication())
{
}

//
// Does a given HWND belong to this view? Yes if it is us, or a child of us
//
bool
TWindowView::VnIsWindow(HWND hWnd)
{
  return hWnd == GetHandle() || IsChild(hWnd);
}

#endif
//----------------------------------------------------------------------------
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_ABSTRACT_STREAMABLE(TView);
IMPLEMENT_STREAMABLE2(TWindowView, TWindow, TView);

#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
TView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TView* o = GetObject();
  bool hasViewMenu = is.readByte();
  if (hasViewMenu) {
    o->ViewMenu = new TMenuDescr;
    is >> *o->ViewMenu;
  }
  else
    o->ViewMenu = 0;
  is >> o->ViewId;
  is >> o->Doc;
  is >> o->NextView;
  return o;
}

//
//
//
void
TView::Streamer::Write(opstream& os) const
{
  TView* o = GetObject();
  os.writeByte(int16(o->ViewMenu ? 1 : 0));
  if (o->ViewMenu)
    os << *o->ViewMenu;
  os << o->ViewId;
  os << o->Doc;
  os << o->NextView;
}

//
//
//
void*
TWindowView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TWindow*)GetObject(), is);
  ReadBaseObject((TView*)GetObject(), is);
  return GetObject();
}

//
//
//
void
TWindowView::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TWindow*)GetObject(), os);
  WriteBaseObject((TView*)GetObject(), os);
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
