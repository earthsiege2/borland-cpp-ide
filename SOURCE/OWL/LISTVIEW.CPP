//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   include\owl\listview.cpp
//   Implements class TListView
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\listview.h>
#include <owl\listview.rc>
#include <owl\docview.rc>
#include <owl\inputdia.h>

DIAG_DECLARE_GROUP(OwlDocView);        // General Doc/View diagnostic group

#if !defined(SECTION) || SECTION == 1

//  class TListView
//  ----- ---------
//
DEFINE_RESPONSE_TABLE1(TListView, TListBox)
  EV_COMMAND(CM_LISTUNDO,    CmEditUndo),
  EV_COMMAND(CM_LISTCUT,     CmEditCut),
  EV_COMMAND(CM_LISTCOPY,    CmEditCopy),
  EV_COMMAND(CM_LISTPASTE,   CmEditPaste),
  EV_COMMAND(CM_LISTCLEAR,   CmEditClear),
  EV_COMMAND(CM_LISTDELETE,  CmEditDelete),
  EV_COMMAND(CM_LISTADD,     CmEditAdd),
  EV_COMMAND(CM_LISTEDIT,    CmEditItem),
  EV_WM_GETDLGCODE,
  EV_NOTIFY_AT_CHILD(LBN_DBLCLK, CmEditItem),
  EV_NOTIFY_AT_CHILD(LBN_SELCHANGE, CmSelChange),
  EV_VN_DOCCLOSED,
  EV_VN_ISWINDOW,
  EV_VN_ISDIRTY,
  EV_VN_COMMIT,
  EV_VN_REVERT,
END_RESPONSE_TABLE;

TListView::TListView(TDocument& doc, TWindow* parent)
   : TView(doc),TListBox(parent, GetNextViewId(), 0,0,0,0),
     Origin(0), MaxWidth(0), DirtyFlag(FALSE)
{
  Attr.Style &= ~(WS_BORDER | LBS_SORT);
  Attr.Style |= (WS_HSCROLL | LBS_NOINTEGRALHEIGHT);
  Attr.AccelTable = IDA_LISTVIEW;
  SetViewMenu(new TMenuDescr(IDM_LISTVIEW,0,1,0,0,0,1));
}

void
TListView::SetExtent(LPSTR str)
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

BOOL
TListView::VnDocClosed(int omode)
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
TListView::LoadData(int top, int sel)
{
  char buf[100+1];
  istream* inStream;
  BOOL status = TRUE;

  CmEditClear();
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

BOOL
TListView::Create()
{
  TRY {
    TListBox::Create();   // throws exception TWindow::TXWindow
  }
  CATCH( (TXOwl& x) {
    Doc->PostError(IDS_NOMEMORYFORVIEW, MB_OK);
    return TRUE;   // cannot return FALSE - throws another exception
  })
  if (Doc->GetDocPath() == 0) {  
    return TRUE;           // new file, no data to display
  }
  if (!LoadData(0, 0))
    NotOK();
  return TRUE;
}

BOOL
TListView::VnCommit(BOOL force)
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

BOOL
TListView::VnRevert(BOOL clear)
{
  if (!clear && Doc->GetDocPath() != 0)
    return LoadData(0,0);
  CmEditClear();
  DirtyFlag = FALSE;
  return TRUE;
}

UINT
TListView::EvGetDlgCode(MSG far*)
{
  UINT retVal = (UINT)DefaultProcessing();
  retVal |= DLGC_WANTCHARS;
  return retVal;
}

void
TListView::CmEditUndo()
{
  MessageBox("Feature not implemented", "Undo", MB_OK);
}

void
TListView::CmEditCut()
{
  CmEditCopy();
  CmEditDelete();
}

void
TListView::CmEditCopy()
{
  HANDLE cbhdl;
  char far* buf;
  int index = GetSelIndex();
  if (!GetCount()) return;
  int len = GetStringLen(index);
  TClipboard& cb = OpenClipboard();
  if (cb.EmptyClipboard()) {
    cbhdl = GlobalAlloc(GHND,len+0+1);
    buf = (char far*)GlobalLock(cbhdl);
    GetString(buf, index);
    GlobalUnlock(cbhdl);
    cb.SetClipboardData(CF_TEXT, cbhdl);
  }
  cb.CloseClipboard();
}

void
TListView::CmEditPaste()
{
  HANDLE cbhdl;
  char far* text;
  int index = GetSelIndex();
  if (index < 0)
    index = 0;
  TClipboard& cb = OpenClipboard();
  if (!cb) return;   // clipboard open by another program
  if ((cbhdl = cb.GetClipboardData(CF_TEXT)) != 0) {
    text = (char far*)GlobalLock(cbhdl);
    InsertString(text, index);
    SetSelIndex(index);
    DirtyFlag = TRUE;
    GlobalUnlock(cbhdl);
  }
  cb.CloseClipboard();
}

void
TListView::CmEditDelete()
{
  int count = GetCount();
  int index = GetSelIndex();
  if (!count) return;
  DeleteString(index);
  if (index == count-1) index--;
  SetSelIndex(index);
  DirtyFlag = TRUE;
}

void
TListView::CmEditClear()
{
  if (GetCount()) {
    ClearList();
    DirtyFlag = TRUE;
    SetHorizontalExtent(MaxWidth = 0);
  }
}

static int linePrompt(TWindow* parent,int index,UINT id,LPSTR buf,int buflen)
{
  char msg[41];
  wsprintf(msg, string(*parent->GetModule(), IDS_LISTNUM).c_str(), index);
  LPCSTR prompt = string(*parent->GetModule(), id).c_str();
  return TInputDialog(parent, msg, prompt, buf, buflen).Execute();
}

void
TListView::CmEditAdd()
{
  char inputText[101];
  int index = GetSelIndex() + 1;   // becomes 0 if list box is empty
  inputText[0] = 0;
  if (linePrompt(this,index+1,CM_LISTADD,inputText,sizeof(inputText))==IDOK) {
    InsertString(inputText, index);
    SetSelIndex(index);
    SetExtent(inputText);
    DirtyFlag = TRUE;
  }
}

void
TListView::CmEditItem()
{
  char inputText[101];
  int index = GetSelIndex();
  if (index < 0)
    return;
  GetSelString(inputText, sizeof(inputText)-1);
  if (linePrompt(this,index+1,CM_LISTEDIT,inputText,sizeof(inputText))==IDOK){
    DeleteString(index);
    InsertString(inputText, index);
    SetExtent(inputText);
    SetSelIndex(index);
    DirtyFlag = TRUE;
  }
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE2(TListView, TListBox, TView);

void*
TListView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TListBox*)GetObject(), is);
  ReadBaseObject((TView*)GetObject(), is);
  is >> GetObject()->Origin;
  return GetObject();
}

void
TListView::Streamer::Write(opstream &os) const
{
  WriteBaseObject((TListBox*)GetObject(), os);
  WriteBaseObject((TView*)GetObject(), os);
  os << GetObject()->Origin;
}

#endif

