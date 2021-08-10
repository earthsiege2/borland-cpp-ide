//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implements class TDocManager
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/docmanag.h>
#include <owl/appdict.h>
#include <owl/docview.rh>
#include <string.h>
#include <dlgs.h>  // cmb1 for file open dialog box
#include <dir.h>   // MAXEXT for file open dialog default extension

#if defined(SECTION) && SECTION != 1
DIAG_DECLARE_GROUP(OwlDocView);        // General Doc/View diagnostic group
#endif

#if !defined(SECTION) || SECTION == 1

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlDocView, 1, 0);

//
//  class TPickList
//  ----- ---------
//
class TPickList : public TWindow {
  public:
    TPickList(const char far* title, TWindow* parent);
    TPickList(uint sid, TWindow* parent);
   ~TPickList();
    int AddString(const char far* str);
    int Execute();   // returns pick index (1 based), 0 if cancelled

  private:
    LRESULT EvCommand(uint id, HWND hWndCtl, uint notifyCode);

    HMENU Popup;
    int   Count;
    int   Index;
};

TPickList::TPickList(const char far* title, TWindow* parent)
:
  TWindow(parent, 0, 0),
  Count(0)
{
  Popup = ::CreatePopupMenu();
  if (title) {
    ::AppendMenu(Popup, MF_GRAYED, 0, title);
    ::AppendMenu(Popup, MF_SEPARATOR, 0, 0);
  }
}

TPickList::TPickList(uint sid, TWindow* parent)
:
  TWindow(parent, 0, 0),
  Count(0)
{
  char buf[256];

  Popup = ::CreatePopupMenu();
  if (!sid || !GetApplication()->LoadString(sid, buf, sizeof(buf)))
    return;
  ::AppendMenu(Popup, MF_GRAYED, 0, buf);
  ::AppendMenu(Popup, MF_SEPARATOR, 0, 0);
}

TPickList::~TPickList()
{
  if (Popup)
    ::DestroyMenu(Popup);
}

int
TPickList::AddString(const char far* str)
{
  ::AppendMenu(Popup, MF_ENABLED, ++Count, str);
  return Count;
}

int
TPickList::Execute()
{
  TPoint loc;
  GetCursorPos(loc);
  Create();
  Index = 0;
  ::TrackPopupMenu(Popup, 0, loc.x, loc.y, 0, HWindow, 0);
  GetApplication()->PumpWaitingMessages();  // WM_COMMAND may be in queue
  ::DestroyMenu(Popup);
  Popup = 0;
  return Index;
}

LRESULT
TPickList::EvCommand(uint id, HWND /*hWndCtl*/, uint /*notifyCode*/)
{
  WARNX(OwlDocView, id > Count, 0, "TPickList index invalid");
  Index = id;
  return 0;
}

//----------------------------------------------------------------------------
//  class TDocManager
//

DEFINE_RESPONSE_TABLE (TDocManager)
  EV_WM_CANCLOSE,
  EV_WM_PREPROCMENU,
  EV_WM_WAKEUP,
  EV_COMMAND(CM_FILENEW,           CmFileNew),
  EV_COMMAND(CM_FILEOPEN,          CmFileOpen),
  EV_COMMAND(CM_FILESAVE,          CmFileSave),
  EV_COMMAND(CM_FILESAVEAS,        CmFileSaveAs),
  EV_COMMAND(CM_FILEREVERT,        CmFileRevert),
  EV_COMMAND(CM_FILECLOSE,         CmFileClose),
  EV_COMMAND(CM_VIEWCREATE,        CmViewCreate),
  EV_COMMAND_ENABLE(CM_FILENEW,    CeFileNew),
  EV_COMMAND_ENABLE(CM_FILEOPEN,   CeFileOpen),
  EV_COMMAND_ENABLE(CM_FILESAVE,   CeFileSave),
  EV_COMMAND_ENABLE(CM_FILESAVEAS, CeFileSaveAs),
  EV_COMMAND_ENABLE(CM_FILEREVERT, CeFileRevert),
  EV_COMMAND_ENABLE(CM_FILECLOSE,  CeFileClose),
  EV_COMMAND_ENABLE(CM_VIEWCREATE, CeViewCreate),
END_RESPONSE_TABLE;

