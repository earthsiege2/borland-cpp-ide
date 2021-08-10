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
  ::CLSIDFromString(WideString("{F5ABCC43-5685-45E0-9269-89C18603E8F9}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "CountryEditor", "C++Builder WebBroker Application - 'CountryEditor'");
}
#pragma startup initFunc 31

