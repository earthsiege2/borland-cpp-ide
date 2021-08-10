//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#pragma link "WebReq.obj"
#pragma link "ComAppHlpr.obj"
#pragma link "WebInit.obj"
#pragma link "ReqMulti.obj"

//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", Form1);
USEFORM("MainPg.cpp", MainPage); /* TWebAppPageModule: File Type */
USEFORM("PhotoDataPg.cpp", PhotoData); /* TWebDataModule: File Type */
USEFORM("DisplayOptionsPg.cpp", DisplayOptionsPage); /* TWebPageModule: File Type */
USEFORM("LoginPg.cpp", LoginPage); /* TWebPageModule: File Type */
USEFORM("UploadPicturesPg.cpp", UploadPicturesPage); /* TWebPageModule: File Type */
USEFORM("AddUsersPg.cpp", AddUsersPage); /* TWebPageModule: File Type */
USEFORM("ErrorPg.cpp", ErrorPage); /* TWebPageModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  // Browse to: http://localhost:1024/PhotoGalleryDebugger.Photos
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

