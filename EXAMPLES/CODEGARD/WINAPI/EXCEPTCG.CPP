/*--------------------------------------------------------

   EXCEPTCG.CPP -- Test exceptions in CodeGuard
 --------------------------------------------------------*/
#define STRICT
#include <windows.h>
#include <dos.h>

#include "exceptcg.h"

#pragma warn -aus
#pragma warn -use

#if defined (__FLAT__)
#define MSG "GPExceptCG1: Generate GP from invalid selector"
#else
#define MSG "GPExceptCG1: Generate GP from invalid address"
#endif


char GPExceptCG1()
{
  int MBret = IDYES;
  char _FAR* p=(char*)1, a;
  MBret = MessageBox(NULL,"GPExceptCG1:Generate GP from bad dereference?",
            "EXCEPTCG.CPP", MB_YESNO );
  if( MBret == IDYES )
    a = *p;
  return a;
}

void GPExceptCG2()
{
  UINT Handle;
  char _FAR* p;
  char c;
  int MBret = IDYES;

  MBret = MessageBox(NULL,"GPExceptCG2:Generate GP from beyond selector limit (16-bit issue only)?", "EXCEPTCG.CPP", MB_YESNO );
#if !defined(__FLAT__)
  if( MBret == IDYES )
  {
    Handle = AllocSelector( _DS );
    SetSelectorLimit( Handle, 5 );
    p = (char _FAR*)MK_FP( Handle, 0 );
    c = p[10]; // GP
 // c = p[2]; // OK
  }
#endif
}

