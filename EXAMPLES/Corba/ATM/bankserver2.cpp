//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("BankServer2.res");
USEFORM("bankunit2.cpp", Bank2Form);
USEIDL("xaction.idl");
USEIDL("Banking.idl");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();
       Application->CreateForm(__classid(TBank2Form), &Bank2Form);
       Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
   return 0;
}
//---------------------------------------------------------------------------
