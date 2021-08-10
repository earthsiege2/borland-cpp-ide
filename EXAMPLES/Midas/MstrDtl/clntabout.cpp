//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ClntAbout.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
//--------------------------------------------------------------------- 
void __fastcall ShowAboutBox(void)
{
  TAboutBox *AboutBox;

  __try
  {
    AboutBox = new TAboutBox(Application);
    AboutBox->ShowModal();
  }
  __finally
  {
    delete AboutBox;
  }
}
//---------------------------------------------------------------------
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::FormShow(TObject *Sender)
{
  ProgramIcon->Picture->Icon->Assign(Application->Icon);        
}
//---------------------------------------------------------------------------

