//---------------------------------------------------------------------------
#include <WebBroker.hpp>
#include <ISAPIApp.hpp>
#include <Isapi2.hpp>
#pragma hdrstop

#include <ComObj.hpp>

USEFORM("AddUsersPg.cpp", AddUsersPage); /* TWebPageModule: File Type */
USEFORM("DisplayOptionsPg.cpp", DisplayOptionsPage); /* TWebPageModule: File Type */
USEFORM("ErrorPg.cpp", ErrorPage); /* TWebPageModule: File Type */
USEFORM("LoginPg.cpp", LoginPage); /* TWebPageModule: File Type */
USEFORM("MainPg.cpp", MainPage); /* TWebAppPageModule: File Type */
USEFORM("PhotoDataPg.cpp", PhotoData); /* TWebDataModule: File Type */
USEFORM("UploadPicturesPg.cpp", UploadPicturesPage); /* TWebPageModule: File Type */
//---------------------------------------------------------------------------
#define Application Webbroker::Application

#pragma link "isapiapp.obj"
#pragma link "webbroker.obj"
#pragma link "webinit.obj"
#pragma link "reqmulti.obj"
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  CoInitFlags = COINIT_MULTITHREADED; // Due to multi-threading
  try
  {
    if (reason == DLL_PROCESS_ATTACH) {
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
extern "C"
{
  BOOL __declspec(dllexport) WINAPI GetExtensionVersion(Isapi2::THSE_VERSION_INFO &Ver)
  {
    return Isapiapp::GetExtensionVersion(Ver);
  }
  //---------------------------------------------------------------------------
  unsigned __declspec(dllexport) WINAPI HttpExtensionProc(Isapi2::TEXTENSION_CONTROL_BLOCK &ECB)
  {
    return Isapiapp::HttpExtensionProc(ECB);
  }
  //---------------------------------------------------------------------------
  BOOL __declspec(dllexport) WINAPI TerminateExtension(int dwFlags)
  {
    return Isapiapp::TerminateExtension(dwFlags);
  }
}
//---------------------------------------------------------------------------
#undef Application
//---------------------------------------------------------------------------
