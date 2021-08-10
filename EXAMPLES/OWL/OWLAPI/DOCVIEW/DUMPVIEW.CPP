//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   Implements class TDumpView
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\docmanag.h>
#include <owl\filedoc.h>
#include <owl\listbox.h>
#include <owl\inputdia.h>
#include <owl\dc.h>
#include "dumpview.rc"

struct TDumpData;

class _DOCVIEWCLASS TDumpView : public TListBox, public TView {
  public:
    TDumpView(TDocument& doc, TWindow* parent = 0);
   ~TDumpView();
    static LPCSTR StaticName() {return "Dump View";}  // put in resource

    //
    // overridden virtuals from TView
    //
    LPCSTR   GetViewName(){return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    BOOL     SetDocTitle(LPCSTR docname, int index)
                          {return TListBox::SetDocTitle(docname, index); }
    //
    // overridden virtuals from TWindow
    //
    BOOL     Create();
    BOOL     CanClose()   {return TListBox::CanClose() && Doc->CanClose();}
    int    MaxWidth;    // maximum horizontal extent

  protected:
    long Origin;
    long FileSize;
    int  UpdateMode; // 0=NotEditing, 1=HighNibble, 2=LowNibble, -1=Flushing
    int  CharWidth;
    int  CharHeight;
    int  EditByte;
    int  EditLine;
    TDumpData* Changes;
    void Init();
    BOOL LoadData(int top, int sel);
    void FormatLine(int index, TDumpData* data);
    BOOL NewEditLine(int line, int byte);
    void EndEditLine();
    void KillChanges();
        
  private:
    //
    // message response functions
    //
    BOOL VnCommit(BOOL force);
    BOOL VnRevert(BOOL clear);
    BOOL VnIsWindow(HWND hWnd) {return HWindow == hWnd;}
    BOOL VnIsDirty();
    BOOL VnDocClosed(int omode);
    void CmEditUndo();
    void CmEditItem();
    void EvPaint();
    void EvKeyDown(UINT key, UINT repeatCount, UINT flags);
    void EvLButtonDown(UINT modKeys, TPoint& point);
    void EvLButtonDblClk(UINT modKeys, TPoint& point);
    void CmSelChange(){} // to prevent interpreting as unprocessed accelerator

  DECLARE_RESPONSE_TABLE(TDumpView);
  DECLARE_STREAMABLE(,TDumpView,1);
};

DIAG_DECLARE_GROUP(OwlDocView);        // General Doc/View diagnostic group

const int DisplayLines = 16;   // initial list box size
const int ListBoxMax = 100;    // max number of lines stored in list box
const int DataWidth = 8;       // number of data bytes per line
const int AddrWidth = 2;       // number of bytes in address
const int LineWidth = AddrWidth*2 + 1 + DataWidth*3 + DataWidth;

struct TDumpData {
   long       Addr;
   char       Old[DataWidth];
   char       New[DataWidth];
   int        Count;
   TDumpData* Next;
};

DEFINE_RESPONSE_TABLE1(TDumpView, TListBox)
  EV_WM_KEYDOWN,
  EV_COMMAND(CM_DUMPUNDO,    CmEditUndo),
  EV_COMMAND(CM_DUMPEDIT,    CmEditItem),
  EV_WM_PAINT,
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONDBLCLK,
  EV_VN_DOCCLOSED,
  EV_VN_ISWINDOW,
  EV_VN_ISDIRTY,
  EV_VN_COMMIT,
  EV_VN_REVERT,
  EV_NOTIFY_AT_CHILD(LBN_SELCHANGE, CmSelChange),
END_RESPONSE_TABLE;

TDumpView::TDumpView(TDocument& doc, TWindow* parent)
         : TView(doc), TListBox(parent, GetNextViewId(), 0,0,0,0)
{
  Init();
  Attr.Style &= ~(WS_BORDER | LBS_SORT);
  Attr.Style |= (LBS_DISABLENOSCROLL);
  Attr.AccelTable = IDA_DUMPVIEW;
  SetViewMenu(new TMenuDescr(IDM_DUMPVIEW,0,1,0,0,0,1));
}

void
TDumpView::Init()
{
  Origin = 0;
  UpdateMode = 0;
  Changes = 0;
}

BOOL
TDumpView::VnDocClosed(int omode)
{
  int top;
  int sel;
  if (UpdateMode == -1 || !(omode & ofWrite))  // make sure someone else's write
    return FALSE;
  top = GetTopIndex();
  sel = GetSelIndex();
  ClearList();
  LoadData(top, sel);
  return TRUE;
}

static char HexDigit(int i)
{
  char c = char((i & 15) + '0');
  if (c > '9')
    c += char('A' - ('9' + 1));
  return c;
}

void
TDumpView::FormatLine(int line, TDumpData* data)
{
  char buf[LineWidth + 2];
  int index;
  char* pbuf;
  char* pasc;
  unsigned char chr;
  long addr = data->Addr;

  for (index = AddrWidth*2; --index >= 0; addr >>= 4)
    buf[index] = HexDigit((int)addr);
  pbuf = buf + AddrWidth*2;
  *pbuf++ = ' ';
  pasc = pbuf + DataWidth*3;
  for (index = 0; index < DataWidth; index++) {
    if (index < data->Count) {
      chr = data->New[index];
      *pbuf++ = HexDigit(chr >> 4);
      *pbuf++ = HexDigit(chr);
      pasc[index] = char((chr >= 0x20 && chr < 0x7F) ? chr : 0x7F);
    } else {
      *pbuf++ = ' ';
      *pbuf++ = ' ';
      pasc[index] = ' ';
    }
    *pbuf++ = ' ';
  }
  pasc[DataWidth] = 0;  // null terminate buffer
  InsertString(buf, line);
}

static long GetAddr(int index)
{
   return index * DataWidth;
   // need to add origin!
}

static int GetIndex(long addr)
{
   return int(addr / DataWidth);
   // need to subtract origin!
}

BOOL
TDumpView::LoadData(int top, int sel)
{
  TDumpData data;
  istream* inStream;
  int count;

  if ((inStream = Doc->InStream(ofRead | ofBinary)) == 0)
    return FALSE;

  for (count=0, data.Addr=0; count<ListBoxMax; count++,data.Addr+=DataWidth) {
    inStream->read(data.New, DataWidth);
    if ((data.Count = inStream->gcount()) == 0)
      break;
    FormatLine(-1, &data);
    if (data.Count != DataWidth)
      break;
  }
  SetTopIndex(top);
  SetSelIndex(sel);
  delete inStream;   // close file in case process switch
  return TRUE;
}

BOOL
TDumpView::Create()
{
  TRect rect;
  LOGFONT fontinfo;
  HGDIOBJ font = GetStockObject(SYSTEM_FIXED_FONT);
  TListBox::Create();   // throws exception TXInvalidWindow
  SendMessage(WM_SETFONT, (UINT)font, 0L);
  GetObject(font, sizeof(LOGFONT), &fontinfo);
  CharWidth  = fontinfo.lfWidth;
  CharHeight = fontinfo.lfHeight;
  GetClientRect(rect);   // created with 0,0 size, .right is -scroll bar size
  if (rect.right < 0) {  // if new view, else streaming in presized window
    rect.right = LineWidth * CharWidth + (-rect.right+2) + CharWidth/2;
    rect.bottom = CharHeight * DisplayLines;
    MoveWindow(rect);
  //if (!Parent->IsFlagSet(wfMainWindow))// prevent parent shrink if main window
      Parent->SetFlag(wfShrinkToClient);
  }
  if (Doc->GetDocPath() == 0) {  
    return TRUE;           // new file, no data to display
  }
  if (!LoadData(0, 0))
    NotOK();
  return TRUE;
}

BOOL
TDumpView::VnCommit(BOOL /*force*/)
{
  TDumpData* edit;
  ostream* outStream;

  EndEditLine();
  if (!Changes)
    return TRUE;
  if ((outStream = Doc->OutStream(ofReadWrite | ofBinary)) == 0)
    return FALSE;
  while ((edit = Changes) != 0) {
    outStream->seekp(edit->Addr);
    outStream->write(edit->New, edit->Count);
    // test goodbit
    Changes = Changes->Next;
    delete edit;
  }
  UpdateMode = -1;         // to detect our own close notification
  outStream->seekp(0,ios::end);
  delete outStream;
  return TRUE;
}

BOOL
TDumpView::VnRevert(BOOL clear)
{
  EndEditLine();
  KillChanges();
  ClearList();
  return (!clear && Doc->GetDocPath() != 0) ? LoadData(0, 0) : TRUE;
}

TDumpView::~TDumpView()
{
  KillChanges();
}

BOOL
TDumpView::NewEditLine(int line, int byte)
{
  istream* inStream;
  TDumpData* edit;
  TRect rect;
  BOOL stat = TRUE;
  if (line < 0)
    return FALSE;
  SetSelIndex(line);  // restore index in case changes
  if (UpdateMode > 0) {
    return FALSE;
  }
  if ((inStream = Doc->InStream(ofRead | ofBinary)) == 0)
    return FALSE;
  if ((edit = new TDumpData) == 0)
    return FALSE;
  edit->Addr = GetAddr(line);
  inStream->seekg(edit->Addr);
  // test goodbit
  inStream->read(edit->Old, DataWidth);
  if ((edit->Count = inStream->gcount()) > 0) {
    memcpy(edit->New, edit->Old, edit->Count);
    UpdateMode = 1;
    GetItemRect(line, rect);
    InvalidateRect(rect);
    edit->Next = Changes;
    Changes = edit;
    while (byte >= edit->Count)
      byte--;
    EditByte = byte;
    EditLine = line;
  } else {
    delete edit;
    stat = FALSE;
  }
  delete inStream;
  return stat;
}

BOOL
TDumpView::VnIsDirty()
{
  return (Changes
          && (Changes->Next
              || memcmp(Changes->New, Changes->Old, Changes->Count) != 0));
}

void
TDumpView::EndEditLine()
{
  TDumpData* edit = Changes;
  if (UpdateMode > 0) {
    TRect rect;
    GetItemRect(EditLine, rect);
    InvalidateRect(rect);
    if (memcmp(edit->New, edit->Old, edit->Count) == 0) {
      Changes = Changes->Next;
      delete edit;
    }
  }
  UpdateMode = 0;
}

void
TDumpView::KillChanges()
{
  TDumpData* edit;
  while ((edit = Changes) != 0) {
    Changes = Changes->Next;
    delete edit;
  }
}

void
TDumpView::EvLButtonDown(UINT modKeys, TPoint& point)
{
  if (UpdateMode > 0) {
    int index = ((point.x*2 - CharWidth)/(CharWidth*2) - AddrWidth*2)/3;
    if (index >= 0 && index < Changes->Count) {
      EditByte = index;
      UpdateMode = 1;
      TRect rect;
      GetItemRect(EditLine, rect);
      InvalidateRect(rect);
    }
  } else {
    TListBox::EvLButtonDown(modKeys, point);
  }
}

void
TDumpView::EvLButtonDblClk(UINT /*modKeys*/, TPoint& point)
{
  int index = ((point.x*2 - CharWidth)/(CharWidth*2) - AddrWidth*2)/3;
  if (index < 0 || index >= DataWidth)
    index = 0;
  int line = point.y/CharHeight + GetTopIndex();
  if (UpdateMode <= 0 || line != EditLine) {
    EndEditLine();
    NewEditLine(line, index);
  }
}

void
TDumpView::EvKeyDown(UINT key, UINT repeatCount, UINT flags)
{
  char oldchr, newchr;
  MSG msg;

  if (UpdateMode <= 0) {
    if (key != VK_LEFT && key != VK_RIGHT)
      TListBox::EvKeyDown(key, repeatCount, flags);
    return;
  }
  switch (key) {
    case VK_ESCAPE:  // abort changes to current line
      CmEditUndo();
      return;

    case VK_RETURN:  // enter changes for current line, not committed yet
      EndEditLine();
      break;

    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
      key += ('0' + 10) - 'A';  // fall through to digit cases
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      newchr = char(key - '0');
      oldchr = Changes->New[EditByte];
      ::PeekMessage(&msg, HWindow, WM_CHAR, WM_CHAR, PM_REMOVE);
      switch(UpdateMode) {
        case 1:
          newchr = char((oldchr & 0x0F) + (newchr<<4));
          break;
        case 2:
          newchr = char((oldchr & 0xF0) + newchr);
          break;
        default:
          return;
      } 
      Changes->New[EditByte] = newchr;
      DeleteString(EditLine);
      FormatLine(EditLine, Changes);
      SetSelIndex(EditLine);
      if (UpdateMode++ == 2 && EditByte < Changes->Count-1) {
        EditByte++;
        UpdateMode = 1;
      }
      break;
    case VK_UP:  
    case VK_DOWN:
    case VK_PRIOR:
    case VK_NEXT:
    case VK_END:
    case VK_HOME:
      if (UpdateMode > 0)
        return;       
      break;
    case VK_LEFT:
      if (UpdateMode <= 0 || EditByte == 0)
        return;       
      UpdateMode = 1;
      EditByte--;
      break;
    case VK_RIGHT:
      if (UpdateMode <= 0 || EditByte >= (Changes->Count-1))
        return;
      UpdateMode = 1;
      EditByte++;
      break;
    default:
      break;
  }
  TRect rect;
  GetItemRect(EditLine, rect);
  InvalidateRect(rect);
}

void
TDumpView::EvPaint()
{
  TRegion updateRgn;
  GetUpdateRgn(updateRgn);
  DefaultProcessing();  // predefined class, don't call TWindow
//TWindow::EvPaint();
  if (UpdateMode <= 0)
    return;
  if (GetSelIndex() != EditLine) { /*::MessageBeep(MB_ICONEXCLAMATION);*/ return;}
  if (GetTopIndex() > EditLine || (GetTopIndex()+DisplayLines) <= EditLine)
    return;
  TRect rect;
  GetItemRect(EditLine, rect);
  rect.left += CharWidth * (AddrWidth*2+1+EditByte*3) + 1;
  rect.right = rect.left + CharWidth * 2;
  // should check if in update region!
  TClientDC dc(HWindow);
  dc.SelectClipRgn(updateRgn);
  dc.IntersectClipRect(rect);
//GetUpdateRgn(updateRgn);
  dc.InvertRgn(updateRgn);
}

void
TDumpView::CmEditUndo()
{
  TRect rect;
  TDumpData* edit;

  UpdateMode = 0;
  if (!Changes)
    return;
  int index = GetIndex(Changes->Addr);
  DeleteString(index);
  memcpy(Changes->New, Changes->Old, Changes->Count);
  FormatLine(index, Changes);
  SetSelIndex(index);
  edit = Changes;
  Changes = Changes->Next;
  delete edit;
  GetItemRect(index, rect);
  InvalidateRect(rect);
}

void
TDumpView::CmEditItem()
{
  int line = GetSelIndex();
  if (UpdateMode > 0) {
    if (line == EditLine)
      return;
    EndEditLine();
  }
  NewEditLine(line, 0);
}

IMPLEMENT_STREAMABLE2(TDumpView, TListBox, TView);

void*
TDumpView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TListBox*)GetObject(), is);
  ReadBaseObject((TView*)GetObject(), is);
  is >> GetObject()->Origin;
  GetObject()->Init();
  return GetObject();
}

void
TDumpView::Streamer::Write(opstream &os) const
{
  WriteBaseObject((TListBox*)GetObject(), os);
  WriteBaseObject((TView*)GetObject(), os);
  os << GetObject()->Origin;
}

DEFINE_DOC_TEMPLATE_CLASS(TFileDocument, TDumpView, DumpTemplate);
DumpTemplate dumpTpl("DumpView, Binary files", "*.obj;*.res", 0, 0,
                     dtAutoDelete | dtUpdateDir);
