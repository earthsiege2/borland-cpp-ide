//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Definition of class TDocTemplate, and class template TDocTemplateT<D,V>
//----------------------------------------------------------------------------
#if !defined(OWL_DOCTPL_H)
#define OWL_DOCTPL_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(WINSYS_REGISTRY_H)
# include <winsys/registry.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

#if defined(_OWLDLL) && defined(BI_APP_DLL) && !defined(BI_PLAT_WIN32)
# define _DOCVIEWENTRY __export   // templates in a DLL using DLLs
#else
# define _DOCVIEWENTRY
#endif

class _OWLCLASS TDocTemplate;
class _OWLCLASS TDocManager;
class _OWLCLASS TModule;
class _OWLCLASS TDocument;
class _OWLCLASS TView;

//
// Templates constructed before app get linked onto this head pointer
//
extern TDocTemplate* DocTemplateStaticHead;

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TDocTemplate
// ~~~~~ ~~~~~~~~~~~~
class _OWLCLASS TDocTemplate : public TRegLink, public TStreamableBase {
  public:
    virtual TDocument*      ConstructDoc(TDocument* parent = 0) = 0;
    virtual TView*          ConstructView(TDocument& doc) = 0;
    virtual TDocument*      IsMyKindOfDoc(TDocument& doc) = 0;
    virtual TView*          IsMyKindOfView(TView& view) = 0;
    virtual const char far* GetViewName() = 0;

    bool                    IsVisible(); // displayable in file select dialogs
    virtual TDocTemplate*   Clone(TModule* module,
                                  TDocTemplate*& phead=DocTemplateStaticHead)=0;

    TDocManager*            GetDocManager() const;
    void                    SetDocManager(TDocManager* dm);
    const char far*         GetDirectory() const;
    void                    SetDirectory(const char far*);
    void                    SetDirectory(const char far*, int len);
    TDocTemplate*           GetNextTemplate() const;
    bool                    IsFlagSet(long flag) const;
    long                    GetFlags() const;
    void                    SetFlag(long flag);
    void                    ClearFlag(long flag);
    bool                    IsStatic() const;
    TModule*&               GetModule();
    void                    SetModule(TModule* module);
    int                     GetRefCount() const;

    const char far*         GetFileFilter() const;
    const char far*         GetDescription() const;
    const char far*         GetDefaultExt() const;
    void                    SetFileFilter(const char far*);
    void                    SetDescription(const char far*);
    void                    SetDefaultExt(const char far*);


  protected:                // Called only from parameterized derived class
    TDocTemplate(TRegList& regList, TModule*& module, TDocTemplate*& phead);
   ~TDocTemplate();

  private:
    char far* Directory;        // Current directory path, 0 until changed
    long      Flags;            // dtXxx bits for dialogs and creation modes
    TDocManager* DocManager;    // Pointer back to document manager
    int       RefCnt;           // Documents attached + 1 if attached to docmgr
    TModule** ModulePtr;        // Would be TModule*&, except for streaming
    TModule*  ModuleDeref;      // Used only when setting a new module

#if defined(OWL2_COMPAT)
  // The following functions are maintained for backward compatability
  // with code generated for versions prior to enhanced document templates
  //
  public:
    virtual TDocument* CreateDoc(const char far* path, long flags = 0) = 0;
    virtual TView*     CreateView(TDocument& doc, long flags = 0) = 0;
    TDocument*         InitDoc(TDocument* doc,const char far* path,long flags);
    TView*             InitView(TView* view);
    bool               SelectSave(TDocument& doc);

  protected:                // Called only from parameterized derived class
    TDocTemplate(const char* desc, const char* filt,
                 const char* dir,  const char* ext, long flags,
                 TModule*& module, TDocTemplate*& phead);
  private:
    static bool       _CALLCNVN (*SelectSave_)(TDocTemplate* tpl, TDocument& doc);
    static TView*     _CALLCNVN (*InitView_)(TView* view);
    static TDocument* _CALLCNVN (*InitDoc_)(TDocTemplate& tpl, TDocument* doc,
                                  const char far* path, long flags);
#endif

  DECLARE_ABSTRACT_STREAMABLE(_OWLCLASS, TDocTemplate, 1);
  friend class TDocument;   // access to RefCnt
  friend class TDocManager;
};

//
// class TDocTemplateT<D,V>
// ~~~~~ ~~~~~~~~~~~~~~~~~~
template<class D, class V>
class _DOCVIEWENTRY TDocTemplateT : public TDocTemplate {
  public:
    TDocTemplateT(TRegList& regList, TModule*& module = ::Module,
                  TDocTemplate*& phead = DocTemplateStaticHead);
    TDocTemplateT(const char* desc, const char* filt,
                  const char* dir, const char* ext, long flags = 0,
                  TModule*& module = ::Module,
                  TDocTemplate*& phead = DocTemplateStaticHead);
    TDocTemplateT* Clone(TModule* module,
                         TDocTemplate*& phead = DocTemplateStaticHead);

    D* ConstructDoc(TDocument* parent = 0);
    V* ConstructView(TDocument& doc);
    D* IsMyKindOfDoc(TDocument& doc);  // Returns 0 if template can't support
    V* IsMyKindOfView(TView& view);    // Returns 0 if template incompatible

