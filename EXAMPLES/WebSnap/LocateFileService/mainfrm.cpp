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
  ::CLSIDFromString(WideString("{FA38240C-57A8-4E14-BBFC-41E3E74FFB2D}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "LocateService",
    "C++Builder WebBroker Application - 'LocateService'");
}
#pragma startup initFunc 31


