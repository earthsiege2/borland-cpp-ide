//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.0  $
//
// Simple controller driving Excel [Using TypeLibrary from Office 95 CD]
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#include "xl5en32.hxx"

HINSTANCE hInstance = 0;

void
PlayWithActiveSheet(Workbook& workbook)
{
  // Bind to sheet of active workbook
  //
  Worksheet worksheet;
  worksheet.Bind(LPDISPATCH(workbook.GetActiveSheet()));

  // Get range in worksheet
  //
  if (worksheet.IsBound()) {
    Range range;
    range.Bind(LPDISPATCH(worksheet.Range(string("A1"), string("H8"))));

    // Throw some random values in there - heck, it's free!
    //
    range.SetFormula(string("=rand()"));
  }
}

void
CreateAWorkbook(Workbooks& workbooks)
{
  // Create new active workbook
  //
  Workbook workbook;
  workbook.Bind(LPDISPATCH(workbooks.Add(TNoArg())));

  // Pass workbook object for more automation
  //
  PlayWithActiveSheet(workbook);

  // Save new document to current path
  //
  char path[_MAX_PATH];
  ::GetModuleFileName(hInstance, path, sizeof(path));

  // NOTE: Cheap way to strip extension from current app's path - Argh!
  //
  TNoArg _x;
  char *p = strstr(path, ".EXE");
  if (p) *p = 0;
  workbook.SaveAs(string(path), _x, _x, _x, _x, _x, _x, _x);
}

void
RetrieveWorkbooksObject(Application& xcl)
{
  // Have a 'Workbooks' object bind to workbook collection
  //
  Workbooks workbooks;
  workbooks.Bind(LPDISPATCH(xcl.Workbooks()));

  // Have some more fun
  //
  CreateAWorkbook(workbooks);
}

//
// Routine that jumps start the automation sample by launching EXCEL,
// making it visible...
//
void
AutomateExcel()
{
  // Instance of proxy object representing EXCEL v7.0 application
  //
  Application xcl;

  try {

    // Bind to application
    //
    xcl.Bind("Excel.Application.5");

    // Talk to application
    //
    try {

      // Make Excel visible
      //
      xcl.SetVisible(true);

      // Go have some fun...
      //
      RetrieveWorkbooksObject(xcl);

      // Hide Excel
      //
      xcl.SetVisible(false);
    }

    // Failure during Automation exchange with application
    //
    catch (xmsg& msg) {
      MessageBox(0, msg.why().c_str(), "Exception Info", MB_OK);
    }

    // Unload application - NOTE: Since we're invoking 'Quit' we need
    // to unbind to prevent a 'Release' call in the destructor of the
    // proxy object.
    //
    if (xcl.IsBound()) {
      xcl.Quit();
      xcl.Unbind(false);
    }
  }

  // Following most likely indicates a failure to bind/quit
  //
  catch (xmsg& msg) {
    MessageBox(0, msg.why().c_str(), "Exception Info", MB_OK);
  }
}

//
//
//
int PASCAL
WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance,
        LPSTR cmdLine, int cmdShow)
{
  try {
    hInstance= hInst;
    TOleInit initOle;
    AutomateExcel();
  }
  catch (xmsg& x) {
    MessageBox(0, x.why().c_str(), "Exception Info", MB_OK|MB_TASKMODAL);
  }
  return 0;
}
