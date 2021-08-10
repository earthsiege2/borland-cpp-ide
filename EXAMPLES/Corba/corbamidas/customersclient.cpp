//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <corba.h>
USERES("CustomersClient.res");
USEFORM("ClientFormU.cpp", ClientForm);
USEIDL("Customers.idl");
USEFORM("ClientDataModuleU.cpp", ClientDataModule); /* TDataModule: DesignClass */
USEUNIT("Any2Variant.cpp");
USEUNIT("Customers_c.cpp");
USEUNIT("Customers_s.cpp");
//---------------------------------------------------------------------------
#pragma warn -aus
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     // Initialize the ORB
     CORBA::ORB_var orb = CORBA::ORB_init(__argc, __argv);
     Application->CreateForm(__classid(TClientDataModule), &ClientDataModule);
     Application->CreateForm(__classid(TClientForm), &ClientForm);
     Application->Run();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
  }
  return 0;
}
#pragma warn .aus
//---------------------------------------------------------------------------
