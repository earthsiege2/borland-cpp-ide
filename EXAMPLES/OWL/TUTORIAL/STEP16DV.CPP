//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//   Tutorial application -- step16dv.cpp
//   Automation Server example
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/dc.h>
#include <owl/inputdia.h>
#include <owl/chooseco.h>
#include <owl/gdiobjec.h>
#include <owl/docmanag.h>
#include <owl/listbox.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <classlib/arrays.h>
#include <owl/olemdifr.h>
#include <owl/oledoc.h>
#include <owl/oleview.h>
#include <ocf/automacr.h>
#include "step16dv.h"
#include "step16.h"
#include "step16dv.rc"

BEGIN_REGISTRATION(DocReg)
  REGDATA(progid,     "DrawPad.Drawing.16")
  REGDATA(description,"DrawPad (Step16--AutoServer) Drawing")
  REGDATA(menuname,   "Drawing")
  REGDATA(extension,  "p16")
  REGDATA(docfilter,  "*.p16")
  REGDOCFLAGS(dtAutoOpen | dtAutoDelete | dtUpdateDir | dtCreatePrompt | dtRegisterExt)
//REGDATA(debugger,   "tdw")
  REGDATA(insertable, "")
  REGDATA(verb0,      "&Edit")
  REGDATA(verb1,      "&Open")
  REGFORMAT(0, ocrEmbedSource,  ocrContent,  ocrIStorage,  ocrSet)
  REGFORMAT(1, ocrMetafilePict, ocrContent,  ocrMfPict|ocrStaticMed, ocrGet)
END_REGISTRATION
BEGIN_REGISTRATION(ListReg)
  REGDATA(description,"Line List")
  REGDATA(extension,  "p16")
  REGDATA(docfilter,  "*.p16")
  REGDOCFLAGS(dtAutoDelete | dtHidden)
END_REGISTRATION

DEFINE_DOC_TEMPLATE_CLASS(TDrawDocument, TDrawView,       DrawTemplate);
DEFINE_DOC_TEMPLATE_CLASS(TDrawDocument, TDrawListView,   DrawListTemplate);
DrawTemplate drawTpl(DocReg);
DrawListTemplate drawListTpl(ListReg);

//===============================  TLine  =====================================
//
void
TLine::SetPen(int penSize)
{
  if (penSize < 1)
    PenSize = 1;
  else
    PenSize = penSize;
}

void
TLine::SetPen(TColor& newColor, int penSize)
{
  // If penSize isn't the default (0), set PenSize to the new size.
  if (penSize)
    PenSize = penSize;

  Color = newColor;
}

bool
TLine::Draw(TDC& dc) const
{
  // Set pen for the dc to the values for this line
  TPen pen(Color, PenSize, PS_INSIDEFRAME);
  dc.SelectObject(pen);

  // Iterates through the points in the line i.
  TPointsIterator j(*this);
  bool first = true;

  while (j) {
    TPoint p = j++;

    if (!first)
      dc.LineTo(p);
    else {
      dc.MoveTo(p);
      first = false;
    }
  }
  dc.RestorePen();
  return true;
}

ostream&
operator <<(ostream& os, const TLine& line)
{
  // Write the number of points in the line
  os << line.GetItemsInContainer();

  // Get and write pen attributes.
  os << ' ' << line.Color << ' ' << line.PenSize;

  // Get an iterator for the array of points
  TPointsIterator j(line);

  // While the iterator is valid (i.e. we haven't run out of points)
  while(j)
    // Write the point from the iterator and increment the array.
    os << j++;
  os << '\n';

  // return the stream object
  return os;
}

istream&
operator >>(istream& is, TLine& line)
{
  unsigned numPoints;
  is >> numPoints;

  COLORREF color;
  int penSize;
  is >> color >> penSize;
  line.SetPen(TColor(color), penSize);

  while (numPoints--) {
    TPoint point;
    is >> point;
    line.Add(point);
  }

  // return the stream object
  return is;
}

