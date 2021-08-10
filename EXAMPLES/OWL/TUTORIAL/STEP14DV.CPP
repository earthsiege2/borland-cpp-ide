//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//   Tutorial application
//   OLE 2 container example
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/dc.h>
#include <owl/inputdia.h>
#include <owl/chooseco.h>
#include <owl/gdiobjec.h>
#include <owl/docmanag.h>
#include <owl/listbox.h>
#include <classlib/arrays.h>
#include <owl/oledoc.h>
#include <owl/oleview.h>
#include <owl/edit.rh>
#include "step14dv.rc"

typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;


//===============================  TLine  =====================================
//
class TLine : public TPoints {
  public:
    // Constructor to allow construction from a color and a pen size.
    // Also serves as default constructor.
    TLine(const TColor& color = TColor(0), int penSize = 1) :
      TPoints(10, 0, 10), PenSize(penSize), Color(color){}

    // Functions to modify and query pen attributes.
    int QueryPenSize() const {return PenSize;}
    const TColor& QueryColor() const {return Color;}
    void SetPen(TColor& newColor, int penSize = 0);
    void SetPen(int penSize);
    bool GetPenSize();
    bool GetPenColor();

    // TLine draws itself.  Returns true if everything went OK.
    virtual bool Draw(TDC&) const;

    // The == operator must be defined for the container class, even if unused
    bool operator ==(const TLine& other) const {return &other == this;}
    friend ostream& operator <<(ostream& os, const TLine& line);
    friend istream& operator >>(istream& is, TLine& line);

  protected:
    int PenSize;
    TColor Color;
};

typedef TArray<TLine> TLines;
typedef TArrayIterator<TLine> TLinesIterator;

class _USERCLASS TDrawDocument : public TOleDocument {
  public:
    enum {
      PrevProperty = TOleDocument::NextProperty-1,
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

    TDrawDocument(TDocument* parent = 0);
   ~TDrawDocument() { delete Lines; delete UndoLine; }

    // implement virtual methods of TDocument
    bool   Open(int mode, const char far* path=0);
    bool   Close();
    bool   Commit(bool force = false);

    int         FindProperty(const char far* name);  // return index
    int         PropertyFlags(int index);
    const char* PropertyName(int index);
    int         PropertyCount() {return NextProperty - 1;}
    int         GetProperty(int index, void far* dest, int textlen=0);

    // data access functions
    TLine* GetLine(uint index);
    int    AddLine(TLine& line);
    void   DeleteLine(uint index);
    void   ModifyLine(TLine& line, uint index);
    void   Clear();
    void   Undo();

  protected:
    TLines* Lines;
    TLine*  UndoLine;
    int     UndoState;
    int     UndoIndex;
    string  FileInfo;
};

class _USERCLASS TDrawView : public TOleView {
  public:
    TDrawView(TDrawDocument& doc, TWindow* parent = 0);
   ~TDrawView() {delete Line;}
    static const char far* StaticName() {return "Draw View";}
    const char far* GetViewName() {return StaticName();}

  protected:
    TDrawDocument*    DrawDoc;  // same as Doc member, but cast to derived class
    TPen*             Pen;
    TLine*            Line;     // To hold a single line sent or received from document

    // Message response functions
    void EvLButtonDown(uint, TPoint&);
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
    bool VnAppend(uint index);
    bool VnDelete(uint index);
    bool VnModify(uint index);

  DECLARE_RESPONSE_TABLE(TDrawView);
};


class _USERCLASS TDrawListView : public TListBox, public TView {
  public:
    TDrawListView(TDrawDocument& doc, TWindow* parent = 0);
   ~TDrawListView(){}
    static const char far* StaticName() {return "DrawList View";}
    int CurIndex;

    // Overridden virtuals from TView
    //
    const char far* GetViewName() {return StaticName();}
    TWindow* GetWindow() {return (TWindow*)this;}
    bool SetDocTitle(const char far* docname, int index)
                    {return TListBox::SetDocTitle(docname, index);}

    // Overridden virtuals from TWindow
    //
    bool CanClose();
    bool Create();

  protected:
    TDrawDocument* DrawDoc;  // same as Doc member, but cast to derived class
    void LoadData();
    void FormatData(const TLine* line, uint index);

    // Message response functions
    void CmPenSize();
    void CmPenColor();
    void CmClear();
    void CmUndo();
    void CmDelete();

    // Document notifications
    bool VnIsWindow(HWND hWnd) {return HWindow == hWnd;}
    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnAppend(uint index);
    bool VnDelete(uint index);
    bool VnModify(uint index);

