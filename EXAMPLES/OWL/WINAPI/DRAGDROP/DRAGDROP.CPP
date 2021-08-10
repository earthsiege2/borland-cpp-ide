//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//
//
//   Drag and Drop example in OWL
//
//   This is a code example using the Drag and Drop feature in
//   Windows 3.1 with OWL.  The example shows how to drop files
//   into the client area of the main window and then print
//   out the file names that were dropped in the client area.
//   TMyWindow maintains this information in a List of Lists.
//   Each sub List is a set of files that were dropped.  The code
//   is well commented with Steps to follow the creation of the
//   application as well as comments for common pitfalls and
//   important lines of code that affect the performance of your
//   application.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\window.h>
#include <owl\framewin.h>
#include <owl\dc.h>
#include <stdio.h>
#include <dir.h>
#include <classlib\bags.h>

char HelpText[]=
  "\n\r"
  "This application must be run under Windows 3.1 or later.\n\r "
  "Bring up the Windows File Manager. Select a file with\n\r "
  "the left mouse button and keep the button down.\n\r "
  "Now drag the mouse over until it is on top of the drag\n\r "
  "n' drop window client area. Now release the left mouse\n\r"
  "button. You have just dragged and dropped a file. To\n\r "
  "drag a group of files, select the group with the Shift\n\r "
  "and arrow keys and then repeat the previous directions.";


//----------------------------------------------------------------------------

// TFileDrop class Maintains information about a dropped file,
// its name, where it was dropped, and whether or not it
// was in the client area
//
class TFileDrop {
  public:
    // Redefine all the pure virtual functions that make Object abstract.
    //
    operator == (const TFileDrop& other) const {return this == &other;}

    char*  FileName;
    TPoint Point;
    BOOL   InClientArea;

    HICON  Icon;
    BOOL   DefIcon;

    TFileDrop(char*, TPoint&, BOOL, TModule* module);
    ~TFileDrop();
    char* WhoAmI();
};

typedef TIBagAsVector<TFileDrop> TFileList;
typedef TIBagAsVectorIterator<TFileDrop> TFileListIter;
typedef TBagAsVector<TFileList*> TFileListList;
typedef TBagAsVectorIterator<TFileList*> TFileListListIter;

TFileDrop::TFileDrop(char* fileName, TPoint& p, BOOL inClient, TModule* module)
{
  char  exePath[MAXPATH];

  exePath[0] = 0;
  FileName = strcpy(new char[strlen(fileName)+1], fileName);
  Point = p;
  InClientArea = inClient;

  Icon = (WORD)FindExecutable(FileName, ".\\", exePath) <= 32 ? 0 :
          ::ExtractIcon(*module, exePath, 0);

  // Use a question mark if couldn't get the icon from the executable.
  //
  if ((WORD)Icon <= 1) {  // 0=no icons in exe,  1=not an exe
    Icon = LoadIcon(0, (WORD)Icon == 1 ? IDI_APPLICATION : IDI_QUESTION);
    DefIcon = TRUE;

  } else
    DefIcon = FALSE;

}

TFileDrop::~TFileDrop()
{
  delete FileName;
  if (!DefIcon)    // Don't call FreeResource() on the '?' icon
    FreeResource(Icon);
}

char*
TFileDrop::WhoAmI()
{
  static char buffer[80];
  sprintf(buffer, "File: %s (%d,%d) InClient: %d", FileName, Point.x, Point.y,
          InClientArea);
  return buffer;
}

//----------------------------------------------------------------------------

static void DoDelete(TFileList*& list, void*) {
  delete list;
}

class TMyWindow : public TWindow {
  public:
    TMyWindow();

  protected:
    void SetupWindow();
    void CleanupWindow();
    void Paint(TDC&, BOOL, TRect&);

    //----------------------------------------------------------------
    // Step 2:
    // Dispatch a message to WM_DROPFILES
    //
    void EvDropFiles(TDropInfo);
    void EvSize(UINT, TSize&) { Invalidate(); }
    void CmHowTo() { GetHelp = TRUE; Invalidate(); }
    void CmView() { GetHelp = FALSE; Invalidate(); }
    void CmClear() {
        GetHelp = FALSE;
        AllFiles->ForEach(DoDelete, 0);
        AllFiles->Flush();
        Invalidate();
    }
    void CmAbout() {
        MessageBox("DRAG n' DROP\nWritten using ObjectWindows\n"
                   "Copyright (c) 1991, 1993 Borland", "ABOUT BOX", MB_OK);
    }

  protected:
    TFileListList*  AllFiles;
                   // Each Object in the list will also be a list.
                   // These lists will contain the names of the files
                   // that have been dragged & dropped in a group.
  private:
    BOOL GetHelp;

  DECLARE_RESPONSE_TABLE(TMyWindow);
};

DEFINE_RESPONSE_TABLE1(TMyWindow, TWindow)
  EV_WM_SIZE,
  EV_WM_DROPFILES,
  EV_COMMAND(101, CmHowTo),
  EV_COMMAND(102, CmView),
  EV_COMMAND(103, CmClear),
  EV_COMMAND(104, CmAbout),
