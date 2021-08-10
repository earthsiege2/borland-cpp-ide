/*--------------------------------------------------------

   FILESCG.CPP -- Test file handles in CodeGuard
  --------------------------------------------------------*/
#define STRICT
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include "testdll.h"
#include "filescg.h"


void FilesCG()
{
   char buffer[200];
   int i;

   MessageBox(NULL,"FilesCG: Using a freed handle", "FILESCG.CPP", MB_OK );
   i = open("test1.dat", O_CREAT, S_IREAD | S_IWRITE  );
   close(i);
   read (i, buffer, 5);
}

#pragma warn -aus
void FilesMixCG()
{
 int i = 0;

 MessageBox(NULL,"FilesMixCG: Mixing RTL file handles", "FILESCG.CPP", MB_OK );
 i = open("test2.dat", O_CREAT, S_IREAD | S_IWRITE );
 RTLMixHandle( i );
}

void FStreamsCG()
{
  FILE * fp;
  MessageBox(NULL,"FStreamsCG: Using FILE streams", "FILESCG.CPP", MB_OK );
  fp = fopen("test3.dat", "wt+" );
  fclose( fp );
  fwrite( "hello", 1, sizeof("hello"), fp );
}
