//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//
//   Implements classes TDrawDocument, TDrawView, TDrawListView
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/docmanag.h>
#include <owl/filedoc.h>
#include <owl/dc.h>
#include <owl/inputdia.h>
#include <owl/chooseco.h>
#include <owl/gdiobjec.h>
#include <owl/listbox.h>
#include <owl/docview.h>
#include <classlib/arrays.h>
#include <stdio.h>
#include "linedoc.rc"

typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;

class TLine : public TPoints {
  public:
    // Constructor to allow construction from a color and a pen size.
    // Also serves as default constructor.
    //
    TLine(const TColor &color = TColor(0), int penSize = 1)
      : TPoints(10, 0, 10), PenSize(penSize), Color(color) {}

    // Functions to modify and query pen attributes.
    //
    int QueryPenSize() const { return PenSize; }
    const TColor& QueryColor() const { return Color; }
    void SetPen(const TColor& newColor, int penSize = 0);
    void SetPen(int penSize);
    bool GetPenSize();
    bool GetPenColor();

    // TLine draws itself.  Returns true if everything went OK.
    //
    virtual bool Draw(TDC&) const;

    // The == operator must be defined for the container class, even if unused
    //
    bool operator ==(const TLine& other) const { return &other == this; }
    friend ostream& operator <<(ostream& os, const TLine& line);
    friend istream& operator >>(istream& is, TLine& line);

  protected:
    int    PenSize;
    TColor Color;
};

typedef TArray<TLine> TLines;
typedef TArrayIterator<TLine> TLinesIterator;

class _DOCVIEWCLASS TDrawDocument : public TFileDocument {
  public:
    enum {
      PrevProperty = TFileDocument::NextProperty-1,
      LineCount,
      Description,
      NextProperty,
    };

    enum {
      UndoNone,
      UndoDelete,
      UndoAppend,
      UndoModify
    };

    TDrawDocument(TDocument* parent = 0)
        : TFileDocument(parent), Lines(0), UndoLine(0), UndoState(UndoNone) {}
   ~TDrawDocument() { delete Lines; delete UndoLine; }

    // Implement virtual methods of TDocument
    //
    bool   Open(int mode, const char far* path=0);
    bool   Close();
    bool   IsOpen() { return Lines != 0; }
    bool   Commit(bool force = false);
    bool   Revert(bool clear = false);

    int         FindProperty(const char far* name);  // return index
    int         PropertyFlags(int index);
    const char* PropertyName(int index);
    int         PropertyCount() {return NextProperty - 1;}
    int         GetProperty(int index, void far* dest, int textlen=0);

    // data access functions
    //
    const TLine* GetLine(unsigned int index);
    int    AddLine(TLine& line);
    void   DeleteLine(unsigned int index);
    void   ModifyLine(TLine& line, unsigned int index);
    void   Clear();
    void   Undo();

  protected:
    TLines* Lines;
    TLine* UndoLine;
    int    UndoState;
    int    UndoIndex;
    string FileInfo;

  DECLARE_STREAMABLE(, TDrawDocument,1);
};

class _DOCVIEWCLASS TDrawView : public TWindowView
{
  public:
    TDrawView(TDrawDocument& doc, TWindow *parent = 0);
   ~TDrawView() {delete DragDC; delete Line;}
    static const char far* StaticName() {return "Draw View";}
    const char far* GetViewName(){return StaticName();}

  protected:
    TDrawDocument* DrawDoc;  // same as Doc member, but cast to derived class
    TDC *DragDC;
    TPen *Pen;
    TLine *Line; // To hold a single line sent or received from document

    // Message response functions
    void EvLButtonDown(uint, TPoint&);
    void EvRButtonDown(uint, TPoint&);
    void EvMouseMove(uint, TPoint&);
    void EvLButtonUp(uint, TPoint&);
    void Paint(TDC&, bool, TRect&);
    void CmPenSize();
    void CmPenColor();
    void CmClear();
    void CmUndo();

    // Document notifications
    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnAppend(unsigned int index);
    bool VnDelete(unsigned int index);
    bool VnModify(unsigned int index);

  DECLARE_RESPONSE_TABLE(TDrawView);
  DECLARE_STREAMABLE(,TDrawView,1);
};

class _DOCVIEWCLASS TDrawListView : public TListBox, public TView {
  public:
    TDrawListView(TDrawDocument& doc, TWindow* parent = 0);
   ~TDrawListView(){}
    static const char far* StaticName() {return "DrawList View";}