TDocManager::TDocManager(int mode, TDocTemplate*& templateHead)
:
  Mode(mode),
  TemplateHead(&templateHead)
{
  TDocTemplate* ptpl;

  TemplateList = templateHead;  // catch up with any statics
  for (ptpl = TemplateList; ptpl; ptpl = ptpl->GetNextTemplate())
    ptpl->DocManager = this;

  Application = GetApplicationObject();

  // setup backward compatibility entry points
  //
  TDocTemplate::SelectSave_ = SelectSave;
  TDocTemplate::InitDoc_    = InitDoc;
  TDocTemplate::InitView_   = InitView;
}

TDocManager::TDocManager(int mode, TApplication* app, TDocTemplate*& templateHead)
:
  Mode(mode),
  Application(app),
  TemplateHead(&templateHead)
{
  TDocTemplate* ptpl;

  TemplateList = templateHead;  // catch up with any statics
  for (ptpl = TemplateList; ptpl; ptpl = ptpl->GetNextTemplate())
    ptpl->DocManager = this;

  // setup backward compatibility entry points
  //
  TDocTemplate::SelectSave_ = SelectSave;
  TDocTemplate::InitDoc_    = InitDoc;
  TDocTemplate::InitView_   = InitView;
}

TDocManager::~TDocManager()
{
  TDocument* doc;
  while ((doc = DocList.Next(0)) != 0) {
    if (doc->IsOpen())
      doc->Close();
    delete doc;            // removes view, unlinks template and doc manager
    Application->PumpWaitingMessages();  // force out posted MDI child destroy
  }
  while (TemplateList) {
    TDocTemplate* ptpl = TemplateList;
    TemplateList = ptpl->GetNextTemplate();
    if (ptpl->RefCnt & 0x8000)  // skip over statics
      ptpl->DocManager = 0;
    else
      delete ptpl;
  }
}

//
//  prompts user to select a document class for a new document
//  returns the template index used for the selection (1-based), 0 if failure
//
int
TDocManager::SelectDocType(TDocTemplate** tpllist, int tplcount)
{
  TPickList* pickl = new TPickList(IDS_DOCLIST, Application->GetMainWindow());
  while (tplcount--)
    pickl->AddString((*tpllist++)->GetDescription());
  int index = pickl->Execute();
  delete pickl;
  return index;
}

//
//  prompts user to select a view class for a new view on existing document
//  returns the template index used for the selection (1-based), 0 if failure
//
int
TDocManager::SelectViewType(TDocTemplate** tpllist, int tplcount)
{
  TPickList* pickl = new TPickList(IDS_VIEWLIST, Application->GetMainWindow());
  while (tplcount--)
    pickl->AddString((*tpllist++)->GetViewName());
  int index = pickl->Execute();
  delete pickl;
  return index;
}

//
//  struct to pass data to the dialog hook function via OPENFILENAME.lCustData
//  under Win32s the OPENFILENAME passed to WM_INITDIALOG is a temporary copy
//
struct TplHookData {      // pointer to this struct passed as lCustData
  long Flags;             // original flags passed to SelectDocPath
  unsigned long far* DlgFlags;     // pointer to dialog flags in OPENFILENAME
  char far* ExtBuf;       // pointer to buffer holding the default extension
  TDocTemplate** TplList; // template pointer array
  int InitIndex;          // starting index, ofn.nFilterIndex is inconsistent
  bool Save;              // true if saving
};

