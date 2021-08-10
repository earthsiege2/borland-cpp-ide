//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1994 by Borland International
//   Ole tutorial application -- owlole2.cpp
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
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
#include <owl/oleframe.h>
#include <owl/olewindo.h>
#include <ocf/ocstorag.h>
#include <classlib/arrays.h>
#include <stdlib.h>
#include <string.h>
#include "owlole2.rc"

// App registration object
//
static TPointer<TOcRegistrar> Registrar;
DEFINE_APP_DICTIONARY(AppDictionary);

#define DocExt   "sp2"  // Scribble Pad #2 document extension

REGISTRATION_FORMAT_BUFFER(100)

BEGIN_REGISTRATION(AppReg)
  REGDATA(clsid,      "{B6B58B60-B9C3-101B-B3FF-86C8A0834EDE}")
  REGDATA(appname,    "Scribble Pad")
END_REGISTRATION

// Register clipboard formats
//
BEGIN_REGISTRATION(DocReg)
  REGDATA(progid,     "Scribble.Pad.2")
  REGDATA(description,"Scribble Pad (Container)")
  REGDATA(extension,  DocExt )
  REGDATA(docfilter,  "*." DocExt)
  REGFORMAT(0, ocrEmbedSource,  ocrContent,  ocrIStorage, ocrGet)
  REGFORMAT(1, ocrMetafilePict, ocrContent,  ocrMfPict|ocrStaticMed, ocrGet)
  REGFORMAT(2, ocrBitmap, ocrContent,  ocrGDI|ocrStaticMed, ocrGet)
  REGFORMAT(3, ocrDib, ocrContent,  ocrHGlobal|ocrStaticMed, ocrGet)
  REGFORMAT(4, ocrLinkSource, ocrContent,  ocrIStream, ocrGet)
END_REGISTRATION

TRegLink* RegLinkHead = 0;
TRegLink  DocLink(DocReg, RegLinkHead);
const char ScribbleAppTitle[] = "Scribble";

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

class TScribbleWindow : public TOleWindow {
  public:
    TScribbleWindow(TWindow* parent, TOpenSaveDialog::TData& fileData);
   ~TScribbleWindow()
    {
      delete Line;
      delete Lines;
    }

  protected:
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

    const char far* EvOcViewTitle(){return ScribbleAppTitle; }
  DECLARE_RESPONSE_TABLE(TScribbleWindow);
};

DEFINE_RESPONSE_TABLE1(TScribbleWindow, TOleWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND(CM_PENSIZE, CmPenSize),
  EV_COMMAND(CM_PENCOLOR, CmPenColor),
  EV_COMMAND(CM_ABOUT, CmAbout),

  EV_OC_VIEWTITLE,
END_RESPONSE_TABLE;

TScribbleWindow::TScribbleWindow(TWindow* parent, TOpenSaveDialog::TData& fileData)
:
  TOleWindow(parent, 0),
  FileData(fileData)
{
  Lines     = new TLines(5, 0, 5);
  Line      = new TLine(TColor::Black, 1);
  Pen       = 0;
  IsNewFile = true;
  IsDirty   = false;

  // Create a OcDocument object to hold the ole parts that we create
  // and a OcView to provide ole services
  //
  CreateOcView(RegLinkHead, false, 0);
}

void
TScribbleWindow::SetupWindow()
{
  TOleWindow::SetupWindow();
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
        break;

      case IDNO:
        // Choosing No means don't save the drawing but close.
        // NOTE: Still need to call TOleWindow::CanClose for OLE cleanup
        break;
    }

  // Allow TOleWindow to perform OLE document cleanup
  //
  return TOleWindow::CanClose();
}

