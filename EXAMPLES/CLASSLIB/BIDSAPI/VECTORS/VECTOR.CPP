// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// vector.cpp
//    Must link with myclass.cpp.
// ---------------------------------------------------------------------------

#include <classlib/vectimp.h>
#include <classlib/alloctr.h>
#include <iostream.h>
#include <strstrea.h>
#include "../myclass.h"

typedef TMCVectorImp<MyClass, TStandardAllocator> ContainerType;
typedef TMCVectorIteratorImp<MyClass, TStandardAllocator> IteratorType;

const int MaxItems=6;

void ForEachCallBack(MyClass& mc, void* s)
{
    cout << (char*)s << mc << endl;
}

void AddItems(ContainerType& container, int numItems)
{
    for( int i=numItems; i>0; i-- )
        {
        char buf[80];
        ostrstream str( buf, sizeof(buf) );
        str << i << " hello" << ends;
        container.Add(MyClass(buf));
        }
}

void UseForwardIterator(ContainerType& container)
{
    IteratorType iterator(container);
    while( iterator )
        {
        cout << iterator.Current() << endl;
        iterator++;
        }
}

int main()
{
    ContainerType container(MaxItems);
    AddItems(container, MaxItems);
  
    cout << "--- Starting ForEach" << endl;
    container.ForEach(ForEachCallBack, (void*)"FE ");
  
    cout << "--- Starting Iterator (forward)" << endl;
    UseForwardIterator(container);
  
    return 0;
}
