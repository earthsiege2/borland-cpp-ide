//---------------------------------------------------------------------------
#include <WebBroker.hpp>
#include <ApacheApp.hpp>
#pragma hdrstop

USEFORM("HelloUnit.cpp", WebModule1); /* TWebModule: File Type */
//---------------------------------------------------------------------------
#define Application Webbroker::Application

#pragma link "ApacheApp.obj"
#pragma link "webbroker.obj"

//---------------------------------------------------------------------------
extern "C"
{
  /* This module is the exported entry point accessed by Apache.
     Use the name of this variable in the httpd.conf file when loading
     this module, but preced it with an underscore:

     #### Start httpd.conf suggestion
     LoadModule _Project1_module "C:\FullPathToTheDll.dll"
     <Location /some_location>
       SetHandler Project1-handler
     </Location>
    #### End httpd.conf suggestion

    Be sure to put the LoadModule directive after the ClearModuleList
    directive in the httpd.conf file.

    To change the default handler name, do a strcpy in the DllEntryPoint
    function below, such as:

    ...

      if (reason == DLL_PROCESS_ATTACH) {
        strcpy(ContentType, "custom_handler_name-handler");
    ...

    */

  Httpd::module __declspec(dllexport) hello_module;
}

//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  try
  {
    if (reason == DLL_PROCESS_ATTACH) {
      strcpy(ContentType, "hello-handler");
      strcpy(ModuleName, "mod_hello");
      Apacheapp::set_module(&hello_module);

                 Application->Initialize();
                 Application->CreateForm(__classid(TWebModule1), &WebModule1);
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

