//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Filters.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  if ((reason == DLL_PROCESS_DETACH) && (PreprocessFilter != NULL))
  {
    PreprocessFilter->Destroyed();
  }
  return 1;
}
//---------------------------------------------------------------------------
