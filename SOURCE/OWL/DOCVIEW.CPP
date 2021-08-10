//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\docview.cpp
//   Implements classes TDocument, TView, TWindowView
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\docmanag.h>
#include <owl\docview.rc>
#include <string.h>

DIAG_DECLARE_GROUP(OwlDocView);        // General Doc/View diagnostic group

#if !defined(SECTION) || SECTION == 1

const UINT MinUniqueViewId = 0x8000;
UINT TView::NextViewId = MinUniqueViewId;

//
//  class TDocument
//  ----- ---------
//

TDocument*
TDocument::List::Next(const TDocument* doc)
{
  return doc ? doc->NextDoc : DocList;
}

BOOL
TDocument::List::Insert(TDocument* doc)
{
  TDocument* pdoc;
  for (pdoc = DocList; pdoc; pdoc = pdoc->NextDoc)
    if (pdoc == doc)
      return FALSE;
  doc->NextDoc = DocList;
  DocList = doc;
  return TRUE;
}

BOOL
TDocument::List::Remove(TDocument* doc)
{
  TDocument** ppdoc;
  for (ppdoc = &DocList; *ppdoc; ppdoc = &(*ppdoc)->NextDoc){
    if (*ppdoc == doc) {
      *ppdoc = doc->NextDoc;
      return TRUE;
    }
  }
  return FALSE;
}

void
TDocument::List::Destroy()
{
  while(DocList)
    delete DocList;   // removes it entry from destructor
}

TDocument::TDocument(TDocument* parent)
                  : ParentDoc(parent), NextDoc(0), OpenMode(0),
                    Title(0), Template(0), ViewList(0), Tag(0), StreamList(0),
                    DocPath(0), DirtyFlag(FALSE)
{
  if (parent) {
    DocManager = parent->DocManager;
    parent->ChildDoc.Insert(this);
  } else {
    TApplication* app = GetApplicationObject();
    if ((DocManager = app->DocManager) == 0)
      THROW( TXOwl(IDS_NODOCMANAGER) );  // no doc manager to catch this one
    DocManager->DocList.Insert(this);
  }
}

TDocument::~TDocument()
{
  ChildDoc.Destroy();    // destroy children first, otherwise unnecessary
  Close();               // force close (not virtual at this point!)

  //  delete all attached views, data has already been flushed
  //
  SetTemplate(0);   // unref tpl, prevent self autodelete when deleting views
  TView* pview;
  for (pview = ViewList; pview != 0; pview = pview->NextView) {
    DocManager->PostEvent(dnClose, *pview);
    delete pview;
  }

  //  delete all streams, should only be present if abort or coding error
  //
  while(StreamList)
    delete StreamList;

  // detach from parent and doc manager
  //
  if (ParentDoc) {
    ParentDoc->ChildDoc.Remove(this);
  } else {
    DocManager->PostEvent(dnClose, *this);
    DocManager->DocList.Remove(this);
  }

  delete Title;
  delete DocPath;
}

static char* PropNames[] = {
  "Document Class",  // DocumentClass
  "Template Name",   // TemplateName
  "View Count",      // ViewCount
  "Storage Path",    // StoragePath
  "Document Title",  // DocTitle
};

static int PropFlags[] = {
  pfGetText|pfConstant,  // DocumentClass
  pfGetText,             // TemplateName
  pfGetBinary|pfGetText, // ViewCount
  pfGetText|pfSettable,  // StoragePath
  pfGetText|pfSettable,  // DocTitle
};

const char*
TDocument::PropertyName(int index)
{
  if (index <= PrevProperty)
    return 0;
  else if (index < NextProperty)
    return PropNames[index-PrevProperty-1];
  else
    return 0;
}

int
TDocument::PropertyFlags(int index)
{
  if (index <= PrevProperty)
    return 0;
  else if (index < NextProperty)
    return PropFlags[index-PrevProperty-1];
  else
    return 0;
}

int
TDocument::FindProperty(const char far* name)
{
  int i;
  for (i=0; i < NextProperty-PrevProperty-1; i++)
    if (strcmp(PropNames[i], name) == 0)
      return i+PrevProperty+1;
  return 0;
}

