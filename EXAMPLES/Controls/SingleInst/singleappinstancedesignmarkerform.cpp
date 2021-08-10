
#include <vcl.h>
#pragma hdrstop

#include "SingleAppInstanceDesignMarkerForm.h"
#include "SingleInstance.h"

#include <ComObj.Hpp>

#define NDEBUG
#include <cassert>

#pragma package(smart_init)
#pragma resource "*.dfm"

void __fastcall ShowErrorSlashInName(void)
{
  MessageBeep(MB_ICONHAND);

  MessageDlg( "You are trying to assign text to the Marker property that " \
              "contains the slash character ('\\'). " \
              "Due to an implementation restriction, this is not possible.\r\n" \
              "\r\n" \
              "Please remove the slash character from the Marker text.",
              mtError,
              TMsgDlgButtons() << mbOK,
              0 );
}

//---------------------------------------------------------------------------

__fastcall TfrmMarkerPropertyEditor::TfrmMarkerPropertyEditor(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TfrmMarkerPropertyEditor::btOKClick(TObject *Sender)
{
  FMarkerText = cbMarkerText->Text;

  if (!TSingleAppInstance::IsValidMarkerText(FMarkerText))
  {
    ShowErrorSlashInName();

    return;
  }

  ModalResult = mrOk;
}

void __fastcall TfrmMarkerPropertyEditor::cbMarkerTextKeyPress(
  TObject *Sender, char &Key)
{
  // The marker may not contain the "\" character
  if (Key == '\\')
  {
    Key = 0;

    ShowErrorSlashInName();
  }
}

void __fastcall TfrmMarkerPropertyEditor::SetMarkerText(const String& Value)
{
  FMarkerText = Value;
  cbMarkerText->Text = FMarkerText;
}

AnsiString GetGUIDString(void)
{
  GUID SystemUniqueMarker;
  AnsiString ResultString;

  LPOLESTR StringBuffer;
  int StringBufferSize = 0;
  int ApiResult;

  OleCheck( CoCreateGuid(&SystemUniqueMarker) );

  StringBuffer = 0;
  try
  {
    do
    {
      StringBufferSize += 200;
      assert(StringBufferSize < 10 * 1024); // Bound the string buffer size

      delete[] StringBuffer;
      StringBuffer = new wchar_t[StringBufferSize];

      ApiResult = StringFromGUID2(SystemUniqueMarker, StringBuffer, StringBufferSize);
      if (ApiResult > 0)
        break;

    } while (StringBufferSize == 0);

    ResultString = static_cast<PWideChar>(StringBuffer);
  }
  __finally
  {
    delete[] StringBuffer;
  }

  return ResultString;
}

void __fastcall TfrmMarkerPropertyEditor::FillMarkerComboWithValues(void)
{
  cbMarkerText->Items->Add(GetGUIDString());
}

void __fastcall TfrmMarkerPropertyEditor::FormShow(TObject *Sender)
{
  FillMarkerComboWithValues();
}

void __fastcall TfrmMarkerPropertyEditor::btHelpClick(TObject *Sender)
{
  MessageDlg( "Sorry, online help has not been implemented (yet).",
              mtInformation,
              TMsgDlgButtons() << mbOK,
              0);
}


