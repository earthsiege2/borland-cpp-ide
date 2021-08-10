//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implements class TEditView
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/editview.h>
#include <owl/docview.rh>
#include <owl/editview.rh>

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
:
  TEditSearch(parent, GetNextViewId()),
  TView(doc),
  Origin(0)
{
  Attr.AccelTable = IDA_EDITVIEW;
  if (::FindResource(*GetModule(), TResId(IDM_EDITVIEW), RT_MENU))
    SetViewMenu(new TMenuDescr(IDM_EDITVIEW, 0,2,0,0,0,1, GetModule()));
}

void
TEditView::EvNCDestroy()
{
#if !defined(BI_PLAT_WIN32)
  HGLOBAL hdl = (HGLOBAL)::GlobalHandle((uint)GetWindowWord(GWW_HINSTANCE));
#endif
  TEditSearch::EvNCDestroy();// call TWindow::EvNCDestroy, this may be deleted
#if !defined(BI_PLAT_WIN32)
  if (hdl) {
    ::GlobalUnlock(hdl);
    ::GlobalFree(hdl);
  }
#endif
}

TEditView::~TEditView()
{
}

bool
TEditView::VnDocClosed(int omode)
{
  if (VnIsDirty() || !(omode & ofWrite))  // make sure someone else's write
    return false;

  int top = GetFirstVisibleLine();
  uint selbeg;
  uint selend;
  TEdit::GetSelection(selbeg, selend);
  TEdit::Clear();
  LoadData();
  Scroll(0, top);
  TEdit::SetSelection(selbeg, selend);

  return true;
}

bool
TEditView::LoadData()
{
  istream* inStream;
  if ((inStream = Doc->InStream(ios::in | ios::binary)) == 0) {
    Doc->PostError(IDS_UNABLEOPEN, MB_OK);
    return false;
  }
  inStream->seekg(0L, ios::end);
  unsigned long total = inStream->tellg();
  inStream->seekg(0L, ios::beg);
  uint count = (total > MAX_EDIT_BUF) ? MAX_EDIT_BUF : (uint)total;
  char far* buf = LockBuffer(count + 1);
  if (!buf) {
    delete inStream;
//    THROW( TXOutOfMemory() );
    Doc->PostError(IDS_NOMEMORYFORVIEW, MB_OK);
    return false;
  }

  uint len;
#if defined(BI_DATA_NEAR)
  char xbuf[512];
  uint pos = 0;
  do {
    len = (count-pos > sizeof(xbuf) ? sizeof(xbuf) : count-pos);
    inStream->read(xbuf, len);
    if (inStream->gcount() != len)
      break;  // if error test again below
    memcpy(buf+pos, (char far*)xbuf, len);
    pos += len;
  } while (pos < count);
#else
  inStream->read(buf, len = count);
#endif

  bool status = (inStream->gcount() == len);
  buf[count] = 0;    // 0 terminate buffer
  UnlockBuffer(buf, true);
  delete inStream;   // close file in case process switch
  if (!status)
    Doc->PostError(IDS_READERROR, MB_OK);

  return status;
}

bool
TEditView::Create()
{
  TRY {
    TEditSearch::Create();   // throws exception TWindow::TXWindow
  }
  CATCH( (TXOwl& x) {
    Doc->PostError(IDS_NOMEMORYFORVIEW, MB_OK);
    NotOK();
    return true;   // cannot return false - throws another exception
  })
  if (Doc->GetDocPath() == 0) {  
    return true;           // new file, no data to display
  }
  if (!LoadData())
    NotOK();
  return true;
}

void
TEditView::PerformCreate(int menuOrId)
{
#if defined(BI_PLAT_WIN32)
  HINSTANCE hInst = *GetModule();
#else
  HGLOBAL hdl = ::GlobalAlloc(GHND, 256);  // will grow as needed
  if (!hdl) {
//  Doc->PostError(IDS_NOMEMORYFORVIEW, MB_OK);
//  return;
    THROW( TXOutOfMemory() );
  }
  uint16 editDS = FP_SEG(::GlobalLock(hdl));
  ::LocalInit(editDS, 0, 0);
  ::GlobalUnlock(hdl);
  HINSTANCE hInst = (HINSTANCE)hdl;
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

bool
TEditView::VnCommit(bool force)
{
  if (!force && !(VnIsDirty()))
    return true;

  ostream* outStream;
  if ((outStream = Doc->OutStream(ios::out | ios::binary)) == 0) {
    Doc->PostError(IDS_UNABLEOPEN, MB_OK);
    return false;
  }
  outStream->seekp(Origin);

  bool status = false;
  char far* buf = LockBuffer();
  if (buf) {
    uint count = strlen(buf);
#if defined(BI_DATA_NEAR)
    char xbuf[512];
    uint len;
    uint pos = 0;
    do {
      len = count-pos > sizeof(xbuf) ? sizeof(xbuf) : count-pos;
      memcpy((char far*)xbuf, buf+pos, len);
      outStream->write(xbuf, len);
      if (!outStream->good())
        break;  // if error test again below
      pos += len;
    } while (pos < count);
#else
    outStream->write(buf, count);
#endif
    status = ToBool(outStream->good());
    UnlockBuffer(buf);
    ClearModify();   // reset edit control
  }
  delete outStream;
  if (!status)
    Doc->PostError(IDS_WRITEERROR, MB_OK);

  return status;
}

bool
TEditView::VnRevert(bool clear)
{
  TEdit::Clear();
  ClearModify();   // reset edit control
  return clear ? true : LoadData();
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
