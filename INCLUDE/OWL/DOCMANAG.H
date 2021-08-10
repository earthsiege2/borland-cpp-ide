//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   include\owl\docmanag.h
//   Defines classes TDocManager, TDocTemplate, TDocTemplateT<D,V>
//----------------------------------------------------------------------------
#if !defined(__OWL_DOCMANAG_H)
#define __OWL_DOCMANAG_H

#if !defined(__OWL_DOCVIEW_H)
  #include <owl\docview.h>
#endif
#if !defined(__OWL_APPLICAT_H)
  #include <owl\applicat.h>
#endif

#if defined(__DLL__)            // if implementing documents & views in a DLL
# define _DOCVIEWCLASS _export  // force data segment load on method entry
#else
# define _DOCVIEWCLASS
#endif

#if defined(__DLL__) && !defined(__WIN32__) // templates in a DLL
# define _DOCVIEWENTRY _export
#else
# define _DOCVIEWENTRY
#endif

extern TDocTemplate* DocTemplateStaticHead;// templates constructed before app

//
// definitions of dm??? document manager operational mode flags
//
const int dmSDI        = 0x0001; // does not support multiple open documents
const int dmMDI        = 0x0002; // supports multiple open documents
const int dmMenu       = 0x0004; // set IDs for file menu
const int dmSaveEnable = 0x0010; // enable FileSave even if doc is unmodified
const int dmNoRevert   = 0x0020; // disable FileRevert menu item

//
// definitions of dt??? document/view flags for templates and CreateDoc()
//
const long dtNewDoc     = 0x80000000L; // create new document, no path used
const long dtAutoDelete = 0x40000000L; // delete doc when last view is deleted
const long dtNoAutoView = 0x20000000L; // no automatic create of default view
const long dtSingleView = 0x10000000L; // only a single view per document
const long dtAutoOpen   = 0x08000000L; // open document upon creation
const long dtUpdateDir  = 0x04000000L; // syncronize directory with dialog dir
const long dtHidden     = 0x02000000L; // hide template from user selection
const long dtSelected   = 0x01000000L; // indicates template last selected

//
// flags defined by Windows in <commdlg.h> - use the low order 17 bits
//
const long dtReadOnly       = OFN_READONLY;      // initial check readonly box
const long dtOverwritePrompt= OFN_OVERWRITEPROMPT;  // prompt before overwrite
const long dtHideReadOnly   = OFN_HIDEREADONLY;     // no show readonly box
const long dtPathMustExist  = OFN_PATHMUSTEXIST;    // path must be valid
const long dtFileMustExist  = OFN_FILEMUSTEXIST;    // file must exist
const long dtCreatePrompt   = OFN_CREATEPROMPT;     // prompt before create
const long dtNoReadOnly     = OFN_NOREADONLYRETURN; // return writable file
const long dtNoTestCreate   = OFN_NOTESTFILECREATE; // skip create tests

const long dtProhibited = OFN_ALLOWMULTISELECT | OFN_ENABLEHOOK
                          | OFN_ENABLETEMPLATE | OFN_ENABLETEMPLATEHANDLE;

//
// definitions of dn??? document/view message notifications
//
enum{
  dnCreate,                 // new document or view has been created
  dnClose                   // document or view has been closed
};

class _OWLCLASS TDocManager;

//
//  class TDocTemplate
//  ----- ------------
//
class _OWLCLASS TDocTemplate : public TStreamableBase {
  public:
    virtual TDocument* CreateDoc(const char far* path, long flags = 0) = 0;
    virtual TView*     CreateView(TDocument& doc, long flags = 0) = 0;
    virtual TDocument* IsMyKindOfDoc(TDocument& doc) = 0;
    virtual TView*     IsMyKindOfView(TView& view) = 0;
    virtual const char far* GetViewName() = 0;
    BOOL               SelectSave(TDocument& doc);
    BOOL               IsVisible();     // displayable in file select dialogs
    virtual TDocTemplate* Clone(TModule* module,
                                TDocTemplate*& phead=DocTemplateStaticHead)=0;
    TDocManager*    GetDocManager() const {return DocManager;}
    void            SetDocManager(TDocManager* dm) {DocManager = dm;}
    const char far* GetFileFilter() const {return FileFilter;}
    void            SetFileFilter(const char far*);
    const char far* GetDescription() const {return Description;}
    void            SetDescription(const char far*);
    const char far* GetDirectory() const {return Directory;}
    void            SetDirectory(const char far*);
    void            SetDirectory(const char far*, int len);
    const char far* GetDefaultExt() const {return DefaultExt;}
    void            SetDefaultExt(const char far*);
    long            GetFlags() const {return Flags;}
    BOOL            IsFlagSet(long flag) {return (Flags & flag) != 0;}
    void            SetFlag(long flag)  {Flags |= flag;}
    void            ClearFlag(long flag){Flags &= ~flag;}
    BOOL            IsStatic() {return (RefCnt & 0x8000) != 0;}
    TModule*&       GetModule() {return *ModulePtr;}
    void            SetModule(TModule* module){ModuleDeref = module;
                                              ModulePtr = &ModuleDeref;}

