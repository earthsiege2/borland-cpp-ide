//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.17  $
//
// Implementation of class TDocument
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

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlDocView);        // General Doc/View diagnostic group

//    of index between multiple applications.
// int TDocument::UntitledIndex = 0;

#if !defined(SECTION) || SECTION == 1

//
//
//
TDocument::TDocument(TDocument* parent)
:
  ParentDoc(parent),
  NextDoc(0), OpenMode(0),
  Title(0), Template(0),
  ViewList(0), Tag(0), StreamList(0),
  DocPath(0),
  DirtyFlag(false), Embedded(false)
{
  if (parent) {
    DocManager = parent->DocManager;

    // Handle case of 'dummy' parent [parent parented to itself] which was
    // created by the docmanager simply to pass itself to us
    //
    if (parent->ParentDoc == parent) {
      ParentDoc = 0;
      CHECK(DocManager);
      DocManager->DocList.Insert(this);
    }
    else
      parent->ChildDoc.Insert(this);
  }
  else {
    TApplication* app = GetApplicationObject();
    CHECK(app);
    DocManager = app->DocManager;
    if (!DocManager)
      TXOwl::Raise(IDS_NODOCMANAGER);  // No doc manager to catch this one
    DocManager->DocList.Insert(this);
  }
}

//
//
//
TDocument::~TDocument()
{
  // Is this a dummy document?
  //
  if (ParentDoc == this)
    return;

  // Unref template - prevents self autodelete when deleting views, including
  // views in child documents
  //
  SetTemplate(0);

  // Destroy children first if we have any. Then force close here as a last
  // resort if derived classes have not done so. Since we have destructed down
  // to a TDocument by now, derived closes will not be called.
  //
  ChildDoc.Destroy();
  Close();

  // NOTE: View's destructor invokes 'DetachView' which removes it from
  //       the list
  //
  while (ViewList)
    delete ViewList;

  // Delete all streams, should only be present if abort or coding error
  //
  while (StreamList) {
    TRACEX(OwlDocView, 0, "~TDocument(): StreamList not 0!");
    delete StreamList;
  }

  // Detach from parent and doc manager
  //
  if (ParentDoc) {
    ParentDoc->ChildDoc.Remove(this);
  }
  else {
    CHECK(DocManager);
    DocManager->PostEvent(dnClose, *this);
    DocManager->DocList.Remove(this);
  }

  delete[] Title;
  delete[] DocPath;
}

//
//
//
static char* PropNames[] = {
  "Document Class",  // DocumentClass
  "Template Name",   // TemplateName
  "View Count",      // ViewCount
  "Storage Path",    // StoragePath
  "Document Title",  // DocTitle
};

//
//
//
static int PropFlags[] = {
  pfGetText|pfConstant,  // DocumentClass
  pfGetText,             // TemplateName
  pfGetBinary|pfGetText, // ViewCount
  pfGetText|pfSettable,  // StoragePath
  pfGetText|pfSettable,  // DocTitle
};

//
//
//
const char*
TDocument::PropertyName(int index)
{
  if (index <= PrevProperty) {
    TRACEX(OwlDocView, 0, "PropertyName(): index <= PrevProperty!");
    return 0;
  }
  else if (index < NextProperty)
    return PropNames[index-PrevProperty-1];
  else {
    TRACEX(OwlDocView, 0, "PropertyName(): index >= PrevProperty!");
    return 0;
  }
}

//
//
//
int
TDocument::PropertyFlags(int index)
{
  if (index <= PrevProperty) {
    TRACEX(OwlDocView, 0, "PropertyFlags(): index <= PrevProperty!");
    return 0;
  }
  else if (index < NextProperty)
    return PropFlags[index-PrevProperty-1];
  else {
    TRACEX(OwlDocView, 0, "PropertyFlags(): index >= PrevProperty!");
    return 0;
  }
}

//
//
//
int
TDocument::FindProperty(const char far* name)
{
  int i;
  for (i=0; i < NextProperty-PrevProperty-1; i++)
    if (strcmp(PropNames[i], name) == 0)
      return i+PrevProperty+1;

  TRACEX(OwlDocView, 0, "FindProperty(): " \
        "index of [" << string(name) << "] not found" );
  return 0;
}

