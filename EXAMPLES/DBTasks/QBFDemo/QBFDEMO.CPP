//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USERES("Qbfdemo.res");
USEFORM("QBFForm.cpp", QueryForm);
USEFORM("Rsltform.cpp", ResultForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
      Application->Initialize();
      Application->CreateForm(__classid(TQueryForm), &QueryForm);
      Application->Run();
  }
  catch(Exception& e)
  {
      ShowMessage(e.Message);
  }
      return 0;
}
//---------------------------------------------------------------------------
