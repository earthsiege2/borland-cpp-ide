//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1994 by Borland International
//   Tutorial application -- step08.cpp
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dc.h>
#include <owl/inputdia.h>
#include <owl/opensave.h>
#include <classlib/arrays.h>
#include <stdlib.h>
#include <string.h>
#include "step08.rc"

typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;

class TLine : public TPoints {
  public:
    TLine(int penSize = 1) : TPoints(10, 0, 10)
    {
      PenSize = penSize;
    }

    int QueryPen() const
    {
      return PenSize;
    }

    int QueryPen(int penSize);

    // The == operator must be defined for the container class, even if unused
    bool operator ==(const TLine& other) const
    {
      return &other == this;
    }

    friend ostream& operator <<(ostream& os, const TLine& line);
    friend istream& operator >>(istream& is, TLine& line);

  protected:
    int PenSize;
};

int
TLine::QueryPen(int penSize)
{
  if (penSize < 0)
    PenSize = 1;
  else if (penSize > 0)
    PenSize = penSize;
  return PenSize;
}

typedef TArray<TLine> TLines;
typedef TArrayIterator<TLine> TLinesIterator;

class TDrawWindow : public TWindow {
  public:
    TDrawWindow(TWindow* parent = 0);
   ~TDrawWindow()
    {
      delete DragDC;
      delete Pen;
      delete Line;
      delete Lines;
      delete FileData;
    }

  protected:
    TDC* DragDC;
    TPen* Pen;
    TLines* Lines;
    TLine* Line; // To hold a single line at a time that later gets
                 // stuck in Lines
    TOpenSaveDialog::TData* FileData;
    bool IsDirty, IsNewFile;

    void SetPenSize(int newSize);
    int GetPenSize();

    // Override member function of TWindow
    bool CanClose();

    // Message response functions
    void EvLButtonDown(uint, TPoint&);
    void EvRButtonDown(uint, TPoint&);
    void EvMouseMove(uint, TPoint&);
    void EvLButtonUp(uint, TPoint&);
    void Paint(TDC&, bool, TRect&);
    void CmFileNew();
    void CmFileOpen();
    void CmFileSave();
    void CmFileSaveAs();
    void CmPenSize();
    void CmAbout();
    void SaveFile();
    void OpenFile();

  DECLARE_RESPONSE_TABLE(TDrawWindow);
};

