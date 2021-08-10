//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Defines class TDocManager
//----------------------------------------------------------------------------
#if !defined(OWL_DOCMANAG_H)
#define OWL_DOCMANAG_H

#if !defined(OWL_DOCVIEW_H)
# include <owl/docview.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_DOCTPL_H)
# include <owl/doctpl.h>
#endif

#define _DOCVIEWCLASS _USERCLASS
extern TDocTemplate* DocTemplateStaticHead; // Templates constructed before app

//
// definitions of dm??? document manager operational mode flags
//
const int dmSDI        = 0x0001; // does not support multiple open documents
const int dmMDI        = 0x0002; // supports multiple open documents
const int dmMenu       = 0x0004; // set IDs for file menu
const int dmSaveEnable = 0x0010; // enable FileSave even if doc is unmodified
const int dmNoRevert   = 0x0020; // disable FileRevert menu item

const long dtProhibited = OFN_ALLOWMULTISELECT | OFN_ENABLEHOOK
                          | OFN_ENABLETEMPLATE | OFN_ENABLETEMPLATEHANDLE;

//
// definitions of dn??? document/view message notifications
//
enum {
  dnCreate,                 // new document or view has been created
  dnClose                   // document or view has been closed
};

//
//  class TDocManager
//  ----- -----------
//
class _OWLCLASS TDocManager : public TEventHandler, public TStreamableBase {
  public:
    TDocument::List DocList;      // list of attached documents

    TDocManager(int mode, TDocTemplate*& templateHead = ::DocTemplateStaticHead);
    TDocManager(int mode, TApplication* app,
                TDocTemplate*& templateHead = ::DocTemplateStaticHead);
    virtual ~TDocManager();

    virtual TDocument*  CreateAnyDoc(const char far* path, long flags = 0);
    virtual TView*      CreateAnyView(TDocument& doc,long flags = 0);
    TDocument*          CreateDoc(TDocTemplate* tpl, const char far* path,
                        TDocument* parent=0, long flags=0);
    TView*              CreateView(TDocument& doc);
    TDocument*          InitDoc(TDocument* doc,const char far* path,long flags);
    bool                SelectSave(TDocument& doc);
    virtual TDocTemplate* SelectAnySave(TDocument& doc, bool samedoc = true);
    virtual TDocTemplate* MatchTemplate(const char far* path);
    virtual TDocument*  GetCurrentDoc();  // return doc with focus, else 0
    virtual bool        FlushDoc(TDocument& doc); // attempt to update changes
    TDocument*          FindDocument(const char far* path); // 0 if not found
    TApplication*       GetApplication() {return Application;}
    bool                IsFlagSet(int flag) {return (Mode & flag) != 0;}
    void                RefTemplate(TDocTemplate&);    // add template ref    
    void                UnRefTemplate(TDocTemplate&);  // drop template ref    
    void                DeleteTemplate(TDocTemplate&); // remove from list
    void                AttachTemplate(TDocTemplate&); // append to list
    TDocTemplate*       GetNextTemplate(TDocTemplate* tpl)
                        {return tpl ? tpl->GetNextTemplate() : TemplateList;}

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
    virtual uint  PostDocError(TDocument& doc, uint sid, uint choice = MB_OK);
    virtual void  PostEvent(int id, TDocument& doc); // changed doc status
    virtual void  PostEvent(int id, TView& view);    // changed view status

    // delegated methods from TApplication
    //
    void EvPreProcessMenu(HMENU hMenu);
    bool EvCanClose();
    void EvWakeUp();

  protected:

    // overrideable document manager UI functions
    //
    virtual int   SelectDocPath(TDocTemplate** tpllist, int tplcount,
                     char far* path, int buflen, long flags, bool save=false);
    virtual int   SelectDocType(TDocTemplate** tpllist, int tplcount);
    virtual int   SelectViewType(TDocTemplate** tpllist, int tplcount);

  private:
    //
    // Command enabler handlers
    //
    virtual void CeFileNew(TCommandEnabler& ce);
    virtual void CeFileOpen(TCommandEnabler& ce);
    virtual void CeFileSave(TCommandEnabler& ce);
    virtual void CeFileSaveAs(TCommandEnabler& ce);
    virtual void CeFileRevert(TCommandEnabler& ce);
    virtual void CeFileClose(TCommandEnabler& ce);
    virtual void CeViewCreate(TCommandEnabler& ce);

    int           Mode;           // mode flags: dmxxx
    TDocTemplate* TemplateList;   // chained list of doc templates, 0 if none
    TApplication* Application;    // current application, set by constructor
    TDocTemplate** TemplateHead;  // saved pointer to DocTemplateStaticHead

    // backward compatibility implementation entry points
    // 
    static bool       SelectSave(TDocTemplate* tpl, TDocument& doc);
    static TView*     InitView(TView* view);
    static TDocument* InitDoc(TDocTemplate& tpl, TDocument* doc,
                              const char far* path, long flags);

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

#define EV_WM_PREPROCMENU\
  {WM_OWLPREPROCMENU, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_HMENU_Sig(&TMyClass::EvPreProcessMenu)}

#define EV_WM_CANCLOSE\
  {WM_OWLCANCLOSE, 0, (TAnyDispatcher)::U_Dispatch,\
   (TMyPMF)B_Sig(&TMyClass::EvCanClose)}

#define EV_WM_WAKEUP\
  {WM_OWLWAKEUP, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvWakeUp)}

#endif  // OWL_DOCMANAG_H
