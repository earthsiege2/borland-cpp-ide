//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   Implements class TExceptionView
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\docmanag.h>
#include "xcptview.rc"
#include <owl\docview.rc>
#include <owl\inputdia.h>
#include <owl\compat.h>
#include <owl\listbox.h>
#include <owl\filedoc.h>
#include "xcptview.rc"

class XVLink;

class _DOCVIEWCLASS TExceptionView : public TListBox, public TView {
  public:
    TExceptionView(TDocument& doc, TWindow* parent = 0);
   ~TExceptionView();
    static LPCSTR StaticName() {return "Exception Log";}  // put in resource
    BOOL DirtyFlag;
    int CurIndex;
    void LogThrow(char* str);
    void Annotate(int index, char chr, BOOL cache = FALSE);

    //
    // overridden virtuals from TView
    //
    const char far*   GetViewName(){return StaticName();}
//    LPCSTR   GetViewName(){return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    BOOL     SetDocTitle(const char far* docname, int index)
//    BOOL     SetDocTitle(LPCSTR docname, int index)
                          {return TListBox::SetDocTitle(docname, index); }
    //
    // overridden virtuals from TWindow
    //
    BOOL CanClose()   {return TListBox::CanClose() && Doc->CanClose();}
    BOOL Create();

  protected:
    long Origin;
    int  MaxWidth;    // maximum horizontal extent
    XVLink* Link;
    char Cache;
    unexpected_function OldUnexpectedHandler;
    void Init();
    void SetExtent(LPSTR str);
    BOOL LoadData(int top, int sel);
    //
    // message response functions
    //
    BOOL VnDocClosed(int omode);
    BOOL VnCommit(BOOL force);
    BOOL VnRevert(BOOL clear);
    BOOL VnIsWindow(HWND hWnd) {return HWindow == hWnd;}
    BOOL VnIsDirty()       {return DirtyFlag;}
    void CmSelChange(){} // to prevent interpreting as unprocessed accelerator
    void CmTXOwl();
    void CmTXTest();
    void CmTXComp();
    void CmTXMem();
    void CmXalloc();
    void CmXmsg();
    void CmForeign();
    void CmUnexpected() throw (xalloc);
    void CmBadCast();
    void CmBadTypeid();
    void CmOwlSend();
    void CmClear();
    void EvTimeChange();
  DECLARE_RESPONSE_TABLE(TExceptionView);
  DECLARE_STREAMABLE(,TExceptionView,1);
};

class XVLink{  // access class to prevent calling deleted view
  public:
    XVLink(TExceptionView* view) : View(view), RefCnt(1), Suspended(FALSE) {}
    TExceptionView* View;
    int RefCnt;
    BOOL Suspended;
    void Annotate(int index, char chr)
      {if (View) View->Annotate(index, chr, Suspended);}
    void AddRef() {RefCnt++;}
    void SubRef() {if (--RefCnt == 0) delete this;}
};

class TXTest : public TXOwl {
  public:
    TXTest(UINT resId, XVLink* view, int index);
    TXTest(const TXTest&);
    const TXTest& operator = (const TXTest&);
   ~TXTest();
    TXOwl* Clone();
    void Throw();
    int Unhandled(TModule* app, unsigned promptResId);
    XVLink* View;
    int Index;
};

DEFINE_RESPONSE_TABLE1(TExceptionView, TListBox)
  EV_COMMAND(CM_TXOWL,      CmTXOwl),
  EV_COMMAND(CM_TXTEST,     CmTXTest),
  EV_COMMAND(CM_TXCOMP,     CmTXComp),
  EV_COMMAND(CM_TXMEM,      CmTXMem),
  EV_COMMAND(CM_XALLOC,     CmXalloc),
  EV_COMMAND(CM_XMSG,       CmXmsg),
  EV_COMMAND(CM_FOREIGN,    CmForeign),
  EV_COMMAND(CM_UNEXPECTED, CmUnexpected),
  EV_COMMAND(CM_BADCAST,    CmBadCast),
  EV_COMMAND(CM_BADTYPEID,  CmBadTypeid),
  EV_COMMAND(CM_OWLSEND,    CmOwlSend),
  EV_COMMAND(CM_XCLEAR,     CmClear),
  EV_NOTIFY_AT_CHILD(LBN_SELCHANGE, CmSelChange),
  EV_VN_DOCCLOSED,
  EV_VN_ISWINDOW,
  EV_VN_ISDIRTY,
  EV_VN_COMMIT,
  EV_VN_REVERT,
  EV_WM_TIMECHANGE,
END_RESPONSE_TABLE;

void XUnexpectedHandler()
{
  throw xmsg(string(*::Module,XM_UNEXPECTED));
}

