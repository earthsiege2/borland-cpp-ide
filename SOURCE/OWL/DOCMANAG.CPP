//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   include\owl\docview.cpp
//   Implements classes TDocManager, TDocTemplate
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\docmanag.h>
#include <owl\docview.rc>
#include <string.h>
#include <dlgs.h>  /* cmb1 for file open dialog box */
#include <dir.h>   /* MAXEXT for file open dialog default extension */

#define TemplatesSeized ((TDocTemplate*)1)  // template list taken by doc mgr

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
    TPickList(LPCSTR title, TWindow* parent = 0);
    TPickList(UINT sid, TWindow* parent = 0);
   ~TPickList();
    int AddString(LPCSTR str);
    int Execute();   // returns pick index (1-based), 0 if cancelled

  private:
    LRESULT EvCommand (UINT id, HWND hWndCtl, UINT notifyCode);
    HMENU Popup;
    int Count;
    int Index;
};

LRESULT
TPickList::EvCommand (UINT id, HWND /* hWndCtl */, UINT /* notifyCode */)
{
  WARNX(OwlDocView, id > Count, 0, "TPickList index invalid");
  Index = id;
  return 0;
}

TPickList::TPickList(LPCSTR title, TWindow* parent)
  : TWindow(parent ? parent : GetApplicationObject()->MainWindow,0,0)
{
  Popup = ::CreatePopupMenu();
  if (title) {
    ::AppendMenu(Popup, MF_GRAYED, 0, title);
    ::AppendMenu(Popup, MF_SEPARATOR, 0, 0);
  }
  Count = 0;
}

TPickList::TPickList(UINT sid, TWindow* parent)
 : TWindow(parent ? parent : GetApplicationObject()->MainWindow,0,0), Count(0)
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
TPickList::AddString(LPCSTR str)
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
//----------------------------------------------------------------------------
//
//  class TDocTemplate
//  ----- ------------
//

TDocTemplate::TDocTemplate(LPCSTR desc, LPCSTR filt, LPCSTR dir, LPCSTR ext,
                           long flags, TModule*& module, TDocTemplate*& rptpl)
  : Flags(flags),
    Description(desc ? strnewdup(desc) : 0),
    FileFilter (filt ? strnewdup(filt) : 0),
    Directory  (dir  ? strnewdup(dir)  : 0),
    DefaultExt (ext  ? strnewdup(ext)  : 0),
    ModulePtr(&module)
{
  // link this template into doc manager's template list
  // if the doc manager is not constructed yet, link into static list
  // the doc manager will then hook this list into its own chain
  TDocTemplate** pptpl;
  if (rptpl == TemplatesSeized) {
    DocManager = GetApplicationObject()->DocManager;
    RefCnt = 1;
    pptpl = &DocManager->TemplateList;
  } else {
    pptpl = &rptpl;
    RefCnt = 0x8001;  // flag as static
  }
  while (*pptpl)     // put new templates at end of chain
    pptpl = &(*pptpl)->NextTemplate;
  NextTemplate = 0;
  *pptpl = this;
}

void TDocTemplate::SetFileFilter(const char far* txt)
{
  delete FileFilter;
  FileFilter = txt ? strnewdup(txt) : 0;
}

void TDocTemplate::SetDescription(const char far* txt)
{
  delete Description;
  Description = txt ? strnewdup(txt) : 0;
}

void TDocTemplate::SetDirectory(const char far* txt)
{
  delete Directory;
  Directory = txt ? strnewdup(txt) : 0;
}

void TDocTemplate::SetDirectory(const char far* txt, int len)
{
  delete Directory;
  if (txt && len > 0) {
    Directory = strncpy(new far char[len+1], txt, len);
    Directory[len] = 0;
  } else {
    Directory = 0;
  }
}

void TDocTemplate::SetDefaultExt(const char far* txt)
{
  delete DefaultExt;
  DefaultExt = txt ? strnewdup(txt) : 0;
}

