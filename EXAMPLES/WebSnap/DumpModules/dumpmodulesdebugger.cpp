//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#pragma link "WebReq.obj"
#pragma link "ComAppHlpr.obj"
#pragma link "WebInit.obj"
//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", Form1);
USEFORM("MainPg.cpp", MainPage); /* TWebAppPageModule: File Type */
USEFORM("DumpModulesPg.cpp", DumpModulesPage); /* TWebPageModule: File Type */
USEFORM("CountryTablePg.cpp", CountryTablePage); /* TWebPageModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
    Application->Initialize();
    Application->CreateForm(__classid(TForm1), &Form1);
     Application->Run();
  }
  catch (Exception &exception)
  {
    Sysutils::ShowException(&exception, System::ExceptAddr());
  }
  return 0;
}
//---------------------------------------------------------------------------

