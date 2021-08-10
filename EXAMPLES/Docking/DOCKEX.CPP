//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("dockex.res");
USEFORM("main.cpp", MainForm);
USEFORM("dockform.cpp", DockableForm);
USEFORM("conjoinhost.cpp", ConjoinDockHost);
USEFORM("tabhost.cpp", TabDockHost);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->CreateForm(__classid(TMainForm), &MainForm);
     Application->Run();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
  }
  return 0;
}
//---------------------------------------------------------------------------