//
//  dialog hook function to catch template selection changes
//
uint CALLBACK __export
TplHook(HWND hDlg, uint msg, uint wParam, int32 lParam)
{
  static TplHookData* hookData;  // !!update to store in dialog property
  TDocTemplate** tpllist;
  OPENFILENAME* ofnHook;
  int idx;
  switch(msg) {
    case WM_COMMAND:
#if defined(BI_PLAT_WIN32)
      if (LOWORD(wParam) != cmb1 || HIWORD(wParam) != CBN_SELCHANGE)
#else
      if (wParam != cmb1 || HIWORD(lParam) != CBN_SELCHANGE)
#endif
        return 0;
      idx = (int)::SendMessage((HWND)(uint)lParam, CB_GETCURSEL, 0, 0L);
      break;

    case WM_INITDIALOG:
      ofnHook = (OPENFILENAME*)lParam;
      hookData = (TplHookData*)ofnHook->lCustData;
      idx = hookData->InitIndex;  // can't rely upon ofnHook->nFilterIndex
      break;

    default:
      return 0;
  }
  tpllist = hookData->TplList;
  long flags = tpllist[idx]->GetFlags() | hookData->Flags;
  if (hookData->Save)
    flags = (flags | dtNoReadOnly) & ~dtFileMustExist;
  *hookData->DlgFlags = flags & ~dtProhibited;
  if (tpllist[idx]->GetDefaultExt())
    strcpy(hookData->ExtBuf, tpllist[idx]->GetDefaultExt());
  else
    hookData->ExtBuf[0] = 0;
  ::SendDlgItemMessage(hDlg, chx1, BM_SETCHECK, ((flags&dtReadOnly) != 0), 0);
  ::ShowWindow(GetDlgItem(hDlg, chx1), (flags&dtHideReadOnly)?SW_HIDE:SW_SHOW);
  return 0;  // flag as unprocessed
}

//  prompts user with one or all templates to select file to open
//  returns the template index used for the selection (1-based), 0 if failure
//  this is Windows-specific, using the system-defined file open dialog box
//
int
TDocManager::SelectDocPath(TDocTemplate** tpllist, int tplcount,
              char far* path, int buflen, long flags, bool save)
{
  char extbuf[MAXEXT-1];       // writable buffer for default file extension
  OPENFILENAME ofn;            // local openfilename structure
  int index, count, len;
  char* filtbuf;
  char* pbuf;
  memset(&ofn, 0, sizeof(ofn));
  TDocTemplate* ptpl;
  TProcInstance TplHookProcInstance((FARPROC)TplHook);

  // Concatenate description and filters into a single string
  //
  for (len=2, count=0; count < tplcount; count++) {
    ptpl = tpllist[count];
    len += (strlen(ptpl->GetFileFilter())+2); // space for two null separators
    if (ptpl->GetDescription())
      len += strlen(ptpl->GetDescription());
  }
  filtbuf = new char[len];
  for (pbuf = filtbuf, count=0; count < tplcount; count++) {
    ptpl = tpllist[count];
    if ((len = strlen(ptpl->GetDescription())) != 0) {
      strcpy(pbuf, ptpl->GetDescription());
      pbuf += len + 1;
    }
    else {
      *pbuf++ = 0;
    }
    strcpy(pbuf, ptpl->GetFileFilter());
    pbuf += strlen(pbuf) + 1;
  }
  *pbuf = 0;              // double null to signify end

  // set selection to previously selected template if present
  //
  for (index = count = 0; count < tplcount; count++)
    if (tpllist[count]->IsFlagSet(dtSelected)) {
      index = count;
      break;
    }

  struct TplHookData hookData = {flags,&ofn.Flags,extbuf,tpllist,index,save};
  ofn.nFilterIndex = index + 1; // Note: Windows *might* decrement this by one
  ofn.lpstrInitialDir = tpllist[index]->GetDirectory();
  ofn.lpstrDefExt = (LPCSTR)&extbuf;  // receives string from hook function
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hwndOwner = Application->GetMainWindow()->HWindow;
  ofn.lpstrFilter = filtbuf;
  ofn.lpstrFile = path;
  ofn.nMaxFile = buflen;
  ofn.Flags = OFN_ENABLEHOOK /* | OFN_NOCHANGEDIR */;
  ofn.lCustData = (LPARAM)&hookData;
  (DLGPROC)ofn.lpfnHook = (DLGPROC)(FARPROC)TplHookProcInstance;

  Application->EnableCtl3dAutosubclass(true);

  if ((save ? ::GetSaveFileName(&ofn) : ::GetOpenFileName(&ofn)) == 0) {
    uint32 err = ::CommDlgExtendedError();  // temp for debugging use
    if (err != 0)
      TRACEX(OwlDocView, 0, "OpenFileName error:" << err);
    ofn.nFilterIndex = 0;
  }
  else {
    TDocument* doc;
    if (ofn.lpstrFile && (doc = FindDocument(ofn.lpstrFile)) != 0) {
      PostDocError(*doc, IDS_DUPLICATEDOC);
      return 0;
    }

    // Set flag to remember template which was selected
    //
    for (index=(int)ofn.nFilterIndex-1, count=0; count < tplcount; count++) {
      if (count == index)
        tpllist[count]->SetFlag(dtSelected);
      else
        tpllist[count]->ClearFlag(dtSelected);
    }
    // Update template with directory from dialog if flag set
    //
    ptpl = tpllist[(int)ofn.nFilterIndex - 1];
    if (ofn.nFileOffset && (ptpl->IsFlagSet(dtUpdateDir))
                        && (ptpl->GetDirectory()==0
         || memcmp(ptpl->GetDirectory(), ofn.lpstrFile,ofn.nFileOffset) != 0))
      ptpl->SetDirectory(ofn.lpstrFile, ofn.nFileOffset);
  }
  delete [] filtbuf;
  Application->EnableCtl3dAutosubclass(false);
  return (int)ofn.nFilterIndex;
}