TExceptionView::TExceptionView(TDocument& doc, TWindow* parent)
   : TView(doc), TListBox(parent, GetNextViewId(), 0,0,0,0),
     Origin(0), MaxWidth(0)
{
  Attr.Style &= ~(WS_BORDER | LBS_SORT);
  Attr.Style |= (WS_HSCROLL | LBS_NOINTEGRALHEIGHT);
  Attr.AccelTable = IDA_XCPTVIEW;
  SetViewMenu(new TMenuDescr(IDM_XCPTVIEW,0,2,0,0,0,1));
  Init();
}

void TExceptionView::Init()
{
  Link = new XVLink(this);
  OldUnexpectedHandler = set_unexpected(XUnexpectedHandler);
  DirtyFlag = FALSE;
  Cache = 0;
}

TExceptionView::~TExceptionView()
{
  Link->View = 0;  // prevent calling into destructed view
  Link->SubRef();  // will destruct when no outstanding exceptions
  set_unexpected(OldUnexpectedHandler);
}

struct XTest {  // class with destructor for testing TPointer
  char* P;
  XTest() {P = new char[4];}
  virtual ~XTest();     // non inline to allow breakpoint set
};
XTest::~XTest(){delete P;}

struct XTestD : public XTest {  // class derived from XTest
  XTestD() : XTest(), Q(0) {}
  char* Q;
 ~XTestD() {delete Q;}
};

static ThrowTXOwl()  // extra call level to allow TPointer testing
{
  throw TXOwl(XM_TXOWL);
}

void TExceptionView::CmTXOwl()
{
  TPointer<char> ptr = new char[20];
  ptr[0] = 0;
  TPointer<XTest> x;
  x = new XTest();
  LogThrow("TXOwl thrown");
  XTest* xt = new XTestD();
  delete xt;
  ThrowTXOwl();
}

void TExceptionView::CmTXTest()
{
  LogThrow("TXTest thrown");
  throw TXTest(XM_TXTEST, Link, CurIndex);
}

void TExceptionView::CmTXComp()
{
  LogThrow("TXCompatibility throw by setting Status");
  Status = EM_INVALIDWINDOW;
}

void TExceptionView::CmTXMem()
{
  LogThrow("TXOutOfMemory thrown");
  throw TXOutOfMemory();
}

void TExceptionView::CmXalloc()
{
  LogThrow("xalloc thrown");
  throw xalloc(string(*::Module,XM_XALLOC),1234);
}

void TExceptionView::CmXmsg()
{
  LogThrow("xmsg thrown");
  throw xmsg(string(*::Module,XM_XMSG));
}

void TExceptionView::CmForeign()
{
  LogThrow("int thrown");
  throw (int)35;
}

void TExceptionView::CmUnexpected() throw (xalloc)
{
  LogThrow("Unexpected xmsg thrown");
  throw xmsg(string(*::Module,XM_UNEXPECTED));
}

static xmsg* XVRef(xmsg&) {return 0;}

void TExceptionView::CmBadCast()
{
  LogThrow("Failed dynamic_cast<>");
  XVRef(dynamic_cast<xmsg&>(*this));
}

void TExceptionView::CmBadTypeid()
{
  LogThrow("type_id() called on invalid object");
  class __rtti C {int i; virtual ~C(){}};
  C* o = 0;
  static const char* n;
  n = typeid(*o).name();
}

void TExceptionView::CmOwlSend()
{
  ::SendMessage(HWindow, WM_TIMECHANGE,0,0); // any strange message will do
  GetApplication()->ResumeThrow();
}

void TExceptionView::EvTimeChange()
{
  LogThrow("TXTest thrown from event handler");
  throw TXTest(XM_OWLSEND, Link, CurIndex);
}

void TExceptionView::CmClear()
{
  ClearList();
  DirtyFlag = FALSE;
  SetHorizontalExtent(MaxWidth = 0);
}

void TExceptionView::LogThrow(char* str)
{
  SetSelIndex(CurIndex = AddString(str));
  SetExtent(str);
  DirtyFlag = TRUE;
}

void TExceptionView::Annotate(int index, char chr, BOOL cache)
{
  if (Cache) {  // check if character logged during exception processing
    char chr = Cache;
    Cache = 0;
    Annotate(index, chr);  // we assume here we're still at the same index
  }
  if (cache && chr == '~') {  // check if in destructor with cloned exception
    Cache = chr;
    return;
  }
  char buf[100];
  int len = GetStringLen(index);
  GetString(buf, index);
  buf[len]   = ' ';
  buf[len+1] = chr;
  buf[len+2] = 0;
  DeleteString(index);
  InsertString(buf, index);
  SetSelIndex(index);
}

void TExceptionView::SetExtent(LPSTR str)
{
  HDC hdc;
  int len;
  TSize extent;
  if ((len = strlen(str)) == 0)
    return;
  hdc = ::GetDC(HWindow);
  ::GetTextExtentPoint(hdc, str, len, &extent);
  extent.cx += 2; // room for focus rectangle

  if (extent.cx > MaxWidth){
    SetHorizontalExtent(MaxWidth = extent.cx);
  }
  ::ReleaseDC(HWindow, hdc);
}

