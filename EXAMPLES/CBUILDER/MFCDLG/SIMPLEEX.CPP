//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("SimpleCB.cpp", Form1);
USERES("SimpleEx.res");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TForm1), &Form1);
	Application->Run();

	return 0;
}
//---------------------------------------------------------------------------
