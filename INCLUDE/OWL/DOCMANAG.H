//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Definition of class TDocManager
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
#if !defined(OWL_OPENSAVE_H)
# include <owl/opensave.h>
#endif

//
// Class modifier that can be used for docview classes that may be in a dll
//
#define _DOCVIEWCLASS _USERCLASS

//
// Definitions of dmXxx document manager operational mode flags
//
const int dmSDI        = 0x0001;  // Does not support multiple open documents
const int dmMDI        = 0x0002;  // Supports multiple open documents
const int dmMenu       = 0x0004;  // Set IDs for file menu
const int dmSaveEnable = 0x0010;  // Enable FileSave even if doc is unmodified
const int dmNoRevert   = 0x0020;  // Disable FileRevert menu item

//
// Flags which are stripped off when invoking Open/Save dialogs [See
// SelectDocPath method for more information ]
//
const long dtProhibited = OFN_ENABLEHOOK | 
                          OFN_HIDEREADONLY |
                          OFN_ENABLETEMPLATE | 
                          OFN_ALLOWMULTISELECT | 
                          OFN_ENABLETEMPLATEHANDLE;

//
// Definitions of dnXxx document/view message notifications
//
enum {
  dnCreate,                 // New document or view has been created
  dnClose,                  // Document or view has been closed
  dnRename                  // Document has been renamed
};

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// Class TDocManager
// ~~~~~ ~~~~~~~~~~~
class _OWLCLASS TDocManager : virtual public TEventHandler,
                              virtual public TStreamableBase {
  public:
    TDocManager(int mode, TApplication* app,
                TDocTemplate*& templateHead = ::DocTemplateStaticHead);
    virtual ~TDocManager();

    // Retrieve template info: count, list or descriptions
    //
    int                   GetTemplateCount(TDocument* ofDocType = 0, 
                                           TView* ofViewType = 0);
    virtual int           GetNewTemplates(TDocTemplate** tplList, int size, 
                                          bool newDoc);
    virtual int           GetSaveTemplates(TDocTemplate** tplList, int size,
                                           TDocument& doc, bool sameDoc);
    virtual int           GetViewTemplates(TDocTemplate** tplList, int size,
                                           TDocument& doc);
    virtual int           GetTemplateDescription(TDocTemplate** tpllist, 
                                                 int tplcount, char* buff = 0, 
                                                 int size = 0);

    // Create (construct & initialize) document and views
    //
    virtual TDocument*    CreateAnyDoc(const char far* path, long flags = 0);
    TDocument*            CreateDoc(TDocTemplate* tpl, const char far* path,
                                    TDocument* parent=0, long flags=0);
    TDocument*            InitDoc(TDocument* doc, const char far* path, 
                                  long flags);

    virtual TView*        CreateAnyView(TDocument& doc,long flags = 0);
    TView*                CreateView(TDocument& doc, TDocTemplate* tpl=0);

    // Save document
    //
    bool                  SelectSave(TDocument& doc);
    virtual TDocTemplate* SelectAnySave(TDocument& doc, bool samedoc = true);
    virtual bool          FlushDoc(TDocument& doc); // Attempt to update changes

    // Find related template or document 
    //
    virtual TDocTemplate* MatchTemplate(const char far* path);
    virtual TDocument*    GetCurrentDoc();  // Return doc with focus, else 0
    TDocument*            FindDocument(const char far* path); // 0 if not found
    static  bool          IsAMatch(const char far* path, const char far* fltr);

    // Accessors
    //
    TApplication*         GetApplication() const;
    int&                  GetUntitledIndex();
    TDocTemplate*         GetTemplateList() const;
    TDocument::List&      GetDocList();      

    // Check Document Manager's state
    //
    bool                  IsFlagSet(int flag) const;
    int                   GetModeFlags() const;

    // Manipulate template List [add, remove, etc]
    //
    TDocTemplate*         GetNextTemplate(TDocTemplate* tpl) const;
    void                  RefTemplate(TDocTemplate&);    // add template ref
    void                  UnRefTemplate(TDocTemplate&);  // drop template ref
    void                  DeleteTemplate(TDocTemplate&); // remove from list
    void                  AttachTemplate(TDocTemplate&); // append to list

    // Primary event handlers, public to allow direct invocation from app
    //
    virtual void          CmFileOpen();
    virtual void          CmFileNew();
    virtual void          CmFileClose();
    virtual void          CmFileSave();
    virtual void          CmFileSaveAs();
    virtual void          CmFileRevert();
    virtual void          CmViewCreate();

    // Overrideable document manager UI functions
    //
    virtual uint          PostDocError(TDocument& doc, uint sid, 
                                       uint choice = MB_OK);
    virtual void          PostEvent(int id, TDocument& doc); // changed doc status
    virtual void          PostEvent(int id, TView& view);    // changed view status
    virtual void          UpdateFileMenu(TMenu& menubar);

    // Delegated methods from TApplication
    //
    void                  EvPreProcessMenu(HMENU hMenu);
    bool                  EvCanClose();
    void                  EvWakeUp();

#if defined(OWL2_COMPAT)
    TDocManager(int mode, TDocTemplate*& templateHead=::DocTemplateStaticHead);
#endif

  protected:

    // Index of last untitled document
    //
    int                   UntitledIndex;

    // Next ID to be assigned to a view
    //
    uint                  NextViewId;  

    // Helper routine used by constructor(s)
    //
    void                  Init(int mode, TApplication* app, 
                               TDocTemplate*& templateHead);

    // Overrideable document manager UI functions
    //
    virtual int           SelectDocType(TDocTemplate** tpllist,
                                        int tplcount);
    virtual int           SelectDocPath(TDocTemplate** tpllist, int tplcount,
                                        char far* path, int buflen, 
                                        long flags, bool save=false, TDocument* doc = NULL);
    virtual int           SelectViewType(TDocTemplate** tpllist, 
                                         int tplcount);

    // Overrideable method invoked just before DocManager creates a document
    //
    virtual bool          CreatingDoc(TDocTemplate* tpl);

  public_data:

    // List of attached documents
    //
    TDocument::List       DocList;      

  private:
    int                   Mode;         // Mode flags: dmxxx
    TDocTemplate*         TemplateList; // Chained list of doc templates
    TApplication*         Application;  // Current application
    TDocTemplate**        TemplateHead; // Saved pointer Template Head

    // Command enabler handlers
    //
    virtual void          CeFileNew(TCommandEnabler& ce);
    virtual void          CeFileOpen(TCommandEnabler& ce);
    virtual void          CeFileSave(TCommandEnabler& ce);
    virtual void          CeFileSaveAs(TCommandEnabler& ce);
    virtual void          CeFileRevert(TCommandEnabler& ce);
    virtual void          CeFileClose(TCommandEnabler& ce);
    virtual void          CeViewCreate(TCommandEnabler& ce);

#if defined(OWL2_COMPAT)
    static bool           SelectSave(TDocTemplate* tpl, TDocument& doc);
    static TView*         InitView(TView* view);
    static TDocument*     InitDoc(TDocTemplate& tpl, TDocument* doc,
                                  const char far* path, long flags);
#endif

  DECLARE_RESPONSE_TABLE(TDocManager);
  DECLARE_STREAMABLE(_OWLCLASS, TDocManager, 1);

  friend class TDocTemplate;  // access to template list, PostEvent()
  friend class TDocument;     // access to Application
};

