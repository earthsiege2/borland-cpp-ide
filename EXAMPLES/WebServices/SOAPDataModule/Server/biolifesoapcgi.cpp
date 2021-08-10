//---------------------------------------------------------------------------
#include <condefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SysUtils.hpp>
#include <WebBroker.hpp>
#include <CGIApp.hpp>
#pragma hdrstop
USEFORM("Unit1.cpp", WebModule1); /* TWebModule: File Type */
USEFORM("Unit2.cpp", BiolifeService); /* TSoapDataModule: File Type */
//---------------------------------------------------------------------------
#define Application Webbroker::Application
#pragma link "cgiapp.obj"
#pragma link "webbroker.obj"
#pragma link "ReqMulti.obj"
#pragma link "WebSnap.lib"
#pragma link "WebDSnap.lib"
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  try
  {
    Application->Initialize();
    Application->CreateForm(__classid(TWebModule1), &WebModule1);
                 Application->Run();
  }
  catch (Exception &exception)
  {
    Sysutils::ShowException(&exception, System::ExceptAddr());
  }
  return 0;
}
//---------------------------------------------------------------------------
