//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//  include\owl\docview.h
//  Defines classes TDocument, TView,TWindowView, TStream,TInStream,TOutStream
//----------------------------------------------------------------------------
#if !defined(__OWL_DOCVIEW_H)
#define __OWL_DOCVIEW_H

#if !defined(__OWL_APPLICAT_H)
  #include <owl\applicat.h>
#endif
#if !defined(__OWL_FRAMEWIN_H)
  #include <owl\framewin.h>
#endif
#if !defined(__COMMDLG_H)
  #include <commdlg.h>
#endif
#include <string.h>
#include <alloc.h>
#if !defined(__WIN32__)
  #if !defined( _OLE2_H_ )
    struct FAR FILETIME {DWORD dwLowDateTime; DWORD dwHighDateTime;};
  #endif
  #include <io.h>
void DateTimeToFileTime(struct date* dosd, struct time* dost, FILETIME FAR* pft);
BOOL FileTimeToDateTime(FILETIME FAR* pft, struct date* dosd, struct time* dost);
int  FormatDateTime(struct date, struct time, void far* dest, int textlen);
#endif
int  FormatFileTime(FILETIME* pft, void far* dest, int textlen);

//
// document open and sharing modes - used in storage and stream constructors
//   note: the bits values are those of file streams, not same as RTL or OLE
//
enum {
  ofParent    = 0,      // use open mode of parent storage
  ofRead      = 0x0001, // ios::in,  open for reading
  ofWrite     = 0x0002, // ios::out, open for writing
  ofReadWrite = (ofRead|ofWrite),
  ofAtEnd     = 0x0004, // ios::ate, seek to eof upon original open
  ofAppend    = 0x0008, // ios::app, append mode: all additions at eof
  ofTruncate  = 0x0010, // ios::trunc, truncate file if already exists
  ofNoCreate  = 0x0020, // ios::nocreate,  open fails if file doesn't exist
  ofNoReplace = 0x0040, // ios::noreplace, open fails if file already exists
  ofBinary    = 0x0080, // ios::binary, binary (not text) file, no CR stripping
  ofIosMask   = 0x00FF, // all of the above bits as used by class ios

  ofTransacted= 0x1000, // STGM_TRANSACTED, supports commit and revert
  ofPreserve  = 0x2000, // STGM_CONVERT, backup old data of same name
  ofPriority  = 0x4000, // STGM_PRIORITY, temporary efficient peeking
  ofTemporary = 0x8000, // STGM_DELETEONRELEASE, delete when destructed
 
  shCompat    = 0x0600, // for non-compliant applications, avoid if possible
  shNone      = 0x0800, // DENY_ALL functionality
  shRead      = 0x0A00, // DENY_WRITE functionality
  shWrite     = 0x0C00, // DENY_READ functionality
  shReadWrite = 0x0E00, // DENY_NONE functionality
  shDefault   = 0,      // use stream implementation default value
  shMask      = (shCompat|shNone|shRead|shWrite)
};
#define PREV_OPEN (ofNoCreate|ofNoReplace)
#define IS_PREV_OPEN(omode) ((omode & PREV_OPEN)==PREV_OPEN)

//
// definitions of vnXxxx view notification event IDs
// event ID's up to vnCustomBase reserved for general doc-view notifications
//
const int vnViewOpened = 1;   // a new view has just been constructed
const int vnViewClosed = 2;   // another view is about to be destructed
const int vnDocOpened  = 3;   // document has just been opened
const int vnDocClosed  = 4;   // document has just been closed
const int vnCommit     = 5;   // document is committing, flush cached changes
const int vnRevert     = 6;   // document has reverted, reload data from doc
const int vnIsDirty    = 7;   // respond TRUE if uncommitted changes present
const int vnIsWindow   = 8;   // respond TRUE if passed HWND is that of view
const int vnCustomBase = 100; // base of document class specific notifications

//
// document and view property access flags
//
const int pfGetText   =  1;   // property accessible as text format
const int pfGetBinary =  2;   // property accessible as native non-text format
const int pfConstant  =  4;   // property is invariant for object instance
const int pfSettable  =  8;   // property settable as native format
const int pfUnknown   = 16;   // property defined but unavailable in object  
const int pfHidden    = 32;   // property should be hidden from normal browse
const int pfUserDef   =128;   // property has been user-defined at run time

