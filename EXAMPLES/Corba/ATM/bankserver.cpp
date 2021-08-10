//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("BankServer.res");
USEFORM("BankUnit.cpp", BankForm);
USEIDL("Banking.idl");
USEIDL("xaction.idl");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();
       Application->CreateForm(__classid(TBankForm), &BankForm);
       Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
   return 0;
}
//---------------------------------------------------------------------------
