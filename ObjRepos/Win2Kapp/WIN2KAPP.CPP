//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("W2kMain.cpp", Win2kAppForm);
USERC("W2kStrs.rc");
USERES("WIN2kAPP.res");
USEFORM("about.cpp", AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TWin2kAppForm), &Win2kAppForm);
	Application->CreateForm(__classid(TAboutBox), &AboutBox);
	Application->Run();

	return 0;
}
//---------------------------------------------------------------------