  protected:                // called only from parameterized subclass
    TDocTemplate(const char far* desc, const char far* filt,
                 const char far* dir,  const char far* ext, long flags,
                 TModule*& module, TDocTemplate*& phead);
   ~TDocTemplate();
    TDocument* InitDoc(TDocument* doc, const char far* path, long flags);
    TView*     InitView(TView* view);

  private:
    char far* FileFilter;         // file matching pattern
    char far* Description;        // decription to put in list box
    char far* Directory;          // directory path
    char far* DefaultExt;         // default extension
    long  Flags;                  // dt??? bits for dialogs and creation modes
    TDocManager*  DocManager;     // pointer back to document manager
    TDocTemplate* NextTemplate;   // doc template chain link
    int  RefCnt;               // documents attached + 1 if attached to docmgr
    TModule** ModulePtr;          // would be TModule*&, except for streaming
    TModule*  ModuleDeref;        // used only when setting a new module


  DECLARE_ABSTRACT_STREAMABLE (_OWLCLASS,TDocTemplate,1);
  friend class TDocument;   // access to RefCnt
  friend class TDocManager;
};

inline BOOL
TDocTemplate::IsVisible() {
  return (!(Flags & dtHidden) && Description != 0);
}

//
//  class TDocTemplateT<D,V>
//  ----- ------------------
//
template<class D, class V>
class _DOCVIEWENTRY TDocTemplateT : public TDocTemplate {
  public:
    TDocTemplateT(const char far* filt, const char far* desc,
                  const char far* dir, const char far* ext, long flags = 0,
                  TModule*& module = ::Module,
                  TDocTemplate*& phead = DocTemplateStaticHead);
    TDocTemplateT* Clone(TModule* module,
                         TDocTemplate*& phead = DocTemplateStaticHead);
    D* CreateDoc(const char far* path, long flags=0);
    TView* CreateView(TDocument& doc, long flags=0);
    D* IsMyKindOfDoc(TDocument& doc);  // returns 0 if template can't support
    V* IsMyKindOfView(TView& view);    // returns 0 if template incompatible
    virtual const char far* GetViewName() {return V::StaticName();}

  // explicit expansion of DECLARE_STREAMABLE for use with parameterized class
  // DECLARE_STREAMABLE_FROM_BASE(TDocTemplateT<D,V>);
  #define TEMPLATECLASS TDocTemplateT<D,V>
  DECLARE_CASTABLE;
  DECLARE_STREAMABLE_CTOR(TDocTemplateT);
  DECLARE_STREAMER_FROM_BASE(_OWLCLASS, TEMPLATECLASS, TDocTemplate);
  DECLARE_STREAMABLE_OPS(TEMPLATECLASS);
  #undef TEMPLATECLASS
};

//
//  class TDocManager
//  ----- -----------
//
class _OWLCLASS TDocManager : public TEventHandler, public TStreamableBase {
  public:
    TDocument::List DocList;      // list of attached documents
    TDocManager(int mode,TDocTemplate*& templateHead = DocTemplateStaticHead);
    virtual ~TDocManager();
    virtual TDocument*  CreateAnyDoc(const char far* path, long flags = 0);
    virtual TView*      CreateAnyView(TDocument& doc,long flags = 0);
    virtual TDocTemplate* SelectAnySave(TDocument& doc, BOOL samedoc = TRUE);
    virtual TDocTemplate* MatchTemplate(const char far* path);
    virtual TDocument*  GetCurrentDoc();  // return doc with focus, else 0
    virtual BOOL        FlushDoc(TDocument& doc); // attempt to update changes
    TDocument*          FindDocument(const char far* path); // 0 if not found
    TApplication*       GetApplication() {return Application;}
    BOOL                IsFlagSet(int flag) {return (Mode & flag) != 0;}
    void                RefTemplate(TDocTemplate&);    // add template ref    
    void                UnRefTemplate(TDocTemplate&);  // drop template ref    
    void                DeleteTemplate(TDocTemplate&); // remove from list
    void                AttachTemplate(TDocTemplate&); // append to list
    TDocTemplate*       GetNextTemplate(TDocTemplate* tpl)
                        {return tpl ? tpl->NextTemplate : TemplateList;}