//
// class TDvOpenSaveData
// ~~~~~ ~~~~~~~~~~~~~~~
// TDvOpenSaveData encapsulates the information used to initialized
// the Open or Save As dialog box by ObjectWindows' DocView manager.
// Besides the typically 'OPENFILENAME' related information, it also
// provides methods to retrieve the template list and template count
// of the current Document Manager.
//
class _OWLCLASS TDvOpenSaveData : public TOpenSaveDialog::TData {
  public:
    TDvOpenSaveData(uint32 flags, char far* filter, 
                    const char far* initialDir, const char far* defExt, 
                    int filterIndex, TDocTemplate **tmplList, int tmplCount);

    TDocTemplate**  GetTmplList() const;
    int             GetTmplCount() const;

  protected:
    int             TmplCount; // Number of Doc/View templates in 'TmplList'
    int             TmplIndex; // Index of the default template.
    TDocTemplate**  TmplList;  // List of Doc/View templates displayed in
                               // Common Dialog during a File|Open or
                               // File|SaveAs operation.
};

//
// class TDvOpenSaveDataOwner
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~
// TDvOpenSaveDataOwner is a mixin class used by the DocView encapsulation
// of the FileOpen and FileSave dialogs. It provides accessors to the 
// template list and template count used by these dialogs. It purpose is to 
// provide an  encapsulation of code shared by the TDvFileOpenDialog an 
// TDvFileSaveDialog class.
//
class _OWLCLASS TDvOpenSaveDataOwner {
  public:
    TDocTemplate**    GetTmplList() const;
    int               GetTmplCount() const;

  protected:
    TDvOpenSaveDataOwner(TDvOpenSaveData& data);
    TDvOpenSaveData&  DvData;
};


