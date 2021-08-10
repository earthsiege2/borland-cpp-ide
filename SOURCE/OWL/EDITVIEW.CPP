//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   include\owl\editview.cpp
//   Implements class TEditView
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\editview.h>
#include <owl\docview.rc>
#include <owl\editview.rc>

DIAG_DECLARE_GROUP(OwlDocView);        // General Doc/View diagnostic group

#if !defined(SECTION) || SECTION == 1

#define MAX_EDIT_BUF (30000)  // can't add new chars after 30,000 bytes

//
//  class TEditView
//  ----- ---------
//
DEFINE_RESPONSE_TABLE1(TEditView, TEditSearch)
  EV_VN_DOCCLOSED,
  EV_VN_ISWINDOW,
  EV_VN_ISDIRTY,
  EV_VN_COMMIT,
  EV_VN_REVERT,
  EV_WM_NCDESTROY,
END_RESPONSE_TABLE;

TEditView::TEditView(TDocument& doc, TWindow* parent)
         : TEditSearch(parent, GetNextViewId()), TView(doc), Origin(0)
{
  Attr.AccelTable = IDA_EDITVIEW;
  SetViewMenu(new TMenuDescr(IDM_EDITVIEW,0,2,0,0,0,1));
}

void
TEditView::EvNCDestroy()
{
#if !defined(__WIN32__)
  HGLOBAL hdl = (HGLOBAL)GlobalHandle((UINT)GetWindowWord(GWW_HINSTANCE));
#endif
  TEditSearch::EvNCDestroy();// call TWindow::EvNCDestroy, this may be deleted
#if !defined(__WIN32__)
  if (hdl) {
    GlobalUnlock(hdl);
    GlobalFree(hdl);
  }
#endif
}

TEditView::~TEditView()
{
}

BOOL
TEditView::VnDocClosed(int omode)
{
  int top;
  UINT selbeg;
  UINT selend;

  if (VnIsDirty() || !(omode & ofWrite))  // make sure someone else's write
    return FALSE;
  top = GetFirstVisibleLine();
  TEdit::GetSelection(selbeg, selend);
  TEdit::Clear();
  LoadData();
  Scroll(0, top);
  TEdit::SetSelection(selbeg, selend);
  return TRUE;
}

BOOL
TEditView::LoadData()
{
  unsigned long total;
  UINT count, len;
  LPSTR buf;
  istream* inStream;
  BOOL status;

  if ((inStream = Doc->InStream(ios::in | ios::binary)) == 0) {
    Doc->PostError(IDS_UNABLEOPEN, MB_OK);
    return FALSE;
  }
  inStream->seekg(0L, ios::end);
  total = inStream->tellg();
  inStream->seekg(0L, ios::beg);
  if (total > MAX_EDIT_BUF)
    count = MAX_EDIT_BUF;
  else
    count = (UINT)total;
  buf = LockBuffer(count + 1);
  if (!buf){
    delete inStream;
//    THROW( TXOutOfMemory() );
    Doc->PostError(IDS_NOMEMORYFORVIEW, MB_OK);
    return FALSE;
  }
#if defined(__SMALL__) || defined(__MEDIUM__)
  char xbuf[512];
  UINT pos = 0;
  do {
    len = (count-pos > sizeof(xbuf) ? sizeof(xbuf) : count-pos);
    inStream->read(xbuf, len);
    if (inStream->gcount() != len)
      break;  // if error test again below
    memcpy(buf+pos, (LPSTR)xbuf, len);
    pos += len;
  } while (pos < count);
#else
  inStream->read(buf, len = count);
#endif
  status = (inStream->gcount() == len);
  buf[count] = 0;  // null terminate buffer
  UnlockBuffer(buf, TRUE);
  delete inStream;   // close file in case process switch
  if (!status)
    Doc->PostError(IDS_READERROR, MB_OK);
  return status;
}

BOOL
TEditView::Create()
{
  TRY {
    TEditSearch::Create();   // throws exception TWindow::TXWindow
  }
  CATCH( (TXOwl& x) {
    Doc->PostError(IDS_NOMEMORYFORVIEW, MB_OK);
    NotOK();
    return TRUE;   // cannot return FALSE - throws another exception
  })
  if (Doc->GetDocPath() == 0) {  
    return TRUE;           // new file, no data to display
  }
  if (!LoadData())
    NotOK();
  return TRUE;
}

void
TEditView::PerformCreate(int menuOrId)
{
  HINSTANCE hInst;
#if defined(__WIN32__)
  hInst = *GetModule();
#else
  HGLOBAL hdl;
  hdl = ::GlobalAlloc(GHND, 256);  // will grow as needed
  if (!hdl) {
//  Doc->PostError(IDS_NOMEMORYFORVIEW, MB_OK);
//  return;
    THROW( TXOutOfMemory() );
  }
  WORD editDS = FP_SEG(GlobalLock(hdl));
  LocalInit(editDS, 0, 0);
  GlobalUnlock(hdl);
  hInst = (HINSTANCE)hdl;
#endif
// if (doc readonly || size too large) Attr.Style |= ES_READONLY;
  HWindow = CreateWindowEx(Attr.ExStyle,
                           GetClassName(),
                           Title,
                           Attr.Style,
                           Attr.X, Attr.Y, Attr.W, Attr.H,
                           Parent ? Parent->HWindow : 0,
                           (HMENU)menuOrId,
                           hInst,
                           Attr.Param);
}

BOOL
TEditView::VnCommit(BOOL force)
{
  UINT count;
  LPSTR buf;
  ostream* outStream;
  BOOL status = FALSE;

  if (!force && !(VnIsDirty()))
    return TRUE;
  if ((outStream = Doc->OutStream(ios::out | ios::binary)) == 0) {
    Doc->PostError(IDS_UNABLEOPEN, MB_OK);
    return FALSE;
  }
  outStream->seekp(Origin);
  buf = LockBuffer();
  if (buf) {
    count = strlen(buf);
#if defined(__SMALL__) || defined(__MEDIUM__)
    char xbuf[512];
    UINT len;
    UINT pos = 0;
    do {
      len = count-pos > sizeof(xbuf) ? sizeof(xbuf) : count-pos;
      memcpy((LPSTR)xbuf, buf+pos, len);
      outStream->write(xbuf, len);
      if (!outStream->good())
        break;  // if error test again below
      pos += len;
    } while (pos < count);
#else
    outStream->write(buf, count);
#endif
    status = outStream->good();
    UnlockBuffer(buf);
    ClearModify();   // reset edit control
  }
  delete outStream;
  if (!status)
    Doc->PostError(IDS_WRITEERROR, MB_OK);
  return status;
}

BOOL
TEditView::VnRevert(BOOL clear)
{
  TEdit::Clear();
  ClearModify();   // reset edit control
  return clear ? TRUE : LoadData();
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE2(TEditView, TEditSearch, TView);

void*
TEditView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TEditSearch*)GetObject(), is);
  ReadBaseObject((TView*)GetObject(), is);
  is >> GetObject()->Origin;
  return GetObject();
}

void
TEditView::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TEditSearch*)GetObject(), os);
  WriteBaseObject((TView*)GetObject(), os);
  os << GetObject()->Origin;
}

#endif
