#include <vcl.h>
#pragma hdrstop

#include <Dialogs.Hpp>

#include <windows.h>

//
// Includes to support design-time code
//
#include <DesignIntf.hpp>
#include <ToolsApi.hpp>

//
// Version info component and declarations of component + property editor
//
#include "VersionInfoComponent.h"
#include "VersionInfoUI.h"
#include "VersionInfoDesignTimeCode.h"

#define NDEBUG
#include <cassert>

#pragma package(smart_init)

//---------------------------------------------------------------------------

static bool __fastcall GetVersionInfoFileNameViaDialog(String& ResultFileName)
{
  TOpenDialog* AOpenDialog;
  bool ResultAccepted;

  AOpenDialog = new TOpenDialog(NULL);
  try
  {
    AOpenDialog->DefaultExt = "*.exe";
    AOpenDialog->FileName = ResultFileName;
    AOpenDialog->Filter = "Binary files (*.exe;*.dll;*.ocx)|*.EXE;*.DLL;*.OCX|All files (*.*)|*.*";

    AOpenDialog->Options = TOpenOptions() << ofPathMustExist << ofFileMustExist
                                          << ofHideReadOnly << ofEnableSizing;

    ResultAccepted = AOpenDialog->Execute();
    if (ResultAccepted)
    {
      ResultFileName = ExpandFileName(AOpenDialog->FileName);
    }
  }
  __finally
  {
    delete AOpenDialog;
  }

  return ResultAccepted;
}

//---------------------------------------------------------------------------

void __fastcall TVersionInfoFileNameEditor::Edit(void)
{
  String NewFileName;

  NewFileName = this->GetStrValue();

  if (GetVersionInfoFileNameViaDialog(NewFileName))
  {
    // Update the property with the new value...
    SetValue(NewFileName);
    // ...and notify the designer that (implicitly)
    // the whole component has changed its state
    // as a result of the FileName's setter method.
    Designer->Modified();
  }
}

TPropertyAttributes __fastcall TVersionInfoFileNameEditor::GetAttributes(void)
{
  return (TPropertyAttributes() << paDialog);
}

AnsiString __fastcall TVersionInfoFileNameEditor::GetValue(void)
{
  AnsiString Result;

  Result = inherited::GetValue();
  if (Result.Length() == 0)
    Result = "(Current Application)";

  return Result;
}

void __fastcall TVersionInfoFileNameEditor::SetValue(const AnsiString Value)
{
  inherited::SetValue(Value);
}

//-----------------------------------------------------------------------------------

TPropertyAttributes __fastcall TVersionInfoFileDateEditor::GetAttributes(void)
{
  return TPropertyAttributes() << paReadOnly;
}

AnsiString __fastcall TVersionInfoFileDateEditor::GetValue(void)
{
  AnsiString DateTimeString;
  TVersionInfo* VersionInfoComponent;

  VersionInfoComponent = dynamic_cast<TVersionInfo*>(this->GetComponent(0));
  assert(VersionInfoComponent != NULL);

  if (VersionInfoComponent->Enabled && VersionInfoComponent->HasVersionInfo)
  {
    try
    {
      DateTimeString = FormatDateTime("dddddd - tt", TDateTime(double(GetFloatValue())));
    }
    catch(...)
    {
      DateTimeString = "(Invalid file date)";
    }
  }
  else
  {
    DateTimeString = "";
  }

  return DateTimeString;
}

//-----------------------------------------------------------------------------------

void __fastcall TVersionInfoLanguageCharsetIndexEditor::Edit(void)
{
  // Do nothing.
}

TPropertyAttributes __fastcall TVersionInfoLanguageCharsetIndexEditor::GetAttributes(void)
{
  return TPropertyAttributes() << paValueList;
}

AnsiString __fastcall TVersionInfoLanguageCharsetIndexEditor::GetTranslationNameAtIndex(const int Index)
{
  DWORD LanguageCode;
  DWORD Charset;
  TVersionInfo* VersionInfoComponent;

  VersionInfoComponent = dynamic_cast<TVersionInfo*>(GetComponent(0));
  assert(VersionInfoComponent != NULL);

  LanguageCode = reinterpret_cast<DWORD>(VersionInfoComponent->Translations->Objects[Index]);
  Charset = (LanguageCode >> 16) & 0xFFFF; // Get bits 15-31 and mask out the rest
  LanguageCode = LanguageCode & 0xFFFF; // Mask out upper 16 bits

  // Return the formatted result string
  AnsiString Result;

  return Result.sprintf( "%s%.4x:%s%.4x - %s",
                         HexDisplayPrefix.c_str(),
                         LanguageCode,
                         HexDisplayPrefix.c_str(),
                         Charset,
                         TVersionInfo::TranslateVersionLanguageName(LanguageCode).c_str()
                         );
}