//
//
//
int
TDocument::GetProperty(int prop, void far* dest, int textlen)
{
  const char far* src;
  char numBuf[15];
  switch (prop) {
    case DocumentClass:
      src = _TYPENAME(this);
      break;

    case TemplateName:
      src = Template ? Template->GetDescription() : 0;
      break;

    case ViewCount: {
      int cnt;
      TView* view;
      for (view=ViewList, cnt=0; view != 0; view=view->NextView, cnt++)
        ; // Do nothing
      if (!textlen) {
        *(int far*)dest = cnt;
        return sizeof(int);
      }
      sprintf(numBuf, "%d", cnt);
      src = numBuf;
      break;
    }

    case StoragePath:
      src = DocPath;
      break;

    case DocTitle:
      src = Title;
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
//
//
bool
TDocument::SetProperty(int prop, const void far* src)
{
  switch (prop) {
    case DocTitle:
      SetTitle((const char far*)src);
      break;

    case StoragePath:
      return SetDocPath((const char far*)src);

    default:
      TRACEX(OwlDocView, 0, "SetProperty(): invalid prop [" << prop <<\
            "] specified!");
      return false;
  }
  return true;
}

//
//
//
TDocument&
TDocument::RootDocument()
{
  TDocument* pdoc = this;
  while (pdoc->ParentDoc)
    pdoc = pdoc->ParentDoc;
  return *pdoc;
}

//
//
//
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

//
//
//
bool
TDocument::SetDocPath(const char far* path)
{
  // Path has been set already
  //
  if (path && (path == DocPath)) {
    TRACEX(OwlDocView, 0, "SetDocPath(): path [" << string(path) << "] "\
                          "already set!");
    return true;
  }

  delete[] DocPath;
  DocPath = (path && *path) ? strnewdup(path) : 0;

  char title[_MAX_PATH] = "Unknown";  // Never used - but just in case!
  if (!DocPath || ::GetFileTitle(DocPath, title, sizeof title) != 0) {
    CHECK(DocManager);
    CHECK(DocManager->GetApplication());

    int len = DocManager->GetApplication()->LoadString(IDS_UNTITLED,
                                                       title, sizeof title);
    if (DocManager->IsFlagSet(dmMDI))
      sprintf(title+len, "%d", ++(DocManager->GetUntitledIndex()));
  }
  SetTitle(title);
  return true;  // derived classes may validate path
}

//
//
//
void
TDocument::SetTitle(const char far* title)
{
  delete[] Title;
  Title = title ? strnewdup(title) : 0;
  ReindexFrames();
}

//
//
//
bool
TDocument::SetTemplate(TDocTemplate* tpl)
{
  if (Template) {
    CHECK(DocManager);
    DocManager->UnRefTemplate(*Template);
  }
  if (tpl) {
    CHECK(DocManager);
    DocManager->RefTemplate(*tpl);
  }
  Template = tpl;
  return true;
}

//
//
//
void
TDocument::ReindexFrames()
{
  TView* view;
  int seq;

  for (seq = -1, view = ViewList; view != 0; view = view->NextView) {
    seq -= view->SetDocTitle(Title, seq);  // decrement if title displayed
    if (seq == -3)   // need only check if more than one title displayed
      break;
  }
  if (seq == -1)
    return;
  seq = (seq == -2 ? 0 : 1);
  for (view = ViewList; view != 0; view = view->NextView) {
    seq += view->SetDocTitle(Title, seq);  // increment if title displayed
  }
}

//
//
//
void
TDocument::AttachStream(TStream& strm)
{
  strm.NextStream = StreamList;
  StreamList = &strm;
}

//
//
//
void
TDocument::DetachStream(TStream& strm)
{
  TStream** plist = &StreamList;
  for ( ; *plist; plist = &(*plist)->NextStream) {
    if (*plist == &strm) {
      *plist = strm.NextStream;
      return;
    }
  }
}

//
//
//
TStream*
TDocument::NextStream(const TStream* strm)
{
  return strm ? strm->NextStream : StreamList;
}

//
//
//
TView*
TDocument::NextView(const TView* view)
{
  return view ? view->NextView : ViewList;
}

//
//
//
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

//
//
//
TView*
TDocument::InitView(TView* view)
{
  if (!view) {
    TRACEX(OwlDocView, 0, "InitView(): 0 view specified!");
    return 0;
  }
  if (!view->IsOK()) {
    TRACEX(OwlDocView, 0, "InitView(): Invalid view object specified!");
    delete view;
    return 0;
  }

  CHECK(DocManager);
  DocManager->PostEvent(dnCreate, *view);

  if (!view->IsOK()) {
    TRACEX(OwlDocView, 0, "InitView(): Invalid view object post dnCreate!");
    delete view;
    return 0;
  }

  ReindexFrames();
  TView::BumpNextViewId();

  return view;
}

//
// DetachView is invoked from TView's destructor so that the view can detach
// itself from this document. True is returned if the detachment is successful
// indicating that this document should be deleted.
//
bool
TDocument::DetachView(TView& view)
{
  TView** plist = &ViewList;
  for (; *plist; plist = &(*plist)->NextView) {
    if (*plist == &view) {

      // Found the view, now detach it and notify app and other views
      //
      DocManager->PostEvent(dnClose, view);
      *plist = view.NextView;
      NotifyViews(vnViewClosed, (long)&view, &view);

      // Cleanup doc if last view was just closed and dtAutoDelete
      // or dtAutoOpen is set. dtAutoOpen will cause an autoclose, while
      // dtAutoDelete will delete this doc also.
      //
      if (!ViewList) {
        if (Template && ((Template->Flags & dtAutoDelete) ||
                         (Template->Flags & dtAutoOpen))) {
          // Close document streams
          //
          if (IsOpen())
            Close();

          // Returning true will cause ~TView to delete document. Using
          // 'view.IsOK()' caters for cases where TView's construction failed.
          //
          return (Template->Flags & dtAutoDelete) && view.IsOK();
        }
      }
      else {
        ReindexFrames();
      }
      break;
    }
  }
  return false;
}

//
//
//
bool
TDocument::Commit(bool force)
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0) {
    if (!pdoc->Commit(force))
      return false;
  }

  WARNX(OwlDocView, !DocPath, 0, "Commit(): 0 DocPath!");
  return NotifyViews(vnCommit, force);
}

