//---------------------------------------------------------------------------
/*
  To use this Apache Shared Module project:
  Add the following to your httpd.conf file:

#### Start config (make sure it is after the ClearModuleList line)
LoadModule _photos_module "c:\Full path to dll"
<Location /photos>
  SetHandler photos-handler
</Location>
#### End config

Start apache, and browse to:
http://localhost/photos

Troubleshooting:
Make sure you don't have IIS running.
Make sure your port in httpd.conf is 80.
Notice the underscore in front of the module name in the LoadModule
  directive.

*/


#include <WebBroker.hpp>
#include <ApacheApp.hpp>
#pragma hdrstop

USEFORM("MainPg.cpp", MainPage); /* TWebAppPageModule: File Type */
USEFORM("AddUsersPg.cpp", AddUsersPage); /* TWebPageModule: File Type */
USEFORM("DisplayOptionsPg.cpp", DisplayOptionsPage); /* TWebPageModule: File Type */
USEFORM("ErrorPg.cpp", ErrorPage); /* TWebPageModule: File Type */
USEFORM("LoginPg.cpp", LoginPage); /* TWebPageModule: File Type */
USEFORM("PhotoDataPg.cpp", PhotoData); /* TWebDataModule: File Type */
USEFORM("UploadPicturesPg.cpp", UploadPicturesPage); /* TWebPageModule: File Type */
//---------------------------------------------------------------------------
#define Application Webbroker::Application

#pragma link "ApacheApp.obj"
#pragma link "webbroker.obj"
#pragma link "webinit.obj"

//---------------------------------------------------------------------------
extern "C"
{
  Httpd::module __declspec(dllexport) photos_module;
}

//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  try
  {
    if (reason == DLL_PROCESS_ATTACH) {
      strcpy(ContentType, "photos-handler");
      Apacheapp::set_module(&photos_module);
		  Application->Initialize();
		  Application->Run();
    }
  }
  catch (Exception &exception)
  {
  }
  return 1;
}
//---------------------------------------------------------------------------
#undef Application
//---------------------------------------------------------------------------