bool __fastcall TVersionInfoLanguageCharsetIndexEditor::GetIndexForTranslationName(
  const String& TranslationName, int& Index)
{
  // OK, this is pretty inefficient, but it is
  // pretty effective and idiot-proof, too.

  TVersionInfo* VersionInfoComponent;

  VersionInfoComponent = dynamic_cast<TVersionInfo*>(GetComponent(0));
  assert(VersionInfoComponent != NULL);

  Index = VersionInfoComponent->Translations->Count-1;

  while (Index >= 0)
  {
    if (TranslationName == GetTranslationNameAtIndex(Index))
      break;
    Index--;
  }

  return (Index >= 0);
}

AnsiString __fastcall TVersionInfoLanguageCharsetIndexEditor::GetValue(void)
{
  AnsiString Result;
  TVersionInfo* VersionInfoComponent;

  VersionInfoComponent = dynamic_cast<TVersionInfo*>(GetComponent(0));
  assert(VersionInfoComponent != NULL);

  if (VersionInfoComponent->LanguageCharsetIndex >= 0)
  {
    Result = GetTranslationNameAtIndex(VersionInfoComponent->LanguageCharsetIndex);
  }
  else
  {
    Result = "(No language selected)";
  }

  return Result;
}

void __fastcall TVersionInfoLanguageCharsetIndexEditor::SetValue(const AnsiString Value)
{
  int NewLanguageCharsetIndex;
  TVersionInfo* VersionInfoComponent;

  VersionInfoComponent = dynamic_cast<TVersionInfo*>(GetComponent(0));
  assert(VersionInfoComponent != NULL);

  if ( VersionInfoComponent->Enabled &&
       GetIndexForTranslationName(Value, NewLanguageCharsetIndex) )
  {
    SetOrdValue(NewLanguageCharsetIndex);
  }
  else
  {
    inherited::SetValue(Value);
  }
}

void __fastcall TVersionInfoLanguageCharsetIndexEditor::GetValues(Classes::TGetStrProc Proc)
{
  TVersionInfo* VersionInfoComponent;
  int NumberElements;

  VersionInfoComponent = dynamic_cast<TVersionInfo*>(GetComponent(0));
  assert(VersionInfoComponent != NULL);

  if (!VersionInfoComponent->Enabled || !VersionInfoComponent->HasVersionInfo)
    return;

  NumberElements = VersionInfoComponent->Translations->Count;

  for (int i = 0; i < NumberElements; ++i)
  {
    Proc( GetTranslationNameAtIndex(i) );
  }
}

//-----------------------------------------------------------------------------------

void __fastcall TVersionInfoComponentEditor::DoTestAboutBox(void)
{
  TVersionInfo* VersionInfoComponent;

  VersionInfoComponent = dynamic_cast<TVersionInfo*>(this->Component);
  assert(VersionInfoComponent != NULL);

  VersionInfoComponent->ShowAboutBox();
}

void __fastcall TVersionInfoComponentEditor::DoChangeFileNameProperty(void)
{
  TVersionInfo* VersionInfoComponent;
  String NewFileName;

  VersionInfoComponent = dynamic_cast<TVersionInfo*>(this->Component);
  assert(VersionInfoComponent != NULL);

  NewFileName = VersionInfoComponent->FileName;

  if (GetVersionInfoFileNameViaDialog(NewFileName))
  {
    // Update
    VersionInfoComponent->FileName = NewFileName;
    Designer->Modified();
  }
}

void __fastcall TVersionInfoComponentEditor::Edit(void)
{
  // Execute default action
  DoTestAboutBox();
}

void __fastcall TVersionInfoComponentEditor::ExecuteVerb(int Index)
{
  switch(Index)
  {
    case 0:
      DoTestAboutBox();
      break;

    case 1:
      DoChangeFileNameProperty();
      break;

    default:
      // This ought not to happen
      assert(false);
  }
}

AnsiString __fastcall TVersionInfoComponentEditor::GetVerb(int Index)
{
  AnsiString VerbResult;

  switch(Index)
  {
    case 0:
      VerbResult = "Test About box";
      break;

    case 1:
      VerbResult = "Select file...";
      break;

    default:
      // This ought not to happen
      assert(false);
  }

  return VerbResult;
}

int __fastcall TVersionInfoComponentEditor::GetVerbCount(void)
{
  const int NumberVerbs = 2;

  return NumberVerbs;
}


