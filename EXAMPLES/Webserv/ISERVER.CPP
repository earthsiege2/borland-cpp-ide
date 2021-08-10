//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <WebBroker.hpp>
#include <ISAPIApp.hpp>
#include <Isapi2.hpp>
//---------------------------------------------------------------------------
#pragma hdrstop
USEFORM("main.cpp", CInfoModule); /* TWebModule: DesignClass */
USEFILE("readme.txt");
//---------------------------------------------------------------------------
#define Application Webbroker::Application

#pragma link "isapiapp.obj"
#pragma link "webbroker.obj"
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TCInfoModule), &CInfoModule);
                 Application->Run();
	}
	catch (Exception &exception)
	{
	}
	return 1;
}
//---------------------------------------------------------------------------
extern "C"
{
  BOOL __export WINAPI GetExtensionVersion(Isapi2::THSE_VERSION_INFO &Ver)
  {
      return Isapiapp::GetExtensionVersion(Ver);
  }
  //---------------------------------------------------------------------------
  int __export WINAPI HttpExtensionProc(Isapi2::TEXTENSION_CONTROL_BLOCK &ECB)
  {
      return Isapiapp::HttpExtensionProc(ECB);
  }
  //---------------------------------------------------------------------------
  BOOL __export WINAPI TerminateExtension(int dwFlags)
  {
      return Isapiapp::TerminateExtension(dwFlags);
  }
}
//---------------------------------------------------------------------------
