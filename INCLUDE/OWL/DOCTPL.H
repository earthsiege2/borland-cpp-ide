//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Defines classes TDocTemplate, TDocTemplateT<D,V>
//----------------------------------------------------------------------------
#if !defined(OWL_DOCTPL_H)
#define OWL_DOCTPL_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif
#if !defined(OSL_LOCALE_H)
# include <osl/locale.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>
#endif

#if defined(_OWLDLL) && defined(__DLL__) && !defined(BI_PLAT_WIN32)
# define _DOCVIEWENTRY __export   // templates in a DLL using DLLs
#else
# define _DOCVIEWENTRY
#endif

class _OWLCLASS TDocTemplate;
class _OWLCLASS TDocManager;
class _OWLCLASS TModule;
class _OWLCLASS TDocument;
class _OWLCLASS TView;

extern TDocTemplate* DocTemplateStaticHead;// templates constructed before app

//
//  class TDocTemplate
//  ----- ------------
//
class _OWLCLASS TDocTemplate : public TRegLink, public TStreamableBase {
  public:
    virtual TDocument* ConstructDoc(TDocument* parent = 0) = 0;
    virtual TView*     ConstructView(TDocument& doc) = 0;
    virtual TDocument* IsMyKindOfDoc(TDocument& doc) = 0;
    virtual TView*     IsMyKindOfView(TView& view) = 0;
    virtual const char far* GetViewName() = 0;
    bool               IsVisible();     // displayable in file select dialogs
    virtual TDocTemplate* Clone(TModule* module,
                                TDocTemplate*& phead=DocTemplateStaticHead)=0;
    TDocManager*    GetDocManager() const {return DocManager;}
    void            SetDocManager(TDocManager* dm) {DocManager = dm;}
    const char far* GetDirectory() const;
    void            SetDirectory(const char far*);
    void            SetDirectory(const char far*, int len);
    TDocTemplate*   GetNextTemplate() const {return (TDocTemplate*)Next;}
    bool            IsFlagSet(long flag) const {return ToBool(GetFlags()&flag);}
    long            GetFlags() const {return Flags;}
    void            SetFlag(long flag);
    void            ClearFlag(long flag);
    bool            IsStatic() {return ToBool(RefCnt & 0x8000);}
    TModule*&       GetModule() {return *ModulePtr;}
    void            SetModule(TModule* module) {ModuleDeref = module;
                                                ModulePtr = &ModuleDeref;}

  protected:                // called only from parameterized subclass
    TDocTemplate(TRegList& regList, TModule*& module, TDocTemplate*& phead);
   ~TDocTemplate();

  private:
    char far* Directory;        // current directory path, 0 until changed
    long      Flags;            // dt??? bits for dialogs and creation modes
    TDocManager*  DocManager;   // pointer back to document manager
    int       RefCnt;           // documents attached + 1 if attached to docmgr
    TModule** ModulePtr;        // would be TModule*&, except for streaming
    TModule*  ModuleDeref;      // used only when setting a new module

  // The following functions are maintained for backward compatability
  // with code generated for versions prior to enhanced document templates
  //
  public:
    virtual TDocument* CreateDoc(const char far* path, long flags = 0) = 0;
    virtual TView*     CreateView(TDocument& doc, long flags = 0) = 0;
    TDocument*         InitDoc(TDocument* doc,const char far* path,long flags);
    TView*             InitView(TView* view);
    bool               SelectSave(TDocument& doc);
    const char far*    GetFileFilter() const;
    const char far*    GetDescription() const;
    const char far*    GetDefaultExt() const;
    void               SetFileFilter(const char far*);
    void               SetDescription(const char far*);
    void               SetDefaultExt(const char far*);

  protected:                // called only from parameterized subclass
    TDocTemplate(const char* desc, const char* filt,
                 const char* dir,  const char* ext, long flags,
                 TModule*& module, TDocTemplate*& phead);
  private:
    static bool       (*SelectSave_)(TDocTemplate* tpl, TDocument& doc);
    static TView*     (*InitView_)(TView* view);
    static TDocument* (*InitDoc_)(TDocTemplate& tpl, TDocument* doc,
                                  const char far* path, long flags);

  DECLARE_ABSTRACT_STREAMABLE(_OWLCLASS, TDocTemplate, 1);
  friend class TDocument;   // access to RefCnt
  friend class TDocManager;
};