int
TDocument::GetProperty(int prop, void far* dest, int textlen)
{
  const char far* src;
  switch(prop)
  {
    case DocumentClass:
      src = _TYPENAME(this);
      break;
    case TemplateName:
      src = Template ? Template->Description : 0;
      break;
    case ViewCount:
    {
      char buf[4];
      int cnt;
      TView* pview;
      for (pview=ViewList, cnt=0; pview != 0; pview=pview->NextView, cnt++) ;
      if (!textlen) {
        *(int far*)dest = cnt;
        return sizeof(int);
      }
      wsprintf(buf, "%d", cnt);
      src = buf;
      break;
    }
    case StoragePath:
      src = DocPath;
      break;
    case DocTitle:
      src = Title;
      break;
    default:
      return 0;
  }
  if (!textlen)
    return 0;
  int srclen = src ? strlen(src) : 0;
  if (textlen > srclen)
    textlen = srclen;
  if (textlen)
    memcpy(dest, src, textlen);
  *((char far*)dest + textlen) = 0;
  return srclen;
}

BOOL
TDocument::SetProperty(int prop, const void far* src)
{
  switch(prop)
  {
    case DocTitle:
      SetTitle((const char far*)src);
      break;
    case StoragePath:
      return SetDocPath((const char far*)src);
    default:
      return FALSE;
  }
  return TRUE;
}

TDocument&
TDocument::RootDocument()
{
  TDocument* pdoc = this;
  while(pdoc->ParentDoc)
    pdoc = pdoc->ParentDoc;
  return *pdoc; 
}

void
TDocument::SetDocManager(TDocManager& dm)
{
  if (!ParentDoc) {
    if (DocManager)  // test needed for TDocManager::Streamer::Read()
      DocManager->DocList.Remove(this);
    dm.DocList.Insert(this);
  }
  DocManager = &dm;
}

BOOL
TDocument::SetDocPath(LPCSTR path)
{
  char title[256];
  delete DocPath;
  DocPath = path ? strnewdup(path) : 0;
  if (path == 0 || ::GetFileTitle(path, title, sizeof(title)) != 0) {
    if (DocManager->Application->LoadString(IDS_UNTITLED, title, sizeof(title)) == 0)
      title[0] = 0;
  }
  SetTitle(title);
  return TRUE;  // derived classes may validate path
}

void
TDocument::SetTitle(LPCSTR title)
{
  delete Title;
  Title = title ? strnewdup(title) : 0;
  ReindexFrames();
}

BOOL
TDocument::SetTemplate(TDocTemplate* tpl)
{
  if (Template)
    DocManager->UnRefTemplate(*Template);
  if (tpl)
    DocManager->RefTemplate(*tpl);
  Template = tpl;
  return TRUE;
}

void
TDocument::ReindexFrames()
{
  TView* pview;
  int seq;

  for (seq = -1, pview = ViewList; pview != 0; pview = pview->NextView) {
         seq -= pview->SetDocTitle(Title, seq);  // decrement if title displayed
         if (seq == -3)   // need only check if more than one title displayed
      break;
  }
  if (seq == -1)
    return;
  seq = (seq == -2 ? 0 : 1);
  for (pview = ViewList; pview != 0; pview = pview->NextView) {
    seq += pview->SetDocTitle(Title, seq);  // increment if title displayed
  }
}

void
TDocument::AttachStream(TStream& strm)
{
  strm.NextStream = StreamList;
  StreamList = &strm;
}

void
TDocument::DetachStream(TStream& strm)
{
  TStream** plist = &StreamList;
  for ( ; *plist; plist = &(*plist)->NextStream) {
    if (*plist == &strm){
      *plist = strm.NextStream;
      return;
    }
  }
}

TStream*
TDocument::NextStream(const TStream* strm)
{
  return strm ? strm->NextStream : StreamList;
}

TView*
TDocument::NextView(const TView* view)
{
  return view ? view->NextView : ViewList;
}

void
TDocument::AttachView(TView& view)
{
  TView** ppview;

  for (ppview = &ViewList; *ppview; ppview = &(*ppview)->NextView)
  ;
  *ppview = &view;    // insert at end of list
  view.NextView = 0;
  view.Doc = this;
  NotifyViews(vnViewOpened, (long)&view, &view);
}

TView*
TDocument::InitView(TView* view)
{
  if (!view)           // test if new TView failed
      return 0;
  if (!view->IsOK()){  // test if constructor failed
      delete view;
      return 0;
  }
  DocManager->PostEvent(dnCreate, *view);
  if (!view->IsOK()){      // if failed in creation
      delete view;
      return 0;
  }
  ReindexFrames();
  if (++TView::NextViewId < MinUniqueViewId)
    TView::NextViewId = MinUniqueViewId;
  return view;
}