void
TDocManager::AttachTemplate(TDocTemplate& tpl)
{
  tpl.DocManager = this;
  TDocTemplate::AddLink((TRegLink*&)TemplateList, tpl);
}

void
TDocManager::DeleteTemplate(TDocTemplate& tpl)
{
  if (tpl.RefCnt & 0x8000) // check for static templates
    return;
  if (!tpl.DocManager)    // check if has owner
    return;

  if (TDocTemplate::RemoveLink((TRegLink*&)TemplateList, tpl)) {
    UnRefTemplate(tpl);  // will delete unless documents still reference it
    return;
  }
  TRACEX(OwlDocView, 0, "TDocManager::DeleteTemplate(), not in app list");
}

//  initialize document using its specific doc template
//  prompts for pathname if none supplied and not creating a new document
//
TDocument*
TDocManager::InitDoc(TDocument* doc, const char far* path, long flags)
{
  TDocTemplate* tpl = doc->GetTemplate();
  if (!tpl)
    return 0;
  flags ^= tpl->GetFlags();     // alter template's flags using caller's mask
  if (flags & dtNewDoc) {
    doc->SetDocPath(0);
    if (!doc->InitDoc()) { // Give doc a chance to do its own initialization
      PostDocError(*doc, IDS_UNABLEOPEN);
      delete doc;
      return 0;
    }
  }
  else {
    if (!path) {
      char filepath[256];
      if (!tpl->GetFileFilter())
        return 0;
      filepath[0] = 0;    // no initial file path
      int index = SelectDocPath(&tpl, 1, filepath, sizeof(filepath), flags);
      if (!index) {
        delete doc;
        return 0;
      }
      path = filepath;
    }
    doc->SetDocPath(path);
    if (!doc->InitDoc()) { // Give doc a chance to do its own initialization
      PostDocError(*doc, IDS_UNABLEOPEN);
      delete doc;
      return 0;
    }

    if ((flags & dtAutoOpen)
        && !doc->Open((flags & dtNoReadOnly) ? ofReadWrite : ofRead)) {
      PostDocError(*doc, IDS_UNABLEOPEN);
      delete doc;
      return 0;
    }
  }
  PostEvent(dnCreate, *doc);
  if (!(flags & dtNoAutoView)) {
    if (!doc->InitView(tpl->ConstructView(*doc))) {
      if (flags & dtAutoDelete) {
        if (doc->IsOpen())
          doc->Close();
        delete doc;
      }
      return 0;
    }
  }
  return doc;
}

//  create and initialize document using a specific doc template
//
TDocument*
TDocManager::CreateDoc(TDocTemplate* tpl, const char far* path,
                       TDocument* parent, long flags)
{
  if (!tpl)
    return 0;

  TDocument dummyDoc(this);
  if (parent == 0)
    parent = &dummyDoc;

  TDocument* doc = tpl->ConstructDoc(parent);
  if (!doc)
    return 0;
  doc->SetTemplate(tpl);
  return InitDoc(doc, path, flags);
}

TView*
TDocManager::CreateView(TDocument& doc)
{
  return doc.InitView(doc.GetTemplate()->ConstructView(doc)); // tests view==0
}

bool
TDocManager::SelectSave(TDocument& doc)
{
  TDocTemplate* ptpl = doc.GetTemplate();
  if (!ptpl || !ptpl->GetFileFilter())
    return false;
  char filepath[256];
  if (doc.GetDocPath())
    strcpy(filepath, doc.GetDocPath());
  else
    filepath[0] = 0;    // no initial file path
  int index = SelectDocPath(&ptpl,1, filepath,sizeof(filepath), 0, true);
  return index ? doc.SetDocPath(filepath) : false;
}

