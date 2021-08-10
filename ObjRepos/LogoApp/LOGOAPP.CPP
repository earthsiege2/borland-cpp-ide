//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("LogoMain.cpp", LogoAppForm);
USERC("LogoStrs.rc");
USERES("LogoApp.res");
USEFORM("about.cpp", AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TLogoAppForm), &LogoAppForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->Run();

	return 0;
}
//---------------------------------------------------------------------