class _OWLCLASS TDocManager;
class _OWLCLASS TDocTemplate;
class _OWLCLASS_RTL TStream;
class _OWLCLASS_RTL TInStream;
class _OWLCLASS_RTL TOutStream;
class _OWLCLASS TDocument;
class _OWLCLASS TView;
class _OWLCLASS TMenuDescr;

//
//  class TDocument - abstract base class for document/view management
//  ----- ---------
//
class _OWLCLASS TDocument : public TStreamableBase {
  public:
    enum {
      PrevProperty = 0,
      DocumentClass,     // text
      TemplateName,      // text
      ViewCount,         // int
      StoragePath,       // text
      DocTitle,          // text
      NextProperty,
    };

    class _OWLCLASS List {
      public:
        List() : DocList(0) {}
       ~List() {Destroy();}
        BOOL Insert(TDocument* doc);  // insert new document, fails if there
        BOOL Remove(TDocument* doc);  // remove document, fails if not there
        TDocument* Next(const TDocument* doc); // returns first if doc=0
        void Destroy();               // deletes all documents
      private:
        TDocument* DocList;
    };

    LPVOID        Tag;          // application hook, not used internally
    List          ChildDoc;     // linked child document chain

    TDocument(TDocument* parent = 0);
    virtual ~TDocument();
    virtual TInStream*  InStream  (int mode, LPCSTR strmId=0) {return 0;}
    virtual TOutStream* OutStream (int mode, LPCSTR strmId=0) {return 0;}
    virtual BOOL   Open(int mode, LPCSTR path=0) {return TRUE;}
    virtual BOOL   Close();      // close document, does not delete or detach
    virtual BOOL   Commit(BOOL force=FALSE); // save current data, force write
    virtual BOOL   Revert(BOOL clear=FALSE); // abort changes, no reload if TRUE
    virtual TDocument& RootDocument();
    TDocManager&   GetDocManager() {return *DocManager;}
    void           SetDocManager(TDocManager& dm);
    TDocument*     GetParentDoc() {return ParentDoc;}

    TDocTemplate*  GetTemplate() {return Template;}
    BOOL           SetTemplate(TDocTemplate* tpl);
    virtual BOOL   SetDocPath(LPCSTR path);
    LPCSTR         GetDocPath() {return DocPath;}
    virtual void   SetTitle(LPCSTR title);
    LPCSTR         GetTitle() {return Title;}
    virtual BOOL   IsDirty();           // also queries doc and view hierarchy
    void           SetDirty(BOOL dirty = TRUE){DirtyFlag = dirty;}
    virtual BOOL   IsOpen()                   {return StreamList != 0;}
    virtual BOOL   CanClose();           // returns FALSE if unable to close
    BOOL           HasFocus(HWND hwnd);
    BOOL           NotifyViews(int event, long item=0, TView* exclude=0);
    TView*         QueryViews(int event, long item=0, TView* exclude=0);
    virtual UINT   PostError(UINT sid, UINT choice = MB_OK);

    virtual int    PropertyCount() {return NextProperty-1;}
    virtual int    FindProperty(const char far* name);// return property index
    virtual int    PropertyFlags(int index);          // pfXxxxx bit array
    virtual const char*  PropertyName(int index);     // locale invariant name
    virtual int    GetProperty(int index, void far* dest, int textlen=0);
    virtual BOOL   SetProperty(int index, const void far* src); // native type
    TStream*       NextStream(const TStream* strm);
    TView*         NextView(const TView* view);
    int            GetOpenMode();
    void           SetOpenMode(int mode);

  protected:
    BOOL          DirtyFlag;    // document changed, might not represent views
    virtual void  AttachStream(TStream& strm);// called from TStream constructor
    virtual void  DetachStream(TStream& strm);// called from TStream destructor

  private:
    TDocManager*  DocManager;   // pointer back to document manager
    TDocument*    NextDoc;      // next in linked chain of active documents
    TView*        ViewList;     // head of linked view chain, 0 if no views
    TStream*      StreamList;   // head of linked stream chain, 0 if no streams
    int           OpenMode;     // mode and protection flags
    LPSTR         DocPath;      // path used to open/save document
    LPSTR         Title;        // current document title, 0 if untitled
    TDocument*    ParentDoc;    // parent document, 0 if this is root document
    TDocTemplate* Template;     // template associated with this document

    void   ReindexFrames();          // force view title and index update
    void   AttachView(TView& view);  // called from TView constructor
    BOOL   DetachView(TView& view);  // called from TView destructor
    TView* InitView(TView* view);    // called from template InitView

