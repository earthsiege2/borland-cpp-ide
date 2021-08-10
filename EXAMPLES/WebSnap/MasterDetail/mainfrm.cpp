//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop
#include "MainFrm.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void initFunc()
{
  GUID appGuid;
  ::CLSIDFromString(WideString("{40F893FA-3A45-4BF1-876B-C07ACDF1DF44}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "MasterDetail", "C++Builder WebBroker Application - 'MasterDetail'");
}
#pragma startup initFunc 31

