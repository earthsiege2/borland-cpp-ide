//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("atmserver.res");
USEFORM("atmserverunit.cpp", Form2);
USEIDL("xaction.idl");
USEIDL("Banking.idl");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();
       Application->CreateForm(__classid(TForm2), &Form2);
       Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
   return 0;
}
//---------------------------------------------------------------------------

