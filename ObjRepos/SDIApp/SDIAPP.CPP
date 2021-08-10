//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("SDIMain.cpp", SDIAppForm);
USEFORM("About.cpp", AboutBox);
USERES("sdiapp.res");
//----------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TSDIAppForm), &SDIAppForm);
	Application->CreateForm(__classid(TAboutBox), &AboutBox);
	Application->Run();

	return 0;
}
//---------------------------------------------------------------------
