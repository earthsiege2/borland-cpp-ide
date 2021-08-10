/*--------------------------------------------------------

   POINTCG.CPP -- Test pointers in CodeGuard
 --------------------------------------------------------*/
#define STRICT
#include <windows.h>
#include <string.h>
#include <malloc.h>

#include "pointcg.h"
#include "testdll.h"

#pragma warn -sus
#pragma warn -use

extern char  buf_d[21]; // reference to global pointer for overrun test
char *cptr; // pointer to test mixing RTL pointers

void PointersCG()
{
  MessageBox(NULL,"PointersCG: Global data overrun", "POINTCG.CPP", MB_OK );
  strcpy(buf_d, "This string is long!\n");
}

void StackPointersCG()
{
  char pad1[21];
  char buf_s[21];
  char pad2[21];
  MessageBox(NULL,"StackPointersCG: Pointer Stack overrun","POINTCG.CPP", MB_OK );
  strcpy(buf_s, "This string is long!\n");
}

void PointersMixCG()
{
   MessageBox(NULL,"PointersMixCG: Mixing RTL pointers", "POINTCG.CPP",MB_OK );
   cptr = new char[10];
   strcpy( cptr, "hello" );
   RTLMixPointer( cptr ); // call DLL to delete the pointer
}

void PointersMixTypes()
{
   MessageBox(NULL,"PointersMixTypes: Mixing new and malloc", "POINTCG.CPP",MB_OK );
   char * mismatchPtr = new char[10];  // allocate with 'new'
   free( mismatchPtr );                // delete with 'free'
}

void PointersBadDelete()
{
   char * cptr1;
   MessageBox(NULL,"PointersBadDelete: Deleting pointer incorrectly", "POINTCG.CPP",MB_OK );
   cptr1 = new char; // allocate one object
   delete[] cptr1; // delete array of objects
}

// A function returning a pointer to destroyed local structure.
char * getBadLocal()
{
   char buf[20];
   return buf;
}

void PointersBadLocal()
{
   char buf[20];
   char *cptr1;
   MessageBox(NULL,"PointersBadLocal: Using destroyed local pointer", "POINTCG.CPP",MB_OK );
   cptr1 = getBadLocal(); // get a pointer to a destroyed local object
   strcpy( buf, cptr1 );
}