    // Overridden virtuals from TView
    //
    const char far* GetViewName(){return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    bool     SetDocTitle(const char far* docname, int index)
                          {return TListBox::SetDocTitle(docname, index); }

    // Overridden virtuals from TWindow
    //
    bool CanClose()   {return TListBox::CanClose() && Doc->CanClose();}
    bool Create();

  protected:
    TDrawDocument* DrawDoc;  // same as Doc member, but cast to derived class
    void LoadData();
    void FormatData(const TLine* line, unsigned int index);

    // Message response functions
    void CmPenSize();
    void CmPenColor();
    void CmClear();
    void CmUndo();
    void CmDelete();

    // Document notifications
    bool VnIsWindow(HWND hWnd) {return GetHandle() == hWnd;}
    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnAppend(unsigned int index);
    bool VnDelete(unsigned int index);
    bool VnModify(unsigned int index);

  DECLARE_RESPONSE_TABLE(TDrawListView);
  DECLARE_STREAMABLE(,TDrawListView,1);
};

const int vnDrawAppend = vnCustomBase+0;
const int vnDrawDelete = vnCustomBase+1;
const int vnDrawModify = vnCustomBase+2;

NOTIFY_SIG(vnDrawAppend, unsigned int)
NOTIFY_SIG(vnDrawDelete, unsigned int)
NOTIFY_SIG(vnDrawModify, unsigned int)

#define EV_VN_DRAWAPPEND  VN_DEFINE(vnDrawAppend,  VnAppend,  int)
#define EV_VN_DRAWDELETE  VN_DEFINE(vnDrawDelete,  VnDelete,  int)
#define EV_VN_DRAWMODIFY  VN_DEFINE(vnDrawModify,  VnModify,  int)

DEFINE_DOC_TEMPLATE_CLASS(TDrawDocument, TDrawView,   DrawTemplate);
DEFINE_DOC_TEMPLATE_CLASS(TDrawDocument, TDrawListView,   DrawListTemplate);
DrawTemplate drawTpl("Draw Line Files","*.pts",0,"PTS",dtAutoDelete|dtUpdateDir);
DrawListTemplate drawListTpl("Line List","*.pts",0,"PTS",dtAutoDelete|dtHidden);

void TLine::SetPen(int penSize)
{
  if (penSize < 1)
    PenSize = 1;
  else
    PenSize = penSize;
}

void TLine::SetPen(const TColor& newColor, int penSize)
{
  // If penSize isn't the default (0), set PenSize to the new size.
  if (penSize)
    PenSize = penSize;

  Color = newColor;
}

bool TLine::Draw(TDC &dc) const
{
  // Set pen for the dc to the values for this line
  TPen pen(Color, PenSize);
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

bool TDrawDocument::Commit(bool force)
{
  if (!IsDirty() && !force)
    return true;

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

  SetDirty(false);
  return true;
}

bool TDrawDocument::Revert(bool clear)
{
  if (!TFileDocument::Revert(clear))
    return false;
  if (!clear)
    Open(0);
  return true;
}

bool TDrawDocument::Open(int /*mode*/, const char far* path)
{
  char fileinfo[100];
  Lines = new TLines(5, 0, 5);
  if (path)
    SetDocPath(path);
  if (GetDocPath()) {
    TInStream* is = InStream(ofRead);
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

bool TDrawDocument::Close()
{
  delete Lines;
  Lines = 0;
  return true;
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
  SetDirty(true);
  NotifyViews(vnDrawAppend, index);
  UndoState = UndoAppend;
  return index;
}

void TDrawDocument::DeleteLine(unsigned int index)
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

void TDrawDocument::ModifyLine(TLine& line, unsigned int index)
{
  delete UndoLine;
  UndoLine = new TLine((*Lines)[index]);
  SetDirty(true);
  (*Lines)[index] = line;
  NotifyViews(vnDrawModify, index);
  UndoState = UndoModify;
  UndoIndex = index;
}

void TDrawDocument::Clear()
{
  Lines->Flush();
  NotifyViews(vnRevert, true);
}

void TDrawDocument::Undo()
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

bool TLine::GetPenSize()
{
  char inputText[6];

  sprintf(inputText, "%d", PenSize);
  if (TInputDialog(0, "Line Thickness",
                        "Input a new thickness:",
                        inputText,
                        sizeof(inputText),::Module).Execute() != IDOK)
    return false;
  PenSize = atoi(inputText);

  if (PenSize < 1)
    PenSize = 1;

  return true;
}

bool TLine::GetPenColor()
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
  colors.Color = TColor(QueryColor());
  colors.CustColors = custColors;
  if (TChooseColorDialog(0, colors).Execute() != IDOK)
    return false;
  SetPen(colors.Color);
  return true;
}

DEFINE_RESPONSE_TABLE1(TDrawView, TWindowView)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_COMMAND(CM_PENSIZE, CmPenSize),
  EV_COMMAND(CM_PENCOLOR, CmPenColor),
  EV_COMMAND(CM_CLEAR, CmClear),
  EV_COMMAND(CM_UNDO, CmUndo),
  EV_VN_COMMIT,
  EV_VN_REVERT,
  EV_VN_DRAWAPPEND,
  EV_VN_DRAWDELETE,
  EV_VN_DRAWMODIFY,
END_RESPONSE_TABLE;

TDrawView::TDrawView(TDrawDocument& doc,TWindow *parent)
         : TWindowView(doc,parent), DrawDoc(&doc)
{
  DragDC = 0;
  Line = new TLine(TColor::Black, 1);
  SetViewMenu(new TMenuDescr(IDM_DRAWVIEW,0,2,0,0,0,1));
}

void TDrawView::EvLButtonDown(uint, TPoint& point)
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

void TDrawView::EvRButtonDown(uint, TPoint&)
{
  CmUndo();
}

void TDrawView::EvMouseMove(uint, TPoint& point)
{
  if (DragDC) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
}

void TDrawView::EvLButtonUp(uint, TPoint&)
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
  Line->GetPenSize();
}

void TDrawView::CmPenColor()
{
  Line->GetPenColor();
}

void TDrawView::CmClear()
{
  DrawDoc->Clear();
}

void TDrawView::CmUndo()
{
  DrawDoc->Undo();
}

void TDrawView::Paint(TDC& dc, bool, TRect&)
{
  // Iterates through the array of line objects.
  int i = 0;
  const TLine* line;
  while ((line = DrawDoc->GetLine(i++)) != 0)
    line->Draw(dc);
}

bool TDrawView::VnCommit(bool /*force*/)
{
  // nothing to do here, no data held in view
  return true;
}

bool TDrawView::VnRevert(bool /*clear*/)
{
  Invalidate();  // force full repaint
  return true;
}

bool TDrawView::VnAppend(unsigned int index)
{
  TClientDC dc(*this);
  const TLine* line = DrawDoc->GetLine(index);
  line->Draw(dc);
  return true;
}

bool TDrawView::VnModify(unsigned int /*index*/)
{
  Invalidate();  // force full repaint
  return true;
}

bool TDrawView::VnDelete(unsigned int /*index*/)
{
  Invalidate();  // force full repaint
  return true;
}

DEFINE_RESPONSE_TABLE1(TDrawListView, TListBox)
  EV_COMMAND(CM_PENSIZE, CmPenSize),
  EV_COMMAND(CM_PENCOLOR, CmPenColor),
  EV_COMMAND(CM_CLEAR, CmClear),
  EV_COMMAND(CM_UNDO, CmUndo),
  EV_COMMAND(CM_DELETE, CmDelete),
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
  SetViewMenu(new TMenuDescr(IDM_DRAWLISTVIEW,0,1,0,0,0,1));
}

bool TDrawListView::Create()
{
  TListBox::Create();
  LoadData();
  return true;
}

void TDrawListView::LoadData()
{
  ClearList();
  int i = 0;
  const TLine* line;
  while ((line = DrawDoc->GetLine(i)) != 0)
    FormatData(line, i++);

  SetSelIndex(0);
}

void TDrawListView::FormatData(const TLine* line, int unsigned index)
{
  char buf[80];
  TColor color(line->QueryColor());
  sprintf(buf, "Color = R%d G%d B%d, Size = %d, Points = %d",
           color.Red(), color.Green(), color.Blue(),
           line->QueryPenSize(), line->GetItemsInContainer());
  DeleteString(index);
  InsertString(buf, index);
  SetSelIndex(index);
}

void TDrawListView::CmPenSize()
{
  int index = GetSelIndex();
  const TLine* line = DrawDoc->GetLine(index);
  if (line) {
    TLine* newline = new TLine(*line);
    if (newline->GetPenSize())
      DrawDoc->ModifyLine(*newline, index);
    delete newline;
  }
}

void TDrawListView::CmPenColor()
{
  int index = GetSelIndex();
  const TLine* line = DrawDoc->GetLine(index);
  if (line) {
    TLine* newline = new TLine(*line);
    if (newline->GetPenColor())
      DrawDoc->ModifyLine(*newline, index);
    delete newline;
  }
}

void TDrawListView::CmClear()
{
  DrawDoc->Clear();
}

void TDrawListView::CmUndo()
{
  DrawDoc->Undo();
}

void TDrawListView::CmDelete()
{
  DrawDoc->DeleteLine(GetSelIndex());
}

bool TDrawListView::VnCommit(bool /*force*/)
{
  return true;
}

bool TDrawListView::VnRevert(bool /*clear*/)
{
  LoadData();
  return true;
}

bool TDrawListView::VnAppend(unsigned int index)
{
  const TLine* line = DrawDoc->GetLine(index);
  FormatData(line, index);
  SetSelIndex(index);
  return true;
}

bool TDrawListView::VnDelete(unsigned int index)
{
  DeleteString(index);
  HandleMessage(WM_KEYDOWN,VK_DOWN); // force selection
  return true;
}

bool TDrawListView::VnModify(unsigned int index)
{
  const TLine* line = DrawDoc->GetLine(index);
  FormatData(line, index);
  return true;
}

static char* PropNames[] = {
  "Line Count",			 // LineCount
  "Description",			 // Description
};

static int PropFlags[] = {
  pfGetBinary|pfGetText, // LineCount
  pfGetText,             // Description
};

const char*
TDrawDocument::PropertyName(int index)
{
  if (index <= PrevProperty)
    return TFileDocument::PropertyName(index);
  else if (index < NextProperty)
    return PropNames[index-PrevProperty-1];
  else
    return 0;
}

int
TDrawDocument::PropertyFlags(int index)
{
  if (index <= PrevProperty)
    return TFileDocument::PropertyFlags(index);
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
  if (IsOpen())
    switch(prop)
    {
      case LineCount:
      {
        int count = Lines->GetItemsInContainer();
        if (!textlen) {
          *(int far*)dest = count;
          return sizeof(int);
        }
        return sprintf((char*)dest, "%d", count);
      }
      case Description:
        char* temp = new char[textlen]; // need local copy for medium model
        int len = FileInfo.copy(temp, textlen);
        strcpy((char*)dest, temp);
        return len;
    }
  return TFileDocument::GetProperty(prop, dest, textlen);
}

IMPLEMENT_STREAMABLE1(TDrawDocument, TFileDocument);

void*
TDrawDocument::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TDrawDocument* o = GetObject();
  o->UndoState = UndoNone;
  o->UndoLine = 0;
  o->Lines = 0;
  ReadBaseObject((TFileDocument*)o, is);
  return o;
}

