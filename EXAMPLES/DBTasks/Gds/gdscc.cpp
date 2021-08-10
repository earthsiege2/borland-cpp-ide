//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("DataMod.cpp", Data);
USEFORM("..\OBJRepos\basemod.cpp", Base);
USEFORM("CustMod.cpp", Cust);
USEFORM("homemod.cpp", Home);
USEFORM("TermMod.cpp", Term);
USEFORM("$(BCB)\ObjRepos\customdm.cpp", CustomerData); /* TDataModule: File Type */
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