    virtual const char far* GetViewName();

#if defined(OWL2_COMPAT)
    // The following functions are maintained for backward compatability
    //
    D*     CreateDoc(const char far* path, long flags = 0);
    TView* CreateView(TDocument& doc, long flags = 0);
#endif

#if !defined(BI_NO_OBJ_STREAMING)
  // Explicit expansion of DECLARE_STREAMABLE for use with parameterized class
  // DECLARE_STREAMABLE_FROM_BASE(TDocTemplateT<D,V>);
  //
  #define TEMPLATECLASS TDocTemplateT<D,V>
  DECLARE_CASTABLE;
  DECLARE_STREAMABLE_CTOR(TDocTemplateT);
  DECLARE_STREAMER_FROM_BASE(_DOCVIEWENTRY, TEMPLATECLASS, TDocTemplate);
  DECLARE_STREAMABLE_OPS(TEMPLATECLASS);
  #undef TEMPLATECLASS
#endif
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Template flags used in reg parameter "docflags"
//

//
// Definitions of dtXxx document/view flags for templates and CreateDoc()
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
// Flags defined by Windows in <commdlg.h> - use the low order 17 bits
//
const long dtReadOnly       = 0x0001; //OFN_READONLY;         // initial check readonly box
const long dtOverwritePrompt= 0x0002; //OFN_OVERWRITEPROMPT;  // prompt before overwrite
const long dtHideReadOnly   = 0x0004; //OFN_HIDEREADONLY;     // no show readonly box
const long dtPathMustExist  = 0x0800; //OFN_PATHMUSTEXIST;    // path must be valid
const long dtFileMustExist  = 0x1000; //OFN_FILEMUSTEXIST;    // file must exist
const long dtCreatePrompt   = 0x2000; //OFN_CREATEPROMPT;     // prompt before create
const long dtNoReadOnly     = 0x8000; //OFN_NOREADONLYRETURN; // return writable file
const long dtNoTestCreate   = 0x10000L;//OFN_NOTESTFILECREATE; // skip create tests;

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline TDocManager* TDocTemplate::GetDocManager() const
{
  return DocManager;
}

//
inline void TDocTemplate::SetDocManager(TDocManager* dm)
{
  DocManager = dm;
}

//
inline TDocTemplate* TDocTemplate::GetNextTemplate() const
{
  return (TDocTemplate*)Next;
}

//
inline bool TDocTemplate::IsFlagSet(long flag) const
{
  return (GetFlags() & flag) != 0;
}

//
inline long TDocTemplate::GetFlags() const
{
  return Flags;
}

//
inline bool TDocTemplate::IsStatic() const
{
  return (RefCnt & 0x8000) != 0;
}

//
inline TModule*& TDocTemplate::GetModule()
{
  return *ModulePtr;
}

//
// Return the number of reference count of the template.
// NOTE: The reference count of static templates has the high bit set.
//
inline int TDocTemplate::GetRefCount() const
{
  return RefCnt;
}

//
inline void TDocTemplate::SetModule(TModule* module)
{
  ModuleDeref = module;
  ModulePtr = &ModuleDeref;
}

//
inline bool
TDocTemplate::IsVisible()
{
  return (GetFlags() & dtHidden) == 0;
}

//
template<class D, class V> inline
TDocTemplateT<D,V>::TDocTemplateT(TRegList& regList, TModule*& module,
                                  TDocTemplate*& phead)
:
  TDocTemplate(regList, module, phead)
{
}

//
template<class D, class V> inline
TDocTemplateT<D,V>::TDocTemplateT(const char* desc, const char* filt,
                        const char* dir,  const char* ext, long flags,
                        TModule*& module, TDocTemplate*& phead)
:
  TDocTemplate(desc, filt, dir, ext, flags, module, phead)
{
}

//
template<class D, class V> inline TDocTemplateT<D,V>*
TDocTemplateT<D,V>::Clone(TModule* module, TDocTemplate*& phead)
{
  TDocTemplateT<D,V>* tpl = new TDocTemplateT<D,V>(GetRegList(),
                                                   GetModule(), phead);
  tpl->SetModule(module);
  return tpl;
}

#if !defined(BI_COMP_MSC)  
//
// 'Factory' method to create a new document of type 'D' using the specified
// parameter as the parent document.
//
template<class D, class V> inline D*
TDocTemplateT<D,V>::ConstructDoc(TDocument* parent = 0)
{
  return new D(parent);
}
#endif

//
// 'Factory' method to create a new view of type 'V' from the specified
// document parameter.
//
template<class D, class V> inline V*
TDocTemplateT<D,V>::ConstructView(TDocument& doc)
{
  return new V((D&)doc);
}

//
template<class D, class V> inline const char far*
TDocTemplateT<D,V>::GetViewName()
{
  return V::StaticName();
}

//----------------------------------------------------------------------------

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

//----------------------------------------------------------------------------
#if defined(OWL2_COMPAT)

//
inline TDocument*
TDocTemplate::InitDoc(TDocument* doc, const char far* path, long flags)
{
  return InitDoc_(*this, doc, path, flags);
}

//
inline TView*
TDocTemplate::InitView(TView* view)
{
  return InitView_(view);
}

//
inline bool
TDocTemplate::SelectSave(TDocument& doc)
{
  return SelectSave_(this, doc);
}

//
template<class D, class V> inline D*
TDocTemplateT<D,V>::CreateDoc(const char far* path, long flags)
{
  return (D*)InitDoc(new D((TDocument*)0), path, flags);
}

//
template<class D, class V> inline TView*
TDocTemplateT<D,V>::CreateView(TDocument& doc, long /*flags*/)
{
  return (V*)InitView(new V((D&)doc));
}
#endif  // defined(OWL2_COMPAT)

#endif  // OWL_DOCTPL_H