void
TDrawDocument::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TFileDocument*)GetObject(), os);
}

IMPLEMENT_STREAMABLE1(TDrawView, TWindowView);

void*
TDrawView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TDrawView* o = GetObject();
  ReadBaseObject((TWindowView*)o, is);
  is >> o->DrawDoc;
  int width;
  COLORREF color;
  is >> width >> color;
  o->Line = new TLine(TColor(color), width);
  o->DragDC = 0;
  return o;
}

void
TDrawView::Streamer::Write(opstream &os) const
{
  TDrawView* o = GetObject();
  WriteBaseObject((TWindowView*)o, os);
  os << o->DrawDoc;
  os << o->Line->QueryPenSize();
  os << COLORREF(o->Line->QueryColor());
}

IMPLEMENT_STREAMABLE2(TDrawListView, TListBox, TView);

void*
TDrawListView::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TDrawListView* o = GetObject();
  ReadBaseObject((TListBox*)o, is);
  ReadBaseObject((TView*)o, is);
  is >> o->DrawDoc;
  return o;
}

void
TDrawListView::Streamer::Write(opstream &os) const
{
  TDrawListView* o = GetObject();
  WriteBaseObject((TListBox*)o, os);
  WriteBaseObject((TView*)o, os);
  os << o->DrawDoc;
}