TDocument*
TDocManager::FindDocument(const char far* path)
{
  TDocument* doc = 0;
  while ((doc = DocList.Next(doc)) != 0)
    if (path) {
      if (doc->GetDocPath() && strcmp(doc->GetDocPath(), path) == 0)
        break;
    }
    else {
      if (doc->GetDocPath() == 0)
        break;
    }
  return doc;
}

void
TDocManager::PostEvent(int id, TDocument& doc)
{
  TWindow* win = Application->GetMainWindow();
  if (win && win->HWindow)
    win->SendMessage(WM_OWLDOCUMENT, id, (LPARAM)&doc);
}

void
TDocManager::PostEvent(int id, TView& view)
{
  TWindow* win = Application->GetMainWindow();
  if (win && win->HWindow)
    win->SendMessage(WM_OWLVIEW, id, (LPARAM)&view);
}

bool
TDocManager::EvCanClose()
{
  TDocument* doc = 0;
  while ((doc = DocList.Next(doc)) != 0) {
    if (!doc->CanClose())  // normally calls back to FlushDoc()
      return false;
  }
  return true;
}

//
// Preprocess the app frame's menu to replace the file menu with one managed
// by this docmanager
//
void
TDocManager::EvPreProcessMenu(HMENU hMenuBar)
{
  if (Mode & dmMenu) {
    HMENU hMenu = Application->LoadMenu(IDM_DOCMANAGERFILE);
    if (!hMenu)
      hMenu = ::Module->LoadMenu(IDM_DOCMANAGERFILE);
    if (hMenu) {
      char buf[40];
      Application->LoadString(IDS_DOCMANAGERFILE, buf, sizeof buf);
      if (Mode & dmNoRevert)
        ::DeleteMenu(hMenu, CM_FILEREVERT, MF_BYCOMMAND);
      ::DeleteMenu(hMenuBar, 0, MF_BYPOSITION);
      ::InsertMenu(hMenuBar, 0, MF_BYPOSITION|MF_POPUP, (uint)hMenu, buf);
    }
  }
}

void
TDocManager::EvWakeUp()
{
  TDocument* doc = 0;
  while ((doc = DocList.Next(doc)) != 0)
    doc->ReindexFrames();
}

bool
TDocManager::FlushDoc(TDocument& doc)
{
  while (doc.IsDirty()) {
    int saveOrNot = doc.IsEmbedded() ?
                      IDYES :
                      PostDocError(doc, IDS_DOCCHANGED, MB_YESNOCANCEL);

    switch (saveOrNot) {
      case IDYES:
        // Prompt the user for filename in save-as situation
        //
        if (!doc.IsEmbedded() && doc.GetDocPath() == 0) {
          TDocTemplate* tpl = SelectAnySave(doc, false);
          if (!tpl)
            continue;
          if (tpl != doc.Template)
            doc.SetTemplate(tpl);
        }
        if (doc.Commit())
          return true;
        continue;

      case IDNO:
        if (doc.Revert(true))
          return true;
        return false;

      case IDCANCEL:
        return false;
    }
  }
  return true;
}

TDocument*
TDocManager::GetCurrentDoc()
{
  TDocument* doc = 0;
  HWND hwnd = GetApplication()->GetMainWindow()->GetCommandTarget();

  while ((doc = DocList.Next(doc)) != 0 && !doc->HasFocus(hwnd))
    ;
  return doc;
}

//
// event handlers
//
void
TDocManager::CeFileNew(TCommandEnabler& ce)
{
  ce.Enable(TemplateList != 0);
}

void
TDocManager::CmFileNew()
{
  CreateAnyDoc(0, dtNewDoc);
}

void
TDocManager::CeFileOpen(TCommandEnabler& ce)
{
  ce.Enable(TemplateList != 0);
}

void
TDocManager::CmFileOpen()
{
  CreateAnyDoc(0, 0);
}

void
TDocManager::CeFileClose(TCommandEnabler& ce)
{
  ce.Enable(GetCurrentDoc() != 0);
}