BOOL
TDocument::DetachView(TView& view)
{
  TView** plist = &ViewList;
  for ( ; *plist; plist = &(*plist)->NextView) {
    if (*plist == &view){
      *plist = view.NextView;
      NotifyViews(vnViewClosed, (long)&view, &view);
      if (!ViewList){     // all views for this doc are now gone
         if (Template && (Template->Flags & dtAutoDelete)) {
           if (IsOpen())
             Close();	  // close the document streams
           return view.IsOK();   // delete doc UNLESS failure in creation
         }
      } else {
        ReindexFrames();
      }
      break;
    }
  }
  return FALSE;
}

BOOL
TDocument::Commit(BOOL force)
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0) {
    if (!pdoc->Commit(force))
      return FALSE;
  }
  // should we test here for DocPath==0 , or should caller have checked?
  return NotifyViews(vnCommit, force);
}

BOOL
TDocument::Revert(BOOL clear)
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0) {
    if (!pdoc->Revert(clear))
      return FALSE;
  }
  return NotifyViews(vnRevert, clear);
}

BOOL
TDocument::NotifyViews(int event, long item, TView* exclude)
{
  BOOL answer = TRUE;
  TEventHandler::TEventInfo eventInfo(WM_OWLNOTIFY, event);

  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)  
    answer &= pdoc->NotifyViews(event, item, exclude);

  TView* pview;
  for (pview = ViewList; pview != 0; pview = pview->NextView)
    if (pview != exclude && pview->Find(eventInfo))
      answer &= (int)pview->Dispatch(eventInfo, 0, item);
  return answer;
}

TView*
TDocument::QueryViews(int event, long item, TView* exclude)
{
  TView* pview;
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if ((pview = pdoc->QueryViews(event, item, exclude)) != 0)
      return pview;

  TEventHandler::TEventInfo eventInfo(WM_OWLNOTIFY, event);
  for (pview = ViewList; pview != 0; pview = pview->NextView)
    if (pview != exclude && pview->Find(eventInfo)
                         && pview->Dispatch(eventInfo, 0, item))
      return pview;    // return first acknowledger

  return 0;            // if no takers
}

BOOL
TDocument::IsDirty()
{
  if (DirtyFlag)
    return TRUE;

  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if (pdoc->IsDirty())
      return TRUE;

  return (QueryViews(vnIsDirty) != 0);
}

BOOL
TDocument::HasFocus(HWND hwnd)
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if (pdoc->HasFocus(hwnd))
      return TRUE;

  return (QueryViews(vnIsWindow, (long)hwnd) != 0);
}

BOOL
TDocument::CanClose()
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if (!pdoc->CanClose())
      return FALSE;

  return DocManager->FlushDoc(*this);  // do the UI in the doc manager
}

BOOL
TDocument::Close()
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if (!pdoc->Close())
      return FALSE;

  return TRUE;
}

UINT
TDocument::PostError(UINT sid, UINT choice)
{
  return DocManager->PostDocError(*this, sid, choice);
}


//
//  class TView
//  ----- -----
//

TView::TView(TDocument& doc) : Tag(0), ViewMenu(0)
{
  ViewId = NextViewId;
  doc.AttachView(*this);
}

TView::~TView()
{
  delete ViewMenu;
  if (Doc->DetachView(*this)) {
    delete Doc;
  }
}

void
TView::SetViewMenu(TMenuDescr* menu)
{
  ViewMenu = menu;
  TDocTemplate* tpl = Doc->GetTemplate();
  if (tpl && *ViewMenu->Module == *tpl->GetModule())
    ViewMenu->Module = tpl->GetModule();// force same module alias as template
}

static char* TView_PropertyNames[] = {
  "View Class",      // ViewClass
  "View Name",       // ViewName
};

static int TView_PropertyFlags[] = {
  pfGetText|pfConstant,  // ViewClass
  pfGetText|pfConstant,  // ViewName
};

const char*
TView::PropertyName(int index)
{
  if (index <= PrevProperty)
    return 0;
  else if (index < NextProperty)
    return TView_PropertyNames[index-PrevProperty-1];
  else
    return 0;
}

int
TView::PropertyFlags(int index)
{
  if (index <= PrevProperty)
    return 0;
  else if (index < NextProperty)
    return TView_PropertyFlags[index-PrevProperty-1];
  else
    return 0;
}

int
TView::FindProperty(const char far* name)
{
  int i;
  for (i=0; i < NextProperty-PrevProperty-1; i++)
    if (strcmp(TView_PropertyNames[i], name) == 0)
      return i+PrevProperty+1;
  return 0;
}