DEFINE_AUTOCLASS(TDrawDocument)
  EXPOSE_PROPRW(PenSize,    TAutoShort, "PenSize",    "Current pen size", 0)
  EXPOSE_PROPRW(PenColor,   TAutoLong,  "PenColor",   "Current pen color", 0)
  EXPOSE_METHOD(AddPoint,   TAutoVoid,  "AddPoint",   "Add a point to the current line", 0)
   REQUIRED_ARG(            TAutoShort, "X")
   REQUIRED_ARG(            TAutoShort, "Y")
  EXPOSE_METHOD(AddLine,    TAutoVoid,  "AddLine",    "Add current line into drawing", 0)
  EXPOSE_METHOD(ClearLine,  TAutoVoid,  "ClearLine",  "Erases current line", 0)
  EXPOSE_APPLICATION(       TDrawApp,   "Application","Application object", 0)
END_AUTOCLASS(TDrawDocument, tfNormal,  "TDrawDoc",   "Draw document class", 0)

TDrawDocument::TDrawDocument(TDocument* parent)
  : TOleDocument(parent), UndoLine(0), UndoState(UndoNone)
{
  Lines         = new TLines(100, 0, 5);
  AutoPenSize   = 1;
  AutoPenColor  = RGB(0, 0, 0);
  AutoLine      = new TLine(AutoPenColor, AutoPenSize);
}

TDrawDocument::~TDrawDocument()
{
  delete AutoLine;
  delete Lines;
  delete UndoLine;
}

bool
TDrawDocument::Commit(bool force)
{
  TOleDocument::Commit(force);

  TOutStream* os = OutStream(ofWrite);
  if (!os)
    return false;

  // Write the number of lines in the figure
  *os << Lines->GetItemsInContainer();

  // Append a description using a resource string
  *os << ' ' << FileInfo << '\n';

  // Get an iterator for the array of lines
  TLinesIterator i(*Lines);

  // While the iterator is valid (i.e. we haven't run out of lines)
  while (i) {
    // Copy the current line from the iterator and increment the array.
    *os << i++;
  }
  delete os;

  //
  // Commit the storage if it was opened in transacted mode
  TOleDocument::CommitTransactedStorage();
  SetDirty(false);

  return true;
}

bool
TDrawDocument::Open(int mode, const char far* path)
{
  char fileinfo[100];

  TOleDocument::Open(mode, path);
  if (GetDocPath()) {
    TInStream* is = (TInStream*)InStream(ofRead);
    if (!is)
      return false;

    unsigned numLines;
    *is >> numLines;
    is->getline(fileinfo, sizeof(fileinfo));
    while (numLines--) {
      TLine line;
      *is >> line;
      Lines->Add(line);
    }

    delete is;

    FileInfo = fileinfo;
  } else {
    FileInfo = string(*::Module,IDS_FILEINFO);
  }
  SetDirty(false);
  UndoState = UndoNone;
  return true;
}

bool
TDrawDocument::Close()
{
  if (TOleDocument::Close()) {
    Lines->Flush();
    return true;
  }

  return false;
}

TLine*
TDrawDocument::GetLine(uint index)
{
  return index < Lines->GetItemsInContainer() ? &(*Lines)[index] : 0;
}

int
TDrawDocument::AddLine(TLine& line)
{
  int index = Lines->GetItemsInContainer();
  Lines->Add(line);
  SetDirty(true);
  NotifyViews(vnDrawAppend, index);
  UndoState = UndoAppend;
  return index;
}

void
TDrawDocument::DeleteLine(uint index)
{
  const TLine* oldLine = GetLine(index);
  if (!oldLine)
    return;
  delete UndoLine;
  UndoLine = new TLine(*oldLine);
  Lines->Detach(index);
  SetDirty(true);
  NotifyViews(vnDrawDelete, index);
  UndoState = UndoDelete;
}

void
TDrawDocument::ModifyLine(TLine& line, uint index)
{
  delete UndoLine;
  UndoLine = new TLine((*Lines)[index]);
  SetDirty(true);
  (*Lines)[index] = line;
  NotifyViews(vnDrawModify, index);
  UndoState = UndoModify;
  UndoIndex = index;
}

void
TDrawDocument::Clear()
{
  Lines->Flush();
  NotifyViews(vnRevert, true);
}