void
TDocManager::CmFileClose()
{
  TDocument* doc = GetCurrentDoc();
  if (doc && doc->CanClose()) {  // normally calls back to FlushDoc()
    if (!doc->Close())
      PostDocError(*doc, IDS_UNABLECLOSE);
    else
      delete doc;
  }
}

void
TDocManager::CeFileSaveAs(TCommandEnabler& ce)
{
  TDocument* doc = GetCurrentDoc();
  ce.Enable(doc != 0);
}

void
TDocManager::CmFileSaveAs()
{
  TDocument* doc = GetCurrentDoc();
  if (doc) {
    TDocTemplate* tpl = SelectAnySave(*doc, false);
    if (tpl) {
      if (tpl != doc->Template)
        doc->SetTemplate(tpl);       // replace existing template
      doc->Commit(true);             // force rewrite to new path
    }
  }
}

void
TDocManager::CeFileSave(TCommandEnabler& ce)
{
  TDocument* doc = GetCurrentDoc();
  ce.Enable(doc && (doc->IsDirty() || (Mode & dmSaveEnable)));
}

void
TDocManager::CmFileSave()
{
  TDocument* doc = GetCurrentDoc();
  if (doc) {
    if (doc->GetDocPath() == 0) {
      CmFileSaveAs();
      return;
    }
    if (!(Mode & dmSaveEnable) && !doc->IsDirty()) {
      PostDocError(*doc, IDS_NOTCHANGED);
      return;
    }
    doc->Commit();  // should force write here?
  }
}

void
TDocManager::CeFileRevert(TCommandEnabler& ce)
{
  TDocument* doc = GetCurrentDoc();
  ce.Enable(doc && doc->IsDirty() && doc->GetDocPath());
}

void
TDocManager::CmFileRevert()
{
  TDocument* doc = GetCurrentDoc();
  if (doc && doc->GetDocPath()) {
    if (!doc->IsDirty()) {
      PostDocError(*doc, IDS_NOTCHANGED);
      return;
    }
    doc->Revert();
  }
}

void
TDocManager::CeViewCreate(TCommandEnabler& hndlr)
{
  TDocument* doc = GetCurrentDoc();
  hndlr.Enable(doc != 0);
}

void
TDocManager::CmViewCreate()
{
  TDocument* doc = GetCurrentDoc();
  if (doc)
    CreateAnyView(*doc);
}

uint
TDocManager::PostDocError(TDocument& doc, uint sid, uint choice)
{
  char buf[256];

  if (Application->LoadString(sid, buf, sizeof buf) == 0)
    strcpy(buf, "Error: Message not found");  // should throw exception?
  if (choice != MB_OK)
    choice |= MB_ICONQUESTION;
  return Application->GetMainWindow()->MessageBox(buf, doc.GetTitle(), choice);
}

//
//  CreateAnyDoc - selects from list of attached non-hidden doc templates
//
TDocument*
TDocManager::CreateAnyDoc(const char far* path, long flags)
{
  TDocTemplate* ptpl;
  TDocument* doc;
  char filepath[256];
  int index;
  TDocTemplate* tpllist[40];  // increase number to display more templates
  int tplcount = 0;

  // compose list of visible templates
  //
  for (ptpl = TemplateList; ptpl; ptpl = ptpl->GetNextTemplate()) {
    if (ptpl->IsVisible() &&
        !(ptpl->IsFlagSet(dtReadOnly) && (flags & dtNewDoc)))
      tpllist[tplcount++] = ptpl;

    // prevent overflowing array
    if (tplcount >= sizeof(tpllist)/sizeof(tpllist[0]))
      break;
  }
  if (!tplcount)
    return 0;         // no usable templates

  if (flags & dtNewDoc) {  // creat empty doc from any registered template
    index = tplcount==1 ? 1 : SelectDocType(tpllist, tplcount);
  }
  else {           // select doc using filters from all registered templates
    if (path)
      strcpy(filepath, path);
    else
      filepath[0] = 0;    // no initial file path
    index = SelectDocPath(tpllist, tplcount, filepath, sizeof(filepath), flags);
    WARNX(OwlDocView, index > tplcount, 0,
          "Invalid template index from SelectDocPath");
  }
  if (!index)
    return 0;   // user cancel or dialog error

  if (filepath && (doc = FindDocument(filepath)) != 0) {
    PostDocError(*doc, IDS_DUPLICATEDOC);
    return 0;
  }

  ptpl = tpllist[index-1];

  if ((Mode & dmSDI) && (doc = DocList.Next(0)) != 0) { // one at a time if SDI
    if (!doc->CanClose())        // normally calls back to FlushDoc()
      return 0;
    if (!doc->Close()) {
      PostDocError(*doc, IDS_UNABLECLOSE);
      return 0;
    }
    delete doc;
  }

  doc = ptpl->ConstructDoc(&TDocument(this));  // pass a dummy doc
  doc->SetTemplate(ptpl);
  return InitDoc(doc, filepath, flags);
}

