//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("ddraw2.res");
USEFORM("Main.cpp", FormMain);
USERC("ddex2.rc");
USEUNIT("..\Utils\ddutil.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();
       Application->CreateForm(__classid(TFormMain), &FormMain);
       Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
   return 0;
}
//---------------------------------------------------------------------------