void
TDrawDocument::Undo()
{
  switch (UndoState) {
    case UndoAppend:
      DeleteLine(Lines->GetItemsInContainer()-1);
      return;
    case UndoDelete:
      AddLine(*UndoLine);
      delete UndoLine;
      UndoLine = 0;
      return;
    case UndoModify:
      TLine* temp = UndoLine;
      UndoLine = 0;
      ModifyLine(*temp, UndoIndex);
      delete temp;
  }
}

bool
GetPenSize(TWindow* parent, TLine& line)
{
  char inputText[6];

  wsprintf(inputText, "%d", line.PenSize);
  if (TInputDialog(parent, "Line Thickness",
                   "Input a new thickness:",
                   inputText,
                   sizeof(inputText)).Execute() != IDOK)
    return false;
  line.PenSize = atoi(inputText);

  if (line.PenSize < 1)
    line.PenSize = 1;

  return true;
}

bool
GetPenColor(TWindow* parent, TLine& line)
{
  TChooseColorDialog::TData colors;
  static TColor custColors[16] =
  {
    0x010101L, 0x101010L, 0x202020L, 0x303030L,
    0x404040L, 0x505050L, 0x606060L, 0x707070L,
    0x808080L, 0x909090L, 0xA0A0A0L, 0xB0B0B0L,
    0xC0C0C0L, 0xD0D0D0L, 0xE0E0E0L, 0xF0F0F0L
  };

  colors.Flags = CC_RGBINIT;
  colors.Color = TColor(line.QueryColor());
  colors.CustColors = custColors;
  if (TChooseColorDialog(parent, colors).Execute() != IDOK)
    return false;
  line.SetPen(colors.Color);
  return true;
}

DEFINE_RESPONSE_TABLE1(TDrawView, TOleView)
  EV_WM_LBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_COMMAND(CM_PENSIZE, CmPenSize),
  EV_COMMAND(CM_PENCOLOR, CmPenColor),
  EV_COMMAND(CM_EDITCLEAR, CmClear),
  EV_COMMAND(CM_EDITUNDO, CmUndo),
  EV_VN_COMMIT,
  EV_VN_REVERT,
  EV_VN_DRAWAPPEND,
  EV_VN_DRAWDELETE,
  EV_VN_DRAWMODIFY,
  EV_OC_VIEWPARTSIZE,
  EV_OC_VIEWSHOWTOOLS,
END_RESPONSE_TABLE;

TDrawView::TDrawView(TDrawDocument& doc, TWindow* parent)
:
  TOleView(doc, parent), DrawDoc(&doc)
{
  Line      = new TLine(TColor::Black, 1);
  Attr.AccelTable = IDA_DRAWVIEW;
  SetViewMenu(new TMenuDescr(IDM_DRAWVIEW));
  ToolBar = 0;
}

//
// Let container know about the server view size in pixels
//
bool
TDrawView::EvOcViewPartSize(TOcPartSize far& ps)
{
  TClientDC dc(*this);

  TRect rect(0, 0, 0, 0);
  // a 2" x 2" extent for server
  //
  rect.right  = dc.GetDeviceCaps(LOGPIXELSX) * 2;
  rect.bottom = dc.GetDeviceCaps(LOGPIXELSY) * 2;

  ps.PartRect = rect;
  return true;
}

bool
TDrawView::EvOcViewShowTools(TOcToolBarInfo far& tbi)
{
  // Construct & create a control bar for show, destroy our bar for hide
  //
  if (tbi.Show) {
    if (!ToolBar) {
      ToolBar = new TControlBar(this);
      ToolBar->Insert(*new TButtonGadget(CM_PENSIZE, CM_PENSIZE, TButtonGadget::Command));
      ToolBar->Insert(*new TButtonGadget(CM_PENCOLOR, CM_PENCOLOR, TButtonGadget::Command));
      ToolBar->Insert(*new TSeparatorGadget);
      ToolBar->Insert(*new TButtonGadget(CM_ABOUT, CM_ABOUT, TButtonGadget::Command));
      ToolBar->SetHintMode(TGadgetWindow::EnterHints);
    }
    ToolBar->Create();
    tbi.HTopTB = (HWND)*ToolBar;
  }
  else {
    if (ToolBar) {
      ToolBar->Destroy();
      delete ToolBar;
      ToolBar = 0;
    }
  }
  return true;
}