//
//  class TDocTemplateT<D,V>
//  ----- ------------------
//
template<class D, class V>
class _DOCVIEWENTRY TDocTemplateT : public TDocTemplate {
  public:
    TDocTemplateT(TRegList& regList, TModule*& module = ::Module,
                  TDocTemplate*& phead = DocTemplateStaticHead);
    TDocTemplateT(const char* filt, const char* desc,
                  const char* dir, const char* ext, long flags = 0,
                  TModule*& module = ::Module,
                  TDocTemplate*& phead = DocTemplateStaticHead);
    TDocTemplateT* Clone(TModule* module,
                         TDocTemplate*& phead = DocTemplateStaticHead);
    D* ConstructDoc(TDocument* parent = 0);
    V* ConstructView(TDocument& doc);
    D* IsMyKindOfDoc(TDocument& doc);  // returns 0 if template can't support
    V* IsMyKindOfView(TView& view);    // returns 0 if template incompatible
    virtual const char far* GetViewName() {return V::StaticName();}

    // The following functions are maintained for backward compatability
    //
    D* CreateDoc(const char far* path, long flags = 0);
    TView* CreateView(TDocument& doc, long flags = 0);

  // explicit expansion of DECLARE_STREAMABLE for use with parameterized class
  // DECLARE_STREAMABLE_FROM_BASE(TDocTemplateT<D,V>);
  //
  #define TEMPLATECLASS TDocTemplateT<D,V>
  DECLARE_CASTABLE;
  DECLARE_STREAMABLE_CTOR(TDocTemplateT);
  DECLARE_STREAMER_FROM_BASE(_DOCVIEWENTRY, TEMPLATECLASS, TDocTemplate);
  DECLARE_STREAMABLE_OPS(TEMPLATECLASS);
  #undef TEMPLATECLASS
};

//----------------------------------------------------------------------------
// Template flags used in reg parameter "docflags"
//

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
const long dtDynRegInfo = 0x00800000L; // reginfo table is dynamic, not static
const long dtSingleUse  = 0x00400000L; // to be registered as single use
const long dtRegisterExt= 0x00200000L; // register extension with this app

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

//----------------------------------------------------------------------------
// inline implementations
//

inline bool
TDocTemplate::IsVisible() {
  return ToBool(!(GetFlags() & dtHidden));
}

inline TDocument*
TDocTemplate::InitDoc(TDocument* doc,const char far* path,long flags)
{
  return InitDoc_(*this, doc, path, flags);
}

inline TView*
TDocTemplate::InitView(TView* view)
{
  return InitView_(view);
}

inline bool
TDocTemplate::SelectSave(TDocument& doc)
{
  return SelectSave_(this, doc);
}

template<class D, class V> inline
TDocTemplateT<D,V>::TDocTemplateT(TRegList& regList,
                        TModule*& module, TDocTemplate*& phead)
                  : TDocTemplate(regList, module, phead){}

template<class D, class V> inline
TDocTemplateT<D,V>::TDocTemplateT(const char* desc, const char* filt,
                        const char* dir,  const char* ext, long flags,
                        TModule*& module, TDocTemplate*& phead)
                  : TDocTemplate(desc, filt, dir, ext, flags, module, phead){}

template<class D, class V> inline TDocTemplateT<D,V>*
TDocTemplateT<D,V>::Clone(TModule* module, TDocTemplate*& phead) {
  TDocTemplateT<D,V>* tpl = new TDocTemplateT<D,V>(GetRegList(),
                                                   GetModule(), phead);
  tpl->SetModule(module);
  return tpl;
}

template<class D, class V> inline D*
TDocTemplateT<D,V>::ConstructDoc(TDocument* parent = 0) {
  return new D(parent);
}

template<class D, class V> inline V*
TDocTemplateT<D,V>::ConstructView(TDocument& doc) {
  return new V((D&)doc);
}

template<class D, class V> inline D*
TDocTemplateT<D,V>::CreateDoc(const char far* path, long flags) {
  return (D*)InitDoc(new D(0), path, flags);
}

template<class D, class V> inline TView*
TDocTemplateT<D,V>::CreateView(TDocument& doc, long flags) {
  return (V*)InitView(new V((D&)doc));
}

#if defined(BI_NO_NEW_CASTS)  // cannot use templates with TYPESEAFE_DOWNCAST

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

#else                         // with RTTI, all functions can be templatized

template<class D, class V> D*
TDocTemplateT<D,V>::IsMyKindOfDoc(TDocument& doc)
{
  return dynamic_cast<D*>(&doc);
}

template<class D, class V> V*
TDocTemplateT<D,V>::IsMyKindOfView(TView& view)
{
  return dynamic_cast<V*>(&view);
}

#define DEFINE_DOC_TEMPLATE_CLASS(docClass, viewClass, tplClass) \
  typedef TDocTemplateT<docClass, viewClass> tplClass;           \
  IMPLEMENT_STREAMABLE_FROM_BASE(tplClass, TDocTemplate);

#endif

#endif  // OWL_DOCTPL_H