//
//  SelectAnySave - selects from registered templates supporting this doc
//
TDocTemplate*
TDocManager::SelectAnySave(TDocument& doc, bool samedoc)
{
  TDocTemplate* ptpl;
  char filepath[256];
  int index;
  TDocTemplate* tpllist[40];
  int tplcount;

  if (!TemplateList)
    return 0;   // if no templates are registered
  for (tplcount = 0, ptpl = TemplateList; ptpl; ptpl = ptpl->GetNextTemplate()) {
    if (ptpl->IsVisible() && (!samedoc || ptpl->IsMyKindOfDoc(doc))
        && !ptpl->IsFlagSet(dtReadOnly) )
      tpllist[tplcount++] = ptpl;
  }
  if (!tplcount)
    return 0;         // no usable templates
  if (doc.GetDocPath())
    strcpy(filepath, doc.GetDocPath());
  else
    filepath[0] = 0;    // no initial file path
  index = SelectDocPath(tpllist, tplcount, filepath, sizeof(filepath),0,true);
  if (!index)
    return 0;   // user cancel or dialog error
  ptpl = tpllist[index-1];
  if (!doc.SetDocPath(filepath))
    return 0;
  return ptpl;
}

//
//  CreateAnyView - selects from registered templates supporting this doc
//
TView*
TDocManager::CreateAnyView(TDocument& doc, long /*flags*/)
{
  const int MaxViewCount = 25;
  TDocTemplate* tplList[MaxViewCount];
  int tplCount;
  TDocTemplate* ptpl;
  int index;
  const char far* viewName;

  for (ptpl=TemplateList, tplCount=0; ptpl != 0; ptpl = ptpl->GetNextTemplate()) {
    if (ptpl->IsMyKindOfDoc(doc)) {
      viewName = ptpl->GetViewName();
      for (index = 0; index < tplCount; index++)
        if (tplList[index]->GetViewName() == viewName)
          break;
      if (ptpl->IsFlagSet(dtSingleView)) {
        TView* pview = 0;
        while ((pview = doc.NextView(pview)) != 0)
          if (ptpl->IsMyKindOfView(*pview))
            index = -1;  // force continue in outer loop
      }
      if (index == tplCount) {
        tplList[tplCount++] = ptpl;
      }
    }
  }
  index = (tplCount > 1) ? SelectViewType(tplList, tplCount) : tplCount;
  if (index == 0)   // check if user cancelled or no valid templates
    return 0;

  ptpl = tplList[index - 1];
  return doc.InitView(ptpl->ConstructView(doc)); // call virtual create
}

#define ANSITOUPPER(c) ( (char)(unsigned)(unsigned long)\
                ::AnsiUpper((char far*)(unsigned long)(c)) )

TDocTemplate*
TDocManager::MatchTemplate(const char far* path)
{
  TDocTemplate* ptpl;
  char name[256];

  if (FindDocument(path))
    return 0;   // prevent reload of same document
  if (::GetFileTitle(path, name, sizeof(name)) != 0)
    return 0;   // invalid name or buffer too small
  ::AnsiUpper(name);
  for (ptpl = TemplateList; ptpl != 0; ptpl = ptpl->GetNextTemplate()) {
    const char far* pp = ptpl->GetFileFilter();
    if (!pp || ptpl->IsFlagSet(dtHidden))
      continue;
    char* pn = name;
    char  cp;
    do {
      if ((cp = *pp++) != '?') {
        if (cp == '*') {
          while (*pn != '.' && *pn != 0)
            pn++;
          if (*pp == '.' && *pn == 0)  // check for missing extension
            pp++;
          continue;
        }
        if (*pn != ANSITOUPPER(cp)) {  // if mismatch
          if (!(cp == ';' && *pn == 0)) { // check for successful case
            while (cp != ';' && cp != 0)  // check if more patterns
              cp = *pp++;
            pn = name;      // rescan name
            continue;
          }
        }
      }
      if (*pn++ == 0)    // reached end of name OK
        return ptpl;
    } while (cp != 0);
  }
  return 0;   // returns 0 if loop terminates with no matching templates
}

