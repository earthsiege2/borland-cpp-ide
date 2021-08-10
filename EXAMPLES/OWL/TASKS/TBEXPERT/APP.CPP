//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    app.cpp
//
// Date:        27-Sep-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "TBExpert.h"

char OriginalDir[MAXPATH];
char CurrentDir[MAXPATH];
bool Generate = true;
TGeneratedNames Names;

TGeneratedNames::TGeneratedNames()
{
  FrameInstance = new char[MAXPATH];
  ControlBarInstance = new char[MAXPATH];

  strcpy(FrameInstance, "frame");
  strcpy(ControlBarInstance, "controlBar");
}

TGeneratedNames::~TGeneratedNames()
{
  delete[] ControlBarInstance;
  delete[] FrameInstance;
}

//
// Application constructor
//
TTBExpertApp::TTBExpertApp()
:
  TApplication()
{
  getcwd(OriginalDir, MAXPATH);
  getcwd(CurrentDir, MAXPATH);
  GadgetFactories = new TGadgetFactory*[MaxGadgetFactories];
  for (int i = 0; i < MaxGadgetFactories; i++)
    GadgetFactories[i] = 0;
}


//
// Application destructor
//
TTBExpertApp::~TTBExpertApp()
{
  if (Generate) {
    ofstream f("test.txt");
    f << "//----------------------------------------------------------------------------" << endl;
    f << "// #defines" << endl;
    f << "//" << endl;
    GenerateDefines(f);
    f << endl;
    f << "//----------------------------------------------------------------------------" << endl;
    f << "// Declarations" << endl;
    f << "//" << endl;
    GenerateDeclarations(f);
    f << endl;
    f << "//----------------------------------------------------------------------------" << endl;
    f << "// Code section" << endl;
    f << "//" << endl;
    GenerateCode(f);
    f << endl;
  }

  chdir(OriginalDir);
  for (int i = 0; i < MaxGadgetFactories; i++)
    delete GadgetFactories[i];
  delete[] GadgetFactories;
}


//
// InitMainWindow
//
void
TTBExpertApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, "Toolbar Expert",
    new TTBExpertWindow);
  SetMainWindow(frame);
}

void
TTBExpertApp::GenerateDefines(ofstream& f)
{
  for (int i = 0; i < CountOfGadgetFactories; i++)
    if (GadgetFactories[i])
      GadgetFactories[i]->GenerateDefine(f);
}

void
TTBExpertApp::GenerateDeclarations(ofstream& f)
{
  f << "  TFrameWindow* " << Names.FrameInstance << ";" << endl;
  f << "  TControlBar* " << Names.ControlBarInstance;
  f << " = new TControlBar(" << Names.FrameInstance << ");" << endl;
}

void
TTBExpertApp::GenerateCode(ofstream& f)
{
  f << "  " << Names.FrameInstance << "->Insert(*" << Names.ControlBarInstance;
  f << ", TDecoratedFrame::Top);" << endl;
  for (int i = 0; i < CountOfGadgetFactories; i++) {
    if (GadgetFactories[i]) {
      f << "  " << Names.ControlBarInstance << "->Insert(";
      GadgetFactories[i]->GenerateCode(f);
      f << ");" << endl;
    }
  }
}

//
// OwlMain
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  InitCommonControls();
  TTBExpertApp app;
  return app.Run();
}

