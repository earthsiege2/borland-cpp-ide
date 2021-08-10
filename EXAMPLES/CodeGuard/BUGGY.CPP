//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 2000-2002 Borland Corporation. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("buggy.res");
//---------------------------------------------------------------------------

/***************************************************************************\
WARNING : This program contains intentional memory allocation errors, and
other programming errors. It is intended to demonstrate how CodeGuard will
detect programming errors. You should ensure that you have shut down any
other applications that may be running and that you have saved all your files
before running this application.
\***************************************************************************/

class MyClass {
  private:
    int x;
  public:
    void SetX(int xx) {x = xx;}
};

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
//double free
void *p = malloc(123);
free(p);
free(p);

//access after free
int *i = (int*)malloc(sizeof(int));
free(i);
*i = 99;

//allocated with new[] deallocated with delete (no brackets)
char *c = new char[64];
delete c;

//overrun the end of the array
char foo[10];
foo[11] = 'a';

//copy a string into another which is one character too small
char *name = "Chris";
char *myname = new char[strlen(name)];
strcpy(myname, name);
delete[] myname;

//call a member function after instance is freed
MyClass *instance = new MyClass;
delete instance;
instance->SetX(10);

//memory leak -- allocated and never unallocated
TStringList *sl = new TStringList;
sl->Add("Hello there");

return 0;
}
//---------------------------------------------------------------------------
