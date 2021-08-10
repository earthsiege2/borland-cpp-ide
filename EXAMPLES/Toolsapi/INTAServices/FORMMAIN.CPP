//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <toolsapi.hpp>

#include "FormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TDisplayForm::TDisplayForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDisplayForm::FormShow(TObject *Sender)
{
  int i;
  TCustomActionList *AList;
  _di_INTAServices IDE;
  HRESULT hr;

  hr = BorlandIDEServices->QueryInterface(__uuidof(INTAServices), (void **)&IDE);
  if (SUCCEEDED(hr))
  {
    AList = IDE->GetActionList();
    for (i = 0; i < AList->ActionCount; i++)
      ComboBox1->Items->Add((AList->Actions[i])->Name);
  }

  ComboBox1->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TDisplayForm::Button1Click(TObject *Sender)
{
  if (OpenPictureDialog1->Execute())
    Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TDisplayForm::BitBtn1Click(TObject *Sender)
{
  int Index;
  int i;
  TCustomActionList *AList;
  TContainedAction *Temp;
  _di_INTAServices IDE;
  HRESULT hr;

  hr = BorlandIDEServices->QueryInterface(__uuidof(INTAServices), (void **)&IDE);
  if (SUCCEEDED(hr))
  {
   Index = IDE->AddMasked(Image1->Picture->Bitmap,
                            Image1->Picture->Bitmap->TransparentColor, "New image");
    if (Index == -1)
      throw Exception("Error loading image for ToolButton in a custom package");

    AList = IDE->GetActionList();
    for (i = 0; i < AList->ActionCount; i++)
    {
      Temp = AList->Actions[i];
      if (ComboBox1->Items->Strings[ComboBox1->ItemIndex] == Temp->Name)
        dynamic_cast<TAction *>(Temp)->ImageIndex = Index;
    }
  }
}
//---------------------------------------------------------------------------