int
TView::GetProperty(int prop, void far* dest, int textlen)
{
  const char far* src;
  switch(prop)
  {
    case ViewClass:
      src = _TYPENAME(this);
      break;
    case ViewName:
      src = GetViewName();
      break;
    default:
      return 0;
  }
  if (!textlen)
    return 0;
  int srclen = src ? strlen(src) : 0;
  if (textlen > srclen)
    textlen = srclen;
  if (textlen)
    memcpy(dest, src, textlen);
  *((char far*)dest + textlen) = 0;
  return srclen;
}


//
//  class TWindowView
//  ----- -----------
//

DEFINE_RESPONSE_TABLE1(TWindowView, TWindow)
  EV_VN_ISWINDOW,
END_RESPONSE_TABLE;


//
//  class TDateTime (eventually)
//  ----- ---------
//
int FormatFileTime(FILETIME* pft, void far* dest, int textlen)
{
  char buf[40];
  int len;

  if (!textlen) {
    *(FILETIME FAR*)dest = *pft;
    return sizeof(FILETIME);
  }
#if defined(__WIN32__)
  SYSTEMTIME dt;
  FileTimeToSystemTime(pft, &dt);
  len = wsprintf(buf,"%d/%d/%d %02d:%02d:%02d.%02d",
                 dt.wMonth, dt.wDay, dt.wYear,
                 dt.wHour, dt.wMinute, dt.wSecond, dt.wMilliseconds/10);
#else
  struct time filet;
  struct date filed;
  if (!(FileTimeToDateTime(pft, &filed, &filet)))
    return FALSE;
  len = wsprintf(buf,"%d/%d/%d %02d:%02d:%02d.%02d",
                 filed.da_mon,filed.da_day,filed.da_year,
                 filet.ti_hour,filet.ti_min,filet.ti_sec,filet.ti_hund);
#endif
  if (textlen > len)
    textlen = len;
  memcpy(dest, buf, textlen);
  *((char far*)dest + textlen) = 0;
  return len;
}

#if !defined(__WIN32__)
//
// Win32/OLE2 compatible FILETIME support for 16-bit applications
//    these functions to be incorporated into TDateTime class
//

int FormatDateTime(struct date filed, struct time filet, void far* dest, int textlen)
{
  char buf[40];
  if (!textlen) {
    DateTimeToFileTime(&filed, &filet, (FILETIME FAR*)dest);
    return sizeof(FILETIME);
  }
  int len = wsprintf(buf,"%d/%d/%d %02d:%02d:%02d.%02d",
                    filed.da_mon,filed.da_day,filed.da_year,
                    filet.ti_hour,filet.ti_min,filet.ti_sec,filet.ti_hund);
  if (textlen > len)
    textlen = len;
  memcpy(dest, buf, textlen);
  *((char far*)dest + textlen) = 0;
  return len;
}

// Convert date and time structures to 64-bit FILETIME structure
//  multiply seconds by 10^7 and adjust offset to Jan. 1, 1601
//  adjustment from Jan.1, 1970 = 116,444,736,000,000,000 = 0x019DB1DED53E8000
//  This code is for Win32 and OLE2 compatibility when using Win16

#include <dos.h>

void DateTimeToFileTime(struct date* dosd, struct time* dost, FILETIME FAR* pft)
{
  union {
    long udt;
    int  w[2];
  } u;
  u.udt = dostounix(dosd, dost);
  _BL = dost->ti_hund;
  _AX = u.w[0];
  _CX = u.w[1];
  asm mov  di,200
  asm mul  di
  asm mov  bh,0
  asm add  bx,bx
  asm add  ax,bx
  asm adc  dl,dh
  asm xchg ax,cx
  asm mov  bx,dx
  asm mul  di
  asm add  bx,ax
  asm mov  si,0
  asm adc  si,dx
  asm les  di,pft
  asm mov  ax,50000
  asm xchg ax,cx
  asm mul  cx
  asm add  ax,0x8000
  asm adc  dx,0
  asm mov  es:[di],ax
  asm xchg ax,dx
  asm xchg ax,bx
  asm mul  cx
  asm add  ax,bx
  asm adc  dx,0
  asm add  ax,0xD53E
  asm adc  dx,0
  asm mov  es:[di+2],ax
  asm xchg ax,dx
  asm xchg ax,si
  asm mul  cx
  asm add  ax,si
  asm adc  dx,0
  asm add  ax,0xB1DE
  asm adc  dx,0x019D
  asm mov  es:[di+4],ax
  asm mov  es:[di+6],dx
}