#endif

#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE(TDocManager);

void*
TDocManager::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TDocManager* o = GetObject();

  TDocTemplate* ptpl = o->TemplateList;
  for (;;) {
    int isStatic;

    is >> isStatic;
    if (isStatic == -1)
      break;

    if (isStatic) {
      if (ptpl) {                         // if static templates available
        is >> *ptpl;                      // update static template data
        ptpl = o->GetNextTemplate(ptpl);
      }
      else {                            // have run out of static templates
        char tbuf[sizeof(TDocTemplate)];  // sink for unused template data
        memset(tbuf,0,sizeof(tbuf));      // force static flag off
        is >> *(TDocTemplate*)tbuf;
      }
    }
    else {                // if dynamic template, object will be constructed
      TModule* module;
      is >> module;
      is >> ptpl;
      ptpl->SetModule(module);
      o->AttachTemplate(*ptpl);
    }
  }

  int count;
  is >> count;               // document count
  while (count--) {
    TDocument*  doc;
    is >> doc;
    doc->SetDocManager(*o);  // inserts properly into list
  }

  // Get application, & post ourselves a wakeup message to finish things up
  // once all windows have been created, etc.
  //
  o->Application = GetApplicationObject();
  TWindow* win = o->Application->GetMainWindow();
  if (win && win->HWindow)
    win->PostMessage(WM_OWLWAKEUP);

  return o;
}

void
TDocManager::Streamer::Write(opstream& os) const
{
  TDocManager* o = GetObject();

  TDocTemplate* ptpl = 0;
  while ((ptpl = o->GetNextTemplate(ptpl)) != 0) {
    int flag = ptpl->IsStatic();
    os << flag;
    if (flag) {
      os << *ptpl;              // write reference to static template
    }
    else {
      os << ptpl->GetModule();  // write template's module pointer first
      os << ptpl;               // write pointer to static template
    }
  }
  os << -1;   // template list terminator

  TDocument* doc = 0;
  int count;
  for (count = 0; (doc = o->DocList.Next(doc))!=0; count++) ;
  os << count;

  // Must write documents out in order created, i.e. from end of list forward
  //
  while (count) {
    int i = count--;
    for (doc = 0; i--; doc = o->DocList.Next(doc)) ;
    os << doc;
  }
}

//
// TDocTemplate backward compatibility code
//

bool TDocManager::SelectSave(TDocTemplate* ptpl, TDocument& doc)
{
  TDocManager* mgr = ptpl->GetDocManager();
  if (!mgr || !ptpl || !ptpl->GetFileFilter())
    return false;
  char filepath[256];
  if (doc.GetDocPath())
    strcpy(filepath, doc.GetDocPath());
  else
    filepath[0] = 0;    // no initial file path
  int index = mgr->SelectDocPath(&ptpl,1, filepath,sizeof(filepath), 0, true);
  return index ? doc.SetDocPath(filepath) : false;
}

TView* TDocManager::InitView(TView* view)
{
  if (!view)   // test in case new TView failed
    return 0;
  return view->GetDocument().InitView(view);
}

TDocument* TDocManager::InitDoc(TDocTemplate& tpl, TDocument* doc,
                                const char far* path, long flags)
{
  TDocManager* mgr = tpl.GetDocManager();
  if (!mgr || !doc)
    return 0;
  doc->SetTemplate(&tpl);
  return mgr->InitDoc(doc, path, flags);
}

static void Obsolete() {TRACEX(OwlDocView, 0, "Obsolete function called");}
void TDocTemplate::SetFileFilter(const char far*) {Obsolete();}
void TDocTemplate::SetDescription(const char far*){Obsolete();}
void TDocTemplate::SetDefaultExt(const char far*) {Obsolete();}

#endif

