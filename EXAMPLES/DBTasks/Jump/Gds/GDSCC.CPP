//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEDATAMODULE("DataMod.cpp", Data);
USEFILE("readme.txt");
USEFORM("..\..\..\..\ObjRepos\customdm.cpp", CustomerData); /* TDataModule: DesignClass */
USEFORM("..\OBJREPOS\BASEMOD.cpp", Base);
USEFORM("CustMod.cpp", Cust);
USEFORM("HomeMod.cpp", Home);
USEFORM("TermMod.cpp", Term);
USERES("Gdscc.res");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
        Application->Initialize();
        Application->CreateForm(__classid(THome), &Home);
	Application->CreateForm(__classid(TData), &Data);
	Application->CreateForm(__classid(TCust), &Cust);
	Application->CreateForm(__classid(TTerm), &Term);
	Application->CreateForm(__classid(TCustomerData), &CustomerData);
	Application->Run();
   }
   catch (Exception &exception)
   {
        Application->ShowException(&exception);
   }
        return 0;
}
//---------------------------------------------------------------------------