DEFINE_RESPONSE_TABLE1(TDrawWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND(CM_ABOUT, CmAbout),
  EV_COMMAND(CM_PENSIZE, CmPenSize),
END_RESPONSE_TABLE;

TDrawWindow::TDrawWindow(TWindow* parent)
{
  Init(parent, 0, 0);
  DragDC    = 0;
  Lines     = new TLines(5, 0, 5);
  Line      = new TLine;
  Pen       = new TPen(TColor::Black, Line->QueryPen());
  IsNewFile = true;
  IsDirty   = false;
  FileData  = new TOpenSaveDialog::TData(OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,
                                        "Point Files (*.PT8)|*.pt8|", 0, "",
                                        "PT8");
}

bool
TDrawWindow::CanClose()
{
  if (IsDirty)
    switch(MessageBox("Do you want to save?", "Drawing has changed",
                      MB_YESNOCANCEL | MB_ICONQUESTION)) {
      case IDCANCEL:
        // Choosing Cancel means to abort the close -- return false.
        return false;

      case IDYES:
        // Choosing Yes means to save the drawing.
        CmFileSave();
    }
  return true;
}

void
TDrawWindow::EvLButtonDown(uint, TPoint& point)
{
  if (!DragDC) {
    SetCapture();
    DragDC = new TClientDC(*this);
    DragDC->SelectObject(*Pen);
    DragDC->MoveTo(point);
    Line->Add(point);
    IsDirty = true;
  }
}

void
TDrawWindow::EvRButtonDown(uint, TPoint&)
{
  SetPenSize(GetPenSize());
}

void
TDrawWindow::EvMouseMove(uint, TPoint& point)
{
  if (DragDC) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
}

void
TDrawWindow::EvLButtonUp(uint, TPoint&)
{
  if (DragDC) {
    ReleaseCapture();
    Lines->Add(*Line);
    Line->Flush();
    delete DragDC;
    DragDC = 0;
  }
}

void
TDrawWindow::CmPenSize()
{
  SetPenSize(GetPenSize());
}

int
TDrawWindow::GetPenSize()
{
  char inputText[6];
  int newPenSize = 1;

  wsprintf(inputText, "%d", Line->QueryPen());
  if ((TInputDialog(this, "Line Thickness",
                        "Input a new thickness:",
                        inputText,
                        sizeof(inputText))).Execute() == IDOK) {
    newPenSize = atoi(inputText);

    if (newPenSize < 0)
      newPenSize = 1;
  }
  return newPenSize;
}

void
TDrawWindow::SetPenSize(int newSize)
{
  delete Pen;
  Pen = new TPen(TColor::Black, Line->QueryPen(newSize));
}

void
TDrawWindow::Paint(TDC& dc, bool, TRect&)
{
  // Iterates through the array of line objects.
  TLinesIterator i(*Lines);

  while (i) {
    // Set pen for the dc to current line's pen.
    TPen pen(TColor::Black, i.Current().QueryPen());
    dc.SelectObject(pen);

    // Iterates through the points in the line i.
    TPointsIterator j(i++);
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
  }
}

void
TDrawWindow::CmFileNew()
{
  if (CanClose()) {
    Line->Flush();
    Lines->Flush();
    Invalidate();
    IsDirty = false;
    IsNewFile = true;
  }
}

void
TDrawWindow::CmFileOpen()
{
  if (CanClose())
    if ((TFileOpenDialog(this, *FileData)).Execute() == IDOK)
      OpenFile();
}

void
TDrawWindow::CmFileSave()
{
  if (IsNewFile)
    CmFileSaveAs();
  else
    SaveFile();
}

void
TDrawWindow::CmFileSaveAs()
{
  if (IsNewFile)
    strcpy(FileData->FileName, "");

  if ((TFileSaveDialog(this, *FileData)).Execute() == IDOK)
    SaveFile();
}

void
TDrawWindow::CmAbout()
{
  TDialog(this, IDD_ABOUT).Execute();
}

void
TDrawWindow::SaveFile()
{
  ofstream os(FileData->FileName);

  if (!os)
    MessageBox("Unable to open file", "File Error", MB_OK | MB_ICONEXCLAMATION);
  else {
    // Write the number of lines in the figure
    os << Lines->GetItemsInContainer() << '\n';

    // Get an iterator for the array of lines
    TLinesIterator i(*Lines);

    // While the iterator is valid (i.e. we haven't run out of lines)
    while (i) {
      // Copy the current line from the iterator and increment the array.
      TLine line = i++;
      os << line;
    }

    // Set new file and dirty display indicator to false.
    IsNewFile = IsDirty = false;
  }
}

void
TDrawWindow::OpenFile()
{
  ifstream is(FileData->FileName);

  if (!is)
    MessageBox("Unable to open file", "File Error", MB_OK | MB_ICONEXCLAMATION);
  else {
    unsigned numLines;

    Lines->Flush();
    Line->Flush();

    is >> numLines;

    while (numLines--) {
      TLine line;
      is >> line;
      Lines->Add(line);
    }
  }
  IsNewFile = IsDirty = false;
  Invalidate();
}

class TDrawApp : public TApplication {
  public:
    TDrawApp() : TApplication() {}

    void InitMainWindow()
    {
      SetMainWindow(new TFrameWindow(0, "Drawing Pad", new TDrawWindow));
      GetMainWindow()->AssignMenu("COMMANDS");
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDrawApp().Run();
}

ostream&
operator <<(ostream& os, const TLine& line)
{
  // Write the number of points in the line
  os << line.GetItemsInContainer();

  // Write the pen size
  os << ' ' << line.PenSize;

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

  is >> line.PenSize;

  while (numPoints--) {
    TPoint point;
    is >> point;
    line.Add(point);
  }
  // return the stream object
  return is;
}