  DECLARE_ABSTRACT_STREAMABLE (_OWLCLASS,TDocument,1);
  friend class _OWLCLASS TDocTemplate;  // access to InitView()
  friend class _OWLCLASS TView;         // access to AttachView(), DetatchView()
  friend class _OWLCLASS_RTL TStream;   // access to AttachStream(), DetachStream()
  friend class _OWLCLASS TDocManager;
  friend class _OWLCLASS List;          // access to NextDoc
};

//
//  class TStream - abstract base class for storage stream access
//  ----- -------
//

class _OWLCLASS_RTL TStream {
  public:
    TDocument& GetDocument() {return Doc;}
   ~TStream()                {Doc.DetachStream(*this);}
    int        GetOpenMode();
    const char far* GetStreamName();

  protected:
    TDocument& Doc;        // document owning this stream
    TStream* NextStream;   // next stream in linked list of active streams

    TStream(TDocument& doc,     LPCSTR name,       int mode)
                 : Doc(doc), StreamName(name), OpenMode(mode)
              {Doc.AttachStream(*this);}

  private:
    int             OpenMode;
    const char far* StreamName;

  friend class TDocument;
};

//
//  class TInStream - base class for input streams
//  ----- ---------
//
class _OWLCLASS_RTL TInStream : public TStream, public istream {
  public:
    TInStream(TDocument& doc, LPCSTR name, int mode)
               : TStream(doc,        name,     mode), istream() {}
};

//
//  class TOutStream - base class for output streams
//  ----- ---------
//
class _OWLCLASS_RTL TOutStream : public TStream, public ostream {
  public:
    TOutStream(TDocument& doc, LPCSTR name, int mode)
                : TStream(doc,        name,     mode), ostream() {}
};

//
//  class TView - abstract base class for view access from document
//  ----- -----
//
class _OWLCLASS TView : virtual public TEventHandler,
                        virtual public TStreamableBase {
  public:
    enum {
      PrevProperty = 0,
      ViewClass,                  // text
      ViewName,                   // text
      NextProperty,
    };
    LPVOID          Tag;        // application hook, not used internally

    TView(TDocument& doc);
    virtual ~TView();
    TDocument&  GetDocument() {return *Doc;}
    unsigned    GetViewId()   {return ViewId;}
    TMenuDescr* GetViewMenu() {return ViewMenu;} 
    void        SetViewMenu(TMenuDescr* menu);
    BOOL        IsOK() {return ViewId != 0;}  // TRUE if successfully created
    static unsigned GetNextViewId() {return NextViewId;} // next ID to assign

    // must implement, used by template manager for selection
    // static LPCSTR StaticName() {return "name of view";}
    virtual LPCSTR GetViewName()=0;         // return static name of view

    virtual TWindow* GetWindow() {return 0;} // if not derived from TWindow
    virtual BOOL   SetDocTitle(LPCSTR docname, int index) {return FALSE;}

    virtual int    PropertyCount() {return NextProperty - 1;}
    virtual int    FindProperty(const char far* name);// return property index
    virtual int    PropertyFlags(int index);          // pfXxxxx bit array
    virtual const char*  PropertyName(int index);     // locale invariant name
    virtual int    GetProperty(int index, void far* dest, int textlen=0);
    virtual BOOL   SetProperty(int index, const void far* src) {return FALSE;}

  protected:
    TDocument*   Doc;
    void         NotOK() {ViewId = 0;}  // to flag errors in creation
  private:
    TView*       NextView;   // linked view chain, 0 if no more views
    unsigned     ViewId;     // unique ID for this view, used for controls
    TMenuDescr*  ViewMenu;   // menu descriptor specific for this view or 0
    static unsigned NextViewId; // next view ID to be assigned

  DECLARE_ABSTRACT_STREAMABLE (_OWLCLASS,TView,1);
  friend class _OWLCLASS TDocument;   // needs access to NextView
  friend class TDocument::Streamer;   // needs access to NextView
};

//
//  class TWindowView
//  ----- -----------
//
class _OWLCLASS TWindowView : public TWindow, public TView {
  public:
    TWindowView(TDocument& doc, TWindow* parent = 0)
      : TView(doc), TWindow(parent) {}
   ~TWindowView() {}
    static LPCSTR StaticName() {return "Window View";}  // put in resource
    //
    // inherited virtuals from TWindow
    //
    BOOL     CanClose()  {return TWindow::CanClose() && Doc->CanClose();}
    //
    // inherited virtuals from TView
    //
    LPCSTR   GetViewName() {return StaticName();}
    TWindow* GetWindow() {return (TWindow*)this;}
    BOOL     SetDocTitle(LPCSTR docname, int index)
             { return TWindow::SetDocTitle(docname, index); }
  private:
    //
    // event handlers
    //
    BOOL     VnIsWindow(HWND hWnd) {return HWindow == hWnd;}

