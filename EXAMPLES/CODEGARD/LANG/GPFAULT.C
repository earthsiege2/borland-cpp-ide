/* This example compiles, links, and runs without
   apparent problems.
   If you recompile with CodeGuard enabled, the 
   program terminates with a GP fault (Exception 0xD)
   in Windows.
***/

#include <stdlib.h>

int a;

#pragma argsused
int main (int argc, char* argv[])
{
    int **p;
    int *q;

   p = malloc(sizeof(*p) * 4);

   /*  Initialize p */
   p[3] = &a;

   /*  Do something with p */
   p[3] = 0;

   /*  All done with p, so free it */
   free(p);

   /*  Broken code, referencing p after we've freed it */
   if (p[3])
   {
      q = p[3];
      *q = 1;
   }
   return 0;
}

