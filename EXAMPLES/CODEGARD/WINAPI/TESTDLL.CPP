/*--------------------------------------------------------

   TESTDLL.CPP -- DLL to Test CodeGuard
 --------------------------------------------------------*/

#define STRICT
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <io.h>
#include "testdll.h"

int FAR  PASCAL _export RTLMixPointer( char * str )
{
   MessageBox(NULL,"RTLMixPointer: DLL deleting EXE pointer", "TESTDLL.CPP", MB_OK );
   delete[] str;
   return 1;
}

int FAR  PASCAL _export RTLMixHandle( int handle )
{
   MessageBox(NULL,"RTLMixHandle: DLL closing EXE handle", "TESTDLL.CPP", MB_OK );
   close( handle );
   return 1;
}



#pragma argsused
#if defined (__FLAT__)
BOOL WINAPI DllEntryPoint(HINSTANCE hinstDLL, DWORD  fdwReason, LPVOID  lpvReserved )
#define RET true;
#else
int FAR PASCAL LibMain( HANDLE hInst, WORD wDS, WORD wHpSz, LPSTR lpCmdLn )
#define RET 1;
#endif
{
    return RET;
}