  DECLARE_RESPONSE_TABLE(TWindowView);
  DECLARE_STREAMABLE (_OWLCLASS, TWindowView,1);
};

//
// View Notification Handler Definitions
//

// Dispatchers passing data in LPARAM and returning BOOL

LRESULT _OWLFUNC
B_long_Dispatch(GENERIC& generic, int (GENERIC::*pmf)(long), WPARAM, LPARAM);
LRESULT _OWLFUNC
B_int_Dispatch(GENERIC& generic, int (GENERIC::*pmf)(int), WPARAM, LPARAM);
LRESULT _OWLFUNC
B_void_Dispatch(GENERIC& generic, int (GENERIC::*pmf)(), WPARAM, LPARAM);
LRESULT _OWLFUNC
B_pointer_Dispatch(GENERIC& generic, int (GENERIC::*pmf)(void*), WPARAM, LPARAM);

//
// handlers for new document and view notifications
//

#define EV_OWLDOCUMENT(id, method)\
  {WM_OWLDOCUMENT, id, (TAnyDispatcher)::v_POINTER_Dispatch,\
   (TMyPMF)v_OWLDOCUMENT_Sig(&TMyClass::method)}

#define EV_OWLVIEW(id, method)\
  {WM_OWLVIEW, id, (TAnyDispatcher)::v_POINTER_Dispatch,\
   (TMyPMF)v_OWLVIEW_Sig(&TMyClass::method)}

#define EV_OWLNOTIFY(id, method)\
  {WM_OWLNOTIFY, id, (TAnyDispatcher)::i_LPARAM_Dispatch,\
   (TMyPMF)B_LPARAM_Sig(&TMyClass::method)}
 
#define EV_VIEWNOTIFY(id, method) \
  {WM_OWLNOTIFY, id, (TAnyDispatcher)::B_long_Dispatch, \
  (TMyPMF)B_LPARAM_Sig(&TMyClass::method)}

#define NOTIFY_SIG(id, arg) \
  template <class T> \
  inline BOOL (T::*id##_Sig(BOOL (T::*pmf)(arg)))(arg) { return pmf; }

#define VN_DEFINE(id, method, disp) \
  {WM_OWLNOTIFY, id, \
  (TAnyDispatcher) ::B_##disp##_Dispatch, \
  (TMyPMF)id##_Sig(&TMyClass::method)}

NOTIFY_SIG(vnViewOpened,TView*)
NOTIFY_SIG(vnViewClosed,TView*)
NOTIFY_SIG(vnDocOpened, int)
NOTIFY_SIG(vnDocClosed, int)
NOTIFY_SIG(vnCommit, BOOL)
NOTIFY_SIG(vnRevert, BOOL)
NOTIFY_SIG(vnIsDirty, void)
NOTIFY_SIG(vnIsWindow, HWND)

#define EV_VN_VIEWOPENED VN_DEFINE(vnViewOpened,VnViewOpened,pointer)
#define EV_VN_VIEWCLOSED VN_DEFINE(vnViewClosed,VnViewClosed,pointer)
#define EV_VN_DOCOPENED  VN_DEFINE(vnDocOpened, VnDocOpened, int)
#define EV_VN_DOCCLOSED  VN_DEFINE(vnDocClosed, VnDocClosed, int)
#define EV_VN_COMMIT     VN_DEFINE(vnCommit,    VnCommit,    int)
#define EV_VN_REVERT     VN_DEFINE(vnRevert,    VnRevert,    int)
#define EV_VN_ISDIRTY    VN_DEFINE(vnIsDirty,   VnIsDirty,   void)
#define EV_VN_ISWINDOW   VN_DEFINE(vnIsWindow,  VnIsWindow,  int)

// inline implementations

inline int
TDocument::GetOpenMode()
{
  return OpenMode;
}

inline void
TDocument::SetOpenMode(int mode)
{
  OpenMode = mode;
}

inline const char far*
TStream::GetStreamName()
{
  return StreamName;
}

inline int
TStream::GetOpenMode()
{
  return OpenMode;
}

#endif  // __OWL_DOCVIEW_H
