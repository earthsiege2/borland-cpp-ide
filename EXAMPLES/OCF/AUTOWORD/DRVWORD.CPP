//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1996, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.1  $
//
// Sample illustrating how to Automate MS Word [Office/95 product]
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#include "wb70en32.hxx"

// Instance handle of this application
//
HINSTANCE hInstance=0;

// Simple routine which binds to Word and creates a simple file with some
// text in it.
//
void
AutomateWord()
{
  WordBasic word;
  try {

    // Bind to application
    //
    word.Bind("Word.Basic");

    // Talk to application
    //
    try {

      // Create a static instance of a noarg to make it easy to have
      // non-specified optional arguments.
      //
      static TNoArg _x;

      // Display the application
      //
      word.AppShow(string(""));

      // Create a new document
      //
      word.FileNewDefault();

      // Put some text in document
      //
      for (int i=0; i<6; i++) {
        word.InsertPara();
        word.Insert("Text inserted by an OCF Automation Controller at ");
        word.InsertDateTime(_x, _x);

        // Tweak font for fun!
        //
        word.GrowFont();
      }

      // Save new document to current path
      //
      char path[_MAX_PATH];
      ::GetModuleFileName(hInstance, path, sizeof(path));

      // NOTE: Cheap way to strip extension from current app's path - Argh!
      //
      char *p = strstr(path, ".EXE");
      if (p) *p = 0;
      word.FileSaveAs(string(path), _x, _x, _x, _x, _x, _x, _x, _x, _x, _x);
    }

    // Failure during Automation exchange with application
    //
    catch (xmsg& msg) {
      MessageBox(0, msg.why().c_str(), "Exception Info", MB_OK);
    }
  }

  // Following most likely indicates a failure to bind/quit
  //
  catch (xmsg& msg) {
    MessageBox(0, msg.why().c_str(), "Exception Info", MB_OK);
  }
}

int PASCAL
WinMain(HINSTANCE hInst, HINSTANCE /*hPrevInstance*/,
        LPSTR /*cmdLine*/, int /*cmdShow*/)
{
  hInstance = hInst;
  try {
    TOleInit initOle;
    AutomateWord();
  }
  catch (xmsg& x) {
    MessageBox(0, x.why().c_str(), "Exception Info", MB_OK|MB_TASKMODAL);
  }
  return 0;
}
