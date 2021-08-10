#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <malloc.h>

// Errors in this program are intentional.  Warnings disabled.
#pragma warn -sus
#pragma warn -par
#pragma warn -aus
#pragma warn -use

// Some data in DGROUP to demonstrate overruns/underruns.
char  pad1[21];
char  buf_d[21];
char  pad2[21];

// A structure to demonstrate uninitialized data access.
typedef struct
{
   int handle;
   int offset;
} MYSTRUCT;


// A few simple classes to demonstrate C++ specific errors.
class A
{
public:
   // constructor
   A(){};

   // destructor
   ~A(){};

   // data

   MYSTRUCT info[3];

   // A couple of member functions.
   void method(void)
   {
      printf("Hi from A::foo\n");
   }

   int getHandle(void)
   {
      return handle;
   }

private:
   int handle;
};


class B: virtual A
{
public:
   // constructor
   B(){};

   // destructor - should be virtual
   ~B(){};
};

// A function returning a pointer to destroyed local structure.
char * getBadLocal(void)
{
   char buf[20];
   return buf;
}

// A function returning a pointer to destroyed local class.
A * getBadAuto(void)
{
   A a;
   return &a;
}

// This function is here so we can pretend we use pointer p.
// Otherwise, a non-used pointer is removed by the compiler optimizations.
void nop(char * p) { }

#pragma argsused
int main (int argc, char* argv[])
{
   // An array on the stack.
   char buf_s[21];
   char * pad = (char *) malloc(200);
   // An array in the RTL heap.
   char * buf_h = (char *) malloc(21);
   char * p;
   // A scratch buffer.
   char  buffer [200];

   // A structure with uninitialized members.
   MYSTRUCT * m = new MYSTRUCT;

   //----------//
   // Overruns //
   //----------//

   // Stack overrun:
   strcpy(buf_s, "This string is long!\n");

   // Global data overrun:
   strcpy(buf_d, "This string is long!\n");

   // Heap block overrun:
   strcpy(buf_h, "This string is long!\n");

   //-------------//
   // Free access //
   //-------------//

   free(buf_h);
   strcpy(buf_h, "Copy to free block");

   //-----------------------//
   // access to freed local //
   //-----------------------//
   p = getBadLocal();
   memcpy(buffer, p, 20);

   //-------------//
   // double free //
   //-------------//
   free(buf_h);

   // Get the block back.
   buf_h = (char *) malloc(21);

   //--------------------------//
   // uninitialized data usage //
   //--------------------------//
   close(m->handle);


   // Now some C++ specific errors:

   //------------------------//
   // Using a deleted object. //
   //------------------------//

   A * a = new A;
   delete a;
   a->method();

   //---------------------------------//
   // Using a destroyed local object. //
   //---------------------------------//
   getBadAuto()->method();

   //-------------//
   // bad casting //
   //-------------//
   B * b = new B;
   a = (A *) b;
   delete a;

   //----------------------------//
   // uninitialized member usage //
   //----------------------------//
   a = new A;
   close(a -> getHandle() );

   delete a;

   // RESOURCE ERRORS

   //--------------------//
   // using a bad handle //
   //--------------------//
   close(234);

   //----------------------//
   // using a freed handle //
   //----------------------//
   int i = open("lang.cpp", 0);
   close(i);
   read (i, buffer, 5);

   //--------------//
   // double close //
   //--------------//
   close(i);

   //---------------//
   // type mismatch //
   //---------------//
   char * ss = new char[21];
   free(ss);

#ifdef	__WIN32__
   // The following section demonstrates errors that are caused in the user
   // code without calling any RTL or system calls. This is available only
   // in the 32-bit CodeGuard.

   //----------//
   // Overruns //
   //----------//

   // Stack overrun in user code.
   p = buf_s+15;
   p[6]=0;

    // Global data overrun in user code.
   p = buf_d+15;
   p[6]=0;

   // Heap block overrun in user code.
   p = buf_h+15;
   p[6]=0;

   // Stack arithmetic overrun in user code.
   p = buf_s+22;
   nop(p);

    // Global data arithmetic overrun in user code.
   p = buf_d+22;
   nop(p);

   // Heap block arithmetic overrun in user code.
   p = buf_h+22;
   nop(p);

   //-----------//
   // Underruns //
   //-----------//

   // Stack underrun in user code.
   p = buf_s+2;
   p[-3]=0;

    // Global data underrun in user code.
   p = buf_d+2;
   p[-6]=0;

   // Heap block underrun in user code.
   p = buf_h+2;
   p[-20]=0;

   //----------//
   // Just bad //
   //----------//
   p = (char*) 0x44;
   p++;
   nop(p);


   p = (char*) (((unsigned long) buf_s)-1000);
   p++;
   nop(p);

   //----------------------------//
   // Arithmetic in freed block. //
   //----------------------------//
   free(buf_h);
   p = buf_h+5;
   nop(p);

   //----------------------------//
   // Arithmetic in freed local. //
   //----------------------------//
   p = getBadLocal();
   p++;
   nop(p);

#endif

   //---------------//
   // double delete //
   //---------------//
   b = new B;
   delete b;
   delete b;

   // Resource leaks will be reported for m (MYSTRUCT), pad and
   // class B (that wasn't correctly deleted)
   return 0;
}
