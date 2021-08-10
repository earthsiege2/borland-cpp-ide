//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//   Tutorial application -- step18dv.cpp
//   Automation Container Server example
//----------------------------------------------------------------------------

#define NO_VBX_PICTURES // So that vivbx.h's LPPICTURE does not conflict with
                        // olectl's LPPICTURE

#include <owl/pch.h>
#include <owl/dc.h>
#include <owl/inputdia.h>
#include <owl/chooseco.h>
#include <owl/gdiobjec.h>
#include <owl/docmanag.h>
#include <owl/listbox.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/scroller.h>  // scrolling support
#include <classlib/arrays.h>
#include <owl/olemdifr.h>
#include <owl/oledoc.h>
#include <owl/oleview.h>
#include <owl/edit.rh>
#include <owl/opensave.h>
#include <owl/messageb.h>
#include <ocf/automacr.h>
#include <ocf/ocdata.h>
#include <ocf/ocremvie.h>
#include <ocf/ocreg.h>
#include "step18dv.h"
#include "step18.h"
#include "step18dv.rc"
#include <olectl.h>
#include <tchar.h>

const char  DocContent[] = "All";
const char  DrawPadFormat[] = "DrawPad";

BEGIN_REGISTRATION(DocReg)
  REGDATA(progid,     "DrawPad.Drawing.18")
  REGDATA(description,"DrawPad (Step18--AutoContServer) Drawing")
  REGDATA(menuname,   "Drawing")
  REGDATA(extension,  "p18")
  REGDATA(docfilter,  "*.p18")
  REGDOCFLAGS(dtAutoOpen | dtAutoDelete | dtUpdateDir | dtCreatePrompt | dtRegisterExt)
//REGDATA(debugger,   "tdw")
  REGDATA(insertable, "")
//x  REGDATA(control, "")
  REGDATA(verb0,      "&Edit")
  REGDATA(verb1,      "&Open")
  REGFORMAT(0, DrawPadFormat,   ocrContent,  ocrHGlobal,              ocrGetSet)
  REGFORMAT(1, ocrEmbedSource,  ocrContent,  ocrIStorage,             ocrGetSet)
  REGFORMAT(2, ocrMetafilePict, ocrContent,  ocrMfPict|ocrStaticMed,  ocrGet)
  REGFORMAT(3, ocrBitmap,       ocrContent,  ocrGDI|ocrStaticMed,     ocrGet)
  REGFORMAT(4, ocrDib,          ocrContent,  ocrHGlobal|ocrStaticMed, ocrGet)
END_REGISTRATION
BEGIN_REGISTRATION(ListReg)
  REGDATA(description,"Line List")
  REGDATA(extension,  "p18")
  REGDATA(docfilter,  "*.p18")
  REGDOCFLAGS(dtAutoDelete | dtHidden)
END_REGISTRATION

DEFINE_DOC_TEMPLATE_CLASS(TDrawDocument, TDrawView,       DrawTemplate);
DEFINE_DOC_TEMPLATE_CLASS(TDrawDocument, TDrawListView,   DrawListTemplate);
DrawTemplate drawTpl(DocReg);
DrawListTemplate drawListTpl(ListReg);
HRESULT OcDispSetProp (IDispatch *pID, DISPID id, VARIANTARG *propVal);
HRESULT OcDispGetProp (IDispatch *pID, DISPID id, VARIANTARG *propVal);
HRESULT OcDispGetPropString (IDispatch *pID, DISPID id,
  char *propVal, int bufSize);

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
TLine::SetPen(const TColor& newColor, int penSize)
{
  // If penSize isn't the default (0), set PenSize to the new size.
  if (penSize)
    PenSize = penSize;

  Color = newColor;
}

void
TLine::Invalidate(TDrawView& view)
{
  TOleClientDC dc(view);

  TRect rUpdate(GetBound());
  rUpdate.Inflate(1, 1);
  dc.LPtoDP((TPoint *)&rUpdate, 2);
  TUIHandle handle(rUpdate, TUIHandle::Framed);
  rUpdate = handle.GetBoundingRect();

  view.GetDocument().NotifyViews(vnInvalidate, (long)&rUpdate, 0);
}

void
TLine::UpdateBound()
{
  // Iterates through the points in the line i.
  TPointsIterator j(*this);
  if (!j)
    return;
  TPoint p = j++;
  Bound.Set(p.x, p.y, 0, 0);

  while (j) {
    p = j++;
   if ((p.x - PenSize) < Bound.left)
     Bound.left = (p.x - PenSize);
   if ((p.x + PenSize) > Bound.right)
     Bound.right = (p.x + PenSize);
   if ((p.y - PenSize) < Bound.top)
     Bound.top = (p.y - PenSize);
   if ((p.y + PenSize) > Bound.bottom)
     Bound.bottom = (p.y + PenSize);
  }
  Bound.right  += 1;
  Bound.bottom += 1;
}

void
TLine::UpdatePosition(TPoint& newPos)
{
  for (TPointsIterator i(*this); i; i++) {
    TPoint* pt = (TPoint *)&i.Current();
    pt->x += newPos.x;
    pt->y += newPos.y;
  }

  Bound.Offset(newPos.x, newPos.y);
}

void
TLine::UpdateSize(TSize& newSize)
{
  TSize delta = newSize - GetSize();
  for (TPointsIterator i(*this); i; i++) {
    TPoint* pt = (TPoint *)&i.Current();
    pt->x += (((pt->x - Bound.left) * delta.cx + (GetSize().cx >> 1))/GetSize().cx);
    pt->y += (((pt->y - Bound.top) * delta.cy + (GetSize().cy >> 1))/GetSize().cy);
  }

  Bound.right = Bound.left + newSize.cx;
  Bound.bottom = Bound.top  + newSize.cy;
}

