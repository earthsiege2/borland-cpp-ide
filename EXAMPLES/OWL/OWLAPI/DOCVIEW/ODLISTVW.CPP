//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   Implements class TODListView
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\docmanag.h>
#include <owl\filedoc.h>
#include <owl\inputdia.h>
#include "odlistbx.h"
#include "odlistvw.rc"

//  class TODListView
//  ----- -----------
//
class _DOCVIEWCLASS TODListView : public TODListBox, public TView {
  public:
    TODListView(TDocument& doc, TWindow* parent = 0);
   ~TODListView();
    static LPCSTR StaticName() {return "OD List View";}  // put in resource
    BOOL DirtyFlag;

    //
    // overridden virtuals from TView
    //
    LPCSTR   GetViewName(){return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    BOOL     SetDocTitle(LPCSTR docname, int index)
                          {return TODListBox::SetDocTitle(docname, index); }
    //
    // overridden virtuals from TWindow
    //
    BOOL Create();
    UINT EvGetDlgCode(MSG far*);
    BOOL CanClose()   {return TODListBox::CanClose() && Doc->CanClose();}

  protected:
    long Origin;
    BOOL LoadData(int top, int sel);
    //
    // message response functions
    //
    void CmEditUndo();
    void CmEditCut();
    void CmEditCopy();
    void CmEditPaste();
    void CmEditDelete();
    void CmEditClear();
    void CmEditAdd();
    void CmEditItem();
//  void CmLineIndent();
//  void CmLineUnindent();
    BOOL VnCommit(BOOL force);
    BOOL VnRevert(BOOL clear);
    BOOL VnIsWindow(HWND hWnd) {return HWindow == hWnd;}
    BOOL VnIsDirty()  {return DirtyFlag;}
    BOOL VnDocClosed(int omode);
    void EvDestroy();
    void CmSelChange(){} // to prevent interpreting as unprocessed accelerator

  DECLARE_RESPONSE_TABLE(TODListView);
  DECLARE_STREAMABLE(,TODListView,1);
};

DEFINE_RESPONSE_TABLE1(TODListView, TODListBox)
  EV_COMMAND(CM_ODLISTUNDO,    CmEditUndo),
  EV_COMMAND(CM_ODLISTCUT,     CmEditCut),
  EV_COMMAND(CM_ODLISTCOPY,    CmEditCopy),
  EV_COMMAND(CM_ODLISTPASTE,   CmEditPaste),
  EV_COMMAND(CM_ODLISTCLEAR,   CmEditClear),
  EV_COMMAND(CM_ODLISTDELETE,  CmEditDelete),
  EV_COMMAND(CM_ODLISTADD,     CmEditAdd),
  EV_COMMAND(CM_ODLISTEDIT,    CmEditItem),
  EV_WM_GETDLGCODE,
  EV_WM_DESTROY,
  EV_NOTIFY_AT_CHILD(LBN_DBLCLK,    CmEditItem),
  EV_NOTIFY_AT_CHILD(LBN_SELCHANGE, CmSelChange),
  EV_VN_DOCCLOSED,
  EV_VN_ISWINDOW,
  EV_VN_ISDIRTY,
  EV_VN_COMMIT,
  EV_VN_REVERT,
END_RESPONSE_TABLE;

DEFINE_DOC_TEMPLATE_CLASS(TFileDocument, TODListView, ODLBTemplate);
ODLBTemplate odBinTpl("ODListBox, All files","*.*", 0, "TXT",dtAutoDelete);
ODLBTemplate odTxtTpl("ODStrings, All files","*.*", 0, "TXT",dtAutoDelete);

TODListView::TODListView(TDocument& doc, TWindow* /*parent*/)
   : TView(doc), TODListBox(GetNextViewId()),
     Origin(0), DirtyFlag(FALSE)
{
  Attr.Style &= ~(WS_BORDER | LBS_SORT);
  Attr.Style |= (WS_HSCROLL | LBS_NOINTEGRALHEIGHT);
  if (doc.GetTemplate() == &odTxtTpl)
    Attr.Style |= LBS_HASSTRINGS;
  Attr.AccelTable = IDA_ODLISTVIEW;
  SetViewMenu(new TMenuDescr(IDM_ODLISTVIEW,0,1,0,0,0,1));
}

BOOL
TODListView::LoadData(int top, int sel)
{
  char buf[100+1];
  istream* inStream;
  char* str;

  CmEditClear();
  DirtyFlag = FALSE;
  if ((inStream = Doc->InStream(ios::in)) == 0)
    return FALSE;

  for (;;) {
    inStream->getline(buf, sizeof(buf)-1);
    if (!inStream->gcount() && !inStream->good())
      break;  // if EOF or error
    if (Attr.Style & LBS_HASSTRINGS) {   // strings stored in list box
      str = buf;
    } else {
      str = new char[strlen(buf)+1];
      strcpy(str, buf);
    }
    AddString(str);
  }
  SetSelIndex(top);
  SetSelIndex(sel);
  delete inStream;   // close file in case process switch
  return TRUE;
}

BOOL
TODListView::Create()
{
  DirtyFlag = FALSE;
  TODListBox::Create();   // throws exception TXInvalidWindow
  if (Doc->GetDocPath() == 0) {  
    return TRUE;           // new file, no data to display
  }
  if (!LoadData(0, 0))
    NotOK();
  return TRUE;
}

BOOL
TODListView::VnDocClosed(int omode)
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

BOOL
TODListView::VnCommit(BOOL force)
{
  int count;
  int index;
  int len;
  char* buf = 0;  // initialized only to prevent warning about use before def
  LPSTR str;
  int buflen = 0;
  ostream* outStream;

  if (!force && !DirtyFlag)
    return TRUE;
  if ((outStream = Doc->OutStream(ios::out)) == 0)
    return FALSE;
  outStream->seekp(Origin);

  count = GetCount();
  for (index = 0; index < count; index++) {
    if (Attr.Style & LBS_HASSTRINGS) {
      len = GetStringLen(index);
    } else {
      str = (LPSTR)GetItemData(index);
      len = str ? lstrlen(str) : 0;
    }
    if (len != 0){
      if (len >= buflen){
         if (buflen != 0) delete buf;
         buf = new char[buflen = len+1];
      }
      if (Attr.Style & LBS_HASSTRINGS)
        GetString(buf, index);
      else
        lstrcpy(buf, str);
      *outStream << buf;
    }
    *outStream << '\n';
  }
  if (buflen != 0)
    delete buf;
  DirtyFlag = 2;           // to detect our own close notification
  delete outStream;
  DirtyFlag = FALSE;
  return TRUE;
}

BOOL
TODListView::VnRevert(BOOL clear)
{
  if (!clear && Doc->GetDocPath() != 0)
    return LoadData(0,0);
  CmEditClear();
  return TRUE;
}

UINT
TODListView::EvGetDlgCode(MSG far*)
{
  UINT retVal = (UINT)DefaultProcessing();
  retVal |= DLGC_WANTCHARS;
  return retVal;
}

void
TODListView::CmEditUndo()
{
  MessageBox("Feature not implemented", "Undo", MB_OK);
}

void
TODListView::CmEditCut()
{
  CmEditCopy();
  CmEditDelete();
}

void
TODListView::CmEditCopy()
{
  HANDLE cbhdl;
  LPSTR gbuf;
  LPSTR str;
  int len;
  int index = GetSelIndex();
  if (!GetCount()) return;
  if (Attr.Style & LBS_HASSTRINGS) {  // strings stored in list box
    len = GetStringLen(index);
  }else{
    str = (LPSTR)GetItemData(index);
    len = lstrlen(str);
  }
  TClipboard& cb = OpenClipboard();
  if (cb.EmptyClipboard()) {
    cbhdl = GlobalAlloc(GHND,len+0+1);
    gbuf = (char far*)GlobalLock(cbhdl);
    if (Attr.Style & LBS_HASSTRINGS){  // strings stored in list box
      GetString(gbuf, index);
    }else{
      lstrcpy(gbuf, str);
    }
    GlobalUnlock(cbhdl);
    cb.SetClipboardData(CF_TEXT, cbhdl);
  }
  cb.CloseClipboard();
}

void
TODListView::CmEditPaste()
{
  HANDLE cbhdl;
  LPSTR text;
  LPSTR str;
  int index = GetSelIndex();
  if (index < 0)
    index = 0;
//UINT format = 0;
  TClipboard& cb = OpenClipboard();
  if (!cb) return;  // clipboard open by another program
//if (!cb.IsClipboardFormatAvailable(CF_TEXT)) return;
  if ((cbhdl = cb.GetClipboardData(CF_TEXT)) != 0){
    text = (LPSTR)GlobalLock(cbhdl);
    if (Attr.Style & LBS_HASSTRINGS) {   // strings stored in list box
      str = text;
    }else{
      str = new char[lstrlen(text)+1];
      lstrcpy(str, text);
    }
    InsertString(str, index);
    SetSelIndex(index);
    DirtyFlag = TRUE;
    GlobalUnlock(cbhdl);
  }
  cb.CloseClipboard();
}

void
TODListView::CmEditDelete()
{
  ODItemInfo item;
  int count = GetCount();
  if (!count)
    return;
  item.Hdc = ::GetDC(*this);
  item.Index = GetSelIndex();
  item.Data  = (void far*) GetItemData(item.Index);
  item.State = 0;
  GetItemInfo(item);
  ::ReleaseDC(*this, item.Hdc);
  if (item.Extent.cx == MaxWidth)
    SetHorizontalExtent(MaxWidth = 0); // force recalculate max width
  if (!(Attr.Style & LBS_HASSTRINGS))  // strings not stored in list box
    delete item.Data;
  DeleteString(item.Index);
  if (item.Index == count-1) item.Index--;
  SetSelIndex(item.Index);
  DirtyFlag = TRUE;
}

void
TODListView::CmEditClear()
{
  int count = GetCount();
  if (!count)
    return;
  if (!(Attr.Style & LBS_HASSTRINGS)) {  // strings not stored in list box
    int index;
    for (index = 0; index < count; index++) {
      delete (LPSTR)GetItemData(index);
    }
  }
  ClearList();
  DirtyFlag = TRUE;
  SetHorizontalExtent(MaxWidth = 0);
}

TODListView::~TODListView()
{
  if (HWindow)
    CmEditClear();
}

void
TODListView::EvDestroy()
{
  CmEditClear();
  TWindow::EvDestroy();
}

static int linePrompt(TWindow* parent,int index,UINT id,LPSTR buf,int buflen)
{
  char msg[41];
  wsprintf(msg, string(*parent->GetModule(), IDS_ODLISTNUM).c_str(), index);
  LPCSTR prompt = string(*parent->GetModule(), id).c_str();
  return TInputDialog(parent, msg, prompt, buf, buflen).Execute();
}

void
TODListView::CmEditAdd()
{
  LPSTR str;
  char inputText[80];
  int index = GetSelIndex() + 1;
  inputText[0] = 0;
  if (linePrompt(this,index+1,CM_ODLISTADD,inputText,sizeof(inputText))==IDOK) {
    if (Attr.Style & LBS_HASSTRINGS) {   // strings stored in list box
      str = inputText;
    } else {
      str = new char[lstrlen(inputText)+1];
      lstrcpy(str, inputText);
    }
    InsertString(str, index);
    SetSelIndex(index);
    DirtyFlag = TRUE;
  }
}

void
TODListView::CmEditItem()
{
  LPSTR str;
  int len;
  char* inputText;
  int index = GetSelIndex();
  if (index < 0)
    return;
  if (Attr.Style & LBS_HASSTRINGS) { // strings stored in list box
    len = GetStringLen(index);
    inputText = new char[len + 81];
    GetString(inputText, index);
  }else{
    str = (LPSTR)GetItemData(index);
    len = lstrlen(str);
    inputText = new char[len + 81];
    lstrcpy(inputText, str);
  }
  if (linePrompt(this,index+1,CM_ODLISTEDIT,inputText, len + 81)==IDOK){
    if (Attr.Style & LBS_HASSTRINGS){  // strings stored in list box
      str = inputText;
    }else{
      delete (LPSTR)GetItemData(index);
      str = new char[lstrlen(inputText)+1];
      lstrcpy(str, inputText);
    }
    DeleteString(index);
    InsertString(str, index);
    SetSelIndex(index);
    DirtyFlag = TRUE;
  }  
  delete inputText;
}

IMPLEMENT_STREAMABLE2(TODListView, TODListBox, TView);

void *
TODListView::Streamer::Read(ipstream &is, uint32 /* version */) const
{
  ReadBaseObject((TODListBox*)GetObject(), is);
  ReadBaseObject((TView*)GetObject(), is);
  is >> GetObject()->Origin;
  GetObject()->DirtyFlag = FALSE;
  return GetObject();
}

void
TODListView::Streamer::Write(opstream &os) const
{
  WriteBaseObject((TODListBox*)GetObject(), os);
  WriteBaseObject((TView*)GetObject(), os);
  os << GetObject()->Origin;
}