BOOL TExceptionView::VnDocClosed(int omode)
{
  int top;
  int sel;
  if (DirtyFlag == 2 || !(omode & ofWrite))  // make sure someone else's write
    return FALSE;
  top = GetTopIndex();
  sel = GetSelIndex();
  LoadData(top, sel);
  return TRUE;
}

BOOL TExceptionView::LoadData(int top, int sel)
{
  char buf[100+1];
  istream* inStream;
  BOOL status = TRUE;

  CmClear();
  DirtyFlag = FALSE;
  if ((inStream = Doc->InStream(ios::in)) == 0) {
    Doc->PostError(IDS_UNABLEOPEN, MB_OK);
    return FALSE;
  }
  for (;;) {
    inStream->getline(buf, sizeof(buf)-1);
    if (!inStream->gcount() && !inStream->good()) {
      status = inStream->eof();
      break;
    }
    AddString(buf);
    SetExtent(buf);
  }
  SetTopIndex(top);
  SetSelIndex(sel);
  delete inStream;   // close file in case process switch
  if (!status)
    Doc->PostError(IDS_READERROR, MB_OK);
  return status;
}

BOOL TExceptionView::Create()
{
  try {
    TListBox::Create();   // throws exception TWindow::TXWindow
  }
  catch (TXOwl& x) {
    Doc->PostError(IDS_NOMEMORYFORVIEW, MB_OK);
    return TRUE;   // cannot return FALSE - throws another exception
  }
  if (Doc->GetDocPath() == 0) {
    return TRUE;           // new file, no data to display
  }
  if (!LoadData(0, 0))
    NotOK();
  return TRUE;
}

BOOL TExceptionView::VnCommit(BOOL force)
{
  int count;
  int index;
  int len;
  char* buf;
  ostream* outStream;
  BOOL status;

  if (!force && !DirtyFlag)
    return TRUE;
  if ((outStream = Doc->OutStream(ios::out)) == 0) {
    Doc->PostError(IDS_UNABLEOPEN, MB_OK);
    return FALSE;
  }
  outStream->seekp(Origin);
  count = GetCount();
  for (index = 0; index < count; index++) {
    len = GetStringLen(index);
    buf = new char[len+1];
    GetString(buf, index);
    *outStream << buf << '\n';
    delete buf;
  }
  DirtyFlag = 2;           // to detect our own close notification
  status = outStream->good();
  delete outStream;
  DirtyFlag = FALSE;
  if (!status)
    Doc->PostError(IDS_WRITEERROR, MB_OK);
  return status;
}

BOOL TExceptionView::VnRevert(BOOL clear)
{
  if (!clear && Doc->GetDocPath() != 0)
    return LoadData(0,0);
  CmClear();
  return TRUE;
}

// Exception class for monitoring exception progress

TXTest::TXTest(UINT resId, XVLink* view, int index)
       : TXOwl(resId), View(view), Index(index)
{
  View->AddRef();
  View->Annotate(Index, '#');
}

TXTest::TXTest(const TXTest& s) : TXOwl(s), View(s.View),Index(s.Index)
{
  View->AddRef();
  View->Annotate(Index, '+');
}

TXTest::~TXTest()
{
// We cannot do any action here that would cause an exeption to be thrown
// since this object may have just been caught and cloned, a call involving
// messaging through windows would cause the cloned exception to be rethrown
  View->Annotate(Index, '~');
  View->SubRef();
}

const TXTest& TXTest::operator = (const TXTest& src)
{
  *(TXOwl*)this = src;
  View = src.View;
  Index = src.Index;
  View->AddRef();
  View->Annotate(Index, '=');
  return *this;
}

TXOwl* TXTest::Clone()
{
  View->Suspended = TRUE;  // prevent rethrow during logging Windows call
  View->Annotate(Index, '&');
  return new TXTest(*this);  // will do the AddRef
}

void TXTest::Throw()
{
  View->Suspended = FALSE;
  View->Annotate(Index, '!');
  throw *this;
}

int TXTest::Unhandled(TModule* app, unsigned promptResId)
{
  View->Annotate(Index, '?');
  return TXOwl::Unhandled(app, promptResId);
}

IMPLEMENT_STREAMABLE2(TExceptionView, TListBox, TView);

void* TExceptionView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TExceptionView* o = GetObject();
  ReadBaseObject((TListBox*)o, is);
  ReadBaseObject((TView*)o, is);
  o->Init();
  is >> o->Origin;
  is >> o->MaxWidth;
  return o;
}

void TExceptionView::Streamer::Write(opstream &os) const
{
  WriteBaseObject((TListBox*)GetObject(), os);
  WriteBaseObject((TView*)GetObject(), os);
  os << GetObject()->Origin;
  os << GetObject()->MaxWidth;
}

DEFINE_DOC_TEMPLATE_CLASS(TFileDocument, TExceptionView, XcptTemplate);
XcptTemplate xcptTpl("Exception Log File","*.xlg", 0, "XLG",dtAutoDelete|dtUpdateDir);