void
TLine::DrawSelection(TDC &dc)
{
  TUIHandle(Bound, TUIHandle::DashFramed).Paint(dc);
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

  TScreenDC dc;

  // 8.5"" x 11" draw document
  DocSize.cx = dc.GetDeviceCaps(LOGPIXELSX)* 85 / 10;
  DocSize.cy = dc.GetDeviceCaps(LOGPIXELSY)* 11;
}

TDrawDocument::~TDrawDocument()
{
  delete AutoLine;
  delete Lines;
  delete UndoLine;
}

TLine*
TDrawDocument::GetLine(TString& moniker)
{
  int index = atoi(moniker);
  return GetLine(index);
}

bool
TDrawDocument::CommitSelection(TOleWindow& oleWin, void* userData)
{
  TOleDocument::CommitSelection(oleWin, userData);

  TDrawView* drawView = TYPESAFE_DOWNCAST(&oleWin, TDrawView);
  TOutStream* os = OutStream(ofWrite);
  if (!os || !drawView)
    return false;

  // Make the line usable in a container by adjusting its origin
  //
  TLine* line = (TLine*)userData;
  int i = line? 1 : 0;
  TPoint newPos(Margin, Margin);
  if (line) {
    newPos -= line->GetBound().TopLeft();
    line->UpdatePosition(newPos);
  }

  // Write the number of lines in the figure
  *os << i;

  // Append a description using a resource string
  *os << ' ' << FileInfo << '\n';

  // Copy the current line from the iterator and increment the array.
  if (line)
    *os << *line;

  delete os;

  // restore line
  //
  if (line)
    line->UpdatePosition(-newPos);

  //
  // Commit the storage if it was opened in transacted mode
//  TOleDocument::CommitTransactedStorage();

  return true;
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

  TOleDocument::Open(mode, path);   // normally path should be null
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
      line.UpdateBound();
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

//
// Read in the lines from a storage and put them at the location specified
// by where
//
bool
TDrawDocument::OpenSelection(int mode, const char far* path, TPoint far* where)
{
  char fileinfo[100];

  TOleDocument::Open(mode, path);   // normally path should be null
  //if (GetDocPath()) {
    TInStream* is = (TInStream*)InStream(ofRead);
    if (!is)
      return false;

    unsigned numLines;
    *is >> numLines;
    is->getline(fileinfo, sizeof(fileinfo));
    while (numLines--) {
      TLine line;
      *is >> line;
      if (where) {
        TPoint newPos(where->x, where->y);
        newPos -= line.GetBound().TopLeft();
        line.UpdatePosition(newPos);
      }
      line.UpdateBound();
      Lines->Add(line);
    }

    delete is;

  if (GetDocPath()) {
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
  Lines->Flush();
  return TOleDocument::Close();
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

  wsprintf(inputText, "%d", line.QueryPenSize());
  if (TInputDialog(parent, "Line Thickness",
                   "Input a new thickness:",
                   inputText,
                   sizeof(inputText)).Execute() != IDOK)
    return false;
  line.SetPen(atoi(inputText));

  if (line.QueryPenSize() < 1)
    line.SetPen(1);

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

DEFINE_RESPONSE_TABLE1(TDrawLinkView, TOleLinkView)
  EV_VN_DRAWDELETE,
  EV_VN_DRAWMODIFY,
END_RESPONSE_TABLE;

TDrawLinkView::TDrawLinkView(TDocument& doc, TOcLinkView& view)
  :TOleLinkView(doc, view)
{
  DrawDoc = TYPESAFE_DOWNCAST(&doc, TDrawDocument);
  CHECK(DrawDoc);
}

TDrawLinkView::~TDrawLinkView()
{
}

//
// Line was modified
//
bool
TDrawLinkView::VnModify(uint index)
{
  // Get the selection correspondign to the moniker
  //
  TLine * line = DrawDoc->GetLine(GetMoniker());
  if (!line)
    return false;

  // Notify the container
  //
  if (index == DrawDoc->GetLines()->Find(*line)) {
    UpdateLinks();
  }

  return true;
}

//
// Line was deleted
//
bool
TDrawLinkView::VnDelete(uint index)
{
  // Get the selection correspondign to the moniker
  //
  TLine * line = DrawDoc->GetLine(GetMoniker());
  if (!line)
    return false;

  // Notify the container
  //
  if (index == DrawDoc->GetLines()->Find(*line)) {
    UpdateLinks();
  }
  return true;
}

DEFINE_RESPONSE_TABLE1(TDrawView, TOleView)
  EV_WM_LBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,

  EV_COMMAND(CM_NEWCONTROL, CmNewControl),
  EV_COMMAND(CM_CONTROLPROPS, CmControlProps),
  EV_COMMAND_ENABLE(CM_CONTROLPROPS, CeControlProps),
  EV_COMMAND(CM_CONTROLFONT, CmControlFont),
  EV_COMMAND(CM_CONTROLCAPTION, CmControlCaption),
  EV_COMMAND(CM_CONTAINERMODE, CmContainerMode),
  EV_COMMAND_ENABLE(CM_CONTAINERMODE, CeContainerMode),
  EV_COMMAND_ENABLE(CM_CONTROLCAPTION, CeControlProps),
  EV_COMMAND_ENABLE(CM_CONTROLFONT, CeControlProps),
  EV_COMMAND(CM_REGISTEROCX, CmRegisterControl),
  EV_COMMAND(CM_UNREGISTEROCX, CmUnregisterControl),
  EV_COMMAND(CM_PEN, CmPen),
  EV_COMMAND_ENABLE(CM_PEN, CePen),
  EV_COMMAND(CM_SELECT, CmSelect),
  EV_COMMAND_ENABLE(CM_SELECT, CeSelect),
  EV_COMMAND(CM_PENSIZE, CmPenSize),
  EV_COMMAND(CM_PENCOLOR, CmPenColor),
  EV_COMMAND(CM_EDITCLEAR, CmClear),
  EV_COMMAND(CM_EDITUNDO, CmUndo),
  EV_COMMAND(CM_EDITCUT, CmEditCut),
  EV_COMMAND(CM_EDITCOPY, CmEditCopy),
  EV_COMMAND_ENABLE(CM_EDITCUT, CeEditCut),
  EV_COMMAND_ENABLE(CM_EDITCOPY, CeEditCopy),
  EV_COMMAND(CM_ORGSIZE, CmOrgSize),
  EV_COMMAND(CM_DOUBLESIZE, CmDoubleSize),
  EV_COMMAND(CM_HALFSIZE, CmHalfSize),
  EV_COMMAND_ENABLE(CM_ORGSIZE, CeOrgSize),
  EV_COMMAND_ENABLE(CM_DOUBLESIZE, CeDoubleSize),
  EV_COMMAND_ENABLE(CM_HALFSIZE, CeHalfSize),
  EV_VN_COMMIT,
  EV_VN_REVERT,
  EV_VN_DRAWAPPEND,
  EV_VN_DRAWDELETE,
  EV_VN_DRAWMODIFY,

  EV_WM_SETFOCUS,
  EV_OC_VIEWPARTSIZE,
  EV_OC_VIEWSHOWTOOLS,
  EV_OC_VIEWGETITEMNAME,
  EV_OC_VIEWSETLINK,
  EV_OC_VIEWCLIPDATA,

END_RESPONSE_TABLE;

TDrawView::TDrawView(TDrawDocument& doc, TWindow* parent)
:
  TOleView(doc, parent), DrawDoc(&doc), pIFont (NULL)
{
  // this is temporary to let all control to paint
  // we need CLIPCHILDREN, so we'll put it back
  ModifyStyle(WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0);

  Selected  = 0;
  Tool      = DrawPen;
  ToolBar   = 0;

  Line = new TLine(TColor::Black, 1);
  Attr.AccelTable = IDA_DRAWVIEW;
  SetViewMenu(new TMenuDescr(IDM_DRAWVIEW));

  // Name our clipboard format
  //
  OcApp->AddUserFormatName("DrawPad Native Data", "Owl DrawPad native data", DrawPadFormat);

  IUnknown *pIU;
  OcApp->BOleComponentCreate (&pIU, NULL, cidBOleFont);
  pIU->QueryInterface (IID_IFontDisp, &(LPVOID)pIFont);
  pIU->Release ();
  backRGB = RGB (0xFF, 0x00, 0x00);
  designMode = FALSE;
}

TDrawView::~TDrawView()
{
  delete Line;
  if (pIFont)
    pIFont->Release ();
}

void
TDrawView::SetupWindow()
{
  TOleView::SetupWindow();

  // Scroll bars
  Attr.Style |= WS_VSCROLL | WS_HSCROLL;

  Scroller = new TScroller(this, 1, 1, 0, 0);
  AdjustScroller();

  // Set this option to force all embedded servers to open out of place
  // GetOcView()->SetOption(voNoInPlace,true);

  // Set this option to force all embedded servers to open out of place
  // when the container/server is inplace
  // GetOcView()->SetOption(voNoNestedInPlace,true);

}

//
// Adjust the Scroller range
//
void
TDrawView::AdjustScroller()
{
  TDrawDocument *drawDoc = TYPESAFE_DOWNCAST(&GetDocument(), TDrawDocument);
  CHECK(drawDoc);
  TSize range = drawDoc->GetDocSize();

  // Use device unit for scroll range
  //
  TOleClientDC dc(*this);
  dc.LPtoDP((TPoint*)&range);

  range -= GetClientRect().Size();
  Scroller->SetRange(range.cx, range.cy);
}

//
// Reset scroller range.
//
void
TDrawView::EvSize(UINT SizeType, TSize& Size)
{
  TOleView::EvSize(SizeType, Size);
  if (SizeType != SIZEICONIC) {
    AdjustScroller();
  }
}

static int
Intersect(const TLine& line, void* param)
{
  TPoint*  pt = (TPoint*)param;
  TLine &modify = const_cast<TLine&>(line);
  if (modify.IsSelected()) {
    modify.Where = TUIHandle(modify.GetBound(), TUIHandle::Framed).HitTest(*pt);
  }
  else {
    if (modify.GetBound().Contains(*pt))
      modify.Where = TUIHandle::MidCenter;
    else
      modify.Where = TUIHandle::Outside;
  }

  return line.Where != TUIHandle::Outside;
}

TLine*
TDrawView::HitTest(TPoint& pt)
{
  return DrawDoc->GetLines()->LastThat(Intersect, &pt);
}

bool
TDrawView::ShowCursor(HWND /*wnd*/, uint hitTest, uint /*mouseMsg*/)
{
  TPoint pt;
  GetCursorPos(pt);
  ScreenToClient(pt);
  if (Tool == DrawSelect) {
    ::SetCursor(::LoadCursor(0, IDC_ARROW));
    return true;
  }

  if (Tool == DrawPen && (hitTest == HTCLIENT)) {
    HCURSOR cur = ::LoadCursor(*GetModule(), MAKEINTRESOURCE(IDC_PENCIL));
    ::SetCursor(cur);
    return true;
  }

  if (Tool == DrawPen && ((hitTest == HTHSCROLL) || (hitTest == HTVSCROLL))) {
    ::SetCursor(::LoadCursor(0, IDC_ARROW));
    return true;
  }

  return false;
}


//
// Let container know about the server view size in pixels
//
bool
TDrawView::EvOcViewPartSize(TOcPartSize far& ps)
{
  TClientDC dc(*this);

  TRect rect(0, 0, 0, 0);
  TLine* line = 0;
  if (ps.Selection) {
    if (ps.Moniker) {
      if (strcmp(*ps.Moniker, OleStr(DocContent)) == 0)
        line = 0; // whole document
      else
        line = DrawDoc->GetLine(*ps.Moniker);
    }
    else{
      line = (TLine*) ps.UserData;
    }
  }

  if (line) {
    *(TPoint*)&rect.left   = line->GetBound().TopLeft();
    rect.right  = rect.left + line->GetBound().Width()  + 2 * Margin;
    rect.bottom = rect.top  + line->GetBound().Height() + 2 * Margin;
  }
  else {
    // a 2" x 2" extent for server
    //
    rect.right  = dc.GetDeviceCaps(LOGPIXELSX) * 2;
    rect.bottom = dc.GetDeviceCaps(LOGPIXELSY) * 2;
  }

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
      ToolBar->Insert(*new TButtonGadget(CM_PEN, CM_PEN, TButtonGadget::Exclusive));
      ToolBar->Insert(*new TButtonGadget(CM_SELECT, CM_SELECT, TButtonGadget::Exclusive));
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

//
// Find the item name for whole doc or selection
//
bool
TDrawView::EvOcViewGetItemName(TOcItemName& item)
{
  if (item.Selection) {
    if (!Selected)
      return false;
    char name[32];
    itoa(DrawDoc->GetLines()->Find(*Selected), name, 10);
    item.Name = name;
  }
  else {
    item.Name = "content"; // item name representing the whole document
  }
  return true;
}


//
// Ask server to provide data according to the format in a handle
//
bool
TDrawView::EvOcViewClipData(TOcFormatData far& formatData)
{
  if (strcmp(OleStr(formatData.Format.GetRegName()), OleStr(DrawPadFormat)) != 0)
    return false; // not our clipboard format

  bool status = true;
  if (formatData.Paste) { // Pasting native data
    DrawDoc->SetHandle(ofReadWrite, formatData.Handle, false);
    DrawDoc->OpenSelection(ofRead, 0, formatData.Where);
    Invalidate();
    // Restore the original storage
    //
    DrawDoc->RestoreStorage();

  }
  else { // Copying native data
    HANDLE data = GlobalAlloc(GHND|GMEM_SHARE, 0);
    DrawDoc->SetHandle(ofReadWrite, data, true);

    // Copy the selection if the target format is "DrawPad"
    //
    if (formatData.UserData) {
      status = DrawDoc->CommitSelection(*this, formatData.UserData);
    }
    else {
      status = DrawDoc->Commit(true);
    }

    formatData.Handle = data;
    // Restore the original storage
    //
    DrawDoc->RestoreStorage();
  }

  return status;
}

bool
TDrawView::EvOcAmbientGetBackColor(long *rgb)
{
  *rgb = backRGB;
  return true;
}

bool
TDrawView::EvOcAmbientGetFont(IDispatch** font)
{
  *font = pIFont;
  pIFont->AddRef ();
  return true;
}

bool
TDrawView::EvOcAmbientGetUserMode(bool* mode)
{
  *mode = (designMode == FALSE);
  return true;
}

bool
TDrawView::EvOcAmbientGetShowGrabHandles(bool* show)
{
  *show = designMode;
  return true;
}

bool
TDrawView::EvOcAmbientGetShowHatching(bool* show)
{
  *show = designMode;
  return true;
}

bool
TDrawView::EvOcAmbientGetDisplayAsDefault(bool* show)
{
  *show = (designMode == FALSE);
  return true;
}

bool
TDrawView::EvOcAmbientGetTextAlign(short* align)
{
  *align = 3;  // right justify
  return true;
}

bool
TDrawView::EvOcCtrlClick(TCtrlEvent*)
{
  MessageBeep (1);
  SetStatusText ("Click Event");
  return true;
}

bool
TDrawView::EvOcCtrlDblClick(TCtrlEvent*)
{
  MessageBeep (1);
  SetStatusText ("Double Click Event");
  return true;
}

bool
TDrawView::EvOcCtrlCustomEvent(TCtrlCustomEvent* pev)
{
  char       propString[256];
  ITypeInfo *pITypeInfo;
  LPTYPEATTR pTA;
  UINT       i, j;
  UINT       cEvents;

  propString[0] = '\0';
  lstrcat (propString, "Custom Event:  ");
  pITypeInfo = pev->Ctrl->GetEventTypeInfo ();
  MessageBeep (1);
  if (pITypeInfo)  {
    pITypeInfo->GetTypeAttr (&pTA);
    if (pTA) {
      cEvents = pTA->cFuncs;
      pITypeInfo->ReleaseTypeAttr (pTA);
      for (i = 0; i < cEvents; i++) {
        LPFUNCDESC    pFD;

        if (SUCCEEDED (pITypeInfo->GetFuncDesc (i, &pFD))) {
          if (pFD->memid == pev->Args->DispId) {
            UINT       cNames;
            BSTR       bstrName;       //Event name (function only)
            TAutoVal   Val;

            pITypeInfo->GetNames (pFD->memid, &bstrName, 1, &cNames);
            lstrcat (propString, OleStr (bstrName));
            SysFreeString (bstrName);
            pITypeInfo->ReleaseFuncDesc (pFD);

            lstrcat (propString, "    ");
            if ((pev->Args->ArgCount < 100) && (pev->Args->ArgCount > 0)) {  // rayk - bug check for how this is set
              for (j = 0; j < pev->Args->ArgCount; j++) {
                Val = (*pev->Args)[j];
                if ((Val.GetDataType() == VT_I4) ||
                    (Val.GetDataType() == VT_I2))
                  wsprintf (propString, "%s(int)Arg\[%d\]=0x%x; ",
                       propString, j, (int)(Val));
              }
            }
            SetStatusText (propString);
          }
        }
      }
    }
    pITypeInfo->Release();
  }
  return TRUE;
}

void
TDrawView::SetStatusText (char far* text)
{
  TOleFrame* mw =
        TYPESAFE_DOWNCAST(GetApplication()->GetMainWindow(), TOleFrame);
  TMessageBar* mb =
        TYPESAFE_DOWNCAST(mw->ChildWithId(IDW_STATUSBAR), TMessageBar);
  if (mb) {
#if defined(BI_DATA_NEAR)
    mb->SetText(string(text).c_str());
#else
    mb->SetText(text);
#endif
  }
}

//
// object selection
//
bool
TDrawView::Select(uint modKeys, TPoint& point)
{
  if (Tool != DrawSelect)
    return false;

  // Clicked in lines?
  TLine *line = HitTest(point);
  SetLineSelection(line);

  if (Selected) { // there is a selection
    TOleView::SetSelection(0);
    DragRect = line->GetBound();
    DragRect.right++;
    DragRect.bottom++;
    DragHit = line->Where;
    DragStart = DragPt = point;
    if (!DragDC)
      DragDC = new TOleClientDC(*this);

    DragDC->DrawFocusRect(DragRect);
    SetCapture();
    return true;
  }
  else
    // Select OLE object, if any
    return TOleView::Select(modKeys, point);

}

void
TDrawView::EvLButtonDown(uint modKeys, TPoint& point)
{
  TOleView::EvLButtonDown(modKeys, point);
  if (SelectEmbedded() || !DragDC)
    return;

  if (Tool == DrawSelect) { // selection
//    Select(modKeys, point);
  }
  else if (Tool == DrawPen) {
    SetCapture();
    Pen = new TPen(Line->QueryColor(), Line->QueryPenSize());
    DragDC->SelectObject(*Pen);
    DragRect.SetNull();
    DragDC->MoveTo(point);
    Line->Add(point);
  }
}

void
TDrawView::EvMouseMove(uint modKeys, TPoint& point)
{
  TOleView::EvMouseMove(modKeys, point);
  if (SelectEmbedded() || !DragDC)
    return;

  if (Tool == DrawPen) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
  else if (Selected && DragHit == TUIHandle::MidCenter &&
    !InClient(*DragDC, point)) { // selection
    DragDC->DrawFocusRect(DragRect);   // erase old rect

    // Start drag & drop
    //
    TOcDropAction outAction;
    TOcDataProvider* ocData = new TOcDataProvider(*OcView, &DocReg, 0,
                                                  (void*)Selected, CleanUp);
    OcApp->Drag(ocData, (TOcDropAction)(daDropCopy | daDropMove | daDropLink),
                outAction);

    if (outAction == daDropMove) {
      DrawDoc->DeleteLine(DrawDoc->GetLines()->Find(*Selected));
      SetLineSelection(0);
    }
    ocData->Release();
    DragHit = TUIHandle::Outside;
  }
}

void
TDrawView::SetLineSelection(TLine *Line)
{
  if (Selected) {
    Selected->Invalidate(*this);
    Selected->Select(false);
  }
  Selected = Line;
  if (Selected) {
    Selected->Select(true);
    Selected->Invalidate(*this);
  }
}

void
TDrawView::SetLineSelection(int index)
{
  SetLineSelection(DrawDoc->GetLine(index));
}

void TDrawView::EvLButtonUp(uint modKeys, TPoint& point)
{
  TPoint oldPoint = point;

  if (!DragDC)
    return;

  if ((Tool == DrawSelect) && !SelectEmbedded()) {
    if (Selected && DragHit == TUIHandle::MidCenter) {
      Selected->Invalidate(*this);
      DragDC->DPtoLP(&point);
      TPoint newPos = point - DragStart;
      Selected->UpdatePosition(newPos);
      Selected->Invalidate(*this);
      InvalidatePart(invView);
      DragHit = TUIHandle::Outside;
      ReleaseCapture();
    }
  } else if ((Tool == DrawPen) && !SelectEmbedded()) {
    ReleaseCapture();
    if (Line->GetItemsInContainer() > 1) {
      Line->UpdateBound();
      DrawDoc->AddLine(*Line);
    }

    Line->Flush();
    delete Pen;
  }

  TOleView::EvLButtonUp(modKeys, oldPoint);
}

void
TDrawView::CePen(TCommandEnabler& ce)
{
  ce.SetCheck(Tool == DrawPen);
}

void
TDrawView::CeSelect(TCommandEnabler& ce)
{
  ce.SetCheck(Tool == DrawSelect);
}

void
TDrawView::CeContainerMode(TCommandEnabler& ce)
{
  if (designMode)
    ce.SetCheck (1);
  else
    ce.SetCheck (0);
}

void
TDrawView::CeControlProps(TCommandEnabler& ce)
{
  bool CtrlActive = FALSE;
  TOcPart* p = OcView->GetActivePart();
  if (p) {
    IBControl *CtrlI;
    if (SUCCEEDED(p->QueryInterface(IID_IBControl, &(LPVOID)CtrlI))) {
      CtrlActive = TRUE;
      CtrlI->Release();
    }
  }
  ce.Enable(CtrlActive);
}

void
TDrawView::CmControlProps()
{
  TOcPart* p = OcView->GetActivePart();
  if (p) {

    char          propString[4096];
    char       temp[128];
    IDispatch *pID = NULL;
    TOcControl*  pCtrl;
    IBControl* pIU;

    ITypeInfo     *pITypeInfo = NULL;
    LPTYPEATTR     pTA;
    UINT           i;
    UINT           cVars, cEvents;

    if (FAILED (p->QueryInterface(IID_IBControl, &(LPVOID)pIU)))
      goto err2a;
    pIU->Release ();
    pCtrl = (TOcControl *)p;

    if (FAILED (pIU->GetCtrlDispatch(&pID)))
      goto err2a;

    //if (FAILED (pCtrl->QueryInterface(IID_IDispatch, &(LPVOID)pID)))
    //  goto err2a;

    pID->GetTypeInfo (0, 0, &pITypeInfo);
    if (!pITypeInfo)
      goto err2;

    pITypeInfo->GetTypeAttr (&pTA);
    if (!pTA)
      goto err;

    cEvents = pTA->cFuncs;
    cVars = pTA->cVars;
    pITypeInfo->ReleaseTypeAttr (pTA);

    propString[0] = '\0';
        lstrcat (propString, "\nMETHODS:\n");
    for (i = 0; i < cEvents; i++) {
      LPFUNCDESC    pFD;

      /*
       * The only piece of information we want from for each
       * event is the function name using ITypeInfo::GetNames.
       */

      if (SUCCEEDED (pITypeInfo->GetFuncDesc (i, &pFD)))
      {
        UINT       cNames;
        BSTR       bstrName;       //Event name (function only)

        pITypeInfo->GetNames (pFD->memid, &bstrName, 1, &cNames);
        lstrcat (propString, OleStr(bstrName));
        wsprintf (temp, "\(0x%08lX\)", pFD->memid);
        lstrcat (propString, temp);
        lstrcat (propString, "\n");
        SysFreeString (bstrName);
        pITypeInfo->ReleaseFuncDesc (pFD);
      }
   }

   lstrcat (propString, _TEXT("\nPROPERTIES:\n"));
   for (i = 0; i < cVars; i++) {
     LPVARDESC    pVD;
     BSTR         bstrName;

     if (SUCCEEDED (pITypeInfo->GetVarDesc (i, &pVD)))
     {
       UINT      cNames;

       pITypeInfo->GetNames (pVD->memid, &bstrName, 1, &cNames);
       lstrcat (propString, OleStr(bstrName));
       wsprintf (temp, "\(0x%08lX\)", pVD->memid);
       lstrcat (propString, temp);
       lstrcat (propString, ": ");
       if (SUCCEEDED (OcDispGetPropString (pID, pVD->memid, temp, 255)))
         lstrcat (propString, temp);

       lstrcat (propString, "\n");
       SysFreeString (bstrName);
       pITypeInfo->ReleaseVarDesc (pVD);
     }
   }

   if (pITypeInfo)
     pITypeInfo->Release ();

   lstrcat (propString, "\nEVENTS:\n");
   pITypeInfo = pCtrl->GetEventTypeInfo ();
   if (pITypeInfo)  {

     if (SUCCEEDED (pITypeInfo->GetTypeAttr(&pTA))) {

       cEvents = pTA->cFuncs;
       pITypeInfo->ReleaseTypeAttr (pTA);

       for (i=0; i < cEvents; i++)
       {
         LPFUNCDESC     pFD;

         if (SUCCEEDED (pITypeInfo->GetFuncDesc(i, &pFD)))
         {
           UINT       cNames;
           BSTR       bstrName;       //Event name (function only)

           pITypeInfo->GetNames (pFD->memid, &bstrName, 1, &cNames);
           lstrcat (propString, OleStr (bstrName));
           wsprintf (temp, "\(0x%08lX\)", pFD->memid);
           lstrcat (propString, temp);
                 lstrcat (propString, "\n");
           SysFreeString (bstrName);
           pITypeInfo->ReleaseFuncDesc (pFD);
         }
       }
     }
   }

   MessageBox (propString, "OCX Properties", MB_APPLMODAL);

err:
   if (pITypeInfo)
     pITypeInfo->Release();
err2:
   if (pID)
     pID->Release ();
err2a:
  }
}


void
TDrawView::CmControlFont ()
{
  TOcPart* p = OcView->GetActivePart();
  if (p) {
    IDispatch *pID;
    IDispatch *pIF;
    VARIANTARG result;
    VARIANTARG result2;

    IBControl* pICtrl;
    if (FAILED(p->QueryInterface(IID_IBControl, &(LPVOID)pICtrl)))
      return;
    pICtrl->Release();

                // get control's IDispatch
    if (FAILED(pICtrl->GetCtrlDispatch(&pID)))
      return;

                // ask for control's font
    if (SUCCEEDED (OcDispGetProp (pID, DISPID_FONT, &result))) {

      pIF = result.pdispVal;
      if (SUCCEEDED (OcDispGetProp (pIF, DISPID_FONT_BOLD, &result2))) {
        VariantChangeType( &result2, &result2, 0, VT_BOOL);
        result2.boolVal = result2.boolVal ? false : true;
        OcDispSetProp (pIF, DISPID_FONT_BOLD, &result2);
      }
            if (SUCCEEDED (OcDispGetProp (pIF, DISPID_FONT_SIZE, &result2))) {
              VariantChangeType( &result2, &result2, 0, VT_CY);
        #ifdef WIN32
              result2.cyVal.s.Lo = result2.cyVal.s.Lo + 20000;
              if (result2.cyVal.s.Lo > 140000)
                result2.cyVal.s.Lo = 60000;
        #else
              result2.cyVal.Lo = result2.cyVal.Lo + 20000;
        #endif
              OcDispSetProp (pIF, DISPID_FONT_SIZE, &result2);
            }
    }

    pID->Release();
  }
}


void
TDrawView::CmContainerMode ()
{
  designMode ^= TRUE;
  if (OcView) {
    ((TOcxView *) OcView)->SetUserMode (designMode == FALSE);
    ((TOcxView *) OcView)->SetDisplayAsDefault (designMode == FALSE);
    ((TOcxView *) OcView)->SetShowGrabHandles (designMode == TRUE);
    ((TOcxView *) OcView)->SetShowHatching (designMode == TRUE);
    ((TOcxView *) OcView)->SetUIDead (designMode == TRUE);
    TOleView::SetSelection(0);
  }
}


void
TDrawView::CmRegisterControl ()
{
  //
  // Create/Init TFileOpenDialog data structure
  //
  TOpenSaveDialog::TData *data;
  data = new TOpenSaveDialog::TData (OFN_FILEMUSTEXIST,
              "Ole Controls (*.ocx)\0*.ocx\0All Files (*.*)\0*.*\0",
              0, ".");

  //
  // Execute dialog and return status [copying new filename if necessary]
  //
  TFileOpenDialog fopenDlg(this, *data, 0, "Register Control");
  int ret = fopenDlg.Execute();

  if (ret == IDOK) {
    if (SUCCEEDED (OcRegisterControl (data->FileName)))
      MessageBox ("Control was successfully registered.", "OCX Registration", MB_APPLMODAL);
    else
      MessageBox ("Unable to register control.", "OCX Registration", MB_APPLMODAL);
  }
  delete data;
}


void
TDrawView::CmUnregisterControl ()
{
  TOcInitInfo initInfo (OcView);
  initInfo.Container = NULL; // use active document
  if (OcApp->BrowseControls (initInfo)) {
    if (SUCCEEDED (OcUnregisterControl (*(LPIID)initInfo.CId)))
      MessageBox ("Control was successfully unregistered.", "OCX Registration", MB_APPLMODAL);
    else
      MessageBox ("Unable to unregister control.", "OCX Registration", MB_APPLMODAL);
  }
}

void
TDrawView::CmControlCaption ()
{
  TOcPart* p = OcView->GetActivePart();
  if (p) {
    char       propString[256];
    IDispatch *pID;
    BSTR       bstrName;       //Event name (function only)
    VARIANTARG result;
    static int num = 0;

    IBControl* pIU;
    if (FAILED (p->QueryInterface(IID_IBControl, &(LPVOID)pIU)))
      return;
    pIU->Release ();

    if (FAILED (pIU->GetCtrlDispatch(&pID)))
      return;

    wsprintf (propString, "OCX #&%d", num++);
    bstrName = SysAllocString (propString);
    VariantInit (&result);
    result.vt = VT_BSTR;
    result.bstrVal = bstrName;
    OcDispSetProp (pID, DISPID_CAPTION, &result);
    SysFreeString (bstrName);
    pID->Release();
  }
}

void
TDrawView::CmNewControl()
{
  PRECONDITION(OcView);
  TOcInitInfo initInfo(OcView);
  static int count = 0;

  if (OcApp->BrowseControls(initInfo)) {
    TRect rect;
    GetInsertPosition(rect);
    rect.left += count * 40;
    rect.top  += count * 40;
    rect.right  = rect.left + 100;
    rect.bottom = rect.top + 100;
    TMyOcxEvent *pEv = new TMyOcxEvent ();
    TOcControl *ctrl = new TOcControl(*GetOcDoc(), 0, (TOcControlEvent *)pEv);
    ctrl->Init (&initInfo, rect);
    SetSelection (ctrl);
    CmControlCaption ();
    count++;

    OcView->Rename();
    InvalidatePart(invView);
  }
}

void
TDrawView::CmPen()
{
  Tool = DrawPen;
}

void
TDrawView::CmSelect()
{
  Tool = DrawSelect;
}

void
TDrawView::CmPenSize()
{
  if (Selected) {
    GetPenSize(this, *Selected);
    Selected->UpdateBound();
    DrawDoc->ModifyLine(*Selected, DrawDoc->GetLines()->Find(*Selected));
  }
  else
    GetPenSize(this, *Line);
}

void
TDrawView::CmPenColor()
{
  if (Selected) {
    GetPenColor(this, *Selected);
    DrawDoc->ModifyLine(*Selected, DrawDoc->GetLines()->Find(*Selected));
  }
  else
    GetPenColor(this, *Line);
}

void
TDrawView::CmOrgSize()
{
  SetScale(100);
}

void
TDrawView::CmDoubleSize()
{
  SetScale(200);
}

void
TDrawView::CmHalfSize()
{
  SetScale(50);
}

void
TDrawView::CeOrgSize(TCommandEnabler& ce)
{
  ce.SetCheck(!Scale.IsZoomed());
}

void
TDrawView::CeDoubleSize(TCommandEnabler& ce)
{
  ce.SetCheck(Scale.GetScale() == 200);
}

void
TDrawView::CeHalfSize(TCommandEnabler& ce)
{
  ce.SetCheck(Scale.GetScale() == 50);
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

void
TDrawView::CeEditCut(TCommandEnabler& ce)
{
  ce.Enable(Selected != 0 || SelectEmbedded());
}

void
TDrawView::CeEditCopy(TCommandEnabler& ce)
{
  ce.Enable(Selected != 0 || SelectEmbedded());
}

//
// method to clean up the userdata passed to TOcDataProvider
//
void
TDrawView::CleanUp(void* /*userData*/)
{
  // No data clean up to do here
}

void
TDrawView::CmEditCut()
{
  if (Selected) {
    // Create a TOcDataProvider with current selection
    //
    TOcDataProvider* ocData = new TOcDataProvider(*OcView, &DocReg, 0,
                                                  (void*)Selected, CleanUp);
    OcApp->Copy(ocData);

    // Ask server to render its data before it's deleted
    //
    ocData->Disconnect();
    ocData->Release();

    // Delete the line
    //
    DrawDoc->DeleteLine(DrawDoc->GetLines()->Find(*Selected));
    SetLineSelection(0);
  }
  else
    TOleView::CmEditCut();
}

void
TDrawView::CmEditCopy()
{
  if (Selected) {
    // Create a TOcDataProvider with current selection
    //
    TOcDataProvider* ocData = new TOcDataProvider(*OcView, &DocReg, 0,
                                                  (void*)Selected, CleanUp);
    OcApp->Copy(ocData);
    ocData->Release();
  }
  else
    TOleView::CmEditCopy();
}

void
TDrawView::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  bool metafile = (dc.GetDeviceCaps(TECHNOLOGY) == DT_METAFILE);

  // Iterates through the array of line objects.
  int j = 0;
  TLine* line;
  while ((line = const_cast<TLine *>(DrawDoc->GetLine(j++))) != 0) {
    line->Draw(dc);
    if (line->IsSelected() && !metafile)
      line->DrawSelection(dc);
  }
}

bool
TDrawView::PaintSelection(TDC& dc, bool /*erase*/, TRect& /*rect*/, void* userData)
{
  TLine* line = (TLine*) userData;
  if (!line)
    return false;

  TPoint newPos(Margin, Margin);
  newPos -= line->GetBound().TopLeft();
  line->UpdatePosition(newPos);
  line->Draw(dc);
  line->UpdatePosition(-newPos);

  return true;
}

// Establish link with whole doc or selection
//
bool
TDrawView::EvOcViewSetLink(TOcLinkView& view)
{
  // Attach a linked view to this document
  //
  new TDrawLinkView(GetDocument(), view);
  return true;
}

bool
TDrawView::PaintLink(TDC& dc, bool erase, TRect& rect, TString& moniker)
{
  //Draw the whole document if linking to the whole doc
  //
  if (strcmp(moniker, OleStr(DocContent)) == 0) {
    Paint(dc, erase, rect);
    return true;
  }

  // Find the selection with the corresponding moniker
  //
  TLine* line = DrawDoc->GetLine(moniker);

  if (!line)
    return false;

  TPoint newPos(Margin, Margin);
  newPos -= rect.TopLeft();
  line->UpdatePosition(newPos);
  line->Draw(dc);
  line->UpdatePosition(-newPos);
  return true;
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
  InvalidatePart(invView);
  return true;
}

bool
TDrawView::VnAppend(uint index)
{
  TLine* line = DrawDoc->GetLine(index);
  line->UpdateBound();
  line->Invalidate(*this);
  InvalidatePart(invView);
  return true;
}

bool
TDrawView::VnModify(uint /*index*/)
{
  Invalidate();  // force full repaint
  InvalidatePart(invView);
  return true;
}

bool
TDrawView::VnDelete(uint /*index*/)
{
  Invalidate();  // force full repaint
  InvalidatePart(invView);
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

TDrawListView::TDrawListView(TDrawDocument& doc,TWindow *parent)
       : TView(doc), TListBox(parent, GetNextViewId(), 0,0,0,0), DrawDoc(&doc)
{
  Attr.Style &= ~(WS_BORDER | LBS_SORT);
  Attr.Style |= LBS_NOINTEGRALHEIGHT;
  Attr.AccelTable = IDA_DRAWLISTVIEW;
  SetViewMenu(new TMenuDescr(IDM_DRAWLISTVIEW));
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


ObjectPtr GetMyControl(ObjectPtr ctl);

DEFINE_AUTOCLASS (TMyOcxEvent)
  EXPOSE_METHOD (SpinPositive,  TAutoLong,  "SpinPositive",   "SpinPositive",     0)
  EXPOSE_INHERIT (TOcControlEvent, "TOcControlEvent")
END_AUTOCLASS (TMyOcxEvent, tfNormal, "TMyOcx",   "TMyOcx class", 0)

ObjectPtr GetMyControl(ObjectPtr ctl)
{
  return (ObjectPtr) ((TOcControlEvent *)ctl)->GetControl();
}

void
TMyOcxEvent::InitEventDispatch()
{
  if (!pIEvents)
    (TUnknown *)pIEvents = CreateAutoObject(this, ClassInfo);
}

long
TMyOcxEvent::SpinPositive ()
{
  // this event is only applicable for spindial from the MS CDK
  MessageBox (0, "My Spin Positive Special Event", "Special Event Handler", MB_APPLMODAL);
  return 0;
}


HRESULT OcDispGetPropString (IDispatch *pID, DISPID id,
  char *propVal, int /*bufSize*/)
{
  VARIANTARG result;
  HRESULT    hr;
  if (SUCCEEDED (hr = OcDispGetProp (pID, id, &result))) {
    // Coerce to a string
    if (SUCCEEDED (VariantChangeType (&result, &result, 0,
        VT_BSTR )))  {
                        if (*(result.bstrVal))
        lstrcpy (propVal, OleStr(result.bstrVal));
      else
        *propVal = '\0';
    }
  }
  VariantClear (&result);
  return hr;
}


HRESULT OcDispGetProp (IDispatch *pID, DISPID id, VARIANTARG *propVal)
{
  DISPPARAMS args;

  VariantInit (propVal);
  args.rgvarg = NULL;
  args.cArgs = 0;
  args.cNamedArgs = 0;
  args.rgdispidNamedArgs = NULL;

  return pID->Invoke (id, IID_NULL,
      LOCALE_SYSTEM_DEFAULT,
      DISPATCH_PROPERTYGET, &args, propVal, NULL, NULL);
}


HRESULT OcDispSetProp (IDispatch *pID, DISPID id, VARIANTARG *propVal)
{
  HRESULT    hr;
  DISPPARAMS args;
  VARIANTARG name[1];
  DISPID     namedArgs[1];

  VariantInit (&name[0]);
  VariantCopy (&name[0], propVal);
  namedArgs[0] = DISPID_PROPERTYPUT;
  args.rgvarg = NULL;
  args.cArgs = 1;
  args.cNamedArgs = 1;
  args.rgvarg = name;
  args.rgdispidNamedArgs = namedArgs;
  hr = pID->Invoke (id, IID_NULL, LOCALE_SYSTEM_DEFAULT,
      DISPATCH_PROPERTYPUT, &args, NULL, NULL, NULL);
  VariantClear (&name[0]);
  return hr;
}
