//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/listbox.h>
#include <owl/editfile.rh>  // includes editsear.rh
#include <owl/editfile.h>
#include <owl/layoutwi.h>
#include <owl/static.h>
#include <owl/gdiobjec.h>
#include <owl/combobox.h>
#include <owl/button.h>
#include <owl/menu.h>

#include <dir.h>

#include "filebrow.rh"

const ID_FilePane        = 1;
const ID_EditPane        = 2;
const ID_FindPane        = 3;
const ID_FilePaneLabel   = 5;
const ID_DirPane         = 6;
const ID_DirPaneLabel    = 7;
const ID_FilterPane      = 9;
const ID_FilterPaneLabel = 10;
const ID_DrivePane       = 11;

const CaptionHeight = 12;
const EditHeight    = 30; // Height of an edit control, with borders, in pixels
const ButtonWidth   = 40;
const MaxEntry      = MAXFILE+MAXEXT+4;


//----------------------------------------------------------------------------

//
// File edit control class w/ a context popup menu
//
class TMyEdit : public TEditFile {
  public:
    TMyEdit(TWindow*        parent = 0,
            int             id = 0,
            const char far* text = 0,
            int x = 0, int y = 0, int w = 0, int h = 0,
            const char far* fileName = 0,
            TModule*        module = 0) :
            TEditFile(parent,id,text,x,y,w,h,fileName,module) {}

  void EvRButtonDown(uint modkeys, TPoint& point);

  DECLARE_RESPONSE_TABLE(TMyEdit);
};

DEFINE_RESPONSE_TABLE1(TMyEdit,TEditFile)
  EV_WM_RBUTTONDOWN,
END_RESPONSE_TABLE;

void
TMyEdit::EvRButtonDown(uint /*modkeys*/, TPoint& point)
{
  TPoint lp = point;
  TPopupMenu *menu = new TPopupMenu();

  // Commands are handled by TEditFile
  //
  menu->AppendMenu(MF_STRING, CM_FILESAVE, "Save");
  menu->AppendMenu(MF_STRING, CM_FILESAVEAS, "Save As");
  menu->AppendMenu(MF_SEPARATOR, 0, 0);
  menu->AppendMenu(MF_STRING, CM_EDITUNDO, "Undo");
  menu->AppendMenu(MF_STRING, CM_EDITCUT, "Cut");
  menu->AppendMenu(MF_STRING, CM_EDITCOPY, "Copy");
  menu->AppendMenu(MF_STRING, CM_EDITPASTE, "Paste");
  menu->AppendMenu(MF_STRING, CM_EDITDELETE, "Delete");
  menu->AppendMenu(MF_STRING, CM_EDITCLEAR, "Clear");
  menu->AppendMenu(MF_SEPARATOR, 0, 0);
  menu->AppendMenu(MF_STRING, CM_EDITFIND, "Find");
  menu->AppendMenu(MF_STRING, CM_EDITREPLACE, "Replace");
  menu->AppendMenu(MF_STRING, CM_EDITFINDNEXT, "Next");
  ClientToScreen(lp);

  menu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, lp, 0, HWindow);
  delete menu;
}

//----------------------------------------------------------------------------

class TBrowserWindow;

//
// Layout window for find pane
//
class TFindPane : public TLayoutWindow {
  public:
    TFindPane(TBrowserWindow* parent);
    void SetupWindow();
    void Paint(TDC& dc, bool erase, TRect& rect);

    void Update();

    char Filter[256];

  protected:
    // Notification Handlers
    //
    void SelectDir();
    void SelectDrive();
    void SelectFilter();

    void EvSize(uint sizeType, TSize& size);

  private:
    // File Filter string
    //
    TButton* FilterPaneLabel;
    TEdit*   FilterPane;

    // List of drives
    //
    TComboBox* DrivePane;

    // List of directories
    //
    TStatic*  DirPaneLabel;
    TListBox* DirPane;

    TBrowserWindow* Browser;       // Our parent

  DECLARE_RESPONSE_TABLE(TFindPane);
};

//
// Main client layout window
//
class TBrowserWindow : public TLayoutWindow {
  public:
    TBrowserWindow();
   ~TBrowserWindow()
    {
      delete CaptionFont;
    }

    void SetupWindow();

    // Notification Handlers
    //
    void SelectFile();

    TFont*     CaptionFont;  // Used for pane labels
    TFindPane* FindPane;

    // List of files
    //
    TStatic*   FilePaneLabel;
    TListBox*  FilePane;
    TMyEdit*   EditPane;

  DECLARE_RESPONSE_TABLE(TBrowserWindow);
};

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TFindPane, TLayoutWindow)
  EV_LBN_SELCHANGE(ID_DirPane, SelectDir),
  EV_CBN_CLOSEUP(ID_DrivePane, SelectDrive),
  EV_BN_CLICKED(ID_FilterPaneLabel, SelectFilter),
  EV_WM_SIZE,
END_RESPONSE_TABLE;