void
TScribbleWindow::EvLButtonDown(uint modKeys, TPoint& point)
{
  TOleWindow::EvLButtonDown(modKeys, point);

  if (DragDC && !SelectEmbedded()) {
    SetCapture();
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
TScribbleWindow::EvMouseMove(uint modKeys, TPoint& point)
{
  TOleWindow::EvMouseMove(modKeys, point);

  if (DragDC && !SelectEmbedded()) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
}

void
TScribbleWindow::EvLButtonUp(uint modKeys, TPoint& point)
{
  if (DragDC) {
    if (!SelectEmbedded()) {
      ReleaseCapture();
      if (Line->GetItemsInContainer() > 1)
        Lines->Add(*Line);
      Line->Flush();
      delete Pen;
      Pen = 0;
    }
  }
  TOleWindow::EvLButtonUp(modKeys, point);
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
TScribbleWindow::Paint(TDC& dc, bool erase, TRect& rect)
{
  TOleWindow::Paint(dc, erase, rect);

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
  if (pathChanged && !OcDoc->SaveToFile(FileData.FileName))
    return; // error!
  TOcStorage* storage = OcDoc->GetStorage();

  if (!storage) {
    MessageBox("Bogus internal storage problem", "File Error", MB_OK | MB_ICONEXCLAMATION);
  }
  else {
    TOcStream  stream(*storage, "Scribble", true, STGM_READWRITE);
    ostrstream os;

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

    OcDoc->SetName(FileData.FileName);

    stream.Write(os.str(), os.pcount());
    stream.Commit(STGC_DEFAULT);

    OcDoc->SaveParts(0, true);
    OcDoc->GetStorage()->Commit(STGC_DEFAULT);
  }
}

void
TScribbleWindow::OpenFile()
{
  try {
    OcDoc->SetStorage(FileData.FileName);
    TOcStorage* storage = OcDoc->GetStorage();

    if (!storage)
      MessageBox("Bogus internal storage problem", "File Error", MB_OK | MB_ICONEXCLAMATION);
    else {
      TOcStream   stream(*storage, "Scribble", false, STGM_READWRITE);

      // figure out the size of our stream to read, & read it into a buffer
      uint64 size;
      stream.Seek(0, STREAM_SEEK_END, &size);
      char* buff = new char[(int)size.LowPart+10]; 
      stream.Seek(0, STREAM_SEEK_SET);
      stream.Read(buff, size.LowPart);

      // now make the buffer into a input str stream & stream in our objects
      istrstream is(buff, (int)size.LowPart);
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
      delete [] buff;

      OcDoc->LoadParts();
    }
    IsNewFile = IsDirty = false;
    Invalidate();
  }
  catch(TXBase& xbase) {
    MessageBox(xbase.why().c_str(), "EXCEPTION", MB_OK);
  }
}

//----------------------------------------------------------------------------

class TScribbleApp : public TApplication, public TOcModule {
  public:
    TScribbleApp();

    TUnknown* CreateOleObject(uint32 /*options*/, TRegLink* /*link*/) {return 0;}

  protected:
    void InitMainWindow();
    void InitInstance();

    void CmFileNew();
    void CmFileOpen();

    TOpenSaveDialog::TData FileData;

  DECLARE_RESPONSE_TABLE(TScribbleApp);
};

DEFINE_RESPONSE_TABLE(TScribbleApp)
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
END_RESPONSE_TABLE;

TScribbleApp::TScribbleApp()
:
  TApplication(::AppReg["appname"]),
  FileData(OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,
           "Scribble Files (*."DocExt")|*."DocExt"|", 0, "", DocExt)
{
}

void
TScribbleApp::InitMainWindow()
{
  // Construct the ole decorated frame window
  TOleFrame* frame = new TOleFrame(GetName(), 0, true, this);

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

  // Set the main window and its menu
  SetMainWindow(frame);
  GetMainWindow()->SetMenuDescr(TMenuDescr(IDM_SCRIBBLE));
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
    Registrar = new TOcRegistrar(::AppReg, TOleFactory<TScribbleApp>(),
                                 TApplication::GetCmdLine());
    return Registrar->Run();
  }
  catch (xmsg& x) {
    ::MessageBox(0, x.why().c_str(), "Scribble App Exception", MB_OK);
  }
  return -1;
}
