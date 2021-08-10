//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1994 by Borland International
//   Ole tutorial application -- owlole1.cpp
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/decframe.h>
#include <owl/dc.h>
#include <owl/inputdia.h>
#include <owl/opensave.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/statusba.h>
#include <owl/gdiobjec.h>
#include <owl/chooseco.h>
#include <classlib/arrays.h>
#include <stdlib.h>
#include <string.h>
#include "owlole1.rc"

#define DocExt   "sp1"  // Scribble Pad #1 document extension

//----------------------------------------------------------------------------

typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;

class TLine : public TPoints {
  public:
    // Constructor to allow construction from a color and a pen size.
    // Also serves as default constructor.
    TLine(const TColor& color = TColor(0), int penSize = 1) :
      TPoints(10, 0, 10), PenSize(penSize), Color(color) {}

    // Functions to modify and query pen attributes.
    int QueryPenSize() const
    {
      return PenSize;
    }

    TColor& QueryColor()
    {
      return Color;
    }

    void SetPen(TColor& newColor, int penSize = 0);
    void SetPen(int penSize);

    // TLine draws itself.  Returns true if everything went OK.
    virtual bool Draw(TDC&) const;

    // The == operator must be defined for the container class, even if unused
    bool operator ==(const TLine& other) const
    {
      return &other == this;
    }

    friend ostream& operator <<(ostream& os, const TLine& line);
    friend istream& operator >>(istream& is, TLine& line);

  protected:
    int PenSize;
    TColor Color;
};

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

//----------------------------------------------------------------------------

typedef TArray<TLine> TLines;
typedef TArrayIterator<TLine> TLinesIterator;

class TScribbleWindow : public TWindow {
  public:
    TScribbleWindow(TWindow* parent, TOpenSaveDialog::TData& fileData);
   ~TScribbleWindow()
    {
      delete DragDC;
      delete Line;
      delete Lines;
    }

  protected:
    TDC* DragDC;
    TPen* Pen;
    TLines* Lines;
    TLine* Line; // To hold a single line at a time that later gets
                 // stuck in Lines
    TOpenSaveDialog::TData& FileData;
    bool IsDirty, IsNewFile;

    void GetPenSize(); // GetPenSize always calls Line->SetPen().

    // Override member function of TWindow
    void SetupWindow();
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
    void CmPenColor();
    void CmAbout();
    void SaveFile(bool pathChanged);
    void OpenFile();

  DECLARE_RESPONSE_TABLE(TScribbleWindow);
};