//
//
//
bool
TDocument::Revert(bool clear)
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0) {
    if (!pdoc->Revert(clear))
      return false;
  }
  return NotifyViews(vnRevert, clear);
}

//
//
//
bool
TDocument::NotifyViews(int event, long item, TView* exclude)
{
  bool answer = true;

  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    answer = (answer && pdoc->NotifyViews(event, item, exclude)) != 0;

  TEventHandler::TEventInfo eventInfo(WM_OWLNOTIFY, event);
  for (TView* view = ViewList; view != 0; view = view->NextView)
    if (view != exclude && view->Find(eventInfo))
      answer = (answer && view->Dispatch(eventInfo, 0, item)) != 0;

  return answer;
}

//
//
//
TView*
TDocument::QueryViews(int event, long item, TView* exclude)
{
  TView* view;
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if ((view = pdoc->QueryViews(event, item, exclude)) != 0)
      return view;

  TEventHandler::TEventInfo eventInfo(WM_OWLNOTIFY, event);
  for (view = ViewList; view != 0; view = view->NextView) {
    if (view != exclude) {
      if (view->Find(eventInfo)) {
        if (view->Dispatch(eventInfo, 0, item)) {
          return view;            // Return first acknowledger
        }
      }
    }
  }
  return 0;           
}

//
//
//
bool
TDocument::IsDirty()
{
  if (DirtyFlag)
    return true;

  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if (pdoc->IsDirty())
      return true;

  return QueryViews(vnIsDirty) != 0;
}

//
//
//
bool
TDocument::HasFocus(HWND hWnd)
{
  return DocWithFocus(hWnd) != 0;
}

//
// Return pointer to this document or one of its child documents if the 
// spcecified window parameter is a view associated with the document.
// NOTE: Unlike 'HasFocus', this method allows you to distinguish whether
//       the document with focus is a child document.
//
TDocument*
TDocument::DocWithFocus(HWND hWnd)
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if (pdoc->DocWithFocus(hWnd))
      return pdoc;

  return QueryViews(vnIsWindow, (long)hWnd) ? this : 0;
}

//
//
//
bool
TDocument::CanClose()
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if (!pdoc->CanClose())
      return false;

  return DocManager->FlushDoc(*this);  // do the UI in the doc manager
}

//
//
//
bool
TDocument::Close()
{
  TDocument* pdoc = 0;
  while ((pdoc = ChildDoc.Next(pdoc)) != 0)
    if (!pdoc->Close())
      return false;

  return true;
}

//
//
//
uint
TDocument::PostError(uint sid, uint choice)
{
  return DocManager->PostDocError(*this, sid, choice);
}

//----------------------------------------------------------------------------

//
//
//
TDocument*
TDocument::TList::Next(const TDocument* doc)
{
  return doc ? doc->NextDoc : DocList;
}

//
//
//
bool
TDocument::TList::Insert(TDocument* doc)
{
  TDocument* pdoc;
  for (pdoc = DocList; pdoc; pdoc = pdoc->NextDoc)
    if (pdoc == doc)
      return false;
  doc->NextDoc = DocList;
  DocList = doc;
  return true;
}

//
//
//
bool
TDocument::TList::Remove(TDocument* doc)
{
  TDocument** ppdoc;
  for (ppdoc = &DocList; *ppdoc; ppdoc = &(*ppdoc)->NextDoc) {
    if (*ppdoc == doc) {
      *ppdoc = doc->NextDoc;
      return true;
    }
  }
  return false;
}

//
//
//
void
TDocument::TList::Destroy()
{
  while (DocList)
    delete DocList;   // removes it entry from destructor
}

#endif
//----------------------------------------------------------------------------
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_ABSTRACT_STREAMABLE(TDocument);

#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
TDocument::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TDocument* o = GetObject();

  o->NextDoc = 0;
  o->StreamList = 0;
  o->DocManager = 0;
  o->DirtyFlag = false;

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

//
//
//
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

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
