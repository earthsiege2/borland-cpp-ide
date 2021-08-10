//---------------------------------------------------------------------------
#include <vcl.h>
#include <winbase.h>
#pragma hdrstop

#include "ResourceLocator.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool TemplateFileStreamFromResource(const AnsiString AFileName, TStream* &AStream)
{
  try  {
    AnsiString sResourceName = LowerCase(ChangeFileExt(AFileName, ""));
    AStream = new TResourceStream((int)HInstance, sResourceName, "HTML");
  }
  catch (...) {
    return false;
  }
  return true;
}