// Convert FILETIME structure to date and time structures

BOOL FileTimeToDateTime(FILETIME FAR* pft, struct date* dosd, struct time* dost)
{
  union {
    long udt;
    int  w[2];
  } u;
  asm les  di,pft
  asm mov  dx,es:[di+6]
  asm mov  ax,es:[di+4]
  asm sub  ax,0xB1DE
  asm sbb  dx,0x019D
  asm jnc OK
  return FALSE;
OK:
  asm mov  cx,50000
  asm div  cx
  asm xchg bx,ax
  asm mov  ax,es:[di+2]
  asm sub  ax,0xD53E
  asm sbb  dx,0
  asm div  cx
  asm xchg si,ax
  asm mov  ax,es:[di]
  asm sub  ax,(0x8000-5000)
  asm sbb  dx,0
  asm div  cx
  asm mov  dx,bx
  asm xchg ax,si
  asm mov  cx,200
  asm div  cx
  asm xchg ax,si
  asm div  cx
  asm shr  dx,1
  asm push dx
  u.w[0] = _AX;
  u.w[1] = _SI;
  unixtodos(u.udt, dosd, dost);
  asm pop  ax
  dost->ti_hund = _AL;
  return TRUE;
}
#endif //!defined(__WIN32__)

//
// dispatchers for view notifications
//

LRESULT _OWLFUNC
B_long_Dispatch(GENERIC& generic, int (GENERIC::*pmf)(long), WPARAM, LPARAM a)
{
  return (generic.*pmf)(a);
}

LRESULT _OWLFUNC
B_int_Dispatch(GENERIC& generic, int (GENERIC::*pmf)(int), WPARAM, LPARAM a)
{
  return (generic.*pmf)((int)a);
}

LRESULT _OWLFUNC
B_void_Dispatch(GENERIC& generic, int (GENERIC::*pmf)(), WPARAM, LPARAM)
{
  return (generic.*pmf)();
}

LRESULT _OWLFUNC
B_pointer_Dispatch(GENERIC& generic, int(GENERIC::*pmf)(void*),WPARAM,LPARAM a)
{
  return (generic.*pmf)((void*)a);
}

#endif
#if !defined(SECTION) || SECTION == 2


IMPLEMENT_ABSTRACT_STREAMABLE(TView);

void*
TView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TView* o = GetObject();
  BOOL hasViewMenu = is.readByte();
  if (hasViewMenu) {
    o->ViewMenu = new TMenuDescr;
    is >> *o->ViewMenu;
  } else
    o->ViewMenu = 0;
  is >> o->ViewId;
  is >> o->Doc;
  is >> o->NextView;
  return o;
}

void
TView::Streamer::Write(opstream& os) const
{
  TView* o = GetObject();
  os.writeByte(o->ViewMenu ? (char)1 : (char)0);
  if (o->ViewMenu)
    os << *o->ViewMenu;
  os << o->ViewId;
  os << o->Doc;
  os << o->NextView;
}


IMPLEMENT_ABSTRACT_STREAMABLE(TDocument);

void*
TDocument::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TDocument* o = GetObject();

  o->NextDoc = 0;
  o->StreamList = 0;
  o->DocManager = 0;
  o->DirtyFlag = FALSE;

  is >> o->OpenMode;
  o->DocPath = is.freadString();
  o->Title   = is.freadString();
  is >> o->Template;  // static templates must have been already streamed
  is >> o->ParentDoc;
  o->ViewList = 0;    // must init, does not get set until after view streamed
  is >> o->ViewList;
  is >> TView::NextViewId;  // static, but must get set by at least 1 document

  return o;
}

void
TDocument::Streamer::Write(opstream& os) const
{
  TDocument* o = GetObject();

  while (!o->CanClose())   // can't permit cancel here
    ;
  os << o->OpenMode;
  os.fwriteString(o->DocPath);
  os.fwriteString(o->Title);
  os << o->Template;       // templates already streamed, must be so if static
  os << o->ParentDoc;
  os << o->ViewList;       // each view streams out the next
  os << TView::NextViewId; // insure that this static var gets set on reload
}

IMPLEMENT_STREAMABLE2(TWindowView, TWindow, TView);
void*
TWindowView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TWindow*)GetObject(), is);
  ReadBaseObject((TView*)GetObject(), is);
  return GetObject();
}

void
TWindowView::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TWindow*)GetObject(), os);
  WriteBaseObject((TView*)GetObject(), os);
}

#endif
