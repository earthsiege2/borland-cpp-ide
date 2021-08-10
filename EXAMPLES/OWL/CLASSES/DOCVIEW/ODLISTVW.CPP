//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//
//   Implements class TODListView
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/docmanag.h>
#include <owl/filedoc.h>
#include <owl/inputdia.h>
#include <stdio.h>
#include "odlistbx.h"
#include "odlistvw.rc"

// class TODListView
// ~~~~~ ~~~~~~~~~~~
class _DOCVIEWCLASS TODListView : public TODListBox, public TView {
  public:
    TODListView(TDocument& doc, TWindow* parent = 0);
   ~TODListView();
    static const char far* StaticName() {return "OD List View";}  // put in resource
    bool DirtyFlag;

    // Overridden virtuals from TView
    //
    const char far*  GetViewName() {return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    bool     SetDocTitle(const char far* docname, int index)
                          {return TODListBox::SetDocTitle(docname, index); }
    // Overridden virtuals from TWindow
    //
    bool Create();
    uint EvGetDlgCode(MSG far*);
    bool CanClose()   {return TODListBox::CanClose() && Doc->CanClose();}

  protected:
    long Origin;
    bool LoadData(int top, int sel);

    // Message response functions
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
    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnIsWindow(HWND hWnd) {return GetHandle() == hWnd;}
    bool VnIsDirty()  {return DirtyFlag;}
    bool VnDocClosed(int omode);
    void EvDestroy();
    void CmSelChange() {} // to prevent interpreting as unprocessed accelerator

  DECLARE_RESPONSE_TABLE(TODListView);
  DECLARE_STREAMABLE(,TODListView,1);
};


//
// Last virtual line appended to list
//
const char VirtualLastLineStr[] = "---";

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
:
  TView(doc),
  TODListBox((int)GetNextViewId()),
  Origin(0),
  DirtyFlag(false)
{
  Attr.Style &= ~(WS_BORDER | LBS_SORT);
  Attr.Style |= (WS_HSCROLL | LBS_NOINTEGRALHEIGHT);
  if (doc.GetTemplate() == &odTxtTpl)
    Attr.Style |= LBS_HASSTRINGS;
  Attr.AccelTable = IDA_ODLISTVIEW;
  SetViewMenu(new TMenuDescr(IDM_ODLISTVIEW,0,1,0,0,0,1));
}

bool
TODListView::LoadData(int top, int sel)
{
  CmEditClear();
  DeleteString(0);
  DirtyFlag = false;

  istream* inStream;
  if ((inStream = Doc->InStream(ios::in)) == 0)
    return false;

  for (;;) {
    char buf[100+1];
    inStream->getline(buf, sizeof(buf)-1);
    if (!inStream->gcount() && !inStream->good())
      break;  // if EOF or error
    char* str;
    if (Attr.Style & LBS_HASSTRINGS) {   // strings stored in list box
      str = buf;
    }
    else {
      str = new char[strlen(buf)+1];
      strcpy(str, buf);
    }
    AddString(str);
  }
  AddString(VirtualLastLineStr);
  SetSelIndex(top);
  SetSelIndex(sel);
  delete inStream;   // close file in case process switch
  return true;
}

bool
TODListView::Create()
{
  DirtyFlag = false;
  TODListBox::Create();   // throws exception TXInvalidWindow
  if (Doc->GetDocPath() == 0) {
    CmEditClear();         // perform any clearing initialization
    return true;           // new file, no data to display
  }
  if (!LoadData(0, 0))
    NotOK();
  return true;
}

bool
TODListView::VnDocClosed(int omode)
{
  int top;
  int sel;
  if (DirtyFlag == 2 || !(omode & ofWrite))  // make sure someone else's write
    return false;
  top = GetTopIndex();
  sel = GetSelIndex();
  LoadData(top, sel);
  return true;
}

bool
TODListView::VnCommit(bool force)
{
  if (!force && !DirtyFlag)
    return true;

  ostream* outStream;
  if ((outStream = Doc->OutStream(ios::out)) == 0)
    return false;
  outStream->seekp(Origin);

  char* buf = 0;  // initialized only to prevent warning about use before def
  int buflen = 0;
  int count = GetCount();
  for (int index = 0; index < count-1; index++) {  // don't write last virtual line
    int len;
    char far* str;
    if (Attr.Style & LBS_HASSTRINGS) {
      len = GetStringLen(index);
    }
    else {
      str = (char far*)GetItemData(index);
      len = str ? strlen(str) : 0;
    }
    if (len != 0) {
      if (len >= buflen) {
        if (buflen != 0)
          delete buf;
        buf = new char[buflen = len+1];
      }
      if (Attr.Style & LBS_HASSTRINGS)
        GetString(buf, index);
      else
        strcpy(buf, str);
      *outStream << buf;
    }
    *outStream << '\n';
  }
  if (buflen != 0)
    delete buf;
  DirtyFlag = 2;           // to detect our own close notification
  delete outStream;
  DirtyFlag = false;
  return true;
}

bool
TODListView::VnRevert(bool clear)
{
  if (!clear && Doc->GetDocPath() != 0)
    return LoadData(0,0);
  CmEditClear();
  DirtyFlag = false;
  return true;
}

uint
TODListView::EvGetDlgCode(MSG far*)
{
  uint retVal = (uint)DefaultProcessing();
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
  int index = GetSelIndex();
  int count = GetCount();
  if (count <= 1 || index >= count-1)
    return;

  char far* str;
  int len;
  if (Attr.Style & LBS_HASSTRINGS) {  // strings stored in list box
    len = GetStringLen(index);
  }
  else {
    str = (char far*)GetItemData(index);
    len = strlen(str);
  }

  TClipboard cb(*this);
  if (cb.EmptyClipboard()) {
    HANDLE cbhdl = ::GlobalAlloc(GHND, len+0+1);
    char far* gbuf = (char far*)::GlobalLock(cbhdl);
    if (Attr.Style & LBS_HASSTRINGS) {  // strings stored in list box
      GetString(gbuf, index);
    }
    else {
      strcpy(gbuf, str);
    }
    ::GlobalUnlock(cbhdl);
    cb.SetClipboardData(CF_TEXT, cbhdl);
  }
}

void
TODListView::CmEditPaste()
{
  int index = GetSelIndex();
  if (index < 0)
    index = 0;

  TClipboard cb(*this);
  if (!cb)
    return;  // clipboard open by another window

  HANDLE cbhdl = cb.GetClipboardData(CF_TEXT);
  if (cbhdl) {
    char far* text = (char far*)::GlobalLock(cbhdl);
    char far* str;
    if (Attr.Style & LBS_HASSTRINGS) {   // strings stored in list box
      str = text;
    }
    else {
      str = new char[strlen(text)+1];
      strcpy(str, text);
    }
    InsertString(str, index);
    SetSelIndex(index+1);
    DirtyFlag = true;
    ::GlobalUnlock(cbhdl);
  }
}

void
TODListView::CmEditDelete()
{
  int count = GetCount();
  int index = GetSelIndex();
  if (count <= 1 || index >= count-1)
    return;

  ODItemInfo item;
  item.Hdc = ::GetDC(*this);
  item.Index = index;
  item.Data  = (void far*)GetItemData(index);
  item.State = 0;
  GetItemInfo(item);
  ::ReleaseDC(*this, item.Hdc);
  if (item.Extent.cx == MaxWidth)
    SetHorizontalExtent(MaxWidth = 0); // force recalculate max width
  if (!(Attr.Style & LBS_HASSTRINGS))  // strings not stored in list box
    delete item.Data;

  DeleteString(index);
  SetSelIndex(index);
  DirtyFlag = true;
}

void
TODListView::CmEditClear()
{
  int count = GetCount();
  if (count == 1)
    return;
  if (count) {
    if (!(Attr.Style & LBS_HASSTRINGS))  // strings not stored in list box
      for (int index = 0; index < count-1; index++)
        delete[] (char far*)GetItemData(index);
    ClearList();
    DirtyFlag = true;
    SetHorizontalExtent(MaxWidth = 0);
  }
  AddString(VirtualLastLineStr);
}

TODListView::~TODListView()
{
  if (GetHandle())
    CmEditClear();
}

void
TODListView::EvDestroy()
{
  CmEditClear();
  TWindow::EvDestroy();
}

static int linePrompt(TWindow* parent, int index, uint id, char far* buf,int buflen)
{
  char msg[41];
  sprintf(msg, string(*parent->GetModule(), IDS_ODLISTNUM).c_str(), index);
  const char far* prompt = string(*parent->GetModule(), id).c_str();
  return TInputDialog(parent, msg, prompt, buf, buflen).Execute();
}

void
TODListView::CmEditAdd()
{
  char inputText[80];
  *inputText = 0;

  int index = GetSelIndex();
  if (index < 0)
    index = 0;

  if (linePrompt(this,index+1,CM_ODLISTADD,inputText,sizeof(inputText))==IDOK) {
    char far* str;
    if (Attr.Style & LBS_HASSTRINGS) {   // strings stored in list box
      str = inputText;
    }
    else {
      str = new char[strlen(inputText)+1];
      strcpy(str, inputText);
    }
    InsertString(str, index);
    SetSelIndex(index+1);
    DirtyFlag = true;
  }
}

void
TODListView::CmEditItem()
{
  int index = GetSelIndex();
  if (index < 0 || index >= GetCount()-1)
    return;

  int len;
  char* inputText;
  if (Attr.Style & LBS_HASSTRINGS) { // strings stored in list box
    len = GetStringLen(index);
    inputText = new char[len + 81];
    GetString(inputText, index);
  }
  else {
    char far* str = (char far*)GetItemData(index);
    len = strlen(str);
    inputText = new char[len + 81];
    strcpy(inputText, str);
  }
  if (linePrompt(this,index+1,CM_ODLISTEDIT,inputText, len + 81)==IDOK) {
    char far* str;
    if (Attr.Style & LBS_HASSTRINGS) {  // strings stored in list box
      str = inputText;
    }
    else {
      delete (char far*)GetItemData(index);
      str = strnewdup(inputText);
    }
    DeleteString(index);
    InsertString(str, index);
    SetSelIndex(index);
    DirtyFlag = true;
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
  GetObject()->DirtyFlag = false;
  return GetObject();
}

void
TODListView::Streamer::Write(opstream &os) const
{
  WriteBaseObject((TODListBox*)GetObject(), os);
  WriteBaseObject((TView*)GetObject(), os);
  os << GetObject()->Origin;
}