  DECLARE_RESPONSE_TABLE(TDrawListView);
};

const int vnDrawAppend     = vnCustomBase+0;
const int vnDrawDelete     = vnCustomBase+1;
const int vnDrawModify     = vnCustomBase+2;

NOTIFY_SIG(vnDrawAppend, uint)
NOTIFY_SIG(vnDrawDelete, uint)
NOTIFY_SIG(vnDrawModify, uint)

#define EV_VN_DRAWAPPEND  VN_DEFINE(vnDrawAppend,  VnAppend,  int)
#define EV_VN_DRAWDELETE  VN_DEFINE(vnDrawDelete,  VnDelete,  int)
#define EV_VN_DRAWMODIFY  VN_DEFINE(vnDrawModify,  VnModify,  int)


// Register document template info and clipboard formats
//
BEGIN_REGISTRATION(DocReg)
  REGDATA(progid,     "DrawPad.Document.14")
  REGDATA(description,"Drawing Pad (Step14--Container)")
  REGDATA(extension,  "p14")
  REGDATA(docfilter,  "*.p14")
  REGDOCFLAGS(dtAutoOpen | dtAutoDelete | dtUpdateDir | dtCreatePrompt | dtRegisterExt)
  REGFORMAT(0, ocrEmbedSource,  ocrContent,  ocrIStorage, ocrGet)
  REGFORMAT(1, ocrMetafilePict, ocrContent,  ocrMfPict|ocrStaticMed, ocrGet)
  REGFORMAT(2, ocrBitmap, ocrContent,  ocrGDI|ocrStaticMed, ocrGet)
  REGFORMAT(3, ocrDib, ocrContent,  ocrHGlobal|ocrStaticMed, ocrGet)
END_REGISTRATION
BEGIN_REGISTRATION(ListReg)
  REGDATA(description,"Line List")
  REGDATA(extension,  "p14")
  REGDATA(docfilter,  "*.p14")
  REGDOCFLAGS(dtAutoDelete | dtHidden)
END_REGISTRATION

DEFINE_DOC_TEMPLATE_CLASS(TDrawDocument, TDrawView,       DrawTemplate);
DEFINE_DOC_TEMPLATE_CLASS(TDrawDocument, TDrawListView,   DrawListTemplate);
DrawTemplate drawTpl(DocReg);
DrawListTemplate drawListTpl(ListReg);

//===============================  TLine  =====================================
//
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

TDrawDocument::TDrawDocument(TDocument* parent)
        : TOleDocument(parent), UndoLine(0),
          UndoState(UndoNone)
{
  Lines = new TLines(100, 0, 5);
}

bool TDrawDocument::Commit(bool force)
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

bool TDrawDocument::Open(int mode, const char far* path)
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

bool TDrawDocument::Close()
{
  if (TOleDocument::Close()) {
    Lines->Flush();
    return true;
  }

  return false;
}

TLine* TDrawDocument::GetLine(uint index)
{
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

void TDrawDocument::DeleteLine(uint index)
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

void TDrawDocument::ModifyLine(TLine& line, uint index)
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

  wsprintf(inputText, "%d", PenSize);
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
  EV_WM_SETFOCUS,
END_RESPONSE_TABLE;

TDrawView::TDrawView(TDrawDocument& doc, TWindow* parent)
:
  TOleView(doc, parent), DrawDoc(&doc)
{
  Line = new TLine(TColor::Black, 1);
  Attr.AccelTable = IDA_DRAWVIEW;
  SetViewMenu(new TMenuDescr(IDM_DRAWVIEW));
}

void TDrawView::EvLButtonDown(uint modKeys, TPoint& point)
{
  TOleView::EvLButtonDown(modKeys, point);

  if (DragDC && !SelectEmbedded()) {
    SetCapture();
    Pen = new TPen(Line->QueryColor(), Line->QueryPenSize());
    DragDC->SelectObject(*Pen);
    DragDC->MoveTo(point);
    Line->Add(point);
  }
}

void TDrawView::EvMouseMove(uint modKeys, TPoint& point)
{
  TOleView::EvMouseMove(modKeys, point);

  if (DragDC && !SelectEmbedded() && GetCapture() == *this) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
}

void TDrawView::EvLButtonUp(uint modKeys, TPoint& point)
{
  if (DragDC) {
    if (!SelectEmbedded()) {
      ReleaseCapture();
      if (Line->GetItemsInContainer() > 1)
        DrawDoc->AddLine(*Line);
      Line->Flush();
      delete Pen;
    }
  }

  TOleView::EvLButtonUp(modKeys, point);
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

void TDrawView::Paint(TDC& dc, bool erase, TRect&rect)
{
  TOleView::Paint(dc, erase, rect);

  // Iterates through the array of line objects.
  int j = 0;
  TLine* line;
  while ((line = const_cast<TLine *>(DrawDoc->GetLine(j++))) != 0)
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

bool TDrawView::VnAppend(uint index)
{
  TClientDC dc(*this);
  const TLine* line = DrawDoc->GetLine(index);
  line->Draw(dc);
  return true;
}

bool TDrawView::VnModify(uint /*index*/)
{
  Invalidate();  // force full repaint
  return true;
}

bool TDrawView::VnDelete(uint /*index*/)
{
  Invalidate();  // force full repaint
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
  wsprintf(buf, "Color = R%d G%d B%d, Size = %d, Points = %d",
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

bool TDrawListView::VnAppend(uint index)
{
  const TLine* line = DrawDoc->GetLine(index);
  FormatData(line, index);
  SetSelIndex(index);
  return true;
}

bool TDrawListView::VnDelete(uint index)
{
  DeleteString(index);
  HandleMessage(WM_KEYDOWN,VK_DOWN); // force selection
  return true;
}

bool TDrawListView::VnModify(uint index)
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
    return TOleDocument::PropertyName(index);  // OC server change
  else if (index < NextProperty)
    return PropNames[index-PrevProperty-1];
  else
    return 0;
}

int
TDrawDocument::PropertyFlags(int index)
{
  if (index <= PrevProperty)
    return TOleDocument::PropertyFlags(index); // OC server change
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
  switch(prop)
  {
    case LineCount:
    {
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
  return TOleDocument::GetProperty(prop, dest, textlen); // OC server change
}