TDocTemplate::~TDocTemplate()   // called only when RefCnt goes to 0
{
  delete FileFilter;
  delete Description;
  delete Directory;
  delete DefaultExt;
}


//  prompts user to select a document class for a new document
//  returns the template index used for the selection (1-based), 0 if failure

int
TDocManager::SelectDocType(TDocTemplate** tpllist, int tplcount)
{
  TPickList* pickl = new TPickList(IDS_DOCLIST);
  while (tplcount--)
    pickl->AddString((*tpllist++)->GetDescription());
  int index = pickl->Execute();
  delete pickl;
  return index;
}

//  prompts user to select a view class for a new view on existing document
//  returns the template index used for the selection (1-based), 0 if failure

int
TDocManager::SelectViewType(TDocTemplate** tpllist, int tplcount)
{
  TPickList* pickl = new TPickList(IDS_VIEWLIST);
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
  TDocTemplate** TplList; // template pointer array
  char far* ExtBuf;       // pointer to buffer holding the default extension
  int InitIndex;          // starting index, ofn.nFilterIndex is inconsistent
};

//
//  dialog hook function to catch template selection changes
//
UINT FAR PASCAL _export
TplHook(HWND hDlg, UINT msg, UINT wParam, LONG lParam)
{
  static TplHookData* hookData;  // !!update to store in dialog property
  TDocTemplate** tpllist;
  OPENFILENAME* ofnHook;
  int idx;
  switch(msg) {
    case WM_COMMAND:
#if defined(__WIN32__)
      if (LOWORD(wParam) != cmb1 || HIWORD(wParam) != CBN_SELCHANGE)
#else
      if (wParam != cmb1 || HIWORD(lParam) != CBN_SELCHANGE)
#endif
        return 0;
      idx = (int)::SendMessage((HWND)(UINT)lParam, CB_GETCURSEL, 0, 0L);
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
  if (tpllist[idx]->GetDefaultExt())
    strcpy(hookData->ExtBuf, tpllist[idx]->GetDefaultExt());
  else
    hookData->ExtBuf[0] = 0;
  ::SendDlgItemMessage(hDlg, chx1, BM_SETCHECK, 
                       tpllist[idx]->IsFlagSet(dtReadOnly), 0);
  ::ShowWindow(GetDlgItem(hDlg, chx1),
               tpllist[idx]->IsFlagSet(dtHideReadOnly) ? SW_HIDE : SW_SHOW);
  return 0;  // flag as unprocessed
}

//
//  prompts user with one or all templates to select file to open
//  returns the template index used for the selection (1-based), 0 if failure
//  this is Windows-specific, using the system-defined file open dialog box
//
int
TDocManager::SelectDocPath(TDocTemplate** tpllist, int tplcount,
              LPSTR path, int buflen, long flags, BOOL save)
{
  char extbuf[MAXEXT-1];       // writable buffer for default file extension
  OPENFILENAME ofn;            // local openfilename structure
  int index, count, len;
  char* filtbuf;
  char* pbuf;
  memset(&ofn, 0, sizeof(ofn));
  TDocTemplate* ptpl;
  TProcInstance TplHookProcInstance((FARPROC)TplHook);
  // concatenate description and filters into a single string
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
    } else {
      *pbuf++ = 0;
    }
    len = strlen(ptpl->GetFileFilter());
    strcpy(pbuf, ptpl->GetFileFilter());
    pbuf += len + 1;
  }
  *pbuf = 0;              // double null to signify end
  // set selection to previously selected template if present
  for (index = count = 0; count < tplcount; count++)
    if (tpllist[count]->IsFlagSet(dtSelected)) {
      index = count;
      break;
    }
  struct TplHookData hookData = {tpllist, extbuf, index};
  ofn.nFilterIndex = index + 1; // Note: Windows *might* decrement this by one
  ofn.lpstrInitialDir = tpllist[index]->GetDirectory();
  ofn.lpstrDefExt = (LPCSTR)&extbuf;  // receives string from hook function
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hwndOwner = GetApplicationObject()->MainWindow->HWindow;
  ofn.lpstrFilter = filtbuf;
  ofn.lpstrFile = path;
  ofn.nMaxFile = buflen;
  ofn.Flags = (flags & ~dtProhibited) | OFN_ENABLEHOOK/* | OFN_NOCHANGEDIR */;
  ofn.lCustData = (LPARAM)&hookData;   
  (DLGPROC)ofn.lpfnHook = (DLGPROC)(FARPROC)TplHookProcInstance;
  GetApplicationObject()->EnableCtl3dAutosubclass(TRUE);
  if ((save ? ::GetSaveFileName(&ofn) : ::GetOpenFileName(&ofn)) == 0){
    DWORD err = ::CommDlgExtendedError();  // temp for debugging use
    if (err != 0)
      TRACEX(OwlDocView, 0, "OpenFileName error:" << err);
    ofn.nFilterIndex = 0;
  } else {
    // set flag to remember template which was selected
    for (index=(int)ofn.nFilterIndex-1, count=0; count < tplcount; count++) {
      if (count == index)
        tpllist[count]->SetFlag(dtSelected);
      else
        tpllist[count]->ClearFlag(dtSelected);
    }
    // update template with directory from dialog if flag set
    ptpl = tpllist[(int)ofn.nFilterIndex - 1];
    if (ofn.nFileOffset && (ptpl->IsFlagSet(dtUpdateDir))
                        && (ptpl->GetDirectory()==0
         || memcmp(ptpl->GetDirectory(), ofn.lpstrFile,ofn.nFileOffset) != 0))
      ptpl->SetDirectory(ofn.lpstrFile, ofn.nFileOffset);
  }
  delete filtbuf;
  GetApplicationObject()->EnableCtl3dAutosubclass(FALSE);
  return (int)ofn.nFilterIndex;
}

