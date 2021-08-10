//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Important note about package memory management:
//
//   If your package exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library BCBMM.LIB to both the package project and
//   any EXE projects that use the package.  This will change the package and
//   its calling EXE's to use the BORLNDMM.DLL as their memory manager.
//   In these cases, the file BORLNDMM.DLL should be deployed along with your
//   package.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
        return 1;
}
//---------------------------------------------------------------------------