TFindPane::TFindPane(TBrowserWindow* parent)
:
  TLayoutWindow(parent),
  TWindow(parent, 0, 0)
{
  Browser = parent;
  TLayoutMetrics lm;

  lm.X.Units = lm.Y.Units = lm.Width.Units = lm.Height.Units = lmPixels;

  // If layout window has a border, then it will automatically adjust
  // children by 1 pixel
  //
//  Attr.Style |= WS_BORDER;

  DrivePane = new TComboBox(this, ID_DrivePane, 0, 0, 0, 0,
    CBS_DROPDOWNLIST|CBS_SORT|CBS_NOINTEGRALHEIGHT, MAXDIR);

  DirPaneLabel = new TStatic(this, ID_DirPaneLabel, "Directory", 0, 0, 0, 0, 0);
  DirPaneLabel->Attr.Style |= SS_CENTER;

  DirPane = new TListBox(this, ID_DirPane, 0, 0, 0, 0);
  DirPane->Attr.Style |= LBS_NOINTEGRALHEIGHT;

  FilterPaneLabel = new TButton(this, ID_FilterPaneLabel, "Filter", 0, 0, 0, 0);
  FilterPaneLabel->Attr.Style |= SS_CENTER;

  FilterPane = new TEdit(this, ID_FilterPane, 0, 0, 0, 0, 0, 0);


  // (Drive &) DirPaneLabel
  //
  lm.Width.SameAs(lmParent, lmRight);
  lm.Height.Absolute(CaptionHeight);
  lm.X.SameAs(lmParent, lmLeft);
  lm.Y.SameAs(lmParent, lmTop);
  SetChildLayoutMetrics(*DirPaneLabel, lm);

  // Drive Pane
  //
  lm.Width.SameAs(lmParent, lmRight);
  lm.Height.Absolute(5*EditHeight);
  lm.X.SameAs(lmParent, lmLeft);
  lm.Y.Below(DirPaneLabel);
  SetChildLayoutMetrics(*DrivePane, lm);

  // Dir Pane
  //
  lm.X.SameAs(lmParent, lmLeft);
  lm.Y.Below(DrivePane, -(4 * EditHeight));
  lm.Width.SameAs(lmParent, lmRight);
  lm.Height.Above(FilterPaneLabel);
  SetChildLayoutMetrics(*DirPane, lm);

  // FilterPaneLabel
  //
  lm.Width.Absolute(ButtonWidth);
  lm.Height.Absolute(EditHeight);
  lm.X.SameAs(lmParent, lmLeft);
  lm.Y.Set(lmBottom, lmSameAs, lmParent, lmBottom);
  SetChildLayoutMetrics(*FilterPaneLabel, lm);

  // FilterPane
  //
  lm.Width.SameAs(lmParent, lmRight);
  lm.Height.Absolute(EditHeight);     // Would be nicer to calculate size
  lm.X.RightOf(FilterPaneLabel);
  lm.Y.SameAs(FilterPaneLabel, lmTop);
  SetChildLayoutMetrics(*FilterPane, lm);

  strcpy(Filter, "*.*");

  SetBkgndColor(TColor::Sys3dFace);
}

void
TFindPane::SetupWindow()
{
  char dirBuf[MAXDIR+1];
  char *ptr;
  TLayoutWindow::SetupWindow();

  // Fill list box with drives and directories
  //
  DirPane->DirectoryList(DDL_DIRECTORY | DDL_EXCLUSIVE, "*.*");
  DrivePane->DirectoryList(DDL_DRIVES | DDL_EXCLUSIVE, "*.*");

  // Set edit field in drive list
  //
  dirBuf[0] = (char)(getdisk()+'A');
  dirBuf[1] = 0;
  DrivePane->SetSelString(dirBuf, 0);

  // Update label with current drive and directory
  //
  ptr = getcwd(dirBuf, sizeof(dirBuf));

  DirPaneLabel->SetWindowFont(*Browser->CaptionFont, false);
  FilterPaneLabel->SetWindowFont(*Browser->CaptionFont, false);
  DirPaneLabel->SetText(ptr);
  FilterPane->SetText(Filter);
}

//
// Make sure comboboxes are not dropped when the window is re-sized or moved
// if they are, they'll be left floating
//
void
TFindPane::Paint(TDC& dc, bool erase, TRect& rect)
{
  if (DrivePane)
    DrivePane->HideList();

  TLayoutWindow::Paint(dc, erase, rect);
}

//
// make sure comboboxes are not dropped when the window is re-sized or moved
// if they are, they'll be left floating
//
void
TFindPane::EvSize(uint sizeType, TSize& size)
{
  if (DrivePane)
    DrivePane->HideList();

  TLayoutWindow::EvSize(sizeType, size);
}

void
TFindPane::SelectDrive()
{
  char buf[MaxEntry];    // Directory names look like [anydir]

  DrivePane->GetSelString(buf, sizeof buf);
  setdisk(buf[2]-'a');   // Directories are shown in list box as [-a-]

  Update();
}

void
TFindPane::SelectDir()
{
  char buf[MaxEntry];     // Directory names look like [anydir]
  DirPane->GetSelString(buf, sizeof buf);
  char* ptr = buf+1;      // Strip leading [
  buf[strlen(buf)-1] = 0; // Strip trailing ]
  chdir(ptr);

  Update();
}