//
// class TDvFileOpenDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~
// TDvFileOpenDialog encapsulates the FileOpen dialog used by the
// DocView manager. It enhances the standard ObjectWindows TFileOpenDialog 
// by providing logic to update the dialog as the user switches amoung
// file types.
//
class _OWLCLASS TDvFileOpenDialog : public TFileOpenDialog, public TDvOpenSaveDataOwner {
  public:
    TDvFileOpenDialog(TWindow* parent, TDvOpenSaveData& data,
                      const char* title = 0);
  protected:
    bool              DialogFunction(uint message, TParam1, TParam2);
};

//
// class TDvFileSaveDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~
// TDvFileSaveDialog encapsulates the FileSave dialog used by the
// DocView manager. It enhances the standard ObjectWindows TFileSaveDialog 
// by providing logic to update the dialog as the user switches amoung
// file types.
//
class _OWLCLASS TDvFileSaveDialog : public TFileSaveDialog, public TDvOpenSaveDataOwner {
  public:
    TDvFileSaveDialog(TWindow* parent, TDvOpenSaveData& data,
                      const char* title = 0);
  protected:
    bool              DialogFunction(uint message, TParam1, TParam2);
};

#define EV_WM_PREPROCMENU\
  {WM_OWLPREPROCMENU, 0, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_HMENU_Sig(&TMyClass::EvPreProcessMenu)}

#define EV_WM_CANCLOSE\
  {WM_OWLCANCLOSE, 0, (TAnyDispatcher)::B_Dispatch,\
   (TMyPMF)B_Sig(&TMyClass::EvCanClose)}

#define EV_WM_WAKEUP\
  {WM_OWLWAKEUP, 0, (TAnyDispatcher)::v_Dispatch,\
   (TMyPMF)v_Sig(&TMyClass::EvWakeUp)}

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Increment the reference count of a DocView template to indicate that it's
// currently in use by the DocManager.
//
inline void TDocManager::RefTemplate(TDocTemplate& tpl)
{
  ++tpl.RefCnt;
}

//
// Decrement the reference count of a DocView template.
// NOTE: The template is deleted when the reference count reaches zero.
//
inline void TDocManager::UnRefTemplate(TDocTemplate& tpl)
{
  if (--tpl.RefCnt == 0)
    delete &tpl;
}

//
// Returns the TApplication* object associated with this DocManager.
//
inline TApplication* TDocManager::GetApplication() const
{
  return Application;
}

//
// Returns true if the specified flag is currently enabled by the
// DocManager or false otherwise.
//
inline bool TDocManager::IsFlagSet(int flag) const
{
  return (Mode & flag) != 0;
}

//
// Returns variable representing the dtXXXX flags [see DOCTPL.H for list] 
// of the DocManager.
//
inline int TDocManager::GetModeFlags() const
{
  return Mode;
}

//
// Returns template following specified template - Pass in '0' as
// parameter to get pointer to the template list.
//
inline TDocTemplate* TDocManager::GetNextTemplate(TDocTemplate* tpl) const
{
  return tpl ? tpl->GetNextTemplate() : TemplateList;
}

//
// Returns the index to be used by an untitled document.
// NOTE: Untitled indices start at '0' and are incremented
//       after a new document is created.
//
inline int& TDocManager::GetUntitledIndex()
{
  return UntitledIndex;
}

//
// Returns a pointer to the list of DocView templates currently
// registered with the DocManager.
//
inline TDocTemplate* TDocManager::GetTemplateList() const
{
  return TemplateList;
}

//
// Returns a List of document currently managed by the DocManager.
//
inline TDocument::List& TDocManager::GetDocList()
{
  return DocList;
}

//
// Returns the list of templates displayed in the Open or Save
// dialogs used by the DocManager.
//
inline TDocTemplate** TDvOpenSaveData::GetTmplList() const
{
  return TmplList;
}

//
// Returns the number of DocView templates currently displayed in the
// Open or Save dialogs used by the DocManager.
//
inline int TDvOpenSaveData::GetTmplCount() const
{
  return TmplCount;
}

//
// Returns the list of templates displayed in the Open or Save
// dialogs used by the DocManager.
//
inline TDocTemplate** TDvOpenSaveDataOwner::GetTmplList() const
{
  return DvData.GetTmplList();
}

//
// Returns the number of DocView templates currently displayed in the
// Open or Save dialogs used by the DocManager.
//
inline int TDvOpenSaveDataOwner::GetTmplCount() const
{
  return DvData.GetTmplCount();
}

#endif  // OWL_DOCMANAG_H