void
TDocManager::AttachTemplate(TDocTemplate& tpl)
{
  TDocTemplate** pptpl = &TemplateList;
  while (*pptpl)     // put new templates at end of chain
    pptpl = &(*pptpl)->NextTemplate;
  tpl.NextTemplate = 0;
  tpl.DocManager = this;
  *pptpl = &tpl;
}

void
TDocManager::DeleteTemplate(TDocTemplate& tpl)
{
  if (tpl.RefCnt & 0x8000) // check for static templates
    return;
  if (!tpl.DocManager)    // check if has owner           
    return;
  TDocTemplate** tpllist = &tpl.DocManager->TemplateList;
  for ( ; *tpllist; tpllist = &(*tpllist)->NextTemplate) {
    if (*tpllist == &tpl) {
      *tpllist = tpl.NextTemplate; // remove from application list
      UnRefTemplate(tpl);  // will delete unless documents still reference it
      return;
    }
  }
  TRACEX(OwlDocView, 0, "TDocManager::DeleteTemplate(), not in app list");
}

//
//  initialize document using a specific doc template
//  prompts for pathname if none supplied and not creating a new document
//
TDocument*
TDocTemplate::InitDoc(TDocument* doc, LPCSTR path, long flags)
{
  char filepath[256];
  if (!doc)
    return doc;       // in case new TDocument failed
  flags ^= Flags;     // alter template's flags using caller's mask       
  if (flags & dtNewDoc) {
    doc->SetDocPath(0);
  } else {
    if (!path) {
      if (!FileFilter)
        return 0;
      filepath[0] = 0;    // no initial file path
      TDocTemplate* ptpl = this;
      int index = doc->DocManager->SelectDocPath(&ptpl, 1,
                                filepath, sizeof(filepath), flags|Flags);
      if (!index) {
        delete doc;
        return 0;
      }
      path = filepath;
    }
    doc->SetDocPath(path);

    if ((flags & dtAutoOpen)
    && !doc->Open((flags & dtNoReadOnly) ? ofReadWrite : ofRead)) {
      doc->DocManager->PostDocError(*doc, IDS_UNABLEOPEN);
      delete doc;
      return 0;
    }
  }
  doc->SetTemplate(this);
  doc->DocManager->PostEvent(dnCreate, *doc);
  if (!(flags & dtNoAutoView)) {
    if (!(CreateView(*doc, flags))) {
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

BOOL
TDocTemplate::SelectSave(TDocument& doc)
{
  char filepath[256];
  if (!FileFilter)
    return FALSE;
  if (doc.GetDocPath())
    strcpy(filepath, doc.GetDocPath());
  else
    filepath[0] = 0;    // no initial file path
  TDocTemplate* ptpl = this;
  int index = doc.DocManager->SelectDocPath(&ptpl,1, filepath,sizeof(filepath),
                            (Flags|dtNoReadOnly)&~dtFileMustExist, TRUE);
  return index ? doc.SetDocPath(filepath) : FALSE;
}

TView*
TDocTemplate::InitView(TView* view)
{
  if (!view)   // test in case new TView failed
    return 0;
  return view->GetDocument().InitView(view);
}

//
//  class TDocManager
//  ----- -----------
//

DEFINE_RESPONSE_TABLE (TDocManager)
  EV_WM_CANCLOSE,
  EV_WM_PREPROCMENU,
  EV_COMMAND(CM_FILENEW,           CmFileNew),
  EV_COMMAND(CM_FILEOPEN,          CmFileOpen),
  EV_COMMAND(CM_FILESAVE,          CmFileSave),
  EV_COMMAND(CM_FILESAVEAS,        CmFileSaveAs),
  EV_COMMAND(CM_FILEREVERT,        CmFileRevert),
  EV_COMMAND(CM_FILECLOSE,         CmFileClose),
  EV_COMMAND(CM_VIEWCREATE,        CmViewCreate),
  EV_COMMAND_ENABLE(CM_FILENEW,    CmEnableNew),
  EV_COMMAND_ENABLE(CM_FILEOPEN,   CmEnableOpen),
  EV_COMMAND_ENABLE(CM_FILESAVE,   CmEnableSave),
  EV_COMMAND_ENABLE(CM_FILESAVEAS, CmEnableSaveAs),
  EV_COMMAND_ENABLE(CM_FILEREVERT, CmEnableRevert),
  EV_COMMAND_ENABLE(CM_FILECLOSE,  CmEnableClose),
  EV_COMMAND_ENABLE(CM_VIEWCREATE, CmEnableCreate),
END_RESPONSE_TABLE;

TDocManager::TDocManager(int mode, TDocTemplate*& templateHead)
            : Mode(mode), TemplateHead(&templateHead)
{
  TDocTemplate* ptpl;

  if (templateHead != TemplatesSeized) {
    TemplateList = templateHead;  // catch up with any statics
    templateHead = TemplatesSeized;
  }
  for (ptpl = TemplateList; ptpl; ptpl = ptpl->NextTemplate) {
    ptpl->DocManager = this;
    ptpl->RefCnt |= 0x8000;       // flag as static
  }
  Application = GetApplicationObject();
}

TDocManager::~TDocManager()
{
  TDocument* pdoc = 0;
  TDocTemplate* ptpl;
  while ((pdoc = DocList.Next(pdoc)) != 0) {
    if (pdoc->IsOpen())
      pdoc->Close();
    delete pdoc;            // removes view, unlinks template and doc manager
    Application->PumpWaitingMessages();  // force out posted MDI child destroy
  }
  for (ptpl=TemplateList; ptpl != 0 ; ptpl = ptpl->NextTemplate) {
    if (ptpl->RefCnt & 0x8000)  // skip over statics
      ptpl->DocManager = 0;
    else
      delete ptpl;
  }
  *TemplateHead = TemplateList;  // restore for next DocManager
}

TDocument*
TDocManager::FindDocument(const char far* path)
{
  TDocument* pdoc = 0;
  while ((pdoc = DocList.Next(pdoc)) != 0)
    if (path) {
      if (pdoc->GetDocPath() && strcmp(pdoc->GetDocPath(), path) == 0)
        break;
    } else {
      if (pdoc->GetDocPath() == 0)
        break;
    }
  return pdoc;
}

void
TDocManager::PostEvent(int id, TDocument& doc)
{
  TWindow* win = Application->MainWindow;
  if (win && win->HWindow)
    win->SendMessage(WM_OWLDOCUMENT, id, (LPARAM)&doc);
}

void
TDocManager::PostEvent(int id, TView& view)
{
  TWindow* win = Application->MainWindow;
  if (win && win->HWindow)
    win->SendMessage(WM_OWLVIEW, id, (LPARAM)&view);
}

BOOL
TDocManager::EvCanClose()
{
  TDocument* pdoc = 0;
  while ((pdoc = DocList.Next(pdoc)) != 0) {
    if (pdoc->CanClose() == FALSE)  // normally calls back to FlushDoc()
      return FALSE;
  }
  return TRUE;
}

void
TDocManager::EvPreProcessMenu(HMENU fmenu)
{
  if (Mode & dmMenu) {
    HMENU menu = ::Module->LoadMenu(IDM_DOCMANAGERFILE);
    char buf[40];
    Application->LoadString(IDS_DOCMANAGERFILE, buf, sizeof(buf));
    if (menu) {
      if (Mode & dmNoRevert)
        ::DeleteMenu(menu, CM_FILEREVERT, MF_BYCOMMAND);
      ::DeleteMenu(fmenu, 0, MF_BYPOSITION);
      ::InsertMenu(fmenu, 0, MF_BYPOSITION|MF_POPUP, (UINT)menu, buf);
    }
  }
}

BOOL
TDocManager::FlushDoc(TDocument& doc)
{
  while (doc.IsDirty()) {
    switch(PostDocError(doc, IDS_DOCCHANGED, MB_YESNOCANCEL))
    {
      case IDYES:
        if (doc.GetDocPath() == 0) {
          TDocTemplate* tpl;
          if ((tpl = SelectAnySave(doc, FALSE))==0)
            continue;
          if (tpl != doc.Template)
            doc.SetTemplate(tpl);
        }
        if (doc.Commit())
          return TRUE;
        continue;

      case IDNO:
        if (doc.Revert(TRUE))
          return TRUE;
        return FALSE;

      case IDCANCEL:
        return FALSE;
    }
  }
  return TRUE;
}

TDocument*
TDocManager::GetCurrentDoc()
{
  TDocument* doc = 0;
  HWND hwnd = TWindow::GetFocus();

  while ((doc = DocList.Next(doc)) != 0 && !doc->HasFocus(hwnd))
    ;
  return doc;
}

//
// event handlers
//
void
TDocManager::CmEnableNew(TCommandEnabler& hndlr)
{
  hndlr.Enable(TemplateList != 0);
}

void
TDocManager::CmFileNew()
{
  CreateAnyDoc(0, dtNewDoc);
}

void
TDocManager::CmEnableOpen(TCommandEnabler& hndlr)
{
  hndlr.Enable(TemplateList != 0);
}

void
TDocManager::CmFileOpen()
{
  CreateAnyDoc(0, 0);
}

void
TDocManager::CmEnableClose(TCommandEnabler& hndlr)
{
  hndlr.Enable(GetCurrentDoc() != 0);
}

void
TDocManager::CmFileClose()
{
  TDocument* doc;

  if ((doc = GetCurrentDoc()) == 0)
    return;
  if (doc->CanClose() == FALSE)  // normally calls back to FlushDoc()
    return;
  if (!doc->Close())
    PostDocError(*doc, IDS_UNABLECLOSE);
  else
    delete doc;
}

void
TDocManager::CmEnableSaveAs(TCommandEnabler& hndlr)
{
  TDocument* doc = GetCurrentDoc();
  hndlr.Enable(doc != 0);
}

void
TDocManager::CmFileSaveAs()
{
  TDocument* doc;
  TDocTemplate* tpl;

  if ((doc = GetCurrentDoc()) == 0)
    return;
  if ((tpl = SelectAnySave(*doc, FALSE)) == 0)
    return;
  if (tpl != doc->Template)
    doc->SetTemplate(tpl);       // replace existing template
  doc->Commit(TRUE);             // force rewrite to new path
}

void
TDocManager::CmEnableSave(TCommandEnabler& hndlr)
{
  TDocument* doc = GetCurrentDoc();
  hndlr.Enable(doc && (doc->IsDirty() || (Mode & dmSaveEnable)));
}

void
TDocManager::CmFileSave()
{
  TDocument* doc;

  if ((doc = GetCurrentDoc()) == 0)
    return;
  if (doc->GetDocPath() == 0) {
    CmFileSaveAs();
    return;
  }
  if (!(Mode & dmSaveEnable) && !doc->IsDirty()){
    PostDocError(*doc, IDS_NOTCHANGED);
    return;
  }
  doc->Commit();  // should force write here?
}

void
TDocManager::CmEnableRevert(TCommandEnabler& hndlr)
{
  TDocument* doc = GetCurrentDoc();
  hndlr.Enable(doc && doc->IsDirty() && doc->GetDocPath());
}

void
TDocManager::CmFileRevert()
{
  TDocument* doc;

  if ((doc = GetCurrentDoc()) == 0 || !doc->GetDocPath())
    return;
  if (!doc->IsDirty()){
    PostDocError(*doc, IDS_NOTCHANGED);
    return;
  }
  doc->Revert();
}

void
TDocManager::CmEnableCreate(TCommandEnabler& hndlr)
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

UINT
TDocManager::PostDocError(TDocument& doc, UINT sid, UINT choice)
{
  char buf[256];

  if (Application->LoadString(sid, buf, sizeof(buf)) == 0)
    strcpy(buf, "Error: Message not found");  // should throw exception?
  if (choice != MB_OK)
    choice |= MB_ICONQUESTION;
  return Application->MainWindow->MessageBox(buf, doc.GetTitle(), choice);
}

//
//  CreateAnyDoc - selects from list of attached non-hidden doc templates
//
TDocument*
TDocManager::CreateAnyDoc(LPCSTR path, long flags)
{
  TDocTemplate* ptpl;
  TDocument* doc;
  char filepath[256];
  int index;
  TDocTemplate* tpllist[40];
  int tplcount = 0;

  // compose list of visible templates
  for (ptpl=TemplateList; ptpl; ptpl=ptpl->NextTemplate) {
    if (ptpl->IsVisible() &&
        !(ptpl->IsFlagSet(dtReadOnly) && (flags & dtNewDoc)))
      tpllist[tplcount++] = ptpl;
  }
  if (!tplcount)
    return 0;         // no usable templates

  if (flags & dtNewDoc) {  // creat empty doc from any registered template
    index = tplcount==1 ? 1 : SelectDocType(tpllist, tplcount);
  } else {           // select doc using filters from all registered templates
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

  if ((Mode & dmSDI) && (doc=DocList.Next(0)) != 0) {  // one at a time if SDI
    if (doc->CanClose() == FALSE)        // normally calls back to FlushDoc()
      return 0;
    if (!doc->Close()) {
      PostDocError(*doc, IDS_UNABLECLOSE);
      return 0;
    }
    delete doc;
  }
  return ptpl->CreateDoc(filepath, flags);
}

//
//  SelectAnySave - selects from registered templates supporting this doc
//
TDocTemplate*
TDocManager::SelectAnySave(TDocument& doc, BOOL samedoc)
{
  TDocTemplate* ptpl;
  char filepath[256];
  int index;
  TDocTemplate* tpllist[40];
  int tplcount;

  if (!TemplateList)
    return 0;   // if no templates are registered
  for (tplcount=0, ptpl=TemplateList; ptpl; ptpl=ptpl->NextTemplate) {
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
  index = SelectDocPath(tpllist, tplcount, filepath, sizeof(filepath),
                        dtNoReadOnly, TRUE);
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
TDocManager::CreateAnyView(TDocument& doc, long flags)
{
  const int MaxViewCount = 25;
  TDocTemplate* tplList[MaxViewCount];
  int tplCount;
  TDocTemplate* ptpl;
  int index;
  LPCSTR viewName;

  for (ptpl=TemplateList, tplCount=0; ptpl != 0; ptpl = ptpl->NextTemplate) {
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
  return ptpl->CreateView(doc, flags); // call virtual create function
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
  for (ptpl=TemplateList; ptpl != 0; ptpl = ptpl->NextTemplate) {
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
      if (ptpl) {  // if static templates available
        is >> *ptpl;       // update static template data
        ptpl = o->GetNextTemplate(ptpl);
      } else {    // have run out of static templates
        char tbuf[sizeof(TDocTemplate)];  // sink for unused template data
        memset(tbuf,0,sizeof(tbuf));      // force static flag off
        is >> *(TDocTemplate*)tbuf;
      }
    } else {     // if dynamic template, object will be constructed
      TModule* module;
      is >> module;
      is >> ptpl;
      ptpl->SetModule(module);
      o->AttachTemplate(*ptpl);
    }
  }
    
  int count;
  is >> count;     // document count
  while (count--) {
    TDocument*  pdoc;
    is >> pdoc;
    pdoc->SetDocManager(*o);  // inserts into properly into list
  }

  o->Application = GetApplicationObject();
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
    } else {
      os << ptpl->GetModule();  // write template's module pointer first
      os << ptpl;               // write pointer to static template
    }
  }
  os << -1;   // template list terminator  

  TDocument* pdoc = 0;
  int count;
  for (count = 0; (pdoc = o->DocList.Next(pdoc))!=0; count++) ;
  os << count;

  // must write documents out in order created, i.e. from end of list forward
  while (count) {
    int i = count--;
    for (pdoc = 0; i--; pdoc = o->DocList.Next(pdoc)) ;
    os << pdoc;
  }
}

IMPLEMENT_ABSTRACT_STREAMABLE(TDocTemplate);

void*
TDocTemplate::Streamer::Read(ipstream& is, uint32 /* version */) const
{
  TDocTemplate* o = GetObject();
  BOOL wasStatic = o->IsStatic();  // test in case dummy template passed
  is >> o->RefCnt;  // need to set back to 1 if doc attach increments!!?
  is >> o->Flags;
  if (o->IsStatic()) {
    delete o->Description;
    delete o->FileFilter;
    delete o->Directory;
    delete o->DefaultExt;
  }
  o->Description = is.freadString();
  o->FileFilter  = is.freadString();
  o->Directory   = is.freadString();
  o->DefaultExt  = is.freadString();
  if (o->IsStatic() && !wasStatic) {  // dummy template passed as sink
    delete o->Description;
    delete o->FileFilter;
    delete o->Directory;
    delete o->DefaultExt;
  }
  return o;
}

void
TDocTemplate::Streamer::Write(opstream& os) const
{
  TDocTemplate* o = GetObject();
  os << o->RefCnt;
  os << o->Flags;
  os.fwriteString(o->Description);
  os.fwriteString(o->FileFilter);
  os.fwriteString(o->Directory);
  os.fwriteString(o->DefaultExt);
}

#endif

