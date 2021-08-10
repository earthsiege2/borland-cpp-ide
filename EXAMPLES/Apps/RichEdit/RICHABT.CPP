//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "RichAbt.h"
#include <stdio.h>
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm2 *Form2;
//----------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent *Owner)
  : TForm(Owner)
{
}
//----------------------------------------------------------------------------
 void __fastcall TForm2::FormShow(TObject* /*Sender*/)
{
     TMemoryStatus MS;
     MS.dwLength = sizeof(MS);
     GlobalMemoryStatus(&MS);
     PhysMem->Caption = FormatFloat("#,###' KB'", MS.dwTotalPhys / 1024);
     CHAR lpMemLoad[5];
     sprintf(lpMemLoad, "%d %%", MS.dwMemoryLoad);
     FreeRes->Caption = lpMemLoad;
}
//----------------------------------------------------------------------------