void
TFindPane::SelectFilter()
{
  char buf[256];
  FilterPane->GetText(buf, sizeof(buf));  // Get text from edit control
  strcpy(Filter, buf);
  Update();
}

void
TFindPane::Update()
{
  // Update title bar with new directory
  //
  char dirBuf[MAXDIR];
  char* ptr = getcwd(dirBuf, sizeof(dirBuf));
  if (ptr)
    DirPaneLabel->SetText(ptr);

  DirPane->ClearList();
  DirPane->DirectoryList(DDL_DIRECTORY|DDL_EXCLUSIVE, "*.*");
  Browser->FilePane->ClearList();
  Browser->FilePane->DirectoryList(0, Filter);  // Update file list
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TBrowserWindow,TLayoutWindow)
  EV_LBN_SELCHANGE(ID_FilePane,SelectFile),
END_RESPONSE_TABLE;

TBrowserWindow::TBrowserWindow()
:
  TLayoutWindow(0),
  TWindow(0, 0, 0)
{
  TLayoutMetrics lm;

  lm.X.Units = lm.Y.Units = lm.Width.Units = lm.Height.Units = lmPixels;

  // If layout window has a border, then it will automatically adjust
  // children by 1 pixel
  //
  Attr.Style |= WS_BORDER;

  // Find a font that will fit into our small captions and buttons
  //
  CaptionFont = new TFont(
    "Small Fonts",              // facename
    -(CaptionHeight),           // height,
    0, 0, 0, FW_NORMAL,         // width, esc, orientation, weight
    VARIABLE_PITCH | FF_SWISS,  // Pitch and Family
    false, false, false,        // Italic, Underline, Strikeout
    ANSI_CHARSET,               // Charset
    OUT_CHARACTER_PRECIS,       // Output precision
    CLIP_DEFAULT_PRECIS,        // Clip precision
    PROOF_QUALITY               // Quality
  );

  FindPane = new TFindPane(this);

  lm.Width.PercentOf(lmParent, lmRight, 50);
  lm.Height.PercentOf(lmParent, lmBottom, 50);
  lm.X.SameAs(lmParent, lmLeft);
  lm.Y.SameAs(lmParent, lmTop);
  SetChildLayoutMetrics(*FindPane, lm);

  // File Pane ----------------------------------------------------------
  //
  FilePaneLabel = new TStatic(this, ID_FilePaneLabel, "Files", 0, 0, 0, 0, 0);
  FilePaneLabel->Attr.Style |= SS_CENTER;

  lm.Width.SameAs(lmParent, lmRight);
  lm.Height.Absolute(CaptionHeight);
  lm.X.RightOf(FindPane, 1);
  lm.Y.SameAs(FindPane, lmTop);
  SetChildLayoutMetrics(*FilePaneLabel, lm);

  FilePane = new TListBox(this, ID_FilePane, 0, 0, 0, 0);

  // Prevent list box from adjusting it's size to avoid partial lines
  //
  FilePane->Attr.Style |= LBS_NOINTEGRALHEIGHT;

  lm.Width.SameAs(lmParent, lmRight);
  lm.Height.SameAs(FindPane, lmBottom);
  lm.X.RightOf(FindPane, 1);
  lm.Y.Below(FilePaneLabel);
  SetChildLayoutMetrics(*FilePane, lm);

  EditPane = new TMyEdit(this, ID_EditPane);
  lm.Width.SameAs(lmParent, lmRight);
  lm.Height.SameAs(lmParent, lmBottom);
  lm.X.SameAs(lmParent, lmLeft);
  lm.Y.Below(FindPane, 1);
  SetChildLayoutMetrics(*EditPane, lm);

  SetBkgndColor(TColor::Sys3dFace);
}

void
TBrowserWindow::SetupWindow()
{
  TLayoutWindow::SetupWindow();

  // Fill list box with list of files in current directory
  //
  FilePane->DirectoryList(0, FindPane->Filter);

  // Switch to our small font
  //
  FilePaneLabel->SetWindowFont(*CaptionFont, false);
}

void
TBrowserWindow::SelectFile()
{
  char buf[MaxEntry];

  FilePane->GetSelString(buf, sizeof buf);

  // Here's where doc/view would allow us to switch to different views
  // for different docs easily.
  // For now, we'll get an error if we try to view a .exe file
  // or a file that's too big for the edit buffer.
  //
  if (EditPane->Read(buf)) {
    EditPane->Invalidate();
    EditPane->SetFileName(buf);
  }
  else {
    EditPane->SetText("File Error");
  }
}

//----------------------------------------------------------------------------

class TFileBrowserApp : public TApplication {
  public:
    TFileBrowserApp() : TApplication("") {}

    void InitMainWindow();
};

void
TFileBrowserApp::InitMainWindow()
{
  MainWindow = new TFrameWindow(0, "Owl File Browser", new TBrowserWindow());
  MainWindow->SetIcon(this, IDC_1);
  MainWindow->Attr.H = 300;
  MainWindow->Attr.W = 300;
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TFileBrowserApp().Run();
}
