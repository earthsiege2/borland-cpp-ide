//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000 Inprise Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("textdata_pkg.res");
USERES("textdata.dcr");
USEUNIT("TextDataSet.cpp");
USEPACKAGE("vcl50.bpi");
USEPACKAGE("vcldb50.bpi");
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  return 1;
}
//---------------------------------------------------------------------------
