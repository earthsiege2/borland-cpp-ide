//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Tutorial application -- step11dv.cpp
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\dc.h>
#include <owl\inputdia.h>
#include <owl\chooseco.h>
#include <owl\gdiobjec.h>
#include <owl\docmanag.h>
#include <owl\filedoc.h>
#include <classlib\arrays.h>
#include "step11dv.rc"

typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;

class TLine : public TPoints {
  public:
    // Constructor to allow construction from a color and a pen size.
    // Also serves as default constructor.
    TLine(const TColor &color = TColor(0), int penSize = 1)
      : TPoints(10, 0, 10), PenSize(penSize), Color(color) {}

    // Functions to modify and query pen attributes.
    int QueryPenSize() const { return PenSize; }
    const TColor& QueryColor() const { return Color; }
    void SetPen(TColor &newColor, int penSize = 0);
    void SetPen(int penSize);

    // TLine draws itself.  Returns TRUE if everything went OK.
    virtual BOOL Draw(TDC &) const;

    // The == operator must be defined for the container class, even if unused
    BOOL operator ==(const TLine& other) const { return &other == this; }
    friend ostream& operator <<(ostream& os, const TLine& line);
    friend istream& operator >>(istream& is, TLine& line);

  protected:
    int PenSize;
    TColor Color;
};

typedef TArray<TLine> TLines;
typedef TArrayIterator<TLine> TLinesIterator;

class _DOCVIEWCLASS TDrawDocument : public TFileDocument
{
  public:
    TDrawDocument(TDocument* parent = 0) : TFileDocument(parent), Lines(0) {}
   ~TDrawDocument() { delete Lines; }

    // implement virtual methods of TDocument
    BOOL   Open(int mode, const char far* path=0);
    BOOL   Close();
    BOOL   IsOpen() { return Lines != 0; }
    BOOL   Commit(BOOL force = FALSE);
    BOOL   Revert(BOOL clear = FALSE);

    // data access functions
    const TLine* GetLine(unsigned int index);
    int    AddLine(TLine& line);

  protected:
    TLines* Lines;
};

class _DOCVIEWCLASS TDrawView : public TWindowView
{
  public:
    TDrawView(TDrawDocument& doc, TWindow *parent = 0);
   ~TDrawView() {delete DragDC; delete Line;}
    static const char far* StaticName() {return "Draw View";}

  protected:
    TDrawDocument* DrawDoc;  // same as Doc member, but cast to derived class
    TDC *DragDC;
    TPen *Pen;
    TLine *Line; // To hold a single line sent or received from document
    void GetPenSize(); // GetPenSize always calls Line->SetPen().

    // Message response functions
    void EvLButtonDown(UINT, TPoint&);
    void EvRButtonDown(UINT, TPoint&);
    void EvMouseMove(UINT, TPoint&);
    void EvLButtonUp(UINT, TPoint&);
    void Paint(TDC&, BOOL, TRect&);
    void CmPenSize();
    void CmPenColor();

    // Document notifications
    BOOL VnCommit(BOOL force);
    BOOL VnRevert(BOOL clear);

    DECLARE_RESPONSE_TABLE(TDrawView);
};

DEFINE_DOC_TEMPLATE_CLASS(TDrawDocument, TDrawView,   DrawTemplate);
DrawTemplate drawTpl("Point Files (*.PTS)","*.pts",0,"PTS",dtAutoDelete|dtUpdateDir);

void TLine::SetPen(int penSize)
{
  if (penSize < 1)
    PenSize = 1;
  else
    PenSize = penSize;
}

void TLine::SetPen(TColor &newColor, int penSize)
{
  // If penSize isn't the default (0), set PenSize to the new size.
  if (penSize)
    PenSize = penSize;

  Color = newColor;
}

BOOL TLine::Draw(TDC &dc) const
{
  // Set pen for the dc to the values for this line
  TPen pen(Color, PenSize);
  dc.SelectObject(pen);

  // Iterates through the points in the line i.
  TPointsIterator j(*this);
  BOOL first = TRUE;

  while (j) {
    TPoint p = j++;

    if (!first)
      dc.LineTo(p);
    else {
      dc.MoveTo(p);
      first = FALSE;
    }
  }
  dc.RestorePen();
  return TRUE;
}

ostream& operator <<(ostream& os, const TLine& line)
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

istream& operator >>(istream& is, TLine& line)
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