void
TDrawView::EvLButtonDown(uint modKeys, TPoint& point)
{
  TOleView::EvLButtonDown(modKeys, point);

  if (DragDC) {
    SetCapture();
    Pen = new TPen(Line->QueryColor(), Line->QueryPenSize());
    DragDC->SelectObject(*Pen);
    DragDC->MoveTo(point);
    Line->Add(point);
  }
}

void
TDrawView::EvMouseMove(uint modKeys, TPoint& point)
{
  TOleView::EvMouseMove(modKeys, point);

  if (DragDC) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
}

void
TDrawView::EvLButtonUp(uint modKeys, TPoint& point)
{
  if (DragDC) {
    ReleaseCapture();
    if (Line->GetItemsInContainer() > 1)
      DrawDoc->AddLine(*Line);
    Line->Flush();
    delete Pen;
  }

  TOleView::EvLButtonUp(modKeys, point);
}

void
TDrawView::CmPenSize()
{
  GetPenSize(this, *Line);
}

void
TDrawView::CmPenColor()
{
  GetPenColor(this, *Line);
}

void
TDrawView::CmClear()
{
  DrawDoc->Clear();
}

void
TDrawView::CmUndo()
{
  DrawDoc->Undo();
}

//
// Paint into the window dc
//
void
TDrawView::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  // Iterates through the array of line objects.
  int j = 0;
  TLine* line;
  while ((line = const_cast<TLine *>(DrawDoc->GetLine(j++))) != 0)
    line->Draw(dc);
}

bool
TDrawView::VnCommit(bool /*force*/)
{
  // nothing to do here, no data held in view
  return true;
}

bool
TDrawView::VnRevert(bool /*clear*/)
{
  Invalidate();  // force full repaint
  InvalidatePart(invView); // OC server change
  return true;
}

bool
TDrawView::VnAppend(uint index)
{
  TClientDC dc(*this);
  const TLine* line = DrawDoc->GetLine(index);
  bool metafile = dc.GetDeviceCaps(TECHNOLOGY) == DT_METAFILE;
  SetupDC(dc, !metafile);
  line->Draw(dc);
  InvalidatePart(invView);
  return true;
}

bool
TDrawView::VnModify(uint /*index*/)
{
  Invalidate();  // force full repaint
  InvalidatePart(invView); // OC server change
  return true;
}

bool
TDrawView::VnDelete(uint /*index*/)
{
  Invalidate();  // force full repaint
  InvalidatePart(invView); // OC server change
  return true;
}

DEFINE_RESPONSE_TABLE1(TDrawListView, TListBox)
  EV_COMMAND(CM_PENSIZE, CmPenSize),
  EV_COMMAND(CM_PENCOLOR, CmPenColor),
  EV_COMMAND(CM_EDITCLEAR, CmClear),
  EV_COMMAND(CM_EDITUNDO, CmUndo),
  EV_COMMAND(CM_EDITDELETE, CmDelete),
  EV_VN_ISWINDOW,
  EV_VN_COMMIT,
  EV_VN_REVERT,
  EV_VN_DRAWAPPEND,
  EV_VN_DRAWDELETE,
  EV_VN_DRAWMODIFY,
END_RESPONSE_TABLE;

TDrawListView::TDrawListView(TDrawDocument& doc,TWindow* parent)
       : TView(doc), TListBox(parent, GetNextViewId(), 0,0,0,0), DrawDoc(&doc)
{
  Attr.Style &= ~(WS_BORDER | LBS_SORT);
  Attr.Style |= LBS_NOINTEGRALHEIGHT;
  Attr.AccelTable = IDA_DRAWLISTVIEW;
  SetViewMenu(new TMenuDescr(IDM_DRAWLISTVIEW));
}

bool
TDrawListView::CanClose()
{
  TView* curView = Doc->GetViewList();
  while (curView) {
    if (curView != this)
      return true;

    curView = curView->GetNextView();
  }

  return Doc->CanClose();
}