    // primary event handlers, public to allow direct invocation from app
    //
    virtual void CmFileOpen();
    virtual void CmFileNew();
    virtual void CmFileClose();
    virtual void CmFileSave();
    virtual void CmFileSaveAs();
    virtual void CmFileRevert();
    virtual void CmViewCreate();

    // overrideable document manager UI functions
    //
    virtual UINT  PostDocError(TDocument& doc, UINT sid, UINT choice = MB_OK);
    virtual void  PostEvent(int id, TDocument& doc); // changed doc status
    virtual void  PostEvent(int id, TView& view);    // changed view status

    // delegated methods from TApplication
    //
    void EvPreProcessMenu(HMENU hMenu);
    BOOL EvCanClose();

  protected:

    // overrideable document manager UI functions
    //
    virtual int   SelectDocPath(TDocTemplate** tpllist, int tplcount,
                     char far* path, int buflen, long flags, BOOL save=FALSE);
    virtual int   SelectDocType(TDocTemplate** tpllist, int tplcount);
    virtual int   SelectViewType(TDocTemplate** tpllist, int tplcount);

  private:
    //
    // event enabling handlers
    //
    virtual void CmEnableNew(TCommandEnabler& hndlr);
    virtual void CmEnableOpen(TCommandEnabler& hndlr);
    virtual void CmEnableSave(TCommandEnabler& hndlr);
    virtual void CmEnableSaveAs(TCommandEnabler& hndlr);
    virtual void CmEnableRevert(TCommandEnabler& hndlr);
    virtual void CmEnableClose(TCommandEnabler& hndlr);
    virtual void CmEnableCreate(TCommandEnabler& hndlr);

    int           Mode;           // mode flags: dmxxx
    TDocTemplate* TemplateList;   // chained list of doc templates, 0 if none
    TApplication* Application;    // current application, set by constructor
    TDocTemplate** TemplateHead;  // saved pointer to DocTemplateStaticHead

  DECLARE_RESPONSE_TABLE(TDocManager);
  DECLARE_STREAMABLE(_OWLCLASS, TDocManager, 1);
  friend class TDocTemplate;  // access to template list, PostEvent()
  friend class TDocument;     // access to Application
};

//
// inline implementations
//

inline void
TDocManager::RefTemplate(TDocTemplate& tpl)
{
  ++tpl.RefCnt;
}

inline void
TDocManager::UnRefTemplate(TDocTemplate& tpl)
{
  if (--tpl.RefCnt == 0)
    delete &tpl;
}

template<class D, class V> inline
TDocTemplateT<D,V>::TDocTemplateT(const char far* desc, const char far* filt,
                        const char far* dir,  const char far* ext, long flags,
                        TModule*& module, TDocTemplate*& phead)
                  : TDocTemplate(desc, filt, dir, ext, flags, module, phead){}

template<class D, class V> inline TDocTemplateT<D,V>*
TDocTemplateT<D,V>::Clone(TModule* module, TDocTemplate*& phead) {
  TDocTemplateT<D,V>* tpl = new TDocTemplateT<D,V>(GetDescription(), GetFileFilter(),
                                GetDirectory(), GetDefaultExt(),
                                GetFlags(), GetModule(), phead);
  tpl->SetModule(module);
  return tpl;
}

template<class D, class V> inline D*
TDocTemplateT<D,V>::CreateDoc(const char far* path, long flags) {
  return (D*)InitDoc(new D(0), path, flags);
}

template<class D, class V> inline TView*
TDocTemplateT<D,V>::CreateView(TDocument& doc, long flags) {
  return (V*)InitView(new V((D&)doc));
}

#define DEFINE_DOC_TEMPLATE_CLASS(docClass, viewClass, tplClass) \
  typedef TDocTemplateT<docClass, viewClass> tplClass;           \
  IMPLEMENT_STREAMABLE_FROM_BASE(tplClass, TDocTemplate);        \
  docClass* tplClass::IsMyKindOfDoc(TDocument& doc)              \
  {                                                              \
    return TYPESAFE_DOWNCAST(&doc, docClass);                    \
  }                                                              \
  viewClass* tplClass::IsMyKindOfView(TView& view)               \
  {                                                              \
    return TYPESAFE_DOWNCAST(&view, viewClass);                  \
  }

#define EV_WM_PREPROCMENU\
  {WM_OWLPREPROCMENU, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_HMENU_Sig(&TMyClass::EvPreProcessMenu)}

#define EV_WM_CANCLOSE\
  {WM_OWLCANCLOSE, 0, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)B_Sig(&TMyClass::EvCanClose)}

#endif  // __OWL_DOCMANAG_H