END_RESPONSE_TABLE;


//----------------------------------------------------------------
// AllFiles of TMyWindow is a linked list of Lists.
// Each List in the linked list will contain the file names
// that were received during a WM_DROPFILES messages.
// The following declarations are to build up the object
// which will desribe an individual file that was droped
// during one of these messages.
// Since these objects are derived from Object, they
// can be inserted into a List.
//----------------------------------------------------------------

TMyWindow::TMyWindow() : TWindow(0, 0, 0)
{
  AllFiles = new TFileListList;
  GetHelp = TRUE;
}

void
TMyWindow::SetupWindow()
{
  TWindow::SetupWindow();

  //----------------------------------------------------------------
  // Step 1:
  // calling DragAcceptFiles.  If you pass FALSE, you're saying
  // I don't accept them anymore.
  // WARNING: Don't do this in the constructor!  HWindow is NOT
  // valid at that point.
  //
  DragAcceptFiles(TRUE);
}

void
TMyWindow::CleanupWindow()
{
  //----------------------------------------------------------------
  // Step 9:
  // Don't accept files anymore
  //
//  DragAcceptFiles(FALSE);
  delete AllFiles;
  TWindow::CleanupWindow();
}

//----------------------------------------------------------------
//  Step 3:
//  Retrieve a handle to an internal data structure in
//  SHELL.DLL.  Get the info out of it.
//
void
TMyWindow::EvDropFiles(TDropInfo drop)
{
  GetHelp = FALSE;

  //----------------------------------------------------------------
  // Step 4:
  // Find out how many files are dropped,
  //
  int totalNumberOfFiles = drop.DragQueryFileCount();

  TFileList* files = new TFileList;

  for (WORD i = 0; i < totalNumberOfFiles; i++) {
    //----------------------------------------------------------------
    // Step 5:
    // Get the length of a filename.
    //
    UINT  fileLength = drop.DragQueryFileNameLen(i)+1;
    char* fileName = new char[fileLength];

    //----------------------------------------------------------------
    // Step 6:
    // Copy a file name.   Tell DragQueryFile the file
    // your interested in (i) and the length of your buffer.
    // NOTE: Make sure that the length is 1 more than the filename
    // to make room for the null charater!
    //
    drop.DragQueryFile(i, fileName, fileLength);

    //----------------------------------------------------------------
    // Step 7:
    // Getting the file dropped. The location is relative to your
    // client coordinates, and will have negative values if dropped in
    // the non client parts of the window.
    //
    // DragQueryPoint copies that point where the file was dropped
    // and returns whether or not the point is in the client area.
    // Regardless of whether or not the file is dropped in the client
    // or non-client area of the window, you will still receive the
    // file name.
    //
    TPoint point;
    BOOL   inClientArea = drop.DragQueryPoint(point);
    files->Add(new TFileDrop(fileName, point, inClientArea, GetModule()));
  }
  AllFiles->Add(files);  // Add this sublist of dropped files to the big list.

  //----------------------------------------------------------------
  // Step 8:
  // Release the memory shell allocated for this handle
  // with DragFinish.
  // NOTE: This is a real easy step to forget and could
  // explain memory leaks and incorrect program performance.
  //
  drop.DragFinish();

  Invalidate();  // Make sure we repaint.
}

void
TMyWindow::Paint(TDC& dc, BOOL, TRect&)
{
  if (GetHelp) {
    TRect rect;
    GetClientRect(rect);
    dc.DrawText(HelpText, strlen(HelpText), rect,
                DT_NOCLIP|DT_CENTER|DT_WORDBREAK);
  } else {
    dc.SetBkMode(TRANSPARENT);

    // get a list iterator for the main list.
    //
    TFileListListIter allFileI(*AllFiles);
    int i = 0;

    // for each element in the main list that is not 0, get a
    // list iterator for that element, which is itself a list,
    // call it a sub list
    //
    while (allFileI) {
      if (allFileI.Current()) {
        TFileListIter subListI(*allFileI.Current());
        // for each element in the sub list, get the string
        // which describes it, we know these elements are
        // instances of the TFileDrop class
        //
        while (subListI) {
          char* str = subListI.Current()->WhoAmI();
          DrawIcon(dc, 10, 20*i, subListI.Current()->Icon);
          dc.TextOut(TPoint(60, 20*i), str);
          i += 2;
          subListI++;
        }
        allFileI++;
      }
    }
  }
}

//----------------------------------------------------------------------------

class TMyApp : public TApplication {
  public:
    TMyApp() : TApplication() {}
    void InitMainWindow();
};

void
TMyApp::InitMainWindow()
{
  MainWindow = new TFrameWindow(0, "Drag & Drop Example", new TMyWindow);
  MainWindow->AssignMenu("DRAGMENU");
  MainWindow->EnableKBHandler();
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMyApp().Run();
}
