// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// bintree.cpp
//    Must link with myclass.cpp.
// ---------------------------------------------------------------------------

#include <classlib/binimp.h>
#include <iostream.h>
#include <strstrea.h>
#include "../myclass.h" 

typedef TBinarySearchTreeImp<MyClass> ContainerType;
typedef TBinarySearchTreeIteratorImp<MyClass> IteratorType;

const int MaxItems=6;

void ForEachCallBack(MyClass& mc, void *s)
{
    cout << (char *)s << mc << endl;
}

void AddItems(ContainerType& container, int numItems)
{
    int multiplier = 1;
    for( int i=numItems; i>0; i-- )
        {
        char buf[80];
        ostrstream str(buf, sizeof(buf) );
        str << (numItems-multiplier*i) << " hello" << ends;
        multiplier = -1 * multiplier;
        container.Add(MyClass(buf));
        }
}

void UseInorderIterator(ContainerType& container)
{
    IteratorType iterator(container);
    while( iterator )
        {
        cout << iterator.Current() << endl;
        iterator++;
        }
}

void UsePreorderIterator(ContainerType& container)
{
    IteratorType iterator(container, TBinarySearchTreeBase::PreOrder);
    while( iterator )
        {
        cout << iterator.Current() << endl;
        iterator++;
        }
}

void UsePostorderIterator(ContainerType& container)
{
    IteratorType iterator(container, TBinarySearchTreeBase::PostOrder);
    while( iterator )
        {
        cout << iterator.Current() << endl;
        iterator++;
        }
}

int main()
{
    ContainerType container;
    AddItems(container, MaxItems);
  
    cout << "--- Starting ForEach" << endl;
    container.ForEach(ForEachCallBack, (void*)"FE ");
  
    cout << "--- Starting Iterator (inorder)" << endl;
    UseInorderIterator(container);
  
    cout << "--- Starting Iterator (preorder)" << endl;
    UsePreorderIterator(container);
  
    cout << "--- Starting Iterator (postorder)" << endl;
    UsePostorderIterator(container);
  
    return 0;
}