DEFINE_RESPONSE_TABLE1(TScribbleWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND(CM_PENSIZE, CmPenSize),
  EV_COMMAND(CM_PENCOLOR, CmPenColor),
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

TScribbleWindow::TScribbleWindow(TWindow* parent, TOpenSaveDialog::TData& fileData)
:
  TWindow(parent, 0),
  FileData(fileData)
{
  DragDC    = 0;
  Lines     = new TLines(5, 0, 5);
  Line      = new TLine(TColor::Black, 1);
  Pen       = 0;
  IsNewFile = true;
  IsDirty   = false;
}

void
TScribbleWindow::SetupWindow()
{
  TWindow::SetupWindow();
  if (*FileData.FileName)
    OpenFile();
  else
    SetDocTitle("Untitled", 0);
}

bool
TScribbleWindow::CanClose()
{
  if (IsDirty)
    switch (MessageBox("Do you want to save?", "Scribbling has changed",
                       MB_YESNOCANCEL | MB_ICONQUESTION)) {
      case IDCANCEL:
        // Choosing Cancel means to abort the close -- return false.
        return false;

      case IDYES:
        // Choosing Yes means to save the drawing, then close.
        CmFileSave();
    }
  return true;
}

void
TScribbleWindow::EvLButtonDown(uint, TPoint& point)
{
  if (!DragDC) {
    SetCapture();
    DragDC = new TClientDC(*this);
    Pen = new TPen(Line->QueryColor(), Line->QueryPenSize());
    DragDC->SelectObject(*Pen);
    DragDC->MoveTo(point);
    Line->Add(point);
    IsDirty = true;
  }
}

void
TScribbleWindow::EvRButtonDown(uint, TPoint&)
{
  GetPenSize();
}

void
TScribbleWindow::EvMouseMove(uint, TPoint& point)
{
  if (DragDC) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
}

void
TScribbleWindow::EvLButtonUp(uint, TPoint&)
{
  if (DragDC) {
    ReleaseCapture();
    Lines->Add(*Line);
    Line->Flush();
    delete DragDC;
    delete Pen;
    DragDC = 0;
  }
}

void
TScribbleWindow::CmPenSize()
{
  GetPenSize();
}

void
TScribbleWindow::CmPenColor()
{
  TChooseColorDialog::TData colors;
  static TColor custColors[16] = {
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

void
TScribbleWindow::GetPenSize()
{
  char inputText[6];
  int penSize = Line->QueryPenSize();

  wsprintf(inputText, "%d", penSize);
  if (TInputDialog(this, "Line Thickness",
                   "Input a new thickness:",
                   inputText,
                   sizeof(inputText)).Execute() == IDOK) {
    penSize = atoi(inputText);

    if (penSize < 1)
      penSize = 1;
  }
  Line->SetPen(penSize);
}

void
TScribbleWindow::Paint(TDC& dc, bool, TRect&)
{
  // Iterates through the array of line objects.
  TLinesIterator i(*Lines);

  while (i)
    i++.Draw(dc);
}

void
TScribbleWindow::CmFileSave()
{
  if (IsNewFile)
    CmFileSaveAs();
  else
    SaveFile(false);
}

void
TScribbleWindow::CmFileSaveAs()
{
  if (TFileSaveDialog(this, FileData).Execute() == IDOK)
    SaveFile(true);
}

void
TScribbleWindow::CmAbout()
{
  TDialog(this, IDD_ABOUT).Execute();
}

void
TScribbleWindow::SaveFile(bool pathChanged)
{
  ofstream os(FileData.FileName);

  if (!os)
    MessageBox("Unable to open file", "File Error", MB_OK | MB_ICONEXCLAMATION);
  else {
    // Write the number of lines in the figure
    os << Lines->GetItemsInContainer();

    // Append a description using a resource string
    os << ' ' << string(*GetApplication(), IDS_FILEINFO) << '\n';

    // Get an iterator for the array of lines
    TLinesIterator i(*Lines);

    // While the iterator is valid (i.e. we haven't run out of lines)
    while (i)
      // Copy the current line from the iterator and increment the array.
      os << i++;

    // Set new file and dirty display indicator to false.
    IsNewFile = IsDirty = false;
    if (pathChanged)
      SetDocTitle(FileData.FileName, 0);
  }
}

void
TScribbleWindow::OpenFile()
{
  ifstream is(FileData.FileName);

  if (!is)
    MessageBox("Unable to open file", "File Error", MB_OK | MB_ICONEXCLAMATION);
  else {
    unsigned numLines;
    char fileinfo[100];

    Lines->Flush();
    Line->Flush();

    is >> numLines;
    is.getline(fileinfo, sizeof(fileinfo));
    SetDocTitle(FileData.FileName, 0);

    for (int i = 0; i < numLines; i++) {
      TLine line;
      is >> line;
      Lines->Add(line);
    }
  }
  IsNewFile = IsDirty = false;
  Invalidate();
}

//----------------------------------------------------------------------------

class TScribbleApp : public TApplication {
  public:
    TScribbleApp();

  protected:
    void InitMainWindow();
    void InitInstance();

    void CmFileNew();
    void CmFileOpen();

    TOpenSaveDialog::TData FileData;

  DECLARE_RESPONSE_TABLE(TScribbleApp);
};

DEFINE_RESPONSE_TABLE1(TScribbleApp, TApplication)
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
END_RESPONSE_TABLE;

TScribbleApp::TScribbleApp()
:
  TApplication("Scribble Pad"),
  FileData(OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,
           "Scribble Files (*."DocExt")|*."DocExt"|", 0, "", DocExt)
{
}

void
TScribbleApp::InitMainWindow()
{
  // Construct the decorated frame window
  TDecoratedFrame* frame = new TDecoratedFrame(0, GetName(), 0, true, this);

  // Construct a status bar
  TStatusBar* sb = new TStatusBar(frame, TGadget::Recessed);

  // Construct a control bar
  TControlBar* cb = new TControlBar(frame);
  cb->Insert(*new TButtonGadget(CM_FILENEW, CM_FILENEW, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_FILEOPEN, CM_FILEOPEN, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_FILESAVEAS, CM_FILESAVEAS, TButtonGadget::Command));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_PENSIZE, CM_PENSIZE, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_PENCOLOR, CM_PENCOLOR, TButtonGadget::Command));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_ABOUT, CM_ABOUT, TButtonGadget::Command));
  cb->Attr.Id = IDW_TOOLBAR;

  // Insert the status bar and control bar into the frame
  frame->Insert(*sb, TDecoratedFrame::Bottom);
  frame->Insert(*cb, TDecoratedFrame::Top);

  // Set the menu & icon
  frame->SetMenuDescr(TMenuDescr(IDM_SCRIBBLE));
  frame->SetIcon(this, IDI_TUTORIAL);

  // Set the main window
  SetMainWindow(frame);
}

//
// Call file new command handler to get the initial new window
//
void
TScribbleApp::InitInstance()
{
  TApplication::InitInstance();

  FileData.FileName[0] = 0;
  TWindow* client = new TScribbleWindow(0, FileData);
  TWindow* oldClient = GetMainWindow()->SetClientWindow(client);
  if (oldClient) {
    oldClient->Destroy();
    delete oldClient;
  }
}

void
TScribbleApp::CmFileNew()
{
  TWindow* scribbleWindow = GetMainWindow()->GetClientWindow();
  if (!scribbleWindow->CanClose())
    return;

  FileData.FileName[0] = 0;
  TWindow* client = new TScribbleWindow(0, FileData);
  GetMainWindow()->SetClientWindow(client);
  scribbleWindow->Destroy(0);
  delete scribbleWindow;
}

void
TScribbleApp::CmFileOpen()
{
  TWindow* scribbleWindow = GetMainWindow()->GetClientWindow();
  if (!scribbleWindow->CanClose())
    return;

  if (TFileOpenDialog(GetMainWindow(), FileData).Execute() == IDOK) {
    TWindow* newScribbleWindow = new TScribbleWindow(0, FileData);
    GetMainWindow()->SetClientWindow(newScribbleWindow);
    scribbleWindow->Destroy(0);
    delete scribbleWindow;
  }
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  try {
    return TScribbleApp().Run();
  }
  catch (xmsg& x) {
    ::MessageBox(0, x.why().c_str(), "Scribble App Exception", MB_OK);
  }
  return -1;
}
