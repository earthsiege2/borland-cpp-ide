//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <memory>
#include <cassert>

#include "SingleInstanceSampleUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SingleInstance"
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SingleAppInstance1ReceiveCommandLine(
      TObject *Sender, char *CommandLine)
{
  mCommandLines->Lines->Add(CommandLine);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SingleAppInstance1SecondInstance(TObject *Sender,
      bool &ShutDown)
{
  ShowMessage("Ho! I am a second instance!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btCloseClick(TObject *Sender)
{
  Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btTestClick(TObject *Sender)
{
  std::auto_ptr<TSingleAppInstance> ManualInstance;

  ManualInstance.reset(new TSingleAppInstance(this));
  ManualInstance->Enabled = true;

  assert(ManualInstance->Enabled == false);

  ManualInstance.reset(new TSingleAppInstance(NULL));
  ManualInstance->Enabled = true;

  assert(ManualInstance->Enabled == false);

  MessageDlg( "The component passed the internal consistency checks.",
              mtInformation,
              TMsgDlgButtons() << mbOK,
              0 );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btLaunchInstanceClick(TObject *Sender)
{
  STARTUPINFO si = { sizeof(STARTUPINFO) };
  PROCESS_INFORMATION pi;

  Win32Check( CreateProcess( Application->ExeName.c_str(),
                             "This is the second instance...",
                             NULL, NULL,
                             false,
                             0,
                             NULL, NULL,
                             &si, &pi) );

  Win32Check( CloseHandle(pi.hThread) );
  Win32Check( CloseHandle(pi.hProcess) );
}
//---------------------------------------------------------------------------

