/*--------------------------------------------------------

   MEMCG.CPP -- Test pointers in CodeGuard
 --------------------------------------------------------*/
#define STRICT
#include <windows.h>

#include "memcg.h"

#pragma warn -aus
void LocalAllocCG()
{
  HLOCAL hLocal;
  void NEAR* localBuff;
  MessageBox(NULL,"LocalMemCG: Local Memory", "MEMCG.CPP", MB_OK );
  hLocal = LocalAlloc( 10, LMEM_MOVEABLE );
  localBuff = LocalLock( hLocal );
     //   LocalFree( hLocal );
}

void GlobalAllocCG()
{
  HGLOBAL hglb;
  void FAR* lpvBuffer;

  MessageBox(NULL,"GlobalMemCG: Global Memory", "MEMCG.CPP", MB_OK );
  hglb = GlobalAlloc(GPTR, 1024);
  lpvBuffer = GlobalLock(hglb);

  // GlobalUnlock(hglb);
  // GlobalFree(hglb);
}

void WinModuleCG()
{
  HINSTANCE loadLibRet=0;

  MessageBox(NULL,"WinModuleCG: Windows Module", "MEMCG.CPP", MB_OK );
  loadLibRet = LoadLibrary("loadtest.dll");

  FreeLibrary( loadLibRet );
  FreeLibrary( loadLibRet );
//    FreeLibrary( loadLibRet );
}


