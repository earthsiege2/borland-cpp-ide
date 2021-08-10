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
  ::CLSIDFromString(WideString("{9786E02F-1B47-415C-9E38-6CE24BB8351E}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "DumpModules", "C++Builder WebBroker Application - 'DumpModules'");
}
#pragma startup initFunc 31

