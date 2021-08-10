//---------------------------------------------------------------------------
#include "about.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutBox *AboutBox;

 __fastcall TAboutBox::TAboutBox(TComponent* Owner) : TForm(Owner)
{
}

void __fastcall TAboutBox::FormCreate(TObject *Sender)
{
  Caption = Format("About %s",
                   ARRAYOFCONST((Application->Title)));
  ProgramIcon->Picture->Assign(Application->Icon);
  ProgramName->Caption = Application->Title;
}


void __fastcall ShowAboutBox()
{
  TAboutBox* a = new TAboutBox(Application);
  try{
    a->ShowModal();
  }
  catch(...){
    a->Free();
    throw;
  }
  a->Free();
}