bool
TDrawListView::Create()
{
  TListBox::Create();
  LoadData();
  return true;
}

void
TDrawListView::LoadData()
{
  ClearList();
  int i = 0;
  const TLine* line;
  while ((line = DrawDoc->GetLine(i)) != 0)
    FormatData(line, i++);

  SetSelIndex(0);
}

void
TDrawListView::FormatData(const TLine* line, int unsigned index)
{
  char buf[80];
  TColor color(line->QueryColor());
  wsprintf(buf, "Color = R%d G%d B%d, Size = %d, Points = %d",
           color.Red(), color.Green(), color.Blue(),
           line->QueryPenSize(), line->GetItemsInContainer());
  DeleteString(index);
  InsertString(buf, index);
  SetSelIndex(index);
}

void
TDrawListView::CmPenSize()
{
  int index = GetSelIndex();
  const TLine* line = DrawDoc->GetLine(index);
  if (line) {
    TLine* newline = new TLine(*line);
    if (GetPenSize(this, *newline))
      DrawDoc->ModifyLine(*newline, index);
    delete newline;
  }
}

void
TDrawListView::CmPenColor()
{
  int index = GetSelIndex();
  const TLine* line = DrawDoc->GetLine(index);
  if (line) {
    TLine* newline = new TLine(*line);
    if (GetPenColor(this, *newline))
      DrawDoc->ModifyLine(*newline, index);
    delete newline;
  }
}

void
TDrawListView::CmClear()
{
  DrawDoc->Clear();
}

void
TDrawListView::CmUndo()
{
  DrawDoc->Undo();
}

void
TDrawListView::CmDelete()
{
  DrawDoc->DeleteLine(GetSelIndex());
}

bool
TDrawListView::VnCommit(bool /*force*/)
{
  return true;
}

bool
TDrawListView::VnRevert(bool /*clear*/)
{
  LoadData();
  return true;
}

bool
TDrawListView::VnAppend(uint index)
{
  const TLine* line = DrawDoc->GetLine(index);
  FormatData(line, index);
  SetSelIndex(index);
  return true;
}

bool
TDrawListView::VnDelete(uint index)
{
  DeleteString(index);
  HandleMessage(WM_KEYDOWN,VK_DOWN); // force selection
  return true;
}

bool
TDrawListView::VnModify(uint index)
{
  const TLine* line = DrawDoc->GetLine(index);
  FormatData(line, index);
  return true;
}

static char* PropNames[] = {
  "Line Count",      // LineCount
  "Description",       // Description
};

static int PropFlags[] = {
  pfGetBinary|pfGetText, // LineCount
  pfGetText,             // Description
};

const char*
TDrawDocument::PropertyName(int index)
{
  if (index <= PrevProperty)
    return TStorageDocument::PropertyName(index);  // OC server change
  else if (index < NextProperty)
    return PropNames[index-PrevProperty-1];
  else
    return 0;
}

int
TDrawDocument::PropertyFlags(int index)
{
  if (index <= PrevProperty)
    return TStorageDocument::PropertyFlags(index); // OC server change
  else if (index < NextProperty)
    return PropFlags[index-PrevProperty-1];
  else
    return 0;
}

int
TDrawDocument::FindProperty(const char far* name)
{
  for (int i=0; i < NextProperty-PrevProperty-1; i++)
    if (strcmp(PropNames[i], name) == 0)
      return i+PrevProperty+1;
  return 0;
}

int
TDrawDocument::GetProperty(int prop, void far* dest, int textlen)
{
  switch(prop) {
    case LineCount: {
      int count = Lines->GetItemsInContainer();
      if (!textlen) {
        *(int far*)dest = count;
        return sizeof(int);
      }
      return wsprintf((char far*)dest, "%d", count);
    }
    case Description:
      char* temp = new char[textlen]; // need local copy for medium model
      int len = FileInfo.copy(temp, textlen);
      strcpy((char far*)dest, temp);
      return len;
  }
  return TStorageDocument::GetProperty(prop, dest, textlen); // OC server change
}