BOOL TDrawDocument::Commit(BOOL force)
{
  if (!IsDirty() && !force)
    return TRUE;

  TOutStream* os = OutStream(ofWrite);
  if (!os)
    return FALSE;

  // Write the number of lines in the figure
  *os << Lines->GetItemsInContainer();

  // Append a description using a resource string
  *os << ' ' << string(*GetDocManager().GetApplication(),IDS_FILEINFO) << '\n';

  // Get an iterator for the array of lines
  TLinesIterator i(*Lines);

  // While the iterator is valid (i.e. we haven't run out of lines)
  while (i) {
    // Copy the current line from the iterator and increment the array.
    *os << i++;
  }
  delete os;

  SetDirty(FALSE);
  return TRUE;
}

BOOL TDrawDocument::Revert(BOOL clear)
{
  if (!TFileDocument::Revert(clear))
    return FALSE;
  if (!clear)
    Open(0);
  return TRUE;
}

BOOL TDrawDocument::Open(int /*mode*/, const char far* path)
{
  Lines = new TLines(5, 0, 5);
  if (path)
    SetDocPath(path);
  if (GetDocPath()) {
    TInStream* is = InStream(ofRead);
    if (!is)
      return FALSE;

    unsigned numLines;
    char fileinfo[100];
    *is >> numLines;
    is->getline(fileinfo, sizeof(fileinfo));
    while (numLines--) {
      TLine line;
      *is >> line;
      Lines->Add(line);
    }
    delete is;
  }
  SetDirty(FALSE);
  return TRUE;
}

BOOL TDrawDocument::Close()
{
  delete Lines;
  Lines = 0;
  return TRUE;
}

const TLine* TDrawDocument::GetLine(unsigned int index)
{
  if (!IsOpen() && !Open(ofRead | ofWrite))
    return 0;
  return index < Lines->GetItemsInContainer() ? &(*Lines)[index] : 0;
}

int TDrawDocument::AddLine(TLine& line)
{
  int index = Lines->GetItemsInContainer();
  Lines->Add(line);
  SetDirty(TRUE);
  return index;
}

DEFINE_RESPONSE_TABLE1(TDrawView, TWindowView)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_COMMAND(CM_PENSIZE, CmPenSize),
  EV_COMMAND(CM_PENCOLOR, CmPenColor),
  EV_VN_COMMIT,
  EV_VN_REVERT,
END_RESPONSE_TABLE;

TDrawView::TDrawView(TDrawDocument& doc,TWindow *parent)
         : TWindowView(doc,parent), DrawDoc(&doc)
{
  DragDC = 0;
  Line = new TLine(TColor::Black, 1);
  SetViewMenu(new TMenuDescr(IDM_DRAWVIEW,0,1,0,0,0,0));
}

void TDrawView::EvLButtonDown(UINT, TPoint& point)
{
  if (!DragDC) {
    SetCapture();
    DragDC = new TClientDC(*this);
    Pen = new TPen(Line->QueryColor(), Line->QueryPenSize());
    DragDC->SelectObject(*Pen);
    DragDC->MoveTo(point);
    Line->Add(point);
  }
}

void TDrawView::EvRButtonDown(UINT, TPoint&)
{
  GetPenSize();
}

void TDrawView::EvMouseMove(UINT, TPoint& point)
{
  if (DragDC) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
}

void TDrawView::EvLButtonUp(UINT, TPoint&)
{
  if (DragDC) {
    ReleaseCapture();
    if (Line->GetItemsInContainer() > 1)
      DrawDoc->AddLine(*Line);
    Line->Flush();
    delete DragDC;
    delete Pen;
    DragDC = 0;
  }
}

void TDrawView::CmPenSize()
{
  GetPenSize();
}

void TDrawView::CmPenColor()
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
  colors.Color = TColor(Line->QueryColor());
  colors.CustColors = custColors;
  if (TChooseColorDialog(this, colors).Execute() == IDOK)
    Line->SetPen(colors.Color);
}

void TDrawView::GetPenSize()
{
  char inputText[6];
  int penSize = Line->QueryPenSize();

  wsprintf(inputText, "%d", penSize);
  if (TInputDialog(this, "Line Thickness",
                        "Input a new thickness:",
                        inputText,
                        sizeof(inputText),::Module).Execute() == IDOK) {
    penSize = atoi(inputText);

    if (penSize < 1)
      penSize = 1;
  }
  Line->SetPen(penSize);
}

void TDrawView::Paint(TDC& dc, BOOL, TRect&)
{
  // Iterates through the array of line objects.
  int i = 0;
  const TLine* line;
  while ((line = DrawDoc->GetLine(i++)) != 0)
    line->Draw(dc);
}

BOOL TDrawView::VnCommit(BOOL /*force*/)
{
  // nothing to do here, no data held in view
  return TRUE;
}

BOOL TDrawView::VnRevert(BOOL /*clear*/)
{
  Invalidate();  // force full repaint
  return TRUE;
}

