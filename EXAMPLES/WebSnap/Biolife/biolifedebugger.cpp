//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#pragma link "WebReq.obj"
#pragma link "ComAppHlpr.obj"
#pragma link "WebInit.obj"
#pragma link "ReqMulti.obj"

//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", MainForm);
USEFORM("MainPg.cpp", MainPage); /* TWebAppPageModule: File Type */
USEFORM("DataMod.cpp", BioDataModule); /* TWebDataModule: File Type */
USEFORM("DetailsPg.cpp", DetailsPage); /* TWebPageModule: File Type */
USEFORM("GridPg.cpp", GridPage); /* TWebPageModule: File Type */
USEFORM("LoginPg.cpp", LoginPage); /* TWebPageModule: File Type */
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
    Sysutils::ShowException(&exception, System::ExceptAddr());
  }
  return 0;
}
//---------------------------------------------------------------------------

